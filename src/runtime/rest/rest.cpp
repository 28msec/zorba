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
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>

#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>

#include "zorbaerrors/error_manager.h"

#include "zorba/item.h"
#include "zorba/singleton_item_sequence.h"
#include "zorbatypes/datetime/parse.h"
#include "util/web/web.h"

#include "system/globalenv.h"

#include "api/serialization/serializer.h"
#include "api/serialization/serializable_wrapper.h"

#include "context/static_context.h"
#include "context/namespace_context.h"

#include "runtime/rest/rest.h"
#include "runtime/util/iterator_impl.h"
#include "runtime/api/runtimecb.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/iterator.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/api/copymode.h"

using namespace std;


namespace zorba {

using namespace store;

static const char expect_buf[] = "Expect:";

SERIALIZABLE_CLASS_VERSIONS(ZorbaRestHeadIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaRestHeadIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaRestGetIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaRestGetIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaRestPostIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaRestPostIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaRestPutIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaRestPutIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaRestDeleteIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaRestDeleteIterator)

/****************************************************************************
 *
 * CurlStreamBuffer
 *
 ****************************************************************************/
                   
CurlStreamBuffer::CurlStreamBuffer(CURLM* aMultiHandle, CURL* aEasyHandle)
  : std::streambuf(), MultiHandle(aMultiHandle), EasyHandle(aEasyHandle)
{
  CurlErrorBuffer = new char[CURLOPT_ERRORBUFFER];
  memset(CurlErrorBuffer, 0, CURLOPT_ERRORBUFFER);
  
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
  
  return error;
}

CurlStreamBuffer::~CurlStreamBuffer()
{
  delete[] CurlErrorBuffer;
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
  return EOF;
}

const char* CurlStreamBuffer::getErrorBuffer() const
{
  return CurlErrorBuffer;
}

bool createTypeHelper(store::Item_t& result, xqpString type_name)
{
  xqpString xs_ns = "http://www.w3.org/2001/XMLSchema";
  xqpString xs_pre = "xs";
  return GENV_ITEMFACTORY->createQName(result, xs_ns.theStrStore, xs_pre.theStrStore, type_name.theStrStore);
}

bool createQNameHelper(store::Item_t& result, xqpString name) 
{
  xqpString ns = ZORBA_REST_FN_NS;
  xqpString pre = "zorba-rest";
  return GENV_ITEMFACTORY->createQName(result, ns.getStore(), pre.getStore(), name.getStore());
}
    
bool createNodeHelper(store::Item_t parent,
    PlanState& planState,
    static_context* sctx,
    xqpString name,
    store::Item_t* result = NULL)
{
  store::Item_t qname, temp_result, type_qname;
  store::NsBindings bindings;
  xqpStringStore_t baseUri = sctx->final_baseuri().getStore();
  createQNameHelper(qname, name);
  createTypeHelper(type_qname, "untyped");
  bool status = GENV_ITEMFACTORY->createElementNode(
      temp_result,
      parent,
      -1,
      qname,
      type_qname,
      true,
      false,
      bindings,
      baseUri);

  if (result != NULL)
    *result = temp_result;
  
  return status;
}

bool createAttributeHelper(store::Item_t parent, xqpString name, xqpString value, store::Item_t* result = NULL)
{
  store::Item_t qname, temp_result, str_item;
  createQNameHelper(qname, name);
  store::Item_t type_qname;
  createTypeHelper(type_qname, "string");
  GENV_ITEMFACTORY->createString(str_item, value.theStrStore);
  GENV_ITEMFACTORY->createAttributeNode(
      temp_result,
      parent, 
      -1,
      qname,
      type_qname,
      str_item);

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

#ifdef ZORBA_WITH_TIDY
static int readSome(std::istream& stream, char *buffer, int maxlen) {
  stream.read(buffer, maxlen);
  return stream.gcount();
}
#endif

int processReply(const QueryLoc& aLoc,
                 store::Item_t& result,
                 PlanState& planState,
                 static_context* sctx,
                 xqpString& lUriString,
                 int code,
                 std::vector<std::string>& headers,
                 CurlStreamBuffer* theStreamBuffer,
                 const char* tidyUserOpt,
                 bool ignore_payload = false) 
{
  int reply_code;
  xqpString content_type;
  store::Item_t payload, error_node, headers_node, text_code, status_code;
  store::Item_t doc = NULL;

  createNodeHelper(NULL, planState, sctx, "result", &result); 
  createNodeHelper(result, planState, sctx, "status-code", &status_code);
  if (headers.size() == 0)
  { 
    // No headers -- create error message node
    xqpStringStore_t temp = new xqpStringStore(theStreamBuffer->getErrorBuffer());
    createNodeHelper(result, planState, sctx, "error-message", &error_node);
    GENV_ITEMFACTORY->createTextNode(text_code, error_node, -1, temp);
  }
  createNodeHelper(result, planState, sctx, "headers", &headers_node);
  if (!ignore_payload)
    createNodeHelper(result, planState, sctx, "payload", &payload);

  if (headers.size() == 0)
  {
	// No headers, use cURL's error code.
    reply_code = code; 
  }
  else
  {
    if (parse_int_const_position<int>(headers.operator[](0), 9, reply_code, 1))
    {
	  // No status code in the reply. Put a -1 in there.
      reply_code = -1; 
    }

    for (unsigned int i = 1; i < headers.size(); i++)
    {
      int pos = headers.operator[](i).find(':');
      if (pos > -1)
      {
        store::Item_t header, header_value;
        createNodeHelper(headers_node, planState, sctx, "header", &header);

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
        // invalid header, ignore it
      }
    }
  }

  xqpString temp = NumConversions::intToStr(reply_code);
  GENV_ITEMFACTORY->createTextNode(text_code, status_code, -1, temp.theStrStore);

  // Always add payload to response (not only in case of a successful request)
  // Payload in case of errors usually contains detailed error message
  if ((!ignore_payload) /*&& reply_code >= 200 && reply_code < 300*/)
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
    else if (content_type.indexOf("text/html") == 0)
      doc_type = 2;
    else if (content_type.indexOf("text/") == 0)
      doc_type = 2;
    else
      doc_type = 1;

    switch (doc_type)
    {
    case 4:
      {
        store::Item_t temp;

        if(tidyUserOpt == NULL)
        {
          std::istream is(theStreamBuffer);
          try {
            temp = GENV_STORE.loadDocument(lUriString.theStrStore, is, false);
          }
          catch(error::ZorbaError& lError) {
            ZORBA_ERROR_LOC_DESC(lError.theErrorCode, aLoc, "Malformed REST response.");
          }
        }
        else
        {
#ifdef ZORBA_WITH_TIDY
          std::string         input;
          char                lBuf[1024];
          int                 lRes = 0;
          xqp_string          diag, strOut;

          std::istream lStream(theStreamBuffer);
          while ( (lRes = readSome(lStream, lBuf, 1023)) > 0 ) {
            lBuf[lRes] = 0;
            input += lBuf;
          }

          int res = tidy(input.c_str(), strOut, diag, (NULL != tidyUserOpt? tidyUserOpt: NULL));
          if( res < 0){
            ZORBA_ERROR_DESC_OSS(API0036_TIDY_ERROR, diag.c_str());
          }

          std::istringstream is(strOut, istringstream::in);
#else
		      std::istream is(theStreamBuffer);
#endif
          temp = GENV_STORE.loadDocument(lUriString.theStrStore, is, false);
        }
        
        if (temp != NULL)
        {
          store::Iterator_t doc_children = temp->getChildren();
          doc_children->open();
          CopyMode copyMode;
          copyMode.theDoCopy = false;
          while (doc_children->next(doc))
            doc->copy(payload, -1, copyMode);
        }
        else
        {
          // xml could not parsed
          ZORBA_ERROR(STR0021_LOADER_PARSING_ERROR);
        }
      }
      break;
    case 3:  // xml
      {
        store::Item_t temp;
        std::istream is(theStreamBuffer);
        temp = GENV_STORE.loadDocument(lUriString.theStrStore, is, false);
		    if (temp != NULL)
        {
          store::Iterator_t doc_children = temp->getChildren();
          doc_children->open();
          CopyMode copyMode;
          copyMode.theDoCopy = false;
          while (doc_children->next(doc)) {
            doc->copy(payload, -1, copyMode);
          }
        }
        else
        {
          // xml could not be parsed
          ZORBA_ERROR(STR0021_LOADER_PARSING_ERROR);
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
  if (temp.size() > 0)
  {
    if (temp[temp.size()-1] == 0x0D)  // delete the 0xD at the end.
      temp.erase(temp.end()-1);
    state->headers->push_back(temp);        
    // std::cout << "header: " << temp << std::endl;
  }
  
  return size * nmemb;
}

static void setupConnection(ZorbaRestGetIteratorState* state, int get_method)
{
  state->MultiHandle = curl_multi_init(); 
  state->EasyHandle = curl_easy_init();

  curl_easy_setopt(state->EasyHandle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
  curl_easy_setopt(state->EasyHandle, CURLOPT_HEADERFUNCTION, getHeaderData);
  curl_easy_setopt(state->EasyHandle, CURLOPT_WRITEHEADER, state);
  
  if (get_method == 0)
    curl_easy_setopt(state->EasyHandle, CURLOPT_HTTPGET, 1);
  else if (get_method == 1)
    curl_easy_setopt(state->EasyHandle, CURLOPT_HTTPPOST, 1);
  else if (get_method == 2)
    curl_easy_setopt(state->EasyHandle, CURLOPT_CUSTOMREQUEST, "PUT");
  else if (get_method == 3)
    curl_easy_setopt(state->EasyHandle, CURLOPT_CUSTOMREQUEST, "DELETE");
  else if (get_method == 4)
    curl_easy_setopt(state->EasyHandle, CURLOPT_CUSTOMREQUEST, "HEAD");
  
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
  {
	  // top node should be element node
    ZORBA_ERROR(API0050_REST_ERROR_HEADER);
    return;
  }

  if (xqpString("headers") == headers->getNodeName()->getLocalName())
  {
    it = headers->getChildren();
    it->open();
    while (it->next(child) && child)
      processHeader(child, headers_list);
    return;
  }

  it = headers->getAttributes();
  it->open();
  while (it->next(child) && child)
  {
    if (xqpString("name") == child->getNodeName()->getLocalName())
      name = child;
  }

  if (name.getp() == NULL)
  {
    // header without an associated name
    ZORBA_ERROR(API0050_REST_ERROR_HEADER);
	return;
  }

  it = headers->getChildren();
  it->open();
  it->next(child);
  if (child == NULL)
  {
    // HTTP header without a value 
    xqpString temp = xqpString(name->getStringValue()) + xqpString(": ");
    *headers_list = curl_slist_append(*headers_list , temp.c_str());
  }
  else if (child->getNodeKind() == store::StoreConsts::textNode)
  {
    xqpString temp = xqpString(name->getStringValue()) + xqpString(": ") + child->getStringValue().getp();
    *headers_list = curl_slist_append(*headers_list , temp.c_str());
  }
  else 
  {
	  ZORBA_ERROR(API0050_REST_ERROR_HEADER);
  }
}

// Returns all the children of a node as a concatenated string (text nodes + serialized 
// element nodes) in the children_string out-paramter, and sets the has_element_child flag
static void getSerializedChildren(store::Item_t node, xqpString& children_string, bool& has_element_child)
{
  store::Iterator_t it;
  store::Item_t lChild;
  children_string = "";
  has_element_child = false;
  
  it = node->getChildren();
  it->open();
  while (it->next(lChild) && lChild)
  {
    if (lChild->getNodeKind() == store::StoreConsts::textNode)
    {
      children_string += xqpString(lChild->getStringValue());
    }
    else if (lChild->getNodeKind() == store::StoreConsts::elementNode)
    {
      stringstream ss;
      error::ErrorManager lErrorManager;
      serializer ser(&lErrorManager);
      ser.setParameter("omit-xml-declaration", "yes");

      // Build a singleton item sequence and wrap it in a Serializable.
      // The new serializer interface only accepts Serializable objects.
      const zorba::Item lItem(lChild);
      SingletonItemSequence lSequence(lItem);
      intern::SerializableWrapper lWrapper(&lSequence);
      ser.serialize(&lWrapper, ss);

      children_string += ss.str().c_str();        
      has_element_child = true;
    }
	// ignore other nodes
  }
}

// Takes a <part name="name">value</part> element, and returns it as a "name=value",
// URI encoding both members of the pair
static xqpString buildKeyValuePair(Item_t& payload_data)
{
  store::Iterator_t it;
  store::Item_t child, name;
  xqpString result;
  
  if (payload_data->getNodeKind() != store::StoreConsts::elementNode)
  {
    ZORBA_ERROR(API0051_REST_ERROR_PAYLOAD);
    return result;
  }

  it = payload_data->getAttributes();
  it->open();
  while (it->next(child) && child)
  {
    if ((xqpString("name") == child->getNodeName()->getLocalName()))
      name = child;
  }

  if (name.getp() == NULL)
  {
    // payload part without an associated name
    ZORBA_ERROR(API0051_REST_ERROR_PAYLOAD);
    return result;
  }

  result = result + xqpString(name->getStringValue()->encodeForUri());

  it = payload_data->getChildren();
  it->open();
  it->next(child);
  if (child && (child->getNodeKind() == store::StoreConsts::textNode))
    result += "=" + xqpString(child->getStringValue()->encodeForUri());

  return result;
}

// Takes a <payload> node, with <part name1="name">value</part>... children,
// iterates through the children and returns a string of the form name1=value&name2=value
static xqpString buildChildrenURL(Item_t& payload_data)
{
  store::Iterator_t it;
  store::Item_t child;
  xqpString result;

  it = payload_data->getChildren();
  it->open();
  while (it->next(child))
    if (child && (child->getNodeKind() == store::StoreConsts::elementNode))
    {
      if (result.bytes() > 0)
        result += "&";
      result += buildKeyValuePair(child);
    }
    
  return result;
}

typedef enum {
  PAYLOAD_TYPE_MULTIPART_FORMDATA,
  PAYLOAD_TYPE_URLENCODED
} PAYLOAD_TYPE;

static PAYLOAD_TYPE processPayload(Item_t& payload_data, struct curl_httppost** first, struct curl_httppost** last, xqpString& constructedURL)
{
  store::Iterator_t it;
  store::Item_t child, name, filename, content_type;

  // top node should be an element node
  if (payload_data->getNodeKind() != store::StoreConsts::elementNode)
  {
    ZORBA_ERROR(API0051_REST_ERROR_PAYLOAD);
    return PAYLOAD_TYPE_MULTIPART_FORMDATA; 
  }

  it = payload_data->getAttributes();
  it->open();
  while (it->next(child) && child)
  {
    if (xqpString("name") == child->getNodeName()->getLocalName())
      name = child;

    if (xqpString("filename") == child->getNodeName()->getLocalName())
      filename = child;

    if (xqpString("content-type") == child->getNodeName()->getLocalName())
      content_type = child;
  }

  if (xqpString("payload") == payload_data->getNodeName()->getLocalName())
  {
    if (content_type.getp() != NULL
        &&
        xqpString("application/x-www-form-urlencoded") == content_type->getStringValue()->c_str())
    {
      constructedURL = buildChildrenURL(payload_data);
      return PAYLOAD_TYPE_URLENCODED;
    }
    else
    {
      it = payload_data->getChildren();
      it->open();
      while (it->next(child) && child)
        if (child->getNodeKind() == store::StoreConsts::elementNode)
          processPayload(child, first, last, constructedURL);
      return PAYLOAD_TYPE_MULTIPART_FORMDATA;
    }
  }

  if (name.getp() == NULL)
  {
    // payload part without an associated name
    ZORBA_ERROR(API0051_REST_ERROR_PAYLOAD);
    return PAYLOAD_TYPE_MULTIPART_FORMDATA; 
  }

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
    xqpString payload_string;
    bool has_element_child;
    getSerializedChildren(payload_data, payload_string, has_element_child);

    if (has_element_child)
    {
      curl_formadd(first, last,
                  CURLFORM_COPYNAME, name->getStringValue()->c_str(),
                  CURLFORM_COPYCONTENTS, payload_string.c_str(),
                  CURLFORM_CONTENTTYPE, "text/html",
                  CURLFORM_END);
    }
    else
    {
      curl_formadd(first, last,
                  CURLFORM_COPYNAME, name->getStringValue()->c_str(),
                  CURLFORM_COPYCONTENTS, payload_string.c_str(),
                  CURLFORM_END);
    }
  }

  return PAYLOAD_TYPE_MULTIPART_FORMDATA;
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
  while (it->next(child) && child)
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
      (xqpString("multipart/form-data") == content_type->getStringValue().getp()
      ||
      xqpString("application/x-www-form-urlencoded") == content_type->getStringValue()->c_str()))
    return false;

  if (filename.getp() != NULL)
  {
    xqpString test = filename->getStringValue()->c_str();
    ifstream ifs(filename->getStringValue()->c_str());
    
    if (!ifs)
    {
      ZORBA_ERROR(API0051_REST_ERROR_PAYLOAD);
      return false;
    }

    filebuf* pbuf = ifs.rdbuf();
    long size = pbuf->pubseekoff(0,ios::end,ios::in);
    pbuf->pubseekpos(0,ios::in);    
    buffer = std::auto_ptr<char>(new char[size]);
#ifdef WIN32
    pbuf->_Sgetn_s(buffer.get(), size, size);
#else
    pbuf->sgetn(buffer.get(), size);
#endif

    curl_easy_setopt(EasyHandle, CURLOPT_POSTFIELDSIZE , size);
    curl_easy_setopt(EasyHandle, CURLOPT_POSTFIELDS, buffer.get());

    if (content_type.getp() == NULL)
      *headers_list = curl_slist_append(*headers_list, "Content-Type: application/octet-stream");

    ifs.close();
  }
  else
  {
    xqpString payload_string;
    bool has_element_child;
    getSerializedChildren(payload_data, payload_string, has_element_child);

    buffer = std::auto_ptr<char>(new char[payload_string.bytes()]);
    memcpy(buffer.get(), payload_string.c_str(), payload_string.bytes());

    curl_easy_setopt(EasyHandle, CURLOPT_POSTFIELDSIZE , payload_string.bytes());
    curl_easy_setopt(EasyHandle, CURLOPT_POSTFIELDS, buffer.get());
    curl_easy_setopt(EasyHandle, CURLOPT_POST, 1);

    if (content_type.getp() == NULL)
    {
      if (has_element_child)
        *headers_list = curl_slist_append(*headers_list, "Content-Type: text/xml");
      else
        *headers_list = curl_slist_append(*headers_list, "Content-Type: text/plain");
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
  {
    // top node should be element node
    ZORBA_ERROR(API0051_REST_ERROR_PAYLOAD);
    return Uri; 
  }

  if (xqpString("payload") == payload_data->getNodeName()->getLocalName())
  {
    if (Uri.indexOf("?") == -1)
      Uri += "?";
    else
      Uri += "&";
    Uri += buildChildrenURL(payload_data);
  }

  return Uri;
}

/****************************************************************************
 *
 * rest-head Iterator
 *
 ****************************************************************************/
bool ZorbaRestHeadIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item, lUri, payload_data, headers, tidyUserOpt;
  xqpString Uri;
  curl_slist *headers_list = NULL;
  int code;
  unsigned int index = 1;
  
  ZorbaRestGetIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaRestGetIteratorState, state, planState);

  setupConnection(state, 4);

  if (CONSUME(lUri,0) == false)
  {
    ZORBA_ERROR_DESC(XQP0020_INVALID_URI, "No URI given to the REST head() function.");
  }

  Uri = lUri->getStringValue()->str();

  if (theChildren.size() > index)
    while (CONSUME(payload_data, index))
      Uri = processGetPayload(payload_data, Uri);

  if (theChildren.size() > (index + 1))
    while (CONSUME(headers, (index + 1)))
      processHeader(headers, &headers_list);

  curl_easy_setopt(state->EasyHandle, CURLOPT_URL, Uri.c_str());
  curl_easy_setopt(state->EasyHandle, CURLOPT_HTTPHEADER, headers_list );
#ifndef ZORBA_VERIFY_PEER_SSL_CERTIFICATE//default is to not verify root certif
  curl_easy_setopt(state->EasyHandle, CURLOPT_SSL_VERIFYPEER, 0);
  //but CURLOPT_SSL_VERIFYHOST is left default, value 2, meaning verify that
  //the Common Name or Subject Alternate Name field in the certificate matches the name of the server
  //tested with https://www.npr.org/rss/rss.php?id=1001
  //about using ssl certs in curl: http://curl.haxx.se/docs/sslcerts.html
#else
  #if defined WIN32
  //set the root CA certificates file path
  if(GENV.g_curl_root_CA_certificates_path[0])
    curl_easy_setopt(state->EasyHandle, CURLOPT_CAINFO, GENV.g_curl_root_CA_certificates_path);
  #endif
#endif
  code = state->theStreamBuffer->multi_perform();
  processReply(loc,
               result,
               planState,
               theSctx,
               Uri,
               code,
               *state->headers,
               state->theStreamBuffer.getp(),
               (tidyUserOpt!=NULL)?tidyUserOpt->getStringValue()->c_str():NULL, true);

  curl_slist_free_all(headers_list);
  cleanupConnection(state);
  STACK_PUSH(true, state);
  STACK_END (state);
}

NARY_ACCEPT(ZorbaRestHeadIterator);



bool ZorbaRestGetIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item, lUri, payload_data, headers, tidyUserOpt;
  xqpString Uri;
  curl_slist *headers_list = NULL;
  int code;
  unsigned int index = 1;
  
  ZorbaRestGetIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaRestGetIteratorState, state, planState);

  setupConnection(state, 0);

  if (CONSUME(lUri,0) == false)
  {
    ZORBA_ERROR_DESC(XQP0020_INVALID_URI, "No URI given to the REST get() function.");
  }

  Uri = lUri->getStringValue()->str();

#ifdef ZORBA_WITH_TIDY
  if(isGetTidy)
  {
    index = 2;
    if (theChildren.size() > 1)
      CONSUME(tidyUserOpt, 1);
  }
#endif

  if (theChildren.size() > index)
    while (CONSUME(payload_data, index))
      Uri = processGetPayload(payload_data, Uri);

  if (theChildren.size() > (index + 1))
    while (CONSUME(headers, (index + 1)))
      processHeader(headers, &headers_list);

  curl_easy_setopt(state->EasyHandle, CURLOPT_URL, Uri.c_str());
  curl_easy_setopt(state->EasyHandle, CURLOPT_HTTPHEADER, headers_list );
#ifndef ZORBA_VERIFY_PEER_SSL_CERTIFICATE//default is to not verify root certif
  curl_easy_setopt(state->EasyHandle, CURLOPT_SSL_VERIFYPEER, 0);
  //but CURLOPT_SSL_VERIFYHOST is left default, value 2, meaning verify that
  //the Common Name or Subject Alternate Name field in the certificate matches the name of the server
  //tested with https://www.npr.org/rss/rss.php?id=1001
  //about using ssl certs in curl: http://curl.haxx.se/docs/sslcerts.html
#else
  #if defined WIN32
  //set the root CA certificates file path
  if(GENV.g_curl_root_CA_certificates_path[0])
    curl_easy_setopt(state->EasyHandle, CURLOPT_CAINFO, GENV.g_curl_root_CA_certificates_path);
  #endif
#endif
  code = state->theStreamBuffer->multi_perform();
  processReply(loc,
               result,
               planState,
               theSctx,
               Uri,
               code,
               *state->headers,
               state->theStreamBuffer.getp(),
               (tidyUserOpt!=NULL)?tidyUserOpt->getStringValue()->c_str():NULL);

  curl_slist_free_all(headers_list);
  cleanupConnection(state);
  STACK_PUSH(true, state);
  STACK_END (state);
}

NARY_ACCEPT(ZorbaRestGetIterator);

bool ZorbaRestPostIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUri, payload_data, headers, tidyUserOpt;
  xqpString Uri;
  curl_httppost *first = NULL, *last = NULL;
  curl_slist *headers_list = NULL;
  std::auto_ptr<char> buffer;
  int code;
  unsigned int index = 1;
  bool single_payload = false;
  PAYLOAD_TYPE payload_type = PAYLOAD_TYPE_MULTIPART_FORMDATA;
  xqpString constructedURL;
  
  ZorbaRestGetIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaRestGetIteratorState, state, planState);
  
