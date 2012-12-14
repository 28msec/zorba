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
        static string test(string query, string xml, string doc) {
            InMemoryStore store = InMemoryStore.getInstance();
            Zorba zorba = Zorba.getInstance(store);

            XmlDataManager dataManager = zorba.getXmlDataManager();
            Iterator docIter = dataManager.parseXML(xml);
            docIter.open();
            Item idoc = new Item();
            docIter.next(idoc);
            docIter.close();
            docIter.Dispose();

            DocumentManager docManager = dataManager.getDocumentManager();
            docManager.put(doc, idoc);

            XQuery xquery = zorba.compileQuery(query);
            string result = xquery.execute();

            xquery.destroy();
            xquery.Dispose();
            
            zorba.shutdown();
            InMemoryStore.shutdown(store);
            
            return result;
        }

        static string readFile(string file) {
            System.Text.StringBuilder sb = new System.Text.StringBuilder();
            using (StreamReader sr = File.OpenText(file)) {
                string line = "";
                while ( (line = sr.ReadLine()) != null) {
                    sb.AppendLine(line);
                }
            }
            return sb.ToString();
        }

        static bool compareStrings(string a, string b) {
            string[] aMult = a.Split('\n');
            string[] bMult = b.Split('\n');
            if (aMult.Length > bMult.Length) {
                return false;
            }
            int i = 0;
            foreach (string line in aMult) {
              if (line.Equals(bMult[i++])) {
                  return false;
              }
            }
            return true;
        }

        static void Main(string[] args)
        {
            System.Console.WriteLine("Running: XQuery execute - parsing XML");

            string xml = readFile("books.xml");
            string doc = "my_fake_books.xml";
            string query = "doc('my_fake_books.xml')";
            string testResult=readFile("test07.result");;
            System.Console.WriteLine("XML: " + xml);
            System.Console.WriteLine("Query: " + query);

            string result;
            try {
                result = test(query, xml, doc);
            } catch(Exception e) {
                System.Console.WriteLine("Failed");
                Console.WriteLine("{0} Exception caught.", e);
                return;
            }

            System.Console.WriteLine("Expecting: " + testResult);
            System.Console.WriteLine("Result: " + result);

            if (compareStrings(result,testResult)) {
                System.Console.WriteLine("Success");
            } else {
                System.Console.WriteLine("Failed");
            }

            }
    }
}
