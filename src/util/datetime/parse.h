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
bool is_digit(char ch);

// Returns the last day of the given year and month. E.g. for 1980 and 2 it
// will return 29. Returns 0 on an error
int get_last_day(int year, int month);

} // namespace xqp

#endif
