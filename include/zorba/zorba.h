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

      /** \brief Gets the singleton instance of Zorba object.
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

      virtual ~Zorba();

      /** \brief Creates an XQuery object.
       *
       * This methods creates an XQuery object without implicitliy assigning it a query.
       * A object returned by this method can be compiled (see compileQuery).
       *
       * Optionally, this query takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * compiling or executing the query, is reported to the passed error handler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       *
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
       */
      virtual XQuery_t
      createQuery(ErrorHandler* aErrorHandler = 0) = 0;
      

      /** \brief Creates and compiles an XQuery object.
       *
       * This methods creates an XQuery object and compiles the query string passed to this method.
       *
       * Optionally, this query takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * compiling or executing the query, is reported to the passed error handler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       * 
       * @param aQuery the query string for the new XQuery object.
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
       */
      virtual XQuery_t
      compileQuery(const String& aQuery, ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Creates and compiles an XQuery object using a StaticContext.
       *
       * This methods creates an XQuery object and compiles the query string passed to this method.
       * Compilation is done using the information contained in the StaticContext that
       * is passed as parameter.
       *
       * Optionally, this query takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * compiling or executing the query, is reported to the passed error handler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       * 
       * @param aQuery the query string for the new XQuery object.
       * @param aContext the StaticContext that contains information used for compiling the query.
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
       */
      virtual XQuery_t
      compileQuery(const String& aQuery, const StaticContext_t& aContext, 
                   ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Creates and compiles an XQuery object.
       *
       * This methods creates an XQuery object and compiles the query that is passed to this method
       * as an input stream.
       *
       * Optionally, this query takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * compiling or executing the query, is reported to the passed error handler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       * 
       * @param aQuery the input stream providing the query.
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
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
       * Optionally, this query takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * compiling or executing the query, is reported to the passed error handler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       * 
       * @param aQuery the input stream providing the query.
       * @param aContext the StaticContext that contains information used for compiling the query.
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
       */
      virtual XQuery_t
      compileQuery(std::istream& aQuery, const StaticContext_t& aContext, 
                   ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Creates and compiles an XQuery object using the given CompilerHints.
       *
       * This methods creates an XQuery object and compiles the query string passed to this method.
       * Compilation and optimization is done with respect to the given CompilerHints.
       *
       * Optionally, this query takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * compiling or executing the query, is reported to the passed error handler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       * 
       * @param aQuery the query string for the new XQuery object.
       * @param aCompilerHints the CompilerHints used to compile the query.
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
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
       * Optionally, this query takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * compiling or executing the query, is reported to the passed error handler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       * 
       * @param aQuery the query string for the new XQuery object.
       * @param aContext the StaticContext that contains information used for compiling the query.
       * @param aCompilerHints the CompilerHints used to compile the query.
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
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
       * Optionally, this query takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * compiling or executing the query, is reported to the passed error handler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       * 
       * @param aQuery the input stream providing the query.
       * @param aCompilerHints the CompilerHints used to compile the query.
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
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
       * Optionally, this query takes an ErrorHandler as parameter. In the case
       * an ErrorHandler is passed as parameter, each error that occurs during
       * compiling or executing the query, is reported to the passed error handler.
       * If not ErrorHandler is given, exceptions are thrown for each of these errors.
       * 
       * @param aQuery the input stream providing the query.
       * @param aContext the StaticContext that contains information used for compiling the query.
       * @param aCompilerHints the CompilerHints used to compile the query.
       * @param aErrorHandler the ErrorHandler to which errors should be reported.
       */
      virtual XQuery_t
      compileQuery(std::istream& aQuery, const StaticContext_t& aContext, 
                   const XQuery::CompilerHints_t&,
                   ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Create a StaticContext.
       *
       */
      virtual StaticContext_t
      createStaticContext(ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Get the ItemFactory
       *
       */
      virtual ItemFactory*
      getItemFactory() = 0;

      /** \brief Get the XmlDataManager.
       *
       */
      virtual XmlDataManager*
      getXmlDataManager() = 0;

      /** \brief Get information about the version of Zorba.
       *
       */
      static const Version&
      version();

  }; /* class Zorba */
} /* namespace xqp */

/** \example simple.cpp
 *  This is a simple example that demonstrate how to use the Zorba XQuery Engine to
 *  compile and execute queries.
 *
 */

#endif /* XQP_ZORBA_API_H */
