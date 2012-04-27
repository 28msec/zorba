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
import java.util.TimeZone;
import javax.xml.namespace.QName;
import javax.xml.stream.XMLStreamReader;
import javax.xml.transform.Source;
import javax.xml.xquery.XQException;
import javax.xml.xquery.XQItem;
import javax.xml.xquery.XQItemType;
import javax.xml.xquery.XQResultSequence;
import javax.xml.xquery.XQSequence;
import javax.xml.xquery.XQSequenceType;
import javax.xml.xquery.XQStaticContext;
import org.w3c.dom.Node;
import org.zorbaxquery.api.XQuery;
import org.zorbaxquery.api.Zorba;
import javax.xml.xquery.XQConnection;
import java.util.Collection;
import java.util.ArrayList;
import javax.xml.stream.XMLOutputFactory;
import javax.xml.stream.XMLStreamWriter;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.sax.SAXSource;
import javax.xml.transform.stax.StAXResult;
import javax.xml.transform.stax.StAXSource;
import javax.xml.transform.stream.StreamResult;
import javax.xml.transform.stream.StreamSource;
import org.zorbaxquery.api.DynamicContext;
import org.zorbaxquery.api.Item;
import org.zorbaxquery.api.Iterator;
import org.zorbaxquery.api.XmlDataManager;

public class XQPreparedExpression implements javax.xml.xquery.XQPreparedExpression {

    private XQuery query;
    private XQConnection connection;
    private boolean closed;
    private Collection<XQResultSequence> resultSequences = new ArrayList<XQResultSequence>();
    private DynamicContext dynamicContext;
    private XmlDataManager xmlDataManager;
    private XQStaticContext staticContext;
    private Collection<String> itemsBounded = new ArrayList<String>();

    
    public XQPreparedExpression (XQConnection conn, String string) throws XQException {
        if (conn.isClosed()) {
            throw new XQException ("Connection is closed");
        }
        closed = false;
        connection = conn;
        Zorba zorba = ((org.zorbaxquery.api.xqj.XQConnection)connection).getZorbaInstance(); 
        try {
            query =  zorba.compileQuery(string);
            dynamicContext = query.getDynamicContext();
            xmlDataManager = ((org.zorbaxquery.api.xqj.XQConnection)connection).getZorbaInstance().getXmlDataManager();
        } catch (Exception e) {
            throw new XQException ("Error creating new Prepared expression with static context: " + e.getLocalizedMessage());
        
        }
    }
    public XQPreparedExpression (XQConnection conn, String string, XQStaticContext sc) throws XQException {
        if (conn.isClosed()) {
            throw new XQException ("Connection is closed");
        }
        closed = false;
        connection = conn;
        Zorba zorba = ((org.zorbaxquery.api.xqj.XQConnection)connection).getZorbaInstance(); 
        try {
            query =  zorba.compileQuery(string, ((org.zorbaxquery.api.xqj.XQStaticContext)sc).getZorbaStaticContext());
            dynamicContext = query.getDynamicContext();
            xmlDataManager = ((org.zorbaxquery.api.xqj.XQConnection)connection).getZorbaInstance().getXmlDataManager();
        } catch (Exception e) {
            throw new XQException ("Error creating new Prepared expression with static context: " + e.getLocalizedMessage());
        
        }
    }

    @Override
    public void cancel() throws XQException {
        isClosedXQException();
        
    }

    @Override
    public boolean isClosed() {
        return closed;
    }

    @Override
    public void close() throws XQException {
        closed = true;
        for (XQResultSequence sequence: resultSequences) {
            sequence.close();
        }
        if (query!=null) {
            query.delete();
        }
    }

    @Override
    public XQResultSequence executeQuery() throws XQException {
        isClosedXQException();
        XQResultSequence result = null;
        try {
            result = new org.zorbaxquery.api.xqj.XQResultSequence(connection, query, true);
        } catch (Exception e) {
            throw new XQException("Error executing query: " + e.getLocalizedMessage());
        }
        resultSequences.add(result);
        return result;
    }

