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
#ifndef ZORBA_COMPILER_DATAFLOW_ANNOTATIONS_H
#define ZORBA_COMPILER_DATAFLOW_ANNOTATIONS_H

#include "compiler/expression/expr_classes.h"

namespace zorba 
{

class UDFCallChain;


/*******************************************************************************

********************************************************************************/
class DataflowAnnotationsComputer 
{
public:
  DataflowAnnotationsComputer() { }

  ~DataflowAnnotationsComputer() { }
  
  void compute(expr* e);

private:
  void compute_var_decl_expr(var_decl_expr* e);
  void compute_block_expr(block_expr* e);
  void compute_wrapper_expr(wrapper_expr* e);
  void compute_var_expr(var_expr* e);
  void compute_var_set_expr(var_set_expr* e);
  void compute_flwor_expr(flwor_expr* e);
  void compute_trycatch_expr(trycatch_expr* e);
  void compute_promote_expr(promote_expr* e);
  void compute_if_expr(if_expr* e);
  void compute_fo_expr(fo_expr* e);
  void compute_instanceof_expr(instanceof_expr* e);
  void compute_treat_expr(treat_expr* e);
  void compute_castable_expr(castable_expr* e);
  void compute_cast_expr(cast_expr* e);
  void compute_name_cast_expr(name_cast_expr* e);
  void compute_validate_expr(validate_expr* e);
  void compute_extension_expr(extension_expr* e);
  void compute_relpath_expr(relpath_expr* e);
  void compute_axis_step_expr(axis_step_expr* e);
  void compute_match_expr(match_expr* e);
  void compute_const_expr(const_expr* e);
  void compute_order_expr(order_expr* e);
  void compute_elem_expr(elem_expr* e);
  void compute_doc_expr(doc_expr* e);
  void compute_attr_expr(attr_expr* e);
  void compute_text_expr(text_expr* e);
  void compute_pi_expr(pi_expr* e);
  
  void default_walk(expr* e);
  bool generic_compute(expr* e);
};


/*******************************************************************************

********************************************************************************/
class SourceFinder
{
  friend class MarkNodeCopyProps;

  typedef std::map<var_expr*, std::vector<expr*>* > VarSourcesMap;
  typedef std::pair<var_expr*, std::vector<expr*>* > VarSourcesPair;

  typedef std::map<user_function*, std::vector<expr*>* > UdfSourcesMap;
  typedef std::pair<user_function*, std::vector<expr*>* > UdfSourcesPair;

  typedef std::map<expr*, user_function*> SourceUdfMap;
  typedef std::pair<expr*, user_function*> SourceUdfMapPair;

protected:
  VarSourcesMap                theVarSourcesMap;
  UdfSourcesMap                theUdfSourcesMap;
  SourceUdfMap                 theSourceUdfMap;

  user_function              * theStartingUdf;

protected:
  void findNodeSourcesRec(
      expr* node,
      std::vector<expr*>& sources,
      user_function* currentUdf);

public:
  ~SourceFinder();

  void findNodeSources(
      expr* inExpr,
      UDFCallChain* udfChain,
      std::vector<expr*>& sources);
};


}
#endif /* ZORBA_DATAFLOW_ANNOTATIONS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
