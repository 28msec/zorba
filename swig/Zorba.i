
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
  
  XQuery createQuery() 
  {
    return XQuery(theZorba->createQuery());
  }

  XQuery compileQuery(const std::string& aStr) 
  {
    return XQuery(theZorba->compileQuery(aStr));
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
  XQuery compileQuery(const ZIStreamHelper& aZorbaStream)
  {
    zorbabuffer *buffer = new zorbabuffer(&const_cast<ZIStreamHelper &> (aZorbaStream));
    std::istream stream = std::istream(buffer);
    //zistream stream = zistream(buffer);
    return XQuery(theZorba->compileQuery(stream));
  }

  XQuery compileQuery(const ZIStreamHelper& aZorbaStream, StaticContext &aStaticContext )
  { 
    zorbabuffer *buffer = new zorbabuffer(&const_cast<ZIStreamHelper &> (aZorbaStream));
    std::istream stream = std::istream(buffer);
    return XQuery(theZorba->compileQuery(stream, aStaticContext.theStaticContext));
  }
*/

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
  std::string getVersion() {
    return zorba::Zorba::version().getVersion();
  }
  int getMajorVersion() {
    return zorba::Zorba::version().getMajorVersion();
  }
  int getMinorVersion() {
    return zorba::Zorba::version().getMinorVersion();
  }
  int getPatchVersion() {
    return zorba::Zorba::version().getPatchVersion();
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
  //XQuery compileQuery(const ZIStreamHelper& aZorbaStream);
  //XQuery compileQuery(const ZIStreamHelper& aZorbaStream, StaticContext &aStaticContext );
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
  std::string getVersion();
  int getMajorVersion();
  int getMinorVersion();
  int getPatchVersion();

}; // class Zorba