    @Override
    public QName[] getAllExternalVariables() throws XQException {
        isClosedXQException();
        Collection<QName> result = new ArrayList<QName>();
        Iterator iter = null;
        query.getExternalVariables(iter);
        iter.open();
        Item item = new Item();
        while (iter.next(item)) {
            result.add(new QName(item.getNamespace(), item.getLocalName(), item.getPrefix()));
        }
        iter.close();
        iter.delete();
        return result.toArray(new QName[0]);
    }

    
    private boolean isExternal(String varName) {
        boolean found=false;
        Iterator iter = null;
        query.getExternalVariables(iter);
        iter.open();
        Item item = new Item();
        while (iter.next(item)) {
            if (item.getLocalName().equalsIgnoreCase(varName)) {
                found = true;
            }
        }
        iter.close();
        iter.delete();
        return found;
    }
    
    @Override
    public QName[] getAllUnboundExternalVariables() throws XQException {
        isClosedXQException();
        
        Collection<QName> result = new ArrayList<QName>();
        Iterator iter = null;
        query.getExternalVariables(iter);
        Item item = new Item();
        iter.open();
        while (iter.next(item)) {
            boolean found = false;
            for (String key: itemsBounded){
                if (item.getLocalName().equalsIgnoreCase(key)) {
                    found = true;
                }
            }
            if (!found) {
                result.add(new QName(item.getNamespace(), item.getLocalName(), item.getPrefix()));
            }
        }
        iter.close();
        iter.delete();
        return result.toArray(new QName[0]);
    }

