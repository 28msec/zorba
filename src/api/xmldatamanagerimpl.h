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
#pragma once
#ifndef ZORBA_XMLDATAMANAGER_IMPL_H
#define ZORBA_XMLDATAMANAGER_IMPL_H

#include <zorba/xmldatamanager.h>

#include <zorba/api_shared_types.h>

#include "zorbautils/latch.h"

#include "common/shared_types.h"
#include "util/singleton.h"


namespace zorba {

class DiagnosticHandler;
class ItemFactory;
class DocumentManagerImpl;
class CollectionManagerImpl;

namespace store {
    class Store;
}


class XmlDataManagerImpl : public XmlDataManager
{
private:
  friend struct Loki::CreateUsingNew<XmlDataManagerImpl>;

protected:
  store::Store           * theStore;

  DiagnosticHandler      * theDiagnosticHandler;

  bool                     theUserDiagnosticHandler;

  SYNC_CODE(Latch          theLatch;)

  StaticContext_t          theContext;
  ItemFactory*             theFactory;

  // allow for lazy creation
  mutable DocumentManagerImpl*   theDocManager;
  mutable CollectionManagerImpl* theColManager;
  mutable CollectionManagerImpl* theW3CColManager;

protected:
  void
  initStaticContext(DiagnosticHandler* aDiagnosticHandler = 0);

  void
  initializeItemFactory();

  static void
  destroyStream(std::istream& stream);

public:
  DocumentManager*
  getDocumentManager() const;

  CollectionManager*
  getCollectionManager() const;

  CollectionManager*
  getW3CCollectionManager() const;

  Item
  parseXML(std::istream& aStream) const;

  ItemSequence_t
  parseXML(std::istream& aStream, ParseOptions& aOptions) const;

  Item
  fetch(const String& aURI) const;

  void registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler);

private:
  XmlDataManagerImpl();

  virtual ~XmlDataManagerImpl();
};


typedef
Loki::SingletonHolder<XmlDataManagerImpl,
                      Loki::CreateUsingNew,
                      Loki::DeletableSingleton> XmlDataManagerSingleton;

} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
