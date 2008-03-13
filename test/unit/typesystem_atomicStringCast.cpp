#include <cassert>
#include <string>

#include <zorba/zorba_api.h>

#include "types/casting.h"
#include "types/root_typemanager.h"
#include "system/globalenv.h"
#include "system/zorba.h"

using namespace zorba;

int typesystem_atomicStringCast (int argc, char* argv[]) {
  ZorbaEngine_t zorba_factory = ZorbaEngine::getInstance();
  zorba_factory->initThread();
  
#if 0
  GenericCast* lCaster = GenericCast::instance();
  
  {
    xqpString lStr = "9.9";
    TypeSystem::xqtref_t lType = GENV_TYPESYSTEM.create_atomic_type(TypeSystem::XS_FLOAT, TypeSystem::QUANT_ONE);
    Item_t lItem = lCaster->stringSimpleCast(lStr, lType);
    TypeSystem::xqtref_t lType2 = GENV_TYPESYSTEM.create_type(lItem->getType(), TypeSystem::QUANT_ONE);
    assert(GENV_TYPESYSTEM.is_equal(*lType, *lType2));
    std::cout << "Float: " << lItem->getFloatValue() << std::endl;
  }
  
  {
    xqpString lStr = "9.9";
    TypeSystem::xqtref_t lType = GENV_TYPESYSTEM.create_atomic_type(TypeSystem::XS_DOUBLE, TypeSystem::QUANT_ONE);
    Item_t lItem = lCaster->stringSimpleCast(lStr, lType);
    TypeSystem::xqtref_t lType2 = GENV_TYPESYSTEM.create_type(lItem->getType(), TypeSystem::QUANT_ONE);
    assert(GENV_TYPESYSTEM.is_equal(*lType, *lType2));
    std::cout << "Double: " << lItem->getDoubleValue() << std::endl;
  }
  
  {
    xqpString lStr = "9.9";
    TypeSystem::xqtref_t lType = GENV_TYPESYSTEM.create_atomic_type(TypeSystem::XS_DECIMAL, TypeSystem::QUANT_ONE);
    Item_t lItem = lCaster->stringSimpleCast(lStr, lType);
    TypeSystem::xqtref_t lType2 = GENV_TYPESYSTEM.create_type(lItem->getType(), TypeSystem::QUANT_ONE);
    assert(GENV_TYPESYSTEM.is_equal(*lType, *lType2));
    std::cout << "Decimal: " << lItem->getDecimalValue() << std::endl;
  }
  
  {
    xqpString lStr = "123";
    TypeSystem::xqtref_t lType = GENV_TYPESYSTEM.create_atomic_type(TypeSystem::XS_INTEGER, TypeSystem::QUANT_ONE);
    Item_t lItem = lCaster->stringSimpleCast(lStr, lType);
    TypeSystem::xqtref_t lType2 = GENV_TYPESYSTEM.create_type(lItem->getType(), TypeSystem::QUANT_ONE);
    assert(GENV_TYPESYSTEM.is_equal(*lType, *lType2));
    std::cout << "Integer: " << lItem->getIntegerValue() << std::endl;
    assert(lItem->getIntegerValue() == 123);
  }

  {
    xqpString lStr = "true";
    TypeSystem::xqtref_t lType = GENV_TYPESYSTEM.create_atomic_type(TypeSystem::XS_BOOLEAN, TypeSystem::QUANT_ONE);
    Item_t lItem = lCaster->stringSimpleCast(lStr, lType);
    TypeSystem::xqtref_t lType2 = GENV_TYPESYSTEM.create_type(lItem->getType(), TypeSystem::QUANT_ONE);
    assert(GENV_TYPESYSTEM.is_equal(*lType, *lType2));
    std::cout << "Boolean: " << lItem->getBooleanValue() << std::endl;
    assert(lItem->getBooleanValue() == true);
  }

  {
    xqpString lStr = "fn:something";
    TypeSystem::xqtref_t lType = GENV_TYPESYSTEM.create_atomic_type(TypeSystem::XS_QNAME, TypeSystem::QUANT_ONE);
    Item_t lItem = lCaster->stringSimpleCast(lStr, lType);
    TypeSystem::xqtref_t lType2 = GENV_TYPESYSTEM.create_type(lItem->getType(), TypeSystem::QUANT_ONE);
    assert(GENV_TYPESYSTEM.is_equal(*lType, *lType2));
    std::cout << "QName: " << lItem->show() << std::endl;
    assert(lItem->getPrefix() == "fn");
    assert(lItem->getLocalName() == "something");
  }    
    
  {
    
  }
#endif
  
  zorba_factory->uninitThread();
  zorba_factory->shutdown();
  
  return 0;
}
