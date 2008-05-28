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

namespace zorba
{
const char* Schema::XSD_NAMESPACE = XML_SCHEMA_NS;

bool Schema::_isInitialized = false;

xqtref_t getXQTypeForXSTypeDefinition(const TypeManager *typeManager, 
    XSTypeDefinition* xsTypeDef);


xqp_string transcode(const XMLCh *const str)
{
    char* trStr = XMLString::transcode(str);
    xqp_string res (trStr);
    delete trStr;
    return res;
}


void Schema::initialize()
{
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
}

void Schema::terminate()
{
    if (_isInitialized)
    {
        XERCES_CPP_NAMESPACE::XMLPlatformUtils::Terminate();    
        _isInitialized = false;
    }
}

#ifndef ZORBA_NO_XMLSCHEMA

Schema::Schema()
{
    _grammarPool = new XMLGrammarPoolImpl(XMLPlatformUtils::fgMemoryManager);
    _udTypesCache = new hashmap<xqtref_t>;
}

Schema::~Schema()
{
    delete _grammarPool;
    //_grammarPool = NULL;
    delete _udTypesCache;
}

void Schema::registerXSD(const char* xsdFileName)
{
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

        LoadSchemaErrorHandler handler;    
        parser->setErrorHandler(&handler);

        //cout << "==Parsing== " << xsdFileName << endl;
        parser->loadGrammar(xsdFileName, Grammar::SchemaGrammarType, true);
        
        if (handler.getSawErrors())
        {
            handler.resetErrors();
        }        
    }
    catch (const OutOfMemoryException&)
    {
        std::cerr << "OutOfMemoryException during parsing: '" << xsdFileName << "'\n" << std::endl;
    }
    catch (const XMLException& e)
    {
        std::cerr << "\nError during parsing: '" << xsdFileName << "'\n"
        << "Exception message is:  \n"
        << StrX(e.getMessage()) << std::endl;
    }
    catch (...)
    {
        std::cerr << "\nUnexpected exception during parsing: '" << xsdFileName << "'\n" << std::endl;
    }
}

void Schema::printXSDInfo(bool excludeBuiltIn)
{
    PrintSchema::printInfo(excludeBuiltIn, _grammarPool);
  
  //xqp_string val;
  //store::Item_t res;

  //val = "  \t\n  1 \t ";
  //XercesParseUtils::parseXSBoolean(val, res);
  //XercesParseUtils::parseXSInteger(val, res);
  //XercesParseUtils::parseXSPositiveInteger(val, res);
  //XercesParseUtils::parseXSNonPositiveInteger(val, res);
  //XercesParseUtils::parseXSNegativeInteger(val, res);
  //XercesParseUtils::parseXSNonNegativeInteger(val, res);
  //XercesParseUtils::parseXSUnsignedByte(val, res);
  //XercesParseUtils::parseXSUnsignedShort(val, res);
  //XercesParseUtils::parseXSUnsignedInt(val, res);
  //XercesParseUtils::parseXSUnsignedLong(val, res);
  //XercesParseUtils::parseXSByte(val, res);
  //XercesParseUtils::parseXSShort(val, res);
  //XercesParseUtils::parseXSInt(val, res);
  //XercesParseUtils::parseXSLong(val, res);
  //val = "  \t\n  1.1 \t ";
  //XercesParseUtils::parseXSFloat(val, res);
  //XercesParseUtils::parseXSDouble(val, res);
  //XercesParseUtils::parseXSDecimal(val, res);
  
  //XercesParseUtils::parseXSString(val, res);
  //XercesParseUtils::parseXSNormalizedString(val, res);
  //val = "  \t\n  ACBD \t ";
  //XercesParseUtils::parseXSToken(val, res);
  //XercesParseUtils::parseXSNMToken(val, res);
  //XercesParseUtils::parseXSName(val, res);
  //XercesParseUtils::parseXSNCName(val, res);
  //XercesParseUtils::parseXSID(val, res);
  //XercesParseUtils::parseXSIDRef(val, res);
  //XercesParseUtils::parseXSEntity(val, res);
  //XercesParseUtils::parseXSNotation(val, res);

  //val = "   2002-10-10T12:00:00  ";
  //XercesParseUtils::parseXSDateTime(val, res);
  //val = "   2002-10-11+12:00  ";
  //XercesParseUtils::parseXSDate(val, res);
  //val = "   13:20:00-05:00  ";
  //XercesParseUtils::parseXSTime(val, res);
    //val = "   1999-04-05:00  ";
  //XercesParseUtils::parseXSGYearMonth(val, res);
  //val = "  1999-05:00  ";
  //XercesParseUtils::parseXSGYear(val, res);
  //val = "  --12-30-05:00  ";
  //XercesParseUtils::parseXSGMonthDay(val, res);
  //val = "  ---30-05:00  ";
  //XercesParseUtils::parseXSGDay(val, res);
  //val = "  --12-05:00  ";
  //XercesParseUtils::parseXSGMonth(val, res);
  //val = "  P1Y2M3DT10H30M12.123S  ";
  //XercesParseUtils::parseXSDuration(val, res);
  //val = "  P1Y2M ";
  //XercesParseUtils::parseXSYearMonthDuration(val, res);
  //val = "  P3DT10H30M12.123S  ";
  //XercesParseUtils::parseXSDayTimeDuration(val, res);
  //val = "  blah blah blah  ";
  //XercesParseUtils::parseXSAnyAtomicType(val, res);
  //XercesParseUtils::parseXSUntypedAtomic(val, res);
  //val = "  SGVsbG8gV29ybGQ=  ";
  //XercesParseUtils::parseXSBase64Binary(val, res);
  //val = "  FF0099  ";
  //XercesParseUtils::parseXSHexBinary(val, res);
  //val = "  http://a.b.c/a/b/c.d  ";
  //XercesParseUtils::parseXSAnyUri(val, res);
  //val = "  p:local  ";
  //XercesParseUtils::parseXSQName(val, res);
  //std::cout << "Val: " << val << "\tResult: '" << res->getStringValue() << "'\n\n\n\n";



    //std::cout <<"\n\nValidate the value of a user defined atomic type:\n";
    //
    //RootTypeManager& ts = GENV_TYPESYSTEM;
    //const DelegatingTypeManager *typeManager = new DelegatingTypeManager(&ts);

    //store::ItemFactory* factory = GENV_ITEMFACTORY;
    //
    //xqp_string lNamespace("simple.xsd");
    //xqp_string lPrefix("");
    //xqp_string lLocal("HatSizeType");
    //store::Item_t qname = factory->createQName(lNamespace.getStore(),
    //    lPrefix.getStore(), lLocal.getStore());;

    //xqtref_t type = createIfExists(typeManager, qname, TypeConstants::QUANT_ONE);
    //
    //const xqp_string textValue("17");
    //xqtref_t aSourceType = ts.STRING_TYPE_ONE;
    //xqtref_t aTargetType = type;

    //store::Item_t result;
    //parseUserAtomicTypes(textValue, aSourceType, aTargetType, result);
}

