/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
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
        bool print_item_flow;  // TODO: move to RuntimeCB

        __config_t() 
        { 
          opt_level        = O1;    
          print_translated = false; 
          print_normalized = false; 
          print_optimized  = false; 
          print_item_flow  = false; 
        }
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
