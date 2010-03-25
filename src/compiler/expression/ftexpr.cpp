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

#include "compiler/expression/expr_visitor.h"
#include "compiler/expression/ftexpr.h"
#include "compiler/expression/ftexpr_visitor.h"
#include "zorbautils/container_util.h"

using namespace std;

namespace zorba {
  
SERIALIZABLE_CLASS_VERSIONS(ft_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ft_expr)

SERIALIZABLE_CLASS_VERSIONS(ftcontains_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftcontains_expr)

SERIALIZABLE_CLASS_VERSIONS(ftand_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftand_expr)

SERIALIZABLE_CLASS_VERSIONS(ftexpr)
END_SERIALIZABLE_CLASS_VERSIONS(ftexpr)

SERIALIZABLE_CLASS_VERSIONS(ftcontent_filter)
END_SERIALIZABLE_CLASS_VERSIONS(ftcontent_filter)

SERIALIZABLE_CLASS_VERSIONS(ftcase_option)
END_SERIALIZABLE_CLASS_VERSIONS(ftcase_option)

SERIALIZABLE_CLASS_VERSIONS(ftdiacritics_option)
END_SERIALIZABLE_CLASS_VERSIONS(ftdiacritics_option)

SERIALIZABLE_CLASS_VERSIONS(ftdistance_filter)
END_SERIALIZABLE_CLASS_VERSIONS(ftdistance_filter)

SERIALIZABLE_CLASS_VERSIONS(ftextension_option)
END_SERIALIZABLE_CLASS_VERSIONS(ftextension_option)

SERIALIZABLE_CLASS_VERSIONS(ftextension_selection_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftextension_selection_expr)

SERIALIZABLE_CLASS_VERSIONS(ftlanguage_option)
END_SERIALIZABLE_CLASS_VERSIONS(ftlanguage_option)

SERIALIZABLE_CLASS_VERSIONS(ftmatch_option)
END_SERIALIZABLE_CLASS_VERSIONS(ftmatch_option)

SERIALIZABLE_CLASS_VERSIONS(ftmatch_options)
END_SERIALIZABLE_CLASS_VERSIONS(ftmatch_options)

SERIALIZABLE_CLASS_VERSIONS(ftmild_not_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftmild_not_expr)

SERIALIZABLE_CLASS_VERSIONS(ftor_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftor_expr)

SERIALIZABLE_CLASS_VERSIONS(ftorder_filter)
END_SERIALIZABLE_CLASS_VERSIONS(ftorder_filter)

SERIALIZABLE_CLASS_VERSIONS(ftpos_filter)
END_SERIALIZABLE_CLASS_VERSIONS(ftpos_filter)

SERIALIZABLE_CLASS_VERSIONS(ftprimary_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftprimary_expr)

SERIALIZABLE_CLASS_VERSIONS(ftprimary_with_options_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftprimary_with_options_expr)

SERIALIZABLE_CLASS_VERSIONS(ftrange_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftrange_expr)

SERIALIZABLE_CLASS_VERSIONS(ftscope_filter)
END_SERIALIZABLE_CLASS_VERSIONS(ftscope_filter)

SERIALIZABLE_CLASS_VERSIONS(ftselection_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftselection_expr)

SERIALIZABLE_CLASS_VERSIONS(ftstem_option)
END_SERIALIZABLE_CLASS_VERSIONS(ftstem_option)

SERIALIZABLE_CLASS_VERSIONS(ftstop_words)
END_SERIALIZABLE_CLASS_VERSIONS(ftstop_words)

SERIALIZABLE_CLASS_VERSIONS(ftstop_word_option)
END_SERIALIZABLE_CLASS_VERSIONS(ftstop_word_option)

SERIALIZABLE_CLASS_VERSIONS(ftthesaurus_id)
END_SERIALIZABLE_CLASS_VERSIONS(ftthesaurus_id)

SERIALIZABLE_CLASS_VERSIONS(ftthesaurus_option)
END_SERIALIZABLE_CLASS_VERSIONS(ftthesaurus_option)

SERIALIZABLE_CLASS_VERSIONS(ftunary_not_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftunary_not_expr)

SERIALIZABLE_CLASS_VERSIONS(ftwild_card_option)
END_SERIALIZABLE_CLASS_VERSIONS(ftwild_card_option)

SERIALIZABLE_CLASS_VERSIONS(ftwindow_filter)
END_SERIALIZABLE_CLASS_VERSIONS(ftwindow_filter)

SERIALIZABLE_CLASS_VERSIONS(ftwords_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftwords_expr)

SERIALIZABLE_CLASS_VERSIONS(ftwords_times_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftwords_times_expr)

#define BEGIN_VISIT( V )                                                \
  { /* begin scope */                                                   \
    ftexpr_visitor::begin_result const br0 = (V).begin_visit( *this );  \
    if ( !(br0 & ftexpr_visitor::br_no_children) ) {

#define END_VISIT( V )                        \
    }                                         \
    if ( !(br0 & ftexpr_visitor::br_no_end) ) \
        (V).end_visit( *this );               \
  } /* end scope */

#define ACCEPT( FTEXPR, V )                 \
  if ( !(FTEXPR) ) ; else (FTEXPR)->accept( V )

#define ACCEPT_SEQ( T, S, V )                                     \
  for ( T::const_iterator i = (S).begin(); i != (S).end(); ++i )  \
    ACCEPT( *i, V );

///////////////////////////////////////////////////////////////////////////////

ft_expr::ft_expr( short sctx, QueryLoc const &loc ) :
  expr( sctx, loc )
{
}

ft_expr::~ft_expr() {
}

ostream& ft_expr::put( ostream &os ) const {
  return os << "ft_expr\n";
}

void ft_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (expr*)this );
}

