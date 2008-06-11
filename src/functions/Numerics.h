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
#ifndef ZORBA_NUMERICS_H
#define ZORBA_NUMERICS_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {

class zorba;

// Zorba specific functions:

/**
 * Function to produce a fixed amount of integer for testing purposes.
 */
class zor_numgen : public function
{
public:
	zor_numgen(const signature& sig) : function (sig) {}
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

void populateContext_Numerics(static_context *sctx);
void populateContext_Math (static_context *sctx);

}	/* namespace zorba */
#endif	/* ZORBA_NUMERICS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
