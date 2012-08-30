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
#pragma once
#ifndef ZORBA_COMPILER_FTNODE_H
#define ZORBA_COMPILER_FTNODE_H

#include <zorba/locale.h>

#include "common/shared_types.h"
#include "compiler/expression/expr_base.h"
#include "compiler/expression/ftnode_classes.h"
#include "compiler/parser/ft_types.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/parsetree/parsenodes.h"
#include "runtime/base/plan_iterator.h"
#include "util/cxx_util.h"
#include "zorbatypes/rchandle.h"
#include "zorbatypes/zstring.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * Base class for full-text expression classes.
 */
class ftnode : public SimpleRCObject {
public:
  SERIALIZABLE_ABSTRACT_CLASS(ftnode)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftnode, SimpleRCObject)
  void serialize( serialization::Archiver& );

  virtual ft_visit_result::type accept( ftnode_visitor& ) = 0;
  virtual ftnode_t clone( expr::substitution_t& ) const = 0;
  QueryLoc const& get_loc() const { return loc_; }
  virtual std::ostream& put( std::ostream& ) const = 0;

protected:
  ftnode( QueryLoc const &loc ) : loc_( loc ) {
  }

private:
  QueryLoc loc_;
};

inline std::ostream& operator<<( std::ostream &o, ftnode const &n ) {
  return n.put( o );
}

////////// FTMatchOptions /////////////////////////////////////////////////////

class ftmatch_option : public ftnode {
public:
  SERIALIZABLE_ABSTRACT_CLASS(ftmatch_option)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftmatch_option,ftnode)
  void serialize( serialization::Archiver& );

protected:
  ftmatch_option( QueryLoc const &loc ) : ftnode( loc ) { }
};


class ftcase_option : public ftmatch_option {
public:
  SERIALIZABLE_CLASS(ftcase_option)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftcase_option,ftmatch_option)
  void serialize( serialization::Archiver& );

  ftcase_option(
    QueryLoc const&,
    ft_case_mode::type = ft_case_mode::DEFAULT
  );

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  ft_case_mode::type get_mode() const { return mode_; }
  std::ostream& put( std::ostream& ) const;

private:
  ft_case_mode::type mode_;
};
typedef rchandle<ftcase_option> ftcase_option_t;


class ftdiacritics_option : public ftmatch_option {
public:
  SERIALIZABLE_CLASS(ftdiacritics_option)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftdiacritics_option,ftmatch_option)
  void serialize( serialization::Archiver& );

  ftdiacritics_option(
    QueryLoc const&,
    ft_diacritics_mode::type = ft_diacritics_mode::DEFAULT
  );

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  ft_diacritics_mode::type get_mode() const { return mode_; }
  std::ostream& put( std::ostream& ) const;

private:
  ft_diacritics_mode::type mode_;
};
typedef rchandle<ftdiacritics_option> ftdiacritics_option_t;


class ftextension_option : public ftmatch_option {
public:
  SERIALIZABLE_CLASS(ftextension_option)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftextension_option,ftmatch_option)
  void serialize( serialization::Archiver& );

  ftextension_option(
    QueryLoc const&,
    rchandle<QName> const&,
    zstring const &val
  );

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  rchandle<QName> const& get_qname() const { return qname_; }
  zstring const& get_val() const { return val_; }
  std::ostream& put( std::ostream& ) const;

private:
  rchandle<QName> qname_;
  zstring val_;
};
typedef rchandle<ftextension_option> ftextension_option_t;


class ftlanguage_option : public ftmatch_option {
public:
  SERIALIZABLE_CLASS(ftlanguage_option)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftlanguage_option,ftmatch_option)
  void serialize( serialization::Archiver& );

  ftlanguage_option(
    QueryLoc const&,
    zstring const &language
  );

  ftlanguage_option(
    QueryLoc const&,
    locale::iso639_1::type
  );

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  locale::iso639_1::type get_language() const { return lang_; }
  std::ostream& put( std::ostream& ) const;

private:
  locale::iso639_1::type lang_;
};
typedef rchandle<ftlanguage_option> ftlanguage_option_t;


class ftstem_option : public ftmatch_option {
public:
  SERIALIZABLE_CLASS(ftstem_option)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftstem_option,ftmatch_option)
  void serialize( serialization::Archiver& );

  ftstem_option(
    QueryLoc const&,
    ft_stem_mode::type = ft_stem_mode::DEFAULT
  );

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  ft_stem_mode::type get_mode() const { return mode_; }
  std::ostream& put( std::ostream& ) const;

private:
  ft_stem_mode::type mode_;
};
typedef rchandle<ftstem_option> ftstem_option_t;


