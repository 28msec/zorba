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
#include <zorba/item.h>

#include "html.h"
#include "tidy_wrapper.h"

namespace zorba
{
  namespace htmlmodule
  {

//*****************************************************************************
//*****************************************************************************

ParseFunction::ParseFunction(const HtmlModule* aModule)
: HtmlFunction(aModule)
{
}

ItemSequence_t
ParseFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
  {
    std::auto_ptr<std::istringstream> iss;
    std::istream *is;
    String docString;
    Item lStringItem, lOptionsItem;

    if (aArgs.size() >= 1)
    {
      Iterator_t lArg0Iter = aArgs[0]->getIterator();
      lArg0Iter->open();
      lArg0Iter->next(lStringItem);
      lArg0Iter->close();
    }

    if ( lStringItem.isStreamable() )
    {
      //
      // The "iss" auto_ptr can NOT be used since it will delete the stream that,
      // in this case, is a data member inside another object and not dynamically
      // allocated.
      //
      // We can't replace "iss" with "is" since we still need the auto_ptr for
      // the case when the result is not streamable.
      //
      is = &lStringItem.getStream();
    }
    else
    {
      docString = lStringItem.getStringValue();
      iss.reset (new std::istringstream(docString.c_str()));
      is = iss.get();
    }

    if (aArgs.size() == 2)
    {
      Iterator_t lArg1Iter = aArgs[1]->getIterator();
      lArg1Iter->open();
      lArg1Iter->next(lOptionsItem);
      lArg1Iter->close();
    }

    return ItemSequence_t(new SingletonItemSequence(
      createHtmlItem( *is , lOptionsItem )));
  }

//*****************************************************************************
//*****************************************************************************

ItemFactory* HtmlModule::theFactory = 0;

HtmlModule::~HtmlModule()
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
HtmlModule::getExternalFunction(const String& aLocalname)
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
  }
  return lFunc;
}

void
HtmlModule::destroy()
{
  if (!dynamic_cast<HtmlModule*>(this))
  {
    return;
  }
  delete this;
}
//*****************************************************************************
//*****************************************************************************

  } /* namespace htmlmodule */
} /* namespace zorba */

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule()
{
  return new zorba::htmlmodule::HtmlModule();
}