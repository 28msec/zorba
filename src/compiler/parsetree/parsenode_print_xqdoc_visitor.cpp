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
#include "parsenode_print_xqdoc_visitor.h"

#include <ostream>
#include <stack>

#include <compiler/parsetree/parsenode_print_xquery_visitor.h>
#include <compiler/parsetree/parsenode_visitor.h>

#include <compiler/parser/xqdoc_comment.h>
#include <types/typemanager.h>
#include "store/api/item_factory.h"
#include "store/api/item.h"
#include "store/api/store.h"
#include "store/api/copymode.h"
#include "store/api/iterator.h"
#include "system/globalenv.h"

using namespace std;

namespace zorba {

class ParseNodePrintXQDocVisitor : public parsenode_visitor
{
private:
  string getFileName(const string& aFileName)
  {
    string::size_type lIndex = aFileName.find_last_of("/\\");
    if (lIndex == string::npos) {
      return aFileName;
    } else {
      return aFileName.substr(lIndex+1);
    }
  }

  void print_comment(store::Item_t& result, const XQDocComment* aComment)
  {
    if (aComment == 0) {
      return;
    }
    list<XQDocAnnotation> lAnnotations = aComment->getAnnotations();
    list<XQDocAnnotation>::const_iterator lIt;

    if (!aComment->getDescription().empty() ||
        lAnnotations.begin() != lAnnotations.end() ||
        aComment->hasVersion() ||
        aComment->hasReturn() ||
        aComment->isDeprecated()) {

      list<XQDocAnnotation> lAuthorAnn;
      list<XQDocAnnotation> lParamAnn;
      list<XQDocAnnotation> lErrorAnn;
      list<XQDocAnnotation> lSeeAnn;
      list<XQDocAnnotation> lSinceAnn;

      for (lIt = lAnnotations.begin(); lIt != lAnnotations.end(); ++lIt) {
        const XQDocAnnotation lAnnotation = *lIt;
        if (lAnnotation.getName() == "param") {
          lParamAnn.push_back(lAnnotation);
        } else if (lAnnotation.getName() == "error") {
          lErrorAnn.push_back(lAnnotation);
        } else if (lAnnotation.getName() == "see") {
          lSeeAnn.push_back(lAnnotation);
        } else if (lAnnotation.getName() == "author") {
          lAuthorAnn.push_back(lAnnotation);
        } else if (lAnnotation.getName() == "since") {
          lSinceAnn.push_back(lAnnotation);
        }
      }

      store::Item_t lCommentQName, lCommentElem;

      theFactory->createQName(lCommentQName, theXQDocNS, theXQDocPrefix, "comment");

      theFactory->createElementNode(
          lCommentElem, result, -1, lCommentQName, theTypeName,
          true, false, theNSBindings, theBaseURI);

      // description
      if (!aComment->getDescription().empty()) {
        printCommentFragment(lCommentElem, aComment->getDescription(), "description");
      }

      // author
      for (lIt = lAuthorAnn.begin(); lIt != lAuthorAnn.end(); ++lIt) {
        const XQDocAnnotation lAnnotation = *lIt;
        printCommentFragment(lCommentElem, lAnnotation.getValue(), "author");
      }

      // version
      if (aComment->hasVersion()) {
        printCommentFragment(lCommentElem, aComment->getVersion(), "version");
      }

      // param
      for (lIt = lParamAnn.begin(); lIt != lParamAnn.end(); ++lIt) {
        const XQDocAnnotation lAnnotation = *lIt;
        printCommentFragment(lCommentElem, lAnnotation.getValue(), "param");
      }

      // return
      if (aComment->hasReturn()) {
        printCommentFragment(lCommentElem, aComment->getReturn(), "return");
      }

      // error
      for (lIt = lErrorAnn.begin(); lIt != lErrorAnn.end(); ++lIt) {
        const XQDocAnnotation lAnnotation = *lIt;
        printCommentFragment(lCommentElem, lAnnotation.getValue(), "error");
      }

      // deprecated
      if (aComment->isDeprecated()) {
        printCommentFragment(lCommentElem, aComment->getDeprecatedComment(), "deprecated");
      }

      // see
      for (lIt = lSeeAnn.begin(); lIt != lSeeAnn.end(); ++lIt) {
        const XQDocAnnotation lAnnotation = *lIt;
        printCommentFragment(lCommentElem, lAnnotation.getValue(), "see");
      }

      // since
      for (lIt = lSinceAnn.begin(); lIt != lSinceAnn.end(); ++lIt) {
        const XQDocAnnotation lAnnotation = *lIt;
        printCommentFragment(lCommentElem, lAnnotation.getValue(), "since");
      }
    }
  }