  setupConnection(state, 1);

  if (CONSUME(lUri, 0) == false)
  {
    ZORBA_ERROR_DESC(XQP0020_INVALID_URI, "No URI given to the REST post() function.");
  }
  Uri = lUri->getStringValue()->str();

#ifdef ZORBA_WITH_TIDY
  if(isPostTidy)
  {
    index = 2;
    if(theChildren.size() > 1)
      CONSUME(tidyUserOpt, 1);
  }
#endif
  
  if (theChildren.size() > index)
  {
    store::Item_t payload_data;
    int status = CONSUME(payload_data, index);

    if (status)
    {
      if (processSinglePayload(payload_data, state->EasyHandle, &headers_list, buffer))
      {
        single_payload = true;
      }
      else
      {
        payload_type = processPayload(payload_data, &first, &last, constructedURL);
        while (CONSUME(payload_data, index))
          payload_type = processPayload(payload_data, &first, &last, constructedURL);
      }
    }
  }

  if (single_payload == false)
    curl_easy_setopt(state->EasyHandle, CURLOPT_HTTPPOST, first);

  if (theChildren.size() > (index+1))
    while (CONSUME(headers, (index+1)))
      processHeader(headers, &headers_list);
  
  if (payload_type == PAYLOAD_TYPE_URLENCODED)
    Uri += "?" + constructedURL;

