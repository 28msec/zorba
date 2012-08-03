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
import java.math.BigDecimal;
import java.math.BigInteger;
import java.net.URI;
import java.nio.CharBuffer;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.Properties;
import javax.xml.datatype.DatatypeConstants;
import javax.xml.datatype.Duration;
import javax.xml.datatype.XMLGregorianCalendar;
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
import org.w3c.dom.*;
import org.zorbaxquery.api.*;

  /**
   * 
   * A connection (session) with a specific XQuery engine. Connections are obtained through an ZorbaXQDataSource object.
   * 
   * XQuery expressions are executed and results are returned within the context of a connection. They are either executed through ZorbaXQExpression or ZorbaXQPreparedExpression objects.
   * 
   *   ZorbaXQDataSource ds;// obtain the XQuery datasource
   *   ... 
   *   ZorbaXQConnection conn = ds.getConnection();
   * 
   *   ZorbaXQPreparedExpression expr = conn.prepareExpression("for $i in ...");
   *   XQResultSequence result = expr.executeQuery();
   *   // - or - 
   *   ZorbaXQExpression expr = conn.createExpression();
   *   ZorbaXQSequence result = expr.executeQuery("for $i in..");
   * 
   *   // The sequence can now be iterated 
   *   while (result.next())
   *   { 
   *      String str  = result.getItemAsString();
   *      System.out.println(" output "+ str);
   *   }
   *   result.close();
   *   expr.close(); 
   *   conn.close();  // close the connection and free all resources..
   * 
   * 
   * A connection holds also default values for ZorbaXQExpression and ZorbaXQPreparedExpression properties. An application can override these defaults by passing an ZorbaXQStaticContext object to the setStaticContext() method.
   * 
   */
public class ZorbaXQConnection implements javax.xml.xquery.XQConnection {
    private InMemoryStore store;
    private Zorba zorba;
    private boolean autocommit;
    private boolean closed;
    private Collection<XQExpression> cExpression;
    private Collection<XQPreparedExpression> cPreparedExpression;
    private Collection<XQMetaData> cMetadata;
    private XQStaticContext lStaticContext;
    private ZorbaXQXmlDataManager lXmlDataManager;
    private Properties properties;
    private StringVector uriPaths;
    private StringVector libPaths;
    private StringVector modulePaths;
    
    protected Zorba getZorbaInstance() throws XQException {
        if (zorba!=null) {
            return zorba;
        } else {
            throw new XQException("Error returning Zorba Instance");
        }
    }
    public ZorbaXQConnection() {
        cExpression = new ArrayList<XQExpression>();
        cPreparedExpression = new ArrayList<XQPreparedExpression>();
        store = InMemoryStore.getInstance();
        zorba = Zorba.getInstance ( store );
        autocommit = true;
        closed = false;
    }
    public ZorbaXQConnection(Properties aProperties) {
        cExpression = new ArrayList<XQExpression>();
        cPreparedExpression = new ArrayList<XQPreparedExpression>();
        store = InMemoryStore.getInstance();
        zorba = Zorba.getInstance ( store );
        autocommit = true;
        closed = false;
        properties = aProperties;
        for (String prop :properties.stringPropertyNames()) {
            if (prop.equalsIgnoreCase(ZorbaXQDataSource.ZORBA_PROPERTIES_URI_PATHS)) {
                String[] paths = properties.getProperty(prop).split("[;,]");
                uriPaths = new StringVector();
                for (String path: paths) {
                    uriPaths.add(path);
                }
            }
            if (prop.equalsIgnoreCase(ZorbaXQDataSource.ZORBA_PROPERTIES_LIB_PATHS)) {
                String[] paths = properties.getProperty(prop).split("[;,]");
                libPaths = new StringVector();
                for (String path: paths) {
                    libPaths.add(path);
                }
            }
            if (prop.equalsIgnoreCase(ZorbaXQDataSource.ZORBA_PROPERTIES_MODULE_PATHS)) {
                String[] paths = properties.getProperty(prop).split("[;,]");
                modulePaths = new StringVector();
                for (String path: paths) {
                    modulePaths.add(path);
                }
            }
        }
        lStaticContext = new org.zorbaxquery.api.xqj.ZorbaXQStaticContext(zorba);
        if (uriPaths!=null) {
            ((org.zorbaxquery.api.xqj.ZorbaXQStaticContext)lStaticContext).setURIPaths(uriPaths);
        }
        if (libPaths!=null) {
            ((org.zorbaxquery.api.xqj.ZorbaXQStaticContext)lStaticContext).setLIBPaths(libPaths);
        }
        if (modulePaths!=null) {
            ((org.zorbaxquery.api.xqj.ZorbaXQStaticContext)lStaticContext).setMODPaths(modulePaths);
        }
        
    }
    
  /** \brief Closes the connection.
   * 
   * Closes the connection. This also closes any ZorbaXQExpression and ZorbaXQPreparedExpression obtained from this connection. Once the connection is closed, no method other than close or the isClosed method may be called on the connection object. Calling close on an ZorbaXQConnection object that is already closed has no effect. Note that an XQJ driver is not required to provide finalizer methods for the connection and other objects. Hence it is strongly recommended that users call this method explicitly to free any resources. It is also recommended that they do so under a final block to ensure that the object is closed even when there are exceptions.
   * 
   * @throw XQException - if there is an error during closing the connection.
   */
    @Override
    public void close() throws XQException {
        if (closed) return; // already closed
        try {
            for (XQExpression exp : cExpression ){
                exp.close();  // Notify the dependents objects to close
            }
            for (XQPreparedExpression exp : cPreparedExpression ){
                exp.close();  // Notify the dependents objects to close
            }
        } catch (XQException e) {
            throw new XQException("Error closing connection: " + e.getLocalizedMessage());
        }

        if (lStaticContext != null ) {
            ((org.zorbaxquery.api.xqj.ZorbaXQStaticContext)lStaticContext).getZorbaStaticContext().destroy();
        }
        if (lXmlDataManager != null) {
            lXmlDataManager.close();
        }
        zorba.shutdown();
        InMemoryStore.shutdown ( store );
        closed = true;
    }
    
    public ZorbaXQXmlDataManager getXmlDataManager() {
        if (lXmlDataManager==null) {
            lXmlDataManager = new ZorbaXQXmlDataManager(zorba);
        }
        return lXmlDataManager;
    }

    @Override
    public void setAutoCommit(boolean bln) throws XQException {
        isClosedXQException();
        autocommit = bln;
    }

  /** \brief Gets the auto-commit attribute of this connection
   * 
   * @return the auto-commit attribute of this connection. true if the connection operates in auto-commit mode; otherwise false
   * @throw XQException - if the connection is in a closed state
   */
    @Override
    public boolean getAutoCommit() throws XQException {
        isClosedXQException();
        return autocommit;
    }

  /** \brief Makes all changes made in the current transaction permanent and releases any locks held by the datasource.
   * 
   * This method should be used only when auto-commit mode is disabled. Any XQResultSequence, or XQResultItem may be implicitly closed upon commit, if the holdability property of the sequence is set to XQConstants.HOLDTYPE_CLOSE_CURSORS_AT_COMMIT.
   * 
   * @throw XQException - if the connection is in a closed state or this connection is operating in auto-commit mode
   */
    @Override
    public void commit() throws XQException {
        isClosedXQException();
        throw new UnsupportedOperationException("Zorba does not support transactions... yet...");
    }

  /** \brief Creates a new ZorbaXQExpression object that can be used to perform execute immediate operations with XQuery expressions.
   * 
   * The properties of the connection's default ZorbaXQStaticContext are copied to the returned ZorbaXQExpression.
   * 
   * @return ZorbaXQExpression that can be used to execute multiple expressions
   * @throw XQException - if the connection is in a closed state
   */
    @Override
    public XQExpression createExpression() throws XQException {
        isClosedXQException();
        XQExpression expression;
        if (lStaticContext == null) {
            expression = new org.zorbaxquery.api.xqj.ZorbaXQExpression(this);
        } else {
            expression = new org.zorbaxquery.api.xqj.ZorbaXQExpression(this, lStaticContext);
        }
        cExpression.add(expression);
        return expression;
    }

  /** \brief Creates a new ZorbaXQExpression object that can be used to perform execute immediate operations with XQuery expressions.
   * 
   * The properties of the specified ZorbaXQStaticContext values are copied to the returned ZorbaXQExpression.
   * 
   * @param value - ZorbaXQStaticContext containing values of expression properties
   * @return ZorbaXQExpression that can be used to execute multiple expressions
   * @throw XQException - if (1) the connection is in a closed state, or (2) the specified argument is null
   */
    @Override
    public XQExpression createExpression(XQStaticContext value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        XQExpression expression = new org.zorbaxquery.api.xqj.ZorbaXQExpression(this, value);
        cExpression.add(expression);
        return expression;
    }

  /** \brief Gets the metadata for this connection.
   * 
   * @return XQMetadata representing the metadata of this connection
   * @throw XQException - if the connection is in a closed state
   */
    @Override
    public XQMetaData getMetaData() throws XQException {
        isClosedXQException();
        return new org.zorbaxquery.api.xqj.ZorbaXQMetaData(this);
    }

  /** \brief Checks if the connection is closed.
   * 
   * @return true if the connection is in a closed state, false otherwise
   */
    @Override
    public boolean isClosed() {
        return closed;
    }

  /** \brief Prepares an expression for execution.
   * 
   * The properties of the connection's default ZorbaXQStaticContext are copied to the returned ZorbaXQPreparedExpression.
   * 
   * @param value - the XQuery expression as a String. Cannot be null
   * @return the prepared XQuery expression
   * @throw XQException - if (1) the connection is in a closed state, (2) there are errors preparing the expression, or (3) the xquery parameter is null
   */
    @Override
    public XQPreparedExpression prepareExpression(String value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        XQPreparedExpression expression;
        try {
            if (lStaticContext == null) {
                expression = new org.zorbaxquery.api.xqj.ZorbaXQPreparedExpression(this, value);
            } else {
                expression = new org.zorbaxquery.api.xqj.ZorbaXQPreparedExpression(this, value, lStaticContext);
            }
            cPreparedExpression.add(expression);
        } catch (Exception e) {
          throw new XQException("Error preparing expression: "+e.getLocalizedMessage());
        }
        return expression;
    }

  /** \brief Prepares an expression for execution.
   * 
   * The properties of the connection's default ZorbaXQStaticContext are copied to the returned ZorbaXQPreparedExpression.
   * 
   * @param string - the XQuery expression as a String. Cannot be null
   * @param xqsc - ZorbaXQStaticContext containing values of expression properties.
   * @return the prepared XQuery expression
   * @throw XQException - if (1) the connection is in a closed state, (2) there are errors preparing the expression, or (3) the xquery parameter is null
   */
    @Override
    public XQPreparedExpression prepareExpression(String string, XQStaticContext xqsc) throws XQException {
        isClosedXQException();
        isNullXQException(string);
        isNullXQException(xqsc);
        XQPreparedExpression expression = null;
        try {
            expression = new org.zorbaxquery.api.xqj.ZorbaXQPreparedExpression(this, string, xqsc);
            cPreparedExpression.add(expression);
        } catch (Exception e) {
          throw new XQException("Error preparing expression");
        }
        return expression;
    }

