#ifndef XMLWHITESPACE_H_
#define XMLWHITESPACE_H_

#include <zorbatypes/xqpstring.h>

namespace zorba
{

typedef enum {
    WS_PRESERVE,
    WS_REPLACE,
    WS_COLLAPSE,
    WS_UNSPECIFIED
} XmlWhitespace_t;

/*
 * doesn't change the string, returns the same str
 */ 
xqpString xmlWhitespacePreserve(xqpString str);

/*
 * replace each \n, \r and \t with one space char
 */ 
xqpString xmlWhitespaceReplace(xqpString str);

/*
 * same as xmlWhitespaceReplace(xqpString str) plus
 * it collapses multiple consecutive spaces to a single one, 
 * and leading and trailing spaces are removed
 */ 
xqpString xmlWhitespaceCollapse(xqpString str);

/*
 * Performs the specified action (preserve / replace / collapse)
 */ 
xqpString xmlWhitespaceCollapse(xqpString str, XmlWhitespace_t wsct);

} // end xqp namespace
#endif /*XMLWHITESPACE_H_*/
