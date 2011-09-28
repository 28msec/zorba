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


def test(zorba):
  #Read and write result
  print 'Executing: test05.xq'
  f = open('test05.xq', 'r')
  lines = f.read()
  f.close()
  xquery = zorba.compileQuery(lines)
  result = xquery.printPlanAsXML()
  print result
  return


store = zorba_api.InMemoryStore_getInstance()
zorba = zorba_api.Zorba_getInstance(store)

print "Running: XQuery execute - printPlanAsXML"
test(zorba)
print "Success"


zorba.shutdown()
zorba_api.InMemoryStore_shutdown(store)

