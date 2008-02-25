#ifndef ZORBA_RESULT_ITERATOR_H
#define ZORBA_RESULT_ITERATOR_H

#include <zorba/common/api_shared_types.h>
#include <zorba/item.h>

//Wrap the iterator interface
namespace xqp{

class ResultIterator : virtual public SimpleRCObject
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
