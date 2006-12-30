/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_loader.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_XML_LOADER_H
#define XQP_XML_LOADER_H
 
#include "../../util/xqpexception.h"
#include "xml_ostream.h"

namespace xqp {

class xml_loader
{
  void xml_error(std::string const&) 
  throw (xqpexception);

  /**
   *  Load an XML file.
   *  @param path the input file path name
   *  @param uri  the input document label
   *  @param xos  the XML output stream
   *  @throws xqpexception
   */
  void xml_loader::load_xml_file(
    std::string const& path,
    std::string const& uri,
    xml_ostream& xos)
  throw (xqpexception);
  
};


}	/* namespace xqp */
#endif  /* XQP_XML_LOADER_H */
