/**
 *
 * @copyright
 * ========================================================================
 *	Copyright 2007 FLWOR Foundation
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *		http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 * ========================================================================
 *
 * @author Nicolae Brinza (nbrinza@ipdevel.ro)
 * @file serialization/serializer.cpp
 *
 */

#include "api/serializer.h"
#include "util/zorba.h"
#include "store/native/basic_item_factory.h"
#include "types/sequence_type.h"


namespace xqp {


const xqp_string serializer::END_OF_LINE = "\n";

serializer::serializer()
{
	version = "1.0";
	indent = 0;
}

serializer::~serializer()
{
}

void serializer::set_parameter(xqp_string parameter_name, xqp_string value)
{
	// TODO: add handled parameters translation

}

void serializer::list_copy(list_type& dest, list_type& src)
{
	list_iterator<Item_t> it = src.begin();

	for ( ; it != src.end(); ++it)
	{
		dest.push_back(*it);
	}
}

void serializer::normalize_sequence(list_type& items, list_type& out)
{
	list_type s1, s2, s3, s4, s5, s6;
	list_iterator<Item_t> it = NULL;
	list_iterator<Item_t> st = NULL;

	// TODO: ItemFactory* pif = zorba::getZorbaForCurrentThread()->getItemFactory();
	ItemFactory* pif = new BasicItemFactory();

	// step 1
	if (items.size() == 0)
	{
		s1.push_back(pif->createString(""));
	}
	else
	{
		list_copy(s1, items);
	}
	
	// step 2
	it = s1.begin();
	for ( ; it != s1.end(); ++it)
	{
		if ((*it)->isAtomic())
		{
			s2.push_back(pif->createString((*it)->getStringProperty()));

		}
		else
		{
			s2.push_back(*it);
		}
	}

	// step 3
	it = s2.begin();
	st = s2.begin();
	for ( ; it != s2.end(); ++it)
	{
		if ((*it)->isNode())
		{
			if (st != it)
			{
				xqp_string s;

				// concatenate strings
				s += (*st)->getStringProperty();
				++st;
				for ( ; st != it; ++st)
					s += " " + (*st)->getStringProperty(); 

				s3.push_back(pif->createString(s));
			}

			s3.push_back(*it);
			st = it;
			if (st != s2.end())
				++st;
		}
	}

	if (st != it)
	{
		xqp_string s;

		// concatenate strings
		s += (*st)->getStringProperty();
		++st;
		for ( ; st != it; ++st)
			s += " " + (*st)->getStringProperty();

		s3.push_back(pif->createString(s));
	}
	
	// step 4
	it = s3.begin();
	for ( ; it != s3.end(); ++it)
	{
		if ((*it)->isAtomic()
			&&
			(*it)->getType() == xs_string)
		{		
			s4.push_back(pif->createTextNode((*it)->getStringProperty()));
		}
		else
		{
			s4.push_back(*it);
		}
	}

	// step 5
	it = s4.begin();
	for ( ; it != s4.end(); ++it)
	{
		if ((*it)->isNode()
			&&
			(*it)->getNodeKind() == documentNode )
		{
			Iterator_t children = (*it)->getChildren();
			IteratorWrapper iw(children);
			Item_t child = iw.next();
			while (child != NULL)
			{
				s5.push_back(child);
				child = iw.next();
			}
		}
		else
		{
			s5.push_back(*it);
		}    
	}

	// step 6
	it = s5.begin();
	st = s5.begin();
	for ( ; it != s5.end(); ++it)
	{
		if ((*it)->isNode()
			&&
			(*it)->getNodeKind() == textNode )
		{
			if (st != it)
			{
				xqp_string s;

				// concatenate strings
				for ( ; st != it; ++st)
					s += (*st)->getStringProperty(); 
					
				// TODO: need to drop nodes with values of zero length?

				s6.push_back(pif->createTextNode(s));
			}

			s6.push_back(*it);
			st = it;
			if (st != s5.end())
				++st;
		}
	}
	
	if (st != it)
	{
		xqp_string s;
    
    	// concatenate strings
		for ( ; st != it; ++st)
			s += (*st)->getStringProperty(); 
					
		// TODO: need to drop nodes with values of zero length?
        
        s6.push_back(pif->createTextNode(s));
	}
	    
	// step 7
	it = s6.begin();
	for ( ; it != s6.end(); ++it)
	{
		if ((*it)->isNode()
			&&
			((*it)->getNodeKind() == attributeNode)
				||
				(*it)->getNodeKind() == namespaceNode)
		{
			// throw error
			ZorbaErrorAlerts::error_alert (
			    error_messages::SENR0001_Item_is_attribute_or_namespace_node,
			    error_messages::SYSTEM_ERROR,
			    NULL
		);

		}
	}

	list_copy (out, s6);
}

void serializer::emit_expanded_string(xqp_string str, ostream& os)
{
	// TODO: quote characters 
	os << str;
}

void serializer::emit_indentation(int depth, ostream& os)
{
	for (int i=0; i<depth; i++)
		os << "  ";
}

unsigned int serializer::emit_node_children(Item_t item, ostream& os, int depth)
{
	unsigned int children_count = 0;

	// emit attributes first
	Iterator_t it = item->getChildren();
	IteratorWrapper iw(it);
	Item_t child = iw.next();
	while (child!= NULL)
	{
		if (child->getNodeKind() == attributeNode)
		{
			if (children_count == 0)
				os << ">";

			emit_node(child, os, depth);
			children_count++;
		}
    
    	child = iw.next();
	}

	// output all the other nodes
	it = item->getChildren();
	IteratorWrapper iw2(it);
	child = iw.next();
	while (child!= NULL)
	{
		if (child->getNodeKind() != attributeNode)
		{
			if (children_count == 0)
				os << ">";

			emit_node(child, os, depth);
			children_count++;
		}
    
    	child = iw.next();
	}

	return children_count;
}

void serializer::emit_node(Item_t item, ostream& os, int depth)
{
	if( item->getNodeKind() == documentNode )
	{
		if (indent)
			emit_indentation(depth, os);
		os << "<" << item->getDocumentURI();
		
		unsigned int children_count = emit_node_children(item, os, depth+1);

		if (children_count > 0)
		{
			if (indent)
				emit_indentation(depth, os);
        	os << "</" << item->getDocumentURI() << ">";
		}
		else
			os << "/>";

		if (indent)
			os << serializer::END_OF_LINE;
	}
	else if (item->getNodeKind() == elementNode)
	{
		if (indent)
			emit_indentation(depth, os);
		os << "<" << item->getNodeName()->getStringProperty();

		unsigned int children_count = emit_node_children(item, os, depth);

		if (children_count > 0)
		{
			if (indent)
				emit_indentation(depth, os);
			os << "</" << item->getNodeName()->getStringProperty();
		}
		else
			os << "/>";

		if (indent)
			os << serializer::END_OF_LINE;
	}
	else if (item->getNodeKind() == attributeNode )
	{
		os << " " << item->getNodeName()->getStringProperty() << "=\"";
		emit_expanded_string(item->getStringValue(), os);
		os << "\"";
	}
	else if (item->getNodeKind() == namespaceNode)
	{

	}
	else if (item->getNodeKind() == textNode)
	{
		emit_expanded_string(item->getStringValue(), os);
	}
}

void serializer::serialize_as_xml(list_type& items, ostream& os)
{
	list_type s;

	// /* testing:
	list_iterator<Item_t> it = items.begin();
	for ( ; it != items.end(); ++it )
	{
		Item_t item = *it;
		os << item->show();
	}
	/* */

	normalize_sequence(items, s);

	
	it = s.begin();
	for ( ; it != s.end(); ++it )
		os << "<" << (*it)->show() << "> ";

	// emit the XML header
	// TODO: process econding
	os << "<?xml version=\"" << version << "\" encoding=\"UTF-8\"?>";
	if (indent)
		os << END_OF_LINE;


	it = s.begin();

	if ((*it)->getNodeKind() == documentNode)
		emit_node(*it, os, 0);
	else
	{
		// surround in <doc> tags
		os << "<doc>";
		for ( ; it != s.end(); ++it )
			emit_node( *it, os, 1);

		os << "</doc>";
	}
}

} // namespace xqp
