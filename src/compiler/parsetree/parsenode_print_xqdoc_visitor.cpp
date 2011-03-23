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
#include <map>

#include <compiler/parsetree/parsenode_print_xquery_visitor.h>
#include <compiler/parsetree/parsenode_visitor.h>

#include <compiler/parser/xqdoc_comment.h>
#include "types/root_typemanager.h"
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
  if (lIndex == string::npos) 
  {
    return aFileName;
  }
  else
  {
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
    list<XQDocAnnotation> lLibraryAnn;
    list<XQDocAnnotation> lExampleAnn;

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
      } else if (lAnnotation.getName() == "library") {
        lLibraryAnn.push_back(lAnnotation);
      } else if (lAnnotation.getName() == "example") {
        lExampleAnn.push_back(lAnnotation);
      }
    }

    store::Item_t lCommentQName, lCommentElem;

    theFactory->createQName(lCommentQName, theXQDocNS, theXQDocPrefix, "comment");

    store::Item_t lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
    theFactory->createElementNode(lCommentElem, result,
                                  lCommentQName, lTypeName,
                                  true, false, theNSBindings, theBaseURI);
    
    // description
    if (!aComment->getDescription().empty()) {
      printCommentFragment(lCommentElem, aComment->getDescription().str(), "description");
    }

    // author
    for (lIt = lAuthorAnn.begin(); lIt != lAuthorAnn.end(); ++lIt) {
      const XQDocAnnotation lAnnotation = *lIt;
      printCommentFragment(lCommentElem, lAnnotation.getValue().str(), "author");
    }

    // version
    if (aComment->hasVersion()) {
      printCommentFragment(lCommentElem, aComment->getVersion().str(), "version");
    }

    // param
    for (lIt = lParamAnn.begin(); lIt != lParamAnn.end(); ++lIt) {
      const XQDocAnnotation lAnnotation = *lIt;
      printCommentFragment(lCommentElem, lAnnotation.getValue().str(), "param");
    }

    // return
    if (aComment->hasReturn()) {
      printCommentFragment(lCommentElem, aComment->getReturn().str(), "return");
    }

    // error
    for (lIt = lErrorAnn.begin(); lIt != lErrorAnn.end(); ++lIt) {
      const XQDocAnnotation lAnnotation = *lIt;
      printCommentFragment(lCommentElem, lAnnotation.getValue().str(), "error");
    }

    // deprecated
    if (aComment->isDeprecated()) {
      printCommentFragment(lCommentElem, aComment->getDeprecatedComment().str(), "deprecated");
    }
    
    // see
    for (lIt = lSeeAnn.begin(); lIt != lSeeAnn.end(); ++lIt) {
      const XQDocAnnotation lAnnotation = *lIt;
      printCommentFragment(lCommentElem, lAnnotation.getValue().str(), "see");
    }
    
    // since
    for (lIt = lSinceAnn.begin(); lIt != lSinceAnn.end(); ++lIt) {
      const XQDocAnnotation lAnnotation = *lIt;
      printCommentFragment(lCommentElem, lAnnotation.getValue().str(), "since");
    }
    
    // library
    for (lIt = lLibraryAnn.begin(); lIt != lLibraryAnn.end(); ++lIt) {
      const XQDocAnnotation lAnnotation = *lIt;
      printCommentFragment(lCommentElem, lAnnotation.getValue().str(), "library");
    }

    // example
    for (lIt = lExampleAnn.begin(); lIt != lExampleAnn.end(); ++lIt) {
      const XQDocAnnotation lAnnotation = *lIt;
      printCommentFragment(lCommentElem, lAnnotation.getValue().str(), "example");
    }
  }
}


