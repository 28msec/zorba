
%{  // start Implementation

class Item 
{
  friend class ResultIterator;
  friend class StaticContext;

private:
  zorba::Item theItem;

public:
  Item() {}
  Item(const Item& aItem) : theItem(aItem.theItem) {}
  static Item createEmptyItem() { return Item(); }
  std::string getStringValue() const 
  { return 		std::string(theItem.getStringValue().c_str()); }

  std::string serialize() const {
    std::stringstream lStream;
    theItem.serialize(lStream);
    return lStream.str();
  }
}; // class Item

class ResultIterator 
{
private:
  zorba::ResultIterator_t theResultIterator;

public:
  ResultIterator() {}
  ResultIterator(const ResultIterator& aResultIterator) 
    : theResultIterator(aResultIterator.theResultIterator) {}
  ResultIterator(zorba::ResultIterator_t aResultIterator) : 
      theResultIterator(aResultIterator) {}
  void open() { theResultIterator->open(); }
  bool next(Item& aItem) { return theResultIterator->next(aItem.theItem); }
  void close() { theResultIterator->close(); }
  void destroy() { theResultIterator = 0; }

}; // class ResultIterator

class XQuery 
{
private:
  zorba::XQuery_t theQuery;

public:
  XQuery() {}
  XQuery(const XQuery& aXQuery) : theQuery(aXQuery.theQuery) {}
  XQuery(zorba::XQuery_t aQuery) : theQuery(aQuery) {}

  std::string execute()
  {
    std::stringstream lStream;
    lStream << theQuery;
    return lStream.str();
  }

  void setVariableAsDocument(const std::string& aVarName, 
                             const std::string& aURL, 
                             const std::string& aContent)
  {
    std::auto_ptr<std::istream> lDocStream(new std::stringstream(aContent));
  	zorba::DynamicContext* lCtx = theQuery->getDynamicContext();

  	lCtx->setVariableAsDocument(aVarName, aURL, lDocStream);
   }

  std::string printPlanAsXML()
  {
    std::ostringstream lStream;
    theQuery->printPlan(lStream);
    return lStream.str();
  }

  std::string printPlanAsDOT()
  {
    std::ostringstream lStream;
    theQuery->printPlan(lStream, true);
    return lStream.str();
  }

#ifdef SWIGPYTHON
  void executeSAX(SAX2ContentHandlerProxy* contentHandlerProxy)
  { theQuery->executeSAX(contentHandlerProxy); }
#endif

  bool isUpdateQuery() { return theQuery->isUpdateQuery(); }
  void applyUpdates() { theQuery->applyUpdates(); }
  void destroy() { theQuery = 0; }
  ResultIterator iterator() { return ResultIterator(theQuery->iterator()); }
}; // class XQuery


%}  // end   Implementation


// Interfaces

class Item 
{
public: 
  static Item createEmptyItem();
  std::string getStringValue() const;
  std::string serialize() const;
}; // class Item

class ResultIterator 
{
public:
  void open();
  bool next(Item&);
  void close();
  void destroy();
}; // class ResultIterator

class XQuery 
{
public:
  std::string execute();
  std::string printPlanAsXML();
  std::string printPlanAsDOT();

#ifdef SWIGPYTHON
  void executeSAX(SAX2ContentHandlerProxy* contentHandlerProxy);
#endif

  bool isUpdateQuery();
  void applyUpdates();
  void destroy();
  ResultIterator iterator();
  void setVariableAsDocument(const std::string& aVarName, 
                             const std::string& aURL, 
                             const std::string& aContent);
}; // class XQuery
