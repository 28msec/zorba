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

class CollectionManager
{
private:
  zorba::CollectionManager* theManager;

public:
  CollectionManager() : theManager(0) {}
  CollectionManager(const CollectionManager& aMgr) : theManager(aMgr.theManager) {}
  CollectionManager(zorba::CollectionManager* aMgr) : theManager(aMgr) {}

  ItemSequence availableCollections();
  void createCollection(const Item &aName );
  void createCollection(const Item &aName, const SingletonItemSequence &aContents );
  void deleteCollection(const Item &aName );
  Collection getCollection(const Item &aName );
  bool isAvailableCollection(const Item &aName );
  void registerDiagnosticHandler(DiagnosticHandler *aDiagnosticHandler);
  
};

#endif