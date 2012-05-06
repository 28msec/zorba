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
package api_test;


import java.io.BufferedReader;
import java.io.FileReader;
import java.net.URI;
import java.net.URISyntaxException;
import javax.xml.namespace.QName;

import org.zorbaxquery.api.xqj.XQDataSource;
import javax.xml.xquery.XQConnection;
import javax.xml.xquery.XQException;
import javax.xml.xquery.XQExpression;
import javax.xml.xquery.XQItem;
import javax.xml.xquery.XQItemType;
import javax.xml.xquery.XQSequence;
import org.zorbaxquery.api.Collection;
import org.zorbaxquery.api.CollectionManager;
import org.zorbaxquery.api.InMemoryStore;
import org.zorbaxquery.api.Item;
import org.zorbaxquery.api.ItemFactory;
import org.zorbaxquery.api.ItemSequence;
import org.zorbaxquery.api.StaticCollectionManager;
import org.zorbaxquery.api.XQuery;
import org.zorbaxquery.api.XmlDataManager;
import org.zorbaxquery.api.Zorba;
import org.zorbaxquery.api.xqj.XQCollection;
import org.zorbaxquery.api.xqj.XQCollectionManager;
import org.zorbaxquery.api.xqj.XQStaticCollectionManager;
import org.zorbaxquery.api.xqj.XQXmlDataManager;

public class Api_test {

  static 
  {
    System.loadLibrary ( "zorba_api" );
  }

  static boolean example_1() throws XQException
  {
      XQDataSource xqds = new XQDataSource();
      XQConnection xqc = xqds.getConnection();
      XQExpression xqe = xqc.createExpression();
      org.zorbaxquery.api.xqj.XQResultSequence xqs = (org.zorbaxquery.api.xqj.XQResultSequence) xqe.executeQuery("1,2,3");
      XQStaticCollectionManager colManager =  xqs.getStaticCollectionManager();
      xqc.close();
      xqc.close();
      return true;
  }

  static boolean example_2 () throws XQException
  {
      StringBuilder strBuilder = new StringBuilder();
      try {
            BufferedReader in = new BufferedReader(new FileReader("managers/module1.xq"));
            String str;
            while ((str = in.readLine()) != null) {
                strBuilder.append(str);
            }
            in.close();
      } catch (Exception e) {
          throw new XQException("Error reading file for test: " + e.getLocalizedMessage());
      }
      XQDataSource xqds = new XQDataSource();
      XQConnection xqc = xqds.getConnection();
      XQExpression xqe = xqc.createExpression();
      org.zorbaxquery.api.xqj.XQResultSequence xqs = (org.zorbaxquery.api.xqj.XQResultSequence) xqe.executeQuery(strBuilder.toString());
      XQStaticCollectionManager colManager =  xqs.getStaticCollectionManager();
      boolean resultAdding = false;
      boolean resultDeleting = true;
      URI uri;
      QName qname;
      XQItemType type = null;
        try {
          uri = new URI("http://www.mod2.com/");
          qname = new QName("http://www.mod2.com/", "coll");
          type = xqc.createAtomicType( XQItemType.XQBASETYPE_QNAME, qname, uri);
        } catch (URISyntaxException e) {
            throw new XQException("Error creating QName: " + e.getLocalizedMessage());
        }
      XQItem colName = xqc.createItemFromString("coll",  type);
      colManager.createCollection(colName);
      resultAdding = colManager.isAvailableCollection(colName);
      colManager.deleteCollection(colName);
      resultDeleting = !colManager.isAvailableCollection(colName);
      xqc.close();
      return resultAdding && resultDeleting;
  }
  
