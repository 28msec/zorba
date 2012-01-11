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

  /** \brief Using the StaticCollectionManager one can retrieve information
   *   about statically declared collections and indexes as well as manage them.
   *
   * The StaticCollectionManager can be retrieved from (1) a compiled XQuery
   * or (2) a StaticContext object. In both cases, this class provides access
   * to information for the collections and indexes that are declared in (1) all the
   * modules (transitively) imported by the main query or (2) the module
   * that resulted in the compilation of the StaticContext, respectively.
   * Moreover, this class allows to create or delete such collections and indexes.
   *
   */
  class ZORBA_DLL_PUBLIC StaticCollectionManager : public CollectionManager
  {
  public:
    /**
     * List all the collections that are declared in the XQuery or the
     * StaticContext that was used to retrieve this StaticCollectionManager.
     *
     * @return a sequence of QNames of all said collections
     */
    virtual ItemSequence_t
    declaredCollections() const = 0;

    /**
     * Checks if a collection with a given QName is declared in the XQuery
     * or the StaticContext that was used to retrieve this
     * StaticCollectionManager.
     *
     * @return true if a collection with the given name is declared,
     *   false otherwise.
     */
    virtual bool
    isDeclaredCollection(const Item& aQName) const = 0;

    /**
     * Create the index with the given name.
     *
     * @param aName The name of the index to create.
     *
     * @throw zerr:ZDDY0021 if a index with the given name is not declared.
     *
     * @throw zerr:ZDDY0022 if a index with the given name already exists.
     */
    virtual void
    createIndex(const Item& aQName) = 0;

    /**
     * Create the index with the given name.
     *
     * @param aName The name of the index to create.
     *
     * @throw zerr:ZDDY0021 if a index with the given name is not declared.
     *
     * @throw zerr:ZDDY0009 if a index with the given name does not exist
     */
    virtual void
    deleteIndex(const Item& aQName) = 0;

    /**
     * This function returns a sequence of names of the indexes
     * that are available.
     *
     * @return The list of names of the available indexes.
     */
    virtual ItemSequence_t
    availableIndexes() const = 0;

    /**
     * This function returns true if a index with the given name is available.
     *
     * @param aName The name of the index that is being checked.
     *
     * @return true if the index is available and false otherwise.
     */
    virtual bool
    isAvailableIndex(const Item& aQName) const = 0;

    /**
     * List all the indexes that are declared in the XQuery or the
     * StaticContext that was used to retrieve this StaticCollectionManager.
     *
     * @return a sequence of QNames of all said indexes
     */
    virtual ItemSequence_t
    declaredIndexes() const = 0;

    /**
     * Checks if a index with a given QName is declared in the XQuery
     * or the StaticContext that was used to retrieve this
     * StaticCollectionManager.
     *
     * @return true if a collection with the given name is declared,
     *   false otherwise.
     */
    virtual bool
    isDeclaredIndex(const Item& aQName) const = 0;

    virtual ~StaticCollectionManager() {}

  }; /* class StaticCollectionManager */

} /* namespace zorba */
#endif
/* vim:set et sw=2 ts=2: */
