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
using System.Text;
using org.zorbaxquery.api;

namespace ZorbaApplication
{

    class MyDiagnosticHandler : DiagnosticHandler {
        public override void error(ZorbaException exception) {
          System.Console.WriteLine("Exception catched in MyDiagnosticHandler");
          System.Console.WriteLine("Description: " + exception.getDescription());
        }
    }

    class Program
    {
        static String test() {
            MyDiagnosticHandler diagnosticHandler = new MyDiagnosticHandler();

            InMemoryStore store = InMemoryStore.getInstance();
            Zorba zorba = Zorba.getInstance(store);

            ItemFactory itemFactory = zorba.getItemFactory();
            Item iNull = itemFactory.createJSONNull();
            System.Console.WriteLine( "Creating JSON Item null:  " +  iNull.serialize());
            iNull.Dispose();
            
            Item iNumber = itemFactory.createJSONNumber("5");
            System.Console.WriteLine( "Creating JSON Item number:  " + iNumber.serialize() );
            iNumber.Dispose();
            
            StringVector sv = new StringVector();
            sv.Add("Hello");
            sv.Add("Zorba");
            sv.Add("Hello");
            sv.Add("Zorba");
            Item iArray = itemFactory.createJSONArray(sv);
            sv.Dispose();
            System.Console.WriteLine( "Creating JSON Item array:  " + iArray.serialize() );
            iArray.Dispose();
            
            zorba.shutdown();
            InMemoryStore.shutdown(store);
            
            return "ok";
        }

        static void Main(string[] args)
        {
            System.Console.WriteLine("Running: Compile query string using Diagnostic Handler");

            String testResult = "ok";
            String result;
            try {
                result = test();
            } catch(Exception e) {
                System.Console.WriteLine("Failed");
                Console.WriteLine("{0} Exception caught.", e);
                return;
            }
            
            if (result.Equals(testResult)) {
                System.Console.WriteLine("Success");
            } else {
                System.Console.WriteLine("Failed");
            }

            
        }
    }
}
