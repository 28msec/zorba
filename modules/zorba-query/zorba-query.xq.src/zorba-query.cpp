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
#include <zorba/internal/unique_ptr.h>

#include <time.h>
#include <stdio.h>
#include <zorba/util/uuid.h>
#include <vector>

#include "zorba-query.h"

namespace zorba { namespace zorbaquery {

/*******************************************************************************

********************************************************************************/
zorba::ExternalFunction* ZorbaQueryModule::getExternalFunction(
    const zorba::String& localName)
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
    else if (localName == "variable-value")
    {
      lFunc = new VariableValueFunction(this);
    }
    else if (localName == "query-plan")
    {
      lFunc = new QueryPlanFunction(this);
    }
    else if (localName == "load-from-query-plan")
    {
      lFunc = new LoadFromQueryPlanFunction(this);
    }
  }
  
  return lFunc;
}
    

/*******************************************************************************
  Invoked from static_context::~static_context()
********************************************************************************/
void ZorbaQueryModule::destroy() 
{
  delete this;
}


/*******************************************************************************

********************************************************************************/
ZorbaQueryModule::~ZorbaQueryModule()
{
  for (FuncMap_t::const_iterator lIter = theFunctions.begin();
       lIter != theFunctions.end(); ++lIter) 
  {
    delete lIter->second;
  }
  theFunctions.clear();
}


/*******************************************************************************

********************************************************************************/
QueryData::QueryData(XQuery_t aQuery, URIMapper *aMapper, URLResolver *aResolver)
  :
  theQuery(aQuery),
  theURIMapper(aMapper),
  theURLResolver(aResolver)
{
}


/*******************************************************************************

********************************************************************************/
QueryData::~QueryData()
{
  theQuery->close();
  delete theURIMapper;
  delete theURLResolver;
}


/*******************************************************************************

********************************************************************************/
QueryMap::QueryMap()
{
  theQueryMap = new QueryMap_t();
}


/*******************************************************************************

********************************************************************************/
bool  QueryMap::storeQuery(
    const String& aKeyName,
    XQuery_t aQuery,
    URIMapper* aMapper,
    URLResolver* aResolver)
{
  QueryData_t lQueryData(new QueryData(aQuery, aMapper, aResolver));

  std::pair<QueryMap_t::iterator,bool> ret;

  ret = theQueryMap->insert(std::pair<String, QueryData_t>(aKeyName, lQueryData));

  return ret.second;
}


/*******************************************************************************

********************************************************************************/
XQuery_t QueryMap::getQuery(const String& aKeyName)
{
  QueryMap::QueryMap_t::iterator lIter = theQueryMap->find(aKeyName);

  if (lIter == theQueryMap->end())
    return NULL;
    
  XQuery_t lQuery = lIter->second->getQuery();

  return lQuery;
}


/*******************************************************************************

********************************************************************************/
bool QueryMap::deleteQuery(const String& aKeyName)
{
  QueryMap::QueryMap_t::iterator lIter = theQueryMap->find(aKeyName);

  if (lIter == theQueryMap->end())
    return false;

  theQueryMap->erase(lIter);
  return true;
}


/*******************************************************************************

********************************************************************************/
void QueryMap::destroy() throw()
{
  if (theQueryMap)
  {
    delete theQueryMap;
  }
  delete this;
}


/*******************************************************************************

********************************************************************************/
static void streamReleaser(std::istream* aStream)
{
  delete aStream;
}  
  

/*******************************************************************************

********************************************************************************/
void ZorbaQueryFunction::throwError(
    const char *err_localname,
    const std::string& aErrorMessage)
{
  String errNS(ZORBA_QUERY_MODULE_NAMESPACE);
  String errName(err_localname);
  Item errQName = ZorbaQueryModule::getItemFactory()->createQName(errNS, errName);
  String errDescription(aErrorMessage);
  throw USER_EXCEPTION(errQName, errDescription);
}


