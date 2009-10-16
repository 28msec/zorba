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
#ifndef ZORBA_EXPR_CONSTS_H
#define ZORBA_EXPR_CONSTS_H

namespace zorba 
{


enum axis_kind_t
{
  axis_kind_self,
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
  match_no_test,
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
  match_no_wild,
  match_all_wild,
  match_prefix_wild,
  match_name_wild
};


enum expr_update_t
{
  UPDATE_EXPR,
  VACUOUS_EXPR,
  SIMPLE_EXPR,
  SEQUENTIAL_EXPR
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
