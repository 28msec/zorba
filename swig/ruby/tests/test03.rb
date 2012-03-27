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

class MyDiagnosticHandler < Zorba_api.DiagnosticHandler
  def error(self, *args)
    print "Error args: " + args
  end
end

def test(zorba):
  diagnosticHandler = MyDiagnosticHandler.new
  begin
    xquery = zorba.compileQuery("1 div 0", diagnosticHandler)
    print xquery.execute()
  rescue => e
    print "Caught error: " + e.message
  ensure
    xquery.destroy()
  end
end

store = Zorba_api::InMemoryStore.getInstance()
zorba = Zorba_api::Zorba.getInstance(store)

print "Running: Capturing error with DiagnosticHandler"
test(zorba)
print "Success"

zorba.shutdown()
Zorba_api::InMemoryStore.shutdown(store)
