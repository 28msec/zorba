#ifndef ZORBA_STATELESS_EXTERNAL_FUNCTION_H
#define ZORBA_STATELESS_EXTERNAL_FUNCTION_H

#include <vector>
#include <zorba/api_shared_types.h> 

#include <zorba/external_function_data.h>

namespace zorba {

  class StatelessExternalFunction : public ExternalFunctionData 
  {
    public:
      typedef std::vector<ItemSequence*> Arguments_t;

    public:
      virtual ~StatelessExternalFunction() {}

      virtual String 
      getURI() const = 0;
      
      virtual String
      getLocalName() const = 0;

      virtual ItemSequence_t
      evaluate(const Arguments_t&) const = 0;
  };
} /* namespace zorba */
#endif
