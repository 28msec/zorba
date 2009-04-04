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
#include "runtime/base/plan_iterator.h"
#include "indexing/value_index.h"
#include "system/globalenv.h"
#include "store/api/store.h"

namespace zorba 
{

ValueIndex::~ValueIndex()
{
}


ValueIndexInsertSession_t ValueIndex::createBulkInsertSession()
{
  xqpStringStore_t uristore(getIndexUri());
  store::Index *store_index = GENV_STORE.getIndex(uristore);
  if (store_index == NULL) {
    ZORBA_ERROR_PARAM(XQP0033_INDEX_DOES_NOT_EXIST, getIndexUri(), "");
  }
  store::IndexEntryReceiver_t receiver = store_index->createInsertSession();
  ValueIndexInsertSession_t session = new ValueIndexInsertSession(this, receiver);
  return session;
}


void ValueIndexInsertSession::commitBulkInsertSession()
{
  m_bulkInsertSession->commit();
  m_bulkInsertSession = NULL;
}


void ValueIndexInsertSession::abortBulkInsertSession()
{
  m_bulkInsertSession->abort();
  m_bulkInsertSession = NULL;
}

}
/* vim:set ts=2 sw=2: */
