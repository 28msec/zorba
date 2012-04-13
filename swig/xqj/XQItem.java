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

import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.StringReader;
import java.io.Writer;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.net.URI;
import java.util.Properties;
import javax.xml.datatype.DatatypeFactory;
import javax.xml.namespace.QName;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamReader;
import javax.xml.transform.Result;
import javax.xml.transform.Source;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.xquery.XQException;
import javax.xml.xquery.XQItemType;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.xml.sax.ContentHandler;
import org.xml.sax.InputSource;
import org.xml.sax.helpers.AttributesImpl;
import org.zorbaxquery.api.Item;
import org.zorbaxquery.api.Iterator;
import org.zorbaxquery.api.SerializationOptions;

class XQItem implements javax.xml.xquery.XQItem {

    private Item item;
    private boolean closed=false;
    private XQItemType itemType;
    
    protected Item getZorbaItem() {
        return item;
    }
    
    public XQItem(XQItemType itemType) {
        this.itemType = itemType;
    }

    public XQItem(Item item) {
        this.item = new Item(item);
        this.itemType = new org.zorbaxquery.api.xqj.XQItemType(this.item);
    }

    public XQItem(Item item, XQItemType itemType) {
        this.item = new Item(item);
        this.itemType = itemType;
    }

    public XQItem(javax.xml.xquery.XQItem item) throws XQException {
        this.item = new Item(((XQItem)item).getZorbaItem());
        this.itemType = item.getItemType();
    }

    @Override
    public void close() throws XQException {
        if (!closed) {
            item.close();
            item.delete();
            closed = true;
        }
    }

    @Override
    public boolean isClosed() {
        return closed;
    }

    @Override
    public boolean getBoolean() throws XQException {
        isClosedXQException();
        if (itemType.getBaseType()!=XQItemType.XQBASETYPE_BOOLEAN) {
            throw new XQException("Object is not boolean");
        }
        Boolean result;
        try {
            result = item.getBooleanValue();
        } catch (Exception e) {
            throw new XQException("Error getting boolean value" + e.getLocalizedMessage());
        }
        return result;
    }

    @Override
    public byte getByte() throws XQException {
        isClosedXQException();
        isDecimalXQException();
        byte result = 0;
        try {
            if (itemType.getBaseType() == XQItemType.XQBASETYPE_BYTE) {
                result = (byte) item.getIntValue();
            } else {
                result = Byte.parseByte(item.getStringValue());
            }
        } catch (Exception e) {
            throw new XQException("Error getting byte value" + e.getLocalizedMessage());
        }
        return result;
    }

    @Override
    public double getDouble() throws XQException {
        isClosedXQException();
        isFloatXQException();
        double result = 0;
        try {
            if (itemType.getBaseType() == XQItemType.XQBASETYPE_DOUBLE) {
                result = item.getDoubleValue();
            } else {
                result = Double.parseDouble(item.getStringValue());
            }
        } catch (Exception e) {
            throw new XQException("Error getting byte value" + e.getLocalizedMessage());
        }
        return result;
    }

    @Override
    public float getFloat() throws XQException {
        isClosedXQException();
        isFloatXQException();
        float result = 0;
        try {
            if (itemType.getBaseType() == XQItemType.XQBASETYPE_FLOAT) {
                result = (float)item.getDoubleValue();
            } else {
                result = Float.parseFloat(item.getStringValue());
            }
        } catch (Exception e) {
            throw new XQException("Error getting byte value" + e.getLocalizedMessage());
        }
        return result;
    }

    @Override
    public int getInt() throws XQException {
        isClosedXQException();
        isDecimalXQException();
        int result = 0;
        try {
            if (itemType.getBaseType() == XQItemType.XQBASETYPE_INT) {
                result = item.getIntValue();
            } else {
                result = Integer.parseInt(item.getStringValue());
            }
        } catch (Exception e) {
            throw new XQException("Error getting byte value" + e.getLocalizedMessage());
        }
        return result;
    }

