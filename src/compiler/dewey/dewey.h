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
#ifndef ZORBA_DEWEY_CLASSIFICATION
#define ZORBA_DEWEY_CLASSIFICATION

#include <stack>
#include <map>
#include <list>
#include <cassert>

#include "compiler/parser/query_loc.h"
#include "compiler/parsetree/parsenodes.h"
#include "compiler/parsetree/parsenode_visitor.h"

#define DECL_CONCRETE_VISIT(node)      \
  void* begin_visit(node const &) { return no_state; } \
  void end_visit(node const&, void* visit_state){}

namespace zorba{

class DeweyClassification;

std::map<std::stack<unsigned int>, const QueryLoc> classify(parsenode& aNode);

class Node
{
  private:
    std::stack<unsigned int> theDecimal;
    const QueryLoc theLocation;
    Node* theParent;
    std::list<Node*> theChildren;

    Node* setParent(Node* aParent)
    {
      theParent = aParent;
      return this;
    }

  public:
    Node(const QueryLoc& aLocation): theLocation(aLocation), theParent(0){}
    
    Node(const QueryLoc& aLocation, std::stack<unsigned int> aDecimal)
      : theDecimal(aDecimal), theLocation(aLocation), theParent(0){}

    ~Node()
    {
      std::list<Node*>::iterator it;
      for(it=theChildren.begin(); it!=theChildren.end(); ++it)
      {
        delete *it;
      }
    }

    Node* addChild(Node* aChild)
    {
      aChild->setParent(this);
      theChildren.push_back(aChild);
      return this;
    }

    Node* getParent() const
    {
      return theParent;
    }
    
    std::list<Node*> getChildren()
    {
      return theChildren;
    }

    const QueryLoc getLocation()
    {
      return theLocation;
    }

    void setDecimal(std::stack<unsigned int> aDecimal)
    {
      theDecimal = aDecimal;
    }

    std::stack<unsigned int> getDecimal()
    {
      return theDecimal;
    }

    void accept(DeweyClassification* v);
};

class DeweyClassification: public parsenode_visitor
{
  private:
    Node* theRoot;
    Node* theParent;
    std::stack<unsigned int> theDecimal;
    std::map<uint64_t, unsigned int> theCounter;
    std::map<std::stack<unsigned int>, const QueryLoc> theClassification;

    void push(const QueryLoc& loc)
    {
      if(theRoot == 0)
      {
        Node* aNode = new Node(loc);
        theRoot = aNode;
        theParent = aNode;
      } else {
        Node* lChild = new Node(loc);
        assert(theParent != 0);
        theParent->addChild(lChild);
        theParent = lChild;
      }
    }

    void add(const QueryLoc& loc)
    {
      if(theRoot == 0)
      {
        Node* aNode = new Node(loc);
        theRoot = aNode;
        theParent = aNode;
      } else {
        Node* lChild = new Node(loc);
        assert(theParent != 0);
        theParent->addChild(lChild);
      }     
    }

    void pop()
    {
      if(theParent->getParent() != 0)
      {
        theParent = theParent->getParent();
      }
    }
  
  public:
    DeweyClassification(): theRoot(0), theParent(0){}

    ~DeweyClassification()
    {
      /*We don't have the ownership on the tree*/
    }

    Node* getRoot() const
    {
      return theRoot;
    }

    std::map<std::stack<unsigned int>, const QueryLoc> getClassification()
    {
      return theClassification;
    }

    void begin_visit(Node* aNode)
    {
      std::stack<unsigned int> lDecimal;
      Node* lParent = aNode->getParent();
      if(lParent==0)
      {
        lDecimal.push(1);
        aNode->setDecimal(lDecimal);
      } else {
        uint64_t lReference = (uint64_t)lParent;
        std::map<uint64_t, unsigned int>::iterator it;
        lDecimal = lParent->getDecimal();
        it = theCounter.find(lReference);
        if(it == theCounter.end())
        {
          theCounter.insert(std::make_pair<uint64_t, unsigned int>(lReference, 1));
          lDecimal.push(1);
        } else {
          it->second += 1;
          lDecimal.push(it->second);
        }
        aNode->setDecimal(lDecimal);
        theClassification.insert(
          std::make_pair<std::stack<unsigned int>, const QueryLoc>
          (aNode->getDecimal(), aNode->getLocation())
        );
      }
    }

