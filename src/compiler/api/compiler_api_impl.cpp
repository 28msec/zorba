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

#include "compiler/api/compiler_api_impl.h"
#include "compiler/api/compilercb.h"
#include "compiler/rewriter/rewriters/default_optimizer.h"


namespace zorba {

XQueryCompilerSubsystemImpl::XQueryCompilerSubsystemImpl()
  :
  m_defaultOptimizer(new DefaultOptimizer())
{
}


XQueryCompilerSubsystemImpl::~XQueryCompilerSubsystemImpl()
{
}


Rewriter *XQueryCompilerSubsystemImpl::getDefaultOptimizingRewriter()
{
  return m_defaultOptimizer.get();
}

}
/* vim:set et sw=2 ts=2: */
