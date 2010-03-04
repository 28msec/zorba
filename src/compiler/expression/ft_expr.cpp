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

#include "compiler/expression/ft_expr.h"
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

SERIALIZABLE_CLASS_VERSIONS(ftcontent_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftcontent_expr)

SERIALIZABLE_CLASS_VERSIONS(ftcase_option_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftcase_option_expr)

SERIALIZABLE_CLASS_VERSIONS(ftdiacritics_option_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftdiacritics_option_expr)

SERIALIZABLE_CLASS_VERSIONS(ftdistance_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftdistance_expr)

SERIALIZABLE_CLASS_VERSIONS(ftextension_option_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftextension_option_expr)

SERIALIZABLE_CLASS_VERSIONS(ftextension_selection_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftextension_selection_expr)

SERIALIZABLE_CLASS_VERSIONS(ftlanguage_option_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftlanguage_option_expr)

SERIALIZABLE_CLASS_VERSIONS(ftmatch_option_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftmatch_option_expr)

SERIALIZABLE_CLASS_VERSIONS(ftmild_not_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftmild_not_expr)

SERIALIZABLE_CLASS_VERSIONS(ftor_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftor_expr)

SERIALIZABLE_CLASS_VERSIONS(ftorder_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftorder_expr)

SERIALIZABLE_CLASS_VERSIONS(ftpos_filter_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftpos_filter_expr)

SERIALIZABLE_CLASS_VERSIONS(ftprimary_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftprimary_expr)

SERIALIZABLE_CLASS_VERSIONS(ftprimary_with_options_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftprimary_with_options_expr)

SERIALIZABLE_CLASS_VERSIONS(ftrange_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftrange_expr)

SERIALIZABLE_CLASS_VERSIONS(ftscope_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftscope_expr)

SERIALIZABLE_CLASS_VERSIONS(ftselection_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftselection_expr)

SERIALIZABLE_CLASS_VERSIONS(ftstem_option_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftstem_option_expr)

SERIALIZABLE_CLASS_VERSIONS(ftstop_words_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftstop_words_expr)

SERIALIZABLE_CLASS_VERSIONS(ftstop_word_option_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftstop_word_option_expr)

SERIALIZABLE_CLASS_VERSIONS(ftthesaurus_id_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftthesaurus_id_expr)

SERIALIZABLE_CLASS_VERSIONS(ftthesaurus_option_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftthesaurus_option_expr)

SERIALIZABLE_CLASS_VERSIONS(ftunary_not_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftunary_not_expr)

SERIALIZABLE_CLASS_VERSIONS(ftwild_card_option_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftwild_card_option_expr)

SERIALIZABLE_CLASS_VERSIONS(ftwindow_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftwindow_expr)

SERIALIZABLE_CLASS_VERSIONS(ftwords_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftwords_expr)

SERIALIZABLE_CLASS_VERSIONS(ftwords_times_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ftwords_times_expr)

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

void ftcontains_expr::serialize( serialization::Archiver &ar )
{
  serialize_baseclass( ar, (expr*)this );
  ar & range_;
  ar & ftselection_;
  ar & ftignore_;
}

void ftcontains_expr::next_iter( expr_iterator_data &v ) {
  BEGIN_EXPR_ITER ();
  ITER (range_);
  ITER (ftselection_);
  ITER (ftignore_);
  END_EXPR_ITER ();
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

void ftand_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & list_;
}

ftand_expr::ftand_expr(
  QueryLoc const &loc, ftexpr_list_t &r
) :
  ftexpr( loc )
{
  list_.swap( r );
}

ftand_expr::~ftand_expr() {
  delete_ptr_container( list_ );
}

ftcase_option_expr::ftcase_option_expr(
  QueryLoc const &loc,
  ft_case_mode::type mode
) :
  ftmatch_option_expr( loc ),
  mode_( mode )
{
}

void ftcase_option_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option_expr*)this );
  SERIALIZE_ENUM(ft_case_mode::type,mode_);
}

ftcontent_expr::ftcontent_expr(
  QueryLoc const &loc, ft_content_mode::type mode
) :
  ftpos_filter_expr( loc ),
  mode_( mode_ )
{
}

ftdiacritics_option_expr::ftdiacritics_option_expr(
  QueryLoc const &loc,
  ft_diacritics_mode::type mode
) :
  ftmatch_option_expr( loc ),
  mode_( mode )
{
}

void ftdiacritics_option_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option_expr*)this );
  SERIALIZE_ENUM(ft_diacritics_mode::type,mode_);
}

ftdistance_expr::ftdistance_expr(
  QueryLoc const &loc,
  ftrange_expr *range,
  ft_unit::type unit
) :
  ftpos_filter_expr( loc ),
  range_( range ),
  unit_( unit )
{
}

void ftdistance_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftpos_filter_expr*)this );
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

void ftextension_selection_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
}

ftextension_option_expr::ftextension_option_expr(
  QueryLoc const &loc,
  rchandle<QName> qname,
  string const &val
) :
  ftmatch_option_expr( loc ),
  qname_( qname ),
  val_( val )
{
}

void ftextension_option_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option_expr*)this );
  ar & qname_;
  ar & val_;
}

