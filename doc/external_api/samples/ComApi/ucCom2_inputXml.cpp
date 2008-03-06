// ComApi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ZorbaCOMApi.h"
#include <iostream>

using namespace std;


int ucCom2_inputXml()
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
                        "$var1//title[fn:contains(fn:string(), $var2)]");

  if(zorba_engine->createQuery(xquery_bstr, NULL, NULL, FALSE, NULL, &xquery_interf) != S_OK)
  {
    cout << "cannot create or compile xquery" << endl;
    return -1;
  }
  xquery = xquery_interf;

  //rss from http://rss.news.yahoo.com/rss/tech
  //rss from http://rss.news.yahoo.com/rss/science

  CComPtr<IDynamicQueryContext>   dctx;//use smart pointers
  IDynamicQueryContext  *dctx_interf = NULL;

  if(zorba_engine->createDynamicQueryContext(&dctx_interf) != S_OK)
  {
    cout << "cannot create DynamicQueryContext " << endl;
    return -1;
  }
  dctx = dctx_interf;

  //search first into yahoo technology rss xml (saved localy)

  if(dctx->setVariableAsDocumentFromFile(CComBSTR("var1"), CComBSTR("Yahoo! News Technology News.xml"), NULL) != S_OK)
  {
    cout << "cannot load  Yahoo! News Technology News.xml" << endl;
    return -1;
  }
  if(dctx->setVariableAsString(CComBSTR("var2"), CComBSTR("(AP)")) != S_OK)
  {
    cout << "cannot set var2 as string" << endl;
    return -1;
  }


  if(xquery->initExecution(dctx) != S_OK)
  {
    cout << "cannot init execution mode on xquery" << endl;
    return -1;
  }

  BSTR    resultXML;

  if(xquery->serializeXMLtoBuffer(&resultXML) != S_OK)
  {
    cout << "cannot execute and serialize the xquery" << endl;
    return -1;
  }

  cout << endl << "-------result of executing xquery1------" << endl << endl;
  {
    CT2CA  ansi_result(resultXML);
    cout << (LPCSTR)ansi_result << endl;
  }
  
  ::SysFreeString(resultXML);




  ///try with yahoo science rss xml, search for (Reuters)

  if(dctx->setVariableAsDocumentFromFile(CComBSTR("var1"), CComBSTR("Yahoo! News Science News.xml"), NULL) != S_OK)
  {
    cout << "cannot load  Yahoo! News Science News.xml" << endl;
    return -1;
  }
  if(dctx->setVariableAsString(CComBSTR("var2"), CComBSTR("(Reuters)")) != S_OK)
  {
    cout << "cannot set var2 as string" << endl;
    return -1;
  }


  if(xquery->initExecution(dctx) != S_OK)
  {
    cout << "cannot init execution mode on xquery" << endl;
    return -1;
  }

  if(xquery->serializeXMLtoBuffer(&resultXML) != S_OK)
  {
    cout << "cannot execute and serialize the xquery" << endl;
    return -1;
  }

  cout << endl << "-------result of executing xquery2------" << endl << endl;
  {
    CT2CA  ansi_result(resultXML);
    cout << (LPCSTR)ansi_result << endl;
  }
  
  ::SysFreeString(resultXML);

	return 0;
}

