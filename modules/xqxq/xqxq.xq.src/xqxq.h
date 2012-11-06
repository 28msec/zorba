#ifndef __COM_ZORBA_WWW_MODULES_XQXQ_H__
#define __COM_ZORBA_WWW_MODULES_XQXQ_H__

#include <map>

#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include <zorba/function.h>
#include <zorba/dynamic_context.h>

#define XQXQ_MODULE_NAMESPACE "http://www.zorba-xquery.com/modules/xqxq"

namespace zorba { namespace xqxq {
  
  

  class XQXQModule : public ExternalModule {
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

      FuncMap_t theFunctions;

    public:

      virtual ~XQXQModule();

      virtual zorba::String 
        getURI() const {return XQXQ_MODULE_NAMESPACE;}

      virtual zorba::ExternalFunction* 
        getExternalFunction(const String& localName);

      virtual void destroy();

      static ItemFactory*
        getItemFactory()
      {
        return Zorba::getInstance(0)->getItemFactory();
      }

  };

  /**
   * @brief Bag class for objects associated with a prepared query
   */
  class QueryData : public SmartObject
  {
    private:
      XQuery_t theQuery;
      URIMapper* theURIMapper;
      URLResolver* theURLResolver;

    public:
      QueryData(XQuery_t aQuery, URIMapper* aMapper, URLResolver* aResolver);
      virtual ~QueryData();
      XQuery_t getQuery() { return theQuery; }
  };
  typedef SmartPtr<QueryData> QueryData_t;

  class QueryMap : public ExternalFunctionParameter
  {
    private:
      typedef std::map<String, QueryData_t> QueryMap_t;
      QueryMap_t* queryMap;

    public:
      QueryMap();
      bool 
        storeQuery(const String&, XQuery_t, URIMapper*, URLResolver*);
      XQuery_t
        getQuery(const String&);
      bool 
        deleteQuery(const String&);
      virtual void 
        destroy() throw();
  };

  class XQXQFunction : public ContextualExternalFunction
  {
    protected:
      const XQXQModule* theModule;

       String
         getOneStringArgument(const Arguments_t&, int) const;

       Item
         getItemArgument(const Arguments_t&, int) const;

       Iterator_t
         getIterArgument(const Arguments_t&, int) const;

      static void
        throwError(const char*, const std::string);

      XQuery_t
      getQuery(
          const zorba::DynamicContext* dctx,
          const zorba::String& aIdent) const;

    public:

      XQXQFunction(const XQXQModule* module);

      virtual ~XQXQFunction();

      virtual String
        getURI() const;
  };

  

  class PrepareMainModuleFunction : public XQXQFunction{
    public:
      PrepareMainModuleFunction(const XQXQModule* aModule) : XQXQFunction(aModule) {}

      virtual ~PrepareMainModuleFunction(){  }
      
      virtual zorba::String
        getLocalName() const { return "prepare-main-module"; }

      virtual zorba::ItemSequence_t
        evaluate(const Arguments_t&,
                 const zorba::StaticContext*,
                 const zorba::DynamicContext*) const;

      protected:

      class XQXQURLResolver : public URLResolver
      {
        protected:
        Item theFunction;
        StaticContext_t theCtx;

        public:
        XQXQURLResolver(Item& aFunction, StaticContext_t& aSctx) : URLResolver(), theFunction(aFunction), theCtx(aSctx) {}
        
        virtual ~XQXQURLResolver(){ }
      
        virtual Resource* resolveURL(const String& aUrl,
          EntityData const* aEntityData);

      };

      class XQXQURIMapper : public URIMapper
      {
        protected:
        Item theFunction;
        StaticContext_t theCtx;

        public:
        XQXQURIMapper(Item& aFunction, StaticContext_t& aSctx) : URIMapper(), theFunction(aFunction), theCtx(aSctx) {}
        
        virtual ~XQXQURIMapper(){ }
        
