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
import java.util.Collection;
import javax.xml.xquery.XQException;
import org.zorbaxquery.api.CollectionManager;
import javax.xml.xquery.XQSequence;
import javax.xml.xquery.XQItem;


  /** \brief This class defines a set of functions for managing persistent
   *         collections.
   *
   */
public class XQCollectionManager {

    private boolean closed = false;
    private CollectionManager collectionManager = null;
    private Collection<XQSequence> sequences = new ArrayList<XQSequence>();
    private Collection<XQCollection> collections = new ArrayList<XQCollection>();

    protected XQCollectionManager (CollectionManager cm) {
        collectionManager = cm;
    }

  /** \brief Closes the collection manager.
   * 
   * Closes the collection manager. Once the collection manager is closed, no method other than close or the isClosed method may be called on the collection manager object. Calling close on an XQCollectionManager object that is already closed has no effect.
   * 
   * @throw XQException - if there is an error during closing the collection.
   */
    public void close() throws XQException {
        for (XQSequence exp : sequences ){
            exp.close();  // Notify the dependents objects to close
        }
        for (XQCollection exp : collections ){
            exp.close();  // Notify the dependents objects to close
        }
        if (collectionManager!=null) {
            collectionManager.delete();
        }
        closed = true;
    }

  /** \brief Checks if the collection manager is closed.
   * 
   * @return true if the collection manager is in a closed state, false otherwise
   */
    public boolean isClosed() {
        return closed;
    }

    /**
     * This function returns a sequence of names of the collections
     * that are available. If this is an instance of the StaticCollectionManager
     * class (i.e. returned by any of the getStaticCollectionManager methods),
     * the collections returned by this function are also
     * statically declared.
     *
     * @return The list of names of the available collections.
     * @throw XQException if any error occurs retreiving the collections
     *
     */
    public XQSequence availableCollections() throws XQException {
        isClosedXQException();
        XQSequence result = new org.zorbaxquery.api.xqj.XQSequence(collectionManager.availableCollections());
        sequences.add(result);
        return result;
    }

    /**
     * This function creates the collection with the given name.
     *
     * @param aName The name of the collection to create.
     *
     * @throw XQException if a collection with the given name already exists.
     *
     */
    public void createCollection(XQItem aName ) throws XQException {
        isClosedXQException();
        collectionManager.createCollection(((org.zorbaxquery.api.xqj.XQItem)aName).getZorbaItem());
    }

    /**
     * This function removes the collection with the given name.
     *
     * @param aName The name of the collection to delete.
     *
     * @throw XQException if the collection does not exist.
     */
    public void deleteCollection(XQItem aName ) throws XQException {
        isClosedXQException();
        collectionManager.deleteCollection(((org.zorbaxquery.api.xqj.XQItem)aName).getZorbaItem());
    }

    /**
     * Returns a instance of the Collection class which can
     * be used to modify and retrieve the contents of the collection
     * identified by the given name.
     *
     * @param aName The name of the collection to retrieve.
     *
     * @throw XQException if the collection does not exist.
     */
    public XQCollection getCollection(XQItem aName ) throws XQException {
        isClosedXQException();
        XQCollection result = new XQCollection ( collectionManager.getCollection(((org.zorbaxquery.api.xqj.XQItem)aName).getZorbaItem()) );
        collections.add(result);
        return result;
    }

    /**
     * This function returns true if a collection with the given name is available.
     * If this is an instance of the StaticCollectionManager class (i.e.
     * returned by any of the getStaticCollectionManager() methods),
     * the collection also needs to be statically declared.
     *
     * @param aName The name of the collection that is being checked.
     *
     * @return true if the collection is available and false otherwise.
     * @throw XQException if any error occurs verifying the collection
     *
     */
    public boolean isAvailableCollection(XQItem aName ) throws XQException {
        isClosedXQException();
        return collectionManager.isAvailableCollection( ((org.zorbaxquery.api.xqj.XQItem)aName).getZorbaItem() );
    }

    private void isClosedXQException() throws XQException {
        if (closed) {
            throw new XQException("CollectionManager is closed");
        }
    }
    
}
