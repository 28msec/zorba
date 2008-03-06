// ComApi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ZorbaCOMApi.h"
#include <iostream>

using namespace std;


int ucCom1_serializeXml()
{

  CComPtr<IZorbaSingleThread>   zorba_engine;//use smart pointers

  if(zorba_engine.CoCreateInstance(CLSID_ZorbaSingleThread, NULL, CLSCTX_ALL) != S_OK)
  {
    cout << "cannot CoCreate CLSID_ZorbaSingleThread . Register the Zorba COM object first" << endl;
    return -1;
  }

  CComPtr<IXQuery>   xquery;//use smart pointers
  IXQuery   *xquery_interf = NULL;
  CComBSTR  xquery_bstr("1+2");

  if(zorba_engine->createQuery(xquery_bstr, NULL, NULL, FALSE, NULL, &xquery_interf) != S_OK)
  {
    cout << "cannot create or compile xquery" << endl;
    return -1;
  }

  xquery = xquery_interf;

  if(xquery->initExecution(NULL) != S_OK)
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

  cout << endl << "-------result of executing xquery------" << endl << endl;
  CT2CA  ansi_result(resultXML);

  cout << (LPCSTR)ansi_result << endl;

  ::SysFreeString(resultXML);

	return 0;
}

