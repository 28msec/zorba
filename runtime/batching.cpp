#include "batching.h"

#include "runtime/zorba.h"

namespace xqp {

BasicIterator::BasicIterator(yy::location _loc) : 
																	loc(_loc)
{
  this->current_line = 0;
	zorp = zorba::getZorbaForCurrentThread();
}
BasicIterator::BasicIterator(const BasicIterator& it) : rcobject (), 
																					loc(it.loc)
{
  this->current_line = 0;
	zorp = zorba::getZorbaForCurrentThread();
}

BasicIterator::~BasicIterator()
{
}

void BasicIterator::open()
{
	assert(!open_b);
	open_b = true;
	
	// Initialization of the line info for Duff's device.
	this->current_line = 0;
	_open();
}

void BasicIterator::close()
{
	assert(open_b);
	open_b = false;
	_close();
}

bool BasicIterator::isOpen() const
{
	return open_b;
}

bool BasicIterator::done() const
{
	return false;
}

item_t BasicIterator::next()
{
	assert(open_b);
	//daniel: saves the current iterator in zorba object (to keep track of the current iterator)
	if(zorp)
	{
		zorp->current_iterator.push(this);
		
		item_t retitem = _next();
		
		zorp->current_iterator.pop();
		return retitem;
	}
	else
		return _next();
}

item_t BasicIterator::produceNext()
{
	return NULL;
}

void BasicIterator::reset()
{
	
}

void BasicIterator::releaseResources()
{
	
}


std::ostream& BasicIterator::show(std::ostream& os)
{
	os << IT_INDENT << "<" << typeid(*this).name() << ">" << std::endl;
	_show(os);
	os << IT_OUTDENT << "</" << typeid(*this).name() << ">" << std::endl;
	return os;
}

// template <class IterType>
// Batcher<IterType>::Batcher(yy::location _loc) : BasicIterator(_loc) { }

// template <class IterType>
// Batcher<IterType>::Batcher(const Batcher<IterType>& it) : BasicIterator(it) {}

// template <class IterType>
// Batcher<IterType>::~Batcher() {}
/*
template <class IterType>
item_t Batcher<IterType>::produceNext() {
	return static_cast<IterType*>(this)->nextImpl();
}

template <class IterType>
void Batcher<IterType>::reset() {
	static_cast<IterType*>(this)->resetImpl();
}

template <class IterType>
void Batcher<IterType>::freeResources() {
	static_cast<IterType*>(this)->freeResourcesImpl();
}

template <class IterType>
item_t Batcher<IterType>::consumeNext(iterator_t& subIterator) {
	return subIterator->produceNext();
}

template <class IterType>
void Batcher<IterType>::resetChild(iterator_t& subIterator) {
	subIterator->reset();
}

template <class IterType>
void Batcher<IterType>::releaseChildResources(iterator_t& subIterator) {
	subIterator->releaseResources();
}*/

}
