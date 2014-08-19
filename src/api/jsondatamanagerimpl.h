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
#pragma once
#ifndef ZORBA_JSONDATAMANAGER_IMPL_H
#define ZORBA_JSONDATAMANAGER_IMPL_H

#include <zorba/jsondatamanager.h>

#include <zorba/api_shared_types.h>

#include "zorbautils/latch.h"

#include "common/shared_types.h"
#include "util/singleton.h"

namespace zorba {

class DiagnosticHandler;
class ItemFactory;

namespace store
{
  class Store;
}


class JsonDataManagerImpl : public JsonDataManager
{
  friend class ZorbaImpl;

protected:
  store::Store                     * theStore;

  DiagnosticHandler                * theDiagnosticHandler;

  bool                               theUserDiagnosticHandler;

  StaticContext_t                    theContext;

  ItemFactory                      * theFactory;

public:
  ItemSequence_t parseJSON(std::istream& aStream) const;

  ItemSequence_t parseJSON(std::istream& aStream, ParseOptions& aOptions) const;

  void registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler);

private:
  JsonDataManagerImpl();

  virtual ~JsonDataManagerImpl();

  void initStaticContext(DiagnosticHandler* aDiagnosticHandler = 0);
};


} // namespace zorba

#endif /* ZORBA_JSONDATAMANAGER_IMPL_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
