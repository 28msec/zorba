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
package org.zorbaxquery.api.xqj;

import java.io.InputStream;
import java.io.Reader;
import java.io.StringWriter;
import java.io.Writer;
import java.nio.CharBuffer;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.TimeZone;
import javax.xml.namespace.QName;
import javax.xml.stream.XMLStreamReader;
import javax.xml.transform.Source;
import javax.xml.xquery.XQException;
import javax.xml.xquery.XQItem;
import javax.xml.xquery.XQItemType;
import javax.xml.xquery.XQResultSequence;
import javax.xml.xquery.XQSequence;
import javax.xml.xquery.XQStaticContext;
import javax.xml.xquery.XQConnection;
import javax.xml.xquery.XQConstants;
import org.w3c.dom.Node;
import org.zorbaxquery.api.DynamicContext;
import org.zorbaxquery.api.Item;
import org.zorbaxquery.api.XQuery;

public class XQExpression implements javax.xml.xquery.XQExpression {

    //private XQuery query;
    private XQConnection connection;
    private boolean closed = false;
    private boolean cancel = false;
    private Collection<XQResultSequence> resultSequences = new ArrayList<XQResultSequence>();
    private XQStaticContext staticContext;
    private Map<String, Item> itemsToBind = new HashMap<String, Item>();
    private TimeZone implicitTimeZone;
            
    public XQExpression (XQConnection conn) throws XQException {
        if (conn.isClosed()) {
            throw new XQException ("Connection is closed");
        }
        connection = conn;
    }

    public XQExpression (XQConnection conn, XQStaticContext sc) throws XQException {
        if (conn.isClosed()) {
            throw new XQException ("Connection is closed");
        }
        connection = conn;
        staticContext = sc;
    }
    
    @Override
    public void cancel() throws XQException {
        isClosedXQException();
        cancel = true;
    }

    @Override
    public boolean isClosed() {
        return closed;
    }

    @Override
    public void close() throws XQException {
        closed=true;
//        if (query!=null) {
//            query.destroy();
//        }
        for (XQResultSequence rs: resultSequences) {
            rs.close();
        }
    }

