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
#include "compiler/expression/ft_expr.h"
#include "compiler/expression/ftnode_visitor.h"
#include "zorbautils/container_util.h"

using namespace std;

namespace zorba {
  
SERIALIZABLE_CLASS_VERSIONS(ftcontains_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftcontains_expr)

SERIALIZABLE_CLASS_VERSIONS(ftand)
END_SERIALIZABLE_CLASS_VERSIONS(ftand)

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

SERIALIZABLE_CLASS_VERSIONS(ftextension_selection)
END_SERIALIZABLE_CLASS_VERSIONS(ftextension_selection)

SERIALIZABLE_CLASS_VERSIONS(ftlanguage_option)
END_SERIALIZABLE_CLASS_VERSIONS(ftlanguage_option)

SERIALIZABLE_CLASS_VERSIONS(ftmatch_option)
END_SERIALIZABLE_CLASS_VERSIONS(ftmatch_option)

SERIALIZABLE_CLASS_VERSIONS(ftmatch_options)
END_SERIALIZABLE_CLASS_VERSIONS(ftmatch_options)

SERIALIZABLE_CLASS_VERSIONS(ftmild_not)
END_SERIALIZABLE_CLASS_VERSIONS(ftmild_not)

SERIALIZABLE_CLASS_VERSIONS(ftnode)
END_SERIALIZABLE_CLASS_VERSIONS(ftnode)

SERIALIZABLE_CLASS_VERSIONS(ftor)
END_SERIALIZABLE_CLASS_VERSIONS(ftor)

SERIALIZABLE_CLASS_VERSIONS(ftorder_filter)
END_SERIALIZABLE_CLASS_VERSIONS(ftorder_filter)

SERIALIZABLE_CLASS_VERSIONS(ftpos_filter)
END_SERIALIZABLE_CLASS_VERSIONS(ftpos_filter)

SERIALIZABLE_CLASS_VERSIONS(ftprimary)
END_SERIALIZABLE_CLASS_VERSIONS(ftprimary)

SERIALIZABLE_CLASS_VERSIONS(ftprimary_with_options)
END_SERIALIZABLE_CLASS_VERSIONS(ftprimary_with_options)

SERIALIZABLE_CLASS_VERSIONS(ftrange)
END_SERIALIZABLE_CLASS_VERSIONS(ftrange)

SERIALIZABLE_CLASS_VERSIONS(ftscope_filter)
END_SERIALIZABLE_CLASS_VERSIONS(ftscope_filter)

SERIALIZABLE_CLASS_VERSIONS(ftselection)
END_SERIALIZABLE_CLASS_VERSIONS(ftselection)

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

SERIALIZABLE_CLASS_VERSIONS(ftunary_not)
END_SERIALIZABLE_CLASS_VERSIONS(ftunary_not)

SERIALIZABLE_CLASS_VERSIONS(ftwild_card_option)
END_SERIALIZABLE_CLASS_VERSIONS(ftwild_card_option)

SERIALIZABLE_CLASS_VERSIONS(ftwindow_filter)
END_SERIALIZABLE_CLASS_VERSIONS(ftwindow_filter)

SERIALIZABLE_CLASS_VERSIONS(ftwords)
END_SERIALIZABLE_CLASS_VERSIONS(ftwords)

SERIALIZABLE_CLASS_VERSIONS(ftwords_times)
END_SERIALIZABLE_CLASS_VERSIONS(ftwords_times)

#define DO_CHILDREN( R )  ( !(R & ft_visit_result::no_children) )
#define DO_END_VISIT( R ) ( !(R & ft_visit_result::no_end) )

#define BEGIN_VISIT( V )                                \
  ft_visit_result::type vr0 = (V).begin_visit( *this ); \
  if ( DO_CHILDREN( vr0 ) ) {

#define END_VISIT( V )                                       \
  }                                                          \
  if ( !DO_END_VISIT( vr0 ) ) ; else (V).end_visit( *this ); \
  return vr0

#define EV_ACCEPT( EXPR, V )                  \
    if ( !(EXPR) ) ; else (EXPR)->accept( V )

#define EV_ACCEPT_NULL( EXPR, V )                     \
  {                                                   \
    expr_visitor *const ev = (V).get_expr_visitor();  \
    if ( ev && (EXPR) ) (EXPR)->accept( *ev );        \
  }

#define ACCEPT( FTNODE, V ) \
  if ( !(FTNODE) ) ; else   \
  vr0 = (ft_visit_result::type)(vr0 | (FTNODE)->accept( V ))

#define ACCEPT_SEQ( T, S, V )                 \
  for ( T::const_iterator i = (S).begin();    \
        DO_CHILDREN( vr0 ) && i != (S).end(); \
        ++i )                                 \
    ACCEPT( *i, V );

///////////////////////////////////////////////////////////////////////////////

ftcontains_expr::ftcontains_expr(
  static_context* sctx,
  QueryLoc const &loc,
  expr_t range,
  ftnode *ftsel,
  expr_t ftignore
) :
  expr( sctx, loc, ft_expr_kind ),
  range_( range ),
  ftselection_( ftsel ),
  ftignore_( ftignore )
{
  ZORBA_ASSERT( range );
  ZORBA_ASSERT( ftsel );
  compute_scripting_kind();
}

void ftcontains_expr::accept( expr_visitor &v ) {
  if ( v.begin_visit( *this ) ) {
    EV_ACCEPT( range_, v );
    ftselection_->accept( *v.get_ftnode_visitor() );
    EV_ACCEPT( ftignore_, v );
  }
  v.end_visit( *this );
}

void ftcontains_expr::compute_scripting_kind() {
  theScriptingKind = SIMPLE_EXPR;
  // TODO: checkIsSimple for all sub-expr
}

void ftcontains_expr::serialize( serialization::Archiver &ar )
{
  serialize_baseclass( ar, (expr*)this );
  ar & range_;
  ar & ftselection_;
  ar & ftignore_;
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

void ftnode::serialize( serialization::Archiver &ar ) {
  ar & loc_;
}

ftand::ftand(
  QueryLoc const &loc,
  ftnode_list_t &list
) :
  ftnode( loc )
{
  list_.swap( list );
}

ftand::~ftand() {
  delete_ptr_container( list_ );
}

ft_visit_result::type ftand::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT_SEQ( ftnode_list_t, list_, v );
  END_VISIT( v );
}

void ftand::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftnode*)this );
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

