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
#include "capi/data_manager.h"

#include <cassert>
#include <sstream>
#include <zorba/zorba.h>
#include "capi/capi_util.h"
#include "capi/collection.h"

using namespace zorba;

#define ZORBAC_DATAMANAGER_TRY try {
#define ZORBAC_DATAMANAGER_CATCH \
    return XQ_NO_ERROR;          \
  } catch (ZorbaException &e) {     \
    return e.getErrorCode();        \
  } catch (...) {                   \
    return XQP0019_INTERNAL_ERROR;  \
  }


namespace zorbac {

  zorba::XmlDataManager*
  getDataManager(XQC_DataManager data_manager)
  {
    return static_cast<zorba::XmlDataManager*>(data_manager->data);
  }

  XQUERY_ERROR
  DataManager::load_document(XQC_DataManager data_manager, const char* doc_uri, FILE* document)
  {
    ZORBAC_DATAMANAGER_TRY
      zorba::XmlDataManager* lDataManager = getDataManager(data_manager);

      std::stringstream lStream;
      CAPIUtil::getIStream(document, lStream);

      lDataManager->loadDocument(doc_uri, lStream);

    ZORBAC_DATAMANAGER_CATCH
  }

  XQUERY_ERROR
  DataManager::load_document_uri(XQC_DataManager data_manager, const char* location)
  {
    ZORBAC_DATAMANAGER_TRY
      zorba::XmlDataManager* lDataManager = getDataManager(data_manager);

      lDataManager->loadDocument(location);
    ZORBAC_DATAMANAGER_CATCH
  }

  XQUERY_ERROR
  DataManager::get_document(XQC_DataManager data_manager, const char* doc_uri, XQC_Item_Ref doc)
  {
    ZORBAC_DATAMANAGER_TRY
      zorba::XmlDataManager* lDataManager = getDataManager(data_manager);

      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());

      std::auto_ptr<zorba::Item> lInnerItem(new zorba::Item(lDataManager->getDocument(doc_uri)));

      (*doc) = lItem.release();
      (*doc)->data = lInnerItem.release();
    ZORBAC_DATAMANAGER_CATCH
  }

  XQUERY_ERROR
  DataManager::delete_document(XQC_DataManager data_manager, const char* doc_uri)
  {
    ZORBAC_DATAMANAGER_TRY
      zorba::XmlDataManager* lDataManager = getDataManager(data_manager);

      lDataManager->deleteDocument(doc_uri);
    ZORBAC_DATAMANAGER_CATCH
  }

  XQUERY_ERROR
  DataManager::create_collection(XQC_DataManager data_manager, const char* col_uri,
                                 XQC_Collection_Ref col)
  {
    ZORBAC_DATAMANAGER_TRY
      zorba::XmlDataManager* lDataManager = getDataManager(data_manager);

      std::auto_ptr<XQC_Collection_s> lCollection(new XQC_Collection_s());

      zorba::Collection_t lInnerCollection = lDataManager->createCollection(col_uri);

      Collection::assign_functions(lCollection.get());

      (*col) = lCollection.release();
      lInnerCollection->addReference();
      (*col)->data = lInnerCollection.get();

    ZORBAC_DATAMANAGER_CATCH
  }

  XQUERY_ERROR
  DataManager::get_collection(XQC_DataManager data_manager, const char* col_uri, 
                              XQC_Collection_Ref col)
  {
    ZORBAC_DATAMANAGER_TRY
      zorba::XmlDataManager* lDataManager = getDataManager(data_manager);

      std::auto_ptr<XQC_Collection_s> lCollection(new XQC_Collection_s());

      zorba::Collection_t lInnerCollection = lDataManager->getCollection(col_uri);

      Collection::assign_functions(lCollection.get());

      (*col) = lCollection.release();
      lInnerCollection->addReference();
      (*col)->data = lInnerCollection.get();
    ZORBAC_DATAMANAGER_CATCH
  }

  XQUERY_ERROR
  DataManager::delete_collection(XQC_DataManager data_manager, const char* col_uri)
  {
    ZORBAC_DATAMANAGER_TRY
      zorba::XmlDataManager* lDataManager = getDataManager(data_manager);

      lDataManager->deleteCollection(col_uri);
    ZORBAC_DATAMANAGER_CATCH
  }

  void
  DataManager::free(XQC_DataManager data_manager)
  {
    try {
      //zorba::XmlDataManager* lDataManager = getDataManager(collection);
      delete data_manager;
    } catch (ZorbaException &e) { 
      assert(false);
    } catch (...) { 
      assert(false);
    }
  }

  void
  DataManager::assign_functions(XQC_DataManager data_manager)
  {
    data_manager->load_document     = DataManager::load_document;
    data_manager->load_document_uri = DataManager::load_document_uri;
    data_manager->get_document      = DataManager::get_document;
    data_manager->delete_document   = DataManager::delete_document;
    data_manager->create_collection = DataManager::create_collection;
    data_manager->get_collection    = DataManager::get_collection;
    data_manager->delete_collection = DataManager::delete_collection;
    data_manager->free              = DataManager::free;
  }

} /* namespace zorbac */

