/*
 * Copyright 2006-2011 The FLWOR Foundation.
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

#ifndef ZORBA_STORE_JSON_VISITOR_H
#define ZORBA_STORE_JSON_VISITOR_H

#include "common/common.h"
#include "shared_types.h"

namespace zorba
{

namespace simplestore
{

namespace json
{

/******************************************************************************

*******************************************************************************/
class JSONVisitor
{
public:
  JSONVisitor() { }

  virtual ~JSONVisitor() {}

  virtual void begin( const JSONObject* ) = 0;
  virtual void end( const JSONObject* ) = 0;

  virtual void begin( const JSONArray* ) = 0;
  virtual void end( const JSONArray* ) = 0;

  virtual void begin( const JSONObjectPair* ) = 0;
  virtual void end( const JSONObjectPair* ) = 0;

  virtual void begin( const JSONArrayPair* ) = 0;
  virtual void end( const JSONArrayPair* ) = 0;
};


/******************************************************************************

*******************************************************************************/
class JSONPrinterVisitor : public JSONVisitor
{
protected:
  std::ostream& os;
  bool theIndent;
  std::string theEol;
  uint32_t theNumIndent;

public:
  JSONPrinterVisitor(
      std::ostream& o,
      bool aIndent = true )
    : os(o),
      theIndent(aIndent),
#ifdef WIN32
      theEol("\c\r")
#else
      theEol("\n")
#endif
      , theNumIndent(0)
  { }

  virtual ~JSONPrinterVisitor() {}

  virtual void begin( const JSONObject* );
  virtual void end( const JSONObject* );

  virtual void begin( const JSONArray* );
  virtual void end( const JSONArray* );

  virtual void begin( const JSONObjectPair* );
  virtual void end( const JSONObjectPair* );

  virtual void begin( const JSONArrayPair* );
  virtual void end( const JSONArrayPair* );

protected:
  virtual void print( const zorba::store::Item* );

  void inc()
  {
    if (theIndent)
    {
      theNumIndent += 2;
    }
  }

  void dec()
  {
    if (theIndent)
    {
      theNumIndent -= 2;
    }
  }

  void indent()
  {
    if (theIndent)
    {
      for (uint32_t i = 0; i < theNumIndent; ++i)
      {
        os << " ";
      }
      
    }
  }

  void eol()
  {
    if (theIndent)
    {
      os << theEol;
    }
  }
};

} // namespace json
} // namespace simplestore
} // namespace zorba
#endif /* ZORBA_STORE_JSON_VISITOR_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
