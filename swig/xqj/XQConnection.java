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

import java.io.IOException;
import java.io.InputStream;
import java.io.Reader;
import java.io.StringWriter;
import java.io.Writer;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.net.URI;
import java.util.Iterator;
import java.nio.CharBuffer;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Properties;
import javax.xml.datatype.DatatypeConstants;
import javax.xml.datatype.Duration;
import javax.xml.datatype.XMLGregorianCalendar;
import javax.xml.namespace.QName;
import javax.xml.stream.XMLOutputFactory;
import javax.xml.stream.XMLStreamReader;
import javax.xml.stream.XMLStreamWriter;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Source;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.sax.SAXSource;
import javax.xml.transform.stax.StAXResult;
import javax.xml.transform.stax.StAXSource;
import javax.xml.transform.stream.StreamResult;
import javax.xml.transform.stream.StreamSource;
import javax.xml.xquery.XQException;
import javax.xml.xquery.XQExpression;
import javax.xml.xquery.XQItem;
import javax.xml.xquery.XQItemType;
import javax.xml.xquery.XQMetaData;
import javax.xml.xquery.XQPreparedExpression;
import javax.xml.xquery.XQSequence;
import javax.xml.xquery.XQSequenceType;
import javax.xml.xquery.XQStaticContext;
import org.w3c.dom.Attr;
import org.w3c.dom.Comment;
import org.w3c.dom.Document;
import org.w3c.dom.DocumentFragment;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.ProcessingInstruction;
import org.w3c.dom.Text;
import org.zorbaxquery.api.InMemoryStore;
import org.zorbaxquery.api.Item;
import org.zorbaxquery.api.ItemFactory;
import org.zorbaxquery.api.StringVector;
import org.zorbaxquery.api.XmlDataManager;
import org.zorbaxquery.api.Zorba;

public class XQConnection implements javax.xml.xquery.XQConnection {
    private InMemoryStore store;
    private Zorba zorba;
    private boolean autocommit;
    private boolean closed;
    private Collection<XQExpression> cExpression;
    private Collection<XQPreparedExpression> cPreparedExpression;
    private Collection<XQMetaData> cMetadata;
    private XQStaticContext lStaticContext;
    private XQXmlDataManager lXmlDataManager;
    private Properties properties;
    private StringVector uriPaths;
    private StringVector libPaths;
    private StringVector modulePaths;
    
    protected Zorba getZorbaInstance() throws XQException {
        if (zorba!=null) {
            return zorba;
        } else {
            throw new XQException("Error returning Zorba Instance");
        }
    }
    public XQConnection() {
        cExpression = new ArrayList<XQExpression>();
        cPreparedExpression = new ArrayList<XQPreparedExpression>();
        store = InMemoryStore.getInstance();
        zorba = Zorba.getInstance ( store );
        autocommit = true;
        closed = false;
    }
    public XQConnection(Properties aProperties) {
        cExpression = new ArrayList<XQExpression>();
        cPreparedExpression = new ArrayList<XQPreparedExpression>();
        store = InMemoryStore.getInstance();
        zorba = Zorba.getInstance ( store );
        autocommit = true;
        closed = false;
        properties = aProperties;
        for (String prop :properties.stringPropertyNames()) {
            if (prop.equalsIgnoreCase(XQDataSource.ZORBA_PROPERTIES_URI_PATHS)) {
                String[] paths = properties.getProperty(prop).split("[;,]");
                uriPaths = new StringVector();
                for (String path: paths) {
                    uriPaths.add(path);
                }
            }
            if (prop.equalsIgnoreCase(XQDataSource.ZORBA_PROPERTIES_LIB_PATHS)) {
                String[] paths = properties.getProperty(prop).split("[;,]");
                libPaths = new StringVector();
                for (String path: paths) {
                    libPaths.add(path);
                }
            }
            if (prop.equalsIgnoreCase(XQDataSource.ZORBA_PROPERTIES_MODULE_PATHS)) {
                String[] paths = properties.getProperty(prop).split("[;,]");
                modulePaths = new StringVector();
                for (String path: paths) {
                    modulePaths.add(path);
                }
            }
        }
        lStaticContext = new org.zorbaxquery.api.xqj.XQStaticContext(zorba);
        if (uriPaths!=null) {
            ((org.zorbaxquery.api.xqj.XQStaticContext)lStaticContext).setURIPaths(uriPaths);
        }
        if (libPaths!=null) {
            ((org.zorbaxquery.api.xqj.XQStaticContext)lStaticContext).setLIBPaths(libPaths);
        }
        if (modulePaths!=null) {
            ((org.zorbaxquery.api.xqj.XQStaticContext)lStaticContext).setMODPaths(modulePaths);
        }
        
    }
    
    
    @Override
    public void close() throws XQException {
        if (closed) return; // already closed
        try {
            for (XQExpression exp : cExpression ){
                exp.close();  // Notify the dependents objects to close
            }
            for (XQPreparedExpression exp : cPreparedExpression ){
                exp.close();  // Notify the dependents objects to close
            }
        } catch (XQException e) {
            throw new XQException("Error closing connection: " + e.getLocalizedMessage());
        }

        if (lStaticContext != null ) {
            ((org.zorbaxquery.api.xqj.XQStaticContext)lStaticContext).getZorbaStaticContext().destroy();
        }
        if (lXmlDataManager != null) {
            lXmlDataManager.close();
        }
        zorba.shutdown();
        InMemoryStore.shutdown ( store );
        closed = true;
    }
    
    public XQXmlDataManager getXmlDataManager() {
        if (lXmlDataManager==null) {
            lXmlDataManager = new XQXmlDataManager(zorba);
        }
        return lXmlDataManager;
    }

    @Override
    public void setAutoCommit(boolean bln) throws XQException {
        isClosedXQException();
        autocommit = bln;
    }

    @Override
    public boolean getAutoCommit() throws XQException {
        isClosedXQException();
        return autocommit;
    }

    @Override
    public void commit() throws XQException {
        isClosedXQException();
        throw new UnsupportedOperationException("Zorba does not support transactions... yet...");
    }

