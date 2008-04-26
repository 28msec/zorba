#ifndef XQP_ZORBA_API_H
#define XQP_ZORBA_API_H

#include <istream>

#include <zorba/api_shared_types.h>

#include <zorba/version.h>
#include <zorba/exception.h>
#include <zorba/xquery.h>
#include <zorba/static_context.h>
#include <zorba/dynamic_context.h>
#include <zorba/result_iterator.h>
#include <zorba/item.h>
#include <zorba/item_factory.h>
#include <zorba/zorbastring.h>
#include <zorba/exception.h>
#include <zorba/error_handler.h>
#include <zorba/xmldatamanager.h>
#include <zorba/default_error_handler.h>
#include <zorba/collection.h>

namespace zorba {

  /**
   *
   */
  class Zorba 
  {
    public:

      /** \brief Gets the singleton instance of the Zorba object.
       *
       * The Zorba object provides factory methods creating and/or compiling XQuery
       * objects, creating StaticContext objects, and accessing components as, for example,
       * the ItemFactory or the XmlDataManager.
       *
       * The first time this function is called, the %Zorba Engine is initialized.
       * Thereby, it initializes all the libraries that are used in the system, i.e.
       * ICU, libxml2, xerces, and libcurl.
       *
       * @return Zorba the singleton Zorba object
       *
       */
      static Zorba* 
      getInstance();

      /** \brief Releases all resources aquired by the Zorba %XQuery Engine.
       *
       * also release resources aquired by the libraries used (i.e. icu, libxml2, xerces, libcurl)
       * before calling shutdown, all xquery objects, items, contexts, ... have to be closed or
       * out of scope
       * otherwise this call may fails
       * after shutdown has been called, any call to zorba are invalid. 
       * getInstance may used to reinitialize the engine
       * 
       */
      virtual void 
      shutdown() = 0;

      /** \brief Destructor.
       *
       * The destructor is called during static deinitialization if getInstance has been
       * called at least once before.
       */
      virtual ~Zorba();

      /** \brief Creates an XQuery object.
       *
       * This methods creates an XQuery object without implicitliy assigning it a query.
       * A object returned by this method can be compiled (see compileQuery).
       *
       * Optionally, this method takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * compiling or executing the query, is reported to the passed error handler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       *
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
       * @return XQuery the newly created XQuery object.
       */
      virtual XQuery_t
      createQuery(ErrorHandler* aErrorHandler = 0) = 0;
      

