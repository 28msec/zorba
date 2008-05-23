/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "runtime/rest/rest.h"

#include <curl/curl.h>

#include "runtime/util/iterator_impl.h"
#include "runtime/api/runtimecb.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "store/api/iterator.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/naive/node_items.h"
#include "store/api/copymode.h"
#include "types/root_typemanager.h"
#include "context/static_context.h"
#include "context/namespace_context.h"

#include "zorbatypes/numconversions.h"
#include "zorbatypes/datetime/parse.h"
#include "system/globalenv.h"
#include "errors/error_manager.h"


namespace zorba {

/****************************************************************************
 *
 * CurlStreamBuffer
 *
 ****************************************************************************/
                   
CurlStreamBuffer::CurlStreamBuffer(CURLM* aMultiHandle, CURL* aEasyHandle)
  : std::streambuf(), MultiHandle(aMultiHandle), EasyHandle(aEasyHandle)
{
  CurlErrorBuffer = new char[CURLOPT_ERRORBUFFER];
  CurlErrorBuffer[0] = 0;
  
  curl_easy_setopt(EasyHandle, CURLOPT_ERRORBUFFER, CurlErrorBuffer);
  curl_easy_setopt(EasyHandle, CURLOPT_WRITEDATA, this);
  curl_easy_setopt(EasyHandle, CURLOPT_WRITEFUNCTION, CurlStreamBuffer::write_callback);
  curl_easy_setopt(EasyHandle, CURLOPT_BUFFERSIZE, INITIAL_BUFFER_SIZE);
}

int CurlStreamBuffer::multi_perform()
{
  CURLMsg* msg;
  int MsgsInQueue;
  int StillRunning = 0;
  bool done = false;
  int error = 0;

  while (!done)
  {
    while (CURLM_CALL_MULTI_PERFORM == curl_multi_perform(MultiHandle, &StillRunning))
      ;

    while ((msg = curl_multi_info_read(MultiHandle, &MsgsInQueue)))
      if (msg->msg == CURLMSG_DONE)
      {
        error = msg->data.result;
        done = true;
      }
  }

  // TODO: return message, too ?
  //if (error)
  //  std::cout << "error: [" << CurlErrorBuffer << "]" << std::endl;
  
  return error;
}

CurlStreamBuffer::~CurlStreamBuffer()
{
  delete[] CurlErrorBuffer; 
  CurlErrorBuffer = NULL;
  free(eback());
}

size_t CurlStreamBuffer::write_callback(char* buffer, size_t size, size_t nitems, void* userp)
{
  CurlStreamBuffer* sbuffer = static_cast<CurlStreamBuffer*>(userp);
  size_t result = sbuffer->sputn(buffer, size*nitems);
  sbuffer->setg(sbuffer->eback(), sbuffer->gptr(), sbuffer->pptr());
  return result;
}

int CurlStreamBuffer::overflow(int c)
{
  char* _out_cur = pptr();
  char* _in_cur = gptr();
  char* _in_beg = eback();
  
  int new_size = 2 * (epptr() - _in_beg);
  if (new_size == 0)
    new_size = INITIAL_BUFFER_SIZE;
  
  char* new_buffer = (char*)realloc(_in_beg, new_size);
  
  if (new_buffer != _in_beg)
  {
    _out_cur = new_buffer + (pptr() - pbase());
    _in_cur = new_buffer + (_in_cur - _in_beg);
    _in_beg = new_buffer;
  }
  setp(_out_cur, new_buffer + new_size);
  sputc(c);
  setg(_in_beg, _in_cur, pptr());
  
  return 0;
}

int CurlStreamBuffer::underflow()
{
  // TODO: place a call to multi_perform() ?
  return EOF;
}

/****************************************************************************
 *
 * ChildrenIterator
 *
 ****************************************************************************/
 
void ChildrenIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
}

void ChildrenIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
}

store::Item_t
ChildrenIterator::nextImpl(PlanState& planState) const
{
  ChildrenIteratorState* state;
  DEFAULT_STACK_INIT(ChildrenIteratorState, state, planState);
  
  state->index = 0;
  while(state->index < children.size())
  {
    STACK_PUSH(children[state->index], state);
    state->index++;
  }
  
  STACK_PUSH(NULL, state);
  STACK_END (state);
}


/****************************************************************************
 *
 * rest-get Iterator
 *
 ****************************************************************************/

ZorbaRestGetIteratorState::ZorbaRestGetIteratorState() 
{
}

ZorbaRestGetIteratorState::~ZorbaRestGetIteratorState()
{
}

void
ZorbaRestGetIteratorState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
}

void
ZorbaRestGetIteratorState::reset(PlanState& planState) 
{
  PlanIteratorState::reset(planState);
}

