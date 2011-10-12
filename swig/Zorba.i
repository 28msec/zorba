
%{  // start Implementation

class Zorba 
{
private:
  zorba::Zorba* theZorba;
  Zorba(zorba::Zorba* aZorba) : theZorba(aZorba) {}

public:
  Zorba():theZorba(0){}
  Zorba(const Zorba& aZorba) : theZorba(aZorba.theZorba) {}
  
  static Zorba getInstance(const Store& aStore)
  {
    return Zorba(zorba::Zorba::getInstance(aStore.getStore()));
  }
  ItemFactory getItemFactory()
  {
    return ItemFactory(theZorba->getItemFactory());
  }
  
  StaticContext createStaticContext()
  {
    return StaticContext(theZorba->createStaticContext());
  }
  
  XQuery compileQuery(const std::string& aStr) 
  {
    return XQuery(theZorba->compileQuery(aStr));
  }

  XQuery createQuery() 
  {
    return XQuery(theZorba->createQuery());
  }

  XQuery compileQuery(
    const std::string& aStr,
    StaticContext &aStaticContext )
  { 
    return XQuery(
      theZorba->compileQuery(
        aStr,
        aStaticContext.theStaticContext
      )
    );
  }

  /*
  //--->> DiagnosticHandler implementations are postponed
  XQuery compileQuery(
    const std::string& aStr,
    DiagnosticHandler* aDiagnosticHandler
  )
  {
    return XQuery(theZorba->compileQuery(aStr, aDiagnosticHandler));
  }
  XQuery compileQuery(
    const std::string& aStr,
    StaticContext &aStaticContext, 
    DiagnosticHandler* aDiagnosticHandler)
  { 
    return XQuery(
      theZorba->compileQuery(
        aStr,
        aStaticContext.theStaticContext,
        aDiagnosticHandler
      )
    );
  }

  XQuery compileQuery(
    const std::string& aStr,
    CompilerHints& aCompilerHints,
    DiagnosticHandler* aDiagnosticHandler)
  { 
    return XQuery(
      theZorba->compileQuery(
        aStr,
        aCompilerHints.theCompilerHints,
        aDiagnosticHandler
      )
    );
  }
*/

  XmlDataManager getXmlDataManager()
  {
    return XmlDataManager(theZorba->getXmlDataManager());
  }

  void shutdown() 
  {
    theZorba->shutdown();
  }

}; // class Zorba


%}  // end Implementation

// Interface

class Zorba 
{
 public:
  static Zorba getInstance(const Store&);
  StaticContext createStaticContext();
  XQuery createQuery();
  XQuery compileQuery(const std::string& aStr);
  XQuery compileQuery(const std::string& aStr, StaticContext &aStaticContext );
  ItemFactory getItemFactory();
  
  /*
  XQuery compileQuery(const std::string& aStr, DiagnosticHandler* aDiagnosticHandler);
  XQuery compileQuery(const std::string& aStr, StaticContext &aStaticContext, 
                      DiagnosticHandler* aDiagnosticHandler);
  XQuery compileQuery(const std::string& aStr, CompilerHints &aCompilerHints, 
                      DiagnosticHandler* aDiagnosticHandler);
  */
  XmlDataManager getXmlDataManager();
  void shutdown();

}; // class Zorba
