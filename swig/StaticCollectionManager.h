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
#ifndef API_STATIC_COLLECTION_MANAGER_H
#define API_STATIC_COLLECTION_MANAGER_H

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
class StaticCollectionManager
{
private:
  zorba::StaticCollectionManager* theStaticManager;

public:
  StaticCollectionManager(const StaticCollectionManager& aMgr) : theStaticManager(aMgr.theStaticManager) {}
  StaticCollectionManager(zorba::StaticCollectionManager* aMgr) : theStaticManager(aMgr) {}

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
     * This function returns a sequence of names of the indexes
     * that are available.
     *
     * @return The list of names of the available indexes.
     */
  ItemSequence availableIndexes();

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
     * Create the index with the given name.
     *
     * @param aQName The name of the index to create.
     *
     * @throw zerr:ZDDY0021 if a index with the given name is not declared.
     *
     * @throw zerr:ZDDY0022 if a index with the given name already exists.
     */
  void createIndex( const Item & aQName );

    /**
     * List all the collections that are declared in the XQuery or the
     * StaticContext that was used to retrieve this StaticCollectionManager.
     *
     * @return a sequence of QNames of all said collections
     */
  ItemSequence declaredCollections();

    /**
     * List all the indexes that are declared in the XQuery or the
     * StaticContext that was used to retrieve this StaticCollectionManager.
     *
     * @return a sequence of QNames of all said indexes
     */
  ItemSequence declaredIndexes();

    /**
     * This function removes the collection with the given name.
     *
     * @param aName The name of the collection to delete.
     *
     * @throw XDDY0003 if the collection does not exist.
     */
  void deleteCollection(const Item &aName );

    /**
     * Create the index with the given name.
     *
     * @param aQName The name of the index to create.
     *
     * @throw zerr:ZDDY0021 if a index with the given name is not declared.
     *
     * @throw zerr:ZDDY0009 if a index with the given name does not exist
     */
  void deleteIndex(const Item &aQName );

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

    /**
     * This function returns true if a index with the given name is available.
     *
     * @param aQName The name of the index that is being checked.
     *
     * @return true if the index is available and false otherwise.
     */
  bool isAvailableIndex(const Item &aQName );

    /**
     * Checks if a collection with a given QName is declared in the XQuery
     * or the StaticContext that was used to retrieve this
     * StaticCollectionManager.
     *
     * @return true if a collection with the given name is declared,
     *   false otherwise.
     */
  bool isDeclaredCollection( const Item & aQName );

    /**
     * Checks if a index with a given QName is declared in the XQuery
     * or the StaticContext that was used to retrieve this
     * StaticCollectionManager.
     *
     * @return true if a collection with the given name is declared,
     *   false otherwise.
     */
  bool isDeclaredIndex( const Item & aQName );

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
  void  registerDiagnosticHandler(DiagnosticHandler *aDiagnosticHandler );
};

#endif