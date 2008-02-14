
#ifndef XQUERY_RESULT_ITERATOR_API_31_JAN_2008
#define XQUERY_RESULT_ITERATOR_API_31_JAN_2008

#include "zorba/util/rchandle.h"
#include "zorba/store/api/item.h"

//Wrap the iterator interface
namespace xqp{

class ResultIterator : virtual public rcobject
{
public:

	virtual ~ResultIterator() {}

	virtual void		openIterator() = 0;

	virtual Item_t	nextItem() = 0;

	virtual void		closeIterator() = 0;

};

typedef rchandle<ResultIterator>		ResultIterator_t;

}//end namespace xqp

#endif
