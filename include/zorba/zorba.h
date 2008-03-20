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
#include <zorba/string.h>
#include <zorba/exception.h>
#include <zorba/error_handler.h>
#include <zorba/xmldatamanager.h>


namespace zorba {

  /**
   *
   */
  class Zorba 
  {
    public:
      /** \brief Gets an instance of the Zorba %XQuery Engine.
       *
       */
      static Zorba* 
      getInstance();

      /** \brief Releases all resources aquired by the Zorba %XQuery Engine.
       * 
       */
      virtual void 
      shutdown() = 0;

      virtual ~Zorba();


      /** \brief Creates and compiles an XQuery object.
       * 
       */
      virtual XQuery_t
      createQuery(const String& aQuery, ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Creates and compiles a XQuery object.
       * 
       */
      virtual XQuery_t
      createQuery(const String& aQuery, const StaticContext_t& aContext, 
                  ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Create and compile an XQuery object.
       * 
       */
      virtual XQuery_t
      createQuery(std::istream& aQuery, ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Create and compile an XQuery object.
       * 
       */
      virtual XQuery_t
      createQuery(std::istream& aQuery, const StaticContext_t& aContext,
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
#endif /* XQP_ZORBA_API_H */