/*******************************************************************************

********************************************************************************/
ZorbaQueryFunction::ZorbaQueryFunction(const ZorbaQueryModule* aModule)
  :
  theModule(aModule)
{
  srand(static_cast<unsigned int>(::time(NULL)));
}
    

/*******************************************************************************

********************************************************************************/
ZorbaQueryFunction::~ZorbaQueryFunction()
{
}


/*******************************************************************************

********************************************************************************/
String ZorbaQueryFunction::getURI() const 
{
  return theModule->getURI();
}


/*******************************************************************************

********************************************************************************/
String ZorbaQueryFunction::getOneStringArgument(const Arguments_t& aArgs, int aPos) const
{
  Item lItem;
  Iterator_t args_iter = aArgs[aPos]->getIterator();
  args_iter->open();
  args_iter->next(lItem);
  String lTmpString = lItem.getStringValue();
  args_iter->close();
  return lTmpString;
}


/*******************************************************************************

********************************************************************************/
Item ZorbaQueryFunction::getItemArgument(const Arguments_t& aArgs, int aPos) const
{
  Item lItem;
  Iterator_t args_iter = aArgs[aPos]->getIterator();
  args_iter->open();
  args_iter->next(lItem);
  args_iter->close();
  
  return lItem;
}


/*******************************************************************************

********************************************************************************/
Iterator_t ZorbaQueryFunction::getIterArgument(const Arguments_t& aArgs, int aPos) const
{
  Iterator_t args_iter = aArgs[aPos]->getIterator();
  return args_iter;
}


/*******************************************************************************

********************************************************************************/
XQuery_t ZorbaQueryFunction::getQuery(
    const zorba::DynamicContext* aDctx,
    const zorba::String& aIdent) const
{
  QueryMap* lQueryMap;

  if (!(lQueryMap =
        dynamic_cast<QueryMap*>(aDctx->getExternalFunctionParameter("zqQueryMap"))))
  {
    throwError("NO_QUERY_MATCH", "No query with the given identifier was found");
  }
  
  XQuery_t lQuery;
  if (!(lQuery = lQueryMap->getQuery(aIdent)))
    throwError("NO_QUERY_MATCH", "No query with the given identifier was found");
  
  return lQuery;
}


/*******************************************************************************

********************************************************************************/
void  ZorbaQueryURIMapper::mapURI(
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
  ItemSequence_t lSeq1 = new SingletonItemSequence(ZorbaQueryModule::getItemFactory()->createString(aUri));
  ItemSequence_t lSeq2 = new SingletonItemSequence(ZorbaQueryModule::getItemFactory()->createString(lDataKind));
  lArgs.push_back(lSeq1);
  lArgs.push_back(lSeq2);

  ItemSequence_t lResult = theCtx->invoke(theFunction, lArgs);
  
  //Check if the result is an empty sequence by creating an Iterator, this is
  // cheaper than serializing the result and then checking if it was empty.
  Iterator_t lIter = lResult->getIterator();
  Item lItem;
  lIter->open();
  while (lIter->next(lItem))
  {
    //std::cout << lItem.getStringValue() << std::endl;
    oUris.push_back(lItem.getStringValue());
  }
  lIter->close();  
}
      

/*******************************************************************************

********************************************************************************/
Resource* ZorbaQueryURLResolver::resolveURL(
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
  ItemSequence_t lSeq1 = new SingletonItemSequence(ZorbaQueryModule::getItemFactory()->createString(aUrl));
  ItemSequence_t lSeq2 = new SingletonItemSequence(ZorbaQueryModule::getItemFactory()->createString(lDataKind));
  lArgs.push_back(lSeq1);
  lArgs.push_back(lSeq2);
  
  ItemSequence_t lResult = theCtx->invoke(theFunction, lArgs);

  // Check if the result is an empty sequence by creating an Iterator, this is
  // cheaper than serializing the result and then checking if it was empty.
  Iterator_t lIter = lResult->getIterator();
  Item lItem;
  lIter->open();
  lIter->next(lItem);
  lIter->close();
  lIter = NULL;

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
  return StreamResource::create(new std::istringstream(lSerResult.str()),
                                &streamReleaser);
}


