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

import java.io.*;
import java.nio.CharBuffer;
import java.util.ArrayList;
import java.util.Collection;
import java.util.TimeZone;
import javax.xml.namespace.QName;
import javax.xml.stream.XMLOutputFactory;
import javax.xml.stream.XMLStreamReader;
import javax.xml.stream.XMLStreamWriter;
import javax.xml.transform.*;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.sax.SAXSource;
import javax.xml.transform.stax.StAXResult;
import javax.xml.transform.stax.StAXSource;
import javax.xml.transform.stream.StreamResult;
import javax.xml.transform.stream.StreamSource;
import javax.xml.xquery.*;
import org.w3c.dom.Node;
import org.zorbaxquery.api.*;
 /**
   * This class describes an expression that can be prepared for multiple subsequent executions. A prepared expression can be created from the connection.
   * 
   * The preparation of the expression does the static analysis of the expression using the static context information.
   * 
   * The dynamic context information, such as values for bind variables, can then be set using the setter methods. When setting values for bind variables, these variables should be present as external variables in the prolog of the prepared expression.
   * 
   * The static type information of the query can also be retrieved if the XQuery implementation provides it using the getStaticResultType method.
   * 
   * When the expression is executed using the executeQuery method, if the execution is successful, then an ZorbaXQResultSequence object is returned. The ZorbaXQResultSequence object is tied to the ZorbaXQPreparedExpression from which it was prepared and is closed implicitly if that expression is either closed or if re-executed.
   * 
   * The ZorbaXQPreparedExpression object is dependent on the ZorbaXQConnection object from which it was created and is only valid for the duration of that object. Thus, if the ZorbaXQConnection object is closed then this ZorbaXQPreparedExpression object will be implicitly closed and it can no longer be used.
   * 
   * An XQJ driver is not required to provide finalizer methods for the connection and other objects. Hence it is strongly recommended that users call close method explicitly to free any resources. It is also recommended that they do so under a final block to ensure that the object is closed even when there are exceptions. Not closing this object implicitly or explicitly might result in serious memory leaks.
   * 
   * When the ZorbaXQPreparedExpression is closed any ZorbaXQResultSequence object obtained from it is also implicitly closed.
   * 
   * Example -
   * \code{.java}
   *   ZorbaXQConnection conn = XQDataSource.getconnection();
   *   ZorbaXQPreparedExpression expr = conn.prepareExpression
   *           ("for $i in (1) return 'abc' "); 
   *  
   *   // get the sequence type out.. This would be something like xs:string *
   *   ZorbaXQSequenceType type = expr.getStaticResultType();
   * 
   *   XQSequence result1 = expr.executeQuery();
   *  
   *   // process the result..
   *   result1.next();
   *   System.out.println(" First result1 "+ result1.getAtomicValue());
   * 
   *   ZorbaXQResultSequence result2 = expr.executeQuery();
   * 
   *   // result1 is implicitly closed 
   *   // recommended to close the result sequences explicitly.
   * 
   *   // process the result..
   *   while (result2.next()) 
   *      System.out.println(" result is "+ result2.getAtomicValue());
   *  
   *   result2.close(); 
   *   expr.close(); // closing expression implicitly closes all result sequence or
   *                 // items obtained from this expression.
   *   conn.close(); // closing connections will close expressions and results.
   *  \endcode
   */
public class ZorbaXQPreparedExpression implements javax.xml.xquery.XQPreparedExpression {

    private XQuery query;
    private XQConnection connection;
    private boolean closed;
    private Collection<XQResultSequence> resultSequences = new ArrayList<XQResultSequence>();
    private DynamicContext dynamicContext;
    private XmlDataManager xmlDataManager;
    private XQStaticContext staticContext;
    private Collection<String> itemsBounded = new ArrayList<String>();

    
    public ZorbaXQPreparedExpression (XQConnection conn, String string) throws XQException {
        if (conn.isClosed()) {
            throw new XQException ("Connection is closed");
        }
        closed = false;
        connection = conn;
        Zorba zorba = ((org.zorbaxquery.api.xqj.ZorbaXQConnection)connection).getZorbaInstance(); 
        try {
            query =  zorba.compileQuery(string);
            dynamicContext = query.getDynamicContext();
            xmlDataManager = ((org.zorbaxquery.api.xqj.ZorbaXQConnection)connection).getZorbaInstance().getXmlDataManager();
        } catch (Exception e) {
            throw new XQException ("Error creating new Prepared expression with static context: " + e.getLocalizedMessage());
        
        }
    }