  void printCommentFragment(store::Item_t& aParent, std::string aString, std::string aTag)
  {
    store::Item_t lQName, lElem, lText;

    theFactory->createQName(lQName, theXQDocNS, theXQDocPrefix, aTag.c_str());
    theFactory->createElementNode(
        lElem, aParent, -1, lQName, theTypeName,
        true, false, theNSBindings, theBaseURI);

    // parse the contents of the description in order
    // to be able to get proper XHTML tags
    // Therefore, we have to insert an artificial root tag
    // which is removed afterwards.
    std::ostringstream os;
    os << "<root>" << aString << "</root>";
    std::istringstream is(os.str());

    try {
      store::Item_t lContent = GENV_STORE.loadDocument(theBaseURI, theBaseURI, is, false);
      store::Iterator_t lIter = lContent->getChildren();
      store::Item_t lRootElem;
      lIter->open();
      if (lIter->next(lRootElem)) {
        store::Iterator_t lIter2 = lRootElem->getChildren();
        lIter2->open();
        size_t i = 0;
        store::Item_t lTmp;
        while (lIter2->next(lTmp)) {
          store::CopyMode lMode;
          // insert every element into the that that we create
          lTmp->copy(lElem, i++, lMode);
        }
      }

    } catch (error::ZorbaError& e) {
      ZORBA_ERROR_DESC_OSS(XQP0000_DYNAMIC_RUNTIME_ERROR, 
        "The xqdoc documentation contains an error that doesn't allow the document to be parsed as XML. "
        << e.theDescription << " '" << aString << "'");
    }
  }

protected:
  store::Item_t&      theResult;

  store::Item_t       theModule;
  store::Item_t       theImports;
  store::Item_t       theVariables;
  store::Item_t       theFunctions;

  const char*         theXQDocNS;
  const char*         theXQDocPrefix;

  xqpStringStore_t    theFileName;
  xqpStringStore_t    theBaseURI;
  xqpStringStore_t    theVersion;
  store::NsBindings   theNSBindings;
  store::Item_t       theTypeName;
  
  store::ItemFactory* theFactory;