    @Override
    public XQItemType getItemType() throws XQException {
        isClosedXQException();
        return itemType;
    }

    @Override
    public String getAtomicValue() throws XQException {
        isClosedXQException();
        if (!item.isAtomic()) {
            throw new XQException("Object is not atomic");
        }
        org.zorbaxquery.api.Item lItem = null;
        try {
            org.zorbaxquery.api.Iterator iterator = item.getAtomizationValue();
            lItem = new Item();  // creating a new item to be filled by iterator
            iterator.open();
            iterator.next(lItem); // item CAN'T BE NULL
            iterator.close();
        } catch (Exception e) {
            throw new XQException("Error getting atomic value: " + e.getLocalizedMessage());
        }
        return lItem.getStringValue();
    }

    @Override
    public long getLong() throws XQException {
        isClosedXQException();
        isDecimalXQException();
        long result = 0;
        try {
            if (itemType.getBaseType() == XQItemType.XQBASETYPE_LONG) {
                result = item.getLongValue();
            } else {
                result = Long.parseLong(item.getStringValue());
            }
        } catch (Exception e) {
            throw new XQException("Error getting byte value" + e.getLocalizedMessage());
        }
        return result;
    }

    @Override
    public Node getNode() throws XQException {
        isClosedXQException();
        if (!item.isNode()) {
            throw new XQException("Object is not a node");
        }
        Node result = null;
        InputStream inputStream = new ByteArrayInputStream(item.toString().getBytes());
        try {
            DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
            DocumentBuilder db = dbf.newDocumentBuilder();
            Document doc = db.newDocument();
            Item nodeName = new Item();
            item.getNodeName(nodeName);
            switch (itemType.getItemKind()) {
                case XQItemType.XQITEMKIND_ATTRIBUTE:
                    result = doc.createAttributeNS("", nodeName.getStringValue());
                    break;
                case XQItemType.XQITEMKIND_COMMENT:
                    result = doc.createComment(item.getStringValue());
                    break;
                case XQItemType.XQITEMKIND_DOCUMENT:
                    String tmpDoc = item.serialize();
                    if (tmpDoc.length()>0) {
                        result = db.parse(new InputSource(new StringReader(tmpDoc)));
                    } else {
                        result = doc;  // empty doc
                    }
                    break;
                case XQItemType.XQITEMKIND_ELEMENT:
                    Element e = doc.createElementNS("", nodeName.getStringValue());
                    Node text = doc.createTextNode(item.getStringValue());
                    e.appendChild(text);
                    result = e;
                    break;
                case XQItemType.XQITEMKIND_PI:
                    String tmpPI = item.serialize().substring(2).split(" ")[0];
                    result = doc.createProcessingInstruction(tmpPI, item.getStringValue());
                    break;
                case XQItemType.XQITEMKIND_TEXT:
                    result = doc.createTextNode(item.getStringValue());
                    break;
                default:
                    throw new XQException("Error getting the node for this Item Kind.");
            }
        } catch (Exception ex) {
            throw new XQException("Error converting Item to Node" + ex.getLocalizedMessage());
        }
        
        return result;
    }

    @Override
    public URI getNodeUri() throws XQException {
        isClosedXQException();
        if (!item.isNode()) {
            throw new XQException("Object is not a node");
        }
        URI result;
        String namespace = "";
        try {
            namespace = item.getNamespace();
        } catch (Exception ex) {
            throw new XQException("Error getting Node URI: " + ex.getLocalizedMessage());
        }
        try {
            result = new URI(namespace);
        } catch (Exception ex) {
            throw new XQException("Error getting Node URI: " + ex.getLocalizedMessage());
        }
        return result;
    }

