
#include "store/naive/simple_store.h"


namespace xqp
{

Store& Store::getInstance()
{
  static SimpleStore theGlobalStore;

  return theGlobalStore;
}

}
