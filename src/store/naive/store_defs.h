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

#include "store/naive/store_manager_impl.h"

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


#define BASE_NODE(item) (reinterpret_cast<XmlNode*>((item).getp()))

#define INTERNAL_NODE(item) (reinterpret_cast<InternalNode*>((item).getp()))

#define DOC_NODE(item) (reinterpret_cast<DocumentNode*>((item).getp()))

#define ATTR_NODE(item) (reinterpret_cast<AttributeNode*>((item).getp()))

#define ELEM_NODE(item) (reinterpret_cast<ElementNode*>((item).getp()))

#define TEXT_NODE(item) (reinterpret_cast<TextNode*>((item).getp()))

#define PI_NODE(item) (reinterpret_cast<PiNode*>((item).getp()))

#define COMMENT_NODE(item) (reinterpret_cast<CommentNode*>((item).getp()))


/*******************************************************************************
  !!! ATTENTION: The order of thr enum values within SchemaTypeCode is important.
  !!! DO NOT change this order!!!!
********************************************************************************/
enum SchemaTypeCode
{
  XS_UNTYPED = 0,

  XS_ANY,

  XS_ANY_SIMPLE,

  XS_ANY_ATOMIC,

  XS_UNTYPED_ATOMIC,

  XS_ANY_URI,

  XS_QNAME,

  XS_NOTATION,

  XS_STRING,
  XS_NORMALIZED_STRING,
  XS_TOKEN,
  XS_NMTOKEN,
  XS_LANGUAGE,
  XS_NAME,
  XS_NCNAME,
  XS_ID,
  XS_IDREF,
  XS_ENTITY,

  XS_DATETIME,
  XS_DATE,
  XS_TIME,

  XS_GYEAR_MONTH,
  XS_GYEAR,
  XS_GMONTH_DAY,
  XS_GDAY,
  XS_GMONTH,

  XS_DURATION,
  XS_DT_DURATION,
  XS_YM_DURATION,

  XS_FLOAT,
  XS_DOUBLE,
  XS_DECIMAL,
  XS_INTEGER,
  XS_NON_POSITIVE_INTEGER,
  XS_NON_NEGATIVE_INTEGER,
  XS_NEGATIVE_INTEGER,
  XS_POSITIVE_INTEGER,
  XS_LONG,
  XS_INT,
  XS_SHORT,
  XS_BYTE,
  XS_UNSIGNED_LONG,
  XS_UNSIGNED_INT,
  XS_UNSIGNED_SHORT,
  XS_UNSIGNED_BYTE,

  XS_BASE64BINARY,
  XS_HEXBINARY,
  XS_BOOLEAN,

  ZXSE_ERROR,

  ZXSE_TUPLE,

  XS_LAST
};


enum IndexKeyTypeCode
{
  IDX_XS_STRING,

  IDX_XS_DOUBLE,

  IDX_XS_DECIMAL,

  IDX_XS_INTEGER,

  IDX_XS_LONG,

  IDX_XS_BASE64BINARY,

  IDX_XS_HEXBINARY,

  IDX_XS_BOOLEAN,

  IDX_XS_DATETIME,

  IDX_XS_DURATION,

  IDX_XS_QNAME,

  IDX_XS_LAST
};


}
}
#endif
/* vim:set et sw=2 ts=2: */