  string        theQuery;

public:

ParseNodePrintXQDocVisitor(store::Item_t &aResult, const string& aFileName)
  : theResult(aResult),
    theXQDocNS("http://www.xqdoc.org/1.0"),
    theXQDocPrefix("xqdoc"),
    theFileName(new xqpStringStore(getFileName(aFileName))),
    theBaseURI(new xqpStringStore("http://www.xqdoc.org/1.0")),
    theVersion(new xqpStringStore("1.0")),
    theFactory(GENV_ITEMFACTORY)
{
}

void print(const parsenode* p, const store::Item_t& aDateTime)
{
  store::Item_t lXQDocQName, lControlQName, lDateQName, lVersionQName,
                lImportsQName, lVariablesQName, lFunctionsQName, lModuleQName;

  store::Item_t lControlElem, lDateElem, lVersionElem,
                lDateText, lVersionText;

  theFactory->createQName(lXQDocQName, theXQDocNS, theXQDocPrefix, "xqdoc");
  theFactory->createQName(lControlQName, theXQDocNS, theXQDocPrefix, "control");
  theFactory->createQName(lDateQName, theXQDocNS, theXQDocPrefix, "date");
  theFactory->createQName(lVersionQName, theXQDocNS, theXQDocPrefix, "version");
  theFactory->createQName(lImportsQName, theXQDocNS, theXQDocPrefix, "imports");
  theFactory->createQName(lVariablesQName, theXQDocNS, theXQDocPrefix, "variables");
  theFactory->createQName(lFunctionsQName, theXQDocNS, theXQDocPrefix, "functions");
  theFactory->createQName(lModuleQName, theXQDocNS, theXQDocPrefix, "module");

  // create the prolog
  // <xqdoc><control><date/><version/></control>
  theFactory->createElementNode(
      theResult, NULL, -1, lXQDocQName, theTypeName,
      true, false, theNSBindings, theBaseURI);

  // control, module, imports, functions
  theFactory->createElementNode(
      lControlElem, theResult, -1, lControlQName, theTypeName,
      true, false, theNSBindings, theBaseURI);

  theFactory->createElementNode(
      theModule, theResult, -1, lModuleQName, theTypeName,
      true, false, theNSBindings, theBaseURI);

  theFactory->createElementNode(
      theImports, theResult, -1, lImportsQName, theTypeName,
      true, false, theNSBindings, theBaseURI);

  theFactory->createElementNode(
      theVariables, theResult, -1, lVariablesQName, theTypeName,
      true, false, theNSBindings, theBaseURI);

  theFactory->createElementNode(
      theFunctions, theResult, -1, lFunctionsQName, theTypeName,
      true, false, theNSBindings, theBaseURI);

  // date version
  theFactory->createElementNode(
      lDateElem, lControlElem, -1, lDateQName, theTypeName,
      true, false, theNSBindings, theBaseURI);

  theFactory->createElementNode(
      lVersionElem, lControlElem, -1, lVersionQName, theTypeName,
      true, false, theNSBindings, theBaseURI);

  xqpStringStore_t lDate = aDateTime->getStringValue();
  theFactory->createTextNode(lDateText, lDateElem.getp(), -1, lDate);

  theFactory->createTextNode(lVersionText, lVersionElem, -1, theVersion);

    
  p->accept(*this);

}

#define IDS \
  " pos='" << n.get_location() << "' ptr='" << &n << "'"


#define XQDOC_NO_BEGIN_TAG( cls )       \
  void *begin_visit(const cls& /*n*/) { \
    return no_state;                    \
  }

#define XQDOC_NO_END_TAG( cls )                                     \
  void end_visit(const cls& /*n*/, void* /*visit_state*/) {}

#define XQDOC_NO_BEGIN_END_TAG( cls ) \
  XQDOC_NO_BEGIN_TAG (cls)            \
  XQDOC_NO_END_TAG (cls)

XQDOC_NO_BEGIN_END_TAG (AbbrevForwardStep)
XQDOC_NO_BEGIN_END_TAG (CaseClause)
XQDOC_NO_BEGIN_END_TAG (DefaultNamespaceDecl)
XQDOC_NO_BEGIN_END_TAG (DirAttr)
XQDOC_NO_BEGIN_END_TAG (ForwardAxis)
XQDOC_NO_BEGIN_END_TAG (GeneralComp)

// TODO: main module 
XQDOC_NO_BEGIN_END_TAG (MainModule)

XQDOC_NO_BEGIN_TAG (ModuleDecl)

void end_visit(const ModuleDecl& n, void* /*visit_state*/)
{
  store::Item_t lURIQName, lNameQName, lTypeQName;

  store::Item_t lURIElem, lNameElem, lTypeAttr, lURIText, lNameText;

  theFactory->createQName(lURIQName, theXQDocNS, theXQDocPrefix, "uri");
  theFactory->createQName(lNameQName, theXQDocNS, theXQDocPrefix, "name");
  theFactory->createQName(lTypeQName, "", "", "type");

  store::Item_t lAttrValue;
  xqpStringStore_t lAttrString(new xqpStringStore("library"));
  theFactory->createString(lAttrValue, lAttrString);

  theFactory->createAttributeNode(
      lTypeAttr, theModule, -1, lTypeQName, theTypeName, lAttrValue);

  theFactory->createElementNode(
      lURIElem, theModule, -1, lURIQName, theTypeName,
      true, false, theNSBindings, theBaseURI);

  xqpStringStore_t lTargetNS = n.get_target_namespace();
  theFactory->createTextNode(lURIText, lURIElem.getp(), -1, lTargetNS);

  theFactory->createElementNode(
      lNameElem, theModule, -1, lNameQName, theTypeName,
      true, false, theNSBindings, theBaseURI);
  theFactory->createTextNode(lNameText, lNameElem, -1, theFileName);

  print_comment(theModule, n.getComment());
}

XQDOC_NO_BEGIN_TAG (FunctionDecl)

void end_visit(const FunctionDecl& n, void* /*visit_state*/)
{
  store::Item_t lFuncQName, lNameQName, lSigQName;
  store::Item_t lFuncElem, lNameElem, lSigElem, lFuncText, lNameText, lSigText;

  theFactory->createQName(lFuncQName, theXQDocNS, theXQDocPrefix, "function");
  theFactory->createQName(lNameQName, theXQDocNS, theXQDocPrefix, "name");
  theFactory->createQName(lSigQName, theXQDocNS, theXQDocPrefix, "signature");

  theFactory->createElementNode(
      lFuncElem, theFunctions, -1, lFuncQName, theTypeName,
      true, false, theNSBindings, theBaseURI);

  print_comment(lFuncElem, n.getComment());

  theFactory->createElementNode(
      lNameElem, lFuncElem, -1, lNameQName, theTypeName,
      true, false, theNSBindings, theBaseURI);

  theFactory->createElementNode(
      lSigElem,  lFuncElem, -1, lSigQName, theTypeName,
      true, false, theNSBindings, theBaseURI);


  xqpStringStore_t lNameString = n.get_name()->get_localname();
  theFactory->createTextNode(lNameText, lNameElem, -1, lNameString);

  std::ostringstream lSig;

  FunctionDecl lFunctionDeclClone(n.get_location(), n.get_name(), n.get_paramlist(), n.get_return_type(), 0, n.get_kind());
  FunctionIndex lIndex = print_parsetree_xquery(lSig, &lFunctionDeclClone);

  xqpStringStore_t lSigString = new xqpStringStore(lSig.str());
  theFactory->createTextNode(lSigText, lSigElem, -1, lSigString);
}

XQDOC_NO_BEGIN_TAG (VarDecl)

void end_visit(const VarDecl& n, void*)
{
  store::Item_t lVariableQName, lUriQName;
  store::Item_t lVariableElem, lUriElem, lUriText;

  theFactory->createQName(lVariableQName, theXQDocNS, theXQDocPrefix, "variable");
  theFactory->createQName(lUriQName, theXQDocNS, theXQDocPrefix, "uri");

  theFactory->createElementNode(
      lVariableElem, theVariables, -1, lVariableQName, theTypeName,
      true, false, theNSBindings, theBaseURI);

  theFactory->createElementNode(
      lUriElem, lVariableElem, -1, lUriQName, theTypeName,
      true, false, theNSBindings, theBaseURI);

  xqpStringStore_t lUriString(new xqpStringStore(n.get_name()->get_localname()->c_str()));
  theFactory->createTextNode(lUriText, lUriElem, -1, lUriString);

  print_comment(lVariableElem, n.getComment());
}


XQDOC_NO_BEGIN_TAG (ModuleImport)

void end_visit(const ModuleImport& n, void*)
{
  store::Item_t lImportQName, lUriQName;
  store::Item_t lImportElem, lUriElem, lUriText;

  theFactory->createQName(lImportQName, theXQDocNS, theXQDocPrefix, "import");
  theFactory->createQName(lUriQName, theXQDocNS, theXQDocPrefix, "uri");

  theFactory->createElementNode(
      lImportElem, theImports, -1, lImportQName, theTypeName,
      true, false, theNSBindings, theBaseURI);

  theFactory->createElementNode(
      lUriElem, lImportElem, -1, lUriQName, theTypeName,
      true, false, theNSBindings, theBaseURI);

  xqpStringStore_t lUriString(new xqpStringStore(n.get_uri()->c_str()));
  theFactory->createTextNode(lUriText, lUriElem, -1, lUriString);

  print_comment(lImportElem, n.getComment());
}

XQDOC_NO_BEGIN_END_TAG (AdditiveExpr)
XQDOC_NO_BEGIN_END_TAG (AndExpr)
XQDOC_NO_BEGIN_END_TAG (AnyKindTest)
XQDOC_NO_BEGIN_END_TAG (AposAttrContentList)
XQDOC_NO_BEGIN_END_TAG (AposAttrValueContent)
XQDOC_NO_BEGIN_END_TAG (ArgList)
XQDOC_NO_BEGIN_END_TAG (AssignExpr)
XQDOC_NO_BEGIN_END_TAG (AtomicType)
XQDOC_NO_BEGIN_END_TAG (AttributeTest)
XQDOC_NO_BEGIN_END_TAG (AxisStep)
XQDOC_NO_BEGIN_END_TAG (BaseURIDecl)
XQDOC_NO_BEGIN_END_TAG (BlockBody)
XQDOC_NO_BEGIN_END_TAG (BoundarySpaceDecl)
XQDOC_NO_BEGIN_END_TAG (CaseClauseList)
XQDOC_NO_BEGIN_END_TAG (CastableExpr)
XQDOC_NO_BEGIN_END_TAG (CastExpr)
XQDOC_NO_BEGIN_END_TAG (CatchExpr)
XQDOC_NO_BEGIN_END_TAG (CatchListExpr)
XQDOC_NO_BEGIN_END_TAG (CDataSection)
XQDOC_NO_BEGIN_END_TAG (CollectionDecl)
XQDOC_NO_BEGIN_END_TAG (CommentTest)
XQDOC_NO_BEGIN_END_TAG (CommonContent)
XQDOC_NO_BEGIN_END_TAG (ComparisonExpr)
XQDOC_NO_BEGIN_END_TAG (CompAttrConstructor)
XQDOC_NO_BEGIN_END_TAG (CompCommentConstructor)
XQDOC_NO_BEGIN_END_TAG (CompDocConstructor)
XQDOC_NO_BEGIN_END_TAG (CompElemConstructor)
XQDOC_NO_BEGIN_END_TAG (CompPIConstructor)
XQDOC_NO_BEGIN_END_TAG (CompTextConstructor)
XQDOC_NO_BEGIN_END_TAG (ConstructionDecl)
XQDOC_NO_BEGIN_END_TAG (ContextItemExpr)
XQDOC_NO_BEGIN_END_TAG (CopyNamespacesDecl)
XQDOC_NO_BEGIN_END_TAG (CopyVarList)
XQDOC_NO_BEGIN_END_TAG (CountClause)
XQDOC_NO_BEGIN_END_TAG (CtxItemDecl)
XQDOC_NO_BEGIN_END_TAG (DecimalFormatNode)
XQDOC_NO_BEGIN_END_TAG (DefaultCollationDecl)
XQDOC_NO_BEGIN_END_TAG (DeleteExpr)
XQDOC_NO_BEGIN_END_TAG (DirAttributeList)
XQDOC_NO_BEGIN_END_TAG (DirAttributeValue)
XQDOC_NO_BEGIN_END_TAG (DirCommentConstructor)
XQDOC_NO_BEGIN_END_TAG (DirElemConstructor)
XQDOC_NO_BEGIN_END_TAG (DirElemContent)
XQDOC_NO_BEGIN_END_TAG (DirElemContentList)
XQDOC_NO_BEGIN_END_TAG (DirPIConstructor)
XQDOC_NO_BEGIN_END_TAG (DocumentTest)
XQDOC_NO_BEGIN_END_TAG (ElementTest)
XQDOC_NO_BEGIN_END_TAG (EmptyOrderDecl)
XQDOC_NO_BEGIN_END_TAG (EnclosedExpr)
XQDOC_NO_BEGIN_END_TAG (EvalExpr)
XQDOC_NO_BEGIN_END_TAG (ExitExpr)
XQDOC_NO_BEGIN_END_TAG (Expr)
XQDOC_NO_BEGIN_END_TAG (exprnode)
XQDOC_NO_BEGIN_END_TAG (ExtensionExpr)
XQDOC_NO_BEGIN_END_TAG (FilterExpr)
XQDOC_NO_BEGIN_END_TAG (FlowCtlStatement)
XQDOC_NO_BEGIN_END_TAG (FLWORClauseList)
XQDOC_NO_BEGIN_END_TAG (FLWORExpr)
XQDOC_NO_BEGIN_END_TAG (FLWORWinCond)
XQDOC_NO_BEGIN_END_TAG (ForClause)
XQDOC_NO_BEGIN_END_TAG (ForwardStep)
XQDOC_NO_BEGIN_END_TAG (FTAnd)
XQDOC_NO_BEGIN_END_TAG (FTAnyallOption)
XQDOC_NO_BEGIN_END_TAG (FTBigUnit)
XQDOC_NO_BEGIN_END_TAG (FTCaseOption)
XQDOC_NO_BEGIN_END_TAG (FTContainsExpr)
XQDOC_NO_BEGIN_END_TAG (FTContent)
XQDOC_NO_BEGIN_END_TAG (FTDiacriticsOption)
XQDOC_NO_BEGIN_END_TAG (FTDistance)
XQDOC_NO_BEGIN_END_TAG (FTExtensionOption)
XQDOC_NO_BEGIN_END_TAG (FTExtensionSelection)
XQDOC_NO_BEGIN_END_TAG (FTIgnoreOption)
XQDOC_NO_BEGIN_END_TAG (FTLanguageOption)
XQDOC_NO_BEGIN_END_TAG (FTMatchOptions)
XQDOC_NO_BEGIN_END_TAG (FTMildNot)
XQDOC_NO_BEGIN_END_TAG (FTOptionDecl)
XQDOC_NO_BEGIN_END_TAG (FTOr)
XQDOC_NO_BEGIN_END_TAG (FTOrder)
XQDOC_NO_BEGIN_END_TAG (FTPrimaryWithOptions)
XQDOC_NO_BEGIN_END_TAG (FTRange)
XQDOC_NO_BEGIN_END_TAG (FTScope)
XQDOC_NO_BEGIN_END_TAG (FTScoreVar)
XQDOC_NO_BEGIN_END_TAG (FTSelection)
XQDOC_NO_BEGIN_END_TAG (FTStemOption)
XQDOC_NO_BEGIN_END_TAG (FTStopWordOption)
XQDOC_NO_BEGIN_END_TAG (FTStopWords)
XQDOC_NO_BEGIN_END_TAG (FTStopWordsInclExcl)
XQDOC_NO_BEGIN_END_TAG (FTThesaurusID)
XQDOC_NO_BEGIN_END_TAG (FTThesaurusOption)
XQDOC_NO_BEGIN_END_TAG (FTTimes)
XQDOC_NO_BEGIN_END_TAG (FTUnaryNot)
XQDOC_NO_BEGIN_END_TAG (FTUnit)
XQDOC_NO_BEGIN_END_TAG (FTWeight)
XQDOC_NO_BEGIN_END_TAG (FTWildCardOption)
XQDOC_NO_BEGIN_END_TAG (FTWindow)
XQDOC_NO_BEGIN_END_TAG (FTWords)
XQDOC_NO_BEGIN_END_TAG (FTWordsTimes)
XQDOC_NO_BEGIN_END_TAG (FTWordsValue)
XQDOC_NO_BEGIN_END_TAG (FunctionCall)
XQDOC_NO_BEGIN_END_TAG (GroupByClause)
XQDOC_NO_BEGIN_END_TAG (GroupCollationSpec)
XQDOC_NO_BEGIN_END_TAG (GroupSpec)
XQDOC_NO_BEGIN_END_TAG (GroupSpecList)
XQDOC_NO_BEGIN_END_TAG (IfExpr)
XQDOC_NO_BEGIN_END_TAG (AST_IndexDecl)
XQDOC_NO_BEGIN_END_TAG (IndexKeyList)
XQDOC_NO_BEGIN_END_TAG (IndexKeySpec)
XQDOC_NO_BEGIN_END_TAG (InsertExpr)
XQDOC_NO_BEGIN_END_TAG (InstanceofExpr)
XQDOC_NO_BEGIN_END_TAG (IntegrityConstraintDecl)
XQDOC_NO_BEGIN_END_TAG (IntersectExceptExpr)
XQDOC_NO_BEGIN_END_TAG (ItemType)
XQDOC_NO_BEGIN_END_TAG (LetClause)
XQDOC_NO_BEGIN_END_TAG (LibraryModule)
XQDOC_NO_BEGIN_END_TAG (Module)
XQDOC_NO_BEGIN_END_TAG (MultiplicativeExpr)
XQDOC_NO_BEGIN_END_TAG (NamespaceDecl)
XQDOC_NO_BEGIN_END_TAG (NameTest)
XQDOC_NO_BEGIN_END_TAG (NodeComp)
XQDOC_NO_BEGIN_END_TAG (NodeModifier)
XQDOC_NO_BEGIN_END_TAG (NumericLiteral)
XQDOC_NO_BEGIN_END_TAG (OccurrenceIndicator)
XQDOC_NO_BEGIN_END_TAG (OptionDecl)
XQDOC_NO_BEGIN_END_TAG (OrderByClause)
XQDOC_NO_BEGIN_END_TAG (OrderCollationSpec)
XQDOC_NO_BEGIN_END_TAG (OrderDirSpec)
XQDOC_NO_BEGIN_END_TAG (OrderedExpr)
XQDOC_NO_BEGIN_END_TAG (OrderEmptySpec)
XQDOC_NO_BEGIN_END_TAG (OrderingModeDecl)
XQDOC_NO_BEGIN_END_TAG (OrderModifierPN)
XQDOC_NO_BEGIN_END_TAG (OrderSpec)
XQDOC_NO_BEGIN_END_TAG (OrderSpecList)
XQDOC_NO_BEGIN_END_TAG (OrExpr)
XQDOC_NO_BEGIN_END_TAG (Param)
XQDOC_NO_BEGIN_END_TAG (ParamList)
XQDOC_NO_BEGIN_END_TAG (ParenthesizedExpr)
XQDOC_NO_BEGIN_END_TAG (ParseErrorNode)
XQDOC_NO_BEGIN_END_TAG (parsenode)
XQDOC_NO_BEGIN_END_TAG (PathExpr)
XQDOC_NO_BEGIN_END_TAG (PITest)
XQDOC_NO_BEGIN_END_TAG (PositionalVar)
XQDOC_NO_BEGIN_END_TAG (Pragma)
XQDOC_NO_BEGIN_END_TAG (PragmaList)
XQDOC_NO_BEGIN_END_TAG (PredicateList)
XQDOC_NO_BEGIN_END_TAG (Prolog)
XQDOC_NO_BEGIN_END_TAG (QName)
XQDOC_NO_BEGIN_END_TAG (QuantifiedExpr)
XQDOC_NO_BEGIN_END_TAG (QueryBody)
XQDOC_NO_BEGIN_END_TAG (QuoteAttrContentList)
XQDOC_NO_BEGIN_END_TAG (QuoteAttrValueContent)
XQDOC_NO_BEGIN_END_TAG (QVarInDecl)
XQDOC_NO_BEGIN_END_TAG (QVarInDeclList)
XQDOC_NO_BEGIN_END_TAG (RangeExpr)
XQDOC_NO_BEGIN_END_TAG (RelativePathExpr)
XQDOC_NO_BEGIN_END_TAG (RenameExpr)
XQDOC_NO_BEGIN_END_TAG (ReplaceExpr)
XQDOC_NO_BEGIN_END_TAG (RevalidationDecl)
XQDOC_NO_BEGIN_END_TAG (ReverseAxis)
XQDOC_NO_BEGIN_END_TAG (ReverseStep)
XQDOC_NO_BEGIN_END_TAG (SchemaAttributeTest)
XQDOC_NO_BEGIN_END_TAG (SchemaElementTest)
XQDOC_NO_BEGIN_END_TAG (SchemaImport)
XQDOC_NO_BEGIN_END_TAG (SchemaPrefix)
XQDOC_NO_BEGIN_END_TAG (SequenceType)
XQDOC_NO_BEGIN_END_TAG (SignList)
XQDOC_NO_BEGIN_END_TAG (SIND_DeclList)
XQDOC_NO_BEGIN_END_TAG (SingleType)
XQDOC_NO_BEGIN_END_TAG (StringLiteral)
XQDOC_NO_BEGIN_END_TAG (TextTest)
XQDOC_NO_BEGIN_END_TAG (TransformExpr)
XQDOC_NO_BEGIN_END_TAG (TreatExpr)
XQDOC_NO_BEGIN_END_TAG (TryExpr)
XQDOC_NO_BEGIN_END_TAG (TypeName)
XQDOC_NO_BEGIN_END_TAG (SwitchExpr)
XQDOC_NO_BEGIN_END_TAG (SwitchCaseClause)
XQDOC_NO_BEGIN_END_TAG (SwitchCaseClauseList)
XQDOC_NO_BEGIN_END_TAG (SwitchCaseOperandList)
XQDOC_NO_BEGIN_END_TAG (TypeswitchExpr)
XQDOC_NO_BEGIN_END_TAG (UnaryExpr)
XQDOC_NO_BEGIN_END_TAG (UnionExpr)
XQDOC_NO_BEGIN_END_TAG (UnorderedExpr)
XQDOC_NO_BEGIN_END_TAG (URILiteralList)
XQDOC_NO_BEGIN_END_TAG (ValidateExpr)
XQDOC_NO_BEGIN_END_TAG (ValueComp)
XQDOC_NO_BEGIN_END_TAG (VarBinding)
XQDOC_NO_BEGIN_END_TAG (VarGetsDecl)
XQDOC_NO_BEGIN_END_TAG (VarGetsDeclList)
XQDOC_NO_BEGIN_END_TAG (VarInDecl)
XQDOC_NO_BEGIN_END_TAG (VarInDeclList)
XQDOC_NO_BEGIN_END_TAG (VarRef)
XQDOC_NO_BEGIN_END_TAG (VersionDecl)
XQDOC_NO_BEGIN_END_TAG (VFO_DeclList)
XQDOC_NO_BEGIN_END_TAG (WhereClause)
XQDOC_NO_BEGIN_END_TAG (WhileExpr)
XQDOC_NO_BEGIN_END_TAG (Wildcard)
XQDOC_NO_BEGIN_END_TAG (WindowClause)
XQDOC_NO_BEGIN_END_TAG (WindowVarDecl)
XQDOC_NO_BEGIN_END_TAG (WindowVars)

XQDOC_NO_BEGIN_END_TAG (LiteralFunctionItem)
XQDOC_NO_BEGIN_END_TAG (InlineFunction)
XQDOC_NO_BEGIN_END_TAG (AnyFunctionTest)
XQDOC_NO_BEGIN_END_TAG (TypeList)
XQDOC_NO_BEGIN_END_TAG (TypedFunctionTest)
XQDOC_NO_BEGIN_END_TAG (DynamicFunctionInvocation)

};

void print_parsetree_xqdoc(
  store::Item_t&      result,
  const parsenode*    p,
  const string&       aFileName,
  const store::Item_t& aDateTime)
{
  ParseNodePrintXQDocVisitor v(result, aFileName);
  v.print(p, aDateTime);
}

} // end namespace