      /** \brief Creates and compiles an XQuery object.
       *
       * This methods creates an XQuery object and compiles the query string passed to this method.
       *
       * Optionally, this method takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * compiling or executing the query, is reported to the passed error handler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       * 
       * @param aQuery the query string for the new XQuery object.
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
       * @return XQuery the newly created and compiled XQuery object.
       */
      virtual XQuery_t
      compileQuery(const String& aQuery, ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Creates and compiles an XQuery object using a StaticContext.
       *
       * This methods creates an XQuery object and compiles the query string passed to this method.
       * Compilation is done using the information contained in the StaticContext that
       * is passed as parameter.
       *
       * Optionally, this method takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * compiling or executing the query, is reported to the passed error handler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       * 
       * @param aQuery the query string for the new XQuery object.
       * @param aContext the StaticContext that contains information used for compiling the query.
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
       * @return XQuery the newly created and compiled XQuery object.
       */
      virtual XQuery_t
      compileQuery(const String& aQuery, const StaticContext_t& aContext, 
                   ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Creates and compiles an XQuery object.
       *
       * This methods creates an XQuery object and compiles the query that is passed to this method
       * as an input stream.
       *
       * Optionally, this method takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * compiling or executing the query, is reported to the passed error handler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       * 
       * @param aQuery the input stream providing the query.
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
       * @return XQuery the newly created and compiled XQuery object.
       */
      virtual XQuery_t
      compileQuery(std::istream& aQuery, ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Creates and compiles an XQuery object using a StaticContext.
       *
       * This methods creates an XQuery object and compiles the query that is passed to this method
       * as an input stream.
       * Compilation is done using the information contained in the StaticContext that
       * is passed as parameter.
       *
       * Optionally, this method takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * compiling or executing the query, is reported to the passed error handler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       * 
       * @param aQuery the input stream providing the query.
       * @param aContext the StaticContext that contains information used for compiling the query.
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
       * @return XQuery the newly created and compiled XQuery object.
       */
      virtual XQuery_t
      compileQuery(std::istream& aQuery, const StaticContext_t& aContext, 
                   ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Creates and compiles an XQuery object using the given CompilerHints.
       *
       * This methods creates an XQuery object and compiles the query string passed to this method.
       * Compilation and optimization is done with respect to the given CompilerHints.
       *
       * Optionally, this method takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * compiling or executing the query, is reported to the passed error handler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       * 
       * @param aQuery the query string for the new XQuery object.
       * @param aCompilerHints the CompilerHints used to compile the query.
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
       * @return XQuery the newly created and compiled XQuery object.
       */
      virtual XQuery_t
      compileQuery(const String& aQuery, const XQuery::CompilerHints_t& aCompilerHints, 
                   ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Creates and compiles an XQuery object using the given CompilerHints. Moreover,
       *         the information from the StaticContext is used to compile the query.
       *
       * This methods creates an XQuery object and compiles the query string passed to this method.
       * Compilation and optimization is done with respect to the given CompilerHints.
       * Moreover, compilation is done using the information contained in the StaticContext.
       *
       * Optionally, this method takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * compiling or executing the query, is reported to the passed error handler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       * 
       * @param aQuery the query string for the new XQuery object.
       * @param aContext the StaticContext that contains information used for compiling the query.
       * @param aCompilerHints the CompilerHints used to compile the query.
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
       * @return XQuery the newly created and compiled XQuery object.
       */
      virtual XQuery_t
      compileQuery(const String& aQuery, const StaticContext_t& aContext, 
                   const XQuery::CompilerHints_t&,
                   ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Creates and compiles an XQuery object using the given CompilerHints. 
       *
       * This methods creates an XQuery object and compiles the query that is passed to this method
       * as an input stream.
       * Compilation and optimization is done with respect to the given CompilerHints.
       *
       * Optionally, this method takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * compiling or executing the query, is reported to the passed error handler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       * 
       * @param aQuery the input stream providing the query.
       * @param aCompilerHints the CompilerHints used to compile the query.
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
       * @return XQuery the newly created and compiled XQuery object.
       */
      virtual XQuery_t
      compileQuery(std::istream& aQuery, const XQuery::CompilerHints_t& aCompilerHints, 
                   ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Creates and compiles an XQuery object using the given CompilerHints. 
       *
       * This methods creates an XQuery object and compiles the query that is passed to this method
       * as an input stream.
       * Compilation and optimization is done with respect to the given CompilerHints.
       * Moreover, compilation is done using the information contained in the StaticContext.
       *
       * Optionally, this method takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * compiling or executing the query, is reported to the passed error handler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       * 
       * @param aQuery the input stream providing the query.
       * @param aContext the StaticContext that contains information used for compiling the query.
       * @param aCompilerHints the CompilerHints used to compile the query.
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
       * @return XQuery the newly created and compiled XQuery object.
       */
      virtual XQuery_t
      compileQuery(std::istream& aQuery, const StaticContext_t& aContext, 
                   const XQuery::CompilerHints_t&,
                   ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Creates a new StaticContext.
       * 
       * The method returns a StaticContext object that can be used
       * for compiling a query. Instances of the StaticContext class are
       * returned as a boost smart pointer 
       * (see http://www.boost.org/doc/libs/1_35_0/libs/smart_ptr/smart_ptr.htm),
       * i.e. objects of type StaticContext_t are reference counted boost smart pointers 
       * to an dynamically allocated StaticContext object. Hence, each object can h
       * have multiple owners. The object is deleted if nobody holds on to an StaticContext_t 
       * object anymore.
       *
       * Optionally, this method takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * setting or getting information out of the StaticContext, is reported to the passed 
       * ErrorHandler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       *
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
       * @return StaticContext_t a new StaticContext object.
       */
      virtual StaticContext_t
      createStaticContext(ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Gets the singelton instance of the ItemFactory.
       *
       * @return ItemFactory the singleton instance of the ItemFactory.
       */
      virtual ItemFactory*
      getItemFactory() = 0;

      /** \brief Gets the singleton instance of the XmlDataManager object.
       *
       * @return XmlDataManager the singelton instance of the XmlDataManager.
       */
      virtual XmlDataManager*
      getXmlDataManager() = 0;

      /** \brief Get information about the used version of %Zorba.
       *
       * @return Version informatino about the used %Zorba version.
       */
      static const Version&
      version();

  }; /* class Zorba */

} /* namespace zorba */

/** 
 * \example simple.cpp
 *  This is a simple example that demonstrate how to use the Zorba XQuery Engine to
 *  create, compile, and execute queries.
 *
 * \example datamanager.cpp
 *  This file contains some examples that demonstrate how the XmlDataManager can be used
 *  to load files, create collection, etc.
 *
 * \example context.cpp
 *  This file demonstrates how the ItemFactory can be used to create new Items and 
 *  bind the Items to external variables in the dynamic context of a query.
 *
 */
#endif /* XQP_ZORBA_API_H */
