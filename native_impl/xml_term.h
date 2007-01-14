/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_term.h,v 1.1.1.1 2006/10/09 06:58:38 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen
 *
 */

#ifndef XQP_XML_TERM_H
#define XQP_XML_TERM_H

#include <string>
#include <sstream>

namespace xqp {

/*______________________________________________________________________
| 
|  One term extracted from an XML document.
|_______________________________________________________________________*/

class xml_term
{
public:
	std::string term;			// the input term
  uint32_t uri;   			// URI hash
  uint32_t pos;					// term offset in source

public:
  xml_term() {}

  xml_term(
		std::string const& _term,
		uint32_t _uri,
		uint32_t _pos)
  :
		term(_term),
		uri(_uri),
		pos(_pos)
	{}

  ~xml_term() {}

public:
	std::string const& get_term() const { return term; }
	unsigned get_uri() const { return uri; }
	unsigned get_pos() const { return pos; }
  std::string to_string() const;

};


}	/* namespace xq p*/
#endif	/* XQP_XML_TERM_H */
