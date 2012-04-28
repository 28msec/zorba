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
import org.zorbaxquery.api.Collection;
import javax.xml.xquery.XQItem;
import javax.xml.xquery.XQSequence;
import org.zorbaxquery.api.ItemSequence;

public class XQCollection {

    private boolean closed = false;
    private Collection collection = null;
    private java.util.Collection<XQSequence> sequences = new ArrayList<XQSequence>();

    protected XQCollection(Collection col) {
        collection = col;
    }

    public void close() throws XQException {
        for (XQSequence exp : sequences ){
            exp.close();  // Notify the dependents objects to close
        }
        if (collection!=null) {
            collection.delete();
        }
        closed = true;
    }

    public boolean isClosed() {
        return closed;
    }

    public XQSequence contents() throws XQException {
        isClosedXQException();
        XQSequence result =  new org.zorbaxquery.api.xqj.XQSequence(collection.contents().getIterator());
        sequences.add(result);
        return result;
    }

    public void deleteNodeFirst() throws XQException {
        isClosedXQException();
        collection.deleteNodeFirst();
    }

    public void deleteNodeLast() throws XQException {
        isClosedXQException();
        collection.deleteNodeLast();
    }

    public void deleteNodes(XQSequence aNodes ) throws XQException {
        isClosedXQException();
        try {
            ItemSequence sequence =  ((org.zorbaxquery.api.xqj.XQSequence)aNodes).getItemSequence();
            collection.deleteNodes(sequence);
        } catch (XQException e) {
            throw e;
        }
    }   

    public void deleteNodesFirst(long aNumNodes ) throws XQException {
        isClosedXQException();
        collection.deleteNodesFirst(aNumNodes);
    }

    public void deleteNodesLast(long aNumNodes ) throws XQException {
        isClosedXQException();
        collection.deleteNodesLast(aNumNodes);
    }

    public String getName() throws XQException {
        isClosedXQException();
        return collection.getName().getStringValue();
    }

    public XQItemType getType() throws XQException {
        isClosedXQException();
        return new XQItemType(collection.getType());
    }

    public long indexOf(XQItem aNode ) throws XQException {
        isClosedXQException();
        return collection.indexOf(((org.zorbaxquery.api.xqj.XQItem)aNode).getZorbaItem());
    }

    public void insertNodesAfter(XQItem aTarget, XQSequence aNodes ) throws XQException {
        isClosedXQException();
        try {
            ItemSequence sequence =  ((org.zorbaxquery.api.xqj.XQSequence)aNodes).getItemSequence();
            collection.insertNodesAfter(((org.zorbaxquery.api.xqj.XQItem)aTarget).getZorbaItem(), sequence);
        } catch (XQException e) {
            throw e;
        }
    }

    public void insertNodesBefore(XQItem aTarget, XQSequence aNodes ) throws XQException {
        isClosedXQException();
        try {
            ItemSequence sequence =  ((org.zorbaxquery.api.xqj.XQSequence)aNodes).getItemSequence();
            collection.insertNodesBefore(((org.zorbaxquery.api.xqj.XQItem)aTarget).getZorbaItem(), sequence);
        } catch (XQException e) {
            throw e;
        }
    }

    public void insertNodesFirst(XQSequence aNodes ) throws XQException {
        isClosedXQException();
        try {
            ItemSequence sequence =  ((org.zorbaxquery.api.xqj.XQSequence)aNodes).getItemSequence();
            collection.insertNodesFirst(sequence);
        } catch (XQException e) {
            throw e;
        }
    }

    public void insertNodesLast(XQSequence aNodes ) throws XQException {
        isClosedXQException();
        try {
            ItemSequence sequence =  ((org.zorbaxquery.api.xqj.XQSequence)aNodes).getItemSequence();
            collection.insertNodesLast(sequence);
        } catch (XQException e) {
            throw e;
        }
    }

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
