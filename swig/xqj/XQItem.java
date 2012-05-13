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
import java.util.ArrayList;
import java.util.Collection;
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
import org.zorbaxquery.api.StringPair;
import org.zorbaxquery.api.StringPairVector;

/**
  * This class represents an item in the XDM.
  * This class also implements the common interface XQItemAccessor for accessing the values of an XQuery item. All the get functions raise an exception if the underlying sequence object is not positioned on an item (e.g. if the sequence is positioned before the first item or after the last item). 
  * 
  * Example -
  * 
  *  \code{.java}
  *   XQPreparedExpression expr = conn.prepareExpression("for $i ..");
  *   XQSequence result = expr.executeQuery();
  * 
  *   // create the ItemTypes for string and integer
  *   XQItemType strType = conn.createAtomicType(XQItemType.XQBASETYPE_STRING);
  *   XQItemType intType = conn.createAtomicType(XQItemType.XQBASETYPE_INTEGER);
  *  
  *   // posititioned before the first item
  *   while (result.next())
  *   {
  *     // If string or any of its subtypes, then get the string value out
  *  
  *     if (result.instanceOf(strType))
  *       String str = result.getAtomicValue();
  *     else if (result.instanceOf(intType))
  *        // if it is exactly an int
  *       int intval = result.getInt();
  *       ...
  *  
  *     // Alternatively, you can get the exact type out.
  *     XQItemType type = result.getItemType();
  *  
  *     // Now perform the comparison..
  *     if (type.equals(intType))
  *     { ... };
  *   
  *   }
  *  \endcode
  * See also:
  * Table 6 - XQuery Atomic Types and Corresponding Java Object Types, XQuery API for Java (XQJ) 1.0, for mapping of XQuery atomic types to Java object types. For example, if the XQuery value returned is of type xs:unsignedByte, then calling the getObject() method will return a Java object of type java.lang.Short.
  * Table 7 - XQuery Node Types and Corresponding Java Object Types XQuery API for Java (XQJ) 1.0, for the mapping of XQuery node types to the corresponding Java object types. For example, if the XQuery value returned is an element node, then calling the getObject() or getNode() method will return a Java object of type org.w3.dom.Element.
  *   
  
  */
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

  /** \brief   Close the item and release all the resources associated with this item.
   * 
   *   Close the item and release all the resources associated with this item. No method other than the isClosed or close method may be called once the item is closed. Calling close on an XQItem object that is already closed has no effect.
   * 
   * @throw XQException - if there is an error during closing the item
   */
    @Override
    public void close() throws XQException {
        if (!closed) {
            item.close();
            item.delete();
            closed = true;
        }
    }

  /** \brief  Checks if the item is closed.
   * 
   *  Checks if the item is closed.
   * 
   * @return boolean true if the item is in a closed state, false otherwise
   */
    @Override
    public boolean isClosed() {
        return closed;
    }

  /** \brief Gets the current item as a boolean.
   * 
   * Gets the current item as a boolean. The current item must be an atomic value of type xs:boolean or a subtype.
   * 
   * @return a boolean representing the current item
   * @throw XQException - if (1) the conversion of the current item to a boolean fails, (2) if there are errors accessing the current item, (3) if the underlying sequence or item is in a closed state, or (4) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
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

  /** \brief Gets the current item as a byte.
   * 
   * Gets the current item as a byte. The current item must be an atomic value of type xs:decimal or a subtype, and its value must be in the value space of byte.
   * 
   * @return a byte representing the current item
   * @throw XQException - if (1) the conversion of the current item to a byte fails, (2) if there are errors accessing the current item, (3) if the underlying sequence or item is in a closed state, or (4) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
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

  /** \brief Gets the current item as a double.
   * 
   * Gets the current item as a double. The current item must be an atomic value of type xs:double or a subtype.
   * 
   * @return a double representing the current item
   * @throw XQException - if (1) the conversion of the current item to a double fails, (2) if there are errors accessing the current item, (3) if the underlying sequence or item is in a closed state, or (4) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
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

  /** \brief Gets the current item as a float.
   * 
   * Gets the current item as a float. The current item must be an atomic value of type xs:float or a subtype.
   * 
   * @return a float representing the current item
   * @throw XQException - if (1) the conversion of the current item to a float fails, (2) if there are errors accessing the current item, (3) if the underlying sequence or item is in a closed state, or (4) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
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

  /** \brief Gets the current item as an int. 
   * 
   * Gets the current item as an int. The current item must be an atomic value of type xs:decimal or a subtype, and its value must be in the value space of int.
   * 
   * @return an int representing the current item
   * @throw XQException - if (1) the conversion of the current item to a int fails, (2) if there are errors accessing the current item, (3) if the underlying sequence or item is in a closed state, or (4) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
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

  /** \brief Gets the type of the item. 
   * 
   * Gets the type of the item. 
   * On a forward only sequence this method can be called independent of any other get or write method. It will not raise an error if such method has been called already, nor will it affect subsequent invocations of any other get or write method.
   * 
   * @return the type of the item
   * @throw XQException - if (1) there are errors accessing the type of the item, or (2) the underlying sequence or item is in a closed state
   */
    @Override
    public XQItemType getItemType() throws XQException {
        isClosedXQException();
        return itemType;
    }

  /** \brief Gets the current item as a Java String.
   * 
   * Gets the current item as a Java String. The current item must be an atomic value. This function casts the current item to an xs:string value according to the casting rules defined in 17.1.2 Casting to xs:string and xs:untypedAtomic, XQuery 1.0 and XPath 2.0 Functions and Operators, and then returns the value as a Java String.
   * 
   * @return the string representation of the item
   * @throw XQException - if (1) there are errors accessing the item's value, (2) the item is not an atomic value, (3) there is an error when casting the item to a string representation, (4) the underlying sequence or item is in a closed state, or (5) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
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

  /** \brief Gets the current item as a long.
   * 
   * Gets the current item as a long. The current item must be an atomic value of type xs:decimal or a subtype, and its value must be in the value space of long.
   * 
   * @return a long representing the current item
   * @throw XQException - if (1) the conversion of the current item to a long fails, (2) if there are errors accessing the current item, (3) if the underlying sequence or item is in a closed state, or (4) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
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

  /** \brief Gets the item as a DOM node.
   * 
   * Gets the item as a DOM node. The current item must be a node. The type of the returned DOM node is governed by Table 7 - XQuery Node Types and Corresponding Java Object Types XQuery API for Java (XQJ) 1.0 The instance of the returned node is implementation dependent. The node may be a reference or a copy of the internal state of the item. It is advisable to make a copy of the node if the application plans to modify it.
   * 
   * @return a DOM node representing the current item
   * @throw XQException - if (1) if there are errors accessing the current item, (2) the current item is not a node, (3) if the underlying sequence or item is in a closed state, or (4) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
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
            }
        } catch (Exception ex) {
            throw new XQException("Error converting Item to Node" + ex.getLocalizedMessage());
        }
        
        return result;
    }

  /** \brief Returns the URI for this item.
   * 
   * Returns the URI for this item. If the item is a document node, then this method returns the absolute URI of the resource from which the document node was constructed. If the document URI is not available, then the empty string is returned. If the document URI is available, the returned value is the same as if fn:document-uri were evaluated on this document node. If the item is of a node kind other than document node, then the returned URI is implementation-defined.
   * On a forward only sequence this method can be called independent of any other get or write method. It will not raise an error if such method has been called already, nor will it affect subsequent invocations of any other get or write method on the current item.
   * 
   * @return the document URI for this document node or the empty string if not available. For other node kinds, the result is implementation-defined
   * @throw XQException - if (1) if there are errors accessing the current item, (2) the current item is not a node, (3) if the underlying sequence or item is in a closed state
   */
    @Override
    public URI getNodeUri() throws XQException {
        isClosedXQException();
        if (!item.isNode()) {
            throw new XQException("Object is not a node");
        }
        URI result;
        String namespace = "";
        try {
            Item type = new Item();
            type = item.getType();
            if (type.getStringValue().equalsIgnoreCase("xs:qname")) {
                namespace = item.getNamespace();
            } else {
                StringPairVector bindings = item.getNamespaceBindings();
                // Not using the full set, only the first binding
                if (bindings.size()>0) {
                    StringPair pair = bindings.get(0);
                    namespace = pair.getFirst();
                }
            }
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

  /** \brief Gets the current item as an Object.
   * 
   * Gets the current item as an Object. The data type of the returned object will be the Java Object type as specified in 14.4 Mapping an XQuery Atomic Value to a Java Object Type and 14.5 Mapping an XQuery Node to a Java Object Type, XQuery API for Java (XQJ) 1.0.
   * 
   * @return an object representing the current item
   * @throw XQException - if (1) if there are errors accessing the current item, (2) if the underlying sequence or item is in a closed state, or (3) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
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
                //result = this.getNode();
                DatatypeFactory factory = DatatypeFactory.newInstance();
                switch (itemType.getBaseType()) {
                    /*
                    case XQItemType.XQBASETYPE_ANYATOMICTYPE:
                        break;
                    case XQItemType.XQBASETYPE_ANYSIMPLETYPE:
                        break;
                    case XQItemType.XQBASETYPE_ANYTYPE:
                        break;
                     *
                     */
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
                }

            }
        } catch (Exception e) {
            throw new XQException("Error getting byte value: " + e.getLocalizedMessage());
        }
        return result;
    }

  /** \brief Read the current item as an XMLStreamReader object.
   * 
   * Read the current item as an XMLStreamReader object, as described in Section 12.1 Serializing an XDM instance into a StAX event stream (XMLStreamReader), XQuery API for Java (XQJ) 1.0. Note that the serialization process might fail, in which case a XQException is thrown. While the stream is being read, the application MUST NOT do any other concurrent operations on the underlying item or sequence. The operation on the stream is undefined if the underlying sequence is repositioned or the state of the underlying item or sequence is changed by concurrent operations.
   * 
   * @return an XML reader object as XMLStreamReader
   * @throw XQException - if (1) there are errors accessing the current item or the underlying sequence, (2) the underlying sequence or item is in a closed state, (3) in the case of a forward only sequence, a get or write method has already been invoked on the current item, or (4) in case of an error during serialization of the current item into a StAX event stream as defined in Section 12.1 Serializing an XDM instance into a StAX event stream (XMLStreamReader), XQuery API for Java (XQJ) 1.0
   */
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

  /** \brief Serializes the current item according to the XSLT 2.0 and XQuery 1.0 serialization.
   * 
   * Serializes the current item according to the XSLT 2.0 and XQuery 1.0 serialization. Serialization parameters, which influence how serialization is performed, can be specified. Refer to the XSLT 2.0 and XQuery 1.0 serialization and Section 12 Serialization, XQuery API for Java (XQJ) 1.0 for more information.
   * 
   * @param prprts - specifies the serialization parameters, null is considered equivalent to an empty Properties object
   * @return the serialized representation of the item
   * @throw XQException - if (1) there are errors accessing the current item or the underlying sequence, (2) the underlying sequence or item is in a closed state, (3) in the case of a forward only sequence, a get or write method has already been invoked on the current item, or (4) if there are errors during serialization
   */
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

  /** \brief Gets the current item as a short.
   * 
   * Gets the current item as a short. The current item must be an atomic value of type xs:decimal or a subtype, and its value must be in the value space of short.
   * 
   * @return a short representing the current item
   * @throw XQException - if (1) the conversion of the current item to a short fails, (2) if there are errors accessing the current item, (3) if the underlying sequence or item is in a closed state, or (4) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
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

  /** \brief Checks if the item "matches" an item type.
   * 
   * Checks if the item "matches" an item type, as defined in 2.5.4.2 Matching an Item Type and an Item, XQuery 1.0: An XML Query Language. You can use this method to first check the type of the result before calling the specific get methods. 
   * 
   * Example -
   * \code{.java}
   *   ...
   *   XQItemType strType = conn.createAtomicType(XQItemType.XQBASETYPE_STRING);
   *   XQItemType nodeType = conn.createNodeType();
   * 
   *   XQSequence result = preparedExpr.executeQuery();
   *   while (result.next())
   *   {
   *      // Generic check for node.. 
   *      if (result.instanceOf(nodeType))
   *         org.w3.dom.Node node = result.getNode();
   *      else if (result.instanceOf(strType))
   *         String str = result.getAtomicValue();
   *    }
   *  
   * 
   * If either the type of the XQItemAccessor or the input XQItemType is not a built-in type, then this method is allowed to raise exception if it can NOT determine the instanceOf relationship due to the lack of the access of the XML schema that defines the user defined schema types if the XQMetaData.isUserDefinedXMLSchemaTypeSupported() method returns false. 
   * Otherwise, this method must determine if the type of the XQItemAccessor is an instance of the input XQItemType. Note even if isUserDefinedXMLSchemaTypeSupported() returns false, an XQJ implementation may still be able to determine the instanceOf relationship for certain cases involving user defined schema type. For example, if the type of an XQItemAccessor is of mySchema:hatSize sequence type and the input parameter XQItemType is of item() sequence type, the return value for instanceOf relationship should always be true even though the XQJ implementation does not know the precise type information of mySchema:hatSize type defined in XML schema 'mySchema'.
   * \endcode
   * @param xqit - item type to match
   * @return true if this item matches the input item type as defined in 2.5.4.2 Matching an Item Type and an Item, XQuery 1.0: An XML Query Language, and false if it does not
   * @throw XQException - if (1) there are errors accessing the item's type, (2) if the underlying sequence or item is in a closed state, (3) if the implementation is unable to determine the schema definition of a user defined schema type, or (4) the type parameter is null
   */
    @Override
    public boolean instanceOf(XQItemType xqit) throws XQException {
        isClosedXQException();
        return itemType.equals(xqit);
    }

  /** \brief Serializes the current item to a Writer.
   * 
   * Serializes the current item to a Writer according to XSLT 2.0 and XQuery 1.0 serialization. Serialization parameters, which influence how serialization is performed, can be specified. Refer to the XSLT 2.0 and XQuery 1.0 serialization and Section 12 Serialization, XQuery API for Java (XQJ) 1.0 for more information.
   * 
   * @param out - the output stream into which the current item is to be serialized
   * @param prprts - specifies the serialization parameters, null is considered equivalent to an empty Properties object
   * @throw XQException - if (1) there are errors accessing the current item or the underlying sequence, (2) the underlying sequence or item is in a closed state, (3) in the case of a forward only sequence, a get or write method has already been invoked on the current item, (4) if there are errors during serialization, or (5) the os parameter is null
   */
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

  /** \brief Serializes the current item to a Writer.
   * 
   * Serializes the current item to a Writer according to XSLT 2.0 and XQuery 1.0 serialization. Serialization parameters, which influence how serialization is performed, can be specified. Refer to the XSLT 2.0 and XQuery 1.0 serialization and Section 12 Serialization, XQuery API for Java (XQJ) 1.0 for more information.
   * 
   * Warning: When outputting to a Writer, make sure the writer's encoding matches the encoding parameter if specified as a property or the default encoding.
   * @param out - the output stream into which the current item is to be serialized
   * @param prprts - specifies the serialization parameters, null is considered equivalent to an empty Properties object
   * @throw XQException - if (1) there are errors accessing the current item or the underlying sequence, (2) the underlying sequence or item is in a closed state, (3) in the case of a forward only sequence, a get or write method has already been invoked on the current item, (4) if there are errors during serialization, or (5) the os parameter is null
   */
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

  /** \brief Writes the current item to a SAX handler.
   * 
   * Writes the current item to a SAX handler, as described in in Section 12.2 Serializing an XDM instance into a SAX event stream, XQuery API for Java (XQJ) 1.0. Note that the serialization process might fail, in which case a XQException is thrown. The specified org.xml.sax.ContentHandler can optionally implement the org.xml.sax.LexicalHandler interface. An implementation must check if the specified ContentHandler implements LexicalHandler. If the handler is a LexicalHandler comment nodes are reported, otherwise they will be silently ignored.
   * 
   * @param saxhdlr - the SAX content handler, optionally a lexical handler
   * @throw XQException - if (1) there are errors accessing the current item or the underlying sequence, (2) the underlying sequence or item is in a closed state, (3) in the case of a forward only sequence, a get or write method has already been invoked on the current item, (4) in case of an error while serializing the XDM instance into a SAX event stream, or (5) the saxhdlr parameter is null
   */
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

  /** \brief Writes the current item to a Result.
   * 
   * Writes the current item to a Result. First the item is normalized as described in XSLT 2.0 and XQuery 1.0 serialization. Subsequently it is serialized to the Result object.
   * Note that the normalization process can fail, in which case an XQException is thrown. An XQJ implementation must at least support the following implementations:
   * - javax.xml.transform.dom.DOMResult
   * - javax.xml.transform.sax.SAXResult
   * - javax.xml.transform.stream.StreamResult
   * 
   * @param result - the result object into which the item is to be serialized
   * @throw XQException - if (1) there are errors accessing the current item or the underlying sequence, (2) the underlying sequence or item is in a closed state, (3) in the case of a forward only sequence, a get or write method has already been invoked on the current item, (4) in case of an error while serializing the current item into the Result object, or (5) the result parameter is null
   */
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
