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
#include "common/common.h"

#include "zorba/api_shared_types.h"

#include "schema.h"
#include "StrX.h"
#include "LoadSchemaErrorHandler.h"
#include "PrintSchema.h"
#include "XercesParseUtils.h"

#include "types/typeimpl.h"
#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "types/casting.h"
#include "types/delegating_typemanager.h"

#include "zorbaerrors/Assert.h"

#include "system/globalenv.h"

#include "store/api/item_factory.h"

#include <zorbatypes/xerces_xmlcharray.h>

#include "zorbamisc/ns_consts.h"

using namespace std;
namespace zorba
{
const char* Schema::XSD_NAMESPACE = XML_SCHEMA_NS;

bool Schema::_isInitialized = false;

#ifndef ZORBA_NO_XMLSCHEMA
xqp_string transcode(const XMLCh *const str)
{
    char* trStr = XMLString::transcode(str);
    xqp_string res (trStr);
    XMLString::release(&trStr);
    return res;
}
#endif //ZORBA_NO_XMLSCHEMA


void Schema::initialize()
{
#ifndef ZORBA_NO_XMLSCHEMA
    if (_isInitialized)
        return;
    
    try
    {
        XERCES_CPP_NAMESPACE::XMLPlatformUtils::Initialize();
        _isInitialized = true;
    }
    catch (const XERCES_CPP_NAMESPACE::XMLException& toCatch)
    {
        std::cerr   << "Error during Xerces-C initialization! Message:\n"
               << StrX(toCatch.getMessage()) << std::endl;
        return;         
    }
#endif //ZORBA_NO_XMLSCHEMA
}

void Schema::terminate()
{
#ifndef ZORBA_NO_XMLSCHEMA
    if (_isInitialized)
    {
        XERCES_CPP_NAMESPACE::XMLPlatformUtils::Terminate();    
        _isInitialized = false;
    }
#endif //ZORBA_NO_XMLSCHEMA
}


Schema::Schema()
{
#ifndef ZORBA_NO_XMLSCHEMA
    _grammarPool = new XMLGrammarPoolImpl(XMLPlatformUtils::fgMemoryManager);
    _udTypesCache = new hashmap<xqtref_t>;
#endif //ZORBA_NO_XMLSCHEMA
}

Schema::~Schema()
{
#ifndef ZORBA_NO_XMLSCHEMA
    delete _grammarPool;
    delete _udTypesCache;
#endif //ZORBA_NO_XMLSCHEMA
}

void Schema::registerXSD(const char* xsdURL, const QueryLoc& loc)
{
#ifndef ZORBA_NO_XMLSCHEMA
    std::auto_ptr<SAX2XMLReader> parser;
    
    try
    {    
        parser.reset (XMLReaderFactory::createXMLReader(XMLPlatformUtils::fgMemoryManager, _grammarPool));
        parser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
        parser->setFeature(XMLUni::fgXercesSchema, true);
        parser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);
        parser->setFeature(XMLUni::fgSAX2CoreNameSpacePrefixes, false);
        parser->setFeature(XMLUni::fgSAX2CoreValidation, true);
        parser->setFeature(XMLUni::fgXercesDynamic, true);
        parser->setProperty(XMLUni::fgXercesScannerName, (void *)XMLUni::fgSGXMLScanner);

        LoadSchemaErrorHandler handler(loc);    
        parser->setErrorHandler(&handler);

        //cout << "== Parsing == " << xsdURL << endl;
        XMLChArray xerces_xsdURL (xsdURL);
        XMLURL url (xerces_xsdURL.get ());
        URLInputSource input_src (url);
        parser->loadGrammar(input_src, Grammar::SchemaGrammarType, true);
        
        if (handler.getSawErrors())
        {
            handler.resetErrors();
        }        
    }
    catch (const OutOfMemoryException&)
    {
        std::cerr << "OutOfMemoryException during parsing: '" << xsdURL << "'\n" << std::endl;
        ZORBA_ERROR_LOC_DESC (XQST0059, loc, string("OutOfMemoryException during parsing ") + string(xsdURL));
    }
    catch (const XMLException& e)
    {
        std::cerr << "\nError during parsing: '" << xsdURL << "'\n"
        << "Exception message is:  \n"
        << StrX(e.getMessage()) << std::endl;
        ZORBA_ERROR_LOC_DESC( XQST0059, loc, StrX(e.getMessage()));
    }
    catch (...)
    {
        std::cerr << "\nUnexpected exception during parsing: '" << xsdURL << "'\n" << std::endl;
        ZORBA_ERROR_LOC_DESC (XQST0059, loc, string("Unexpected exception during parsing: ") + string(xsdURL));
    }

#if 0                   // enable this to debug registered user defined schema types
      printXSDInfo();
#endif
#endif //ZORBA_NO_XMLSCHEMA
}

