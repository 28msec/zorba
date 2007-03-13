/*
 * @(#)FactoryFinder.java	1.4 01/12/03
 *
 * Copyright 2002 Sun Microsystems, Inc. All rights reserved.
 * SUN PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

package javax.xml.parsers;

import java.io.InputStream;
import java.io.IOException;
import java.io.File;
import java.io.FileInputStream;

import java.util.Properties;
import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * This class is duplicated for each JAXP subpackage so keep it in
 * sync.  It is package private.
 *
 * This code is designed to implement the JAXP 1.1 spec pluggability
 * feature and is designed to run on JDK version 1.1 and later including
 * JVMs that perform early linking like the Microsoft JVM in IE 5.  Note
 * however that it must be compiled on a JDK version 1.2 or later system
 * since it calls Thread#getContextClassLoader().  The code also runs both
 * as part of an unbundled jar file and when bundled as part of the JDK.
 */
class FactoryFinder {
    /** Temp debug code - this will be removed after we test everything
     */
    private static boolean debug = false;
    static {
        // Use try/catch block to support applets
        try {
            debug = System.getProperty("jaxp.debug") != null;
        } catch (Exception x) {
        }
    }

    private static void debugPrintln(String msg) {
        if (debug) {
            System.err.println("JAXP: " + msg);
        }
    }

    /**
     * Figure out which ClassLoader to use.  For JDK 1.2 and later use the
     * context ClassLoader if possible.  Note: we defer linking the class
     * that calls an API only in JDK 1.2 until runtime so that we can catch
     * LinkageError so that this code will run in older non-Sun JVMs such
     * as the Microsoft JVM in IE.
     */
    private static ClassLoader findClassLoader()
        throws ConfigurationError
    {
        ClassLoader classLoader;
        try {
            // Construct the name of the concrete class to instantiate
            Class clazz = Class.forName(FactoryFinder.class.getName()
                                        + "$ClassLoaderFinderConcrete");
            ClassLoaderFinder clf = (ClassLoaderFinder) clazz.newInstance();
            classLoader = clf.getContextClassLoader();
        } catch (LinkageError le) {
            // Assume that we are running JDK 1.1, use the current ClassLoader
            classLoader = FactoryFinder.class.getClassLoader();
        } catch (ClassNotFoundException x) {
            // This case should not normally happen.  MS IE can throw this
            // instead of a LinkageError the second time Class.forName() is
            // called so assume that we are running JDK 1.1 and use the
            // current ClassLoader
            classLoader = FactoryFinder.class.getClassLoader();
        } catch (Exception x) {
            // Something abnormal happened so throw an error
            throw new ConfigurationError(x.toString(), x);
        }
        return classLoader;
    }

    /**
     * Create an instance of a class using the specified ClassLoader
     */
    private static Object newInstance(String className,
                                      ClassLoader classLoader)
        throws ConfigurationError
    {
        try {
            Class spiClass;
            if (classLoader == null) {
                spiClass = Class.forName(className);
            } else {
                spiClass = classLoader.loadClass(className);
            }
            return spiClass.newInstance();
        } catch (ClassNotFoundException x) {
            throw new ConfigurationError(
                "Provider " + className + " not found", x);
        } catch (Exception x) {
            throw new ConfigurationError(
                "Provider " + className + " could not be instantiated: " + x,
                x);
        }
    }

    /**
     * Finds the implementation Class object in the specified order.  Main
     * entry point.
     * @return Class object of factory, never null
     *
     * @param factoryId             Name of the factory to find, same as
     *                              a property name
     * @param fallbackClassName     Implementation class name, if nothing else
     *                              is found.  Use null to mean no fallback.
     *
     * Package private so this code can be shared.
     */
    static Object find(String factoryId, String fallbackClassName)
        throws ConfigurationError
    {
        ClassLoader classLoader = findClassLoader();

        // Use the system property first
        try {
            String systemProp =
                System.getProperty( factoryId );
            if( systemProp!=null) {
                debugPrintln("found system property" + systemProp);
                return newInstance(systemProp, classLoader);
            }
        } catch (SecurityException se) {
        }

        // try to read from $java.home/lib/xml.properties
        try {
            String javah=System.getProperty( "java.home" );
            String configFile = javah + File.separator +
                "lib" + File.separator + "jaxp.properties";
            File f=new File( configFile );
            if( f.exists()) {
                Properties props=new Properties();
                props.load( new FileInputStream(f));
                String factoryClassName = props.getProperty(factoryId);
                debugPrintln("found java.home property " + factoryClassName);
                return newInstance(factoryClassName, classLoader);
            }
        } catch(Exception ex ) {
            if( debug ) ex.printStackTrace();
        }

        String serviceId = "META-INF/services/" + factoryId;
        // try to find services in CLASSPATH
        try {
            InputStream is=null;
            if (classLoader == null) {
                is=ClassLoader.getSystemResourceAsStream( serviceId );
            } else {
                is=classLoader.getResourceAsStream( serviceId );
            }
        
            if( is!=null ) {
                debugPrintln("found " + serviceId);
                BufferedReader rd =
                    new BufferedReader(new InputStreamReader(is, "UTF-8"));
        
                String factoryClassName = rd.readLine();
                rd.close();

                if (factoryClassName != null &&
                    ! "".equals(factoryClassName)) {
                    debugPrintln("loaded from services: " + factoryClassName);
                    return newInstance(factoryClassName, classLoader);
                }
            }
        } catch( Exception ex ) {
            if( debug ) ex.printStackTrace();
        }

        if (fallbackClassName == null) {
            throw new ConfigurationError(
                "Provider for " + factoryId + " cannot be found", null);
        }

        debugPrintln("loaded from fallback value: " + fallbackClassName);
        return newInstance(fallbackClassName, classLoader);
    }

    static class ConfigurationError extends Error {
        private Exception exception;

        /**
         * Construct a new instance with the specified detail string and
         * exception.
         */
        ConfigurationError(String msg, Exception x) {
            super(msg);
            this.exception = x;
        }

        Exception getException() {
            return exception;
        }
    }

    /*
     * The following nested classes allow getContextClassLoader() to be
     * called only on JDK 1.2 and yet run in older JDK 1.1 JVMs
     */

    private static abstract class ClassLoaderFinder {
        abstract ClassLoader getContextClassLoader();
    }

    static class ClassLoaderFinderConcrete extends ClassLoaderFinder {
        ClassLoader getContextClassLoader() {
            return Thread.currentThread().getContextClassLoader();
        }
    }
}
