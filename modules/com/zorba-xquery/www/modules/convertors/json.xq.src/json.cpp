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

#include <sstream>

#include <zorba/empty_sequence.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/error_list.h>
#include <zorba/user_exception.h>
#include <zorba/item.h>
#include <zorba/store_consts.h>

#include "json.h"
#include "jansson_wrapper.h"

namespace zorba
{
  namespace jsonmodule
  {
zorba::String
JsonFunction::getOptionValue(zorba::Item& aOptionsItem, const char* aOptionName) const
{
  zorba::Iterator_t lChildrenIt, lAttrIt;
  zorba::Item       lChild, lAttr, lNodeNameItem;
  bool              lCorrectChild = false;

  lChildrenIt = aOptionsItem.getChildren();
  lChildrenIt->open();
  while (lChildrenIt->next(lChild))
  {
    if (lChild.getNodeKind() == store::StoreConsts::elementNode)
    {
      lAttrIt = lChild.getAttributes();
      lAttrIt->open();
      while (lAttrIt->next(lAttr))
      {
        if(lAttr.getNodeKind() == store::StoreConsts::attributeNode)
        {
          lAttr.getNodeName(lNodeNameItem);
          if(!lCorrectChild &&
              lNodeNameItem.getStringValue().equals("name"))
            lCorrectChild = lAttr.getStringValue().equals("mapping");
          else if(lCorrectChild &&
                  lNodeNameItem.getStringValue().equals("value"))
            return lAttr.getStringValue();
        }
      }
    }
  }
  lChildrenIt->close();

  return zorba::String("");
}
//*****************************************************************************
//*****************************************************************************

ParseFunction::ParseFunction(const JsonModule* aModule)
: JsonFunction(aModule)
{
}

ItemSequence_t
ParseFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
  {
    zorba::Item       lStringItem, lOptionsItem, lResItem;
    zorba::String     lBaseUri, lJsonMapping, lOptionName("mapping");
    std::stringstream lSs, lErrorLogSs;

    if (aArgs.size() >= 1)
    {
      Iterator_t lArg0Iter = aArgs[0]->getIterator();
      lArg0Iter->open();
      lArg0Iter->next(lStringItem);
      lArg0Iter->close();
    }

    lBaseUri = aSctxCtx->getBaseURI();

    if (aArgs.size() == 2)
    {
      Iterator_t lArg0Iter = aArgs[1]->getIterator();
      lArg0Iter->open();
      lArg0Iter->next(lOptionsItem);
      lArg0Iter->close();
    }

    lJsonMapping = getOptionValue(lOptionsItem, lOptionName.c_str());

    if(lJsonMapping.equals("simple-json"))
      JSON_parse(lStringItem.getStringValue().c_str(), lSs, lErrorLogSs);
    else if(lJsonMapping.equals("json-ml"))
      JSON_ML_parse(lStringItem.getStringValue().c_str(), lSs, lErrorLogSs);
    else
    {
      zorba::Item lError = theModule->getItemFactory()->createQName(theModule->getURI(), "WrongParam");
      lErrorLogSs << "Mapping type '" << lJsonMapping << "' not supported.\nPossible values are 'simple-json' or 'json-ml'.";
      throw USER_EXCEPTION(lError, lErrorLogSs.str());
    }

    if(!lErrorLogSs.str().empty())
    {
      zorba::Item lError = theModule->getItemFactory()->createQName(theModule->getURI(), "WrongParam");
      throw USER_EXCEPTION(lError, lErrorLogSs.str());
    }

    XmlDataManager* lDataManager = Zorba::getInstance(0)->getXmlDataManager();
    Item lItem = lDataManager->parseDocument(lSs);

    return ItemSequence_t(new SingletonItemSequence(lItem));
  }

//*****************************************************************************
//*****************************************************************************
SerializeFunction::StringStreamSequence::StringStreamSequence(ItemSequence* input)
  : input_iter(input->getIterator()),
    is(new std::istream(this))
{
  line_index = 0;
  has_next = true;
  is_open = false;
  open_count = 0;
  input_iter->open();
}

void SerializeFunction::StringStreamSequence::open()
{
  is_open = true;
  line_index = 1;
  if(open_count)
  {
    is->seekg(0);
    if(is->fail())
      throw USER_EXCEPTION(theFactory->createQName("http://www.zorba-xquery.com/modules/convertors/json", "ZXQP0019"),
                           "Cannot reset Json SerializeFunction streamable string item");
  }
  open_count++;
}

void SerializeFunction::StringStreamSequence::close()
{
  is_open = false;
}

bool SerializeFunction::StringStreamSequence::isOpen() const
{
  return is_open;
}

bool SerializeFunction::StringStreamSequence::next( Item &result )
{
  if(!is_open)
    throw USER_EXCEPTION(theFactory->createQName("http://www.zorba-xquery.com/modules/convertors/json", "ZXQP0019"),
                         "Next called on Json SerializeFunction::StringStreamSequence iterator that is not open");

  if(!has_next)
    return false;
  result = streamable_item;
  has_next = false;
  return true;
}

bool SerializeFunction::StringStreamSequence::next(std::string &result_string)
{
  if(!input_iter->next(node_item))
    return false;

  std::stringstream lSs, lErrorLogSs;

  if(theMapping.equals("simple-json"))
    JSON_serialize(node_item, lSs, lErrorLogSs);
  else if(theMapping.equals("json-ml"))
    JSON_ML_serialize(node_item, lSs, lErrorLogSs);

  if(!lErrorLogSs.str().empty())
    throw USER_EXCEPTION(theFactory->createQName("http://www.zorba-xquery.com/modules/convertors/json", "ZXQP0019"),
                         lErrorLogSs.str());

  result_string = lSs.str();
  return true;
}

bool SerializeFunction::StringStreamSequence::reset()
{
  input_iter->close();
  input_iter->open();
  return true;
}


SerializeFunction::SerializeFunction(const JsonModule* aModule)
: JsonFunction(aModule)
{
}

ItemSequence_t
SerializeFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
  {
    zorba::Item       lOptionsItem, lResItem;
    zorba::String     lBaseUri, lJsonMapping, lOptionName("mapping");
    std::stringstream lSs, lErrorLogSs;

    lBaseUri = aSctxCtx->getBaseURI();

    if (aArgs.size() == 2)
    {
      Iterator_t lArg0Iter = aArgs[1]->getIterator();
      lArg0Iter->open();
      lArg0Iter->next(lOptionsItem);
      lArg0Iter->close();
    }

    lJsonMapping = getOptionValue(lOptionsItem, lOptionName.c_str());

    if(!lJsonMapping.equals("simple-json") &&
       !lJsonMapping.equals("json-ml"))
    {
      zorba::Item lError = theModule->getItemFactory()->createQName(theModule->getURI(), "WrongParam");
      lErrorLogSs << "Mapping type '" << lJsonMapping << "' not supported.\nPossible values are 'simple-json' or 'json-ml'.";
      throw USER_EXCEPTION(lError, lErrorLogSs.str());
    }

    StringStreamSequence  *stream_sequence = new StringStreamSequence((ItemSequence*)aArgs[0]);
    stream_sequence->theMapping = lJsonMapping;
    stream_sequence->theFactory = theModule->getItemFactory();
    stream_sequence->streamable_item =
    theModule->getItemFactory()->createStreamableString(
        *(stream_sequence->is), StringStreamSequence::destroyStream);

    return ItemSequence_t(stream_sequence);

  }

//*****************************************************************************
//*****************************************************************************

ItemFactory* JsonModule::theFactory = 0;

JsonModule::~JsonModule()
{
  for ( FuncMap_t::const_iterator lIter = theFunctions.begin();
        lIter != theFunctions.end();
        ++lIter)
       {
         delete lIter->second;
       }
       theFunctions.clear();
}

StatelessExternalFunction*
JsonModule::getExternalFunction(const String& aLocalname)
{
  StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
  if (!lFunc)
  {
    if (1 == 0)
    { }
    else if (aLocalname.equals("parse-internal"))
    {
      lFunc = new ParseFunction(this);
    }
    else if (aLocalname.equals("serialize-internal"))
    {
      lFunc = new SerializeFunction(this);
    }
  }
  return lFunc;
}

void
JsonModule::destroy()
{
  if (!dynamic_cast<JsonModule*>(this))
  {
    return;
  }
  delete this;
}
//*****************************************************************************
//*****************************************************************************

  } /* namespace jsonmodule */
} /* namespace zorba */

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule()
{
  return new zorba::jsonmodule::JsonModule();
}
