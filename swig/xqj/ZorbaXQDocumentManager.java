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
import org.zorbaxquery.api.DocumentManager;
import javax.xml.xquery.XQItem;

public class ZorbaXQDocumentManager {

    private boolean closed = false;
    DocumentManager dc;
    private Collection<ZorbaXQSequence> sequences = new ArrayList<ZorbaXQSequence>();
    
    protected ZorbaXQDocumentManager(DocumentManager aDocumentManager) {
        dc = aDocumentManager;
    }

    public void close() throws XQException {
        for (ZorbaXQSequence exp : sequences ){
            exp.close();  // Notify the dependents objects to close
        }
        closed = true;
    }
    public boolean isClosed() {
        return closed;
    }

    public ZorbaXQSequence availableDocuments() throws XQException {
        isClosedXQException();
        ZorbaXQSequence result = new ZorbaXQSequence(dc.availableDocuments().getIterator());
        sequences.add(result);
        return result;
    }

    public void put(String aName, javax.xml.xquery.XQItem aDoc)  throws XQException {
        isClosedXQException();
        dc.put(aName, ((org.zorbaxquery.api.xqj.ZorbaXQItem)aDoc).getZorbaItem());
    }
    public void remove(String aName) throws XQException {
        isClosedXQException();
        dc.remove(aName);
    }
    public XQItem document(String aName) throws XQException {
        isClosedXQException();
        return new org.zorbaxquery.api.xqj.ZorbaXQItem(dc.document(aName));
    }
    public boolean isAvailableDocument(String aName) throws XQException {
        isClosedXQException();
        return dc.isAvailableDocument(aName);
    }
    
    private void isClosedXQException() throws XQException {
        if (closed) {
            throw new XQException("DocumentManager is closed");
        }
    }
}