    @Override
    public XQExpression createExpression() throws XQException {
        isClosedXQException();
        XQExpression expression;
        if (lStaticContext == null) {
            expression = new org.zorbaxquery.api.xqj.XQExpression(this);
        } else {
            expression = new org.zorbaxquery.api.xqj.XQExpression(this, lStaticContext);
        }
        cExpression.add(expression);
        return expression;
    }

    @Override
    public XQExpression createExpression(XQStaticContext value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        XQExpression expression = new org.zorbaxquery.api.xqj.XQExpression(this, value);
        cExpression.add(expression);
        return expression;
    }

    @Override
    public XQMetaData getMetaData() throws XQException {
        isClosedXQException();
        return new org.zorbaxquery.api.xqj.XQMetaData(this);
    }

    @Override
    public boolean isClosed() {
        return closed;
    }

    @Override
    public XQPreparedExpression prepareExpression(String value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        XQPreparedExpression expression;
        try {
            if (lStaticContext == null) {
                expression = new org.zorbaxquery.api.xqj.XQPreparedExpression(this, value);
            } else {
                expression = new org.zorbaxquery.api.xqj.XQPreparedExpression(this, value, lStaticContext);
            }
            cPreparedExpression.add(expression);
        } catch (Exception e) {
          throw new XQException("Error preparing expression: "+e.getLocalizedMessage());
        }
        return expression;
    }

    @Override
    public XQPreparedExpression prepareExpression(String string, XQStaticContext xqsc) throws XQException {
        isClosedXQException();
        isNullXQException(string);
        isNullXQException(xqsc);
        XQPreparedExpression expression = null;
        try {
            expression = new org.zorbaxquery.api.xqj.XQPreparedExpression(this, string, xqsc);
            cPreparedExpression.add(expression);
        } catch (Exception e) {
          throw new XQException("Error preparing expression");
        }
        return expression;
    }

    @Override
    public XQPreparedExpression prepareExpression(Reader reader) throws XQException {
        isClosedXQException();
        isNullXQException(reader);
        
        StringBuffer string = new StringBuffer();
        CharBuffer buffer = CharBuffer.allocate(1024);
        Writer writer = new StringWriter();
        
        try {
            while( reader.read(buffer) >= 0 ) {
                buffer.flip();
                writer.append(buffer);
                buffer.clear();
            }
            reader.close();
        } catch (Exception ex) {
            throw new XQException("Error preparing expression" + ex.getLocalizedMessage());
        }
        
        XQPreparedExpression expression;
        if (lStaticContext == null) {
            expression = new org.zorbaxquery.api.xqj.XQPreparedExpression(this, writer.toString());
        } else {
            expression = new org.zorbaxquery.api.xqj.XQPreparedExpression(this, writer.toString(), lStaticContext);
        }
        cPreparedExpression.add(expression);
        return expression;
    }

    @Override
    public XQPreparedExpression prepareExpression(Reader reader, XQStaticContext xqsc) throws XQException {
        isClosedXQException();
        isNullXQException(reader);
        isNullXQException(xqsc);
        StringBuffer string = new StringBuffer();
        CharBuffer buffer = CharBuffer.allocate(1024);
        Writer writer = new StringWriter();
        try {
            while( reader.read(buffer) >= 0 ) {
                buffer.flip();
                writer.append(buffer);
                buffer.clear();
            }
            reader.close();
        } catch (Exception ex) {
            throw new XQException("Error preparing expression" + ex.getLocalizedMessage());
        }
        
        XQPreparedExpression expression = new org.zorbaxquery.api.xqj.XQPreparedExpression(this, writer.toString(), xqsc);
        
        cPreparedExpression.add(expression);
        return expression;
    }

    @Override
    public XQPreparedExpression prepareExpression(InputStream in) throws XQException {
        isClosedXQException();
        isNullXQException(in);
        StringBuffer  out = new StringBuffer ();
        try {
            byte[] b = new byte[4096];
            for (int n; (n = in.read(b)) != -1;) {
                out.append(new String(b, 0, n));
            }
        } catch (Exception ex) {
            throw new XQException("Error preparing expression" + ex.getLocalizedMessage());
        }
        
        XQPreparedExpression expression;
        if (lStaticContext == null) {
            expression = new org.zorbaxquery.api.xqj.XQPreparedExpression(this, out.toString());
        } else {
            expression = new org.zorbaxquery.api.xqj.XQPreparedExpression(this, out.toString(), lStaticContext);
        }
        try {
            cPreparedExpression.add(expression);
        } catch (Exception ex) {
            throw new XQException("Error preparing expression" + ex.getLocalizedMessage());
        }
            
        return expression;
    }

    @Override
    public XQPreparedExpression prepareExpression(InputStream in, XQStaticContext xqsc) throws XQException {
        isClosedXQException();
        isNullXQException(in);
        isNullXQException(xqsc);
        StringBuffer  out = new StringBuffer ();
        try {
            byte[] b = new byte[4096];
            for (int n; (n = in.read(b)) != -1;) {
                out.append(new String(b, 0, n));
            }
        } catch (IOException ex) {
            throw new XQException("Error preparing expression" + ex.getLocalizedMessage());
        }
        
        XQPreparedExpression expression = null;
        try {
            expression = new org.zorbaxquery.api.xqj.XQPreparedExpression(this, out.toString(), xqsc);
            cPreparedExpression.add(expression);
        } catch (Exception ex) {
            throw new XQException("Error preparing expression" + ex.getLocalizedMessage());
        }
        return expression;
    }

    @Override
    public void rollback() throws XQException {
        throw new UnsupportedOperationException("Zorba does not support transactions... yet...");
    }

    @Override
    public XQStaticContext getStaticContext() throws XQException {
        isClosedXQException();
        lStaticContext = new org.zorbaxquery.api.xqj.XQStaticContext(zorba);
        if (uriPaths!=null) {
            ((org.zorbaxquery.api.xqj.XQStaticContext)lStaticContext).setURIPaths(uriPaths);
        }
        if (libPaths!=null) {
            ((org.zorbaxquery.api.xqj.XQStaticContext)lStaticContext).setLIBPaths(libPaths);
        }
        if (modulePaths!=null) {
            ((org.zorbaxquery.api.xqj.XQStaticContext)lStaticContext).setMODPaths(modulePaths);
        }
        return lStaticContext;
    }

