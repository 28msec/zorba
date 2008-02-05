#include "globalenv.h"
#include "types/typesystem.h"
#include "mapm/m_apm.h"
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
  m_globalEnv->m_typesystem.reset(new TypeSystem());

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

  delete m_globalEnv;
	m_globalEnv = NULL;
}

GlobalEnvironment::GlobalEnvironment()
{
}

TypeSystem& GlobalEnvironment::getTypeSystem()
{
  return *m_typesystem;
}

/* vim:set ts=2 sw=2: */

