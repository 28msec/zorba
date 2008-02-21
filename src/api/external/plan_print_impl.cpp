
#include "api/external/plan_print_impl.h"
#include "compiler/parsetree/parsenodes.h"
#include "compiler/parsetree/parsenode_print_xml_visitor.h"
#include "compiler/parsetree/parsenode_print_dot_visitor.h"
#include "runtime/visitors/printervisitor.h"
#include "runtime/visitors/iterprinter.h"
#include "compiler/expression/expr.h"
#include "runtime/base/plan_iterator.h"

namespace xqp{

XQueryTreePlansImpl::XQueryTreePlansImpl()
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

XQueryTreePlansImpl::~XQueryTreePlansImpl()
{
}

void  XQueryTreePlansImpl::setOutputASTPlan(std::ostream *os, enum PrintFormat_t format)
{
  os_ast = os;
  format_ast = format;
}

void  XQueryTreePlansImpl::setOutputExpressionPlan(std::ostream *os, enum PrintFormat_t format)
{
  os_expr = os;
  format_expr = format;
}

void  XQueryTreePlansImpl::setOutputNormalizedExpressionPlan(std::ostream *os, enum PrintFormat_t format)
{
  os_normalized_expr = os;
  format_normalized_expr = format;
}
void  XQueryTreePlansImpl::setOutputRuntimePlan(std::ostream *os, enum PrintFormat_t format)
{
  os_runtime = os;
  format_runtime = format;
}

void XQueryTreePlansImpl::printASTPlan(rchandle<parsenode> parsenodes)
{
  if(!os_ast)
    return;

  *os_ast << "Parse tree:\n";
  ParseNodePrintXMLVisitor lPrintXMLVisitor(*os_ast);
  lPrintXMLVisitor.print(&*parsenodes);
}

void XQueryTreePlansImpl::printExprPlan(rchandle<expr> expr)
{
  if(!os_expr)
    return;

  *os_expr << "Expression tree after translation:\n";
  expr->put(*os_expr) << std::endl;
}

void XQueryTreePlansImpl::printNormalizedExprPlan(rchandle<expr> normalized_expr)
{
  if(!os_normalized_expr)
    return;

  *os_normalized_expr << "Expression tree after normalization:\n";
  normalized_expr->put(*os_normalized_expr) << std::endl;
}

void XQueryTreePlansImpl::printRuntimePlan(PlanIter_t top_iterator)
{
  if(!os_runtime)
    return;
  *os_runtime << "Iterator tree:\n";
  XMLIterPrinter vp(*os_runtime);
  PrinterVisitor pv(vp, top_iterator);
  pv.print();
}



}//end namespace xqp
