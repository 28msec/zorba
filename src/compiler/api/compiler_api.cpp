#include "compiler/api/compiler_api.h"

#include <istream>
#include <memory>
#include "system/globalenv.h"
#include "compiler/api/compiler_api_impl.h"
#include "compiler/api/compilercb.h"
#include "context/static_context.h"

#include "types/root_typemanager.h"
#include "types/delegating_typemanager.h"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parsetree/parsenodes.h" 
#include "compiler/expression/expr.h"
#include "compiler/translator/translator.h"
#include "compiler/normalizer/normalizer.h"
#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/rewriter/framework/rewriter.h"
#include "compiler/codegen/plan_visitor.h"

#include "runtime/api/plan_wrapper.h"
#include "util/properties.h"

#include "compiler/parsetree/parsenode_print_xml_visitor.h"
#include "runtime/visitors/printervisitor.h"
#include "runtime/visitors/iterprinter.h"


namespace zorba {

  // static context is in the compilercb
  XQueryCompiler::XQueryCompiler(CompilerCB* aCompilerCB) 
    : theCompilerCB(aCompilerCB)
  { 
    aCompilerCB->m_sctx->set_typemanager(std::auto_ptr<TypeManager>(new DelegatingTypeManager(&GENV_TYPESYSTEM)));
  }

  XQueryCompiler::~XQueryCompiler()
  { }

  PlanIter_t
  XQueryCompiler::compile(std::istream& aXQuery, const xqpString & aFileName)
  {
    parsenode_t lAST = parse(aXQuery, aFileName);

    expr_t lExpr = normalize(lAST);
    lExpr = optimize(lExpr);

    // TODO we might pass the CompilerCB here, however, we also need it in the runtime
    // because codegeneration for udfs is triggered there
    // then however, the compilercb can not be const in the runtime?!
    PlanIter_t plan = codegen ("query", lExpr);  // TODO can NULL be returned?


    if (Properties::instance()->printIteratorTree()) {
      XMLIterPrinter vp(std::cout);
      PrinterVisitor pv(vp, plan);
    }


    return plan;
  }

  parsenode_t
  XQueryCompiler::parse(std::istream& aXQuery, const xqpString & aFileName)
  {
    xquery_driver lDriver(&*theCompilerCB);
    lDriver.parse_stream(aXQuery, aFileName);

    if (Properties::instance()->printAST())
      print_parsetree_xml (std::cout, &*lDriver.get_expr());
    return lDriver.get_expr();
  }

  expr_t
  XQueryCompiler::normalize(parsenode_t aParsenode)
  {
    expr_t lExpr = translate (Properties::instance()->printTranslatedExpressions(), *aParsenode, theCompilerCB);
    if ( lExpr == NULL ) { // todo, can this happen?
      ZORBA_ERROR( ZorbaError::API0002_COMPILE_FAILED);
      return NULL;
    }

    normalize_expr_tree (Properties::instance()->printNormalizedExpressions() ? "query" : NULL, 
                         theCompilerCB, lExpr);

    return lExpr;
 }

  expr_t
  XQueryCompiler::optimize(expr_t lExpr) 
  {
    if (theCompilerCB->m_config.opt_level > CompilerCB::config_t::O0) {
      RewriterContext rCtx(theCompilerCB, lExpr);
      GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rCtx);
      lExpr = rCtx.getRoot();
      
      if (Properties::instance()->printOptimizedExpressions()) {
        std::cout << "Optimized expression tree for query:\n";
        lExpr->put(std::cout) << std::endl;
      }
    }

    return lExpr;
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