    @Override
    public void setStaticContext(XQStaticContext xqsc) throws XQException {
        isClosedXQException();
        isNullXQException(xqsc);
        if ((lStaticContext!=null) && (lStaticContext!=xqsc)) {  // delete previous static context
            ((org.zorbaxquery.api.xqj.XQStaticContext)lStaticContext).getZorbaStaticContext().delete();
        }
        lStaticContext = xqsc;
    }

    @Override
    public XQItem createItemFromAtomicValue(String value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        isNullXQException(type);
        if (type.getItemKind()!=XQItemType.XQITEMKIND_ATOMIC) {
            throw new XQException("ItemType is not Atomic");
        }
        XQItem item = null;
        try {
            item = this.createItemFromString(value, type);
        } catch (Exception e) {
            throw new XQException("Error creating item of this type " + e.getLocalizedMessage());
        }
        return item;
    }

    @Override
    public XQItem createItemFromString(String value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        if (type==null) {
            type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_STRING);
        }
        ItemFactory itemFactory = zorba.getItemFactory();
        XQItem item = null;
        try {
            switch (type.getBaseType()) {
            case XQItemType.XQBASETYPE_BOOLEAN:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createBoolean(Boolean.parseBoolean(value)), type);
                break;
            case XQItemType.XQBASETYPE_ANYURI:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createAnyURI(value), type);
                break;
            case XQItemType.XQBASETYPE_BASE64BINARY:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createBase64Binary(value, value.length()), type);
                break;
            case XQItemType.XQBASETYPE_BYTE:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createByte(value.charAt(0)), type);
                break;
            case XQItemType.XQBASETYPE_DATE:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDate(value), type);
                break;
            case XQItemType.XQBASETYPE_DATETIME:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDateTime(value), type);
                break;
            case XQItemType.XQBASETYPE_DAYTIMEDURATION:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDuration(value), type);
                break;
            case XQItemType.XQBASETYPE_DECIMAL:
                BigDecimal dec = new BigDecimal(value);
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDecimal(value), type);
                break;
            case XQItemType.XQBASETYPE_DOUBLE:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDouble(Double.parseDouble(value)), type);
                break;
            case XQItemType.XQBASETYPE_DURATION:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDuration(value), type);
                break;
            case XQItemType.XQBASETYPE_FLOAT:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createFloat(value), type);
                break;
            case XQItemType.XQBASETYPE_GDAY:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createGDay(value), type);
                break;
            case XQItemType.XQBASETYPE_GMONTH:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createGMonth(value), type);
                break;
            case XQItemType.XQBASETYPE_GMONTHDAY:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createGMonthDay(value), type);
                break;
            case XQItemType.XQBASETYPE_GYEAR:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createGYear(value), type);
                break;
            case XQItemType.XQBASETYPE_GYEARMONTH:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createGYearMonth(value), type);
                break;
            case XQItemType.XQBASETYPE_HEXBINARY:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createHexBinary(value, value.length()), type);
                break;
            case XQItemType.XQBASETYPE_INT:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createInt(Integer.parseInt(value)), type);
                break;
            case XQItemType.XQBASETYPE_INTEGER:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createInteger(Integer.parseInt(value)), type);
                break;
            case XQItemType.XQBASETYPE_LONG:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createLong(Long.parseLong(value)), type);
                break;
            case XQItemType.XQBASETYPE_NCNAME:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createNCName(value), type);
                break;
            case XQItemType.XQBASETYPE_NEGATIVE_INTEGER:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createNegativeInteger(Long.parseLong(value)), type);
                break;
            case XQItemType.XQBASETYPE_NONNEGATIVE_INTEGER:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createNonNegativeInteger(new BigInteger(value)), type);
                break;
            case XQItemType.XQBASETYPE_NONPOSITIVE_INTEGER:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createNonPositiveInteger(Long.parseLong(value)), type);
                break;
            case XQItemType.XQBASETYPE_POSITIVE_INTEGER:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createPositiveInteger(new BigInteger(value)), type);
                break;
            case XQItemType.XQBASETYPE_QNAME:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createQName(type.getSchemaURI().toString(), value), type);
                break;
            case XQItemType.XQBASETYPE_SHORT:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createShort(Short.parseShort(value)), type);
                break;
            case XQItemType.XQBASETYPE_STRING:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createString(value), type);
                break;
            case XQItemType.XQBASETYPE_TIME:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createTime(value), type);
                break;
            case XQItemType.XQBASETYPE_UNSIGNED_BYTE:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createUnsignedByte(Short.parseShort(value)), type);
                break;
            case XQItemType.XQBASETYPE_UNSIGNED_INT:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createUnsignedInt(Long.parseLong(value)), type);
                break;
            case XQItemType.XQBASETYPE_UNSIGNED_LONG:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createUnsignedLong(new BigInteger(value)), type);
                break;
            case XQItemType.XQBASETYPE_UNSIGNED_SHORT:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createUnsignedShort(Integer.parseInt(value)), type);
                break;
            case XQItemType.XQBASETYPE_YEARMONTHDURATION:
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDuration(value), type);
                break;
            // TODO: revisit this posibilities
            case XQItemType.XQBASETYPE_ANYATOMICTYPE:
            case XQItemType.XQBASETYPE_ANYSIMPLETYPE:
            case XQItemType.XQBASETYPE_ENTITY:
            case XQItemType.XQBASETYPE_ENTITIES:
            case XQItemType.XQBASETYPE_ANYTYPE:
            case XQItemType.XQBASETYPE_LANGUAGE:
            case XQItemType.XQBASETYPE_ID:
            case XQItemType.XQBASETYPE_IDREF:
            case XQItemType.XQBASETYPE_IDREFS:
            case XQItemType.XQBASETYPE_NAME:
            case XQItemType.XQBASETYPE_NMTOKEN:
            case XQItemType.XQBASETYPE_NMTOKENS:
            case XQItemType.XQBASETYPE_NORMALIZED_STRING:
            case XQItemType.XQBASETYPE_NOTATION:
            case XQItemType.XQBASETYPE_TOKEN:
            case XQItemType.XQBASETYPE_UNTYPED:
            case XQItemType.XQBASETYPE_UNTYPEDATOMIC:
                throw new UnsupportedOperationException("Not supported yet.");
            default:
                
                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createString(value), type);
                break;
            }
        } catch (Exception e) {
            throw new XQException ("Error parsing value" + e.getLocalizedMessage());
        }
        return item;
    }

    @Override
    public XQItem createItemFromDocument(String value, String baseURI, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        if (type!=null) {
            if ( ! ((type.getItemKind()== XQItemType.XQITEMKIND_DOCUMENT_ELEMENT)||(type.getItemKind()== XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT)) ) {
                throw new XQException("Invalid type");
            }
        } else {
            type =  this.createElementType(null, XQItemType.XQBASETYPE_UNTYPED);
        }
        
        XmlDataManager dm = null;
        Item doc = null;
        XQItem item = null;
        try {
            dm = zorba.getXmlDataManager();
            doc = new Item();
            org.zorbaxquery.api.Iterator iterator =  dm.parseXML(value);
            iterator.open();
            iterator.next(doc);
            iterator.close();
            iterator.delete();
            item = new org.zorbaxquery.api.xqj.XQItem(doc);
        } catch (Exception e) {
            throw new XQException("Error creating Item" + e.getLocalizedMessage());
        }
        return item;
    }

    @Override
    public XQItem createItemFromDocument(Reader value, String baseURI, XQItemType type) throws XQException {
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
        
        XQItem item = createItemFromDocument(writer.toString(), baseURI, type);
        return item;
    }

    @Override
    public XQItem createItemFromDocument(InputStream value, String baseURI, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        // TODO: Rodolfo: optimize this, not good to have a string
        StringBuffer out = new StringBuffer ();
        try {
            byte[] b = new byte[4096];
            for (int n; (n = value.read(b)) != -1;) {
                out.append(new String(b, 0, n));
            }
        } catch (Exception ex) {
            throw new XQException("Error preparing expression" + ex.getLocalizedMessage());
        }
        XQItem item = createItemFromDocument(out.toString(), baseURI, type);
        return item;
    }

    @Override
    public XQItem createItemFromDocument(XMLStreamReader value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
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
        XQItem item = createItemFromDocument(writer.toString(), "", type);
        return item;
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
    public XQItem createItemFromDocument(Source value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        XQItem item = null;
        if (value instanceof StreamSource) {
            item = createItemFromDocument(((StreamSource)value).getReader(), "", type);
        } else if (value instanceof SAXSource) {
            item = createItemFromDocument(((SAXSource)value).getInputSource().getByteStream(), "", type);
        } else if (value instanceof DOMSource) {
            item = createItemFromDocument( nodeToString(((DOMSource)value).getNode()), "", type);
        } else {
            throw new UnsupportedOperationException("Not supported yet.");
        }
        return item;
        
    }

    @Override
    public XQItem createItemFromObject(Object value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        if (value instanceof XQItem) {
            return (XQItem)value;
        }
        
        ItemFactory itemFactory = zorba.getItemFactory();
        XQItem item = null;
        if (type==null) {
            
            if (value instanceof Boolean) {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_BOOLEAN);
            } else if (value instanceof Byte) {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_BYTE);
            } else if (value instanceof Float) {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_FLOAT);
            } else if (value instanceof Double) {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_DOUBLE);
            } else if (value instanceof Integer) {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_INT);
            } else if (value instanceof Long) {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_LONG);
            } else if (value instanceof Short) {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_SHORT);
            } else if (value instanceof String) {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_STRING);
            } else if (value instanceof BigDecimal) {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_DECIMAL);
            } else if (value instanceof BigInteger) {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_INTEGER);
            } else if (value instanceof Duration) {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_DURATION);
            } else if (value instanceof XMLGregorianCalendar) {
                QName schType = ((XMLGregorianCalendar)value).getXMLSchemaType();
                if (schType.equals(DatatypeConstants.GDAY)) {
                    type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_GDAY);
                } else if (schType.equals(DatatypeConstants.GMONTHDAY)) {
                    type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_GMONTHDAY);
                } else if (schType.equals(DatatypeConstants.GMONTH)) {
                    type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_GMONTH);
                } else if (schType.equals(DatatypeConstants.GYEAR)) {
                    type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_GYEAR);
                } else if (schType.equals(DatatypeConstants.GYEARMONTH)) {
                    type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_GYEARMONTH);
                } else if (schType.equals(DatatypeConstants.DATETIME)) {
                    type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_DATETIME);
                } else if (schType.equals(DatatypeConstants.DATE)) {
                    type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_DATE);
                } else if (schType.equals(DatatypeConstants.TIME)) {
                    type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_TIME);
                }
            } else if (value instanceof QName) {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_QNAME);
            } else if (value instanceof Document) {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_DOCUMENT);
            } else if (value instanceof DocumentFragment) {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_DOCUMENT);
            } else if (value instanceof Element){
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ELEMENT);
            } else if (value instanceof Attr) {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATTRIBUTE);
            } else if (value instanceof Comment) {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_COMMENT);
            } else if (value instanceof ProcessingInstruction) {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_PI);
            } else if (value instanceof Text) {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_TEXT);
            } else {
                type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC);
            }
        }
        try {
            switch (type.getItemKind()) {
                case XQItemType.XQITEMKIND_ATOMIC:
                    switch (type.getBaseType()) {
                    case XQItemType.XQBASETYPE_BOOLEAN:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createBoolean((Boolean)value), type);
                        break;
                    case XQItemType.XQBASETYPE_ANYURI:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createAnyURI(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_BASE64BINARY:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createBase64Binary(value.toString(), (value.toString()).length()), type);
                        break;
                    case XQItemType.XQBASETYPE_BYTE:
                        if (value instanceof Byte) {
                            byte tmpByte = ((Byte)value).byteValue();
                            item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createByte((char)tmpByte), type);
                        } else {
                            item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createByte((value.toString()).charAt(0)), type);
                        }
                        break;
                    case XQItemType.XQBASETYPE_DATE:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDate(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_DATETIME:
                        if (value.toString().contains(":")) {
                            item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDateTime(value.toString()), type);
                        } else {
                            item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDate(value.toString()), type);
                        }
                        break;
                    case XQItemType.XQBASETYPE_DAYTIMEDURATION:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDuration(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_DECIMAL:
                        if (value instanceof BigDecimal) {
                            item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDecimal(((BigDecimal)value).toPlainString()), type);
                        } else {
                            item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDecimal(value.toString()), type);
                        }
                        break;
                    case XQItemType.XQBASETYPE_DOUBLE:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDouble(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_DURATION:
                        if (value instanceof Duration) {
                            Duration duration = (Duration)value;
                            Boolean daytime = duration.isSet(DatatypeConstants.DAYS) || duration.isSet(DatatypeConstants.HOURS) || 
                                              duration.isSet(DatatypeConstants.MINUTES) || duration.isSet(DatatypeConstants.SECONDS);
                            Boolean yearmonth = duration.isSet(DatatypeConstants.YEARS) || duration.isSet(DatatypeConstants.MONTHS);
                            if (daytime && yearmonth){
                                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDuration(value.toString()), type);
                            } else if (yearmonth) {
                                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createYearMonthDuration(value.toString()), type);
                            } else if (daytime) {
                                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDayTimeDuration(value.toString()), type);
                            }
                        } else {
                            boolean yearMonth = value.toString().contains("Y") || value.toString().contains("M");
                            boolean dayTime = value.toString().contains("D") || value.toString().contains("T");
                            if (yearMonth && dayTime) {
                                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDuration(value.toString()), type);
                            } else if (yearMonth) {
                                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createYearMonthDuration(value.toString()), type);
                            } else if (dayTime) {
                                item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDayTimeDuration(value.toString()), type);
                            }
                        }
                        break;
                    case XQItemType.XQBASETYPE_FLOAT:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createFloat((Float)value), type);
                        break;
                    case XQItemType.XQBASETYPE_GDAY:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createGDay(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_GMONTH:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createGMonth(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_GMONTHDAY:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createGMonthDay(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_GYEAR:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createGYear(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_GYEARMONTH:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createGYearMonth(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_HEXBINARY:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createHexBinary(value.toString(), (value.toString()).length()), type);
                        break;
                    case XQItemType.XQBASETYPE_INT:
                    case XQItemType.XQBASETYPE_INTEGER:
                        if (value instanceof BigInteger) {
                            BigInteger val = (BigInteger)value;
                            item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createInteger(val.longValue()), type);
                        } else if (value instanceof Integer) {
                            item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createInt((Integer)value), type);
                        } else if (value instanceof String) {
                            item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createInteger(value.toString()), type);
                        } else {
                            throw new XQException ("Error parsing integer: " + value.toString());
                        }
                        break;
                    case XQItemType.XQBASETYPE_LONG:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createLong((Long)value), type);
                        break;
                    case XQItemType.XQBASETYPE_NCNAME:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createNCName(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_NEGATIVE_INTEGER:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createNegativeInteger((Long)value), type);
                        break;
                    case XQItemType.XQBASETYPE_NONNEGATIVE_INTEGER:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createNonNegativeInteger(new BigInteger(value.toString())), type);
                        break;
                    case XQItemType.XQBASETYPE_NONPOSITIVE_INTEGER:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createNonPositiveInteger((Long)value), type);
                        break;
                    case XQItemType.XQBASETYPE_POSITIVE_INTEGER:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createPositiveInteger(new BigInteger(value.toString())), type);
                        break;
                    case XQItemType.XQBASETYPE_QNAME:
                        if (value instanceof QName) {
                            QName qname =  (QName) value;
                            item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createQName(qname.getNamespaceURI(), qname.getPrefix(), qname.getLocalPart()), type);
                        } else if (value.toString().contains("{")) {
                            item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createQName(value.toString()), type);
                        } else {
                            item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createQName("", value.toString()), type);
                        }
                        break;
                    case XQItemType.XQBASETYPE_SHORT:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createShort((Short)value), type);
                        break;
                    case XQItemType.XQBASETYPE_STRING:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createString(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_TIME:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createTime(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_TOKEN:
                        break;
                    case XQItemType.XQBASETYPE_UNSIGNED_BYTE:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createUnsignedByte((Short)value), type);
                        break;
                    case XQItemType.XQBASETYPE_UNSIGNED_INT:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createUnsignedInt((Long)value), type);
                        break;
                    case XQItemType.XQBASETYPE_UNSIGNED_LONG:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createUnsignedLong(new BigInteger(value.toString())), type);
                        break;
                    case XQItemType.XQBASETYPE_UNSIGNED_SHORT:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createUnsignedShort((Integer)value), type);
                        break;
                    case XQItemType.XQBASETYPE_YEARMONTHDURATION:
                        item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDuration(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_ANYATOMICTYPE:
                    case XQItemType.XQBASETYPE_ANYSIMPLETYPE:
                    case XQItemType.XQBASETYPE_ANYTYPE:
                    case XQItemType.XQBASETYPE_ENTITIES:
                    case XQItemType.XQBASETYPE_ENTITY:
                    case XQItemType.XQBASETYPE_ID:
                    case XQItemType.XQBASETYPE_IDREF:
                    case XQItemType.XQBASETYPE_IDREFS:
                    case XQItemType.XQBASETYPE_LANGUAGE:
                    case XQItemType.XQBASETYPE_NAME:
                    case XQItemType.XQBASETYPE_NMTOKEN:
                    case XQItemType.XQBASETYPE_NMTOKENS:
                    case XQItemType.XQBASETYPE_NORMALIZED_STRING:
                    case XQItemType.XQBASETYPE_NOTATION:
                    case XQItemType.XQBASETYPE_UNTYPED:
                    case XQItemType.XQBASETYPE_UNTYPEDATOMIC:
                        throw new XQException ("Base type not supported yet.");
                    default:
                        throw new XQException ("Unable to determine XQBASETYPE.");
                    }
                    break;
                case XQItemType.XQITEMKIND_ATTRIBUTE:
                    if (value instanceof Attr){
                        Attr attribute = (Attr) value;
                        Item iEmpty = new Item();
                        Item nodeName = itemFactory.createQName(attribute.getNamespaceURI()==null?"":attribute.getNamespaceURI(), 
                                                                attribute.getPrefix()==null?"":attribute.getPrefix(), 
                                                                attribute.getName()==null?"":attribute.getName());
                        Item nodeValue = null;
                        if (!attribute.getValue().isEmpty()) {
                            nodeValue = itemFactory.createQName(attribute.getNamespaceURI()==null?"":attribute.getNamespaceURI(), 
                                                                attribute.getPrefix()==null?"":attribute.getPrefix(), 
                                                                attribute.getValue()==null?"":attribute.getValue());
                        } else {
                            nodeValue = new Item();
                        }
                        //TODO: Rodolfo: use centralized constants instead of strings
                        Item iUntyped = itemFactory.createQName("http://www.w3.org/2001/XMLSchema", "xs", "untyped");
                        Item attributeNode = itemFactory.createAttributeNode(iEmpty, nodeName, iUntyped, nodeValue);
                        item = new org.zorbaxquery.api.xqj.XQItem(attributeNode, type);
                    }
                    break;
                case XQItemType.XQITEMKIND_COMMENT:
                    if (value instanceof Comment){
                        Comment comment = (Comment) value;
                        Item iEmpty = new Item();
                        Item elementNode = itemFactory.createCommentNode(iEmpty, comment.getTextContent());
                        item = new org.zorbaxquery.api.xqj.XQItem(elementNode, type);
                    } else {
                        Item iEmpty = new Item();
                        Item elementNode = itemFactory.createCommentNode(iEmpty, value.toString());
                        item = new org.zorbaxquery.api.xqj.XQItem(elementNode, type);
                    }
                    break;
                case XQItemType.XQITEMKIND_DOCUMENT:
                    if ((value instanceof Document) || (value instanceof DocumentFragment)){
                        DOMSource source = null;
                        if (value instanceof Document) {
                            source = new DOMSource((Document)value);
                        } else {
                            source = new DOMSource((DocumentFragment)value);
                        }

                        Transformer transformer = TransformerFactory.newInstance().newTransformer();
                        transformer.setOutputProperty(OutputKeys.OMIT_XML_DECLARATION, "yes");
                        StreamResult result = new StreamResult(new StringWriter());
                        
                        transformer.transform(source, result);
                        String xmlString = result.getWriter().toString();
                        Item tmpItem = new Item();
                        if (xmlString.length()>0) {
                            XmlDataManager dataManager = zorba.getXmlDataManager();
                            org.zorbaxquery.api.Iterator iter = dataManager.parseXML(xmlString);
                            iter.open();
                            iter.next(tmpItem);
                            iter.close();
                            iter.delete();
                        } else {
                            tmpItem = itemFactory.createDocumentNode("", "");
                        }
                        
                        item = new org.zorbaxquery.api.xqj.XQItem(tmpItem, type);
                    }
                      
                    break;
                case XQItemType.XQITEMKIND_ELEMENT:
                    if (value instanceof Element){
                        Element element = (Element) value;
                        Item iEmpty = new Item();
                        Item nodeName = itemFactory.createQName(element.getNamespaceURI()==null?"":element.getNamespaceURI(), 
                                                                element.getPrefix()==null?"":element.getPrefix(), 
                                                                element.getNodeName()==null?"":element.getNodeName());
                        Item iUntyped = itemFactory.createQName("http://www.w3.org/2001/XMLSchema", "xs", "untyped");
                        Item elementNode = itemFactory.createElementNode(iEmpty, nodeName, iUntyped, false, false);
                        item = new org.zorbaxquery.api.xqj.XQItem(elementNode, type);
                    }
                    break;
                case XQItemType.XQITEMKIND_PI:
                    if (value instanceof ProcessingInstruction){
                        ProcessingInstruction pi = (ProcessingInstruction) value;
                        Item iEmpty = new Item();
                        Item elementNode = itemFactory.createPiNode(iEmpty, 
                                pi.getTarget(), 
                                pi.getTextContent(), 
                                pi.getBaseURI()==null?"":pi.getBaseURI());
                        item = new org.zorbaxquery.api.xqj.XQItem(elementNode, type);
                    }
                    break;
                case XQItemType.XQITEMKIND_TEXT:
                    if (value instanceof Text){
                        Text text = (Text) value;
                        Item iEmpty = new Item();
                        Item elementNode = itemFactory.createTextNode(iEmpty, text.getWholeText());
                        item = new org.zorbaxquery.api.xqj.XQItem(elementNode, type);
                    }
                    break;
                case XQItemType.XQITEMKIND_DOCUMENT_ELEMENT:
                case XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT:
                case XQItemType.XQITEMKIND_ITEM:
                case XQItemType.XQITEMKIND_NODE:
                case XQItemType.XQITEMKIND_SCHEMA_ATTRIBUTE:
                case XQItemType.XQITEMKIND_SCHEMA_ELEMENT:
                    throw new XQException ("This item kind is currently unsupported.");
                default:
                    throw new XQException ("Unable to determine XQITEMKIND.");
            }
        } catch (Exception e) {
            throw new XQException ("Error parsing value" + e.getLocalizedMessage());
        }
        return item;
    }

    @Override
    public XQItem createItemFromBoolean(boolean bln, XQItemType type) throws XQException {
        isClosedXQException();
        if (type == null) {
            type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_BOOLEAN);
        }
        if (type.getBaseType() != XQItemType.XQBASETYPE_BOOLEAN) {
            throw new XQException("Type is not boolean, use proper method");
        }
        
        XQItem item = null;
        try {
            ItemFactory itemFactory = zorba.getItemFactory();
            item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createBoolean(bln));
        } catch (Exception e) {
            throw new XQException("Error creating new item");
        }
        return item;
    }

    // This method works for Decimal and all subtypes,
    // verifies that the type is correct and create the Item
    private XQItem createDecimal(BigDecimal value, XQItemType type) throws XQException {
        XQItem item = null;
        try {
            ItemFactory itemFactory = zorba.getItemFactory();
            switch (type.getBaseType()) {
                case XQItemType.XQBASETYPE_BYTE:
                    item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createByte((char)value.byteValue()), type);
                    break;
                case XQItemType.XQBASETYPE_INTEGER:
                    item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createInteger(value.longValue()), type);
                    break;
                case XQItemType.XQBASETYPE_DECIMAL:
                    item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDecimalFromLong(value.longValue()), type);
                    break;
                case XQItemType.XQBASETYPE_INT:
                    item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createInt(value.intValue()), type);
                    break;
                case XQItemType.XQBASETYPE_LONG:
                    item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createLong(value.longValue()), type);
                    break;
                case XQItemType.XQBASETYPE_NEGATIVE_INTEGER:
                    item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createNegativeInteger(value.longValue()), type);
                    break;
                case XQItemType.XQBASETYPE_NONNEGATIVE_INTEGER:
                    item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createNonNegativeInteger(value.toBigInteger()), type);
                    break;
                case XQItemType.XQBASETYPE_NONPOSITIVE_INTEGER:
                    item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createNonPositiveInteger(value.longValue()), type);
                    break;
                case XQItemType.XQBASETYPE_POSITIVE_INTEGER:
                    item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createPositiveInteger(value.toBigInteger()), type);
                    break;
                case XQItemType.XQBASETYPE_SHORT:
                    item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createShort(value.shortValue()), type);
                    break;
                case XQItemType.XQBASETYPE_UNSIGNED_BYTE:
                    item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createUnsignedByte(value.shortValue()), type);
                    break;
                case XQItemType.XQBASETYPE_UNSIGNED_INT:
                    item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createUnsignedInt(value.longValue()), type);
                    break;
                case XQItemType.XQBASETYPE_UNSIGNED_LONG:
                    item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createUnsignedLong(value.toBigInteger()), type);
                    break;
                case XQItemType.XQBASETYPE_UNSIGNED_SHORT:
                    item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createShort(value.shortValue()), type);
                    break;
                default:
                    throw new XQException("Type is not xs:decimal or a derivate.");
            }
        } catch (Exception e) {
            throw new XQException("Error creating Item: " + e.getLocalizedMessage());
        }
        return item;
    }
    
    @Override
    public XQItem createItemFromByte(byte b, XQItemType type) throws XQException {
        isClosedXQException();
        if (type == null) {
            type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_BYTE);
        }
        return createDecimal(new BigDecimal(b), type);
    }

    @Override
    public XQItem createItemFromDouble(double value, XQItemType type) throws XQException {
        isClosedXQException();
        if (type == null) {
            type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_DOUBLE);
        }
        if (type.getBaseType() != XQItemType.XQBASETYPE_DOUBLE) {
            throw new XQException("Type is not double, use proper method");
        }
        XQItem item = null;
        try {
            ItemFactory itemFactory = zorba.getItemFactory();
            item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createDouble(value), type);
        } catch (Exception e) {
            throw new XQException("Error Creating Item From Double" + e.getLocalizedMessage());
        }
        return item;
    }

    @Override
    public XQItem createItemFromFloat(float value, XQItemType type) throws XQException {
        isClosedXQException();
        if (type == null) {
            type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_FLOAT);
        }
        if (type.getBaseType() != XQItemType.XQBASETYPE_FLOAT) {
            throw new XQException("Type is not float, use proper method");
        }
        XQItem item = null;
        try {
            ItemFactory itemFactory = zorba.getItemFactory();
            item = new org.zorbaxquery.api.xqj.XQItem(itemFactory.createFloat(value), type);
        } catch (Exception e) {
            throw new XQException("Error Creating Item From Float" + e.getLocalizedMessage());
        }
        return item;
    }

    @Override
    public XQItem createItemFromInt(int value, XQItemType type) throws XQException {
        isClosedXQException();
        if (type == null) {
            type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_INT);
        }
        switch (type.getBaseType()) {
            case XQItemType.XQBASETYPE_BYTE:
            case XQItemType.XQBASETYPE_SHORT:
                throw new XQException("Can't downgrade the Base Type from an Int number");
            default:
                break;
        }
        return createDecimal(new BigDecimal(value), type);
    }

    @Override
    public XQItem createItemFromLong(long value, XQItemType type) throws XQException {
        isClosedXQException();
        if (type == null) {
            type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_LONG);
        }
        switch (type.getBaseType()) {
            case XQItemType.XQBASETYPE_BYTE:
            case XQItemType.XQBASETYPE_SHORT:
            case XQItemType.XQBASETYPE_INT:
                throw new XQException("Can't downgrade the Base Type from an Long number");
            default:
                break;
        }
        return createDecimal(new BigDecimal(value), type);
    }

    @Override
    public XQItem createItemFromNode(Node value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        
        XQItem result = null;
        try {
            result = createItemFromString(nodeToString(value), type);
        } catch( Exception e ) {
            throw new XQException("Error Creating Item From Node" + e.getLocalizedMessage());
        }
        return result;
    }

    @Override
    public XQItem createItemFromShort(short value, XQItemType type) throws XQException {
        isClosedXQException();
        if (type == null) {
            type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_SHORT);
        }
        if (type.getBaseType()==XQItemType.XQBASETYPE_BYTE) {
            throw new XQException("Can't create a Byte from a Short number");
        }
        return createDecimal(new BigDecimal(value), type);
    }

    @Override
    public XQItem createItem(XQItem value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        if (value.isClosed()) {
            throw new XQException("Item is closed.");
        }
        XQItem result = new org.zorbaxquery.api.xqj.XQItem(value);
        return result;
    }

    @Override
    public XQSequence createSequence(XQSequence value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        if (value.isClosed()) {
            throw new XQException("Sequence is closed.");
        }
        XQSequence result = null;
        try {
            result = new org.zorbaxquery.api.xqj.XQSequence(value);
        } catch (Exception ex) {
            throw new XQException("Error creating sequence: " + ex.getLocalizedMessage());
        }
        return result;
    }

    @Override
    public XQSequence createSequence(Iterator value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        XQSequence result = null;
        try {
            result = new org.zorbaxquery.api.xqj.XQSequence(value);
        } catch (Exception ex) {
            throw new XQException("Error creating sequence: " + ex.getLocalizedMessage());
        }
        return result;
    }

    @Override
    public XQItemType createAtomicType(int basetype) throws XQException {
        isClosedXQException();
        if ((basetype==XQItemType.XQBASETYPE_UNTYPED) || 
            (basetype==XQItemType.XQBASETYPE_ANYTYPE) || 
            (basetype==XQItemType.XQBASETYPE_IDREFS) || 
            (basetype==XQItemType.XQBASETYPE_NMTOKENS) || 
            (basetype==XQItemType.XQBASETYPE_ENTITIES) || 
            (basetype==XQItemType.XQBASETYPE_ANYSIMPLETYPE)) {
            throw new XQException("Invalid base type.");
        }
        XQItemType type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, basetype);
        return type;
    }

    @Override
    public XQItemType createAtomicType(int basetype, QName qname, URI uri) throws XQException {
        if (closed) {
            throw new XQException("Object closed");
        }
        if ((basetype==XQItemType.XQBASETYPE_UNTYPED) || 
            (basetype==XQItemType.XQBASETYPE_ANYTYPE) || 
            (basetype==XQItemType.XQBASETYPE_IDREFS) || 
            (basetype==XQItemType.XQBASETYPE_NMTOKENS) || 
            (basetype==XQItemType.XQBASETYPE_ENTITIES) || 
            (basetype==XQItemType.XQBASETYPE_ANYSIMPLETYPE)) {
            throw new XQException("Invalid base type.");
        }
        XQItemType type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATOMIC, qname, basetype, uri);
        return type;
    }

    @Override
    public XQItemType createAttributeType(QName nodename, int basetype) throws XQException {
        isClosedXQException();
        if ((basetype==XQItemType.XQBASETYPE_UNTYPED)||(basetype==XQItemType.XQBASETYPE_ANYTYPE)) {
            throw new XQException("Base Type can't be XQItemType.XQBASETYPE_UNTYPED or XQItemType.XQBASETYPE_ANYTYPE");
        }
        return new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATTRIBUTE, nodename, basetype);
    }

    @Override
    public XQItemType createAttributeType(QName nodename, int basetype, QName typename, URI schemaURI) throws XQException {
        isClosedXQException();
        if ((basetype==XQItemType.XQBASETYPE_UNTYPED)||(basetype==XQItemType.XQBASETYPE_ANYTYPE)) {
            throw new XQException("Base Type can't be XQItemType.XQBASETYPE_UNTYPED or XQItemType.XQBASETYPE_ANYTYPE");
        }
        if ((schemaURI!=null) && (typename==null)) {
            throw new XQException("If Schema URI is specified, Base Type must be also specified");
        }
        return new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ATTRIBUTE, nodename, basetype, typename, schemaURI, true);
    }

    @Override
    public XQItemType createSchemaAttributeType(QName nodename, int basetype, URI uri) throws XQException {
        isClosedXQException();
        return new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_SCHEMA_ATTRIBUTE, nodename, basetype, uri);
    }

    @Override
    public XQItemType createCommentType() throws XQException {
        isClosedXQException();
        return new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_COMMENT);
    }

    @Override
    public XQItemType createDocumentElementType(XQItemType elementType) throws XQException {
        isClosedXQException();
        isNullXQException(elementType);
        if (elementType.getItemKind()!=XQItemType.XQITEMKIND_ELEMENT) {
            throw new XQException("Item Kind must be XQItemType.XQITEMKIND_ELEMENT");
        }
        return new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_DOCUMENT_ELEMENT, elementType.getNodeName(), elementType.getBaseType(), elementType.getSchemaURI());
    }

    @Override
    public XQItemType createDocumentSchemaElementType(XQItemType elementType) throws XQException {
        isClosedXQException();
        if (elementType.getItemKind()!=XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT) {
            throw new XQException("Item Kind must be XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT");
        }
        return new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_DOCUMENT_ELEMENT, elementType.getNodeName(), elementType.getBaseType(), elementType.getSchemaURI());
    }

    @Override
    public XQItemType createDocumentType() throws XQException {
        isClosedXQException();
        return new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_DOCUMENT);
    }

    @Override
    public XQItemType createElementType(QName nodename, int baseType) throws XQException {
        isClosedXQException();
        XQItemType item = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ELEMENT, nodename, baseType);
        return item;
    }

    @Override
    public XQItemType createElementType(QName nodename, int baseType, QName typename, URI schemaURI, boolean allowNill) throws XQException {
        isClosedXQException();
        XQItemType item = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ELEMENT, nodename, baseType, typename, schemaURI, allowNill);
        return item;
    }

    @Override
    public XQItemType createSchemaElementType(QName nodename, int baseType, URI schemaURI) throws XQException {
        isClosedXQException();
        XQItemType item = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_SCHEMA_ELEMENT, nodename, baseType, schemaURI);
        return item;
    }

    @Override
    public XQItemType createItemType() throws XQException {
        isClosedXQException();
        XQItemType type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_ITEM);
        return type;
    }

    @Override
    public XQItemType createNodeType() throws XQException {
        isClosedXQException();
        XQItemType type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_NODE);
        return type;
    }

    @Override
    public XQItemType createProcessingInstructionType(String piTarget) throws XQException {
        isClosedXQException();
        XQItemType type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_PI, piTarget);
        return type;
    }

    @Override
    public XQSequenceType createSequenceType(XQItemType item, int occurence) throws XQException {
        isClosedXQException();
        if ( ((item==null) && (occurence != XQSequenceType.OCC_EMPTY)) || ((item!=null) && (occurence == XQSequenceType.OCC_EMPTY))) {
            throw new XQException("Item is null");
        }
        if (!((occurence ==  XQSequenceType.OCC_ZERO_OR_ONE) ||
            (occurence == XQSequenceType.OCC_EXACTLY_ONE) ||
            (occurence == XQSequenceType.OCC_ZERO_OR_MORE) ||
            (occurence == XQSequenceType.OCC_ONE_OR_MORE) ||
            (occurence == XQSequenceType.OCC_EMPTY))) {
            throw new XQException("Occurence must be from: OCC_ZERO_OR_ONE, OCC_EXACTLY_ONE, OCC_ZERO_OR_MORE, OCC_ONE_OR_MORE, OCC_EMPTY ");
        }
        
        XQSequenceType result = new org.zorbaxquery.api.xqj.XQSequenceType(item, occurence);
        return result;
    }

    @Override
    public XQItemType createTextType() throws XQException {
        isClosedXQException();
        XQItemType type = new org.zorbaxquery.api.xqj.XQItemType(XQItemType.XQITEMKIND_TEXT);
        return type;
    }
    
    private void isClosedXQException() throws XQException {
        if (closed) {
            throw new XQException("This connection is closed");
        }
    }
    private void isNullXQException(Object value) throws XQException {
        if (value==null) {
            throw new XQException("Parameter shouldn't be null");
        }
    }
   
}
