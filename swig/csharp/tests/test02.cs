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
    class Program
    {
        static void Main(string[] args)
        {
            System.Console.WriteLine("Running: Compile query string");

            InMemoryStore store = InMemoryStore.getInstance();
            Zorba zorba = Zorba.getInstance(store);
            XQuery xquery = zorba.compileQuery("(1,2,3,4,5)");
            Iterator iter = xquery.iterator();
            iter.open();
            Item item = new Item();
            while (iter.next(item)) {
              System.Console.WriteLine(item.getStringValue());
            }
            iter.close();
            iter.Dispose();
            xquery.Dispose();
            zorba.shutdown();
            InMemoryStore.shutdown(store);

            System.Console.WriteLine("Success");
        }
    }
}
