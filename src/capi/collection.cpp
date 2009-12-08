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
#include "capi/collection.h"

#include <cassert>
#include <sstream>
#include <zorba/zorba.h>
#include "capi/capi_util.h"
#include "capi/item.h"
#include "capi/error.h"

using namespace zorba;

#define ZORBAC_COLLECTION_TRY try {
#define ZORBAC_COLLECTION_CATCH \
    return XQC_NO_ERROR;              \
  } catch (ZorbaException &e) {     \
      return Error::convert_xquery_error(e.getErrorCode()); \
  } catch (...) {                   \
    return XQC_INTERNAL_ERROR;  \
  }


namespace zorbac {

  zorba::Collection*
  getCollection(XQC_Collection collection)
  {
    return static_cast<zorba::Collection*>(collection->data);
  }

  XQC_Error
  Collection::get_name(XQC_Collection collection, XQC_Item_Ref name_item)
  {
    ZORBAC_COLLECTION_TRY
      zorba::Collection* lCollection = getCollection(collection);

      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = lCollection->getName();

      Item::assign_functions(lItem.get());

      (*name_item) = lItem.release();
      (*name_item)->data = lInnerItem.release();
    ZORBAC_COLLECTION_CATCH
  }

  XQC_Error
  Collection::add_node(XQC_Collection collection, XQC_Item node)
  {
    ZORBAC_COLLECTION_TRY
      zorba::Collection* lCollection = getCollection(collection);
      zorba::Item* lItem = static_cast<zorba::Item*>(node->data);

      lCollection->addNode(*lItem);
    ZORBAC_COLLECTION_CATCH
  }

  XQC_Error
  Collection::delete_node(XQC_Collection collection, XQC_Item node)
  {
    ZORBAC_COLLECTION_TRY
      zorba::Collection* lCollection = getCollection(collection);
      zorba::Item* lItem = static_cast<zorba::Item*>(node->data);

      lCollection->deleteNode(*lItem);
    ZORBAC_COLLECTION_CATCH
  }

  XQC_Error
  Collection::add_sequence(XQC_Collection collection, XQC_Sequence* sequence)
  {
    ZORBAC_COLLECTION_TRY
      zorba::Collection* lCollection = getCollection(collection);
      zorba::ResultIterator* lIter = static_cast<zorba::ResultIterator*>(sequence->data);

      lCollection->addNodes(lIter);
    ZORBAC_COLLECTION_CATCH
  }

  XQC_Error
  Collection::add_document(XQC_Collection collection, FILE* doc)
  {
    ZORBAC_COLLECTION_TRY
      zorba::Collection* lCollection = getCollection(collection);

      std::stringstream lStream;
      CAPIUtil::getIStream(doc, lStream);

      lCollection->addDocument(lStream);

    ZORBAC_COLLECTION_CATCH
  }

  XQC_Error
  Collection::add_document_char(XQC_Collection collection, const char* doc)
  {
    ZORBAC_COLLECTION_TRY
      zorba::Collection* lCollection = getCollection(collection);

      std::stringstream lStream;
      lStream << doc;

      lCollection->addDocument(lStream);

    ZORBAC_COLLECTION_CATCH
  }


  void
  Collection::free(XQC_Collection collection)
  {
    try {
      zorba::Collection* lCollection = getCollection(collection);
      lCollection->removeReference();
      delete collection;
    } catch (ZorbaException&) { 
      assert(false);
    } catch (...) { 
      assert(false);
    }
  }

  void
  Collection::assign_functions(XQC_Collection collection)
  {
    collection->get_name          = Collection::get_name;
    collection->add_node          = Collection::add_node;
    collection->delete_node       = Collection::delete_node;
    collection->add_sequence      = Collection::add_sequence;
    collection->add_document      = Collection::add_document;
    collection->add_document_char = Collection::add_document_char;
    collection->free              = Collection::free;
  }

} /* namespace zorbac */
