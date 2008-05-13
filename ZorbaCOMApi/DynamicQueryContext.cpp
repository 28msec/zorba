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
// DynamicQueryContext.cpp : Implementation of CDynamicQueryContext

#include "stdafx.h"
#include "DynamicQueryContext.h"
#include "zorba/dynamic_context.h"
#include "utils.h"
#include <fstream>
#include "zorba/string.h"

// CDynamicQueryContext

/* [helpstring][id] */ 
HRESULT STDMETHODCALLTYPE CDynamicQueryContext::getInternalDynamicQueryContextPtr( 
    /* [retval][out] */ VARIANT *internal_ptr)
{
  internal_ptr->pintVal = (int*)&*wrapped_interface;
  internal_ptr->vt = VT_INT | VT_BYREF;

  return S_OK;
}

///* [helpstring][id] */ 
//HRESULT STDMETHODCALLTYPE CDynamicQueryContext::setVariableAsInt( 
//    /* [in] */ BSTR varname,
//    /* [in] */ int int_value)
//{
//  char  *utf8varname;
//  utf8varname = getUtf8String(varname);
//  if(!utf8varname)
//  {
//    return E_INVALIDARG;
//  }
//  
//  bool retbool = wrapped_interface->setVariableAsInt(utf8varname, int_value);
//  delete[] utf8varname;
//
//  return retbool ? S_OK : E_FAIL;
//}

//HRESULT STDMETHODCALLTYPE CDynamicQueryContext::setVariableAsString( BSTR varname, BSTR str_value)
//{
//  char  *utf8varname;
//  utf8varname = getUtf8String(varname);
//  if(!utf8varname)
//  {
//    return E_INVALIDARG;
//  }
//  char  *utf8str_value;
//  utf8str_value = getUtf8String(str_value);
//  if(!utf8str_value)
//  {
//    delete[] utf8varname;
//    return E_INVALIDARG;
//  }
//
//  bool retbool = wrapped_interface->setVariableAsString(utf8varname, utf8str_value);
//  delete[] utf8varname;
//  delete[] utf8str_value;
//
//  return retbool ? S_OK : E_FAIL;
//}

 /* [helpstring][id] */ 
HRESULT STDMETHODCALLTYPE CDynamicQueryContext::setVariableAsDocumentFromFile( 
    /* [in] */ BSTR varname,
    /* [in] */ BSTR file_path,
    /* [in] */ BSTR storeUri)
{
  char  *utf8varname;
  utf8varname = getUtf8String(varname);
  if(!utf8varname)
  {
    return E_INVALIDARG;
  }
  char  *utf8file_path;
  utf8file_path = getUtf8String(file_path);
  if(!utf8file_path)
  {
    delete[] utf8varname;
    return E_INVALIDARG;
  }
  char  *utf8storeUri;
  utf8storeUri = getUtf8String(storeUri);
  if(!utf8storeUri)
  {
    delete[] utf8varname;
    delete[] utf8file_path;
    return E_INVALIDARG;
  }
  
  COLE2CT    fpath(file_path);
  std::ifstream    fin(fpath);
//  bool retbool = wrapped_interface->setVariableAsDocumentFromFile(utf8varname, 
//                                                                  utf8file_path,
//                                                                  utf8storeUri);
  zorba::String    zstr_varname(utf8varname);
  zorba::String    zstr_storeUri(utf8storeUri);
  wrapped_interface->setVariableAsDocument(zstr_varname, zstr_storeUri, fin);

  delete[] utf8varname;
  delete[] utf8file_path;
  delete[] utf8storeUri;

  //return retbool ? S_OK : E_FAIL;
  return S_OK;
}

 /* [helpstring][id] */ 
//HRESULT STDMETHODCALLTYPE CDynamicQueryContext::deleteVariable( 
//    /* [in] */ BSTR varname)
//{
//  char  *utf8varname;
//  utf8varname = getUtf8String(varname);
//  if(!utf8varname)
//  {
//    return E_INVALIDARG;
//  }
//
//  bool retbool = wrapped_interface->deleteVariable(utf8varname);
//
//  return retbool ? S_OK : E_FAIL;
//}

 /* [helpstring][id] */ 
//HRESULT STDMETHODCALLTYPE CDynamicQueryContext::deleteAllVariables( void)
//{
//  wrapped_interface->deleteAllVariables();
//
//  return S_OK;
//}

 /* [helpstring][id] */ 
HRESULT STDMETHODCALLTYPE CDynamicQueryContext::setContextItemAsDocumentFromFile( 
    /* [in] */ BSTR file_path,
    /* [in] */ BSTR storeUri)
{
  char  *utf8file_path;
  utf8file_path = getUtf8String(file_path);
  if(!utf8file_path)
  {
    return E_INVALIDARG;
  }
  char  *utf8storeUri;
  utf8storeUri = getUtf8String(storeUri);
  if(!utf8storeUri)
  {
    delete[] utf8file_path;
    return E_INVALIDARG;
  }
  
  COLE2CT    fpath(file_path);
  std::ifstream    fin(fpath);
//  bool retbool = wrapped_interface->setContextItemAsDocumentFromFile(
//                                                                  utf8file_path,
//                                                                  utf8storeUri);
  wrapped_interface->setContextItemAsDocument(utf8storeUri, fin);

  delete[] utf8file_path;
  delete[] utf8storeUri;

  //return retbool ? S_OK : E_FAIL;
  return S_OK;
}
