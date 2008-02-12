#include <cassert>
#include "zorba/common/common.h"
#include "zorba/store/api/item.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "types/root_typemanager.h"

using namespace xqp;

int typesystem_isSubtype(int argc, char* argv[]) {
  {
    Store& store = Store::getInstance();
    Item_t lInteger = store.getItemFactory().createInteger(Integer::parseInt((int32_t)1));
    Item_t lInt = store.getItemFactory().createInt(1);
    Item_t lDecimal = store.getItemFactory().createDecimal(Decimal::parseInt((int32_t)1));

    xqtref_t lIntegerType = GENV_TYPESYSTEM.create_type(lInteger->getType(), TypeConstants::QUANT_ONE);
    xqtref_t lIntType = GENV_TYPESYSTEM.create_type(lInt->getType(), TypeConstants::QUANT_ONE);
    xqtref_t lDecimalType = GENV_TYPESYSTEM.create_type(lDecimal->getType(), TypeConstants::QUANT_ONE);

    assert(GENV_TYPESYSTEM.is_atomic(*lIntType));
    assert(GENV_TYPESYSTEM.is_subtype(*lIntType, *lIntegerType));
    assert(GENV_TYPESYSTEM.is_subtype(*lIntType, *lDecimalType));
    assert(GENV_TYPESYSTEM.is_subtype(*lIntegerType, *lDecimalType));
  }

  GlobalEnvironment::destroy();
  
  return 0;
}
