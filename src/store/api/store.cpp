
#include "store/naive/simple_store.h"


namespace xqp
{

Store& Store::getInstance()
{
  static SimpleStore theGlobalStore;

  theGlobalStore.init();

  return theGlobalStore;
}

}
