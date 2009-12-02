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

#include "system/globalenv.h"

#include "util/converters/json_converter.h"

#include "context/static_context.h"

#include "runtime/convertors/convertors.h"

#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item_factory.h"

#include "runtime/convertors/convertors.h"
#include "zorbautils/checked_vector.h"
#include "types/root_typemanager.h"


namespace zorba {
bool
ZorbaJsonParseIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  xqp_string        error_log;
  bool              parseOK = true;
  store::Item_t     strItem;

  ZorbaJsonParseIteratorState *state;
  DEFAULT_STACK_INIT(ZorbaJsonParseIteratorState, state, planState);

  if( state->theBaseUri.empty() )
    state->theBaseUri = theSctx->final_baseuri();

  while (consumeNext(strItem, theChildren[0].getp(), planState))
  {
    if( strItem->getStringValue()->empty() )
      ZORBA_ERROR_LOC_PARAM(API0060_CONV_JSON_PARSE,
                            loc,
                            strItem->show(),
                            "The string representation of the value passed was empty.");

    parseOK = JSON_parse( strItem->getStringValue()->c_str(),
                          strItem->getStringValue()->bytes(),
                          result,
                          state->theBaseUri.getStore(),
                          error_log);

    if(parseOK && result &&
       result->isNode() &&
       result->getNodeKind () == store::StoreConsts::elementNode)
    {
      STACK_PUSH (true, state);
    }
    else
      ZORBA_ERROR_LOC_PARAM(API0060_CONV_JSON_PARSE,
                            loc,
                            strItem->getStringValue()->c_str(),
                            error_log.c_str());
  }

  STACK_END (state);
}

bool
ZorbaJsonSerializeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t     elemItem;
  xqpStringStore_t  str, error_log;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (consumeNext(elemItem, theChildren[0].getp(), planState))
  {
    if( !elemItem->isNode() ||
       elemItem->getNodeKind () != store::StoreConsts::elementNode)
      ZORBA_ERROR_LOC_PARAM(API0062_CONV_JSON_PARAM, loc, elemItem->getStringValue()->c_str() , "");
    else
    {
      if( !JSON_serialize(elemItem, str, error_log) )
        ZORBA_ERROR_LOC_PARAM(API0061_CONV_JSON_SERIALIZE, loc, elemItem->getStringValue()->c_str() , error_log);
      else
      {
        GENV_ITEMFACTORY->createString(result, str);
        STACK_PUSH (true, state);
      }
    }
  }

  STACK_END (state);
}

//JsonML
bool
ZorbaJsonMLParseIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  xqp_string        error_log;
  bool              parseOK = true;
  store::Item_t     strItem;

  ZorbaJsonMLParseIteratorState *state;
  DEFAULT_STACK_INIT(ZorbaJsonMLParseIteratorState, state, planState);

  if( state->theBaseUri.empty() )
    state->theBaseUri = theSctx->final_baseuri();

  while (consumeNext(strItem, theChildren[0].getp(), planState))
  {
    if( strItem->getStringValue()->empty() )
      ZORBA_ERROR_LOC_PARAM(API0063_CONV_JSON_ML_PARSE,
                            loc,
                            strItem->show(),
                            "The string representation of the value passed was empty.");

    parseOK = JSON_ML_parse(strItem->getStringValue()->c_str(),
                            strItem->getStringValue()->bytes(),
                            result,
                            state->theBaseUri.getStore(),
                            error_log);
    if(parseOK && result &&
       result->isNode() &&
       result->getNodeKind () == store::StoreConsts::elementNode)
      STACK_PUSH (true, state);
    else
      ZORBA_ERROR_LOC_PARAM(API0063_CONV_JSON_ML_PARSE,
                            loc,
                            strItem->getStringValue()->c_str(),
                            error_log.c_str());
  }

  STACK_END (state);
}

