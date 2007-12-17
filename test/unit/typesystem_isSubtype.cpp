#include <cassert>
#include "zorba/common.h"
#include "zorba/store/api/item.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "types/typesystem.h"

using namespace xqp;

int typesystem_isSubtype(int argc, char* argv[]) {
  Store& store = Store::getInstance();
  Item_t lInteger = store.getItemFactory().createInteger(1);
  Item_t lInt = store.getItemFactory().createInt(1);
  Item_t lDecimal = store.getItemFactory().createDecimal(1);
  
  TypeSystem::xqtref_t lIntegerType = GENV_TYPESYSTEM.create_type(lInteger->getType(), TypeSystem::QUANT_ONE);
  TypeSystem::xqtref_t lIntType = GENV_TYPESYSTEM.create_type(lInt->getType(), TypeSystem::QUANT_ONE);
  TypeSystem::xqtref_t lDecimalType = GENV_TYPESYSTEM.create_type(lDecimal->getType(), TypeSystem::QUANT_ONE);
  
  assert(GENV_TYPESYSTEM.is_atomic(*lIntType));
  assert(GENV_TYPESYSTEM.is_subtype(*lIntType, *lIntegerType));
  assert(GENV_TYPESYSTEM.is_subtype(*lIntType, *lDecimalType));
  assert(GENV_TYPESYSTEM.is_subtype(*lIntegerType, *lDecimalType));
  
  return 0;
}
