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
using System.IO;
using org.zorbaxquery.api;

namespace ZorbaApplication
{
    class Program
    {
        
        static void Main(string[] args)
        {
            System.Console.WriteLine("Running: XQuery execute - printPlanAsDOT");
            InMemoryStore store = InMemoryStore.getInstance();
            Zorba zorba = Zorba.getInstance(store);

            System.Console.WriteLine("Executing: test06.xq");
            
            System.Text.StringBuilder sb = new System.Text.StringBuilder();
            using (StreamReader sr = File.OpenText("test04.xq")) {
                String line = "";
                while ( (line = sr.ReadLine()) != null) {
                    sb.Append(line+"\n");
                }
            }
            
            XQuery xquery = zorba.compileQuery(sb.ToString());
            System.Console.WriteLine(xquery.printPlanAsDOT());
            xquery.Dispose();

            zorba.shutdown();
            InMemoryStore.shutdown(store);
            System.Console.WriteLine("Success");
        }
    }
}

