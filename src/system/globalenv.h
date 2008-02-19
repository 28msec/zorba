#ifndef XQP_GLOBALENV_H
#define XQP_GLOBALENV_H

#include <memory>
#include "mapm/m_apm.h"

namespace xqp {

class RootTypeManager;
class static_context;
class Store;

class GlobalEnvironment {
  public:
    static void init();
    static void destroy();
    static GlobalEnvironment& getInstance();

    RootTypeManager& getRootTypeManager();
    static_context& getRootStaticContext();
    Store& getStore();
  private:
    GlobalEnvironment();

    std::auto_ptr<Store> m_store;
    std::auto_ptr<static_context> m_rootStaticContext;
    M_APM                     m_mapm; // this is a pointer type

    static GlobalEnvironment *m_globalEnv;
};

#define GENV GlobalEnvironment::getInstance()

#define GENV_TYPESYSTEM GlobalEnvironment::getInstance().getRootTypeManager()

}

#endif /* XQP_GLOBALENV_H */
/* vim:set ts=2 sw=2: */
