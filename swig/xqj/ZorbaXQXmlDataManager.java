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
import org.zorbaxquery.api.ItemSequence;
import org.zorbaxquery.api.XmlDataManager;
import org.zorbaxquery.api.Zorba;


  /**
   * Using the ZorbaXQXmlDataManager one can manage documents and collections.
   * 
   * The ZorbaXQXmlDataManager is a singleton instance. The XQConnection object is reponsible for maintaining its lifetime. The instance can be accessed by calling getXmlDataManager() on the XQConnection object. It may not be accessed anymore after XQConnection is closed.
   * 
   */
public class ZorbaXQXmlDataManager {
    
    private boolean closed = false;
    private XmlDataManager dm;
    private ZorbaXQDocumentManager lDocumentManager;
    private ZorbaXQCollectionManager lCollectionManager;
    private ZorbaXQCollectionManager lW3CollectionManager;
    private Collection<ZorbaXQSequence> sequences = new ArrayList<ZorbaXQSequence>();

    protected ZorbaXQXmlDataManager(Zorba zorba) {
        dm = zorba.getXmlDataManager();
    }
    
  /** \brief   Close the XmlDataManager and release all the resources associated with this item.
   * 
   *   Close the XmlDataManager and release all the resources associated with this item. No method other than the isClosed or close method may be called once the XmlDataManager is closed. Calling close on an XmlDataManager object that is already closed has no effect.
   * 
   * @throw XQException - if there is an error during closing the item
   */
    public void close() throws XQException {
        if (lDocumentManager!=null) {
            lDocumentManager.close();
        }
        if (lCollectionManager!=null) {
            lCollectionManager.close();
        }
        if (lW3CollectionManager!=null) {
            lW3CollectionManager.close();
        }
        for (ZorbaXQSequence exp : sequences ){
            exp.close();  // Notify the dependents objects to close
        }
        if (dm!=null) {
            dm.delete();
        }
        closed = true;
    }

  /** \brief  Checks if the ZorbaXQXmlDataManager is closed.
   * 
   *  Checks if the ZorbaXQXmlDataManager is closed.
   * 
   * @return boolean true if the ZorbaXQXmlDataManager is in a closed state, false otherwise
   */
    public boolean isClosed() {
        return closed;
    }

    public ZorbaXQDocumentManager getDocumentManager()  throws XQException {
        isClosedXQException();
        if (lDocumentManager==null) {
            lDocumentManager = new ZorbaXQDocumentManager(dm.getDocumentManager());
        }
        return lDocumentManager;
    }

  /** \brief Returns a CollectionManager responsible for all collections.
   * The collection manager provides a set of functions for managing collections identified by a QName and their contents.
   * 
   * Please note that the resulting manager is only responsible for dynamic collections identified by a QName, i.e. those that are not declared in the prolog of a module or identified by a URI.
   * 
   * @return The collection manager responsible for managing collections.
   */
    public ZorbaXQCollectionManager getCollectionManager()  throws XQException {
        isClosedXQException();
        if (lCollectionManager==null) {
            lCollectionManager = new ZorbaXQCollectionManager(dm.getCollectionManager());
        }
        return lCollectionManager;
    }

  /** \brief Returns a CollectionManager responsible for collections identified by a URI.
   * The collection manager provides a set of functions for managing collections identified by a URI and their contents.
   * 
   * Please note that the resulting manager is only responsible for dynamic collections identified by a URI, i.e. those that are not declared in the prolog of a module or identified by a QName.
   * 
   * @return The collection manager responsible for managing collections.
   */
    public ZorbaXQCollectionManager getW3CCollectionManager()  throws XQException {
        isClosedXQException();
        if (lW3CollectionManager==null) {
            lW3CollectionManager = new ZorbaXQCollectionManager(dm.getW3CCollectionManager());
        }
        return lW3CollectionManager;
    }

  /** \brief Parse an XML document and return an ZorbaXQSequence.
   * 
   */
    public ZorbaXQSequence parseXML(String xmlText) throws XQException {
        isClosedXQException();
        ItemSequence zSequence = new ItemSequence(dm.parseXMLtoItem(xmlText));
        ZorbaXQSequence result = new ZorbaXQSequence(zSequence);
        sequences.add(result);
        return result;
    }

    private void isClosedXQException() throws XQException {
        if (closed) {
            throw new XQException("XmlDataManager is closed");
        }
    }
}
