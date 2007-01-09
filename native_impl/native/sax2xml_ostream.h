/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: sax2xml_ostream.h,v 1.1.1.1 2006/10/09 06:58:39 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen
 *
 */

 
/*______________________________________________________________________
|  
|_______________________________________________________________________*/


#ifndef XQP_SAX2XML_OSTREAM_H
#define XQP_SAX2XML_OSTREAM_H

#include <string>
#include <stack>
#include <ostream>

#include "../../util/rchandle.h"
#include "../../util/URI.h"

#include "xml_ostream.h"
#include "xml_term.h"

namespace xqp {

class sax2xml_ostream 
{
protected:
	static const uint32_t STACK_CAPACITY = 65536;
	std::string the_stack[STACK_CAPACITY];

	uint32_t top;
  std::string the_attribute;			// most recent attribute
  std::string the_element;				// most recent element tag
	std::string	the_PCDATA;					// most recent PCDATA
  std::string	the_PITarget;				// most recent PITarget
  uint16_t the_entity;						// most recent entity 

	uint32_t term_pos;							// current term position
	uint32_t last_pos;							// last term position, for delta-coding
	uint64_t uri;										// current URI hash
	uint32_t elem_counter;					// element counter
	std::vector<xml_term>& term_list;

	bool term_indexing;							// index terms
	bool bigram_indexing;						// index term bigrams
	bool e_indexing;								// index elements
	bool p_indexing;								// index     c/word::t
	bool gp_indexing;								// index   b/c/word::t
	bool ggp_indexing;							// index a/b/c/word::t

	xml_ostream& xmlss;

public:	// ctor, dtor
	sax2xml_ostream(
		uint64_t uri,
	  std::vector<xml_term>&,				// accumulate terms here
	  xml_ostream&);								// accumulate document here

	~sax2xml_ostream() {}

protected:
	void error(std::string const& msg) const throw (xqpexception);

public:	

	void add_term(xml_term const&);
	void add_term(std::string const& term, uint64_t uri, uint32_t pos);
	uint32_t get_term_position() const { return term_pos; }
	std::string elem_counter_string();
	uint32_t short get_entity() { return the_entity; }

public:	// SAX 'ContentHandler' callback methods

	//	Receive notification of character data.
	void characters(char* ch, int start, int length);

	//	Receive notification of the end of a document.
	void endDocument();

	//	Receive notification of the end of an element.
	void endElement(std::string const& uri, std::string const& localName, std::string const& qName);

	//	End the scope of a prefix-URI mapping.
	void endPrefixMapping(std::string const& prefix);

	//	Receive notification of ignorable whitespace in element content.
	void ignorableWhitespace(char* ch, int start, int length);

	//	Receive notification of a processing instruction.
	void processingInstruction(std::string cosnt& target, std::string cosnt& data);

	//	Receive an object for locating the origin of SAX document events.
	void setDocumentLocator(Locator const& locator);

	//	Receive notification of a skipped entity.
	void skippedEntity(std::string const& name);

	//	Receive notification of the beginning of a document.
	void startDocument();

	//	Receive notification of the beginning of an element.
	void startElement(std::string const& uri,
										std::string const& localName,
										std::string const& qName,
										Attributes const& atts);

	//	Begin the scope of a prefix-URI Namespace mapping.
	void startPrefixMapping(std::string const& prefix, std::string const& uri);


};

}	/* namespace xqp */
#endif	/* XQP_SAX2XML_OSTREAM_H */
