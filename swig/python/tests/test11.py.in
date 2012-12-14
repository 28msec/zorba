# Copyright 2006-2011 The FLWOR Foundation.
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import sys
sys.path.insert(0, '@pythonPath@')
import zorba_api

store = zorba_api.InMemoryStore_getInstance()
zorba = zorba_api.Zorba_getInstance(store)

print "Running: CompileQuery CollectionManager"

xmlManager = zorba.getXmlDataManager()
collectionManager = xmlManager.getCollectionManager()
itemFactory = zorba.getItemFactory()
name = itemFactory.createQName("http://www.zorba-xquery.com/", "aaa")
collectionManager.createCollection(name)
isAdded = collectionManager.isAvailableCollection(name)

if isAdded :
  collection = collectionManager.getCollection(name);
  data = xmlManager.parseXMLtoItem("<books><book>Book 1</book><book>Book 2</book></books>");
  itemSequence = zorba_api.ItemSequence(data)
  collection.insertNodesLast(itemSequence)

print "Success"


zorba.shutdown()
zorba_api.InMemoryStore_shutdown(store)

