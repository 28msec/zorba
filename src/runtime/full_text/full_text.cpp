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
 
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/full_text/full_text.h"
#include "system/globalenv.h"

/******************************************************************************
 *                                                                            *
 * This USED to be a generated file, but isn't currently because the formerly *
 * corresponding .xml file with the same name wasn't sufficiently flexible.   *
 *                                                                            *
 * The code that's in this file is the same as what would have been           *
 * generated.                                                                 *
 *                                                                            *
 ******************************************************************************/

namespace zorba {

const char* FTContainsIterator::class_name_str = "FTContainsIterator";
FTContainsIterator::class_factory<FTContainsIterator>
  FTContainsIterator::g_class_factory;

const serialization::ClassVersion 
  FTContainsIterator::class_versions[] = { { 1, 0x000905, false } };

const int FTContainsIterator::class_versions_count =
  sizeof( FTContainsIterator::class_versions ) /
  sizeof( struct serialization::ClassVersion );

void FTContainsIterator::accept( PlanIterVisitor &v ) const {
  v.beginVisit( *this );
  theChild0->accept( v );
  if ( theChild1 )                      // optional ftignore
    theChild1->accept( v );
  v.endVisit( *this );
}

FTContainsIterator::~FTContainsIterator() {
}

}
/* vim:set et sw=2 ts=2: */
