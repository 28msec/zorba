
#ifndef XQUERY_EXECUTION_EASY_API_12_DEC_2007
#define XQUERY_EXECUTION_EASY_API_12_DEC_2007

#include "util/rchandle.h"

namespace xqp {

class XQueryResult : public rcobject
{
public:
	virtual ~XQueryResult() {};
  virtual bool serializeXML( std::ostream& os ) = 0;
  virtual bool serializeHTML( std::ostream& os ) = 0;
  virtual bool serializeTEXT( std::ostream& os ) = 0;

	virtual bool isError() = 0;
};

typedef rchandle<XQueryResult>		XQueryResult_t;


}//end namespace xqp


#endif
