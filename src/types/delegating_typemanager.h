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
#ifndef ZORBA_DELEGATING_TYPEMANAGER_H
#define ZORBA_DELEGATING_TYPEMANAGER_H

#include "types/typemanagerimpl.h"
#include <zorba/typeident.h>
#include "common/shared_types.h"
#include "types/schema/schema.h"

namespace zorba {

/*
 * Interface used by other parts of zorba to ask questions about types.
 */
class DelegatingTypeManager : public TypeManagerImpl {
  public:
    DelegatingTypeManager(TypeManager *parent)
        : TypeManagerImpl(parent->level() + 1, parent) 
    {
        _schema = NULL; 
        initializeSchema();
    }
    
    virtual ~DelegatingTypeManager()
    {
        if ( _schema!=NULL )
            delete _schema;
    }


    virtual xqtref_t create_named_atomic_type(
        store::Item* qname,
        TypeConstants::quantifier_t quantifier) const;

    virtual xqtref_t create_named_type(
        store::Item* qname,
        TypeConstants::quantifier_t quantifier = TypeConstants::QUANT_ONE) const;

    void initializeSchema();
    void terminateSchema();
	 
    Schema* getSchema() const
    { 
        return _schema; 
    }
 
  private:
    Schema *_schema;
};

}

#endif /* ZORBA_DELEGATING_TYPEMANAGER_H */
/* vim:set ts=2 sw=2: */
