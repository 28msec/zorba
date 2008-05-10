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
#ifndef ZORBA_COMPILER_API_IMPL_H
#define ZORBA_COMPILER_API_IMPL_H

#include "compiler/api/compiler_api.h"

namespace zorba {

class XQueryCompilerSubsystemImpl : public XQueryCompilerSubsystem 
{
 friend class XQueryCompilerSubsystem;

 private:
  std::auto_ptr<Rewriter> m_defaultOptimizer;

 public:
  ~XQueryCompilerSubsystemImpl() throw ();

  Rewriter *getDefaultOptimizingRewriter();

 private:
  XQueryCompilerSubsystemImpl();
};

} /* namespace zorba */
#endif /* ZORBA_COMPILER_API_IMPL_H */
/* vim:set ts=2 sw=2: */
