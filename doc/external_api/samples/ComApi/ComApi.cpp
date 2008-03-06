// ComApi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ZorbaCOMApi.h"
#include <iostream>
#include <string.h>

using namespace std;

//class Id for Zorba Engine class
EXTERN_C const CLSID  CLSID_ZorbaSingleThread = {0x6C2420BD,0x4924,0x4B62,{0xB6,0x1E,0x69,0xD5,0x63,0xC7,0x4A,0x78}};

int ucCom1_serializeXml();
int ucCom2_inputXml();

int _tmain(int argc, _TCHAR* argv[])
{

  CoInitialize(NULL);

  if(argc < 2)
  {
    cout << "parameters should be the index of test 1,2,3... etc in any order" << endl;
    return -1;
  }

  for(int i=1;i<argc;i++)
  {
    if(!_tcscmp(argv[i], _T("1")))
      ucCom1_serializeXml();
    if(!_tcscmp(argv[i], _T("2")))
      ucCom2_inputXml();
  }

  CoUninitialize();
	return 0;
}

