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

typedef Zorba_SerializerOptions_t* (*itemHandler)(void* aUserData);

/** 
 * \brief This class is the representation of an %XQuery in the %Zorba engine.
 *
 * To compile and execute an XQuery, an instance of this class must be created. 
 * This is done by using either the createQuery or compileQuery methods of the
 * Zorba class. These methods return an instance of XQuery_t, which is a 
 * reference counted smart pointer to a dynamically allocated XQuery object.
 * After receiving an XQuery_t, an application can make multiple copies of it.
 * Hence, an XQuery object can have multiple users, potentially in different
 * threads. The XQuery object is deleted when all XQuery_t objects that point 
 * to it are destroyed.
 *
 * The file \link simple.cpp \endlink contains some basic examples the demonstrate
 * the use of this class.
 *
 * Note: This class is reference counted. When writing multi-threaded clients,
 * it is the responibility of the client code to synchronize assignments to the
 * SmartPtr holding this object.
 */
class ZORBA_DLL_PUBLIC XQuery : public SmartObject
{
 public:
  /** 
   * \brief Destructor that destroys this XQuery object. 
   * 
   * The destructor is called automatically when there are no more XQuery_t
   * smart pointers pointing to this XQuery instance.
   */
  virtual ~XQuery() {}

  /** 
   * \brief Set the filename of a query.
   *
   * This (after URI-encoding) becomes the encapsulating entity's
   * retrieval URI (in RFC 3986 terms).
   */
  virtual void
  setFileName(const String&) = 0;
  