void Schema::printXSDInfo(bool excludeBuiltIn)
{
#ifndef ZORBA_NO_XMLSCHEMA
    PrintSchema::printInfo(excludeBuiltIn, _grammarPool);
#endif //ZORBA_NO_XMLSCHEMA
}

xqtref_t Schema::createIfExists( const TypeManager *typeManager, const store::Item* qname,
    TypeConstants::quantifier_t quantifier)
{
#ifndef ZORBA_NO_XMLSCHEMA
    const char* uri_cstr = qname->getNamespace()->c_str();
    if ( XMLString::equals(XSD_NAMESPACE, uri_cstr) )
        return NULL;

    //std::cout << "--createIfExists: " << qname->getNamespace() << "@" << qname->getLocalName() << "\n";

    if (_grammarPool==NULL)
        // there is no schema import i.e. no user defined types 
        return NULL;

    // check the cache first
    std::string key = qname->getLocalName()->str() + ":" + uri_cstr + " " + 
        TypeOps::decode_quantifier (quantifier);
    xqtref_t res;
    if( _udTypesCache->get(key, res) )
        return res;

    // not found in cache, make a new one
    XMLChArray local (qname->getLocalName()->c_str());
    XMLChArray uri (uri_cstr);

    XSModel* xsModel = _grammarPool->getXSModel();
    XSTypeDefinition* xsTypeDef = xsModel->getTypeDefinition(local, uri);

    if ( xsTypeDef==NULL )
        res = NULL;
    else
        res = getXQTypeForXSTypeDefinition(typeManager, xsTypeDef);

    // stick it in the cache even if it's NULL
    _udTypesCache->put(key, res);

    return res;
#else  //ZORBA_NO_XMLSCHEMA
    return NULL;
#endif //ZORBA_NO_XMLSCHEMA
}


