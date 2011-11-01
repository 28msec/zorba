/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

%{  // start Implementation

class Iterator 
{
protected:
  friend class DynamicContext;
  zorba::Iterator_t theIterator;
  zorba::Item theItem;
  bool theConsumed;

public:
  Iterator() {}
  Iterator(const Iterator& anIterator)
    : theIterator(anIterator.theIterator),
      theItem(anIterator.theItem),
      theConsumed(false)
  {}

  Iterator(zorba::Iterator_t anIterator)
    : theIterator(anIterator),
      theConsumed(false)
  {}

  Iterator(zorba::Item& aItem)
    : theIterator(0),
      theItem(aItem),
      theConsumed(false)
  {}

  void open()
  {
    if (theIterator)
      theIterator->open();
    theConsumed = false;
  }

  bool next(Item& aItem);

  void close()
  {
    if (theIterator)
      theIterator->close();
    theConsumed = true;
  }

  void destroy()
  {
    theIterator = 0;
  }

}; // class Iterator


class Item 
{
  friend class Iterator;
  friend class StaticContext;
  friend class DocumentManager; 
  friend class SingletonIterator;
  friend class DynamicContext;
  friend class ItemFactory;

private:
  zorba::Item theItem;

public:
  Item() {}
  Item(const Item& aItem) : theItem(aItem.theItem) {}
  Item(const zorba::Item& aZItem) : theItem(aZItem) {}

  static Item createEmptyItem() 
  { return Item(); }

  std::string getStringValue() const 
  { return std::string(theItem.getStringValue().c_str()); }
  
  std::string serialize() const 
  {
    std::stringstream lStream; 
    Zorba_SerializerOptions_t lOptions; 
    zorba::Serializer_t lSerializer = zorba::Serializer::createSerializer(lOptions); 
    zorba::SingletonItemSequence lSequence(theItem); 
    lSerializer->serialize(&lSequence, lStream); 
    return lStream.str();
  }
  
  Iterator getAtomizationValue () const
  { return Iterator(theItem.getAtomizationValue()); }
  
  Iterator getAttributes () const
  { return Iterator(theItem.getAttributes()); }
  
  bool getBooleanValue () const
  { return theItem.getBooleanValue(); }

  Iterator getChildren () const
  { return Iterator(theItem.getChildren()); }

  Item getEBV () const
  { return Item(theItem.getEBV()); }

  int getIntValue () const
  { return theItem.getIntValue(); }
  
  std::string getLocalName () const
  { return std::string(theItem.getLocalName().c_str()); }

  std::string getNamespace () const
  { return std::string(theItem.getNamespace().c_str()); }

  bool getNodeName (Item &aNodeName) const
  { return theItem.getNodeName( aNodeName.theItem ); }

  std::string getPrefix () const
  { return std::string(theItem.getPrefix().c_str()); }

  Item getType () const
  { return Item( theItem.getType() ); }

  unsigned int getUnsignedIntValue () const
  { return theItem.getUnsignedIntValue(); }

  bool isAtomic () const
  { return theItem.isAtomic(); }

  bool isNaN () const
  { return theItem.isNaN(); }

  bool isNode () const
  { return theItem.isNode(); }

  bool isNull () const
  { return theItem.isNull(); }

  bool isPosOrNegInf () const
  { return theItem.isPosOrNegInf(); }
  
  int getNodeKind () const
  { return theItem.getNodeKind(); }

}; // class Item

class DynamicContext
{
private:
  zorba::DynamicContext* theContext;

public:
  DynamicContext()
    : theContext(0)
  {
  }

  DynamicContext(const DynamicContext& aCtx)
    : theContext(aCtx.theContext)
  {
  }

  DynamicContext(zorba::DynamicContext* aCtx)
    : theContext(aCtx)
  {
  }

  void
  setVariable(
    const std::string& aNamespace,
    const std::string& aLocalname,
    Iterator aIter)
  {
    theContext->setVariable(aNamespace, aLocalname, aIter.theIterator);
  }

  void
  setContextItem(Item aItem)
  {
    theContext->setContextItem(aItem.theItem);
  }
};

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

  void compile (const std::string &aQuery)
  {
    theQuery->compile(aQuery);
  }

  void compile (const std::string &aQuery, StaticContext &aStaticContext )
  {
    Zorba_CompilerHints_t hints;
    theQuery->compile(aQuery, aStaticContext.theStaticContext, hints);
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

  DynamicContext
  getDynamicContext()
  {
    return DynamicContext(theQuery->getDynamicContext());
  }

#ifdef SWIGPYTHON
  void executeSAX(SAX2ContentHandlerProxy* contentHandlerProxy)
  { theQuery->executeSAX(contentHandlerProxy); }
#endif

  void destroy() { theQuery = 0; }
  Iterator iterator() { return Iterator(theQuery->iterator()); }
}; // class XQuery


// remaining method definitions from Iterator
bool
Iterator::next(Item& aItem)
{
  if (theIterator)
  {
    return theIterator->next(aItem.theItem);
  }
  else
  {
    if (!theConsumed)
    {
      aItem = theItem;
      return true;
    }
    else
    {
      return false;
    }
  }
}


%}  // end   Implementation


// Interfaces

class DynamicContext
{
public:
  void
  setVariable(
    const std::string& aNamespace,
    const std::string& aLocalname,
    Iterator);

  void
  setContextItem(Item);
};

class Item 
{
public: 
  static Item createEmptyItem();
  std::string getStringValue() const;
  std::string serialize() const;
  Iterator getAtomizationValue () const;
  Iterator getAttributes () const;
  bool getBooleanValue () const;
  Iterator getChildren () const;
  Item getEBV () const;
  int getIntValue () const;
  std::string getLocalName () const;
  std::string getNamespace () const;
  bool getNodeName (Item &aNodeName) const;
  std::string getPrefix () const;
  Item getType () const;
  unsigned int getUnsignedIntValue () const;

  int getNodeKind() const;
  bool isAtomic () const;
  bool isNaN () const;
  bool isNode () const;
  bool isNull () const;
  bool isPosOrNegInf () const;
}; // class Item

class Iterator 
{
public:
  void open();
  bool next(Item&);
  void close();
  void destroy();
}; // class Iterator

class XQuery 
{
public:
  std::string execute();
  std::string printPlanAsXML();
  std::string printPlanAsDOT();
  void compile (const std::string &aQuery);
  void compile (const std::string &aQuery, StaticContext &aStaticContext);

#ifdef SWIGPYTHON
  void executeSAX(SAX2ContentHandlerProxy* contentHandlerProxy);
#endif

  void destroy();
  Iterator iterator();
  DynamicContext getDynamicContext();
}; // class XQuery
