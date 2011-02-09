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
#include "csv.h"
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <vector>
#include <iostream>
#include <limits.h>
#include <string.h>

#include <zorba/zorba.h>
#include <zorba/store_consts.h>
#include <zorba/stateless_function.h>
#include <zorba/item_factory.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/empty_sequence.h>
#include <zorba/file.h>

namespace zorba{
String encodeStringToQNameString(std::string &str);
unsigned int utf8_sequence_length(const char* lead_it);
}

namespace zorba {  namespace csv {

ItemFactory* CSVModule::theFactory = 0;

CSVModule::CSVModule()
{
  lParseFunc = NULL;
  lSerializeFunc = NULL;
}

StatelessExternalFunction*
CSVModule::getExternalFunction(const zorba::String &aLocalname)
{
  if (1 == 0) {
  }
  else if (aLocalname.equals("parse-internal")) {
    lParseFunc = new CSVParseFunction(this);
    return lParseFunc;
  }
  else if (aLocalname.equals("serialize-internal")) {
    lSerializeFunc = new CSVSerializeFunction(this);
    return lSerializeFunc;
  }
  return NULL;
}

void
CSVModule::destroy()
{
  if (!dynamic_cast<CSVModule*>(this)) {
    return;
  }
  delete this;
}

bool compareItemQName(Item item, const char *localname, const char *ns)
{
  int node_kind = item.getNodeKind();
  if(node_kind != store::StoreConsts::elementNode)
    return false;
  Item node_name;
  item.getNodeName(node_name);
  String  item_namespace = node_name.getNamespace();
  if(ns && ns[0] && !item_namespace.byteEqual(ns, (unsigned int)strlen(ns)))
  {
    return false;
  }
  String  item_name = node_name.getLocalName();
  if(!item_name.byteEqual(localname, (unsigned int)strlen(localname)))
  {
    return false;
  }
  return true;
}

bool getChild(zorba::Iterator_t children, const char *localname, const char *ns, 
                           zorba::Item &child_item);
bool getChild(zorba::Item &lItem, const char *localname, const char *ns, 
                           zorba::Item &child_item)
{
  Iterator_t    children;
  children = lItem.getChildren();
  children->open();
  bool retval = getChild(children, localname, ns, child_item);
  children->close();
  return retval;
}

bool getChild(zorba::Iterator_t children, const char *localname, const char *ns, 
                           zorba::Item &child_item)
{
  while(children->next(child_item))
  {
    if(child_item.getNodeKind() != store::StoreConsts::elementNode)
      continue;
    Item    child_name;
    child_item.getNodeName(child_name);
    String  item_namespace = child_name.getNamespace();
    if(!item_namespace.byteEqual(ns, (unsigned int)strlen(ns)))
    {
      continue;//next child
    }
    String  item_name = child_name.getLocalName();
    if(!item_name.byteEqual(localname, (unsigned int)strlen(localname)))
    {
      continue;//next child
    }
    return true;
  }
  return false;
}

bool getAttribute(Item element, const char *lookup_name, String &attr_value)
{
  Iterator_t attrs;
  attrs = element.getAttributes();
  attrs->open();
  Item attr;
  while(attrs->next(attr))
  {
    Item attr_name;
    attr.getNodeName(attr_name);
    String attr_localname;
    attr_localname = attr_name.getLocalName();
    if(!strcmp(attr_localname.c_str(), lookup_name))
    {
      attr_value = attr.getStringValue();
      return true;
    }
  }
  attrs->close();
  return false;
}

void addIndentation(Item parent, unsigned int indent_level,
                    ItemFactory *item_factory)
{
  return;
/*
  if(indent_level > 100)
    indent_level = 100;
  char ws[110];
  ws[0] = '\n';
  memset(ws+1, ' ', indent_level);
  ws[indent_level+1] = 0;
  item_factory->createTextNode(parent, ws);
*/
}

///////////////////////////////////////////////////////////////////////////

/****************************************
  CSV to XML convertor
**************************************/
CSVOptions::CSVOptions()
{
  separator = ",";
  quote_char = "\"";//double quotes
  quote_escape = "\"\"";//double double quotes
  first_row_is_header = 0;//not header
  last_subheader_row = 0;
  start_from_row = 1;
  last_row = 0;
  column_specified = false;
  add_last_void_columns = false;
  //row_name = "row";
  //column_name = "column";
  last_column_position_is_computed = false;
}

void CSVOptions::parse(zorba::Item options_node, ItemFactory *item_factory)
{
  String empty_string;
  row_qname = item_factory->createQName(empty_string, empty_string, "row");
  column_qname = item_factory->createQName(empty_string, empty_string, "column");
  
  if(!options_node.isNull())
  {
    if(!compareItemQName(options_node, "options", ""))
    {
      std::stringstream lErrorMessage;
      Item options_qname;
      options_node.getNodeName(options_qname);
      lErrorMessage << "Options field must be of element options instead of " << options_qname.getStringValue();
      Item errWrongParamQName;
      String errNS("http://www.zorba-xquery.com/modules/csv");
      String errName("WrongParam");
      errWrongParamQName = item_factory->createQName(errNS, errName);
      String errDescription(lErrorMessage.str());
      ExternalFunctionData::error(errWrongParamQName, errDescription);
    }
    zorba::Item   xmlnode_item;
    if(getChild(options_node, "xml-nodes", "", xmlnode_item))
    {
      //the first child is the row name (if it exists)
      //then the first child of the first child is the column name (if it exists)
      Iterator_t    children;
      children = xmlnode_item.getChildren();
      children->open();
      Item row_item;
      while(children->next(row_item))
      {
        int column_kind = row_item.getNodeKind();
        if(column_kind != store::StoreConsts::elementNode)
          continue;
        row_item.getNodeName(row_qname);
        Iterator_t    children;
        children = row_item.getChildren();
        children->open();
        Item column_item;
        while(children->next(column_item))
        {
          int column_kind = column_item.getNodeKind();
          if(column_kind != store::StoreConsts::elementNode)
            continue;
          column_item.getNodeName(column_qname);
          column_specified = true;
          break;
        }
        children->close();
        break;
      }
      children->close();
    }
    zorba::Item   columns_item;
    if(getChild(options_node, "column-widths", "", columns_item))
    {
      bool align_right = false;
      int last_pos = 1;
      column_positions.push_back(1);

      String attr_value;
      if(getAttribute(columns_item, "align", attr_value))
      {
        if(attr_value.byteEqual("right", 5))
          align_right = true;
      }
      Iterator_t    children;
      children = columns_item.getChildren();
      children->open();
      Item column_item;
      while(children->next(column_item))
      {
        if(compareItemQName(column_item, "column-width", ""))
        {
          String column_text = column_item.getStringValue();
          const char *column_str = column_text.c_str();
          while(*column_str && isascii(*column_str) && isspace(*column_str))
            column_str++;
          unsigned int width = abs(atoi(column_str));
          last_pos += width;
          column_positions.push_back(last_pos);
          if(getAttribute(column_item, "align", attr_value))
          {
            if(attr_value.byteEqual("right", 5))
              aligns.push_back(true);
            else
              aligns.push_back(false);
          }
          else
            aligns.push_back(align_right);
        }
      }
      children->close();
      last_column_position_is_computed = true;
    }
    else if(getChild(options_node, "column-positions", "", columns_item))
    {
      bool align_right = false;
      String attr_value;
      if(getAttribute(columns_item, "align", attr_value))
      {
        if(attr_value.byteEqual("right", 5))
          align_right = true;
      }
      Iterator_t    children;
      children = columns_item.getChildren();
      children->open();
      Item column_item;
      while(children->next(column_item))
      {
        if(compareItemQName(column_item, "column-position", ""))
        {
          String column_text = column_item.getStringValue();
          const char *column_str = column_text.c_str();
          while(*column_str && isascii(*column_str) && isspace(*column_str))
            column_str++;
          unsigned int position = abs(atoi(column_str));
          if((column_positions.size() == 0) && position > 1)
            column_positions.push_back(1);
          column_positions.push_back(position);
          if(getAttribute(column_item, "align", attr_value))
          {
            if(attr_value.byteEqual("right", 5))
              aligns.push_back(true);
            else
              aligns.push_back(false);
          }
          else
            aligns.push_back(align_right);
        }
      }
      children->close();
    }
    else if(getChild(options_node, "csv", "", columns_item))
    {
      String attr_value;
      if(getAttribute(columns_item, "separator", attr_value))
      {
        separator = attr_value.c_str();
      }
      if(getAttribute(columns_item, "quote-char", attr_value))
      {
        quote_char = attr_value.c_str();
      }
      if(getAttribute(columns_item, "quote-escape", attr_value))
      {
        quote_escape= attr_value.c_str();
      }
    }
    
    Item first_header_item;
    if(getChild(options_node, "first-row-is-header", "", first_header_item))
    {
      first_row_is_header = 1;
      String attr_value;
      if(getAttribute(first_header_item, "line", attr_value))
      {
        const char *attr_str = attr_value.c_str();
        while(*attr_str && isascii(*attr_str) && isspace(*attr_str))
          attr_str++;
        int lineval = atoi(attr_str);
        if(lineval > 0)
          first_row_is_header = lineval;
        const char *subheader = strchr(attr_str, '-');
        if(subheader && *subheader)
        {
          subheader++;
          while(*subheader && isascii(*subheader) && isspace(*subheader))
            subheader++;
          last_subheader_row = atoi(subheader);
          if(last_subheader_row <= first_row_is_header)
            last_subheader_row = 0;
        }
      }
    }
    Item start_row_item;
    if(getChild(options_node, "start-from-row", "", start_row_item))
    {
      String attr_value;
      if(getAttribute(start_row_item, "line", attr_value))
      {
        const char *attr_str = attr_value.c_str();
        while(*attr_str && isascii(*attr_str) && isspace(*attr_str))
          attr_str++;
        int lineval = atoi(attr_str);
        if(lineval > 0)
          start_from_row = lineval;
        if(first_row_is_header > start_from_row)
          first_row_is_header = start_from_row;
        const char *last = strchr(attr_str, '-');
        if(last && *last)
        {
          last++;
          while(*last && isascii(*last) && isspace(*last))
            last++;
          last_row = atoi(last);
          if(last_row <= start_from_row)
            last_row = 0;
        }
      }
    }
    Item add_last_col_item;
    if(getChild(options_node, "add-last-void-columns", "", add_last_col_item))
      add_last_void_columns = true;
  }
  
  separator_size = (unsigned int)separator.length();
  quote_char_size = (unsigned int)quote_char.length();
  quote_escape_size = (unsigned int)quote_escape.length();
  if(!quote_char_size)
    quote_escape_size = 0;
}

void CSVParseFunction::CSVItemSequence::init(Item string_item,
                                        ItemFactory   *item_factory)
{
	if ( string_item.isStreamable() ) {
    unsigned int max_len = csv_options.separator_size;
    if(max_len < csv_options.quote_char_size)
      max_len = csv_options.quote_char_size;
    if(max_len < csv_options.quote_escape_size)
      max_len = csv_options.quote_escape_size;
		input_stream = new StreamWrapper(string_item, max_len);
	} else {
    input_stream = new CharPtrStream(string_item);
	}
  this->item_factory = item_factory;
  line_index = 1;
}

void CSVParseFunction::CSVItemSequence::rtrim(std::string &field)
{
  const char *cstr = field.c_str();
  size_t len = field.length();
  const char *endstr = cstr + len-1;
  while((endstr > cstr) && isascii(*endstr) && isspace(*endstr))
  {
    len--;
    endstr--;
  }
  field.resize(len);
}

bool CSVParseFunction::CSVItemSequence::read_line(std::vector<std::string>& line) //OUT
{
  if(!csv_options.column_positions.size())
  {
    return csv_read_line(line);
  }
  else
  {
    return txt_read_line(line);
  }
}

bool CSVParseFunction::CSVItemSequence::csv_read_line(std::vector<std::string>& line) //OUT
{
  //line.clear();
  //read all fields until new line
  //beware of quotes and quote escapes
  
  bool  is_empty_line = true;
  bool  is_within_quotes = false;
  line.resize(1);
  std::string    *field = &line.back();
  field->reserve(100);
  while(!input_stream->is_end())
  {
    if(!is_within_quotes && input_stream->compare(csv_options.separator))
    {
      line.resize(line.size()+1);
      field = &line.back();
      field->reserve(100);
      input_stream->skip(csv_options.separator_size);
    }
    else if((csv_options.quote_escape_size > 1) && input_stream->compare(csv_options.quote_escape))
    {
      field->append(csv_options.quote_char);
      input_stream->skip(csv_options.quote_escape_size);
    }
    else if(csv_options.quote_char_size && input_stream->compare(csv_options.quote_char))
    {
      is_within_quotes = !is_within_quotes;
      input_stream->skip(csv_options.quote_char_size);
    }
    else if(!is_within_quotes && ((*input_stream->get_utf8_seq() == '\n') || (*input_stream->get_utf8_seq() == '\r')))
    {
      while(!input_stream->is_end()  && (((*input_stream->get_utf8_seq()) == '\r') || ((*input_stream->get_utf8_seq()) == '\n')))
      {
        input_stream->skip(1);
      }
      break;
    }
    else
    {
      unsigned int seq_len = input_stream->get_utf8_sequence_length();
      field->append(input_stream->get_utf8_seq(), seq_len);
      input_stream->skip(seq_len);
    }
    is_empty_line = false;
  }

  //if(field->empty())
  //  line.resize(line.size()-1);
  return !is_empty_line;
}

bool   CSVParseFunction::CSVItemSequence::txt_read_line(std::vector<std::string>   &line)//OUT
{
  bool  is_empty_line = true;
  std::string    *field = NULL;
  //read all fields until new line
  
  unsigned int   pos = 1;
  unsigned int   column = 0;
  size_t         column_positions_size = csv_options.column_positions.size();
  while(!input_stream->is_end())
  {
    const char *curent_char = input_stream->get_utf8_seq();
    if((column < column_positions_size) && 
      (pos >= csv_options.column_positions[column]))
    {
      if((column == (column_positions_size-1)) && csv_options.last_column_position_is_computed)
      {
        //premature finish of the line
        while(!input_stream->is_end()  && ((*curent_char != '\r') && (*curent_char != '\n')))
        {
          input_stream->skip(1);
          curent_char = input_stream->get_utf8_seq();
        }
        while(!input_stream->is_end()  && ((*curent_char == '\r') || (*curent_char == '\n')))
        {
          input_stream->skip(1);
          curent_char = input_stream->get_utf8_seq();
        }
        break;
      }
      if(field)
        rtrim(*field);
      line.resize(line.size()+1);
      field = &line.back();
      field->reserve(100);

      column++;

    }
    
    if((*curent_char == '\n') || (*curent_char == '\r'))
    {
      while(!input_stream->is_end()  && ((*curent_char == '\r') || (*curent_char == '\n')))
      {
        input_stream->skip(1);
        curent_char = input_stream->get_utf8_seq();
      }
      break;
    }
    else if(field && !field->length() && ((*curent_char == ' ') || (*curent_char == '\t')))
    {
      //ignore padding whitespace
      input_stream->skip(1);
      pos++;
    }
    else
    {
      unsigned int seq_len = input_stream->get_utf8_sequence_length();
      if(field)
        field->append(curent_char, seq_len);
      input_stream->skip(seq_len);
      pos++;
      is_empty_line = false;
    }
  }

  if(field)
    rtrim(*field);
  //if(field->empty())
  //  line.resize(line.size()-1);
  return !is_empty_line;
}

void CSVParseFunction::CSVItemSequence::buildHeader(std::vector<std::vector<std::string> > &headers)
{
  HeaderNode* header_node;
  header_qnames.resize(headers.at(0).size());  
  for(unsigned int i=0;i<headers.size();i++)
  {
    std::vector<std::string> &line = headers.at(i);
    for(unsigned int j=0;j<line.size();j++)
    {
      std::string &header_name = line.at(j);
      rtrim(header_name);
      if(!header_name.empty())
      {
        header_node = new HeaderNode;
        header_node->level = i;
        header_node->start_pos = j;
        String encoded_localname = encodeStringToQNameString(header_name);
        if(csv_options.column_specified)
          header_node->name = item_factory->createQName( csv_options.column_qname.getNamespace().c_str(),
                                          csv_options.column_qname.getPrefix().c_str(),
                                          encoded_localname);
        else
          header_node->name = item_factory->createQName( csv_options.row_qname.getNamespace().c_str(),
                                          csv_options.row_qname.getPrefix().c_str(),
                                          encoded_localname);
        if(header_qnames[j] != NULL)
        {
          header_node->parent = header_qnames[j];
          header_qnames[j]->children.push_back(header_node);
        }
        else if(i && j && (header_qnames[j-1] != NULL))
        {
          if(header_qnames[j-1]->level == i)
          {
            if(header_qnames[j-1]->parent != NULL)
            {
              header_node->parent = header_qnames[j-1]->parent;
              header_qnames[j-1]->parent->children.push_back(header_node);
            }
          }
          else
          {
            header_node->parent = header_qnames[j-1];
            header_qnames[j-1]->children.push_back(header_node);
          }
        }
        header_qnames[j] = header_node;
      }
    }
  }

  //now fill in the empty named columns
  for(unsigned int i=0;i<header_qnames.size();i++)
  {
    if(header_qnames[i] == NULL)
    {
      char column_name[100];
      sprintf(column_name, "column%d", i+1);
      header_node = new HeaderNode;
      header_node->level = i;
      String encoded_localname = column_name;
      if(csv_options.column_specified)
        header_node->name = item_factory->createQName( csv_options.column_qname.getNamespace().c_str(),
                                        csv_options.column_qname.getPrefix().c_str(),
                                        encoded_localname);
      else
        header_node->name = item_factory->createQName( csv_options.row_qname.getNamespace().c_str(),
                                        csv_options.row_qname.getPrefix().c_str(),
                                        encoded_localname);
      header_qnames[i] = header_node;
    }
  }
}

bool CSVParseFunction::CSVItemSequence::buildNodeTree(zorba::Item parent, 
                                                      HeaderNode *current, 
                                                      //std::vector<std::string>  &line,
                                                      unsigned int &line_pos
                                                      //unsigned int indent_level,
                                                      //zorba::Item item_type,
                                                      //std::vector<std::pair<String, String> >   &ns_binding
                                                      )
{
  zorba::Item   fieldNode;
  //zorba::Item   textNode;

  if(!csv_options.add_last_void_columns && (line_pos >= line.size()))
    return false;
//  addIndentation(parent, indent_level, item_factory);

  fieldNode = item_factory->createElementNode(parent, current->name, item_type, false, false, ns_binding);
  
  if(current->children.size())
  {
    std::vector<HeaderNode*>::iterator children_it;
    for(children_it = current->children.begin(); children_it != current->children.end(); children_it++)
    {
      while((*children_it)->start_pos > line_pos)
      {
        if(line_pos < line.size() && !line[line_pos].empty())
        {
          item_factory->createTextNode(fieldNode, line[line_pos]);
        }
        line_pos++;
      }
      buildNodeTree(fieldNode, (*children_it), line_pos);
    }
//    addIndentation(fieldNode, indent_level, item_factory);
  }
  else
  {
    if(line_pos < line.size() && !line[line_pos].empty())
      item_factory->createTextNode(fieldNode, line[line_pos]);
    line_pos++;
  }
  return true;
}

CSVParseFunction::CSVItemSequence::CSVItemSequence()
{
  is_open = false;
  open_count = 0;
}

void CSVParseFunction::CSVItemSequence::open()
{
  is_open = true;
  if(open_count && !input_stream->reset())
  {
    throw zorba::ExternalFunctionData::createZorbaException(XQP0019_INTERNAL_ERROR,
      "Cannot reset input stream for CSVParseFunction for second iterator open", __FILE__, __LINE__);  
  }
  line_index = 1;
  open_count++;

  ns_binding.clear();
  if(!csv_options.row_qname.getNamespace().empty())
  {
    ns_binding.push_back(std::pair<String, String>(csv_options.row_qname.getPrefix().c_str(), 
                                                 csv_options.row_qname.getNamespace().c_str()));
  }
  item_type = item_factory->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
}

void CSVParseFunction::CSVItemSequence::close()
{
  is_open = false;
}

bool CSVParseFunction::CSVItemSequence::isOpen() const
{
  return is_open;
}

bool CSVParseFunction::CSVItemSequence::next(Item& result)
{
  if(!is_open)
  {
    throw zorba::ExternalFunctionData::createZorbaException(XQP0019_INTERNAL_ERROR,
      "CSVParseFunction::CSVItemSequence Iterator consumed without open", __FILE__, __LINE__);  
  }
  if(csv_options.first_row_is_header)
  {
    std::vector<std::vector<std::string> > headers;
    headers.resize(1);
    std::vector<std::string> &line = headers.back();
    while(line_index <= csv_options.first_row_is_header)
    {
      line.clear();
      if(!read_line(line))
        return false;
      line_index++;
    }
    if(csv_options.last_subheader_row)
    {
      do
      {
        headers.resize(headers.size()+1);
        std::vector<std::string> &line = headers.back();
        if(!read_line(line))
          return false;
        line_index++;
      }
      while(line_index <= csv_options.last_subheader_row);
    }

    buildHeader(headers);
    csv_options.first_row_is_header = 0;
  }

  if(csv_options.last_row && (line_index > csv_options.last_row))
    return false;

  //now read everything else
  do
  {
    line.clear();
    if(!read_line(line))
      return false;
    line_index++;
  }
  while(line_index <= csv_options.start_from_row);


  result = item_factory->createElementNode(null_parent, csv_options.row_qname, item_type, false, false, ns_binding);

  if(header_qnames.size())
  {
    unsigned int i;
    unsigned int line_pos = 0;
    HeaderNode *prev_parent = NULL;
    for(i=0;i<header_qnames.size();i++)
    {
      HeaderNode *header = header_qnames[i];
      HeaderNode *header_parent = header;
      while(header_parent->parent)
        header_parent = header_parent->parent;
      if(header_parent == prev_parent)
        continue;
    
      if(!buildNodeTree(result, header_parent, line_pos))
        break;
      prev_parent = header_parent;
    }
  }
  else
  {
    unsigned int i;
    for(i = 0; i < line.size(); i++)
    {
      zorba::Item   fieldNode;
      //zorba::Item   textNode;

      addIndentation(result, 2, item_factory);

      fieldNode = item_factory->createElementNode(result, csv_options.column_qname, item_type, false, false, ns_binding);

      if(!line[i].empty())
        item_factory->createTextNode(fieldNode, line[i]);
    }
  }

//-  if(line.size())
//-    item_factory->createTextNode(result, "\n");

  return true;
}

zorba::ItemSequence_t
CSVParseFunction::evaluate(const Arguments_t& args,
         const zorba::StaticContext* sctx,
         const zorba::DynamicContext* dctx) const
{
  Item string_item;
  Iterator_t arg0_iter = args[0]->getIterator();
  arg0_iter->open();
  if (!arg0_iter->next(string_item)) 
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as first parameter";
    Item errWrongParamQName;
    String errNS("http://www.zorba-xquery.com/modules/csv");
    String errName("WrongParam");
    errWrongParamQName = theModule->getItemFactory()->createQName(errNS, errName);
    String errDescription(lErrorMessage.str());
    ExternalFunctionData::error(errWrongParamQName, errDescription);
  }
  arg0_iter->close();
 
