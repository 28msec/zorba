#ifndef XQP_COMPILERCB_H
#define XQP_COMPILERCB_H

#include <vector>
#include "common/shared_types.h"

namespace zorba {
  
  class CompilerCB 
  {
    public:
      typedef struct __config_t {
        typedef enum {
          O0,
          O1
        } opt_level_t;

        opt_level_t opt_level;
        bool print_translated, print_normalized, print_optimized;

        __config_t() { opt_level = O1; }
      } config_t;
      
      ~CompilerCB();
      static_context*               m_sctx;          
      std::vector<static_context_t> m_sctx_list;     
      error::ErrorManager*          m_error_manager;
      config_t                      m_config;
  }; /* class CompilerCB */

} /* namespace zorba */

#endif /* XQP_COMPILERCB_H */
/* vim:set ts=2 sw=2: */
