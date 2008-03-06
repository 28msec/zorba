// ComApi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ZorbaCOMApi.h"
#include <iostream>

using namespace std;


int ucCom3_resultDOM()
{

  CComPtr<IZorbaSingleThread>   zorba_engine;//use smart pointers
  if(zorba_engine.CoCreateInstance(CLSID_ZorbaSingleThread, NULL, CLSCTX_ALL) != S_OK)
  {
    cout << "cannot CoCreate CLSID_ZorbaSingleThread . Register the Zorba COM object first" << endl;
    return -1;
  }

  CComPtr<IXQuery>   xquery;//use smart pointers
  IXQuery   *xquery_interf = NULL;
  CComBSTR  xquery_bstr("declare variable $var1 external; "
                        "declare variable $var2 external; "
                        "$var1//book[fn:contains(fn:string(), $var2)]");

  if(zorba_engine->createQuery(xquery_bstr, NULL, NULL, FALSE, NULL, &xquery_interf) != S_OK)
  {
    cout << "cannot create or compile xquery" << endl;
    return -1;
  }
  xquery = xquery_interf;


  CComPtr<IDynamicQueryContext>   dctx;//use smart pointers
  IDynamicQueryContext  *dctx_interf = NULL;

  if(zorba_engine->createDynamicQueryContext(&dctx_interf) != S_OK)
  {
    cout << "cannot create DynamicQueryContext " << endl;
    return -1;
  }
  dctx = dctx_interf;

  //search first into yahoo technology rss xml (saved localy)

  if(dctx->setVariableAsDocumentFromFile(CComBSTR("var1"), CComBSTR("books.xml"), NULL) != S_OK)
  {
    cout << "cannot load  books.xml" << endl;
    return -1;
  }
  if(dctx->setVariableAsString(CComBSTR("var2"), CComBSTR("sun")) != S_OK)
  {
    cout << "cannot set var2 as string" << endl;
    return -1;
  }


  if(xquery->initExecution(dctx) != S_OK)
  {
    cout << "cannot init execution mode on xquery" << endl;
    return -1;
  }
  
  IXMLDOMDocument *dom_result;
  CComPtr<IXMLDOMDocument>    dom_ptr;

  if(xquery->getResultsAsDOM(&dom_result) != S_OK)
  {
    cout << "cannot get the xquery result as MSXML DOM" << endl;
    return -1;
  }
  dom_ptr = dom_result;//to handle the ref count automatically

  //now serialize the DOM result into a file
  _variant_t dom_filename = _T("dom_output.xml");
  if(!SUCCEEDED(dom_ptr->save(dom_filename)))
  {
    cout << "cannot get the xquery result as MSXML DOM" << endl;
    return -1;
  } 

	return 0;
}