    @Override
    public Object getObject() throws XQException {
        isClosedXQException();
        Object result = null;
        try {
            if ((itemType.getItemKind()==XQItemType.XQITEMKIND_ATTRIBUTE) ||
                (itemType.getItemKind()==XQItemType.XQITEMKIND_COMMENT) ||
                (itemType.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT) ||
                (itemType.getItemKind()==XQItemType.XQITEMKIND_ELEMENT) ||
                (itemType.getItemKind()==XQItemType.XQITEMKIND_PI) ||
                (itemType.getItemKind()==XQItemType.XQITEMKIND_TEXT) ) {
                result = this.getNode();
            } else if (itemType.getItemKind()==XQItemType.XQITEMKIND_ATOMIC) {

                DatatypeFactory factory = DatatypeFactory.newInstance();
                switch (itemType.getBaseType()) {
                    case XQItemType.XQBASETYPE_ANYURI:
                        result = item.getStringValue();
                        break;
                    case XQItemType.XQBASETYPE_BASE64BINARY:
                        result = item.serialize().getBytes();
                        break;
                    case XQItemType.XQBASETYPE_BOOLEAN:
                        result = item.getBooleanValue();
                        break;
                    case XQItemType.XQBASETYPE_BYTE:
                        result = new Byte(item.getStringValue());
                        break;
                    case XQItemType.XQBASETYPE_DATE:
                    case XQItemType.XQBASETYPE_DATETIME:
                    case XQItemType.XQBASETYPE_GDAY:
                    case XQItemType.XQBASETYPE_GMONTH:
                    case XQItemType.XQBASETYPE_GMONTHDAY:
                    case XQItemType.XQBASETYPE_GYEAR:
                    case XQItemType.XQBASETYPE_GYEARMONTH:
                    case XQItemType.XQBASETYPE_TIME:
                        result = factory.newXMLGregorianCalendar(item.getStringValue());
                        break;
                    case XQItemType.XQBASETYPE_DURATION:
                        result = factory.newDuration(item.getStringValue());
                        break;
                    case XQItemType.XQBASETYPE_DAYTIMEDURATION:
                        String tmpString = item.getStringValue();
                        result = factory.newDurationDayTime(tmpString);
                        break;
                    case XQItemType.XQBASETYPE_YEARMONTHDURATION:
                        result = factory.newDurationYearMonth(item.getStringValue());
                        break;
                    case XQItemType.XQBASETYPE_DECIMAL:
                        result = new BigDecimal(item.getStringValue());
                        break;
                    case XQItemType.XQBASETYPE_DOUBLE:
                        result = item.getDoubleValue();
                        break;
                    case XQItemType.XQBASETYPE_ENTITIES:
                        result = item.getStringValue();
                        break;
                    case XQItemType.XQBASETYPE_ENTITY:
                        result = item.getStringValue();
                        break;
                    case XQItemType.XQBASETYPE_FLOAT:
                        result = (float)(item.getDoubleValue());
                        break;
                    case XQItemType.XQBASETYPE_HEXBINARY:
                        result = item.getStringValue().getBytes();
                        break;
                    case XQItemType.XQBASETYPE_ID:
                        result = item.getStringValue();
                        break;
                    case XQItemType.XQBASETYPE_IDREF:
                        result = item.getStringValue();
                        break;
                    case XQItemType.XQBASETYPE_IDREFS:
                        result = item.getStringValue();
                        break;
                    case XQItemType.XQBASETYPE_INT:
                        result = item.getIntValue();
                        break;
                    case XQItemType.XQBASETYPE_LANGUAGE:
                        result = item.getStringValue();
                        break;
                    case XQItemType.XQBASETYPE_LONG:
                        result = item.getLongValue();
                        break;
                    case XQItemType.XQBASETYPE_NAME:
                        result = item.getStringValue();
                        break;
                    case XQItemType.XQBASETYPE_NCNAME:
                        result = item.serialize();
                        break;
                    case XQItemType.XQBASETYPE_NMTOKEN:
                        result = item.getStringValue();
                        break;
                    case XQItemType.XQBASETYPE_NMTOKENS:
                        result = item.getStringValue();
                        break;
                    case XQItemType.XQBASETYPE_INTEGER:
                    case XQItemType.XQBASETYPE_NEGATIVE_INTEGER:
                    case XQItemType.XQBASETYPE_POSITIVE_INTEGER:
                    case XQItemType.XQBASETYPE_NONNEGATIVE_INTEGER:
                    case XQItemType.XQBASETYPE_NONPOSITIVE_INTEGER:
                    case XQItemType.XQBASETYPE_UNSIGNED_LONG:
                        result = new BigInteger(item.getStringValue());
                        break;
                    case XQItemType.XQBASETYPE_NORMALIZED_STRING:
                        result = item.getStringValue();
                        break;
                    case XQItemType.XQBASETYPE_NOTATION:
                        result = item.getStringValue();
                        break;
                    case XQItemType.XQBASETYPE_QNAME:
                        result = new QName(item.getNamespace(), item.getLocalName(), item.getPrefix()) ;
                        break;
                    case XQItemType.XQBASETYPE_STRING:
                        result = item.getStringValue();
                        break;
                    case XQItemType.XQBASETYPE_TOKEN:
                        result = item.getStringValue();
                        break;
                    case XQItemType.XQBASETYPE_SHORT:
                    case XQItemType.XQBASETYPE_UNSIGNED_BYTE:
                        result = new Short(item.getStringValue());
                        break;
                    case XQItemType.XQBASETYPE_UNSIGNED_INT:
                        result = new Long(item.getStringValue());
                        break;
                    case XQItemType.XQBASETYPE_UNSIGNED_SHORT:
                        result = new Integer(item.getStringValue());
                        break;
                    case XQItemType.XQBASETYPE_UNTYPED:
                        result = item.getStringValue();
                        break;
                    case XQItemType.XQBASETYPE_UNTYPEDATOMIC:
                        result = item.getStringValue();
                        break;
                    default:
                        throw new XQException("Error getting object for this ItemType");
                }

            }
        } catch (Exception e) {
            throw new XQException("Error getting byte value: " + e.getLocalizedMessage());
        }
        return result;
    }