#ifndef ZORBA_NO_XMLSCHEMA
xqtref_t Schema::getXQTypeForXSTypeDefinition(const TypeManager *typeManager, XSTypeDefinition* xsTypeDef)
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
        xqp_string strUri = transcode(uri);

        if ( XMLString::equals(strUri.c_str (), Schema::XSD_NAMESPACE) )
        {
            const XMLCh* local = xsTypeDef->getName();
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
                result = GENV_TYPESYSTEM.GMONTH_DAY_TYPE_ONE;
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
            else if ( XMLString::equals(SchemaSymbols::fgELT_NOTATION, local) )
            {
                result = GENV_TYPESYSTEM.ID_TYPE_ONE;
            }
            else if ( XMLString::equals(SchemaSymbols::fgATT_ID, local) )
            {
                result = GENV_TYPESYSTEM.ID_TYPE_ONE;
            }
            // SchemaSymbols::fgDT_NMTOKEN doesn't exist in Xerces
            else if ( XMLString::equals(XMLChArray("NMTOKEN").get (), local) )
            {
                result = GENV_TYPESYSTEM.NMTOKEN_TYPE_ONE;
            }
            else if ( XMLString::equals(XMLChArray("IDREF").get (), local) )
            {
                result = GENV_TYPESYSTEM.IDREF_TYPE_ONE;
            }
            else if ( XMLString::equals(XMLChArray("ENTITY").get (), local) )
            {
                result = GENV_TYPESYSTEM.ID_TYPE_ONE;
            }
            // YearMonthDuration and DayTimeDuration are not in schema spec
            else
            {
                // type not covered             
                ZORBA_ASSERT(false);
                result = NULL;
            }
        }
        else
        {
            // must be a user defined simple type
            XSSimpleTypeDefinition * xsSimpleTypeDef = (XSSimpleTypeDefinition *)xsTypeDef;

            xqp_string lNamespace (strUri);
            xqp_string lPrefix;
            xqp_string lLocal = transcode(xsTypeDef->getName());

            store::Item_t qname;
            GENV_ITEMFACTORY->createQName(qname, lNamespace.getStore(), lPrefix.getStore(), lLocal.getStore());


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

                    xqtref_t baseXQType = getXQTypeForXSTypeDefinition(typeManager, baseTypeDef);

                    xqtref_t xqType = xqtref_t(new UserDefinedXQType(typeManager, qname, baseXQType, TypeConstants::QUANT_ONE, XQType::SIMPLE_CONTENT_KIND));

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
                    xqtref_t itemXQType = getXQTypeForXSTypeDefinition(typeManager, itemTypeDef);

                    xqtref_t xqType = xqtref_t(
                        new UserDefinedXQType(typeManager, qname, NULL /*GENV_TYPESYSTEM.ANY_SIMPLE_TYPE*/,
                                TypeConstants::QUANT_ONE, itemXQType.getp()));

                    result = xqType;
                }
                break;

            case XSSimpleTypeDefinition::VARIETY_UNION:
                {
                    XSSimpleTypeDefinitionList * memberTypesDefList = xsSimpleTypeDef->getMemberTypes();
                    if ( !memberTypesDefList )
                    {
                        //error since VARIETY is UNION must have a memberTypesDefList
                        ZORBA_ASSERT(false);             
                        result = NULL;
                    }

                    std::vector<const XQType*> unionItemTypes;

                    for ( unsigned int i=0; i<memberTypesDefList->size(); i++)
                    {
                        XSSimpleTypeDefinition * itemTypeDef = memberTypesDefList->elementAt(i);
                        xqtref_t itemXQType = getXQTypeForXSTypeDefinition(typeManager, itemTypeDef);
                        unionItemTypes.push_back(itemXQType.getp());
                    }

                    xqtref_t xqType = xqtref_t(
                        new UserDefinedXQType(typeManager, qname, NULL /*GENV_TYPESYSTEM.ANY_SIMPLE_TYPE*/,
                                TypeConstants::QUANT_ONE, unionItemTypes));

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
        } // end user defined simple types
    }     // end simple types
    else
    {  
        // is not a simple type 
        // first check if it is a built-in type
        const XMLCh* uri = xsTypeDef->getNamespace();
        xqp_string strUri = transcode(uri);

        if ( XMLString::equals(strUri.c_str (), Schema::XSD_NAMESPACE) )
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
                //error allway must have a baseType
                ZORBA_ASSERT(false);             
                result = NULL;
            }

            xqtref_t baseXQType = getXQTypeForXSTypeDefinition(typeManager, baseTypeDef);

            xqp_string lNamespace (strUri);
            xqp_string lPrefix;
            xqp_string lLocal = transcode(xsTypeDef->getName());

            store::Item_t qname;
            GENV_ITEMFACTORY->createQName(qname, lNamespace.getStore(), lPrefix.getStore(), lLocal.getStore());

            // get content type
            XSComplexTypeDefinition *xsComplexTypeDef = static_cast<XSComplexTypeDefinition*>(xsTypeDef);
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

            xqtref_t xqType = xqtref_t(new UserDefinedXQType(typeManager, qname, baseXQType, TypeConstants::QUANT_ONE, contentType));

            result = xqType;
        }
    } 

    return result;
}


XERCES_CPP_NAMESPACE::XMLGrammarPool* Schema::getGrammarPool()
{
    return _grammarPool;
}
#endif //ZORBA_NO_XMLSCHEMA


// user simple types, i.e. Atomic, List or Union Types
bool Schema::parseUserSimpleTypes(const xqp_string textValue, const xqtref_t& aTargetType, 
    std::vector<store::Item_t> &resultList)
{
    //std::cout << "parseUserSimplTypes: " << textValue;

    if ( aTargetType->type_kind() != XQType::USER_DEFINED_KIND )
    {
        // must be a built in type
        store::Item_t atomicResult;
        xqpStringStore_t textval = textValue.getStore();
        bool res = GenericCast::instance()->castToAtomic(atomicResult, textval, aTargetType); //todo add nsCtx
        
        if ( res==false )
            return false;
        else
        {
            resultList.push_back(atomicResult);
            return true;
        }
    }

    ZORBA_ASSERT( aTargetType->type_kind() == XQType::USER_DEFINED_KIND );

    const UserDefinedXQType* udXQType = static_cast<const UserDefinedXQType*>(aTargetType.getp());

    ZORBA_ASSERT( udXQType->isAtomic() || udXQType->isList() || udXQType->isUnion() );


    bool hasResult = false;

    switch ( udXQType->getTypeCategory() )
    {
    case UserDefinedXQType::ATOMIC_TYPE:
        {
            store::Item_t atomicResult;
            hasResult = parseUserAtomicTypes( textValue, aTargetType, atomicResult);
            
            if ( !hasResult )
                return false;
            else
            {
                resultList.push_back(atomicResult);
                return true;
            }
        }
        break;

    case UserDefinedXQType::LIST_TYPE:
  
        return parseUserListTypes( textValue, aTargetType, resultList);
        break;

    case UserDefinedXQType::UNION_TYPE:
  
        return parseUserUnionTypes( textValue, aTargetType, resultList);
        break;

    case UserDefinedXQType::COMPLEX_TYPE:
    default:
        ZORBA_ASSERT( false);
        break;
    }

    return false;
}


