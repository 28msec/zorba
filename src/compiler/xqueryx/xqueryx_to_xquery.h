
#ifndef ZORBA_XQUERYX_TO_XQUERY_CONVERTOR
#define ZORBA_XQUERYX_TO_XQUERY_CONVERTOR

namespace zorba {

struct xsltStylesheet;

class XQueryXConvertor
{
  xsltStylesheet*     xqueryx_xslt;
  bool                inited;
public:
  XQueryXConvertor();
  ~XQueryXConvertor();
  
  void XQueryX_init();
  char* XQueryX2XQuery( const char *xqueryx);

  bool isWhitespace(char c);
  char* skipWhitespaces(char *xquery_str);
  bool  isXQueryX(char *xquery_str);

  void freeResult(char *result_str);
};

};//end namespace zorba

#endif
