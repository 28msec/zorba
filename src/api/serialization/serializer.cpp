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

#include "api/serialization/serializer.h"
#include "util/zorba.h"
#include "store/naive/basic_item_factory.h"
#include "types/sequence_type.h"

#include "string.h"

namespace xqp {


const xqp_string serializer::END_OF_LINE = "\n";

void serializer::reset()
{
	state = INITIAL_STATE;
	version = "1.0";	
	indent = PARAMETER_VALUE_NO;
	standalone = PARAMETER_VALUE_OMIT;
	omit_xml_declaration = PARAMETER_VALUE_NO;
	byte_order_mark = PARAMETER_VALUE_NO;
}

serializer::serializer()
{
	reset();	
}

serializer::~serializer()
{
}

void serializer::set_parameter(xqp_string parameter_name, xqp_string value)
{
	// TODO: add handled parameters translation
	if (parameter_name == "standalone")
	{
		if (value == "yes")
			standalone = PARAMETER_VALUE_YES;
		else if (value == "no")
			standalone = PARAMETER_VALUE_NO;
		else if (value == "omit")
			standalone = PARAMETER_VALUE_OMIT;
		else
			ZorbaErrorAlerts::error_alert(
				error_messages::SEPM0016_Invalid_parameter_value,
				error_messages::SYSTEM_ERROR,
				NULL);
	}
	else if (parameter_name == "omit-xml-declaration")
	{
		if (value == "yes")
			omit_xml_declaration = PARAMETER_VALUE_YES;
		else if (value == "no")
			omit_xml_declaration = PARAMETER_VALUE_NO;		
		else
			ZorbaErrorAlerts::error_alert(
				error_messages::SEPM0016_Invalid_parameter_value,
				error_messages::SYSTEM_ERROR,
   				NULL);
	}
	else if (parameter_name == "byte-order-mark")
	{
		if (value == "yes")
			byte_order_mark = PARAMETER_VALUE_YES;
		else if (value == "no")
			byte_order_mark = PARAMETER_VALUE_NO;
		else
			ZorbaErrorAlerts::error_alert(
				error_messages::SEPM0016_Invalid_parameter_value,
				error_messages::SYSTEM_ERROR,
				NULL);
	}
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
			Item_t child = children->next();
			while (child != NULL)
			{
				s5.push_back(child);
				child = children->next();
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
	const char* chars = str.c_str();
	int is_quote;
	
	for (unsigned int i=0; i<str.bytes(); i++, chars++ )
	{
		switch (*chars)
		{
		case '<':
			os << "&lt;";
			break;
		case '>':
			os << "&gt;";
			break;
			
		case '"':
			os << "&quot;";
			break;
			
		case '&':
			is_quote = 0;
			for (unsigned int j=1; j<str.bytes()-i; j++)
			{
				if ( ! ((*(chars+j) >= 'a' && *(chars+j) <= 'z') 
					||
					(*(chars+j) >= 'A' && *(chars+j) <= 'Z')
					||
					(*(chars+j) >= '0' && *(chars+j) <= '9')
					||
					(*(chars+j) == '#')))
				{
					break;				
				}
				
				if (*(chars+j) == ';' 
					&&
					(j>1))
				{
					is_quote = 1;
					break;				
				}
			}
			
			if (is_quote)
				os << *chars;
			else
				os << "&amp;";
			break;
			
		default:
			os << *chars;
			break;
		}
	}	
}

void serializer::emit_indentation(int depth, ostream& os)
{
	for (int i=0; i<depth; i++)
		os << "  ";
}

unsigned int serializer::emit_node_children(Item_t item, ostream& os, int depth)
{
	Iterator_t it;
	Item_t child;
	unsigned int children_count = 0;
	bool closed_parent_tag = 0;

	// emit namespace declarations
	it = item->getChildren();
	child = it->next();
	while (child != NULL )
	{
		if (child->getNodeKind() == namespaceNode )
		{
			emit_node(child, os, depth);
			children_count++;			
		}		
		
		child = it->next();
	}
	
	/* TODO: uncomment when this will be implemented in the Item store
	it = item->getNamespaceNodes();
	child = it->next();
	while (child != NULL )
	{
		if (child->getNodeKind() == namespaceNode )
		{
			emit_node(child, os, depth);
			children_count++;			
		}		
		
		child = it->next();
	}
	*/ 
	
	// emit attributes 
	it = item->getAttributes();
	child = it->next();
	while (child!= NULL)
	{		
		emit_node(child, os, depth);
		children_count++;		
    	child = it->next();
	}
	
	// output all the other nodes
	it = item->getChildren();
	child = it->next();
	while (child!= NULL)
	{
		if (child->getNodeKind() != attributeNode
		   &&
		   child->getNodeKind() != namespaceNode)
		{
			
			if (!closed_parent_tag)
			{
				os << ">";
				closed_parent_tag = 1;
			}

			emit_node(child, os, depth);
			children_count++;
		}

    	child = it->next();
	}

	return children_count;
}

void serializer::emit_node(Item_t item, ostream& os, int depth)
{
	if( item->getNodeKind() == documentNode )
	{
		state = DOCUMENT_STARTED;
		emit_node_children(item, os, depth+1);
	}
	else if (item->getNodeKind() == elementNode)
	{
		if (indent)
			emit_indentation(depth, os);
		os << "<" << item->getNodeName()->getStringProperty();

		unsigned int children_count = emit_node_children(item, os, depth);

		if (children_count > 0)		
			os << "</" << item->getNodeName()->getStringProperty() << ">";
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
		os << " " << item->getNodeName()->getStringProperty() << "=\"";
		emit_expanded_string(item->getStringValue(), os);
		os << "\"";
	}
	else if (item->getNodeKind() == textNode)
	{		
		emit_expanded_string(item->getStringValue(), os);
	}
	else 
	{
		os << "node of type: " << item->getNodeKind();
		
	}
}

void serializer::validate_parameters(void)
{
	if (omit_xml_declaration == PARAMETER_VALUE_YES)
	{		
		if (standalone != PARAMETER_VALUE_OMIT
			/*||
			(version != "1.0" && doctype_system is specified*/ )
		{
			// throw SEPM0009
		}
	}
}

void serializer::serialize_as_xml(PlanIter_t iter, ostream& os)
{
	PlanIterWrapper iw(iter);
	Item_t item;
	
	validate_parameters();
	
	os << "\n--- Serialization ---------------\n";
	
	if (byte_order_mark == PARAMETER_VALUE_YES)
	{
		// TODO: output BOM depending on given encoding
		xqpString temp;
		temp = (uint32_t)0xFEFF;
		os << temp;
	}
	
	if (omit_xml_declaration == PARAMETER_VALUE_NO)
	{
		os << "<?xml version=\"" << version << "\" encoding=\"UTF-8\"";
		if (standalone != PARAMETER_VALUE_OMIT)
		{
			os << "standalone=\"";
			
			if (standalone == PARAMETER_VALUE_YES)
				os << "yes";
			else
				os << "no";
			
			os << "\"";
		}	
		os << "?>";
		
		if (indent)
			os << END_OF_LINE;
	}

	item = iw.next();	
	while (item != NULL )
	{
		if (item->isAtomic())
		{
			emit_expanded_string(item->getStringValue(), os);
		}
		else
		{
			emit_node(item, os, 0);
		}

		item = iw.next();
	}
	
	os << "\n--- end -------------------------\n";
}

void serializer::serialize_as_xml2(list_type& items, ostream& os)
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
