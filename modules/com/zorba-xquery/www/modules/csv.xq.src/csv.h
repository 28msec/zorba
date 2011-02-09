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
#ifndef ZORBA_PROCESSMODULE_CSV_H
#define ZORBA_PROCESSMODULE_CSV_H

#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include <zorba/external_function.h>
#include <zorba/smart_ptr.h>

#include "stream_wrapper.h"
#include "stringiterator_streambuf.h"

namespace zorba {
namespace csv {

/******************************************************************************
 *****************************************************************************/
class CSVModule : public ExternalModule
{
private:
  static ItemFactory* theFactory;
  StatelessExternalFunction* lParseFunc;
  StatelessExternalFunction* lSerializeFunc;
protected:
  class ltstr
  {
  public:
    bool operator()(const String& s1, const String& s2) const
    {
      return s1.compare(s2) < 0;
    }
  };

public:
  CSVModule();
  virtual ~CSVModule() {delete lParseFunc; delete lSerializeFunc;}

  virtual zorba::String getURI() const
  { return "http://www.zorba-xquery.com/modules/csv"; }

  virtual zorba::StatelessExternalFunction*
  getExternalFunction(const zorba::String &aLocalname);

  virtual void destroy();

  static ItemFactory* getItemFactory()
  {
    if(!theFactory)
    {
      theFactory = Zorba::getInstance(0)->getItemFactory();
    }

    return theFactory;
  }
};

/******************************************************************************
 *****************************************************************************/

class CSVOptions
{
public:
  std::string separator;
  unsigned int separator_size;
  std::string quote_char;
  unsigned int quote_char_size;
  std::string quote_escape;
  unsigned int quote_escape_size;

  std::vector<unsigned int> column_positions;
  std::vector<bool>         aligns;
  bool last_column_position_is_computed;
  
  unsigned int   first_row_is_header;
  unsigned int   last_subheader_row;
  unsigned int   start_from_row;//default 1
  unsigned int   last_row;//default 0
  bool           add_last_void_columns;
  Item   row_qname;
  bool   column_specified;
  Item   column_qname;

public:
  CSVOptions();

  void parse(zorba::Item options_node, ItemFactory *item_factory);
};


class CSVParseFunction : public NonePureStatelessExternalFunction
{
  class CSVItemSequence : public ItemSequence, public Iterator
  {
  private:
    ItemFactory   *item_factory;
    unsigned int line_index;
    SmartPtr<CharStreamBase>  input_stream;
    bool is_open;
    int open_count;

    std::vector<std::pair<String, String> >   ns_binding;
    Item null_parent;
    zorba::Item   item_type;
    std::vector<std::string>  line;

    class HeaderNode : public SmartObject
    {
    public:
      zorba::Item name;
      unsigned int level;
      unsigned int start_pos;
      SmartPtr<HeaderNode>  parent;
      std::vector<HeaderNode*> children;
    };
    std::vector<SmartPtr<HeaderNode> > header_qnames;
  public:
    CSVOptions  csv_options;

  public:
    CSVItemSequence();
    virtual ~CSVItemSequence() {}
    
    void init(Item string_item, ItemFactory   *item_factory);

    Iterator_t getIterator() {return this;}

    //Iterator interface
    virtual void open();
    virtual bool next(Item& aItem);
    virtual void close();
    virtual bool isOpen() const;
  private:
    void rtrim(std::string &field);

    bool read_line(std::vector<std::string>& line);
    bool csv_read_line(std::vector<std::string>& line);
    bool txt_read_line(std::vector<std::string>   &line);
    void buildHeader(std::vector<std::vector<std::string> > &headers);
    bool buildNodeTree(zorba::Item parent, 
                        HeaderNode *current, 
                        //std::vector<std::string>  &line,
                        unsigned int &line_pos
                        //unsigned int indent_level,
                        //zorba::Item item_type,
                        //std::vector<std::pair<String, String> >   &ns_binding
                        );

  };
public:
  CSVParseFunction(const CSVModule* aModule) : theModule(aModule) {}

  virtual ~CSVParseFunction() {};

  virtual zorba::String
  getLocalName() const { return "parse-internal"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;

  virtual String getURI() const
  {
    return theModule->getURI();
  }

protected:
  const CSVModule* theModule;
};


class CSVSerializeFunction : public NonePureStatelessExternalFunction
{
  class StringStreamSequence : public ItemSequence, public Iterator, public StringIteratorStreamBuf
  {
  private:
    //ItemSequence*  input_nodes;
    Iterator_t     input_iter;
    std::vector<std::vector<String> > headers;
    int line_index;
    bool has_next;
    bool is_open;
    int  open_count;

    std::vector<String> line;
    Item node_item;
  public:
    std::istream is;
    CSVOptions csv_options;
    Item streamable_item;
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
  private:
    void csv_get_headers(  Item node, 
                           unsigned int level,
                           unsigned int &position);
    void csv_write_line(
      Item node, 
      std::vector<String>& line,
      unsigned int level);
    bool needs_quote(String &field);
    std::string csv_quote_field(String &field);
    void csv_write_line_to_string(std::vector<String> &line,
                           std::string &result_string);
    void txt_write_line_to_string(std::vector<String> &line,
                                std::string &result_string);
  };
public:
  CSVSerializeFunction(const CSVModule* aModule) : theModule(aModule) {}

  virtual ~CSVSerializeFunction() {}

  virtual zorba::String
  getLocalName() const { return "serialize-internal"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;

  virtual String getURI() const
  {
    return theModule->getURI();
  }

private:

protected:
  const CSVModule* theModule;
};



} /* namespace csv */
} /* namespace zorba */

#endif // ZORBA_PROCESSMODULE_CSV_H
