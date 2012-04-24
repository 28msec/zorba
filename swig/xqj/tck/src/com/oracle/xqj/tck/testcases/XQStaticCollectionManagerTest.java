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
package com.oracle.xqj.tck.testcases;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.net.URI;
import java.net.URISyntaxException;
import javax.xml.namespace.QName;
import javax.xml.xquery.XQException;
import javax.xml.xquery.XQExpression;
import javax.xml.xquery.XQItem;
import javax.xml.xquery.XQItemType;
import org.zorbaxquery.api.xqj.XQResultSequence;
import javax.xml.xquery.XQSequence;
import org.zorbaxquery.api.xqj.XQCollection;
import org.zorbaxquery.api.xqj.XQStaticCollectionManager;
import org.zorbaxquery.api.xqj.XQXmlDataManager;

public class XQStaticCollectionManagerTest  extends XQJTestCase {

    public void testCollectionManager() throws XQException {
        org.zorbaxquery.api.xqj.XQConnection my_xqc;
        
        my_xqc = (org.zorbaxquery.api.xqj.XQConnection) xqds.getConnection();
        XQExpression xqe = my_xqc.createExpression();
        XQResultSequence xqs = (XQResultSequence) xqe.executeQuery("1,2,3");
        XQStaticCollectionManager colManager =  xqs.getStaticCollectionManager();
        try {
          my_xqc.close();
          my_xqc.close();
        } catch (XQException e) {
          junit.framework.Assert.fail("A-XQC-1.1: closing connection failed with message: " + e.getMessage());
        }

        junit.framework.Assert.assertEquals("A-XQC-1.2: closing a connection, closes dependent objects", true, xqs.isClosed());
        junit.framework.Assert.assertEquals("A-XQC-1.2: closing a connection, closes dependent objects", true, colManager.isClosed());
    }

    public void testCollectionManagerAdding() throws XQException {
        org.zorbaxquery.api.xqj.XQConnection my_xqc;
        StringBuilder strBuilder = new StringBuilder();
        try {
            BufferedReader in = new BufferedReader(new FileReader("module1.xq"));
            String str;
            while ((str = in.readLine()) != null) {
                strBuilder.append(str);
            }
            in.close();
        } catch (Exception e) {
          junit.framework.Assert.fail("Error reading query for test: " + e.getMessage());
        }
        my_xqc = (org.zorbaxquery.api.xqj.XQConnection) xqds.getConnection();
        XQExpression xqe = my_xqc.createExpression();
        XQResultSequence xqs = (XQResultSequence) xqe.executeQuery(strBuilder.toString());
        XQStaticCollectionManager colManager =  xqs.getStaticCollectionManager();
        boolean resultAdding = false;
        boolean resultDeleting = true;
        try {
          URI uri;
          QName qname;
          XQItemType type = null;
            try {
              uri = new URI("http://www.mod2.com/");
              qname = new QName("http://www.mod2.com/", "coll");
              type = my_xqc.createAtomicType( XQItemType.XQBASETYPE_QNAME, qname, uri);
            } catch (URISyntaxException ex) {
                junit.framework.Assert.fail("Error creating collection: " + ex.getMessage());
            }
          XQItem colName = my_xqc.createItemFromString("coll",  type);
          colManager.createCollection(colName);
          resultAdding = colManager.isAvailableCollection(colName);
          colManager.deleteCollection(colName);
          resultDeleting = colManager.isAvailableCollection(colName);
          my_xqc.close();
        } catch (Exception e) {
          junit.framework.Assert.fail("Error creating collection: " + e.getMessage());
        }

        junit.framework.Assert.assertEquals("Error creating collection: ", true, resultAdding);
        junit.framework.Assert.assertEquals("Error creating collection: ", false, resultDeleting);
    }


    public void testCollectionManagerEditing() throws XQException {
        org.zorbaxquery.api.xqj.XQConnection my_xqc;

        StringBuilder strBuilder = new StringBuilder();
        try {
            BufferedReader in = new BufferedReader(new FileReader("module1.xq"));
            String str;
            while ((str = in.readLine()) != null) {
                strBuilder.append(str);
            }
            in.close();
        } catch (Exception e) {
          junit.framework.Assert.fail("Error reading query for test: " + e.getMessage());
        }
        my_xqc = (org.zorbaxquery.api.xqj.XQConnection) xqds.getConnection();
        XQExpression xqe = my_xqc.createExpression();
        XQResultSequence xqs = (XQResultSequence) xqe.executeQuery(strBuilder.toString());
        XQStaticCollectionManager colManager =  xqs.getStaticCollectionManager();
        boolean result = false;
        try {
          URI uri;
          QName qname;
          XQItemType type = null;
            try {
              uri = new URI("http://www.mod2.com/");
              qname = new QName("http://www.mod2.com/", "coll");
              type = my_xqc.createAtomicType( XQItemType.XQBASETYPE_QNAME, qname, uri);
            } catch (URISyntaxException ex) {
                junit.framework.Assert.fail("Error creating collection: " + ex.getMessage());
            }
          XQItem colName = my_xqc.createItemFromString("coll",  type);
          colManager.createCollection(colName);
          XQCollection collection = colManager.getCollection(colName);
          
          
          XQXmlDataManager manager = my_xqc.getXmlDataManager();
          XQSequence data = manager.parseXML("<books><book>Book 1</book><book>Book 2</book></books>");
          collection.insertNodesFirst(data);
          
          my_xqc.close();
        } catch (Exception e) {
          junit.framework.Assert.fail("Error editing collection: " + e.getMessage());
        }

        junit.framework.Assert.assertEquals("Error editing collection: ", false, result);
    }
}
