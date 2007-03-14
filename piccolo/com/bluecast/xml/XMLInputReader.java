/*
 * $Id: XMLInputReader.java,v 1.3 2004/07/08 08:03:04 yuvalo Exp $
 *
 * (C) Copyright 2002-2004 by Yuval Oren. All rights reserved.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */


package  com.bluecast.xml;

import  java.io.*;
import  com.bluecast.io.*;
import  java.util.*;


/**
 * A Reader for XML documents
 * the proper character set to use based on Byte Order Marks and XML
 * declarations.
 *
 * @author Yuval Oren, yuval@bluecast.com
 * @version $Revision: 1.3 $
 */
abstract public class XMLInputReader extends Reader {
    private String xmlVersion = null;
    private boolean xmlStandaloneDeclared = false;
    private boolean xmlStandalone = false;
    private String xmlDeclaredEncoding = null;

    private XMLDeclParser parser = new XMLDeclParser();

    protected void resetInput() {
        xmlVersion = xmlDeclaredEncoding = null;
        xmlStandaloneDeclared = xmlStandalone = false;
    }

    /**
     * Call this to parse the XML declaration. Returns the number
     * of characters used by the declaration, or zero if no declaration
     * was found.
     */
    protected int parseXMLDeclaration(char[] cbuf, int offset, int length)
    throws IOException {
        parser.reset(cbuf, offset, length);
        if (parser.parse() == parser.SUCCESS) {
            xmlVersion = parser.getXMLVersion();
            xmlStandalone = parser.isXMLStandalone();
            xmlStandaloneDeclared = parser.isXMLStandaloneDeclared();
            xmlDeclaredEncoding = parser.getXMLEncoding();
            return parser.getCharsRead();
        }
        else
            return 0;
    }

    /**
     * Gets the version string from the XML declaration, or null.
     */
    public String getXMLVersion () {
        return  xmlVersion;
    }

    /**
     * Returns the Standalone value from the XML declaration.
     * Defaults to false if no value was declared.
     */
    public boolean isXMLStandalone () {
        return  xmlStandalone;
    }

    /**
     * Returns true if an XML "standalone" declaration was found.
     */
    public boolean isXMLStandaloneDeclared() {
        return xmlStandaloneDeclared;
    }

    /**
     *  Gets the declared encoding from the XML declaration,
     *  or null if no value was found.
     */
    public String getXMLDeclaredEncoding () {
        return  xmlDeclaredEncoding;
    }
}



