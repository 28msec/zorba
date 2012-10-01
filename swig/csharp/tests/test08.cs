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
    class Program
    {
        
        static public void printIterator(Iterator iterator, String pre) {
          Item item = new Item();
          iterator.open();
          while (iterator.next(item)) {
              printItem(item, pre);
          }
          item.Dispose();
          iterator.close();
          iterator.Dispose();
        }

         
        static public void printItem(Item item, String pre) {
          if (item.isAtomic()) {
            Item typeItem = item.getType();
            System.Console.WriteLine(pre + "Leaf Atomic: \"" + item.getStringValue() + "\" \ttype:" + typeItem.getStringValue());
            typeItem.Dispose();
            return;
          }

          if (item.isNode()) {
            int kind = item.getNodeKind();
            if (kind ==  0) { // anyNode
              System.Console.WriteLine(pre + "Any node");
              System.Console.WriteLine( pre + "  Children:");
              printIterator(item.getChildren(), pre+"    ");
            }
            if (kind ==  1) { // doc
              System.Console.WriteLine( pre + "Doc" );
              System.Console.WriteLine( pre + "  Children:" );
              printIterator(item.getChildren(), pre+"    ");
            }
            if (kind == 2) { // element
              Item nodeName = new Item();
              item.getNodeName(nodeName);
              Item typeItem = item.getType();            
              System.Console.WriteLine( pre + "Start Element: ", nodeName.getStringValue(), " \ttype:", typeItem.getStringValue() );
              System.Console.WriteLine( pre + "  Attributes:" );
              printIterator(item.getAttributes(), pre+"    ");
              System.Console.WriteLine( pre + "  Children:" );
              printIterator(item.getChildren(), pre+"    ");
              System.Console.WriteLine( pre + "End  Element: " + nodeName.getStringValue() );
              typeItem.Dispose();
              nodeName.Dispose();
            }
            if (kind == 3) { // attribute
              Item nodeName = new Item();
              item.getNodeName(nodeName);
              Item typeItem = item.getType();            
              System.Console.WriteLine( pre + "Attribute: " + nodeName.getStringValue() + "= \"" + item.getStringValue() + "\" \ttype:" + typeItem.getStringValue());
              System.Console.WriteLine( pre+"  Atomization value:");
              printIterator(item.getAtomizationValue(), pre+"    ");
              typeItem.Dispose();
              nodeName.Dispose();
            }
            if (kind == 4) { // text
              Item typeItem = item.getType();
              System.Console.WriteLine( pre + "Text: " + item.getStringValue() + " \ttype:" + typeItem.getStringValue() );
              System.Console.WriteLine( pre + "  Atomization value:" );
              printIterator(item.getAtomizationValue(), pre+"    ");
              typeItem.Dispose();
            }
            if (kind == 5) { // pi
              Item nodeName = new Item();
              item.getNodeName(nodeName);
              System.Console.WriteLine( pre + "Pi: " + nodeName.getStringValue() );
              nodeName.Dispose();
            }
            if (kind == 6) { // comment
              System.Console.WriteLine( pre + "Comment: " + item.getStringValue() );
            }
          } else {
            System.Console.WriteLine( pre+"Item not Node, not Atomic");
          }
        }

        static void test(String query) {
            InMemoryStore store = InMemoryStore.getInstance();
            Zorba zorba = Zorba.getInstance(store);

            XQuery xquery = zorba.compileQuery(query);

            Iterator iterator = xquery.iterator();
            printIterator(iterator, "");
            
            xquery.destroy();
            xquery.Dispose();
            
            zorba.shutdown();
            InMemoryStore.shutdown(store);
            
            return;
        }

        static void Main(string[] args)
        {
            System.Console.WriteLine("Running: XQuery execute - Get Iterator and print info from its items");

            String query = "(1, xs:int(2),\"bla\", <a><b att=\"{(3, xs:int(4),\"foo\", \"bar\")}\"/>text<!--a comment--><?pi?></a>)";
            System.Console.WriteLine("Query: " + query);
            try {
                test(query);
            } catch(Exception e) {
                System.Console.WriteLine("Failed");
                Console.WriteLine("{0} Exception caught.", e);
                return;
            }
            
            System.Console.WriteLine("Success");
        }
    }
}
