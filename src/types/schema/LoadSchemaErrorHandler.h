#ifndef LOADSCHEMAERRORHANDLER_H_
#define LOADSCHEMAERRORHANDLER_H_

#include "xercesIncludes.h"

using namespace XERCES_CPP_NAMESPACE;

namespace zorba
{

class LoadSchemaErrorHandler 
    : public DefaultHandler
{
public:
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    LoadSchemaErrorHandler ();
    ~LoadSchemaErrorHandler ();

    bool getSawErrors() const
    {
        return fSawErrors;
    }

    void warning(const SAXParseException& exc);
    void error(const SAXParseException& exc);
    void fatalError(const SAXParseException& exc);
    void resetErrors();


private:
    bool            fSawErrors;
};

} // namespace xqp

#endif /*LOADSCHEMAERRORHANDLER_H_*/
