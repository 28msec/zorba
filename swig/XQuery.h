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
#ifndef API_XQUERY_H
#define API_XQUERY_H

/** 
 * \brief This class is the representation of an %XQuery in the %Zorba engine.
 *
 * To compile and execute an XQuery, an instance of this class must be created. 
 * This is done by using either the createQuery or compileQuery methods of the
 * Zorba class.
 *
 */
class XQuery
{
private:
  zorba::XQuery_t theQuery;
  bool closed;

public:
  XQuery():closed(false) {}
  XQuery(const XQuery& aXQuery) : theQuery(aXQuery.theQuery), closed(aXQuery.closed) {}
  XQuery(zorba::XQuery_t aQuery) : theQuery(aQuery), closed(false) {}

  /**
   * \brief Execute the query. The query can be executed with this function.
   *  The query only has a result if it's a non-updating query.
   *
   * @throw ZorbaException if an error occurs (e.g. the query is closed or has
   *        not been compiled or is not updating)
   */
  std::string execute();

  /** 
   * \brief Print the execution plan of this query to a given string.
   *
   * @return A String with the output.
   * @throw ZorbaException if the query has been closed or is not compiled.
   */
  std::string printPlanAsXML();

  /** 
   * \brief Print the execution plan of this query to a given string.
   *
   * @return A String with the output.
   * @throw ZorbaException if the query has been closed or is not compiled.
   */
  std::string printPlanAsDOT();

  /** 
   * \brief Compile a query given as a String.
   *
   * @param aQuery the query String to compile.
   * @throw ZorbaException if the query has been closed, is already compiled, or
   *        an error occurs while compiling the query.
   */
  void compile (const std::string &aQuery);

  /** 
   * \brief Compile a query given as a String, using a given static context and  
   *         compiler hints.
   *
   * @param aQuery the query String to compile.
   * @param aStaticContext the static context.
   * @throw ZorbaException if the query has been closed, is already compiled, or
   *        an error occurs while compiling the query.
   */
  void compile (const std::string &aQuery, StaticContext &aStaticContext);
#ifdef SWIGPYTHON
  /**
   * \brief Serialize the query result as SAX events and call the callbacks
   *        of the SAX2_ContentHandler that is given as input
   *
   * @param contentHandlerProxy the content handler on which SAX callbacks are called.
   */
  void executeSAX(SAX2ContentHandlerProxy* contentHandlerProxy);
#endif

  /** /brief deletes this object from memory
  */
  void destroy();

  /**
   * \brief Get an iterator for the result of the query. Allows an application
   * to lazily execute the query, retrieving the result one item at a time.
   *
   * @return Iterator iterator over the result sequence.
   * @throw ZorbaException if an error occurs (e.g. the query is closed or has
   *        not been compiled).
   */
  Iterator iterator();

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
  DynamicContext getDynamicContext();

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
  StaticContext getStaticContext();

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
  StaticCollectionManager getStaticCollectionManager();

  /** \brief Returns the QName of all external variables 
   *
   * @param vars iterator to store the results.
   * @throw ZorbaException if an error occured.
   */
  void getExternalVariables(Iterator& vars) const;
  
  /** \brief Execute the query and write the result to the given output stream.
   *  The query only has a result if it's a non-updating query.
   *
   * @stream The output stream on which the result is written.
   */
  void execute( ZorbaIOStream & stream );

  /** \brief Execute the query and write the result to the given output stream.
   *  The query only has a result if it's a non-updating query.
   *
   * @stream The output stream on which the result is written.
   * @param serOptions The serialization options for this Query result
   */
  void execute( ZorbaIOStream & stream, SerializationOptions & serOptions );
  
  /**
   * \brief Execute the query. The query can be executed with this function.
   *  The query only has a result if it's a non-updating query.
   *
   * @param serOptions The serialization options for this Query result
   * @throw ZorbaException if an error occurs (e.g. the query is closed or has
   *        not been compiled or is not updating)
   */
  std::string execute( SerializationOptions & serOptions );

}; // class XQuery

#endif