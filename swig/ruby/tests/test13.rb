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

def test(zorba)
  begin
    itemFactory = zorba.getItemFactory()
    print "Creating JSON Item null:  ", itemFactory.createJSONNull().serialize()
    print "Creating JSON Item number:  ", itemFactory.createJSONNumber("5").serialize()
    sv = Zorba_api.StringVector(4)
    sv[0]="Hello"
    sv[1]="Zorba"
    sv[2]="Hello"
    sv[3]="Zorba"
    print "Creating JSON Item array:  ", itemFactory.createJSONArray(sv).serialize()
    print "Success"
  rescue => e
    print "Caught error: " + e.message
  end
end

store = Zorba_api::InMemoryStore.getInstance()
zorba = Zorba_api::Zorba.getInstance(store)

print "Running: Creating JSON objects using the API"
test(zorba)

zorba.shutdown()
Zorba_api::InMemoryStore.shutdown(store)