///////////////////////////////////////////////////////////////////////////////

class pass_thru_expr_visitor : public expr_visitor {
public:
  pass_thru_expr_visitor( ftexpr_visitor &v ) : ftexpr_visitor_( v ) { }

  ftexpr_visitor& get_ftexpr_visitor();

  DECL_EXPR_VISITOR_VISIT_MEM_FNS( attr_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( axis_step_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( castable_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( cast_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( const_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( debugger_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( delete_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( doc_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( dynamic_function_invocation_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( elem_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( eval_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( exit_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( extension_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( flowctl_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( flwor_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( fo_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( ftcontains_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( function_item_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( if_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( insert_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( instanceof_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( match_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( name_cast_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( order_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( pi_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( promote_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( relpath_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( rename_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( replace_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( sequential_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( text_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( transform_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( treat_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( trycatch_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( validate_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( var_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( while_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( wrapper_expr );

private:
  ftexpr_visitor &ftexpr_visitor_;
};

ftexpr_visitor& pass_thru_expr_visitor::get_ftexpr_visitor() {
  return ftexpr_visitor_;
}

#define V pass_thru_expr_visitor

DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, attr_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, axis_step_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, castable_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, cast_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, const_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, debugger_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, delete_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, doc_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, dynamic_function_invocation_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, elem_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, eval_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, exit_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, extension_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, flowctl_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, flwor_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, fo_expr )

bool V::begin_visit( ftcontains_expr &e ) {
  //e.get_ftselection()
  return true;
}

DEF_EXPR_VISITOR_END_VISIT( V, ftcontains_expr )

DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, function_item_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, if_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, insert_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, instanceof_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, match_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, name_cast_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, order_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, pi_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, promote_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, relpath_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, rename_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, replace_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, sequential_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, text_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, transform_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, treat_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, trycatch_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, validate_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, var_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, while_expr )
DEF_EXPR_VISITOR_VISIT_MEM_FNS( V, wrapper_expr )

#undef V

///////////////////////////////////////////////////////////////////////////////

/**
 * An next_iter_ftexpr_visitor is-an ftexpr_visitor that is used only by
 * ftcontains_expr::next_iter().
 */
class next_iter_ftexpr_visitor : public ftexpr_visitor {
public:
  typedef list<expr_t> expr_list_t;

  next_iter_ftexpr_visitor() : expr_visitor_( *this ) { }

  void push_back( expr_t e ) {
    sub_expr_list_.push_back( e );
  }

  expr_list_t& get_sub_expr_list() {
    return sub_expr_list_;
  }

  expr_visitor& get_expr_visitor();

protected:
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftand_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftextension_selection_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftmild_not_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftor_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftprimary_with_options_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftrange_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftselection_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftunary_not_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftwords_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftwords_times_expr );

  // FTPosFilters
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftcontent_filter );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftdistance_filter );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftorder_filter );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftscope_filter );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftwindow_filter );

  // FTMatchOptions
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftcase_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftdiacritics_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftextension_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftlanguage_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftmatch_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftstem_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftstop_word_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftstop_words );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftthesaurus_id );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftthesaurus_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftwild_card_option );

private:
  expr_list_t sub_expr_list_;
  pass_thru_expr_visitor expr_visitor_;
};

expr_visitor& next_iter_ftexpr_visitor::get_expr_visitor() {
  return expr_visitor_;
}

#define V next_iter_ftexpr_visitor

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftand_expr );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftextension_selection_expr );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftmild_not_expr );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftor_expr );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftprimary_with_options_expr );

ftexpr_visitor::begin_result V::begin_visit( ftrange_expr &c ) {
  push_back( c.get_expr1().getp() );
  if ( c.get_expr2() )
    push_back( c.get_expr2().getp() );
  return br_no_end;
}
DEF_FTEXPR_VISITOR_END_VISIT( V, ftrange_expr );

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftselection_expr );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftunary_not_expr );

ftexpr_visitor::begin_result V::begin_visit( ftwords_expr &c ) {
  push_back( c.get_expr() );
  return br_no_end;
}
DEF_FTEXPR_VISITOR_END_VISIT( V, ftwords_expr );

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftwords_times_expr );

// FTPosFilters
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftcontent_filter );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftdistance_filter );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftorder_filter );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftscope_filter );

ftexpr_visitor::begin_result V::begin_visit( ftwindow_filter &c ) {
  push_back( c.get_window().getp() );
  return br_no_end;
}
DEF_FTEXPR_VISITOR_END_VISIT( V, ftwindow_filter )

// FTMatchOptions
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftcase_option );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftdiacritics_option );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftextension_option );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftlanguage_option );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftmatch_option );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftstem_option );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftstop_word_option );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftstop_words );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftthesaurus_id );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftthesaurus_option );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftwild_card_option );

#undef V

///////////////////////////////////////////////////////////////////////////////

class ftcontains_expr_iterator_data : public expr_iterator_data {
public:
  list<expr_t> expr_list_;
  list<expr_t>::iterator iter_;

  ftcontains_expr_iterator_data( expr *e, list<expr_t> expr_list ) :
    expr_iterator_data( e )
  {
    expr_list_.swap( expr_list );
  }
};

///////////////////////////////////////////////////////////////////////////////

ftcontains_expr::ftcontains_expr(
  short sctx,
  QueryLoc const &loc,
  range_expr_t range,
  ftexpr *ftselection,
  union_expr_t ftignore
) :
  ft_expr( sctx, loc ),
  range_( range ),
  ftselection_( ftselection ),
  ftignore_( ftignore )
{
}

/* DEF_EXPR_ACCEPT( ftcontains_expr ) */

void ftcontains_expr::accept( expr_visitor &v ) {
  if ( v.begin_visit( *this ) ) {
    ACCEPT( range_, v );
    ftexpr_visitor &v2 = v.get_ftexpr_visitor();
    ACCEPT( ftselection_, v2 );
    ACCEPT( ftignore_, v );
  }
  v.end_visit( *this );
}

void ftcontains_expr::compute_scripting_kind() const {
  theCache.scripting_kind.kind = SIMPLE_EXPR;
  theCache.scripting_kind.valid = true;
  // TODO: checkIsSimple for all sub-expr
}

void ftcontains_expr::serialize( serialization::Archiver &ar )
{
  serialize_baseclass( ar, (expr*)this );
  ar & range_;
  ar & ftselection_;
  ar & ftignore_;
}

expr_iterator_data* ftcontains_expr::make_iter() {
  next_iter_ftexpr_visitor v;
  v.push_back( range_.getp() );
  ftselection_->accept( v );
  v.push_back( ftignore_.getp() );
  return new ftcontains_expr_iterator_data( this, v.get_sub_expr_list() );
}

void ftcontains_expr::next_iter( expr_iterator_data &v ) {
  BEGIN_EXPR_ITER2(ftcontains_expr);
  ITER_FOR_EACH( iter_, vv.expr_list_.begin(), vv.expr_list_.end(), *vv.iter_ );
  END_EXPR_ITER();
}

ostream& ftcontains_expr::put( ostream& o ) const
{
  //BEGIN_EXPR (ftcontains_expr);
  range_->put( o ) << endl;
  o << "ftcontains\n";
  //ftselection_->put( o ) << endl;
  if ( ftignore_ )
    ftignore_->put( o );
  //CLOSE_EXPR;
  return o;
}

///////////////////////////////////////////////////////////////////////////////

ftexpr_visitor::~ftexpr_visitor() {
  // do nothing
}

///////////////////////////////////////////////////////////////////////////////

ftexpr::~ftexpr() {
}

void ftexpr::serialize( serialization::Archiver &ar ) {
  ar & loc_;
}

ftand_expr::ftand_expr(
  QueryLoc const &loc,
  ftexpr_list_t &list
) :
  ftexpr( loc )
{
  list_.swap( list );
}

ftand_expr::~ftand_expr() {
  delete_ptr_container( list_ );
}

void ftand_expr::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT_SEQ( ftexpr_list_t, list_, v );
  END_VISIT( v );
}

void ftand_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & list_;
}

ftcase_option::ftcase_option(
  QueryLoc const &loc,
  ft_case_mode::type mode
) :
  ftmatch_option( loc ),
  mode_( mode )
{
}

void ftcase_option::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  END_VISIT( v );
}

