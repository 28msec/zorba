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
import javax.xml.xquery.XQItem;
import javax.xml.xquery.XQSequence;
import org.zorbaxquery.api.StaticCollectionManager;


  /**
   * Using the ZorbaXQStaticCollectionManager one can retrieve information about statically declared collections and indexes as well as manage them.
   * 
   * The ZorbaXQStaticCollectionManager can be retrieved from (1) a compiled XQuery or (2) a XQStaticContext object. In both cases, this class provides access to information for the collections and indexes that are declared in (1) all the modules (transitively) imported by the main query or (2) the module that resulted in the compilation of the StaticContext, respectively. Moreover, this class allows to create or delete such collections and indexes.
   */
public class ZorbaXQStaticCollectionManager {

    private boolean closed = false;
    private StaticCollectionManager collectionManager = null;
    private Collection<XQSequence> sequences = new ArrayList<XQSequence>();
    private Collection<ZorbaXQCollection> collections = new ArrayList<ZorbaXQCollection>();

    protected ZorbaXQStaticCollectionManager (StaticCollectionManager cm) {
        collectionManager = cm;
    }

    public void close() throws XQException {
        for (XQSequence exp : sequences ){
            exp.close();  // Notify the dependents objects to close
        }
        for (ZorbaXQCollection exp : collections ){
            exp.close();  // Notify the dependents objects to close
        }
        closed = true;
    }

    public boolean isClosed() {
        return closed;
    }

  /** \brief This function returns a sequence of names of the collections that are available.
   * 
   * If this is an instance of the StaticCollectionManager class (i.e. returned by any of the getStaticCollectionManager methods), the collections returned by this function are also statically declared.
   * 
   * @return ZorbaXQSequence - The list of names of the available collections.
   */
    public XQSequence availableCollections() throws XQException {
        isClosedXQException();
        XQSequence result = new org.zorbaxquery.api.xqj.ZorbaXQSequence(collectionManager.availableCollections());
        sequences.add(result);
        return result;
    }

  /** \brief This function creates the collection with the given name.
   * 
   * @param aName	The name of the collection to create.
   * @throw XQException- if a collection with the given name already exists.
   */
    public void createCollection(XQItem aName ) throws XQException {
        isClosedXQException();
        collectionManager.createCollection(((org.zorbaxquery.api.xqj.ZorbaXQItem)aName).getZorbaItem());
    }

  /** \brief This function removes the collection with the given name.
   * 
   * @param aName	- The name of the collection to delete.
   * @throw XQException - if the collection does not exist.
   */
    public void deleteCollection(XQItem aName ) throws XQException {
        isClosedXQException();
        collectionManager.deleteCollection(((org.zorbaxquery.api.xqj.ZorbaXQItem)aName).getZorbaItem());
    }

  /** \brief Returns a instance of the Collection class which can be used to modify and retrieve the contents of the collection identified by the given name.
   * 
   * @param aName	- The name of the collection to retrieve.
   * @return ZorbaXQCollection - The collection if available.
   * @throw XQException - if the collection does not exist.
   */
    public ZorbaXQCollection getCollection(XQItem aName ) throws XQException {
        isClosedXQException();
        ZorbaXQCollection result = new ZorbaXQCollection ( collectionManager.getCollection(((org.zorbaxquery.api.xqj.ZorbaXQItem)aName).getZorbaItem()) );
        collections.add(result);
        return result;
    }

  /** \brief This function returns true if a collection with the given name is available.
   * 
   * If this is an instance of the StaticCollectionManager class (i.e. returned by any of the getStaticCollectionManager() methods), the collection also needs to be statically declared.
   * 
   * @param aName - The name of the collection that is being checked.
   * @return true if the collection is available and false otherwise.
   * @throw XQException - if the Collection Manager is closed
   */
    public boolean isAvailableCollection(XQItem aName ) throws XQException {
        isClosedXQException();
        return collectionManager.isAvailableCollection( ((org.zorbaxquery.api.xqj.ZorbaXQItem)aName).getZorbaItem() );
    }

    private void isClosedXQException() throws XQException {
        if (closed) {
            throw new XQException("CollectionManager is closed");
        }
    }
    
}
