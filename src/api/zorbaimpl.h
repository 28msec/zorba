#ifndef XQP_ZORBA_IMPL_H
#define XQP_ZORBA_IMPL_H

#include <istream>

#include <zorba/zorba.h>

namespace zorba {

  namespace error {
    class ZorbaError;
  }

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
      createQuery(const String& aQuery, ErrorHandler* aErrorHandler = 0);

      XQuery_t
      createQuery(const String& aQuery, const StaticContext_t& aContext, 
                  ErrorHandler* aErrorHandler = 0);

      XQuery_t
      createQuery(std::istream& aQuery, ErrorHandler* aErrorHandler = 0);

      XQuery_t
      createQuery(std::istream& aQuery, const StaticContext_t& aContext,
                  ErrorHandler* aErrorHandler = 0);

      StaticContext_t
      createStaticContext(ErrorHandler* aErrorHandler = 0);

      ItemFactory*
      getItemFactory();

      XmlDataManager*
      getXmlDataManager();

      static void
      notifyError(ErrorHandler*, error::ZorbaError&);

    protected:
      friend class Zorba;
      ZorbaImpl();

      void
      init();

      bool theIsInitialized;

  }; /* class ZorbaImpl */


} /* namespace zorba */
#endif /* XQP_ZORBA_IMPL_H */