bool
ZorbaJsonMLSerializeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t     elemItem;
  xqpStringStore_t  str, error_log;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (consumeNext(elemItem, theChildren[0].getp(), planState))
  {
    if(!elemItem->isNode() ||
       elemItem->getNodeKind () != store::StoreConsts::elementNode)
      ZORBA_ERROR_LOC_PARAM(API0065_CONV_JSON_ML_PARAM,
                            loc,
                            elemItem->getStringValue()->c_str(),
                            "");
    else
    {
      if( !JSON_ML_serialize(elemItem, str, error_log) )
        ZORBA_ERROR_LOC_PARAM(API0064_CONV_JSON_ML_SERIALIZE,
                              loc,
                              elemItem->getStringValue()->c_str(),
                              error_log);
      else
      {
        GENV_ITEMFACTORY->createString(result, str);
        STACK_PUSH (true, state);
      }
    }
  }
  STACK_END (state);
}



/****************************************
  CSV to XML convertor
**************************************/

bool   csv_read_line(xqpString::codepoints_iterator &csv_it, //IN-OUT
                     checked_vector<uint32_t> &separator_cp, //IN
                     checked_vector<uint32_t> &quote_escape_cp, //IN
                     checked_vector<uint32_t> &quote_char_cp, //IN
                     checked_vector<xqpString>   &line)//OUT
{
  line.clear();
  //read all fields until new line
  //beware of quotes and quote escapes
  
  xqpString    field;
  bool  is_within_quotes = false;
  for(;!csv_it.is_end(); ++csv_it)
  {
    if(!is_within_quotes && ((*csv_it) == separator_cp[0]))
    {
      line.push_back(field);
      field = new xqpStringStore();
    }
    else if((*csv_it) == quote_escape_cp[0])
    {
      int matching_chars = csv_it.compare_cp(quote_escape_cp);
      if(matching_chars == quote_escape_cp.size())
      {
        field += quote_char_cp[0];
      }
      else
      {
        for(int i=0;i<matching_chars;i++) 
          field += quote_escape_cp[i];
      }
    }
    else if((*csv_it) == quote_char_cp[0])
    {
      is_within_quotes = !is_within_quotes;
    }
    else if(((*csv_it) == '\n') || ((*csv_it) == '\r'))
    {
      if(is_within_quotes)
        field += (*csv_it);
      else
      {
        xqpString::codepoints_iterator next_it = csv_it;
        ++next_it;
        if(!next_it.is_end()  && (((*next_it) == '\r') || ((*next_it) == '\n')))
        {
          csv_it = next_it;
        }
        break;
      }
    }
    else
    {
      field += (*csv_it);
    }
  }

  if(!field.empty())
    line.push_back(field);
  return line.size() > 00;
}


