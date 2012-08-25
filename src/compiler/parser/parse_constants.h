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
#pragma once
#ifndef ZORBA_COMPILER_PARSE_CONSTANTS_H
#define ZORBA_COMPILER_PARSE_CONSTANTS_H

#include <assert.h>

namespace zorba {

class ParseConstants
{
  public:
    enum default_namespace_mode_t 
    {
      ns_element_default,
      ns_function_default
    };

    enum function_type_t 
    {
      fn_simple,
      fn_extern_simple,
      fn_update,
      fn_extern_update,
      fn_sequential,
      fn_extern_sequential
    };

    enum dir_spec_t 
    {
      dir_ascending,
      dir_descending
    };

    enum quantification_mode_t 
    {
      quant_some,
      quant_every
    };

    enum add_op_t 
    {
      op_plus,
      op_minus
    };

    enum mult_op_t 
    {
      op_mul,
      op_div,
      op_idiv,
      op_mod
    };

    enum intex_op_t 
    {
      op_intersect,
      op_except	
    };

    enum gencomp_t 
    {
      op_eq,
      op_ne,
      op_lt,
      op_le,
      op_gt,
      op_ge
    };

    enum valcomp_t 
    {
      op_val_eq,
      op_val_ne,
      op_val_lt,
      op_val_le,
      op_val_gt,
      op_val_ge
    };

    enum nodecomp_t 
    {
      op_is,
      op_precedes,
      op_follows	
    };

    enum validation_mode_t 
    {
      val_strict,
      val_lax,
      val_dtd_lax,
      val_typename
    };

    enum pathtype_t 
    {
      path_leading_lone_slash,
      path_leading_slash,
      path_leading_slashslash,
      path_relative
    };

    enum steptype_t 
    {
      st_step,
      st_slash,
      st_slashslash,
      st_bang
    };

    enum axis_kind_t
    {
      axis_child,
      axis_descendant,
      axis_attribute,
      axis_self,
      axis_descendant_or_self,
      axis_following_sibling,
      axis_following,
      axis_parent,
      axis_ancestor,
      axis_preceding_sibling,
      axis_preceding,
      axis_ancestor_or_self
    };

    enum wildcard_t 
    {
      wild_all,
      wild_elem,
      wild_prefix
    };

    enum numeric_type_t 
    {
      num_integer,
      num_decimal,
      num_double
    };

    enum common_content_t 
    {
      cont_entity,
      cont_charref,
      cont_escape_lbrace,
      cont_escape_rbrace,
      cont_expr
    };

    enum occurrence_t 
    {
      occurs_never,
      occurs_exactly_one,
      occurs_optionally,
      occurs_zero_or_more,
      occurs_one_or_more
    };


  static const char* decode_numeric_type (enum numeric_type_t t) 
  {
    switch (t) 
    {
    case num_integer: return "integer";
    case num_decimal: return "decimal";
    case num_double:  return "double";
    default: assert (false); return "?";
    }
  }

  static const char* decode_axis_kind(axis_kind_t a)
  {
    switch (a)
    {
    case axis_child: return "child";
    case axis_descendant: return "descendant";
    case axis_attribute: return "attr";
    case axis_self: return "self";
    case axis_descendant_or_self: return "descendant-or-self";
    case axis_following_sibling: return "following-sibling";
    case axis_following: return "following";
    case axis_parent: return "parent";
    case axis_ancestor: return "ancestor";
    case axis_preceding_sibling: return "preceding_sibling";
    case axis_preceding: return "preceding";
    case axis_ancestor_or_self: return "ancestor_or_self";
    default: assert (false); return "?";
    }
  }
  
  static const char* decode_pathtype_t(enum pathtype_t ptype)       
  {
    switch (ptype)
    {
    case path_leading_lone_slash : return "path_leading_lone_slash";
    case path_leading_slash : return "path_leading_slash";
    case path_leading_slashslash : return "path_leading_slashslash";
    case path_relative : return "path_relative";
    default: assert (false); return "?";
    }
  }
  
  static const char* decode_steptype_t(enum steptype_t stype)
  {
    switch (stype)
    {
    case st_step : return "st_step";
    case st_slash : return "st_slash";
    case st_slashslash : return "st_slashslash";
    default: assert (false); return "?";
    }
  }
}; /* class ParseConstants */

} /* namespace zorba */
#endif /* ZORBA_PARSE_CONSTANTS_H */
/* vim:set et sw=2 ts=2: */
