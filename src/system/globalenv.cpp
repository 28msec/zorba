#include "globalenv.h"
#include "mapm/m_apm.h"
#include "types/root_typemanager.h"
#include "context/root_static_context.h"
#include "functions/library.h"
#include "store/naive/simple_store.h"
#include <libxml/parser.h>

using namespace xqp;

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
  m_globalEnv->m_store.reset(new SimpleStore());
  static_cast<SimpleStore *>(m_globalEnv->m_store.get())->init();
  m_globalEnv->m_rootStaticContext.reset(new root_static_context());
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
}

void GlobalEnvironment::destroy()
{
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

Store& GlobalEnvironment::getStore()
{
  return *m_store;
}

/* vim:set ts=2 sw=2: */

