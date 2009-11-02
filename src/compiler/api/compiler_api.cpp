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

#include "util/properties.h"

#include "context/static_context.h"
#include "context/standard_uri_resolvers.h"

#include "types/root_typemanager.h"
#include "types/typemanagerimpl.h"

#include "compiler/api/compiler_api_impl.h"
#include "compiler/api/compilercb.h"
#include "compiler/parser/xquery_driver.h"
#include "compiler/parsetree/parsenodes.h" 
#include "compiler/parsetree/parsenodes.h" 
#include "compiler/expression/expr_base.h"
#include "compiler/translator/translator.h"
#include "compiler/normalizer/normalizer.h"
#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/rewriter/framework/rewriter.h"
#include "compiler/codegen/plan_visitor.h"
#include "compiler/parsetree/parsenode_print_xml_visitor.h"
#include "compiler/parsetree/parsenode_print_xqdoc_visitor.h"
//#include "compiler/dewey/dewey.h"
#ifdef ZORBA_XQUERYX
#include "compiler/xqueryx/xqueryx_to_xquery.h"
#endif

#include "runtime/base/plan_iterator.h"


namespace zorba 
{

static void print_ast_tree(const parsenode *n, const std::string& name) 
{
  std::cout << "AST for " << name << "\n";
  print_parsetree_xml (std::cout, n);
  std::cout << std::endl;
}


static void print_xqdoc_tree(
    const parsenode *n,
    std::string name,
    std::ostream& anOutput,
    store::Item_t aDateTime) 
{
  print_parsetree_xqdoc (anOutput, n, name, aDateTime);
}



XQueryCompiler::XQueryCompiler(CompilerCB* aCompilerCB) 
  :
  theCompilerCB(aCompilerCB),
  theResolver(0)
{ 
}


XQueryCompiler::~XQueryCompiler()
{
  delete theResolver;
}


void XQueryCompiler::parseOnly(std::istream& aXQuery, const xqpString& aFileName)
{
  parsenode_t pn = parse(aXQuery, aFileName);
}


PlanIter_t XQueryCompiler::compile(parsenode_t ast) 
{
  expr_t lExpr = normalize(ast);
  lExpr = optimize(lExpr);

#if 0
  lExpr = lExpr->clone();
#endif

  // TODO we might pass the CompilerCB here, however, we also need it in the runtime
  // because codegeneration for udfs is triggered there
  // then however, the compilercb can not be const in the runtime?!
  PlanIter_t plan = codegen ("main query", lExpr, theCompilerCB);

  return plan;
}

void XQueryCompiler::xqdoc(std::istream& aXQuery, const xqpString& aFileName, std::ostream& anOutput, const store::Item_t& aDateTime)
{
  parsenode_t lAST = parse(aXQuery, aFileName);
  print_xqdoc_tree(lAST.getp(), aFileName, anOutput, aDateTime);
}

PlanIter_t
XQueryCompiler::compile(std::istream& aXQuery, const xqpString & aFileName)
{
  parsenode_t lAST = parse(aXQuery, aFileName);

  if(theCompilerCB->theConfig.lib_module &&
     typeid (lAST) != typeid (LibraryModule))
    lAST = createMainModule(lAST, aXQuery, aFileName);

  return compile (lAST);
}


parsenode_t
XQueryCompiler::parse(std::istream& aXQuery, const xqpString & aFileName)
{
  // TODO: move these out
  if (Properties::instance()->printAst()) {
    theCompilerCB->theConfig.parse_cb = print_ast_tree;
  }
  
  std::istream  *xquery_stream = &aXQuery;

#ifdef ZORBA_XQUERYX
  char  *converted_xquery_str = NULL;
  std::string   xquery_str;
  bool  is_xqueryx = false;
  {
    char  strtemp[1000];
    //int   nr_read = 1;
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

    converted_xquery_str = xqxconvertor->XQueryX2XQuery(xquery_str.c_str());

#ifndef NDEBUG
    printf ("\n\n%s", converted_xquery_str);  // debug
#endif
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
  }
  return node;
}

expr_t
XQueryCompiler::normalize(parsenode_t aParsenode)
{
  expr_t lExpr = translate (*aParsenode, theCompilerCB);
  if ( lExpr == NULL ) 
  { // TODO: can this happen?
    ZORBA_ERROR( API0002_COMPILE_FAILED);
    return NULL;
  }
  normalize_expr_tree ("query", theCompilerCB, lExpr, NULL);
  theCompilerCB->setIsUpdating(lExpr->is_updating());
  return lExpr;
}


expr_t
XQueryCompiler::optimize(expr_t lExpr) 
{
  if (theCompilerCB->theConfig.opt_level > CompilerCB::config_t::O0) 
  {
    RewriterContext rCtx(theCompilerCB, lExpr);
    GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rCtx);
    lExpr = rCtx.getRoot();
    
    if (theCompilerCB->theConfig.optimize_cb != NULL)
      theCompilerCB->theConfig.optimize_cb (&*lExpr, "query");
  }

  return lExpr;
}


parsenode_t
XQueryCompiler::createMainModule(
    parsenode_t aLibraryModule,
    std::istream& aXQuery,
    const xqpString & aFileName)
{
  //get the namespace from the LibraryModule
  LibraryModule *mod_ast = dynamic_cast<LibraryModule *> (&*aLibraryModule);
  if (!mod_ast) 
  {
    ZORBA_ERROR_DESC_OSS(API0002_COMPILE_FAILED,
                        "given library module is not a valid module, e.g. the module declaration is missing");

  }

  std::string lib_namespace = mod_ast->get_decl()->get_target_namespace();

  //create a dummy main module
  std::stringstream lDocStream;
  lDocStream << "import module namespace m = '"
             << lib_namespace
             << "'; 1";

  aXQuery.clear();
  aXQuery.seekg(0);

  theResolver = new StandardLibraryModuleURIResolver(aXQuery, lib_namespace, aFileName.c_str());
  theCompilerCB->theRootSctx->add_module_uri_resolver(theResolver);

  return  parse(lDocStream, aFileName);
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
