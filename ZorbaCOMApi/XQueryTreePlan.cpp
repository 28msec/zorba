// XQueryTreePlan.cpp : Implementation of CXQueryTreePlan

#include "stdafx.h"
#include "XQueryTreePlan.h"
#include "zorba/xquery_plan_print.h"

// CXQueryTreePlan

HRESULT STDMETHODCALLTYPE CXQueryTreePlan::getInternalXQueryTreePlanPtr( 
/* [retval][out] */ VARIANT *internal_ptr)
{
  internal_ptr->pintVal = (int*)&*wrapped_interface;
  internal_ptr->vt = VT_INT | VT_BYREF;

  return S_OK;
}