    @Override
    public XMLStreamReader getItemAsStream() throws XQException {
        isClosedXQException();
        XMLInputFactory factory = XMLInputFactory.newInstance();
        XMLStreamReader result = null;
        try {
            result = factory.createXMLStreamReader(new StringReader(item.serialize()));
        } catch (Exception ex) {
            throw new XQException("Error creating XMLStreamReader: " + ex.getLocalizedMessage());
        }
        return result;
    }

    @Override
    public String getItemAsString(Properties prprts) throws XQException {
        isClosedXQException();
        String result = null;
        try {
            SerializationOptions opts = new SerializationOptions();
            if ((prprts!=null) && prprts.size()>0) {
                for(String key : prprts.stringPropertyNames()) {
                    String value = prprts.getProperty(key);
                    opts.setSerializerOption(key, value);
                }
            }
            result = item.serialize(opts).replace("&gt;", ">").replace("&lt;", "<");
        } catch (Exception ex) {
            throw new XQException("Error serializing item" + ex.getLocalizedMessage());
        }
        return result;
    }

    @Override
    public short getShort() throws XQException {
        isClosedXQException();
        isDecimalXQException();
        short result;
        try {
            if (itemType.getBaseType() == XQItemType.XQBASETYPE_SHORT) {
                result = (short) item.getIntValue();
            } else {
                result = Short.parseShort(item.getStringValue());
            }
        } catch (Exception ex) {
            throw new XQException("Error getting short value: " + ex.getLocalizedMessage());
        }
        return result;
    }

    @Override
    public boolean instanceOf(XQItemType xqit) throws XQException {
        isClosedXQException();
        return itemType.equals(xqit);
    }

    @Override
    public void writeItem(OutputStream out, Properties prprts) throws XQException {
        isClosedXQException();
        isNullXQException(out);
        isNullXQException(prprts);
        try {
            SerializationOptions opts = new SerializationOptions();
            if ((prprts!=null) && prprts.size()>0) {
                for(String key : prprts.stringPropertyNames()) {
                    String value = prprts.getProperty(key);
                    opts.setSerializerOption(key, value);
                }
            }
            out.write(item.serialize(opts).getBytes());
        } catch (Exception ex) {
            throw new XQException("Error writing on stream: " + ex.getLocalizedMessage());
        }
    }

