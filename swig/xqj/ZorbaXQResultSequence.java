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
import org.zorbaxquery.api.SerializationOptions;

 /**
   * This class represents a sequence of items obtained as a result of evaluation XQuery expressions. The result sequence is tied to the XQconnection object on which the expression was evaluated.
   * 
   * This sequence can be obtained by performing an executeQuery on the expression object. It represents a cursor-like class.
   * 
   * The ZorbaXQResultSequence object is dependent on the connection and the expression from which it was created and is only valid for the duration of those objects. Thus, if any one of those objects is closed, this ZorbaXQResultSequence object will be implicitly closed and it can no longer be used. Similarly re-executing the expression also implicitly closes the associated result sequences.
   * 
   * An XQJ driver is not required to provide finalizer methods for the connection and other objects. Hence it is strongly recommended that users call close method explicitly to free any resources. It is also recommended that they do so under a final block to ensure that the object is closed even when there are exceptions. Not closing this object implicitly or explicitly might result in serious memory leaks.
   * 
   * When the ZorbaXQResultSequence is closed any ZorbaXQResultItem objects obtained from it are also implicitly closed.
   * 
   * Example -
   * 
   * \code{.java} 
   *   XQPreparedExpression expr = conn.prepareExpression("for $i ..");
   *   ZorbaXQResultSequence result = expr.executeQuery();
   *  
   *   // create the ItemTypes for string and integer
   *   XQItemType strType = conn.createAtomicType(XQItemType.XQBASETYPE_STRING);
   *   XQItemType intType = conn.createAtomicType(XQItemType.XQBASETYPE_INT);
   * 
   *   // posititioned before the first item
   *   while (result.next())
   *   {
   *     XQItemType type = result.getItemType();
   *  
   *     // If string, then get the string value out
   *     if (type.equals(strType))
   *       String str = result.getAtomicValue();
   *     else if (type.equals(intType))  // if it is an integer..
   *       int intval = result.getInt();
   *       ...
   *   }
   *  
   *   result.close(); // explicitly close the result sequence
   * \endcode
   */
public class ZorbaXQResultSequence implements javax.xml.xquery.XQResultSequence {
    
    private boolean closed = false;
    private boolean delivered = false;
    //private boolean isonitem = false;
    private boolean consumedItem = false;
    private boolean iterDeleted = false;

    private XQConnection connection = null;
    private Iterator iter = null;
    private ZorbaXQResultItem current = null;
    private Collection<ZorbaXQResultItem> items = new ArrayList<ZorbaXQResultItem>();
    private org.zorbaxquery.api.XQuery lQuery=null;
    private boolean preparedExpression;
    private ZorbaXQStaticCollectionManager lStaticCollectionManager;

    public ZorbaXQResultSequence(XQConnection conn, org.zorbaxquery.api.XQuery query, boolean prepared) {
        lQuery = query;
        iter = query.iterator();
        iter.open();
        connection = conn;
        preparedExpression = prepared;
    }

  /** \brief   Gets the XQuery connection associated with this result sequence
   * 
   * @return the connection associated with this result sequence
   * @throw XQException - if the result sequence is in a closed state
   */
    @Override
    public XQConnection getConnection() throws XQException {
        isClosedXQException();
        return connection;
    }

  /** \brief Moves the XQSequence's position to the given item number in this object.
   * 
   * If the item number is positive, the XQSequence moves to the given item number with respect to the beginning of the XQSequence.
   * The first item is item 1, the second is item 2, and so on.
   * 
   * If the given item number is negative, the XQSequence positions itself on an absolute item position with respect to the end of the sequence.
   * 
   * For example, calling the method absolute(-1) positions the XQSequence on the last item; calling the method absolute(-2) moves the XQSequence to the next-to-last item, and so on. absolute(0) will position the sequence before the first item.
   * 
   * An attempt to position the sequence beyond the first/last item set leaves the current position to be before the first item or after the last item.
   * 
   * Calling this method on an empty sequence will return false.
   * 
   * @param i - the item position to jump to
   * @return true if the current position is within the sequence, false otherwise
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state
   */
    @Override
    public boolean absolute(int i) throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