bool
ZorbaCSV2XMLIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t   rootNode;
  store::Item_t   typeName;
  typeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  store::NsBindings   ns_bindings;
  checked_vector<xqpString>  line;

  ZorbaCSV2XMLIteratorState *state;
  DEFAULT_STACK_INIT(ZorbaCSV2XMLIteratorState, state, planState);

  //read csv
  if(!consumeNext(result, theChildren[0].getp(), planState))
  {
    ZORBA_ERROR_LOC_PARAM(API0071_CONV_CSV2XML_PARAM,
                          loc,
                          "Missing param csv", "");
  }
  state->csv = result->getStringValue().getp();
  state->csv_it = state->csv.get_codepoints_iterator();
  //read first_row_is_header
  if(!consumeNext(result, theChildren[1].getp(), planState))
  {
    ZORBA_ERROR_LOC_PARAM(API0071_CONV_CSV2XML_PARAM,
                          loc,
                          "Missing param first_row_is_header", "");
  }
  state->first_row_is_header = result->getBooleanValue();
  //read separator
  {
    xqpString         separator;
    if(!consumeNext(result, theChildren[2].getp(), planState))
    {
      ZORBA_ERROR_LOC_PARAM(API0071_CONV_CSV2XML_PARAM,
                            loc,
                            "Missing param separator", "");
    }
    separator = result->getStringValue().getp();
    state->separator_cp = separator.getCodepoints();
  }
  {
    xqpString         quote_char;
    //read quote_char
    if(!consumeNext(result, theChildren[3].getp(), planState))
    {
      ZORBA_ERROR_LOC_PARAM(API0071_CONV_CSV2XML_PARAM,
                            loc,
                            "Missing param quote_escape", "");
    }
    quote_char = result->getStringValue().getp();
    state->quote_char_cp = quote_char.getCodepoints();
  }
  {
    //read quote_escape
    xqpString         quote_escape;
    if(!consumeNext(result, theChildren[4].getp(), planState))
    {
      ZORBA_ERROR_LOC_PARAM(API0071_CONV_CSV2XML_PARAM,
                            loc,
                            "Missing param quote_char", "");
    }
    quote_escape = result->getStringValue().getp();
    state->quote_escape_cp = quote_escape.getCodepoints();
  }
  //read root_node
  //if(!consumeNext(root_node_name, theChildren[5].getp(), planState))
  //{
  //  ZORBA_ERROR_LOC_PARAM(API0071_CONV_CSV2XML_PARAM,
  //                        loc,
  //                        "Missing param root_node", "");
  //}
  //read row_node
  if(!consumeNext(state->row_node_name, theChildren[5].getp(), planState))
  {
    ZORBA_ERROR_LOC_PARAM(API0071_CONV_CSV2XML_PARAM,
                          loc,
                          "Missing param row_node", "");
  }
  //read default_column_node
  if(!consumeNext(state->default_column_node_name, theChildren[6].getp(), planState))
  {
    ZORBA_ERROR_LOC_PARAM(API0071_CONV_CSV2XML_PARAM,
                          loc,
                          "Missing param default_column_node", "");
  }

  
  //create the doc node
  //store::Item_t   docNode;
  {
    xqpString  strBaseUri = theSctx->final_baseuri();//state->theCompilerCB->getStaticContext(
    state->baseUri = strBaseUri.getStore();
  }
  //xqpStringStore_t  docUri;
  //GENV_ITEMFACTORY->createDocumentNode(docNode, baseUri, docUri);

  //create the root node

  //GENV_ITEMFACTORY->createElementNode(rootNode, docNode.getp(), -1, root_node_name, typeName, false, false, ns_bindings, baseUri);

  if(state->first_row_is_header)
  {
    if(!csv_read_line(state->csv_it, state->separator_cp, state->quote_escape_cp, state->quote_char_cp, line))
    {
      ZORBA_ERROR_LOC_PARAM(API0071_CONV_CSV2XML_PARAM,
                          loc,
                          "CSV is empty", "");
    }
    checked_vector<xqpString>::iterator  line_it;
    for(line_it = line.begin(); line_it != line.end(); line_it++)
    {
      store::Item_t   qn;
      GENV_ITEMFACTORY->createQName(qn, state->default_column_node_name != NULL ? state->default_column_node_name->getNamespace()->c_str() : "", 
                                        state->default_column_node_name != NULL ? state->default_column_node_name->getPrefix()->c_str() : "",
                                        (*line_it).c_str());
      state->header_qnames.push_back(qn);
    }
  }

  //now read everything else
  while(csv_read_line(state->csv_it, state->separator_cp, state->quote_escape_cp, state->quote_char_cp, line))
  {
    {
      store::Item_t   row_node_name_copy = state->row_node_name;
      xqpStringStore_t    baseUri_copy = state->baseUri.getStore();
      GENV_ITEMFACTORY->createElementNode(result, rootNode.getp(), -1, row_node_name_copy, typeName, false, false, ns_bindings, baseUri_copy);
    }
    unsigned int i;
    for(i=0;i<line.size();i++)
    {
      store::Item_t   fieldNode;
      store::Item_t   textNode;
      store::Item_t   column_node_name;
      if(state->first_row_is_header)
      {
        if(i >= state->header_qnames.size())
        {
          ZORBA_ERROR_LOC(API0072_CONV_CSV2XML_TOO_MANY_FIELDS,
                              loc);
        }
        column_node_name = state->header_qnames[i];
        xqpStringStore_t    baseUri_copy = state->baseUri.getStore();
        GENV_ITEMFACTORY->createElementNode(fieldNode, result.getp(), -1, column_node_name, typeName, false, false, ns_bindings, baseUri_copy);
      }
      else
      {
        column_node_name = state->default_column_node_name;
        xqpStringStore_t    baseUri_copy = state->baseUri.getStore();
        GENV_ITEMFACTORY->createElementNode(fieldNode, result.getp(), -1, column_node_name, typeName, false, false, ns_bindings, baseUri_copy);
      }
      xqpStringStore_t  texttext = line[i].getStore();
      GENV_ITEMFACTORY->createTextNode(textNode, fieldNode, -1, texttext);
    }
    STACK_PUSH (true, state);
  }

  STACK_END (state);

}

} /* namespace zorba */
