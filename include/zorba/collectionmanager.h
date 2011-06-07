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
#ifndef ZORBA_COLLECTIONMANAGER_API_H
#define ZORBA_COLLECTIONMANAGER_API_H

#include <zorba/config.h>
#include <zorba/api_shared_types.h>

namespace zorba {

  /** \brief This class defines a set of functions for managing persistent
   *         collections.
   *
   */
  class ZORBA_DLL_PUBLIC CollectionManager
  {
  public:
    /**
     * This function creates the collection with the given name.
     *
     * @param aName The name of the collection to create.
     *
     * @error XDDY0002 if a collection with the given name already exists.
     *
     */
    virtual void
    createCollection(const Item& aName) = 0;

    /**
     * This function creates the collection with the given name.
     * Moreover, it adds copies of the sequence aContents to the new collection.
     *
     * @param aName The name of the collection to create.
     *
     * @error XDDY0002 if a collection with the given name already exists.
     *
     */
    virtual void
    createCollection(
        const Item& aName,
        const ItemSequence_t& aContents) = 0;

    /**
     * This function removes the collection with the given name.
     *
     * @param aName The name of the collection to delete.
     *
     * @error XDDY0003 if the collection does not exist.
     */
    virtual void
    deleteCollection(const Item& aName) = 0;

    /**
     * Returns a instance of the Collection class which can
     * be used to modify and retrieve the contents of the collection
     * identified by the given name.
     *
     * @param aName The name of the collection to retrieve.
     *
     * @error XDDY0003 if the collection does not exist.
     */
    virtual Collection_t
    getCollection(const Item& aName) const = 0;

    /**
     * This function returns a sequence of names of the collections that are available.
     *
     * @return The list of names of the available collections.
     *
     */
    virtual ItemSequence_t
    availableCollections() const = 0;

    /**
     * This function returns true if a collection with the given name is available.
     *
     * @param aName The name of the collection that is being checked.
     *
     * @return true if the collection is available and false otherwise.
     *
     */
    virtual bool
    isAvailableCollection(const Item& aName) const = 0;

    /** \brief Destructor
     *
     */
    virtual ~CollectionManager() {}

  }; /* class CollectionManager */

} /* namespace zorba */
#endif

