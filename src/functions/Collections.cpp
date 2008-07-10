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

#include "system/globalenv.h"

#include "functions/Collections.h"
#include "runtime/collections/CollectionsImpl.h"

namespace zorba {
PlanIter_t
zorba_collection::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaCollectionIterator(loc, argv);
}

PlanIter_t
zorba_list_collections::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaListCollectionsIterator(loc, argv);
}

PlanIter_t
zorba_create_collection::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaCreateCollectionIterator(loc, argv);
}

PlanIter_t
zorba_delete_collection::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaDeleteCollectionIterator(loc, argv);
}

PlanIter_t
zorba_delete_all_collections::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaDeleteAllCollectionsIterator(loc, argv);
}

PlanIter_t
zorba_insert_node_first::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaInsertNodeFirstIterator(loc, argv);
}

PlanIter_t
zorba_insert_node_last::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaInsertNodeLastIterator(loc, argv);
}

PlanIter_t
zorba_insert_node_before::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaInsertNodeBeforeIterator(loc, argv);
}

PlanIter_t
zorba_insert_node_after::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaInsertNodeAfterIterator(loc, argv);
}

PlanIter_t
zorba_insert_node_at::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaInsertNodeAtIterator(loc, argv);
}

PlanIter_t
zorba_remove_node::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaRemoveNodeIterator(loc, argv);
}

PlanIter_t
zorba_remove_node_at::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaRemoveNodeAtIterator(loc, argv);
}

PlanIter_t
zorba_node_count::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaNodeCountIterator(loc, argv);
}

PlanIter_t
zorba_node_at::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaNodeAtIterator(loc, argv);
}

PlanIter_t
zorba_export_collection::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaExportCollectionIterator(loc, argv);
}

} /* namespace zorba */
