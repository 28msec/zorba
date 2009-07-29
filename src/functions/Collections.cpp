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

namespace zorba 
{

PlanIter_t
zorba_collection_exists::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaCollectionExistsIterator(sctx, loc, argv);
}


PlanIter_t
zorba_import_xml::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaImportXmlIterator(sctx, loc, argv);
}

PlanIter_t
zorba_import_catalog::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaImportCatalogIterator(sctx, loc, argv);
}

PlanIter_t
zorba_import_folder::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaImportFolderIterator(sctx, loc, argv);
}

PlanIter_t
zorba_list_collections::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaListCollectionsIterator(sctx, loc, argv);
}

PlanIter_t
zorba_create_collection::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaCreateCollectionIterator(sctx, loc, argv);
}

PlanIter_t
zorba_delete_collection::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaDeleteCollectionIterator(sctx, loc, argv);
}

PlanIter_t
zorba_delete_all_collections::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaDeleteAllCollectionsIterator(sctx, loc, argv);
}

PlanIter_t
zorba_insert_nodes_first::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaInsertNodeFirstIterator(sctx, loc, argv);
}

PlanIter_t
zorba_insert_nodes_last::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaInsertNodeLastIterator(sctx, loc, argv);
}

PlanIter_t
zorba_insert_nodes_before::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaInsertNodeBeforeIterator(sctx, loc, argv);
}

PlanIter_t
zorba_insert_nodes_after::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaInsertNodeAfterIterator(sctx, loc, argv);
}

PlanIter_t
zorba_insert_nodes_at::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaInsertNodeAtIterator(sctx, loc, argv);
}

PlanIter_t
zorba_remove_nodes::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaRemoveNodeIterator(sctx, loc, argv);
}

PlanIter_t
zorba_remove_node_at::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaRemoveNodeAtIterator(sctx, loc, argv);
}

PlanIter_t
zorba_nodes_count::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaNodeCountIterator(sctx, loc, argv);
}

PlanIter_t
zorba_node_at::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaNodeAtIterator(sctx, loc, argv);
}

PlanIter_t
zorba_index_of::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaIndexOfIterator(sctx, loc, argv);
}

PlanIter_t
zorba_export_xml::codegen (CompilerCB* /*cb*/, short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaExportXmlIterator(sctx, loc, argv);
}

} /* namespace zorba */