  static boolean example_3a() throws XQException
  {
      StringBuilder strBuilder = new StringBuilder();
      try {
            BufferedReader in = new BufferedReader(new FileReader("managers/module1.xq"));
            String str;
            while ((str = in.readLine()) != null) {
                strBuilder.append(str);
            }
            in.close();
      } catch (Exception e) {
          throw new XQException("Error reading file for test: " + e.getLocalizedMessage());
      }
      XQDataSource xqds = new XQDataSource();
      org.zorbaxquery.api.xqj.XQConnection xqc = (org.zorbaxquery.api.xqj.XQConnection) xqds.getConnection();
      XQExpression xqe = xqc.createExpression();
      org.zorbaxquery.api.xqj.XQResultSequence xqs = (org.zorbaxquery.api.xqj.XQResultSequence) xqe.executeQuery(strBuilder.toString());
      XQStaticCollectionManager colManager =  xqs.getStaticCollectionManager();
      URI uri;
      QName qname;
      XQItemType type = null;
        try {
          uri = new URI("http://www.mod2.com/");
          qname = new QName("http://www.mod2.com/", "coll");
          type = xqc.createAtomicType( XQItemType.XQBASETYPE_QNAME, qname, uri);
        } catch (URISyntaxException e) {
            throw new XQException("Error creating QName: " + e.getLocalizedMessage());
        }
      XQItem colName = xqc.createItemFromString("coll",  type);
      colManager.createCollection(colName);
      XQCollection collection = colManager.getCollection(colName);
      
      XQXmlDataManager manager = xqc.getXmlDataManager();
      XQSequence data = manager.parseXML("<books><book>Book 1</book><book>Book 2</book></books>");
      collection.insertNodesFirst(data);
      
      colManager.deleteCollection(colName);
      boolean resultDeleting = !colManager.isAvailableCollection(colName);
      xqc.close();
      return resultDeleting;
  }

  static boolean example_3b() throws XQException
  {
      StringBuilder strBuilder = new StringBuilder();
      try {
            BufferedReader in = new BufferedReader(new FileReader("managers/module1.xq"));
            String str;
            while ((str = in.readLine()) != null) {
                strBuilder.append(str);
            }
            in.close();
      } catch (Exception e) {
          throw new XQException("Error reading file for test: " + e.getLocalizedMessage());
      }
    InMemoryStore store = InMemoryStore.getInstance();
    Zorba zorba = Zorba.getInstance ( store );
    XQuery query = zorba.compileQuery(strBuilder.toString());
    StaticCollectionManager manager = query.getStaticCollectionManager();
    
    
    ItemFactory factory = zorba.getItemFactory();
    Item name = factory.createQName("http://www.mod2.com/", "coll");
    
    manager.createCollection(name);
    Collection collection = manager.getCollection(name);

    XmlDataManager xmlManager = zorba.getXmlDataManager();
    Item data = xmlManager.parseXMLtoItem("<books><book>Book 1</book><book>Book 2</book></books>");
    ItemSequence sequence = new ItemSequence(data);
    collection.insertNodesLast(sequence);
    
    zorba.shutdown();
    InMemoryStore.shutdown ( store );

    return true;
  }

  static boolean example_4() throws XQException
  {
      XQDataSource xqds = new XQDataSource();
      org.zorbaxquery.api.xqj.XQConnection xqc = (org.zorbaxquery.api.xqj.XQConnection) xqds.getConnection();
      XQExpression xqe = xqc.createExpression();
      XQXmlDataManager xmlManager = xqc.getXmlDataManager();
      XQCollectionManager colManager =  xmlManager.getCollectionManager();
      xqc.close();
      xqc.close();
      return true;
  }

