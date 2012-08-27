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


import java.io.*;
import java.net.URI;
import java.net.URISyntaxException;
import java.util.Properties;
import javax.xml.namespace.QName;
import javax.xml.xquery.*;
import org.zorbaxquery.api.*;
import org.zorbaxquery.api.xqj.*;

public class Tests {

  static 
  {
    System.loadLibrary ( "zorba_api" );
  }

  static String getFile(String filename) throws FileNotFoundException, IOException {
    File file = new File(filename);
    FileInputStream fileStream = new FileInputStream(file);
    InputStreamReader reader = new InputStreamReader( fileStream, "UTF8" );
    BufferedReader    buffer = new BufferedReader( reader );
    String line;
    StringBuilder builder = new StringBuilder();
    while ( (line = buffer.readLine()) != null ) 
    {
      builder.append(line);
    }
    return builder.toString();
  }

  static boolean checkResult(String test, String queryResult) {
    System.out.println("Result:");
    System.out.println(queryResult);
    System.out.println("Expected:");
    System.out.println(test);
    return (queryResult.indexOf(test)>=0) || (test.indexOf(queryResult)>=0);    
  }

  static boolean test_1() throws XQException
  {
      ZorbaXQDataSource xqds = new ZorbaXQDataSource();
      XQConnection xqc = xqds.getConnection();
      XQExpression xqe = xqc.createExpression();
      org.zorbaxquery.api.xqj.ZorbaXQResultSequence xqs = (org.zorbaxquery.api.xqj.ZorbaXQResultSequence) xqe.executeQuery("1,2,3");
      ZorbaXQStaticCollectionManager colManager =  xqs.getStaticCollectionManager();
      xqc.close();
      xqc.close();
      return true;
  }


  static boolean test_2 () throws XQException
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
      ZorbaXQDataSource xqds = new ZorbaXQDataSource();
      XQConnection xqc = xqds.getConnection();
      XQExpression xqe = xqc.createExpression();
      org.zorbaxquery.api.xqj.ZorbaXQResultSequence xqs = (org.zorbaxquery.api.xqj.ZorbaXQResultSequence) xqe.executeQuery(strBuilder.toString());
      ZorbaXQStaticCollectionManager colManager =  xqs.getStaticCollectionManager();
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
  
  static boolean test_3a() throws XQException
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
      ZorbaXQDataSource xqds = new ZorbaXQDataSource();
      org.zorbaxquery.api.xqj.ZorbaXQConnection xqc = (org.zorbaxquery.api.xqj.ZorbaXQConnection) xqds.getConnection();
      XQExpression xqe = xqc.createExpression();
      org.zorbaxquery.api.xqj.ZorbaXQResultSequence xqs = (org.zorbaxquery.api.xqj.ZorbaXQResultSequence) xqe.executeQuery(strBuilder.toString());
      ZorbaXQStaticCollectionManager colManager =  xqs.getStaticCollectionManager();
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
      ZorbaXQCollection collection = colManager.getCollection(colName);
      
      ZorbaXQXmlDataManager manager = xqc.getXmlDataManager();
      XQSequence data = manager.parseXML("<books><book>Book 1</book><book>Book 2</book></books>");
      collection.insertNodesFirst(data);
      
