/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
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
        
    default:
      assert (false); return v;
    }
}

} // end xqp namespace
