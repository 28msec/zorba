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
#ifndef ZORBA_VALUE_INDEX_H
#define ZORBA_VALUE_INDEX_H

#include <vector>

#include "common/shared_types.h"

//#include "compiler/expression/expr.h"
#include "store/api/index.h"

namespace zorba 
{

class ValueIndexInsertSession;

typedef rchandle<ValueIndexInsertSession> ValueIndexInsertSession_t;


/******************************************************************************

  Class ValueIndex represents an index declaration, which describes the index
  properties and the domain and field expressions and their types. An instance
  of ValueIndex is constructed by the translator for each DECLARE INDEX stmt
  that appears in an imported data module. A (index_qname --> ValueIndex obj)
  mapping is also registered in the static context during translation.

  The DECLARE INDEX sysntax is the following:
  -------------------------------------------

  IndexDecl ::= "declare" ("unique" | "non" "unique")? 
                          ("ordered" | "unordered")?
                          ("manual" | "automatic)?
                          "index" QName
                          "on" Expr
                          "by" "(" IndexKeyList ")"

  IndexKeyList ::= IndexKeySpec (COMMA IndexKeySpec)*

  IndexKeySpec ::= ExprSingle TypeDeclaration? 
                              ("empty" ("greatest" | "least"))?
                              ("collation" UriLiteral)?

  Constraints:
  ------------

  The domain expr must be deterministic and it must not reference any variables
  that are not defined inside the expr itself.

  After atomization, the ExprSingle in each IndexKeySpec must return a single
  atomic value for each value returned by the domain expression.


  Index-related functions:
  ------------------------

    create-index(...)
    create-internal-index(...)
    drop-index(...)
    probe-index-point(...)
    probe-index-range(...)

  See src/functions/Index.cpp for details.
 
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
  static_context         * theSctx;

  store::Item_t            theName;
  bool                     theIsUnique;
  bool                     theIsTemp;
  index_method_t           theMethod;

  for_clause_t             theDomainClause;
  std::vector<expr_t>      theKeyExprs;
  std::vector<xqtref_t>    theKeyTypes;
  std::vector<std::string> theKeyCollations;

  expr_t                   theBuildExpr;
  PlanIter_t               theBuildPlan;

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

  bool getTemp() const { return theIsTemp; }

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

  const std::vector<std::string>& getKeyCollations() const 
  {
    return theKeyCollations; 
  }

  void setKeyCollations(const std::vector<std::string>& keyCollations) 
  {
    theKeyCollations = keyCollations;
  }

  std::vector<store::PatternIECreatorPair>& getPatternCreatorPairs()
  {
    return m_creatorPatterns;
  }

  const std::vector<store::PatternIECreatorPair>& getPatternCreatorPairs() const
  {
    return m_creatorPatterns;
  }

  expr* getBuildExpr(CompilerCB* topCCB, const QueryLoc& loc);

  PlanIterator* getBuildPlan(CompilerCB* topCCB, const QueryLoc& loc);
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