void ftcase_option::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option*)this );
  SERIALIZE_ENUM(ft_case_mode::type,mode_);
}

ftcontent_filter::ftcontent_filter(
  QueryLoc const &loc, ft_content_mode::type mode
) :
  ftpos_filter( loc ),
  mode_( mode_ )
{
}

void ftcontent_filter::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  END_VISIT( v );
}

ftdiacritics_option::ftdiacritics_option(
  QueryLoc const &loc,
  ft_diacritics_mode::type mode
) :
  ftmatch_option( loc ),
  mode_( mode )
{
}

void ftdiacritics_option::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  END_VISIT( v );
}

void ftdiacritics_option::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option*)this );
  SERIALIZE_ENUM(ft_diacritics_mode::type,mode_);
}

ftdistance_filter::ftdistance_filter(
  QueryLoc const &loc,
  ftrange_expr *range,
  ft_unit::type unit
) :
  ftpos_filter( loc ),
  range_( range ),
  unit_( unit )
{
}

void ftdistance_filter::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT( range_, v );
  END_VISIT( v );
}

void ftdistance_filter::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftpos_filter*)this );
  ar & range_;
  SERIALIZE_ENUM(ft_unit::type,unit_);
}

ftextension_selection_expr::ftextension_selection_expr(
  QueryLoc const &loc,
  /* TODO: pragma_list, */
  ftselection_expr *ftselection
) :
  ftprimary_expr( loc ),
  /* TODO: pragma_list_( pragma_list ), */
  ftselection_( ftselection )
{
}