  static boolean example_5() throws XQException
  {
      XQDataSource xqds = new XQDataSource();
      org.zorbaxquery.api.xqj.XQConnection xqc = (org.zorbaxquery.api.xqj.XQConnection) xqds.getConnection();
      XQXmlDataManager xmlManager = xqc.getXmlDataManager();
      XQCollectionManager colManager =  xmlManager.getCollectionManager();
      boolean resultAdding = false;
      boolean resultDeleting = true;
      URI uri;
      QName qname;
      XQItemType type = null;
        try {
          uri = new URI("http://www.mod2.com/");
          qname = new QName("http://www.mod2.com/", "col2");
          type = xqc.createAtomicType( XQItemType.XQBASETYPE_QNAME, qname, uri);
        } catch (URISyntaxException e) {
            throw new XQException("Error creating QName: " + e.getLocalizedMessage());
        }
      XQItem colName = xqc.createItemFromString("col2",  type);
      colManager.createCollection(colName);
      resultAdding = colManager.isAvailableCollection(colName);
      colManager.deleteCollection(colName);
      resultDeleting = !colManager.isAvailableCollection(colName);
      xqc.close();
      return resultAdding && resultDeleting;
  }
  static boolean example_6a() throws XQException
  {
    InMemoryStore store = InMemoryStore.getInstance();
    Zorba zorba = Zorba.getInstance ( store );
    XmlDataManager xmlManager = new XmlDataManager(zorba.getXmlDataManager());
    CollectionManager manager = new CollectionManager(xmlManager.getCollectionManager());

    ItemFactory factory = zorba.getItemFactory();
    Item name = factory.createQName("http://www.zorba-xquery.com/", "aaa");
    manager.createCollection(name);
    boolean resultAdding = manager.isAvailableCollection(name);
    Collection collection = null;
    //Item data = new Item();
    if (resultAdding) {
      collection = manager.getCollection(name);
      Item data = xmlManager.parseXMLtoItem("<books><book>Book 1</book><book>Book 2</book></books>");
      collection.insertNodesLast(new ItemSequence(data));
    }
    collection.delete();
    
    zorba.shutdown();
    InMemoryStore.shutdown ( store );
    return true;
  }

  static boolean example_6b() throws XQException
  {
      XQDataSource xqds = new XQDataSource();
      org.zorbaxquery.api.xqj.XQConnection xqc = (org.zorbaxquery.api.xqj.XQConnection) xqds.getConnection();
      XQXmlDataManager xmlManager = xqc.getXmlDataManager();
      XQCollectionManager colManager =  xmlManager.getCollectionManager();
      URI uri;
      QName qname;
      XQItemType type = null;
        try {
          uri = new URI("http://www.mod2.com/");
          qname = new QName("http://www.mod2.com/", "col2");
          type = xqc.createAtomicType( XQItemType.XQBASETYPE_QNAME, qname, uri);
        } catch (URISyntaxException e) {
            throw new XQException("Error creating QName: " + e.getLocalizedMessage());
        }
      XQItem colName = xqc.createItemFromString("col2",  type);
      colManager.createCollection(colName);
      XQCollection collection = colManager.getCollection(colName);
      colName.close();
      XQSequence data = xmlManager.parseXML("<books><book>Book 1</book><book>Book 2</book></books>");
      collection.insertNodesLast(data);
      xqc.close();
      return true;
  }

  public static void main ( String argv[] ) throws XQException
  {
    boolean res = false;

    System.out.println ("executing test 1" );
    res = example_1( );
    if ( !res ) 
      System.exit ( 1 ); 

    System.out.println ( "executing test 2" );
    res = example_2 ( );
    if (!res) 
      System.exit ( 1 ); 
  
    System.out.println ( "executing test 3a" );
    res = example_3a ( );
    if (!res) 
      System.exit ( 1 ); 
  
    System.out.println ( "executing test 3b" );
    res = example_3b ( );
    if (!res) 
      System.exit ( 1 ); 
    
    System.out.println ( "executing test 4" );
    res = example_4 ( );
    if (!res) 
      System.exit ( 1 ); 

    System.out.println ( "executing test 5" );
    res = example_5 ( );
    if (!res) 
      System.exit ( 1 ); 
    System.out.println ( "executing test 6a" );
    res = example_6a ( );
    if (!res) 
      System.exit ( 1 ); 

    System.out.println ( "executing test 6b" );
    res = example_6b ( );
    if (!res) 
      System.exit ( 1 ); 
    System.out.println ( "done." );

  } // main

} // class Test_Zorba

