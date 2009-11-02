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

#include "store/api/index.h"

namespace zorba 
{

class ValueIndexInsertSession;

typedef rchandle<ValueIndexInsertSession> ValueIndexInsertSession_t;


/******************************************************************************

  Class ValueIndex represents an index declaration, which describes the index
  properties and the domain and key expressions and their types. An instance
  of ValueIndex is constructed by the translator for each DECLARE INDEX stmt
  that appears in an imported data module. A (index_qname --> ValueIndex obj)
  mapping is also registered in the static context during translation.

  The DECLARE INDEX sysntax is the following:
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

  theSctx          : The root static context of the data module containing the
                     index declaration.
  theName          : The qname that identifies the index.
  theIsUnique      : Whether it is a unique index or not.
  theIsTemp        : Whether it is a temp index or not. A temp index is an index
                     that is created on-the-fly to optimize a query by converting
                     a nested-lopp join to a hashjoin (see index_join_rule.cpp).
                     Such an index is destroyed at the end of the query that 
                     created it.
  theMethod        : Whether this is a tree-based (ordered) or hash-based
                     (unordered) index.
  theDomainClause  : A FOR-clause that associates the domain expr with a FOR var
                     that is referenced by the key exprs and acts as the domain
                     node for those exprs.
  theKeyExprs      :
  theOrderModifiers:

  theSources       : The qnames of the collections referenced in the domain and
                     key exprs.
  theBuildExpr     :
  theBuildPlan     :
********************************************************************************/
class ValueIndex : public SimpleRCObject 
{
public:
  typedef enum 
  {
    HASH,
    BTREE
  } index_method_t;

private:
  static_context            * theSctx;

  store::Item_t               theName;
  bool                        theIsUnique;
  bool                        theIsTemp;
  index_method_t              theMethod;

  for_clause_t                theDomainClause;
  std::vector<expr_t>         theKeyExprs;
  std::vector<xqtref_t>       theKeyTypes;
  std::vector<OrderModifier>  theOrderModifiers;

  std::vector<const store::Item*> theSources;

  expr_t                          theBuildExpr;
  PlanIter_t                      theBuildPlan;

  std::vector<store::PatternIECreatorPair> m_creatorPatterns;

public:
  SERIALIZABLE_CLASS(ValueIndex)
  ValueIndex(::zorba::serialization::Archiver& ar);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  ValueIndex(CompilerCB* ccb, const QueryLoc& loc, const store::Item_t& name);

  ~ValueIndex();

  static_context* getSctx() const { return theSctx; }

  store::Item* getName() const;

  bool getUnique() const { return theIsUnique; }

  void setUnique(bool unique) { theIsUnique = unique; }

  bool isTemp() const { return theIsTemp; }

  void setTemp(bool tmp) { theIsTemp = tmp; }

  index_method_t getMethod() const { return theMethod; }

  void setMethod(index_method_t method) { theMethod = method; }

  expr_t getDomainExpr() const;

  void setDomainExpr(expr_t domainExpr);

  var_expr_t getDomainVariable() const;

  void setDomainVariable(var_expr_t domainVar);

  var_expr_t getDomainPositionVariable() const;

  void setDomainPositionVariable(var_expr_t domainPosVar);

  const std::vector<expr_t>& getKeyExpressions() const;

  void setKeyExpressions(const std::vector<expr_t>& keyExprs);

  const std::vector<xqtref_t>& getKeyTypes() const;

  void setKeyTypes(const std::vector<xqtref_t>& keyTypes);

  const std::vector<OrderModifier>& getOrderModifiers() const;

  void setOrderModifiers(const std::vector<OrderModifier>& modifiers);

  std::vector<store::PatternIECreatorPair>& getPatternCreatorPairs()
  {
    return m_creatorPatterns;
  }

  const std::vector<store::PatternIECreatorPair>& getPatternCreatorPairs() const
  {
    return m_creatorPatterns;
  }

  void analyzeExpr(const expr* e);

  expr* getBuildExpr(CompilerCB* topCCB, const QueryLoc& loc);

  PlanIterator* getBuildPlan(CompilerCB* topCCB, const QueryLoc& loc);

private:
  void analyzeExprInternal(
        const expr* e,
        std::vector<const store::Item*>& sources,
        std::vector<const var_expr*>& varExprs);
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
