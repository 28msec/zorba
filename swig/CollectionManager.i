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

%{  // start Implementation

  ItemSequence CollectionManager::availableCollections()
  {
    return ItemSequence( theManager->availableCollections() );
  }

  void CollectionManager::createCollection(const Item &aName )
  {
    theManager->createCollection(aName.theItem );
  }

  void CollectionManager::createCollection(const Item &aName, const SingletonItemSequence &aContents )
  {
    theManager->createCollection(aName.theItem, aContents.theItemSequence );
  }

  void CollectionManager::deleteCollection(const Item &aName )
  {
    theManager->deleteCollection(aName.theItem );
  }
  
  Collection CollectionManager::getCollection(const Item &aName )
  {
    return Collection(theManager->getCollection(aName.theItem ));
  }

  bool CollectionManager::isAvailableCollection(const Item &aName )
  {
    return theManager->isAvailableCollection(aName.theItem );
  }

  void CollectionManager::registerDiagnosticHandler(DiagnosticHandler *aDiagnosticHandler)
  {
    theManager->registerDiagnosticHandler(aDiagnosticHandler);
  }

%}  // end   Implementation

%include "CollectionManager.h"