    void end_visit(Node* aNode){ /* do nothing here... */ }

    void* begin_visit(const FLWORExpr& v)
    {
      const QueryLoc loc;
      push(loc);
      add(v.get_return_location());
      return no_state;
    }

    void end_visit(const FLWORExpr& v, void* /* visit state */)
    {
      pop();
    }
    
    void* begin_visit(const FunctionDecl& v)
    {
      //return false;
      return no_state;
    }

    void end_visit(const FunctionDecl& v, void* /* visit state */)
    {
      //pop();
    }

    void* begin_visit(const FunctionCall& v)
    {
      add(v.get_location());
      return no_state;
    }

    void end_visit(const FunctionCall& v, void* /* visit state */){}
    
    void* begin_visit(const VarGetsDecl& v)
    {
      add(v.get_initexpr()->get_location());
      return no_state;
    }

    void end_visit(const VarGetsDecl& v, void* /* visit state */){ /* do nothing */ }

    void* begin_visit(const Expr& v)
    {
      const QueryLoc loc;
      push(loc);
      //std::cerr << "Expr" << std::endl;
      //add(v.get_location());
      return no_state;
    }

    void end_visit(const Expr& v, void* /* visit state */)
    {
      pop();
    }

    void* begin_visit(const ForClause& v)
    {
      return no_state;
    }

    void end_visit(const ForClause& v, void* /* visit state */)
    {
    }

    void* begin_visit(const VarInDecl& v)
    {
      const QueryLoc loc;
      //push(loc);
      add(v.get_location());
      //pop();
      return no_state;
    }

    void end_visit(const VarInDecl& v, void* /* visit state */)
    {
      //pop();
    }

    void* begin_visit(const IfExpr& v)
    {
      const QueryLoc loc;
      push(loc);
      add(v.get_cond_expr()->get_location());
      add(v.get_then_expr()->get_location());
      add(v.get_else_expr()->get_location());
      return no_state;
    }

    void end_visit(const IfExpr& v, void* /* visit state */)
    {
      pop();
    }

