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

import java.io.PrintWriter;
import java.sql.Connection;
import java.util.Enumeration;
import java.util.Properties;
import javax.xml.xquery.*;

  /**
   * An XQDataSource is a factory for XQConnection objects. 
   */
public class XQDataSource implements javax.xml.xquery.XQDataSource {
    
   static {
      System.loadLibrary ( "zorba_api" );
   }
    public static final String ZORBA_PROPERTIES_URI_PATHS = "URI-PATHS";
    public static final String ZORBA_PROPERTIES_LIB_PATHS = "LIB-PATHS";
    public static final String ZORBA_PROPERTIES_MODULE_PATHS = "MODULE-PATHS";
    
    private int loginTimeout;
    protected PrintWriter logWriter;
    private Properties properties = new Properties();
    private String[] propertiesAllowed = {ZORBA_PROPERTIES_URI_PATHS, ZORBA_PROPERTIES_LIB_PATHS, ZORBA_PROPERTIES_MODULE_PATHS};
    public XQDataSource() {
    }


  /** \brief Attempts to create a connection to an XML datasource.
   * 
   * Attempts to create a connection to an XML datasource.
   * 
   * @return a connection to the XML datasource
   * @throw XQException - if a datasource access error occurs
   */
    @Override
    public XQConnection getConnection() throws XQException {
        XQConnection conn;
        try {
            if (!properties.isEmpty()) {
                conn = new XQConnection(properties);
            } else {
                conn = new XQConnection();
            }
        } catch ( Exception e ) {
            throw new XQException("Error creating new Zorba Connection Instance");
        }
        return conn;
    }

  /** \brief Attempts to create a connection to an XML datasource using an existing JDBC connection.
   * 
   * Attempts to create a connection to an XML datasource using an existing JDBC connection. An XQJ implementation is not required to support this method. If it is not supported, then an exception (XQException) is thrown. The XQJ and JDBC connections will operate under the same transaction context.
   * 
   * @param cnctn - an existing JDBC connection
   * @return a connection to the XML datasource
   * @throw XQException - if (1) a datasource access error occurs, (2) the implementation does not support this method of getting an XQConnection, or (3) if the con parameter is null
   */
    @Override
    public XQConnection getConnection(Connection cnctn) throws XQException {
        /* Attempts to create a connection to an XML datasource using an 
         * existing JDBC connection. An XQJ implementation is not required 
         * to support this method. If it is not supported, then an 
         * exception (XQException) is thrown. The XQJ and JDBC connections 
         * will operate under the same transaction context.
         * */
        throw new XQException("Connection to an XML datasource using an existing JDBC connection is not supported.");
    }

  /** \brief Attempts to establish a connection to an XML datasource using the supplied username and password.
   * 
   * Attempts to establish a connection to an XML datasource using the supplied username and password.
   * 
   * @param username - the user on whose behalf the connection is being made
   * @param passwd - the user's password
   * @return a connection to the XML datasource
   * @throw XQException - if a datasource access error occurs
   */
    @Override
    public XQConnection getConnection(String username, String passwd) throws XQException {
        XQConnection conn;
        try {
          if (!properties.isEmpty()) {
            conn = new XQConnection(properties);
          } else {
            conn = new XQConnection();
          }
        } catch ( Exception e ) {
            throw new XQException("Error creating new Zorba Connection Instance");
        }
        return conn;
    }

  /** \brief Gets the maximum time in seconds that this datasource can wait while attempting to connect to a database.
   * 
   * Gets the maximum time in seconds that this datasource can wait while attempting to connect to a database. A value of zero means that the timeout is the default system timeout if there is one; otherwise, it means that there is no timeout. When a XQDataSource object is created, the login timeout is initially zero. It is implementation-defined whether the returned login timeout is actually used by the data source implementation.
   * 
   * @return the datasource login time limit
   * @throw XQException - if a datasource access error occurs
   */
    @Override
    public int getLoginTimeout() throws XQException {
        return loginTimeout;
    }

  /** \brief Retrieves the log writer for this XQDataSource object.
   * 
   * Retrieves the log writer for this XQDataSource object. The log writer is a character output stream to which all logging and tracing messages for this datasource will be printed. This includes messages printed by the methods of this object, messages printed by methods of other objects manufactured by this object, and so on. When a XQDataSource object is created, the log writer is initially null; in other words, the default is for logging to be disabled.
   * 
   * @return the log writer for this datasource or null if logging is disabled
   * @throw XQException - if a datasource access error occurs
   */
    @Override
    public PrintWriter getLogWriter() throws XQException {
        return logWriter;
    }

  /** \brief Returns an array containing the property names supported by this XQDataSource.
   * 
   * Returns an array containing the property names supported by this XQDataSource. Implementations that support user name and password must recognize the user name and password properties listed below. 
   * 
   * user	the user name to use for creating a connection
   * password	the password to use for creating a connection
   * 
   * Any additional properties are implementation-defined.
   * 
   * @return String[] an array of property names supported by this implementation
   */
    @Override
    public String[] getSupportedPropertyNames() {
        return propertiesAllowed;
    }

