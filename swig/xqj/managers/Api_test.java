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
package api_test;


import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Type;
import java.util.Locale;

public class Api_test {
    static 
    {
        System.loadLibrary ( "zorba_api" );
    }


    public static void main ( String... args )
    {
        try {
          Class<?> c = Class.forName("api_test.Tests");
          Object t = c.newInstance();

          Method[] allMethods = c.getDeclaredMethods();
          for (Method m : allMethods) {
              String mname = m.getName();
              if (!mname.startsWith("test")
                  || (m.getGenericReturnType() != boolean.class)) {
                  continue;
              }
              Type[] pType = m.getGenericParameterTypes();
              if ((pType.length != 1)
                  || Locale.class.isAssignableFrom(pType[0].getClass())) {
                  //continue;
              }

              System.out.format("invoking %s()%n", mname);
              try {
                  m.setAccessible(true);
                  Object o = m.invoke(t);
                  System.out.format("%s() returned %b%n", mname, (Boolean) o);
                  if ((Boolean) o) {
                    System.out.println("Success");
                  } else {
                    System.out.println("Failed");
                    System.exit (1);
                  }

              // Handle any exceptions thrown by method to be invoked.
              } catch (InvocationTargetException x) {
                  Throwable cause = x.getCause();
                  System.err.format("invocation of %s failed: %s%n",
                       mname, cause.getMessage());
              }
          }

            // production code should handle these exceptions more gracefully
        } catch (Exception e) {
          System.out.println("Failed");
          System.out.println("Exception caught. " + e.getLocalizedMessage());
          e.printStackTrace();
        }
    } // main

} // class Test_Zorba
