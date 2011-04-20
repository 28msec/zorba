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
#include <zorba/external_function.h>
#include <zorba/external_module.h>

#include "stringiterator_streambuf.h"

namespace zorba
{
  namespace jsonmodule
  {
//*****************************************************************************
//*****************************************************************************
    class JsonModule : public ExternalModule
    {
    private:
      static ItemFactory* theFactory;

    protected:
      class ltstr
      {
      public:
        bool operator()(const String& s1, const String& s2) const
        {
          return s1.compare(s2) < 0;
        }
      };

      typedef std::map<String, StatelessExternalFunction*, ltstr> FuncMap_t;

      FuncMap_t theFunctions;

    public:
      virtual ~JsonModule();

      virtual String
      getURI() const { return "http://www.zorba-xquery.com/modules/convertors/json"; }

      virtual StatelessExternalFunction*
      getExternalFunction(const String& aLocalname);

      virtual void
      destroy();

      static ItemFactory*
      getItemFactory()
      {
        if(!theFactory)
        {
          theFactory = Zorba::getInstance(0)->getItemFactory();
        }
        return theFactory;
      }
    };

//*****************************************************************************
//*****************************************************************************
    class JsonFunction : public NonePureStatelessExternalFunction
    {
    protected:
      const JsonModule* theModule;
      zorba::String getOptionValue(zorba::Item& aOptionsItem, const char* aOptionName) const;
    public:
      JsonFunction(const JsonModule* aModule)
      : theModule(aModule) {};

      ~JsonFunction() {};

      virtual String
      getURI() const { return theModule->getURI(); }

    };

//*****************************************************************************
//*****************************************************************************
    class ParseFunction : public JsonFunction
    {
    public:
      ParseFunction(const JsonModule* aModule);

      virtual String
      getLocalName() const { return "parse-internal"; }

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;
    };

    class SerializeFunction : public JsonFunction
    {
      class StringStreamSequence : public ItemSequence, public Iterator, public StringIteratorStreamBuf
      {
      private:
        Iterator_t     input_iter;
        std::vector<std::vector<String> > headers;
        int line_index;
        bool has_next;
        bool is_open;
        int  open_count;

        std::vector<String> line;
        Item node_item;
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
        destroyStream(std::istream& stream) { delete &stream; }

      };
    public:
      SerializeFunction(const JsonModule* aModule);

      virtual String
      getLocalName() const { return "serialize-internal"; }

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;
    };



  } /* namespace jsonmodule */
} /* namespace zorba */

#endif /* ZORBA_JSONMODULE_JSON_H */