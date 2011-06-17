/*
 * Copyright 2006-2011 The FLWOR Foundation.
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
#ifndef ZORBA_STATICCOLLECTIONMANAGER_API_H
#define ZORBA_STATICCOLLECTIONMANAGER_API_H

#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/collection_manager.h>

namespace zorba {

  /** \brief 
   *
   */
  class ZORBA_DLL_PUBLIC StaticCollectionManager : public CollectionManager
  {
  public:
    virtual ItemSequence_t
    declaredCollections() const = 0;

    virtual bool
    isDeclaredCollection(const Item& aQName) const = 0;

    virtual ~StaticCollectionManager() {}

  }; /* class StaticCollectionManager */

} /* namespace zorba */
#endif
/* vim:set et sw=2 ts=2: */
