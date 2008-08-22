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
#ifndef ZORBA_COLLECTION_H
#define ZORBA_COLLECTION_H

#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {

class zorba_import_xml : public function
{
  public:
    zorba_import_xml(const signature& sig): function(sig){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};


class zorba_import_catalog : public function
{
  public:
    zorba_import_catalog(const signature& sig): function(sig){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

class zorba_import_folder : public function
{
  public:
    zorba_import_folder(const signature& sig): function(sig){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

class zorba_list_collections : public function
{
  public:
    zorba_list_collections(const signature& sig): function(sig){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

class zorba_create_collection : public function
{
  public:
    zorba_create_collection(const signature& sig): function(sig){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

class zorba_delete_collection : public function
{
  public:
    zorba_delete_collection(const signature& sig): function(sig){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

class zorba_delete_all_collections : public function
{
  public:
    zorba_delete_all_collections(const signature& sig): function(sig){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

class zorba_insert_nodes_first : public function
{
  public:
    zorba_insert_nodes_first(const signature& sig): function(sig){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

class zorba_insert_nodes_last : public function
{
  public:
    zorba_insert_nodes_last(const signature& sig): function(sig){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

class zorba_insert_nodes_before : public function
{
  public:
    zorba_insert_nodes_before(const signature& sig): function(sig){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

class zorba_insert_nodes_after : public function
{
  public:
    zorba_insert_nodes_after(const signature& sig): function(sig){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

class zorba_insert_nodes_at : public function
{
  public:
    zorba_insert_nodes_at(const signature& sig): function(sig){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

class zorba_remove_nodes : public function
{
  public:
    zorba_remove_nodes(const signature& sig): function(sig){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

class zorba_remove_node_at : public function
{
  public:
    zorba_remove_node_at(const signature& sig): function(sig){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

class zorba_nodes_count : public function
{
  public:
    zorba_nodes_count(const signature& sig): function(sig){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

class zorba_node_at : public function
{
  public:
    zorba_node_at(const signature& sig): function(sig){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

class zorba_index_of : public function
{
  public:
    zorba_index_of(const signature& sig): function(sig){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

class zorba_export_xml : public function
{
  public:
    zorba_export_xml(const signature& sig): function(sig){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};
} /* namespace zorba */

#endif
