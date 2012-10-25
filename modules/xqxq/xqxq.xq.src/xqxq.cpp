#include <zorba/item_factory.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/diagnostic_list.h>
#include <zorba/empty_sequence.h>
#include <zorba/store_manager.h>
#include <zorba/user_exception.h>
#include <zorba/uri_resolvers.h>
#include <zorba/vector_item_sequence.h>
#include <zorba/serializer.h>
#include <zorba/xquery.h>
#include <time.h>
#include <stdio.h>
#include <zorba/util/uuid.h>
#include <vector>

#include "xqxq.h"

namespace zorba { namespace xqxq {

  /*******************************************************************************************
  *******************************************************************************************/

  zorba::ExternalFunction*
    XQXQModule::getExternalFunction(const zorba::String& localName)
  {
    
    FuncMap_t::iterator lIte = theFunctions.find(localName);
    
    ExternalFunction*& lFunc = theFunctions[localName];

    if (lIte == theFunctions.end())
    {
      if (localName == "prepare-main-module")
      {
        lFunc = new PrepareMainModuleFunction(this);
      }
      if (localName == "prepare-library-module")
      {
        lFunc = new PrepareLibraryModuleFunction(this);
      }
      else if (localName == "is-bound-context-item")
      {
        lFunc = new IsBoundContextItemFunction(this);
      }
      else if (localName == "is-bound-variable")
      {
        lFunc = new IsBoundVariableFunction(this);
      }
      else if (localName == "external-variables")
      {
        lFunc = new GetExternalVariablesFunction(this);
      }
      else if (localName == "is-updating")
      {
        lFunc = new IsUpdatingFunction(this);        
      }
      else if (localName == "is-sequential")
      {
        lFunc = new IsSequentialFunction(this);
      }      
      else if (localName == "bind-context-item")
      {
        lFunc = new BindContextItemFunction(this);
      }
      else if (localName == "bind-variable")
      {
        lFunc = new BindVariableFunction(this);
      }
      else if (localName == "evaluate")
      {
        lFunc = new EvaluateFunction(this);
      }
      else if (localName == "evaluate-updating")
      {
        lFunc = new EvaluateUpdatingFunction(this);
      }
      else if (localName == "evaluate-sequential")
      {
        lFunc = new EvaluateSequentialFunction(this);
      }
      else if (localName == "delete-query")
      {
        lFunc = new DeleteQueryFunction(this);
      }
    }

    return lFunc;
  }

  void XQXQModule::destroy() 
  {
    delete this;
  }

  XQXQModule::~XQXQModule()
  {
    for (FuncMap_t::const_iterator lIter = theFunctions.begin();
       lIter != theFunctions.end(); ++lIter) 
    {
      delete lIter->second;
    }
    theFunctions.clear();
  }

  /*******************************************************************************************
  *******************************************************************************************/
  XQXQFunction::XQXQFunction(const XQXQModule* aModule)
    : theModule(aModule)
  {
    srand(time(NULL));
  }

  XQXQFunction::~XQXQFunction()
  {
    
  }

  String XQXQFunction::getURI() const 
  {
    return theModule->getURI();
  }

  String
    XQXQFunction::getOneStringArgument(const Arguments_t& aArgs, int aPos) const
  {
    Item lItem;
    Iterator_t args_iter = aArgs[aPos]->getIterator();
    args_iter->open();
    args_iter->next(lItem);
    String lTmpString = lItem.getStringValue();
    args_iter->close();
    return lTmpString;
  }


  Item
    XQXQFunction::getItemArgument(const Arguments_t& aArgs, int aPos) const
  {
    Item lItem;
    Iterator_t args_iter = aArgs[aPos]->getIterator();
    args_iter->open();
    args_iter->next(lItem);
    args_iter->close();

    return lItem;
  }

  Iterator_t
    XQXQFunction::getIterArgument(const Arguments_t& aArgs, int aPos) const
  {
    Iterator_t args_iter = aArgs[aPos]->getIterator();
    return args_iter;
  }

