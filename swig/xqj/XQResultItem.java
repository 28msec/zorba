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
 /**
   * This class represents an immutable item object obtained from an XQResultSequence using the getItem method.
   * 
   * A forward only result sequence does not support calling the getter methods multiple times on the same item. To work around this case, the getItem method can be used to obtain a result item and then getter methods may be called multiple times on this item.
   * 
   * The XQResultItem object is dependent on the connection, expression and the sequence from which it was created and is only valid for the duration of those objects. Thus, if any one of those objects is closed, this XQResultItem object will be implicitly closed, and it can no longer be used. Similarly re-executing the expression also implicitly closes the associated result sequences, which in turn implicitly closes this result item.
   * 
   * An XQJ driver is not required to provide finalizer methods for the connection and other objects. Hence it is strongly recommended that users call close method explicitly to free any resources. It is also recommended that they do so under a final block to ensure that the object is closed even when there are exceptions. Not closing this object implicitly or explicitly might result in serious memory leaks.
   * 
   * Example -
   * \code{.java}
   * 
   *   XQPreparedExpression expr = conn.prepareExpression("for $i ..");
   *   XQResultSequence result = expr.executeQuery();
   * 
   *   // posititioned before the first item
   *   while (result.next())
   *   {
   *     XQResultItem item = result.getItem();
   *     // perform multiple gets on this item 
   *     // get DOM
   *     org.w3.dom.Node node = item.getNode(); 
   *     // get SAX
   *     item.writeItemToSAX(saxHandler);
   *  
   *     item.close();  // good practice.  Item will get implicitly closed
   *                    // when the expression,  connection or sequence is closed.
   *   }
   * 
   *   result.close(); // explicitly close the result sequence
   * \endcode
   **/
public class XQResultItem extends XQItem implements javax.xml.xquery.XQResultItem {

    private XQConnection connection;
    
    
    public XQResultItem(Item item, XQConnection conn) {
        super(item);
        connection = conn;
    }

  /** \brief   Gets the XQuery connection associated with this result item
   * 
   *   Gets the XQuery connection associated with this result item
   * 
   * @return the connection associated with this result item
   * @throw XQException - if the result item is in a closed state
   */
    @Override
    public XQConnection getConnection() throws XQException {
        if (super.isClosed()) {
            throw new XQException("Object closed");
        }
        return connection;
    }
    
    
    
}
