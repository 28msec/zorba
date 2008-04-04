#include <libxml/parser.h>
#include <unicode/uclean.h>

#include "zorbatypes/m_apm.h"

#include "globalenv.h"
#include "types/root_typemanager.h"
#include "context/root_static_context.h"
#include "functions/library.h"
#include "store/naive/simple_store.h"
#include "compiler/api/compiler_api.h"
#include "types/schema/schema.h"

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
  m_globalEnv = new GlobalEnvironment();

  // initialize the icu library
  // we do this here because we are sure that is used
  // from one thread only
  // see http://www.icu-project.org/userguide/design.html#Init_and_Termination
  // and http://www.icu-project.org/apiref/icu4c/uclean_8h.html
  {
    UErrorCode lICUInitStatus = U_ZERO_ERROR;
    u_init(&lICUInitStatus);
    assert(lICUInitStatus == U_ZERO_ERROR);
  }
  
  m_globalEnv->m_store.reset(new store::SimpleStore());
  static_cast<store::SimpleStore *>(m_globalEnv->m_store.get())->init();
  root_static_context *rctx = new root_static_context();
  m_globalEnv->m_rootStaticContext.reset(rctx);
  rctx->init();
  BuiltinFunctionLibrary::populateContext(m_globalEnv->m_rootStaticContext.get());

  // initialize mapm for bignum handling
  m_globalEnv->m_mapm = m_apm_init();

  // This initializes the libxml2 library and checks 
  // potential ABI mismatches between
  // the version it was compiled for and the actual 
  // shared library used.
  // calling its init is done here because we also want to
  // free it at the end, i.e. when zorba is shutdown
  LIBXML_TEST_VERSION

  m_globalEnv->m_compilerSubSys = XQueryCompilerSubsystem::create();

  // initialize Xerces-C lib
  Schema::initialize();
}

void GlobalEnvironment::destroy()
{
  // terminate Xerces-C lib
  Schema::terminate();

  // do cleanup of the libxml2 library
  // however, after that, a user will have to call 
  // LIBXML_TEST_VERSION if he wants to use libxml2
  // beyond the lifecycle of zorba
  xmlCleanupParser(); 

  // release resources aquired by the mapm library
  // this will force zorba users to reinit mapm
  // if they shutdown zorba but want to use mapm beyond
  m_apm_free(m_globalEnv->m_mapm);
  m_apm_free_all_mem();
  m_globalEnv->m_mapm = 0;

  m_globalEnv->m_rootStaticContext.reset(NULL);
  m_globalEnv->m_store.reset(NULL);

  // we shutdown icu
  // again it is important to mention this in the documentation
  // we might disable this call because it only
  // releases statically initialized memory and prevents
  // valgrind from reporting those problems at the end
  // see http://www.icu-project.org/apiref/icu4c/uclean_8h.html#93f27d0ddc7c196a1da864763f2d8920
  {
    u_cleanup();
  }

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