  XQuery_t
  XQXQFunction::getQuery(
      const zorba::DynamicContext* aDctx,
      const zorba::String& aIdent) const
  {
    QueryMap* lQueryMap;
    if (!(lQueryMap= dynamic_cast<QueryMap*>(aDctx->getExternalFunctionParameter("xqxqQueryMap"))))
    {
      throwError("NoQueryMatch", "No query with the given identifier was found");
    }

    XQuery_t lQuery;
    if (!(lQuery = lQueryMap->getQuery(aIdent)))
      throwError("NoQueryMatch", "No query with the given identifier was found");

    return lQuery;
  }

  void
    XQXQFunction::throwError(const char *err_localname, const std::string aErrorMessage)
  {
    String errNS(XQXQ_MODULE_NAMESPACE);
    String errName(err_localname);
    Item errQName = XQXQModule::getItemFactory()->createQName(errNS, errName);
    String errDescription(aErrorMessage);
    throw USER_EXCEPTION(errQName, errDescription);
  }

  /*******************************************************************************************
  *******************************************************************************************/

  QueryData::QueryData(XQuery_t aQuery, URIMapper *aMapper, URLResolver *aResolver)
    : theQuery(aQuery),
      theURIMapper(aMapper),
      theURLResolver(aResolver)
  {
  }

  QueryData::~QueryData()
  {
    theQuery->close();
    delete theURIMapper;
    delete theURLResolver;
  }

  /*******************************************************************************************
  *******************************************************************************************/

  QueryMap::QueryMap()
  {
    QueryMap::queryMap = new QueryMap_t();
  }

  bool 
    QueryMap::storeQuery(const String& aKeyName, XQuery_t aQuery,
                         URIMapper* aMapper, URLResolver* aResolver)
  {
    QueryData_t lQueryData(new QueryData(aQuery, aMapper, aResolver));
    std::pair<QueryMap_t::iterator,bool> ret;
    ret = queryMap->insert(std::pair<String, QueryData_t>(aKeyName, lQueryData));
    return ret.second;
  }

  XQuery_t
    QueryMap::getQuery(const String& aKeyName)
  {
    QueryMap::QueryMap_t::iterator lIter = queryMap->find(aKeyName);

    if(lIter == queryMap->end())
      return NULL;
    
    XQuery_t lQuery = lIter->second->getQuery();

    return lQuery;
  }

  bool
    QueryMap::deleteQuery(const String& aKeyName)
  {
    QueryMap::QueryMap_t::iterator lIter = queryMap->find(aKeyName);

    if(lIter == queryMap->end())
      return false;

    queryMap->erase(lIter);
    return true;
  }

  void
    QueryMap::destroy() throw()
  {
    if(queryMap)
    {
      for (QueryMap_t::const_iterator lIter = queryMap->begin();
           lIter != queryMap->end(); ++lIter)
      {
        deleteQuery(lIter->first);
      }
      queryMap->clear();
      delete queryMap;
    }
    delete this;
  }

  /*******************************************************************************************
  *******************************************************************************************/
  static void streamReleaser(std::istream* aStream)
  {
    delete aStream;
  }  
  
  void 
    PrepareMainModuleFunction::XQXQURIMapper::mapURI(
     String aUri,
     EntityData const* aEntityData,
     std::vector<String>& oUris)
  {
    //Create entityData string to send to the new url resolver
    String lDataKind;
    switch (aEntityData->getKind())
    {
      case EntityData::SCHEMA:
        lDataKind = "schema";
        break;
      case EntityData::MODULE:
        lDataKind = "module";
        break;
      default:
        break;
    }

    //construct the arguments for the url resolver
    std::vector<ItemSequence_t> lArgs;
    ItemSequence_t lSeq0 = new SingletonItemSequence(theFunction);
    ItemSequence_t lSeq1 = new SingletonItemSequence(XQXQModule::getItemFactory()->createString(aUri));
    ItemSequence_t lSeq2 = new SingletonItemSequence(XQXQModule::getItemFactory()->createString(lDataKind));
    lArgs.push_back(lSeq0);
    lArgs.push_back(lSeq1);
    lArgs.push_back(lSeq2);

    //invoke the HOF helper function using the arguments generated
    Item lHofHelper = XQXQModule::getItemFactory()->createQName("http://www.zorba-xquery.com/modules/xqxq", "xqxq", "hof-invoker");
    ItemSequence_t lResult = theCtx->invoke(lHofHelper, lArgs);

    //Check if the result is an empty sequence by creating an Iterator, this is cheaper than serializing the result
    //and then checking if it was empty.
    Iterator_t lIter = lResult->getIterator();
    Item lItem;
    lIter->open();
    while (lIter->next(lItem))
    {
      std::cout << lItem.getStringValue() << std::endl;
      oUris.push_back(lItem.getStringValue());
    }
    lIter->close();

  }
      