    @Override
    public void writeItem(Writer writer, Properties prprts) throws XQException {
        isClosedXQException();
        isNullXQException(writer);
        isNullXQException(prprts);
        try {
            SerializationOptions opts = new SerializationOptions();
            if ((prprts!=null) && prprts.size()>0) {
                for(String key : prprts.stringPropertyNames()) {
                    String value = prprts.getProperty(key);
                    opts.setSerializerOption(key, value);
                }
            }
            writer.write(item.serialize(opts));
        } catch (Exception ex) {
            throw new XQException("Error sending to writer: " + ex.getLocalizedMessage());
        }
    }

    @Override
    public void writeItemToSAX(ContentHandler ch) throws XQException {
        isClosedXQException();
        isNullXQException(ch);
        try {
            AttributesImpl attributes = new AttributesImpl();
            Iterator attr = item.getAttributes();
            attr.open();
            Item attribute = new Item();
            while (attr.next(attribute)) {
                attributes.addAttribute(attribute.getNamespace(), attribute.getLocalName(), "", attribute.getType().getStringValue(), attribute.getStringValue());
            }
            attribute.close();
            attr.close();
            attr.delete();
            //attribute.delete();
            String namespace = "";
            if (itemType.getBaseType() != XQItemType.XQBASETYPE_ANYTYPE){
                namespace = item.getNamespace();
            }
            Item name = new Item();
            item.getNodeName(name);
            String nodeName = name.getStringValue();
            name.close();
            //name.delete();
            char [] content = item.getStringValue().toCharArray();
            
            ch.startElement(namespace, nodeName , "", attributes);
            ch.characters(content, 0, content.length);
            ch.endElement(namespace, nodeName, "");
        } catch (Exception ex) {
            throw new XQException("Error writing item to SAX: " + ex.getLocalizedMessage());
        }
    }

    @Override
    public void writeItemToResult(Result result) throws XQException {
        isClosedXQException();
        isNullXQException(result);
        try {
            Source xmlSource = new DOMSource(getNode());
            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            Transformer transformer;
            transformer = transformerFactory.newTransformer();
            transformer.setOutputProperty("indent", "yes");
            transformer.transform(xmlSource, result);
        } catch (Exception ex) {
            throw new XQException ("Error serializing to javax.xml.transform.Result");
        }
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
    
    private void isDecimalXQException() throws XQException {
        switch (itemType.getBaseType()) {
            case XQItemType.XQBASETYPE_DECIMAL:
            case XQItemType.XQBASETYPE_BYTE:
            case XQItemType.XQBASETYPE_INT:
            case XQItemType.XQBASETYPE_INTEGER:
            case XQItemType.XQBASETYPE_LONG:
            case XQItemType.XQBASETYPE_NEGATIVE_INTEGER:
            case XQItemType.XQBASETYPE_NONNEGATIVE_INTEGER:
            case XQItemType.XQBASETYPE_NONPOSITIVE_INTEGER:
            case XQItemType.XQBASETYPE_POSITIVE_INTEGER:
            case XQItemType.XQBASETYPE_SHORT:
            case XQItemType.XQBASETYPE_UNSIGNED_LONG:
            case XQItemType.XQBASETYPE_UNSIGNED_INT:
            case XQItemType.XQBASETYPE_UNSIGNED_SHORT:
            case XQItemType.XQBASETYPE_UNSIGNED_BYTE:
                break;
            default:
                throw new XQException("Object is not xs:decimal or a derivate");
        }
    }
    
    private void isFloatXQException() throws XQException {
        if (! ((itemType.getBaseType()==XQItemType.XQBASETYPE_FLOAT) ||
            (itemType.getBaseType()==XQItemType.XQBASETYPE_DOUBLE)) )
            {
                throw new XQException("Object is not xs:decimal or a derivate");
            }
    }
}