void printCommentFragment(store::Item_t& aParent, string aString, string aTag)
{
  store::Item_t lQName, lElem, lText;

  store::Item_t lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createQName(lQName, theXQDocNS, theXQDocPrefix, aTag.c_str());
  theFactory->createElementNode(lElem, aParent, lQName, lTypeName,
                                true, false, theNSBindings, theBaseURI);

  // parse the contents of the description in order
  // to be able to get proper XHTML tags
  // Therefore, we have to insert an artificial root tag
  // which is removed afterwards.
  ostringstream os;
  os << "<root>" << aString << "</root>";
  istringstream is(os.str());
  
  try 
  {
    store::LoadProperties loadProperties;
    loadProperties.setStoreDocument(false);
    store::Item_t lContent = GENV_STORE.loadDocument(theBaseURI,
                                                     theBaseURI,
                                                     is,
                                                     loadProperties);
    store::Iterator_t lIter = lContent->getChildren();
    store::Item_t lRootElem;
    lIter->open();
    if (lIter->next(lRootElem)) 
    {
      store::Iterator_t lIter2 = lRootElem->getChildren();
      lIter2->open();
      store::Item_t lTmp;
      while (lIter2->next(lTmp))
      {
        store::CopyMode lMode;
        // insert every element into the that that we create
        lTmp->copy(lElem, lMode);
      }
    }
  }
  catch (error::ZorbaError& e)
  {
    ZORBA_ERROR_DESC_OSS(XQD0001_DOCUMENT_NOT_VALID,
                         "The xqdoc documentation contains an error that doesn't allow the document to be parsed as XML. "
                         << e.theDescription << " '" << aString << "'");
  }
}

  
protected:
  store::Item_t&       theResult;

  store::Item_t        theModule;
  store::Item_t        theImports;
  store::Item_t        theVariables;
  store::Item_t        theFunctions;

  // set of functions being invoked in the function
  // whoes declaration is currently being processed
  map<string, store::Item_t>  theInvokedFunc;

  // prefix -> uri
  map<zstring, zstring> theNamespaces;

  const char*          theXQDocNS;
  const char*          theXQDocPrefix;

  zstring              theFileName;
  zstring              theBaseURI;
  zstring              theVersion;
  store::NsBindings    theNSBindings;

  store::ItemFactory * theFactory;

  string               theQuery;

public:

