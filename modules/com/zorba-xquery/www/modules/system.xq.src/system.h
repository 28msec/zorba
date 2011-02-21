#ifndef __COM_ZORBA_WWW_MODULES_SYSTEM_H__
#define __COM_ZORBA_WWW_MODULES_SYSTEM_H__
#include <vector>
#include <map>

#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include <zorba/external_function.h>

namespace zorba { namespace system {
  class SystemModule : public ExternalModule {
    private:
      StatelessExternalFunction* thePropertyFunction;
      StatelessExternalFunction* thePropertiesFunction;
      const static String SYSTEM_MODULE_NAMESPACE;
    public:
      SystemModule();
      virtual ~SystemModule();
    public:
      virtual String getURI() const { return SYSTEM_MODULE_NAMESPACE; }

      virtual StatelessExternalFunction* getExternalFunction(const String& localName);

      virtual void destroy();
  };

  class SystemFunction {
    protected:
      const ExternalModule* theModule;
      ItemFactory* theFactory;
      std::map<String, String> theProperties;
    public:
      SystemFunction(const ExternalModule* aModule);
    protected:
      String getURI() const { return theModule->getURI(); }
      bool getEnv(const String& name, String& value) const;
      void getEnvNames(std::vector<Item>& names) const;
      String intToString(int v);
  };

  class PropertiesFunction : public PureStatelessExternalFunction, public SystemFunction {
    public:
      PropertiesFunction(const ExternalModule* mod) : SystemFunction(mod) {}

      virtual String getLocalName() const { return "properties"; }

      virtual ItemSequence_t 
      evaluate(const StatelessExternalFunction::Arguments_t& args) const;
      virtual String getURI() const { return SystemFunction::getURI(); }
  };

  class PropertyFunction : public NonePureStatelessExternalFunction, public SystemFunction {
    public:
      PropertyFunction(const ExternalModule* mod) : SystemFunction(mod) {}

      virtual String getLocalName() const { return "property"; }

      virtual ItemSequence_t 
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* sctx,
               const DynamicContext* dctx) const;
      virtual String getURI() const { return SystemFunction::getURI(); }
  };

} } // namespace zorba, namespace system

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::system::SystemModule();
}

#endif // __COM_ZORBA_WWW_MODULES_SYSTEM_H__
