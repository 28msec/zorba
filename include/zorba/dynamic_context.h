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
#ifndef ZORBA_DYNAMIC_CONTEXT_API_H
#define ZORBA_DYNAMIC_CONTEXT_API_H

#include <time.h>
#include <istream>
#include <memory>

#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/static_context_consts.h>
#include <zorba/xmldatamanager.h>


namespace zorba {


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
class ZORBA_DLL_PUBLIC DynamicContext
{
 public:
  /**
   * \brief Defines the external variable identified by aQName and assigns it
   * the value of aItem.
   *
   * @param aQName the QName that identifies the external variable.
   * @param aItem the Item that is used as value for the variable.
   * @return true if the variable has been set, false otherwise.
   * @throw ZorbaException if an error occured (e.g. the given Item is not valid).
   */
  virtual bool
  setVariable(
      const String& aQName,
      const Item& aItem) = 0;

  /**
   * \brief Defines the external variable identified by aQName and assigns it
   * the sequence that is returned by evaluating aIterator.
   *
   * @param aQName the QName that identifies the external variable.
   * @param aIterator the Iterator producing the sequence that is assigned
   *        to the variable.
   * @return true if the variable has been set successfully, false otherwise.
   * @throw ZorbaException if an error occured (e.g. the given Iterator is not valid).
   */
  virtual bool
  setVariable( 
      const String& aQName,
      const Iterator_t& aIterator) = 0;

  /** 
   * \brief Defines the external variable identified by an expanded QName and
   * assigns it the sequence that is returned by evaluating aIterator.
   *
   * @param aNamespace the namespace URI of the variable's expanded QName
   * @param aLocalname the local name of the variable's expanded QName
   * @param aIterator the Iterator producing the sequence that is assigned
   *        to the variable.
   * @return true if the variable has been set successfully, false otherwise.
   * @throw ZorbaException if an error occured (e.g. the given Iterator is not valid).
   */
  virtual bool
  setVariable( 
      const String& aNamespace,
      const String& aLocalname,
      const Iterator_t& aIterator) = 0;

  /** \brief Sets the value of the external variable identified by aQName to the
   *         the document node that results from reading and parsing the xml
   *         document in the given istream.
   *
   * @param aQName the QName that identifies the external variable.
   * @param aDocURI the URI that is used to reference the document in the XmlDataManager.
   * @param aDocStream the istream used to read the document from. Ownership
   *        of the input stream is transfered to the processor using an auto_ptr.
   * @param aMode the mode to validate the document with. If it is equal to
   *        validate_skip, no validation is done. Otherwise, the document will
   *        be validated in strict or lax mode using the in-scope schema definitions
   *        that are found in the query's static context.
   * @return true if the variable has been set successfully, false otherwise.
   * @throw ZorbaException if an error occured.
   *
   * @deprecated Use setVarableAsDocument method with LoadProperties param
   */
  virtual bool
  setVariableAsDocument( const String& aQName,
                         const String& aDocURI,
                         std::auto_ptr<std::istream> aDocStream,
                         validation_mode_t aMode = validate_skip) = 0;

  /** \brief Sets the value of the external variable identified by aQName to the
   *         the document node that results from reading and parsing the xml
   *         document downloaded from the given URI.
   *
   * @param aQName the QName that identifies the external variable.
   * @param aDocURI the source URI, which is also used to reference the
   *        document in the XmlDataManager.
   * @param aMode the mode to validate the document with. If it is equal to
   *        validate_skip, no validation is done. Otherwise, the document will
   *        be validated in strict or lax mode using the in-scope schema definitions
   *        that are found in the query's static context.
   * @return true if the variable has been set successfully, false otherwise.
   * @throw ZorbaException if an error occured.
   *
   * @deprecated Use setVarableAsDocument method with LoadProperties param
   */
  virtual bool
  setVariableAsDocument( const String& aQName,
                         const String& aDocURI,
                         validation_mode_t aMode = validate_skip) = 0;

  /** \brief Sets the value of the external variable identified by aQName to the
   *         the document node that results from reading and parsing the xml
   *         document in the given istream.
   *
   * @param aQName the QName that identifies the external variable.
   * @param aDocURI the URI that is used to reference the document in the XmlDataManager.
   * @param aDocStream the istream used to read the document from. Ownership
   *        of the input stream is transfered to the processor using an auto_ptr.
   * @param aLoadProperties properties used for loading the document.
   * @param aReplaceDoc If a parsed document with the same URI exists in zorba's
   *        store already, then if aReplaceDoc is false, the variable is set to
   *        the root node of the existing document (i.e., no document is read from
   *        the given stream); otherwise, if aReplaceDoc is true, the existing
   *        document will be replaced by the document read from the given stream.
   * @return true if the variable has been set successfully, false otherwise.
   * @throw ZorbaException if an error occured.
   */
  virtual bool
  setVariableAsDocument( const String& aQName,
                         const String& aDocURI,
                         std::auto_ptr<std::istream> aDocStream,
                         const XmlDataManager::LoadProperties& aLoadProperties,
                         bool aReplaceDoc = false) = 0;