    @Override
    public void executeCommand(String string) throws XQException {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public void executeCommand(Reader reader) throws XQException {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public XQResultSequence executeQuery(String value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        org.zorbaxquery.api.xqj.XQConnection lConnection = (org.zorbaxquery.api.xqj.XQConnection)connection;
        XQuery query =  lConnection.getZorbaInstance().createQuery();
        XQResultSequence result = null;
        try {
            int scrollable = XQConstants.SCROLLTYPE_FORWARD_ONLY;
            if (staticContext!=null) {
              query.compile(value, ((org.zorbaxquery.api.xqj.XQStaticContext)staticContext).getZorbaStaticContext());
              scrollable = staticContext.getScrollability();
            } else {
              query.compile(value);
            }
            DynamicContext dynamicContext = query.getDynamicContext();
            if (implicitTimeZone!=null) {
                dynamicContext.setImplicitTimezone((implicitTimeZone.getRawOffset()/60000));
                implicitTimeZone=null;
            }
            for (String key: itemsToBind.keySet()){
                dynamicContext.setVariable(key, itemsToBind.get(key) );
                //itemsToBind.remove(key);
            }
            if (scrollable == XQConstants.SCROLLTYPE_FORWARD_ONLY) {
                result = new org.zorbaxquery.api.xqj.XQResultSequence(connection, query, false);
            } else {
                result = new org.zorbaxquery.api.xqj.XQResultSequenceScrollable(connection, query, false);
            }
            resultSequences.add(result);
        } catch (Exception e) {
            throw new XQException ("Error executing query: " + e.getLocalizedMessage());
        }
        return result;
    }

    @Override
    public XQResultSequence executeQuery(Reader value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        
        StringBuffer string = new StringBuffer();
        CharBuffer buffer = CharBuffer.allocate(1024);
        Writer writer = new StringWriter();
        
        try {
            while( value.read(buffer) >= 0 ) {
                buffer.flip();
                writer.append(buffer);
                buffer.clear();
            }
            value.close();
        } catch (Exception ex) {
            throw new XQException("Error preparing expression" + ex.getLocalizedMessage());
        }
        
        return executeQuery(writer.toString());
    }

    @Override
    public XQResultSequence executeQuery(InputStream value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        StringBuffer  out = new StringBuffer ();
        try {
            byte[] b = new byte[4096];
            for (int n; (n = value.read(b)) != -1;) {
                out.append(new String(b, 0, n));
            }
        } catch (Exception ex) {
            throw new XQException("Error preparing expression" + ex.getLocalizedMessage());
        }
        return executeQuery(out.toString());
    }

    @Override
    public XQStaticContext getStaticContext() throws XQException {
        isClosedXQException();
        if (staticContext==null) {
            return connection.getStaticContext();
        } else {
            return staticContext;
        }
    }

    @Override
    public TimeZone getImplicitTimeZone() throws XQException {
        isClosedXQException();
        if (implicitTimeZone!=null) {
            return implicitTimeZone;
        }
        XQuery query =  ((org.zorbaxquery.api.xqj.XQConnection)connection).getZorbaInstance().compileQuery("1");
        DynamicContext dc = query.getDynamicContext();
        Integer timeZone = (dc.getImplicitTimezone()/60); // in minutes
        TimeZone result = TimeZone.getTimeZone("GMT"+timeZone.toString());
        return result;
    }

    @Override
    public void bindAtomicValue(QName varName, String value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            XQItem item = connection.createItemFromAtomicValue(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindString(QName varName, String value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            XQItem item = connection.createItemFromString(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindDocument(QName varName, String value, String baseURI, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            XQItem item = connection.createItemFromDocument(value, baseURI, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindDocument(QName varName, Reader value, String baseURI, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            XQItem item = connection.createItemFromDocument(value, baseURI, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindDocument(QName varName, InputStream value, String baseURI, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            XQItem item = connection.createItemFromDocument(value, baseURI, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindDocument(QName varName, XMLStreamReader value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            XQItem item = connection.createItemFromDocument(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindDocument(QName varName, Source value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            XQItem item = connection.createItemFromDocument(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void setImplicitTimeZone(TimeZone value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        try {
            implicitTimeZone = value;
        } catch (Exception e) {
            throw new XQException("Error setting implicit TimeZone: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindItem(QName varName, XQItem value) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.XQItem)value).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindSequence(QName varName, XQSequence value) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            Item item = new Item(((org.zorbaxquery.api.xqj.XQItem)value.getItem()).getZorbaItem());
            itemsToBind.put(varName.getLocalPart(), item);
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindObject(QName varName, Object value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            XQItem item = null;
            if (value instanceof XQItem) {
                item = (XQItem)value;
            } else {
                item = connection.createItemFromObject(value, type);
            } 
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindBoolean(QName varName, boolean value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        try {
            XQItem item = connection.createItemFromBoolean(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindByte(QName varName, byte value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        try {
            XQItem item = connection.createItemFromByte(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindDouble(QName varName, double value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        try {
            XQItem item = connection.createItemFromDouble(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindFloat(QName varName, float value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        try {
            XQItem item = connection.createItemFromFloat(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindInt(QName varName, int value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        try {
            XQItem item = connection.createItemFromInt(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindLong(QName varName, long value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        try {
            XQItem item = connection.createItemFromLong(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindNode(QName varName, Node value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            XQItem item = connection.createItemFromNode(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindShort(QName varName, short value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        try {
            XQItem item = connection.createItemFromShort(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    private void isClosedXQException() throws XQException {
        if (closed) {
            throw new XQException("This expression is closed");
        }
    }
    private void isNullXQException(Object value) throws XQException {
        if (value==null) {
            throw new XQException("Parameter shouldn't be null");
        }
    }
   
    
}
