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
import org.zorbaxquery.api.ItemSequence;
import org.zorbaxquery.api.Iterator;


 /**
   * 
   * This interface represents a sequence of items as defined in the XDM. The sequence may be materialized or non-materialized.
   * 
   * The next method is useful to position the XQSequence over the next item in the sequence. If the scrollability is XQConstants.SCROLLTYPE_SCROLLABLE, then the previous method can be called to move backwards. In the case of a forward only sequence, the get methods may be only called once per item. To perform multiple gets on an item, extract the item first from the sequence using the getItem method and then operate on the XQItem object.
   * 
   *  \code{.java}
   *   XQPreparedExpression expr = conn.prepareExpression("for $i ..");
   *   XQSequence result = expr.executeQuery();
   *  
   *   // create the ItemTypes for string and integer
   *   XQItemType strType = conn.createAtomicType(XQItemType.XQBASETYPE_STRING);
   *   XQItemType intType = conn.createAtomicType(XQItemType.XQBASETYPE_INT);
   * 
   *   // positioned before the first item
   *   while (result.next())
   *   {
   *     XQItemType type = result.getItemType();
   *  
   *     // If string, then get the string value out
   *     if (type.equals(strType))
   *       String str = result.getAtomicValue();
   *     else if (type.equals(intType))  // if it is an integer..
   *       int intval = result.getInt();
   *  
   *      ...
   *   }
   *  \endcode
   *  
   * In a sequence, the cursor may be positioned on an item, after the last item or before the first item. The getPosition method returns the current position number. A value of 0 indicates that it is positioned before the first item, a value of count() + 1 indicates that it is positioned after the last item, and any other value indicates that it is positioned on the item at that position.
   * For example, a position value of 1 indicates that it is positioned on the item at position 1.
   * 
   * The isOnItem method may be used to find out if the cursor is positioned on the item. When the cursor is positioned on an item, the next method call will move the cursor to be on the next item.
   * 
   * See also: Section 12 Serialization, XQuery API for Java (XQJ) 1.0, which describes some general information applicable to various XQJ serialization methods.
   * 
   * 
   */
public class XQSequence implements javax.xml.xquery.XQSequence {

    private boolean closed = false;
    private boolean forwardOnly = true;
    private boolean currentItemGet = false;
    private Collection<XQItem> content = new ArrayList<XQItem>();
    private int position = 1;
    int size = 0;
    private ItemSequence itemSequence = null;

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

    public XQSequence(org.zorbaxquery.api.Iterator iterator) {
        if (iterator.isOpen()) {
            org.zorbaxquery.api.Item item = new org.zorbaxquery.api.Item();
            while (iterator.next(item)) {
                XQItem xItem = new org.zorbaxquery.api.xqj.XQItem(item);
                content.add(xItem);
            }
            size = content.size();
        }
    }

    public XQSequence(org.zorbaxquery.api.Item item) {
        XQItem xItem = new org.zorbaxquery.api.xqj.XQItem(item);
        content.add(xItem);
        size = content.size();
    }

    protected XQSequence(ItemSequence seq) {
        itemSequence = seq;
        org.zorbaxquery.api.Iterator iterator = seq.getIterator();
        if (iterator.isOpen()) {
            org.zorbaxquery.api.Item item = null;
            while (iterator.next(item)) {
                XQItem xItem = new org.zorbaxquery.api.xqj.XQItem(item);
                content.add(xItem);
            }
            size = content.size();
        }
    }

    protected ItemSequence getItemSequence() throws XQException {
        if (itemSequence==null) {
            throw new XQException("This Sequence doesn't come from Zorba ItemSequence object");
        }
        return itemSequence;
    }

  /** \brief Moves the XQSequence's position to the given item number in this object.
   * 
   * Moves the XQSequence's position to the given item number in this object. If the item number is positive, the XQSequence moves to the given item number with respect to the beginning of the XQSequence.
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

  /** \brief Move to the position after the last item.
   * 
   * Move to the position after the last item.
   * 
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state
   */
    @Override
    public void afterLast() throws XQException {
        isClosedXQException();
        position = content.size()+1;
    }

