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
#ifndef ZORBA_STATIC_CONTEXT_CONSTS_H
#define ZORBA_STATIC_CONTEXT_CONSTS_H

namespace zorba {

  // TODO move into src/context
  class StaticContextConsts 
  {
    public:
      enum xpath1_0compatib_mode_t { xpath2_0, xpath1_0_only     };
      enum construction_mode_t     { cons_preserve, cons_strip   };
      enum ordering_mode_t         { ordered, unordered          };
      enum order_empty_mode_t      { empty_greatest, empty_least };
      enum boundary_space_mode_t   { preserve_space, strip_space };
      enum inherit_mode_t          { inherit_ns, no_inherit_ns   };
      enum preserve_mode_t         { preserve_ns, no_preserve_ns };

  }; /* class StaticContextConsts */

} /* namespace zorba */

#endif
