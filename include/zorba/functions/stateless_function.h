#ifndef XQP_STATELESS_EXTERNAL_FUNCTION_H
#define XQP_STATELESS_EXTERNAL_FUNCTION_H

#include "zorba/common/api_shared_types.h" // for ItemSequence_t
#include "zorba/types/representations.h" // for xqpQName

#include "zorba/functions/external_function_data.h"

namespace xqp {

  class StatelessExternalFunction : public ExternalFunctionData 
  {
    public:
      typedef std::vector<ItemSequence_t> Arguments_t;

    public:
      virtual ~StatelessExternalFunction() {}

      virtual xqp_string getURI() const = 0;
      virtual xqp_string getLocalName() const = 0;

      virtual ItemSequence_t evaluate(const Arguments_t&) const = 0;

  };

} /* namespace xqp */

#endif