void ftextension_selection_expr::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT( ftselection_, v );
  END_VISIT( v );
}

void ftextension_selection_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
}

ftextension_option::ftextension_option(
  QueryLoc const &loc,
  rchandle<QName> qname,
  string const &val
) :
  ftmatch_option( loc ),
  qname_( qname ),
  val_( val )
{
}

void ftextension_option::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  END_VISIT( v );
}

void ftextension_option::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option*)this );
  ar & qname_;
  ar & val_;
}

ftlanguage_option::ftlanguage_option(
  QueryLoc const &loc,
  string const &lang
) :
  ftmatch_option( loc ),
  language_( lang )
{
}

void ftlanguage_option::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  END_VISIT( v );
}

void ftlanguage_option::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option*)this );
  ar & language_;
}

void ftmatch_option::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
}

ftmatch_options::ftmatch_options(
  QueryLoc const &loc
) :
  ftexpr( loc ),
  case_option_( new ftcase_option( loc ) ),
  diacritics_option_( new ftdiacritics_option( loc ) ),
  extension_option_( NULL ),
  language_option_( new ftlanguage_option( loc, "" ) ),
  stem_option_( new ftstem_option( loc ) ),
  thesaurus_option_( NULL ),
  wild_card_option_( new ftwild_card_option( loc ) )
{
}

ftmatch_options::~ftmatch_options() {
  delete case_option_;
  delete extension_option_;
  delete language_option_;
  delete stem_option_;
  delete stop_word_option_;
  delete thesaurus_option_;
  delete wild_card_option_;
}

void ftmatch_options::accept( ftexpr_visitor &v ) {
  ACCEPT( case_option_, v );
  ACCEPT( diacritics_option_, v );
  ACCEPT( extension_option_, v );
  ACCEPT( language_option_, v );
  ACCEPT( stem_option_, v );
  ACCEPT( stop_word_option_, v );
  ACCEPT( thesaurus_option_, v );
  ACCEPT( wild_card_option_, v );
}

void ftmatch_options::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & case_option_;
  ar & extension_option_;
  ar & language_option_;
  ar & stem_option_;
  ar & stop_word_option_;
  ar & thesaurus_option_;
  ar & wild_card_option_;
}

