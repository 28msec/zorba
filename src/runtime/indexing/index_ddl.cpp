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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************

#include "runtime/visitors/planiter_visitor.h"
#include "runtime/indexing/index_ddl.h"
#include "system/globalenv.h"


#include "store/api/iterator.h"

namespace zorba {

// <CreateIndexIterator>
const char* CreateIndexIterator::class_name_str = "CreateIndexIterator";
CreateIndexIterator::class_factory<CreateIndexIterator>
CreateIndexIterator::g_class_factory;

const serialization::ClassVersion 
CreateIndexIterator::class_versions[] ={{ 1, 0x000905, false}};

const int CreateIndexIterator::class_versions_count =
sizeof(CreateIndexIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void CreateIndexIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

CreateIndexIterator::~CreateIndexIterator() {}

// </CreateIndexIterator>


// <DeleteIndexIterator>
const char* DeleteIndexIterator::class_name_str = "DeleteIndexIterator";
DeleteIndexIterator::class_factory<DeleteIndexIterator>
DeleteIndexIterator::g_class_factory;

const serialization::ClassVersion 
DeleteIndexIterator::class_versions[] ={{ 1, 0x000905, false}};

const int DeleteIndexIterator::class_versions_count =
sizeof(DeleteIndexIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void DeleteIndexIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

DeleteIndexIterator::~DeleteIndexIterator() {}

// </DeleteIndexIterator>



}