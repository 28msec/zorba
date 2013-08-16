# Copyright 2006-2012 The FLWOR Foundation.
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

def test(zorba, query)
  begin
    xquery = zorba.compileQuery(query)
    print xquery.execute()
    print "Success"
  rescue => e
    print "Caught error: " + e.message
  ensure
    xquery.destroy()
  end
end

store = Zorba_api::InMemoryStore.getInstance()
zorba = Zorba_api::Zorba.getInstance(store)

print "Running: Compile query string using JSONiq \n"
query = <<-eoquery
 import module namespace file='http://expath.org/ns/file';
 let $sats := jn:parse-json(file:read-text("@rubyPathFiles@/tests/satellites.json"))('satellites') 
 return { 
   'visible' : [ 
      for $sat in jn:keys($sats) 
      where $sats($sat)('visible') 
      return $sat 
   ], 
   'invisible' : [ 
      for $sat in jn:keys($sats) 
      where not($sats($sat)('visible')) 
      return $sat 
   ] 
 } 
eoquery

test(zorba, query)

zorba.shutdown()
Zorba_api::InMemoryStore.shutdown(store)
