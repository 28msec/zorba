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

require '@rubyPath@/zorba_api'

def test(zorba)
  file = File.open("books.xml", "rb")
  contents = file.read

  dataManager = zorba.getXmlDataManager()
  docIter = dataManager.parseXML(contents)
  docIter.open()

  doc = Zorba_api::Item.createEmptyItem()
  docIter.next(doc)

  docIter.close()
  docIter.destroy()
 
  docManager = dataManager.getDocumentManager()
  docManager.put("my_fake_books.xml", doc)
  xquery = zorba.compileQuery("doc('my_fake_books.xml')")

  result = xquery.execute()
  print result
  xquery.destroy()
end 
  
store = Zorba_api::InMemoryStore.getInstance()
zorba = Zorba_api::Zorba.getInstance(store)

print "Running: XQuery execute - parsing XML"
test(zorba)
print "Success"

zorba.shutdown()
Zorba_api::InMemoryStore.shutdown(store)
