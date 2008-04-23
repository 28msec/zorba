#ifndef ZORBA_GLOBALENV_H
#define ZORBA_GLOBALENV_H

#include <memory>
#include "common/common.h"
#ifndef ZORBA_NO_BIGNUMBERS
#include "zorbatypes/m_apm.h"
#endif
#include "common/shared_types.h"

namespace zorba {

class RootTypeManager;
class static_context;
//namespace store {
//  class ItemFactory;
//}

class GlobalEnvironment {
  public:
    static void init();
    static void destroy();
    static GlobalEnvironment& getInstance();

    RootTypeManager& getRootTypeManager();
    static_context& getRootStaticContext();
    XQueryCompilerSubsystem& getCompilerSubsystem();
    store::Store& getStore();
    store::ItemFactory* getItemFactory();

  private:
    GlobalEnvironment();

    std::auto_ptr<store::Store> m_store;
    std::auto_ptr<static_context> m_rootStaticContext;
#ifndef ZORBA_NO_UNICODE
    M_APM                     m_mapm; // this is a pointer type
#endif
    std::auto_ptr<XQueryCompilerSubsystem> m_compilerSubSys;

//#if defined U_STATIC_IMPLEMENTATION && (defined WIN32 || defined WINCE)
    unsigned char*    icu_appdata;
//#endif

    static GlobalEnvironment *m_globalEnv;
};

#define GENV GlobalEnvironment::getInstance()

#define GENV_TYPESYSTEM GlobalEnvironment::getInstance().getRootTypeManager()

#define GENV_COMPILERSUBSYS GlobalEnvironment::getInstance().getCompilerSubsystem()

#define GENV_STORE GlobalEnvironment::getInstance().getStore()

#define GENV_ITEMFACTORY GlobalEnvironment::getInstance().getItemFactory()

}

#endif /* ZORBA_GLOBALENV_H */
/* vim:set ts=2 sw=2: */