      colManager.deleteCollection(colName);
      boolean resultDeleting = !colManager.isAvailableCollection(colName);
      xqc.close();
      return resultDeleting;
  }

  static boolean test_3b() throws XQException
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

  static boolean test_4() throws XQException
  {
      ZorbaXQDataSource xqds = new ZorbaXQDataSource();
      org.zorbaxquery.api.xqj.ZorbaXQConnection xqc = (org.zorbaxquery.api.xqj.ZorbaXQConnection) xqds.getConnection();
      XQExpression xqe = xqc.createExpression();
      ZorbaXQXmlDataManager xmlManager = xqc.getXmlDataManager();
      ZorbaXQCollectionManager colManager =  xmlManager.getCollectionManager();
      xqc.close();
      xqc.close();
      return true;
  }

  static boolean test_5() throws XQException
  {
      ZorbaXQDataSource xqds = new ZorbaXQDataSource();
      org.zorbaxquery.api.xqj.ZorbaXQConnection xqc = (org.zorbaxquery.api.xqj.ZorbaXQConnection) xqds.getConnection();
      ZorbaXQXmlDataManager xmlManager = xqc.getXmlDataManager();
      ZorbaXQCollectionManager colManager =  xmlManager.getCollectionManager();
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
  static boolean test_6a() throws XQException
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

  static boolean test_6b() throws XQException
  {
      ZorbaXQDataSource xqds = new ZorbaXQDataSource();
      org.zorbaxquery.api.xqj.ZorbaXQConnection xqc = (org.zorbaxquery.api.xqj.ZorbaXQConnection) xqds.getConnection();
      ZorbaXQXmlDataManager xmlManager = xqc.getXmlDataManager();
      ZorbaXQCollectionManager colManager =  xmlManager.getCollectionManager();
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
      ZorbaXQCollection collection = colManager.getCollection(colName);
      colName.close();
      XQSequence data = xmlManager.parseXML("<books><book>Book 1</book><book>Book 2</book></books>");
      collection.insertNodesLast(data);
      xqc.close();
      return true;
  }

  static boolean test_7() throws XQException
  {
    InMemoryStore store = InMemoryStore.getInstance();
    Zorba zorba = Zorba.getInstance ( store );
    String test = "Hello world!";
    ZorbaReaderWrapper stream = new ZorbaReaderWrapper(new StringReader("'"+test+"'"));
    XQuery query = zorba.compileQuery(stream);
    String queryResult = query.execute();
    boolean result = checkResult(test, queryResult);
    zorba.shutdown();
    InMemoryStore.shutdown ( store );
    return result;
  }

  static boolean test_8() throws XQException, UnsupportedEncodingException
  {
    InMemoryStore store = InMemoryStore.getInstance();
    Zorba zorba = Zorba.getInstance ( store );
    StringBuilder test = new StringBuilder();
    for (int i=0; i<20; i++) {
      test.append("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"); // 100 chars
    }
    String queryString = "'" + test.toString() + "'";
    ZorbaInputWrapper stream = new ZorbaInputWrapper(new ByteArrayInputStream(queryString.getBytes("UTF-8")));
    XQuery query = zorba.compileQuery(stream);
    String queryResult = query.execute();
    boolean result = checkResult(test.toString(), queryResult);
    zorba.shutdown();
    InMemoryStore.shutdown ( store );
    return result;
  }

  static boolean test_9() throws XQException, UnsupportedEncodingException
  {
    InMemoryStore store = InMemoryStore.getInstance();
    Zorba zorba = Zorba.getInstance ( store );
    String test = "<Hello><ab/><ax/>World</Hello>";
    ZorbaInputWrapper stream = new ZorbaInputWrapper(new ByteArrayInputStream(test.getBytes("UTF-8")));
    SerializationOptions opts = new SerializationOptions();
    opts.setIndent(SerializationOptions.Indent.ZORBA_API_INDENT_NO);
    XQuery query = zorba.compileQuery(stream);
    String queryResult = query.execute(opts);
    boolean result = checkResult(test, queryResult);
    query.destroy();
    zorba.shutdown();
    InMemoryStore.shutdown ( store );
    return result;
  }

  static boolean test_10() throws XQException, UnsupportedEncodingException
  {
    InMemoryStore store = InMemoryStore.getInstance();
    Zorba zorba = Zorba.getInstance ( store );
    String test = "<Hello><ab/><ax/>World</Hello>";
    ZorbaInputWrapper stream = new ZorbaInputWrapper(new ByteArrayInputStream(test.getBytes("UTF-8")));
    XQuery query = zorba.compileQuery(stream);
    ByteArrayOutputStream out = new ByteArrayOutputStream();
    ZorbaOutputWrapper OStream = new ZorbaOutputWrapper(out);
    query.execute(OStream);
    boolean result = checkResult(test, out.toString());
    query.destroy();
    zorba.shutdown();
    InMemoryStore.shutdown ( store );
    return result;
  }

  static boolean test_11a() throws XQException, FileNotFoundException, IOException
  {
    InMemoryStore store = InMemoryStore.getInstance();
    Zorba zorba = Zorba.getInstance ( store );
    String test = getFile("managers/utf.txt");
    org.zorbaxquery.api.ZorbaReaderWrapper stream = new org.zorbaxquery.api.ZorbaReaderWrapper(new StringReader("'"+test+"'"));
    XQuery query = zorba.compileQuery(stream);
    SerializationOptions opts = new SerializationOptions();
    opts.setOmitXMLDeclaration(SerializationOptions.OmitXMLDeclaration.ZORBA_API_OMIT_XML_DECLARATION_YES);
    String queryResult = query.execute(opts);
    boolean result = checkResult(test, queryResult);
    zorba.shutdown();
    InMemoryStore.shutdown ( store );
    return result;
  }

  static boolean test_11b() throws XQException, FileNotFoundException, IOException
  {
    String test = getFile("managers/utf.txt");
    ZorbaXQDataSource xqds = new ZorbaXQDataSource();
    XQConnection xqc = xqds.getConnection();
    XQExpression xqe = xqc.createExpression();
    org.zorbaxquery.api.xqj.ZorbaXQResultSequence xqs = (org.zorbaxquery.api.xqj.ZorbaXQResultSequence) xqe.executeQuery("'"+test+"'");
    ZorbaXQStaticCollectionManager colManager =  xqs.getStaticCollectionManager();
    Properties prpts = new Properties();
    String queryResult =xqs.getSequenceAsString(prpts);
    boolean result = checkResult(test, queryResult);
    xqc.close();
    xqc.close();
    return true;
  }

} // class Test_Zorba