ft_visit_result::type ftcase_option::accept( ftnode_visitor &v ) {
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

ft_visit_result::type ftcontent_filter::accept( ftnode_visitor &v ) {
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

ft_visit_result::type ftdiacritics_option::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  END_VISIT( v );
}

void ftdiacritics_option::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option*)this );
  SERIALIZE_ENUM(ft_diacritics_mode::type,mode_);
}

ftdistance_filter::ftdistance_filter(
  QueryLoc const &loc,
  ftrange *range,
  ft_unit::type unit
) :
  ftpos_filter( loc ),
  range_( range ),
  unit_( unit )
{
}

ft_visit_result::type ftdistance_filter::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT( range_, v );
  END_VISIT( v );
}

void ftdistance_filter::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftpos_filter*)this );
  ar & range_;
  SERIALIZE_ENUM(ft_unit::type,unit_);
}

ftextension_selection::ftextension_selection(
  QueryLoc const &loc,
  /* TODO: pragma_list, */
  ftselection *selection
) :
  ftprimary( loc ),
  /* TODO: pragma_list_( pragma_list ), */
  ftselection_( selection )
{
}

ft_visit_result::type ftextension_selection::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT( ftselection_, v );
  END_VISIT( v );
}

void ftextension_selection::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftnode*)this );
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

