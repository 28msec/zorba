
#ifndef XQUERY_EXECUTION_EASY_API_12_DEC_2007
#define XQUERY_EXECUTION_EASY_API_12_DEC_2007

#include "util/rchandle.h"

namespace xqp {

class XQueryResult : public rcobject
{
public:
	virtual ~XQueryResult() {};
  virtual std::ostream& serializeXML( std::ostream& os ) = 0;
  virtual std::ostream& serializeHTML( std::ostream& os ) = 0;
  virtual std::ostream& serializeTEXT( std::ostream& os ) = 0;
};

typedef rchandle<XQueryResult>		XQueryResult_t;


}//end namespace xqp


#endif
