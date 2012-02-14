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
 #include "stdafx.h"

#include "functions/func_ft_module.h"

#include "runtime/full_text/ft_module.h"


namespace zorba
{

/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_full_text_tokenizer_properties::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new TokenizerPropertiesIterator(theModuleSctx, loc, argv);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_full_text_tokenize::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new TokenizeIterator(theModuleSctx, loc, argv);
}


}
