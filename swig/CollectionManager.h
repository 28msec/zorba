/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
#ifndef API_COLLECTION_MANAGER_H
#define API_COLLECTION_MANAGER_H

  /** \brief This class defines a set of functions for managing persistent
   *         collections.
   *
   */
class CollectionManager
{
private:
  zorba::CollectionManager* theManager;

public:
  CollectionManager(const CollectionManager& aMgr) : theManager(aMgr.theManager) {}
  CollectionManager(zorba::CollectionManager* aMgr) : theManager(aMgr) {}

    /**
     * This function returns a sequence of names of the collections
     * that are available. If this is an instance of the StaticCollectionManager
     * class (i.e. returned by any of the getStaticCollectionManager methods),
     * the collections returned by this function are also
     * statically declared.
     *
     * @return The list of names of the available collections.
     *
     */
  ItemSequence availableCollections();

  /**
     * This function creates the collection with the given name.
     *
     * @param aName The name of the collection to create.
     *
     * @throw XDDY0002 if a collection with the given name already exists.
     *
     */
  void createCollection(const Item &aName );

  /**
     * This function creates the collection with the given name.
     * Moreover, it adds copies of the sequence aContents to the new collection.
     *
     * @param aName The name of the collection to create.
     * @param aContents The sequence of items.
     *
     * @throw XDDY0002 if a collection with the given name already exists.
     *
     */
  void createCollection(const Item &aName, const ItemSequence &aContents );

  /**
     * This function removes the collection with the given name.
     *
     * @param aName The name of the collection to delete.
     *
     * @throw XDDY0003 if the collection does not exist.
     */
  void deleteCollection(const Item &aName );

    /**
     * Returns a instance of the Collection class which can
     * be used to modify and retrieve the contents of the collection
     * identified by the given name.
     *
     * @param aName The name of the collection to retrieve.
     *
     * @throw XDDY0003 if the collection does not exist.
     */
  Collection getCollection(const Item &aName );

    /**
     * This function returns true if a collection with the given name is available.
     * If this is an instance of the StaticCollectionManager class (i.e.
     * returned by any of the getStaticCollectionManager() methods),
     * the collection also needs to be statically declared.
     *
     * @param aName The name of the collection that is being checked.
     *
     * @return true if the collection is available and false otherwise.
     *
     */
  bool isAvailableCollection(const Item &aName );

    /** \brief Register a DiagnosticHandler to which errors
     * occuring during the management of collections are reported.
     *
     * If no DiagnosticHandler has been set using this function or
     * the corresponding function of the XmlDataManager then
     * subclasses of the ZorbaException class are thrown to report
     * errors.
     *
     * @param aDiagnosticHandler DiagnosticHandler to which errors
     *        are reported. The caller retains ownership over the
     *        DiagnosticHandler passed as parameter.
     */
  void registerDiagnosticHandler(DiagnosticHandler *aDiagnosticHandler);
  
};

#endif