ft_visit_result::type ftextension_option::accept( ftnode_visitor &v ) {
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

ft_visit_result::type ftlanguage_option::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  END_VISIT( v );
}

void ftlanguage_option::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option*)this );
  ar & language_;
}

void ftmatch_option::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftnode*)this );
}

ftmatch_options::ftmatch_options(
  QueryLoc const &loc
) :
  ftnode( loc ),
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

ft_visit_result::type ftmatch_options::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT( case_option_, v );
  ACCEPT( diacritics_option_, v );
  ACCEPT( extension_option_, v );
  ACCEPT( language_option_, v );
  ACCEPT( stem_option_, v );
  ACCEPT( stop_word_option_, v );
  ACCEPT( thesaurus_option_, v );
  ACCEPT( wild_card_option_, v );
  END_VISIT( v );
}

void ftmatch_options::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftnode*)this );
  ar & case_option_;
  ar & extension_option_;
  ar & language_option_;
  ar & stem_option_;
  ar & stop_word_option_;
  ar & thesaurus_option_;
  ar & wild_card_option_;
}

ftmild_not::ftmild_not( QueryLoc const &loc, ftnode_list_t &list ) :
  ftnode( loc )
{
  list_.swap( list );
}

ftmild_not::~ftmild_not() {
  delete_ptr_container( list_ );
}

ft_visit_result::type ftmild_not::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT_SEQ( ftnode_list_t, list_, v );
  END_VISIT( v );
}

void ftmild_not::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftnode*)this );
  ar & list_;
}

ftor::~ftor() {
  delete_ptr_container( list_ );
}

ftor::ftor( QueryLoc const &loc, ftnode_list_t &list ) :
  ftnode( loc )
{
  list_.swap( list );
}

ft_visit_result::type ftor::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT_SEQ( ftnode_list_t, list_, v );
  END_VISIT( v );
}

void ftor::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftnode*)this );
  ar & list_;
}

ftorder_filter::ftorder_filter( QueryLoc const &loc ) :
  ftpos_filter( loc )
{
}

ft_visit_result::type ftorder_filter::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  END_VISIT( v );
}

void ftorder_filter::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftpos_filter*)this );
}

ftpos_filter::ftpos_filter( QueryLoc const &loc ) :
  ftnode( loc )
{
}

ftprimary_with_options::ftprimary_with_options(
  QueryLoc const &loc
) :
  ftnode( loc ),
  primary_( NULL ),
  match_options_( new ftmatch_options( loc ) ),
  weight_( NULL )
{
  // do nothing else
}

ftprimary_with_options::~ftprimary_with_options() {
  delete primary_;
  delete match_options_;
}

ft_visit_result::type ftprimary_with_options::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT( primary_, v );
  ACCEPT( match_options_, v );
  END_VISIT( v );
}

void ftprimary_with_options::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftnode*)this );
  ar & primary_;
  ar & match_options_;
  ar & weight_;
}

ftrange::ftrange(
  QueryLoc const &loc,
  ft_range_mode::type mode,
  expr_t expr1,
  expr_t expr2
) :
  ftnode( loc ),
  mode_( mode ),
  expr1_( expr1 ),
  expr2_( expr2 )
{
}

ft_visit_result::type ftrange::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  EV_ACCEPT_NULL( expr1_, v );
  EV_ACCEPT_NULL( expr2_, v );
  END_VISIT( v );
}

void ftrange::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftnode*)this );
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

ft_visit_result::type ftscope_filter::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  END_VISIT( v );
}

void ftscope_filter::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftpos_filter*)this );
  SERIALIZE_ENUM(ft_scope::type,scope_);
  SERIALIZE_ENUM(ft_big_unit::type,unit_);
}

ftselection::ftselection(
  QueryLoc const &loc,
  ftnode *ftor,
  ftpos_filter_list_t &list
) :
  ftprimary( loc ),
  ftor_( ftor )
{
  list.swap( list_ );
}

ftselection::~ftselection() {
  delete_ptr_container( list_ );
}

