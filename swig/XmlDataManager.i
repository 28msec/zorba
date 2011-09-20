/*
 * Copyright 2006-2008 The FLWOR Foundation.
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


class DocumentManager
{
private:
  zorba::DocumentManager* theManager;

public:
  DocumentManager() : theManager(0) {}
  DocumentManager(const DocumentManager& aMgr) : theManager(aMgr.theManager) {}
  DocumentManager(zorba::DocumentManager* aMgr) : theManager(aMgr) {}

  void put(const std::string& aName, Item aDoc)
  {
    theManager->put(aName, aDoc.theItem);
  }

  void remove(const std::string& aName)
  {
    theManager->remove(aName);
  }

  Item document(const std::string& aName)
  {
    return theManager->document(aName);
  }

  bool isAvailableDocument(const std::string& aName)
  {
    return theManager->isAvailableDocument(aName);
  }
};

class XmlDataManager
{
private:
  zorba::XmlDataManager* theManager;

public:
  XmlDataManager() : theManager(0) {}
  XmlDataManager(const XmlDataManager& aMgr) : theManager(aMgr.theManager) {}
  XmlDataManager(zorba::XmlDataManager* aMgr) : theManager(aMgr) {}

  DocumentManager getDocumentManager()
  {
    return DocumentManager(theManager->getDocumentManager()); 
  }

  Iterator parseXML(const std::string& aDoc)
  {
    std::stringstream lDoc;
    lDoc << aDoc;
    zorba::Item lItem = theManager->parseXML(lDoc);
    return Iterator(lItem);
  }

};

%}  // end   Implementation

class DocumentManager
{
public:
  void put(const std::string& aName, Item aDoc);

  void remove(const std::string& aName);

  Item document(const std::string& aName);

  bool isAvailableDocument(const std::string& aName);
};


class XmlDataManager 
{
public:
  DocumentManager getDocumentManager();

  Iterator parseXML(const std::string& aDoc);
   
}; // class XmlDataManager