    public ZorbaXQPreparedExpression (XQConnection conn, Reader reader) throws XQException {
        if (conn.isClosed()) {
            throw new XQException ("Connection is closed");
        }
        closed = false;
        connection = conn;
        Zorba zorba = ((org.zorbaxquery.api.xqj.ZorbaXQConnection)connection).getZorbaInstance(); 
        try {
            ZorbaReaderWrapper stream = new ZorbaReaderWrapper(reader);
            query =  zorba.compileQuery(stream);
            dynamicContext = query.getDynamicContext();
            xmlDataManager = ((org.zorbaxquery.api.xqj.ZorbaXQConnection)connection).getZorbaInstance().getXmlDataManager();
        } catch (Exception e) {
            throw new XQException ("Error creating new Prepared expression with static context: " + e.getLocalizedMessage());
        
        }
    }

    public ZorbaXQPreparedExpression (XQConnection conn, InputStream input) throws XQException {
        if (conn.isClosed()) {
            throw new XQException ("Connection is closed");
        }
        closed = false;
        connection = conn;
        Zorba zorba = ((org.zorbaxquery.api.xqj.ZorbaXQConnection)connection).getZorbaInstance(); 
        try {
            ZorbaInputWrapper stream = new ZorbaInputWrapper(input);
            query =  zorba.compileQuery(stream);
            dynamicContext = query.getDynamicContext();
            xmlDataManager = ((org.zorbaxquery.api.xqj.ZorbaXQConnection)connection).getZorbaInstance().getXmlDataManager();
        } catch (Exception e) {
            throw new XQException ("Error creating new Prepared expression with static context: " + e.getLocalizedMessage());
        
        }
    }

    public ZorbaXQPreparedExpression (XQConnection conn, String string, XQStaticContext sc) throws XQException {
        if (conn.isClosed()) {
            throw new XQException ("Connection is closed");
        }
        closed = false;
        connection = conn;
        Zorba zorba = ((org.zorbaxquery.api.xqj.ZorbaXQConnection)connection).getZorbaInstance(); 
        try {
            query =  zorba.compileQuery(string, ((org.zorbaxquery.api.xqj.ZorbaXQStaticContext)sc).getZorbaStaticContext());
            dynamicContext = query.getDynamicContext();
            xmlDataManager = ((org.zorbaxquery.api.xqj.ZorbaXQConnection)connection).getZorbaInstance().getXmlDataManager();
        } catch (Exception e) {
            throw new XQException ("Error creating new Prepared expression with static context: " + e.getLocalizedMessage());
        
        }
    }

    public ZorbaXQPreparedExpression (XQConnection conn, Reader reader, XQStaticContext sc) throws XQException {
        if (conn.isClosed()) {
            throw new XQException ("Connection is closed");
        }
        closed = false;
        connection = conn;
        Zorba zorba = ((org.zorbaxquery.api.xqj.ZorbaXQConnection)connection).getZorbaInstance(); 
        try {
            ZorbaReaderWrapper stream = new ZorbaReaderWrapper(reader);
            query =  zorba.compileQuery(stream, ((org.zorbaxquery.api.xqj.ZorbaXQStaticContext)sc).getZorbaStaticContext());
            dynamicContext = query.getDynamicContext();
            xmlDataManager = ((org.zorbaxquery.api.xqj.ZorbaXQConnection)connection).getZorbaInstance().getXmlDataManager();
        } catch (Exception e) {
            throw new XQException ("Error creating new Prepared expression with static context: " + e.getLocalizedMessage());
        
        }
    }

    public ZorbaXQPreparedExpression (XQConnection conn, InputStream input, XQStaticContext sc) throws XQException {
        if (conn.isClosed()) {
            throw new XQException ("Connection is closed");
        }
        closed = false;
        connection = conn;
        Zorba zorba = ((org.zorbaxquery.api.xqj.ZorbaXQConnection)connection).getZorbaInstance(); 
        try {
            ZorbaInputWrapper stream = new ZorbaInputWrapper(input);
            query =  zorba.compileQuery(stream, ((org.zorbaxquery.api.xqj.ZorbaXQStaticContext)sc).getZorbaStaticContext());
            dynamicContext = query.getDynamicContext();
            xmlDataManager = ((org.zorbaxquery.api.xqj.ZorbaXQConnection)connection).getZorbaInstance().getXmlDataManager();
        } catch (Exception e) {
            throw new XQException ("Error creating new Prepared expression with static context: " + e.getLocalizedMessage());
        
        }
    }

  /** \brief Attempts to cancel the execution if both the XQuery engine and XQJ driver support aborting the execution of an ZorbaXQPreparedExpression.
   * 
   * This method can be used by one thread to cancel an ZorbaXQPreparedExpression, that is being executed in another thread. If cancellation is not supported or the attempt to cancel the execution was not successful, the method returns without any error. If the cancellation is successful, an XQException is thrown, to indicate that it has been aborted, by executeQuery, executeCommand or any method accessing the ZorbaXQResultSequence returned by executeQuery. If applicable, any open ZorbaXQResultSequence and XQResultItem objects will also be implicitly closed in this case.
   * 
   * @throw XQException - if the prepared expression is in a closed state
   */
    @Override
    public void cancel() throws XQException {
        isClosedXQException();
    }

  /** \brief Checks if the prepared expression in a closed state.
   * 
   * @return true if the prepared expression is in a closed state, false otherwise.
   */
    @Override
    public boolean isClosed() {
        return closed;
    }

  /** \brief Closes the expression object and release all resources associated with this prepared expression.
   * 
   * This also closes any result sequences obtained from this expression. Once the expression is closed, all methods on this object other than the close or isClosed will raise exceptions. Calling close on an XQExpression object that is already closed has no effect.
   * 
   * @throw XQException - if there are errors when closing the expression
   */
    @Override
    public void close() throws XQException {
        closed = true;
        for (XQResultSequence sequence: resultSequences) {
            sequence.close();
        }
        if (query!=null) {
            query.delete();
        }
    }

  /** \brief Executes the prepared query expression.
   * 
   * Calling this method implicitly closes any previous result sequence obtained from this expression.
   * 
   * @return the xquery sequence object containing the result of the query execution
   * @throw XQException - if (1) there are errors when executing the prepared expression, (2) the prepared expression is in a closed state, or (3) the query execution is cancelled
   */
    @Override
    public XQResultSequence executeQuery() throws XQException {
        isClosedXQException();
        XQResultSequence result = null;
        try {
            result = new org.zorbaxquery.api.xqj.ZorbaXQResultSequence(connection, query, true);
        } catch (Exception e) {
            throw new XQException("Error executing query: " + e.getLocalizedMessage());
        }
        resultSequences.add(result);
        return result;
    }

  /** \brief Retrieves all the external variables defined in the prolog of the prepared expression.
   * 
   * @return an array of QName objects for all the external variables defined in the prolog of a prepared expression. Empty array if there are no external variables present.
   * @throw XQException - if the prepared expression is in a closed state
   */
    @Override
    public QName[] getAllExternalVariables() throws XQException {
        isClosedXQException();
        Collection<QName> result = new ArrayList<QName>();
        Iterator iter = new Iterator();
        query.getExternalVariables(iter);
        iter.open();
        Item item = new Item();
        while (iter.next(item)) {
            result.add(new QName(item.getNamespace(), item.getLocalName(), item.getPrefix()));
        }
        iter.close();
        iter.delete();
        return result.toArray(new QName[0]);
    }

    private boolean isExternal(String varName) {
        boolean found=false;
        Iterator iter = new Iterator();
        query.getExternalVariables(iter);
        iter.open();
        Item item = new Item();
        while (iter.next(item)) {
            if (item.getLocalName().equalsIgnoreCase(varName)) {
                found = true;
            }
        }
        iter.close();
        iter.delete();
        return found;
    }