        virtual void mapURI(
          const zorba::String aUri,
          EntityData const* aEntityData,
          std::vector<zorba::String>& oUris);

      };

  };

  class PrepareLibraryModuleFunction : public XQXQFunction{
    public:
      PrepareLibraryModuleFunction(const XQXQModule* aModule) : XQXQFunction(aModule) {}

      virtual ~PrepareLibraryModuleFunction(){}
      
      virtual zorba::String
        getLocalName() const { return "prepare-library-module"; }

      virtual zorba::ItemSequence_t
        evaluate(const Arguments_t&,
                 const zorba::StaticContext*,
                 const zorba::DynamicContext*) const;
  };

  class IsBoundContextItemFunction : public XQXQFunction{
    public:
      IsBoundContextItemFunction(const XQXQModule* aModule) : XQXQFunction(aModule) {}

      virtual ~IsBoundContextItemFunction(){}

      virtual zorba::String
        getLocalName() const { return "is-bound-context-item"; }

      virtual zorba::ItemSequence_t
        evaluate(const Arguments_t&,
                 const zorba::StaticContext*,
                 const zorba::DynamicContext*) const;
  };

  class IsBoundVariableFunction : public XQXQFunction{
    public:
      IsBoundVariableFunction(const XQXQModule* aModule) : XQXQFunction(aModule) {}

      virtual ~IsBoundVariableFunction(){}

      virtual zorba::String
        getLocalName() const { return "is-bound-variable"; }

      virtual zorba::ItemSequence_t
        evaluate(const Arguments_t&,
                 const zorba::StaticContext*,
                 const zorba::DynamicContext*) const;
  };

  class GetExternalVariablesFunction : public XQXQFunction{
    public:
      GetExternalVariablesFunction(const XQXQModule* aModule) : XQXQFunction(aModule) {}

      virtual ~GetExternalVariablesFunction() {}

      virtual zorba::String
        getLocalName() const {return "external-variables"; }

      virtual zorba::ItemSequence_t
        evaluate(const Arguments_t&,
                 const zorba::StaticContext*,
                 const zorba::DynamicContext*) const;
  };

  class IsUpdatingFunction : public XQXQFunction{
    public:
      IsUpdatingFunction(const XQXQModule* aModule) : XQXQFunction(aModule) {}

      virtual ~IsUpdatingFunction() {}

      virtual zorba::String
        getLocalName() const {return "is-updating"; }

      virtual zorba::ItemSequence_t
        evaluate(const Arguments_t&,
                 const zorba::StaticContext*,
                 const zorba::DynamicContext*) const;

  };

  class IsSequentialFunction : public XQXQFunction{
    public:
      IsSequentialFunction(const XQXQModule* aModule) : XQXQFunction(aModule) {}

      virtual ~IsSequentialFunction() {}

      virtual zorba::String
        getLocalName() const {return "is-sequential"; }

      virtual zorba::ItemSequence_t
        evaluate(const Arguments_t&,
                 const zorba::StaticContext*,
                 const zorba::DynamicContext*) const;
  };

  class BindContextItemFunction : public XQXQFunction{
    public:
      BindContextItemFunction(const XQXQModule* aModule) : XQXQFunction(aModule) {}

      virtual ~BindContextItemFunction() {}

      virtual zorba::String
        getLocalName() const {return "bind-context-item"; }

      virtual zorba::ItemSequence_t
        evaluate(const Arguments_t&,
                 const zorba::StaticContext*,
                 const zorba::DynamicContext*) const;
  };

  class BindContextPositionFunction : public XQXQFunction{
    public:
      BindContextPositionFunction(const XQXQModule* aModule) : XQXQFunction(aModule) {}

      virtual ~BindContextPositionFunction() {}

      virtual zorba::String
        getLocalName() const {return "bind-context-position"; }

      virtual zorba::ItemSequence_t
        evaluate(const Arguments_t&,
                 const zorba::StaticContext*,
                 const zorba::DynamicContext*) const;
  };