class ftstop_words : public ftnode {
public:
  SERIALIZABLE_CLASS(ftstop_words)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftstop_words,ftnode)
  void serialize( serialization::Archiver& );

  typedef std::list<zstring> list_t;

  ftstop_words(
    QueryLoc const&,
    zstring const &uri,
    list_t const&,
    ft_stop_words_unex::type = ft_stop_words_unex::union_
  );

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  zstring const& get_uri() const { return uri_; }
  list_t const& get_list() const { return list_; }
  ft_stop_words_unex::type get_mode() const { return mode_; }
  std::ostream& put( std::ostream& ) const;

  void set_mode( ft_stop_words_unex::type mode ) {
    mode_ = mode;
  }

private:
  zstring uri_;
  list_t list_;
  ft_stop_words_unex::type mode_;
};


class ftstop_word_option : public ftmatch_option {
public:
  SERIALIZABLE_CLASS(ftstop_word_option)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftstop_word_option,ftmatch_option)
  void serialize( serialization::Archiver& );

  typedef std::list<ftstop_words*> list_t;

  ftstop_word_option(
    QueryLoc const&,
    ft_stop_words_mode::type = ft_stop_words_mode::DEFAULT
  );

  ftstop_word_option(
    QueryLoc const&,
    list_t&,
    ft_stop_words_mode::type = ft_stop_words_mode::DEFAULT
  );

  ~ftstop_word_option();

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  ft_stop_words_mode::type get_mode() const { return mode_; }
  list_t const& get_stop_words() const { return stop_words_; }
  std::ostream& put( std::ostream& ) const;

private:
  list_t stop_words_;
  ft_stop_words_mode::type mode_;
};
typedef rchandle<ftstop_word_option> ftstop_word_option_t;


class ftthesaurus_id : public ftnode {
public:
  SERIALIZABLE_CLASS(ftthesaurus_id)
  SERIALIZABLE_CLASS_CONSTRUCTOR2_NULL_PARAM1(ftthesaurus_id,ftnode,levels_)
  void serialize( serialization::Archiver& );

  ftthesaurus_id(
    QueryLoc const&,
    zstring const &uri,
    zstring const &relationship = "",
    ftrange *levels = nullptr
  );
  ~ftthesaurus_id();

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  zstring const& get_uri() const { return uri_; }
  zstring const& get_relationship() const { return relationship_; }
  ftrange const* get_levels() const { return levels_; }
  std::ostream& put( std::ostream& ) const;

private:
  zstring uri_;
  zstring relationship_;
  ftrange *levels_;
};


class ftthesaurus_option : public ftmatch_option {
public:
  SERIALIZABLE_CLASS(ftthesaurus_option)
  SERIALIZABLE_CLASS_CONSTRUCTOR2_NULL_PARAM1(ftthesaurus_option,ftmatch_option,default_tid_)
  void serialize( serialization::Archiver& );

  typedef std::list<ftthesaurus_id*> thesaurus_id_list_t;

  ftthesaurus_option(
    QueryLoc const&,
    ftthesaurus_id *default_tid,
    thesaurus_id_list_t&,
    bool no_thesaurus
  );
  ~ftthesaurus_option();

  ftthesaurus_id const* get_default_thesaurus_id() const {
    return default_tid_;
  }
  thesaurus_id_list_t const& get_thesaurus_id_list() const {
    return thesaurus_id_list_;
  }

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  bool no_thesaurus() const { return no_thesaurus_; }
  std::ostream& put( std::ostream& ) const;

private:
  ftthesaurus_id *default_tid_;
  thesaurus_id_list_t thesaurus_id_list_;
  bool no_thesaurus_;
};
typedef rchandle<ftthesaurus_option> ftthesaurus_option_t;


class ftwild_card_option : public ftmatch_option {
public:
  SERIALIZABLE_CLASS(ftwild_card_option)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftwild_card_option,ftmatch_option)
  void serialize( serialization::Archiver& );

  ftwild_card_option(
    QueryLoc const&,
    ft_wild_card_mode::type = ft_wild_card_mode::DEFAULT
  );

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  ft_wild_card_mode::type get_mode() const { return mode_; }
  std::ostream& put( std::ostream& ) const;

private:
  ft_wild_card_mode::type mode_;
};
typedef rchandle<ftwild_card_option> ftwild_card_option_t;


