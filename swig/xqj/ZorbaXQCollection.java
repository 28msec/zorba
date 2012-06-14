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

import java.util.ArrayList;
import javax.xml.xquery.XQException;
import javax.xml.xquery.XQItem;
import javax.xml.xquery.XQSequence;
import org.zorbaxquery.api.Collection;
import org.zorbaxquery.api.ItemSequence;

/** \brief A Collection is a persistent sequence of node items.
 *
 * Instances of this class can be used to modify or retrieve the contents
 * of a collection.
 *
 */
public class ZorbaXQCollection {

    private boolean closed = false;
    private Collection collection = null;
    private java.util.Collection<XQSequence> sequences = new ArrayList<XQSequence>();

    protected ZorbaXQCollection(Collection col) {
        collection = col;
    }
    
  /** \brief Closes the collection.
   * 
   * Once the collection is closed, no method other than close or the isClosed method may be called on the collection object. Calling close on an ZorbaXQCollection object that is already closed has no effect.
   * 
   * @throw XQException - if there is an error during closing the collection.
   */
    public void close() throws XQException {
        for (XQSequence exp : sequences ){
            exp.close();  // Notify the dependents objects to close
        }
        if (collection!=null) {
            collection.delete();
        }
        closed = true;
    }

  /** \brief Checks if the collection is closed.
   * 
   * @return true if the collection is in a closed state, false otherwise
   */
    public boolean isClosed() {
        return closed;
    }

  /**
   * \brief This function returns the sequence of nodes of the collection.
   *
   * @return The sequence contained in the given collection.
   *
   */
    public XQSequence contents() throws XQException {
        isClosedXQException();
        XQSequence result =  new org.zorbaxquery.api.xqj.ZorbaXQSequence(collection.contents().getIterator());
        sequences.add(result);
        return result;
    }

  /**
   * \brief This function deletes the first node from a collection.
   *
   * @throw XQException if the collection doesn't contain any node.
   *
   */
    public void deleteNodeFirst() throws XQException {
        isClosedXQException();
        collection.deleteNodeFirst();
    }

  /**
   * \brief This function deletes the last node from a collection.
   *
   * @throw XQException if the collection doesn't contain any node.
   *
   */
    public void deleteNodeLast() throws XQException {
        isClosedXQException();
        collection.deleteNodeLast();
    }

  /**
   * \brief This function deletes zero of more nodes from a collection. 
   *
   * @param aNodes the nodes in the collection that should be deleted.
   *
   * @throw XQException if any nodes in the given sequence is not a member of a collection
   *        or not all nodes of the sequence belong to the same collection.
   *
   */
    public void deleteNodes(XQSequence aNodes ) throws XQException {
        isClosedXQException();
        try {
            ItemSequence sequence =  ((org.zorbaxquery.api.xqj.ZorbaXQSequence)aNodes).getItemSequence();
            collection.deleteNodes(sequence);
        } catch (XQException e) {
            throw e;
        }
    }   

  /**
   * \brief This function deletes the n first nodes from a collection.
   *
   * @throw XQException if the collection doesn't contain any node.
   *
   */
    public void deleteNodesFirst(long aNumNodes ) throws XQException {
        isClosedXQException();
        collection.deleteNodesFirst(aNumNodes);
    }

  /**
   * \brief This function deletes the n last nodes from a collection.
   *
   * @throw XQException if the collection doesn't contain any node.
   *
   */
    public void deleteNodesLast(long aNumNodes ) throws XQException {
        isClosedXQException();
        collection.deleteNodesLast(aNumNodes);
    }

  /**
   * \brief Get the name of the collection.
   *
   * @return The name of the collection.
   */
    public String getName() throws XQException {
        isClosedXQException();
        return collection.getName().getStringValue();
    }

