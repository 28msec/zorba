#ifndef XQP_COMPILERCB_H
#define XQP_COMPILERCB_H

#include <vector>
#include "common/shared_types.h"

namespace zorba {
  
  class CompilerCB 
  {
    public:
      ~CompilerCB();
      static_context*               m_sctx;          
      std::vector<static_context_t> m_sctx_list;     
      error::ErrorManager*          m_error_manager; 
  }; /* class CompilerCB */

} /* namespace zorba */

#endif
