
#include "store/naive/qname_pool.h"

int main(int argc, const char * argv[])
{
  xqp::QNamePool* pool = new xqp::QNamePool(16);

  xqp::QNameImpl::setQNamePool(pool);

  xqp::QNameImpl* qn = NULL;

  qn = pool->insert("ns1", "pre1", "loc1");

  qn->free();

  delete pool;

  return 0;
}