/*******************************************************************************

********************************************************************************/
zorba::ItemSequence_t PrepareMainModuleFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const 
{
  DynamicContext* lDynCtx = const_cast<DynamicContext*>(aDctx);
  StaticContext_t lSctxChild = aSctx->createChildContext();
   
  QueryMap* lQueryMap =
  dynamic_cast<QueryMap*>(lDynCtx->getExternalFunctionParameter("zqQueryMap"));

  if (!lQueryMap)
  {
    lQueryMap = new QueryMap();
    lDynCtx->addExternalFunctionParameter("zqQueryMap", lQueryMap);     
  }

  Zorba* lZorba = Zorba::getInstance(0);

  String lQueryString = getOneStringArgument(aArgs, 0); 
    
  XQuery_t lQuery;

  StaticContext_t ltempSctx = lZorba->createStaticContext();
  ltempSctx->setBaseURI(aSctx->getBaseURI());

  std::unique_ptr<ZorbaQueryURLResolver> lResolver;
  std::unique_ptr<ZorbaQueryURIMapper> lMapper;

  if ( aArgs.size() > 2 )
  {
    Item lMapperFunctionItem = getItemArgument(aArgs, 2);
    if (!lMapperFunctionItem.isNull())
    {
      lMapper.reset(new ZorbaQueryURIMapper(lMapperFunctionItem, lSctxChild));
      ltempSctx->registerURIMapper(lMapper.get());
    }
  }

  if ( aArgs.size() > 1 )
  {
    Item lResolverFunctionItem = getItemArgument(aArgs, 1);
    if (!lResolverFunctionItem.isNull())
    {
      lResolver.reset(new ZorbaQueryURLResolver(lResolverFunctionItem, lSctxChild));
      ltempSctx->registerURLResolver(lResolver.get());
    }  
  }
  
  try
  {
    //std::cout << "Hello: " << lQueryString << std::endl;
    lQuery = lZorba->compileQuery(lQueryString, ltempSctx);
  }
  catch (XQueryException& xe)
  {
    lQuery = NULL;
    std::ostringstream err;
    err << "The query compiled using zq:prepare-main-module raised an error at"
        << " file " << xe.source_uri() << " line " << xe.source_line()
        << " column " << xe.source_column() << ": " << xe.what();
    // << " -- Query string : " << std::endl << lQueryString;

    Item errQName = ZorbaQueryModule::getItemFactory()->createQName(
                                xe.diagnostic().qname().ns(),
                                xe.diagnostic().qname().localname());
    throw USER_EXCEPTION(errQName, err.str());
  }
  catch (ZorbaException& e)
  {
    lQuery = NULL;
    std::ostringstream err;
    err << "The query compiled using zq:prepare-main-module raised an error: "
        << e.what();

    Item errQName = ZorbaQueryModule::getItemFactory()->
    createQName(e.diagnostic().qname().ns(), e.diagnostic().qname().localname());

    throw USER_EXCEPTION(errQName, err.str());
  }
  
  uuid lUUID;
  uuid::create(&lUUID);
  
  std::stringstream lStream;
  lStream << lUUID;
  
  String lStrUUID = lStream.str();
  
  lQueryMap->storeQuery(lStrUUID, lQuery, lMapper.release(), lResolver.release());
  
  return ItemSequence_t(new SingletonItemSequence(ZorbaQueryModule::getItemFactory()->createAnyURI(lStrUUID)));
}
    
    
/*******************************************************************************

********************************************************************************/
zorba::ItemSequence_t PrepareLibraryModuleFunction::evaluate(
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
    err << "The query compiled using zq:prepare-library-module raised an error at"
        << " line " << xe.source_line() << " column " << xe.source_column()
        << ": " << xe.what();

    Item errQName = ZorbaQueryModule::getItemFactory()->
    createQName(xe.diagnostic().qname().ns(), xe.diagnostic().qname().localname());

    throw USER_EXCEPTION(errQName, err.str());
  }
  catch (ZorbaException& e)
  {
    std::ostringstream err;
    err << "The query compiled using zq:prepare-main-query raised an error: "
        << e.what();

      Item errQName = ZorbaQueryModule::getItemFactory()->
      createQName(e.diagnostic().qname().ns(), e.diagnostic().qname().localname());

      throw USER_EXCEPTION(errQName, err.str());
    }
    return ItemSequence_t(new EmptySequence());
  }


