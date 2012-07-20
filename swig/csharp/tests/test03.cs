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
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using org.zorbaxquery.api;

namespace ZorbaApplication
{

    class MyDiagnosticHandler : DiagnosticHandler {
        public void error(string [] args) {
          System.Console.WriteLine("Error args: ");
          for (int i=0; i<args.Length; i++) {
            System.Console.WriteLine(args[i]);
          }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            System.Console.WriteLine("Running: Compile query string using Diagnostic Handler");

            InMemoryStore store = InMemoryStore.getInstance();
            Zorba zorba = Zorba.getInstance(store);

            MyDiagnosticHandler diagnosticHandler = new MyDiagnosticHandler();
            try {
              System.Console.WriteLine("Compiling 1 div 0");
              XQuery xquery = zorba.compileQuery("1 div 0", diagnosticHandler);
              System.Console.WriteLine(xquery.execute());
              xquery.Dispose();
            } catch (System.Exception e) {
                System.Console.WriteLine("Error: Exception catch");
                return;
            }
            
            zorba.shutdown();
            InMemoryStore.shutdown(store);

            System.Console.WriteLine("Success");
        }
    }
}
