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

import java.io.InputStream;
import java.io.Reader;
import java.io.StringWriter;
import java.io.Writer;
import java.nio.CharBuffer;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.TimeZone;
import javax.xml.namespace.QName;
import javax.xml.stream.XMLStreamReader;
import javax.xml.transform.Source;
import javax.xml.xquery.XQException;
import javax.xml.xquery.XQItem;
import javax.xml.xquery.XQItemType;
import javax.xml.xquery.XQResultSequence;
import javax.xml.xquery.XQSequence;
import javax.xml.xquery.XQStaticContext;
import javax.xml.xquery.XQConnection;
import javax.xml.xquery.XQConstants;
import org.w3c.dom.Node;
import org.zorbaxquery.api.DynamicContext;
import org.zorbaxquery.api.Item;
import org.zorbaxquery.api.XQuery;

/**
  * This interface describes the execute immediate functionality for expressions. This object can be created from the ZorbaXQConnection and the execution can be done using the executeQuery() or executeCommand() method, passing in the XQuery expression.
  * 
  * All external variables defined in the prolog of the expression to be executed must be set in the dynamic context of this expression using the bind methods. Also, variables bound in this expression but not defined as external in the prolog of the expression to be executed, are simply ignored. For example, if variables $var1 and $var2 are bound, but the query only defines $var1 as external, no error will be reported for the binding of $var2. It will simply be ignored. When the expression is executed using the executeQuery method, if the execution is successful, then an ZorbaXQResultSequence object is returned. The ZorbaXQResultSequence object is tied to the ZorbaXQExpression from which it was prepared and is closed implicitly if that ZorbaXQExpression is either closed or re-executed.
  * 
  * The ZorbaXQExpression object is dependent on the ZorbaXQConnection object from which it was created and is only valid for the duration of that object. Thus, if the ZorbaXQConnection object is closed then this ZorbaXQExpression object will be implicitly closed and it can no longer be used.
  * 
  * An XQJ driver is not required to provide finalizer methods for the connection and other objects. Hence it is strongly recommended that users call close method explicitly to free any resources. It is also recommended that they do so under a final block to ensure that the object is closed even when there are exceptions. Not closing this object implicitly or explicitly might result in serious memory leaks.
  * 
  * When the ZorbaXQExpression is closed any ZorbaXQResultSequence object obtained from it is also implicitly closed.
  * 
  * Example -
  * \code{.java}
  *   ZorbaXQConnection conn = XQDatasource.getConnection();
  *   ZorbaXQExpression expr = conn.createExpression();
  * 
  *   expr.bindInt(new QName("x"), 21, null);
  *  
  *   XQSequence result = expr.executeQuery(
  *      "declare variable $x as xs:integer external;
  *      for $i in $x return $i");
  *    
  *   while (result.next())
  *   {
  *      // process results ...
  *   }
  *  
  *   // Execute some other expression on the same object
  *   XQSequence result = expr.executeQuery("for $i in doc('foo.xml') return $i");
  *   ... 
  * 
  *   result.close(); // close the result
  *   expr.close(); 
  *   conn.close(); 
  *  \endcode
  */
public class ZorbaXQExpression implements javax.xml.xquery.XQExpression {

    //private XQuery query;
    private XQConnection connection;
    private boolean closed = false;
    private boolean cancel = false;
    private Collection<XQResultSequence> resultSequences = new ArrayList<XQResultSequence>();
    private XQStaticContext staticContext;
    private Map<String, Item> itemsToBind = new HashMap<String, Item>();
    private TimeZone implicitTimeZone;
            
    public ZorbaXQExpression (XQConnection conn) throws XQException {
        if (conn.isClosed()) {
            throw new XQException ("Connection is closed");
        }
        connection = conn;
    }

    public ZorbaXQExpression (XQConnection conn, XQStaticContext sc) throws XQException {
        if (conn.isClosed()) {
            throw new XQException ("Connection is closed");
        }
        connection = conn;
        staticContext = sc;
    }