class ftmatch_options : public ftnode {
public:
  SERIALIZABLE_CLASS(ftmatch_options)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftmatch_options,ftnode)
  void serialize( serialization::Archiver& );

  typedef std::list<ftextension_option_t> ftextension_option_list_t;

  ftmatch_options( QueryLoc const& );

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;

  ftcase_option const* get_case_option() const {
    return case_option_.getp();
  }

  ftdiacritics_option const* get_diacritics_option() const {
    return diacritics_option_.getp();
  }

  ftextension_option_list_t* get_extension_options() {
    return extension_options_.empty() ? nullptr : &extension_options_;
  }

  ftextension_option_list_t const* get_extension_options() const {
    return extension_options_.empty() ? nullptr : &extension_options_;
  }

  ftlanguage_option const* get_language_option() const {
    return language_option_.getp();
  }

  ftstem_option const* get_stem_option() const {
    return stem_option_.getp();
  }

  ftstop_word_option const* get_stop_word_option() const {
    return stop_word_option_.getp();
  }

  ftthesaurus_option const* get_thesaurus_option() const {
    return thesaurus_option_.getp();
  }

  ftwild_card_option const* get_wild_card_option() const {
    return wild_card_option_.getp();
  }

  void add_extension_option( ftextension_option *o ) {
    extension_options_.push_back( o );
  }

  void set_case_option( ftcase_option const *o ) {
    case_option_ = o;
  }

  void set_diacritics_option( ftdiacritics_option const *o ) {
    diacritics_option_ = o;
  }

  void set_extension_options( ftextension_option_list_t const *o ) {
    current_extension_options_ = o;
  }

  void set_language_option( ftlanguage_option const *o ) {
    language_option_ = o;
  }

  void set_stem_option( ftstem_option const *o ) {
    stem_option_ = o;
  }

  void set_stop_word_option( ftstop_word_option const *o ) {
    stop_word_option_ = o;
  }

  void set_thesaurus_option( ftthesaurus_option const *o ) {
    thesaurus_option_ = o;
  }

  void set_wild_card_option( ftwild_card_option const *o ) {
    wild_card_option_ = o;
  }

  void set_missing_defaults();

  std::ostream& put( std::ostream& ) const;

private:
  ftcase_option_t case_option_;
  ftdiacritics_option_t diacritics_option_;

  ftextension_option_list_t extension_options_;
  //
  // This points either to our own extension_options_ or a different one set by
  // set_extension_options().
  //
  ftextension_option_list_t const *current_extension_options_;

  ftlanguage_option_t language_option_;
  ftstem_option_t stem_option_;
  ftstop_word_option_t stop_word_option_;
  ftthesaurus_option_t thesaurus_option_;
  ftwild_card_option_t wild_card_option_;
};

////////// Miscellaneous //////////////////////////////////////////////////////

class ftweight : public ftnode {
public:
  SERIALIZABLE_CLASS(ftweight)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftweight,ftnode)
  void serialize( serialization::Archiver& );

  ftweight( QueryLoc const&, expr* const &weight_expr );

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  expr** get_weight_expr() { return &weight_expr_; }
  PlanIter_t get_weight_iter() const { return weight_iter_; }
  std::ostream& put( std::ostream& ) const;

  void set_weight_iter( PlanIter_t const &iter ) {
    weight_iter_ = iter;
  }

private:
  expr* weight_expr_;
  PlanIter_t weight_iter_;
};

////////// FTPrimary & FTSelection ////////////////////////////////////////////

class ftprimary : public ftnode {
public:
  SERIALIZABLE_ABSTRACT_CLASS(ftprimary)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftprimary,ftnode)
  void serialize( serialization::Archiver &ar ) {
    serialize_baseclass( ar, (ftnode*)this );
  }

protected:
  ftprimary( QueryLoc const &loc ) : ftnode( loc ) { }
};


class ftprimary_with_options : public ftnode {
public:
  SERIALIZABLE_CLASS(ftprimary_with_options)
  ftprimary_with_options(serialization::Archiver& ar);
  void serialize( serialization::Archiver& );

  ftprimary_with_options( QueryLoc const& );
  ~ftprimary_with_options();

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  ftprimary const* get_primary() const { return primary_; }
  ftweight* get_weight() { return weight_; }
  ftmatch_options const* get_match_options() const { return match_options_; }
  std::ostream& put( std::ostream& ) const;

  void set_match_options( ftmatch_options *o ) {
    delete match_options_;
    match_options_ = o;
  }

  void set_primary( ftprimary *p ) {
    delete primary_;
    primary_ = p;
  }

  void set_weight( ftweight *weight ) {
    delete weight_;
    weight_ = weight;
  }

private:
  ftprimary *primary_;
  ftmatch_options *match_options_;
  ftweight *weight_;
};


