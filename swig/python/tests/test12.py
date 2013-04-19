# Copyright 2006-2013 The FLWOR Foundation.
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
  try:
    query = (
              " let $sats := jn:json-doc('@pythonPath@/tests/satellites.json')('satellites') "
              " return { "
              "   'visible' : [ "
              "      for $sat in jn:keys($sats) "
              "      where $sats($sat)('visible') "
              "      return $sat "
              "   ], "
              "   'invisible' : [ "
              "      for $sat in jn:keys($sats) "
              "      where not($sats($sat)('visible')) "
              "      return $sat "
              "   ] "
              " } " )

    xquery = zorba.compileQuery(query)
    print xquery.execute()
    print "Success"
  except Exception, e:
    print "Caught error: ", e
  return

store = zorba_api.InMemoryStore_getInstance()
zorba = zorba_api.Zorba_getInstance(store)

print "Running: Compile query string using JSONiq"
test(zorba)


zorba.shutdown()
zorba_api.InMemoryStore_shutdown(store)
