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
#ifndef ZORBA_COMPILER_EXPR_CONSTS_H
#define ZORBA_COMPILER_EXPR_CONSTS_H

namespace zorba
{


enum axis_kind_t
{
  axis_kind_self = 0,
  axis_kind_child,
  axis_kind_parent,
  axis_kind_descendant,
  axis_kind_descendant_or_self,
  axis_kind_ancestor,
  axis_kind_ancestor_or_self,
  axis_kind_following_sibling,
  axis_kind_following,
  axis_kind_preceding_sibling,
  axis_kind_preceding,
  axis_kind_attribute
};


enum match_test_t
{
  match_no_test = 0,
  match_name_test,
  match_anykind_test,
  match_doc_test,
  match_elem_test,
  match_xs_elem_test,
  match_attr_test,
  match_xs_attr_test,
  match_pi_test,
  match_comment_test,
  match_text_test
};

std::string toString(match_test_t a);

enum match_wild_t
{
  match_no_wild = 0,
  match_all_wild,
  match_prefix_wild,
  match_name_wild
};


enum expr_script_kind_t
{
  UNKNOWN_SCRIPTING_KIND =   0,

  VACUOUS_EXPR           =   1,  // An expr that will always return the empty
                                 // sequence and will never have any side-effects.

  SIMPLE_EXPR            =   2,  // An expr that is none of the other kinds.

  UPDATING_EXPR          =   4,  // An expr that may return a non-empty PUL. The
                                 // expr may return non-empty XDM as well.

  VAR_SETTING_EXPR       =   8,  // An expr E during the evaluation of which a
                                 // var may be set and that var is declared
                                 // outside the innermost block that contains E.

  APPLYING_EXPR          =  16,  // An expr during the evaluation of which a
                                 // PUL may get applied.

  EXITING_EXPR           =  32,  // An expr during the evaluation of which an
                                 // exit expression may be executed.

  BREAKING_EXPR          =  64,  // An expr E during the evaluation of which
                                 // a break or continue expr may be executed
                                 // and the the while or flwor expr being
                                 // broken or continued contains E.

  SEQUENTIAL_FUNC_EXPR   = 128   // An expr during the evaluation of which a
                                 // sequential function may be called.
};


enum BoolAnnotationValue
{
  ANNOTATION_UNKNOWN = 0,
  ANNOTATION_FALSE,
  ANNOTATION_TRUE,
  ANNOTATION_TRUE_FIXED
};


class CompareConsts
{
public:
  enum CompareType
  {
    UNKNOWN,
    VALUE_EQUAL, GENERAL_EQUAL, NODE_EQUAL,
    VALUE_NOT_EQUAL, GENERAL_NOT_EQUAL, NODE_NOT_EQUAL,
    VALUE_LESS, GENERAL_LESS,
    VALUE_LESS_EQUAL, GENERAL_LESS_EQUAL,
    VALUE_GREATER, GENERAL_GREATER,
    VALUE_GREATER_EQUAL, GENERAL_GREATER_EQUAL
  };
};


class ArithmeticConsts
{
public:
  enum OperationKind
  {
    UNKNOWN,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    INTEGER_DIVISION,
    MODULO
  };
};


}; // namespace zorba


#endif /* ZORBA_EXPR_CONSTS_H */
/* vim:set et sw=2 ts=2: */