  /** \brief Moves to the position before the first item.
   * 
   * Moves to the position before the first item.
   * 
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state
   */
    @Override
    public void beforeFirst() throws XQException {
        isClosedXQException();
        position = 0;
    }

  /** \brief Closes the sequence and frees all resources associated with this sequence.
   * 
   * Closes the sequence and frees all resources associated with this sequence. Closing an XQSequence object also implicitly closes all XQItem objects obtained from it. All methods other than the isClosed or close method will raise exceptions when invoked after closing the sequence. Calling close on an XQSequence object that is already closed has no effect.
   * 
   * @throw XQException - if there are errors during closing of the sequence
   */
    @Override
    public void close() throws XQException {
        closed = true;
        for (XQItem item: content) {
            item.close();
        }
        if (itemSequence!=null) {
            itemSequence.delete();
        }
    }

  /** \brief Checks if the sequence is closed.
   * 
   * Checks if the sequence is closed.
   * 
   * @return true if the sequence is in a closed state, false otherwise
   */
    @Override
    public boolean isClosed() {
        return closed;
    }

  /** \brief Returns a number indicating the number of items in the sequence.
   * 
   * Returns a number indicating the number of items in the sequence.
   * 
   * @return the number of items in this sequence
   * @throw XQException - if (1) the sequence is forward-only, or (2) the sequence is closed
   */
    @Override
    public int count() throws XQException {
        isClosedXQException();
        return size;
    }

  /** \brief Gets the current cursor position.
   * 
   * Gets the current cursor position.
   * 0 indicates that the position is before the first item and count() + 1 indicates position after the last item. A specific position indicates that the cursor is positioned on the item at that position. Use the isOnItem method to verify if the cursor is positioned on the item.
   * 
   * Calling this method on an empty sequence will return 0.
   * 
   * @throw XQException - if (1) the sequence is forward-only, or (2) the sequence is closed
   */
    @Override
    public int getPosition() throws XQException {
        isClosedXQException();
        return position;
    }

  /** \brief Check if the sequence is positioned on an item or not.
   * 
   * Check if the sequence is positioned on an item or not. Calling this method on an empty sequence will return false.
   * 
   * @return true if the sequence is currently positioned on an item, false if sequence is positioned before the first item, or after the last item
   * @throw XQException - if the sequence is in a closed state
   */
    @Override
    public boolean isOnItem() throws XQException {
        isClosedXQException();
        return (position>0) && (position<(content.size()+1));
    }

  /** \brief Checks if the sequence is scrollable.
   * 
   * Checks if the sequence is scrollable.
   * 
   * @return true if the sequence can be scrolled backward or forward, false otherwise
   * @throw XQException - if the sequence is in a closed state
   */
    @Override
    public boolean isScrollable() throws XQException {
        isClosedXQException();
        return !forwardOnly;
    }

  /** \brief Moves to the first item in the sequence.
   * 
   * Moves to the first item in the sequence. The method returns true, if it was able to move to the first item in the sequence false, otherwise. Calling this method on an empty sequence will return false.
   * 
   * @return true if the sequence was positioned on the first item, false otherwise
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state
   */
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

  /** \brief Get the current item as an immutable XQItem object.
   * 
   * Get the current item as an immutable XQItem object. In case of an XQResultSequence, the item is an XQResultItem. In the case of forward only sequences, this method or any other get or write method may only be called once on the curent item.
   * 
   * The XQItem object is dependent on the sequence from which it was created and is only valid for the duration of XQSequence lifetime. Thus, the XQSequence is closed, this XQItem object will be implicitly closed and it can no longer be used.
   * 
   * @return an XQItem object
   * @throw XQException - if (1) there are errors retrieving the item, or (2) in the case of a forward only sequence, a get or write method has already been invoked on the current item.
   */
    @Override
    public XQItem getItem() throws XQException {
        isClosedXQException();
        isItemGetXQException();
        return (XQItem)content.toArray()[position-1];
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
        isItemGetXQException();
        StringBuffer sb = new StringBuffer();
        for (XQItem item: content) {
            sb.append(item.getItemAsString(null));
        }
        return sb.toString();
    }

