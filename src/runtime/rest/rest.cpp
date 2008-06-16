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
#include <curl/types.h>
#include <curl/easy.h>

#include "api/serialization/serializer.h"

#include "runtime/util/iterator_impl.h"
#include "runtime/api/runtimecb.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "store/api/iterator.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/naive/node_items.h"
#include "store/api/copymode.h"
#include "store/naive/store_defs.h"
#include "store/naive/simple_store.h"
#include "store/naive/basic_item_factory.h"

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

using namespace store;

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

bool createQNameHelper(store::Item_t& result, xqpString name) 
{
  xqpString ns = ZORBA_REST_FN_NS;
  xqpString pre = "zorba-rest";
  return GENV_ITEMFACTORY->createQName(result, ns.getStore(), pre.getStore(), name.getStore());
}
    
bool createResultNode(store::Item_t& result, PlanState& planState, xqpString name, ChildrenIterator_t children) 
{
  store::Item_t qname;
  createQNameHelper(qname, name);
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

bool createAttributeHelper(store::Item_t& result, PlanState& planState, xqpString name, xqpString value) 
{
  std::auto_ptr<store::Iterator> cwrapper1, cwrapper2;
  store::Item_t qname, value_string;
  createQNameHelper(qname, name);
  GENV_ITEMFACTORY->createString(value_string, value.theStrStore);
  cwrapper1.reset(new PlanWrapper(new ChildrenIterator(qname), planState.theCompilerCB, planState.dctx()));
  cwrapper2.reset(new PlanWrapper(new ChildrenIterator(value_string), planState.theCompilerCB, planState.dctx()));
  store::Item_t type = GET_STORE().theSchemaTypeNames[store::XS_STRING];
  return GENV_ITEMFACTORY->createAttributeNode(
      result,
      (ulong)&planState,
      cwrapper1.get(),
      type,
      cwrapper2.get(),
      true,
      true);
}

bool createResultNode(store::Item_t& result, PlanState& planState, xqpString name, store::Item_t child) 
{
  ChildrenIterator_t childIterator;
  childIterator = new ChildrenIterator(child);
  return createResultNode(result, planState, name, childIterator);
}

bool createResultNode(store::Item_t& result, PlanState& planState, xqpString name, store::Item_t child1, store::Item_t child2) 
{
  ChildrenIterator_t childIterator;
  childIterator = new ChildrenIterator(child1, child2);
  return createResultNode(result, planState, name, childIterator);
}

bool createResultNode(store::Item_t& result, PlanState& planState, xqpString name,
                                            store::Item_t child1, store::Item_t child2, store::Item_t child3) 
{
  ChildrenIterator_t childIterator;
  childIterator = new ChildrenIterator(child1, child2, child3);
  return createResultNode(result, planState, name, childIterator);
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

int processReply(store::Item_t& result, PlanState& planState, xqpString& lUriString,
                 int code, std::vector<std::string>& headers, CurlStreamBuffer* theStreamBuffer) 
{
  int reply_code;
  xqpString content_type;
  ChildrenIterator_t headers_iterator = new ChildrenIterator();
  store::Store& store = GENV.getStore();
    
  if (headers.size() == 0)
  {
    reply_code = code; // TODO change cURL's error code to something else? // TODO: throw exception?
  }
  else
  {
    if (parse_int_const_position<int>(headers.operator[](0), 9, reply_code, 1))
    {
      reply_code = -1; // TODO change this code
    }
      
    for (unsigned int i = 1; i < headers.size(); i++)
    {
      int pos = headers.operator[](i).find(':');
      if (pos > -1)
      {
        store::Item_t attrib, header_value, header;
          
        xqpString name_string = headers.operator[](i).substr(0, pos);
        createAttributeHelper(attrib, planState, xqpString("name"), name_string);
          
        string temp = headers.operator[](i).substr(pos+2);

        xqpString value_string = temp;
        GENV_ITEMFACTORY->createTextNode(header_value, (ulong)&planState, value_string.theStrStore, false, true);
        createResultNode(header, planState, "header", attrib, header_value);
        headers_iterator->addChild(header);

        // extract content-type
        if (name_string.lowercase() == "content-type")
          content_type = temp;;
      }
      else
      {
          // TODO: invalid header
      }
    }
  }

  store::Item_t text_code, status_code;
  store::Item_t doc = NULL;
    
  xqpString temp = NumConversions::intToStr(reply_code);
  GENV_ITEMFACTORY->createTextNode(text_code, (ulong)&planState, temp.theStrStore, false, true);
  createResultNode(status_code, planState, "status_code", text_code);

  if (reply_code == 200 )
  {
    int doc_type;  // values: 3 - xml, 2 - text, 1 - everything else (base64), 0 - do nothing, document has bee processed.

    if (content_type.theStrStore.getp() == NULL)
      doc_type = 1;
    else if (content_type.indexOf("application/xml") == 0
             ||
             content_type.indexOf("application/xhtml") == 0
             ||
             content_type.indexOf("text/xml") == 0
             ||
             content_type.indexOf("text/xhtml") == 0)       // XMLs
      doc_type = 3;
    else if (content_type.indexOf("+xml") > -1)
      doc_type = 3;
    else if (content_type.indexOf("text/") == 0)
      doc_type = 2;
    else
      doc_type = 1;

    switch (doc_type)
    {
    case 3:  // xml
      {
        store::Item_t temp;
        std::istream is(theStreamBuffer);
        try {
          temp = store.loadDocument(lUriString.theStrStore, is);
        }
        catch (...) {
          temp = NULL;
        }

        if (temp != NULL)
        {
          store::Iterator_t doc_child = temp->getChildren();
          doc_child->open();
          doc_child->next(doc);
        }
        else
        {
          // TODO: error
        }
      }
      break;
      
    case 2:  // text
      {
        stringstream str;
        str << theStreamBuffer;
        xqpString temp = str.str();
        GENV_ITEMFACTORY->createTextNode(doc, (ulong)&planState, temp.theStrStore, false, true);
      }
      break;

    case 1:  // base64
      {
        xqp_base64Binary base64;
        std::istream is(theStreamBuffer);
        xqpString temp = Base64::encode(is);
        GENV_ITEMFACTORY->createTextNode(doc, (ulong)&planState, temp.theStrStore, false, true);
      }
      break;
    }
  }
    
  if (doc != NULL)
  {
    store::Item_t payload, headers_item;
    createResultNode(payload, planState, "payload", doc);
    createResultNode(headers_item, planState, "headers", headers_iterator);
    createResultNode(result, planState, "result", status_code, headers_item, payload);
  }
  else
  {
    store::Item_t headers_item;
    createResultNode(headers_item, planState, "headers", headers_iterator);
    createResultNode(result, planState, "result", status_code, headers_item);
  }

  return 0;
}

static size_t getHeaderData(void *ptr, size_t size, size_t nmemb, void *aState)
{
  ZorbaRestGetIteratorState* state = static_cast<ZorbaRestGetIteratorState*>(aState);
  
  std::string temp(static_cast<char*>(ptr), size*nmemb-1);
  if (temp[temp.size()-1] == 0x0D)  // delete the 0xD at the end.
    temp.erase(temp.end()-1);
  state->headers->push_back(temp);
  // std::cout << "header: " << temp << std::endl;
  
  return size * nmemb;
}

static void setupConnection(ZorbaRestGetIteratorState* state, bool get_method)
{
  state->MultiHandle = curl_multi_init(); // TODO check error
  state->EasyHandle = curl_easy_init();
  
  if (get_method)
    curl_easy_setopt(state->EasyHandle, CURLOPT_HTTPGET, 1);
  else
    curl_easy_setopt(state->EasyHandle, CURLOPT_HTTPPOST, 1);
    
  curl_easy_setopt(state->EasyHandle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
  curl_easy_setopt(state->EasyHandle, CURLOPT_HEADERFUNCTION, getHeaderData);
  curl_easy_setopt(state->EasyHandle, CURLOPT_WRITEHEADER, state);
  curl_multi_add_handle(state->MultiHandle, state->EasyHandle);
  state->headers = std::auto_ptr<std::vector<std::string> >(new std::vector<std::string>);
  state->theStreamBuffer = new CurlStreamBuffer(state->MultiHandle, state->EasyHandle);
}

static void cleanupConnection(ZorbaRestGetIteratorState* state)
{
  curl_multi_remove_handle(state->MultiHandle, state->EasyHandle);
  curl_easy_cleanup(state->EasyHandle);
  curl_multi_cleanup(state->MultiHandle);
  state->theStreamBuffer = NULL;
  state->headers.reset();
}

void processHeader(store::Item_t& headers, curl_slist** headers_list)
{
  store::Iterator_t it;
  store::Item_t child, name;

  if (headers->getNodeKind() != store::StoreConsts::elementNode)
    return; // TODO: error top node should be element node

  if (xqpString("headers") == headers->getNodeName()->getLocalName())
  {
    it = headers->getChildren();
    it->open();
    while (it->next(child))
      processHeader(child, headers_list);
    return;
  }

  it = headers->getAttributes();
  it->open();
  while (it->next(child))
  {
    if (xqpString("name") == child->getNodeName()->getLocalName())
      name = child;
  }

  if (name.getp() == NULL)
    return; // TODO: signal error - header without an associated name

  it = headers->getChildren();
  it->open();
  it->next(child);
  if (child->getNodeKind() == store::StoreConsts::textNode)
  {
    xqpString temp = xqpString(name->getStringValue()) + xqpString(": ") + child->getStringValueP();
    *headers_list = curl_slist_append(*headers_list , temp.c_str());
  }
  else 
  {
    // TODO: error
  }
}

static void processPayload(Item_t& payload_data, struct curl_httppost** first, struct curl_httppost** last)
{
  store::Iterator_t it;
  store::Item_t child, name;

  if (payload_data->getNodeKind() != store::StoreConsts::elementNode)
    return; // TODO: error top node should be element node

  if (xqpString("payload") == payload_data->getNodeName()->getLocalName())
  {
    it = payload_data->getChildren();
    it->open();
    while (it->next(child))
      processPayload(child, first, last);
    return;
  }

  it = payload_data->getAttributes();
  it->open();
  while (it->next(child))
  {
    if (xqpString("name") == child->getNodeName()->getLocalName())
      name = child;
  }

  if (name.getp() == NULL)
    return; // TODO: signal error - payload part without an associated name

  it = payload_data->getChildren();
  it->open();
  it->next(child);
  if (child->getNodeKind() == store::StoreConsts::textNode)
  {
    curl_formadd(first, last,
                 CURLFORM_COPYNAME, name->getStringValue()->c_str(),
                 CURLFORM_COPYCONTENTS, child->getStringValueP()->c_str(),
                 CURLFORM_END);
  }
  else if (child->getNodeKind() == store::StoreConsts::elementNode)
  {
    stringstream ss;
    error::ErrorManager lErrorManager;
    serializer ser(&lErrorManager);
    ser.set_parameter("omit-xml-declaration","yes");
    ser.serialize(child, ss);
    curl_formadd(first, last,
                 CURLFORM_COPYNAME, name->getStringValue()->c_str(),
                 CURLFORM_COPYCONTENTS, ss.str().c_str(),
                 CURLFORM_CONTENTTYPE, "text/html",
                 CURLFORM_END);
  }
  else
  {
    // TODO: process comments, pi nodes? or generate error?
  }
}

static xqpString processGetPayload(Item_t& payload_data, xqpString& Uri)
{
  store::Iterator_t it;
  store::Item_t child, name;

  if (payload_data->getNodeKind() != store::StoreConsts::elementNode)
    return Uri; // TODO: error top node should be element node

  if (xqpString("payload") == payload_data->getNodeName()->getLocalName())
  {
    it = payload_data->getChildren();
    it->open();
    while (it->next(child))
      Uri = processGetPayload(child, Uri);
    return Uri;
  }

  it = payload_data->getAttributes();
  it->open();
  while (it->next(child))
  {
    if (xqpString("name") == child->getNodeName()->getLocalName())
      name = child;
  }

  if (name.getp() == NULL)
    return Uri; // TODO: signal error - payload part without an associated name

  it = payload_data->getChildren();
  it->open();
  it->next(child);
  if (child->getNodeKind() == store::StoreConsts::textNode)
  {
    if (Uri.indexOf("?") == -1)
      Uri = Uri + "?" + name->getStringValue()->str() + "=" + child->getStringValueP();
    else
      Uri = Uri + "&" + name->getStringValue()->str() + "=" + child->getStringValueP();
  }
  else
  {
    // TODO: generate error or ignore?
  }

  return Uri;
}

bool ZorbaRestGetIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUri, payload_data, headers;
  xqpString Uri;
  curl_slist *headers_list = NULL;
  int code;
  
  ZorbaRestGetIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaRestGetIteratorState, state, planState);
  
  setupConnection(state, true);

  if (CONSUME(lUri,0) )
  {
    //TODO: raise an error
  }
  Uri = lUri->getStringValue()->str();

  if (theChildren.size() > 1)
    while (CONSUME(payload_data, 1))
      Uri = processGetPayload(payload_data, Uri);
  
  if (theChildren.size() > 2)
    while (CONSUME(headers, 2))
      processHeader(headers, &headers_list);

  curl_easy_setopt(state->EasyHandle, CURLOPT_URL, Uri.c_str());
  curl_easy_setopt(state->EasyHandle, CURLOPT_HTTPHEADER, headers_list );
  code = state->theStreamBuffer->multi_perform();
  processReply(result, planState, Uri, code, *state->headers, state->theStreamBuffer.getp());
  
  STACK_PUSH(true, state);
  curl_slist_free_all(headers_list);
  cleanupConnection(state);
  STACK_END (state);
}

bool ZorbaRestPostIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  static const char expect_buf[] = "Expect:";
  store::Item_t lUri, payload_data, headers;
  xqpString Uri;
  curl_httppost *first = NULL, *last = NULL;
  curl_slist *headers_list = NULL;
  int code;
  
  ZorbaRestGetIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaRestGetIteratorState, state, planState);
  
  setupConnection(state, false);

  if (CONSUME(lUri, 0) == false)
  {
    //TODO: raise an error
  }
  Uri = lUri->getStringValue()->str();

  if (theChildren.size() > 1)
    while (CONSUME(payload_data, 1))
      processPayload(payload_data, &first, &last);

  if (theChildren.size() > 2)
    while (CONSUME(headers, 2))
      processHeader(headers, &headers_list);
  
  curl_easy_setopt(state->EasyHandle, CURLOPT_URL, Uri.c_str());
  headers_list = curl_slist_append(headers_list , expect_buf);
  curl_easy_setopt(state->EasyHandle, CURLOPT_HTTPHEADER, headers_list );
  curl_easy_setopt(state->EasyHandle, CURLOPT_HTTPPOST, first);
  code = state->theStreamBuffer->multi_perform();
  processReply(result, planState, Uri, code, *state->headers, state->theStreamBuffer.getp());
  
  STACK_PUSH(true, state);
  curl_formfree(first);
  curl_slist_free_all(headers_list);
  cleanupConnection(state);
  STACK_END (state);
}


} /* namespace zorba */