ParseNodePrintXQDocVisitor(store::Item_t& aResult, const string& aFileName)
  :
  theResult(aResult),
  theXQDocNS("http://www.xqdoc.org/1.0"),
  theXQDocPrefix("xqdoc"),
  theFileName(getFileName(aFileName)),
  theBaseURI("http://www.xqdoc.org/1.0"),
  theVersion("1.0"),
  theFactory(GENV_ITEMFACTORY)
{
  theNamespaces["fn"] = "http://www.w3.org/2005/xpath-functions";
  theNamespaces["math"] = "http://www.w3.org/2005/xpath-functions/math";
  theNamespaces[""] = "http://www.w3.org/2005/xpath-functions";
  theNamespaces["xs"] = "http://www.w3.org/2001/XMLSchema";
  theNamespaces["local"] = "http://www.w3.org/2005/xquery-local-functions";
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

  store::Item_t lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;

  // create the prolog
  // <xqdoc><control><date/><version/></control>
  theFactory->createElementNode(theResult, NULL,
                                lXQDocQName, lTypeName,
                                true, false, theNSBindings, theBaseURI);

  // control, module, imports, functions
  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(lControlElem, theResult,
                                lControlQName, lTypeName,
                                true, false, theNSBindings, theBaseURI);

  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(theModule, theResult,
                                lModuleQName, lTypeName,
                                true, false, theNSBindings, theBaseURI);

  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(theImports, theResult, 
                                lImportsQName, lTypeName,
                                true, false, theNSBindings, theBaseURI);

  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(theVariables, theResult, 
                                lVariablesQName, lTypeName,
                                true, false, theNSBindings, theBaseURI);

  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(theFunctions, theResult, 
                                lFunctionsQName, lTypeName,
                                true, false, theNSBindings, theBaseURI);

  // date version
  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(lDateElem, lControlElem, 
                                lDateQName, lTypeName,
                                true, false, theNSBindings, theBaseURI);

  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(lVersionElem, lControlElem, 
                                lVersionQName, lTypeName,
                                true, false, theNSBindings, theBaseURI);

  zstring lDate;
  aDateTime->getStringValue2(lDate);

  theFactory->createTextNode(lDateText, lDateElem.getp(), lDate);

  theFactory->createTextNode(lVersionText, lVersionElem, theVersion);

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
XQDOC_NO_BEGIN_END_TAG (DirAttr)
XQDOC_NO_BEGIN_END_TAG (ForwardAxis)
XQDOC_NO_BEGIN_END_TAG (GeneralComp)

XQDOC_NO_BEGIN_TAG (DefaultNamespaceDecl)

void end_visit(const DefaultNamespaceDecl& n, void* /*visit_state*/)
{
  if (n.get_mode() == ParseConstants::ns_function_default)
    theNamespaces[""] = n.get_default_namespace();
}

XQDOC_NO_BEGIN_TAG (MainModule)
void end_visit(const MainModule& n, void* /*visit_state*/)
{
  store::Item_t lURIQName, lNameQName, lTypeQName;
  store::Item_t lURIElem, lTypeAttr, lURIText;

  theFactory->createQName(lTypeQName, "", "", "type");
  theFactory->createQName(lURIQName, theXQDocNS, theXQDocPrefix, "uri");

  // @type="main"
  store::Item_t lAttrValue;
  zstring lAttrString("main");
  theFactory->createString(lAttrValue, lAttrString);

  store::Item_t lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createAttributeNode(lTypeAttr, theModule,
                                  lTypeQName, lTypeName, lAttrValue);

  // <uri>filename</uri>
  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(lURIElem, theModule, 
                                lURIQName, lTypeName,
                                true, false, theNSBindings, theBaseURI);

  theFactory->createTextNode(lURIText, lURIElem.getp(), theFileName);

  //print_comment(theModule, n.getComment());
}

void *begin_visit(const ModuleDecl& n) {
  theNamespaces[n.get_prefix()] = n.get_target_namespace();
  return no_state;
}

void end_visit(const ModuleDecl& n, void* /*visit_state*/)
{
  store::Item_t lURIQName, lNameQName, lTypeQName;

  store::Item_t lURIElem, lNameElem, lTypeAttr, lURIText, lNameText;

  theFactory->createQName(lURIQName, theXQDocNS, theXQDocPrefix, "uri");
  theFactory->createQName(lNameQName, theXQDocNS, theXQDocPrefix, "name");
  theFactory->createQName(lTypeQName, "", "", "type");

  store::Item_t lAttrValue;
  zstring lAttrString("library");
  theFactory->createString(lAttrValue, lAttrString);

  store::Item_t lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createAttributeNode(lTypeAttr, theModule, 
                                  lTypeQName, lTypeName, lAttrValue);

  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(lURIElem, theModule, 
                                lURIQName, lTypeName,
                                true, false, theNSBindings, theBaseURI);

  zstring lTargetNS = n.get_target_namespace();
  theFactory->createTextNode(lURIText, lURIElem.getp(), lTargetNS);

  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(lNameElem, theModule,
                                lNameQName, lTypeName,
                                true, false, theNSBindings, theBaseURI);

  theFactory->createTextNode(lNameText, lNameElem, theFileName);

  print_comment(theModule, n.getComment());
}

XQDOC_NO_BEGIN_TAG (FunctionDecl)

void end_visit(const FunctionDecl& n, void* /*visit_state*/)
{
  store::Item_t lFuncQName, lNameQName, lSigQName, lArityQName, lPrivateQName;
  store::Item_t lFuncElem, lNameElem, lSigElem, lFuncText, lNameText, lSigText;
  store::Item_t lArityAttr, lArityValue, lPrivateValue;

  theFactory->createQName(lFuncQName, theXQDocNS, theXQDocPrefix, "function");
  theFactory->createQName(lNameQName, theXQDocNS, theXQDocPrefix, "name");
  theFactory->createQName(lSigQName, theXQDocNS, theXQDocPrefix, "signature");
  theFactory->createQName(lArityQName, "", "", "arity");
  if(n.is_private())
    theFactory->createQName(lPrivateQName, "", "", "isPrivate");

  store::Item_t lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(
      lFuncElem, theFunctions, lFuncQName, lTypeName,
      true, false, theNSBindings, theBaseURI);

  print_comment(lFuncElem, n.getComment());

  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(
      lNameElem, lFuncElem, lNameQName, lTypeName,
      true, false, theNSBindings, theBaseURI);

  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  ostringstream lAttr;
  lAttr << (n.get_param_count());

  zstring lAttrString(lAttr.str().c_str());
  theFactory->createString(lArityValue, lAttrString);

  theFactory->createAttributeNode(
      lArityQName, lFuncElem, lArityQName, lTypeName, lArityValue);
  
  if(n.is_private())
  {
    zstring lPrivateString("true");
    theFactory->createString(lPrivateValue, lPrivateString);
    theFactory->createAttributeNode(
      lPrivateQName, lFuncElem, lPrivateQName, lTypeName, lPrivateValue);
  }

  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(lSigElem, lFuncElem, lSigQName, lTypeName,
                                true, false, theNSBindings, theBaseURI);

  zstring lNameString = n.get_name()->get_localname();
  theFactory->createTextNode(lNameText, lNameElem, lNameString);

  ostringstream lSig;

  FunctionDecl lFunctionDeclClone(n.get_location(),
                                  n.get_name(),
                                  n.get_paramlist(),
                                  n.get_return_type(),
                                  0,
                                  n.get_kind(),
                                  n.get_annotations());

  FunctionIndex lIndex = print_parsetree_xquery(lSig, &lFunctionDeclClone);

  zstring lSigString = lSig.str();
  theFactory->createTextNode(lSigText, lSigElem, lSigString);

  // add all invoked function elements as children to the end of the current
  // function element. After this, clear the set of invoked functions
  // to be prepared for the next function declaration
  for (map<string, store::Item_t>::const_iterator lIter = theInvokedFunc.begin();
       lIter != theInvokedFunc.end(); ++lIter) 
  {
    store::CopyMode lCopyMode;
    (*lIter).second->copy(lFuncElem.getp(), lCopyMode);
  }
  theInvokedFunc.clear();
}

XQDOC_NO_BEGIN_TAG (FunctionCall)

void end_visit(const FunctionCall& n, void*)
{
  rchandle<QName> lFuncName = n.get_fname();

  add_invoked_function(
      lFuncName->get_localname(),
      lFuncName->get_prefix(),
      (n.get_arg_list()?n.get_arg_list()->size():0),
      n.get_location());
}

void add_invoked_function (
    const zstring& aLocalName,
    const zstring& aPrefix,
    size_t aArity,
    const QueryLoc& aLocation)
{
  store::Item_t lInvokedQName, lUriQName, lNameQName, lArityQName;
  store::Item_t lInvokedElem, lUriElem, lNameElem, lArityAttr;
  store::Item_t lUriText, lNameText, lAttrValue;

  theFactory->createQName(lInvokedQName, theXQDocNS, theXQDocPrefix, "invoked");
  theFactory->createQName(lUriQName, theXQDocNS, theXQDocPrefix, "uri");
  theFactory->createQName(lNameQName, theXQDocNS, theXQDocPrefix, "name");
  theFactory->createQName(lArityQName, "", "", "arity");

  store::Item_t lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(
      lInvokedElem, NULL, lInvokedQName, lTypeName,
      false, false, theNSBindings, theBaseURI);

  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(
      lUriElem, lInvokedElem, lUriQName, lTypeName,
      false, false, theNSBindings, theBaseURI);

  map<zstring, zstring>::iterator ite = theNamespaces.find(aPrefix);
  if (ite == theNamespaces.end()) 
  {
    ZORBA_ERROR_DESC_OSS(XQD0000_PREFIX_NOT_DECLARED,
       "Could not generate the xqDoc documentation because the namespace for prefix '"
       << aPrefix << "' is not declared when calling function '" << aLocalName
       << "' from " << aLocation << "."
    );
  }

  zstring lNS = ite->second;

  ostringstream lKey;
  lKey << lNS << aLocalName << "#" << aArity;

  theFactory->createTextNode(lUriText, lUriElem.getp(), lNS);

  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(
      lNameElem, lInvokedElem, lNameQName, lTypeName,
      false, false, theNSBindings, theBaseURI);

  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  ostringstream lAttr;
  lAttr << aArity;

  zstring lAttrString(lAttr.str().c_str());
  theFactory->createString(lAttrValue, lAttrString);

  theFactory->createAttributeNode(
      lArityQName, lInvokedElem, lArityQName, lTypeName, lAttrValue);

  zstring aLocalName2 = aLocalName;
  theFactory->createTextNode(lNameText, lNameElem.getp(), aLocalName2);

  // collect distinct invocation elements
  theInvokedFunc[lKey.str()] = lInvokedElem;
}


XQDOC_NO_BEGIN_TAG (VarDecl)

void end_visit(const VarDecl& n, void*)
{
  if (!n.is_global())
    return;

  store::Item_t lVariableQName, lUriQName;
  store::Item_t lVariableElem, lUriElem, lUriText;

  theFactory->createQName(lVariableQName, theXQDocNS, theXQDocPrefix, "variable");
  theFactory->createQName(lUriQName, theXQDocNS, theXQDocPrefix, "uri");

  store::Item_t lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(
      lVariableElem, theVariables, lVariableQName, lTypeName,
      true, false, theNSBindings, theBaseURI);

  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(
      lUriElem, lVariableElem, lUriQName, lTypeName,
      true, false, theNSBindings, theBaseURI);

  zstring lUriString(n.get_name()->get_localname());

  theFactory->createTextNode(lUriText, lUriElem, lUriString);

  print_comment(lVariableElem, n.getComment());

  // add all invoked function elements as children to the end of the current
  // function element. After this, clear the set of invoked functions
  // to be prepared for the next function declaration
  for (std::map<std::string, store::Item_t>::const_iterator lIter = theInvokedFunc.begin();
       lIter != theInvokedFunc.end(); ++lIter) 
  {
    store::CopyMode lCopyMode;
    (*lIter).second->copy(lVariableElem.getp(), lCopyMode);
  }
  theInvokedFunc.clear();
}

XQDOC_NO_BEGIN_END_TAG (VarNameAndType)

XQDOC_NO_BEGIN_TAG (ModuleImport)

void end_visit(const ModuleImport& n, void*)
{
  store::Item_t lImportQName, lUriQName, lTypeQName;
  store::Item_t lImportElem, lUriElem, lUriText, lTypeAttr;

  theFactory->createQName(lImportQName, theXQDocNS, theXQDocPrefix, "import");
  theFactory->createQName(lUriQName, theXQDocNS, theXQDocPrefix, "uri");

  store::Item_t lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(
      lImportElem, theImports, lImportQName, lTypeName,
      true, false, theNSBindings, theBaseURI);

  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(
      lUriElem, lImportElem, lUriQName, lTypeName,
      true, false, theNSBindings, theBaseURI);

  zstring lUriString(n.get_uri());

  theFactory->createTextNode(lUriText, lUriElem, lUriString);

  theFactory->createQName(lTypeQName, "", "", "type");

  store::Item_t lAttrValue;
  zstring lAttrString("library");
  theFactory->createString(lAttrValue, lAttrString);

  theFactory->createAttributeNode(
      lTypeAttr, lImportElem, lTypeQName, lTypeName, lAttrValue);

  print_comment(lImportElem, n.getComment());

  // collect prefix -> uri mappings for properly
  // reporting function invocations (see FunctionCall)
  theNamespaces[n.get_prefix()] = n.get_uri();
}

// SchemaImport can also bind prefixes which may be used
// in type constructors (i.e. function calls)
XQDOC_NO_BEGIN_TAG (SchemaImport)

void end_visit(const SchemaImport& n, void*)
{
  store::Item_t lImportQName, lUriQName, lTypeQName;
  store::Item_t lImportElem, lUriElem, lUriText, lTypeAttr;

  theFactory->createQName(lImportQName, theXQDocNS, theXQDocPrefix, "import");
  theFactory->createQName(lUriQName, theXQDocNS, theXQDocPrefix, "uri");

  store::Item_t lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(
      lImportElem, theImports, lImportQName, lTypeName,
      true, false, theNSBindings, theBaseURI);

  lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  theFactory->createElementNode(
      lUriElem, lImportElem, lUriQName, lTypeName,
      true, false, theNSBindings, theBaseURI);

  zstring lUriString = n.get_uri();
  theFactory->createTextNode(lUriText, lUriElem, lUriString);

  theFactory->createQName(lTypeQName, "", "", "type");

  store::Item_t lAttrValue;
  zstring lAttrString("schema");
  theFactory->createString(lAttrValue, lAttrString);

  theFactory->createAttributeNode(
      lTypeAttr, lImportElem, lTypeQName, lTypeName, lAttrValue);

  print_comment(lImportElem, n.getComment());

  // collect prefix -> uri mappings for properly
  // reporting function invocations (see FunctionCall)
  zstring lPrefix;
  if (!n.get_prefix()->get_default_bit()) 
  {
    lPrefix = n.get_prefix()->get_prefix();
  }
  theNamespaces[lPrefix] = n.get_uri();
}

XQDOC_NO_BEGIN_END_TAG (AdditiveExpr)
XQDOC_NO_BEGIN_END_TAG (AndExpr)
XQDOC_NO_BEGIN_END_TAG (AnnotationParsenode)
XQDOC_NO_BEGIN_END_TAG (AnnotationListParsenode)
XQDOC_NO_BEGIN_END_TAG (AnnotationLiteralListParsenode)
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
XQDOC_NO_BEGIN_END_TAG (Literal)
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
