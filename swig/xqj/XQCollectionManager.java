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


public class XQCollectionManager {

    private boolean closed = false;
    private CollectionManager collectionManager = null;
    private Collection<XQSequence> sequences = new ArrayList<XQSequence>();
    private Collection<XQCollection> collections = new ArrayList<XQCollection>();

    protected XQCollectionManager (CollectionManager cm) {
        collectionManager = cm;
    }

    public void close() throws XQException {
        for (XQSequence exp : sequences ){
            exp.close();  // Notify the dependents objects to close
        }
        for (XQCollection exp : collections ){
            exp.close();  // Notify the dependents objects to close
        }
        closed = true;
    }

    public boolean isClosed() {
        return closed;
    }

    public XQSequence availableCollections() throws XQException {
        isClosedXQException();
        XQSequence result = new org.zorbaxquery.api.xqj.XQSequence(collectionManager.availableCollections());
        sequences.add(result);
        return result;
    }

    public void createCollection(XQItem aName ) throws XQException {
        isClosedXQException();
        collectionManager.createCollection(((org.zorbaxquery.api.xqj.XQItem)aName).getZorbaItem());
    }

    public void deleteCollection(XQItem aName ) throws XQException {
        isClosedXQException();
        collectionManager.deleteCollection(((org.zorbaxquery.api.xqj.XQItem)aName).getZorbaItem());
    }

    public XQCollection getCollection(XQItem aName ) throws XQException {
        isClosedXQException();
        XQCollection result = new XQCollection ( collectionManager.getCollection(((org.zorbaxquery.api.xqj.XQItem)aName).getZorbaItem()) );
        collections.add(result);
        return result;
    }

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