  class BindContextSizeFunction : public XQXQFunction{
    public:
      BindContextSizeFunction(const XQXQModule* aModule) : XQXQFunction(aModule) {}

      virtual ~BindContextSizeFunction() {}

      virtual zorba::String
        getLocalName() const {return "bind-context-size"; }

      virtual zorba::ItemSequence_t
        evaluate(const Arguments_t&,
                 const zorba::StaticContext*,
                 const zorba::DynamicContext*) const;
  };

  class BindVariableFunction : public XQXQFunction{
    public:
      BindVariableFunction(const XQXQModule* aModule) : XQXQFunction(aModule) {}

      virtual ~BindVariableFunction() {}

      virtual zorba::String
        getLocalName() const {return "bind-variable"; }

      virtual zorba::ItemSequence_t
        evaluate(const Arguments_t&,
                 const zorba::StaticContext*,
                 const zorba::DynamicContext*) const;
  };

  /*******************************************************************************************
  *******************************************************************************************/
  class EvaluateItemSequence : public ItemSequence
  {
  protected:

    class EvaluateIterator : public Iterator
    {
      protected:
        Iterator_t theIterator;

        String theQueryID;

      public:
        EvaluateIterator(Iterator_t& aIter, String aQueryID)
          : theIterator(aIter), theQueryID(aQueryID)
        {
        }

        virtual ~EvaluateIterator(){}

        virtual void
          open()
        {
          theIterator->open();
        }

        virtual bool
          next(Item& aItem);

        virtual void 
          close()
        {
          theIterator->close();
        }

        virtual bool
          isOpen() const
        {
          return theIterator->isOpen();
        }

    };

    typedef zorba::SmartPtr<EvaluateIterator> EvaluateIterator_t;
    EvaluateIterator_t theIter; 

  public:
    EvaluateItemSequence(Iterator_t& aIter, String& aQueryID)
      :theIter (new EvaluateIterator(aIter, aQueryID))
    {
      
    }

    virtual ~EvaluateItemSequence() {}

    Iterator_t
      getIterator() { return theIter.get(); }
  };

  class EvaluateFunction : public XQXQFunction{
    public:
      EvaluateFunction(const XQXQModule* aModule) : XQXQFunction(aModule) {}

      virtual ~EvaluateFunction() {}

      virtual zorba::String
        getLocalName() const {return "evaluate"; }

      virtual zorba::ItemSequence_t
        evaluate(const Arguments_t&,
                 const zorba::StaticContext*,
                 const zorba::DynamicContext*) const;
  };

  class EvaluateUpdatingFunction : public XQXQFunction{
    public:
      EvaluateUpdatingFunction(const XQXQModule* aModule) : XQXQFunction(aModule) {}

      virtual ~EvaluateUpdatingFunction() {}

      virtual zorba::String
        getLocalName() const {return "evaluate-updating"; }

      virtual zorba::ItemSequence_t
        evaluate(const Arguments_t&,
                 const zorba::StaticContext*,
                 const zorba::DynamicContext*) const;
  };

  class EvaluateSequentialFunction : public XQXQFunction{
    public:
      EvaluateSequentialFunction(const XQXQModule* aModule) : XQXQFunction(aModule) {}

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
      const XQXQModule* theModule;
  };

  class DeleteQueryFunction : public XQXQFunction{
    public:
      DeleteQueryFunction(const XQXQModule* aModule) : XQXQFunction(aModule) {}

      virtual ~DeleteQueryFunction() {}

      virtual zorba::String
        getLocalName() const {return "delete-query"; }

      virtual zorba::ItemSequence_t
        evaluate(const Arguments_t&,
                 const zorba::StaticContext*,
                 const zorba::DynamicContext*) const;
  };



}/*xqxq namespace*/}/*zorba namespace*/


#endif //_COM_ZORBA_WWW_MODULES_XQXQ_H_
