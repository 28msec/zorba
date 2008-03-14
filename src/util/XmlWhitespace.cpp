#include "XmlWhitespace.h"

namespace zorba
{

xqpString xmlWhitespacePreserve(xqpString v)
{
    return v;
}

xqpString xmlWhitespaceReplace(xqpString v)
{
    return v.translate(xqpString("\n\r\t"), xqpString("   "));
}

xqpString xmlWhitespaceCollapse(xqpString v)
{
    return v.normalizeSpace();
}

xqpString xmlWhitespaceCollapse(xqpString v, XmlWhitespace_t wsr)
{
    switch( wsr )
    {
    case WS_PRESERVE:
    case WS_UNSPECIFIED:
        return xmlWhitespacePreserve(v);
        break;

    case WS_COLLAPSE:
        return xmlWhitespaceCollapse(v);

    case WS_REPLACE:
        return xmlWhitespaceReplace(v);
    }
}

} // end xqp namespace