class ftextension_selection : public ftprimary {
public:
  SERIALIZABLE_CLASS(ftextension_selection)
  SERIALIZABLE_CLASS_CONSTRUCTOR2_NULL_PARAM1(ftextension_selection,ftprimary,ftselection_)
  void serialize( serialization::Archiver& );

  ftextension_selection(
    QueryLoc const&,
    rchandle<PragmaList> const&,
    ftselection*
  );
  ~ftextension_selection();

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  rchandle<PragmaList> const& get_pragmas() const { return pragmas_; }
  ftselection const* get_ftselection() const { return ftselection_; }
  std::ostream& put( std::ostream& ) const;

private:
  rchandle<PragmaList> pragmas_;
  ftselection *ftselection_;
};


class ftselection : public ftprimary {
public:
  SERIALIZABLE_CLASS(ftselection)
  SERIALIZABLE_CLASS_CONSTRUCTOR2_NULL_PARAM1(ftselection,ftprimary,ftor_)
  void serialize( serialization::Archiver& );

  typedef std::list<ftpos_filter*> ftpos_filter_list_t;

  ftselection(
    QueryLoc const&,
    ftnode *ftor,
    ftpos_filter_list_t const&
  );
  ~ftselection();

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  ftpos_filter_list_t const& get_ftpos_filter_list() const { return list_; }
  ftnode const* get_ftor() const { return ftor_; };
  std::ostream& put( std::ostream& ) const;

private:
  ftnode *ftor_;
  ftpos_filter_list_t list_;
};


class ftwords_times : public ftprimary {
public:
  SERIALIZABLE_CLASS(ftwords_times)
  SERIALIZABLE_CLASS_CONSTRUCTOR2_NULL_PARAM2(ftwords_times,ftprimary,ftwords_,fttimes_)
  void serialize( serialization::Archiver& );

  ftwords_times(
    QueryLoc const&,
    ftwords*,
    ftrange *times = nullptr
  );
  ~ftwords_times();

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  ftwords const* get_words() const { return ftwords_; }
  ftrange const* get_times() const { return fttimes_; }
  std::ostream& put( std::ostream& ) const;

private:
  ftwords *ftwords_;
  ftrange *fttimes_;
};

//////// FTPosFilter //////////////////////////////////////////////////////////

class ftpos_filter : public ftnode {
public:
  SERIALIZABLE_ABSTRACT_CLASS(ftpos_filter)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftpos_filter,ftnode)
  void serialize( serialization::Archiver& );

protected:
  ftpos_filter( QueryLoc const& );
};


class ftcontent_filter : public ftpos_filter {
public:
  SERIALIZABLE_CLASS(ftcontent_filter)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftcontent_filter,ftpos_filter)
  void serialize( serialization::Archiver& );

  ftcontent_filter( QueryLoc const&, ft_content_mode::type );

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  ft_content_mode::type get_mode() const { return mode_; }
  std::ostream& put( std::ostream& ) const;

private:
  ft_content_mode::type mode_;
};


class ftdistance_filter : public ftpos_filter {
public:
  SERIALIZABLE_CLASS(ftdistance_filter)
  SERIALIZABLE_CLASS_CONSTRUCTOR2_NULL_PARAM1(ftdistance_filter,ftpos_filter, range_)
  void serialize( serialization::Archiver& );

  ftdistance_filter( QueryLoc const&, ftrange*, ft_unit::type );
  ~ftdistance_filter();

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  ftrange const* get_range() const { return range_; }
  ft_unit::type get_unit() const { return unit_; }
  std::ostream& put( std::ostream& ) const;

private:
  ftrange *range_;
  ft_unit::type unit_;
};


class ftorder_filter : public ftpos_filter {
public:
  SERIALIZABLE_CLASS(ftorder_filter)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftorder_filter,ftpos_filter)
  void serialize( serialization::Archiver& );

  ftorder_filter( QueryLoc const& );

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  std::ostream& put( std::ostream& ) const;
};


class ftscope_filter : public ftpos_filter {
public:
  SERIALIZABLE_CLASS(ftscope_filter)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftscope_filter,ftpos_filter)
  void serialize( serialization::Archiver& );

  ftscope_filter( QueryLoc const&, ft_scope::type, ft_big_unit::type );

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  ft_scope::type get_scope() const { return scope_; }
  ft_big_unit::type get_unit() const { return unit_; }
  std::ostream& put( std::ostream& ) const;

private:
  ft_scope::type scope_;
  ft_big_unit::type unit_;
};