  /** 
   * \brief Register an DiagnosticHandler to which errors during compilation or
   * execution/serialization are reported.
   *
   * If no DiagnosticHandler has been set via this function, the default error
   * handling mechanism is to throw instances of the ZorbaException class.
   *
   * @param aDiagnosticHandler DiagnosticHandler to which errors are reported. The
   *        caller retains ownership over the DiagnosticHandler passed as
   *        parameter.
   * @throw SystemException if the query has been closed.
   * @see close()
   */
  virtual void
  registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler) = 0;
  
  /** 
   * \brief Reset the error handling mechanism back to the default,
   * i.e.\ behave as if no DiagnosticHandler had been set.
   *   
   *  @throw SystemException if the query has been closed already.
   *  @see registerDiagnosticHandler(DiagnosticHandler*)
   */
  virtual void
  resetDiagnosticHandler() = 0;
  
  /**
   * \brief Set a timeout, after which the execution of the query will be
   * aborted.
   *
   * @param aTimeout is an optional argument, which declares, that the
   *        execution of a query will be aborted after aTimeout number of
   *        seconds. If aTimeout is set to -1 (default), the query will
   *        never abort.
   */
  virtual void
  setTimeout(long aTimeout = -1) = 0;
  
  /**
   * \brief Execute the query and write the result to the given output stream.
   *        The query only has a result if it's a non-updating query.
   *
   * @param aOutStream the output stream on which the result is written.
   * @param aSerOptions an optional set of serialization options.
   * @throw ZorbaException if an error occurs (e.g. the query is closed or
   *        has not been compiled)
   */
  virtual void
  execute(std::ostream& aOutStream,
          const Zorba_SerializerOptions_t* aSerOptions = NULL) = 0;
  
  /**
   * \brief Execute the query and write the result to the given output stream.
   * A handler function gets called before the serialization of each item.
   *
   * @param aOutStream the output stream on which the result is written.
   * @param aCallbackFunction a call back function which is called every time,
   *        before the serialization of an item.
   * @param aCallbackData data which is passed to the call back function.
   * @param aSerOptions Serializer options.
   * @throw ZorbaException if an error occurs (e.g. the query is closed or
   *        has not been compiled)
   */
  virtual void
  execute(std::ostream& aOutStream,
          itemHandler aCallbackFunction,
          void* aCallbackData,
          const Zorba_SerializerOptions_t* aSerOptions = NULL) = 0;
  
  /**
   * \brief Execute the (updating) query. The query can be executed with this
   * function only if it is an updating query.
   *
   * @see isUpdating
   * @throw ZorbaException if an error occurs (e.g. the query is closed or has
   *        not been compiled or is not updating)
   */
  virtual void
  execute() = 0;
  
  /**
   * \brief Get an iterator for the result of the query. Allows an application
   * to lazily execute the query, retrieving the result one item at a time.
   *
   * @return Iterator iterator over the result sequence.
   * @throw ZorbaException if an error occurs (e.g. the query is closed or has
   *        not been compiled).
   */
  virtual Iterator_t
  iterator() = 0;
  
  /**
   * \brief Register a SAX2_ContentHandler for retrieving the serialized 
   *         query result as SAX events when executeSAX() is called.
   *
   * @param aContentHandler the content handler on which SAX callbacks are called.
   */
  virtual void
  registerSAXHandler( SAX2_ContentHandler* aContentHandler ) = 0;
  
  /**
   * \brief Serialize the query result as SAX events and call the callbacks
   *        of the SAX2_ContentHandler that is given as input
   *
   * @param aContentHandler the content handler on which SAX callbacks are called.
   */
  virtual void
  executeSAX( SAX2_ContentHandler* aContentHandler) = 0;
  
  /** 
   * \brief Serialize the query result as SAX events and call the callbacks
   *        of the SAX2_ContentHandler that has been set using registerSAXHandler.
   *
   * @throw ZorbaException if an error occurs (e.g. no SAX2_ContentHandler has
   *        been registered).
   */
  virtual void
  executeSAX() = 0;

  /** 
   * \brief Get the dynamic context of this query.
   *
   * This function returns the dynamic context that belongs to this query and
   * is used during query execution. The context can be used, for example, to
   * set values of external variables, the default collation, or the current
   * datetime. It is only available if the query has been compiled, otherwise
   * an error is reported. Moreover, the context must not be modified during the
   * execution of a query (i.e. if a Iterator is opened). The lifetime of the
   * context returned by this function is restricted by the lifetime of the
   * according query object.
   *
   * @throw SystemException if the query has not been compiled or is closed.
   * @return DynamicContext of this query.
   */
  virtual DynamicContext*
  getDynamicContext() const = 0;

  /** 
   * \brief Get the static context of this query.
   *
   * This function returns the static context that belongs to this query. The
   * static context is only available if the query has been compiled, otherwise
   * an error is reported. The context has all the components and values that 
   * were set in the static context that was passed when creating the query and
   * those that were set in the prolog of the query. Note that after compilation
   * of the query the static context is a read only structure. Moreover, the
   * lifetime of the context returned by this function is restricted by the
   * lifetime of the corresponding query object.
   *
   * @throw SystemException if the query has not been compiled or is closed.
   * @return StaticContext of this query.
   */
  virtual const StaticContext*
  getStaticContext() const = 0;
  
  /** 
   * \brief Parse the given query String.
   *
   * @param aQuery the query file to parse.
   * @throw ZorbaException if an error occurs while parsing the query.
   */
  virtual void
  parse(std::istream& aQuery) = 0;
  
  /** 
   * \brief Compile a query given as a String.
   *
   * @param aQuery the query String to compile.
   * @throw ZorbaException if the query has been closed, is already compiled, or
   *        an error occurs while compiling the query.
   */
  virtual void
  compile(const String& aQuery) = 0;
  
  /** 
   * \brief Compile a query given as a String, using the given compiler hints.
   *
   * @param aQuery the query String to compile.
   * @param aHints hints passed to the query compiler.
   * @throw ZorbaException if the query has been closed, is already compiled, or
   *        an error occurs while compiling the query.
   */
  virtual void 
  compile(const String& aQuery, const Zorba_CompilerHints_t& aHints) = 0;
  
  /** 
   * \brief Compile a query given as an input stream, using the given compiler hints.
   *
   * @param aQuery the query input stream.
   * @param aHints hints passed to the query compiler.
   * @throw ZorbaException if the query has been closed, is already compiled, or
   *        an error occurs while compiling the query.
   */
  virtual void 
  compile(std::istream& aQuery, const Zorba_CompilerHints_t& aHints) = 0;
  
  /** 
   * \brief Compile a query given as a String, using a given static context and  
   *         compiler hints.
   *
   * @param aQuery the query String to compile.
   * @param aStaticContext the static context.
   * @param aHints hints passed to the query compiler.
   * @throw ZorbaException if the query has been closed, is already compiled, or
   *        an error occurs while compiling the query.
   */
  virtual void 
  compile(const String& aQuery,
          const StaticContext_t& aStaticContext, 
          const Zorba_CompilerHints_t& aHints) = 0;
  
  /** 
   * \brief Compile a query given as an input stream, using a given static
   * context and compiler hints.
   *
   * @param aQuery the query input stream.
   * @param aStaticContext the static context.
   * @param aHints hints passed to the query compiler.
   * @throw ZorbaException if the query has been closed, is already compiled, or
   *        an error occurs while compiling the query.
   */
  virtual void 
  compile(std::istream& aQuery,
          const StaticContext_t& aStaticContext, 
          const Zorba_CompilerHints_t& aHints) = 0;
  
  /** 
   * \brief Print the execution plan of this query to the given output stream.
   *
   * @param aStream the output stream to which the execution plan is printed
   * @param aDotFormat specifies the format of the printed execution plan. 
   *        If this is true, then the execution plan is printed in the DOT
   *        format. If this is false, the plan is printed as XML.
   * @throw ZorbaException if the query has been closed or is not compiled.
   */
  virtual void
  printPlan(std::ostream& aStream, bool aDotFormat = false) const = 0;
  
  /** \brief Returns true if the variable is bound to a value
	 *
	 * @param aQName the qname of the variable to check
	 */
  virtual bool
  isBoundExternalVariable(const String& aNamespace, const String& aLocalname) const = 0;

  /** 
   * \brief Check if this query is an updating query.
   *
   * @return true if the query is an updating query, false otherwise.
   * @throw SystemException if the query is not compiled or has been closed.
   * @see close()
   * @see compile(...)
   */
  virtual bool
  isUpdating() const = 0;
  
   /** 
   * \brief Check if this query is a sequential query.
   *
   * @return true if the query is a sequential query, false otherwise.
   * @throw SystemException if the query is not compiled or has been closed.
   * @see close()
   * @see compile(...)
   */
  virtual bool 
  isSequential() const = 0;

  /** \brief Save the compiled execution plan.
   *
   * After compiling an XQuery program you can save the execution plan in some
   * persistent storage. The execution plan is saved in a platform-independent
   * format. You can later load this execution plan into a different XQuery
   * object (potentially  on a different machine) and execute it like it was 
   * compiled in place.
   *
   * @param os The output stream into which the execution plan is saved.
   * @param archive_format Specify which output format to use. Possible values
   *        are ZORBA_USE_BINARY_ARCHIVE and ZORBA_USE_XML_ARCHIVE. The binary
   *        format is much smaller than XML format, but is not human readable.
   * @param save_options Specify some options to the plan serializer.
   *    <ul>Current possible values are: 
   *      <li>DONT_SAVE_UNUSED_FUNCTIONS (default): 
   *        to eliminate unused functions and reduce plan size</li>
   *      <li>SAVE_UNUSED_FUNCTIONS:
   *        to save everything, as if the xquery contains an eval instruction.
   *        This is useful if you intend to use StaticContext::containsFunction 
   *        or StaticContext::findFunctions.</li>
   *   </ul>
   * @return true if success.
   * @throw ZorbaException if the query has not been compiled or there are
   *        problems serializing the execution plan.
   */
  virtual bool
  saveExecutionPlan(std::ostream &os, 
                    Zorba_binary_plan_format_t archive_format = ZORBA_USE_BINARY_ARCHIVE,
                    Zorba_save_plan_options_t save_options = DONT_SAVE_UNUSED_FUNCTIONS) = 0;
  
  /** 
   * \brief Load execution plan.
   *
   * The serialized execution plan contains a general version for the entire
   * archive and specific versions for each class. Zorba does not quarantee
   * that it can load execution plans saved with previous versions of Zorba.
   * In most cases there will be no problems, but the complete backward
   * compatibility cannot be quaranteed.
   *
   * The engine automatically detects the format of the input, either XML or binary.
   *
   * @param is Reference to std::istream.
   * @param aCallback optional callback handler (see SerializationCallback)
   *        that is used to retrieve information that has not been serialized
   *        (e.g. external modules).
   * @return true if success.
   * @throw ZorbaException if there are problems loading the execution plan.
   */
  virtual bool
  loadExecutionPlan(std::istream& is, SerializationCallback* aCallback = 0) = 0;
  
  /** 
   * \brief Close the query and release all of its aquired ressources.
   *
   * While a query is compiled and/or active, it holds on to a number of
   * resources. Before Zorba can be safely shutdown, all resources must
   * be released. For queries this can be done by calling close. However,
   * if close is not called explicitly, it will be automatically called by
   * the XQuery object's destructor, when the last smart pointer pointing
   * this XQuery object is destroyed. 
   *
   * Note: After an XQuery object is closed, calling close() again on the
   * same object is a noop. However, calling any method other than close()
   * on a closed XQuery object is prohibited (an error will be raised).
   *
   * Note: if an iterator has been created to retreive the result of an
   * XQuery object (@see iterator()), that itrator will be closed when 
   * the query is closed, and the association between XQuery object and
   * Iterator object will be destroyed.
   */
  virtual void
  close() = 0;

  /** 
   * \brief Check if this query object has already been closed.
   *
   * @return true if the query has been closed already or false otherwise.
   */
  virtual bool
  isClosed() const = 0;

  /** 
   * \brief Clone this query object in order to execute the query in another
   * thread.
   *
   * Although two or more threads may invoke one of the execute methods on the
   * same XQuery object, these invocations are serialized internally. For true
   * parallel excetution of a query by multiple threads, the XQuery object needs
   * to be cloned, using this method. However, note that if an DiagnosticHandler has
   * been provided by the user (see registerDiagnosticHandler()), this DiagnosticHandler
   * will also be used in the cloned query, and as a result, the user should
   * provide a thread-safe DiagnosticHandler. Alternatively, a new DiagnosticHandler can
   * be registered in the cloned query by using registerDiagnosticHandler again.
   * Or, the cloned query can be reset to use the default DiagnosticHandler (which 
   * just throws exceptions) by calling resetDiagnosticHandler.
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

#ifdef ZORBA_WITH_DEBUGGER
  /**
   * \brief Enable/disable debug mode on the query
   */
  virtual void
  setDebugMode(bool aDebugMode) = 0;
  
  /**
   * \brief Check if the debug mode is activated.
   *
   * @return true if the debug mode is enabled, false otherwise.
   */
  virtual bool
  isDebugMode() const = 0;
