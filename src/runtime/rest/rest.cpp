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

#include "zorbaerrors/error_manager.h"

#include <iostream>
#include <fstream>
using namespace std;

namespace zorba {

/****************************************************************************
 *
 * CurlStreamBuffer
 *
 ****************************************************************************/
                   
CurlStreamBuffer::CurlStreamBuffer(CURLM* aMultiHandle, CURL* aEasyHandle)
  : std::streambuf(), MultiHandle(aMultiHandle), EasyHandle(aEasyHandle)
{
  CurlErrorBuffer = std::auto_ptr<char>(new char[CURLOPT_ERRORBUFFER]);
  CurlErrorBuffer.get()[0] = 0;
  
  curl_easy_setopt(EasyHandle, CURLOPT_ERRORBUFFER, CurlErrorBuffer.get());
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
  ::free(eback());
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
  char* _pptr = pptr();
  char* _gptr = gptr();
  char* _eback = eback();
  
  int new_size = 2 * (epptr() - _eback);
  if (new_size == 0)
    new_size = INITIAL_BUFFER_SIZE;
  
  char* new_buffer = (char*)realloc(_eback, new_size);
  
  if (new_buffer != _eback)
  {
    _pptr = new_buffer + (_pptr - _eback);
    _gptr = new_buffer + (_gptr - _eback);
    _eback = new_buffer;
  }
  setp(_pptr, new_buffer + new_size);
  sputc(c);
  setg(_eback, _gptr, pptr());
  
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

bool
ChildrenIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  ChildrenIteratorState* state;
  DEFAULT_STACK_INIT(ChildrenIteratorState, state, planState);
  
  state->index = 0;
  while(state->index < children.size())
  {
    result = children[state->index];
    STACK_PUSH(true, state);
    state->index++;
  }
  
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

bool ZorbaRestGetIterator::createResultNode(store::Item_t& result, PlanState& planState, xqpString name, ChildrenIterator_t children) const
{
  xqpString ns = ZORBA_REST_FN_NS;
  xqpString pre = "zorba-rest";
  store::Item_t qname;
  
  GENV_ITEMFACTORY->createQName(qname, ns.getStore(), pre.getStore(), name.getStore());
  xqpStringStore_t baseUri = planState.theRuntimeCB->theStaticContext->final_baseuri().getStore();
  store::NsBindings bindings;
  store::CopyMode copymode;
  
  std::auto_ptr<store::Iterator> cwrapper;
  if (children != NULL)
    cwrapper.reset(new PlanWrapper(children.getp(), planState.theCompilerCB, planState.dctx()));
  
  return GENV_ITEMFACTORY->createElementNode(result, (ulong)&planState,
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
}

bool ZorbaRestGetIterator::createResultNode(store::Item_t& result, PlanState& planState, xqpString name, const QueryLoc& loc, store::Item_t child) const
{
  ChildrenIterator_t childIterator;
  childIterator = new ChildrenIterator(loc, child); 
  return createResultNode(result, planState, name, childIterator);
}

bool ZorbaRestGetIterator::createResultNode(store::Item_t& result, PlanState& planState, xqpString name, const QueryLoc& loc, store::Item_t child1, store::Item_t child2) const
{
  ChildrenIterator_t childIterator;
  childIterator = new ChildrenIterator(loc, child1, child2);
  return createResultNode(result, planState, name, childIterator);
}


bool
ZorbaRestGetIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUri;
  xqpStringStore_t lUriString;
  int code;
  store::Item_t doc = NULL;
  store::Store& store = GENV.getStore();
  
  ZorbaRestGetIteratorState* state;
  bool valid = false;
  DEFAULT_STACK_INIT(ZorbaRestGetIteratorState, state, planState);
  
  /********* Initialization ***********************/
  curl_global_init(CURL_GLOBAL_ALL); // TODO: once per application, needs to be moved somewhere else
  state->MultiHandle = curl_multi_init(); // TODO check error
  state->EasyHandle = curl_easy_init();
  state->theStreamBuffer = NULL;
  curl_easy_setopt(state->EasyHandle, CURLOPT_HTTPGET, 1);
  curl_easy_setopt(state->EasyHandle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
  curl_easy_setopt(state->EasyHandle, CURLOPT_HEADERFUNCTION, ZorbaRestGetIterator::getHeaderData);
  curl_easy_setopt(state->EasyHandle, CURLOPT_WRITEHEADER, state);
  curl_multi_add_handle(state->MultiHandle, state->EasyHandle);

  if (!CONSUME(lUri, 0)) {
    // todo raise an error
  }

  lUriString = lUri->getStringValue();
  curl_easy_setopt(state->EasyHandle, CURLOPT_URL, lUriString->c_str());

  state->headers = std::auto_ptr<std::vector<std::string> >(new std::vector<std::string>);
  state->theStreamBuffer = new CurlStreamBuffer(state->MultiHandle, state->EasyHandle);
  
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
    store::Item_t text_code;
    GENV_ITEMFACTORY->createTextNode(text_code, (ulong)&planState, temp.theStrStore, false, true);
    store::Item_t status_code;
    createResultNode(status_code, planState, "status_code", loc, text_code);
    
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
      store::Item_t child;
      children->next(child);
      store::Item_t payload;
      createResultNode(payload, planState, "payload", loc, child); // TODO: check NULL
    
      valid = createResultNode(result, planState, "result", loc, status_code, payload);
    }
    else
    {
      valid = createResultNode(result, planState, "result", loc, status_code);
    }
  }
  
  STACK_PUSH(valid, state);
  
  /********* Deinitialization ***********************/
  curl_multi_remove_handle(state->MultiHandle, state->EasyHandle);
  curl_easy_cleanup(state->EasyHandle);
  curl_multi_cleanup(state->MultiHandle);
  curl_global_cleanup();
  state->theStreamBuffer = NULL;
  state->headers.reset();
  /*
  delete *state->headers;
  state->headers = NULL;
  */
  
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
