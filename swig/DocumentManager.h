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
#ifndef API_DOCUMENT_MANAGER_H
#define API_DOCUMENT_MANAGER_H

class DocumentManager
{
private:
  zorba::DocumentManager* theManager;

public:
  DocumentManager() : theManager(0) {}
  DocumentManager(const DocumentManager& aMgr) : theManager(aMgr.theManager) {}
  DocumentManager(zorba::DocumentManager* aMgr) : theManager(aMgr) {}

  void put(const std::string& aName, Item aDoc);
  void remove(const std::string& aName);
  Item document(const std::string& aName);
  bool isAvailableDocument(const std::string& aName);
  ItemSequence availableDocuments();
};

#endif