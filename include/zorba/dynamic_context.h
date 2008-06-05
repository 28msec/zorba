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

#include <zorba/config.h>
#include <zorba/api_shared_types.h>

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
  class ZORBA_EXTERN_DECL DynamicContext 
  {
    public:
      /** \brief Defines the external variable identified by aQName and assigns it the value of
       *         aItem.
       *
       * @param aQName the QName that identifies the external variable.
       * @param aItem the Item that is used as value for the variable. 
       * @return true if the variable has been set, false otherwise.
       * @throw ZorbaException if an error occured (e.g. the given Item is not valid).
       */
      virtual bool
      setVariable( const String& aQName, const Item& aItem ) = 0;

      /** \brief Defines the external variable identifies by aQName and assigns it the sequence
       *         that is returned by evaluating aResultIterator.
       *
       * @param aQName the QName that identifies the external variable.
       * @param aResultIterator the ResultIterator producing the sequence that is assigned 
       *        to the variable.
       * @return true if the variable has been set successfully, false otherwise.
       * @throw ZorbaException if an error occured (e.g. the given ResultIterator is not valid).
       */
      virtual bool
      setVariable( const String& aQName, const ResultIterator_t& aResultIterator ) = 0;

      /** \brief Defines the external variable identifies by aQName and assigns it the 
       *         the document that results from reading and parsing the given istream.
       *
       * @param aQName the QName that identifies the external variable.
       * @param aDocURI the URI that is used to reference the document in the XmlDataManager.
       * @param aDocStream the istream used to read the document from.
       * @return true if the variable has been set successfully, false otherwise.
       * @throw ZorbaException if an error occured (e.g. the given ResultIterator is not valid).
       */
      virtual bool
      setVariableAsDocument ( const String& aQName, const String& aDocURI, 
                              std::istream& aDocStream) = 0;
      virtual bool
      setVariableAsDocument ( const String& aQName, const String& aDocURI, 
                              std::istream* aDocStream) = 0;

      /** \brief Defines the context item.
       *
       * @param aItem the Item that is used as value for the context item.
       * @return true if the context item was set, false otherwise.
       * @throw ZorbaException if an error occured (e.g. the given Item is not valid).
       */
      virtual bool
      setContextItem ( const Item& aItem ) = 0;

      /** \brief Defines the context item and assigns it the document that results
       *         from parsing the given input stream.
       *
       * @param aDocURI the URI that is used to reference the document in the XmlDataManager.
       * @param aDocStream the istream used to read the document from.
       * @throw ZorbaException if an error occured (e.g. the input document could not be parsed).
       */
      virtual bool
      setContextItemAsDocument ( const String& aDocURI, std::istream& aDocStream ) = 0;
      virtual bool
      setContextItemAsDocument ( const String& aDocURI, std::istream* aDocStream ) = 0;

      /** \brief Defines the value of the current date time that can be accessed by the
       *         fn:current-dateTime() function at the time the query is executed.
       *
       * If the current date time has not been set explicitly the value of the date
       * and time is used at the time the query is created or cloned, respectively.
       *
       * @param aDateTimeItem the dateTime Item.
       * @return true if the variable has been set successfully, false otherwise.
       * @throw ZorbaException if an error occured (e.g. the given Item is invalid or not a Item of
       *        type dateTime
       */
      virtual bool
      setCurrentDateTime( const Item& aDateTimeItem ) = 0;
      
      /** \brief Retrieve the dateTime Item used at the time the query is executed 
       *         (see setCurrentDateTime()).
       *
       * @return Item the dateTime Item used at the time the query is executed.
       */
      virtual Item
      getCurrentDateTime( ) = 0;

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
       *         and an ErrorHandler is used.
       * @throw ZorbaException if an error occured.
       */
      virtual int
      getImplicitTimezone() = 0;

      /** \brief Defines the value of the default collection that is used when calling the
       *         fn:collection function without a parameter.
       *
       * @param aCollectionUri the URI of the collection used by the fn:collection function.
       * @return true if the default collection has been set successfully, false otherwise.
       * @throw ZorbaException if an error occured.
       */
      virtual bool
      setDefaultCollection( const Item& aCollectionUri ) = 0;

    protected:
      /** \brief Destructor
       *
       */
      virtual ~DynamicContext( ) {};
  };

} /* namespace zorba */

#endif
