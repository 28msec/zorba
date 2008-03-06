// XQueryCOM.h : Declaration of the CXQueryCOM

#pragma once
#include "resource.h"       // main symbols

#include "ZorbaCOMApi.h"
#include "zorba/common/api_shared_types.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

namespace zorba
{
  class XQuery;
};

// CXQueryCOM

class ATL_NO_VTABLE CXQueryCOM :
	public CComObjectRootEx<CComMultiThreadModel>,
//	public CComObject<CXQueryCOM>,
	public IDispatchImpl<IXQuery, &IID_IXQuery, &LIBID_ZorbaCOMApiLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
  zorba::XQuery_t     wrapped_interface;
public:
	void setWrappedInterface(zorba::XQuery_t     wrapped_interface)
	{
    this->wrapped_interface = wrapped_interface;
	}

//DECLARE_REGISTRY_RESOURCEID(IDR_XQUERYCOM)


BEGIN_COM_MAP(CXQueryCOM)
	COM_INTERFACE_ENTRY(IXQuery)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

  DECLARE_NOT_AGGREGATABLE( CXQueryCOM )

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
    virtual HRESULT STDMETHODCALLTYPE getInternalXQueryPtr( 
    /* [retval][out] */ VARIANT *internal_ptr);
    virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE initExecution( 
        /* [in] */ IDynamicQueryContext *dctx);
    virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE serializeXMLtoBuffer( 
        /* [retval][out] */ BSTR *result);
    virtual HRESULT STDMETHODCALLTYPE getResultsAsDOM(/*[out, retval]*/ IXMLDOMDocument **dom_result);

};

//OBJECT_ENTRY_AUTO(__uuidof(XQueryCOM), CXQueryCOM)
