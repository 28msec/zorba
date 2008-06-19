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
// XQueryTreePlan.h : Declaration of the CXQueryTreePlan

#pragma once
#include "resource.h"       // main symbols

#include "ZorbaCOMApi.h"
#include "zorba/common/api_shared_types.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

namespace zorba
{
  class XQueryTreePlans;
}

// CXQueryTreePlan

class ATL_NO_VTABLE CXQueryTreePlan :
	public CComObjectRootEx<CComMultiThreadModel>,
//	public CComCoClass<CXQueryTreePlan, &CLSID_XQueryTreePlan>,
	public IDispatchImpl<IXQueryTreePlans, &IID_IXQueryTreePlans, &LIBID_ZorbaCOMApiLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
  zorba::XQueryTreePlans_t  wrapped_interface;
public:
	void setWrappedInterface(zorba::XQueryTreePlans_t wrapped_interface)
	{
    this->wrapped_interface = wrapped_interface;
	}

//DECLARE_REGISTRY_RESOURCEID(IDR_XQUERYTREEPLAN)


BEGIN_COM_MAP(CXQueryTreePlan)
	COM_INTERFACE_ENTRY(IXQueryTreePlans)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

  DECLARE_NOT_AGGREGATABLE( CXQueryTreePlan )


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
    virtual HRESULT STDMETHODCALLTYPE getInternalXQueryTreePlanPtr( 
    /* [retval][out] */ VARIANT *internal_ptr);

};

//OBJECT_ENTRY_AUTO(__uuidof(XQueryTreePlan), CXQueryTreePlan)
