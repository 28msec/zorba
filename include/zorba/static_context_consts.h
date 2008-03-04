#ifndef XQP_STATIC_CONTEXT_CONSTS_H
#define XQP_STATIC_CONTEXT_CONSTS_H

namespace zorba {

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
