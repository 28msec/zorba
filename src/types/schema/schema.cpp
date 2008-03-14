#include "schema.h"
#include "StrX.h"
#include "LoadSchemaErrorHandler.h"
#include "types/typeimpl.h"

using namespace std;
using namespace XERCES_CPP_NAMESPACE;

namespace zorba
{

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

void Schema::registerXSD(char* xsdFileName)
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
    //printSchemaInfo(excludeBuiltIn, _grammarPool);
//    PrintSchema::printInfo(excludeBuiltIn, _grammarPool);
    //    XSDPrintVisitor pv;
    //    XSDDriver driver(static_cast<XSDVisitor&>(pv));
    //     
    //    driver.visitSchemaInfo(excludeBuiltIn, _grammarPool);    
}

//void Schema::loadXsdInXQTypesystem(TypeSystem& typeSystem)
//{
//  typeSystem.createType();
//}

xqtref_t Schema::createIfExists(store::Item_t qname)
{
	xqtref_t * res = new xqtref_t(NULL);//new xqtref_t(new UserDefinedXQType(qname, NULL, TypeConstants::QUANT_ONE));   
	return *res;
}

store::Item_t parseAtomicValue(xqtref_t type, xqpString textValue)
{
    return 0;
}

void Schema::getValidatingItemIterator()
{
    
}

} // namespace zorba
