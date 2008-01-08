/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#ifndef XQP_PRASE_H
#define XQP_PRASE_H

#include <string>

namespace xqp
{

void skip_whitespace(std::string& s, unsigned int& position);
int parse_int(std::string& s, unsigned int& position, long& result);

} // namespace xqp

#endif
