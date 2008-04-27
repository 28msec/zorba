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
#include "compiler/rewriter/framework/sequential_rewriter.h"

namespace zorba {

SequentialRewriter::SequentialRewriter()
{
}

SequentialRewriter::~SequentialRewriter() throw ()
{
}

void SequentialRewriter::rewrite(RewriterContext& rCtx)
{
  rewriters_t::const_iterator end = m_childRewriters.end();
  for(rewriters_t::const_iterator i = m_childRewriters.begin(); i != end; ++i) {
    (*i)->rewrite(rCtx);
  }
}

}
/* vim:set ts=2 sw=2: */
