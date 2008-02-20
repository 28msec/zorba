
#ifndef ZORBA_XQUERY_PLAN_TREE_PRINTING_FOR_DEBUGGING_15_FEB_2008
#define ZORBA_XQUERY_PLAN_TREE_PRINTING_FOR_DEBUGGING_15_FEB_2008

#include "util/rchandle.h"
#include <iostream>

namespace xqp{

class XQueryTreePlans : public SimpleRCObject
{
public:
  enum PrintFormat_t
  {
    PRINT_TEXT,
    PRINT_XML,
    PRINT_DOT
  };

  virtual ~XQueryTreePlans() {}

  virtual void  setOutputASTPlan(std::ostream *os, enum PrintFormat_t format = PRINT_TEXT) = 0;
  virtual void  setOutputExpressionPlan(std::ostream *os, enum PrintFormat_t format = PRINT_TEXT) = 0;
  virtual void  setOutputNormalizedExpressionPlan(std::ostream *os, enum PrintFormat_t format = PRINT_TEXT) = 0;
  virtual void  setOutputRuntimePlan(std::ostream *os, enum PrintFormat_t format = PRINT_TEXT) = 0;
};

typedef rchandle<XQueryTreePlans>   XQueryTreePlans_t;

}//end namespace xqp

#endif

