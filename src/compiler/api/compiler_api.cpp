#include <zorba/properties.h>

#include "system/globalenv.h"
#include "errors/error_factory.h"
#include "compiler/api/compiler_api.h"
#include "compiler/api/compiler_api_impl.h"
#include "compiler/parsetree/parsenodes.h"
#include "compiler/parsetree/parsenode_print_xml_visitor.h"
#include "compiler/parsetree/parsenode_print_dot_visitor.h"
#include "compiler/codegen/plan_visitor.h"
#include "compiler/translator/translator.h"
#include "compiler/normalizer/normalizer.h"
#include "compiler/parser/xquery_driver.h"
#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/rewriter/framework/rewriter.h"
#include "compiler/expression/expr.h"
#include "runtime/visitors/printervisitor.h"
#include "runtime/visitors/iterprinter.h"
#include "runtime/base/plan_iterator.h"

namespace xqp {

XQueryPlanPrinterConfig::XQueryPlanPrinterConfig()
{
  os_ast = NULL;
  format_ast = XQueryTreePlans::PRINT_TEXT;
  os_expr = NULL;
  format_expr = XQueryTreePlans::PRINT_TEXT;
  os_normalized_expr = NULL;
  format_normalized_expr = XQueryTreePlans::PRINT_TEXT;
  os_runtime = NULL;
  format_runtime = XQueryTreePlans::PRINT_TEXT;
}

XQueryPlanPrinterConfig::~XQueryPlanPrinterConfig()
{
}

void  XQueryPlanPrinterConfig::setOutputASTPlan(std::ostream *os, enum PrintFormat_t format)
{
  os_ast = os;
  format_ast = format;
}

void  XQueryPlanPrinterConfig::setOutputExpressionPlan(std::ostream *os, enum PrintFormat_t format)
{
  os_expr = os;
  format_expr = format;
}

void  XQueryPlanPrinterConfig::setOutputNormalizedExpressionPlan(std::ostream *os, enum PrintFormat_t format)
{
  os_normalized_expr = os;
  format_normalized_expr = format;
}
void  XQueryPlanPrinterConfig::setOutputRuntimePlan(std::ostream *os, enum PrintFormat_t format)
{
  os_runtime = os;
  format_runtime = format;
}

void XQueryPlanPrinterConfig::printASTPlan(rchandle<parsenode> parsenodes)
{
  if(!os_ast)
    return;

  *os_ast << "Parse tree:\n";
  ParseNodePrintXMLVisitor lPrintXMLVisitor(*os_ast);
  lPrintXMLVisitor.print(&*parsenodes);
}

void XQueryPlanPrinterConfig::printExprPlan(rchandle<expr> expr)
{
  if(!os_expr)
    return;

  *os_expr << "Expression tree after translation:\n";
  expr->put(*os_expr) << std::endl;
}

void XQueryPlanPrinterConfig::printNormalizedExprPlan(rchandle<expr> normalized_expr)
{
  if(!os_normalized_expr)
    return;

  *os_normalized_expr << "Expression tree after normalization:\n";
  normalized_expr->put(*os_normalized_expr) << std::endl;
}

void XQueryPlanPrinterConfig::printRuntimePlan(PlanIter_t top_iterator)
{
  if(!os_runtime)
    return;
  *os_runtime << "Iterator tree:\n";
  XMLIterPrinter vp(*os_runtime);
  PrinterVisitor pv(vp, top_iterator);
  pv.print();
}

XQueryCompiler::XQueryCompiler(std::vector<rchandle<static_context> >& sctx_list,
  static_context *sctx)
  : m_sctx_list(sctx_list),
  m_sctx(sctx){ }

PlanIter_t XQueryCompiler::compile(xqp_string source_uri, xqp_string xquery_text,
    XQueryPlanPrinterConfig *pp_cfg)
{
  xquery_driver driver;
  driver.filename = source_uri;

  ///build up the expression tree
  if(xquery_text.empty()) {
    driver.parse(source_uri.c_str());
  } else {
    driver.parse_string(xquery_text.c_str());
  }

  rchandle<parsenode> n_p = driver.get_expr();

  if (Properties::instance()->printAST())
  {
    std::cout << "Parse tree:\n";
    ParseNodePrintXMLVisitor lPrintXMLVisitor(std::cout);
    lPrintXMLVisitor.print(&*n_p);
  }
  if (pp_cfg) {
    pp_cfg->printASTPlan(n_p);
  }

  MainModule* mm_p;
  QueryBody* qb_p;
  Expr* ex_p;

  if ((mm_p = dynamic_cast<MainModule*>(&*n_p))==NULL) 
  {
    ZORBA_ERROR_ALERT(ZorbaError::XPST0003,
        NULL, DONT_CONTINUE_EXECUTION,
        "Parse error: expecting MainModule");
    return NULL;
  }

  if ((qb_p = dynamic_cast<QueryBody*>(&*mm_p->get_query_body()))==NULL)
  {
    ZORBA_ERROR_ALERT(ZorbaError::XPST0003,
        NULL, DONT_CONTINUE_EXECUTION,
        "Parse error: expecting MainModule->QueryBody");
    return NULL;
  }

  if ((ex_p = dynamic_cast<Expr*>(&*qb_p->get_expr()))==NULL) 
  {
    ZORBA_ERROR_ALERT(ZorbaError::XPST0003,
        NULL, DONT_CONTINUE_EXECUTION, 
        "Parse error: expecting MainModule->QueryBody->Expr");
    return NULL;
  }

  rchandle<expr> e_h = translate (Properties::instance ()->printTranslatedExpressions (), m_sctx, *mm_p, m_sctx_list);
  if (e_h == NULL)
  {
    ZORBA_ERROR_ALERT(ZorbaError::API0002_COMPILE_FAILED);
    return NULL;
  }
  if (pp_cfg) {
    pp_cfg->printExprPlan(e_h);
  }

  normalize_expr_tree (Properties::instance ()->printNormalizedExpressions () ? "query" : NULL, m_sctx, e_h);

  if (pp_cfg) {
    pp_cfg->printNormalizedExprPlan(e_h);
  }

  RewriterContext rCtx(m_sctx, e_h);
  GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rCtx);
  e_h = rCtx.getRoot();

  PlanIter_t plan = codegen ("query", e_h);
  if (plan == NULL) {
    cout << "Codegen returned null";
    ZORBA_ERROR_ALERT(ZorbaError::API0002_COMPILE_FAILED);
    return NULL;
  }

  if (pp_cfg) {
    pp_cfg->printRuntimePlan(plan);
  }

  return plan;
}

XQueryCompilerSubsystem::XQueryCompilerSubsystem()
{
  
}

XQueryCompilerSubsystem::~XQueryCompilerSubsystem() throw ()
{
}

std::auto_ptr<XQueryCompilerSubsystem> XQueryCompilerSubsystem::create()
{
  return std::auto_ptr<XQueryCompilerSubsystem>(new XQueryCompilerSubsystemImpl());
}

}
/* vim:set ts=2 sw=2: */
