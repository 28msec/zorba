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
#include "../util/xqp_exception.h"
#include <iostream>

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{

	try {
		context ctx;

		vector<nodeid> id_v;
		for (unsigned i=0; i<100; ++i) {
			id_v.push_back(nodeid(rand()));
		}
		uint32_t idcounter = 0;

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
		rchandle<document_node> doc1_h = new document_node(id_v[idcounter++], baseuri, uri2);

		rchandle<element_node> e1_h =
			new element_node(id_v[idcounter++], baseuri, qne1_h, &*doc1_h);
		rchandle<attribute_node> at1_h =
			new attribute_node(id_v[idcounter++], qna1_h, "atval1", &*e1_h);
		e1_h->add_attribute_node(at1_h);
		rchandle<attribute_node> at2_h =
			new attribute_node(id_v[idcounter++], qna2_h, "atval2", &*e1_h);
		e1_h->add_attribute_node(at2_h);

		rchandle<element_node> e2_h =
			new element_node(id_v[idcounter++], baseuri, qne2_h, &*doc1_h);
		rchandle<attribute_node> at3_h =
			new attribute_node(id_v[idcounter++], qna1_h, "atval3", &*e2_h);
		e2_h->add_attribute_node(at3_h);
		rchandle<attribute_node> at4_h =
			new attribute_node(id_v[idcounter++], qna2_h, "atval4", &*e2_h);
		e2_h->add_attribute_node(at4_h);

		e2_h->add_text_node(new text_node(id_v[idcounter++], "text of elem2", &*e2_h));

		rchandle<text_node> txt1_h = new text_node(id_v[idcounter++], "\n  ", &*e1_h);
		rchandle<text_node> txt2_h = new text_node(id_v[idcounter++], "\n", &*e1_h);

		e1_h->add_text_node(txt1_h);
		e1_h->add_element_node(e2_h);
		e1_h->add_text_node(txt2_h);

		rchandle<element_node> e3_h =
			new element_node(id_v[idcounter++], baseuri, qne3_h, &*doc1_h);
		rchandle<attribute_node> at5_h =
			new attribute_node(id_v[idcounter++], qna1_h, "atval5", &*e3_h);
		e3_h->add_attribute_node(at5_h);
		rchandle<attribute_node> at6_h =
			new attribute_node(id_v[idcounter++], qna2_h, "atval6", &*e3_h);
		e3_h->add_attribute_node(at6_h);

		e3_h->add_text_node(new text_node(id_v[idcounter++], "text of elem3", &*e3_h));

		rchandle<text_node> txt3_h = new text_node(id_v[idcounter++], "\n  ", &*e1_h);
		rchandle<text_node> txt4_h = new text_node(id_v[idcounter++], "\n", &*e1_h);

		e1_h->add_text_node(txt3_h);
		e1_h->add_element_node(e3_h);
		e1_h->add_text_node(txt4_h);

		doc1_h->add_element_node(e1_h);
		doc1_h->put(cout,ctx);


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

