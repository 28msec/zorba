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
#ifndef ZORBA_SIMPLE_STORE_STORE_DEFS_H
#define ZORBA_SIMPLE_STORE_STORE_DEFS_H

#include "store_manager_impl.h"

namespace zorba { 

namespace simplestore {


//#define EMBEDED_TYPE
//#define TEXT_ORDPATH


#define GET_STORE() \
  (*zorba::simplestore::StoreManagerImpl::getStoreInternal())

#define GET_FACTORY() \
  (*(reinterpret_cast<BasicItemFactory*>(GET_STORE().getItemFactory())))

#define GET_NODE_FACTORY() \
  (GET_STORE().getNodeFactory())

#define GET_PUL_FACTORY() \
  (GET_STORE().getPULFactory())
  
#define GET_DEFAULT_TREE_ID_GENERATOR() \
  (GET_STORE().getTreeIdGeneratorFactory().getDefaultTreeIdGenerator())


#define BASE_NODE(item) (reinterpret_cast<XmlNode*>((item).getp()))

#define INTERNAL_NODE(item) (reinterpret_cast<InternalNode*>((item).getp()))

#define DOC_NODE(item) (reinterpret_cast<DocumentNode*>((item).getp()))

#define ATTR_NODE(item) (reinterpret_cast<AttributeNode*>((item).getp()))

#define ELEM_NODE(item) (reinterpret_cast<ElementNode*>((item).getp()))

#define TEXT_NODE(item) (reinterpret_cast<TextNode*>((item).getp()))

#define PI_NODE(item) (reinterpret_cast<PiNode*>((item).getp()))

#define COMMENT_NODE(item) (reinterpret_cast<CommentNode*>((item).getp()))

}
}
#endif
/* vim:set et sw=2 ts=2: */
