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
#ifndef ZORBA_RUNTIME_UTIL_DOC_URI_HEURISTICS_H
#define ZORBA_RUNTIME_UTIL_DOC_URI_HEURISTICS_H

#include "stdafx.h"
#include <zorba/config.h>

#include <zorbatypes/zstring.h>

namespace zorba {

class static_context;
class QueryLoc;

/**
 * Utility method for fn:doc() and jn:json-doc(). Given an input string,
 * use a few heuristics to create a valid URI, assuming that the input might
 * be an absolute or relative filesystem path, etc.
 */
void normalizeInputUri(
    zstring const& aUri,
    static_context* aSctx,
    QueryLoc const& aLoc,
    zstring* aResult);
  
} /* namespace zorba */
/* vim:set et sw=2 ts=2: */

#endif /* ZORBA_RUNTIME_UTIL_DOC_URI_HEURISTICS_H */
