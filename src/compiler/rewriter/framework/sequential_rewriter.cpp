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

#include "compiler/rewriter/framework/sequential_rewriter.h"


namespace zorba {


SequentialRewriter::SequentialRewriter()
{
}


SequentialRewriter::~SequentialRewriter()
{
}


bool SequentialRewriter::rewrite(RewriterContext& rCtx)
{
  bool modified = false;

  rewriters_t::const_iterator end = m_childRewriters.end();

  for(rewriters_t::const_iterator i = m_childRewriters.begin(); i != end; ++i)
  {
    bool mod = (*i)->rewrite(rCtx);

    if (mod && modified == false)
      modified = true;
  }

  return modified;
}

}
/* vim:set et sw=2 ts=2: */