ftmild_not_expr::ftmild_not_expr( QueryLoc const &loc, ftexpr_list_t &r ) :
  ftexpr( loc )
{
  list_.swap( r );
}

ftmild_not_expr::~ftmild_not_expr() {
  delete_ptr_container( list_ );
}

void ftmild_not_expr::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT_SEQ( ftexpr_list_t, list_, v );
  END_VISIT( v );
}

void ftmild_not_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & list_;
}

ftor_expr::~ftor_expr() {
  delete_ptr_container( list_ );
}

ftor_expr::ftor_expr( QueryLoc const &loc, ftexpr_list_t &list ) :
  ftexpr( loc )
{
  list_.swap( list );
}

void ftor_expr::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT_SEQ( ftexpr_list_t, list_, v );
  END_VISIT( v );
}

void ftor_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & list_;
}

ftorder_filter::ftorder_filter( QueryLoc const &loc ) :
  ftpos_filter( loc )
{
}

void ftorder_filter::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  END_VISIT( v );
}

void ftorder_filter::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftpos_filter*)this );
}

ftpos_filter::ftpos_filter( QueryLoc const &loc ) :
  ftexpr( loc )
{
}

void ftpos_filter::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
}

ftprimary_with_options_expr::ftprimary_with_options_expr(
  QueryLoc const &loc
) :
  ftexpr( loc ),
  primary_( NULL ),
  match_options_( new ftmatch_options( loc ) ),
  weight_( NULL )
{
  // do nothing else
}

ftprimary_with_options_expr::~ftprimary_with_options_expr() {
  delete primary_;
  delete match_options_;
}

void ftprimary_with_options_expr::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT( primary_, v );
  ACCEPT( match_options_, v );
  END_VISIT( v );
}

void ftprimary_with_options_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & primary_;
  ar & match_options_;
  ar & weight_;
}

ftrange_expr::ftrange_expr(
  QueryLoc const &loc,
  ft_range_mode::type mode,
  additive_expr_t expr1,
  additive_expr_t expr2
) :
  ftexpr( loc ),
  mode_( mode ),
  expr1_( expr1 ),
  expr2_( expr2 )
{
}

void ftrange_expr::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  expr_visitor &v2 = v.get_expr_visitor();
  ACCEPT( expr1_, v2 );
  ACCEPT( expr2_, v2 );
  END_VISIT( v );
}

void ftrange_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  SERIALIZE_ENUM(ft_range_mode::type,mode_);
  ar & expr1_;
  ar & expr2_;
}

ftscope_filter::ftscope_filter(
  QueryLoc const &loc, ft_scope::type scope, ft_big_unit::type unit
) :
  ftpos_filter( loc ),
  scope_( scope ),
  unit_( unit )
{
}

void ftscope_filter::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  END_VISIT( v );
}

void ftscope_filter::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftpos_filter*)this );
  SERIALIZE_ENUM(ft_scope::type,scope_);
  SERIALIZE_ENUM(ft_big_unit::type,unit_);
}

ftselection_expr::ftselection_expr(
  QueryLoc const &loc,
  ftexpr *ftor,
  ftpos_filter_list_t &list
) :
  ftprimary_expr( loc ),
  ftor_( ftor )
{
  list.swap( list_ );
}

ftselection_expr::~ftselection_expr() {
  delete_ptr_container( list_ );
}

void ftselection_expr::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT_SEQ( ftpos_filter_list_t, list_, v );
  END_VISIT( v );
}

void ftselection_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & list_;
  ar & ftor_;
}

ftstem_option::ftstem_option(
  QueryLoc const &loc,
  ft_stem_mode::type mode
) :
  ftmatch_option( loc ),
  mode_( mode )
{
}

void ftstem_option::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  END_VISIT( v );
}

void ftstem_option::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option*)this );
  SERIALIZE_ENUM(ft_stem_mode::type,mode_);
}

ftstop_words::ftstop_words(
  QueryLoc const &loc,
  std::string const &uri,
  list_t const &stop_word_list,
  ft_stop_words_unex::type mode
) :
  ftexpr( loc ),
  uri_( uri ),
  list_( stop_word_list ),
  mode_( mode )
{
}

void ftstop_words::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  END_VISIT( v );
}

void ftstop_words::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & uri_;
  ar & list_;
  SERIALIZE_ENUM(ft_stop_words_unex::type,mode_);
}

ftstop_word_option::ftstop_word_option(
  QueryLoc const &loc,
  ft_stop_words_mode::type mode
) :
  ftmatch_option( loc ),
  mode_( mode )
{
}

