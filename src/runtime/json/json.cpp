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

#include <cassert>
#include <sstream>

#include <zorba/diagnostic_list.h>
#include <zorba/empty_sequence.h>
#include <zorba/item.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/store_consts.h>
#include <zorba/user_exception.h>

#include "util/cxx_util.h"
#include "util/stl_util.h"

#include "json.h"

using namespace std;

namespace zorba {
namespace jsonmodule {

///////////////////////////////////////////////////////////////////////////////

JsonModule::~JsonModule() {
  FOR_EACH( func_map_type, i, func_map_ )
    delete i->second;
}

void JsonModule::destroy() {
  delete this;
}

ItemFactory* JsonModule::getItemFactory() {
  static ItemFactory *f;
  if ( !f )
    f = Zorba::getInstance( nullptr )->getItemFactory();
  return f;
}

ExternalFunction* JsonModule::getExternalFunction( String const &local_name ) {
  ExternalFunction *&f = func_map_[ local_name ];
  if ( !f ) {
    if ( local_name == "parse-internal" )
      f = new ParseFunction( this );
    else if ( local_name == "serialize-internal" )
      f = new SerializeFunction( this );
  }
  return f;
}

String JsonModule::getURI() const {
  return "http://www.zorba-xquery.com/modules/converters/json";
}

///////////////////////////////////////////////////////////////////////////////

JsonFunction::~JsonFunction() {
}

zorba::String JsonFunction::getOptionValue( zorba::Item& options,
                                            char const* ) const {
  zorba::Iterator_t lChildrenIt, lAttrIt;
  zorba::Item       lChild, lAttr, lNodeNameItem;
  bool              lCorrectChild = false;

  lChildrenIt = options.getChildren();
  lChildrenIt->open();
  while ( lChildrenIt->next( lChild ) ) {
    if ( lChild.getNodeKind() == store::StoreConsts::elementNode ) {
      lAttrIt = lChild.getAttributes();
      lAttrIt->open();
      while ( lAttrIt->next(lAttr) ) {
        if ( lAttr.getNodeKind() == store::StoreConsts::attributeNode ) {
          lAttr.getNodeName( lNodeNameItem );
          if ( !lCorrectChild && lNodeNameItem.getStringValue() == "name" )
            lCorrectChild = lAttr.getStringValue() == "mapping";
          else if ( lCorrectChild && lNodeNameItem.getStringValue() == "value" )
            return lAttr.getStringValue();
        }
      }
    }
  }
  lChildrenIt->close();
  return zorba::String("");
}

String JsonFunction::getURI() const {
  return module_->getURI();
}

///////////////////////////////////////////////////////////////////////////////

ItemSequence_t
ParseFunction::evaluate( ExternalFunction::Arguments_t const &aArgs,
                         StaticContext const *sctx,
                         DynamicContext const*dctx ) const {

  zorba::Item   lStringItem, lOptionsItem, lResItem;
  zorba::String lBaseUri, lJsonMapping, lOptionName("mapping");
  stringstream  lSs, lErrorLogSs;

  if ( aArgs.size() >= 1 ) {
    Iterator_t lArg0Iter = aArgs[0]->getIterator();
    lArg0Iter->open();
    lArg0Iter->next(lStringItem);
    lArg0Iter->close();
  }

  lBaseUri = sctx->getBaseURI();

  if ( aArgs.size() == 2 ) {
    Iterator_t lArg0Iter = aArgs[1]->getIterator();
    lArg0Iter->open();
    lArg0Iter->next(lOptionsItem);
    lArg0Iter->close();
  }

  lJsonMapping = getOptionValue(lOptionsItem, lOptionName.c_str());

  if ( lJsonMapping == "simple-json" ) {
    JSON_parse(lStringItem.getStringValue().c_str(), lSs, lErrorLogSs);
  }
  else { // if(lJsonMapping == "json-ml")
    assert(lJsonMapping == "json-ml"); // the schema makes sure that this is the case
    JSON_ML_parse( lStringItem.getStringValue().c_str(), lSs, lErrorLogSs );
  }

  if ( !lErrorLogSs.str().empty() ) {
    zorba::Item lError = module_->getItemFactory()->createQName(
      module_->getURI(), "ParseError"
    );
    throw USER_EXCEPTION( lError, lErrorLogSs.str() );
  }

  XmlDataManager *xdm = Zorba::getInstance( nullptr )->getXmlDataManager();
  Item lItem = xdm->parseXML( lSs );

  return ItemSequence_t( new SingletonItemSequence(lItem) );
}

String ParseFunction::getLocalName() const {
  return "parse-internal";
}

///////////////////////////////////////////////////////////////////////////////

SerializeFunction::StringStreamSequence::StringStreamSequence(ItemSequence* input)
  : input_iter(input->getIterator()),
    is(new istream(this))
{
  line_index = 0;
  has_next = true;
  is_open = false;
  open_count = 0;
  input_iter->open();
}

void SerializeFunction::StringStreamSequence::open() {
  is_open = true;
  line_index = 1;
  if ( open_count ) {
    is->seekg(0);
    if ( is->fail() )
      throw USER_EXCEPTION(
        theFactory->createQName(
          "http://www.zorba-xquery.com/modules/converters/json",
          "InvalidStream"
        ),
        "Cannot reset streamable string item"
      );
  }
  ++open_count;
}

void SerializeFunction::StringStreamSequence::close() {
  is_open = false;
}

bool SerializeFunction::StringStreamSequence::isOpen() const {
  return is_open;
}

bool SerializeFunction::StringStreamSequence::next( Item &result ) {
  assert( is_open );
  if ( !has_next )
    return false;
  result = streamable_item;
  has_next = false;
  return true;
}

bool SerializeFunction::StringStreamSequence::next(string &result_string) {
  if ( !input_iter->next( node_item ) )
    return false;

  stringstream lSs, lErrorLogSs;

  if ( theMapping == "simple-json" )
    JSON_serialize( node_item, lSs, lErrorLogSs );
  else if ( theMapping == "json-ml" )
    JSON_ML_serialize( node_item, lSs, lErrorLogSs );

  if ( !lErrorLogSs.str().empty() )
    throw USER_EXCEPTION(
      theFactory->createQName(
        "http://www.zorba-xquery.com/modules/converters/json", "InvalidXDM"
      ),
      lErrorLogSs.str()
    );

  result_string = lSs.str();
  return true;
}

bool SerializeFunction::StringStreamSequence::reset() {
  input_iter->close();
  input_iter->open();
  return true;
}

ItemSequence_t
SerializeFunction::evaluate( ExternalFunction::Arguments_t const &aArgs,
                             StaticContext const *sctx,
                             DynamicContext const *dctx ) const {

  zorba::Item   lOptionsItem, lResItem;
  zorba::String lBaseUri, lJsonMapping, lOptionName("mapping");
  stringstream  lSs, lErrorLogSs;

  lBaseUri = sctx->getBaseURI();

  if ( aArgs.size() == 2 ) {
    Iterator_t lArg0Iter = aArgs[1]->getIterator();
    lArg0Iter->open();
    lArg0Iter->next(lOptionsItem);
    lArg0Iter->close();
  }

  lJsonMapping = getOptionValue(lOptionsItem, lOptionName.c_str());

  if ( lJsonMapping != "simple-json" && lJsonMapping != "json-ml" ) {
    zorba::Item lError = module_->getItemFactory()->createQName(module_->getURI(), "WrongParam");
    lErrorLogSs << "Mapping type '" << lJsonMapping << "' not supported.\nPossible values are 'simple-json' or 'json-ml'.";
    throw USER_EXCEPTION( lError, lErrorLogSs.str() );
  }

  StringStreamSequence *stream_sequence = new StringStreamSequence((ItemSequence*)aArgs[0]);
  stream_sequence->theMapping = lJsonMapping;
  stream_sequence->theFactory = module_->getItemFactory();
  stream_sequence->streamable_item =
  module_->getItemFactory()->createStreamableString(
      *(stream_sequence->is), &StringStreamSequence::releaseStream);

  return ItemSequence_t( stream_sequence );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace jsonmodule
} // namespace zorba

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::jsonmodule::JsonModule();
}
/* vim:set et sw=2 ts=2: */