  Resource*
    PrepareMainModuleFunction::XQXQURLResolver::resolveURL(
    const String& aUrl,
    EntityData const* aEntityData)
  { 
    //Create entityData string to send to the new url resolver
    String lDataKind;
    switch (aEntityData->getKind())
    {
      case EntityData::SCHEMA:
        lDataKind = "schema";
        break;
      case EntityData::MODULE:
        lDataKind = "module";
        break;
      default:
        break;
    }

    //construct the arguments for the url resolver
    std::vector<ItemSequence_t> lArgs;
    ItemSequence_t lSeq0 = new SingletonItemSequence(theFunction);
    ItemSequence_t lSeq1 = new SingletonItemSequence(XQXQModule::getItemFactory()->createString(aUrl));
    ItemSequence_t lSeq2 = new SingletonItemSequence(XQXQModule::getItemFactory()->createString(lDataKind));
    lArgs.push_back(lSeq0);
    lArgs.push_back(lSeq1);
    lArgs.push_back(lSeq2);

    //invoke the HOF helper function using the arguments generated
    Item lHofHelper = XQXQModule::getItemFactory()->createQName("http://www.zorba-xquery.com/modules/xqxq", "xqxq", "hof-invoker");
    ItemSequence_t lResult = theCtx->invoke(lHofHelper, lArgs);

    //Check if the result is an empty sequence by creating an Iterator, this is cheaper than serializing the result
    //and then checking if it was empty.
    Iterator_t lIter = lResult->getIterator();
    Item lItem;
    lIter->open();
    lIter->next(lItem);
    lIter->close();
    if (lItem.isNull())
      return NULL;

    //Serialize resulting sequence of the resolver
    Zorba_SerializerOptions_t lOpt;
    if (lItem.isNode())
      lOpt.ser_method = ZORBA_SERIALIZATION_METHOD_XML;
    else
      lOpt.ser_method = ZORBA_SERIALIZATION_METHOD_TEXT;
    lOpt.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    Serializer_t lSer = Serializer::createSerializer(lOpt);
    std::stringstream lSerResult;
    lSer->serialize(lResult, lSerResult);

    //return resource
    return StreamResource::create(new std::istringstream(lSerResult.str()), &streamReleaser);
  }