    //DECL_CONCRETE_VISIT (VarInDecl);
    //DECL_CONCRETE_VISIT (ForClause);
    DECL_CONCRETE_VISIT (LetClause);
  	DECL_CONCRETE_VISIT (AbbrevForwardStep);
  	DECL_CONCRETE_VISIT (AnyKindTest);
  	DECL_CONCRETE_VISIT (AposAttrContentList);
  	DECL_CONCRETE_VISIT (AposAttrValueContent);
  	DECL_CONCRETE_VISIT (ArgList);
  	DECL_CONCRETE_VISIT (AtomicType);
  	DECL_CONCRETE_VISIT (AttributeTest);
  	DECL_CONCRETE_VISIT (BaseURIDecl);
  	DECL_CONCRETE_VISIT (BoundarySpaceDecl);
  	DECL_CONCRETE_VISIT (CaseClause);
  	DECL_CONCRETE_VISIT (CaseClauseList);
  	DECL_CONCRETE_VISIT (CommentTest);
  	DECL_CONCRETE_VISIT (ConstructionDecl);
  	DECL_CONCRETE_VISIT (CopyNamespacesDecl);
  	DECL_CONCRETE_VISIT (DefaultCollationDecl);
  	DECL_CONCRETE_VISIT (DefaultNamespaceDecl);
  	DECL_CONCRETE_VISIT (DirAttr);
  	DECL_CONCRETE_VISIT (DirAttributeList);
  	DECL_CONCRETE_VISIT (DirAttributeValue);
  	DECL_CONCRETE_VISIT (DirElemContentList);
  	DECL_CONCRETE_VISIT (DocumentTest);
  	DECL_CONCRETE_VISIT (ElementTest);
  	DECL_CONCRETE_VISIT (EmptyOrderDecl);
  	DECL_CONCRETE_VISIT (FLWORClauseList);
  	DECL_CONCRETE_VISIT (ForwardAxis);
  	DECL_CONCRETE_VISIT (ForwardStep);
  	//DECL_CONCRETE_VISIT (FunctionDecl);
  	DECL_CONCRETE_VISIT (GeneralComp);
  	DECL_CONCRETE_VISIT (ItemType);
  	DECL_CONCRETE_VISIT (LibraryModule);
  	DECL_CONCRETE_VISIT (MainModule );
  	DECL_CONCRETE_VISIT (Module);
  	DECL_CONCRETE_VISIT (ModuleDecl);
  	DECL_CONCRETE_VISIT (ModuleImport);
  	DECL_CONCRETE_VISIT (NameTest);
  	DECL_CONCRETE_VISIT (NamespaceDecl);
  	DECL_CONCRETE_VISIT (NodeComp);
  	DECL_CONCRETE_VISIT (OccurrenceIndicator);
  	DECL_CONCRETE_VISIT (OptionDecl);
    DECL_CONCRETE_VISIT (GroupByClause);
    DECL_CONCRETE_VISIT (GroupSpecList);
    DECL_CONCRETE_VISIT (GroupSpec);
    DECL_CONCRETE_VISIT (GroupCollationSpec);
    DECL_CONCRETE_VISIT (LetClauseList);
  	DECL_CONCRETE_VISIT (OrderByClause);
  	DECL_CONCRETE_VISIT (OrderCollationSpec);
  	DECL_CONCRETE_VISIT (OrderDirSpec);
  	DECL_CONCRETE_VISIT (OrderEmptySpec);
  	DECL_CONCRETE_VISIT (OrderModifier);
  	DECL_CONCRETE_VISIT (OrderSpec);
  	DECL_CONCRETE_VISIT (OrderSpecList);
  	DECL_CONCRETE_VISIT (OrderingModeDecl);
  	DECL_CONCRETE_VISIT (PITest);
  	DECL_CONCRETE_VISIT (Param);
  	DECL_CONCRETE_VISIT (ParamList);
  	DECL_CONCRETE_VISIT (PositionalVar);
  	DECL_CONCRETE_VISIT (Pragma);
  	DECL_CONCRETE_VISIT (PragmaList);
  	DECL_CONCRETE_VISIT (PredicateList);
  	DECL_CONCRETE_VISIT (Prolog);
  	DECL_CONCRETE_VISIT (QVarInDecl);
  	DECL_CONCRETE_VISIT (QVarInDeclList);
  	DECL_CONCRETE_VISIT (QuoteAttrValueContent);
  	DECL_CONCRETE_VISIT (QuoteAttrContentList);
  	DECL_CONCRETE_VISIT (ReverseAxis);
  	DECL_CONCRETE_VISIT (ReverseStep);
  	DECL_CONCRETE_VISIT (SIND_DeclList);
  	DECL_CONCRETE_VISIT (SchemaAttributeTest);
  	DECL_CONCRETE_VISIT (SchemaElementTest);
  	DECL_CONCRETE_VISIT (SchemaImport);
  	DECL_CONCRETE_VISIT (SchemaPrefix);
  	DECL_CONCRETE_VISIT (SequenceType);
  	DECL_CONCRETE_VISIT (SignList);
  	DECL_CONCRETE_VISIT (SingleType);
  	DECL_CONCRETE_VISIT (TextTest);
  	DECL_CONCRETE_VISIT (TypeDeclaration);
  	DECL_CONCRETE_VISIT (TypeName);
  	DECL_CONCRETE_VISIT (URILiteralList);
  	DECL_CONCRETE_VISIT (ValueComp);
  	DECL_CONCRETE_VISIT (VarDecl);
  	DECL_CONCRETE_VISIT (VarGetsDeclList);
  	//DECL_CONCRETE_VISIT (VarInDecl);
  	DECL_CONCRETE_VISIT (VarInDeclList);
  	DECL_CONCRETE_VISIT (VersionDecl);
  	DECL_CONCRETE_VISIT (VFO_DeclList);
  	DECL_CONCRETE_VISIT (WhereClause);
  	DECL_CONCRETE_VISIT (CountClause);
  	DECL_CONCRETE_VISIT (Wildcard);
    DECL_CONCRETE_VISIT (QName);
  
