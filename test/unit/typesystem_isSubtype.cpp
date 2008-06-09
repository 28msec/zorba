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
#include <cassert>

#include <zorba/zorba.h>
#include <inmemorystore/inmemorystore.h>

#include "store/api/item.h"
#include "common/common.h"
#include "system/globalenv.h"
#include "types/root_typemanager.h"
#include "types/typeops.h"

#include "store/naive/simple_store.h"
#include "store/api/item_factory.h"


using namespace zorba;

int typesystem_isSubtype(int argc, char* argv[])
{
  store::SimpleStore* store = inmemorystore::InMemoryStore::getInstance();
  Zorba* lZorba = Zorba::getInstance(store);

  store::Item_t lInteger;
  store->getItemFactory()->createInteger(lInteger, Integer::parseInt((int32_t)1));
  store::Item_t lInt;
  store->getItemFactory()->createInt(lInt, 1);
  store::Item_t lDecimal;
  store->getItemFactory()->createDecimal(lDecimal, Decimal::parseInt((int32_t)1));
  xqtref_t lIntegerType = GENV_TYPESYSTEM.create_named_type(lInteger->getType(), TypeConstants::QUANT_ONE);
  xqtref_t lIntType = GENV_TYPESYSTEM.create_named_type(lInt->getType(), TypeConstants::QUANT_ONE);
  xqtref_t lDecimalType = GENV_TYPESYSTEM.create_named_type(lDecimal->getType(), TypeConstants::QUANT_ONE);
  assert(TypeOps::is_atomic(*lIntType));
  assert(TypeOps::is_subtype(*lIntType, *lIntegerType));
  assert(TypeOps::is_subtype(*lIntType, *lDecimalType));
  assert(TypeOps::is_subtype(*lIntegerType, *lDecimalType));
  lZorba->shutdown();
  return 0;
}
