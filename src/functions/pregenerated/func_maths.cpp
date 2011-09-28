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


#include "stdafx.h"
#include "runtime/maths/maths.h"
#include "functions/func_maths.h"


namespace zorba{



PlanIter_t math_sqrt::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new SqrtIterator(sctx, loc, argv[0]);
}

PlanIter_t math_exp::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ExpIterator(sctx, loc, argv[0]);
}

PlanIter_t math_exp10::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new Exp10Iterator(sctx, loc, argv[0]);
}

PlanIter_t math_log::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new LogIterator(sctx, loc, argv[0]);
}

PlanIter_t math_log10::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new Log10Iterator(sctx, loc, argv[0]);
}

PlanIter_t math_sin::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new SinIterator(sctx, loc, argv[0]);
}

PlanIter_t math_cos::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new CosIterator(sctx, loc, argv[0]);
}

PlanIter_t math_tan::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new TanIterator(sctx, loc, argv[0]);
}

PlanIter_t math_asin::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ArcSinIterator(sctx, loc, argv[0]);
}

PlanIter_t math_acos::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ArcCosIterator(sctx, loc, argv[0]);
}

PlanIter_t math_atan::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ArcTanIterator(sctx, loc, argv[0]);
}

PlanIter_t math_atan2::codegen(
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

PlanIter_t math_pow::codegen(
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

PlanIter_t math_pi::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new PiNumberIterator(sctx, loc);
}

PlanIter_t fn_zorba_math_is_inf::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsInfIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_math_is_nan::codegen(
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
  {
    

    DECL_WITH_KIND(sctx, math_sqrt,
        (createQName("http://www.w3.org/2005/xpath-functions/math","","sqrt"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION),
        FunctionConsts::MATH_SQRT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, math_exp,
        (createQName("http://www.w3.org/2005/xpath-functions/math","","exp"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION),
        FunctionConsts::MATH_EXP_1);

  }


  {
    

    DECL_WITH_KIND(sctx, math_exp10,
        (createQName("http://www.w3.org/2005/xpath-functions/math","","exp10"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION),
        FunctionConsts::MATH_EXP10_1);

  }


  {
    

    DECL_WITH_KIND(sctx, math_log,
        (createQName("http://www.w3.org/2005/xpath-functions/math","","log"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION),
        FunctionConsts::MATH_LOG_1);

  }


  {
    

    DECL_WITH_KIND(sctx, math_log10,
        (createQName("http://www.w3.org/2005/xpath-functions/math","","log10"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION),
        FunctionConsts::MATH_LOG10_1);

  }


  {
    

    DECL_WITH_KIND(sctx, math_sin,
        (createQName("http://www.w3.org/2005/xpath-functions/math","","sin"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION),
        FunctionConsts::MATH_SIN_1);

  }


  {
    

    DECL_WITH_KIND(sctx, math_cos,
        (createQName("http://www.w3.org/2005/xpath-functions/math","","cos"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION),
        FunctionConsts::MATH_COS_1);

  }


  {
    

    DECL_WITH_KIND(sctx, math_tan,
        (createQName("http://www.w3.org/2005/xpath-functions/math","","tan"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION),
        FunctionConsts::MATH_TAN_1);

  }


  {
    

    DECL_WITH_KIND(sctx, math_asin,
        (createQName("http://www.w3.org/2005/xpath-functions/math","","asin"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION),
        FunctionConsts::MATH_ASIN_1);

  }


  {
    

    DECL_WITH_KIND(sctx, math_acos,
        (createQName("http://www.w3.org/2005/xpath-functions/math","","acos"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION),
        FunctionConsts::MATH_ACOS_1);

  }


  {
    

    DECL_WITH_KIND(sctx, math_atan,
        (createQName("http://www.w3.org/2005/xpath-functions/math","","atan"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION),
        FunctionConsts::MATH_ATAN_1);

  }


  {
    

    DECL_WITH_KIND(sctx, math_atan2,
        (createQName("http://www.w3.org/2005/xpath-functions/math","","atan2"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE),
        FunctionConsts::MATH_ATAN2_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_math_cosh,
        (createQName("http://www.zorba-xquery.com/modules/math","","cosh"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE),
        FunctionConsts::FN_ZORBA_MATH_COSH_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_math_acosh,
        (createQName("http://www.zorba-xquery.com/modules/math","","acosh"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE),
        FunctionConsts::FN_ZORBA_MATH_ACOSH_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_math_fmod,
        (createQName("http://www.zorba-xquery.com/modules/math","","fmod"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE),
        FunctionConsts::FN_ZORBA_MATH_FMOD_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_math_ldexp,
        (createQName("http://www.zorba-xquery.com/modules/math","","ldexp"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE),
        FunctionConsts::FN_ZORBA_MATH_LDEXP_2);

  }


  {
    

    DECL_WITH_KIND(sctx, math_pow,
        (createQName("http://www.w3.org/2005/xpath-functions/math","","pow"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION),
        FunctionConsts::MATH_POW_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_math_sinh,
        (createQName("http://www.zorba-xquery.com/modules/math","","sinh"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE),
        FunctionConsts::FN_ZORBA_MATH_SINH_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_math_asinh,
        (createQName("http://www.zorba-xquery.com/modules/math","","asinh"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE),
        FunctionConsts::FN_ZORBA_MATH_ASINH_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_math_tanh,
        (createQName("http://www.zorba-xquery.com/modules/math","","tanh"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE),
        FunctionConsts::FN_ZORBA_MATH_TANH_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_math_atanh,
        (createQName("http://www.zorba-xquery.com/modules/math","","atanh"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE),
        FunctionConsts::FN_ZORBA_MATH_ATANH_1);

  }


  {
    

    DECL_WITH_KIND(sctx, math_pi,
        (createQName("http://www.w3.org/2005/xpath-functions/math","","pi"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE),
        FunctionConsts::MATH_PI_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_math_is_inf,
        (createQName("http://www.zorba-xquery.com/modules/math","","is_inf"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_MATH_IS_INF_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_math_is_nan,
        (createQName("http://www.zorba-xquery.com/modules/math","","is_nan"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_MATH_IS_NAN_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_math_modf,
        (createQName("http://www.zorba-xquery.com/modules/math","","modf"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_PLUS),
        FunctionConsts::FN_ZORBA_MATH_MODF_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_math_frexp,
        (createQName("http://www.zorba-xquery.com/modules/math","","frexp"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_PLUS),
        FunctionConsts::FN_ZORBA_MATH_FREXP_1);

  }

}


}