  /** \brief Attempts to cancel the execution if both the XQuery engine and XQJ driver support aborting the execution of an ZorbaXQExpression.
   * 
   * This method can be used by one thread to cancel an ZorbaXQExpression, that is being executed in another thread. If cancellation is not supported or the attempt to cancel the execution was not successful, the method returns without any error. If the cancellation is successful, an XQException is thrown, to indicate that it has been aborted, by executeQuery, executeCommand or any method accessing the ZorbaXQResultSequence returned by executeQuery. If applicable, any open ZorbaXQResultSequence and XQResultItem objects will also be implicitly closed in this case.
   * 
   * @throw XQException - if the expression is in a closed state
   */
    @Override
    public void cancel() throws XQException {
        isClosedXQException();
        cancel = true;
    }

  /** \brief Checks if the expression is in a closed state.
   * 
   * @return true if the expression is in a closed state, false otherwise
   */
    @Override
    public boolean isClosed() {
        return closed;
    }


  /** \brief Closes the expression object and release associated resources.
   * 
   * Once the expression is closed, all methods on this object other than the close or isClosed will raise exceptions. This also closes any result sequences obtained from this expression. Calling close on an ZorbaXQExpression object that is already closed has no effect.
   * 
   * @throw XQException - if there are errors when closing the expression
   */
   @Override
    public void close() throws XQException {
        closed=true;
        for (XQResultSequence rs: resultSequences) {
            rs.close();
        }
    }

  /** \brief Executes an implementation-defined command.
   * 
   * Calling this method implicitly closes any previous result sequence obtained from this expression.
   * 
   * @param string - the input command as a string
   * @throw XQException - if (1) there are errors when executing the command, or (2) the expression is in a closed state
   */
    @Override
    public void executeCommand(String string) throws XQException {
        throw new UnsupportedOperationException("Not supported yet.");
    }

  /** \brief Executes an implementation-defined command.
   * 
   * Calling this method implicitly closes any previous result sequence obtained from this expression.
   * 
   * @param reader - the input command as a reader
   * @throw XQException - if (1) there are errors when executing the command, or (2) the expression is in a closed state
   */
    @Override
    public void executeCommand(Reader reader) throws XQException {
        throw new UnsupportedOperationException("Not supported yet.");
    }

  /** \brief Executes a query expression.
   * 
   * This implicitly closes any previous result sequences obtained from this expression.
   * 
   * @param value - the input query expression string. Cannot be null
   * @return an ZorbaXQResultSequence object containing the result of the query execution
   * @throw XQException - if (1) there are errors when executing the query, (2) the expression is in a closed state, (3) the execution is cancelled, (4) the query parameter is null
   */
    @Override
    public XQResultSequence executeQuery(String value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        org.zorbaxquery.api.xqj.ZorbaXQConnection lConnection = (org.zorbaxquery.api.xqj.ZorbaXQConnection)connection;
        XQuery query =  lConnection.getZorbaInstance().createQuery();
        XQResultSequence result = null;
        try {
            int scrollable = XQConstants.SCROLLTYPE_FORWARD_ONLY;
            if (staticContext!=null) {
              query.compile(value, ((org.zorbaxquery.api.xqj.ZorbaXQStaticContext)staticContext).getZorbaStaticContext());
              scrollable = staticContext.getScrollability();
            } else {
              query.compile(value);
            }
            DynamicContext dynamicContext = query.getDynamicContext();
            if (implicitTimeZone!=null) {
                dynamicContext.setImplicitTimezone((implicitTimeZone.getRawOffset()/60000));
                implicitTimeZone=null;
            }
            for (String key: itemsToBind.keySet()){
                dynamicContext.setVariable(key, itemsToBind.get(key) );
                //itemsToBind.remove(key);
            }
            if (scrollable == XQConstants.SCROLLTYPE_FORWARD_ONLY) {
                result = new org.zorbaxquery.api.xqj.ZorbaXQResultSequence(connection, query, false);
            } else {
                result = new org.zorbaxquery.api.xqj.ZorbaXQResultSequenceScrollable(connection, query, false);
            }
            resultSequences.add(result);
        } catch (Exception e) {
            throw new XQException ("Error executing query: " + e.getLocalizedMessage());
        }
        return result;
    }

