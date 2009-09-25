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

    // Interface

class XmlDataManager 
{
private:
  zorba::XmlDataManager* theManager;
public:
  XmlDataManager() : theManager(0) {}
  XmlDataManager(const XmlDataManager& aManager)
    : theManager(aManager.theManager) {} 
  XmlDataManager(zorba::XmlDataManager* aManager) : theManager(aManager) {}

  void loadDocument(const std::string& aName, const std::string& aContent)
  {
    std::stringstream lStream(aContent);
    theManager->loadDocument(aName, lStream);
  }

  bool deleteDocument(const std::string& aName) 
  { return theManager->deleteDocument(aName); }
};



%}  // end   Implementation




class XmlDataManager 
{
 public:
  void loadDocument(const std::string& aName, const std::string& aContent);
  bool deleteDocument(const std::string& aName);
}; // class XmlDataManager
