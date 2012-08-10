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
#include "stdafx.h"

#include <istream>
#include <memory>

#include "compiler/api/compiler_api.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/dict.h"

#include "system/globalenv.h"
#include "system/properties.h"

#include "context/static_context.h"

#include "functions/function.h"
#include "functions/udf.h"

#include "types/typeops.h"
#include "types/root_typemanager.h"
#include "types/typemanagerimpl.h"

#include "context/uri_resolver.h"
#include "compiler/api/compiler_api_impl.h"
#include "compiler/api/compilercb.h"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parsetree/parsenodes.h"
#include "compiler/parsetree/parsenodes.h"
#include "compiler/parsetree/parsenode_print_xml_visitor.h"
#include "compiler/parsetree/parsenode_print_xqdoc_visitor.h"

#include "compiler/expression/expr_base.h"

#include "compiler/translator/translator.h"

#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/rewriter/framework/rewriter.h"
#include "compiler/rewriter/tools/udf_graph.h"

#include "compiler/codegen/plan_visitor.h"
#ifdef ZORBA_XQUERYX
#include "compiler/xqueryx/xqueryx_to_xquery.h"
#endif

#include "runtime/base/plan_iterator.h"
#include "util/xml_util.h"
#include "zorbatypes/URI.h"

#include "api/auditimpl.h"
#include <zorba/util/timer.h>


namespace zorba
{

static void print_ast_tree(const parsenode *n, const std::string& name)
{
  std::cout << "AST for " << name << "\n";
  print_parsetree_xml(std::cout, n);
  std::cout << std::endl;
}


/*******************************************************************************

********************************************************************************/
XQueryCompiler::XQueryCompiler(CompilerCB* aCompilerCB)
  :
  theCompilerCB(aCompilerCB)
{
}


/*******************************************************************************

********************************************************************************/
XQueryCompiler::~XQueryCompiler()
{
}


/*******************************************************************************

********************************************************************************/
void XQueryCompiler::parseOnly(
    std::istream& aXQuery,
    const zstring& aFileName)
{
  parsenode_t pn = parse(aXQuery, aFileName);
}


/*******************************************************************************

********************************************************************************/
void XQueryCompiler::xqdoc(
    std::istream&         aXQuery,
    const zstring&        aFileName,
    store::Item_t&        aResult,
    const store::Item_t&  aDateTime)
{
  parsenode_t lAST = parse(aXQuery, aFileName);

  print_parsetree_xqdoc(aResult, lAST.getp(), aFileName.c_str(), aDateTime);
}


/*******************************************************************************

********************************************************************************/
parsenode_t XQueryCompiler::parse(std::istream& aXQuery, const zstring& aFileName)
{
  // TODO: move these out
  if (Properties::instance()->printAst())
  {
    theCompilerCB->theConfig.parse_cb = print_ast_tree;
  }

  std::istream* xquery_stream = &aXQuery;

#ifdef ZORBA_XQUERYX
  char* converted_xquery_str = NULL;
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
    }
    while(aXQuery.gcount() == (sizeof(strtemp)-1));
  }

  XQueryXConvertor* xqxconvertor = GENV.getXQueryXConvertor();

  if(xqxconvertor->isXQueryX((char*)xquery_str.c_str()))
  {
    // identify XQueryX by content:
    // root tag =
    // "<prefix:module ... xmlns:prefix="http://www.w3.org/2005/XQueryX" ... > "

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
    xqxconvertor->freeResult(converted_xquery_str);
  }
#endif
  parsenode_t node = lDriver.get_expr();

  if (typeid (*node) == typeid (ParseErrorNode))
  {
    ParseErrorNode* pen = static_cast<ParseErrorNode *>(&*node);
    throw XQUERY_EXCEPTION_VAR(
      pen->err, ERROR_PARAMS(pen->msg), ERROR_LOC(pen->get_location())
		);
  }

  return node;
}


