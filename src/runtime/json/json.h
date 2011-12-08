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
#ifndef ZORBA_JSONMODULE_JSON_H
#define ZORBA_JSONMODULE_JSON_H

#include <map>

#include <zorba/zorba.h>
#include <zorba/iterator.h>
#include <zorba/function.h>
#include <zorba/external_module.h>

#include "stringiterator_streambuf.h"

namespace zorba {
namespace jsonmodule {

///////////////////////////////////////////////////////////////////////////////

class JsonModule : public ExternalModule {
public:
  virtual ~JsonModule();

  static ItemFactory* getItemFactory();

  // inherited
  void destroy();
  ExternalFunction* getExternalFunction( String const& );
  String getURI() const;

protected:
  typedef std::map<String,ExternalFunction*> func_map_type;
  func_map_type func_map_;
};

///////////////////////////////////////////////////////////////////////////////

class JsonFunction : public ContextualExternalFunction {
public:
  JsonFunction( JsonModule const *module ) : module_( module ) { }
  ~JsonFunction();

  String getURI() const;

protected:
  zorba::String getOptionValue( zorba::Item &options,
                                char const *option_name ) const;

  JsonModule const *module_;
};

///////////////////////////////////////////////////////////////////////////////

class ParseFunction : public JsonFunction {
public:
  ParseFunction( JsonModule const *module ) : JsonFunction( module ) { }

  ItemSequence_t evaluate( ExternalFunction::Arguments_t const&,
                           StaticContext const*, DynamicContext const* ) const;

  String getLocalName() const;
};

///////////////////////////////////////////////////////////////////////////////

class SerializeFunction : public JsonFunction {
public:
  SerializeFunction( JsonModule const *module ) : JsonFunction( module ) { }

  virtual String getLocalName() const {
    return "serialize-internal";
  }

  virtual ItemSequence_t evaluate(const ExternalFunction::Arguments_t& args,
            const StaticContext* aSctxCtx,
            const DynamicContext* aDynCtx) const;

private:
  class StringStreamSequence :
    public ItemSequence, public Iterator, public StringIteratorStreamBuf {
  public:
    std::istream* is;
    String        theMapping;
    ItemFactory*  theFactory;
    Item          streamable_item;
  public:
    StringStreamSequence(ItemSequence* input);
    virtual ~StringStreamSequence() {}

    //for Iterator
    virtual void open();
    virtual void close();
    virtual bool isOpen() const;
    virtual bool next( Item &result );

    //for ItemSequence
    Iterator_t getIterator() {return this;}

    //for StringIteratorStreamBuf
    virtual bool next(std::string &next_string);
    virtual bool reset();

    static void
    releaseStream(std::istream* stream) { delete stream; }

  private:
    Iterator_t     input_iter;
    std::vector<std::vector<String> > headers;
    int line_index;
    bool has_next;
    bool is_open;
    int  open_count;

    std::vector<String> line;
    Item node_item;
  };
};

///////////////////////////////////////////////////////////////////////////////

} // namespace jsonmodule
} // namespace zorba

#endif /* ZORBA_JSONMODULE_JSON_H */
/* vim:set et sw=2 ts=2: */