  /** \brief Retrieves the names of all unbound external variables.
   * 
   * Gets the static type information of the result sequence. If an implementation does not do static typing of the query, then this method must return an ZorbaXQSequenceType object corresponding to the XQuery sequence type item()*.
   * 
   * @return ZorbaXQSequenceType containing the static result information.
   * @throw XQException - if the prepared expression is in a closed state
   */
    @Override
    public QName[] getAllUnboundExternalVariables() throws XQException {
        isClosedXQException();
        
        Collection<QName> result = new ArrayList<QName>();
        Iterator iter = new Iterator();
        query.getExternalVariables(iter);
        Item item = new Item();
        iter.open();
        while (iter.next(item)) {
            boolean found = false;
            for (String key: itemsBounded){
                if (item.getLocalName().equalsIgnoreCase(key)) {
                    found = true;
                }
            }
            if (!found) {
                result.add(new QName(item.getNamespace(), item.getLocalName(), item.getPrefix()));
            }
        }
        iter.close();
        iter.delete();
        return result.toArray(new QName[0]);
    }

  /** \brief Gets the static type information of the result sequence.
   * 
   * If an implementation does not do static typing of the query, then this method must return an ZorbaXQSequenceType object corresponding to the XQuery sequence type item()*.
   * 
   * @return ZorbaXQSequenceType containing the static result information.
   * @throw XQException - if the prepared expression is in a closed state
   */
    @Override
    public XQSequenceType getStaticResultType() throws XQException {
        isClosedXQException();
        XQSequenceType result = new org.zorbaxquery.api.xqj.ZorbaXQSequenceType(new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ITEM), XQSequenceType.OCC_ZERO_OR_MORE );
        return result;
    }

  /** \brief Retrieves the static type of a given external variable.
   * 
   * @param varName - the name of the external variable
   * @return the static type information of the variable as defined in the prolog of the prepared expression
   * @throw XQException - if (1) the variable does not exist in the static context of the expression, or (2) the sequence is in a closed state, or (3) the name parameter is null
   */
    @Override
    public XQSequenceType getStaticVariableType(QName varName) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        XQSequenceType result = null;
        Iterator iter = new Iterator();
        query.getExternalVariables(iter);
        iter.open();
        Item item = new Item();
        while (iter.next(item)) {
            if ( item.getLocalName().equalsIgnoreCase(varName.getLocalPart()) &&
                 item.getNamespace().equalsIgnoreCase(varName.getNamespaceURI()) &&
                 item.getPrefix().equalsIgnoreCase(varName.getPrefix()) ) {
                 if (item.getType().getStringValue().equals("xs:QName")) {
                     result = new org.zorbaxquery.api.xqj.ZorbaXQSequenceType(new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ITEM), XQItemType.OCC_ZERO_OR_MORE);
                 } else {
                     result = new org.zorbaxquery.api.xqj.ZorbaXQSequenceType(new org.zorbaxquery.api.xqj.ZorbaXQItemType(item), XQItemType.OCC_ZERO_OR_MORE);
                 }
                 
            }
        }
        iter.close();
        iter.delete();
        if (result==null) {
            throw new XQException("Item not found");
        }
        return result;
    }

  /** \brief Gets an ZorbaXQStaticContext representing the values for all expression properties. 
   * 
   * Note that these properties cannot be changed; in order to change, a new ZorbaXQPreparedExpression needs to be created.
   * 
   * @return an ZorbaXQStaticContext representing the values for all expression properties
   * @throw XQException - if the expression is in a closed state
   */
    @Override
    public XQStaticContext getStaticContext() throws XQException {
        isClosedXQException();
        if (staticContext==null) {
            staticContext = new org.zorbaxquery.api.xqj.ZorbaXQStaticContext(query);
        }
        return staticContext;
    }

  /** \brief Gets the implicit timezone
   * 
   * @return the implicit timezone. This may have been set by an application using the setImplicitTimeZone method or provided by the implementation
   * @throw XQException - if the expression is in a closed state
   */
    @Override
    public TimeZone getImplicitTimeZone() throws XQException {
        isClosedXQException();
        Integer timeZone = (dynamicContext.getImplicitTimezone()/60); // in minutes
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
   * @throw XQException - if (1) any of the arguments are null, (2) given type is not an atomic type, (3) the conversion of the value to an XDM instance failed, (4) in case of an ZorbaXQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (5) in case of an ZorbaXQPreparedExpression, the variable is not defined in the prolog of the expression, or (6) the expression is in a closed state
   */
    @Override
    public void bindAtomicValue(QName varName, String value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        isNullXQException(type);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        if (type.getItemKind()!=XQItemType.XQITEMKIND_ATOMIC) {
            throw new XQException ("Item kind is not atomic.");
        }
        try {
            XQItem xqitem = connection.createItemFromAtomicValue(value, type);
            Item item = ((org.zorbaxquery.api.xqj.ZorbaXQItem)xqitem).getZorbaItem();
            dynamicContext.setVariable(varName.getLocalPart(), item);
            itemsBounded.add(varName.getLocalPart());
        } catch (Exception e) {
            throw new XQException ("Error binding the atomic value: " + e.getLocalizedMessage());
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
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an ZorbaXQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an ZorbaXQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindString(QName varName, String value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        isNullXQException(value);
        if (type==null) {
            type = ((org.zorbaxquery.api.xqj.ZorbaXQConnection)connection).createAtomicType(XQItemType.XQBASETYPE_STRING);
        }
        try {
            Iterator iter = new Iterator();
            boolean found = false;
            query.getExternalVariables(iter);
            Item tmpItem = new Item();
            iter.open();
            while (iter.next(tmpItem)) {
                if (tmpItem.getStringValue().equalsIgnoreCase(varName.getLocalPart())) {
                    XQItem item = connection.createItemFromString(value, type);
                    dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
                    itemsBounded.add(varName.getLocalPart());
                    found=true;
                }
            }
            iter.close();
            iter.delete();
            if (!found) {
                throw new XQException ("The variable: " + varName.getLocalPart() + " doesn't exist.");
            }
        } catch (XQException e) {
            throw e;
        } catch (Exception e) {
            throw new XQException ("Error binding string to the defined type: " + e.getLocalizedMessage());
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
   * @param type - the type of the value for the created document node. If null is specified, it behaves as if XQDataFactory.createDocumentElementType( XQDataFactory.createElementType(null, ZorbaXQItemType.XQBASETYPE_XS_UNTYPED)) were passed in as the type parameter. That is, the type represents the XQuery sequence type document-node(element(*, xs:untyped))
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an ZorbaXQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an ZorbaXQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindDocument(QName varName, String value, String baseURI, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        isNullXQException(value);
        if (!((type==null) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_ELEMENT) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT))) {
            throw new XQException ("Invalid type.");
        }
        if (type==null) {
            type = connection.createDocumentElementType(connection.createElementType(null, XQItemType.XQBASETYPE_UNTYPED));
        }
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("Variable not found in context.");
        }
        try {
            Item item = new Item();
            item = xmlDataManager.parseXMLtoItem(value);
            dynamicContext.setVariable(varName.getLocalPart(), item);
            itemsBounded.add(varName.getLocalPart());
        } catch (Exception e) {
            throw new XQException ("Error binding document: " + e.getLocalizedMessage());
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
   * @param type - the type of the value for the created document node. If null is specified, it behaves as if XQDataFactory.createDocumentElementType( XQDataFactory.createElementType(null, ZorbaXQItemType.XQBASETYPE_XS_UNTYPED)) were passed in as the type parameter. That is, the type represents the XQuery sequence type document-node(element(*, xs:untyped))
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an ZorbaXQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an ZorbaXQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindDocument(QName varName, Reader value, String baseURI, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        isNullXQException(value);
        if (!((type==null) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_ELEMENT) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT))) {
            throw new XQException ("Invalid type.");
        }
        if (type==null) {
            type = connection.createDocumentElementType(connection.createElementType(null, XQItemType.XQBASETYPE_UNTYPED));
        }
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
        
        bindDocument(varName, writer.toString(), baseURI, type);
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
   * @param type - the type of the value for the created document node. If null is specified, it behaves as if XQDataFactory.createDocumentElementType( XQDataFactory.createElementType(null, ZorbaXQItemType.XQBASETYPE_XS_UNTYPED)) were passed in as the type parameter. That is, the type represents the XQuery sequence type document-node(element(*, xs:untyped))
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an ZorbaXQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an ZorbaXQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindDocument(QName varName, InputStream value, String baseURI, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        isNullXQException(value);
        if (!((type==null) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_ELEMENT) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT))) {
            throw new XQException ("Invalid type.");
        }
        if (type==null) {
            type = connection.createDocumentElementType(connection.createElementType(null, XQItemType.XQBASETYPE_UNTYPED));
        }
        StringBuffer  out = new StringBuffer ();
        try {
            byte[] b = new byte[4096];
            for (int n; (n = value.read(b)) != -1;) {
                out.append(new String(b, 0, n));
            }
        } catch (Exception ex) {
            throw new XQException("Error preparing expression" + ex.getLocalizedMessage());
        }
        bindDocument(varName, out.toString(), baseURI, type);
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
   * @param type - the type of the value for the created document node. If null is specified, it behaves as if XQDataFactory.createDocumentElementType( XQDataFactory.createElementType(null, ZorbaXQItemType.XQBASETYPE_XS_UNTYPED)) were passed in as the type parameter. That is, the type represents the XQuery sequence type document-node(element(*, xs:untyped))
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an ZorbaXQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an ZorbaXQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindDocument(QName varName, XMLStreamReader value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        isNullXQException(value);
        if (!((type==null) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_ELEMENT) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT))) {
            throw new XQException ("Invalid type.");
        }
        if (type==null) {
            type = connection.createDocumentElementType(connection.createElementType(null, XQItemType.XQBASETYPE_UNTYPED));
        }
        
        TransformerFactory tf = TransformerFactory.newInstance();
        Transformer t;
        StAXSource source;
        StAXResult result;
        XMLOutputFactory xof = XMLOutputFactory.newInstance();
        Writer writer = new StringWriter();
        try {
            XMLStreamWriter xmlStreamWriter =  xof.createXMLStreamWriter(writer);
            t = tf.newTransformer();
            source = new StAXSource(value);
            result = new StAXResult(xmlStreamWriter);
            t.transform(source, result);        
        } catch (Exception ex) {
            throw new XQException("Error transforming xml expression" + ex.getLocalizedMessage());
        }
        bindDocument(varName, writer.toString(), null, type);
    }

    private String nodeToString(Node node) {
     StringWriter sw = new StringWriter();
     try {
       Transformer t = TransformerFactory.newInstance().newTransformer();
       t.setOutputProperty(OutputKeys.OMIT_XML_DECLARATION, "yes");
       t.transform(new DOMSource(node), new StreamResult(sw));
     } catch (TransformerException te) {
       System.out.println("nodeToString Transformer Exception" + te.getLocalizedMessage());
     }
     return sw.toString();
    }

  /** \brief Binds a value to the given external variable or the context item. 
   * 
   * Binds a value to the given external variable or the context item from the given Source. An XQJ implementation must at least support the following implementations:
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
   * @param type - the type of the value for the created document node. If null is specified, it behaves as if XQDataFactory.createDocumentElementType( XQDataFactory.createElementType(null, ZorbaXQItemType.XQBASETYPE_XS_UNTYPED)) were passed in as the type parameter. That is, the type represents the XQuery sequence type document-node(element(*, xs:untyped))
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an ZorbaXQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an ZorbaXQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindDocument(QName varName, Source value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        if (!((type==null) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_ELEMENT) || (type.getItemKind()==XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT))) {
            throw new XQException ("Invalid type.");
        }
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        if (type==null) {
            type = connection.createDocumentElementType(connection.createElementType(null, XQItemType.XQBASETYPE_UNTYPED));
        }
        if (value instanceof StreamSource) {
            bindDocument(varName, ((StreamSource)value).getReader(), null, type);
        } else if (value instanceof SAXSource) {
            bindDocument(varName, ((SAXSource)value).getInputSource().getCharacterStream(), null, type);
        } else if (value instanceof DOMSource) {
            bindDocument(varName, nodeToString(((DOMSource)value).getNode()), null, type);
        } else {
            throw new UnsupportedOperationException("Not supported yet.");
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
            dynamicContext.setImplicitTimezone((value.getRawOffset()/60000));
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
   * @throw XQException - if (1) any of the arguments are null, (2) in case of an ZorbaXQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (3) in case of an ZorbaXQPreparedExpression, the variable is not defined in the prolog of the expression, (4) the expression is in a closed state, or (5) the specified item is closed
   */
    @Override
    public void bindItem(QName varName, XQItem value) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.ZorbaXQItem)value).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
        } catch (Exception e) {
            throw new XQException ("Error binding item: " + varName.getLocalPart() + " with error: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable or the context item.
   * 
   * The input sequence is consumed from its current position to the end, after which the input sequence's position will be set to point after the last item. The dynamic type of the value is derived from the items in the sequence. In case of a mismatch between the static and dynamic types, an XQException is be raised either by this method, or during query evaluation.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be bound, cannot be null
   * @throw XQException - if (1) any of the arguments are null, (2) in case of an ZorbaXQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (3) in case of an ZorbaXQPreparedExpression, the variable is not defined in the prolog of the expression, (4) the expression is in a closed state, or (5) the specified item is closed
   */
    @Override
    public void bindSequence(QName varName, XQSequence value) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        if (value.isClosed()) {
            throw new XQException ("Sequence is closed.");
        }
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            if (!value.isOnItem()) {
                value.next();
            }
            Item item = new Item(((org.zorbaxquery.api.xqj.ZorbaXQItem)value.getItem()).getZorbaItem());
            //Item item2 = new Item(item);
            //String val = item.getStringValue();
            dynamicContext.setVariable(varName.getLocalPart(), item);
            itemsBounded.add(varName.getLocalPart());
        } catch (Exception e) {
            throw new XQException ("Error binding item: " + varName.getLocalPart() + " with error: " + e.getLocalizedMessage());
        }
    }

  /** \brief Binds a value to the given external variable or the context item.
   * 
   * The value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the conversion fails, or if there is a mismatch between the static and dynamic types, an XQException is raised either by this method, or during query evaluation.
   * 
   * @param varName - the name of the external variable to bind to, cannot be null
   * @param value - the value to be bound, cannot be null
   * @param type - the type of the value to be bound to the external variable. The default type of the value is used in case null is specified
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an ZorbaXQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an ZorbaXQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindObject(QName varName, Object value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        isNullXQException(value);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            XQItem item = connection.createItemFromObject(value, type);
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
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
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an ZorbaXQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an ZorbaXQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindBoolean(QName varName, boolean value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            XQItem item = connection.createItemFromBoolean(value, type);
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
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
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an ZorbaXQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an ZorbaXQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindByte(QName varName, byte value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            XQItem item = connection.createItemFromByte(value, type);
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
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
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an ZorbaXQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an ZorbaXQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindDouble(QName varName, double value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            XQItem item = connection.createItemFromDouble(value, type);
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
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
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an ZorbaXQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an ZorbaXQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindFloat(QName varName, float value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            XQItem item = connection.createItemFromFloat(value, type);
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
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
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an ZorbaXQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an ZorbaXQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindInt(QName varName, int value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            XQItem item = connection.createItemFromInt(value, type);
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
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
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an ZorbaXQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an ZorbaXQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindLong(QName varName, long value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            XQItem item = connection.createItemFromLong(value, type);
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
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
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an ZorbaXQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an ZorbaXQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindNode(QName varName, Node value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            XQItem item = connection.createItemFromNode(value, type);
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
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
   * @throw XQException - if (1) the varName or value argument is null, (2) the conversion of the value to an XDM instance failed, (3) in case of an ZorbaXQPreparedExpression, the dynamic type of the bound value is not compatible with the static type of the variable, (4) in case of an ZorbaXQPreparedExpression, the variable is not defined in the prolog of the expression, or (5) if the expression is in a closed state
   */
    @Override
    public void bindShort(QName varName, short value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(varName);
        if (!isExternal(varName.getLocalPart())) {
            throw new XQException ("The bound variable must be declared external in the prepared expression.");
        }
        try {
            XQItem item = connection.createItemFromShort(value, type);
            dynamicContext.setVariable(varName.getLocalPart(), ((org.zorbaxquery.api.xqj.ZorbaXQItem)item).getZorbaItem());
            itemsBounded.add(varName.getLocalPart());
        } catch (Exception e) {
            throw new XQException ("Error binding object: " + e.getLocalizedMessage());
        }
    }

    private void isClosedXQException() throws XQException {
        if (closed) {
            throw new XQException("This prepared expression is closed");
        }
    }
    private void isNullXQException(Object value) throws XQException {
        if (value==null) {
            throw new XQException("Parameter shouldn't be null");
        }
    }
    
}
