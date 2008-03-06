// StaticQueryContext.cpp : Implementation of CStaticQueryContext

#include "stdafx.h"
#include "StaticQueryContext.h"
#include "zorba/static_context.h"


// CStaticQueryContext

/* [helpstring][id] */ 
HRESULT STDMETHODCALLTYPE CStaticQueryContext::getInternalStaticQueryContextPtr( 
    /* [retval][out] */ VARIANT *internal_ptr)
{
  internal_ptr->pintVal = (int*)&*wrapped_interface;
  internal_ptr->vt = VT_INT | VT_BYREF;

  return S_OK;
}
