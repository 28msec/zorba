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

  DocumentManager XmlDataManager::getDocumentManager()
  {
    return DocumentManager(theManager->getDocumentManager()); 
  }
  CollectionManager XmlDataManager::getCollectionManager()
  {
    return CollectionManager(theManager->getCollectionManager()); 
  }
  CollectionManager XmlDataManager::getW3CCollectionManager()
  {
    return CollectionManager(theManager->getW3CCollectionManager()); 
  }

  Iterator XmlDataManager::parseXML(const std::string& aDoc)
  {
    std::stringstream lDoc;
    lDoc << aDoc;
    zorba::Item lItem = theManager->parseXML(lDoc);
    return Iterator(lItem);
  }


%}  // end   Implementation

%include "XmlDataManager.h"