  /** \brief Executes a query expression.
   * 
   * This implicitly closes any previous result sequences obtained from this expression.
   * 
   * @param value - the input query expression reader object. Cannot be null
   * @return an ZorbaXQResultSequence object containing the result of the query execution
   * @throw XQException - if (1) there are errors when executing the query, (2) the expression is in a closed state, (3) the execution is cancelled, (4) the query parameter is null
   */
    @Override
    public XQResultSequence executeQuery(Reader value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        
        StringBuffer string = new StringBuffer();
        CharBuffer buffer = CharBuffer.allocate(1024);
        Writer writer = new StringWriter();
        
        try {
            while( value.read(buffer) >= 0 ) {
                buffer.flip();
                writer.append(buffer);
                buffer.clear();
            }
            value.close();
        } catch (Exception ex) {
            throw new XQException("Error preparing expression" + ex.getLocalizedMessage());
        }
        
        return executeQuery(writer.toString());
    }

  /** \brief Executes a query expression.
   * 
   * This implicitly closes any previous result sequences obtained from this expression.
   * 
   * @param value - the input query expression inputstream object. Cannot be null
   * @return an ZorbaXQResultSequence object containing the result of the query execution
   * @throw XQException - if (1) there are errors when executing the query, (2) the expression is in a closed state, (3) the execution is cancelled, (4) the query parameter is null
   */
    @Override
    public XQResultSequence executeQuery(InputStream value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        StringBuffer  out = new StringBuffer ();
        try {
            byte[] b = new byte[4096];
            for (int n; (n = value.read(b)) != -1;) {
                out.append(new String(b, 0, n));
            }
        } catch (Exception ex) {
            throw new XQException("Error preparing expression" + ex.getLocalizedMessage());
        }
        return executeQuery(out.toString());
    }

  /** \brief Gets an ZorbaXQStaticContext representing the values for all expression properties.
   * 
   * Note that these properties cannot be changed; in order to change, a new ZorbaXQExpression needs to be created.
   * 
   * @return an ZorbaXQStaticContext representing the values for all expression properties
   * @throw XQException - if the expression is in a closed state
   */
    @Override
    public XQStaticContext getStaticContext() throws XQException {
        isClosedXQException();
        if (staticContext==null) {
            return connection.getStaticContext();
        } else {
            return staticContext;
        }
    }

  /** \brief Gets the implicit timezone
   * 
   * @return the implicit timezone. This may have been set by an application using the setImplicitTimeZone method or provided by the implementation
   * @throw XQException - if the expression is in a closed state
   */
    @Override
    public TimeZone getImplicitTimeZone() throws XQException {
        isClosedXQException();
        if (implicitTimeZone!=null) {
            return implicitTimeZone;
        }
        XQuery query =  ((org.zorbaxquery.api.xqj.ZorbaXQConnection)connection).getZorbaInstance().compileQuery("1");
        DynamicContext dc = query.getDynamicContext();
        Integer timeZone = (dc.getImplicitTimezone()/60); // in minutes
        TimeZone result = TimeZone.getTimeZone("GMT"+timeZone.toString());
        return result;
    }