ftlanguage_option_expr::ftlanguage_option_expr(
  QueryLoc const &loc, string const &lang
) :
  ftmatch_option_expr( loc ),
  language_( lang )
{
}

void ftlanguage_option_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option_expr*)this );
  ar & language_;
}

void ftmatch_option_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
}

ftmild_not_expr::~ftmild_not_expr() {
  delete_ptr_container( list_ );
}

void ftmild_not_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & list_;
}

ftor_expr::~ftor_expr() {
  delete_ptr_container( list_ );
}

void ftor_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & list_;
}

ftorder_expr::ftorder_expr( QueryLoc const &loc ) : ftpos_filter_expr( loc ) {
}

void ftorder_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftpos_filter_expr*)this );
}

ftprimary_with_options_expr::ftprimary_with_options_expr(
  QueryLoc const &loc
) :
  ftexpr( loc ),
  case_option_( new ftcase_option_expr( loc ) ),
  diacritics_option_( new ftdiacritics_option_expr( loc ) ),
  extension_option_( NULL ),
  language_option_( new ftlanguage_option_expr( loc, "" ) ),
  primary_( NULL ),
  stem_option_( new ftstem_option_expr( loc ) ),
  stop_word_option_( new ftstop_word_option_expr( loc ) ),
  weight_( NULL ),
  wild_card_option_( new ftwild_card_option_expr( loc ) )
{
  // do nothing else
}

ftprimary_with_options_expr::~ftprimary_with_options_expr() {
  delete case_option_;
  delete diacritics_option_;
  delete extension_option_;
  delete language_option_;
  delete primary_;
  delete stem_option_;
  delete stop_word_option_;
  delete thesaurus_option_;
  delete weight_;
  delete wild_card_option_;
}

void ftprimary_with_options_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & case_option_;
  ar & diacritics_option_;
  ar & extension_option_;
  ar & language_option_;
  ar & primary_;
  ar & stem_option_;
  ar & stop_word_option_;
  ar & thesaurus_option_;
  ar & weight_;
  ar & wild_card_option_;
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

void ftrange_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  SERIALIZE_ENUM(ft_range_mode::type,mode_);
  ar & expr1_;
  ar & expr2_;
}

ftscope_expr::ftscope_expr(
  QueryLoc const &loc, ft_scope::type scope, ft_big_unit::type unit
) :
  ftpos_filter_expr( loc ),
  scope_( scope ),
  unit_( unit )
{
}

void ftscope_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftpos_filter_expr*)this );
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

void ftselection_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & list_;
  ar & ftor_;
}

ftstem_option_expr::ftstem_option_expr(
  QueryLoc const &loc,
  ft_stem_mode::type mode
) :
  ftmatch_option_expr( loc ),
  mode_( mode )
{
}

void ftstem_option_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option_expr*)this );
  SERIALIZE_ENUM(ft_stem_mode::type,mode_);
}

ftstop_words_expr::ftstop_words_expr(
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

void ftstop_words_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & uri_;
  ar & list_;
  SERIALIZE_ENUM(ft_stop_words_unex::type,mode_);
}

ftstop_word_option_expr::ftstop_word_option_expr(
  QueryLoc const &loc,
  ft_stop_words_mode::type mode
) :
  ftmatch_option_expr( loc ),
  mode_( mode )
{
}

ftstop_word_option_expr::ftstop_word_option_expr(
  QueryLoc const &loc,
  stop_word_list_t &stop_word_list,
  ft_stop_words_mode::type mode
) :
  ftmatch_option_expr( loc ),
  mode_( mode )
{
  stop_words_.swap( stop_word_list );
}

void ftstop_word_option_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option_expr*)this );
  // TODO: ar & stop_words_;
  SERIALIZE_ENUM(ft_stop_words_mode::type,mode_);
}

ftthesaurus_id_expr::ftthesaurus_id_expr(
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

void ftthesaurus_id_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & uri_;
  ar & relationship_;
  ar & levels_;
}

ftthesaurus_option_expr::ftthesaurus_option_expr(
  QueryLoc const &loc,
  thesaurus_id_list_t &list,
  bool includes_default,
  bool no_thesaurus_arg
) :
  ftmatch_option_expr( loc ),
  includes_default_( includes_default ),
  no_thesaurus_( no_thesaurus_arg )
{
  thesaurus_id_list_.swap( list );
}

ftthesaurus_option_expr::~ftthesaurus_option_expr() {
  delete_ptr_container( thesaurus_id_list_ );
}

void ftthesaurus_option_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option_expr*)this );
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

void ftunary_not_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & subexpr_;
}

ftwild_card_option_expr::ftwild_card_option_expr(
  QueryLoc const &loc,
  ft_wild_card_mode::type mode
) :
  ftmatch_option_expr( loc ),
  mode_( mode )
{
}

void ftwild_card_option_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftmatch_option_expr*)this );
  SERIALIZE_ENUM(ft_wild_card_mode::type,mode_);
}

ftwindow_expr::ftwindow_expr(
  QueryLoc const &loc,
  rchandle<additive_expr> window,
  ft_unit::type unit )
:
  ftpos_filter_expr( loc ),
  window_( window ),
  unit_( unit )
{
}

void ftwindow_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftpos_filter_expr*)this );
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

void ftwords_times_expr::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (ftexpr*)this );
  ar & ftwords_;
  ar & fttimes_;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