  /** \brief Sets the named property to the specified value.
   * 
   * Sets the named property to the specified value. If a property with the same name was already set, then this method will override the old value for that property with the new value.
   * If the implementation does not support the given property or if it can determine that the value given for this property is invalid, then an exception is thrown. If an exception is thrown, then no previous value is overwritten.
   * 
   * @param name - the name of the property to set
   * @param value - the value of the named property
   * @throw XQException - if (1) the given property is not recognized, (2) the value for the given property is determined to be invalid, or (3) the name parameter is null
   */
    @Override
    public void setProperty(String name, String value) throws XQException {
        if (name==null) {
            throw new XQException("Property name is null.");
        }
        boolean allowed = false;
        for(int i=0; i<propertiesAllowed.length; i++) {
            if (propertiesAllowed[i].equals(name)) {
                allowed = true;
            }
        }
        if (allowed) {
            properties.setProperty(name, value);
        } else {
            throw new XQException("Property not allowed.");
        }
    }

  /** \brief Returns the current value of the named property if set, else null.
   * 
   * Returns the current value of the named property if set, else null. If the implementation does not support the given property then an exception is raised.
   * 
   * @param name - the name of the property whose value is needed
   * @return String representing the value of the required property if set, else null
   * @throw XQException - if (1) a given property is not supported, or (2) the name parameter is null
   */
    @Override
    public String getProperty(String name) throws XQException {
        if (name==null) {
            throw new XQException("Property name is null.");
        }
        boolean allowed = false;
        for(int i=0; i<propertiesAllowed.length; i++) {
            if (propertiesAllowed[i].equals(name)) {
                allowed = true;
            }
        }
        if (!allowed) {
            throw new XQException("Property name not supported.");
        }
        return properties.getProperty(name);
    }

  /** \brief Sets the data source properties from the specified Properties instance.
   * 
   * Sets the data source properties from the specified Properties instance. Properties set before this call will still apply but those with the same name as any of these properties will be replaced. Properties set after this call also apply and may replace properties set during this call.
   * If the implementation does not support one or more of the given property names, or if it can determine that the value given for a specific property is invalid, then an exception is thrown. If an exception is thrown, then no previous value is overwritten. is invalid, then an exception is raised.
   * 
   * @param prprts - the list of properties to set
   * @throw XQException - if (1) a given property is not recognized, (2) the value for a given property is determined to be invalid, or (3) the props parameter is null
   */
    @Override
    public void setProperties(Properties prprts) throws XQException {
        if (prprts==null) {
            throw new XQException("Properties are null.");
        }
        boolean allowed = false;
        String tmpstr = null;
        Enumeration em = prprts.keys();
        while (em.hasMoreElements()) {
            allowed = false;
            tmpstr = (String)em.nextElement();
            for (int i=0; i<propertiesAllowed.length; i++) {
                if (propertiesAllowed[i].equals(tmpstr)) {
                    allowed = true;
                }
            }
            if (!allowed) {
                throw new XQException("Property [" + tmpstr + "] not allowed");
            }
        }
        
        em = prprts.keys();
        while (em.hasMoreElements()) {
            tmpstr = (String)em.nextElement();
            properties.setProperty(tmpstr, prprts.getProperty(tmpstr));
        }
        
    }

  /** \brief Sets the maximum time in seconds that this datasource will wait while attempting to connect to a database.
   * 
   * Sets the maximum time in seconds that this datasource will wait while attempting to connect to a database. A value of zero specifies that the timeout is the default system timeout if there is one; otherwise, it specifies that there is no timeout. When a XQDataSource object is created, the login timeout is initially zero. It is implementation-defined whether the specified login timeout is actually used by the data source implementation. If the connection is created over an existing JDBC connection, then the login timeout value from the underlying JDBC connection may be used.
   * 
   * @param seconds - the datasource login time limit
   * @throw XQException - if a datasource access error occurs
   */
    @Override
    public void setLoginTimeout(int seconds) throws XQException {
        loginTimeout = seconds;
    }

  /** \brief Sets the log writer for this XQDataSource object to the given java.io.PrintWriter object.
   * 
   * Sets the log writer for this XQDataSource object to the given java.io.PrintWriter object. The log writer is a character output stream to which all logging and tracing messages for this datasource will be printed. This includes messages printed by the methods of this object, messages printed by methods of other objects manufactured by this object, and so on. When a XQDataSource object is created the log writer is initially null; in other words, the default is for logging to be disabled.
   * 
   * @param writer - the new log writer; to disable logging, set to null
   * @throw XQException - if a datasource access error occurs
   */
    @Override
    public void setLogWriter(PrintWriter writer) throws XQException {
        logWriter = writer;
    }
    
}