  zorba::ItemSequence_t
    PrepareMainModuleFunction::evaluate(
      const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const 
  {
    DynamicContext* lDynCtx = const_cast<DynamicContext*>(aDctx);
    StaticContext_t lSctxChild = aSctx->createChildContext();
   
    QueryMap* lQueryMap;
    if(!(lQueryMap = dynamic_cast<QueryMap*>(lDynCtx->getExternalFunctionParameter("xqxqQueryMap"))))
    {
      lQueryMap = new QueryMap();
      lDynCtx->addExternalFunctionParameter("xqxqQueryMap", lQueryMap);     
    }

    Zorba *lZorba = Zorba::getInstance(0);

    String lQueryString = getOneStringArgument(aArgs, 0); 
    
    XQuery_t lQuery;
    
    StaticContext_t ltempSctx = lZorba->createStaticContext();
    std::auto_ptr<XQXQURLResolver> lResolver;
    std::auto_ptr<XQXQURIMapper> lMapper;

    if ( aArgs.size() > 2 )
    {
      Item lMapperFunctionItem = getItemArgument(aArgs, 2);
      if (!lMapperFunctionItem.isNull())
      {
        lMapper.reset(new XQXQURIMapper(lMapperFunctionItem, lSctxChild));
        ltempSctx->registerURIMapper(lMapper.get());
      }
    }

    if ( aArgs.size() > 1 )
    {
      Item lResolverFunctionItem = getItemArgument(aArgs, 1);
      if (!lResolverFunctionItem.isNull())
      {
        lResolver.reset(new XQXQURLResolver(lResolverFunctionItem, lSctxChild));
        ltempSctx->registerURLResolver(lResolver.get());
      }

    }

    try
    {
      lQuery = lZorba->compileQuery(lQueryString, ltempSctx);
    }
    catch (XQueryException& xe)
    {
      lQuery = NULL;
      std::ostringstream err;
      err << "The query compiled using xqxq:prepare-main-module raised an error at"
          << " line " << xe.source_line() << " column " << xe.source_column() << ": " << xe.what();
      Item errQName = XQXQModule::getItemFactory()->createQName(
          xe.diagnostic().qname().ns(), xe.diagnostic().qname().localname());
      throw USER_EXCEPTION(errQName, err.str());
    }
    catch (ZorbaException& e)
    {
      lQuery = NULL;
      std::ostringstream err;
      err << "The query compiled using xqxq:prepare-main-module raised an error: "
          << e.what();
      Item errQName = XQXQModule::getItemFactory()->createQName(
          e.diagnostic().qname().ns(), e.diagnostic().qname().localname());
      throw USER_EXCEPTION(errQName, err.str());
    }

    uuid lUUID;
    uuid::create(&lUUID);
    
    std::stringstream lStream;
    lStream << lUUID;

    String lStrUUID = lStream.str();

    lQueryMap->storeQuery(lStrUUID, lQuery, lMapper.release(), lResolver.release());
    
    return ItemSequence_t(new SingletonItemSequence(XQXQModule::getItemFactory()->createAnyURI(lStrUUID)));
  }


  /*******************************************************************************************
  *******************************************************************************************/
  zorba::ItemSequence_t
    PrepareLibraryModuleFunction::evaluate(
      const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const 
  {
    Zorba *lZorba = Zorba::getInstance(0);
    String lQueryString = getOneStringArgument(aArgs, 0);     
 
    Zorba_CompilerHints_t hints;
    hints.lib_module = true;

    try
    {
      lZorba->compileQuery(lQueryString, hints);
    }
    catch (XQueryException& xe)
    {
      std::ostringstream err;
      err << "The query compiled using xqxq:prepare-library-module raised an error at"
          << " line " << xe.source_line() << " column " << xe.source_column() << ": " << xe.what();
      Item errQName = XQXQModule::getItemFactory()->createQName(
          xe.diagnostic().qname().ns(), xe.diagnostic().qname().localname());
      throw USER_EXCEPTION(errQName, err.str());
    }
    catch (ZorbaException& e)
    {
      std::ostringstream err;
      err << "The query compiled using xqxq:prepare-main-query raised an error: "
          << e.what();
      Item errQName = XQXQModule::getItemFactory()->createQName(
          e.diagnostic().qname().ns(), e.diagnostic().qname().localname());
      throw USER_EXCEPTION(errQName, err.str());
    }
    return ItemSequence_t(new EmptySequence());
  }

  /*******************************************************************************************
  *******************************************************************************************/
  zorba::ItemSequence_t
    IsBoundContextItemFunction::evaluate(
      const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const 
  {

    String lQueryID = XQXQFunction::getOneStringArgument(aArgs, 0);

    XQuery_t lQuery = getQuery(aDctx, lQueryID);

    bool lIsContextItemBound = lQuery->getDynamicContext()->isBoundContextItem();

    return ItemSequence_t(new SingletonItemSequence(
          XQXQModule::getItemFactory()->createBoolean(lIsContextItemBound)));
  }

  /*******************************************************************************************
  *******************************************************************************************/
  zorba::ItemSequence_t
    IsBoundVariableFunction::evaluate(
      const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const 
  {
    String lQueryID = XQXQFunction::getOneStringArgument(aArgs, 0);
    
    XQuery_t lQuery = getQuery(aDctx, lQueryID);

    Item lVarQName = XQXQFunction::getItemArgument(aArgs, 1);
    bool lIsBoundVariable = false;

    try
    {
      lIsBoundVariable = lQuery->getDynamicContext()->isBoundExternalVariable(lVarQName.getNamespace(),lVarQName.getLocalName());
    }
    catch (ZorbaException& ze)
    {
      if (ze.diagnostic() == zerr::ZAPI0011_ELEMENT_NOT_DECLARED)
        XQXQFunction::throwError("UndeclaredVariable", ze.what());  
      throw; // should not happen
    }
    return ItemSequence_t(new SingletonItemSequence(XQXQModule::getItemFactory()->createBoolean(lIsBoundVariable)));
  
  }

  /*******************************************************************************************
  *******************************************************************************************/
  zorba::ItemSequence_t
    GetExternalVariablesFunction::evaluate(
      const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const 
  {
    
    String lQueryID = XQXQFunction::getOneStringArgument(aArgs, 0);

    XQuery_t lQuery = getQuery(aDctx, lQueryID);
    
    std::vector<Item> lVars;
    Iterator_t lVarsIterator;
    lQuery->getExternalVariables(lVarsIterator);

    Item lVar;
    lVarsIterator->open();
    while(lVarsIterator->next(lVar))
      lVars.push_back(lVar);
    lVarsIterator->close();

    return ItemSequence_t(new VectorItemSequence(lVars));
  }
  /*******************************************************************************************
  *******************************************************************************************/
  zorba::ItemSequence_t
    IsUpdatingFunction::evaluate(
      const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const 
  {
    String lQueryID = XQXQFunction::getOneStringArgument(aArgs, 0);

    XQuery_t lQuery = getQuery(aDctx, lQueryID);

    return ItemSequence_t(new SingletonItemSequence(XQXQModule::getItemFactory()->createBoolean(lQuery->isUpdating())));
  }

  /*******************************************************************************************
  *******************************************************************************************/
  zorba::ItemSequence_t
    IsSequentialFunction::evaluate(
      const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const 
  {
    String lQueryID = XQXQFunction::getOneStringArgument(aArgs, 0);

    XQuery_t lQuery = getQuery(aDctx, lQueryID);

    return ItemSequence_t(new SingletonItemSequence(XQXQModule::getItemFactory()->createBoolean(lQuery->isSequential())));
  }

  /*******************************************************************************************
  *******************************************************************************************/
  zorba::ItemSequence_t
    BindContextItemFunction::evaluate(
      const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const 
  {
    String lQueryID = XQXQFunction::getOneStringArgument(aArgs,0);

    XQuery_t lQuery = getQuery(aDctx, lQueryID);

    // shouldn't raise errors
    Item lItemContext = XQXQFunction::getItemArgument(aArgs, 1);
    lQuery->getDynamicContext()->setContextItem(lItemContext);

    return ItemSequence_t(new EmptySequence());
  }

  /*******************************************************************************************
  *******************************************************************************************/
  zorba::ItemSequence_t
    BindContextPositionFunction::evaluate(
      const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const 
  {

    XQXQFunction::throwError("ImplementationError", "This function is not implemented yet");

    return ItemSequence_t(new EmptySequence());
  }

  /*******************************************************************************************
  *******************************************************************************************/
  zorba::ItemSequence_t
    BindContextSizeFunction::evaluate(
      const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const 
  {

    XQXQFunction::throwError("ImplementationError", "This function is not implemented yet");

    return ItemSequence_t(new EmptySequence());
  }

  /*******************************************************************************************
  *******************************************************************************************/
  zorba::ItemSequence_t
    BindVariableFunction::evaluate(
      const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const 
  {
    String lQueryID = XQXQFunction::getOneStringArgument(aArgs,0);

    XQuery_t lQuery = getQuery(aDctx, lQueryID);
    
    Item lVarQName = XQXQFunction::getItemArgument(aArgs, 1); 

    Iterator_t lVarValue = XQXQFunction::getIterArgument(aArgs, 2); 

    if (!lQuery->getDynamicContext()->setVariable(
          lVarQName.getNamespace(), lVarQName.getLocalName() , lVarValue))
    {
      std::ostringstream lMsg;
      lMsg << "{" << lVarQName.getNamespace() << "}" << lVarQName.getLocalName()
        << ": undefined variable";
      throwError("UndeclaredVariable", lMsg.str());
    }

    return ItemSequence_t(new EmptySequence());
  }

  /*******************************************************************************************
  *******************************************************************************************/
  bool
    EvaluateItemSequence::EvaluateIterator::next(Item& aItem)
  {
    try
    {
      return theIterator->next(aItem);
    }
    catch (XQueryException& xe)
    {
      std::ostringstream err;
      err << "The query " << "(" << theQueryID << ") evaluated using xqxq:evaluate raised an error at"
          << " line " << xe.source_line() << " column " << xe.source_column() << ": " << xe.what();
      Item errQName = XQXQModule::getItemFactory()->createQName(
          xe.diagnostic().qname().ns(), xe.diagnostic().qname().localname());
      throw USER_EXCEPTION(errQName, err.str());
    }
    catch (ZorbaException& e)
    {
      std::ostringstream err;
      err << "The query " << "(" << theQueryID << ") evaluated using xqxq:evaluate raised an error at"
          << e.what();
      Item errQName = XQXQModule::getItemFactory()->createQName(
          e.diagnostic().qname().ns(), e.diagnostic().qname().localname());
      throw USER_EXCEPTION(errQName, err.str());
    }
  }

  /*******************************************************************************************
  *******************************************************************************************/
  zorba::ItemSequence_t
    EvaluateFunction::evaluate(
      const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const 
  {
    String lQueryID = XQXQFunction::getOneStringArgument(aArgs,0);

    XQuery_t lQuery = getQuery(aDctx, lQueryID);

    if(lQuery->isUpdating())
    {
      throwError("QueryIsUpdating", "Executing Query shouldn't be updating.");
    }
    
   
    if(lQuery->isSequential())
    {
      throwError("QueryIsSequential", "Executing Query shouldn't be sequential.");
    }
      
    Iterator_t lIterQuery = lQuery->iterator();

    return ItemSequence_t(new EvaluateItemSequence(lIterQuery, lQueryID));
  }

  /*******************************************************************************************
  *******************************************************************************************/
  zorba::ItemSequence_t
    EvaluateUpdatingFunction::evaluate(
      const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const 
  {
    String lQueryID = XQXQFunction::getOneStringArgument(aArgs,0);

    XQuery_t lQuery = getQuery(aDctx, lQueryID);
    
    if(lQuery->isSequential())
    {
      throwError("QueryIsSequential", "Executing Query shouldn't be sequential.");   
    }

    if(!lQuery->isUpdating())
    {
      throwError("QueryNotUpdating", "Executing Query should be updating.") ; 
    }
    
    Iterator_t lIterQuery = lQuery->iterator();
    return ItemSequence_t(new EvaluateItemSequence(lIterQuery, lQueryID));
}

  /*******************************************************************************************
  *******************************************************************************************/
  zorba::ItemSequence_t
    EvaluateSequentialFunction::evaluate(
      const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const 
  {
    String lQueryID = XQXQFunction::getOneStringArgument(aArgs, 0);

    XQuery_t lQuery = getQuery(aDctx, lQueryID);

    if(lQuery->isUpdating())
    {
      throwError("QueryIsUpdating", "Executing Query shouldn't be updating.");
    }

    if(!lQuery->isSequential())
    {
      throwError("QueryNotSequential", "Executing Query should be sequential.");    
    }

    Iterator_t lIterQuery = lQuery->iterator();
    return ItemSequence_t(new EvaluateItemSequence(lIterQuery, lQueryID));
  }

  /*******************************************************************************************
  *******************************************************************************************/
  zorba::ItemSequence_t
    DeleteQueryFunction::evaluate(
      const Arguments_t& aArgs,
      const zorba::StaticContext* aSctx,
      const zorba::DynamicContext* aDctx) const 
  {
    String lQueryID = XQXQFunction::getOneStringArgument(aArgs,0);

    QueryMap* lQueryMap;
    if (!(lQueryMap= dynamic_cast<QueryMap*>(aDctx->getExternalFunctionParameter("xqxqQueryMap"))))
    {
      throwError("NoQueryMatch", "String identifying query does not exists.");
    }

    if (!lQueryMap->deleteQuery(lQueryID))
    {
      throwError("NoQueryMatch","String identifying query does not exists.");
    }
      
    return ItemSequence_t(new EmptySequence());
  }
 
}/*namespace xqxq*/ }/*namespace zorba*/

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::xqxq::XQXQModule();
}
