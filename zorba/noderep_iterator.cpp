/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: noderep_iterator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "nodereps.h"
#include "noderep_iterator.h"
#include "qnamerep.h"
#include "errors/Error.h"
#include "util/tracer.h"
#include "values/primitive_values.h"

#include <stdlib.h>

using namespace std;
namespace xqp {


/*..........................................
 :     child_noderep_iterator              :
 :.........................................*/

child_noderep_iterator::child_noderep_iterator(
	const noderep* parent,
	noderep* current)
:
	theParentNodePtr(parent),
	theCurrentNodePtr(current)
{
	theEndNodePtr = theParentNodePtr + theParentNodePtr->length();
}
	
noderep* child_noderep_iterator::operator*() const
{
cout << TRACE << endl;

	while (true) {
		switch (theCurrentNodePtr->type()) {
		case documentNode: {
			cout << TRACE << " : documentNode" << endl;
			return new(theCurrentNodePtr) document_noderep();
		}
		case attributeNode: {
			cout << TRACE << " : attributeNode" << endl;
			return new(theCurrentNodePtr) attribute_noderep();
		}
		case elementNode: {
			cout << TRACE << " : elementNode" << endl;
			return new(theCurrentNodePtr) element_noderep();
		}
		case processingInstructionNode: {
			return new(theCurrentNodePtr) pi_noderep();
		}
		case commentNode: {
			return new(theCurrentNodePtr) comment_noderep();
		}
		case textNode: {
			cout << TRACE << " : textNode" << endl;
			return new(theCurrentNodePtr) text_noderep();
		}
		default: {
			cout << TRACE << " : out of order node: "
					 << sequence_type::describe(theCurrentNodePtr->type()) 
					 << " (" << theCurrentNodePtr->length() << ')' << endl;
			return NULL;
		}}
	}
}


child_noderep_iterator& child_noderep_iterator::operator++()
{
cout << TRACE << " : current = " << (uint32_t)(theCurrentNodePtr) << endl;
	if (theCurrentNodePtr >= theEndNodePtr) {
		cout << TRACE << " : iterator overrun" << endl;
		//errors::err(errors::XQP0001_DYNAMIC_ITERATOR_OVERRUN);
		ZorbaErrorAlerts::error_alert(error_messages::XQP0001_DYNAMIC_ITERATOR_OVERRUN,
																	error_messages::RUNTIME_ERROR, 
																	NULL);
	}
cout << TRACE << " : length = " << theCurrentNodePtr->length() << endl;
	theCurrentNodePtr += theCurrentNodePtr->length();
cout << TRACE << " : current = " << (uint32_t)(theCurrentNodePtr) << endl;
	return *this;
}


/*..........................................
 :     attribute_noderep_iterator          :
 :.........................................*/

attribute_noderep_iterator::attribute_noderep_iterator(
	const noderep* parent,
	noderep* current,
	const noderep* end)
:
	theParentNodePtr(parent),
	theCurrentNodePtr(current),
	theEndNodePtr(end)
{
}
	
noderep* attribute_noderep_iterator::operator*() const
{
cout << TRACE << endl;
	return NULL;
}

attribute_noderep_iterator& attribute_noderep_iterator::operator++()
{
	return *this;
}

bool attribute_noderep_iterator::done() const
{
	return (theCurrentNodePtr >= theEndNodePtr); 
}


/*..........................................
 :     namespace_iterator                  :
 :.........................................*/

namespace_noderep_iterator::namespace_noderep_iterator(
	const noderep* parent)
:
	theParentNodePtr(parent)
{
}
	
noderep* namespace_noderep_iterator::operator*() const
{
cout << TRACE << endl;
	return NULL;
}

namespace_noderep_iterator& namespace_noderep_iterator::operator++()
{
	return *this;
}

bool namespace_noderep_iterator::done() const
{
	return true;
}


}	/* namespace xqp */