xqtref_t Schema::createIfExists( const TypeManager *typeManager, const store::Item* qname,
    TypeConstants::quantifier_t quantifier)
{
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
}
#endif//ZORBA_NO_XMLSCHEMA


xqtref_t getXQTypeForXSTypeDefinition(const TypeManager *typeManager, XSTypeDefinition* xsTypeDef)
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

            store::Item_t qname = GENV_ITEMFACTORY->createQName(lNamespace.getStore(), lPrefix.getStore(), lLocal.getStore());

            xqtref_t xqType = xqtref_t(new UserDefinedXQType(typeManager, qname, baseXQType, TypeConstants::QUANT_ONE));

            result = xqType;
        }
    }
    else
      // not implemented for complex Types
      result = NULL;

    return result;
}

#ifndef ZORBA_NO_XMLSCHEMA
// user atomic types
bool Schema::parseUserAtomicTypes(const xqp_string textValue, const xqtref_t& aSourceType,
                                  const xqtref_t& aTargetType, store::Item_t &result)
{
    //std::cout << "parseUserAtomicTypes: " << textValue;

    ZORBA_ASSERT( aSourceType->type_kind() == XQType::ATOMIC_TYPE_KIND && 
        TypeOps::get_atomic_type_code(*aSourceType) == TypeConstants::XS_STRING);
    ZORBA_ASSERT( aTargetType->type_kind() == XQType::USER_DEFINED_KIND );

    const UserDefinedXQType udXQType = static_cast<const UserDefinedXQType&>(*aTargetType);
    ZORBA_ASSERT( udXQType.isAtomic() );

    store::Item_t typeQName = udXQType.getQName();
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

    const XQType* baseType_ptr = udXQType.getBaseType().getp();

    while ( baseType_ptr->type_kind() == XQType::USER_DEFINED_KIND )
    {        
        const UserDefinedXQType* udBaseType_ptr = static_cast<const UserDefinedXQType*>(baseType_ptr);
        baseType_ptr = udBaseType_ptr->getBaseType().getp();
    }

    ZORBA_ASSERT( baseType_ptr->type_kind() == XQType::ATOMIC_TYPE_KIND );

    xqpStringStore_t textval = textValue.getStore();
    result = GenericCast::instance()->cast(textval, baseType_ptr);

    return true;
}
#endif//ZORBA_NO_XMLSCHEMA

} // namespace zorba