/*******************************************************************************

********************************************************************************/
zorba::ItemSequence_t IsBoundContextItemFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const 
{
  String lQueryID = ZorbaQueryFunction::getOneStringArgument(aArgs, 0);

  XQuery_t lQuery = getQuery(aDctx, lQueryID);

  bool lIsContextItemBound = lQuery->getDynamicContext()->isBoundContextItem();

  return ItemSequence_t(new SingletonItemSequence(
          ZorbaQueryModule::getItemFactory()->createBoolean(lIsContextItemBound)));
}


/*******************************************************************************

********************************************************************************/
zorba::ItemSequence_t IsBoundVariableFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const 
{
  String lQueryID = ZorbaQueryFunction::getOneStringArgument(aArgs, 0);
  
  XQuery_t lQuery = getQuery(aDctx, lQueryID);

  Item lVarQName = ZorbaQueryFunction::getItemArgument(aArgs, 1);
  bool lIsBoundVariable = false;

  try
  {
    lIsBoundVariable = lQuery->getDynamicContext()->isBoundExternalVariable(lVarQName.getNamespace(),lVarQName.getLocalName());
  }
  catch (ZorbaException& ze)
  {
    if (ze.diagnostic() == zerr::ZAPI0011_VARIABLE_NOT_DECLARED)
      ZorbaQueryFunction::throwError("UNDECLARED_VARIABLE", ze.what());  
    throw; // should not happen
  }
  return ItemSequence_t(new SingletonItemSequence(ZorbaQueryModule::getItemFactory()->createBoolean(lIsBoundVariable)));
}