  /** \brief Sets the value of the external variable identified by aQName to the
   *         the document node that results from reading and parsing the xml
   *         document retrieved from the given URI.
   *
   * @param aQName the QName that identifies the external variable.
   * @param aDocURI the source Uri, which is also used to reference the
   *        document in the XmlDataManager.
   * @param aLoadProperties properties used for loading the document.
   * @param aReplaceDoc If a parsed document with the same URI exists in zorba's
   *        store already, then if aReplaceDoc is false, the variable is set to
   *        the root node of the existing document (i.e., no document is retrieved
   *        from the given doc URI); otherwise, if aReplaceDoc is true, the
   *        existing document will be replaced by the document retrieved from the
   *        given URI.
   * @return true if the variable has been set successfully, false otherwise.
   * @throw ZorbaException if an error occured.
   */
  virtual bool
  setVariableAsDocument( const String& aQName,
                         const String& aDocURI,
                         const XmlDataManager::LoadProperties& aLoadProperties,
                         bool aReplaceDoc = false) = 0;

  /** \brief Returns the current value of an external
   * variable. Exactly one of the two return values (aItem or
   * aIterator) will be non-null; that is, have isNull() == false.
   *
   * @param aNamespace the namespace URI of the variable's expanded QName
   * @param aLocalname the local name of the variable's expanded QName
   * @param aItem an Item representing the current (single-item) value of
   *  the external variable.
   * @param aIterator an Iterator representing the current (possibly
   *  multi-item) value of the external variable.
   * @return true if the variable has been retrieved successfully, false otherwise.
   * @throw ZorbaException if an error occured (e.g. the given Iterator is not valid).
   */
  virtual bool
  getVariable( const String& aNamespace,
               const String& aLocalname,
               Item& aItem,
               Iterator_t& aIterator) const = 0;

  /** \brief Defines the context item.
   *
   * @param aItem the Item that is used as value for the context item.
   * @return true if the context item was set, false otherwise.
   * @throw ZorbaException if an error occured (e.g. the given Item is not valid).
   */
  virtual bool
  setContextItem ( const Item& aItem ) = 0;

  /** \brief Sets the value of the context item to the the document node that
   *         results from reading and parsing the xml document in the given
   *         input stream.
   *
   * @param aDocURI the URI that is used to reference the document in the XmlDataManager.
   * @param aDocStream the istream used to read the document from. Ownership
   *        of the input stream is transfered to the processor using an auto_ptr.
   * @throw ZorbaException if an error occured (e.g. the input document could
   *        not be parsed).
   *
   * @deprecated Use setContextItemAsDocument method with LoadProperties param
   */
  virtual bool
  setContextItemAsDocument ( const String& aDocURI,
                             std::auto_ptr<std::istream> aDocStream ) = 0;

  /** \brief Defines the context item and assigns it the document downloaded from Uri.
   *
   * @param aDocURI the source Uri and the URI that is used to reference the
   *        document in the XmlDataManager.
   * @param aDocStream the istream used to read the document from. Ownership
   *        of the input stream is transfered to the processor using an auto_ptr.
   * @throw ZorbaException if an error occured (e.g. the input document could
   *        not be parsed).
   *
   * @deprecated Use setContextItemAsDocument method with LoadProperties param
   */
  virtual bool
  setContextItemAsDocument ( const String& aDocURI ) = 0;

  /** \brief Sets the value of the context item to the the document node that
   *         results from reading and parsing the xml document in the given
   *         input stream.
   *
   * @param aDocURI the URI that is used to reference the document in the XmlDataManager.
   * @param aDocStream the istream used to read the document from. Ownership
   *        of the input stream is transfered to the processor using an auto_ptr
   * @param aReplaceDoc If a parsed document with the same URI exists in zorba's
   *        store already, then if aReplaceDoc is false, the variable is set to
   *        the root node of the existing document (i.e., no document is read from
   *        the given stream); otherwise, if aReplaceDoc is true, the existing
   *        document will be replaced by the document read from the given stream.
   * @return true if the variable has been set successfully, false otherwise.
   * @throw ZorbaException if an error occured (e.g. the input document could
   *        not be parsed).
   */
  virtual bool
  setContextItemAsDocument ( const String& aDocURI,
                             std::auto_ptr<std::istream> aDocStream,
                             const XmlDataManager::LoadProperties& aLoadProperties,
                             bool aReplaceDoc = false) = 0;

