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

class StaticCollectionManager
{
private:
  zorba::StaticCollectionManager* theStaticManager;

public:
  StaticCollectionManager() : theStaticManager(0) {}
  StaticCollectionManager(const StaticCollectionManager& aMgr) : theStaticManager(aMgr.theStaticManager) {}
  StaticCollectionManager(zorba::StaticCollectionManager* aMgr) : theStaticManager(aMgr) {}

  ItemSequence availableCollections();
  ItemSequence availableIndexes();
  void createCollection(const Item &aName );
  void createCollection(const Item &aName, const ItemSequence &aContents );
  void createIndex( const Item & aQName );
  ItemSequence declaredCollections();
  ItemSequence declaredIndexes();
  void deleteCollection(const Item &aName );
  void deleteIndex(const Item &aQName );
  Collection getCollection(const Item &aName );
  bool isAvailableCollection(const Item &aName );
  bool isAvailableIndex(const Item &aQName );
  bool isDeclaredCollection( const Item & aQName );
  bool isDeclaredIndex( const Item & aQName );
  void  registerDiagnosticHandler(DiagnosticHandler *aDiagnosticHandler );
};

#endif