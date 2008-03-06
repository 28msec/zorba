// ZorbaSingleThread.cpp : Implementation of CZorbaSingleThread

#include "stdafx.h"
#include "ZorbaSingleThread.h"
#include "zorba/zorba_singlethread.h"
#include "XQueryCOM.h"
#include "DynamicQueryContext.h"

// CZorbaSingleThread

/* [helpstring][id] */ 
HRESULT STDMETHODCALLTYPE CZorbaSingleThread::createQuery( 
    /* [in] */ BSTR aQueryString,
    /* [in] */ IStaticQueryContext *sctx,
    /* [in] */ BSTR xquery_source_uri,
    /* [in] */ VARIANT_BOOL routing_mode,
    /* [in] */ IXQueryTreePlans *tree_plans,
    /* [retval][out] */ IXQuery **ret_xquery)
{
  zorba::XQuery_t    xq;
  zorba::StaticQueryContext   *sctx_interf = NULL;
  zorba::XQueryTreePlans      *tree_plans_interf = NULL;
  VARIANT   wrapped_interf;
  UINT    aQueryStringLen;
  UINT    xquery_source_uriLen;
  char    *utf8Query = NULL;
  char    *utf8source = NULL;
  
  if(ret_xquery == NULL)
    return E_INVALIDARG;

  if(sctx)
  {
    sctx->getInternalStaticQueryContextPtr(&wrapped_interf);
    sctx_interf = reinterpret_cast<zorba::StaticQueryContext*>(wrapped_interf.pintVal);
  }
  if(tree_plans)
  {
    tree_plans->getInternalXQueryTreePlansPtr(&wrapped_interf);
    tree_plans_interf = reinterpret_cast<zorba::XQueryTreePlans*>(wrapped_interf.pintVal);
  }

  aQueryStringLen = SysStringLen(aQueryString);
  xquery_source_uriLen = SysStringLen(xquery_source_uri);
  utf8Query = new char[aQueryStringLen*4+1];
  utf8Query[0] = 0;
  utf8source = new char[xquery_source_uriLen*4+1];
  utf8source[0] = 0;
  
  if(sizeof(aQueryString[0]) > 1)
  {
    //convert from 16 bits to UTF8
    if(aQueryString &&
      !WideCharToMultiByte(CP_UTF8, 0,
                      aQueryString, -1,//aQueryStringLen,
                      utf8Query, aQueryStringLen*4+1,
                      NULL, NULL))
    {
      delete[] utf8Query;
      delete[] utf8source;
      return E_FAIL;
    }
    if(xquery_source_uri &&
      !WideCharToMultiByte(CP_UTF8, 0,
                      xquery_source_uri, -1,//xquery_source_uriLen,
                      utf8source, xquery_source_uriLen*4+1,
                      NULL, NULL))
    {
      delete[] utf8Query;
      delete[] utf8source;
      return E_FAIL;
    }
  }
  else
  {
    if(aQueryString)
      memcpy(utf8Query,  aQueryString, aQueryStringLen+1);
    if(xquery_source_uri)
      memcpy(utf8source, xquery_source_uri, xquery_source_uriLen+1);
  }

  xq = zorba_singlethread->createQuery(utf8Query, 
                                        sctx_interf,
                                        utf8source,
                                        routing_mode ? true : false,
                                        tree_plans_interf);
  delete[] utf8Query;
  delete[] utf8source;

  if(xq == NULL)
    return E_FAIL;

  CComObject<CXQueryCOM>  *xquery_obj = new CComObject<CXQueryCOM>;//ref count is zero

  xquery_obj->setWrappedInterface(xq);
  *ret_xquery = xquery_obj;
  //(*ret_xquery)->AddRef();//call Release when done with this object

  return S_OK;
}

/* [helpstring][id] */ 
HRESULT STDMETHODCALLTYPE CZorbaSingleThread::createDynamicQueryContext( 
    /* [retval][out] */ IDynamicQueryContext **ret_dctx)
{
  zorba::DynamicQueryContext_t    dctx_interface;

  dctx_interface = zorba_singlethread->createDynamicContext();

  if(dctx_interface == NULL)
    return E_FAIL;

  CComObject<CDynamicQueryContext>    *dctx_obj;

  dctx_obj = new CComObject<CDynamicQueryContext>;
  dctx_obj->setWrappedInterface(dctx_interface);

  *ret_dctx = dctx_obj;
//  (*ret_dctx)->AddRef();//call Release when done with this object

  return S_OK;
}

