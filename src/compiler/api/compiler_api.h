#ifndef ZORBA_COMPILER_API_H
#define ZORBA_COMPILER_API_H

#include <zorbatypes/representations.h>

#include <zorba/xquery_plan_print.h>
#include <memory>

#include "common/shared_types.h"

namespace zorba {

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
    rchandle<expr> do_translation (rchandle<parsenode> n_p, XQueryPlanPrinterConfig *pp_cfg);
    static_context *m_sctx;
};

class XQueryCompilerSubsystem {
  public:
    XQueryCompilerSubsystem();
    virtual ~XQueryCompilerSubsystem() throw ();

    virtual Rewriter *getDefaultOptimizingRewriter() = 0;

  private:
    static std::auto_ptr<XQueryCompilerSubsystem> create();
    friend class GlobalEnvironment;
};

} /* namespace zorba */
#endif /* ZORBA_COMPILER_API_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set ts=2 sw=2: */
