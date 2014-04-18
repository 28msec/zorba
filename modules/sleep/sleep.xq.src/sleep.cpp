/*
 * Copyright 2006-2014 The FLWOR Foundation.
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
#include "sleep.h"

#ifdef WIN32
# include <windows.h>
#else
# include <time.h>
#endif
#include <stdlib.h>
#include <limits>
#include <zorba/item_factory.h>
#include <zorba/empty_sequence.h>
#include <zorba/user_exception.h>

namespace zorba { namespace sleep {

MillisFunction::~MillisFunction()
{}

zorba::ItemSequence_t
MillisFunction::evaluate(
  const Arguments_t& aArgs,
  const zorba::StaticContext*,
  const zorba::DynamicContext*) const
{
  // getIntegerValue is not available in Zorba
  // => get the string, parse it, and check the limits
  Item lRequestItem;
  Iterator_t arg0_iter = aArgs[0]->getIterator();
  arg0_iter->open();
  arg0_iter->next(lRequestItem);
  arg0_iter->close();

  std::stringstream lStream;
  unsigned int lMillis;

  zorba::String lStringValue = lRequestItem.getStringValue();
  
  bool lSuccess = lStream << lStringValue &&
    lStream >> lMillis &&
    lStream.eof();

  if ( !lSuccess )
  {
    zorba::String lLocalName = "InvalidValue";
    ItemFactory* lFactory = Zorba::getInstance(0)->getItemFactory();
    zorba::Item lQName = lFactory->createQName( getURI(), "", lLocalName);

    std::ostringstream lMsg;
    lMsg << lStringValue.c_str() << ": exceeds limit ("
      << std::numeric_limits<unsigned int>::min()
      << " < x < "
      << std::numeric_limits<unsigned int>::max() << ")";

    throw USER_EXCEPTION(lQName, lMsg.str());
  }

#ifdef WIN32
  Sleep(lMillis);
#else
  const int32_t lFactor = 1000000;
  struct timespec lTs;
  lTs.tv_sec = lMillis / 1000;
  lTs.tv_nsec = (lMillis % 1000) * lFactor;
  nanosleep(&lTs, 0);
#endif

  return zorba::ItemSequence_t(new zorba::EmptySequence());
}

zorba::ExternalFunction*
SleepModule::getExternalFunction(const zorba::String& aLocalname)
{
  FuncMap_t::const_iterator lFind = theFunctions.find(aLocalname);
  zorba::ExternalFunction*& lFunc = theFunctions[aLocalname];
  if (lFind == theFunctions.end()) {
    if (aLocalname.find("millis") != zorba::String::npos) {
      lFunc = new MillisFunction(this);
    }
  }
  return lFunc;
}

SleepModule::~SleepModule()
{
  for (FuncMap_t::const_iterator lIter = theFunctions.begin();
      lIter != theFunctions.end(); ++lIter)
  {
    delete lIter->second;
  }
  theFunctions.clear();
}

void
SleepModule::destroy()
{
  if (!dynamic_cast<SleepModule*>(this))
    return;
  delete this;
}

} /* namespace sleep */ } /* namespace zorba */
