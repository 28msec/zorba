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
import org.zorbaxquery.api.XmlDataManager;
import org.zorbaxquery.api.Zorba;


public class XQXmlDataManager {
    
    private boolean closed = false;
    private XmlDataManager dm;
    private XQDocumentManager lDocumentManager;
    private XQCollectionManager lCollectionManager;
    private XQCollectionManager lW3CollectionManager;
    private Collection<XQSequence> sequences = new ArrayList<XQSequence>();

    protected XQXmlDataManager(Zorba zorba) {
        dm = zorba.getXmlDataManager();
    }
    
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
        for (XQSequence exp : sequences ){
            exp.close();  // Notify the dependents objects to close
        }
        closed = true;
    }

    public boolean isClosed() {
        return closed;
    }
    
    public XQDocumentManager getDocumentManager()  throws XQException {
        isClosedXQException();
        if (lDocumentManager==null) {
            lDocumentManager = new XQDocumentManager(dm.getDocumentManager());
        }
        return lDocumentManager;
    }
    
    public XQCollectionManager getCollectionManager()  throws XQException {
        isClosedXQException();
        if (lCollectionManager==null) {
            lCollectionManager = new XQCollectionManager(dm.getCollectionManager());
        }
        return lCollectionManager;
    }
    
    public XQCollectionManager getW3CCollectionManager()  throws XQException {
        isClosedXQException();
        if (lW3CollectionManager==null) {
            lW3CollectionManager = new XQCollectionManager(dm.getW3CCollectionManager());
        }
        return lW3CollectionManager;
    }
    
    public XQSequence parseXML(String xmlText) throws XQException {
        isClosedXQException();
        XQSequence result = new XQSequence(dm.parseXML(xmlText));
        sequences.add(result);
        return result;
    }
    
    private void isClosedXQException() throws XQException {
        if (closed) {
            throw new XQException("XmlDataManager is closed");
        }
    }
}