  /** \brief Prepares an expression for execution.
   * 
   * The properties of the connection's default ZorbaXQStaticContext are copied to the returned ZorbaXQPreparedExpression.
   * 
   * @param reader - the XQuery expression as a Reader. Cannot be null
   * @return the prepared XQuery expression
   * @throw XQException - if (1) the connection is in a closed state, (2) there are errors preparing the expression, or (3) the xquery parameter is null
   */
    @Override
    public XQPreparedExpression prepareExpression(Reader reader) throws XQException {
        isClosedXQException();
        isNullXQException(reader);
        
        XQPreparedExpression expression;
        if (lStaticContext == null) {
            expression = new org.zorbaxquery.api.xqj.ZorbaXQPreparedExpression(this, reader);
        } else {
            expression = new org.zorbaxquery.api.xqj.ZorbaXQPreparedExpression(this, reader, lStaticContext);
        }
        cPreparedExpression.add(expression);
        return expression;
    }

  /** \brief Prepares an expression for execution.
   * 
   * The properties of the connection's default ZorbaXQStaticContext are copied to the returned ZorbaXQPreparedExpression.
   * 
   * @param reader - the XQuery expression as a Reader. Cannot be null
   * @param xqsc - ZorbaXQStaticContext containing values of expression properties
   * @return the prepared XQuery expression
   * @throw XQException - if (1) the connection is in a closed state, (2) there are errors preparing the expression, or (3) the xquery parameter is null
   */
    @Override
    public XQPreparedExpression prepareExpression(Reader reader, XQStaticContext xqsc) throws XQException {
        isClosedXQException();
        isNullXQException(reader);
        isNullXQException(xqsc);

        XQPreparedExpression expression = new org.zorbaxquery.api.xqj.ZorbaXQPreparedExpression(this, reader, xqsc);
        
        cPreparedExpression.add(expression);
        return expression;
    }

  /** \brief Prepares an expression for execution.
   * 
   * The properties of the connection's default ZorbaXQStaticContext are copied to the returned ZorbaXQPreparedExpression.
   * 
   * @param in - the XQuery expression as an InputStream. Cannot be null
   * @return the prepared XQuery expression
   * @throw XQException - if (1) the connection is in a closed state, (2) there are errors preparing the expression, or (3) the xquery parameter is null
   */
    @Override
    public XQPreparedExpression prepareExpression(InputStream in) throws XQException {
        isClosedXQException();
        isNullXQException(in);

        XQPreparedExpression expression;
        if (lStaticContext == null) {
            expression = new org.zorbaxquery.api.xqj.ZorbaXQPreparedExpression(this, in);
        } else {
            expression = new org.zorbaxquery.api.xqj.ZorbaXQPreparedExpression(this, in, lStaticContext);
        }
        try {
            cPreparedExpression.add(expression);
        } catch (Exception ex) {
            throw new XQException("Error preparing expression" + ex.getLocalizedMessage());
        }
            
        return expression;
    }

  /** \brief Prepares an expression for execution.
   * 
   * The properties of the connection's default ZorbaXQStaticContext are copied to the returned ZorbaXQPreparedExpression.
   * 
   * @param in - the XQuery expression as an InputStream. Cannot be null
   * @param xqsc - ZorbaXQStaticContext containing values of expression properties
   * @return the prepared XQuery expression
   * @throw XQException - if (1) the connection is in a closed state, (2) there are errors preparing the expression, or (3) the xquery parameter is null
   */
    @Override
    public XQPreparedExpression prepareExpression(InputStream in, XQStaticContext xqsc) throws XQException {
        isClosedXQException();
        isNullXQException(in);
        isNullXQException(xqsc);
        
        XQPreparedExpression expression = null;
        try {
            expression = new org.zorbaxquery.api.xqj.ZorbaXQPreparedExpression(this, in, xqsc);
            cPreparedExpression.add(expression);
        } catch (Exception ex) {
            throw new XQException("Error preparing expression" + ex.getLocalizedMessage());
        }
        return expression;
    }

  /** \brief Undoes all changes made in the current transaction and releases any locks held by the datasource.
   * 
   * This method should be used only when auto-commit mode is disabled.
   * 
   * @throw XQException - if the connection is in a closed state or this connection is operating in auto-commit mode
   */
    @Override
    public void rollback() throws XQException {
        throw new UnsupportedOperationException("Zorba does not support transactions... yet...");
    }

  /** \brief Gets an ZorbaXQStaticContext representing the default values for all expression properties.
   * 
   * In order to modify the defaults, it is not sufficient to modify the values in the returned ZorbaXQStaticContext object; in addition setStaticContext should be called to make those new values effective.
   * 
   * @return ZorbaXQStaticContext representing the default values for all expression properties
   * @throw XQException - if the connection is in a closed state
   */
    @Override
    public XQStaticContext getStaticContext() throws XQException {
        isClosedXQException();
        lStaticContext = new org.zorbaxquery.api.xqj.ZorbaXQStaticContext(zorba);
        if (uriPaths!=null) {
            ((org.zorbaxquery.api.xqj.ZorbaXQStaticContext)lStaticContext).setURIPaths(uriPaths);
        }
        if (libPaths!=null) {
            ((org.zorbaxquery.api.xqj.ZorbaXQStaticContext)lStaticContext).setLIBPaths(libPaths);
        }
        if (modulePaths!=null) {
            ((org.zorbaxquery.api.xqj.ZorbaXQStaticContext)lStaticContext).setMODPaths(modulePaths);
        }
        return lStaticContext;
    }

  /** \brief Sets the default values for all expression properties.
   * 
   * The implementation will read out all expression properties from the specified ZorbaXQStaticContext and update its private copy.
   * 
   * @param xqsc - ZorbaXQStaticContext containing values of expression properties
   * @throw XQException - if the connection is in a closed state
   */
    @Override
    public void setStaticContext(XQStaticContext xqsc) throws XQException {
        isClosedXQException();
        isNullXQException(xqsc);
        if ((lStaticContext!=null) && (lStaticContext!=xqsc)) {  // delete previous static context
            ((org.zorbaxquery.api.xqj.ZorbaXQStaticContext)lStaticContext).getZorbaStaticContext().delete();
        }
        lStaticContext = xqsc;
    }

  /** \brief Creates an item from a given value.
   * 
   * The value is converted into an instance of the specified type according to the casting from xs:string rules outlined in 17.1.1 Casting from xs:string and xs:untypedAtomic, XQuery 1.0 and XPath 2.0 Functions and Operators. If the cast fails an XQException is thrown.
   * 
   * @param value - the lexical string value of the type
   * @param type - the item type
   * @return ZorbaXQItem representing the resulting item
   * @throw XQException - if (1) any of the arguments are null, (2) given type is not an atomic type, (3) the conversion of the value to an XDM instance failed, or (4) the underlying object implementing the interface is closed
   */
    @Override
    public XQItem createItemFromAtomicValue(String value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        isNullXQException(type);
        if (type.getItemKind()!=XQItemType.XQITEMKIND_ATOMIC) {
            throw new XQException("ItemType is not Atomic");
        }
        XQItem item = null;
        try {
            item = this.createItemFromString(value, type);
        } catch (Exception e) {
            throw new XQException("Error creating item of this type " + e.getLocalizedMessage());
        }
        return item;
    }