  /** \brief Binds a value to the given external variable or the context item.
   * 
   * The value is converted into an instance of the specified type according to the casting from xs:string rules outlined in 17.1.1 Casting from xs:string and xs:untypedAtomic, XQuery 1.0 and XPath 2.0 Functions and Operators. If the cast fails, or if there is a mismatch between the static and dynamic types, an XQException is thrown either by this method or during query evaluation.
   * 
   * @param varName - the name of the external variable to bind to
   * @param value - the lexical string value of the type
   * @param type - the item type of the bind
   * @throw XQException - if (1) any of the arguments are null, (2) given type is not an atomic type, (3) the conversion of the value to an XDM instance failed, (4) in case of an XQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (5) in case of an XQPreparedExpression, the variable is not defined in the prolog of the expression, or (6) the expression is in a closed state
   */
    @Override
    public void bindAtomicValue(QName varName, String value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            XQItem item = connection.createItemFromAtomicValue(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable or the context item.
   * 
   * The value is converted into an instance of the specified type, which must represent an xs:string or a type derived by restriction from xs:string. If the specified type is null, it defaults to xs:string.
   * Subsequently the value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0,. If the conversion fails, or if there is a mismatch between the static and dynamic types, an XQException is raised either by this method, or during query evaluation.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be converted, cannot be null
   * @param type - the type of the value to be bound to the external variable. The default type, xs:string, is used in case null is specified
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an XQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an XQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindString(QName varName, String value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            XQItem item = connection.createItemFromString(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable or the context item. 
   * 
   * If the value represents a well-formed XML document, it will be parsed and results in a document node. The kind of the input type must be null, XQITEMKIND_DOCUMENT_ELEMENT, or XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT. 
   * 
   * The value is converted into an instance of the specified type according to the rules defined in 14.3 Mapping a Java XML document to an XQuery document node, XQuery API for Java (XQJ) 1.0. 
   * 
   * If the conversion fails, or if there is a mismatch between the static and dynamic types, an XQException is raised either by this method, or during query evaluation. If the value is not well formed, or if a kind of the input type other than the values list above is specified, behavior is implementation defined and may raise an exception.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be converted, cannot be null
   * @param baseURI - an optional base URI, can be null. It can be used, for example, to resolve relative URIs and to include in error messages.
   * @param type - the type of the value for the created document node. If null is specified, it behaves as if XQDataFactory.createDocumentElementType( XQDataFactory.createElementType(null, XQItemType.XQBASETYPE_XS_UNTYPED)) were passed in as the type parameter. That is, the type represents the XQuery sequence type document-node(element(*, xs:untyped))
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an XQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an XQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindDocument(QName varName, String value, String baseURI, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            XQItem item = connection.createItemFromDocument(value, baseURI, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable or the context item. 
   * 
   * If the value represents a well-formed XML document, it will be parsed and results in a document node. The kind of the input type must be null, XQITEMKIND_DOCUMENT_ELEMENT, or XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT. 
   * 
   * The value is converted into an instance of the specified type according to the rules defined in 14.3 Mapping a Java XML document to an XQuery document node, XQuery API for Java (XQJ) 1.0. 
   * 
   * If the conversion fails, or if there is a mismatch between the static and dynamic types, an XQException is raised either by this method, or during query evaluation. If the value is not well formed, or if a kind of the input type other than the values list above is specified, behavior is implementation defined and may raise an exception.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be converted, cannot be null
   * @param baseURI - an optional base URI, can be null. It can be used, for example, to resolve relative URIs and to include in error messages.
   * @param type - the type of the value for the created document node. If null is specified, it behaves as if XQDataFactory.createDocumentElementType( XQDataFactory.createElementType(null, XQItemType.XQBASETYPE_XS_UNTYPED)) were passed in as the type parameter. That is, the type represents the XQuery sequence type document-node(element(*, xs:untyped))
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an XQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an XQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindDocument(QName varName, Reader value, String baseURI, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            XQItem item = connection.createItemFromDocument(value, baseURI, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable or the context item. 
   * 
   * If the value represents a well-formed XML document, it will be parsed and results in a document node. The kind of the input type must be null, XQITEMKIND_DOCUMENT_ELEMENT, or XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT. 
   * 
   * The value is converted into an instance of the specified type according to the rules defined in 14.3 Mapping a Java XML document to an XQuery document node, XQuery API for Java (XQJ) 1.0. 
   * 
   * If the conversion fails, or if there is a mismatch between the static and dynamic types, an XQException is raised either by this method, or during query evaluation. If the value is not well formed, or if a kind of the input type other than the values list above is specified, behavior is implementation defined and may raise an exception.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be converted, cannot be null
   * @param baseURI - an optional base URI, can be null. It can be used, for example, to resolve relative URIs and to include in error messages.
   * @param type - the type of the value for the created document node. If null is specified, it behaves as if XQDataFactory.createDocumentElementType( XQDataFactory.createElementType(null, XQItemType.XQBASETYPE_XS_UNTYPED)) were passed in as the type parameter. That is, the type represents the XQuery sequence type document-node(element(*, xs:untyped))
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an XQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an XQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindDocument(QName varName, InputStream value, String baseURI, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            XQItem item = connection.createItemFromDocument(value, baseURI, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable or the context item. 
   * 
   * If the value represents a well-formed XML document, it will be parsed and results in a document node. The kind of the input type must be null, XQITEMKIND_DOCUMENT_ELEMENT, or XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT. 
   * 
   * The value is converted into an instance of the specified type according to the rules defined in 14.3 Mapping a Java XML document to an XQuery document node, XQuery API for Java (XQJ) 1.0. 
   * 
   * If the conversion fails, or if there is a mismatch between the static and dynamic types, an XQException is raised either by this method, or during query evaluation. If the value is not well formed, or if a kind of the input type other than the values list above is specified, behavior is implementation defined and may raise an exception.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be converted, cannot be null
   * @param type - the type of the value for the created document node. If null is specified, it behaves as if XQDataFactory.createDocumentElementType( XQDataFactory.createElementType(null, XQItemType.XQBASETYPE_XS_UNTYPED)) were passed in as the type parameter. That is, the type represents the XQuery sequence type document-node(element(*, xs:untyped))
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an XQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an XQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindDocument(QName varName, XMLStreamReader value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            XQItem item = connection.createItemFromDocument(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable or the context item. 
   * 
   * An XQJ implementation must at least support the following implementations:
   * - javax.xml.transform.dom.DOMSource
   * - javax.xml.transform.sax.SAXSource
   * - javax.xml.transform.stream.StreamSource
   * 
   * If the value represents a well-formed XML document, it will be parsed and results in a document node. The kind of the input type must be null, XQITEMKIND_DOCUMENT_ELEMENT, or XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT. 
   * 
   * The value is converted into an instance of the specified type according to the rules defined in 14.3 Mapping a Java XML document to an XQuery document node, XQuery API for Java (XQJ) 1.0. 
   * 
   * If the conversion fails, or if there is a mismatch between the static and dynamic types, an XQException is raised either by this method, or during query evaluation. If the value is not well formed, or if a kind of the input type other than the values list above is specified, behavior is implementation defined and may raise an exception.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be converted, cannot be null
   * @param type - the type of the value for the created document node. If null is specified, it behaves as if XQDataFactory.createDocumentElementType( XQDataFactory.createElementType(null, XQItemType.XQBASETYPE_XS_UNTYPED)) were passed in as the type parameter. That is, the type represents the XQuery sequence type document-node(element(*, xs:untyped))
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an XQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an XQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindDocument(QName varName, Source value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            XQItem item = connection.createItemFromDocument(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

  /** \brief Sets the implicit timezone
   * 
   * @param value - time zone to be set
   * @throw XQException - if the expression is in a closed state
   */
    @Override
    public void setImplicitTimeZone(TimeZone value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        try {
            implicitTimeZone = value;
        } catch (Exception e) {
            throw new XQException("Error setting implicit TimeZone: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable.
   * 
   * The dynamic type of the value is derived from the ZorbaXQItem. In case of a mismatch between the static and dynamic types, an XQException is raised either by this method, or during query evaluation.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be bound, cannot be null
   * @throw XQException - if (1) any of the arguments are null, (2) in case of an XQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (3) in case of an XQPreparedExpression, the variable is not defined in the prolog of the expression, (4) the expression is in a closed state, or (5) the specified item is closed
   */
    @Override
    public void bindItem(QName varName, XQItem value) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.ZorbaXQItem)value).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable.
   * 
   * The input sequence is consumed from its current position to the end, after which the input sequence's position will be set to point after the last item. The dynamic type of the value is derived from the items in the sequence. In case of a mismatch between the static and dynamic types, an XQException is be raised either by this method, or during query evaluation.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be bound, cannot be null
   * @throw XQException - if (1) any of the arguments are null, (2) in case of an XQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (3) in case of an XQPreparedExpression, the variable is not defined in the prolog of the expression, (4) the expression is in a closed state, or (5) the specified item is closed
   */
    @Override
    public void bindSequence(QName varName, XQSequence value) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            Item item = new Item(((org.zorbaxquery.api.xqj.ZorbaXQItem)value.getItem()).getZorbaItem());
            itemsToBind.put(varName.getLocalPart(), item);
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable or the context item.
   * 
   * The value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the conversion fails, or if there is a mismatch between the static and dynamic types, an XQException is raised either by this method, or during query evaluation.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be bound, cannot be null
   * @param type - the type of the value to be bound to the external variable. The default type of the value is used in case null is specified
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an XQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an XQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindObject(QName varName, Object value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            XQItem item = null;
            if (value instanceof XQItem) {
                item = (XQItem)value;
            } else {
                item = connection.createItemFromObject(value, type);
            } 
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable or the context item.
   * 
   * The value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the conversion fails, or if there is a mismatch between the static and dynamic types, an XQException is raised either by this method, or during query evaluation.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be bound, cannot be null
   * @param type - the type of the value to be bound to the external variable. The default type of the value is used in case null is specified
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an XQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an XQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindBoolean(QName varName, boolean value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        try {
            XQItem item = connection.createItemFromBoolean(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable or the context item.
   * 
   * The value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the conversion fails, or if there is a mismatch between the static and dynamic types, an XQException is raised either by this method, or during query evaluation.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be bound, cannot be null
   * @param type - the type of the value to be bound to the external variable. The default type of the value is used in case null is specified
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an XQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an XQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindByte(QName varName, byte value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        try {
            XQItem item = connection.createItemFromByte(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable or the context item.
   * 
   * The value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the conversion fails, or if there is a mismatch between the static and dynamic types, an XQException is raised either by this method, or during query evaluation.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be bound, cannot be null
   * @param type - the type of the value to be bound to the external variable. The default type of the value is used in case null is specified
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an XQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an XQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindDouble(QName varName, double value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        try {
            XQItem item = connection.createItemFromDouble(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable or the context item.
   * 
   * The value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the conversion fails, or if there is a mismatch between the static and dynamic types, an XQException is raised either by this method, or during query evaluation.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be bound, cannot be null
   * @param type - the type of the value to be bound to the external variable. The default type of the value is used in case null is specified
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an XQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an XQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindFloat(QName varName, float value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        try {
            XQItem item = connection.createItemFromFloat(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable or the context item.
   * 
   * The value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the conversion fails, or if there is a mismatch between the static and dynamic types, an XQException is raised either by this method, or during query evaluation.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be bound, cannot be null
   * @param type - the type of the value to be bound to the external variable. The default type of the value is used in case null is specified
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an XQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an XQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindInt(QName varName, int value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        try {
            XQItem item = connection.createItemFromInt(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable or the context item.
   * 
   * The value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the conversion fails, or if there is a mismatch between the static and dynamic types, an XQException is raised either by this method, or during query evaluation.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be bound, cannot be null
   * @param type - the type of the value to be bound to the external variable. The default type of the value is used in case null is specified
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an XQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an XQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindLong(QName varName, long value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        try {
            XQItem item = connection.createItemFromLong(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable or the context item.
   * 
   * The value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the conversion fails, or if there is a mismatch between the static and dynamic types, an XQException is raised either by this method, or during query evaluation.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be bound, cannot be null
   * @param type - the type of the value to be bound to the external variable. The default type of the value is used in case null is specified
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an XQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an XQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindNode(QName varName, Node value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        try {
            XQItem item = connection.createItemFromNode(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable or the context item.
   * 
   * The value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the conversion fails, or if there is a mismatch between the static and dynamic types, an XQException is raised either by this method, or during query evaluation.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be bound, cannot be null
   * @param type - the type of the value to be bound to the external variable. The default type of the value is used in case null is specified
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an XQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an XQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindShort(QName varName, short value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        try {
            XQItem item = connection.createItemFromShort(value, type);
            itemsToBind.put(varName.getLocalPart(),((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    private void isClosedXQException() throws XQException {
        if (closed) {
            throw new XQException("This expression is closed");
        }
    }
    private void isNullXQException(Object value) throws XQException {
        if (value==null) {
            throw new XQException("Parameter shouldn't be null");
        }
    }
   
    
}
