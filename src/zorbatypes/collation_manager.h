#ifndef XQP_ZORBATYPES_COLLATION_MANAGER_H
#define XQP_ZORBATYPES_COLLATION_MANAGER_H

#include <string>
#include <map>
#include "common/libicu.h"

namespace zorba {

  class XQPCollator 
  {
    friend class CollationFactory;
    friend class xqpString;
    friend class xqpStringStore;

    private:
      XQPCollator(Collator*);

    public:
      virtual ~XQPCollator();

    protected:
      Collator* theCollator;
  };

  class CollationFactory 
  {
    public:
      CollationFactory();
      virtual ~CollationFactory();

      /**
       * Creates a collator.
       * The URI specifies the locale and collation strengh that is used.
       *
       * The uri must begin with 
       * http://www.flworfound.org/collations/.
       * Then a collation strengh (PRIMARY, SECONDARY, TERTIARY, QUATTERNARY, 
       * or IDENTICAL followed by a '/'.
       * Then a lowercase two-letter or three-letter ISO-639 code
       * followed by '/' and an optional uppercase two-letter ISO-3166 code.
       * For example, http://www.flworfound.org/collations/PRIMARY/en/US
       * specifies an english language with US begin the country..
       * 
       * For a detailed description see
       * http://www.icu-project.org/apiref/icu4c/classCollator.html
       * and http://www.icu-project.org/apiref/icu4c/classLocale.html
       *
       * @returns 0 if no collator could be found.
       */
      static XQPCollator*
      createCollator(const std::string& aCollationURI);

      /**
       * Creates a collator for the english language, US country and
       * a PRIMARY collation strength.
       */
      static XQPCollator*
      createCollator();

    protected:
      XQPCollator* theRootCollator;
  };
} /* namespace xqp */

#endif
