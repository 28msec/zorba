#include <iostream>

#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include <zorba/function.h>
#include <zorba/empty_sequence.h>
#include <zorba/singleton_item_sequence.h>

using namespace zorba;

namespace commandline {
  
  class CommandLineModule : public ExternalModule
  {
  private:
    ItemFactory* theFacory;
    ExternalFunction* thePrintFunction;
    ExternalFunction* theGetLineFunction;
  public:
    const static String COMMANDLINE_MODULE_NAMESPACE;
  public:
    CommandLineModule();
    ~CommandLineModule();
  public:
    virtual String getURI() const { return COMMANDLINE_MODULE_NAMESPACE; }
    virtual void destroy();
    virtual ExternalFunction* getExternalFunction(const String& localName);
  };

  class CommandLineFunction : public NonContextualExternalFunction
  {
  protected:
    CommandLineModule* theModule;
    ItemFactory* theFactory;
  public:
    CommandLineFunction(CommandLineModule* aModule, ItemFactory* aFactory)
    : theModule(aModule), theFactory(aFactory) {}
  };
  
  class PrintFunction : public CommandLineFunction
  {
  public:
    PrintFunction(CommandLineModule* aModule, ItemFactory* aFactory)
    : CommandLineFunction(aModule, aFactory) {}
  public:
    virtual String getLocalName() const { return "print"; }
    virtual String getURI() const { return CommandLineModule::COMMANDLINE_MODULE_NAMESPACE; }
    virtual ItemSequence_t
    evaluate(const ExternalFunction::Arguments_t& args) const;
  };
  
  class GetLineFunction : public CommandLineFunction
  {
  public:
    GetLineFunction(CommandLineModule* aModule, ItemFactory* aFactory)
    : CommandLineFunction(aModule, aFactory) {}
  public:
    virtual String getLocalName() const { return "get-line"; }
    virtual String getURI() const { return CommandLineModule::COMMANDLINE_MODULE_NAMESPACE; }
    virtual ItemSequence_t
    evaluate(const ExternalFunction::Arguments_t& args) const;
  };
  
  const String CommandLineModule::COMMANDLINE_MODULE_NAMESPACE = "http://www.zorba-xquery.com/examples/commandline";
  
  CommandLineModule::CommandLineModule()
  : theFacory(Zorba::getInstance(0)->getItemFactory()), thePrintFunction(new PrintFunction(this, theFacory)),
  theGetLineFunction(new GetLineFunction(this, theFacory))
  {
  }
  
  CommandLineModule::~CommandLineModule()
  {
    delete thePrintFunction;
    delete theGetLineFunction;
  }
  
  void CommandLineModule::destroy()
  {
    delete this;
  }
  
  ExternalFunction* CommandLineModule::getExternalFunction(const zorba::String &localName)
  {
    if (localName == "print")
      return thePrintFunction;
    else if (localName == "get-line")
      return theGetLineFunction;
    else
      return 0;
  }
  
  ItemSequence_t PrintFunction::evaluate(const ExternalFunction::Arguments_t &args) const
  {
    Iterator_t lIter = args[0]->getIterator();
    lIter->open();
    Item lItem;
    lIter->next(lItem);
    lIter->close();
    std::cout << lItem.getStringValue();
    return ItemSequence_t(new EmptySequence());
  }
  
  ItemSequence_t GetLineFunction::evaluate(const ExternalFunction::Arguments_t &args) const
  {
    std::string lInput;
    std::getline(std::cin, lInput);
    Item res = theFactory->createString(lInput.c_str());
    return ItemSequence_t(new SingletonItemSequence(res));
  }
  
} //end of namespace commandline


#ifdef WIN32                                                                                               
#  define DLL_EXPORT __declspec(dllexport)                                                                 
#else                                                                                                      
#  define DLL_EXPORT __attribute__ ((visibility("default")))                                               
#endif                                                                                                     

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {                                              
  return new commandline::CommandLineModule();                                                                
}