  curl_easy_setopt(state->EasyHandle, CURLOPT_URL, Uri.c_str());
  headers_list = curl_slist_append(headers_list , expect_buf);
  curl_easy_setopt(state->EasyHandle, CURLOPT_HTTPHEADER, headers_list );
#ifndef ZORBA_VERIFY_PEER_SSL_CERTIFICATE//default is to not verify root certif
  curl_easy_setopt(state->EasyHandle, CURLOPT_SSL_VERIFYPEER, 0);
  //but CURLOPT_SSL_VERIFYHOST is left default, value 2, meaning verify that
  //the Common Name or Subject Alternate Name field in the certificate matches the name of the server
  //tested with https://www.npr.org/rss/rss.php?id=1001
  //about using ssl certs in curl: http://curl.haxx.se/docs/sslcerts.html
#else
#  if defined WIN32
  //set the root CA certificates file path
  if(GENV.g_curl_root_CA_certificates_path[0])
    curl_easy_setopt(state->EasyHandle, CURLOPT_CAINFO, GENV.g_curl_root_CA_certificates_path);
#  endif
#endif
  code = state->theStreamBuffer->multi_perform();
  processReply(loc,
      result,
      planState,
      theSctx,
      Uri,
      code,
      *state->headers,
      state->theStreamBuffer.getp(),
      (tidyUserOpt!=NULL)?tidyUserOpt->getStringValue()->c_str():NULL);
  
