/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
#ifndef ZORBA_COMPILER_API_H
#define ZORBA_COMPILER_API_H

#include <memory>
#include "zorbatypes/schema_types.h"

#include "common/shared_types.h"
#include <zorba/api_shared_types.h>

namespace zorba 
{


/********************************************************************************

********************************************************************************/
class XQueryCompiler
{
public:

  CompilerCB  * theCompilerCB;

public:
  XQueryCompiler(CompilerCB* aCompilerCB);

  virtual ~XQueryCompiler();

  void parseOnly(std::istream& aXQuery, const zstring& aFileName);

  void xqdoc(
      std::istream& aXQuery,
      const zstring& aFileName,
      store::Item_t& aResult,
      const store::Item_t& aDateTime,
      uint32_t aOptions);

  parsenode_t parse(std::istream& aXQuery, const zstring& aFileName);

  PlanIter_t compile(
      std::istream& aXQuery,
      const zstring& fileName,
      ulong& nextDynamicVarId);

  PlanIter_t compile(
      const parsenode_t& ast,
      bool applyPUL,
      ulong& nextDynamicVarId,
      audit::ScopedRecord& auditRecord);

  expr* translate(parsenode_t ast, audit::ScopedRecord& ar);

  expr* optimize(expr* e, audit::ScopedRecord& ar);

  PlanIter_t codegen(expr* e, ulong& nextDynamicVarId, audit::ScopedRecord& ar);

private:
  bool getLanguageMode(std::stringstream& s) const;

  parsenode_t createMainModule(
      parsenode_t libModule,
      std::istream& xquery,
      const zstring& fileName);
};


/********************************************************************************

********************************************************************************/
class XQueryCompilerSubsystem
{
  friend class GlobalEnvironment;

public:
  XQueryCompilerSubsystem();

  virtual ~XQueryCompilerSubsystem();

  virtual Rewriter* getDefaultOptimizingRewriter() = 0;

private:
  static std::auto_ptr<XQueryCompilerSubsystem> create();
};


} /* namespace zorba */
#endif /* ZORBA_COMPILER_API_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
