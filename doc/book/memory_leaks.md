# Memory Leaks

## Introduction

The Zorba Processor manages automatically its own memory, but still, there are cases where you may receive the following message:

<tt>
Zorba did not close properly, objects may still in memory while shutdown the store. 
[n] referenced URIs remain in the string pool.
For help avoiding this message please refer to http://www.zorba-xquery.com/html/documentation in section General Architecture -> Memory Leaks.
</tt>

This message means that not all the resources 
were released before Zorba and its store were shutdown.
While this might be a bug/memory leak in Zorba itself, it's also quite likely that the leak is in the application.
For the application, the rule is that before shutting down the store 
all resources must have been released.

So, strictly speaking, your program is leaking resources.

This problem might occur even though the application's code (C++ or other languages) looks good. Here is an example:

\section memory_leaks_example_c Example in C++
In the following example, the StaticContext and XQuery objects are not destroyed before Zorba and the store are shutdown.

\code
int main(int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);
  
  StaticContext_t lContext = lZorba->createStaticContext();
  lContext->addNamespace("foo", "http://www.foo.com");
  XQuery_t lQuery = lZorba->compileQuery("<foo:e/>", lContext);
  lQuery->execute();
  
  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
\endcode

So, for this scenario, the ideal way to solve the problem is through scopes, 
where you implement certain part of code in methods and release them when the objects loose their reference. 
Alternatively, you can explicitly set the variable to null, in which case the object will automatically be released.

Solution example:
\code
int main(int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);
  
  {  // Use a scope

  StaticContext_t lContext = lZorba->createStaticContext();
    lContext->addNamespace("foo", "http://www.foo.com");
    XQuery_t lQuery = lZorba->compileQuery("<foo:e/>", lContext);
    lQuery->execute();
    
    lContext = NULL;  // or explicitely set free the resources
    lQuery = NULL;
  }
  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
\endcode


\section memory_leaks_example_java Example in Java
This particular error is specially notorious when a memory managed language 
shows the error because you expect the language frees all memory, here is an example:

\code
public static void main ( String argv[] )
{
  InMemoryStore store = InMemoryStore.getInstance();
  Zorba zorba = Zorba.getInstance ( store );

  StaticContext context = zorba.createStaticContext();
  context.addNamespace("foo", "http://www.foo.com");
  XQuery query = zorba.compileQuery("<foo:e/>", context);
  String result = query.execute();
  
  zorba.shutdown();
  InMemoryStore.shutdown ( store );
  
}    
\endcode

In this example, and for the rest of the languages because Zorba is created in C++, 
we have created in the Zorba API the method \c destroy() \e that will set free the object
that could be pointing to any resource from the store, this method is in every object that need to be released.

*Java Note: Because Java is a garbage collected language you cannot predict when (or even if) an object will be destroyed. 
Hence there is no direct equivalent of a destructor.
There is an inherited method called finalize, but this is called entirely at the discretion of the garbage collector.
So, destroy() is the best practice for any language including Java.

Solution example:
\code
public static void main ( String argv[] )
{
  InMemoryStore store = InMemoryStore.getInstance();
  Zorba zorba = Zorba.getInstance ( store );

  StaticContext context = zorba.createStaticContext();
  context.addNamespace("foo", "http://www.foo.com");
  XQuery query = zorba.compileQuery("<foo:e/>", context);
  String result = query.execute();

  query.destroy();   // Release memory for this XQuery
  context.destroy(); // Release memory for this StaticContext

  zorba.shutdown();
  InMemoryStore.shutdown ( store );
  
}
\endcode


\section memory_leaks_example_xqj Example in XQJ

The XQJ standard provides specific \c close() \e methods for this specific purpose:
\code
  XQDataSource xqdatasource = new XQDataSource();
  XQConnection xqconnection = xqdatasource.getConnection();
  XQStaticContext staticContext = xqconnection.getStaticContext();
  staticContext.declareNamespace("foo", "http://www.foo.com");
  xqconnection.setStaticContext(staticContext);
  XQExpression xqexpression = xqconnection.createExpression();
  XQSequence xqsequence = xqexpression.executeQuery("<foo:e/>");
  // code to show the output

  xqconnection.close();  // Closing connection frees all related resources
\endcode


*/
/* vim:set et sw=2 ts=2: */
