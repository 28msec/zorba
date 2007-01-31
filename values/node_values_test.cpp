/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: node_values_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "node_values.h"

#include "../context/context.h"
#include "../util/xqp_exception.h"

#include <iostream>

using namespace std;
using namespace xqp;


int main(int argc, char* argv[])
{
	try {
		context ctx;
		nodeid parent(1);
		nodeid doc(2);
		uint32_t idcounter = 3;

		string baseuri("http://base.uri.net/");
		string uri1("uri_01");
		string uri2("uri_02");
		string uri3("uri_03");

		rchandle<QName> qna1_h = new QName(QName::qn_attr,"at1");
		rchandle<QName> qna2_h = new QName(QName::qn_attr,"at2");
		rchandle<QName> qna3_h = new QName(QName::qn_attr,"at3");
		rchandle<QName> qne1_h = new QName(QName::qn_attr,"elem1");
		rchandle<QName> qne2_h = new QName(QName::qn_attr,"elem2");
		rchandle<QName> qne3_h = new QName(QName::qn_attr,"elem3");

		/*
				doc(base_uri/uri1) = 
				  <elem1 at1="atval1" at2="atval2">
					  <elem2>text1</elem2>
					  <elem3>text1</elem2>
				  </elem1>
		*/

		rchandle<document_node> doc1_h =
			new document_node(doc, baseuri, uri2);

		nodeid el1_id(idcounter++);
		rchandle<element_node> e1_h =
			new element_node(el1_id, parent, doc, qne1_h);

		nodeid at1_id(idcounter++);
		rchandle<attribute_node> at1_h =
			new attribute_node(at1_id, el1_id, qna1_h, "atval1");
		e1_h->add_node(&*at1_h);

		nodeid at2_id(idcounter++);
		rchandle<attribute_node> at2_h =
			new attribute_node(at2_id, el1_id, qna2_h, "atval2");
		e1_h->add_node(&*at2_h);

		nodeid el2_id(idcounter++);
		rchandle<element_node> e2_h =
			new element_node(el2_id, parent, doc, qne2_h);

		nodeid at3_id(idcounter++);
		rchandle<attribute_node> at3_h =
			new attribute_node(at3_id, el2_id, qna1_h, "atval3");
		e2_h->add_node(&*at3_h);

		nodeid at4_id(idcounter++);
		rchandle<attribute_node> at4_h =
			new attribute_node(at4_id, el2_id, qna2_h, "atval4");
		e2_h->add_node(&*at4_h);

		nodeid tx1_id(idcounter++);
		rchandle<text_node> tx1_h =
			new text_node(tx1_id, el2_id, "text of elem2");
		e2_h->add_node(&*tx1_h);

		nodeid tx2_id(idcounter++);
		rchandle<text_node> tx2_h =
			new text_node(tx2_id, el1_id, "\n  ");

		nodeid tx3_id(idcounter++);
		rchandle<text_node> tx3_h =
			new text_node(tx3_id, el1_id, "\n");

		e1_h->add_node(&*tx2_h);
		e1_h->add_node(&*e2_h);
		e1_h->add_node(&*tx3_h);

		nodeid el3_id(idcounter++);
		rchandle<element_node> e3_h =
			new element_node(el3_id, parent, doc, qne3_h);

		nodeid at5_id(idcounter++);
		rchandle<attribute_node> at5_h =
			new attribute_node(at5_id, el3_id, qna1_h, "atval5");
		e3_h->add_node(&*at5_h);

		nodeid at6_id(idcounter++);
		rchandle<attribute_node> at6_h =
			new attribute_node(at6_id, el3_id, qna2_h, "atval6");
		e3_h->add_node(&*at6_h);

		nodeid tx4_id(idcounter++);
		rchandle<text_node> tx4_h =
			new text_node(tx4_id, el3_id, "text of elem3");
		e3_h->add_node(&*tx4_h);

		nodeid tx5_id(idcounter++);
		rchandle<text_node> tx5_h =
			new text_node(tx5_id, el1_id, "\n  ");

		nodeid tx6_id(idcounter++);
		rchandle<text_node> tx6_h =
			new text_node(tx6_id, el1_id, "\n");

		e1_h->add_node(&*tx5_h);
		e1_h->add_node(&*e3_h);
		e1_h->add_node(&*tx6_h);

		doc1_h->add_node(&*e1_h);
		doc1_h->put(cout, &ctx);


	/*...........................................
		: element node                            :
		:.........................................:
	*/
/*
		element_node(nodeid id,string const& baseuri,string const& name,
			rchandle<node> parent_h)

		nodeid get_nodeid()
		node_kind_t node_kind()
		item_iterator attributes(context const&)
		item_iterator base_uri(context const&)
		item_iterator children(context const&)
		item_iterator namespace_bindings(context const&)
		item_iterator namespace_nodes(context const&)
		item_iterator node_name(context const&)
		item_iterator parent(context const&)
		item_iterator typed_value(context const&)
		bool is_id(context const&)
		bool is_idrefs(context const&)
		bool nilled(context const&)
		item_type const& get_type(context const&)
		string string_value(context const&)
		void add_element_node(rchandle<element_node>)
		void add_text_node(rchandle<text_node>)
		void add_text_node(string const&)
		void add_attribute_node(rchandle<attribute_node>)
		void add_ns_node(rchandle<ns_node>)
		void add_comment_node(rchandle<comment_node>)
		void add_pi_node(rchandle<pi_node>)
		bool get_nilled()
		bool get_id()
		bool get_idrefs()
		void set_nilled(bool b)
		void set_id(bool b)
		void set_idrefs(bool b)
	
		class child_iterator : public item_iterator
		{
			child_iterator(context const&,element_node const*);
		 	void open();
			void close() {}
			rchandle<item> next();
			bool done();
			void rewind();
		};
		
		class attr_iterator : public item_iterator
		{
			attr_iterator(context const&,element_node const*);
		 	void open();
			void close() {}
			rchandle<item> next();
			bool done();
			void rewind();
		};
*/
	

	/*...........................................
		: namespace node                          :
		:.........................................:
	*/
/*
		ns_node ns1(id_v[0], "?pi1", uri1, rchandle<element_node> parent_h);
		nodeid get_nodeid()
		node_kind_t node_kind()
		item_iterator node_name(context const&)
		item_iterator parent(context const&)
		item_iterator typed_value(context const&)
		string string_value(context const&)
*/
	
	
	/*...........................................
		: procesing instruction node              :
		:.........................................:
	*/
/*
		pi_node( nodeid id, string const& target, string const& content,
			string const& baseuri, rchandle<element_node> parent_h);
		nodeid get_nodeid() const { return id; }
		node_kind_t node_kind() const { return pi_kind; }
		item_iterator base_uri(context const&) const;
		item_iterator parent(context const&) const;
		item_iterator typed_value(context const&) const;
		item_iterator node_name(context const&) const;
		string string_value(context const&) const;
*/
	
	
	/*...........................................
		: comment node                            :
		:.........................................:
	*/
/*
		comment_node( nodeid, string const& content, rchandle<element_node> parent_h);
		nodeid get_nodeid()
		enum node_kind_t node_kind()
		item_iterator base_uri(context const&)
		item_iterator parent(context const&)
		item_iterator typed_value(context const&)
		item_type const& get_type(context const&)
		string string_value(context const&)
*/
	
	
	/*...........................................
		: text node                               :
		:.........................................:
	*/
/*
		text_node( nodeid, string const& content, rchandle<element_node> parent_h)
		nodeid get_nodeid()
		enum node_kind_t node_kind()
		item_iterator base_uri(context const&)
		item_iterator parent(context const&)
		item_iterator typed_value(context const&)
		item_iterator node_name(const context&)
		item_type const& get_type(context const&)
		string string_value(context const&)
*/
	
	
	/*...........................................
		: document node                           :
		:.........................................:
	*/
/*
		document_node doc1(id_v[0], uri1, uri2)

		nodeid get_nodeid()
		node_kind_t node_kind()
		item_iterator base_uri(context const&)
		item_iterator children(context const&)
		item_iterator document_uri(context const&)
		item_iterator typed_value(context const&)
		
		string string_value(context const&)
	  item_iterator unparsed_entity_public_id(context const&,string const& ent)
		item_iterator unparsed_entity_system_id(context const&,string const& ent)
		bool get_entity(string const& entity, std::string & val)
		void put_entity(string const& entity, std::string const& val)
	
		class child_iterator : public item_iterator
		{
			child_iterator(context const&,document_node const*);
		 	void open();
			void close() {}
			rchandle<item> next();
			bool done();
			void rewind();
	
		};
*/
	
	
	
	/*...........................................
		: collection node                         :
		:.........................................:
	*/
/*
		collection_node(nodeid id) 
		nodeid get_nodeid()
		node_kind_t node_kind()
		item_iterator base_uri(context const& ctx)
		item_iterator collection_uri(context const& ctx)
		item_iterator children(context const& ctx)
*/
	
	
	
	/*...........................................
		: attribute node                          :
		:.........................................:
	*/
/*
		attribute_node(nodeid id,rchandle<QName> name,string const& val,
			rchandle<element_node> parent_h);
		nodeid get_nodeid()
		node_kind_t node_kind()
		item_iterator base_uri(context const&)
		item_iterator node_name(context const&)
		item_iterator parent(context const&)
		item_iterator typed_value(context const&)
		bool is_id(context const&)
		bool is_idrefs(context const&)
		item_type const& get_type(context const&)
		string string_value(context const&) 
*/
	
	
	/*...........................................
		: binary node                             :
		:.........................................:
	*/
/*
		binary_node(nodeid id)
		nodeid get_nodeid()
		node_kind_t node_kind(context const&) 
		string string_value(context const&)
		item_iterator base_uri(context const& ctx)
		item_iterator parent(context const& ctx)
		item_iterator type_name(context const& ctx)
		item_iterator typed_value(context const& ctx)
*/
	
	} catch (xqp_exception & e) {
	} catch (exception & e) {
	} catch (...) {
	}
	
}

