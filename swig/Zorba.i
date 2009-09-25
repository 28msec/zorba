
%{  // start Implementation

class Zorba 
{
private:
  zorba::Zorba* theZorba;
  Zorba(zorba::Zorba* aZorba):theZorba(aZorba){}
public:
  Zorba():theZorba(0){}
  Zorba(const Zorba& aZorba) : theZorba(aZorba.theZorba) {}
  
  static Zorba getInstance(const Store& aStore)
  { return Zorba(zorba::Zorba::getInstance(aStore.getStore())); }
  
  XQuery compileQuery(const std::string& aStr) 
  { return XQuery(theZorba->compileQuery(aStr)); }
  
  XQuery compileQuery(const std::string& aStr, ErrorHandler* aErrorHandler)
  { return XQuery(theZorba->compileQuery(aStr, aErrorHandler)); }

  XQuery compileQuery(const std::string& aStr, StaticContext &aStaticContext, 
                      ErrorHandler* aErrorHandler)
  { 
    return XQuery(theZorba->compileQuery(aStr, aStaticContext.theStaticContext,
                                         aErrorHandler));
  }

  XQuery compileQuery(const std::string& aStr, CompilerHints &aCompilerHints, 
                      ErrorHandler* aErrorHandler)
  {
    return XQuery(theZorba->compileQuery(aStr, aCompilerHints.theCompilerHints,
                                         aErrorHandler));
  }

  XmlDataManager getXmlDataManager()
  { return XmlDataManager(theZorba->getXmlDataManager());  }

  void shutdown() 
  { theZorba->shutdown(); }

}; // class Zorba


%}  // end   Implementation

    // Interface

class Zorba 
{
 public:
  static Zorba getInstance(const Store&);
  XQuery compileQuery(const std::string& aStr);
  XQuery compileQuery(const std::string& aStr, ErrorHandler* aErrorHandler);
  XQuery compileQuery(const std::string& aStr, StaticContext &aStaticContext, 
                      ErrorHandler* aErrorHandler);
  XQuery compileQuery(const std::string& aStr, CompilerHints &aCompilerHints, 
                      ErrorHandler* aErrorHandler);
  XmlDataManager getXmlDataManager();
  void shutdown();
}; // class Zorba