#endif
  
  /** 
   * \brief Set the filename of the profile
   *
   * This file will contain the output of Zorba profiler.
   */
  virtual void
  setProfileName( std::string aProfileName ) = 0;
  
  /**
   * \brief Get the filename of the profile
   *
   * This file will contain the output of Zorba profiler.
   */
  virtual std::string
  getProfileName() const = 0;
  
#ifdef ZORBA_WITH_DEBUGGER
  /**
   * \brief Start a debugger server.
   *
   * This method will start a debugger server that will try to connect 
   * to a DBGP-enabled debugger client on the indicated socket (host and port).
   * In order to call this method, the query has to be compiled.
   *
   * @param hort the host where the debugger client is listening.
   * @param port the port on which the debugger client is listening.
   *
   * @throw ZorbaException if an error occurs (e.g. the query is closed or has
   *        not been compiled, the server cannot connect to the client, etc.)
   */
  virtual void
  debug(
    const std::string& host,
    unsigned short port) = 0;

  /**
   * \brief Start a debugger server.
   *
   * This method will start a debugger server that will try to connect 
   * to a DBGP-enabled debugger client on the indicated socket (host and port).
   * In order to call this method, the query has to be compiled.
   * You can specify an output stream and serialization options that can be used
   * by the serializer.
   *
   * @param outStream the output stream on which the result is written.
   * @param serOptions the serialization options.
   * @param hort the host where the debugger client is listening.
   * @param port the port on which the debugger client is listening.
   *
   * @throw ZorbaException if an error occurs (e.g. the query is closed or has
   *        not been compiled, the server cannot connect to the client, etc.)
   */
  virtual void
  debug(
    std::ostream& outStream,
    Zorba_SerializerOptions& serOptions,
    const std::string& host,
    unsigned short port) = 0;


  virtual void
  debug(
    std::ostream& outStream,
    itemHandler callbackFunction,
    void* callbackData,
    Zorba_SerializerOptions& serOptions,
    const std::string& host,
    unsigned short port) = 0;
#endif

  /** \brief Returns a CollectionManager responsible for all collections
   * which are statically declared in the static context of this query
   * (main module) or any transitively imported library module.
   *
   * The collection manager provides a set of functions for managing
   * collections and their contents.
   *
   * @return The collection manager responsible for managing
   *   collections of this query.
   *
   */
  virtual StaticCollectionManager*
  getStaticCollectionManager() const = 0;

  /** \brief Returns the QName of all external variables 
   *
   * @param exVarIterator iterator to store the results.
   * @throw ZorbaException if an error occured.
   */
  virtual bool
  getExternalVariables(Iterator_t& exVarIterator) const = 0;

  /**
   *
   */
  virtual double
  getDocLoadingUserTime() const = 0;
  
  /**
   *
   */
  virtual double
  getDocLoadingTime() const = 0;
};
  

// xml serialization of the query (equiv to calling serialize(os) 
ZORBA_DLL_PUBLIC
std::ostream& operator<< (std::ostream& os, const XQuery_t& aQuery); 

ZORBA_DLL_PUBLIC
std::ostream& operator<< (std::ostream& os, XQuery* aQuery); 


} /* namespace zorba */

#endif
/* vim:set et sw=2 ts=2: */
