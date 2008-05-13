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
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or  implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
// XQueryCOM.cpp : Implementation of CXQueryCOM

#include "stdafx.h"
#include "XQueryCOM.h"
#include "zorba/xquery.h"
#include "zorba/dynamic_context.h"
#include "zorba/exception.h"

#include <string>
#include <sstream>


// CXQueryCOM

/* [helpstring][id] */ 
HRESULT STDMETHODCALLTYPE CXQueryCOM::getInternalXQueryPtr( 
    /* [retval][out] */ VARIANT *internal_ptr)
{
  internal_ptr->pintVal = (int*)&*wrapped_interface;
  internal_ptr->vt = VT_INT | VT_BYREF;

  return S_OK;
}

/* [helpstring][id] */ 
//HRESULT STDMETHODCALLTYPE CXQueryCOM::initExecution( 
//    /* [in] */ IDynamicQueryContext *dctx)
//{
//  zorba::DynamicContext  *dctx_interface = NULL;
//
//  if(dctx)
//  {
//    VARIANT   wrapped_interf;
//    dctx->getInternalDynamicQueryContextPtr(&wrapped_interf);
//    dctx_interface = reinterpret_cast<zorba::DynamicContext*>(wrapped_interf.pintVal);
//  }
//  if(!wrapped_interface->initExecution(dctx_interface))
//    return E_FAIL;
//
//  return S_OK;
//}

/* [helpstring][id] */ 
HRESULT STDMETHODCALLTYPE CXQueryCOM::serializeXMLtoBuffer( 
    /* [retval][out] */ BSTR *result)
{
  std::ostringstream   oss;

  if(!result)
    return E_INVALIDARG;

  try{
  oss << wrapped_interface;
  }catch(zorba::ZorbaException &)
  {
    return E_FAIL;
  }

  std::string   stross;

  stross = oss.str();
  CComBSTR    bstr(stross.c_str());
  *result = bstr.Detach();

  return S_OK;
}

HRESULT STDMETHODCALLTYPE CXQueryCOM::getResultsAsDOM(/*[out, retval]*/ IXMLDOMDocument **dom_result)
{
  if(!dom_result)
    return E_INVALIDARG;

  //use MSXML to create the DOM view over the results
  HRESULT   hr;
  hr = CoCreateInstance(CLSID_DOMDocument, NULL, CLSCTX_ALL,//CLSCTX_INPROC_SERVER, 
       IID_IXMLDOMDocument, (void**)dom_result);

  if(hr != S_OK)
    return hr;


  //serialize all the result in a memory ostream
  std::ostringstream   oss;

  try{
    oss << wrapped_interface;
  }
  catch(zorba::ZorbaException &)
  {
    (*dom_result)->Release();
    return E_FAIL;
  }

  std::string   stross;

  stross = oss.str();
  CComBSTR    bstr_xml(stross.c_str());


  //do the DOM parse
  VARIANT_BOOL    is_successfull;
  hr = (*dom_result)->loadXML(bstr_xml, &is_successfull);
  if(!is_successfull)
  {
    (*dom_result)->Release();
    return hr;
  }

  return S_OK;
}
