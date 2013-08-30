#ifndef __COM_ZORBA_WWW_MODULES_ZORBA_QUERY_H__
#define __COM_ZORBA_WWW_MODULES_ZORBA_QUERY_H__

#include <map>

#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include <zorba/function.h>
#include <zorba/dynamic_context.h>
#include <zorba/serialization_callback.h>

#define ZORBA_QUERY_MODULE_NAMESPACE "http://zorba.io/modules/zorba-query"

namespace zorba { namespace zorbaquery {
  
  
/*******************************************************************************

********************************************************************************/
class ZorbaQueryModule : public ExternalModule 
{
protected:
  class ltstr
  {
  public:
    bool operator()(const String& s1, const String& s2) const
    {
      return s1.compare(s2) < 0;
    }
  };

  typedef std::map<String, ExternalFunction*, ltstr> FuncMap_t;

protected:
  FuncMap_t theFunctions;

public:

  virtual ~ZorbaQueryModule();

  virtual zorba::String getURI() const {return ZORBA_QUERY_MODULE_NAMESPACE;}

  virtual zorba::ExternalFunction* getExternalFunction(const String& localName);

  virtual void destroy();

  static ItemFactory* getItemFactory()
  {
    return Zorba::getInstance(0)->getItemFactory();
  }
};


/*******************************************************************************

********************************************************************************/
class ZorbaQueryURLResolver : public URLResolver
{
protected:
  Item             theFunction;
  StaticContext_t  theCtx;

public:
  ZorbaQueryURLResolver(Item& aFunction, StaticContext_t& aSctx)
    :
    URLResolver(),
    theFunction(aFunction),
    theCtx(aSctx)
  {
  }
        
  virtual ~ZorbaQueryURLResolver() { }
      
  virtual Resource* resolveURL(const String& url, EntityData const* entityData);
};
  

class ZorbaQueryURIMapper : public URIMapper
{
protected:
  Item            theFunction;
  StaticContext_t theCtx;
    
public:
  ZorbaQueryURIMapper(Item& aFunction, StaticContext_t& aSctx)
    :
    URIMapper(),
    theFunction(aFunction),
    theCtx(aSctx)
  {
  }
    
  virtual ~ZorbaQueryURIMapper(){ }
    
  virtual void mapURI(
    const zorba::String aUri,
    EntityData const* aEntityData,
    std::vector<zorba::String>& oUris);
};
/*******************************************************************************
  Bag class for objects associated with a prepared query
********************************************************************************/
class QueryData : public SmartObject
{
private:
  XQuery_t      theQuery;
  URIMapper   * theURIMapper;
  URLResolver * theURLResolver;
  
public:
  QueryData(XQuery_t aQuery, URIMapper* aMapper, URLResolver* aResolver);

  virtual ~QueryData();

  XQuery_t getQuery() { return theQuery; }
};


typedef SmartPtr<QueryData> QueryData_t;


/*******************************************************************************

********************************************************************************/
class QueryMap : public ExternalFunctionParameter
{
private:
  typedef std::map<String, QueryData_t> QueryMap_t;

private:
  QueryMap_t  * theQueryMap;

public:
  QueryMap();

  bool storeQuery(const String&, XQuery_t, URIMapper*, URLResolver*);
  
  XQuery_t getQuery(const String&);
  
  bool deleteQuery(const String&);
  
  virtual void destroy() throw();
};


/*******************************************************************************

********************************************************************************/
class ZorbaQueryFunction : public ContextualExternalFunction
{
protected:
  const ZorbaQueryModule * theModule;

protected:
  static void throwError(const char*, const std::string&);

protected:
  String getOneStringArgument(const Arguments_t&, int) const;

  Item getItemArgument(const Arguments_t&, int) const;

  Iterator_t getIterArgument(const Arguments_t&, int) const;

  XQuery_t getQuery(
      const zorba::DynamicContext* dctx,
      const zorba::String& aIdent) const;

public:
  ZorbaQueryFunction(const ZorbaQueryModule* module);

  virtual ~ZorbaQueryFunction();

  virtual String getURI() const;
};

  
/*******************************************************************************

********************************************************************************/
class PrepareMainModuleFunction : public ZorbaQueryFunction
{
public:
  PrepareMainModuleFunction(const ZorbaQueryModule* aModule) : ZorbaQueryFunction(aModule) {}

  virtual ~PrepareMainModuleFunction(){  }
      
  virtual zorba::String
  getLocalName() const { return "prepare-main-module"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;
};


/*******************************************************************************

********************************************************************************/
class PrepareLibraryModuleFunction : public ZorbaQueryFunction
{
public:
  PrepareLibraryModuleFunction(const ZorbaQueryModule* aModule) : ZorbaQueryFunction(aModule) {}

