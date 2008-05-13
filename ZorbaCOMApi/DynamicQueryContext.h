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
// DynamicQueryContext.h : Declaration of the CDynamicQueryContext

#pragma once
#include "resource.h"       // main symbols

#include "ZorbaCOMApi.h"
#include "zorba/api_shared_types.h"




// CDynamicQueryContext

class ATL_NO_VTABLE CDynamicQueryContext :
	public CComObjectRootEx<CComMultiThreadModel>,
//	public CComCoClass<CDynamicQueryContext, &CLSID_DynamicQueryContext>,
	public IDispatchImpl<IDynamicQueryContext, &IID_IDynamicQueryContext, &LIBID_ZorbaCOMApiLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
  zorba::DynamicContext_t wrapped_interface;
public:
	void setWrappedInterface(zorba::DynamicContext_t wrapped_interface)
	{
    this->wrapped_interface = wrapped_interface;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DYNAMICQUERYEXECUTION)

DECLARE_NOT_AGGREGATABLE(CDynamicQueryContext)

BEGIN_COM_MAP(CDynamicQueryContext)
	COM_INTERFACE_ENTRY(IDynamicQueryContext)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}
public:
  virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getInternalDynamicQueryContextPtr( 
      /* [retval][out] */ VARIANT *internal_ptr);

  //virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setVariableAsInt( 
  //    /* [in] */ BSTR varname,
  //    /* [in] */ int int_value);
  
  //virtual HRESULT STDMETHODCALLTYPE setVariableAsString( BSTR varname, BSTR str_value);

  virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setVariableAsDocumentFromFile( 
      /* [in] */ BSTR varname,
      /* [in] */ BSTR file_path,
      /* [in] */ BSTR storeUri);
  
  //virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE deleteVariable( 
  //    /* [in] */ BSTR varname);
  //
  //virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE deleteAllVariables( void);
  
  virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setContextItemAsDocumentFromFile( 
      /* [in] */ BSTR file_path,
      /* [in] */ BSTR storeUri);
};

//OBJECT_ENTRY_AUTO(__uuidof(DynamicQueryContext), CDynamicQueryContext)