  /**
   * \brief Retrieves the sequence type for this (static declared) collection.
   *
   * @return the sequence type for the said collection, or 0
   *  if this collection is not statically declared.
   *
   * @see isStatic()
   */
    public ZorbaXQItemType getType() throws XQException {
        isClosedXQException();
        return new ZorbaXQItemType(collection.getType());
    }

  /**
   * \brief This function returns the index of the given node in the collection.
   *
   * @param aNode The node to retrieve the index from.
   *
   * @return Returns the position of the given node in the collection.
   *
   * @throw XQException if node is not contained in any collection.
   *
   */
    public long indexOf(XQItem aNode ) throws XQException {
        isClosedXQException();
        return collection.indexOf(((org.zorbaxquery.api.xqj.ZorbaXQItem)aNode).getZorbaItem());
    }

  /**
   * This function inserts copies of the given
   * nodes into a collection at the position directly following the
   * given target node.
   *
   * @param aTarget the node in the collection after which the
   *        sequence should be inserted.
   * @param aNodes The sequences of nodes whose copies should
   *        be added to the collection.
   *
   * @throw XQException if any nodes in the sequence is not a member of a collection
   *        or not all nodes of the sequence belong to the same collection.
   *
   */
    public void insertNodesAfter(XQItem aTarget, XQSequence aNodes ) throws XQException {
        isClosedXQException();
        try {
            ItemSequence sequence =  ((org.zorbaxquery.api.xqj.ZorbaXQSequence)aNodes).getItemSequence();
            collection.insertNodesAfter(((org.zorbaxquery.api.xqj.ZorbaXQItem)aTarget).getZorbaItem(), sequence);
        } catch (XQException e) {
            throw e;
        }
    }

  /**
   * This function inserts copies of the given
   * nodes into a collection at the position directly preceding the
   * given target node.
   *
   * @param aTarget the node in the collection before which the
   *        sequence should be inserted.
   * @param aNodes The sequences of nodes whose copies should
   *        be added to the collection.
   *
   * @throw XQException if any nodes in the sequence is not a member of a collection
   *        or not all nodes of the sequence belong to the same collection.
   *
   */
    public void insertNodesBefore(XQItem aTarget, XQSequence aNodes ) throws XQException {
        isClosedXQException();
        try {
            ItemSequence sequence =  ((org.zorbaxquery.api.xqj.ZorbaXQSequence)aNodes).getItemSequence();
            collection.insertNodesBefore(((org.zorbaxquery.api.xqj.ZorbaXQItem)aTarget).getZorbaItem(), sequence);
        } catch (XQException e) {
            throw e;
        }
    }

  /**
   * This function inserts copies of the
   * given nodes at the beginning of the collection.
   *
   * @param aNodes The sequences of nodes whose copies
   *        should be added to the collection.
   *
   */
    public void insertNodesFirst(XQSequence aNodes ) throws XQException {
        isClosedXQException();
        try {
            ItemSequence sequence =  ((org.zorbaxquery.api.xqj.ZorbaXQSequence)aNodes).getItemSequence();
            collection.insertNodesFirst(sequence);
        } catch (XQException e) {
            throw e;
        }
    }

  /**
   * This function inserts copies of the
   * given nodes at the end of the collection.
   *
   * @param aNodes The sequences of nodes whose copies
   *        should be added to the collection.
   *
   */
    public void insertNodesLast(XQSequence aNodes ) throws XQException {
        isClosedXQException();
        try {
            ItemSequence sequence =  ((org.zorbaxquery.api.xqj.ZorbaXQSequence)aNodes).getItemSequence();
            collection.insertNodesLast(sequence);
        } catch (XQException e) {
            throw e;
        }
    }

  /**
   * The function checks if this collection has been statically declared.
   *
   * @return true if the collection is a static collection, false otherwise.
   */
    public boolean isStatic() throws XQException {
        isClosedXQException();
        return collection.isStatic();
    }

    private void isClosedXQException() throws XQException {
        if (closed) {
            throw new XQException("Collection is closed");
        }
    }
     
    
}