  /* expressions */
  	DECL_CONCRETE_VISIT (AdditiveExpr);
  	DECL_CONCRETE_VISIT (AndExpr);
  	DECL_CONCRETE_VISIT (AxisStep);
  	DECL_CONCRETE_VISIT (CDataSection);
  	DECL_CONCRETE_VISIT (CastExpr);
  	DECL_CONCRETE_VISIT (CastableExpr);
  	DECL_CONCRETE_VISIT (CommonContent);
  	DECL_CONCRETE_VISIT (ComparisonExpr);
  	DECL_CONCRETE_VISIT (CompAttrConstructor);
  	DECL_CONCRETE_VISIT (CompCommentConstructor);
  	DECL_CONCRETE_VISIT (CompDocConstructor);
  	DECL_CONCRETE_VISIT (CompElemConstructor);
  	DECL_CONCRETE_VISIT (CompPIConstructor);
  	DECL_CONCRETE_VISIT (CompTextConstructor);
  	DECL_CONCRETE_VISIT (ContextItemExpr);
  	DECL_CONCRETE_VISIT (DirCommentConstructor);
  	DECL_CONCRETE_VISIT (DirElemConstructor);
  	DECL_CONCRETE_VISIT (DirElemContent);
  	DECL_CONCRETE_VISIT (DirPIConstructor);
  	DECL_CONCRETE_VISIT (EnclosedExpr);
  	DECL_CONCRETE_VISIT (BlockBody);
  	//DECL_CONCRETE_VISIT (Expr);
  	DECL_CONCRETE_VISIT (ExtensionExpr);
  	//DECL_CONCRETE_VISIT (FLWORExpr);
  	DECL_CONCRETE_VISIT (WindowClause);
  	DECL_CONCRETE_VISIT (WindowVarDecl);
  	DECL_CONCRETE_VISIT (FLWORWinCond);
  	DECL_CONCRETE_VISIT (WindowVars);
  	DECL_CONCRETE_VISIT (FilterExpr);
  	//DECL_CONCRETE_VISIT (FunctionCall);
  	//DECL_CONCRETE_VISIT (IfExpr);
  	DECL_CONCRETE_VISIT (InstanceofExpr);
  	DECL_CONCRETE_VISIT (IntersectExceptExpr);
  	DECL_CONCRETE_VISIT (MultiplicativeExpr);
  	DECL_CONCRETE_VISIT (NumericLiteral);
  	DECL_CONCRETE_VISIT (OrExpr);
  	DECL_CONCRETE_VISIT (OrderedExpr);
  	DECL_CONCRETE_VISIT (ParenthesizedExpr);
  	DECL_CONCRETE_VISIT (PathExpr);
  	DECL_CONCRETE_VISIT (QuantifiedExpr);
  	DECL_CONCRETE_VISIT (QueryBody);
  	DECL_CONCRETE_VISIT (RangeExpr);
  	DECL_CONCRETE_VISIT (RelativePathExpr);
  	DECL_CONCRETE_VISIT (StringLiteral);
  	DECL_CONCRETE_VISIT (TreatExpr);
  	DECL_CONCRETE_VISIT (TypeswitchExpr);
  	DECL_CONCRETE_VISIT (UnaryExpr);
  	DECL_CONCRETE_VISIT (UnionExpr);
  	DECL_CONCRETE_VISIT (UnorderedExpr);
  	DECL_CONCRETE_VISIT (ValidateExpr);
  	DECL_CONCRETE_VISIT (VarRef);
  
