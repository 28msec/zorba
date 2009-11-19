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
#ifndef ZORBA_COMPILER_VALUE_INDEX
#define ZORBA_COMPILER_VALUE_INDEX

#include <vector>

#include "common/shared_types.h"

#include "compiler/expression/expr_utils.h"


namespace zorba 
{

class DocIndexer;
typedef rchandle<DocIndexer> DocIndexer_t;


/******************************************************************************

  An index is a map data structure whose contents are defined by a domain expr
  and a number of key exprs. Informally, the domain expr is evaluated first.
  The domain expr must return a sequence of nodes. Then, for each node D in
  the result of that expr, the key exprs are evaluated with D serving as their
  context node. Each key expr must return a single atomic value (after atomization
  is applied). Thus, for each domain node D, a tuple K of N atomic values is
  constructed, and an entry mapping K to D is inserted to the index data structure.
 
  Class ValueIndex represents an index declaration, which describes the index
  properties and the domain and key expressions and their types. An instance
  of ValueIndex is constructed by the translator for each DECLARE INDEX stmt
  that appears in an imported data module. A (index_qname --> ValueIndex obj)
  mapping is also registered in the static context during translation.

  The DECLARE INDEX syntax is the following:
  -------------------------------------------

  IndexDecl ::= "declare" "index" QName
                          "on" Expr
                          "by" "(" IndexKeyList ")"
                          IndexProperties

  IndexProperties ::= ("unique" | "non" "unique")? 
                      ("ordered" | "unordered")?
                      ("manual" | "automatic)?

  IndexKeyList ::= IndexKeySpec (COMMA IndexKeySpec)*

  IndexKeySpec ::= ExprSingle TypeDeclaration? OrderModifier

  OrderModifier ::= ("ascending" | "descending")?
                    ("empty" ("greatest" | "least"))?
                    ("collation" UriLiteral)?

  Constraints:
  ------------

  The domain expr must be deterministic and it must not reference any variables
  that are not defined inside the expr itself.

  After atomization, the ExprSingle in each IndexKeySpec must return at most one
  atomic value for each value returned by the domain expression.


  Index-related functions:
  ------------------------

    create-index(...)
    create-internal-index(...)
    drop-index(...)
    refresh-index(...)
    probe-index-point(...)
    probe-index-range(...)

  See src/functions/Index.cpp for details.
 

  Data members:
  -------------

  theSctx           : The root static context of the data module containing the
                      index declaration.

  theName           : The qname that identifies the index.

  theIsUnique       : Whether it is a unique index or not.
  theIsTemp         : Whether it is a temp index or not. A temp index is an index
                      that is created on-the-fly to optimize a query by converting
                      a nested-lopp join to a hashjoin (see index_join_rule.cpp).
                      Such an index is destroyed at the end of the query that 
                      created it.

  theMaintenanceMode: If and how to maintain the index during/after each apply-
                      updates or not.

  theContainerKind  : The kind if container used to implement the index. 
                      Currently, there are 2 kinds: a tree-based container 
                      (std::map) for ordered indexes, or hash-based container
                      for unordered indexes.

  theDomainClause   : A FOR-clause that associates the domain expr with a FOR var
                      that is referenced by the key exprs and acts as the domain
                      node for those exprs.

  theKeyExprs       :

  theOrderModifiers :

  theSourceNames    : The qnames of the collections referenced in the domain and
                      key exprs.
  theDomainSourceExprs : A vector containing pointers to the dc:collection() exprs
                         within the domain expr.    

  theBuildExpr      : The expr that computes the index entries. It is used to
                      create or rebuild the full index from scratch. The expr
                      is a flwor expr of the following form :

                      for $$dot at $$pos in domainExpr
                      return index-entry-builder($$dot, fieldExpr1, ..., fieldExprN);

  theBuildPlan      : The runtime plan corresponding to theBuildExpr. During
                      runtime (see CreateIndexIterator and RebuildIndexIterator),
                      this plan is wrapper into a PlanWrapper and then passed to
                      the store, which uses it to create or re-build the full
                      index.

  theDocIndexerExpr : This is an expr that builds the index over a single xml 
                      tree, which is provided as an external var to this expr.
                      It is basically the same as theBuildExpr except that a 
                      reference to a collection inside the domainExpr is replaced
                      with a reference to an external var that can be bound
                      dynamically to some xml tree.
                                            
  theDocIndexerVar  : The external var appearing in theDocIndexerExpr.

  theDocIndexer     : If the index domain expr is a map over a collection C,
                      then theDocIndexer obj is not NULL and it provides a
                      method that takes as input a document D in C and produces
                      all the index entries for D. theDocIndexer obj is passed
                      to the store during an apply-updates, so that the store
                      can obtain the index entries corresponding to a document
                      that is being updated within collection C, and using these
                      entries, maintain the index appropriately.
********************************************************************************/
class ValueIndex : public SimpleRCObject 
{
public:
  typedef enum 
  {
    HASH,
    TREE
  } ContainerKind;

