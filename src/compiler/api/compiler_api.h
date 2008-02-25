#ifndef XQP_COMPILER_API_H
#define XQP_COMPILER_API_H

#include <zorba/xquery_plan_print.h>
#include <zorba/representations.h>

#include "common/shared_types.h"

namespace xqp {

class XQueryPlanPrinterConfig : public XQueryTreePlans {
private:
  std::ostream    *os_ast;
  enum PrintFormat_t   format_ast;
  std::ostream    *os_expr;
  enum PrintFormat_t   format_expr;
  std::ostream    *os_normalized_expr;
  enum PrintFormat_t   format_normalized_expr;
  std::ostream    *os_runtime;
  enum PrintFormat_t   format_runtime;

public:

  XQueryPlanPrinterConfig();

  virtual ~XQueryPlanPrinterConfig();

  virtual void  setOutputASTPlan(std::ostream *os, enum PrintFormat_t format);
  virtual void  setOutputExpressionPlan(std::ostream *os, enum PrintFormat_t format);
  virtual void  setOutputNormalizedExpressionPlan(std::ostream *os, enum PrintFormat_t format);
  virtual void  setOutputRuntimePlan(std::ostream *os, enum PrintFormat_t format);

  void printASTPlan(rchandle<parsenode> parsenodes);
  void printExprPlan(rchandle<expr> expr);
  void printNormalizedExprPlan(rchandle<expr> normalized_expr);
  void printRuntimePlan(PlanIter_t top_iterator);
};

class XQueryCompiler {
  public:
    XQueryCompiler(std::vector<rchandle<static_context> >& sctx_list,
        static_context *sctx);
    PlanIter_t compile(xqp_string source_uri, xqp_string xquery_text,
        XQueryPlanPrinterConfig *pp_cfg);

  private:
    std::vector<rchandle<static_context> >& m_sctx_list;
    static_context *m_sctx;
};

} /* namespace xqp */
#endif /* XQP_COMPILER_API_H */
/* vim:set ts=2 sw=2: */
