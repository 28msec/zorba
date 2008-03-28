/*
 *	Copyright 2006-2008 FLWOR Foundation.
 *  Author: Cezar Andrei (cezar dot andrei at gmail dot com)
 *
 */
#include "schema.h"
#include "StrX.h"
#include "LoadSchemaErrorHandler.h"
#include "PrintSchema.h"
#include "XercesParseUtils.h"

#include "zorba/api_shared_types.h"
#include "types/typeimpl.h"

using namespace std;
using namespace XERCES_CPP_NAMESPACE;

namespace zorba
{
const char* Schema::XSD_NAMESPACE = "http://www.w3.org/2001/XMLSchema";
bool Schema::_isInitialized = false;

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

Schema::Schema()
{
    _grammarPool = new XMLGrammarPoolImpl(XMLPlatformUtils::fgMemoryManager);    
}

Schema::~Schema()
{
    //delete _grammarPool;
    _grammarPool = NULL;
}

void Schema::registerXSD(const char* xsdFileName)
{
    SAX2XMLReader* parser;
    
    try
    {        
        parser = XMLReaderFactory::createXMLReader(XMLPlatformUtils::fgMemoryManager, _grammarPool);
        parser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
        parser->setFeature(XMLUni::fgXercesSchema, true);
        parser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);
        parser->setFeature(XMLUni::fgSAX2CoreNameSpacePrefixes, false);
        parser->setFeature(XMLUni::fgSAX2CoreValidation, true);
        parser->setFeature(XMLUni::fgXercesDynamic, true);
        parser->setProperty(XMLUni::fgXercesScannerName, (void *)XMLUni::fgSGXMLScanner);

        LoadSchemaErrorHandler handler;    
        parser->setErrorHandler(&handler);

        cout << "==Parsing== " << xsdFileName << endl;
        parser->loadGrammar(xsdFileName, Grammar::SchemaGrammarType, true);
        
        if (handler.getSawErrors())
        {
            handler.resetErrors();
        }        
    }
    catch (const OutOfMemoryException&)
    {
        cerr << "OutOfMemoryException during parsing: '" << xsdFileName << "'\n" << endl;
    }
    catch (const XMLException& e)
    {
        cerr << "\nError during parsing: '" << xsdFileName << "'\n"
        << "Exception message is:  \n"
        << StrX(e.getMessage()) << endl;
    }
    catch (...)
    {
        cerr << "\nUnexpected exception during parsing: '" << xsdFileName << "'\n" << endl;
    }
    
    delete parser;
}

void Schema::printXSDInfo(bool excludeBuiltIn)
{
    PrintSchema::printInfo(excludeBuiltIn, _grammarPool);
	
	//xqpString val;
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
}

//void Schema::loadXsdInXQTypesystem(TypeSystem& typeSystem)
//{
//  typeSystem.createType();
//}

xqtref_t Schema::createIfExists(const TypeManager *manager, store::Item_t qname, TypeConstants::quantifier_t quantifier)
{
	const char* uri_cstr = qname->getNamespace().c_str();
  if ( XMLString::equals(XSD_NAMESPACE, uri_cstr) )
		return NULL;

//	std::cout << "--createIfExists: " << qname->getNamespace() << "@" << qname->getLocalName() << "\n";

 //   const char* localCStr = qname->getLocalName().c_str();
 //   const XMLCh* local = XMLString::transcode(localCStr);
	//const XMLCh* uri = XMLString::transcode(uri_cstr);

 //   XSModel* xsModel = _grammarPool->getXSModel();
	//XSTypeDefinition* xsTypeDef = xsModel->getTypeDefinition(local, uri);

	xqtref_t res;

	//if (!xsTypeDef)
	//	res = new xqtref_t(NULL);
	//else
	//{
	//	if (xsTypeDef->getTypeCategory() == XSTypeDefinition::SIMPLE_TYPE)
	//	{
	//		res = new xqtref_t(new UserDefinedXQType(manager, qname, *(new xqtref_t(NULL)), quantifier));
	//	}
	//	else
//	}
	
 	return res;
}

store::Item_t parseAtomicValue(xqtref_t type, xqpString textValue)
{
	//switch(type->type_kind())
	//{
	//case XQType::ATOMIC_TYPE_KIND:
	//	

	//case XQType::ANY_SIMPLE_TYPE_KIND:
	//	//factory->

	//case XQType::ANY_TYPE_KIND:
	//case XQType::EMPTY_KIND:
	//case XQType::ITEM_KIND:
	//case XQType::NODE_TYPE_KIND:
	//case XQType::NONE_KIND:
	//case XQType::UNTYPED_KIND:
	//case XQType::USER_DEFINED_KIND:
	//default:
	//}

    return 0;
}

void Schema::getValidatingItemIterator()
{
    
}

} // namespace zorba