  /** \brief Move to the position after the last item.
   * 
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state
   */
    @Override
    public void afterLast() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

  /** \brief Moves to the position before the first item.
   * 
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state
   */
    @Override
    public void beforeFirst() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

  /** \brief Closes the sequence and frees all resources associated with this sequence.
   * 
   * Closing an XQSequence object also implicitly closes all XQItem objects obtained from it. All methods other than the isClosed or close method will raise exceptions when invoked after closing the sequence. Calling close on an XQSequence object that is already closed has no effect.
   * 
   * @throw XQException - if there are errors during closing of the sequence
   */
    @Override
    public void close() throws XQException {
        if (!closed) {
            closed = true;
            for (ZorbaXQResultItem xitem: items){
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
            if (lStaticCollectionManager != null) {
                lStaticCollectionManager.close();
            }
        }
    }

  /** \brief Checks if the sequence is closed.
   * 
   * @return true if the sequence is in a closed state, false otherwise
   */
    @Override
    public boolean isClosed() {
        return closed;
    }

  /** \brief Returns a number indicating the number of items in the sequence.
   * 
   * @return the number of items in this sequence
   * @throw XQException - if (1) the sequence is forward-only, or (2) the sequence is closed
   */
    @Override
    public int count() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

  /** \brief Gets the current cursor position.
   * 
   * 0 indicates that the position is before the first item and count() + 1 indicates position after the last item. A specific position indicates that the cursor is positioned on the item at that position. Use the isOnItem method to verify if the cursor is positioned on the item.
   * 
   * Calling this method on an empty sequence will return 0.
   * 
   * @throw XQException - if (1) the sequence is forward-only, or (2) the sequence is closed
   */
    @Override
    public int getPosition() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

  /** \brief Check if the sequence is positioned on an item or not.
   * 
   * Calling this method on an empty sequence will return false.
   * 
   * @return true if the sequence is currently positioned on an item, false if sequence is positioned before the first item, or after the last item
   * @throw XQException - if the sequence is in a closed state
   */
    @Override
    public boolean isOnItem() throws XQException {
        isClosedXQException();
        return (current!=null);
    }

  /** \brief Checks if the sequence is scrollable.
   * 
   * @return true if the sequence can be scrolled backward or forward, false otherwise
   * @throw XQException - if the sequence is in a closed state
   */
    @Override
    public boolean isScrollable() throws XQException {
        isClosedXQException();
        return false;
    }

  /** \brief Moves to the first item in the sequence.
   * 
   * The method returns true, if it was able to move to the first item in the sequence false, otherwise. Calling this method on an empty sequence will return false.
   * 
   * @return true if the sequence was positioned on the first item, false otherwise
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state
   */
    @Override
    public boolean first() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

  /** \brief Get the current item as an immutable XQItem object.
   * 
   * In case of an ZorbaXQResultSequence, the item is an ZorbaXQResultItem. In the case of forward only sequences, this method or any other get or write method may only be called once on the curent item.
   * 
   * The XQItem object is dependent on the sequence from which it was created and is only valid for the duration of XQSequence lifetime. Thus, the XQSequence is closed, this XQItem object will be implicitly closed and it can no longer be used.
   * 
   * @return an XQItem object
   * @throw XQException - if (1) there are errors retrieving the item, or (2) in the case of a forward only sequence, a get or write method has already been invoked on the current item.
   */
    @Override
    public XQItem getItem() throws XQException {
        isClosedXQException();
        isItemDeliveredXQException();
        isOnItemXQException();

        delivered = true;
        consumedItem = true;
        return current;
    }

  /** \brief Read the entire sequence starting from the current position as an XMLStreamReader object.
   * 
   * Read the entire sequence starting from the current position as an XMLStreamReader object, as described in Section 12.1 Serializing an XDM instance into a StAX event stream (XMLStreamReader), XQuery API for Java (XQJ) 1.0. Note that the serialization process might fail, in which case a XQException is thrown. While the stream is being read, the application MUST NOT do any other concurrent operations on the sequence. The operation on the stream is undefined if the underlying sequence position or state is changed by concurrent operations. After all items are written to the stream, the current position of the cursor is set to point after the last item. Also, in the case of forward only sequences, this method may only be called if the current item has not yet been read through any of the get or write methods.
   * 
   * @return an XML reader object as XMLStreamReader
   * @throw XQException - if (1) there are errors accessing any of the items in the sequence, (2) the sequence is in a closed state, (3) in the case of a forward only sequence, a get or write method has already been invoked on the current item, or (4) in case of an error during serialization of the sequence into a StAX event stream as defined in Section 12.1 Serializing an XDM instance into a StAX event stream (XMLStreamReader), XQuery API for Java (XQJ) 1.0
   */
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

  /** \brief Serializes the sequence starting from the current position to a String.
   * 
   * Serializes the sequence starting from the current position to a String according to the XSLT 2.0 and XQuery 1.0 serialization. Serialization parameters, which influence how serialization is performed, can be specified. Refer to the XSLT 2.0 and XQuery 1.0 serialization and Section 12 Serialization, XQuery API for Java (XQJ) 1.0 for more information. Reading the sequence during the serialization process performs implicit next operations to read the items. After all items are written to the stream, the current position of the cursor is set to point after the last item. Also, in the case of forward only sequences, this method may only be called if the current item has not yet been read through any of the get or write methods.
   * 
   * @param prprts - specifies the serialization parameters, null is considered equivalent to an empty Properties object
   * @return the serialized representation of the sequence
   * @throw XQException - if (1) there are errors accessing the items in the sequence, (2) there are errors during serialization, (3) the sequence is in a closed state, or (4) in the case of a forward only sequence, a get or write method has already been invoked on the current item
   */
    @Override
    public String getSequenceAsString(Properties prprts) throws XQException {
        isClosedXQException();
        isConsumedXQException();
        String result = null;
        try {
            SerializationOptions opts = new SerializationOptions();
            if ((prprts!=null) && prprts.size()>0) {
                for(String key : prprts.stringPropertyNames()) {
                    String value = prprts.getProperty(key);
                    opts.setSerializerOption(key, value);
                }
            }
            if (iter.isOpen()) {
                iter.close();
                iter.delete();
            }
            iterDeleted = true;
            consumedItem = true;
            result = lQuery.execute(opts).replace("&gt;", ">").replace("&lt;", "<");
        } catch (Exception e) {
            throw new XQException("Error getting stream: " + e.getLocalizedMessage());
        } finally {
            if (!preparedExpression) {
                lQuery.delete();
            }
        }
        return result;
    }

  /** \brief Checks if the current position is after the last item in the sequence.
   * 
   * Calling this method on an empty sequence will return false.
   * 
   * @return true if the current position is after the last item, false otherwise
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state
   */
    @Override
    public boolean isAfterLast() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

  /** \brief Checks if the current position before the first item in the sequence.
   * 
   * Calling this method on an empty sequence will return false.
   * 
   * @return true if the current position is before the first item, false otherwise
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state
   */
    @Override
    public boolean isBeforeFirst() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

  /** \brief Checks if the current position at the first item in the sequence.
   * 
   * Calling this method on an empty sequence will return false.
   * 
   * @return true if the current position is at the first item, false otherwise
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state
   */
    @Override
    public boolean isFirst() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

  /** \brief Checks if the current position at the last item in the sequence.
   * 
   * Calling this method on an empty sequence will return false.
   * 
   * @return true if the current position is at the last item, false otherwise
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state
   */
    @Override
    public boolean isLast() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

  /** \brief Moves to the last item in the sequence.
   * 
   * This method returns true, if it was able to move to the last item in the sequence false, otherwise. Calling this method on an empty sequence will return false.
   * 
   * @return true if the sequence was positioned on the last item, false otherwise
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state
   */
    @Override
    public boolean last() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

  /** \brief Moves to the next item in the sequence.
   * 
   * Calling this method on an empty sequence will return false.
   * 
   * @return true if the new item is valid, false if there are no more items
   * @throw XQException - if the sequence is in a closed state
   */
    @Override
    public boolean next() throws XQException {
        isClosedXQException();
        Item lItem = new Item();
        current = null;
        if (iter.next(lItem)) {
            current = new ZorbaXQResultItem(lItem, connection);
            items.add(current);
            delivered = false;
            lItem.delete();
        }
        return (current != null);
    }

  /** \brief Moves to the previous item in the sequence.
   * 
   * Calling this method on an empty sequence will return false.
   * 
   * @return true if the new current position is within the sequence, (i.e., not before first); false otherwise.
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state.
   */
    @Override
    public boolean previous() throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

  /** \brief Moves the cursor a relative number of items.
   * 
   * Moves the cursor a relative number of items, either positive or negative. Attempting to move beyond the first/last item in the sequence positions the sequence before/after the the first/last item. Calling relative(0) is valid, but does not change the cursor position.
   * Note: Calling the method relative(1) is identical to calling the method next and calling the method relative(-1) is identical to calling the method previous(). Calling this method on an empty sequence will return false.
   * 
   * @param i - the item position to jump to
   * @return true if the new current position is within the sequence (i.e., not before first or after last); false otherwise.
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state.
   */
    @Override
    public boolean relative(int i) throws XQException {
        isClosedXQException();
        throw new XQException("This sequence is forward-only");
    }

  /** \brief Serializes the sequence starting from the current position to an OutputStream.
   * 
   * Serializes the sequence starting from the current position to an OutputStream according to the XSLT 2.0 and XQuery 1.0 serialization. Serialization parameters, which influence how serialization is performed, can be specified. Refer to the XSLT 2.0 and XQuery 1.0 serialization and Section 12 Serialization, XQuery API for Java (XQJ) 1.0 for more information. Reading the sequence during the serialization process performs implicit next operations to read the items. After all items are written to the stream, the current position of the cursor is set to point after the last item. Also, in the case of forward only sequences, this method may only be called if the current item has not yet been read through any of the get or write methods.
   * 
   * @param out - the output stream into which the sequence is to be serialized
   * @param prprts - specifies the serialization parameters, null is considered equivalent to an empty Properties object
   * @throw XQException - if (1) there are errors accessing the items in the sequence, (2) there are errors during serialization, (3) the sequence is in a closed state, (4) in the case of a forward only sequence, a get or write method has already been invoked on the current item, or (5) the os parameter is null
   */
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

  /** \brief Serializes the sequence starting from the current position to a Writer.
   * 
   * Serializes the sequence starting from the current position to a Writer according to the XSLT 2.0 and XQuery 1.0 serialization. Serialization parameters, which influence how serialization is performed, can be specified. Refer to the XSLT 2.0 and XQuery 1.0 serialization and Section 12 Serialization, XQuery API for Java (XQJ) 1.0 for more information. 
   * 
   * Warning: When outputting to a Writer, make sure the writer's encoding matches the encoding parameter if specified as a property or the default encoding. 
   * 
   * Reading the sequence during the serialization process performs implicit next operations to read the items. After all items are written to the stream, the current position of the cursor is set to point after the last item. Also, in the case of forward only sequences, this method may only be called if the current item has not yet been read through any of the get or write methods.
   * 
   * @param writer - the writer object into which the sequence is to be serialized
   * @param prprts - specifies the serialization parameters, null is considered equivalent to an empty Properties object
   * @throw XQException - if (1) there are errors accessing the items in the sequence, (2) there are errors during serialization, (3) the sequence is in a closed state, (4) in the case of a forward only sequence, a get or write method has already been invoked on the current item, or (5) the ow parameter is null
   */
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

  /** \brief Writes the entire sequence starting from the current position to a SAX handler.
   * 
   * Writes the entire sequence starting from the current position to a SAX handler, as described in Section 12.2 Serializing an XDM instance into a SAX event stream, XQuery API for Java (XQJ) 1.0. Note that the serialization process might fail, in which case a XQException is thrown. After all items are written to the stream, the current position of the cursor is set to point after the last item. Also, in the case of forward only sequences, this method may only be called if the current item has not yet been read through any of the get or write methods. The specified org.xml.sax.ContentHandler can optionally implement the org.xml.sax.LexicalHandler interface. An implementation must check if the specified ContentHandler implements LexicalHandler. If the handler is a LexicalHandler comment nodes are reported, otherwise they will be silently ignored.
   * 
   * @param ch - the SAX content handler, optionally a lexical handler
   * @throw XQException - if (1) there are errors accessing any of the items in the sequence, (2) the sequence is in a closed state, (3) in the case of a forward only sequence, a get or write method has already been invoked on the current item, (4) in case of an error during serializing the XDM instance into a SAX event stream, or (5) the saxhdlr parameter is null
   */
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

  /** \brief Writes the entire sequence starting from the current position to a Result.
   * 
   * First the sequence is normalized as described in XSLT 2.0 and XQuery 1.0 serialization. Subsequently it is serialized to the Result object.
   * Note that the normalization process can fail, in which case an XQException is thrown. An XQJ implementation must at least support the following implementations: 
   * - javax.xml.transform.dom.DOMResult
   * - javax.xml.transform.sax.SAXResult
   * - javax.xml.transform.stream.StreamResult
   * 
   * @param result - the result object into which the sequence is to be serialized
   * @throw XQException - if (1) there are errors accessing any of the items in the sequence, (2) the sequence is in a closed state, (3) in the case of a forward only sequence, a get or write method has already been invoked on the current item, (4) in case of an error while serializing the sequence into the Result object, or (5) the result parameter is null
   */
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

  /** \brief Gets the current item as a boolean.
   * 
   * The current item must be an atomic value of type xs:boolean or a subtype.
   * 
   * @return a boolean representing the current item
   * @throw XQException - if (1) the conversion of the current item to a boolean fails, (2) if there are errors accessing the current item, (3) if the underlying sequence or item is in a closed state, or (4) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
    @Override
    public boolean getBoolean() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return getItem().getBoolean();
    }

  /** \brief Gets the current item as a byte.
   * 
   * The current item must be an atomic value of type xs:decimal or a subtype, and its value must be in the value space of byte.
   * 
   * @return a byte representing the current item
   * @throw XQException - if (1) the conversion of the current item to a byte fails, (2) if there are errors accessing the current item, (3) if the underlying sequence or item is in a closed state, or (4) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
    @Override
    public byte getByte() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return getItem().getByte();
    }

  /** \brief Gets the current item as a double.
   * 
   * The current item must be an atomic value of type xs:double or a subtype.
   * 
   * @return a double representing the current item
   * @throw XQException - if (1) the conversion of the current item to a double fails, (2) if there are errors accessing the current item, (3) if the underlying sequence or item is in a closed state, or (4) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
    @Override
    public double getDouble() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return getItem().getDouble();
    }

  /** \brief Gets the current item as a float.
   * 
   * The current item must be an atomic value of type xs:float or a subtype.
   * 
   * @return a float representing the current item
   * @throw XQException - if (1) the conversion of the current item to a float fails, (2) if there are errors accessing the current item, (3) if the underlying sequence or item is in a closed state, or (4) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
    @Override
    public float getFloat() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return getItem().getFloat();
    }

  /** \brief Gets the current item as an int. 
   * 
   * The current item must be an atomic value of type xs:decimal or a subtype, and its value must be in the value space of int.
   * 
   * @return an int representing the current item
   * @throw XQException - if (1) the conversion of the current item to a int fails, (2) if there are errors accessing the current item, (3) if the underlying sequence or item is in a closed state, or (4) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
    @Override
    public int getInt() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return getItem().getInt();
    }

  /** \brief Gets the type of the item. 
   * 
   * On a forward only sequence this method can be called independent of any other get or write method. It will not raise an error if such method has been called already, nor will it affect subsequent invocations of any other get or write method.
   * 
   * @return the type of the item
   * @throw XQException - if (1) there are errors accessing the type of the item, or (2) the underlying sequence or item is in a closed state
   */
    @Override
    public XQItemType getItemType() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return current.getItemType();
    }

