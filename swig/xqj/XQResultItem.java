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

import javax.xml.xquery.XQConnection;
import javax.xml.xquery.XQException;
import org.zorbaxquery.api.Item;

public class XQResultItem extends XQItem implements javax.xml.xquery.XQResultItem {

    private XQConnection connection;
    
    
    public XQResultItem(Item item, XQConnection conn) {
        super(item);
        connection = conn;
    }

    @Override
    public XQConnection getConnection() throws XQException {
        if (super.isClosed()) {
            throw new XQException("Object closed");
        }
        return connection;
    }
    
    
    
}
