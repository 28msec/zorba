/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
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
#include "compiler/parsetree/parsenode_base.h" 
#include "compiler/expression/expr_base.h"
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

#ifdef ZORBA_DEBUGGER
#include "debugger/debugger_server.h"
#include "compiler/dewey/dewey.h"
#endif
#ifdef ZORBA_XQUERYX
#include "compiler/xqueryx/xqueryx_to_xquery.h"
#endif
namespace zorba {

  // static context is in the compilercb
XQueryCompiler::XQueryCompiler(CompilerCB* aCompilerCB) 
  :
  theCompilerCB(aCompilerCB)
{ 
  aCompilerCB->m_sctx->set_typemanager(rchandle<TypeManager>(new DelegatingTypeManager(&GENV_TYPESYSTEM)));
}


XQueryCompiler::~XQueryCompiler()
{
}

static void print_ast_tree (const parsenode *n, std::string name) {
  std::cout << "AST for " << name << "\n";
  print_parsetree_xml (std::cout, n);
  std::cout << std::endl;
}

void XQueryCompiler::parseOnly(std::istream& aXQuery, const xqpString& aFileName)
{
  parsenode_t pn = parse(aXQuery, aFileName);
}


PlanIter_t XQueryCompiler::compile(parsenode_t ast) 
{
  expr_t lExpr = normalize(ast);
  lExpr = optimize(lExpr);

  // TODO we might pass the CompilerCB here, however, we also need it in the runtime
  // because codegeneration for udfs is triggered there
  // then however, the compilercb can not be const in the runtime?!
  PlanIter_t plan = codegen ("main query", lExpr, theCompilerCB);

  return plan;
}


PlanIter_t
XQueryCompiler::compile(std::istream& aXQuery, const xqpString & aFileName)
{
  parsenode_t lAST = parse(aXQuery, aFileName);
  return compile (lAST);
}


parsenode_t
XQueryCompiler::parse(std::istream& aXQuery, const xqpString & aFileName)
{
  // TODO: move these out
  if (Properties::instance()->printAst())
    theCompilerCB->m_config.parse_cb = print_ast_tree;
  
  std::istream  *xquery_stream = &aXQuery;

#ifdef ZORBA_XQUERYX
  char  *converted_xquery_str = NULL;
  std::string   xquery_str;
  bool  is_xqueryx = false;
  {
    char  strtemp[1000];
    int   nr_read = 1;
    do
    {
      strtemp[0] = 0;
      aXQuery.read(strtemp, sizeof(strtemp)-1);
      strtemp[aXQuery.gcount()] = 0;
      xquery_str += strtemp;
    }while(aXQuery.gcount() == (sizeof(strtemp)-1));
  }
  XQueryXConvertor    *xqxconvertor = GENV.getXQueryXConvertor();
  //if(theCompilerCB->xqformat == XQUERYX_2005)
  if(xqxconvertor->isXQueryX((char*)xquery_str.c_str()))//identify XQueryX by content: root tag = "<prefix:module ... xmlns:prefix="http://www.w3.org/2005/XQueryX" ... > "
  {
    is_xqueryx = true;
    //translate from xqueryx to xquery using XSLT
    //read all input stream into std::string

    //debug
    printf("\n\n");
    printf(xquery_str.c_str());
    //end debug

    converted_xquery_str = xqxconvertor->XQueryX2XQuery(xquery_str.c_str());
    //debug
    printf("\n\n");
    printf(converted_xquery_str);
    //end debug
    xquery_stream = new std::istringstream(converted_xquery_str);
  }
  else
  {
    xquery_stream = new std::istringstream(xquery_str);
  }
#endif

  xquery_driver lDriver(&*theCompilerCB);
  lDriver.parse_stream(*xquery_stream, aFileName);
#ifdef ZORBA_XQUERYX
  delete xquery_stream;
  if(is_xqueryx)
  {
    //XQueryXConvertor    *xqxconvertor = GENV.getXQueryXConvertor();
    xqxconvertor->freeResult(converted_xquery_str);
  }
#endif
  parsenode_t node = lDriver.get_expr();
  if (typeid (*node) == typeid (ParseErrorNode)) {
    ParseErrorNode *err = static_cast<ParseErrorNode *> (&*node);
    ZORBA_ERROR_LOC_DESC( XPST0003, err->get_location (), err->msg);
    node = NULL;
  }
  return node;
}

expr_t
XQueryCompiler::normalize(parsenode_t aParsenode)
{
  expr_t lExpr = translate (*aParsenode, theCompilerCB);
  if ( lExpr == NULL ) { // TODO: can this happen?
    ZORBA_ERROR( API0002_COMPILE_FAILED);
    return NULL;
  }
#ifdef ZORBA_DEBUGGER
  if(theCompilerCB->m_debugger != 0)
  {
    ZorbaDebugger* lDebugger = theCompilerCB->m_debugger;
    lDebugger->theClassification = classify(*aParsenode);
    std::list<parsenode_t> lModules = lDebugger->getModules();
    std::list<parsenode_t>::iterator it;
    for(it=lModules.begin(); it!=lModules.end(); ++it)
    {
      Classification_t lClassification = classify(**it);
      lDebugger->theClassification.insert(lClassification.begin(), lClassification.end());
    }

#if 0
    Classification_t lClassification = theCompilerCB->m_debugger->theClassification;
    Classification_t::iterator lIter;
    for(lIter=lClassification.begin(); lIter!=lClassification.end(); ++lIter)
    {
      std::stack<unsigned int> s(lIter->second);
      while(!s.empty())
      {
        std::cerr << s.top();
        s.pop();
      }
      std::cerr << ' ' << lIter->first << ' ' << lIter->first.getFunctionName() << std::endl;
    }
#endif
  }
#endif
  normalize_expr_tree ("query", theCompilerCB, lExpr, NULL);
  return lExpr;
}


expr_t
XQueryCompiler::optimize(expr_t lExpr) 
{
  if (theCompilerCB->m_config.opt_level > CompilerCB::config_t::O0) {
    RewriterContext rCtx(theCompilerCB, lExpr);
    GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rCtx);
    lExpr = rCtx.getRoot();
    
    if (theCompilerCB->m_config.optimize_cb != NULL)
      theCompilerCB->m_config.optimize_cb (&*lExpr, "query");
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
