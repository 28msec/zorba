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

import java.util.HashSet;
import java.util.Set;
import javax.xml.xquery.XQConnection;
import javax.xml.xquery.XQException;
import org.zorbaxquery.api.Zorba;

  /** 
   * XQMetaData class provides information about the data source, in various aspects, such as the product name and version identification, supported features, specific behaviors, user information, product limits and so forth. 
   * 
   * An object from this class is obtained from the connection object by calling the getMetaData() method, for example: 
   * \code{.java}
   *   XQMetaData metaData = connection.getMetaData();
   *   String productVersion = metaData.getProductVersion();
   *     ...
   * \endcode
   *  
   * Since the metadata object depends on the connection, all its methods would raise an exception if the connection it is created from is no longer valid.
   */
public class XQMetaData implements javax.xml.xquery.XQMetaData {
    
    private int XQJ_MAJOR = 1;
    private int XQJ_MINOR = 1;
    
    private XQConnection connection;
    private Zorba zorba;
    public XQMetaData(XQConnection conn) throws XQException {
        if (conn.isClosed()) {
            throw new XQException("This connection is closed");
        }
        connection = conn;
        zorba = ((org.zorbaxquery.api.xqj.XQConnection)connection).getZorbaInstance();
    }

  /** \brief Gets the major version of this product.
   * 
   * @return a integer indicating the major version of this product
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public int getProductMajorVersion() throws XQException {
        isClosedXQException();
        return zorba.getMajorVersion();
    }

  /** \brief Gets the minor version of this product.
   * 
   * @return a integer indicating the minor version of this product
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public int getProductMinorVersion() throws XQException {
        isClosedXQException();
        return zorba.getMinorVersion();
    }

  /** \brief Gets the name of this product.
   * 
   * @return a string indicating the product name
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public String getProductName() throws XQException {
        isClosedXQException();
        return "Zorba - The XQuery Processor";
    }

  /** \brief Gets the full version of this product.
   * 
   * @return a string indicating the product version
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public String getProductVersion() throws XQException {
        isClosedXQException();
        return zorba.getVersion();
    }

  /** \brief Gets the major version number of XQJ specification supported by this implementation.
   * 
   * @return an integer indicating the XQJ major version
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public int getXQJMajorVersion() throws XQException {
        isClosedXQException();
        return XQJ_MAJOR;
    }

  /** \brief Gets the minor version number of XQJ specification supported by this implementation.
   * 
   * @return an integer indicating the XQJ minor version
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public int getXQJMinorVersion() throws XQException {
        isClosedXQException();
        return XQJ_MINOR;
    }

  /** \brief Gets the full version of XQJ specification supported by this implementation.
   * 
   * @return a string indicating the version of XQJ specification
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public String getXQJVersion() throws XQException {
        isClosedXQException();
        return new String().concat(new Integer(XQJ_MAJOR).toString()).concat(".").concat(new Integer(XQJ_MINOR).toString());
    }

  /** \brief Query if the associated conection is restricted for read only use.
   * 
   * @return true if the associated connection is for read-only; false otherwise
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public boolean isReadOnly() throws XQException {
        isClosedXQException();
        return false;
    }

  /** \brief Query if XQueryX format is supported in this data source.
   * 
   * @return true if so; otherwise false
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public boolean isXQueryXSupported() throws XQException {
        isClosedXQException();
        return zorba.isXQueryXSupported();
    }

  /** \brief Query if transaction is supported in this data source.
   * 
   * @return true if so; otherwise false
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public boolean isTransactionSupported() throws XQException {
        isClosedXQException();
        return false;
    }

  /** \brief Query if XQuery static typing feature is supported in this data source.
   * 
   * @return true if so; otherwise false
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public boolean isStaticTypingFeatureSupported() throws XQException {
        isClosedXQException();
        return false;
    }

  /** \brief Query if XQuery schema import feature is supported in this connection.
   * 
   * @return true if so; otherwise false
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public boolean isSchemaImportFeatureSupported() throws XQException {
        isClosedXQException();
        return true;
    }

  /** \brief Query if XQuery schema validation feature is supported in this connection.
   * 
   * @return true if so; otherwise false
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public boolean isSchemaValidationFeatureSupported() throws XQException {
        isClosedXQException();
        return true;
    }

  /** \brief Query if XQuery full axis feature is supported in this connection.
   * 
   * @return true if so; otherwise false
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public boolean isFullAxisFeatureSupported() throws XQException {
        isClosedXQException();
        return true;
    }

  /** \brief Query if XQuery module feature is supported in this connection.
   * 
   * @return true if so; otherwise false
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public boolean isModuleFeatureSupported() throws XQException {
        isClosedXQException();
        return true;
    }

  /** \brief Query if XQuery serialization feature is supported in this connection.
   * 
   * @return true if so; otherwise false
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public boolean isSerializationFeatureSupported() throws XQException {
        isClosedXQException();
        return true;
    }

  /** \brief Query if XQuery static typing extensions are supported in this connection.
   * 
   * @return true if so; otherwise false
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public boolean isStaticTypingExtensionsSupported() throws XQException {
        isClosedXQException();
        return false;
    }

  /** \brief Gets the user name associated with this connection.
   * 
   * @return the user's name
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public String getUserName() throws XQException {
        isClosedXQException();
        return null;
    }

  /** \brief Gets the maximum number of characters allowed in an expression in this data source.
   * 
   * @return the maximum length of expression as an integer. A zero value means that there is no limit or the limit is unknown.
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public int getMaxExpressionLength() throws XQException {
        isClosedXQException();
        return 0;
    }

  /** \brief Gets the maximum number of characters allowed in a user name.
   * 
   * @return the maximum length of user name as an integer. A zero value means that there is no limit or the limit is unknown.
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public int getMaxUserNameLength() throws XQException {
        isClosedXQException();
        return 0;
    }

  /** \brief Query if this connection was created from a JDBC connection.
   * 
   * @return true, if this connection was created from a JDBC connection, false otherwise.
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public boolean wasCreatedFromJDBCConnection() throws XQException {
        isClosedXQException();
        return false;
    }

  /** \brief Query if the XQuery encoding declaration is supported by the XQJ implementation.
   * 
   * @return true if the XQuery encoding declaration is supported; false otherwise
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public boolean isXQueryEncodingDeclSupported() throws XQException {
        isClosedXQException();
        return false;
    }

  /** \brief Returns a set of java.lang.String, each of which specifies a character encoding method the XQJ implmentation supports to parse the XQuery query text.
   * 
   * For an example, for an XQJ impmentation which is able to parse the XQuery encoded in "UTF-8" or "UTF-16", it returns a java.util.Set of "UTF-8" and "UTF-16". If the implemetation is not able to generate a list of encodings supported, an empty set is returned. If a non-empty set is returned, the encodings returned in this set are guaranteed to be supported. Note that encodings not in the returned set might also be supported. For example, if the set has two encoding methods: 'UTF-8' and 'UTF-16', they are supported by the implementation. However, this does not mean 'Shift-Js' is not supported. It might be supported.
   * 
   * @return a java.util.Set of java.lang.String, each of which is an XQuery query text encoding method
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public Set getSupportedXQueryEncodings() throws XQException {
        isClosedXQException();
        Set<String> set = new HashSet<String>();
        set.add("UTF8");
        return set;
        
    }

  /** \brief Query if a character encoding method of the XQuery query text is supported by the XQJ implmentation.
   * 
   * @param string - String representing the character encoding method of the XQuery query text.
   * @return true if an XQuery query character encoding method is supported, false otherwise
   * @throw XQException - if (1) the connection is no longer valid, or (2) the specified encoding parameter is null
   */
    @Override
    public boolean isXQueryEncodingSupported(String string) throws XQException {
        isClosedXQException();
        isNullXQException(string);
        return string.equals("UTF8");
    }

  /** \brief Check if the user defined XML schema type is supported in this connection.
   * 
   * If this method returns true, then XQItemAccessor.instanceOf(XQItemType) must be able to determine if the type of an XQItemAccessor is an instance of the XQItemType even if either of them is a user defined XML schema type which is defined by the non-predefined XML schema. The pre-defined XML Schema refers to the XML schema whose schema URL is "http://www.w3.org/2001/XMLSchema"
   * 
   * @return true if the user defined XML schema type is supported in this connection, false otherwise.
   * @throw XQException - if the connection is no longer valid
   */
    @Override
    public boolean isUserDefinedXMLSchemaTypeSupported() throws XQException {
        isClosedXQException();
        return true;
    }
    
    private void isClosedXQException() throws XQException {
        if (connection.isClosed()) {
            throw new XQException("This connection is closed");
        }
    }
    private void isNullXQException(Object value) throws XQException {
        if (value==null) {
            throw new XQException("Parameter shouldn't be null");
        }
    }

}
