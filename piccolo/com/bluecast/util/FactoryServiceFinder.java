/*
 * $Id: FactoryServiceFinder.java,v 1.4 2004/07/08 08:01:45 yuvalo Exp $
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


package com.bluecast.util;

import java.io.*;
import java.util.*;
import java.net.*;

/**
 * This class can enumerate all the Providers of a particular Service. It
 * searches the classpath for META-INF/services/<service name> and returns
 * the first line of each service. That string is usually the name of the
 * factory class implementing the requested service.
 */
public class FactoryServiceFinder {
    static final String SERVICE = "META-INF/services/";

    /**
     * Find the first listed provider for the given service name
     */
    static public String findService(String name) throws IOException {
        InputStream is =
            ClassLoader.getSystemClassLoader().getResourceAsStream(
                SERVICE + name);
        BufferedReader r = new BufferedReader(
            new InputStreamReader(is,"UTF-8"));
        return r.readLine();
    }

    /**
     * Return an Enumeration of class name Strings of
     * available provider classes for the given service.
     */
    static public Enumeration findServices(String name) throws IOException {
        return new FactoryEnumeration(
            ClassLoader.getSystemClassLoader().getResources(name));
    }

    static private class FactoryEnumeration implements Enumeration {
        Enumeration enumValue;
        Object next=null;

        FactoryEnumeration(Enumeration enumValue) {
            this.enumValue = enumValue;
            nextElement();
        }

        public boolean hasMoreElements() {
            return (next != null);
        }

        public Object nextElement() {
            Object current = next;

            while (true) {
                try {
                    if (enumValue.hasMoreElements()) {
                        BufferedReader r = new BufferedReader(
                            new InputStreamReader(
                                ((URL)enumValue.nextElement()).openStream() ) );
                        next = r.readLine();
                    }
                    else
                        next = null;

                    break;
                }
                catch (IOException e) {
                    /* this one got an error. try the next. */
                }
            }

            return current;
        }
    }

}
