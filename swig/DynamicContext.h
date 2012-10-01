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
#ifndef API_DYNAMIC_CONTEXT_H
#define API_DYNAMIC_CONTEXT_H

/** \brief Instances of the class DynamicContext contain the information that is available at the
 *         time the query is executed.
 *
 * The class contains the information that is defined in the %XQuery
 * specification (see http://www.w3.org/TR/xquery/#eval_context).
 *
 * A dynamic context always belongs to a particular query and, hence, can be retrieved by
 * calling getDynamicContext on a compiled query (see XQuery::getDynamicContext()).
 *
 */
class DynamicContext
{
private:
  zorba::DynamicContext* theContext;
public:

  DynamicContext():theContext(0) {}
  DynamicContext(const DynamicContext& aCtx):theContext(aCtx.theContext) {}
  DynamicContext(zorba::DynamicContext* aCtx):theContext(aCtx) {}

  bool 	getContextItem (Item& aItem);

  /** \brief Retrieve the dateTime Item used at the time the query is executed
   *         (see setCurrentDateTime()).
   *
   * @return Item the dateTime Item used at the time the query is executed.
   */
  Item 	getCurrentDateTime ();

  /** \brief Return the value of the default collection that is used when calling the
   *         fn:collection function without a parameter.
   *
   * @return Item the default collection that is set in this dynamic context.
   * @throw ZorbaException if an error occured.
   */
  Item 	getDefaultCollection ();

  /** \brief Retrieve the implicit timezone used in comparisons or arithmetic operations
   *         of date, time, or dateTime values.
   *
   * @return int the implicit timezone. Note that 0 is returned if an error occured
   *         and an DiagnosticHandler is used.
   * @throw ZorbaException if an error occured.
   */
  int 	getImplicitTimezone ();

  /** \brief Returns the current value of an external
   * variable. Exactly one of the two return values (aItem or
   * aIterator) will be non-null; that is, have isNull() == false.
   *
   * The named external variable may be located in the main query or in any
   * modules imported directly or indirectly by the query.
   *
   * @param aNamespace the namespace URI of the variable's expanded QName
   * @param aLocalname the local name of the variable's expanded QName
   * @param aItem an Item representing the current (single-item) value of
   *  the external variable.
   * @param aIterator an Iterator representing the current (possibly
   *  multi-item) value of the external variable.
   * @return true if the variable has been retrieved successfully, false otherwise.
   * @throw ZorbaException if an error occured.
   */
  bool 	getVariable (const std::string& aNamespace, const std::string& aLocalname, Item& aItem, Iterator& aIterator);
  
  /** \brief Defines the context item.
   *
   * @param aItem the Item that is used as value for the context item.
   * @return true if the context item was set, false otherwise.
   * @throw ZorbaException if an error occured (e.g. the given Item is not valid).
   */
  bool setContextItem (Item& aItem);

  /** \brief Defines the value of the current date time that can be accessed by the
   *         fn:current-dateTime() function at the time the query is executed.
   *
   * If the current date time has not been set explicitly the value of the date
   * and time is used at the time the query is created or cloned, respectively.
   *
   * @param aDateTimeItem the dateTime Item.
   * @return true if the variable has been set successfully, false otherwise.
   * @throw ZorbaException if an error occured (e.g. the given Item is invalid
   *        or not a Item of type dateTime)
   */
  bool setCurrentDateTime (Item& aDateTimeItem);

  /** \brief Defines the value of the default collection that is used when calling the
   *         fn:collection function without a parameter.
   *
   * @param aCollectionUri the URI of the collection used by the fn:collection function.
   * @return true if the default collection has been set successfully, false otherwise.
   * @throw ZorbaException if an error occured.
   */
  bool setDefaultCollection (Item& aCollectionUri);

  /** \brief Defines the variable of the implicit timezone to be used when a date, time,
   *         or dateTime value that does not have a timezone is used in a comparison or
   *         arithmetic operation.
   *
   * @param aTimezone the implicit timezone as int that should be used.
   * @return true if the implicit timezone has been set successfully, false otherwise.
   * @throw ZorbaException if an error occured.
   */
  bool setImplicitTimezone (int aTimezone);

  /** 
   * \brief Defines the external variable identified by an expanded QName and
   * assigns it the sequence that is returned by evaluating aIterator.
   *
   * The named external variable may be located in the main query or in any
   * modules imported directly or indirectly by the query.
   *
   * @param aNamespace the namespace URI of the variable's expanded QName
   * @param aLocalname the local name of the variable's expanded QName
   * @param aIter the Iterator producing the sequence that is assigned
   *        to the variable.
   * @return true if the variable has been set successfully, false otherwise.
   * @throw ZorbaException if an error occured (e.g. the given Iterator is not valid).
   */
  bool setVariable (const std::string& aNamespace, const std::string& aLocalname, Iterator& aIter);

  /**
   * \brief Defines the external variable identified by aQName and assigns it
   * the value of aItem.
   *
   * aQName may be in one of two forms: A lexical QName (eg. "ns:foo"), or a
   * James Clark-style universal name (eg. "{nsuri}:foo"). If it is a universal
   * name, then this method will find the named external variable in the main
   * query or in any modules imported directly or indirectly by the query. If it
   * is a lexical QName, then it is only possible to resolve the prefix in the
   * the context of the main query, hence only external variables in the main
   * query or those in directly-imported modules may be bound.
   *
   * @param aQName the QName that identifies the external variable.
   * @param aItem the Item that is used as value for the variable.
   * @return true if the variable has been set, false otherwise.
   * @throw ZorbaException if an error occured (e.g. the given Item is not valid).
   */
  bool setVariable (const std::string& aQName, Item& aItem);

  /**
   * \brief Defines the external variable identified by aQName and assigns it
   * the sequence that is returned by evaluating aIterator.
   *
   * aQName may be in one of two forms: A lexical QName (eg. "ns:foo"), or a
   * James Clark-style universal name (eg. "{nsuri}:foo"). If it is a universal
   * name, then this method will find the named external variable in the main
   * query or in any modules imported directly or indirectly by the query. If it
   * is a lexical QName, then it is only possible to resolve the prefix in the
   * the context of the main query, hence only external variables in the main
   * query or those in directly-imported modules may be bound.
   *
   * @param aQName the QName that identifies the external variable.
   * @param aIterator the Iterator producing the sequence that is assigned
   *        to the variable.
   * @return true if the variable has been set successfully, false otherwise.
   * @throw ZorbaException if an error occured (e.g. the given Iterator is not valid).
   */
  bool setVariable (const std::string& aQName, Iterator& aIterator);

};

#endif