#include "globalenv.h"
#include "types/typesystem.h"

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
}

void GlobalEnvironment::destroy()
{
  delete m_globalEnv;
}

GlobalEnvironment::GlobalEnvironment()
{
}

TypeSystem& GlobalEnvironment::getTypeSystem()
{
  return *m_typesystem;
}

/* vim:set ts=2 sw=2: */

