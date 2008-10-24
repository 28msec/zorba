/*
 * Copyright 2006-2008 The FLWOR Foundation.
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
#ifndef ZORBA_XQUERY_API_H
#define ZORBA_XQUERY_API_H

#include <ostream>

#include <zorba/config.h>
#include <zorba/sax2.h>
#include <zorba/api_shared_types.h>
#include <zorba/options.h>


namespace zorba {

  /** \brief This class is the representation of an %XQuery in the %Zorba engine.
   *
   * To compile and execute an XQuery, an instance of this class must be created. 
   * This is done by using either the createQuery or compileQuery methods of the
   * Zorba class. These methods return an instance of XQuery_t, which is a 
   * reference counted smart pointer to a dynamically allocated XQuery object. After receiving
   * an XQuery_t, an application can make multiple copies of it.
   * Hence, each XQuery object can have multiple owners, potentially in different
   * threads. The XQuery object is deleted when all XQuery_t objects that point 
   * to it are destroyed.
   *
   * Although an XQuery instance may be accessible from multiple threads, the
   * instance is not thread safe, i.e.\ its methods should not be invoked in 
   * parallel by multiple threads. The only exception to this rule is the clone()
   * method. Cloning is the way to execute the same query from multiple threads.
   * Cloning can be done only after the query has been compiled. The clone() 
   * method creates and returns a new XQuery object that shares the same 
   * execution plan as the original XQuery object. After clone() returns, the
   * calling thread can invoke the various execution methods on the XQuery clone. 
   *
   * The file \link simple.cpp \endlink contains some basic examples the demonstrate
   * the use of this class.
   *
   * Note: This class is reference counted. When writing multi-threaded clients,
   * it is the responibility of the client code to synchronize assignments to the
   * SmartPtr holding this object.
   */
  class ZORBA_EXTERN_DECL XQuery : public SmartObject
  {
    public:
      /** \brief Destructor that destroys this XQuery object. 
       * 
       * The destructor is called automatically when there are no more XQuery_t
       * smart pointers pointing to this XQuery instance.
       */
      virtual ~XQuery() {}

      /** \brief Register an ErrorHandler to which errors during compilation or
       *         execution/serialization are reported.
       *
       * If no ErrorHandler has been set using this function or when creating/compiling
       * the query using the Zorba object (i.e.\ createQuery or compileQuery),
       * then subclasses of the ZorbaException class are thrown to report errors.
       *
       *  @param aErrorHandler ErrorHandler to which errors are reported. The
       *         caller retains ownership over the ErrorHandler passed as
       *         parameter.
       *  @throw SystemException if the query has been closed.
       *  @see close()
       */
      virtual void
      registerErrorHandler(ErrorHandler* aErrorHandler) = 0;

      /** \brief Reset the error handling mechanism to throwing exceptions,
       * i.e.\ behave as if no ErrorHandler had been set.
       *   
       *  @throw SystemException if the query has been closed already.
       *  @see registerErrorHandler(ErrorHandler*)
       */
      virtual void
      resetErrorHandler() = 0;

      /** \brief Check if this query is an updating query.
       *
       * @return true if the query is an updating query, false otherwise.
       * @throw SystemException if the query is not compiled or has been closed.
       * @see close()
       * @see compile(...)
       */
      virtual bool
      isUpdateQuery() const = 0;

      /** \brief Serialize the result of the query as text to the given output stream.
       *
       * @param aOutStream the output stream on which the result is written.
       * @param aSerOptions an optinal set of serialization options.
       * @throw ZorbaException if an error occurs (e.g. the query is closed or has not been compiled)
       */
      virtual void
      serialize(std::ostream& aOutStream, 
                const Zorba_SerializerOptions_t& aSerOptions = Zorba_SerializerOptions_default()) = 0;

      /** \brief Apply/execute the query if it is an updating query.
       *
       * @throw ZorbaException if an error occured, e.g. if the query has been closed, if the query
       *        has not been compiled, or an error occures during execution.
       */
      virtual void 
      applyUpdates() = 0;

      /** \brief Get an iterator for the result of the query.
        *
        * @return ResultIterator iterator over the result sequence.
        * @throw ZorbaException if an error occurs (e.g. the query is closed or has not been compiled).
        */
      virtual ResultIterator_t
      iterator() = 0;

      /** \brief Get the dynamic context of this query.
       *
       * This function returns the dynamic context that belongs to this query and
       * is used during query execution.
       * The context can be used, for example, to set values of external variables,
       * the default collation, or the current datetime.
       * It is only available if the query has been compiled, otherwise
       * an error is reported. Moreover, the context must not be modified during the
       * execution of a query (i.e. if a ResultIterator is opened).
       * The lifetime of the context returned by this function is restricted
       * by the lifetime of the according query object.
       *
       * @throw SystemException if the query has not been compiled or is closed.
       * @return DynamicContext of this query.
       */
      virtual DynamicContext*
      getDynamicContext() const = 0;

      /** \brief Get the static context of this query.
       *
       * This function returns the static context that belongs to this query.
       * The static context is only available if the query has been compiled, otherwise
       * an error is reported.
       * The context has all the components and values that have been set by the either
       * the static context that was passed when creating the query and and those that
       * were set in the prolog of the query.
       * Note that after compilation of the query the static context is a read only structure.
       * Moreover, the lifetime of the context returned by this function is restricted
       * by the lifetime of the according query object.
       *
       * @throw SystemException if the query has not been compiled or is closed.
       * @return StaticContext of this query.
       */
      virtual const StaticContext*
      getStaticContext() const = 0;

      /** \brief Parse the given query String.
       *
       * @param aQuery the query String to parse.
       * @throw ZorbaException if an error occurs while parsing the query.
       */
      virtual void
      parse(std::istream& aQuery) = 0;

      /** \brief Compile the give query String.
       *
       * @param aQuery the query String to compile.
       * @throw ZorbaException if the query has been closed, is already compiled, or
       *        an error occurs while compiling the query.
       */
      virtual void
      compile(const String& aQuery) = 0;

      /** \brief Compile the give query String with the given compiler hints.
       *
       * @param aQuery the query String to compile.
       * @param aHints hints passed to the query compiler.
       * @throw ZorbaException if the query has been closed, is already compiled, or
       *        an error occurs while compiling the query.
       */
      virtual void 
      compile(const String& aQuery, const Zorba_CompilerHints_t& aHints) = 0;
      
      /** \brief Compile the query given as an input stream with the given compiler hints.
       *
       * @param aQuery the query input stream.
       * @param aHints hints passed to the query compiler.
       * @throw ZorbaException if the query has been closed, is already compiled, or
       *        an error occurs while compiling the query.
       */
      virtual void 
      compile(std::istream& aQuery, const Zorba_CompilerHints_t& aHints) = 0;
      
      /** \brief Compile the give query String with the given static context and the 
       *         given compiler hints.
       *
       * @param aQuery the query String to compile.
       * @param aStaticContext the static context.
       * @param aHints hints passed to the query compiler.
       * @throw ZorbaException if the query has been closed, is already compiled, or
       *        an error occurs while compiling the query.
       */
      virtual void 
      compile(const String& aQuery, const StaticContext_t& aStaticContext, 
              const Zorba_CompilerHints_t& aHints) = 0;
      
      /** \brief Compile the query given as an input stream with the given static context and the 
       *         given compiler hints.
       *
       * @param aQuery the query input stream.
       * @param aStaticContext the static context.
       * @param aHints hints passed to the query compiler.
       * @throw ZorbaException if the query has been closed, is already compiled, or
       *        an error occurs while compiling the query.
       */
      virtual void 
      compile(std::istream& aQuery, const StaticContext_t& aStaticContext, 
              const Zorba_CompilerHints_t& aHints) = 0;

      /** \brief Set the filename of a query.
       *
       * This (after URI-encoding) becomes the encapsulating entity's
       * retrieval URI (in RFC 3986 terms).
       */
      virtual void
      setFileName( const String& ) = 0;

      /** \brief Register a SAX2_ContentHandler for retrieving the serialized 
       *         query result as SAX events when executeSAX() is called.
       *
       * @param aContentHandler the content handler on which SAX callbacks are called.
       */
      virtual void
      registerSAXHandler( SAX2_ContentHandler* aContentHandler ) = 0;

      /** \brief Register a SAX2_ContentHandler for retrieving the serialized 
       *         query result as SAX.
       * 
       * @param aContentHandler the content handler on which SAX callbacks are called.
       */
      virtual void
      executeSAX( SAX2_ContentHandler* aContentHandler) = 0;

      /** \brief Serialize the query result as SAX events and call the callbacks
       *         of the SAX2_ContentHandler that has been set using registerSAXHandler.
       *
       * @throw ZorbaException if an error occurs (e.g. no SAX2_ContentHandler has been registered).
       */
      virtual void
      executeSAX() = 0;

      /** \brief Close the query and release all aquired ressources.
       *
       * While a query is compiled and/or active, it holds on to a couple of ressources.
       * Before Zorba can be safely shutdown, all ressources must be released.
       * For queries this can be done by calling close. However, if close is not
       * called explicitly, it will be automatically called by the XQuery objects
       * destructor, i.e. if the last smart pointer holding this XQuery object is destroyed.
       *
       * Note that calling close explicitly is usually not necessary. 
       *
       * @throw SystemException if the XQuery object has already been closed.
       */
      virtual void
      close() = 0;

      /** \brief Clone this query object for executing it in another thread.
       *
       * A query object is not thread safe, i.e. it can't be executed in several
       * threads. In order to execute it in another thread it needs to be cloned
       * with this function. However, please note that if an ErrorHandler has
       * been provided by the user (see registerErrorHandler()), this ErrorHandler
       * will also be used in the cloned query, and as a result, the user should
       * provide a thread-safe ErrorHandler. Alternatively, a new ErrorHandler
       * can be registered in the cloned query by using registerErrorHandler 
       * again. Or, the cloned query can be reset to use the default ErrorHandler
       * (which just throws exceptions) by calling resetErrorHandler.
       *
       * This function also clones the StaticContext and DynamicContext of the
       * XQuery object. In the DynamicContext of the cloned query different 
       * variable values can be used, e.g. set different external variable
       * values. For an example of cloning a query and setting different values
       * in the dynamic context see example_10 in file \link simple.cpp \endlink.
       *
       * @return The cloned XQuery object.
       * @throw SystemException if the query has not been compiled or is closed.
       */
      virtual XQuery_t
      clone() const = 0;

#ifdef ZORBA_DEBUGGER
      /** \brief Enable/disable debug mode on the query
       *
       */
      virtual void
      setDebugMode( bool aDebugMode ) = 0;

      /** \brief Check if the debug mode is activated.
       *
       * @return true if the debug mode is enabled, false otherwise.
       */
      virtual bool
      isDebugMode() const = 0;

      /** \brief Run the query with the debugger server.
       *
       * This method run the query with the debugger server.
       * This method is blocking up until a debugger client connects to the
       * server and decided to end the server. In order to call this method, the
       * query has to be compiled.
       *
       * @param aCommandPort the port used to received commands from the client.
       * @param anEventPort the port used to send events to the client.
       */
      virtual void
      debug( unsigned short aCommandPort = 8000, unsigned short anEventPort = 9000 ) = 0;

      /** \brief Run the query with the debugger server.
       *
       * This method run the query with the debugger server.
       * This method is blocking up until a debugger client connects to the
       * server and decided to end the server. In order to call this method, the
       * query has to be compiled.
       * You can specify an output stream and serialization options that can be used
       * by the serializer.
       *
       * @param aOutStream the output stream on which the result is written.
       * @param aSerOptions an optinal set of serialization options.
       * @param aCommandPort the port used to received commands from the client.
       * @param anEventPort the port used to send events to the client.
       *
       * @throw ZorbaException if an error occurs (e.g. the query is closed or has not been compiled)
       *
       */
      virtual void
      debug(std::ostream& aOutStream,
            const Zorba_SerializerOptions_t& aSerOptions = Zorba_SerializerOptions_default(),
            unsigned short aCommandPort = 8000, unsigned short anEventPort = 9000) = 0;
#endif
  };

  // xml serialization of the query (equiv to calling serialize(os) 
  ZORBA_EXTERN_DECL
  std::ostream& operator<< (std::ostream& os, const XQuery_t& aQuery); 
  ZORBA_EXTERN_DECL
  std::ostream& operator<< (std::ostream& os, XQuery* aQuery); 


} /* namespace zorba */

#endif
