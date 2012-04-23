<?
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

//require '@phpPath@/Zorba/zorba_api_wrapper.php';
require 'C:/dev/zapi/build/swig/php/Zorba/zorba_api_wrapper.php';

class MyDiagnosticHandler(zorba_api.DiagnosticHandler): 
  def error(self, *args):
    print "Error args: ", args

def test(zorba):
  #Read and write result
  print 'Executing: compilerHints.xq'
  f = open('compilerHints.xq', 'r')
  lines = f.read()
  f.close()
  diagnosticHandler = MyDiagnosticHandler()
  compilerHints = zorba_api.CompilerHints()
  compilerHints.setOptimizationLevel(1)
  xquery = zorba.compileQuery(lines, compilerHints, diagnosticHandler)
  
  result = xquery.execute()
  print result
  return


store = zorba_api.InMemoryStore_getInstance()
zorba = zorba_api.Zorba_getInstance(store)

print "Running: CompileQuery string + Dignostinc handler + CompilerHint - with optimization 1"
test(zorba)
print "Success"


zorba.shutdown()
zorba_api.InMemoryStore_shutdown(store)

?>