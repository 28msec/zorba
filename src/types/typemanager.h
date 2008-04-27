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
#ifndef ZORBA_TYPEMANAGER_H
#define ZORBA_TYPEMANAGER_H

#include <ostream>
#include <boost/shared_ptr.hpp>
#include <zorba/typeident.h>
#include "util/rchandle.h"
#include "common/shared_types.h"
#include "types/typeconstants.h"


namespace zorba {

class NodeTest;

/*
 * Interface used by other parts of zorba to ask questions about types.
 */
class TypeManager {
  public:
    TypeManager(int level) : m_level(level) { }
    virtual ~TypeManager() { }

    virtual TypeManager *get_parent_type_manager() const = 0;

    virtual int level() const { return m_level; }

    /* Factory Methods */
    virtual xqtref_t create_type_x_quant(
        const XQType& type,
        TypeConstants::quantifier_t quantifier) const = 0;

    virtual xqtref_t create_type(
        const XQType& type,
        TypeConstants::quantifier_t quantifier) const = 0;

    virtual xqtref_t create_type(const TypeIdentifier& ident) const = 0;

    virtual xqtref_t create_value_type(store::Item* item) const = 0;

    virtual xqtref_t create_named_type(
        store::Item* qname,
        TypeConstants::quantifier_t quantifier = TypeConstants::QUANT_ONE) const = 0;

    virtual xqtref_t create_named_atomic_type(
        store::Item* qname,
        TypeConstants::quantifier_t quantifier) const = 0;

    virtual xqtref_t create_atomic_type(
        TypeConstants::atomic_type_code_t type_code,
        TypeConstants::quantifier_t quantifier) const = 0;

    virtual xqtref_t create_node_type(
        rchandle<NodeTest> nodetest,
        xqtref_t content_type,
        TypeConstants::quantifier_t quantifier) const = 0;

    virtual xqtref_t create_any_type() const = 0;

    virtual xqtref_t create_any_item_type(TypeConstants::quantifier_t quantifier) const = 0;

    virtual xqtref_t create_any_simple_type() const = 0;

    virtual xqtref_t create_untyped_type() const = 0;

    virtual xqtref_t create_empty_type() const = 0;

    virtual xqtref_t create_none_type() const = 0;
    

  protected:
    int m_level;
};

}

#endif /* ZORBA_TYPEMANAGER_H */
/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
