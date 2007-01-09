/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: url_cacnonicalizer.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */


#ifndef XQP_URL_CANONICALIZER_H
#define XQP_URL_CANONICALIZER_H

#include <string>
#include <cctype>

#include "../util/hashmap.h"

namespace xqp {

/*_______________________________________________________________________
|                                                                        |
|  Canonicalizes URLs
|________________________________________________________________________|*/

class url_canonicalizer
{

public:
  //ctor, dtor
  url_canonicalizer(unsigned int maxloops, bool stripIndex);
  ~url_canonicalizer();

private:
  static hashmap<char> TLDHash;
	static bool inittab;

  unsigned int max_allowed_loops;
  bool strip_index_pages_in_path;
  std::string saveurl;

private:
  bool escapeChars(
    std::string& s,
    std::string const& reserved_chars,
    const bool (&charTable)[256]);
  void resolveHtmlEntities(std::string &s);

public:
  // Canonicalize a url in place
  bool canonicalizeUrl(std::string& url);

  // find loops in a string
	static bool containsLoop(
    const std::vector<std::string>& v,
    unsigned int max_loops,
    unsigned int stop_offset_from_end);

};


}	/* namespace xqp */
#endif	/* XQP_URL_cANONICALIZER_H */

