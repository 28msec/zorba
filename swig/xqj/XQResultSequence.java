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

import java.io.OutputStream;
import java.io.Reader;
import java.io.StringReader;
import java.io.Writer;
import java.net.URI;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Properties;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import javax.xml.transform.Result;
import javax.xml.xquery.XQConnection;
import javax.xml.xquery.XQException;
import javax.xml.xquery.XQItem;
import javax.xml.xquery.XQItemType;
import org.w3c.dom.Node;
import org.xml.sax.ContentHandler;
import org.zorbaxquery.api.Item;
import org.zorbaxquery.api.Iterator;

public class XQResultSequence implements javax.xml.xquery.XQResultSequence {
    
    private boolean closed = false;
    private boolean delivered = false;
    //private boolean isonitem = false;
    private boolean consumedItem = false;
    private boolean iterDeleted = false;

    private XQConnection connection = null;
    private Iterator iter = null;
    private XQResultItem current = null;
    private Collection<XQResultItem> items = new ArrayList<XQResultItem>();
    private org.zorbaxquery.api.XQuery lQuery=null;
    private boolean preparedExpression;

    public XQResultSequence(XQConnection conn, org.zorbaxquery.api.XQuery query, boolean prepared) {
        lQuery = query;
        iter = query.iterator();
        iter.open();
        connection = conn;
        preparedExpression = prepared;
    }
    
    @Override
    public XQConnection getConnection() throws XQException {
        isClosedXQException();
        return connection;
    }

    @Override
    public boolean absolute(int i) throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

    @Override
    public void afterLast() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

    @Override
    public void beforeFirst() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

    @Override
    public void close() throws XQException {
        if (!closed) {
            closed = true;
            for (XQResultItem xitem: items){
                xitem.close();
            }
            items.removeAll(items);
            if (!iterDeleted) {
                if (iter.isOpen()) {
                    iter.close();
                    iter.delete();
                }
                if (!preparedExpression) {
                    lQuery.delete();
                }
            }
        }
    }

    @Override
    public boolean isClosed() {
        return closed;
    }

    @Override
    public int count() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

    @Override
    public int getPosition() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

    @Override
    public boolean isOnItem() throws XQException {
        isClosedXQException();
        return (current!=null);
    }

    @Override
    public boolean isScrollable() throws XQException {
        isClosedXQException();
        return false;
    }

    @Override
    public boolean first() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

    @Override
    public XQItem getItem() throws XQException {
        isClosedXQException();
        isItemDeliveredXQException();
        isOnItemXQException();

        delivered = true;
        consumedItem = true;
        return current;
    }

    @Override
    public XMLStreamReader getSequenceAsStream() throws XQException {
        isClosedXQException();
        isConsumedXQException();
        Properties properties = null;
        String str = getSequenceAsString(properties);
        XMLInputFactory fac = XMLInputFactory.newInstance();
        Reader read = new StringReader(str);
        XMLStreamReader result = null;
        try {
            result = fac.createXMLStreamReader(read);
        } catch (XMLStreamException ex) {
            throw new XQException("Problem reading the stream: " + str + " - with error: " + ex.getLocalizedMessage());
        }
        return result;
    }

    @Override
    public String getSequenceAsString(Properties prprts) throws XQException {
        isClosedXQException();
        isConsumedXQException();
        String result = null;
        try {
        /*
        if (item.isNode() && item.getNodeKind()==3) { //attribute node
            resultString = resultString.concat(item.getStringValue()).concat(" ");
        } else {
            resultString = resultString.concat(item.serialize().replace("&gt;", ">").replace("&lt;", "<")).concat(" ");
        }
         * 
         */
            if (iter.isOpen()) {
                iter.close();
                iter.delete();
            }
            iterDeleted = true;
            consumedItem = true;
            result = lQuery.execute().replace("&gt;", ">").replace("&lt;", "<");
        } catch (Exception e) {
            throw new XQException("Error getting stream: " + e.getLocalizedMessage());
        } finally {
            if (!preparedExpression) {
                lQuery.delete();
            }
        }
        return result;
    }

    @Override
    public boolean isAfterLast() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

    @Override
    public boolean isBeforeFirst() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

    @Override
    public boolean isFirst() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

    @Override
    public boolean isLast() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

    @Override
    public boolean last() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

