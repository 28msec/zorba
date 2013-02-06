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
  
#define BASE_NODE(item) (static_cast<XmlNode*>((item).getp()))

#define INTERNAL_NODE(item) (static_cast<InternalNode*>((item).getp()))

#define DOC_NODE(item) (static_cast<DocumentNode*>((item).getp()))

#define ATTR_NODE(item) (static_cast<AttributeNode*>((item).getp()))

#define ELEM_NODE(item) (static_cast<ElementNode*>((item).getp()))

#define TEXT_NODE(item) (static_cast<TextNode*>((item).getp()))

#define PI_NODE(item) (static_cast<PiNode*>((item).getp()))

#define COMMENT_NODE(item) (static_cast<CommentNode*>((item).getp()))


#ifndef NDEBUG

#define STORE_TRACE(level, msg)               \
{                                             \
  if (level <= GET_STORE().getTraceLevel())   \
    std::cout << msg << std::endl;            \
}

#define STORE_TRACE1(msg) STORE_TRACE(1, msg);
#define STORE_TRACE2(msg) STORE_TRACE(2, msg);
#define STORE_TRACE3(msg) STORE_TRACE(3, msg);

#else

#define STORE_TRACE(msg)
#define STORE_TRACE1(msg)
#define STORE_TRACE2(msg)
#define STORE_TRACE3(msg)

#endif

}
}
#endif
/* vim:set et sw=2 ts=2: */