  typedef enum
  {
    MANUAL,
    REBUILD,
    DOC_MAP
  } MaintenanceMode;


private:
  static_context                * theSctx;

  store::Item_t                   theName;

  bool                            theIsUnique;
  bool                            theIsTemp;
  MaintenanceMode                 theMaintenanceMode;
  ContainerKind                   theContainerKind;

  for_clause_t                    theDomainClause;
  std::vector<expr_t>             theKeyExprs;
  std::vector<xqtref_t>           theKeyTypes;
  std::vector<OrderModifier>      theOrderModifiers;

  std::vector<store::Item*>       theSourceNames;

  std::vector<expr*>              theDomainSourceExprs;

  expr_t                          theBuildExpr;
  PlanIter_t                      theBuildPlan;

  expr_t                          theDocIndexerExpr;
  PlanIter_t                      theDocIndexerPlan;
  DocIndexer_t                    theDocIndexer; 

public:
  SERIALIZABLE_CLASS(ValueIndex)
  ValueIndex(::zorba::serialization::Archiver& ar);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  ValueIndex(static_context* sctx, const QueryLoc& loc, const store::Item_t& name);

  ~ValueIndex();

  static_context* getSctx() const { return theSctx; }

  store::Item* getName() const;

  bool getUnique() const { return theIsUnique; }

  void setUnique(bool unique) { theIsUnique = unique; }

  bool isTemp() const { return theIsTemp; }

  void setTemp(bool tmp) { theIsTemp = tmp; }

  MaintenanceMode getMaintenanceMode() const { return theMaintenanceMode; }

  void setMaintenanceMode(MaintenanceMode v) { theMaintenanceMode = v; }
 
  bool isAutomatic() const { return theMaintenanceMode != MANUAL; }

  ContainerKind getMethod() const { return theContainerKind; }

  void setMethod(ContainerKind kind) { theContainerKind = kind; }

  expr* getDomainExpr() const;

  void setDomainExpr(expr_t domainExpr);

  var_expr* getDomainVariable() const;

  void setDomainVariable(var_expr_t domainVar);

  var_expr* getDomainPositionVariable() const;

  void setDomainPositionVariable(var_expr_t domainPosVar);

  const std::vector<expr_t>& getKeyExpressions() const;

  void setKeyExpressions(const std::vector<expr_t>& keyExprs);

  const std::vector<xqtref_t>& getKeyTypes() const;

  void setKeyTypes(const std::vector<xqtref_t>& keyTypes);

  const std::vector<OrderModifier>& getOrderModifiers() const;

  void setOrderModifiers(const std::vector<OrderModifier>& modifiers);

  ulong numSources() const { return theSourceNames.size(); }

  store::Item* getSourceName(ulong i) const { return theSourceNames[i]; }

  expr* getDomainSourceExpr(ulong i) const { return theDomainSourceExprs[i]; }

  void analyze();

  expr* getBuildExpr(CompilerCB* ccb, const QueryLoc& loc);

  PlanIterator* getBuildPlan(CompilerCB* ccb, const QueryLoc& loc);

  DocIndexer* getDocIndexer(CompilerCB* ccb, const QueryLoc& loc);

  std::string toString();

private:
  void analyzeExprInternal(
        expr* e,
        std::vector<store::Item*>& sourceNames,
        std::vector<expr*>& sourceExprs,
        std::vector<var_expr*>& varExprs);
};


typedef rchandle<ValueIndex> ValueIndex_t;


}

#endif

/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */
