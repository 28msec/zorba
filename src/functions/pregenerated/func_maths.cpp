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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************


#include "runtime/maths/maths.h"
#include "functions/func_maths.h"


namespace zorba{



PlanIter_t fn_zorba_math_sqrt::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new SqrtIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_exp::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ExpIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_log::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new LogIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_sin::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new SinIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_cos::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new CosIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_tan::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new TanIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_asin::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ArcSinIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_acos::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ArcCosIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_atan::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ArcTanIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_atan2::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new Atan2Iterator(sctx, loc, argv[0], argv[1]);
}

PlanIter_t fn_zorba_math_cosh::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new CoshIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_acosh::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new AcoshIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_fmod::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FmodIterator(sctx, loc, argv[0], argv[1]);
}

PlanIter_t fn_zorba_math_ldexp::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new LdexpIterator(sctx, loc, argv[0], argv[1]);
}

PlanIter_t fn_zorba_math_log10::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new Log10Iterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_pow::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new PowIterator(sctx, loc, argv[0], argv[1]);
}

PlanIter_t fn_zorba_math_sinh::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new SinhIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_asinh::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new AsinhIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_tanh::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new TanhIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_atanh::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new AtanhIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_pi::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new PiNumberIterator(sctx, loc);
}

PlanIter_t fn_zorba_math_isInf::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsInfIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_isNaN::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsNaNIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_modf::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ModfIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_frexp::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FrexpIterator(sctx, loc, argv[0]);
}

void populate_context_maths(static_context* sctx)
{
  DECL(sctx, fn_zorba_math_sqrt,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","sqrt"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_exp,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","exp"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_log,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","log"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_sin,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","sin"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_cos,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","cos"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_tan,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","tan"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_asin,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","asin"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_acos,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","acos"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_atan,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","atan"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_atan2,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","atan2"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_PLUS));


  DECL(sctx, fn_zorba_math_cosh,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","cosh"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_acosh,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","acosh"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_fmod,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","fmod"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_ldexp,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","ldexp"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_log10,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","log10"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_pow,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","pow"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_sinh,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","sinh"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_asinh,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","asinh"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_tanh,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","tanh"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_atanh,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","atanh"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_pi,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","pi"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_zorba_math_isInf,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","isInf"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));


  DECL(sctx, fn_zorba_math_isNaN,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","isNaN"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));


  DECL(sctx, fn_zorba_math_modf,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","modf"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_PLUS));


  DECL(sctx, fn_zorba_math_frexp,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","frexp"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_PLUS));

}


}