  Item options_item;
  Iterator_t arg1_iter = args[1]->getIterator();
  arg1_iter->open();
  arg1_iter->next(options_item);
  arg1_iter->close();
  
  CSVItemSequence *out_sequence = new CSVItemSequence();
  out_sequence->csv_options.parse(options_item, theModule->getItemFactory());
  out_sequence->init(string_item, theModule->getItemFactory());

  //out_sequence->baseUri = sctx->get_base_uri();
  return ItemSequence_t(out_sequence);
}


//////////////////////////////////////////////////////////////////////////////////
//////////////////serialize
CSVSerializeFunction::StringStreamSequence::StringStreamSequence(ItemSequence* input) : 
                                                                                        input_iter(input->getIterator()),
                                                                                        is(this)
{
//  input_nodes = input;
  line_index = 0;
  has_next = true;
  is_open = false;
  open_count = 0;
  input_iter->open();
}

void CSVSerializeFunction::StringStreamSequence::csv_get_headers(  Item node, 
                                             unsigned int level,
                                             unsigned int &position)
{
  Iterator_t   children = node.getChildren();
  Item         column;

  children->open();
  while(children->next(column))
  {
    int column_kind = column.getNodeKind();
    if((column_kind != store::StoreConsts::elementNode) &&
      (column_kind != store::StoreConsts::textNode))
      continue;
    if(column_kind == store::StoreConsts::elementNode)
    {
      if(headers.size() <= level)
        headers.resize(level+1);
      Item element_name;
      column.getNodeName(element_name);
      String column_name = element_name.getLocalName();
      std::vector<String> &header = headers.at(level);
      if(header.size() < position)
        header.resize(position);
      header.push_back(column_name);
      unsigned int prev_position = position;
      csv_get_headers(column, level+1, position);
      if(prev_position == position)
        position++;
    }
    else if(column_kind == store::StoreConsts::textNode)
    {
      String text_string = column.getStringValue();
      String trimmed_text = text_string.trim();
      if(!trimmed_text.empty())
      {
        position++;
      }
    }
  }
  children->close();
}

void CSVSerializeFunction::StringStreamSequence::csv_write_line(
    Item node, 
    std::vector<String>& line,
    unsigned int level)
{
  //iterate through all children of the node and get the string values
  Iterator_t   children = node.getChildren();
  Item       store_column;

  children->open();
  while(children->next(store_column))
  {
    int column_kind = store_column.getNodeKind();
    if((column_kind != store::StoreConsts::elementNode) &&
      (column_kind != store::StoreConsts::textNode))
      continue;
    if(!headers.size())
    {
      if(column_kind != store::StoreConsts::elementNode)
        continue;
      line.push_back(store_column.getStringValue());
    }
    else
    {
      std::vector<String> &header = headers.at(level);
      if(column_kind == store::StoreConsts::elementNode)
      {
        Item element_name;
        store_column.getNodeName(element_name);
        String column_name = element_name.getLocalName();
        for(size_t i=line.size();i<header.size();i++)
        {
          if(header.at(i) == column_name)
          {
            line.resize(i);
            if(level == (headers.size()-1))
            {
              line.push_back(store_column.getStringValue());
            }
            else
            {
              csv_write_line(store_column, line, level+1);
            }
            if(line.size() >= header.size())
              return;
            break;
          }
          else if((i+1)<header.size() && level)
          {
            unsigned int l;
            for(l=0;l<level;l++)
              if(!headers.at(l)[i+1].empty())
                break;
            if(l<level)
              break;
          }
        }
      }
      else if(column_kind == store::StoreConsts::textNode)
      {
        unsigned int l;
        for(l=level;l<headers.size();l++)
          if(!headers.at(l)[line.size()].empty())
            break;
        if(l<headers.size())
          continue;//not a place for text
        if(line.size() >= header.size())
          return;
        String text_string = store_column.getStringValue();
        String trimmed_text = text_string.trim();
        if(!trimmed_text.empty())
        {
          line.push_back(trimmed_text);
        }
      }
    }
  }
  children->close();
}


bool CSVSerializeFunction::StringStreamSequence::needs_quote(String &field)
{
//  if((field.indexOf(csv_options.separator.c_str()) >= 0) || 
//     (csv_options.quote_char_size && field.indexOf(csv_options.quote_char.c_str()) >= 0) ||
//     (field.indexOf("\n") >= 0) || (field.indexOf("\r") >= 0))
//    return true;
//  else
//    return false;
  const char *field_str = field.c_str();
  const char *separator_str = csv_options.separator.c_str();
  const char *quote_char_str = csv_options.quote_char_size ? csv_options.quote_char.c_str() : "";

  while(*field_str)
  {
    if((*field_str == '\n') || (*field_str == '\r'))
      return true;
    if((*field_str == *separator_str) && !strncmp(field_str, separator_str, csv_options.separator_size))
      return true;
    if((*field_str == *quote_char_str) && !strncmp(field_str, quote_char_str, csv_options.quote_char_size))
      return true;
    field_str++;
  }
  return false;
}

std::string CSVSerializeFunction::StringStreamSequence::csv_quote_field(
    String &field)
{
  const char *fieldstr = field.c_str();
  std::string   result;
  result.reserve(field.bytes() + 10);
  result.append(csv_options.quote_char);
  while(*fieldstr)
  {
    if(csv_options.quote_char_size && !strncmp(csv_options.quote_char.c_str(), fieldstr, csv_options.quote_char_size) )
    {
      result.append(csv_options.quote_escape);
      fieldstr += csv_options.quote_char_size;
    }
    else
    {
      unsigned int seqlen = utf8_sequence_length(fieldstr);
      result.append(fieldstr, seqlen);
      fieldstr += seqlen;
    }
  }
  result.append(csv_options.quote_char);
  return result;
}

void CSVSerializeFunction::StringStreamSequence::csv_write_line_to_string(std::vector<String> &line, 
                         std::string &result_string)
{
  std::vector<String>::iterator   line_it;
  size_t addlen = 1;
  for(line_it = line.begin(); line_it != line.end(); line_it++)
  {
    addlen += (*line_it).bytes() + csv_options.separator_size;
  }
  result_string.reserve(result_string.length() + addlen);

  for(line_it = line.begin(); line_it != line.end(); line_it++)
  {
    if(line_it != line.begin())
      result_string.append(csv_options.separator);
    if(needs_quote(*line_it))
    {
      result_string.append(csv_quote_field(*line_it));
    }
    else
      result_string.append((*line_it).c_str());
  }
  result_string.append("\n");
}


void CSVSerializeFunction::StringStreamSequence::txt_write_line_to_string(std::vector<String> &line, 
                              std::string &result_string)
{
  result_string.reserve(result_string.length() + csv_options.column_positions.back() + 1);

  if(csv_options.column_positions[0] > 1)
    result_string.append(csv_options.column_positions[0] - 1, ' ');

  unsigned int i;
  size_t column_positions_size = csv_options.column_positions.size();
  for(i=0;i<column_positions_size;i++)
  {
    if(i >= line.size())
      break;
    unsigned int    field_length = (unsigned int)line[i].length();
    unsigned int    column_length;
    if(i < (column_positions_size-1))
    {
      column_length = csv_options.column_positions[i+1] - csv_options.column_positions[i];
      if(field_length < column_length)
      {
        if(!csv_options.aligns[i])//align left
        {
          result_string.append(line[i].c_str());
          result_string.append(column_length - field_length, ' ');
        }
        else//align right
        {
          result_string.append(column_length - field_length, ' ');
          result_string.append(line[i].c_str());
        }
      }
      else if(field_length == column_length)
      {
        result_string.append(line[i].c_str());
      }
      else
      {
        result_string.append(line[i].c_str(), column_length);
      }
    }
    else if(!csv_options.last_column_position_is_computed)
    {
      result_string.append(line[i].c_str());
    }
  }
  result_string.append("\n");
}

void CSVSerializeFunction::StringStreamSequence::open()
{
  is_open = true;
//  input_iter->open();
  line_index = 1;
  if(open_count)
  {
    is.seekg(0);
    if(is.fail())
    {
      throw zorba::ExternalFunctionData::createZorbaException(XQP0019_INTERNAL_ERROR,
        "Cannot reset CSVSerialize streamable string item", __FILE__, __LINE__);  
    }
  }
  open_count++;
}

void CSVSerializeFunction::StringStreamSequence::close()
{
//  input_iter->close();
  is_open = false;
}

bool CSVSerializeFunction::StringStreamSequence::isOpen() const
{
  return is_open;
}

bool CSVSerializeFunction::StringStreamSequence::next( Item &result )
{
  if(!is_open)
  {
    throw zorba::ExternalFunctionData::createZorbaException(XQP0019_INTERNAL_ERROR,
      "Next called on CSVSerializeFunction::StringStreamSequence iterator that is not open", __FILE__, __LINE__);  
  }
  if(!has_next)
    return false;
  result = streamable_item;
  has_next = false;
  return true;
}


bool CSVSerializeFunction::StringStreamSequence::next(std::string &result_string)
{
  if(!input_iter->next(node_item))
    return false;

  if(csv_options.first_row_is_header > 0)
  {
    unsigned int position = 0;
    csv_get_headers(   node_item, 
                        0,
                        position);
    for(unsigned int i=0;i<headers.size();i++)
    {
      headers.at(i).resize(position);

      //now write the headers
      if(csv_options.column_positions.size() == 0)
      {
        csv_write_line_to_string(headers.at(i), 
                                  result_string);
      }
      else
      {
        txt_write_line_to_string(headers.at(i), 
                                  result_string);
      }
    }
    csv_options.first_row_is_header = 0;
  }
  line.clear();
  csv_write_line(node_item,
                      line, 0);

  //std::string line_string;
  if(csv_options.column_positions.size() == 0)
  {
    csv_write_line_to_string(line, 
                              result_string);
  }
  else
  {
    txt_write_line_to_string(line, 
                              result_string);
  }
  line_index++;
  return true;
}

bool CSVSerializeFunction::StringStreamSequence::reset()
{
  input_iter->close();
  input_iter->open();
  return true;
}
 
zorba::ItemSequence_t
CSVSerializeFunction::evaluate(const Arguments_t& args,
         const zorba::StaticContext* sctx,
         const zorba::DynamicContext* dctx) const
{
  
  Item options_item;
  Iterator_t  arg1_iter = args[1]->getIterator();
  arg1_iter->open();
  arg1_iter->next(options_item);
  arg1_iter->close();
  
  StringStreamSequence  *stream_sequence = new StringStreamSequence((ItemSequence*)args[0]);
  stream_sequence->csv_options.parse(options_item, theModule->getItemFactory());
  stream_sequence->streamable_item = theModule->getItemFactory()->createStreamableString(stream_sequence->is);

  return ItemSequence_t(stream_sequence);
}


}} /* namespace csv & zorba */


#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::csv::CSVModule();
}