    @Override
    public XQSequenceType getStaticResultType() throws XQException {
        isClosedXQException();
        XQSequenceType result = new org.zorbaxquery.api.xqj.XQSequenceType(new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ITEM), XQSequenceType.OCC_ZERO_OR_MORE );
        return result;
    }

    @Override
    public XQSequenceType getStaticVariableType(QName varName) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        XQSequenceType result = null;
        Iterator iter = null;
        query.getExternalVariables(iter);
        iter.open();
        Item item = new Item();
        while (iter.next(item)) {
            if ( item.getLocalName().equalsIgnoreCase(varName.getLocalPart()) &&
                 item.getNamespace().equalsIgnoreCase(varName.getNamespaceURI()) &&
                 item.getPrefix().equalsIgnoreCase(varName.getPrefix()) ) {
                 if (item.getType().getStringValue().equals("xs:QName")) {
                     result = new org.zorbaxquery.api.xqj.XQSequenceType(new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ITEM), XQItemType.OCC_ZERO_OR_MORE);
                 } else {
                     result = new org.zorbaxquery.api.xqj.XQSequenceType(new org.zorbaxquery.api.xqj.XQItemType(item), XQItemType.OCC_ZERO_OR_MORE);
                 }
                 
            }
        }
        iter.close();
        iter.delete();
        if (result==null) {
            throw new XQException("Item not found");
        }
        return result;
    }

    @Override
    public XQStaticContext getStaticContext() throws XQException {
        isClosedXQException();
        if (staticContext==null) {
            staticContext = new org.zorbaxquery.api.xqj.XQStaticContext(query);
        }
        return staticContext;
    }

    @Override
    public TimeZone getImplicitTimeZone() throws XQException {
        isClosedXQException();
        Integer timeZone = (dynamicContext.getImplicitTimezone()/60); // in minutes
        TimeZone result = TimeZone.getTimeZone("GMT"+timeZone.toString());
        return result;
    }

    @Override
    public void bindAtomicValue(QName varName, String value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        isNullXQException(type);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        if (type.getItemKind()!=XQItemType.XQITEMKIND_ATOMIC) {
            throw new XQException ("Item kind is not atomic.");
        }
        try {
            XQItem xqitem = connection.createItemFromAtomicValue(value, type);
            Item item = ((org.zorbaxquery.api.xqj.XQItem)xqitem).getZorbaItem();
            dynamicContext.setVariable(varName.getLocalPart(), item);
            itemsBounded.add(varName.getLocalPart());
        } catch (Exception e) {
            throw new XQException ("Error binding the atomic value: " + e.getLocalizedMessage());
        }
        
    }

    @Override
    public void bindString(QName varName, String value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        isNullXQException(value);
        if (type==null) {
            type = ((org.zorbaxquery.api.xqj.XQConnection)connection).createAtomicType(XQItemType.XQBASETYPE_STRING);
        }
        try {
            Iterator iter = null;
            boolean found = false;
            query.getExternalVariables(iter);
            Item tmpItem = new Item();
            iter.open();
            while (iter.next(tmpItem)) {
                if (tmpItem.getStringValue().equalsIgnoreCase(varName.getLocalPart())) {
                    XQItem item = connection.createItemFromString(value, type);
                    dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
                    itemsBounded.add(varName.getLocalPart());
                    found=true;
                }
            }
            iter.close();
            iter.delete();
            if (!found) {
                throw new XQException ("The variable: " + varName.getLocalPart() + " doesn't exist.");
            }
        } catch (XQException e) {
            throw e;
        } catch (Exception e) {
            throw new XQException ("Error binding string to the defined type: " + e.getLocalizedMessage());
        }
        
    }

    @Override
    public void bindDocument(QName varName, String value, String baseURI, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        isNullXQException(value);
        if (!((type==null) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_ELEMENT) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT))) {
            throw new XQException ("Invalid type.");
        }
        if (type==null) {
            type = connection.createDocumentElementType(connection.createElementType(null, XQItemType.XQBASETYPE_UNTYPED));
        }
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("Variable not found in context.");
        }
        try {
            Iterator iter = xmlDataManager.parseXML(value);
            Item item = new Item();
            iter.next(item);
            dynamicContext.setVariable(varName.getLocalPart(), item);
            itemsBounded.add(varName.getLocalPart());
        } catch (Exception e) {
            throw new XQException ("Error binding document: " + e.getLocalizedMessage());
        }
        
    }

    @Override
    public void bindDocument(QName varName, Reader value, String baseURI, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        isNullXQException(value);
        if (!((type==null) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_ELEMENT) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT))) {
            throw new XQException ("Invalid type.");
        }
        if (type==null) {
            type = connection.createDocumentElementType(connection.createElementType(null, XQItemType.XQBASETYPE_UNTYPED));
        }
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
        
        bindDocument(varName, writer.toString(), baseURI, type);
    }

    @Override
    public void bindDocument(QName varName, InputStream value, String baseURI, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        isNullXQException(value);
        if (!((type==null) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_ELEMENT) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT))) {
            throw new XQException ("Invalid type.");
        }
        if (type==null) {
            type = connection.createDocumentElementType(connection.createElementType(null, XQItemType.XQBASETYPE_UNTYPED));
        }
        StringBuffer  out = new StringBuffer ();
        try {
            byte[] b = new byte[4096];
            for (int n; (n = value.read(b)) != -1;) {
                out.append(new String(b, 0, n));
            }
        } catch (Exception ex) {
            throw new XQException("Error preparing expression" + ex.getLocalizedMessage());
        }
        bindDocument(varName, out.toString(), baseURI, type);
    }

    @Override
    public void bindDocument(QName varName, XMLStreamReader value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        isNullXQException(value);
        if (!((type==null) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_ELEMENT) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT))) {
            throw new XQException ("Invalid type.");
        }
        if (type==null) {
            type = connection.createDocumentElementType(connection.createElementType(null, XQItemType.XQBASETYPE_UNTYPED));
        }
        
        TransformerFactory tf = TransformerFactory.newInstance();
        Transformer t;
        StAXSource source;
        StAXResult result;
        XMLOutputFactory xof = XMLOutputFactory.newInstance();
        Writer writer = new StringWriter();
        try {
            XMLStreamWriter xmlStreamWriter =  xof.createXMLStreamWriter(writer);
            t = tf.newTransformer();
            source = new StAXSource(value);
            result = new StAXResult(xmlStreamWriter);
            t.transform(source, result);        
        } catch (Exception ex) {
            throw new XQException("Error transforming xml expression" + ex.getLocalizedMessage());
        }
        bindDocument(varName, writer.toString(), null, type);
    }

    private String nodeToString(Node node) {
     StringWriter sw = new StringWriter();
     try {
       Transformer t = TransformerFactory.newInstance().newTransformer();
       t.setOutputProperty(OutputKeys.OMIT_XML_DECLARATION, "yes");
       t.transform(new DOMSource(node), new StreamResult(sw));
     } catch (TransformerException te) {
       System.out.println("nodeToString Transformer Exception" + te.getLocalizedMessage());
     }
     return sw.toString();
    }

    @Override
    public void bindDocument(QName varName, Source value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        if (!((type==null) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_ELEMENT) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT))) {
            throw new XQException ("Invalid type.");
        }
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        if (type==null) {
            type = connection.createDocumentElementType(connection.createElementType(null, XQItemType.XQBASETYPE_UNTYPED));
        }
        if (value instanceof StreamSource) {
            bindDocument(varName, ((StreamSource)value).getReader(), null, type);
        } else if (value instanceof SAXSource) {
            bindDocument(varName, ((SAXSource)value).getInputSource().getCharacterStream(), null, type);
        } else if (value instanceof DOMSource) {
            bindDocument(varName, nodeToString(((DOMSource)value).getNode()), null, type);
        } else {
            throw new UnsupportedOperationException("Not supported yet.");
        }
    }

    @Override
    public void setImplicitTimeZone(TimeZone value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        try {
            dynamicContext.setImplicitTimezone((value.getRawOffset()/60000));
        } catch (Exception e) {
            throw new XQException("Error setting implicit TimeZone: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindItem(QName varName, XQItem value) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.XQItem)value).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
        } catch (Exception e) {
            throw new XQException ("Error binding item: " + varName.getLocalPart() + " with error: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindSequence(QName varName, XQSequence value) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        if (value.isClosed()) {
            throw new XQException ("Sequence is closed.");
        }
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            if (!value.isOnItem()) {
                value.next();
            }
            Item item = new Item(((org.zorbaxquery.api.xqj.XQItem)value.getItem()).getZorbaItem());
            //Item item2 = new Item(item);
            //String val = item.getStringValue();
            dynamicContext.setVariable(varName.getLocalPart(), item);
            itemsBounded.add(varName.getLocalPart());
        } catch (Exception e) {
            throw new XQException ("Error binding item: " + varName.getLocalPart() + " with error: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindObject(QName varName, Object value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            XQItem item = connection.createItemFromObject(value, type);
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindBoolean(QName varName, boolean value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            XQItem item = connection.createItemFromBoolean(value, type);
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindByte(QName varName, byte value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            XQItem item = connection.createItemFromByte(value, type);
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindDouble(QName varName, double value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            XQItem item = connection.createItemFromDouble(value, type);
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindFloat(QName varName, float value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            XQItem item = connection.createItemFromFloat(value, type);
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindInt(QName varName, int value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            XQItem item = connection.createItemFromInt(value, type);
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindLong(QName varName, long value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            XQItem item = connection.createItemFromLong(value, type);
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindNode(QName varName, Node value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            XQItem item = connection.createItemFromNode(value, type);
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    @Override
    public void bindShort(QName varName, short value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            XQItem item = connection.createItemFromShort(value, type);
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.XQItem)item).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    private void isClosedXQException() throws XQException {
        if (closed) {
            throw new XQException("This prepared expression is closed");
        }
    }
    private void isNullXQException(Object value) throws XQException {
        if (value==null) {
            throw new XQException("Parameter shouldn't be null");
        }
    }
    
}
