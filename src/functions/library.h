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

        static void populateContext_Accesors(static_context *sctx);
        static void populateContext_Error(static_context *sctx);
        static void populateContext_Nodes(static_context *sctx);
        static void populateContext_AnyURI(static_context *sctx);
        static void populateContext_Context(static_context *sctx);
        static void populateContext_QNames(static_context *sctx);
        static void populateContext_Sequences(static_context *sctx);
        static void populateContext_Comparison(static_context *sctx);
        static void populateContext_Boolean(static_context *sctx);
        static void populateContext_Constructors(static_context *sctx);
        static void populateContext_Debug(static_context *sctx);
        static void populateContext_Zorba(static_context *sctx);
        static void populateContext_ZorbaExtensions(static_context *sctx);
};

} /* namespace zorba */
#endif /* ZORBA_LIBRARY_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
