/*
 * $Id: Entity.java,v 1.3 2004/07/08 08:03:04 yuvalo Exp $
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
import  java.net.*;
import  com.bluecast.util.*;
import  org.xml.sax.*;


public interface Entity {

    public boolean isOpen ();

    public void open () throws IOException, SAXException, RecursionException;
    public void close () throws IOException;

    public String getPublicID ();
    public String getSystemID ();

    public boolean isStandalone ();
    public void setStandalone (boolean standalone);

    public boolean isInternal ();
    public boolean isParsed ();

    // These apply only to external entities
    public String getDeclaredEncoding();
    public boolean isStandaloneDeclared();
    public String getXMLVersion();



    public Reader getReader ();
    public String stringValue ();
    public char[] charArrayValue ();
}