/*******************************************************************************

********************************************************************************/
zorba::ItemSequence_t GetExternalVariablesFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const 
{  
  String lQueryID = ZorbaQueryFunction::getOneStringArgument(aArgs, 0);

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


/*******************************************************************************

********************************************************************************/
zorba::ItemSequence_t IsUpdatingFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const 
{
  String lQueryID = ZorbaQueryFunction::getOneStringArgument(aArgs, 0);
  
  XQuery_t lQuery = getQuery(aDctx, lQueryID);

  return ItemSequence_t(new SingletonItemSequence(ZorbaQueryModule::getItemFactory()->createBoolean(lQuery->isUpdating())));
}


/*******************************************************************************

********************************************************************************/
zorba::ItemSequence_t IsSequentialFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const 
{
  String lQueryID = ZorbaQueryFunction::getOneStringArgument(aArgs, 0);
  
  XQuery_t lQuery = getQuery(aDctx, lQueryID);

  return ItemSequence_t(new SingletonItemSequence(ZorbaQueryModule::getItemFactory()->createBoolean(lQuery->isSequential())));
}


/*******************************************************************************

********************************************************************************/
zorba::ItemSequence_t BindContextItemFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const 
{
  String lQueryID = ZorbaQueryFunction::getOneStringArgument(aArgs,0);
  
  XQuery_t lQuery = getQuery(aDctx, lQueryID);

  // shouldn't raise errors
  Item lItemContext = ZorbaQueryFunction::getItemArgument(aArgs, 1);
  lQuery->getDynamicContext()->setContextItem(lItemContext);

  return ItemSequence_t(new EmptySequence());
}


/*******************************************************************************

********************************************************************************/
zorba::ItemSequence_t BindContextPositionFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const 
{
  ZorbaQueryFunction::throwError("ImplementationError", "This function is not implemented yet");

  return ItemSequence_t(new EmptySequence());
}


/*******************************************************************************

********************************************************************************/
zorba::ItemSequence_t BindContextSizeFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const 
{
  ZorbaQueryFunction::throwError("ImplementationError", "This function is not implemented yet");

  return ItemSequence_t(new EmptySequence());
}


/*******************************************************************************

********************************************************************************/
zorba::ItemSequence_t BindVariableFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const 
{
  String lQueryID = ZorbaQueryFunction::getOneStringArgument(aArgs,0);
  
  XQuery_t lQuery = getQuery(aDctx, lQueryID);
    
  Item lVarQName = ZorbaQueryFunction::getItemArgument(aArgs, 1); 

  Iterator_t lVarValue = ZorbaQueryFunction::getIterArgument(aArgs, 2); 

  if (!lQuery->getDynamicContext()->setVariable(lVarQName.getNamespace(),
                                                lVarQName.getLocalName(),
                                                lVarValue))
  {
    std::ostringstream lMsg;
    lMsg << "{" << lVarQName.getNamespace() << "}" << lVarQName.getLocalName()
         << ": undefined variable";

    throwError("UNDECLARED_VARIABLE", lMsg.str());
  }

  return ItemSequence_t(new EmptySequence());
}


/*******************************************************************************

********************************************************************************/
bool EvaluateItemSequence::EvaluateIterator::next(Item& aItem)
{
  try
  {
    return theIterator->next(aItem);
  }
  catch (XQueryException& xe)
  {
    std::ostringstream err;
    err << "The query " << "(" << theQueryID
        << ") evaluated using zq:evaluate raised an error at"
        << " line " << xe.source_line() << " column "
        << xe.source_column() << ": " << xe.what();

    Item errQName = ZorbaQueryModule::getItemFactory()->
    createQName(xe.diagnostic().qname().ns(), xe.diagnostic().qname().localname());

    throw USER_EXCEPTION(errQName, err.str());
  }
  catch (ZorbaException& e)
  {
    std::ostringstream err;
    err << "The query " << "(" << theQueryID
        << ") evaluated using zq:evaluate raised an error at"
        << e.what();

    Item errQName = ZorbaQueryModule::getItemFactory()->
    createQName(e.diagnostic().qname().ns(), e.diagnostic().qname().localname());

    throw USER_EXCEPTION(errQName, err.str());
  }
}


/*******************************************************************************

********************************************************************************/
zorba::ItemSequence_t EvaluateFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const 
{
  String lQueryID = ZorbaQueryFunction::getOneStringArgument(aArgs,0);

  XQuery_t lQuery = getQuery(aDctx, lQueryID);

  if (lQuery->isUpdating())
  {
    throwError("QUERY_IS_UPDATING", "Executing Query shouldn't be updating.");
  }
     
  if (lQuery->isSequential())
  {
    throwError("QUERY_IS_SEQUENTIAL", "Executing Query shouldn't be sequential.");
  }
      
  Iterator_t lIterQuery = lQuery->iterator();

  return ItemSequence_t(new EvaluateItemSequence(lIterQuery, lQueryID));
}


/*******************************************************************************

********************************************************************************/
zorba::ItemSequence_t EvaluateUpdatingFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const 
{
  String lQueryID = ZorbaQueryFunction::getOneStringArgument(aArgs,0);
  
  XQuery_t lQuery = getQuery(aDctx, lQueryID);
    
  if (lQuery->isSequential())
  {
    throwError("QUERY_IS_SEQUENTIAL", "Executing Query shouldn't be sequential.");   
  }

  if(!lQuery->isUpdating())
  {
    throwError("QUERY_NOT_UPDATING", "Executing Query should be updating.") ; 
  }
  
  Iterator_t lIterQuery = lQuery->iterator();
  return ItemSequence_t(new EvaluateItemSequence(lIterQuery, lQueryID));
}


/*******************************************************************************

********************************************************************************/
zorba::ItemSequence_t EvaluateSequentialFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const 
{
  String lQueryID = ZorbaQueryFunction::getOneStringArgument(aArgs, 0);
  
  XQuery_t lQuery = getQuery(aDctx, lQueryID);

  if(lQuery->isUpdating())
  {
    throwError("QUERY_IS_UPDATING", "Executing Query shouldn't be updating.");
  }

  if(!lQuery->isSequential())
  {
    throwError("QUERY_NOT_SEQUENTIAL", "Executing Query should be sequential.");    
  }

  Iterator_t lIterQuery = lQuery->iterator();
  return ItemSequence_t(new EvaluateItemSequence(lIterQuery, lQueryID));
}


/*******************************************************************************

********************************************************************************/
zorba::ItemSequence_t DeleteQueryFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const 
{
  String lQueryID = ZorbaQueryFunction::getOneStringArgument(aArgs,0);

  QueryMap* lQueryMap;
  if (!(lQueryMap= dynamic_cast<QueryMap*>(aDctx->getExternalFunctionParameter("zqQueryMap"))))
  {
    throwError("NO_QUERY_MATCH", "String identifying query does not exists.");
  }

  if (!lQueryMap->deleteQuery(lQueryID))
  {
    throwError("NO_QUERY_MATCH","String identifying query does not exists.");
  }
      
  return ItemSequence_t(new EmptySequence());
}


/*******************************************************************************

********************************************************************************/
zorba::ItemSequence_t VariableValueFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const 
{
  String lQueryID = ZorbaQueryFunction::getOneStringArgument(aArgs,0);

  QueryMap* lQueryMap;
  if (!(lQueryMap= dynamic_cast<QueryMap*>(aDctx->getExternalFunctionParameter("zqQueryMap"))))
  {
    throwError("NO_QUERY_MATCH", "String identifying query does not exists.");
  }

  XQuery_t lQuery = getQuery(aDctx, lQueryID);

  Item lVarQName = ZorbaQueryFunction::getItemArgument(aArgs, 1);
  bool lIsBoundVariable = false;

  zorba::DynamicContext* lCtx = lQuery->getDynamicContext();
  zorba::String lNS = lVarQName.getNamespace(), lLocal = lVarQName.getLocalName();
  
  try
  {
    lIsBoundVariable = lCtx->isBoundExternalVariable(lNS, lLocal);
  }
  catch (ZorbaException& ze)
  {
    if (ze.diagnostic() == zerr::ZAPI0011_VARIABLE_NOT_DECLARED)
      ZorbaQueryFunction::throwError("UNDECLARED_VARIABLE", ze.what());  
    throw; // should not happen
  }

  if (!lIsBoundVariable)
  {
    std::ostringstream lMsg;
    lMsg << lLocal << ": variable not bound";
    ZorbaQueryFunction::throwError("UNBOUND_VARIABLE", lMsg.str());  
  }

  zorba::Iterator_t lIterator;
  zorba::Item lItem;

  lCtx->getVariable(lNS, lLocal, lItem, lIterator);
      
  if (lIterator)
  {
    return ItemSequence_t(new ValueItemSequence(lIterator));
  }
  else
  {
    return ItemSequence_t(new SingletonItemSequence(lItem));
  }
}

/*******************************************************************************

********************************************************************************/
zorba::ItemSequence_t QueryPlanFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const 
{
  String lQueryID = ZorbaQueryFunction::getOneStringArgument(aArgs,0);

  QueryMap* lQueryMap;
  if (!(lQueryMap = dynamic_cast<QueryMap*>(aDctx->getExternalFunctionParameter("zqQueryMap"))))
  {
    throwError("NO_QUERY_MATCH", "String identifying query does not exists.");
  }

  XQuery_t lQuery = getQuery(aDctx, lQueryID);

  std::unique_ptr<std::stringstream> lExcPlan;
  lExcPlan.reset(new std::stringstream());
  if (!lQuery->saveExecutionPlan(*lExcPlan.get()))
  {
    throwError("NO_QUERY_PLAN", "FAILED getting query execution plan.");
  }
  
  return ItemSequence_t(new SingletonItemSequence(ZorbaQueryModule::getItemFactory()->createStreamableBase64Binary(*lExcPlan.release(), &streamReleaser)));
}
 

/*******************************************************************************

********************************************************************************/
zorba::ItemSequence_t LoadFromQueryPlanFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const 
{
  Item lQueryPlanItem = ZorbaQueryFunction::getItemArgument(aArgs,0);
  std::istream& lQueryPlanStream = lQueryPlanItem.getStream();

  DynamicContext* lDynCtx = const_cast<DynamicContext*>(aDctx);
  StaticContext_t lSctxChild = aSctx->createChildContext();
   
  QueryMap* lQueryMap;
  if (!(lQueryMap = dynamic_cast<QueryMap*>(lDynCtx->getExternalFunctionParameter("zqQueryMap"))))
  {
    lQueryMap = new QueryMap();
    lDynCtx->addExternalFunctionParameter("zqQueryMap", lQueryMap);     
  }

  Zorba* lZorba = Zorba::getInstance(0);
  XQuery_t lQuery;

  std::unique_ptr<ZorbaQueryURLResolver> lResolver;
  std::unique_ptr<ZorbaQueryURIMapper> lMapper;
  try
  {
    lQuery = lZorba->createQuery();
    if ( aArgs.size() > 2)
    {
      QueryPlanSerializationCallback lPlanSer;

      Item lMapperFunctionItem = getItemArgument(aArgs, 2);
      if (!lMapperFunctionItem.isNull())
      {
        lMapper.reset(new ZorbaQueryURIMapper(lMapperFunctionItem, lSctxChild));
        lPlanSer.add_URIMapper(lMapper.get());
      }

      Item lResolverFunctionItem = getItemArgument(aArgs, 1);
      if (!lResolverFunctionItem.isNull())
      {
        lResolver.reset(new ZorbaQueryURLResolver(lResolverFunctionItem, lSctxChild));
        lPlanSer.add_URLResolver(lResolver.get());
      }

      lQuery->loadExecutionPlan(lQueryPlanStream, &lPlanSer);
    }
    else
    { 
      lQuery->loadExecutionPlan(lQueryPlanStream);
    }
  }
  catch (XQueryException& xe)
  {
    lQuery = NULL;
    std::ostringstream err;
    err << "The query loaded from the query plan raised an error at"
      << " file" << xe.source_uri() << " line" << xe.source_line()
      << " column" << xe.source_column() << ": " << xe.what();
    Item errQName = ZorbaQueryModule::getItemFactory()->createQName(
      xe.diagnostic().qname().ns(),
      xe.diagnostic().qname().localname());
    throw USER_EXCEPTION(errQName, err.str());
  }
  catch (ZorbaException& ze)
  {
    lQuery = NULL;
    std::ostringstream err;
    if (ze.diagnostic() == zerr::ZCSE0013_UNABLE_TO_LOAD_QUERY)
      err << "The query loaded from the query plan raised an error: failed to load pre-compiled query: document, collection, or module resolver required but not given.";
    else
      err << "The query loaded from the query plan raised an error: "<< ze.what();
    Item errQName = ZorbaQueryModule::getItemFactory()->createQName(
      ze.diagnostic().qname().ns(),
      ze.diagnostic().qname().localname());
    throw USER_EXCEPTION(errQName, err.str());
  }

  uuid lUUID;
  uuid::create(&lUUID);

  std::stringstream lStream;
  lStream << lUUID;

  String lStrUUID = lStream.str();

  lQueryMap->storeQuery(lStrUUID, lQuery, lMapper.release(), lResolver.release());
  return ItemSequence_t(new SingletonItemSequence(ZorbaQueryModule::getItemFactory()->createAnyURI(lStrUUID)));
}

}/*namespace zorbaquery*/ }/*namespace zorba*/

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::zorbaquery::ZorbaQueryModule();
}
