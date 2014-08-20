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
#include "stdafx.h"

#include "api/jsondatamanagerimpl.h"

#include <fstream>

#include <zorba/config.h>
#include <zorba/zorba_string.h>
#include <zorba/item.h>
#include <zorba/item_sequence.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/iterator.h>
#include <zorba/diagnostic_handler.h>

#include "api/zorbaimpl.h"
#include "api/unmarshaller.h"
#include "api/staticcontextimpl.h"
#include "context/static_context.h"
#include "diagnostics/xquery_diagnostics.h"
#include "runtime/util/flowctl_exception.h"
#include "store/api/collection.h"
#include "store/api/item.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "zorbamisc/ns_consts.h"

namespace zorba {


#define ZORBA_DM_TRY                                    \
  try

#define ZORBA_DM_CATCH                                         \
  catch (ZorbaException const& e)                              \
  {                                                            \
    ZorbaImpl::notifyError(theDiagnosticHandler, e);           \
  }                                                            \
  catch (std::exception const& e)                              \
  {                                                            \
    ZorbaImpl::notifyError(theDiagnosticHandler, e.what());    \
  }                                                            \
  catch (...)                                                  \
  {                                                            \
    ZorbaImpl::notifyError(theDiagnosticHandler);              \
  }


/*******************************************************************************

********************************************************************************/
JsonDataManagerImpl::JsonDataManagerImpl()
{
  Zorba* lZorba = Zorba::getInstance(0);
  theFactory = lZorba->getItemFactory();

  initStaticContext();

  theDiagnosticHandler = new DiagnosticHandler();
  theUserDiagnosticHandler = false;

  ZORBA_TRY
  {
    theStore = & GENV_STORE;
  }
  ZORBA_CATCH
}


/*******************************************************************************

********************************************************************************/
void JsonDataManagerImpl::initStaticContext(DiagnosticHandler* aDiagnosticHandler)
{
  // assumption: Zorba is already initialized
  // otherwise there was no chance for the user to get this data manager
  Zorba* lZorba = Zorba::getInstance(0);

  theContext = lZorba->createStaticContext(aDiagnosticHandler);

  Zorba_CompilerHints_t lHints;
  std::ostringstream lProlog;
  lProlog
    << "import module namespace j = '" << static_context::JSONIQ_FN_NS << "';"
    << "import schema namespace opt = '" << static_context::ZORBA_XML_FN_OPTIONS_NS << "';";

  theContext->loadProlog(lProlog.str(), lHints);
}


/*******************************************************************************

********************************************************************************/
JsonDataManagerImpl::~JsonDataManagerImpl()
{
  if (!theUserDiagnosticHandler)
    delete theDiagnosticHandler;
}

/*******************************************************************************

********************************************************************************/
static void streamReleaser(std::istream* stream)
{
  // it's the user's responsibility to manage the lifetime
}


/*******************************************************************************

********************************************************************************/
ItemSequence_t JsonDataManagerImpl::parseJSON(std::istream& aStream) const
{
  ZORBA_DM_TRY
  {
    Item lQName = theFactory->createQName(static_context::JSONIQ_FN_NS, "parse-json");

    std::vector<ItemSequence_t> lArgs;

    Item lString = theFactory->createStreamableString(aStream, &streamReleaser);
    lArgs.push_back(new SingletonItemSequence(lString));

    return theContext->invoke(lQName, lArgs);
  }
  ZORBA_DM_CATCH
  return 0;
}


/*******************************************************************************

********************************************************************************/
ItemSequence_t JsonDataManagerImpl::parseJSON(
    std::istream& aStream,
    JsonDataManager::ParseOptions& aOptions) const
{
  ZORBA_DM_TRY
  {
    Item lQName = theFactory->createQName(static_context::JSONIQ_FN_NS, "parse-json");

    std::vector<ItemSequence_t> lArgs;

    Item lString = theFactory->createStreamableString(aStream, &streamReleaser);
    lArgs.push_back(new SingletonItemSequence(lString));

    std::vector<std::pair<Item, Item> > lOptionsPairs;
    Item lMultipleName = theFactory->createString("jsoniq-multiple-top-level-items");
    Item lMultipleValue = theFactory->createBoolean(aOptions.isMultipleTopLevelItems());
    lOptionsPairs.push_back(std::make_pair(lMultipleName, lMultipleValue));
    Item lStripName = theFactory->createString("jsoniq-strip-top-level-array");
    Item lStripValue = theFactory->createBoolean(aOptions.isStripTopLevelArray());
    lOptionsPairs.push_back(std::make_pair(lStripName, lStripValue));
    Item lOptionsObj = theFactory->createJSONObject(lOptionsPairs);
    lArgs.push_back(new SingletonItemSequence(lOptionsObj));

    return theContext->invoke(lQName, lArgs);
  }
  ZORBA_DM_CATCH
  return 0;
}

/*******************************************************************************

********************************************************************************/
void JsonDataManagerImpl::registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler)
{
  theContext = new StaticContextImpl(aDiagnosticHandler);
  if (!theUserDiagnosticHandler)
    delete theDiagnosticHandler;

  theDiagnosticHandler = aDiagnosticHandler;
  theUserDiagnosticHandler = true;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
