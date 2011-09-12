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
#ifndef ZORBA_STORE_ANNOTATION_H
#define ZORBA_STORE_ANNOTATION_H

#include <zorba/config.h>
#include "zorbatypes/schema_types.h"
#include "store/api/shared_types.h"


namespace zorba { namespace store {

  class Annotation : public RCObject
  {
    protected:
      SYNC_CODE(mutable RCLock theRCLock;)
    
    public:
      SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })

      long* getSharedRefCounter() const { return NULL; } 

      virtual ~Annotation() {}

    public:
      Item_t theName;
      std::vector<Item_t> theLiterals;
  };

} /* namespace store */ } /* namespace zorba */

#endif
