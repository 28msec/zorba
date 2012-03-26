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
import javax.xml.xquery.XQException;
import javax.xml.xquery.XQItem;
import javax.xml.xquery.XQItemType;
import org.w3c.dom.Node;
import org.xml.sax.ContentHandler;
import org.zorbaxquery.api.Item;

public class XQSequence implements javax.xml.xquery.XQSequence {

    private boolean closed = false;
    private boolean forwardOnly = true;
    private boolean currentItemGet = false;
    private Collection<XQItem> content = new ArrayList<XQItem>();
    private int position = 0;
    int size = 0;

    public XQSequence(javax.xml.xquery.XQSequence sequence) throws XQException {
        try {
            while (sequence.next()) {
                XQItem tmpItem = sequence.getItem();
                Item item = null;
                if (tmpItem instanceof XQItem) {
                    item = ((org.zorbaxquery.api.xqj.XQItem)tmpItem).getZorbaItem();
                } else if (tmpItem instanceof XQResultItem) {
                    item = ((org.zorbaxquery.api.xqj.XQResultItem)tmpItem).getZorbaItem();
                }
                content.add(new org.zorbaxquery.api.xqj.XQItem(item));
            }
            size = content.size();
        } catch (Exception e) {
            throw new XQException("Error iterating from origin object" + e.getLocalizedMessage());
        }
        
    }

    public XQSequence(java.util.Iterator iterator) {
        while (iterator.hasNext()) {
            Object o = iterator.next();
            if (o instanceof XQItem) {
                content.add((XQItem)o);
            }
        }
        size = content.size();
    }

    @Override
    public boolean absolute(int i) throws XQException {
        isClosedXQException();
        boolean result  = false;
        position = 0;
        if (size>0) {
            if (i>0) {
                if (i>size) {
                    position = size+1;
                } else {
                    position = i;
                    result = true;
                }
            } else if(i<0) {
                if (i>(-size)) {
                    position = size+i+1;
                    result = true;
                }
            }
        }
        return result;
    }

    @Override
    public void afterLast() throws XQException {
        isClosedXQException();
        position = content.size()+1;
    }

    @Override
    public void beforeFirst() throws XQException {
        isClosedXQException();
        position = 0;
    }

    @Override
    public void close() throws XQException {
        closed = true;
        for (XQItem item: content) {
            item.close();
        }
    }

    @Override
    public boolean isClosed() {
        return closed;
    }

    @Override
    public int count() throws XQException {
        isClosedXQException();
        return size;
    }

    @Override
    public int getPosition() throws XQException {
        isClosedXQException();
        return position;
    }

    @Override
    public boolean isOnItem() throws XQException {
        isClosedXQException();
        return (position>0) && (position<(content.size()+1));
    }

    @Override
    public boolean isScrollable() throws XQException {
        isClosedXQException();
        return !forwardOnly;
    }

    @Override
    public boolean first() throws XQException {
        isClosedXQException();
        boolean result = false;
        if (content.size()>0) {
            position = 1;
            result = true;
        }
        return result;
    }

    @Override
    public XQItem getItem() throws XQException {
        isClosedXQException();
        isItemGetXQException();
        return (XQItem)content.toArray()[position-1];
    }

    @Override
    public XMLStreamReader getSequenceAsStream() throws XQException {
        isClosedXQException();
        isItemGetXQException();
        StringBuffer sb = new StringBuffer();
        for (XQItem item: content) {
            sb.append(item.getItemAsString(null));
        }
        XMLInputFactory fac = XMLInputFactory.newInstance();
        Reader read = new StringReader(sb.toString());
        XMLStreamReader result = null;
        try {
            result = fac.createXMLStreamReader(read);
        } catch (XMLStreamException ex) {
            throw new XQException("Problem reading the stream: " + sb + " - with error: " + ex.getLocalizedMessage());
        }
        return result;
    }

