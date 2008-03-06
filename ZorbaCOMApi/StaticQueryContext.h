// StaticQueryContext.h : Declaration of the CStaticQueryContext

#pragma once
#include "resource.h"       // main symbols

#include "ZorbaCOMApi.h"
#include "zorba/common/api_shared_types.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

namespace zorba
{
  class StaticQueryContext;
};

// CStaticQueryContext

class ATL_NO_VTABLE CStaticQueryContext :
	public CComObjectRootEx<CComMultiThreadModel>,
//	public CComCoClass<CStaticQueryContext, &CLSID_StaticQueryContext>,
	public IDispatchImpl<IStaticQueryContext, &IID_IStaticQueryContext, &LIBID_ZorbaCOMApiLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
  zorba::StaticQueryContext_t wrapped_interface;
public:
	void setWrappedInterface(zorba::StaticQueryContext_t wrapped_interface)
	{
    this->wrapped_interface = wrapped_interface;
	}

//DECLARE_REGISTRY_RESOURCEID(IDR_STATICQUERYCONTEXT)


BEGIN_COM_MAP(CStaticQueryContext)
	COM_INTERFACE_ENTRY(IStaticQueryContext)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

  DECLARE_NOT_AGGREGATABLE( CStaticQueryContext )


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
  virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getInternalStaticQueryContextPtr( 
      /* [retval][out] */ VARIANT *internal_ptr);

};

//OBJECT_ENTRY_AUTO(__uuidof(StaticQueryContext), CStaticQueryContext)
