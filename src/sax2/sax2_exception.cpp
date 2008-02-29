
#include "zorba/sax2.h"

namespace xqp{

//the SAX exception class hierarchy
SAX2_Exception::SAX2_Exception(xqp_string message)
{
  this->message = message;
}
SAX2_Exception::SAX2_Exception(SAX2_Exception &orig)
{
  this->message = orig.message;
}
SAX2_Exception::~SAX2_Exception() 
{}

const xqp_string  SAX2_Exception::getMessage () const {return message;}



SAX2_NotRecognizedException::SAX2_NotRecognizedException(xqp_string message): SAX2_Exception(message) 
{}


SAX2_NotSupportedException::SAX2_NotSupportedException(xqp_string message): SAX2_Exception(message) 
{}



SAX2_ParseException::SAX2_ParseException(xqp_string message, 
                                         SAX2_Locator *where):
              SAX2_Exception(message)
{
  if(!where)
    return;
  this->publicId = where->getPublicId();
  this->systemId = where->getSystemId();
  this->line = where->getLineNumber();
  this->column = where->getColumnNumber();
}

SAX2_ParseException::SAX2_ParseException(xqp_string message,
                  xqp_string publicId, 
                  xqp_string systemId, 
                  int line, int column)
                  :
            SAX2_Exception(message)
{
  this->publicId = publicId;
  this->systemId = systemId;
  this->line = line;
  this->column = column;
}

SAX2_ParseException::SAX2_ParseException(SAX2_ParseException &orig) :
  SAX2_Exception(orig)
{
  this->publicId = orig.publicId;
  this->systemId = orig.systemId;
  this->line = orig.line;
  this->column = orig.column;
}

long  SAX2_ParseException::getColumnNumber () const 
{return column;}
 
long  SAX2_ParseException::getLineNumber () const 
{return line;}
 
const xqp_string  SAX2_ParseException::getPublicId () const 
{return publicId;}
 
const xqp_string  SAX2_ParseException::getSystemId () const 
{return systemId;}

}//end namespace xqp

