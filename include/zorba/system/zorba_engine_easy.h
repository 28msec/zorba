
#ifndef ZORBA_ENGINE_EASY_API_12_DEC_2007
#define ZORBA_ENGINE_EASY_API_12_DEC_2007

#include "compiler/compiled_xquery_easy.h"

namespace xqp {

class XQuerySimpleFactory
{
public:
  static XQuerySimple_t createQuery(const char* aQueryString,
																		xqp_string	xquery_source_uri = "");
  static XQuerySimple_t createQueryFromFile(const char* xquery_file);
};



}//end namespace xqp

#endif

