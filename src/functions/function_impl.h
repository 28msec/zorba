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
#ifndef ZORBA_FUNCTIONS_FUNCTION_IMPL_H
#define ZORBA_FUNCTIONS_FUNCTION_IMPL_H

#include "system/globalenv.h"

#include "functions/function.h"
#include "functions/library.h"

#include "store/api/store.h"
#include "store/api/item_factory.h"

#include "context/static_context.h"

#ifndef NDEBUG

#include "system/properties.h"

#define DEBUG_FN_DECL(fname, cnt)                                     \
  if (Properties::instance()->dumpLib())                              \
    std::cout << "Bound function " << fname->getStringValue() << "/" << cnt << std::endl;

#else

#define DEBUG_FN_DECL( fname, cnt ) (void) 0

#endif


#define DECL(sctx, type, sig)                                           \
  do                                                                    \
  {                                                                     \
    function_t type##_ptr(new type(signature sig));                     \
    const store::Item* fname = type##_ptr->getName();                   \
    ulong cnt = type##_ptr->get_signature().arg_count();                \
    DEBUG_FN_DECL(fname, cnt);                                          \
    sctx->bind_fn(fname, type##_ptr, cnt, QueryLoc::null);              \
    BuiltinFunctionLibrary::theFunctions[type##_ptr->getKind()] = type##_ptr.getp(); \
  } while(0)


#define COMPUTE_ANNOTATION_DECL()                   \
virtual void compute_annotation(                    \
    AnnotationHolder* parent,                       \
    std::vector<AnnotationHolder *>& kids,          \
    Annotations::Key k) const;


#define CODEGEN_DECL()                                    \
PlanIter_t codegen(CompilerCB* cb,                        \
                   static_context* sctx,                  \
                   const QueryLoc& loc,                   \
                   std::vector<PlanIter_t>& argv,         \
                   AnnotationHolder& ann) const;          \


#define CODEGEN_DEF(class)                                \
PlanIter_t class::codegen(CompilerCB* aCb,                \
                          static_context* aSctx,          \
                          const QueryLoc& aLoc,           \
                          std::vector<PlanIter_t>& aArgs, \
                          AnnotationHolder& aAnn) const


#define DEFAULT_NARY_CODEGEN(Iter)                        \
PlanIter_t codegen(CompilerCB* /* cb */,                  \
                   static_context* sctx,                  \
                   const QueryLoc& loc,                   \
                   std::vector<PlanIter_t>& argv,         \
                   AnnotationHolder &/*ann*/) const       \
{                                                         \
  return new Iter(sctx, loc, argv);                       \
}


#define DEFAULT_BINARY_CODEGEN(Iter)                      \
PlanIter_t codegen(CompilerCB* /* cb */,                  \
                   static_context* sctx,                  \
                   const QueryLoc& loc,                   \
                   std::vector<PlanIter_t>& argv,         \
                   AnnotationHolder &/*ann*/) const       \
{                                                         \
  return new Iter(sctx, loc, argv[0], argv[1]);           \
}


#define DEFAULT_UNARY_CODEGEN(Iter)                       \
PlanIter_t codegen(CompilerCB* /* cb */,                  \
                   static_context* sctx,                  \
                   const QueryLoc& loc,                   \
                   std::vector<PlanIter_t>& argv,         \
                   AnnotationHolder &/*ann*/) const       \
{                                                         \
  return new Iter(sctx, loc, argv[0]);                    \
}


#define DEFAULT_NOARY_CODEGEN(Iter)                       \
PlanIter_t codegen(CompilerCB* /* cb */,                  \
                   static_context* sctx,                  \
                   const QueryLoc& loc,                   \
                   std::vector<PlanIter_t>& argv,         \
                   AnnotationHolder &/*ann*/) const       \
{                                                         \
  return new Iter(sctx, loc);                             \
}



namespace zorba 
{

static inline store::Item_t createQName(
    const char* ns,
    const char* pre,
    const char* local)
{
  store::Item_t res;
  GENV_ITEMFACTORY->createQName(res, ns, pre, local);
  return res;
}



template <class Iter> class function_impl : public function 
{
public:
  function_impl(const signature& sig) : function(sig) {}

  DEFAULT_NARY_CODEGEN(Iter)
};


}	/* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