ft_visit_result::type ftselection::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT( ftor_, v );
  ACCEPT_SEQ( ftpos_filter_list_t, list_, v );
  END_VISIT( v );
}

void ftselection::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftnode*)this );
  ar & ftor_;
  ar & list_;
}

ftstem_option::ftstem_option(
  QueryLoc const &loc,
  ft_stem_mode::type mode
) :
  ftmatch_option( loc ),
  mode_( mode )
{
}

ft_visit_result::type ftstem_option::accept( ftnode_visitor &v ) {
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
  ftnode( loc ),
  uri_( uri ),
  list_( stop_word_list ),
  mode_( mode )
{
}

ft_visit_result::type ftstop_words::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  END_VISIT( v );
}

void ftstop_words::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftnode*)this );
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

ft_visit_result::type ftstop_word_option::accept( ftnode_visitor &v ) {
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
  ftrange *levels
) :
  ftnode( loc ),
  uri_( uri ),
  relationship_( relationship_ ),
  levels_( levels )
{
}

ftthesaurus_id::~ftthesaurus_id() {
  delete levels_;
}

ft_visit_result::type ftthesaurus_id::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT( levels_, v );
  END_VISIT( v );
}

void ftthesaurus_id::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftnode*)this );
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

ft_visit_result::type ftthesaurus_option::accept( ftnode_visitor &v ) {
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

ftunary_not::ftunary_not( QueryLoc const &loc, ftnode *n ) :
  ftnode( loc ), subnode_( n )
{
}

ftunary_not::~ftunary_not() {
  delete subnode_;
}

ft_visit_result::type ftunary_not::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT( subnode_, v );
  END_VISIT( v );
}

void ftunary_not::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftnode*)this );
  ar & subnode_;
}

ftwild_card_option::ftwild_card_option(
  QueryLoc const &loc,
  ft_wild_card_mode::type mode
) :
  ftmatch_option( loc ),
  mode_( mode )
{
}

ft_visit_result::type ftwild_card_option::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  END_VISIT( v );
}

void ftwild_card_option::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option*)this );
  SERIALIZE_ENUM(ft_wild_card_mode::type,mode_);
}

ftwindow_filter::ftwindow_filter(
  QueryLoc const &loc,
  expr_t window,
  ft_unit::type unit )
:
  ftpos_filter( loc ),
  window_( window ),
  unit_( unit )
{
}

ft_visit_result::type ftwindow_filter::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  EV_ACCEPT_NULL( window_, v );
  END_VISIT( v );
}

void ftwindow_filter::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftpos_filter*)this );
  ar & window_;
  SERIALIZE_ENUM(ft_unit::type,unit_);
}

ftwords::ftwords(
  QueryLoc const &loc,
  expr_t expr,
  ft_anyall_mode::type mode
) :
  ftnode( loc ),
  expr_( expr ),
  mode_( mode )
{
}

ft_visit_result::type ftwords::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  EV_ACCEPT_NULL( expr_, v );
  END_VISIT( v );
}

void ftwords::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftnode*)this );
  ar & expr_;
  SERIALIZE_ENUM( ft_anyall_mode::type, mode_ );
}

ftwords_times::ftwords_times(
  QueryLoc const &loc,
  ftwords *ftwords,
  ftrange *fttimes
) :
  ftprimary( loc ),
  ftwords_( ftwords ),
  fttimes_( fttimes )
{
  ZORBA_ASSERT( ftwords_ );
}

ftwords_times::~ftwords_times() {
  delete ftwords_;
  delete fttimes_;
}

ft_visit_result::type ftwords_times::accept( ftnode_visitor &v ) {
  BEGIN_VISIT( v );
  ACCEPT( ftwords_, v );
  ACCEPT( fttimes_, v );
  END_VISIT( v );
}

void ftwords_times::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftnode*)this );
  ar & ftwords_;
  ar & fttimes_;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
