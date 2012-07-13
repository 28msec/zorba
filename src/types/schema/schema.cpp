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
#include "stdafx.h"

#include <string>

#include "compiler/parser/query_loc.h"
#include "context/namespace_context.h"
#include "context/static_context.h"
#include "context/uri_resolver.h"

#include "zorbamisc/ns_consts.h"
#include "diagnostics/assert.h"

#include "types/typeimpl.h"
#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "types/casting.h"
#include "types/schema/schema.h"
#include "types/schema/StrX.h"
#include "types/schema/LoadSchemaErrorHandler.h"
#include "types/schema/PrintSchema.h"
#include "types/schema/XercesParseUtils.h"
#include "system/globalenv.h"
#include "store/api/item_factory.h"
#include "util/utf8_util.h"
#include "types/schema/xercesIncludes.h"
#include "zorbatypes/URI.h"

#ifndef ZORBA_NO_XMLSCHEMA
# include <xercesc/util/XercesVersion.hpp>
# if XERCES_VERSION_MAJOR < 3
    typedef unsigned int XMLFilePos;
    typedef unsigned int Zorba_readBytes_type;
# else 
    typedef XMLSize_t Zorba_readBytes_type;
# endif
# include <xercesc/util/XercesDefs.hpp>
# include <xercesc/util/BinInputStream.hpp>
# include <zorbatypes/xerces_xmlcharray.h>
#endif /* ZORBA_NO_XMLSCHEMA */


#include "zorbaserialization/serialize_template_types.h"
#include "zorbaserialization/serialize_zorba_types.h"


namespace zorba
{
SERIALIZABLE_CLASS_VERSIONS(Schema)

//#define DO_TRACE
//#define DO_PRINT_SCHEMA_INFO

#ifdef DO_TRACE

#define TRACE(msg)                                                            \
  {                                                                           \
    std::cout << __FUNCTION__ << ": " << msg << std::endl; std::cout.flush(); \
  }

#else
#define TRACE(msg)
#endif


const char* Schema::XSD_NAMESPACE = XML_SCHEMA_NS;

bool Schema::theIsInitialized = false;

#ifndef ZORBA_NO_XMLSCHEMA


static void transcode(const XMLCh* const str, zstring& res)
{
  char* trStr = XMLString::transcode(str);
  res = zstring(trStr);
  XMLString::release(&trStr);
}


/**
 * A Xerces BinInputStream that returns bytes from a std::istream.
 */
class IstreamBinInputStream : public XERCES_CPP_NAMESPACE::BinInputStream
{
public:
  IstreamBinInputStream(std::istream* aStream)
    : 
    theStream(aStream)
  {
  }

  virtual XMLFilePos curPos() const
  {
    return theStream->tellg();
  }

  virtual Zorba_readBytes_type readBytes
  (XMLByte * const toFill, const Zorba_readBytes_type maxToRead)
  {
    // QQQ Is this reinterpret_cast necessary? Is it safe? Can I just
    // pump the chars from read() to the XMLBytes Xerces wants?
    char* const lToFill = reinterpret_cast<char*>(toFill);
    TRACE("lToFill: " << lToFill );
    theStream->read(lToFill, maxToRead);
    return static_cast<unsigned int>(theStream->gcount());
  }

  virtual const XMLCh* getContentType() const
  {
    // Unless we know it, do what Xerces' implementation does: return 0
    return 0;
  }

private:
  std::istream* theStream;
};


/**
 * A Xerces InputSource that returns a IstreamBinInputStream.
 */
class IstreamInputSource : public XERCES_CPP_NAMESPACE::InputSource
{
public:
  IstreamInputSource(std::istream* aStream, StreamReleaser aStreamReleaser)
    : theStream(aStream),
      theStreamReleaser(aStreamReleaser)
  {
  }

  ~IstreamInputSource()
  {
    if (theStreamReleaser) 
    {
      theStreamReleaser(theStream);
    }
  }

