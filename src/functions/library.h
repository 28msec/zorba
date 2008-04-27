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
#ifndef ZORBA_LIBRARY_H
#define ZORBA_LIBRARY_H


#include "common/shared_types.h"

namespace zorba {

class static_context;

class BuiltinFunctionLibrary {
    private:
        static void populateContext(static_context *sctx);
        friend class GlobalEnvironment;
};


} /* namespace zorba */
#endif /* ZORBA_LIBRARY_H */

