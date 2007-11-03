
#include <iostream>
#include <sys/time.h>

#include "store/naive/qname_pool.h"

int main(int argc, const char * argv[])
{
  double startTime;
  double endTime;
  struct timeval stime;
  struct timeval etime;

  gettimeofday(&stime, NULL);
  startTime=(double)stime.tv_sec+(1.e-6)*stime.tv_usec;

  xqp::QNamePool* pool = new xqp::QNamePool(xqp::QNamePool::MAX_CACHE_SIZE);

  xqp::QNameImpl::setQNamePool(pool);

  gettimeofday(&etime, NULL);
  endTime=(double)etime.tv_sec+(1.e-6)*etime.tv_usec;
  std::cout << "construction time : " << (double)(endTime-startTime) << std::endl;

  xqp::QNameImpl* qn = NULL;

  qn = pool->insert("ns1", "pre1", "loc1");

  qn->free();

  gettimeofday(&stime, NULL);
  startTime=(double)stime.tv_sec+(1.e-6)*stime.tv_usec;

  delete pool;

  gettimeofday(&etime, NULL);
  endTime=(double)etime.tv_sec+(1.e-6)*etime.tv_usec;
  std::cout << "destruction time : " << (double)(endTime-startTime) << std::endl;

  return 0;
}