  virtual ~PrepareLibraryModuleFunction(){}
      
  virtual zorba::String
  getLocalName() const { return "prepare-library-module"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;
};


/*******************************************************************************

********************************************************************************/
class IsBoundContextItemFunction : public ZorbaQueryFunction
{
public:
  IsBoundContextItemFunction(const ZorbaQueryModule* aModule) : ZorbaQueryFunction(aModule) {}

  virtual ~IsBoundContextItemFunction(){}

  virtual zorba::String
  getLocalName() const { return "is-bound-context-item"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;
};
    
    
/*******************************************************************************

********************************************************************************/
class IsBoundVariableFunction : public ZorbaQueryFunction
{
public:
  IsBoundVariableFunction(const ZorbaQueryModule* aModule) : ZorbaQueryFunction(aModule) {}

  virtual ~IsBoundVariableFunction(){}

  virtual zorba::String
  getLocalName() const { return "is-bound-variable"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;
};
    

/*******************************************************************************

********************************************************************************/
class GetExternalVariablesFunction : public ZorbaQueryFunction
{
public:
  GetExternalVariablesFunction(const ZorbaQueryModule* aModule) : ZorbaQueryFunction(aModule) {}

  virtual ~GetExternalVariablesFunction() {}

  virtual zorba::String
  getLocalName() const {return "external-variables"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;
};


/*******************************************************************************

********************************************************************************/
class IsUpdatingFunction : public ZorbaQueryFunction
{
public:
  IsUpdatingFunction(const ZorbaQueryModule* aModule) : ZorbaQueryFunction(aModule) {}

  virtual ~IsUpdatingFunction() {}

  virtual zorba::String
  getLocalName() const {return "is-updating"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;  
};


/*******************************************************************************

********************************************************************************/
class IsSequentialFunction : public ZorbaQueryFunction
{
public:
  IsSequentialFunction(const ZorbaQueryModule* aModule) : ZorbaQueryFunction(aModule) {}

  virtual ~IsSequentialFunction() {}

  virtual zorba::String
  getLocalName() const {return "is-sequential"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;
};


/*******************************************************************************

********************************************************************************/
class BindContextItemFunction : public ZorbaQueryFunction
{
public:
  BindContextItemFunction(const ZorbaQueryModule* aModule) : ZorbaQueryFunction(aModule) {}

  virtual ~BindContextItemFunction() {}

  virtual zorba::String
  getLocalName() const {return "bind-context-item"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;
};


/*******************************************************************************

********************************************************************************/
class BindContextPositionFunction : public ZorbaQueryFunction
{
public:
  BindContextPositionFunction(const ZorbaQueryModule* aModule) : ZorbaQueryFunction(aModule) {}

  virtual ~BindContextPositionFunction() {}

  virtual zorba::String
  getLocalName() const {return "bind-context-position"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;
};


/*******************************************************************************

********************************************************************************/
class BindContextSizeFunction : public ZorbaQueryFunction
{
public:
  BindContextSizeFunction(const ZorbaQueryModule* aModule) : ZorbaQueryFunction(aModule) {}

  virtual ~BindContextSizeFunction() {}
  
  virtual zorba::String
  getLocalName() const {return "bind-context-size"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;
};


/*******************************************************************************

********************************************************************************/
class BindVariableFunction : public ZorbaQueryFunction
{
public:
  BindVariableFunction(const ZorbaQueryModule* aModule) : ZorbaQueryFunction(aModule) {}

  virtual ~BindVariableFunction() {}

  virtual zorba::String
  getLocalName() const {return "bind-variable"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;
};


/*******************************************************************************

********************************************************************************/
class EvaluateItemSequence : public ItemSequence
{
protected:

  class EvaluateIterator : public Iterator
  {
  protected:
    Iterator_t theIterator;

    String     theQueryID;

  public:
    EvaluateIterator(Iterator_t& aIter, String aQueryID)
      :
      theIterator(aIter),
      theQueryID(aQueryID)
    {
    }

    virtual ~EvaluateIterator(){}

    virtual void open() { theIterator->open(); }

    virtual bool next(Item& aItem);

    virtual void close() { theIterator->close(); }

    virtual bool isOpen() const { return theIterator->isOpen(); }
  };

  typedef zorba::SmartPtr<EvaluateIterator> EvaluateIterator_t;

protected:
  EvaluateIterator_t theIter; 

public:
  EvaluateItemSequence(Iterator_t& aIter, String& aQueryID)
    :
    theIter(new EvaluateIterator(aIter, aQueryID))
  {
  }
  
