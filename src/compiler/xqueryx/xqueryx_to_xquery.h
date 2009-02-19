
#ifndef ZORBA_XQUERYX_TO_XQUERY_CONVERTOR
#define ZORBA_XQUERYX_TO_XQUERY_CONVERTOR

namespace zorba {

struct xsltStylesheet;

class XQueryXConvertor
{
  xsltStylesheet*     xqueryx2005;
  bool                inited;
public:
  XQueryXConvertor();
  ~XQueryXConvertor();
  
  void XQueryX_init();
  char* XQueryX2XQuery( const char *xqueryx);

  void freeResult(char *result_str);
};

};//end namespace zorba

#endif