store::Item_t ZorbaRestGetIterator::createResultNode(PlanState& planState, xqpString name, ChildrenIterator_t children) const
{
  xqpString ns = "http://www.flworfound.org/rest";
  xqpString pre = "zorba-rest";
  store::Item_t qname = GENV_ITEMFACTORY->createQName(ns.getStore(), pre.getStore(), name.getStore());
  xqpStringStore_t baseUri = planState.theRuntimeCB->theStaticContext->final_baseuri().getStore();
  store::NsBindings bindings;
  store::CopyMode copymode;
  
  std::auto_ptr<store::Iterator> cwrapper;
  if (children != NULL)
    cwrapper.reset(new PlanWrapper(children, planState.theCompilerCB, planState.dctx()));
  
  store::Item_t item = GENV_ITEMFACTORY->createElementNode((ulong)&planState,
    qname,
    GENV_TYPESYSTEM.XS_UNTYPED_QNAME,
    cwrapper.get(),
    NULL,
    NULL,
    bindings,
    baseUri,
    true,
    true,
    false,
    copymode);
    
  return item;
}

store::Item_t ZorbaRestGetIterator::createResultNode(PlanState& planState, xqpString name, const QueryLoc& loc, store::Item_t child) const
{
  ChildrenIterator_t childIterator;
  childIterator = new ChildrenIterator(loc, child); 
  return createResultNode(planState, name, childIterator);
}

store::Item_t ZorbaRestGetIterator::createResultNode(PlanState& planState, xqpString name, const QueryLoc& loc, store::Item_t child1, store::Item_t child2) const
{
  ChildrenIterator_t childIterator;
  childIterator = new ChildrenIterator(loc, child1, child2);
  return createResultNode(planState, name, childIterator);
}


store::Item_t
ZorbaRestGetIterator::nextImpl(PlanState& planState) const
{
  store::Item_t lUri;
  xqpStringStore_t lUriString;
  int code;
  store::Item_t result = NULL;
  store::Item_t doc = NULL;
  store::Store& store = GENV.getStore();
  
  ZorbaRestGetIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaRestGetIteratorState, state, planState);
  
  /********* Initialization ***********************/
  curl_global_init(CURL_GLOBAL_ALL); // TODO: once per application, needs to be moved somewhere else
  state->MultiHandle = curl_multi_init(); // TODO check error
  state->EasyHandle = curl_easy_init();
  state->theStreamBuffer = NULL;
  state->headers = NULL;
  curl_easy_setopt(state->EasyHandle, CURLOPT_HTTPGET, 1);
  curl_easy_setopt(state->EasyHandle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
  curl_easy_setopt(state->EasyHandle, CURLOPT_HEADERFUNCTION, ZorbaRestGetIterator::getHeaderData);
  curl_easy_setopt(state->EasyHandle, CURLOPT_WRITEHEADER, state);
  curl_multi_add_handle(state->MultiHandle, state->EasyHandle);

  if ( (lUri = CONSUME(0) ) == NULL ) 
  {
    //TODO: raise an error
  }

  lUriString = lUri->getStringValue();
  curl_easy_setopt(state->EasyHandle, CURLOPT_URL, lUriString->c_str());

  if (state->theStreamBuffer == 0) 
  {
    state->theStreamBuffer = new CurlStreamBuffer(state->MultiHandle, state->EasyHandle);
    state->headers = new std::vector<std::string>();
  }
  
  code = state->theStreamBuffer->multi_perform(); 
  
  /********* Process the reply **********************/
  {
    int result_code;
    if (state->headers->size() == 0)
    {
      result_code = code; // TODO change cURL's error code to something else?
    }
    else if (parse_int_const_position<int>(state->headers->operator[](0), 9, result_code, 1))
    {
      result_code = -1; // TODO change this code
    }
    
    xqpString temp = NumConversions::intToStr(result_code);
    store::Item_t text_code = GENV_ITEMFACTORY->createTextNode((ulong)&planState, temp.theStrStore, false, true);
    store::Item_t status_code = createResultNode(planState, "status_code", loc, text_code);
    
    std::istream is(state->theStreamBuffer);
    try {
      doc = store.loadDocument(lUriString, is);
    }
    catch (...) {
      doc = NULL;
    }
    
    if (doc != NULL)
    {
      store::Iterator_t children = doc->getChildren();
      children->open();
      store::Item_t payload = createResultNode(planState, "payload", loc, children->next()); // TODO: check NULL
    
      result = createResultNode(planState, "result", loc, status_code, payload);
    }
    else
    {
      result = createResultNode(planState, "result", loc, status_code);
    }
  }
  
  STACK_PUSH(result, state);
  
  /********* Deinitialization ***********************/
  curl_multi_remove_handle(state->MultiHandle, state->EasyHandle);
  curl_easy_cleanup(state->EasyHandle);
  curl_multi_cleanup(state->MultiHandle);
  curl_global_cleanup();
  delete state->theStreamBuffer;
  delete state->headers;
  
  STACK_END (state);
}

size_t
ZorbaRestGetIterator::getHeaderData(void *ptr, size_t size, size_t nmemb, void *aState)
{
  ZorbaRestGetIteratorState* state = static_cast<ZorbaRestGetIteratorState*>(aState);
  
  std::string temp(static_cast<char*>(ptr), size*nmemb-1);
  state->headers->push_back(temp);
  // std::cout << "header: " << temp << std::endl;
  
  return size * nmemb;
}

} /* namespace zorba */
