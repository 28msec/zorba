
#ifndef ZORBA_SAX2_XML_READER_27_FEB_2008
#define ZORBA_SAX2_XML_READER_27_FEB_2008

#include "zorba/rchandle.h"

namespace xqp{
class  SAX2_ContentHandler;
class  SAX2_ErrorHandler;
class  SAX2_DTDHandler;
class  SAX2_DeclHandler;
class  SAX2_LexicalHandler;

class	XQuery;
typedef rchandle<XQuery>		XQuery_t;


class SAX2_XMLReader : public SimpleRCObject
{
protected:
  SAX2_ContentHandler *content_handler;
  SAX2_ErrorHandler *error_handler;
  SAX2_DTDHandler   *dtd_handler;
  SAX2_DeclHandler  *decl_handler;
  SAX2_LexicalHandler *lexical_handler;

public:
  SAX2_XMLReader(
                SAX2_ContentHandler *content_handler = NULL,
                SAX2_ErrorHandler* error_handler = NULL,
                SAX2_DTDHandler*  dtd_handler = NULL,
                SAX2_DeclHandler* decl_handler = NULL,
                SAX2_LexicalHandler* lexical_handler = NULL)
  {
    this->content_handler = content_handler;
    this->error_handler = error_handler;
    this->dtd_handler = dtd_handler;
    this->decl_handler = decl_handler;
    this->lexical_handler = lexical_handler;
  }
  virtual ~SAX2_XMLReader() {}

  virtual bool parse(XQuery_t result) = 0;

};

}//end namespace xqp

#endif
