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
#ifndef ZORBA_COMPILER_PATH_EXPR
#define ZORBA_COMPILER_PATH_EXPR


#include "compiler/expression/expr_base.h"

#include "zorbaserialization/class_serializer.h"


namespace zorba 
{

class match_expr;


/*******************************************************************************

  PathExpr ::= 	("/" RelativePathExpr?) |
                ("//" RelativePathExpr) |
                RelativePathExpr

  RelativePathExpr ::= StepExpr (("/" | "//") StepExpr)*


  Formal Semantics [http://www.w3.org/TR/xquery-semantics]:
    /    == fn:root(self::node())
    /A   == fn:root(self::node())/A
    //A  == fn:root(self::node())/descendant-or-self::node()/A
    A//B == A/descendant-or-self::node()/B
  This implies that all path expressions are relative path expressions. So a
  relative path is defined as follows:

 RelativPathExpr ::= "/" | ("/" | "//")?  StepExpr (("/" | "//") StepExpr)*

********************************************************************************/
class relpath_expr : public expr 
{
protected:
  std::vector<expr_t> theSteps;
  long                theTargetPos;

public:
  SERIALIZABLE_CLASS(relpath_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(relpath_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  relpath_expr(short sctx, const QueryLoc& loc);

  expr_kind_t get_expr_kind() const { return relpath_expr_kind; }

  bool cache_compliant() const { return true; }

	size_t size() const { return theSteps.size(); }

	void add_back(expr_t step);

  void erase(ulong i) { theSteps.erase(theSteps.begin() + i); }

  ulong numSteps() const { return theSteps.size(); }

	const expr_t& operator[](int n) const { return theSteps[n]; }

  std::vector<expr_t>::const_iterator begin() const { return theSteps.begin(); }

  std::vector<expr_t>::const_iterator end() const { return theSteps.end(); }

  void setTargetPosition(long pos) { theTargetPos = pos; }

  long getTargetPosition() const { return theTargetPos; }

  void compute_scripting_kind() const;

  xqtref_t return_type_impl(static_context*) const;

  expr_iterator_data* make_iter();

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t &) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/*******************************************************************************

  StepExpr ::= AxisStep  |  FilterExpr

********************************************************************************/


/*******************************************************************************

  AxisStep ::= Axis NodeTest Predicate*

********************************************************************************/
class axis_step_expr : public expr 
{
protected:
  axis_kind_t             theAxis;
  expr_t                  theNodeTest;

public:
  SERIALIZABLE_CLASS(axis_step_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(axis_step_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  static bool is_reverse_axis(axis_kind_t kind);

public:
  axis_step_expr(short sctx, const QueryLoc&);

  expr_kind_t get_expr_kind() const { return axis_step_expr_kind; }

  axis_kind_t getAxis() const { return theAxis; }

  void setAxis(axis_kind_t v) { theAxis = v; }

  bool is_reverse_axis() const { return is_reverse_axis(getAxis()); }

  match_expr* getTest() const 
  {
    return reinterpret_cast<match_expr*>(theNodeTest.getp());
  }

  void setTest(rchandle<match_expr> v) { theNodeTest = v.getp(); }

  void compute_scripting_kind() const;

  xqtref_t return_type_impl(static_context*) const;

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t &) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/*******************************************************************************

  [78] NodeTest ::= KindTest | NameTest

  [79] NameTest ::= QName | Wildcard
  [80] Wildcard ::= "*" | (NCName ":" "*") | ("*" ":" NCName)

  [123] KindTest ::= DocumentTest | ElementTest | AttributeTest |
                     SchemaElementTest | SchemaAttributeTest |
                     PITest | CommentTest | TextTest | AnyKindTest

  If a match_expr represents a KindTest, then theWildKind and theWildName data
  members are not used. If a match_expr represents a NameTest, then theTypeName
  and theNilledAllowed data members are not used.

********************************************************************************/
class match_expr : public expr 
{
protected:
  match_test_t  theTestKind;
  match_test_t  theDocTestKind;

  match_wild_t  theWildKind;
  xqp_string    theWildName;

  store::Item_t theQName;
  store::Item_t theTypeName;
  bool          theNilledAllowed;

public:
  SERIALIZABLE_CLASS(match_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(match_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  match_expr(short sctx, const QueryLoc&);

  expr_kind_t get_expr_kind() const { return match_expr_kind; }

  match_test_t getTestKind() const { return theTestKind; }

  void setTestKind(enum match_test_t v) { theTestKind = v; }

  match_test_t getDocTestKind() const { return theDocTestKind; }

  void setDocTestKind(enum match_test_t v) { theDocTestKind = v; }

  match_wild_t getWildKind() const { return theWildKind; }

  void setWildKind(enum match_wild_t v) { theWildKind = v; }

  const xqp_string& getWildName() const { return theWildName; }

  void setWildName(const xqp_string& v) { theWildName = v; } 

  store::Item* getQName() const { return theQName.getp(); }

  void setQName(const store::Item_t& v) { theQName = v; }

  store::Item* getTypeName() const { return theTypeName.getp(); }

  void setTypeName(const store::Item_t& v) { theTypeName = v; }

  bool getNilledAllowed() const { return theNilledAllowed; }

  void setNilledAllowed(bool v) { theNilledAllowed = v; }

  store::StoreConsts::NodeKind getNodeKind() const;

  void compute_scripting_kind() const;

  xqtref_t return_type_impl(static_context*) const;

  expr_t clone(substitution_t &) const;

  void next_iter(expr_iterator_data&);

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};



}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set ts=2 sw=2: */