  /** \brief Creates an item from a given value.
   * 
   * The value is converted into an instance of the specified type, which must represent an xs:string or a type derived by restriction from xs:string. If the specified type is null, it defaults to xs:string.
   * Subsequently the value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the conversion fails, an XQException will be thrown.
   * 
   * @param value - the value to be converted, cannot be null
   * @param type - the type of the value to be bound to the external variable. The default type, xs:string, is used in case null is specified
   * @return ZorbaXQItem representing the resulting item
   * @throw XQException - if (1) the value argument is null, (2) the conversion of the value to an XDM instance failed, or (3) the underlying object implementing the interface is closed
   */
    @Override
    public XQItem createItemFromString(String value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        if (type==null) {
            type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_STRING);
        }
        ItemFactory itemFactory = zorba.getItemFactory();
        XQItem item = null;
        try {
            switch (type.getBaseType()) {
            case XQItemType.XQBASETYPE_BOOLEAN:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createBoolean(Boolean.parseBoolean(value)), type);
                break;
            case XQItemType.XQBASETYPE_ANYURI:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createAnyURI(value), type);
                break;
            case XQItemType.XQBASETYPE_BASE64BINARY:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createBase64Binary(value, value.length()), type);
                break;
            case XQItemType.XQBASETYPE_BYTE:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createByte(value.charAt(0)), type);
                break;
            case XQItemType.XQBASETYPE_DATE:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDate(value), type);
                break;
            case XQItemType.XQBASETYPE_DATETIME:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDateTime(value), type);
                break;
            case XQItemType.XQBASETYPE_DAYTIMEDURATION:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDuration(value), type);
                break;
            case XQItemType.XQBASETYPE_DECIMAL:
                BigDecimal dec = new BigDecimal(value);
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDecimal(value), type);
                break;
            case XQItemType.XQBASETYPE_DOUBLE:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDouble(Double.parseDouble(value)), type);
                break;
            case XQItemType.XQBASETYPE_DURATION:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDuration(value), type);
                break;
            case XQItemType.XQBASETYPE_FLOAT:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createFloat(value), type);
                break;
            case XQItemType.XQBASETYPE_GDAY:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createGDay(value), type);
                break;
            case XQItemType.XQBASETYPE_GMONTH:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createGMonth(value), type);
                break;
            case XQItemType.XQBASETYPE_GMONTHDAY:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createGMonthDay(value), type);
                break;
            case XQItemType.XQBASETYPE_GYEAR:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createGYear(value), type);
                break;
            case XQItemType.XQBASETYPE_GYEARMONTH:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createGYearMonth(value), type);
                break;
            case XQItemType.XQBASETYPE_HEXBINARY:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createHexBinary(value, value.length()), type);
                break;
            case XQItemType.XQBASETYPE_INT:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createInt(Integer.parseInt(value)), type);
                break;
            case XQItemType.XQBASETYPE_INTEGER:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createInteger(Integer.parseInt(value)), type);
                break;
            case XQItemType.XQBASETYPE_LONG:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createLong(Long.parseLong(value)), type);
                break;
            case XQItemType.XQBASETYPE_NCNAME:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createNCName(value), type);
                break;
            case XQItemType.XQBASETYPE_NEGATIVE_INTEGER:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createNegativeInteger(Long.parseLong(value)), type);
                break;
            case XQItemType.XQBASETYPE_NONNEGATIVE_INTEGER:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createNonNegativeInteger(new BigInteger(value)), type);
                break;
            case XQItemType.XQBASETYPE_NONPOSITIVE_INTEGER:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createNonPositiveInteger(Long.parseLong(value)), type);
                break;
            case XQItemType.XQBASETYPE_POSITIVE_INTEGER:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createPositiveInteger(new BigInteger(value)), type);
                break;
            case XQItemType.XQBASETYPE_QNAME:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createQName(type.getSchemaURI().toString(), value), type);
                break;
            case XQItemType.XQBASETYPE_SHORT:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createShort(Short.parseShort(value)), type);
                break;
            case XQItemType.XQBASETYPE_STRING:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createString(value), type);
                break;
            case XQItemType.XQBASETYPE_TIME:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createTime(value), type);
                break;
            case XQItemType.XQBASETYPE_UNSIGNED_BYTE:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createUnsignedByte(Short.parseShort(value)), type);
                break;
            case XQItemType.XQBASETYPE_UNSIGNED_INT:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createUnsignedInt(Long.parseLong(value)), type);
                break;
            case XQItemType.XQBASETYPE_UNSIGNED_LONG:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createUnsignedLong(new BigInteger(value)), type);
                break;
            case XQItemType.XQBASETYPE_UNSIGNED_SHORT:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createUnsignedShort(Integer.parseInt(value)), type);
                break;
            case XQItemType.XQBASETYPE_YEARMONTHDURATION:
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDuration(value), type);
                break;
            // TODO: revisit this posibilities
            case XQItemType.XQBASETYPE_ANYATOMICTYPE:
            case XQItemType.XQBASETYPE_ANYSIMPLETYPE:
            case XQItemType.XQBASETYPE_ENTITY:
            case XQItemType.XQBASETYPE_ENTITIES:
            case XQItemType.XQBASETYPE_ANYTYPE:
            case XQItemType.XQBASETYPE_LANGUAGE:
            case XQItemType.XQBASETYPE_ID:
            case XQItemType.XQBASETYPE_IDREF:
            case XQItemType.XQBASETYPE_IDREFS:
            case XQItemType.XQBASETYPE_NAME:
            case XQItemType.XQBASETYPE_NMTOKEN:
            case XQItemType.XQBASETYPE_NMTOKENS:
            case XQItemType.XQBASETYPE_NORMALIZED_STRING:
            case XQItemType.XQBASETYPE_NOTATION:
            case XQItemType.XQBASETYPE_TOKEN:
            case XQItemType.XQBASETYPE_UNTYPED:
            case XQItemType.XQBASETYPE_UNTYPEDATOMIC:
                throw new UnsupportedOperationException("Not supported yet.");
            default:
                
                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createString(value), type);
                break;
            }
        } catch (Exception e) {
            throw new XQException ("Error parsing value" + e.getLocalizedMessage());
        }
        return item;
    }

  /** \brief Creates an item from the given value.
   * 
   * If the value represents a well-formed XML document, it will be parsed and results in a document node. The kind of the input type must be null, XQITEMKIND_DOCUMENT_ELEMENT, or XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT. 
   * 
   * The value is converted into an instance of the specified type according to the rules defined in 14.3 Mapping a Java XML document to an XQuery document node, XQuery API for Java (XQJ) 1.0. 
   * 
   * If the value is not well formed, or if a kind of the input type other than the values list above is specified, behavior is implementation defined and may raise an exception.
   * 
   * @param value - the value to be converted, cannot be null
   * @param baseURI - an optional base URI, can be null. It can be used, for example, to resolve relative URIs and to include in error messages.
   * @param type - the type of the value for the created document node. If null is specified, it behaves as if XQDataFactory.createDocumentElementType( XQDataFactory.createElementType(null, ZorbaXQItemType.XQBASETYPE_XS_UNTYPED)) were passed in as the type parameter. That is, the type represents the XQuery sequence type document-node(element(*, xs:untyped))
   * @return ZorbaXQItem representing the resulting item
   * @throw XQException - if (1) the value argument is null, (2) the conversion of the value to an XDM instance failed, or (3) the underlying object implementing the interface is closed
   */
    @Override
    public XQItem createItemFromDocument(String value, String baseURI, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        if (type!=null) {
            if ( ! ((type.getItemKind()== XQItemType.XQITEMKIND_DOCUMENT_ELEMENT)||(type.getItemKind()== XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT)) ) {
                throw new XQException("Invalid type");
            }
        } else {
            type =  this.createElementType(null, XQItemType.XQBASETYPE_UNTYPED);
        }
        
        XmlDataManager dm = null;
        Item doc = null;
        XQItem item = null;
        try {
            dm = zorba.getXmlDataManager();
            doc = new Item();
            doc =  dm.parseXMLtoItem(value);
            item = new org.zorbaxquery.api.xqj.ZorbaXQItem(doc);
        } catch (Exception e) {
            throw new XQException("Error creating Item" + e.getLocalizedMessage());
        }
        return item;
    }

  /** \brief Creates an item from the given value.
   * 
   * If the value represents a well-formed XML document, it will be parsed and results in a document node. The kind of the input type must be null, XQITEMKIND_DOCUMENT_ELEMENT, or XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT. 
   * 
   * The value is converted into an instance of the specified type according to the rules defined in 14.3 Mapping a Java XML document to an XQuery document node, XQuery API for Java (XQJ) 1.0. 
   * 
   * If the value is not well formed, or if a kind of the input type other than the values list above is specified, behavior is implementation defined and may raise an exception.
   * 
   * @param value - the value to be converted, cannot be null
   * @param baseURI - an optional base URI, can be null. It can be used, for example, to resolve relative URIs and to include in error messages.
   * @param type - the type of the value for the created document node. If null is specified, it behaves as if XQDataFactory.createDocumentElementType( XQDataFactory.createElementType(null, ZorbaXQItemType.XQBASETYPE_XS_UNTYPED)) were passed in as the type parameter. That is, the type represents the XQuery sequence type document-node(element(*, xs:untyped))
   * @return ZorbaXQItem representing the resulting item
   * @throw XQException - if (1) the value argument is null, (2) the conversion of the value to an XDM instance failed, or (3) the underlying object implementing the interface is closed
   */
    @Override
    public XQItem createItemFromDocument(Reader value, String baseURI, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        if (type!=null) {
            if ( ! ((type.getItemKind()== XQItemType.XQITEMKIND_DOCUMENT_ELEMENT)||(type.getItemKind()== XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT)) ) {
                throw new XQException("Invalid type");
            }
        } else {
            type =  this.createElementType(null, XQItemType.XQBASETYPE_UNTYPED);
        }
        
        XmlDataManager dm = null;
        Item doc = null;
        XQItem item = null;
        try {
            dm = zorba.getXmlDataManager();
            doc = new Item();
            ReaderZorbaStream stream = new ReaderZorbaStream(value);
            doc =  dm.parseXMLtoItem(stream);
            item = new org.zorbaxquery.api.xqj.ZorbaXQItem(doc);
        } catch (Exception e) {
            throw new XQException("Error creating Item" + e.getLocalizedMessage());
        }
        return item;
    }

  /** \brief Creates an item from the given value.
   * 
   * If the value represents a well-formed XML document, it will be parsed and results in a document node. The kind of the input type must be null, XQITEMKIND_DOCUMENT_ELEMENT, or XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT. 
   * 
   * The value is converted into an instance of the specified type according to the rules defined in 14.3 Mapping a Java XML document to an XQuery document node, XQuery API for Java (XQJ) 1.0. 
   * 
   * If the value is not well formed, or if a kind of the input type other than the values list above is specified, behavior is implementation defined and may raise an exception.
   * 
   * @param value - the value to be converted, cannot be null
   * @param baseURI - an optional base URI, can be null. It can be used, for example, to resolve relative URIs and to include in error messages.
   * @param type - the type of the value for the created document node. If null is specified, it behaves as if XQDataFactory.createDocumentElementType( XQDataFactory.createElementType(null, ZorbaXQItemType.XQBASETYPE_XS_UNTYPED)) were passed in as the type parameter. That is, the type represents the XQuery sequence type document-node(element(*, xs:untyped))
   * @return ZorbaXQItem representing the resulting item
   * @throw XQException - if (1) the value argument is null, (2) the conversion of the value to an XDM instance failed, or (3) the underlying object implementing the interface is closed
   */
    @Override
    public XQItem createItemFromDocument(InputStream value, String baseURI, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        if (type!=null) {
            if ( ! ((type.getItemKind()== XQItemType.XQITEMKIND_DOCUMENT_ELEMENT)||(type.getItemKind()== XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT)) ) {
                throw new XQException("Invalid type");
            }
        } else {
            type =  this.createElementType(null, XQItemType.XQBASETYPE_UNTYPED);
        }
        
        XmlDataManager dm = null;
        Item doc = null;
        XQItem item = null;
        try {
            dm = zorba.getXmlDataManager();
            doc = new Item();
            InputZorbaStream stream = new InputZorbaStream(value);
            doc =  dm.parseXMLtoItem(stream);
            item = new org.zorbaxquery.api.xqj.ZorbaXQItem(doc);
        } catch (Exception e) {
            throw new XQException("Error creating Item" + e.getLocalizedMessage());
        }
        return item;
    }

  /** \brief Creates an item from the given value.
   * 
   * If the value represents a well-formed XML document, it will be parsed and results in a document node. The kind of the input type must be null, XQITEMKIND_DOCUMENT_ELEMENT, or XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT. 
   * 
   * The value is converted into an instance of the specified type according to the rules defined in 14.3 Mapping a Java XML document to an XQuery document node, XQuery API for Java (XQJ) 1.0. 
   * 
   * If the value is not well formed, or if a kind of the input type other than the values list above is specified, behavior is implementation defined and may raise an exception.
   * 
   * @param value - the value to be converted, cannot be null
   * @param type - the type of the value for the created document node. If null is specified, it behaves as if XQDataFactory.createDocumentElementType( XQDataFactory.createElementType(null, ZorbaXQItemType.XQBASETYPE_XS_UNTYPED)) were passed in as the type parameter. That is, the type represents the XQuery sequence type document-node(element(*, xs:untyped))
   * @return ZorbaXQItem representing the resulting item
   * @throw XQException - if (1) the value argument is null, (2) the conversion of the value to an XDM instance failed, or (3) the underlying object implementing the interface is closed
   */
    @Override
    public XQItem createItemFromDocument(XMLStreamReader value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
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
        XQItem item = createItemFromDocument(writer.toString(), "", type);
        return item;
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
    
  /** \brief Creates an item from the given value.
   * 
   * An XQJ implementation must at least support the following implementations:
   * - javax.xml.transform.dom.DOMSource
   * - javax.xml.transform.sax.SAXSource
   * - javax.xml.transform.stream.StreamSource
   * 
   * If the value represents a well-formed XML document, it will result in a document node. The kind of the input type must be null, XQITEMKIND_DOCUMENT_ELEMENT, or XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT. 
   * 
   * The value is converted into an instance of the specified type according to the rules defined in 14.3 Mapping a Java XML document to an XQuery document node, XQuery API for Java (XQJ) 1.0. 
   * 
   * If the value is not well formed, or if a kind of the input type other than the values list above is specified, behavior is implementation defined and may raise an exception.
   * 
   * @param value - the value to be converted, cannot be null
   * @param type - the type of the value for the created document node. If null is specified, it behaves as if XQDataFactory.createDocumentElementType( XQDataFactory.createElementType(null, ZorbaXQItemType.XQBASETYPE_XS_UNTYPED)) were passed in as the type parameter. That is, the type represents the XQuery sequence type document-node(element(*, xs:untyped))
   * @return ZorbaXQItem representing the resulting item
   * @throw XQException - if (1) the value argument is null, (2) the conversion of the value to an XDM instance failed, or (3) the underlying object implementing the interface is closed
   */
    @Override
    public XQItem createItemFromDocument(Source value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        XQItem item = null;
        if (value instanceof StreamSource) {
            item = createItemFromDocument(((StreamSource)value).getReader(), "", type);
        } else if (value instanceof SAXSource) {
            item = createItemFromDocument(((SAXSource)value).getInputSource().getByteStream(), "", type);
        } else if (value instanceof DOMSource) {
            item = createItemFromDocument( nodeToString(((DOMSource)value).getNode()), "", type);
        } else {
            throw new UnsupportedOperationException("Not supported yet.");
        }
        return item;
        
    }

  /** \brief Creates an item from a given value.
   * 
   * The value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the converstion fails, an XQException will be thrown.
   * 
   * @param value - the value to be converted
   * @param type - the type of the value to be bound to the external variable. The default type of the value is used in case null is specified
   * @return ZorbaXQItem representing the resulting item
   * @throw XQException - (1) the conversion of the value to an XDM instance failed, or (2) the underlying object implementing the interface is closed
   */
    @Override
    public XQItem createItemFromObject(Object value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        if (value instanceof XQItem) {
            return (XQItem)value;
        }
        
        ItemFactory itemFactory = zorba.getItemFactory();
        XQItem item = null;
        if (type==null) {
            
            if (value instanceof Boolean) {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_BOOLEAN);
            } else if (value instanceof Byte) {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_BYTE);
            } else if (value instanceof Float) {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_FLOAT);
            } else if (value instanceof Double) {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_DOUBLE);
            } else if (value instanceof Integer) {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_INT);
            } else if (value instanceof Long) {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_LONG);
            } else if (value instanceof Short) {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_SHORT);
            } else if (value instanceof String) {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_STRING);
            } else if (value instanceof BigDecimal) {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_DECIMAL);
            } else if (value instanceof BigInteger) {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_INTEGER);
            } else if (value instanceof Duration) {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_DURATION);
            } else if (value instanceof XMLGregorianCalendar) {
                QName schType = ((XMLGregorianCalendar)value).getXMLSchemaType();
                if (schType.equals(DatatypeConstants.GDAY)) {
                    type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_GDAY);
                } else if (schType.equals(DatatypeConstants.GMONTHDAY)) {
                    type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_GMONTHDAY);
                } else if (schType.equals(DatatypeConstants.GMONTH)) {
                    type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_GMONTH);
                } else if (schType.equals(DatatypeConstants.GYEAR)) {
                    type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_GYEAR);
                } else if (schType.equals(DatatypeConstants.GYEARMONTH)) {
                    type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_GYEARMONTH);
                } else if (schType.equals(DatatypeConstants.DATETIME)) {
                    type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_DATETIME);
                } else if (schType.equals(DatatypeConstants.DATE)) {
                    type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_DATE);
                } else if (schType.equals(DatatypeConstants.TIME)) {
                    type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_TIME);
                }
            } else if (value instanceof QName) {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_QNAME);
            } else if (value instanceof Document) {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_DOCUMENT);
            } else if (value instanceof DocumentFragment) {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_DOCUMENT);
            } else if (value instanceof Element){
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ELEMENT);
            } else if (value instanceof Attr) {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATTRIBUTE);
            } else if (value instanceof Comment) {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_COMMENT);
            } else if (value instanceof ProcessingInstruction) {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_PI);
            } else if (value instanceof Text) {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_TEXT);
            } else {
                type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC);
            }
        }
        try {
            switch (type.getItemKind()) {
                case XQItemType.XQITEMKIND_ATOMIC:
                    switch (type.getBaseType()) {
                    case XQItemType.XQBASETYPE_BOOLEAN:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createBoolean((Boolean)value), type);
                        break;
                    case XQItemType.XQBASETYPE_ANYURI:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createAnyURI(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_BASE64BINARY:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createBase64Binary(value.toString(), (value.toString()).length()), type);
                        break;
                    case XQItemType.XQBASETYPE_BYTE:
                        if (value instanceof Byte) {
                            byte tmpByte = ((Byte)value).byteValue();
                            item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createByte((char)tmpByte), type);
                        } else {
                            item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createByte((value.toString()).charAt(0)), type);
                        }
                        break;
                    case XQItemType.XQBASETYPE_DATE:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDate(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_DATETIME:
                        if (value.toString().contains(":")) {
                            item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDateTime(value.toString()), type);
                        } else {
                            item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDate(value.toString()), type);
                        }
                        break;
                    case XQItemType.XQBASETYPE_DAYTIMEDURATION:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDuration(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_DECIMAL:
                        if (value instanceof BigDecimal) {
                            item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDecimal(((BigDecimal)value).toPlainString()), type);
                        } else {
                            item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDecimal(value.toString()), type);
                        }
                        break;
                    case XQItemType.XQBASETYPE_DOUBLE:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDouble(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_DURATION:
                        if (value instanceof Duration) {
                            Duration duration = (Duration)value;
                            Boolean daytime = duration.isSet(DatatypeConstants.DAYS) || duration.isSet(DatatypeConstants.HOURS) || 
                                              duration.isSet(DatatypeConstants.MINUTES) || duration.isSet(DatatypeConstants.SECONDS);
                            Boolean yearmonth = duration.isSet(DatatypeConstants.YEARS) || duration.isSet(DatatypeConstants.MONTHS);
                            if (daytime && yearmonth){
                                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDuration(value.toString()), type);
                            } else if (yearmonth) {
                                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createYearMonthDuration(value.toString()), type);
                            } else if (daytime) {
                                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDayTimeDuration(value.toString()), type);
                            }
                        } else {
                            boolean yearMonth = value.toString().contains("Y") || value.toString().contains("M");
                            boolean dayTime = value.toString().contains("D") || value.toString().contains("T");
                            if (yearMonth && dayTime) {
                                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDuration(value.toString()), type);
                            } else if (yearMonth) {
                                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createYearMonthDuration(value.toString()), type);
                            } else if (dayTime) {
                                item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDayTimeDuration(value.toString()), type);
                            }
                        }
                        break;
                    case XQItemType.XQBASETYPE_FLOAT:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createFloat((Float)value), type);
                        break;
                    case XQItemType.XQBASETYPE_GDAY:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createGDay(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_GMONTH:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createGMonth(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_GMONTHDAY:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createGMonthDay(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_GYEAR:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createGYear(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_GYEARMONTH:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createGYearMonth(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_HEXBINARY:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createHexBinary(value.toString(), (value.toString()).length()), type);
                        break;
                    case XQItemType.XQBASETYPE_INT:
                    case XQItemType.XQBASETYPE_INTEGER:
                        if (value instanceof BigInteger) {
                            BigInteger val = (BigInteger)value;
                            item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createInteger(val.longValue()), type);
                        } else if (value instanceof Integer) {
                            item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createInt((Integer)value), type);
                        } else if (value instanceof String) {
                            item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createInteger(value.toString()), type);
                        } else {
                            throw new XQException ("Error parsing integer: " + value.toString());
                        }
                        break;
                    case XQItemType.XQBASETYPE_LONG:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createLong((Long)value), type);
                        break;
                    case XQItemType.XQBASETYPE_NCNAME:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createNCName(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_NEGATIVE_INTEGER:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createNegativeInteger((Long)value), type);
                        break;
                    case XQItemType.XQBASETYPE_NONNEGATIVE_INTEGER:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createNonNegativeInteger(new BigInteger(value.toString())), type);
                        break;
                    case XQItemType.XQBASETYPE_NONPOSITIVE_INTEGER:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createNonPositiveInteger((Long)value), type);
                        break;
                    case XQItemType.XQBASETYPE_POSITIVE_INTEGER:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createPositiveInteger(new BigInteger(value.toString())), type);
                        break;
                    case XQItemType.XQBASETYPE_QNAME:
                        if (value instanceof QName) {
                            QName qname =  (QName) value;
                            item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createQName(qname.getNamespaceURI(), qname.getPrefix(), qname.getLocalPart()), type);
                        } else if (value.toString().contains("{")) {
                            item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createQName(value.toString()), type);
                        } else {
                            item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createQName("", value.toString()), type);
                        }
                        break;
                    case XQItemType.XQBASETYPE_SHORT:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createShort((Short)value), type);
                        break;
                    case XQItemType.XQBASETYPE_STRING:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createString(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_TIME:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createTime(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_TOKEN:
                        break;
                    case XQItemType.XQBASETYPE_UNSIGNED_BYTE:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createUnsignedByte((Short)value), type);
                        break;
                    case XQItemType.XQBASETYPE_UNSIGNED_INT:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createUnsignedInt((Long)value), type);
                        break;
                    case XQItemType.XQBASETYPE_UNSIGNED_LONG:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createUnsignedLong(new BigInteger(value.toString())), type);
                        break;
                    case XQItemType.XQBASETYPE_UNSIGNED_SHORT:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createUnsignedShort((Integer)value), type);
                        break;
                    case XQItemType.XQBASETYPE_YEARMONTHDURATION:
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDuration(value.toString()), type);
                        break;
                    case XQItemType.XQBASETYPE_ANYATOMICTYPE:
                    case XQItemType.XQBASETYPE_ANYSIMPLETYPE:
                    case XQItemType.XQBASETYPE_ANYTYPE:
                    case XQItemType.XQBASETYPE_ENTITIES:
                    case XQItemType.XQBASETYPE_ENTITY:
                    case XQItemType.XQBASETYPE_ID:
                    case XQItemType.XQBASETYPE_IDREF:
                    case XQItemType.XQBASETYPE_IDREFS:
                    case XQItemType.XQBASETYPE_LANGUAGE:
                    case XQItemType.XQBASETYPE_NAME:
                    case XQItemType.XQBASETYPE_NMTOKEN:
                    case XQItemType.XQBASETYPE_NMTOKENS:
                    case XQItemType.XQBASETYPE_NORMALIZED_STRING:
                    case XQItemType.XQBASETYPE_NOTATION:
                    case XQItemType.XQBASETYPE_UNTYPED:
                    case XQItemType.XQBASETYPE_UNTYPEDATOMIC:
                        throw new XQException ("Base type not supported yet.");
                    default:
                        throw new XQException ("Unable to determine XQBASETYPE.");
                    }
                    break;
                case XQItemType.XQITEMKIND_ATTRIBUTE:
                    if (value instanceof Attr){
                        Attr attribute = (Attr) value;
                        Item iEmpty = new Item();
                        Item nodeName = itemFactory.createQName(attribute.getNamespaceURI()==null?"":attribute.getNamespaceURI(), 
                                                                attribute.getPrefix()==null?"":attribute.getPrefix(), 
                                                                attribute.getName()==null?"":attribute.getName());
                        Item nodeValue = null;
                        if (!attribute.getValue().isEmpty()) {
                            nodeValue = itemFactory.createQName(attribute.getNamespaceURI()==null?"":attribute.getNamespaceURI(), 
                                                                attribute.getPrefix()==null?"":attribute.getPrefix(), 
                                                                attribute.getValue()==null?"":attribute.getValue());
                        } else {
                            nodeValue = new Item();
                        }
                        //TODO: Rodolfo: use centralized constants instead of strings
                        Item iUntyped = itemFactory.createQName("http://www.w3.org/2001/XMLSchema", "xs", "untyped");
                        Item attributeNode = itemFactory.createAttributeNode(iEmpty, nodeName, iUntyped, nodeValue);
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(attributeNode, type);
                    }
                    break;
                case XQItemType.XQITEMKIND_COMMENT:
                    if (value instanceof Comment){
                        Comment comment = (Comment) value;
                        Item iEmpty = new Item();
                        Item elementNode = itemFactory.createCommentNode(iEmpty, comment.getTextContent());
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(elementNode, type);
                    } else {
                        Item iEmpty = new Item();
                        Item elementNode = itemFactory.createCommentNode(iEmpty, value.toString());
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(elementNode, type);
                    }
                    break;
                case XQItemType.XQITEMKIND_DOCUMENT:
                    if ((value instanceof Document) || (value instanceof DocumentFragment)){
                        DOMSource source = null;
                        if (value instanceof Document) {
                            source = new DOMSource((Document)value);
                        } else {
                            source = new DOMSource((DocumentFragment)value);
                        }

                        Transformer transformer = TransformerFactory.newInstance().newTransformer();
                        transformer.setOutputProperty(OutputKeys.OMIT_XML_DECLARATION, "yes");
                        StreamResult result = new StreamResult(new StringWriter());
                        
                        transformer.transform(source, result);
                        String xmlString = result.getWriter().toString();
                        Item tmpItem = new Item();
                        if (xmlString.length()>0) {
                            XmlDataManager dataManager = zorba.getXmlDataManager();
                            tmpItem = dataManager.parseXMLtoItem(xmlString);
                        } else {
                            tmpItem = itemFactory.createDocumentNode("", "");
                        }
                        
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(tmpItem, type);
                    }
                      
                    break;
                case XQItemType.XQITEMKIND_ELEMENT:
                    if (value instanceof Element){
                        Element element = (Element) value;
                        Item iEmpty = new Item();
                        Item nodeName = itemFactory.createQName(element.getNamespaceURI()==null?"":element.getNamespaceURI(), 
                                                                element.getPrefix()==null?"":element.getPrefix(), 
                                                                element.getNodeName()==null?"":element.getNodeName());
                        Item iUntyped = itemFactory.createQName("http://www.w3.org/2001/XMLSchema", "xs", "untyped");
                        Item elementNode = itemFactory.createElementNode(iEmpty, nodeName, iUntyped, false, false);
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(elementNode, type);
                    }
                    break;
                case XQItemType.XQITEMKIND_PI:
                    if (value instanceof ProcessingInstruction){
                        ProcessingInstruction pi = (ProcessingInstruction) value;
                        Item iEmpty = new Item();
                        Item elementNode = itemFactory.createPiNode(iEmpty, 
                                pi.getTarget(), 
                                pi.getTextContent(), 
                                pi.getBaseURI()==null?"":pi.getBaseURI());
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(elementNode, type);
                    }
                    break;
                case XQItemType.XQITEMKIND_TEXT:
                    if (value instanceof Text){
                        Text text = (Text) value;
                        Item iEmpty = new Item();
                        Item elementNode = itemFactory.createTextNode(iEmpty, text.getWholeText());
                        item = new org.zorbaxquery.api.xqj.ZorbaXQItem(elementNode, type);
                    }
                    break;
                case XQItemType.XQITEMKIND_DOCUMENT_ELEMENT:
                case XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT:
                case XQItemType.XQITEMKIND_ITEM:
                case XQItemType.XQITEMKIND_NODE:
                case XQItemType.XQITEMKIND_SCHEMA_ATTRIBUTE:
                case XQItemType.XQITEMKIND_SCHEMA_ELEMENT:
                    throw new XQException ("This item kind is currently unsupported.");
                default:
                    throw new XQException ("Unable to determine XQITEMKIND.");
            }
        } catch (Exception e) {
            throw new XQException ("Error parsing value" + e.getLocalizedMessage());
        }
        return item;
    }

    @Override
    public XQItem createItemFromBoolean(boolean bln, XQItemType type) throws XQException {
        isClosedXQException();
        if (type == null) {
            type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_BOOLEAN);
        }
        if (type.getBaseType() != XQItemType.XQBASETYPE_BOOLEAN) {
            throw new XQException("Type is not boolean, use proper method");
        }
        
        XQItem item = null;
        try {
            ItemFactory itemFactory = zorba.getItemFactory();
            item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createBoolean(bln));
        } catch (Exception e) {
            throw new XQException("Error creating new item");
        }
        return item;
    }

    private XQItem createDecimal(BigDecimal value, XQItemType type) throws XQException {
        XQItem item = null;
        try {
            ItemFactory itemFactory = zorba.getItemFactory();
            switch (type.getBaseType()) {
                case XQItemType.XQBASETYPE_BYTE:
                    item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createByte((char)value.byteValue()), type);
                    break;
                case XQItemType.XQBASETYPE_INTEGER:
                    item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createInteger(value.longValue()), type);
                    break;
                case XQItemType.XQBASETYPE_DECIMAL:
                    item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDecimalFromLong(value.longValue()), type);
                    break;
                case XQItemType.XQBASETYPE_INT:
                    item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createInt(value.intValue()), type);
                    break;
                case XQItemType.XQBASETYPE_LONG:
                    item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createLong(value.longValue()), type);
                    break;
                case XQItemType.XQBASETYPE_NEGATIVE_INTEGER:
                    item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createNegativeInteger(value.longValue()), type);
                    break;
                case XQItemType.XQBASETYPE_NONNEGATIVE_INTEGER:
                    item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createNonNegativeInteger(value.toBigInteger()), type);
                    break;
                case XQItemType.XQBASETYPE_NONPOSITIVE_INTEGER:
                    item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createNonPositiveInteger(value.longValue()), type);
                    break;
                case XQItemType.XQBASETYPE_POSITIVE_INTEGER:
                    item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createPositiveInteger(value.toBigInteger()), type);
                    break;
                case XQItemType.XQBASETYPE_SHORT:
                    item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createShort(value.shortValue()), type);
                    break;
                case XQItemType.XQBASETYPE_UNSIGNED_BYTE:
                    item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createUnsignedByte(value.shortValue()), type);
                    break;
                case XQItemType.XQBASETYPE_UNSIGNED_INT:
                    item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createUnsignedInt(value.longValue()), type);
                    break;
                case XQItemType.XQBASETYPE_UNSIGNED_LONG:
                    item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createUnsignedLong(value.toBigInteger()), type);
                    break;
                case XQItemType.XQBASETYPE_UNSIGNED_SHORT:
                    item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createShort(value.shortValue()), type);
                    break;
                default:
                    throw new XQException("Type is not xs:decimal or a derivate.");
            }
        } catch (Exception e) {
            throw new XQException("Error creating Item: " + e.getLocalizedMessage());
        }
        return item;
    }

  /** \brief Creates an item from a given value.
   * 
   * The value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the converstion fails, an XQException will be thrown.
   * 
   * @param b - the value to be converted
   * @param type - the type of the value to be bound to the external variable. The default type of the value is used in case null is specified
   * @return ZorbaXQItem representing the resulting item
   * @throw XQException - (1) the conversion of the value to an XDM instance failed, or (2) the underlying object implementing the interface is closed
   */
    @Override
    public XQItem createItemFromByte(byte b, XQItemType type) throws XQException {
        isClosedXQException();
        if (type == null) {
            type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_BYTE);
        }
        return createDecimal(new BigDecimal(b), type);
    }

  /** \brief Creates an item from a given value.
   * 
   * The value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the converstion fails, an XQException will be thrown.
   * 
   * @param value - the value to be converted
   * @param type - the type of the value to be bound to the external variable. The default type of the value is used in case null is specified
   * @return ZorbaXQItem representing the resulting item
   * @throw XQException - (1) the conversion of the value to an XDM instance failed, or (2) the underlying object implementing the interface is closed
   */
    @Override
    public XQItem createItemFromDouble(double value, XQItemType type) throws XQException {
        isClosedXQException();
        if (type == null) {
            type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_DOUBLE);
        }
        if (type.getBaseType() != XQItemType.XQBASETYPE_DOUBLE) {
            throw new XQException("Type is not double, use proper method");
        }
        XQItem item = null;
        try {
            ItemFactory itemFactory = zorba.getItemFactory();
            item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createDouble(value), type);
        } catch (Exception e) {
            throw new XQException("Error Creating Item From Double" + e.getLocalizedMessage());
        }
        return item;
    }

  /** \brief Creates an item from a given value.
   * 
   * The value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the converstion fails, an XQException will be thrown.
   * 
   * @param value - the value to be converted
   * @param type - the type of the value to be bound to the external variable. The default type of the value is used in case null is specified
   * @return ZorbaXQItem representing the resulting item
   * @throw XQException - (1) the conversion of the value to an XDM instance failed, or (2) the underlying object implementing the interface is closed
   */
    @Override
    public XQItem createItemFromFloat(float value, XQItemType type) throws XQException {
        isClosedXQException();
        if (type == null) {
            type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_FLOAT);
        }
        if (type.getBaseType() != XQItemType.XQBASETYPE_FLOAT) {
            throw new XQException("Type is not float, use proper method");
        }
        XQItem item = null;
        try {
            ItemFactory itemFactory = zorba.getItemFactory();
            item = new org.zorbaxquery.api.xqj.ZorbaXQItem(itemFactory.createFloat(value), type);
        } catch (Exception e) {
            throw new XQException("Error Creating Item From Float" + e.getLocalizedMessage());
        }
        return item;
    }

  /** \brief Creates an item from a given value.
   * 
   * The value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the converstion fails, an XQException will be thrown.
   * 
   * @param value - the value to be converted
   * @param type - the type of the value to be bound to the external variable. The default type of the value is used in case null is specified
   * @return ZorbaXQItem representing the resulting item
   * @throw XQException - (1) the conversion of the value to an XDM instance failed, or (2) the underlying object implementing the interface is closed
   */
    @Override
    public XQItem createItemFromInt(int value, XQItemType type) throws XQException {
        isClosedXQException();
        if (type == null) {
            type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_INT);
        }
        switch (type.getBaseType()) {
            case XQItemType.XQBASETYPE_BYTE:
            case XQItemType.XQBASETYPE_SHORT:
                throw new XQException("Can't downgrade the Base Type from an Int number");
            default:
                break;
        }
        return createDecimal(new BigDecimal(value), type);
    }

  /** \brief Creates an item from a given value.
   * 
   * The value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the converstion fails, an XQException will be thrown.
   * 
   * @param value - the value to be converted
   * @param type - the type of the value to be bound to the external variable. The default type of the value is used in case null is specified
   * @return ZorbaXQItem representing the resulting item
   * @throw XQException - (1) the conversion of the value to an XDM instance failed, or (2) the underlying object implementing the interface is closed
   */
    @Override
    public XQItem createItemFromLong(long value, XQItemType type) throws XQException {
        isClosedXQException();
        if (type == null) {
            type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_LONG);
        }
        switch (type.getBaseType()) {
            case XQItemType.XQBASETYPE_BYTE:
            case XQItemType.XQBASETYPE_SHORT:
            case XQItemType.XQBASETYPE_INT:
                throw new XQException("Can't downgrade the Base Type from an Long number");
            default:
                break;
        }
        return createDecimal(new BigDecimal(value), type);
    }

  /** \brief Creates an item from a given value.
   * 
   * The value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the converstion fails, an XQException will be thrown.
   * 
   * @param value - the value to be converted
   * @param type - the type of the value to be bound to the external variable. The default type of the value is used in case null is specified
   * @return ZorbaXQItem representing the resulting item
   * @throw XQException - (1) the conversion of the value to an XDM instance failed, or (2) the underlying object implementing the interface is closed
   */
    @Override
    public XQItem createItemFromNode(Node value, XQItemType type) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        
        XQItem result = null;
        try {
            result = createItemFromString(nodeToString(value), type);
        } catch( Exception e ) {
            throw new XQException("Error Creating Item From Node" + e.getLocalizedMessage());
        }
        return result;
    }

  /** \brief Creates an item from a given value.
   * 
   * The value is converted into an instance of the specified type according to the rule defined in 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the converstion fails, an XQException will be thrown.
   * 
   * @param value - the value to be converted
   * @param type - the type of the value to be bound to the external variable. The default type of the value is used in case null is specified
   * @return ZorbaXQItem representing the resulting item
   * @throw XQException - (1) the conversion of the value to an XDM instance failed, or (2) the underlying object implementing the interface is closed
   */
    @Override
    public XQItem createItemFromShort(short value, XQItemType type) throws XQException {
        isClosedXQException();
        if (type == null) {
            type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, XQItemType.XQBASETYPE_SHORT);
        }
        if (type.getBaseType()==XQItemType.XQBASETYPE_BYTE) {
            throw new XQException("Can't create a Byte from a Short number");
        }
        return createDecimal(new BigDecimal(value), type);
    }

  /** \brief Creates a copy of the specified ZorbaXQItem.
   * 
   * This method can be used, for example, to copy an XQResultItem object so that the new item is not dependant on the connection.
   * 
   * @param value - the ZorbaXQItem to copy
   * @return ZorbaXQItem independent of any underlying ZorbaXQConnection is created
   * @throw XQException - if (1) the specified item is null, (2) the underlying object implementing the interface is closed, (3) the specified item is closed
   */
    @Override
    public XQItem createItem(XQItem value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        if (value.isClosed()) {
            throw new XQException("Item is closed.");
        }
        XQItem result = new org.zorbaxquery.api.xqj.ZorbaXQItem(value);
        return result;
    }

  /** \brief Creates a copy of the specified ZorbaXQSequence.
   * 
   * Creates a copy of the specified ZorbaXQSequence. The newly created ZorbaXQSequence is scrollable and independent of any underlying ZorbaXQConnection. The new ZorbaXQSequence will contain all items from the specified ZorbaXQSequence starting from its current position. The copy process will implicitly perform next operations on the specified sequence to read the items. All items are consumed, the current position of the cursor is set to point after the last item.
   * 
   * @param value - input sequence
   * @return ZorbaXQSequence representing a copy of the input sequence
   * @throw XQException - if (1) there are errors accessing the items in the specified sequence, (2) the specified sequence is closed, (3) in the case of a forward only sequence, a get or write method has already been invoked on the current item, (4) the s parameter is null, or (5) the underlying object implementing the interface is closed
   */
    @Override
    public XQSequence createSequence(XQSequence value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        if (value.isClosed()) {
            throw new XQException("Sequence is closed.");
        }
        XQSequence result = null;
        try {
            result = new org.zorbaxquery.api.xqj.ZorbaXQSequence(value);
        } catch (Exception ex) {
            throw new XQException("Error creating sequence: " + ex.getLocalizedMessage());
        }
        return result;
    }

  /** \brief Creates an ZorbaXQSequence, containing all the items from the iterator.
   * 
   * The newly created ZorbaXQSequence is scrollable and independent of any underlying ZorbaXQConnection. If the iterator returns an ZorbaXQItem, it is added to the sequence. If the iterator returns any other object, an item is added to the sequence following the rules from 14.2 Mapping a Java Data Type to an XQuery Data Type, XQuery API for Java (XQJ) 1.0. If the iterator does not return any items, then an empty sequence is created.
   * 
   * @param value - input sequence
   * @return ZorbaXQSequence representing a copy of the input sequence
   * @throw XQException - if (1) there are errors accessing the items in the specified sequence, (2) the specified sequence is closed, (3) in the case of a forward only sequence, a get or write method has already been invoked on the current item, (4) the s parameter is null, or (5) the underlying object implementing the interface is closed
   */
    @Override
    public XQSequence createSequence(Iterator value) throws XQException {
        isClosedXQException();
        isNullXQException(value);
        XQSequence result = null;
        try {
            result = new org.zorbaxquery.api.xqj.ZorbaXQSequence(value);
        } catch (Exception ex) {
            throw new XQException("Error creating sequence: " + ex.getLocalizedMessage());
        }
        return result;
    }

  /** \brief Creates a new ZorbaXQItemType object representing an XQuery atomic type.
   * 
   * The item kind of the item type will be ZorbaXQItemType.XQITEMKIND_ATOMIC. 
   * Example -
   * \code{.java}
   *   ZorbaXQConnection conn = ...;
   * 
   *   // to create xs:integer item type
   *   conn.createAtomicType(ZorbaXQItemType.XQBASETYPE_INTEGER); 
   * \endcode
   * @param basetype - one of the ZorbaXQItemType.XQBASETYPE_* constants. All basetype constants except the following are valid:<br />ZorbaXQItemType.XQBASETYPE_UNTYPED<br />ZorbaXQItemType.XQBASETYPE_ANYTYPE<br />ZorbaXQItemType.XQBASETYPE_IDREFS<br />ZorbaXQItemType.XQBASETYPE_NMTOKENS<br />ZorbaXQItemType.XQBASETYPE_ENTITIES<br />ZorbaXQItemType.XQBASETYPE_ANYSIMPLETYPE<br />
   * @return a new ZorbaXQItemType representing the atomic type
   * @throw XQException - if (1) an invalid basetype value is passed in, or (2) the underlying object implementing the interface is closed
   */
    @Override
    public XQItemType createAtomicType(int basetype) throws XQException {
        isClosedXQException();
        if ((basetype==XQItemType.XQBASETYPE_UNTYPED) || 
            (basetype==XQItemType.XQBASETYPE_ANYTYPE) || 
            (basetype==XQItemType.XQBASETYPE_IDREFS) || 
            (basetype==XQItemType.XQBASETYPE_NMTOKENS) || 
            (basetype==XQItemType.XQBASETYPE_ENTITIES) || 
            (basetype==XQItemType.XQBASETYPE_ANYSIMPLETYPE)) {
            throw new XQException("Invalid base type.");
        }
        XQItemType type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, basetype);
        return type;
    }

  /** \brief Creates a new ZorbaXQItemType object representing an XQuery atomic type.
   * 
   * The item kind of the item type will be ZorbaXQItemType.XQITEMKIND_ATOMIC. 
   * Example -
   * \code{.java}
   *   ZorbaXQConnection conn = ...;
   * 
   *   // to create xs:integer item type
   *   conn.createAtomicType(ZorbaXQItemType.XQBASETYPE_INTEGER); 
   * \endcode
   * @param basetype - one of the ZorbaXQItemType.XQBASETYPE_* constants. All basetype constants except the following are valid:<br />ZorbaXQItemType.XQBASETYPE_UNTYPED<br />ZorbaXQItemType.XQBASETYPE_ANYTYPE<br />ZorbaXQItemType.XQBASETYPE_IDREFS<br />ZorbaXQItemType.XQBASETYPE_NMTOKENS<br />ZorbaXQItemType.XQBASETYPE_ENTITIES<br />ZorbaXQItemType.XQBASETYPE_ANYSIMPLETYPE<br />
   * @param qname - the QName of the type. If the QName refers to a predefinied type, it must match the basetype. Can be null
   * @param uri - the URI to the schema. Can be null. This can only be specified if the typename is also specified
   * @return a new ZorbaXQItemType representing the atomic type
   * @throw XQException - if (1) an invalid basetype value is passed in, or (2) the underlying object implementing the interface is closed
   */
    @Override
    public XQItemType createAtomicType(int basetype, QName qname, URI uri) throws XQException {
        if (closed) {
            throw new XQException("Object closed");
        }
        if ((basetype==XQItemType.XQBASETYPE_UNTYPED) || 
            (basetype==XQItemType.XQBASETYPE_ANYTYPE) || 
            (basetype==XQItemType.XQBASETYPE_IDREFS) || 
            (basetype==XQItemType.XQBASETYPE_NMTOKENS) || 
            (basetype==XQItemType.XQBASETYPE_ENTITIES) || 
            (basetype==XQItemType.XQBASETYPE_ANYSIMPLETYPE)) {
            throw new XQException("Invalid base type.");
        }
        XQItemType type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATOMIC, qname, basetype, uri);
        return type;
    }

  /** \brief Creates a new ZorbaXQItemType object representing the XQuery attribute(nodename, basetype) type with the given node name and base type.
   * 
   * This method can be used to create item type for attributes with a pre-defined schema type. 
   * 
   * Example -
   * \code{.java}
   *   ZorbaXQConnection conn = ..; // An XQuery connection
   * 
   *   - attribute() // no node name, pass null for the node name
   * 
   *     conn.createAttributeType(null, ZorbaXQItemType.XQBASETYPE_ANYSIMPLETYPE);
   * 
   *   - attribute (*)  // equivalent to attribute()
   * 
   *     conn.createAttributeType(null, ZorbaXQItemType.XQBASETYPE_ANYSIMPLETYPE);
   * 
   *   - attribute (person) // attribute of name person and any simple type.
   * 
   *     conn.createAttributeType(new QName("person"), ZorbaXQItemType.XQBASETYPE_ANYSIMPLETYPE); 
   * 
   *   - attribute(foo:bar) // node name foo:bar, type is any simple type
   * 
   *     conn.createAttributeType(new QName("http://www.foo.com", "bar","foo"), 
   *                              ZorbaXQItemType.XQBASETYPE_ANYSIMPLETYPE);
   * 
   *   - attribute(foo:bar, xs:integer) // node name foo:bar, type is xs:integer
   * 
   *     conn.createAttributeType(new QName("http://www.foo.com", "bar","foo"), 
   *                              ZorbaXQItemType.XQBASETYPE_INTEGER);
   * \endcode
   * @param nodename - specifies the name of the node.null indicates a wildcard for the node name
   * @param basetype - the base type of the attribute. One of the ZorbaXQItemType.XQBASETYPE_* other than ZorbaXQItemType.XQBASETYPE_UNTYPED or ZorbaXQItemType.XQBASETYPE_ANYTYPE
   * @return a new ZorbaXQItemType representing the XQuery attribute(nodename, basetype) type
   * @throw XQException - if (1) the underlying object implementing the interface is closed or (2) if the base type is one of: ZorbaXQItemType.XQBASETYPE_UNTYPED or ZorbaXQItemType.XQBASETYPE_ANYTYPE
   */
    @Override
    public XQItemType createAttributeType(QName nodename, int basetype) throws XQException {
        isClosedXQException();
        if ((basetype==XQItemType.XQBASETYPE_UNTYPED)||(basetype==XQItemType.XQBASETYPE_ANYTYPE)) {
            throw new XQException("Base Type can't be XQItemType.XQBASETYPE_UNTYPED or XQItemType.XQBASETYPE_ANYTYPE");
        }
        return new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATTRIBUTE, nodename, basetype);
    }

  /** \brief  Creates a new ZorbaXQItemType object representing the XQuery attribute(nodename, basetype) type with the given node name and base type.
   * 
   * The type name can reference either pre-defined simple types or user-defined simple types. 
   * 
   * Example -
   * \code{.java}
   *   ZorbaXQConnection conn = ..; // An XQuery connection
   * 
   *   - attribute (name, employeename) // attribute name of type employeename 
   *  
   *   conn.createAttributeType(new QName("name"), ZorbaXQItemType.XQBASETYPE_ANYSIMPLETYPE,
   *                            new QName("employeename"), null);
   *  
   *   - attribute (foo:bar, po:city) 
   *   where the prefix foo refers to the namespace http://www.foo.com and the
   *   prefix po refers to the namespace "http://www.address.com"
   * 
   *   conn.createAttributeType(new QName("http://www.foo.com", "bar","foo"), 
   *                            ZorbaXQItemType.XQBASETYPE_ANYSIMPLETYPE,
   *                            new QName("http://address.com", "address","po"), null);
   * 
   *   - attribute (zip, zipcode) // attribute zip of type zipchode which derives from
   *                              // xs:string 
   * 
   *   conn.createAttributeType(new QName("zip"), ZorbaXQItemType.XQBASETYPE_STRING,
   *                            new QName("zipcode"), null);
   * 
   *   - attribute(foo:bar, po:hatsize) 
   *   where the prefix foo refers to the namespace http://www.foo.com and the
   *   prefix po refers to the namespace "http://www.hatsizes.com" 
   *   with schema URI "http://hatschema.com"
   * 
   *   conn.createAttributeType(new QName("http://www.foo.com", "bar","foo"), 
   *                   ZorbaXQItemType.XQBASETYPE_INTEGER,
   *                   new QName("http://www.hatsizes.com", "hatsize","po"), 
   *                   new QName("http://hatschema.com"));
   * \endcode
   * @param nodename - specifies the name of the node.null indicates a wildcard for the node name
   * @param basetype - the base type of the attribute. One of the XQItemTyupe.XQBASETYPE_* constants other than ZorbaXQItemType.XQBASETYPE_UNTYPED or ZorbaXQItemType.XQBASETYPE_ANYTYPE
   * @param typename - the QName of the type. If the QName refers to a predefinied type, it must match the basetype. Can be null.
   * @param schemaURI - the URI to the schema. Can be null. This can only be specified if the typename is also specified
   * @return a new ZorbaXQItemType representing the XQuery attribute(nodename,basetype, typename,schemaURI) type.
   * @throw XQException - if (1) the underlying object implementing the interface is closed, (2) if the base type is one of: ZorbaXQItemType.XQBASETYPE_UNTYPED or ZorbaXQItemType.XQBASETYPE_ANYTYPE, (3) the schema URI is specified and the typename is not specified, (4) the implementation does not support user-defined XML schema types, or (5) if the typename refers to a predefinied type and does not match basetype
   */
    @Override
    public XQItemType createAttributeType(QName nodename, int basetype, QName typename, URI schemaURI) throws XQException {
        isClosedXQException();
        if ((basetype==XQItemType.XQBASETYPE_UNTYPED)||(basetype==XQItemType.XQBASETYPE_ANYTYPE)) {
            throw new XQException("Base Type can't be XQItemType.XQBASETYPE_UNTYPED or XQItemType.XQBASETYPE_ANYTYPE");
        }
        if ((schemaURI!=null) && (typename==null)) {
            throw new XQException("If Schema URI is specified, Base Type must be also specified");
        }
        return new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ATTRIBUTE, nodename, basetype, typename, schemaURI, true);
    }

  /** \brief Creates a new ZorbaXQItemType object representing the XQuery schema-attribute(nodename,basetype,schemaURI) type, with the given node name, base type, and schema URI.
   * 
   * Example -
   * \code{.java}
   *      ZorbaXQConnection conn = ..; // An XQuery connection
   * 
   *      - schema-attribute (name) // schema-attribute name, found in the schema 
   *                                // available at http://customerschema.com
   * 
   *      conn.createSchemaAttributeType(new QName("name"), 
   *                   ZorbaXQItemType.XQBASETYPE_STRING,
   *                   new URI(http://customerschema.com));
   *  \endcode
   * 
   * @param nodename - specifies the name of the node
   * @param basetype - the base type of the attribute. One of the XQItemTyupe.XQBASETYPE_* constants other than ZorbaXQItemType.XQBASETYPE_UNTYPED or ZorbaXQItemType.XQBASETYPE_ANYTYPE
   * @param uri - the URI to the schema. Can be null
   * @return a new ZorbaXQItemType representing the XQuery schema-attribute(nodename,basetype, schemaURI) type
   * @throw XQException - if (1) the node name is null, (2) if the base type is one of: ZorbaXQItemType.XQBASETYPE_UNTYPED or ZorbaXQItemType.XQBASETYPE_ANYTYPE, (3) the underlying object implementing the interface is closed, or (4) the implementation does not support user-defined XML schema types
   */
    @Override
    public XQItemType createSchemaAttributeType(QName nodename, int basetype, URI uri) throws XQException {
        isClosedXQException();
        return new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_SCHEMA_ATTRIBUTE, nodename, basetype, uri);
    }

  /** \brief Creates a new ZorbaXQItemType object representing the XQuery comment() type.
   * 
   * Creates a new ZorbaXQItemType object representing the XQuery comment() type. The ZorbaXQItemType object will have the item kind set to ZorbaXQItemType.XQITEMKIND_COMMENT. 
   * 
   * Example -
   * \code{.java}
   *   ZorbaXQConnection conn = ..; // An XQuery connection
   *   ZorbaXQItemType cmttype = conn.createCommentType(); 
   * 
   *   int itemkind = cmttype.getItemKind(); // will be ZorbaXQItemType.XQITEMKIND_COMMENT
   * 
   *   ZorbaXQExpression expr = conn.createExpression();
   *   ZorbaXQSequence result = expr.executeQuery("<!-- comments -->");
   * 
   *   result.next();
   *   boolean pi = result.instanceOf(cmttype);  // will be true
   * \endcode
   * 
   * @return a new ZorbaXQItemType representing the XQuery comment() type
   * @throw XQException - if the underlying object implementing the interface is closed
   */
    @Override
    public XQItemType createCommentType() throws XQException {
        isClosedXQException();
        return new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_COMMENT);
    }

  /** \brief Creates a new ZorbaXQItemType object representing the XQuery document-node(elementType) type containing a single element.
   * 
   * Creates a new ZorbaXQItemType object representing the XQuery document-node(elementType) type containing a single element. The ZorbaXQItemType object will have the item kind set to ZorbaXQItemType.XQITEMKIND_DOCUMENT_ELEMENT and the base type set to the item type of the input elementType.
   * 
   * @param elementType - an ZorbaXQItemType object representing an XQuery element() type, cannot be null
   * @return a new ZorbaXQItemType representing the XQuery document-node(elementType) type containing a single element
   * @throw XQException - if (1) the underlying object implementing the interface is closed or (2) the elementType has an item kind different from ZorbaXQItemType.XQITEMKIND_ELEMENT, (3) the elementType argument is null, or (4) the implementation does not support user-defined XML schema types
   */
    @Override
    public XQItemType createDocumentElementType(XQItemType elementType) throws XQException {
        isClosedXQException();
        isNullXQException(elementType);
        if (elementType.getItemKind()!=XQItemType.XQITEMKIND_ELEMENT) {
            throw new XQException("Item Kind must be XQItemType.XQITEMKIND_ELEMENT");
        }
        return new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_DOCUMENT_ELEMENT, elementType.getNodeName(), elementType.getBaseType(), elementType.getSchemaURI());
    }

  /** \brief Creates a new ZorbaXQItemType object representing the XQuery document-node(elementType) type containing a single schema-element(...).
   * 
   * The ZorbaXQItemType object will have the item kind set to ZorbaXQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT and the base type set to the item type of the input elementType.
   * 
   * @param elementType - an ZorbaXQItemType object representing an XQuery schema-element(...) type, cannot be null
   * @return a new ZorbaXQItemType representing the XQuery document-node(elementType) type containing a single schema-element(...) element
   * @throw XQException - if (1) the underlying object implementing the interface is closed or (2) the elementType has an item kind different from ZorbaXQItemType.XQITEMKIND_SCHEMA_ELEMENT, (3) the elementType argument is null, (4) the implementation does not support user-defined XML schema types
   */
    @Override
    public XQItemType createDocumentSchemaElementType(XQItemType elementType) throws XQException {
        isClosedXQException();
        if (elementType.getItemKind()!=XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT) {
            throw new XQException("Item Kind must be XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT");
        }
        return new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_DOCUMENT_ELEMENT, elementType.getNodeName(), elementType.getBaseType(), elementType.getSchemaURI());
    }

  /** \brief Creates a new ZorbaXQItemType object representing the XQuery document-node() type.
   * 
   * The ZorbaXQItemType object will have the item kind set to ZorbaXQItemType.XQITEMKIND_DOCUMENT.
   * 
   * @return a new ZorbaXQItemType representing the XQuery document-node() type
   * @throw XQException - if the underlying object implementing the interface is closed
   */
    @Override
    public XQItemType createDocumentType() throws XQException {
        isClosedXQException();
        return new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_DOCUMENT);
    }

  /** \brief Creates a new ZorbaXQItemType object representing the XQuery element(nodename, basetype) type, with the given node name and base type.
   * 
   * This method can be used to create item type for elements with a pre-defined schema type. 
   * 
   * Example -
   * \code{.java}
   *   ZorbaXQConnection conn = ..; // An XQuery connection
   *   - element() // no node name, pass null for the node name
   * 
   *   conn.createElementType(null, ZorbaXQItemType.XQBASETYPE_ANYTYPE);
   * 
   *   - element (*)  // equivalent to element()
   * 
   *   conn.createElementType(null, ZorbaXQItemType.XQBASETYPE_ANYTYPE);
   * 
   *   - element(person) // element of name person and any type.
   * 
   *   conn.createElementType(new QName("person"), ZorbaXQItemType.XQBASETYPE_ANYTYPE); 
   * 
   *   - element(foo:bar) // node name foo:bar, type is anytype
   * 
   *   conn.createElementType(new QName("http://www.foo.com", "bar","foo"), 
   *                          ZorbaXQItemType.XQBASETYPE_ANYTYPE);
   * 
   *   - element(foo:bar, xs:integer) // node name foo:bar, type is xs:integer
   * 
   *   conn.createElementType(new QName("http://www.foo.com", "bar","foo"), 
   *                          ZorbaXQItemType.XQBASETYPE_INTEGER);
   * \endcode
   * @param nodename - specifies the name of the node. null indicates a wildcard for the node name
   * @param baseType - the base type of the item. One of the ZorbaXQItemType.XQBASETYPE_* constants
   * @return a new ZorbaXQItemType representing the XQuery element(nodename, basetype) type
   * @throw XQException - if (1) the underlying object implementing the interface is closed
   */
    @Override
    public XQItemType createElementType(QName nodename, int baseType) throws XQException {
        isClosedXQException();
        XQItemType item = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ELEMENT, nodename, baseType);
        return item;
    }

  /** \brief Creates a new ZorbaXQItemType object representing the XQuery element(nodename,basetype,typename,schemaURI, allowNill) type, given the node name, base type, schema type name, schema URI, and nilled check.
   * 
   * The type name can reference either pre-defined schema types or user-defined types. 
   * 
   * Example -
   * \code{.java}
   *   ZorbaXQConnection conn = ..; // An XQuery connection
   * 
   *   - element (person, employee) // element person of type employee
   * 
   *   conn.createElementType(new QName("person"), ZorbaXQItemType.XQBASETYPE_ANYTYPE,
   *                          new QName("employee"), null ,false);
   *  
   *   - element(person, employee ? ) // element person of type employee, whose nilled 
   *                                  // property may be true or false. 
   *  
   *   conn.createElementType(new QName("person"), ZorbaXQItemType.XQBASETYPE_ANYTYPE,
   *                          new QName("employee"), null ,true);
   *  
   *   - element(foo:bar, po:address) 
   *   where the prefix foo refers to the namespace http://www.foo.com and the
   *   prefix po refers to the namespace "http://www.address.com"
   * 
   *   conn.createElementType(new QName("http://www.foo.com", "bar","foo"), 
   *                ZorbaXQItemType.XQBASETYPE_ANYTYPE,
   *                new QName("http://address.com", "address","po"), null, false);
   * 
   *   - element (zip, zipcode) // element zip of type zipchode which derives from
   *                            // xs:string 
   * 
   *   conn.createElementType(new QName("zip"), ZorbaXQItemType.XQBASETYPE_STRING,
   *                          new QName("zipcode"), null, false);
   * 
   *   - element (*, xs:anyType ?)
   * 
   *   conn.createElementType(null, ZorbaXQItemType.XQBASETYPE_ANYTYPE, null, null, true);
   * 
   *   - element(foo:bar, po:hatsize) 
   *   where the prefix foo refers to the namespace http://www.foo.com and the
   *   prefix po refers to the namespace "http://www.hatsizes.com" 
   *   with schema URI "http://hatschema.com"
   * 
   *   conn.createElementType(new QName("http://www.foo.com", "bar","foo"), 
   *                       ZorbaXQItemType.XQBASETYPE_INTEGER,
   *                       new QName("http://www.hatsizes.com", "hatsize","po"), 
   *                       new QName("http://hatschema.com"), false);
   * 
   * \endcode 
   * 
   * @param nodename - specifies the name of the element. null indicates a wildcard for the node name
   * @param baseType - the base type of the item. One of the ZorbaXQItemType.XQBASETYPE_* constants
   * @param typename - the QName of the type. If the QName refers to a predefinied type, it must match the basetype. Can be null
   * @param schemaURI - the URI to the schema. Can be null. This can only be specified if the typename is also specified
   * @param allowNill - the nilled property of the element
   * @return a new ZorbaXQItemType representing the XQuery element(nodename,basetype, typename,schemaURI, allowNill) type
   * @throw XQException - if (1) schemaURI is specified but the typename is not specified, (2) the underlying object implementing the interface is closed, (3) the implementation does not support user-defined XML schema types, or (4) if the typename refers to a predefinied type and does not match basetype
   */
    @Override
    public XQItemType createElementType(QName nodename, int baseType, QName typename, URI schemaURI, boolean allowNill) throws XQException {
        isClosedXQException();
        XQItemType item = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ELEMENT, nodename, baseType, typename, schemaURI, allowNill);
        return item;
    }

  /** \brief     Creates a new ZorbaXQItemType object representing the XQuery schema-element(nodename,basetype,schemaURI) type, given the node name, base type, and the schema URI.
   * 
   * Example -
   * \code{.java}
   *      ZorbaXQConnection conn = ..; // An XQuery connection
   * 
   *      - schema-element (customer) // schema-element person, found in
   *                                  // the schema available at http://customerschema.com
   * 
   *      conn.createElementType(new QName("customer"), ZorbaXQItemType.XQBASETYPE_ANYTYPE,
   *                          new URI("http://customerschema.com"));
   * \endcode
   * @param nodename - specifies the name of the element
   * @param baseType - the base type of the item. One of the ZorbaXQItemType.XQBASETYPE_* constants
   * @param schemaURI - the URI to the schema. Can be null
   * @return a new ZorbaXQItemType representing the XQuery schema-element(nodename,basetype, schemaURI) type
   * @throw XQException - if (1) the node name is null, (2) the underlying object implementing the interface is closed, or (3) the implementation does not support user-defined XML schema types
   */
    @Override
    public XQItemType createSchemaElementType(QName nodename, int baseType, URI schemaURI) throws XQException {
        isClosedXQException();
        XQItemType item = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_SCHEMA_ELEMENT, nodename, baseType, schemaURI);
        return item;
    }

  /** \brief Creates a new ZorbaXQItemType object representing the XQuery item type.
   * 
   * The ZorbaXQItemType object will have the item kind set to ZorbaXQItemType.XQITEMKIND_ITEM. 
   * 
   * Example -
   * \code{.java}
   *   ZorbaXQConnection conn = ..; // An XQuery connection
   *   ZorbaXQItemType typ = conn.createItemType(); // represents the XQuery item type "item()"
   * \endcode
   * @return a new ZorbaXQItemType representing the XQuery item type
   * @throw XQException - if the underlying object implementing the interface is closed
   */
    @Override
    public XQItemType createItemType() throws XQException {
        isClosedXQException();
        XQItemType type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_ITEM);
        return type;
    }

  /** \brief Creates a new ZorbaXQItemType object representing the XQuery node() type. 
   * 
   * The ZorbaXQItemType object will have the item kind set to ZorbaXQItemType.XQITEMKIND_NODE.
   * 
   * @return a new ZorbaXQItemType representing the XQuery node() type
   * @throw XQException - if the underlying object implementing the interface is closed
   */
    @Override
    public XQItemType createNodeType() throws XQException {
        isClosedXQException();
        XQItemType type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_NODE);
        return type;
    }

  /** \brief Creates a new ZorbaXQItemType object representing the XQuery processing-instruction(piTarget) type.
   * 
   * The ZorbaXQItemType object will have the item kind set to ZorbaXQItemType.XQITEMKIND_PI. A string literal can be passed to match the PITarget of the processing instruction as described in 2.5.4.2 Matching an Item Type and an Item, XQuery 1.0: An XML Query Language. 
   * 
   * Example -
   * \code{.java}
   *    ZorbaXQConnection conn = ..; // An XQuery connection
   *    ZorbaXQItemType anypi = conn.createProcessingInstructionType(); 
   *    ZorbaXQItemType foopi = conn.createProcessingInstructionType("foo-format");
   * 
   *    ZorbaXQExpression expr = conn.createExpression();
   *    ZorbaXQSequence result = expr.executeQuery("<?format role="output" ?>");
   *  
   *    result.next();
   *    boolean pi = result.instanceOf(anypi);  // will be true
   *    pi = result.instanceOf(foopi);  // will be false
   *  
   *    ZorbaXQExpression expr = conn.createExpression();
   *    ZorbaXQSequence result = expr.executeQuery("<?foo-format role="output" ?>");
   *    
   *    result.next();
   *    boolean pi = result.instanceOf(anypi);  // will be true
   *    pi = result.instanceOf(foopi);  // will be true 
   * \endcode
   * 
   * @param piTarget - the string literal to match the processing instruction's PITarget. A null string value will match all processing instruction nodes
   * @return a new ZorbaXQItemType representing the XQuery processing-instruction(piTarget) type
   * @throw XQException - if the underlying object implementing the interface is closed
   */
    @Override
    public XQItemType createProcessingInstructionType(String piTarget) throws XQException {
        isClosedXQException();
        XQItemType type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_PI, piTarget);
        return type;
    }

  /** \brief Creates a new sequence type from an item type and occurence indicator.
   * 
   * @param item - the item type. This parameter must be null if the occurance is ZorbaXQSequenceType.OCC_EMPTY, and cannot be null for any other occurance indicator
   * @param occurence - The occurence of the item type, must be one of ZorbaXQSequenceType.OCC_ZERO_OR_ONE, ZorbaXQSequenceType.OCC_EXACTLY_ONE, ZorbaXQSequenceType.OCC_ZERO_OR_MORE, ZorbaXQSequenceType.OCC_ONE_OR_MORE, ZorbaXQSequenceType.OCC_EMPTY
   * @return a new ZorbaXQSequenceType representing the type of a sequence
   * @throw XQException - if (1) the item is null and the occurance is not ZorbaXQSequenceType.OCC_EMPTY, (2) the item is not null and the occurance is ZorbaXQSequenceType.OCC_EMPTY, (3) the occurence is not one of: ZorbaXQSequenceType.OCC_ZERO_OR_ONE, ZorbaXQSequenceType.OCC_EXACTLY_ONE, ZorbaXQSequenceType.OCC_ZERO_OR_MORE, ZorbaXQSequenceType.OCC_ONE_OR_MORE, ZorbaXQSequenceType.OCC_EMPTY or (4) the underlying object implementing the interface is closed
   */
    @Override
    public XQSequenceType createSequenceType(XQItemType item, int occurence) throws XQException {
        isClosedXQException();
        if ( ((item==null) && (occurence != XQSequenceType.OCC_EMPTY)) || ((item!=null) && (occurence == XQSequenceType.OCC_EMPTY))) {
            throw new XQException("Item is null");
        }
        if (!((occurence ==  XQSequenceType.OCC_ZERO_OR_ONE) ||
            (occurence == XQSequenceType.OCC_EXACTLY_ONE) ||
            (occurence == XQSequenceType.OCC_ZERO_OR_MORE) ||
            (occurence == XQSequenceType.OCC_ONE_OR_MORE) ||
            (occurence == XQSequenceType.OCC_EMPTY))) {
            throw new XQException("Occurence must be from: OCC_ZERO_OR_ONE, OCC_EXACTLY_ONE, OCC_ZERO_OR_MORE, OCC_ONE_OR_MORE, OCC_EMPTY ");
        }
        
        XQSequenceType result = new org.zorbaxquery.api.xqj.ZorbaXQSequenceType(item, occurence);
        return result;
    }

  /** \brief Creates a new ZorbaXQItemType object representing the XQuery text() type.
   * 
   * The ZorbaXQItemType object will have the item kind set to ZorbaXQItemType.XQITEMKIND_TEXT.
   * 
   * @return a new ZorbaXQItemType representing the XQuery text() type
   * @throw XQException - if the underlying object implementing the interface is closed
   */
    @Override
    public XQItemType createTextType() throws XQException {
        isClosedXQException();
        XQItemType type = new org.zorbaxquery.api.xqj.ZorbaXQItemType(XQItemType.XQITEMKIND_TEXT);
        return type;
    }
    
    private void isClosedXQException() throws XQException {
        if (closed) {
            throw new XQException("This connection is closed");
        }
    }
    private void isNullXQException(Object value) throws XQException {
        if (value==null) {
            throw new XQException("Parameter shouldn't be null");
        }
    }
   
}
