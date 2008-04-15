#ifndef XQP_ZORBA_IMPL_H
#define XQP_ZORBA_IMPL_H

#include <istream>

#include <exception>
#include <zorba/zorba.h>
#include "common/shared_types.h"

namespace zorba {

  namespace error {
    class ZorbaError;
  }


#define ZORBA_TRY try { 
#define ZORBA_CATCH } catch (error::ZorbaError& e) { \
    ZorbaImpl::notifyError(theErrorHandler, e); \
  } catch (std::exception& e) { \
    ZorbaImpl::notifyError(theErrorHandler, e.what()); \
  } catch (...) { \
    ZorbaImpl::notifyError(theErrorHandler); \
  } \
  

  /**
   *
   */
  class ZorbaImpl : public Zorba
  {
    public:
      virtual void 
      shutdown();

      virtual ~ZorbaImpl();

      XQuery_t
      createQuery(ErrorHandler* aErrorHandler = 0);

      XQuery_t
      compileQuery(const String& aQuery, ErrorHandler* aErrorHandler = 0);

      XQuery_t
      compileQuery(const String& aQuery, const StaticContext_t& aContext, ErrorHandler* aErrorHandler = 0); 

      XQuery_t
      compileQuery(std::istream& aQuery, ErrorHandler* aErrorHandler = 0);

      XQuery_t
      compileQuery(std::istream& aQuery, const StaticContext_t& aContext, ErrorHandler* aErrorHandler = 0);

      XQuery_t
      compileQuery(const String& aQuery, const XQuery::CompilerHints_t& aHints, ErrorHandler* aErrorHandler = 0);

      XQuery_t
      compileQuery(const String& aQuery, const StaticContext_t& aContext, const XQuery::CompilerHints_t& aHints, 
                  ErrorHandler* aErrorHandler = 0);

      XQuery_t
      compileQuery(std::istream& aQuery, const XQuery::CompilerHints_t& aHints, ErrorHandler* aErrorHandler = 0);

      XQuery_t
      compileQuery(std::istream& aQuery, const StaticContext_t& aContext, const XQuery::CompilerHints_t& aHints, 
                  ErrorHandler* aErrorHandler = 0);

      StaticContext_t
      createStaticContext(ErrorHandler* aErrorHandler = 0);

      ItemFactory*
      getItemFactory();

      XmlDataManager*
      getXmlDataManager();

      static void
      notifyError(ErrorHandler*, error::ZorbaError&);

      // notify zorba internal error 
      static void
      notifyError(ErrorHandler*, const std::string&);

      static void
      notifyError(ErrorHandler*);

      static void
      checkItem(const store::Item_t& aItem);

    protected:
      friend class Zorba;
      ZorbaImpl();

      void
      init();

      bool theIsInitialized;

  }; /* class ZorbaImpl */


} /* namespace zorba */
#endif /* XQP_ZORBA_IMPL_H */