ftstop_word_option::ftstop_word_option(
  QueryLoc const &loc,
  stop_word_list_t &stop_word_list,
  ft_stop_words_mode::type mode
) :
  ftmatch_option( loc ),
  mode_( mode )
{
  stop_words_.swap( stop_word_list );
}

ftstop_word_option::~ftstop_word_option() {
  delete_ptr_container( stop_words_ );
}

void ftstop_word_option::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT_SEQ( stop_word_list_t, stop_words_, v );
  END_VISIT( v );
}

void ftstop_word_option::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option*)this );
  ar & stop_words_;
  SERIALIZE_ENUM(ft_stop_words_mode::type,mode_);
}

ftthesaurus_id::ftthesaurus_id(
  QueryLoc const &loc,
  std::string const &uri,
  std::string const &relationship,
  ftrange_expr *levels
) :
  ftexpr( loc ),
  uri_( uri ),
  relationship_( relationship_ ),
  levels_( levels )
{
}

ftthesaurus_id::~ftthesaurus_id() {
  delete levels_;
}

void ftthesaurus_id::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT( levels_, v );
  END_VISIT( v );
}

void ftthesaurus_id::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & uri_;
  ar & relationship_;
  ar & levels_;
}

ftthesaurus_option::ftthesaurus_option(
  QueryLoc const &loc,
  thesaurus_id_list_t &list,
  bool includes_default,
  bool no_thesaurus_arg
) :
  ftmatch_option( loc ),
  includes_default_( includes_default ),
  no_thesaurus_( no_thesaurus_arg )
{
  thesaurus_id_list_.swap( list );
}

ftthesaurus_option::~ftthesaurus_option() {
  delete_ptr_container( thesaurus_id_list_ );
}

void ftthesaurus_option::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT_SEQ( thesaurus_id_list_t, thesaurus_id_list_, v );
  END_VISIT( v );
}

void ftthesaurus_option::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option*)this );
  ar & thesaurus_id_list_;
  ar & includes_default_;
  ar & no_thesaurus_;
}

ftunary_not_expr::ftunary_not_expr( QueryLoc const &loc, ftexpr *e ) :
  ftexpr( loc ), subexpr_( e )
{
}

ftunary_not_expr::~ftunary_not_expr() {
  delete subexpr_;
}

void ftunary_not_expr::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT( subexpr_, v );
  END_VISIT( v );
}

void ftunary_not_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & subexpr_;
}

ftwild_card_option::ftwild_card_option(
  QueryLoc const &loc,
  ft_wild_card_mode::type mode
) :
  ftmatch_option( loc ),
  mode_( mode )
{
}

void ftwild_card_option::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  END_VISIT( v );
}

void ftwild_card_option::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option*)this );
  SERIALIZE_ENUM(ft_wild_card_mode::type,mode_);
}

ftwindow_filter::ftwindow_filter(
  QueryLoc const &loc,
  rchandle<additive_expr> window,
  ft_unit::type unit )
:
  ftpos_filter( loc ),
  window_( window ),
  unit_( unit )
{
}

void ftwindow_filter::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  expr_visitor &v2 = v.get_expr_visitor();
  ACCEPT( window_, v2 );
  END_VISIT( v );
}

void ftwindow_filter::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftpos_filter*)this );
  ar & window_;
  SERIALIZE_ENUM(ft_unit::type,unit_);
}

ftwords_expr::ftwords_expr(
  QueryLoc const &loc,
  expr_t expr,
  ft_anyall_mode::type mode
) :
  ftexpr( loc ),
  expr_( expr ),
  mode_( mode )
{
}

void ftwords_expr::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  expr_visitor &v2 = v.get_expr_visitor();
  ACCEPT( expr_, v2 );
  END_VISIT( v );
}

void ftwords_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & expr_;
  SERIALIZE_ENUM( ft_anyall_mode::type, mode_ );
}

ftwords_times_expr::ftwords_times_expr(
  QueryLoc const &loc,
  ftwords_expr *ftwords,
  ftrange_expr *fttimes
) :
  ftprimary_expr( loc ),
  ftwords_( ftwords ),
  fttimes_( fttimes )
{
}

ftwords_times_expr::~ftwords_times_expr() {
  delete ftwords_;
  delete fttimes_;
}

void ftwords_times_expr::accept( ftexpr_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT( ftwords_, v );
  ACCEPT( fttimes_, v );
  END_VISIT( v );
}

void ftwords_times_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & ftwords_;
  ar & fttimes_;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