  virtual XERCES_CPP_NAMESPACE::BinInputStream* makeStream() const
  {
    return new IstreamBinInputStream(theStream);
  }

private:
  std::istream* theStream;
  StreamReleaser theStreamReleaser;
};


/**
 * A Xerces EntityResolver that looks for a specific URL and returns
 * InputSource that reads from a particular std::istream.
 */
class StaticContextEntityResolver : 
    public XERCES_CPP_NAMESPACE::EntityResolver
{
public:
  /**
   * EntityResolver method
   */
  XERCES_CPP_NAMESPACE::InputSource* resolveEntity(
    const XMLCh* const publicId,
    const XMLCh* const systemId)
  {
    TRACE("pId: " << StrX(publicId) << "  sId: " << StrX(systemId));
    if (XMLString::compareString(systemId, theLogicalURI) == 0)
    {
      TRACE("logiUri: " << StrX(theLogicalURI) << " physicalUri: " << StrX(thePhysicalURI));
      // Pass memory ownership of the istream to the IstreamInputSource
      InputSource* lRetval = new IstreamInputSource(theStream, theStreamReleaser);
      theStreamReleaser = nullptr;
      
      lRetval->setSystemId(thePhysicalURI);
      return lRetval;
    }
    else if (publicId==NULL && systemId==NULL)
    {
      TRACE("No systemId and no publicId provided.");
      return NULL;
    }
    else
    {
      const XMLCh* lId;
      bool isPublicId = false;
      bool isSystemId = false;
      
      if (systemId==NULL)
      {
        TRACE("Resolving based on publicId: " << StrX(publicId));
        lId = publicId;
        isPublicId = true;
      }
      else   // publicId must be non-NULL since it was previously checked
      {
        TRACE("Resolving based on systemId: " << StrX(systemId));
        lId = systemId;
        isSystemId = true;
      }
      
      std::auto_ptr<internal::Resource> lResource;
      
      zstring lStrId = StrX(lId).localForm();
      zstring lResolved;
      
      URI lUri(lStrId);
      if ( !lUri.is_absolute() )
      {
        // must be resolved based on the schema location thePhysicalURI
        zstring fullBase(StrX(thePhysicalURI).localForm());
        zstring::size_type i = fullBase.find_last_of("/");
        zstring base = fullBase.substr(0, i == zstring::npos ? fullBase.length() : i+1);
        URI resolvedURI( base, lUri.toString(), true);
        lResolved = resolvedURI.toString();
        TRACE("i: " << i << " base: " << base << " lUri: " << lUri << " lRes: " << lResolved);
      }
      else
        lResolved = lStrId;
      
      try
      {
        TRACE("lId: " << StrX(lId) << " lResolved: " << lResolved << " thePhysURI: " << StrX(thePhysicalURI));
        zstring lErrorMessage;
        lResource = theSctx->resolve_uri(lResolved, internal::EntityData::SCHEMA, lErrorMessage);
        internal::StreamResource* lStream =
            dynamic_cast<internal::StreamResource*>(lResource.get());
        if (lStream != NULL)
        {
          // Pass memory ownership of this istream to the new IstreamInputSource
          InputSource* lRetval = new IstreamInputSource
              (lStream->getStream(), lStream->getStreamReleaser());
          lStream->setStreamReleaser(nullptr);
          
          XMLCh * lResolvedXMLCh = XMLString::transcode(lResolved.c_str());
          if (isSystemId)
            lRetval->setSystemId(lResolvedXMLCh);
          
          if (isPublicId)
            lRetval->setPublicId(lResolvedXMLCh);

          // release lResolvedXMLCh since setSystemId and setPublicId are makeing their own copies
          XMLString::release(&lResolvedXMLCh);
            
          return lRetval;
        }
        else
          return NULL;          
      }
      catch (ZorbaException const& e) {
        TRACE("!!! ZorbaException: " << e );
        if ( e.diagnostic() == zerr::ZXQP0029_URI_ACCESS_DENIED )
        {
          throw;
        }
        else
        {
          //don't throw let Xerces resolve it
          return NULL;
        }
      }
    }
  }

  StaticContextEntityResolver(
    const XMLCh* const aLogicalURI,
    static_context * aSctx,
    internal::StreamResource* aStreamResource)
    : theLogicalURI(aLogicalURI), theSctx(aSctx)
  {
    // Take memory ownership of the istream
    theStream = aStreamResource->getStream();
    theStreamReleaser = aStreamResource->getStreamReleaser();
    aStreamResource->setStreamReleaser(nullptr);
    // Take memory ownership of the translated system ID
    thePhysicalURI = XERCES_CPP_NAMESPACE::XMLString::transcode
      (aStreamResource->getStreamUrl().c_str());
  }

  ~StaticContextEntityResolver()
  {
    XERCES_CPP_NAMESPACE::XMLString::release(&thePhysicalURI);
    if (theStreamReleaser) {
      theStreamReleaser(theStream);
    }
  }

private:
  const XMLCh * theLogicalURI;
  static_context * theSctx;
  std::istream* theStream;
  StreamReleaser theStreamReleaser;
  XMLCh * thePhysicalURI;
};

#endif //ZORBA_NO_XMLSCHEMA


/*******************************************************************************
  Initialize the Xerces platform. Called from GlobalEnvironment::init().
*******************************************************************************/
void Schema::initialize()
{
#ifndef ZORBA_NO_XMLSCHEMA
  if (theIsInitialized)
    return;

  try
  {
    XERCES_CPP_NAMESPACE::XMLPlatformUtils::Initialize();
    theIsInitialized = true;
  }
  catch (const XERCES_CPP_NAMESPACE::XMLException& toCatch)
  {
    std::cerr   << "Error during Xerces-C initialization! Message:\n"
                << StrX(toCatch.getMessage()) << std::endl;
    return;
  }
#endif
}


/*******************************************************************************
  Terminate the Xerces platform. Called from GlobalEnvironment::destroy().
*******************************************************************************/
void Schema::terminate()
{
#ifndef ZORBA_NO_XMLSCHEMA
  if (theIsInitialized)
  {
    XERCES_CPP_NAMESPACE::XMLPlatformUtils::Terminate();
    theIsInitialized = false;
  }
#endif
}


/*******************************************************************************

*******************************************************************************/
Schema::Schema(TypeManager* tm)
  :
  theTypeManager(tm)
{
#ifndef ZORBA_NO_XMLSCHEMA
  theGrammarPool = new XMLGrammarPoolImpl(XMLPlatformUtils::fgMemoryManager);
  // QQQ should be zstring
  theUdTypesCache = 
  new HashMap<zstring, xqtref_t, HashMapZStringCmp>(64, false);
#endif
}


Schema::Schema(::zorba::serialization::Archiver& ar)
{
#ifndef ZORBA_NO_XMLSCHEMA
  initialize();
  theGrammarPool = new XMLGrammarPoolImpl(XMLPlatformUtils::fgMemoryManager);
#endif
}


/*******************************************************************************

*******************************************************************************/
Schema::~Schema()
{
#ifndef ZORBA_NO_XMLSCHEMA
  delete theGrammarPool;
  delete theUdTypesCache;
#endif
}



/*******************************************************************************
  Prints out info about the current schema grammar
*******************************************************************************/
void Schema::printXSDInfo(bool excludeBuiltIn)
{
#ifndef ZORBA_NO_XMLSCHEMA
  PrintSchema::printInfo(excludeBuiltIn, theGrammarPool);
#endif
}


#ifndef ZORBA_NO_XMLSCHEMA


/*******************************************************************************
  Registers an imported schema into the curent grammar
*******************************************************************************/
void Schema::registerXSD(const char* xsdURL,
  static_context * aSctx,
  internal::StreamResource* stream,
  const QueryLoc& loc)
{
  std::auto_ptr<SAX2XMLReader> parser;

  TRACE("url=" << xsdURL << " loc=" << loc);

  try
  {
    SAX2XMLReader* reader =
      XMLReaderFactory::createXMLReader(XMLPlatformUtils::fgMemoryManager,
					theGrammarPool);

    parser.reset(reader);
    // Perform namespace processing
    parser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
    // Do not report attributes used for namespace declarations and optionally
    // do not report original prefixed names
    parser->setFeature(XMLUni::fgSAX2CoreNameSpacePrefixes, false);
    // Enable parser's schema support
    parser->setFeature(XMLUni::fgXercesSchema, true);
    // time and memory intensive to be disabled only if schema files
    // previously checked
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);
    // report all validation errors
    parser->setFeature(XMLUni::fgSAX2CoreValidation, true);
    // validate only if schema is available
    parser->setFeature(XMLUni::fgXercesDynamic, true);
    // load the schema in the grammar pool
    ////parser->setFeature(XMLUni::fgXercesLoadSchema, true);
    // disables network resolver
    parser->setFeature(XMLUni::fgXercesDisableDefaultEntityResolution, true);
    // skip DTDs
    parser->setFeature(XMLUni::fgXercesLoadExternalDTD, false);

    parser->setProperty(XMLUni::fgXercesScannerName,
                        (void *)XMLUni::fgSGXMLScanner);

    LoadSchemaErrorHandler handler(loc);
    parser->setErrorHandler(&handler);

    XMLChArray xerces_xsdURL(xsdURL);
    StaticContextEntityResolver lEntityResolver(xerces_xsdURL.get(), aSctx, stream);
    parser->setEntityResolver(&lEntityResolver);

    //this works but using loadProlog
    //parser->loadGrammar("file:///location/file.xsd",
    //                    Grammar::SchemaGrammarType, true);

    parser->loadGrammar(xsdURL, Grammar::SchemaGrammarType, true);

    if (handler.getSawErrors())
    {
      handler.resetErrors();
    }
  }
  catch (const OutOfMemoryException&)
  {
    throw XQUERY_EXCEPTION( err::XQST0059,
        ERROR_PARAMS( std::string(xsdURL), ZED( SchemaOutOfMemory )),
        ERROR_LOC( loc ) );
  }
  catch (const XMLException& e)
  {
    throw XQUERY_EXCEPTION( err::XQST0059,
        ERROR_PARAMS( std::string(xsdURL), ZED( SchemaParseError ), StrX(e.getMessage())),
        ERROR_LOC( loc ) );
  }
  catch (const ZorbaException& /* e */)
  {
    throw;
  }
  catch (...)
  {
    throw XQUERY_EXCEPTION( err::XQST0059,
        ERROR_PARAMS( std::string(xsdURL), ZED( SchemaUnexpected )),
        ERROR_LOC( loc ) );
  }

#ifdef DO_PRINT_SCHEMA_INFO
  // enable this to debug registered user defined schema types
  printXSDInfo(true);
#endif
}


/*******************************************************************************
  For the given element name find out its declared schema type
*******************************************************************************/
void Schema::getTypeNameFromElementName(
    const store::Item* qname,
    store::Item_t& typeName,
    const QueryLoc& loc)
{
  XSTypeDefinition* typeDef = getTypeDefForElement(qname);

  if (!typeDef)
  {
    throw XQUERY_EXCEPTION(
      err::XPST0008,
      ERROR_PARAMS( qname->getStringValue(), ZED( SchemaElementName ) ),
      ERROR_LOC( loc )
    );
  }

  const XMLCh* typeNameStr = typeDef->getName();
  const XMLCh* typeUri = typeDef->getNamespace();

  GENV_ITEMFACTORY->createQName(typeName,
                                StrX(typeUri).localForm(),
                                "",
                                StrX(typeNameStr).localForm());
}


/*******************************************************************************
  For a given global attribute find out its declared schema type
*******************************************************************************/
void Schema::getTypeNameFromAttributeName(
    const store::Item* qname,
    store::Item_t& typeName,
    const QueryLoc& loc)
{
  XSTypeDefinition* typeDef = getTypeDefForAttribute(qname);

  if (!typeDef)
  {
    throw XQUERY_EXCEPTION(
      err::XPST0008,
      ERROR_PARAMS( qname->getStringValue(), ZED( SchemaAttributeName ) ),
      ERROR_LOC( loc )
    );
  }

  const XMLCh* typeNameStr = typeDef->getName();
  const XMLCh* typeUri = typeDef->getNamespace();

  GENV_ITEMFACTORY->createQName(typeName,
                                StrX(typeUri).localForm(),
                                "",
                                StrX(typeNameStr).localForm());
}


/*******************************************************************************
  Returns an XQType for a global schema element definition if defined,
  otherwise NULL
*******************************************************************************/
xqtref_t Schema::createXQTypeFromElementName(
    const TypeManager* typeManager,
    const store::Item* qname,
    const bool riseErrors,
    const QueryLoc& loc)
{
  TRACE("qn:" << qname->getLocalName() << " @ " <<
        qname->getNamespace() );

  XSTypeDefinition* typeDef = getTypeDefForElement(qname);

  if (!riseErrors && !typeDef)
      return NULL;

  if (!typeDef)
  {
    throw XQUERY_EXCEPTION(
      err::XPST0008,
      ERROR_PARAMS( qname->getStringValue(), ZED( SchemaElementName ) ),
      ERROR_LOC( loc )
    );
  }

  xqtref_t res = createXQTypeFromTypeDefinition(typeManager, typeDef);
  TRACE("res:" << res->get_qname()->getLocalName() << " @ " <<
        res->get_qname()->getNamespace());

  return res;
}


/*******************************************************************************
  Returns an XQType for a global schema attribute definition if defined,
  otherwise NULL
*******************************************************************************/
xqtref_t Schema::createXQTypeFromAttributeName(
    const TypeManager* typeManager,
    const store::Item* qname,
    const bool riseErrors,
    const QueryLoc& loc)
{
  XSTypeDefinition* typeDef = getTypeDefForAttribute(qname);

  if (!riseErrors && !typeDef)
      return NULL;

  if (!typeDef)
  {
    throw XQUERY_EXCEPTION(
      err::XPST0008,
      ERROR_PARAMS( qname->getStringValue(), ZED( SchemaAttributeName ) ),
      ERROR_LOC( loc )
    );
  }

  return createXQTypeFromTypeDefinition(typeManager, typeDef);
}


/*******************************************************************************
  Checks if the Type with the qname exists in the schema as a user-defined type
  if it does than return an XQType for it, if not return NULL
*******************************************************************************/
xqtref_t Schema::createXQTypeFromTypeName(
    const TypeManager* typeManager,
    const store::Item* qname)
{
  XSTypeDefinition* typeDef = NULL;
  xqtref_t res;

  TRACE("typeManager: " << typeManager << " type qname: "
        << qname->getLocalName() << "@"
        << qname->getNamespace());

  if (theGrammarPool == NULL)
        return NULL;

  const zstring& nsuri = qname->getNamespace();
  const zstring& local = qname->getLocalName();

  // check the cache first
  zstring key;
  key.reserve(local.size() + nsuri.size() + 4);
  key += local;
  key += ":";
  key += nsuri;
  key += " ";
  key += TypeOps::decode_quantifier(TypeConstants::QUANT_ONE);

  if( theUdTypesCache->get(key, res))
    return res;

    // not found in cache, make a new one
  XMLChArray xml_local(local.c_str());
  XMLChArray xml_uri(nsuri.c_str());

  bool modelHasChanged;
  XSModel* xsModel = theGrammarPool->getXSModel(modelHasChanged);

  typeDef = xsModel->getTypeDefinition(xml_local, xml_uri);

  if ( typeDef == NULL )
  {
    // Go through all the top level type and element definitions and
    // add annonymous types to the cache
    //( maybe stop whenever it's found - a small optimization )
    // this is required only when the multiple queries are executed in
    // the same run with the current API, but with empty schema context

    TRACE("lookingFor: key:'" << key);
    checkForAnonymousTypes(typeManager);

    if( theUdTypesCache->get(key, res))
      return res;

    res = NULL;
    TRACE("No type definition for " << xml_local << "@" << xml_uri);
    TRACE("add to TypesCache: key:'" << key << "'  t:"
          << ( res==NULL ? "NULL" :
               TypeOps::decode_quantifier(res->get_quantifier())) );
    // stick it in the cache even if it's NULL
    theUdTypesCache->insert(key, res);
  }
  else
  {
    res = createXQTypeFromTypeDefinition(typeManager, typeDef);
  }

  return res;
}


/*******************************************************************************
  Get the the head of the substitution group, if any, that a given globally
  declared element belongs to.
*******************************************************************************/
void Schema::getSubstitutionHeadForElement(
    const store::Item* qname,
    store::Item_t& result)
{
  TRACE(" element qname: " << qname->getLocalName() << "@"
        << qname->getNamespace());

  result = NULL;

  if (theGrammarPool == NULL)
    return;

  XMLChArray local(qname->getLocalName().c_str());
  XMLChArray uri(qname->getNamespace().c_str());

  bool xsModelWasChanged;
  XSModel* model = theGrammarPool->getXSModel(xsModelWasChanged);

  XSElementDeclaration* decl = model->getElementDeclaration(local, uri);

  if (decl)
  {
    XSElementDeclaration* substHead = decl->getSubstitutionGroupAffiliation();

    if (substHead)
    {
      const XMLCh* localName = substHead->getName();
      const XMLCh* nsuri = substHead->getNamespace();

      zstring lLocal;
      transcode(localName, lLocal);
      zstring lNamespace;
      transcode(nsuri, lNamespace);

      GENV_ITEMFACTORY->createQName(result, lNamespace, zstring(), lLocal);
    }
  }
}


/*******************************************************************************
  Get the type definition for a globally declared element
*******************************************************************************/
XSTypeDefinition* Schema::getTypeDefForElement(const store::Item* qname)
{
  XSTypeDefinition* typeDef = NULL;

  TRACE(" element qname: " << qname->getLocalName() << "@" <<
        qname->getNamespace());

  if (theGrammarPool == NULL)
    return NULL;

  XMLChArray local(qname->getLocalName().c_str());
  XMLChArray uri(qname->getNamespace().c_str());

  bool xsModelWasChanged;
  XSModel* model = theGrammarPool->getXSModel(xsModelWasChanged);

  XSElementDeclaration* decl = model->getElementDeclaration(local, uri);

  if (decl)
  {
    typeDef = decl->getTypeDefinition();

    // this works only on the element that is a substitution,
    // not on substitution base element
    //XSElementDeclaration * substGroup =
    //  decl->getSubstitutionGroupAffiliation();

    //if ( substGroup )
    //{
    //    TRACE(" substitutionGroup qname: " << StrX(substGroup->getName()) <<
    //      "@" << StrX(substGroup->getNamespace()) << "\n");
    //}
  }

  return typeDef;
}


/*******************************************************************************
  Get the type definition for a globally declared attribute
*******************************************************************************/
XSTypeDefinition* Schema::getTypeDefForAttribute(const store::Item* qname)
{
  XSTypeDefinition* typeDef = NULL;

  TRACE(" attribute qname: " << qname->getLocalName() << "@" <<
        qname->getNamespace());

  if (theGrammarPool == NULL)
    return NULL;

  XMLChArray local(qname->getLocalName().c_str());
  XMLChArray uri(qname->getNamespace().c_str());

  bool xsModelWasChanged;
  XSModel* model = theGrammarPool->getXSModel(xsModelWasChanged);

  XSAttributeDeclaration* decl = model->getAttributeDeclaration(local, uri);

  if (decl)
    typeDef = decl->getTypeDefinition();

  return typeDef;
}


/*******************************************************************************
  Creates a zorba schema type for a schema type definition
*******************************************************************************/
xqtref_t Schema::createXQTypeFromTypeDefinition(
    const TypeManager* typeManager,
    XSTypeDefinition* xsTypeDef)
{
  if (!xsTypeDef)
  {
    ZORBA_ASSERT(false);
    return NULL;
  }

  xqtref_t result;

  if (xsTypeDef->getTypeCategory() == XSTypeDefinition::SIMPLE_TYPE)
  {
    // first check if it is a built-in type
    const XMLCh* uri = xsTypeDef->getNamespace();
    zstring strUri;
    transcode(uri, strUri);

    if ( XMLString::equals(strUri.c_str(), Schema::XSD_NAMESPACE) )
    {
      const XMLCh* local = xsTypeDef->getName();

      result = createXQTypeFromTypeDefForBuiltinTypes(typeManager, strUri,
                                                      local);
    }
    else
    {
      // must be a user defined simple type
      XSSimpleTypeDefinition * xsSimpleTypeDef =
        (XSSimpleTypeDefinition *)xsTypeDef;

      zstring lLocal;
      transcode(xsTypeDef->getName(), lLocal);

      store::Item_t qname;
      GENV_ITEMFACTORY->createQName(qname, strUri, zstring(), lLocal);
      TRACE("createXQType " << qname->getStringValue() );

      switch ( xsSimpleTypeDef->getVariety() )
      {
      case XSSimpleTypeDefinition::VARIETY_ATOMIC:
      {
        XSTypeDefinition* baseTypeDef = xsTypeDef->getBaseType();
        if ( !baseTypeDef )
        {
          //error allway must have a baseType
          ZORBA_ASSERT(false);
          result = NULL;
        }

        xqtref_t baseXQType = createXQTypeFromTypeDefinition(typeManager,
            baseTypeDef);

        xqtref_t xqType = xqtref_t(new UserDefinedXQType(typeManager,
                                                 qname,
                                                 baseXQType,
                                                 TypeConstants::QUANT_ONE,
                                                 UserDefinedXQType::ATOMIC_TYPE,
                                                 XQType::SIMPLE_CONTENT_KIND));
        TRACE("created atomic " << qname->getStringValue() << " base:" << baseXQType->toString());
        result = xqType;
      }
      break;

      case XSSimpleTypeDefinition::VARIETY_LIST:
      {
        XSSimpleTypeDefinition * itemTypeDef = xsSimpleTypeDef->getItemType();
        if ( !itemTypeDef )
        {
          //error since VARIETY is LIST must have an itemType
          ZORBA_ASSERT(false);
          result = NULL;
        }
        xqtref_t itemXQType = createXQTypeFromTypeDefinition(typeManager,
            itemTypeDef);

        if ( itemXQType->type_kind() == XQType::USER_DEFINED_KIND )
        {   // if UDT add it to the cache, otherwise it will get lost
          addTypeToCache(itemXQType);
        }

        //cout << " creating UDT Simple List Type: " <<
        //  qname->getLocalName()->c_str() <<  "@" <<
        //  qname->getNamespace()->c_str() << " of " << itemXQType->toString()
        //    << endl; cout.flush();

        xqtref_t xqType = xqtref_t(
            new UserDefinedXQType(typeManager,
                                  qname,
                                  NULL /*GENV_TYPESYSTEM.ANY_SIMPLE_TYPE*/,
                                  TypeConstants::QUANT_ONE,
                                  itemXQType.getp()));

        //cout << "   created UDT Simple List Type: " << xqType->toString() <<
        //  endl; cout.flush();
        addTypeToCache(xqType);

        result = xqType;
      }
      break;

      case XSSimpleTypeDefinition::VARIETY_UNION:
      {
        XSSimpleTypeDefinitionList * memberTypesDefList =
            xsSimpleTypeDef->getMemberTypes();

        if ( !memberTypesDefList )
        {
          //error since VARIETY is UNION must have a memberTypesDefList
          ZORBA_ASSERT(false);
          result = NULL;
        }

        //cout << " creating UDT Simple Union Type: " <<
        // qname->getLocalName()->c_str() << "@" <<
        // qname->getNamespace()->c_str() << " of: ";
        std::vector<xqtref_t> unionItemTypes;

        for ( unsigned int i = 0; i < memberTypesDefList->size(); i++)
        {
          XSSimpleTypeDefinition* itemTypeDef =
            memberTypesDefList->elementAt(i);
          xqtref_t itemXQType = createXQTypeFromTypeDefinition(typeManager,
                                                               itemTypeDef);
          unionItemTypes.push_back(itemXQType);
          //cout << " " << itemXQType->toString();

          if ( itemXQType->type_kind() == XQType::USER_DEFINED_KIND )
          {   // if UDT add it to the cache, otherwise it will get lost
            addTypeToCache(itemXQType);
          }
        }
        //cout << endl; cout.flush();

        xqtref_t xqType = xqtref_t(
            new UserDefinedXQType(typeManager,
                                  qname,
                                  NULL /*GENV_TYPESYSTEM.ANY_SIMPLE_TYPE*/,
                                  TypeConstants::QUANT_ONE,
                                  unionItemTypes));

        //cout << "   created UDT Union Type: " << xqType->toString() << endl;
        //  cout.flush();
        addTypeToCache(xqType);

        result = xqType;
      }
      break;

      case XSSimpleTypeDefinition::VARIETY_ABSENT:
        // Xerces source says it must be anySimpleType
        result = GENV_TYPESYSTEM.ANY_SIMPLE_TYPE;
        break;

      default:
        ZORBA_ASSERT(false);
      }

      checkForAnonymousTypesInType(typeManager, xsTypeDef);

    } // end user defined simple types
  }     // end simple types
  else
  {
    // is not a simple type has to be complex
    ZORBA_ASSERT( xsTypeDef->getTypeCategory()==XSTypeDefinition::COMPLEX_TYPE);

    // first check if it is a built-in type
    const XMLCh* uri = xsTypeDef->getNamespace();
    zstring strUri;
    transcode(uri, strUri);

    if ( XMLString::equals(strUri.c_str(), Schema::XSD_NAMESPACE) )
    {
      const XMLCh* local = xsTypeDef->getName();
      // maybe there is a better way than comparing strings
      // but it seems Xerces doesn't have a code for built-in types
      if ( XMLString::equals(XMLChArray("anyType").get(), local) )
      {
        result = GENV_TYPESYSTEM.ANY_TYPE;
      }
      else if ( XMLString::equals(XMLChArray("untyped").get(), local) )
      {
        result = GENV_TYPESYSTEM.UNTYPED_TYPE;
      }
      else
      {
        // there are no other non simple known types in xsd namespace
        ZORBA_ASSERT(false);
      }
    }
    else
    {
      // user defined complex Type
      XSTypeDefinition* baseTypeDef = xsTypeDef->getBaseType();
      if ( !baseTypeDef )
      {
        //error allways must have a baseType
        ZORBA_ASSERT(false);
        result = NULL;
      }

      xqtref_t baseXQType = createXQTypeFromTypeDefinition(typeManager,
                                                           baseTypeDef);

      zstring lLocal;
      transcode(xsTypeDef->getName(), lLocal);

      store::Item_t qname;
      GENV_ITEMFACTORY->createQName(qname, strUri, zstring(), lLocal);

      TRACE("udComplexType: " << StrX(xsTypeDef->getName()) << " @ " <<
            StrX(xsTypeDef->getNamespace()) );

      // get content type
      XSComplexTypeDefinition* xsComplexTypeDef =
        static_cast<XSComplexTypeDefinition*>(xsTypeDef);

      XQType::content_kind_t contentType;

      switch(xsComplexTypeDef->getContentType())
      {
      case XSComplexTypeDefinition::CONTENTTYPE_MIXED:
        contentType = XQType::MIXED_CONTENT_KIND;
        break;
      case XSComplexTypeDefinition::CONTENTTYPE_ELEMENT:
        contentType = XQType::ELEMENT_ONLY_CONTENT_KIND;
        break;
      case XSComplexTypeDefinition::CONTENTTYPE_SIMPLE:
        contentType = XQType::SIMPLE_CONTENT_KIND;
        break;
      case XSComplexTypeDefinition::CONTENTTYPE_EMPTY:
        contentType = XQType::EMPTY_CONTENT_KIND;
        break;
      default:
        ZORBA_ASSERT(false);
      }

      xqtref_t xqType =
            xqtref_t(new UserDefinedXQType(typeManager,
                                           qname,
                                           baseXQType,
                                           TypeConstants::QUANT_ONE,
                                           UserDefinedXQType::COMPLEX_TYPE,
                                           contentType));

      result = xqType;

      addTypeToCache(xqType);

      //check if it contains anonymous types (they are not available through
      //  xsModel API) add them to the cache
      checkForAnonymousTypesInType(typeManager, xsTypeDef);
    }
  }

  return result;
}


xqtref_t Schema::createXQTypeFromTypeDefForBuiltinTypes(
    const TypeManager* typeManager, zstring& strUri,
    const XMLCh* local)
{
  xqtref_t result;

  ZORBA_ASSERT( XMLString::equals(strUri.c_str(), Schema::XSD_NAMESPACE) );

  // maybe there is a better way than comparing strings
  // but it seems Xerces doesn't have a code for built-in types
  if ( XMLString::equals(SchemaSymbols::fgDT_STRING, local) )
  {
    result = GENV_TYPESYSTEM.STRING_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_INT, local) )
  {
    result = GENV_TYPESYSTEM.INT_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_BOOLEAN, local) )
  {
    result = GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_INTEGER, local) )
  {
    result = GENV_TYPESYSTEM.INTEGER_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_POSITIVEINTEGER, local) )
  {
    result = GENV_TYPESYSTEM.POSITIVE_INTEGER_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_NONPOSITIVEINTEGER, local) )
  {
    result = GENV_TYPESYSTEM.NON_POSITIVE_INTEGER_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_NEGATIVEINTEGER, local) )
  {
    result = GENV_TYPESYSTEM.NEGATIVE_INTEGER_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_NONNEGATIVEINTEGER, local) )
  {
    result = GENV_TYPESYSTEM.NON_NEGATIVE_INTEGER_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_UBYTE, local) )
  {
    result = GENV_TYPESYSTEM.UNSIGNED_BYTE_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_USHORT, local) )
  {
    result = GENV_TYPESYSTEM.UNSIGNED_SHORT_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_UINT, local) )
  {
    result = GENV_TYPESYSTEM.UNSIGNED_INT_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_ULONG, local) )
  {
    result = GENV_TYPESYSTEM.UNSIGNED_LONG_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_BYTE, local) )
  {
    result = GENV_TYPESYSTEM.BYTE_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_SHORT, local) )
  {
    result = GENV_TYPESYSTEM.SHORT_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_LONG, local) )
  {
    result = GENV_TYPESYSTEM.LONG_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_FLOAT, local) )
  {
    result = GENV_TYPESYSTEM.FLOAT_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_DOUBLE, local) )
  {
    result = GENV_TYPESYSTEM.DOUBLE_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_DECIMAL, local) )
  {
    result = GENV_TYPESYSTEM.DECIMAL_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_NORMALIZEDSTRING, local) )
  {
    result = GENV_TYPESYSTEM.NORMALIZED_STRING_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_TOKEN, local) )
  {
    result = GENV_TYPESYSTEM.TOKEN_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_NAME, local) )
  {
    result = GENV_TYPESYSTEM.NAME_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_NCNAME, local) )
  {
    result = GENV_TYPESYSTEM.NCNAME_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_DATETIME, local) )
  {
    result = GENV_TYPESYSTEM.DATETIME_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_DATE, local) )
  {
    result = GENV_TYPESYSTEM.DATE_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_TIME, local) )
  {
    result = GENV_TYPESYSTEM.TIME_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_YEAR, local) )
  {
    result = GENV_TYPESYSTEM.GYEAR_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_YEARMONTH, local) )
  {
    result = GENV_TYPESYSTEM.GYEAR_MONTH_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_MONTHDAY, local) )
  {
    result = GENV_TYPESYSTEM.GMONTH_DAY_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_DAY, local) )
  {
    result = GENV_TYPESYSTEM.GDAY_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_MONTH, local) )
  {
    result = GENV_TYPESYSTEM.GMONTH_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_DURATION, local) )
  {
    result = GENV_TYPESYSTEM.DURATION_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_ANYSIMPLETYPE, local) )
  {
    result = GENV_TYPESYSTEM.ANY_SIMPLE_TYPE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_BASE64BINARY, local) )
  {
    result = GENV_TYPESYSTEM.BASE64BINARY_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_HEXBINARY, local) )
  {
    result = GENV_TYPESYSTEM.HEXBINARY_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_ANYURI, local) )
  {
    result = GENV_TYPESYSTEM.ANY_URI_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgDT_QNAME, local) )
  {
    result = GENV_TYPESYSTEM.QNAME_TYPE_ONE;
  }
  else if ( XMLString::equals(SchemaSymbols::fgATTVAL_ID, local) )
  {
    result = GENV_TYPESYSTEM.ID_TYPE_ONE;
  }
  // SchemaSymbols::fgDT_NMTOKEN doesn't exist in Xerces
  else if ( XMLString::equals(XMLChArray("NMTOKEN").get (), local) )
  {
    result = GENV_TYPESYSTEM.NMTOKEN_TYPE_ONE;
  }
  else if ( XMLString::equals(XMLChArray("NMTOKENS").get (), local) )
  {
	store::Item_t qname;
	GENV_ITEMFACTORY->createQName(qname,
								  XML_SCHEMA_NS,
								  "XS",
								  "NMTOKENS");

	result = new UserDefinedXQType(typeManager,
								   qname,
								   NULL,
								   TypeConstants::QUANT_ONE,
								   GENV_TYPESYSTEM.NMTOKEN_TYPE_ONE.getp());
  }
  else if ( XMLString::equals(XMLChArray("IDREF").get (), local) )
  {
    result = GENV_TYPESYSTEM.IDREF_TYPE_ONE;
  }
  else if ( XMLString::equals(XMLChArray("IDREFS").get (), local) )
  {
    store::Item_t qname;
    GENV_ITEMFACTORY->createQName(qname,
                                  XML_SCHEMA_NS,
                                  "XS",
                                  "IDREFS");

    result = new UserDefinedXQType(typeManager,
                                   qname,
                                   NULL,
                                   TypeConstants::QUANT_ONE,
                                   GENV_TYPESYSTEM.IDREF_TYPE_ONE.getp());
  }
  else if ( XMLString::equals(XMLChArray("ENTITY").get (), local) )
  {
    store::Item_t qname;
    GENV_ITEMFACTORY->createQName(qname,
                                  XML_SCHEMA_NS,
                                  "XS",
                                  "ENTITIES");

    result = new UserDefinedXQType(typeManager,
                                   qname,
                                   NULL,
                                   TypeConstants::QUANT_ONE,
                                   GENV_TYPESYSTEM.ENTITY_TYPE_ONE.getp());
  }
  else if ( XMLString::equals(XMLChArray("ENTITIES").get (), local) )
  {
    result = GENV_TYPESYSTEM.ENTITY_TYPE_PLUS;
  }
  else if ( XMLString::equals(XMLChArray("NOTATION").get (), local) )
  {
    result = GENV_TYPESYSTEM.NOTATION_TYPE_ONE;
  }
  else if ( XMLString::equals(XMLChArray("language").get (), local) )
  {
    result = GENV_TYPESYSTEM.LANGUAGE_TYPE_ONE;
  }
  // YearMonthDuration and DayTimeDuration are not in schema spec
  else
  {
    // type not covered
    std::cout << "Assertion Error: Type unknown " << StrX(local).localForm() <<
      "@" << Schema::XSD_NAMESPACE; std::cout.flush();
    ZORBA_ASSERT(false);
    result = NULL;
  }

  return result;
}


void Schema::checkForAnonymousTypes(const TypeManager* typeManager)
{
  if (theGrammarPool == NULL)
    return;

  bool xsModelWasChanged;
  XSModel* model = theGrammarPool->getXSModel(xsModelWasChanged);

  XSNamedMap<XSObject> * typeDefs =
      model->getComponents(XSConstants::TYPE_DEFINITION);
  for( uint i = 0; i<typeDefs->getLength(); i++)
  {
    XSTypeDefinition* typeDef = (XSTypeDefinition*)(typeDefs->item(i));
    checkForAnonymousTypesInType(typeManager, typeDef);
  }

  XSNamedMap<XSObject> * elemDefs =
      model->getComponents(XSConstants::ELEMENT_DECLARATION);
  for( uint i = 0; i<elemDefs->getLength(); i++)
  {
    XSElementDeclaration* elemDecl = (XSElementDeclaration*)(elemDefs->item(i));
    checkForAnonymousTypesInType(typeManager, elemDecl->getTypeDefinition());
    // only if typeDef is Anonymous will be added to the cache
    addAnonymousTypeToCache(typeManager, elemDecl->getTypeDefinition());
  }

  XSNamedMap<XSObject> * attrDefs =
      model->getComponents(XSConstants::ATTRIBUTE_DECLARATION);
  for( uint i = 0; i<attrDefs->getLength(); i++)
  {
    XSAttributeDeclaration* attrDecl =
        (XSAttributeDeclaration*)(attrDefs->item(i));
    checkForAnonymousTypesInType(typeManager, attrDecl->getTypeDefinition());
    // only if typeDef is Anonymous will be added to the cache
    addAnonymousTypeToCache(typeManager, attrDecl->getTypeDefinition());
  }

  XSNamedMap<XSObject> * attrGroupDefs =
      model->getComponents(XSConstants::ATTRIBUTE_GROUP_DEFINITION);
  for( uint i = 0; i<attrGroupDefs->getLength(); i++)
  {
    XSAttributeGroupDefinition* attrGroupDef =
        (XSAttributeGroupDefinition*)(attrGroupDefs->item(i));
    XSAttributeUseList* xsAttributeUseList = attrGroupDef->getAttributeUses();
    if (xsAttributeUseList)
    {
      for (unsigned i = 0; i < xsAttributeUseList->size(); i++)
      {
        XSAttributeDeclaration* attrDecl = xsAttributeUseList->elementAt(i)->
          getAttrDeclaration();
        checkForAnonymousTypesInType(typeManager, attrDecl->getTypeDefinition());
      }
    }
  }

  XSNamedMap<XSObject> * modelGroupDefs =
      model->getComponents(XSConstants::MODEL_GROUP_DEFINITION);
  for( uint i = 0; i<modelGroupDefs->getLength(); i++)
  {
    XSModelGroupDefinition* modelGroupDef =
        (XSModelGroupDefinition*)modelGroupDefs->item(i);
    XSModelGroup *xsModelGroup = modelGroupDef->getModelGroup();
    if (xsModelGroup)
    {
      XSParticleList *xsParticleList = xsModelGroup->getParticles();
      if (xsParticleList)
      {
        for (unsigned i = 0; i < xsParticleList->size(); i++)
        {
          checkForAnonymousTypesInParticle(typeManager,
                                           xsParticleList->elementAt(i));
        }
      }
    }
  }
}

void Schema::checkForAnonymousTypesInType(const TypeManager* typeManager,
                                          XSTypeDefinition* xsTypeDef)
{
    TRACE(" type: " << StrX(xsTypeDef->getName()) << "@" <<
        StrX(xsTypeDef->getNamespace()));

    XSTypeDefinition *xsBaseTypeDef = xsTypeDef->getBaseType();
    if (xsBaseTypeDef)
    {
        addAnonymousTypeToCache(typeManager, xsBaseTypeDef);
    }

    if (xsTypeDef->getTypeCategory() == XSTypeDefinition::SIMPLE_TYPE)
    {
        // Simple
        // to do list, union ??
    }
    else
    {
        // Complex
        XSComplexTypeDefinition* xsComplexTypeDef =
            static_cast<XSComplexTypeDefinition*>(xsTypeDef);
        XSComplexTypeDefinition::CONTENT_TYPE contentType =
            xsComplexTypeDef->getContentType();

        if (contentType == XSComplexTypeDefinition::CONTENTTYPE_ELEMENT
          || contentType == XSComplexTypeDefinition::CONTENTTYPE_MIXED)
        {
            XSParticle *xsParticle = xsComplexTypeDef->getParticle();
            checkForAnonymousTypesInParticle(typeManager, xsParticle);
        }
    }
}

void Schema::checkForAnonymousTypesInParticle(const TypeManager* typeManager,
    XSParticle *xsParticle)
{
    if (!xsParticle)
        return;

    if ( xsParticle->getName() )
    {
        TRACE(" particle: " << StrX(xsParticle->getName()) << " @" <<
            StrX(xsParticle->getNamespace()));
    }
    
    XSParticle::TERM_TYPE termType = xsParticle->getTermType();
    if (termType == XSParticle::TERM_ELEMENT)
    {
        XSElementDeclaration *xsElement = xsParticle->getElementTerm();

        if ( xsElement->getScope() != XSConstants::SCOPE_GLOBAL )
        {
          // if reference to a global definition skip it,
          // otherwise infinite loop
          XSTypeDefinition* xsParticleTypeDef = xsElement->getTypeDefinition();
          addAnonymousTypeToCache(typeManager, xsParticleTypeDef);
        }
    }
    else if (termType == XSParticle::TERM_MODELGROUP)
    {
        XSModelGroup *xsModelGroup = xsParticle->getModelGroupTerm();

        XSParticleList *xsParticleList = xsModelGroup->getParticles();
        for (unsigned i = 0; i < xsParticleList->size(); i++)
        {
            checkForAnonymousTypesInParticle(typeManager,
                xsParticleList->elementAt(i));
        }
    }
}


void Schema::addAnonymousTypeToCache(
    const TypeManager* typeManager,
    XSTypeDefinition* xsTypeDef)
{
  if (!xsTypeDef->getAnonymous())
    return;

  XSTypeDefinition* baseTypeDef = xsTypeDef->getBaseType();
  if (!baseTypeDef) {
    //error allways must have a baseType
    ZORBA_ASSERT(false);
    return;
  }

  xqtref_t baseXQType =
    createXQTypeFromTypeDefinition(typeManager, baseTypeDef);

  const XMLCh* uri = xsTypeDef->getNamespace();
  zstring strUri;
  transcode(uri, strUri);
  zstring lLocal;
  transcode(xsTypeDef->getName(), lLocal);

  store::Item_t qname;
  GENV_ITEMFACTORY->createQName(qname, strUri, zstring(), lLocal);


  switch( xsTypeDef->getTypeCategory() )
  {
  case XSTypeDefinition::SIMPLE_TYPE:
    {
      xqtref_t xqType = createXQTypeFromTypeDefinition(typeManager, xsTypeDef);
      addTypeToCache(xqType);
    }
    break;

  case XSTypeDefinition::COMPLEX_TYPE:
    {
      // get content type
      XSComplexTypeDefinition* xsComplexTypeDef =
        static_cast<XSComplexTypeDefinition*> (xsTypeDef);

      XQType::content_kind_t contentType;

      switch (xsComplexTypeDef->getContentType())
      {
      case XSComplexTypeDefinition::CONTENTTYPE_MIXED :
        contentType = XQType::MIXED_CONTENT_KIND;
        break;
      case XSComplexTypeDefinition::CONTENTTYPE_ELEMENT :
        contentType = XQType::ELEMENT_ONLY_CONTENT_KIND;
        break;
      case XSComplexTypeDefinition::CONTENTTYPE_SIMPLE :
        contentType = XQType::SIMPLE_CONTENT_KIND;
        break;
      case XSComplexTypeDefinition::CONTENTTYPE_EMPTY :
        contentType = XQType::EMPTY_CONTENT_KIND;
        break;
      default:
        ZORBA_ASSERT(false);
      }

      xqtref_t xqType =
        xqtref_t(new UserDefinedXQType(typeManager,
                                       qname,
                                       baseXQType,
                                       TypeConstants::QUANT_ONE,
                                       UserDefinedXQType::COMPLEX_TYPE,
                                       contentType));

      addTypeToCache(xqType);

      // check f0r it's containing annonymous types
      checkForAnonymousTypesInType(typeManager, xsComplexTypeDef);
    }
    break;

  default:
    // no other known type category
    ZORBA_ASSERT(false);
  }
}


void Schema::addTypeToCache(xqtref_t itemXQType)
{
  ZORBA_ASSERT( itemXQType->type_kind() == XQType::USER_DEFINED_KIND );

  const UserDefinedXQType* itemUDType =
    static_cast<const UserDefinedXQType*>(itemXQType.getp());

  const store::Item* qname = itemUDType->get_qname();

  const zstring& local = qname->getLocalName();
  const zstring& ns = qname->getNamespace();

  zstring key;
  key.reserve(ns.size() + local.size() + 4);
  key += local;
  key += ":";
  key += ns;
  key += " ";
  key += TypeOps::decode_quantifier(itemXQType->get_quantifier());

  xqtref_t res;
  if( !theUdTypesCache->get(key, res) )
  {
    TRACE("key: '" << key << "'");
    theUdTypesCache->insert(key, itemXQType);
  }
}

#endif //ZORBA_NO_XMLSCHEMA


/*******************************************************************************
  Parse a given string to create (if possible) an XDM value of a given type.
  The given type is assumed to be a simple type, i.e. Atomic, List or Union.
********************************************************************************/
bool Schema::parseUserSimpleTypes(
    zstring& textValue,
    const xqtref_t& aTargetType,
    std::vector<store::Item_t>& resultList,
    const QueryLoc& loc)
{
  //cout << "parseUserSimpleTypes: '" << textValue << "' to " <<
  //  aTargetType->toString() << endl; cout.flush();

  if ( aTargetType->type_kind() != XQType::USER_DEFINED_KIND )
  {
    // must be a built in type
    store::Item_t atomicResult;
    //todo add nsCtx
    bool res = GenericCast::instance()->castToAtomic(atomicResult,
                                                     textValue,
                                                     aTargetType,
                                                     theTypeManager,
                                                     NULL,
                                                     loc);

    if ( res == false )
    {
      return false;
    }
    else
    {
      // use resultList.resize() and resultList[x].transfer(atomicResult)
      //resultList.push_back(atomicResult);
      std::size_t s = resultList.size();
      resultList.resize(s+1);
      resultList[s].transfer(atomicResult);
      
      return true;
    }
  }

  const UserDefinedXQType* udXQType =
    static_cast<const UserDefinedXQType*>(aTargetType.getp());

  ZORBA_ASSERT(udXQType->isAtomic() || udXQType->isList() || udXQType->isUnion());

  bool hasResult = false;

  switch ( udXQType->getTypeCategory() )
  {
  case UserDefinedXQType::ATOMIC_TYPE:
  {
    store::Item_t atomicResult;
    hasResult = parseUserAtomicTypes(textValue, aTargetType, atomicResult, NULL, loc);

    if ( !hasResult )
      return false;
    else
    {
      //resultList.push_back(atomicResult);
      std::size_t s = resultList.size();
      resultList.resize(s+1);
      resultList[s].transfer(atomicResult);
      return true;
    }
  }
  break;

  case UserDefinedXQType::LIST_TYPE:
    return parseUserListTypes(textValue, aTargetType, resultList, loc);
    break;

  case UserDefinedXQType::UNION_TYPE:
    return parseUserUnionTypes(textValue, aTargetType, resultList, loc);
    break;

  case UserDefinedXQType::COMPLEX_TYPE:
  default:
    ZORBA_ASSERT( false);
    break;
  }

  return false;
}


/*******************************************************************************
  Parse a given string to create (if possible) an XDM value of a given type.
  The given type is assumed to be a user-defined atomic type.
********************************************************************************/
bool Schema::parseUserAtomicTypes(
    zstring& textValue,
    const xqtref_t& aTargetType,
    store::Item_t& result,
    namespace_context* aNCtx,
    const QueryLoc& loc)
{
  TRACE("parsing '" << textValue << "' to " << aTargetType->toString());

  ZORBA_ASSERT( aTargetType->type_kind() == XQType::USER_DEFINED_KIND );

  const UserDefinedXQType* udXQType =
    static_cast<const UserDefinedXQType*>(aTargetType.getp());
  ZORBA_ASSERT( udXQType->isAtomic() );

  const store::Item* typeQName = udXQType->get_qname();

#ifndef ZORBA_NO_XMLSCHEMA
  XMLChArray localPart (typeQName->getLocalName());
  XMLChArray uriStr (typeQName->getNamespace());

  bool wasError = false;

  try
  {
    // Create grammar resolver and string pool that we pass to the scanner
    std::auto_ptr<GrammarResolver> fGrammarResolver(
        new GrammarResolver(theGrammarPool));

    fGrammarResolver->useCachedGrammarInParse(true);

    // retrieve Grammar for the uri
    SchemaGrammar* sGrammar = (SchemaGrammar*) fGrammarResolver->getGrammar(uriStr);

    if (sGrammar)
    {
      DatatypeValidator* xsiTypeDV = fGrammarResolver->
          getDatatypeValidator(uriStr, localPart);

      if (!xsiTypeDV)
      {
        // when complex simple content type use the base type
        // find the first basetype that has a DataTypeValidator
        const UserDefinedXQType* tmpXQType = udXQType;

        while (xsiTypeDV == NULL && tmpXQType != NULL)
        {
          xqtref_t baseXQType = tmpXQType->getBaseType();
          if (baseXQType.getp())
          {
            store::Item_t baseTypeQName = baseXQType->get_qname();
            XMLChArray baseLocalPart(baseTypeQName->getLocalName());
            XMLChArray baseUriStr(baseTypeQName->getNamespace());

            xsiTypeDV = fGrammarResolver->
              getDatatypeValidator(baseUriStr, baseLocalPart);

            tmpXQType = NULL;
            if (baseXQType->type_kind() == XQType::USER_DEFINED_KIND)
            {
              tmpXQType =
                static_cast<const UserDefinedXQType*>(baseXQType.getp());
            }
          }
        }
      }

      if (!xsiTypeDV)
      {
        throw XQUERY_EXCEPTION(
          err::FORG0001, ERROR_PARAMS( aTargetType, ZED( NoTypeInCtx ) )
        );
      }

      // workaround for validating xs:NOTATION with Xerces
      if (theTypeManager != NULL
          &&
          udXQType->isSubTypeOf(theTypeManager, *GENV_TYPESYSTEM.NOTATION_TYPE_ONE))
      {
        // textValue must be in the form of URI:LOCAL
        size_t colonIndex = textValue.find_first_of(":");
        zstring prefix = textValue.substr(0, colonIndex).str();
        zstring local = textValue.substr(colonIndex+1, textValue.size()).str();
        zstring uri;

        if (aNCtx != NULL && aNCtx->findBinding(prefix, uri))
        {
          XMLChArray xchTextValue(uri.append(":").append(local).str());         
          xsiTypeDV->validate(xchTextValue.get());
        }
        else
          ZORBA_ERROR_DESC_OSS(err::FORG0001, "Prefix '" << prefix <<
              "' not found in current namespace context.");
      }
      else
      {
        XMLChArray xchTextValue(textValue.str());
        xsiTypeDV->validate(xchTextValue.get());
      }
    }
    else
    {
      ZORBA_ERROR_DESC_OSS(err::FORG0001,
                           "Uri '" << typeQName->getNamespace()
                           << "' not found in current schema context.");
      wasError = true;
    }

    if (wasError)
      return false;
  }
  catch (XMLException& idve)
  {
    zstring msg;
    transcode(idve.getMessage(), msg);

    throw XQUERY_EXCEPTION(
      err::FORG0001,
      ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), aTargetType, msg )
    );
  }
  catch(const OutOfMemoryException&)
  {
    throw;
  }
  catch (const ZorbaException&) 
  {
    throw;
  }
  catch (...)
  {
    throw;
  }
#endif //ZORBA_NO_XMLSCHEMA

  // find the non user defined base type
  const XQType* baseType = udXQType->getBaseType().getp();

  while (baseType->type_kind() == XQType::USER_DEFINED_KIND)
  {
    const UserDefinedXQType* udt =
        static_cast<const UserDefinedXQType*>(baseType);

    baseType = udt->getBaseType().getp();
  }

  // create a UserTypedAtomicItem with the built-in value
  store::Item_t baseItem;
  
  if (GenericCast::castToAtomic(baseItem,
                                textValue,
                                baseType,
                                theTypeManager,
                                aNCtx,
                                loc))
  {
    store::Item_t tTypeQName = udXQType->get_qname();

    //TRACE("factory '" << baseItem->getStringValue() << "' type " << tTypeQName->getStringValue() << "  base:" << baseType->toString());
    return GENV_ITEMFACTORY->
        createUserTypedAtomicItem(result, baseItem, tTypeQName);
  }
  else
    return false;
}


void splitToAtomicTextValues(
    const zstring& textValue,
    std::vector<zstring>& atomicTextValues)
{
  zstring normalizedTextValue;
  utf8::normalize_whitespace(textValue, &normalizedTextValue);

  size_t start = 0;
  size_t i = 0;

  while ( std::string::npos != (i=normalizedTextValue.find_first_of(" \n\r\t", start)) ) 
  {
    atomicTextValues.push_back(normalizedTextValue.substr(start, i - start));
    start = i+1;
  }

  size_t size = normalizedTextValue.size();

  if ( start < size )
  {
    atomicTextValues.push_back(normalizedTextValue.substr(start, size));
  }
}



