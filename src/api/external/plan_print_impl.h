#ifndef ZORBA_XQUERY_PLAN_PRINT_IMPL_15_FEB_2008
#define ZORBA_XQUERY_PLAN_PRINT_IMPL_15_FEB_2008

#include "compiler/xquery_plan_print.h"
#include "common/shared_types.h"

namespace xqp{

class parsenode;
class expr;

class XQueryTreePlansImpl : public XQueryTreePlans
{
private:
//  rchandle<parsenode>   ast_tree;
//  rchandle<expr>        expr_tree;

  std::ostream    *os_ast;
  enum PrintFormat_t   format_ast;
  std::ostream    *os_expr;
  enum PrintFormat_t   format_expr;
  std::ostream    *os_normalized_expr;
  enum PrintFormat_t   format_normalized_expr;
  std::ostream    *os_runtime;
  enum PrintFormat_t   format_runtime;

public:

  XQueryTreePlansImpl();

  virtual ~XQueryTreePlansImpl();

  virtual void  setOutputASTPlan(std::ostream *os, enum PrintFormat_t format);
  virtual void  setOutputExpressionPlan(std::ostream *os, enum PrintFormat_t format);
  virtual void  setOutputNormalizedExpressionPlan(std::ostream *os, enum PrintFormat_t format);
  virtual void  setOutputRuntimePlan(std::ostream *os, enum PrintFormat_t format);


  void printASTPlan(rchandle<parsenode> parsenodes);
  void printExprPlan(rchandle<expr> expr);
  void printNormalizedExprPlan(rchandle<expr> normalized_expr);
  void printRuntimePlan(PlanIter_t top_iterator);

};

}//end namespace xqp

#endif