  virtual ~EvaluateItemSequence() {}

  Iterator_t getIterator() { return theIter.get(); }
};


/*******************************************************************************

********************************************************************************/
class EvaluateFunction : public ZorbaQueryFunction
{
public:
  EvaluateFunction(const ZorbaQueryModule* aModule) : ZorbaQueryFunction(aModule) {}

  virtual ~EvaluateFunction() {}

  virtual zorba::String
  getLocalName() const {return "evaluate"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;
};


/*******************************************************************************

********************************************************************************/
class EvaluateUpdatingFunction : public ZorbaQueryFunction
{
public:
  EvaluateUpdatingFunction(const ZorbaQueryModule* aModule) : ZorbaQueryFunction(aModule) {}

  virtual ~EvaluateUpdatingFunction() {}

  virtual zorba::String
  getLocalName() const {return "evaluate-updating"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;
};


/*******************************************************************************

********************************************************************************/
class EvaluateSequentialFunction : public ZorbaQueryFunction
{
public:
  EvaluateSequentialFunction(const ZorbaQueryModule* aModule) : ZorbaQueryFunction(aModule) {}

  virtual ~EvaluateSequentialFunction() {}

  virtual zorba::String
  getLocalName() const {return "evaluate-sequential"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;
  
  virtual String getURI() const {
    return theModule->getURI();
  }
  
protected:
  const ZorbaQueryModule* theModule;
};


/*******************************************************************************

********************************************************************************/
class DeleteQueryFunction : public ZorbaQueryFunction
{
public:
  DeleteQueryFunction(const ZorbaQueryModule* aModule) : ZorbaQueryFunction(aModule) {}

  virtual ~DeleteQueryFunction() {}

  virtual zorba::String
  getLocalName() const {return "delete-query"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;
};

  class VariableValueFunction : public ZorbaQueryFunction{
    protected:
      class ValueItemSequence : public ItemSequence
      {
        protected:
          Iterator_t theIterator;

        public:
          ValueItemSequence(Iterator_t& aIter)
            : theIterator(aIter)
          {
          }

          virtual ~ValueItemSequence(){}

          Iterator_t
          getIterator() { return theIterator; }

      };
    public:
      VariableValueFunction(const ZorbaQueryModule* aModule) : ZorbaQueryFunction(aModule) {}

      virtual ~VariableValueFunction() {}

      virtual zorba::String
        getLocalName() const {return "variable-value"; }

      virtual zorba::ItemSequence_t
        evaluate(const Arguments_t&,
                 const zorba::StaticContext*,
                 const zorba::DynamicContext*) const;
  };

/*******************************************************************************

********************************************************************************/
class QueryPlanFunction : public ZorbaQueryFunction
{
public:
  QueryPlanFunction(const ZorbaQueryModule* aModule) : ZorbaQueryFunction(aModule) {}

  virtual ~QueryPlanFunction() {}

  virtual zorba::String
  getLocalName() const {return "query-plan"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;
  
  virtual String getURI() const {
    return theModule->getURI();
  }
  
protected:
  const ZorbaQueryModule* theModule;
};


/*******************************************************************************

********************************************************************************/
class LoadFromQueryPlanFunction : public ZorbaQueryFunction
{
public:
  LoadFromQueryPlanFunction(const ZorbaQueryModule* aModule) : ZorbaQueryFunction(aModule) {}

  virtual ~LoadFromQueryPlanFunction() {}

  virtual zorba::String
  getLocalName() const {return "load-from-query-plan"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;
  
  virtual String getURI() const {
    return theModule->getURI();
  }
  
protected:
  const ZorbaQueryModule* theModule;

  class QueryPlanSerializationCallback : public zorba::SerializationCallback
  {
    std::vector<URIMapper*> theUriMappers;
    std::vector<URLResolver*>theUrlResolvers;

  public:
    QueryPlanSerializationCallback()
    {
    }

    virtual ~QueryPlanSerializationCallback() {}

    void add_URIMapper(URIMapper* aMapper)
    {
      theUriMappers.push_back(aMapper);
    }

    void add_URLResolver(URLResolver* aResolver)
    {
      theUrlResolvers.push_back(aResolver);
    }

    virtual URIMapper*
      getURIMapper(size_t  i ) const { return theUriMappers.size() < i? NULL : theUriMappers[i]; }

    virtual URLResolver*
    getURLResolver(size_t i) const { return theUrlResolvers.size() < i? NULL : theUrlResolvers[i]; }
  };
};
}/*zorbaquery namespace*/}/*zorba namespace*/


#endif //_COM_ZORBA_WWW_MODULES_ZORBA_QUERY_H_
