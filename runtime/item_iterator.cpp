/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*- *
 *  $Id: item_iterator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "item_iterator.h"
#include "util/Assert.h"
#include "errors/Error.h"
#include "values/values.h"
#include "values/nodes.h"
#include "values/qname.h"
#include "runtime/zorba.h"
#include "exprtree/expr.h"

using namespace std;
namespace xqp {

int iteratorTreeDepth = -1;

BasicIterator::BasicIterator(yy::location _loc) : 
																	open_b(false),
																	loc(_loc)
{
  this->current_line = 0;
	zorp = zorba::getZorbaForCurrentThread();
}
BasicIterator::BasicIterator(const BasicIterator& it) : rcobject (), 
																					open_b(it.open_b),
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

item_t BasicIterator::produceNext() {
	return this->nextImpl_();
}

void BasicIterator::reset() {
	this->current_line = 0;
	this->resetImpl_();
}

void BasicIterator::releaseResources() {
	this->releaseResourcesImpl_();
}

item_t BasicIterator::consumeNext(iterator_t& subIterator) {
	return subIterator->next();
}

void BasicIterator::resetChild(iterator_t& subIterator) {
	subIterator->reset();
}

void BasicIterator::releaseChildResources(iterator_t& subIterator) {
	subIterator->releaseResources();
}

item_t BasicIterator::nextImpl_() {
	cout << "'nextImpl_' is missing" << endl;
	return NULL;
}

void BasicIterator::resetImpl_() {
	cout << "'resetImpl_' is missing" << endl;
}

void BasicIterator::releaseResourcesImpl_(){
	cout << "'releaseResourcesImpl_' is missing" << endl;
}

std::ostream& BasicIterator::show(std::ostream& os)
{
	os << IT_INDENT << "<" << typeid(*this).name() << ">" << std::endl;
	_show(os);
	os << IT_OUTDENT << "</" << typeid(*this).name() << ">" << std::endl;
	return os;
}



void map_iterator::_open() {
	theState = outer;
	theInput->open();
}


item_t map_iterator::_next() {
	BasicIterator& input = *theInput;
	BasicIterator& expr = *theExpr;

	while (true) {
		if (theState==outer) {
			item_t i_h = input.next();
			vector<var_iter_t>::const_iterator itv = varv.begin();
			for (; itv!=varv.end(); ++itv) {
				(*itv)->bind(i_h);
			}
			expr.open();
			theState = inner;
		} 
		if (!expr.done()) {
			return expr.next();
		}
		expr.close();
		theState = outer;
	}
}

void map_iterator::_close() {
	theInput->close();
	if (theState!=outer)
		theExpr->close();
}

std::ostream& map_iterator::_show(std::ostream& os)
const
{
	theInput->show(os);
	if (theState!=outer)
		theExpr->show(os);
	return os;
} 

bool map_iterator::done() const {
	return (theInput->done() && (theState==outer || theExpr->done()));
}

} /* namespace xqp */