// user list types
bool Schema::parseUserListTypes(
    const zstring& textValue,
    const xqtref_t& aTargetType,
    std::vector<store::Item_t>& resultList,
    const QueryLoc& loc)
{
  ZORBA_ASSERT( aTargetType->type_kind() == XQType::USER_DEFINED_KIND );

//  cout << "parseUserListTypes: '" << textValue << "' to " <<
//    aTargetType->toString() << endl; cout.flush();

  const UserDefinedXQType* udXQType =
    static_cast<const UserDefinedXQType*>(aTargetType.getp());
  ZORBA_ASSERT( udXQType->isList() );

  bool hasResult = true;
  const XQType* listItemType = udXQType->getListItemType();
  ZORBA_ASSERT( listItemType );

  //split text into atoms
  std::vector<zstring> atomicTextValues;
  splitToAtomicTextValues(textValue, atomicTextValues);

  for ( unsigned int i = 0; i < atomicTextValues.size() ; i++)
  {
    TRACE("trying parsing '" << textValue << "' to " <<
        listItemType->toString());

    bool res = parseUserSimpleTypes(atomicTextValues[i],
                                    xqtref_t(listItemType),
                                    resultList,
                                    loc);
    hasResult = hasResult && res;
  }

  return hasResult;
}

// user union types
bool Schema::parseUserUnionTypes(
    zstring& textValue,
    const xqtref_t& aTargetType,
    std::vector<store::Item_t>& resultList,
    const QueryLoc& loc)
{
//  cout << "parseUserUnionTypes: '" << textValue << "'" <<  " to " <<
//    aTargetType->toString() << endl; cout.flush();

  ZORBA_ASSERT( aTargetType->type_kind() == XQType::USER_DEFINED_KIND );

  const UserDefinedXQType* udXQType =
  static_cast<const UserDefinedXQType*>(aTargetType.getp());
  ZORBA_ASSERT( udXQType->isUnion() );

  std::vector<xqtref_t> unionItemTypes = udXQType->getUnionItemTypes();

  for ( unsigned int i = 0; i < unionItemTypes.size(); i++)
  {
    try
    {
      if (isCastableUserSimpleTypes(textValue, unionItemTypes[i]))
      {
        return parseUserSimpleTypes(textValue, unionItemTypes[i], resultList, loc);
      }
    }
    catch(ZorbaException const&)
    {
    }
  }

  throw XQUERY_EXCEPTION(
    err::FORG0001,
    ERROR_PARAMS( textValue, ZED( NoCastTo_34o ), udXQType->toSchemaString() )
  );
}


// user defined simple types, i.e. Atomic, List or Union Types
bool Schema::isCastableUserSimpleTypes(
    const zstring& textValue,
    const xqtref_t& aTargetType)
{
  //cout << "isCastableUserSimpleTypes: '" << textValue << "' to " <<
  //  aTargetType->toString() << endl; cout.flush();

  if ( aTargetType->type_kind() != XQType::USER_DEFINED_KIND )
  {
    // must be a built in type
    store::Item_t atomicResult;
    
    return GenericCast::instance()->isCastable(textValue, aTargetType, theTypeManager);
    //todo add nsCtx
  }

  ZORBA_ASSERT( aTargetType->type_kind() == XQType::USER_DEFINED_KIND );

  const UserDefinedXQType* udXQType =
    static_cast<const UserDefinedXQType*>(aTargetType.getp());

  ZORBA_ASSERT( udXQType->isAtomic() || udXQType->isList() ||
                udXQType->isUnion() );


  switch ( udXQType->getTypeCategory() )
  {
  case UserDefinedXQType::ATOMIC_TYPE:
    return isCastableUserAtomicTypes( textValue, aTargetType );
    break;

  case UserDefinedXQType::LIST_TYPE:
    return isCastableUserListTypes( textValue, aTargetType );
    break;

  case UserDefinedXQType::UNION_TYPE:
    return isCastableUserUnionTypes( textValue, aTargetType );
    break;

  case UserDefinedXQType::COMPLEX_TYPE:
  default:
    ZORBA_ASSERT( false);
    break;
  }

  return false;;
}


// user defined atomic types
bool Schema::isCastableUserAtomicTypes(
    const zstring& textValue,
    const xqtref_t& aTargetType)
{
  //cout << "isCastableUserAtomicTypes: '" << textValue << "' to " <<
  //  aTargetType->toString() << endl; cout.flush();
  return GenericCast::instance()->isCastable(textValue, aTargetType.getp(), theTypeManager);
}


// user defined list types
bool Schema::isCastableUserListTypes(
    const zstring& textValue,
    const xqtref_t& aTargetType)
{
  //cout << "isCastableUserListTypes: '" << textValue << "' to " <<
  //  aTargetType->toString() << endl; cout.flush();
  ZORBA_ASSERT( aTargetType->type_kind() == XQType::USER_DEFINED_KIND );

  const UserDefinedXQType* udXQType =
    static_cast<const UserDefinedXQType*>(aTargetType.getp());
  ZORBA_ASSERT( udXQType->isList() );

  bool hasResult = true;
  const XQType* listItemType = udXQType->getListItemType();

  //split text into atoms
  std::vector<zstring> atomicTextValues;
  splitToAtomicTextValues(textValue, atomicTextValues);

  for ( unsigned int i = 0; i<atomicTextValues.size() ; i++ )
  {
    bool res = isCastableUserSimpleTypes(atomicTextValues[i],
                                         xqtref_t(listItemType));
    hasResult = hasResult && res;
  }

  return hasResult;
}


// user defined union types
bool Schema::isCastableUserUnionTypes(
    const zstring& textValue,
    const xqtref_t& aTargetType)
{
    //cout << "isCastableUserUnionTypes: '" << textValue << "' to " <<
    //  aTargetType->toString() << endl; cout.flush();

    ZORBA_ASSERT( aTargetType->type_kind() == XQType::USER_DEFINED_KIND );

    const UserDefinedXQType* udXQType =
      static_cast<const UserDefinedXQType*>(aTargetType.getp());
    ZORBA_ASSERT( udXQType->isUnion() );


    std::vector<xqtref_t> unionItemTypes = udXQType->getUnionItemTypes();

    for ( unsigned int i = 0; i<unionItemTypes.size(); i++)
    {
      if ( isCastableUserSimpleTypes(textValue, unionItemTypes[i]))
        return true;
    }

    return false;
}

void Schema::serialize(::zorba::serialization::Archiver& ar)
{
  SERIALIZE_TYPEMANAGER(TypeManager, theTypeManager);

#ifndef ZORBA_NO_XMLSCHEMA
   ar & theUdTypesCache;

   bool is_grammar_NULL = (theGrammarPool == NULL);

   ar.set_is_temp_field(true);

   ar & is_grammar_NULL;

   csize size_of_size_t = sizeof(size_t);

   union
   {
     unsigned long lvalue;
     unsigned char cvalue[4];
   } le_be_value;

   le_be_value.lvalue = 0x11223344;

   if (ar.is_serializing_out())
   {
     ar & size_of_size_t;
     ar & le_be_value.cvalue[0];

     if (!is_grammar_NULL)
     {
       BinMemOutputStream binmemoutputstream;
       zstring binstr;

       try
       {
         theGrammarPool->serializeGrammars(&binmemoutputstream);
         binstr.assign((char*)binmemoutputstream.getRawBuffer(),
                       binmemoutputstream.getSize());
       }
       catch (...)
       {
       }

       ar & binstr;
     }
   }
   else
   {
     csize size_of_size_t2;
     unsigned char le_be_value_first_char;

     ar & size_of_size_t2;
     ar & le_be_value_first_char;

     if (size_of_size_t2 != size_of_size_t ||
         le_be_value_first_char != le_be_value.cvalue[0])
     {
       throw ZORBA_EXCEPTION(zerr::ZCSE0015_INCOMPATIBLE_BETWEEN_32_AND_64_BITS_OR_LE_AND_BE);
     }

     if (!is_grammar_NULL)
     {
       zstring binstr;

       ar & binstr;

       if (!binstr.empty())
       {
         BinMemInputStream binmeminputstream((XMLByte*)binstr.c_str(), binstr.size());
         theGrammarPool->deserializeGrammars(&binmeminputstream);
       }
     }
     else
     {
       theGrammarPool = NULL;
     }
   }

   ar.set_is_temp_field(false);
#endif
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