  /* update-related */
  	DECL_CONCRETE_VISIT (DeleteExpr);
  	DECL_CONCRETE_VISIT (InsertExpr);
  	DECL_CONCRETE_VISIT (RenameExpr);
  	DECL_CONCRETE_VISIT (ReplaceExpr);
  	DECL_CONCRETE_VISIT (RevalidationDecl);
  	DECL_CONCRETE_VISIT (TransformExpr);
  	DECL_CONCRETE_VISIT (VarNameList);
    DECL_CONCRETE_VISIT (VarBinding);
  
  /* try-catch-related */
    DECL_CONCRETE_VISIT (TryExpr);
    DECL_CONCRETE_VISIT (CatchListExpr);
    DECL_CONCRETE_VISIT (CatchExpr);
  
    // eval
    DECL_CONCRETE_VISIT (EvalExpr);
  
  /* full-text-related */
  	DECL_CONCRETE_VISIT (FTAnd);
  	DECL_CONCRETE_VISIT (FTAnyallOption);
  	DECL_CONCRETE_VISIT (FTBigUnit);
  	DECL_CONCRETE_VISIT (FTCaseOption);
  	DECL_CONCRETE_VISIT (FTContainsExpr);
  	DECL_CONCRETE_VISIT (FTContent);
  	DECL_CONCRETE_VISIT (FTDiacriticsOption);
  	DECL_CONCRETE_VISIT (FTDistance);
  	DECL_CONCRETE_VISIT (FTIgnoreOption);
  	DECL_CONCRETE_VISIT (FTInclExclStringLiteral);
  	DECL_CONCRETE_VISIT (FTInclExclStringLiteralList);
  	DECL_CONCRETE_VISIT (FTLanguageOption);
  	DECL_CONCRETE_VISIT (FTMatchOption);
  	DECL_CONCRETE_VISIT (FTMatchOptionProximityList);
  	DECL_CONCRETE_VISIT (FTMildnot);
  	DECL_CONCRETE_VISIT (FTOptionDecl);
  	DECL_CONCRETE_VISIT (FTOr);
  	DECL_CONCRETE_VISIT (FTOrderedIndicator);
  	DECL_CONCRETE_VISIT (FTProximity);
  	DECL_CONCRETE_VISIT (FTRange);
  	DECL_CONCRETE_VISIT (FTRefOrList);
  	DECL_CONCRETE_VISIT (FTScope);
  	DECL_CONCRETE_VISIT (FTScoreVar);
  	DECL_CONCRETE_VISIT (FTSelection);
  	DECL_CONCRETE_VISIT (FTStemOption);
  	DECL_CONCRETE_VISIT (FTStopwordOption);
  	DECL_CONCRETE_VISIT (FTStringLiteralList);
  	DECL_CONCRETE_VISIT (FTThesaurusID);
  	DECL_CONCRETE_VISIT (FTThesaurusList);
  	DECL_CONCRETE_VISIT (FTThesaurusOption);
  	DECL_CONCRETE_VISIT (FTTimes);
  	DECL_CONCRETE_VISIT (FTUnaryNot);
  	DECL_CONCRETE_VISIT (FTUnit);
  	DECL_CONCRETE_VISIT (FTWildcardOption);
  	DECL_CONCRETE_VISIT (FTWindow);
  	DECL_CONCRETE_VISIT (FTWords);
  	DECL_CONCRETE_VISIT (FTWordsSelection);
  	DECL_CONCRETE_VISIT (FTWordsValue);
  	DECL_CONCRETE_VISIT (FTMatchOptionProximity);
  
    DECL_CONCRETE_VISIT (ExitExpr);
    DECL_CONCRETE_VISIT (WhileExpr);
    DECL_CONCRETE_VISIT (FlowCtlStatement);
  
    DECL_CONCRETE_VISIT (ParseErrorNode);
};
}//end of namespace
#endif