/*******************************************************************************

********************************************************************************/
PlanIter_t XQueryCompiler::compile(
    std::istream& aXQuery,
    const zstring& aFileName,
    ulong& nextDynamicVarId)
{
  audit::Event* ae = theCompilerCB->theRootSctx->get_audit_event();
  zorba::audit::ScopedRecord sar(ae);

  const char* lFileName = aFileName.c_str();

  audit::ScopedAuditor<const char*>
  filenameAudit(sar, zorba::audit::XQUERY_COMPILATION_FILENAME, lFileName);

  parsenode_t lAST;

  {
    time::Timer lTimer;

    audit::DurationAuditor
    durationAudit(sar, audit::XQUERY_COMPILATION_PARSE_DURATION, lTimer);

    lAST = parse(aXQuery, aFileName);

    if (theCompilerCB->theConfig.lib_module &&
        dynamic_cast<LibraryModule*>(lAST.getp()) != NULL)
    {
      lAST = createMainModule(lAST, aXQuery, aFileName);
    }
  }

  expr_t rootExpr;

  return compile(lAST, true, rootExpr, nextDynamicVarId, sar);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t XQueryCompiler::compile(
    const parsenode_t& ast,
    bool applyPUL,
    expr_t& rootExpr,
    ulong& nextDynamicVarId,
    audit::ScopedRecord& aAuditRecord)
{
  {
    time::Timer lTimer;

    audit::DurationAuditor
    durationAudit(aAuditRecord,
                  audit::XQUERY_COMPILATION_TRANSLATION_DURATION,
                  lTimer);

    rootExpr = normalize(ast); // also does the translation
  }

  {
    time::Timer lTimer;

    audit::DurationAuditor
    durationAudit(aAuditRecord,
                  audit::XQUERY_COMPILATION_OPTIMIZATION_DURATION,
                  lTimer);

    rootExpr = optimize(rootExpr);
  }

#if 0
  rootExpr = rootExpr->clone();
#endif

  PlanIter_t plan;

  {
    time::Timer lTimer;

    audit::DurationAuditor
    durationAudit(aAuditRecord,
                  audit::XQUERY_COMPILATION_CODEGENERATION_DURATION,
                  lTimer);

    plan = codegen("main query", rootExpr, theCompilerCB, nextDynamicVarId);
  }

  //theCompilerCB->getExprManager()->garbageCollect();

  return plan;
}


/*******************************************************************************

********************************************************************************/
expr_t XQueryCompiler::normalize(parsenode_t aParsenode)
{
#if 0
  time::walltime startTime;
  time::walltime stopTime;
  double elapsedTime;

  time::get_current_walltime(startTime);
#endif

  expr_t lExpr = translate(*aParsenode, theCompilerCB);

#if 0
  std::cout << "Num exprs after translation = "
            << theCompilerCB->getExprManager()->numExprs()
            << std::endl << std::endl;

  time::get_current_walltime(stopTime);
  elapsedTime = time::get_walltime_elapsed(startTime, stopTime);      
  std::cout << "Translation time = " << elapsedTime << std::endl;
#endif

  if ( lExpr == NULL )
  {
    // TODO: can this happen?
    throw ZORBA_EXCEPTION( zerr::ZAPI0002_XQUERY_COMPILATION_FAILED );
  }

  return lExpr;
}


/*******************************************************************************

********************************************************************************/
expr_t XQueryCompiler::optimize(expr_t lExpr)
{
  // Build the call-graph among the udfs that are actually used in the query
  // program.
  UDFGraph udfGraph(lExpr.getp());

  // By default all UDFs are marked as deterministic. Now, we find which udfs
  // are actually non-deterministic and mark them as such. This has to be done
  // before optimization.
  udfGraph.inferDeterminism();

  if (theCompilerCB->theConfig.opt_level <= CompilerCB::config::O0)
    return lExpr;

  // Optimize the udfs.
  udfGraph.optimizeUDFs(theCompilerCB);

  // Optimize the main expr (i.e., the top expr of the main module).
  RewriterContext rCtx(theCompilerCB,
                       lExpr,
                       NULL,
                       "Optimizing main program",
                       lExpr->get_sctx()->is_in_ordered_mode());

  GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rCtx);

  lExpr = rCtx.getRoot();

  if ( theCompilerCB->theConfig.optimize_cb != NULL )
    theCompilerCB->theConfig.optimize_cb(lExpr.getp(), "main query");

#if 0
  std::cout << "Num exprs after optimization = " 
            << theCompilerCB->getExprManager()->numExprs()
            << std::endl << std::endl;
#endif

  return lExpr;
}


