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
#ifndef ZORBA_SEQUENTIAL_REWRITER_H
#define ZORBA_SEQUENTIAL_REWRITER_H

#include <vector>
#include "common/shared_types.h"
#include "compiler/rewriter/framework/rewriter.h"

namespace zorba 
{

/***************************************************************************//**
  Contains a vector V of other rewriters. SequentialRewriter::rewrite() simply
  invokes the rewrtite() method on the rewriters in V, in the order that these
  rewriters appear in V.
********************************************************************************/
class SequentialRewriter : public Rewriter 
{
protected:
  typedef rchandle<Rewriter> rewriter_ptr_t;
  typedef std::vector<rewriter_ptr_t> rewriters_t;

protected:
  rewriters_t m_childRewriters;

public:
  virtual bool rewrite(RewriterContext& rCtx);

protected:
  SequentialRewriter();

  ~SequentialRewriter();
};

}

#endif /* ZORBA_SEQUENTIAL_REWRITER_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