  /** \brief Checks if the current position is after the last item in the sequence.
   * 
   * Checks if the current position is after the last item in the sequence. Calling this method on an empty sequence will return false.
   * 
   * @return true if the current position is after the last item, false otherwise
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state
   */
    @Override
    public boolean isAfterLast() throws XQException {
        isClosedXQException();
        boolean result = false;
        if (size>0) {
            result = position==size+1;
        }
        return result;
    }

  /** \brief Checks if the current position before the first item in the sequence.
   * 
   * Checks if the current position before the first item in the sequence. Calling this method on an empty sequence will return false.
   * 
   * @return true if the current position is before the first item, false otherwise
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state
   */
    @Override
    public boolean isBeforeFirst() throws XQException {
        isClosedXQException();
        boolean result = false;
        if (content.size()>0) {
            result = position==0;
        }
        return result;
    }

  /** \brief Checks if the current position at the first item in the sequence.
   * 
   * Checks if the current position at the first item in the sequence. Calling this method on an empty sequence will return false.
   * 
   * @return true if the current position is at the first item, false otherwise
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state
   */
    @Override
    public boolean isFirst() throws XQException {
        isClosedXQException();
        boolean result = false;
        if (content.size()>0) {
            result = position==1;
        }
        return result;
    }

  /** \brief Checks if the current position at the last item in the sequence.
   * 
   * Checks if the current position at the last item in the sequence. Calling this method on an empty sequence will return false.
   * 
   * @return true if the current position is at the last item, false otherwise
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state
   */
    @Override
    public boolean isLast() throws XQException {
        isClosedXQException();
        boolean result = false;
        if (size>0) {
            result = position==size;
        }
        return result;
    }

  /** \brief Moves to the last item in the sequence.
   * 
   * Moves to the last item in the sequence. This method returns true, if it was able to move to the last item in the sequence false, otherwise. Calling this method on an empty sequence will return false.
   * 
   * @return true if the sequence was positioned on the last item, false otherwise
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state
   */
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

  /** \brief Moves to the next item in the sequence.
   * 
   * Moves to the next item in the sequence. Calling this method on an empty sequence will return false.
   * 
   * @return true if the new item is valid, false if there are no more items
   * @throw XQException - if the sequence is in a closed state
   */
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

  /** \brief Moves to the previous item in the sequence.
   * 
   * Moves to the previous item in the sequence. Calling this method on an empty sequence will return false.
   * 
   * @return true if the new current position is within the sequence, (i.e., not before first); false otherwise.
   * @throw XQException - if (1) the sequence is forward only, or (2) the sequence is in a closed state.
   */
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
        isItemGetXQException();
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
        isItemGetXQException();
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
        isItemGetXQException();
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
   * Writes the entire sequence starting from the current position to a Result. First the sequence is normalized as described in XSLT 2.0 and XQuery 1.0 serialization. Subsequently it is serialized to the Result object.
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
        isItemGetXQException();
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
   * Gets the current item as a boolean. The current item must be an atomic value of type xs:boolean or a subtype.
   * 
   * @return a boolean representing the current item
   * @throw XQException - if (1) the conversion of the current item to a boolean fails, (2) if there are errors accessing the current item, (3) if the underlying sequence or item is in a closed state, or (4) in the case of forward only sequences, a get or write method was already invoked on the current item
   */
    @Override
    public boolean getBoolean() throws XQException {
        isClosedXQException();
        return getItem().getBoolean();
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
        return getItem().getByte();
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
        return getItem().getDouble();
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
        return getItem().getFloat();
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
        return getItem().getInt();
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
        return getItem().getItemType();
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
        return getItem().getAtomicValue();
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
        return getItem().getLong();
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
        return getItem().getNode();
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
        return getItem().getNodeUri();
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
        return getItem().getItemAsStream();
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
        return getItem().getItemAsString(prprts);
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
        isNullXQException(xqit);
        return getItem().instanceOf(xqit);
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
        getItem().writeItem(writer, prprts);
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
        getItem().writeItemToSAX(ch);
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
