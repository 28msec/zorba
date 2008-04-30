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
#include <vector>

#include "system/globalenv.h"
#include "functions/arithmetic.h"
#include "runtime/core/arithmetic_impl.h"

using namespace std;

namespace zorba {

PlanIter_t op_add::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new GenericArithIterator<AddOperation>(loc, argv[0], argv[1]);
}



PlanIter_t op_subtract::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new GenericArithIterator<SubtractOperation>(loc, argv[0], argv[1]);
}



PlanIter_t op_multiply::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new GenericArithIterator<MultiplyOperation>(loc, argv[0], argv[1]);
}



PlanIter_t op_divide::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new GenericArithIterator<DivideOperation>(loc, argv[0], argv[1]);
}



PlanIter_t op_integer_divide::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new GenericArithIterator<IntegerDivideOperation>(loc, argv[0], argv[1]);
}



PlanIter_t op_mod::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new GenericArithIterator<ModOperation>(loc, argv[0], argv[1]);
}




}
