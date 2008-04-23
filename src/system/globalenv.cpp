#include <libxml/parser.h>
#include "common/common.h"

#ifndef ZORBA_NO_UNICODE
#include <unicode/uclean.h>
#endif//#ifndef ZORBA_NO_UNICODE

#include "common/common.h"

#ifdef ZORBA_WITH_REST
#include <curl/curl.h>
#endif

#ifndef ZORBA_NO_BIGNUMBERS
#include "zorbatypes/m_apm.h"
#endif

#include "globalenv.h"
#include "types/root_typemanager.h"
#include "context/root_static_context.h"
#include "functions/library.h"
#include "store/current_store_headers.h"
#include "compiler/api/compiler_api.h"
#include "types/schema/schema.h"
#ifndef ZORBA_NO_UNICODE
#include <unicode/utypes.h>
#include <unicode/udata.h>
#endif//#ifndef ZORBA_NO_UNICODE
#include "store/api/collection.h"

using namespace zorba;

GlobalEnvironment *GlobalEnvironment::m_globalEnv = 0;

GlobalEnvironment& GlobalEnvironment::getInstance()
{
  if (!m_globalEnv) {
    GlobalEnvironment::init();
  }
  return *m_globalEnv;
}

void GlobalEnvironment::init()
{
  // initialize Xerces-C lib
  Schema::initialize();

  m_globalEnv = new GlobalEnvironment();

  // initialize the icu library
  // we do this here because we are sure that is used
  // from one thread only
  // see http://www.icu-project.org/userguide/design.html#Init_and_Termination
  // and http://www.icu-project.org/apiref/icu4c/uclean_8h.html
#ifndef ZORBA_NO_UNICODE
  {
#if defined U_STATIC_IMPLEMENTATION && (defined WIN32 || defined WINCE)
    {
      char    self_path[1024];
      GetModuleFileName(NULL, self_path, sizeof(self_path));
      //PathRemoveFileSpec(self_path);
      char  *filename;
      filename = strrchr(self_path, '\\');
      if(filename)
        filename[1] = 0;
      else
        self_path[0] = 0;
      //strcat(self_path, "\\");
      strcat(self_path, U_ICUDATA_NAME);//icudt39l.dat");
      strcat(self_path, ".dat");
      //unsigned char *icu_data;
      HANDLE    hfile;
      hfile = CreateFile(self_path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
      assert(hfile != INVALID_HANDLE_VALUE);
      DWORD   icusize;
      icusize = GetFileSize(hfile, NULL);
      m_globalEnv->icu_appdata = new unsigned char[icusize];
      DWORD   nr_read;
      ReadFile(hfile, m_globalEnv->icu_appdata, icusize, &nr_read, NULL);
      CloseHandle(hfile);
      UErrorCode    data_err = U_ZERO_ERROR;
      udata_setCommonData(m_globalEnv->icu_appdata, &data_err);
      assert(data_err == U_ZERO_ERROR);

    //  u_setDataDirectory(self_path);
    }
#endif
    UErrorCode lICUInitStatus = U_ZERO_ERROR;
    u_init(&lICUInitStatus);
    assert(lICUInitStatus == U_ZERO_ERROR);
  }
#endif//ifndef ZORBA_NO_UNICODE
  
  m_globalEnv->m_store.reset(new store::SimpleStore());
  static_cast<store::SimpleStore *>(m_globalEnv->m_store.get())->init();
  root_static_context *rctx = new root_static_context();
  m_globalEnv->m_rootStaticContext.reset(rctx);
  rctx->init();
  BuiltinFunctionLibrary::populateContext(m_globalEnv->m_rootStaticContext.get());

#ifndef ZORBA_NO_UNICODE
  // initialize mapm for bignum handling
  m_globalEnv->m_mapm = m_apm_init();
#endif
  // This initializes the libxml2 library and checks 
  // potential ABI mismatches between
  // the version it was compiled for and the actual 
  // shared library used.
  // calling its init is done here because we also want to
  // free it at the end, i.e. when zorba is shutdown
#ifndef ZORBA_MINIMAL_STORE
  LIBXML_TEST_VERSION
#endif

#ifdef ZORBA_WITH_REST
  curl_global_init(CURL_GLOBAL_ALL);
#endif

  m_globalEnv->m_compilerSubSys = XQueryCompilerSubsystem::create();
}

void GlobalEnvironment::destroy()
{
  // terminate Xerces-C lib
  Schema::terminate();

  // do cleanup of the libxml2 library
  // however, after that, a user will have to call 
  // LIBXML_TEST_VERSION if he wants to use libxml2
  // beyond the lifecycle of zorba
#ifndef ZORBA_MINIMAL_STORE
  xmlCleanupParser(); 
#endif

#ifdef ZORBA_WITH_REST
  curl_global_cleanup();
#endif

#ifndef ZORBA_NO_UNICODE
  // release resources aquired by the mapm library
  // this will force zorba users to reinit mapm
  // if they shutdown zorba but want to use mapm beyond
  m_apm_free(m_globalEnv->m_mapm);
  m_apm_free_all_mem();
  m_globalEnv->m_mapm = 0;
#endif

  m_globalEnv->m_rootStaticContext.reset(NULL);
  m_globalEnv->m_store.reset(NULL);

  // we shutdown icu
  // again it is important to mention this in the documentation
  // we might disable this call because it only
  // releases statically initialized memory and prevents
  // valgrind from reporting those problems at the end
  // see http://www.icu-project.org/apiref/icu4c/uclean_8h.html#93f27d0ddc7c196a1da864763f2d8920
#ifndef ZORBA_NO_UNICODE
{
    u_cleanup();
#if defined U_STATIC_IMPLEMENTATION && (defined WIN32 || defined WINCE)
    delete[] m_globalEnv->icu_appdata;
#endif
  }
#endif//ifndef ZORBA_NO_UNICODE

  delete m_globalEnv;
	m_globalEnv = NULL;
}

GlobalEnvironment::GlobalEnvironment()
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

store::Store& GlobalEnvironment::getStore()
{
  return *m_store;
}

store::ItemFactory* GlobalEnvironment::getItemFactory()
{
  return m_store->getItemFactory();
}

XQueryCompilerSubsystem& GlobalEnvironment::getCompilerSubsystem()
{
  return *m_compilerSubSys;
}

/* vim:set ts=2 sw=2: */

