#include "LoadSchemaErrorHandler.h"
#include "StrX.h"


namespace zorba
{

LoadSchemaErrorHandler::LoadSchemaErrorHandler() :
    fSawErrors(false)
{
}

LoadSchemaErrorHandler::~LoadSchemaErrorHandler()
{
}

// ---------------------------------------------------------------------------
//  LoadSchemaErrorHandler: Overrides of the SAX ErrorHandler interface
// ---------------------------------------------------------------------------
void LoadSchemaErrorHandler::error(const SAXParseException& e)
{
    fSawErrors = true;
    XERCES_STD_QUALIFIER cerr << "\nError at file " << StrX(e.getSystemId())
    << ", line " << e.getLineNumber()
    << ", char " << e.getColumnNumber()
    << "\n  Message: " << StrX(e.getMessage()) << XERCES_STD_QUALIFIER endl;
}

void LoadSchemaErrorHandler::fatalError(const SAXParseException& e)
{
    fSawErrors = true;
    XERCES_STD_QUALIFIER cerr << "\nFatal Error at file " << StrX(e.getSystemId())
    << ", line " << e.getLineNumber()
    << ", char " << e.getColumnNumber()
    << "\n  Message: " << StrX(e.getMessage()) << XERCES_STD_QUALIFIER endl;
}

void LoadSchemaErrorHandler::warning(const SAXParseException& e)
{
    XERCES_STD_QUALIFIER cerr << "\nWarning at file " << StrX(e.getSystemId())
    << ", line " << e.getLineNumber()
    << ", char " << e.getColumnNumber()
    << "\n  Message: " << StrX(e.getMessage()) << XERCES_STD_QUALIFIER endl;
}

void LoadSchemaErrorHandler::resetErrors()
{
    fSawErrors = false;
}

} // namspace xqp
