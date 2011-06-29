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
#ifndef ZORBA_STORE_LOAD_PROPERTIES_H
#define ZORBA_STORE_LOAD_PROPERTIES_H

#include "common/common.h"


namespace zorba
{

SYNC_CODE(class Lock;)


namespace store
{

/**
 * How should the document load be done
 */
class LoadProperties
{
private:
  bool theStoreDocument;
  bool theEnableDtdLoader;
  bool theEnableExtParsedEntityLoader;

public:
  LoadProperties() : theStoreDocument(true), theEnableDtdLoader(false), theEnableExtParsedEntityLoader(false) {}
  virtual ~LoadProperties() {}

  /**
   * Set the property storeDocument, it specifies whether the document
   * should be kept in the store (i.e. added to the set of documents)
   */
  void setStoreDocument(bool aStoreDocument)
  {
    theStoreDocument = aStoreDocument;
  }

  /**
   * Get the property storeDocument, it specifies whether the document
   * should be kept in the store (i.e. added to the set of documents)
   */
  bool getStoreDocument() const
  {
    return theStoreDocument;
  }

  /**
   * Set the property enableDtd, it specifies whether the document's
   * dtd should be enabled when loading
   */
  void setEnableDtd(bool aEnableDtdLoader)
  {
    theEnableDtdLoader = aEnableDtdLoader;
  }

  /**
   * Get the property enableDtd, it specifies whether the document's
   * dtd should be enabled when loading
   */
  bool getEnableDtd() const
  {
    return theEnableDtdLoader;
  }

  /**
   * Set the property enableExtParsedEntity, it specifies whether the document
   * should be parsed as an enxternal general parsed entity
   */
  void setEnableExtParsedEntity(bool aEnableExtParsedEntityLoader)
  {
    theEnableExtParsedEntityLoader = aEnableExtParsedEntityLoader;
  }

  /**
   * Get the property enableDtd, it specifies whether the document
   * should be parsed as an enxternal general parsed entity
   */
  bool getEnableExtParsedEntity() const
  {
    return theEnableExtParsedEntityLoader;
  }
};

} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_LOAD_PROPERTIES_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