  curl_formfree(first);
  curl_slist_free_all(headers_list);
  cleanupConnection(state);
  STACK_PUSH(true, state);
  STACK_END (state);
}


NARY_ACCEPT(ZorbaRestPostIterator);


bool ZorbaRestPutIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUri, payload_data, headers;
  xqpString Uri;
  curl_httppost *first = NULL, *last = NULL;
  curl_slist *headers_list = NULL;
  std::auto_ptr<char> buffer;
  int code;
  bool single_payload = false;
  xqpString constructedURL;
  
  ZorbaRestGetIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaRestGetIteratorState, state, planState);
  
  setupConnection(state, 2);

  if (CONSUME(lUri, 0) == false)
  {
    ZORBA_ERROR_DESC(XQP0020_INVALID_URI, "No URI given to the REST put() function.");
  }
  Uri = lUri->getStringValue()->str();

  if (theChildren.size() > 1)
  {
    store::Item_t payload_data;
    int status = CONSUME(payload_data, 1);

    if (status)
    {
      // TODO processSinglePayload and processPayload should be unified. So should be the POST PUT and DELETE Iterators
      if (processSinglePayload(payload_data, state->EasyHandle, &headers_list, buffer))
      {
        single_payload = true;
      }
      else
      {
        processPayload(payload_data, &first, &last, constructedURL);
        while (CONSUME(payload_data, 1))
          processPayload(payload_data, &first, &last, constructedURL);
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
#ifndef ZORBA_VERIFY_PEER_SSL_CERTIFICATE//default is to not verify root certif
  curl_easy_setopt(state->EasyHandle, CURLOPT_SSL_VERIFYPEER, 0);
  //but CURLOPT_SSL_VERIFYHOST is left default, value 2, meaning verify that
  //the Common Name or Subject Alternate Name field in the certificate matches the name of the server
  //tested with https://www.npr.org/rss/rss.php?id=1001
  //about using ssl certs in curl: http://curl.haxx.se/docs/sslcerts.html
#else
#  if defined WIN32
  //set the root CA certificates file path
  if(GENV.g_curl_root_CA_certificates_path[0])
    curl_easy_setopt(state->EasyHandle, CURLOPT_CAINFO, GENV.g_curl_root_CA_certificates_path);
#  endif
#endif
  code = state->theStreamBuffer->multi_perform();
  processReply(loc,
      result,
      planState,
      theSctx,
      Uri,
      code,
      *state->headers,
      state->theStreamBuffer.getp(),
      NULL);
  
  curl_formfree(first);
  curl_slist_free_all(headers_list);
  cleanupConnection(state);
  STACK_PUSH(true, state);
  STACK_END (state);
}


NARY_ACCEPT(ZorbaRestPutIterator);


bool ZorbaRestDeleteIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUri, payload_data, headers;
  xqpString Uri;
  curl_slist *headers_list = NULL;
  int code;
  
  ZorbaRestGetIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaRestGetIteratorState, state, planState);
  
  setupConnection(state, 3);

  if (CONSUME(lUri,0) == false)
  {
    ZORBA_ERROR_DESC(XQP0020_INVALID_URI, "No URI given to the REST delete() function.");;
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
#ifndef ZORBA_VERIFY_PEER_SSL_CERTIFICATE//default is to not verify root certif
  curl_easy_setopt(state->EasyHandle, CURLOPT_SSL_VERIFYPEER, 0);
  //but CURLOPT_SSL_VERIFYHOST is left default, value 2, meaning verify that the Common Name or Subject Alternate Name field in the certificate matches the name of the server
  //tested with https://www.npr.org/rss/rss.php?id=1001
  //about using ssl certs in curl: http://curl.haxx.se/docs/sslcerts.html
#else
#if defined WIN32
  //set the root CA certificates file path
  if(GENV.g_curl_root_CA_certificates_path[0])
    curl_easy_setopt(state->EasyHandle, CURLOPT_CAINFO, GENV.g_curl_root_CA_certificates_path);
#endif
#endif
  code = state->theStreamBuffer->multi_perform();
  processReply(loc,
      result,
      planState,
      theSctx,
      Uri,
      code,
      *state->headers,
      state->theStreamBuffer.getp(),
      NULL,
      true);
  
  curl_slist_free_all(headers_list);
  cleanupConnection(state);
  STACK_PUSH(true, state);
  STACK_END (state);
}

NARY_ACCEPT(ZorbaRestDeleteIterator);

} /* namespace zorba */
