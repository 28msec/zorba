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
 * rest-get Iterator
 *
 ****************************************************************************/

bool createQNameHelper(store::Item_t& result, xqpString name) 
{
  xqpString ns = ZORBA_REST_FN_NS;
  xqpString pre = "zorba-rest";
  return GENV_ITEMFACTORY->createQName(result, ns.getStore(), pre.getStore(), name.getStore());
}
    
bool createNodeHelper(store::Item_t parent, PlanState& planState, xqpString name, store::Item_t* result = NULL)
{
  store::Item_t qname, temp_result;
  store::NsBindings bindings;
  xqpStringStore_t baseUri = planState.theRuntimeCB->theStaticContext->final_baseuri().getStore();
  createQNameHelper(qname, name);
  
  bool status = GENV_ITEMFACTORY->createElementNode(
      temp_result,
      parent,
      -1,
      qname,
      GENV_TYPESYSTEM.XS_UNTYPED_QNAME,
      true,
      false,
      false,
      false,
      bindings,
      baseUri,
      false);

  if (result != NULL)
    *result = temp_result;
  
  return status;
}

bool createAttributeHelper(store::Item_t parent, xqpString name, xqpString value, store::Item_t* result = NULL)
{
  store::Item_t qname, temp_result, str_item;
  createQNameHelper(qname, name);
  store::Item_t type_qname;
  xqpString xs_ns = "http://www.w3.org/2001/XMLSchema";
  xqpString xs_pre = "xs";
  xqpString type_name = "string";
  GENV_ITEMFACTORY->createQName(type_qname, xs_ns.theStrStore, xs_pre.theStrStore, type_name.theStrStore);
  GENV_ITEMFACTORY->createString(str_item, value.theStrStore);
  GENV_ITEMFACTORY->createAttributeNode(
      temp_result,
      parent, 
      -1,
      qname,
      type_qname,
      str_item,
      false,
      false);

  if (result != NULL)
    *result = temp_result;
  
  return true;
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
  store::Item_t payload, headers_node, text_code, status_code;
  store::Item_t doc = NULL;

  createNodeHelper(NULL, planState, "result", &result); // status_code, headers_item, payload);

  createNodeHelper(result, planState, "status-code", &status_code);
  createNodeHelper(result, planState, "headers", &headers_node);
  createNodeHelper(result, planState, "payload", &payload);
  
    
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
        store::Item_t header, header_value;
        createNodeHelper(headers_node, planState, "header", &header);

        xqpString name_string = headers.operator[](i).substr(0, pos);
        createAttributeHelper(header, "name", name_string);
        
        string temp = headers.operator[](i).substr(pos+2);
        xqpString value_string = temp;
        GENV_ITEMFACTORY->createTextNode(header_value, header, -1, value_string.theStrStore);

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

  xqpString temp = NumConversions::intToStr(reply_code);
  GENV_ITEMFACTORY->createTextNode(text_code, status_code, -1, temp.theStrStore);

  if (reply_code >= 200 && reply_code < 300)
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
          temp = GENV_STORE.loadDocument(lUriString.theStrStore, is);
        }
        catch (...) {
          temp = NULL;
        }

        if (temp != NULL)
        {
          store::Iterator_t doc_children = temp->getChildren();
          doc_children->open();
          doc_children->next(doc);
          CopyMode copyMode;
          copyMode.theDoCopy = false;
          doc->copy(payload, -1, CopyMode());
        }
        else
        {
          // TODO: error
        }
      }
      break;
      
    case 2:  // text
      {
        store::Item_t temp_item;
        stringstream str;
        str << theStreamBuffer;
        xqpString temp = str.str();
        GENV_ITEMFACTORY->createTextNode(temp_item, payload, -1, temp.theStrStore);
      }
      break;

    case 1:  // base64
      {
        store::Item_t temp_item;
        xqp_base64Binary base64;
        std::istream is(theStreamBuffer);
        xqpString temp = Base64::encode(is);
        GENV_ITEMFACTORY->createTextNode(temp_item, payload, -1, temp.theStrStore);
      }
      break;
    }
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
    xqpString temp = xqpString(name->getStringValue()) + xqpString(": ") + child->getStringValue().getp();
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
  store::Item_t child, name, filename, content_type;

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

    if (xqpString("filename") == child->getNodeName()->getLocalName())
      filename = child;

    if (xqpString("content-type") == child->getNodeName()->getLocalName())
      content_type = child;
  }

  if (name.getp() == NULL)
    return; // TODO: signal error - payload part without an associated name

  if (filename.getp() != NULL)
  {
    if (content_type != NULL)
      curl_formadd(first, last,
                CURLFORM_COPYNAME, name->getStringValue()->c_str(),
                CURLFORM_FILE, filename->getStringValue()->c_str(),
                CURLFORM_CONTENTTYPE, content_type->getStringValue()->c_str(),
                CURLFORM_END);
    else curl_formadd(first, last,
                CURLFORM_COPYNAME, name->getStringValue()->c_str(),
                CURLFORM_FILE, filename->getStringValue()->c_str(),
                CURLFORM_END);
  }
  else
  {

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
}

