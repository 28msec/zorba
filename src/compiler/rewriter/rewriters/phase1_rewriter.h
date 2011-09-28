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
#ifndef ZORBA_PHASE1_REWRITER_H
#define ZORBA_PHASE1_REWRITER_H

#include "common/shared_types.h"
#include "compiler/rewriter/framework/sequential_rewriter.h"

namespace zorba {

class Phase1Rewriter : public SequentialRewriter 
{
public:
  Phase1Rewriter();
  ~Phase1Rewriter();
};

}

#endif /* ZORBA_PHASE1_REWRITER_H */


/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
