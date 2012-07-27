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
using System.IO;
using org.zorbaxquery.api;

namespace ZorbaApplication
{
    class Program
    {
        
        static String test(String query) {
            InMemoryStore store = InMemoryStore.getInstance();
            Zorba zorba = Zorba.getInstance(store);

            XQuery xquery = zorba.compileQuery(query);
            String result = xquery.printPlanAsDOT();

            xquery.destroy();
            xquery.Dispose();
            
            zorba.shutdown();
            InMemoryStore.shutdown(store);
            
            return result;
        }

        static String readFile(String file) {
            System.Text.StringBuilder sb = new System.Text.StringBuilder();
            using (StreamReader sr = File.OpenText(file)) {
                String line = "";
                while ( (line = sr.ReadLine()) != null) {
                    sb.Append(line+"\n");
                }
            }
            return sb.ToString();
        }

        static void Main(string[] args)
        {
            System.Console.WriteLine("Running: XQuery execute from file test06.xq - printPlanAsDOT");

            String query = readFile("test06.xq");
            
            System.Console.WriteLine("Query: " + query);
            String result;
            try {
                result = test(query);
            } catch(Exception e) {
                System.Console.WriteLine("Failed");
                Console.WriteLine("{0} Exception caught.", e);
                return;
            }
            System.Console.WriteLine(result);
            System.Console.WriteLine("Success");

        }
    }
}