    @Override
    public boolean next() throws XQException {
        isClosedXQException();
        Item lItem = new Item();
        current = null;
        if (iter.next(lItem)) {
            current = new XQResultItem(lItem, connection);
            items.add(current);
            delivered = false;
            lItem.delete();
        }
        return (current != null);
    }

    @Override
    public boolean previous() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

    @Override
    public boolean relative(int i) throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

    @Override
    public void writeSequence(OutputStream out, Properties prprts) throws XQException {
        isClosedXQException();
        isNullXQException(out);
        if (isOnItem()) {
            getItem().writeItem(out, prprts);
        }
        while (next()) {
            getItem().writeItem(out, prprts);
        }
    }

    @Override
    public void writeSequence(Writer writer, Properties prprts) throws XQException {
        isClosedXQException();
        isNullXQException(writer);
        if (isOnItem()) {
            getItem().writeItem(writer, prprts);
        }
        while (next()) {
            getItem().writeItem(writer, prprts);
        }
    }

    @Override
    public void writeSequenceToSAX(ContentHandler ch) throws XQException {
        isClosedXQException();
        isNullXQException(ch);
        if (isOnItem()) {
            getItem().writeItemToSAX(ch);
        }
        while (next()) {
            getItem().writeItemToSAX(ch);
        }
    }

    @Override
    public void writeSequenceToResult(Result result) throws XQException {
        isClosedXQException();
        isNullXQException(result);
        if (isOnItem()) {
            getItem().writeItemToResult(result);
        }
        while (next()) {
            getItem().writeItemToResult(result);
        }
    }

    @Override
    public boolean getBoolean() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return getItem().getBoolean();
    }

    @Override
    public byte getByte() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return getItem().getByte();
    }

    @Override
    public double getDouble() throws XQException {
        isClosedXQException();
        
        return getItem().getDouble();
    }

    @Override
    public float getFloat() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return getItem().getFloat();
    }

    @Override
    public int getInt() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return getItem().getInt();
    }

    @Override
    public XQItemType getItemType() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return current.getItemType();
    }

    @Override
    public String getAtomicValue() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return getItem().getAtomicValue();
    }

    @Override
    public long getLong() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return getItem().getLong();
    }

    @Override
    public Node getNode() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return getItem().getNode();
    }

    @Override
    public URI getNodeUri() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return current.getNodeUri();
    }

    @Override
    public Object getObject() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return getItem().getObject();
    }

    @Override
    public XMLStreamReader getItemAsStream() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return getItem().getItemAsStream();
    }

    @Override
    public String getItemAsString(Properties prprts) throws XQException {
        isClosedXQException();
        return getItem().getItemAsString(prprts);
    }

    @Override
    public short getShort() throws XQException {
        isClosedXQException();
        return getItem().getShort();
    }

    @Override
    public boolean instanceOf(XQItemType xqit) throws XQException {
        isClosedXQException();
        isOnItemXQException();
        isNullXQException(xqit);
        return current.instanceOf(xqit);
    }

    @Override
    public void writeItem(OutputStream out, Properties prprts) throws XQException {
        isClosedXQException();
        isNullXQException(out);
        isNullXQException(prprts);
        getItem().writeItem(out, prprts);
    }

    @Override
    public void writeItem(Writer writer, Properties prprts) throws XQException {
        isClosedXQException();
        isNullXQException(writer);
        isNullXQException(prprts);
        getItem().writeItem(writer, prprts);
    }

    @Override
    public void writeItemToSAX(ContentHandler ch) throws XQException {
        isClosedXQException();
        isNullXQException(ch);
        getItem().writeItemToSAX(ch);
    }

    @Override
    public void writeItemToResult(Result result) throws XQException {
        isClosedXQException();
        isNullXQException(result);
        getItem().writeItemToResult(result);
    }
    
    private void isClosedXQException() throws XQException {
        if (closed) {
            throw new XQException("This sequence is closed");
        }
    }
    private void isConsumedXQException() throws XQException {
        if (consumedItem) {
            throw new XQException("Items already consumed");
        }
    }
    private void isItemDeliveredXQException() throws XQException {
        if (delivered) {
            throw new XQException("Item already consumed");
        }
    }
    private void isOnItemXQException() throws XQException {
        if (current==null) {
            throw new XQException("There are no more items to consume");
        }
    }

    private void isNullXQException(Object value) throws XQException {
        if (value==null) {
            throw new XQException("Parameter shouldn't be null");
        }
    }
}