  /** \brief Gets the current item as a Java String.
   * 
   * The current item must be an atomic value. This function casts the current item to an xs:string value according to the casting rules defined in 17.1.2 Casting to xs:string and xs:untypedAtomic, XQuery 1.0 and XPath 2.0 Functions and Operators, and then returns the value as a Java String.
   * 
   * @return the string representation of the item
   * @throw XQException - if (1) there are errors accessing the item's value, (2) the item is not an atomic value, (3) there is an error when casting the item to a string representation, (4) the underlying sequence or item is in a closed state, or (5) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
    @Override
    public String getAtomicValue() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return getItem().getAtomicValue();
    }

  /** \brief Gets the current item as a long.
   * 
   * The current item must be an atomic value of type xs:decimal or a subtype, and its value must be in the value space of long.
   * 
   * @return a long representing the current item
   * @throw XQException - if (1) the conversion of the current item to a long fails, (2) if there are errors accessing the current item, (3) if the underlying sequence or item is in a closed state, or (4) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
    @Override
    public long getLong() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return getItem().getLong();
    }

  /** \brief Gets the item as a DOM node.
   * 
   * The current item must be a node. The type of the returned DOM node is governed by Table 7 - XQuery Node Types and Corresponding Java Object Types XQuery API for Java (XQJ) 1.0 The instance of the returned node is implementation dependent. The node may be a reference or a copy of the internal state of the item. It is advisable to make a copy of the node if the application plans to modify it.
   * 
   * @return a DOM node representing the current item
   * @throw XQException - if (1) if there are errors accessing the current item, (2) the current item is not a node, (3) if the underlying sequence or item is in a closed state, or (4) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
    @Override
    public Node getNode() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return getItem().getNode();
    }

  /** \brief Returns the URI for this item.
   * 
   * If the item is a document node, then this method returns the absolute URI of the resource from which the document node was constructed. If the document URI is not available, then the empty string is returned. If the document URI is available, the returned value is the same as if fn:document-uri were evaluated on this document node. If the item is of a node kind other than document node, then the returned URI is implementation-defined.
   * On a forward only sequence this method can be called independent of any other get or write method. It will not raise an error if such method has been called already, nor will it affect subsequent invocations of any other get or write method on the current item.
   * 
   * @return the document URI for this document node or the empty string if not available. For other node kinds, the result is implementation-defined
   * @throw XQException - if (1) if there are errors accessing the current item, (2) the current item is not a node, (3) if the underlying sequence or item is in a closed state
   */
    @Override
    public URI getNodeUri() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return current.getNodeUri();
    }

  /** \brief Gets the current item as an Object.
   * 
   * The data type of the returned object will be the Java Object type as specified in 14.4 Mapping an XQuery Atomic Value to a Java Object Type and 14.5 Mapping an XQuery Node to a Java Object Type, XQuery API for Java (XQJ) 1.0.
   * 
   * @return an object representing the current item
   * @throw XQException - if (1) if there are errors accessing the current item, (2) if the underlying sequence or item is in a closed state, or (3) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
    @Override
    public Object getObject() throws XQException {
        isClosedXQException();
        isOnItemXQException();
        return getItem().getObject();
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
        isOnItemXQException();
        return getItem().getItemAsStream();
    }

  /** \brief Serializes the current item according to the XSLT 2.0 and XQuery 1.0 serialization.
   * 
   * Serialization parameters, which influence how serialization is performed, can be specified. Refer to the XSLT 2.0 and XQuery 1.0 serialization and Section 12 Serialization, XQuery API for Java (XQJ) 1.0 for more information.
   * 
   * @param prprts - specifies the serialization parameters, null is considered equivalent to an empty Properties object
   * @return the serialized representation of the item
   * @throw XQException - if (1) there are errors accessing the current item or the underlying sequence, (2) the underlying sequence or item is in a closed state, (3) in the case of a forward only sequence, a get or write method has already been invoked on the current item, or (4) if there are errors during serialization
   */
    @Override
    public String getItemAsString(Properties prprts) throws XQException {
        isClosedXQException();
        return getItem().getItemAsString(prprts);
    }

  /** \brief Gets the current item as a short.
   * 
   * The current item must be an atomic value of type xs:decimal or a subtype, and its value must be in the value space of short.
   * 
   * @return a short representing the current item
   * @throw XQException - if (1) the conversion of the current item to a short fails, (2) if there are errors accessing the current item, (3) if the underlying sequence or item is in a closed state, or (4) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
    @Override
    public short getShort() throws XQException {
        isClosedXQException();
        return getItem().getShort();
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
        isOnItemXQException();
        isNullXQException(xqit);
        return current.instanceOf(xqit);
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
        getItem().writeItem(out, prprts);
    }

  /** \brief Serializes the current item to a Writer.
   * 
   * Serializes the current item to a Writer according to XSLT 2.0 and XQuery 1.0 serialization. Serialization parameters, which influence how serialization is performed, can be specified. Refer to the XSLT 2.0 and XQuery 1.0 serialization and Section 12 Serialization, XQuery API for Java (XQJ) 1.0 for more information.
   * 
   * Warning: When outputting to a Writer, make sure the writer's encoding matches the encoding parameter if specified as a property or the default encoding.
   * @param writer - the output stream into which the current item is to be serialized
   * @param prprts - specifies the serialization parameters, null is considered equivalent to an empty Properties object
   * @throw XQException - if (1) there are errors accessing the current item or the underlying sequence, (2) the underlying sequence or item is in a closed state, (3) in the case of a forward only sequence, a get or write method has already been invoked on the current item, (4) if there are errors during serialization, or (5) the os parameter is null
   */
    @Override
    public void writeItem(Writer writer, Properties prprts) throws XQException {
        isClosedXQException();
        isNullXQException(writer);
        isNullXQException(prprts);
        getItem().writeItem(writer, prprts);
    }

  /** \brief Writes the current item to a SAX handler.
   * 
   * Writes the current item to a SAX handler, as described in in Section 12.2 Serializing an XDM instance into a SAX event stream, XQuery API for Java (XQJ) 1.0. Note that the serialization process might fail, in which case a XQException is thrown. The specified org.xml.sax.ContentHandler can optionally implement the org.xml.sax.LexicalHandler interface. An implementation must check if the specified ContentHandler implements LexicalHandler. If the handler is a LexicalHandler comment nodes are reported, otherwise they will be silently ignored.
   * 
   * @param ch - the SAX content handler, optionally a lexical handler
   * @throw XQException - if (1) there are errors accessing the current item or the underlying sequence, (2) the underlying sequence or item is in a closed state, (3) in the case of a forward only sequence, a get or write method has already been invoked on the current item, (4) in case of an error while serializing the XDM instance into a SAX event stream, or (5) the saxhdlr parameter is null
   */
    @Override
    public void writeItemToSAX(ContentHandler ch) throws XQException {
        isClosedXQException();
        isNullXQException(ch);
        getItem().writeItemToSAX(ch);
    }

  /** \brief Writes the current item to a Result.
   * 
   * First the item is normalized as described in XSLT 2.0 and XQuery 1.0 serialization. Subsequently it is serialized to the Result object.
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
        getItem().writeItemToResult(result);
    }

  /** \brief Returns a StaticCollectionManager.
   * 
   * Returns a CollectionManager responsible for all collections which are statically declared in the static context of this query (main module) or any transitively imported library module.
   * The collection manager provides a set of functions for managing collections and their contents.
   *
   * @return ZorbaXQStaticCollectionManager The collection manager responsible for managing collections of this Sequence.
   * @throw XQException - if the object is closed
   */
    public ZorbaXQStaticCollectionManager getStaticCollectionManager() throws XQException {
        isClosedXQException();
        if (lStaticCollectionManager==null) {
            lStaticCollectionManager = new ZorbaXQStaticCollectionManager(lQuery.getStaticCollectionManager());
        }
        return lStaticCollectionManager;
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
