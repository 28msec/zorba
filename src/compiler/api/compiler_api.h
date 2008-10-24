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
#ifndef ZORBA_COMPILER_API_H
#define ZORBA_COMPILER_API_H

#include <memory>
#include "zorbatypes/representations.h"

#include "common/shared_types.h"

namespace zorba {

class XQueryCompiler 
{
 public:

  CompilerCB* theCompilerCB;

 public:
  XQueryCompiler(CompilerCB*  aCompilerCB);
    
  virtual ~XQueryCompiler();
    
  parsenode_t parse(std::istream& aXQuery, const xqpString & aFileName = "");

  void parseOnly(std::istream& aXQuery, const xqpString& aFileName);

  PlanIter_t compile(std::istream& aXQuery, const xqpString & aFileName = "");
  PlanIter_t compile(parsenode_t);
    
 protected:
  expr_t normalize(parsenode_t);
    
  expr_t optimize(expr_t lExpr);
};


class XQueryCompilerSubsystem 
{
  friend class GlobalEnvironment;

 public:
  XQueryCompilerSubsystem();

  virtual ~XQueryCompilerSubsystem() throw ();

  virtual Rewriter *getDefaultOptimizingRewriter() = 0;

 private:
  static std::auto_ptr<XQueryCompilerSubsystem> create();
};

} /* namespace zorba */
#endif /* ZORBA_COMPILER_API_H */
/* vim:set ts=2 sw=2: */
