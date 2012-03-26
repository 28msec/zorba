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

    @Override
    public int getLoginTimeout() throws XQException {
        return loginTimeout;
    }

    @Override
    public PrintWriter getLogWriter() throws XQException {
        return logWriter;
    }

    @Override
    public String[] getSupportedPropertyNames() {
        return propertiesAllowed;
    }

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

    @Override
    public void setLoginTimeout(int i) throws XQException {
        loginTimeout = i;
    }

    @Override
    public void setLogWriter(PrintWriter writer) throws XQException {
        logWriter = writer;
    }
    
}
