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
  of ValueIndex is constructed by the translator for each DECLARE INDEX statement
  that appears in a query. A (index_uri --> ValueIndex obj) mapping is also
  registered in the static context during translation.

  The DECLARE INDEX sysntax is the following:
  -------------------------------------------

  IndexDecl ::= "DECLARE" ["UNIQUE"] ["HASH" | "BTREE"] "INDEX" UriLiteral
                "ON" ExprSingle "BY" "(" IndexField+ ")"

  IndexField ::= ExprSingle [TypeDeclaration] ["COLLATION" UriLiteral]


  Constraints:
  ------------

  The expressions defining the index fields must return a single atomic value
  for each value returned by the domain expression.


  - Index-related functions (see src/functions/Index.h):

  create-index($indexUri as anyURI) as ()

  drop-index($indexUri as anyURI) as ()

  build-index($indexUri as anyURI) as ()

  probe-index-point($indexUri as anyURI,
                    $key1     as anyAtomic?,
                    ...,
                    $keyN     as anyAtomic?) as item()*

  probe-index-range(uriExpr                  as xs:uri,
                    range1LowerBound         as anyAtomic?,
                    range1UpperBound         as anyAtomic?,
                    range1HaveLowerBound     as boolean?,
                    range1HaveupperBound     as boolean?,
                    range1LowerBoundIncluded as boolean?,
                    range1upperBoundIncluded as boolean?,
                    ....,
                    rangeNLowerBound         as anyAtomic?,
                    rangeNUpperBound         as anyAtomic?,
                    rangeNHaveLowerBound     as boolean?,
                    rangeNHaveupperBound     as boolean?,
                    rangeNLowerBoundIncluded as boolean?,
                    rangeNupperBoundIncluded as boolean?) as item()*

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
  store::Item_t            theName;
  bool                     theIsUnique;
  bool                     theIsTemp;
  index_method_t           theMethod;

  for_clause_t             theDomainClause;
  std::vector<expr_t>      theKeyExprs;
  std::vector<xqtref_t>    theKeyTypes;
  std::vector<std::string> theKeyCollations;

  std::vector<store::PatternIECreatorPair> m_creatorPatterns;

public:
  SERIALIZABLE_CLASS(ValueIndex)
  ValueIndex(::zorba::serialization::Archiver& ar);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  ValueIndex(short sctx, const QueryLoc& loc, const store::Item_t& name);

  ~ValueIndex();

  const store::Item* getName() const;

  bool getUnique() const { return theIsUnique; }

  void setUnique(bool unique) { theIsUnique = unique; }

  bool getTemp() const { return theIsTemp; }

  void setTemp(bool tmp) { theIsTemp = tmp; }

  index_method_t getMethod() const { return theMethod; }

  void setMethod(index_method_t method) { theMethod = method; }

  expr_t getDomainExpression() const;

  void setDomainExpression(expr_t domainExpr);

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
};

typedef rchandle<ValueIndex> ValueIndex_t;


/***************************************************************************//**

********************************************************************************/
class ValueIndexInsertSession : public SimpleRCObject 
{
private:
  store::IndexEntryReceiver_t m_bulkInsertSession;

public:
  ValueIndexInsertSession(store::IndexEntryReceiver_t receiver)
    :
    m_bulkInsertSession(receiver) { }

  void commitBulkInsertSession();

  void abortBulkInsertSession();

  store::IndexEntryReceiver_t& getBulkInsertSession() { return m_bulkInsertSession; }
};

}

#endif /* ZORBA_VALUE_INDEX_H */
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */
