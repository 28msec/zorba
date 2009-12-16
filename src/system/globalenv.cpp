/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "common/common.h"

#ifndef ZORBA_NO_UNICODE
# include <unicode/uclean.h>
# include <unicode/utypes.h>
# include <unicode/udata.h>
#endif//#ifndef ZORBA_NO_UNICODE

#ifndef ZORBA_NO_BIGNUMBERS
#include "zorbatypes/m_apm.h"
#endif

#include "zorbautils/fatal.h"

#include "globalenv.h"
#include "types/root_typemanager.h"
#include "types/schema/schema.h"
#include "context/root_static_context.h"
#include "context/standard_uri_resolvers.h"
#include "functions/library.h"
#include "compiler/api/compiler_api.h"
#include "compiler/xqueryx/xqueryx_to_xquery.h"

#include "types/schema/schema.h"

#include "zorbautils/condition.h"

#include "store/api/collection.h"

#include "store/api/store.h"

#ifdef ZORBA_WITH_REST
#include <curl/curl.h>
#endif

#ifdef ZORBA_XQUERYX
#include <libxslt/xslt.h>
#include <libxml/parser.h>
#endif

using namespace zorba;


GlobalEnvironment * GlobalEnvironment::m_globalEnv = 0;

GlobalEnvironment::~GlobalEnvironment()
{}

void GlobalEnvironment::init_icu()
{
  // initialize the icu library
  // we do this here because we are sure that is used
  // from one thread only
  // see http://www.icu-project.org/userguide/design.html#Init_and_Termination
  // and http://www.icu-project.org/apiref/icu4c/uclean_8h.html
#ifndef ZORBA_NO_UNICODE
#  if defined U_STATIC_IMPLEMENTATION && (defined WIN32 || defined WINCE)
  {
    TCHAR    self_path[1024];
    GetModuleFileName(NULL, self_path, sizeof(self_path));
        //PathRemoveFileSpec(self_path);
    TCHAR  *filename;
    filename = _tcsrchr(self_path, _T('\\'));
    if(filename)
      filename[1] = 0;
    else
      self_path[0] = 0;
        //strcat(self_path, "\\");
        //_tcscat(self_path, _T(U_ICUDATA_NAME));//icudt39l.dat");
    _tcscat(self_path, _T("icudt") _T(U_ICU_VERSION_SHORT) _T(U_ICUDATA_TYPE_LETTER));//icudt39l.dat");
    _tcscat(self_path, _T(".dat"));
        //unsigned char *icu_data;
    HANDLE    hfile;
    hfile = CreateFile(self_path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    ZORBA_ASSERT(hfile != INVALID_HANDLE_VALUE);
    DWORD   icusize;
    icusize = GetFileSize(hfile, NULL);
    icu_appdata = new unsigned char[icusize];
    DWORD   nr_read;
    ReadFile(hfile, icu_appdata, icusize, &nr_read, NULL);
    CloseHandle(hfile);
    UErrorCode    data_err = U_ZERO_ERROR;
    udata_setCommonData(icu_appdata, &data_err);
    ZORBA_ASSERT(data_err == U_ZERO_ERROR);
  
      //  u_setDataDirectory(self_path);
  }
#  endif
  UErrorCode lICUInitStatus = U_ZERO_ERROR;
  u_init(&lICUInitStatus);
  ZORBA_ASSERT(lICUInitStatus == U_ZERO_ERROR);
#endif//ifndef ZORBA_NO_UNICODE
}

void GlobalEnvironment::cleanup_icu()
{
  // we shutdown icu
  // again it is important to mention this in the documentation
  // we might disable this call because it only
  // releases statically initialized memory and prevents
  // valgrind from reporting those problems at the end
  // see http://www.icu-project.org/apiref/icu4c/uclean_8h.html#93f27d0ddc7c196a1da864763f2d8920
#ifndef ZORBA_NO_UNICODE
  u_cleanup();
# if defined U_STATIC_IMPLEMENTATION && (defined WIN32 || defined WINCE)
  delete[] icu_appdata;
# endif
#endif//ifndef ZORBA_NO_UNICODE
}


void GlobalEnvironment::init(store::Store* store)
{
  // initialize Xerces-C lib
  Schema::initialize();


  m_globalEnv = new GlobalEnvironment();

  m_globalEnv->init_icu();

  ZORBA_FATAL(store != NULL, "Must provide store during zorba initialization");

  m_globalEnv->m_store = store;

  m_globalEnv->m_rootStaticContext = new root_static_context();
  m_globalEnv->m_rootStaticContext->init();
  RCHelper::addReference (m_globalEnv->m_rootStaticContext);

  BuiltinFunctionLibrary::create(m_globalEnv->m_rootStaticContext);

#ifndef ZORBA_NO_BIGNUMBERS
  // initialize mapm for bignum handling
  m_globalEnv->m_mapm = m_apm_init();
#endif


#ifdef ZORBA_WITH_REST
#  ifdef ZORBA_WITH_SSL
    curl_global_init(CURL_GLOBAL_ALL);
    #ifdef ZORBA_VERIFY_PEER_SSL_CERTIFICATE
    #if defined WIN32
    //for Windows, try to find the "cacert.pem" file in one of system paths or current dir
    DWORD   search_result;
    #ifndef UNICODE
    char  *certpath = m_globalEnv->g_curl_root_CA_certificates_path;
    #else
    WCHAR certpath[sizeof(m_globalEnv->g_curl_root_CA_certificates_path)];
    #endif
    search_result = SearchPath(NULL, 
                              "cacert.pem", NULL,
                              sizeof(m_globalEnv->g_curl_root_CA_certificates_path),
                              certpath, NULL);
    if(!search_result)
      certpath[0] = 0;
    else
      certpath[search_result] = 0;
    #ifdef UNICODE
    //convert from UNICODE to ASCII
    WideCharToMultiByte(CP_ACP, 0, certpath, -1, 
                      m_globalEnv->g_curl_root_CA_certificates_path, sizeof(m_globalEnv->g_curl_root_CA_certificates_path),
                      NULL, NULL);
    #endif
#endif
#endif
#  else
    curl_global_init(CURL_GLOBAL_NOTHING);
#  endif
#endif

#ifdef ZORBA_XQUERYX
  //libxml2 and libxslt are needed
  xmlInitMemory();

  LIBXML_TEST_VERSION
 
  // TODO function not available on mac
  //xsltInit();
  m_globalEnv->xqueryx_convertor = new XQueryXConvertor;
#endif

  std::auto_ptr<XQueryCompilerSubsystem> lSubSystem = 
    XQueryCompilerSubsystem::create();
  m_globalEnv->m_compilerSubSys = lSubSystem.release();

  m_globalEnv->m_module_resolver = new StandardModuleURIResolver();
  m_globalEnv->m_schema_resolver = new StandardSchemaURIResolver();
}


// destroy all components that were initialized in init 
// note: destruction must be done in reverse initialization order
void GlobalEnvironment::destroy()
{
  delete m_globalEnv->m_schema_resolver;
  delete m_globalEnv->m_module_resolver;

  serialization::ClassSerializer::getInstance()->destroyArchiverForHardcodedObjects();

  delete m_globalEnv->m_compilerSubSys;
  m_globalEnv->m_compilerSubSys = 0;

#ifdef ZORBA_XQUERYX
    //free libxml2 and libxslt

  xsltCleanupGlobals();
  xmlCleanupParser();
  delete m_globalEnv->xqueryx_convertor;
#endif

#ifdef ZORBA_WITH_REST
  curl_global_cleanup();
#endif


#ifndef ZORBA_NO_BIGNUMBERS
  // release resources aquired by the mapm library
  // this will force zorba users to reinit mapm
  // if they shutdown zorba but want to use mapm beyond
  m_apm_free(m_globalEnv->m_mapm);
  m_apm_free_all_mem();
  m_globalEnv->m_mapm = 0;
#endif


  RCHelper::removeReference (m_globalEnv->m_rootStaticContext);
  m_globalEnv->m_rootStaticContext = 0;

  m_globalEnv->m_store = NULL;

  // we shutdown icu
  // again it is important to mention this in the documentation
  // we might disable this call because it only
  // releases statically initialized memory and prevents
  // valgrind from reporting those problems at the end
  // see http://www.icu-project.org/apiref/icu4c/uclean_8h.html#93f27d0ddc7c196a1da864763f2d8920
  m_globalEnv->cleanup_icu();

  BuiltinFunctionLibrary::destroy();

  delete m_globalEnv;
	m_globalEnv = NULL;

  // terminate Xerces-C lib
  Schema::terminate();

}


GlobalEnvironment::GlobalEnvironment()
  :
  m_store(0), 
  m_rootStaticContext(0),
  m_compilerSubSys(0)
{
}


static_context& GlobalEnvironment::getRootStaticContext()
{
  return *m_rootStaticContext;
}


RootTypeManager& GlobalEnvironment::getRootTypeManager()
{
  return *(static_cast<RootTypeManager *>(m_rootStaticContext->get_typemanager()));
}

bool GlobalEnvironment::isRootStaticContextInitialized()
{
  return m_rootStaticContext != NULL;
}

store::Store& GlobalEnvironment::getStore()
{
  return *m_store;
}


store::ItemFactory* GlobalEnvironment::getItemFactory()
{
  return m_store->getItemFactory();
}


store::IteratorFactory* GlobalEnvironment::getIteratorFactory()
{
  return m_store->getIteratorFactory();
}


XQueryCompilerSubsystem& GlobalEnvironment::getCompilerSubsystem()
{
  return *m_compilerSubSys;
}

#ifdef ZORBA_XQUERYX
XQueryXConvertor    *GlobalEnvironment::getXQueryXConvertor()
{
  return xqueryx_convertor;
}
#endif

/* vim:set ts=2 sw=2: */