class ftwindow_filter : public ftpos_filter {
public:
  SERIALIZABLE_CLASS(ftwindow_filter)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftwindow_filter,ftpos_filter)
  void serialize( serialization::Archiver& );

  ftwindow_filter( QueryLoc const&, expr* const&, ft_unit::type );

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  ft_unit::type get_unit() const { return unit_; }
  expr** get_window_expr() { return &window_expr_; }
  PlanIter_t get_window_iter() const { return window_iter_; }
  std::ostream& put( std::ostream& ) const;

  void set_window_iter( PlanIter_t const &iter ) {
    window_iter_ = iter;
  }

private:
  expr* window_expr_;
  ft_unit::type unit_;
  PlanIter_t window_iter_;
};

////////// Boolean operators //////////////////////////////////////////////////

/**
 * This is an abstract base class for nodes that have a list of child nodes,
 * currently ftand, ftmild_not, and ftor.
 */
class ftnode_list : public ftnode {
public:
  SERIALIZABLE_ABSTRACT_CLASS(ftnode_list)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftnode_list,ftnode)
  void serialize( serialization::Archiver& );

  typedef std::list<ftnode*> ftnode_list_t;

  ~ftnode_list();

  ftnode_list_t& get_node_list() { return list_; }
  ftnode_list_t const& get_node_list() const { return list_; }

protected:
  ftnode_list( QueryLoc const &loc, ftnode_list_t& );

private:
  ftnode_list_t list_;
};

class ftand : public ftnode_list {
public:
  SERIALIZABLE_CLASS(ftand)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftand,ftnode_list)
  void serialize( serialization::Archiver& );

  ftand( QueryLoc const&, ftnode_list_t& );

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  std::ostream& put( std::ostream& ) const;
};


class ftmild_not : public ftnode_list {
public:
  SERIALIZABLE_CLASS(ftmild_not)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftmild_not,ftnode_list)
  void serialize( serialization::Archiver& );

  ftmild_not( QueryLoc const&, ftnode_list_t& );

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  std::ostream& put( std::ostream& ) const;
};


class ftor : public ftnode_list {
public:
  SERIALIZABLE_CLASS(ftor)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftor,ftnode_list)
  void serialize( serialization::Archiver& );

  ftor( QueryLoc const&, ftnode_list_t& );

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  std::ostream& put( std::ostream& ) const;
};


class ftunary_not : public ftnode {
public:
  SERIALIZABLE_CLASS(ftunary_not)
  SERIALIZABLE_CLASS_CONSTRUCTOR2_NULL_PARAM1(ftunary_not,ftnode,subnode_)
  void serialize( serialization::Archiver& );

  ftunary_not( QueryLoc const&, ftnode *subnode );
  ~ftunary_not();

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  ftnode const* get_subnode() const { return subnode_; }
  std::ostream& put( std::ostream& ) const;

private:
  ftnode *subnode_;
};

////////// Miscellaneous //////////////////////////////////////////////////////

class ftrange : public ftnode {
public:
  SERIALIZABLE_CLASS(ftrange)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftrange,ftnode)
  void serialize( serialization::Archiver& );

  ftrange(
    QueryLoc const&,
    ft_range_mode::type,
    expr* const &expr1,
    expr* expr2 = 0
  );

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  expr** get_expr1() { return &expr1_; }
  expr** get_expr2() { return &expr2_; }
  PlanIter_t get_plan_iter1() const { return iter1_; }
  PlanIter_t get_plan_iter2() const { return iter2_; }
  ft_range_mode::type get_mode() const { return mode_; }
  std::ostream& put( std::ostream& ) const;

  void set_plan_iters( PlanIter_t const &iter1, PlanIter_t const &iter2 ) {
    iter1_ = iter1;
    iter2_ = iter2;
  }

private:
  ft_range_mode::type mode_;
  expr* expr1_;
  expr* expr2_;
  PlanIter_t iter1_;
  PlanIter_t iter2_;
};


class ftwords : public ftnode {
public:
  SERIALIZABLE_CLASS(ftwords)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftwords,ftnode)
  void serialize( serialization::Archiver& );

  ftwords(
    QueryLoc const&,
    expr* const&,
    ft_anyall_mode::type = ft_anyall_mode::DEFAULT
  );

  ft_visit_result::type accept( ftnode_visitor& );
  ftnode_t clone( expr::substitution_t& ) const;
  expr** get_value_expr() { return &value_expr_; }
  PlanIter_t get_value_iter() const { return value_iter_; }
  ft_anyall_mode::type get_mode() const { return mode_; }
  std::ostream& put( std::ostream& ) const;

  void set_plan_iter( PlanIter_t const &iter ) {
    value_iter_ = iter;
  }

private:
  expr* value_expr_;
  ft_anyall_mode::type mode_;
  PlanIter_t value_iter_;
};

} /* namespace zorba */

#endif /* ZORBA_FTNODE_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
