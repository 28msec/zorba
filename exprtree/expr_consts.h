/**
 *
 * @copyright
 * ========================================================================
 *	Copyright 2007 FLWOR Foundation
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *		http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 * ========================================================================
 *
 * @file exprtree/expr_consts.h
 *
 */

#ifndef XQP_EXPR_CONSTS_H
#define XQP_EXPR_CONSTS_H


namespace xqp {

enum match_test_t
{
  no_test,
  name_test,
  doc_test,
  elem_test,
  attr_test,
  xs_elem_test,
  xs_attr_test,
  pi_test,
  comment_test,
  text_test,
  anykind_test
};


enum match_wild_t
{
  no_wild,
  all_wild,
  prefix_wild,
  name_wild
};


}; // namespace xqp


#endif /* XQP_EXPR_CONSTS_H */