static bool processSinglePayload(Item_t& payload_data, CURL* EasyHandle, curl_slist **headers_list, std::auto_ptr<char>& buffer)
{
  store::Iterator_t it;
  store::Item_t child, name, filename, content_type;

  if (payload_data->getNodeKind() != store::StoreConsts::elementNode)
    return false;

  if (xqpString("payload") != payload_data->getNodeName()->getLocalName())
    return false;

  it = payload_data->getAttributes();
  it->open();
  while (it->next(child))
  {
    if (xqpString("name") == child->getNodeName()->getLocalName())
      name = child;

    if (xqpString("filename") == child->getNodeName()->getLocalName())
      filename = child;

    if (xqpString("content-type") == child->getNodeName()->getLocalName())
      content_type = child;
  }

  if (content_type.getp() != NULL
      &&
      xqpString("multipart/form-data") == content_type->getStringValue().getp())
    return false;

  if (filename.getp() != NULL)
  {
    xqpString test = filename->getStringValue()->c_str();
    ifstream ifs(filename->getStringValue()->c_str());

    if (!ifs)
      return false; // TODO: generate error

    filebuf* pbuf = ifs.rdbuf();
    long size = pbuf->pubseekoff(0,ios::end,ios::in);
    pbuf->pubseekpos(0,ios::in);
    //std::auto_ptr<char> buffer = std::auto_ptr<char>(new char[size]);
    buffer = std::auto_ptr<char>(new char[size]);
    pbuf->sgetn(buffer.get(), size);

    curl_easy_setopt(EasyHandle, CURLOPT_POSTFIELDSIZE , size);
    curl_easy_setopt(EasyHandle, CURLOPT_POSTFIELDS, buffer.get());

    if (content_type.getp() == NULL)
      *headers_list = curl_slist_append(*headers_list, "Content-Type: application/octet-stream");

    ifs.close();
  }
  else
  {
    it = payload_data->getChildren();
    it->open();
    it->next(child);
    if (child->getNodeKind() == store::StoreConsts::textNode)
    {
      xqpStringStore* str = child->getStringValueP();
      buffer = std::auto_ptr<char>(new char[str->bytes()]);
      memcpy(buffer.get(), str->c_str(), str->bytes());

      // curl_easy_setopt(EasyHandle, CURLOPT_COPYPOSTFIELDS, str->c_str());
      curl_easy_setopt(EasyHandle, CURLOPT_POSTFIELDSIZE , str->bytes());
      curl_easy_setopt(EasyHandle, CURLOPT_POSTFIELDS, buffer.get());
      curl_easy_setopt(EasyHandle, CURLOPT_POST, 1);

      if (content_type.getp() == NULL)
        *headers_list = curl_slist_append(*headers_list, "Content-Type: text/plain");
    }
    else if (child->getNodeKind() == store::StoreConsts::elementNode)
    {
      stringstream ss;
      error::ErrorManager lErrorManager;
      serializer ser(&lErrorManager);
      ser.set_parameter("omit-xml-declaration","yes");
      ser.serialize(child, ss);
      buffer = std::auto_ptr<char>(new char[ss.str().size()]);
      memcpy(buffer.get(), ss.str().c_str(), ss.str().size());
      
      // curl_easy_setopt(EasyHandle, CURLOPT_COPYPOSTFIELDS, ss.str().c_str());
      curl_easy_setopt(EasyHandle, CURLOPT_POSTFIELDSIZE , ss.str().size());
      curl_easy_setopt(EasyHandle, CURLOPT_POSTFIELDS, buffer.get());
      curl_easy_setopt(EasyHandle, CURLOPT_POST, 1);

      if (content_type.getp() == NULL)
        *headers_list = curl_slist_append(*headers_list, "Content-Type: text/xml");
    }
    else
    {
      // TODO: process comments, pi nodes? or generate error?
      return false;
    }
  }

  if (content_type.getp() != NULL)
    *headers_list = curl_slist_append(*headers_list,
                                       (xqpString("Content-Type: ") + xqpString(content_type->getStringValue())).c_str());
  
  return true;
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
    // TODO: check if the name of parameter should be escaped too
    xqpStringStore_t value = child->getStringValue()->encodeForUri();
    
    if (Uri.indexOf("?") == -1)
      Uri = Uri + "?" + name->getStringValue()->str() + "=" + value.getp();
    else
      Uri = Uri + "&" + name->getStringValue()->str() + "=" + value.getp();
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
  std::auto_ptr<char> buffer;
  int code;
  bool single_payload = false;
  
  ZorbaRestGetIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaRestGetIteratorState, state, planState);
  
  setupConnection(state, false);

  if (CONSUME(lUri, 0) == false)
  {
    //TODO: raise an error
  }
  Uri = lUri->getStringValue()->str();

  if (theChildren.size() > 1)
  {
    store::Item_t payload_data;
    int status = CONSUME(payload_data, 1);

    if (status)
    {
      if (processSinglePayload(payload_data, state->EasyHandle, &headers_list, buffer))
      {
        single_payload = true;
      }
      else
      {
        processPayload(payload_data, &first, &last);
        while (CONSUME(payload_data, 1))
          processPayload(payload_data, &first, &last);
      }
    }
  }
  if (!single_payload)
    curl_easy_setopt(state->EasyHandle, CURLOPT_HTTPPOST, first);

  if (theChildren.size() > 2)
    while (CONSUME(headers, 2))
      processHeader(headers, &headers_list);
  
  curl_easy_setopt(state->EasyHandle, CURLOPT_URL, Uri.c_str());
  headers_list = curl_slist_append(headers_list , expect_buf);
  curl_easy_setopt(state->EasyHandle, CURLOPT_HTTPHEADER, headers_list );
  code = state->theStreamBuffer->multi_perform();
  processReply(result, planState, Uri, code, *state->headers, state->theStreamBuffer.getp());
  
  STACK_PUSH(true, state);
  curl_formfree(first);
  curl_slist_free_all(headers_list);
  cleanupConnection(state);
  STACK_END (state);
}


} /* namespace zorba */