    @Override
    public String getSequenceAsString(Properties prprts) throws XQException {
        isClosedXQException();
        isItemGetXQException();
        StringBuffer sb = new StringBuffer();
        for (XQItem item: content) {
            sb.append(item.getItemAsString(null));
        }
        return sb.toString();
    }

    @Override
    public boolean isAfterLast() throws XQException {
        isClosedXQException();
        boolean result = false;
        if (size>0) {
            result = position==size+1;
        }
        return result;
    }

    @Override
    public boolean isBeforeFirst() throws XQException {
        isClosedXQException();
        boolean result = false;
        if (content.size()>0) {
            result = position==0;
        }
        return result;
    }

    @Override
    public boolean isFirst() throws XQException {
        isClosedXQException();
        boolean result = false;
        if (content.size()>0) {
            result = position==1;
        }
        return result;
    }

    @Override
    public boolean isLast() throws XQException {
        isClosedXQException();
        boolean result = false;
        if (size>0) {
            result = position==size;
        }
        return result;
    }

    @Override
    public boolean last() throws XQException {
        isClosedXQException();
        boolean result = false;
        if (size>0) {
            position = size;
            result = true;
        }
        return result;
    }

    @Override
    public boolean next() throws XQException {
        isClosedXQException();
        boolean result = false;
        if ((position<=size) && (size>0)) {
            result = (position<size);
            position++;
        }
        return result;
    }

    @Override
    public boolean previous() throws XQException {
        isClosedXQException();
        boolean result = false;
        if ((position>0) && (size>0)) {
            result = (position>1);
            position--;
        }
        return result;
    }

    @Override
    public boolean relative(int i) throws XQException {
        isClosedXQException();
        boolean result  = false;
        if ((i!=0) && (size>0)) {
            position = position + i;
            if (position<0) {
                position = 0;
            } else if (position>size) {
                position=size+1;
            } else {
                result = true;
            }
        }
        return result;
    }

    @Override
    public void writeSequence(OutputStream out, Properties prprts) throws XQException {
        isClosedXQException();
        isItemGetXQException();
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
        isItemGetXQException();
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
        isItemGetXQException();
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
        isItemGetXQException();
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
        return getItem().getBoolean();
    }

    @Override
    public byte getByte() throws XQException {
        isClosedXQException();
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
        return getItem().getFloat();
    }

    @Override
    public int getInt() throws XQException {
        isClosedXQException();
        return getItem().getInt();
    }

    @Override
    public XQItemType getItemType() throws XQException {
        isClosedXQException();
        return getItem().getItemType();
    }

    @Override
    public String getAtomicValue() throws XQException {
        isClosedXQException();
        return getItem().getAtomicValue();
    }

    @Override
    public long getLong() throws XQException {
        isClosedXQException();
        return getItem().getLong();
    }

    @Override
    public Node getNode() throws XQException {
        isClosedXQException();
        return getItem().getNode();
    }

    @Override
    public URI getNodeUri() throws XQException {
        isClosedXQException();
        return getItem().getNodeUri();
    }

    @Override
    public Object getObject() throws XQException {
        isClosedXQException();
        return getItem().getObject();
    }

    @Override
    public XMLStreamReader getItemAsStream() throws XQException {
        isClosedXQException();
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
        isNullXQException(xqit);
        return getItem().instanceOf(xqit);
    }

    @Override
    public void writeItem(OutputStream out, Properties prprts) throws XQException {
        isClosedXQException();
        isNullXQException(out);
        getItem().writeItem(out, prprts);
    }

    @Override
    public void writeItem(Writer writer, Properties prprts) throws XQException {
        isClosedXQException();
        isNullXQException(writer);
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
    private void isItemGetXQException() throws XQException {
        if (forwardOnly && currentItemGet) {
            throw new XQException("Item already consumed on a forward-only sequence");
        }
    }
    private void isNullXQException(Object value) throws XQException {
        if (value==null) {
            throw new XQException("Parameter shouldn't be null");
        }
    }
}