/******************************************************************************
  This is a small helper class used when the user wants to compile a library
  module. The ONLY place it is used (and should be used) is in the
  XQueryCompiler::createMainModule method below.
  QQQ When we have the ability to compile a library module indepedently, this
  rather hacky class can go away. At that time, we can also eliminate the
  "stream URL" hack in StreamResource - this is the only place in the code where
  we use the two-arg StreamResource constructor.
*******************************************************************************/
class FakeLibraryModuleURLResolver : public internal::URLResolver
{
public:
  FakeLibraryModuleURLResolver(
      zstring const& aLibraryModuleNamespace,
      zstring const& aLibraryModuleFilename,
      std::istream& aStream)
    :
    theLibraryModuleNamespace(aLibraryModuleNamespace),
    theLibraryModuleFilename(aLibraryModuleFilename),
    theStream(aStream)
  {
  }

  virtual ~FakeLibraryModuleURLResolver()
  {
  }

  virtual internal::Resource* resolveURL(
      zstring const& aUrl,
      internal::EntityData const* aEntityData)
  {
    if (aUrl != theLibraryModuleNamespace)
    {
      return NULL;
    }
    assert (theStream.good());
    // Pass a nullptr StreamReleaser; memory ownership of the istream remains
    // with the caller of this method.
    // QQQ We can remove this third argument when we can compile modules individually
    return new internal::StreamResource(&theStream, nullptr,
                                    theLibraryModuleFilename);
  }

private:
  zstring theLibraryModuleNamespace;
  zstring theLibraryModuleFilename;
  std::istream& theStream;
};


/******************************************************************************
  Create a dummy main module to wrap a library module.
******************************************************************************/
parsenode_t XQueryCompiler::createMainModule(
    parsenode_t aLibraryModule,
    std::istream& aXQuery,
    const zstring& aFileName)
{
  //get the namespace from the LibraryModule
  LibraryModule* mod_ast = dynamic_cast<LibraryModule *>(&*aLibraryModule);
  if (!mod_ast)
    throw ZORBA_EXCEPTION(
      zerr::ZAPI0002_XQUERY_COMPILATION_FAILED,
      ERROR_PARAMS( ZED( BadLibraryModule ) )
		);

  const zstring& lib_namespace = mod_ast->get_decl()->get_target_namespace();

  URI lURI(lib_namespace);
  if(!lURI.is_absolute())
  {
    throw XQUERY_EXCEPTION(
      err::XQST0046, ERROR_PARAMS( lURI.toString(), ZED( MustBeAbsoluteURI ) ),
      ERROR_LOC( mod_ast->get_decl()->get_location() )
		);
  }

  // Set up the original query stream as the result of resolving the
  // library module's URI
  aXQuery.clear();
  aXQuery.seekg(0);
  FakeLibraryModuleURLResolver* aFakeResolver =
    new FakeLibraryModuleURLResolver(lib_namespace.str(), aFileName, aXQuery);
  theCompilerCB->theRootSctx->add_url_resolver(aFakeResolver);

  // create a dummy main module and parse it
  std::stringstream lDocStream;
  zstring tmp;
  zorba::xml::escape(lib_namespace, &tmp);
  lDocStream << "import module namespace m = '" << tmp << "'; 1";
  return parse(lDocStream, aFileName);
}


/*******************************************************************************

********************************************************************************/
XQueryCompilerSubsystem::XQueryCompilerSubsystem()
{
}


XQueryCompilerSubsystem::~XQueryCompilerSubsystem()
{
}


std::auto_ptr<XQueryCompilerSubsystem> XQueryCompilerSubsystem::create()
{
  return std::auto_ptr<XQueryCompilerSubsystem>(new XQueryCompilerSubsystemImpl());
}

}
/* vim:set et sw=2 ts=2: */