// user atomic types
bool Schema::parseUserAtomicTypes(const xqp_string textValue, const xqtref_t& aTargetType, 
    store::Item_t &result)
{
    //std::cout << "parseUserAtomicTypes: " << textValue;

    ZORBA_ASSERT( aTargetType->type_kind() == XQType::USER_DEFINED_KIND );

    const UserDefinedXQType* udXQType = static_cast<const UserDefinedXQType*>(aTargetType.getp());
    ZORBA_ASSERT( udXQType->isAtomic() );

    store::Item_t typeQName = udXQType->getQName();
#ifndef ZORBA_NO_XMLSCHEMA
    XMLChArray localPart (typeQName->getLocalName());
    XMLChArray uriStr (typeQName->getNamespace());
    
    bool wasError = false;

    try 
    {
        // Create grammar resolver and string pool that we pass to the scanner
        std::auto_ptr<GrammarResolver> fGrammarResolver (new GrammarResolver(_grammarPool));
        fGrammarResolver->useCachedGrammarInParse(true);

        // retrieve Grammar for the uri
        SchemaGrammar* sGrammar = (SchemaGrammar*) fGrammarResolver->getGrammar(uriStr);
        if (sGrammar) 
        {
            DatatypeValidator* xsiTypeDV = fGrammarResolver->getDatatypeValidator(uriStr, localPart);

            if (!xsiTypeDV) 
            {
                ZORBA_ERROR_DESC_OSS( FORG0001, 
                    "Type '" << TypeOps::toString (*aTargetType) << "' not found in current context.");
                wasError = true;
            }

            XMLChArray xchTextValue (textValue.getStore ());
            xsiTypeDV->validate(xchTextValue.get ());
        }
        else
        {
          ZORBA_ERROR_DESC_OSS( FORG0001, 
              "Uri '" << typeQName->getNamespace()->str() << "' not found in current schema context.");
          wasError = true;

        }

        if (wasError)
          return false;
    }
    catch (XMLException& idve)
    {
        ZORBA_ERROR_DESC_OSS( FORG0001, 
            "String '" + textValue.trim(" \n\r\t",4) + "' cannot be cast to '" << 
            TypeOps::toString( *aTargetType ) << "' : " << transcode(idve.getMessage()));
        return false;
    }
    catch(const OutOfMemoryException&) 
    {
        throw;
    }
    catch (...)
    {
        throw;
    }
#endif //ZORBA_NO_XMLSCHEMA

    const XQType* baseType_ptr = udXQType->getBaseType().getp();

    while ( baseType_ptr->type_kind() == XQType::USER_DEFINED_KIND )
    {        
        const UserDefinedXQType* udBaseType_ptr = static_cast<const UserDefinedXQType*>(baseType_ptr);
        baseType_ptr = udBaseType_ptr->getBaseType().getp();
    }

    ZORBA_ASSERT( baseType_ptr->type_kind() == XQType::ATOMIC_TYPE_KIND );

    xqpStringStore_t textval = textValue.getStore();
    return GenericCast::instance()->castToAtomic(result, textval, baseType_ptr);
}


void splitToAtomicTextValues(const xqp_string &textValue, std::vector<xqp_string> &atomicTextValues)
{   
    xqp_string normalizedTextValue = textValue.normalizeSpace();
    checked_vector<uint32_t> codes = normalizedTextValue.getCodepoints();

    xqpString::size_type start = 0;
    xqpString::size_type i = 0;

    while (  i<codes.size() )
    {
        if ( xqpStringStore::is_whitespace(codes[i]) )
        {
            atomicTextValues.push_back( normalizedTextValue.substr(start, i-start));
            start = i;
        }
        i++;
    }

    if ( start < (i-1) )
        atomicTextValues.push_back( normalizedTextValue.substr(start, i-start));    
}



