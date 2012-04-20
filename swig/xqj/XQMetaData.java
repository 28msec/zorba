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
    
    @Override
    public int getProductMajorVersion() throws XQException {
        isClosedXQException();
        return zorba.getMajorVersion();
    }

    @Override
    public int getProductMinorVersion() throws XQException {
        isClosedXQException();
        return zorba.getMinorVersion();
    }

    @Override
    public String getProductName() throws XQException {
        isClosedXQException();
        return "Zorba - The XQuery Processor";
    }

    @Override
    public String getProductVersion() throws XQException {
        isClosedXQException();
        return zorba.getVersion();
    }

    @Override
    public int getXQJMajorVersion() throws XQException {
        isClosedXQException();
        return XQJ_MAJOR;
    }

    @Override
    public int getXQJMinorVersion() throws XQException {
        isClosedXQException();
        return XQJ_MINOR;
    }

    @Override
    public String getXQJVersion() throws XQException {
        isClosedXQException();
        return new String().concat(new Integer(XQJ_MAJOR).toString()).concat(".").concat(new Integer(XQJ_MINOR).toString());
    }

    @Override
    public boolean isReadOnly() throws XQException {
        isClosedXQException();
        return false;
    }

    @Override
    public boolean isXQueryXSupported() throws XQException {
        isClosedXQException();
        return zorba.isXQueryXSupported();
    }

    @Override
    public boolean isTransactionSupported() throws XQException {
        isClosedXQException();
        return false;
    }

    @Override
    public boolean isStaticTypingFeatureSupported() throws XQException {
        isClosedXQException();
        return false;
    }

    @Override
    public boolean isSchemaImportFeatureSupported() throws XQException {
        isClosedXQException();
        return true;
    }

    @Override
    public boolean isSchemaValidationFeatureSupported() throws XQException {
        isClosedXQException();
        return true;
    }

    @Override
    public boolean isFullAxisFeatureSupported() throws XQException {
        isClosedXQException();
        return true;
    }

    @Override
    public boolean isModuleFeatureSupported() throws XQException {
        isClosedXQException();
        return true;
    }

    @Override
    public boolean isSerializationFeatureSupported() throws XQException {
        isClosedXQException();
        return true;
    }

    @Override
    public boolean isStaticTypingExtensionsSupported() throws XQException {
        isClosedXQException();
        return false;
    }

    @Override
    public String getUserName() throws XQException {
        isClosedXQException();
        return null;
    }

    @Override
    public int getMaxExpressionLength() throws XQException {
        isClosedXQException();
        return 0;
    }

    @Override
    public int getMaxUserNameLength() throws XQException {
        isClosedXQException();
        return 0;
    }

    @Override
    public boolean wasCreatedFromJDBCConnection() throws XQException {
        isClosedXQException();
        return false;
    }

    @Override
    public boolean isXQueryEncodingDeclSupported() throws XQException {
        isClosedXQException();
        return false;
    }

    @Override
    public Set getSupportedXQueryEncodings() throws XQException {
        isClosedXQException();
        Set<String> set = new HashSet<String>();
        set.add("UTF8");
        return set;
        
    }

    @Override
    public boolean isXQueryEncodingSupported(String string) throws XQException {
        isClosedXQException();
        isNullXQException(string);
        return string.equals("UTF8");
    }

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
