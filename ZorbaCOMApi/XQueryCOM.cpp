// XQueryCOM.cpp : Implementation of CXQueryCOM

#include "stdafx.h"
#include "XQueryCOM.h"
#include "zorba/compiled_xquery.h"
#include "zorba/dynamic_context.h"

#include <string>
#include <ostream>


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
HRESULT STDMETHODCALLTYPE CXQueryCOM::initExecution( 
    /* [in] */ IDynamicQueryContext *dctx)
{
  zorba::DynamicQueryContext  *dctx_interface = NULL;

  if(dctx)
  {
    VARIANT   wrapped_interf;
    dctx->getInternalDynamicQueryContextPtr(&wrapped_interf);
    dctx_interface = reinterpret_cast<zorba::DynamicQueryContext*>(wrapped_interf.pintVal);
  }
  if(!wrapped_interface->initExecution(dctx_interface))
    return E_FAIL;

  return S_OK;
}

/* [helpstring][id] */ 
HRESULT STDMETHODCALLTYPE CXQueryCOM::serializeXMLtoBuffer( 
    /* [retval][out] */ BSTR *result)
{
  std::ostringstream   oss;

  if(!result)
    return E_INVALIDARG;

  if(!wrapped_interface->serializeXML(oss))
    return E_FAIL;

  std::string   stross;

  stross = oss.str();
  CComBSTR    bstr(stross.c_str());
  *result = bstr.Detach();

  return S_OK;
}