  /** \brief Sets the value of the context item to the the document node that
   *         results from reading and parsing the xml document retrieved from
   *         the given URI.
   *
   * @param aDocURI the source Uri and the URI that is used to reference the
   *        document in the XmlDataManager.
   * @param aDocStream the istream used to read the document from. Ownership
   *        of the input stream is transfered to the processor using an auto_ptr.
   * @param aReplaceDoc If a parsed document with the same URI exists in zorba's
   *        store already, then if aReplaceDoc is false, the variable is set to
   *        the root node of the existing document (i.e., no document is retrieved
   *        from the given doc URI); otherwise, if aReplaceDoc is true, the
   *        existing document will be replaced by the document retrieved from the
   *        given URI.
   * @throw ZorbaException if an error occured (e.g. the input document could
   *        not be parsed).
   */
  virtual bool
  setContextItemAsDocument ( const String& aDocURI,
                             const XmlDataManager::LoadProperties& aLoadProperties,
                             bool aReplaceDoc = false) = 0;

  /** \brief Returns the current value of the context item.
   *
   * @param aItem an Item representing the current value of the context item.
   * @return true if the variable has been retrieved successfully, false otherwise.
   * @throw ZorbaException if an error occured (e.g. the given Iterator is not valid).
   */
  virtual bool
  getContextItem( Item& aItem ) const = 0;

  /** \brief Defines the value of the current date time that can be accessed by the
   *         fn:current-dateTime() function at the time the query is executed.
   *
   * If the current date time has not been set explicitly the value of the date
   * and time is used at the time the query is created or cloned, respectively.
   *
   * @param aDateTimeItem the dateTime Item.
   * @return true if the variable has been set successfully, false otherwise.
   * @throw ZorbaException if an error occured (e.g. the given Item is invalid
   *        or not a Item of type dateTime
   */
  virtual bool
  setCurrentDateTime( const Item& aDateTimeItem ) = 0;

  /** \brief Retrieve the dateTime Item used at the time the query is executed
   *         (see setCurrentDateTime()).
   *
   * @return Item the dateTime Item used at the time the query is executed.
   */
  virtual Item
  getCurrentDateTime( ) const = 0;

  /** \brief Defines the variable of the implicit timezone to be used when a date, time,
   *         or dateTime value that does not have a timezone is used in a comparison or
   *         arithmetic operation.
   *
   * @param aTimezone the implicit timezone as int that should be used.
   * @return true if the implicit timezone has been set successfully, false otherwise.
   * @throw ZorbaException if an error occured.
   */
  virtual bool
  setImplicitTimezone( int aTimezone ) = 0;

  /** \brief Retrieve the implicit timezone used in comparisons or arithmetic operations
   *         of date, time, or dateTime values.
   *
   * @return int the implicit timezone. Note that 0 is returned if an error occured
   *         and an DiagnosticHandler is used.
   * @throw ZorbaException if an error occured.
   */
  virtual int
  getImplicitTimezone() const = 0;

  /** \brief Defines the value of the default collection that is used when calling the
   *         fn:collection function without a parameter.
   *
   * @param aCollectionUri the URI of the collection used by the fn:collection function.
   * @return true if the default collection has been set successfully, false otherwise.
   * @throw ZorbaException if an error occured.
   */
  virtual bool
  setDefaultCollection( const Item& aCollectionUri ) = 0;

  /** \brief Return the value of the default collection that is used when calling the
   *         fn:collection function without a parameter.
   *
   * @return Item the default collection that is set in this dynamic context.
   * @throw ZorbaException if an error occured.
   */
  virtual Item
  getDefaultCollection() const = 0;

  /** \brief Add a name-value pair the this context.
   *         The value can be accessed in the evaluate method
   *         of external functions (see NonePureStatelessExternalFunction).
   *
   * @param aName the name of the parameter to add
   * @param aValue the value that can be accessed in the evaluate method.
   * @return returns true if an entry with the same name did not already exist,
   *         false otherwise.
   */
  virtual bool
  addExternalFunctionParam( const String& aName, void* aValue ) = 0;

  /** \brief Get the value of a pair that was registered using
   *         the addExternalFunctionParam method. This can
   *         be used in the evaluate method
   *         of external functions (see NonePureStatelessExternalFunction).
   *
   * @param aName the name of the parameter to retrieve
   * @return aValue the value matching the given name if true is returned.
   * @return returns true if an entry with the given name was found,
   *         false otherwise.
   */
  virtual bool
  getExternalFunctionParam ( const String& aName, void*& aValue ) const = 0;

protected:
  /** \brief Destructor
   */
  virtual ~DynamicContext( ) {};
};

} /* namespace zorba */

#endif
