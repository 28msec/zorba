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
#include <zorba/collection.h>


namespace zorba {

  /**
   *
   */
  class Zorba 
  {
    public:

      /** \brief Gets an instance of the Zorba %XQuery Engine.
       *
       * TODO
       * on the first time the zorba engine is initialized
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
       */
      virtual XQuery_t
      createQuery(ErrorHandler* aErrorHandler = 0) = 0;
      

      /** \brief Creates and compiles an XQuery object.
       * 
       */
      virtual XQuery_t
      compileQuery(const String& aQuery, ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Creates and compiles a XQuery object.
       * 
       */
      virtual XQuery_t
      compileQuery(const String& aQuery, const StaticContext_t& aContext, ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Create and compile an XQuery object.
       * 
       */
      virtual XQuery_t
      compileQuery(std::istream& aQuery, ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Create and compile an XQuery object.
       * 
       */
      virtual XQuery_t
      compileQuery(std::istream& aQuery, const StaticContext_t& aContext, ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Creates and compiles an XQuery object.
       * 
       */
      virtual XQuery_t
      compileQuery(const String& aQuery, const XQuery::CompilerHints_t&, ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Creates and compiles a XQuery object.
       * 
       */
      virtual XQuery_t
      compileQuery(const String& aQuery, const StaticContext_t& aContext, const XQuery::CompilerHints_t&,
                  ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Create and compile an XQuery object.
       * 
       */
      virtual XQuery_t
      compileQuery(std::istream& aQuery, const XQuery::CompilerHints_t&, ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Create and compile an XQuery object.
       * 
       */
      virtual XQuery_t
      compileQuery(std::istream& aQuery, const StaticContext_t& aContext, const XQuery::CompilerHints_t&,
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