// user list types
bool Schema::parseUserListTypes(const xqp_string textValue, 
    const xqtref_t& aTargetType, std::vector<store::Item_t> &resultList)
{
    //std::cout << "parseUserListTypes: " << textValue;

    ZORBA_ASSERT( aTargetType->type_kind() == XQType::USER_DEFINED_KIND );

    const UserDefinedXQType* udXQType = static_cast<const UserDefinedXQType*>(aTargetType.getp());
    ZORBA_ASSERT( udXQType->isList() );

    bool hasResult = true;
    const XQType* listItemType = udXQType->getListItemType();
    
    //split text into atoms
    std::vector<xqp_string> atomicTextValues;
    splitToAtomicTextValues(textValue, atomicTextValues);
    
    for ( unsigned int i = 0; i<atomicTextValues.size() ; i++ )
    {
        bool res = parseUserSimpleTypes(atomicTextValues[i], xqtref_t(listItemType), resultList);
        hasResult = hasResult && res;
    }

    return hasResult;
}

// user union types
bool Schema::parseUserUnionTypes(const xqp_string textValue, const xqtref_t& aTargetType, 
    std::vector<store::Item_t> &resultList)
{
    //std::cout << "parseUserUnionTypes: " << textValue;

    ZORBA_ASSERT( aTargetType->type_kind() == XQType::USER_DEFINED_KIND );

    const UserDefinedXQType* udXQType = static_cast<const UserDefinedXQType*>(aTargetType.getp());
    ZORBA_ASSERT( udXQType->isUnion() );


    std::vector<const XQType*> unionItemTypes = udXQType->getUnionItemTypes();

    for ( unsigned int i = 0; i<unionItemTypes.size(); i++)
    {        
        if ( isCastableUserSimpleTypes(textValue, xqtref_t(unionItemTypes[i]) ) )
        {                
            return parseUserListTypes(textValue, xqtref_t(unionItemTypes[i]), resultList );
        }
    }

    return false;
}


// user defined simple types, i.e. Atomic, List or Union Types
bool Schema::isCastableUserSimpleTypes(const xqp_string textValue, const xqtref_t& aTargetType)
{
    //std::cout << "isCastableUserSimpleTypes: " << textValue;

    if ( aTargetType->type_kind() != XQType::USER_DEFINED_KIND )
    {
        // must be a built in type
        store::Item_t atomicResult;
        xqpStringStore_t textval = textValue.getStore();
        return GenericCast::instance()->isCastable(textval, aTargetType); //todo add nsCtx
    }

    ZORBA_ASSERT( aTargetType->type_kind() == XQType::USER_DEFINED_KIND );

    const UserDefinedXQType* udXQType = static_cast<const UserDefinedXQType*>(aTargetType.getp());

    ZORBA_ASSERT( udXQType->isAtomic() || udXQType->isList() || udXQType->isUnion() );


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
bool Schema::isCastableUserAtomicTypes(const xqp_string textValue, const xqtref_t& aTargetType)
{
    xqpStringStore_t text = xqpStringStore_t(textValue.getStore());
    return GenericCast::instance()->isCastable( text, aTargetType.getp());
}        

// user defined list types
bool Schema::isCastableUserListTypes(const xqp_string textValue, const xqtref_t& aTargetType)
{
    //std::cout << "isCastableUserListTypes: " << textValue;
    ZORBA_ASSERT( aTargetType->type_kind() == XQType::USER_DEFINED_KIND );

    const UserDefinedXQType* udXQType = static_cast<const UserDefinedXQType*>(aTargetType.getp());
    ZORBA_ASSERT( udXQType->isList() );

    bool hasResult = true;
    const XQType* listItemType = udXQType->getListItemType();
    
    //split text into atoms
    std::vector<xqp_string> atomicTextValues;
    splitToAtomicTextValues(textValue, atomicTextValues);
    
    for ( unsigned int i = 0; i<atomicTextValues.size() ; i++ )
    {
        bool res = isCastableUserSimpleTypes(atomicTextValues[i], xqtref_t(listItemType));
        hasResult = hasResult && res;
    }

    return hasResult;
}        

// user defined union types
bool Schema::isCastableUserUnionTypes(const xqp_string textValue, const xqtref_t& aTargetType)
{
    //std::cout << "isCastableUserUnionTypes: " << textValue;

    ZORBA_ASSERT( aTargetType->type_kind() == XQType::USER_DEFINED_KIND );

    const UserDefinedXQType* udXQType = static_cast<const UserDefinedXQType*>(aTargetType.getp());
    ZORBA_ASSERT( udXQType->isUnion() );


    std::vector<const XQType*> unionItemTypes = udXQType->getUnionItemTypes();

    for ( unsigned int i = 0; i<unionItemTypes.size(); i++)
    {        
        if ( isCastableUserSimpleTypes(textValue, xqtref_t(unionItemTypes[i]) ) )
            return true;
    }

    return false;
}        


} // namespace zorba

