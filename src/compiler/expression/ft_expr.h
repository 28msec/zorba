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

#ifndef ZORBA_FTEXPR_H
#define ZORBA_FTEXPR_H

#include "compiler/expression/expr_base.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/parser/ft_types.h"
#include "compiler/parsetree/parsenodes.h"

namespace zorba {

class ftexpr;

///////////////////////////////////////////////////////////////////////////////

class ft_expr : public expr {
public:
  SERIALIZABLE_ABSTRACT_CLASS(ft_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ft_expr,expr)
  void serialize( serialization::Archiver &ar )
  {
    serialize_baseclass( ar, (expr*)this );
  }

public:
  ~ft_expr();

  virtual std::ostream& put( std::ostream& ) const;

protected:
  ft_expr( short sctx, const QueryLoc& );
};

class ftcontains_expr : public ft_expr {
public:
  SERIALIZABLE_ABSTRACT_CLASS(ftcontains_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftcontains_expr,ft_expr)
  void serialize( serialization::Archiver& );

public:
  ftcontains_expr(
    short sctx,
    QueryLoc const&,
    range_expr_t range,
    ftexpr *ftselection,
    union_expr_t ftignore
  );

  void compute_scripting_kind() const {
    // TODO
  }

  expr_kind_t get_expr_kind() const {
    return ft_expr_kind;
  }

  range_expr_t get_range() const { return range_; }
  ftexpr const* get_ftselection() const { return ftselection_; }
  union_expr_t get_ignore() const { return ftignore_; }

  void next_iter( expr_iterator_data& );
  //void accept (expr_visitor&);

  std::ostream& put(std::ostream&) const;

protected:
  range_expr_t range_;
  ftexpr *ftselection_;
  union_expr_t ftignore_;
};

///////////////////////////////////////////////////////////////////////////////

class ftand_expr;
class ftcase_option_expr;
class ftcontent_expr;
class ftdiacritics_option_expr;
class ftdistance_expr;
class ftextension_option_expr;
class ftextension_selection_expr;
class ftlanguage_option_expr;
class ftmatch_option_expr;
class ftmild_not_expr;
class ftorder_expr;
class ftor_expr;
class ftpos_filter_expr;
class ftprimary;
class ftprimary_with_options_expr;
class ftrange_expr;
class ftscope_expr;
class ftselection_expr;
class ftstem_option_expr;
class ftstop_word_option_expr;
class ftstop_words;
class ftthesaurus_id_expr;
class ftthesaurus_option_expr;
class ftunary_not_expr;
class ftwild_card_option_expr;
class ftwindow_expr;
class ftwords_expr;
class ftwords_times_expr;

class ftexpr_visitor {
public:
  enum begin_result {
    br_continue,
    br_no_children  = 0x01,
    br_no_end       = 0x02,
  };

  virtual ~ftexpr_visitor();

# define DECL_FTEXPR_VISITOR_VISIT_MEM_FNS(C) \
  virtual begin_result begin_visit( C& ) = 0; \
  virtual void end_visit( C& ) = 0

  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftand_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftcase_option_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftcontent_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftdiacritics_option_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftdistance_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftextension_option_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftextension_selection_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftlanguage_option_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftmatch_option_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftmild_not_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftorder_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftor_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftprimary_with_options_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftrange_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftscope_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftselection_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftstem_option_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftstop_word_option_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftstop_words );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftthesaurus_id_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftthesaurus_option_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftunary_not_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftwild_card_option_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftwindow_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftwords_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftwords_times_expr );

# undef DECL_FTEXPR_VISITOR_VISIT_MEM_FNS
};

/**
 * Base class for full-text expression classes.
 */
class ftexpr : public serialization::SerializeBaseClass {
public:
  SERIALIZABLE_ABSTRACT_CLASS(ftexpr)
  void serialize( serialization::Archiver& );

  virtual ~ftexpr();

  QueryLoc const& get_loc() const { return loc_; }

protected:
  ftexpr( QueryLoc const &loc ) : loc_( loc ) {
  }

private:
  QueryLoc loc_;
};

////////// FTMatchOptions /////////////////////////////////////////////////////

class ftmatch_option_expr : public ftexpr {
public:
  SERIALIZABLE_ABSTRACT_CLASS(ftmatch_option_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftmatch_option_expr,ftexpr)
  void serialize( serialization::Archiver& );
  
protected:
  ftmatch_option_expr( QueryLoc const &loc ) : ftexpr( loc ) { }
};

class ftcase_option_expr : public ftmatch_option_expr {
public:
  SERIALIZABLE_CLASS(ftcase_option_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftcase_option_expr,ftmatch_option_expr)
  void serialize( serialization::Archiver& );

  ftcase_option_expr(
    QueryLoc const&,
    ft_case_mode::type = ft_case_mode::DEFAULT
  );

  ft_case_mode::type get_mode() const { return mode_; }

private:
  ft_case_mode::type mode_;
};

class ftdiacritics_option_expr : public ftmatch_option_expr {
public:
  SERIALIZABLE_CLASS(ftdiacritics_option_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftdiacritics_option_expr,ftmatch_option_expr)
  void serialize( serialization::Archiver& );

  ftdiacritics_option_expr(
    QueryLoc const&,
    ft_diacritics_mode::type = ft_diacritics_mode::DEFAULT
  );

  ft_diacritics_mode::type get_mode() const { return mode_; }

private:
  ft_diacritics_mode::type mode_;
};

class ftextension_option_expr : public ftmatch_option_expr {
public:
  SERIALIZABLE_CLASS(ftextension_option_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftextension_option_expr,ftmatch_option_expr)
  void serialize( serialization::Archiver& );

  ftextension_option_expr(
    QueryLoc const&,
    rchandle<QName>,
    std::string const &val
  );

  rchandle<QName> get_qname() const { return qname_; }
  std::string get_val() const { return val_; }

private:
  rchandle<QName> qname_;
  std::string val_;
};

class ftlanguage_option_expr : public ftmatch_option_expr {
public:
  SERIALIZABLE_CLASS(ftlanguage_option_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftlanguage_option_expr,ftmatch_option_expr)
  void serialize( serialization::Archiver& );

  ftlanguage_option_expr(
    QueryLoc const&,
    std::string const &language
  );

  std::string get_language() const { return language_; }

private:
  std::string language_;
};

class ftstem_option_expr : public ftmatch_option_expr {
public:
  SERIALIZABLE_CLASS(ftstem_option_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftstem_option_expr,ftmatch_option_expr)
  void serialize( serialization::Archiver& );

  ftstem_option_expr(
    QueryLoc const&,
    ft_stem_mode::type = ft_stem_mode::DEFAULT
  );

  ft_stem_mode::type get_mode() const { return mode_; }

private:
  ft_stem_mode::type mode_;
};

class ftstop_words_expr : public ftexpr {
public:
  SERIALIZABLE_CLASS(ftstop_words_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftstop_words_expr,ftexpr)
  void serialize( serialization::Archiver& );

  typedef std::list<std::string> list_t;

  ftstop_words_expr(
    QueryLoc const&,
    std::string const &uri,
    list_t const&,
    ft_stop_words_unex::type = ft_stop_words_unex::union_
  );

  std::string const& get_uri() const { return uri_; }
  list_t const& get_list() const { return list_; }
  ft_stop_words_unex::type get_mode() const { return mode_; }

private:
  std::string uri_;
  list_t list_;
  ft_stop_words_unex::type mode_;
};

class ftstop_word_option_expr : public ftmatch_option_expr {
public:
  SERIALIZABLE_CLASS(ftstop_word_option_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftstop_word_option_expr,ftmatch_option_expr)
  void serialize( serialization::Archiver& );

  typedef std::list<ftstop_words_expr> stop_word_list_t;

  ftstop_word_option_expr(
    QueryLoc const&,
    ft_stop_words_mode::type = ft_stop_words_mode::DEFAULT
  );

  ftstop_word_option_expr(
    QueryLoc const&,
    stop_word_list_t&,
    ft_stop_words_mode::type = ft_stop_words_mode::DEFAULT
  );

  ft_stop_words_mode::type get_mode() const { return mode_; }
  stop_word_list_t const& get_stop_words() const { return stop_words_; }

private:
  stop_word_list_t stop_words_;
  ft_stop_words_mode::type mode_;
};

class ftthesaurus_id_expr : public ftexpr {
public:
  SERIALIZABLE_CLASS(ftthesaurus_id_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftthesaurus_id_expr,ftexpr)
  void serialize( serialization::Archiver& );

  ftthesaurus_id_expr(
    QueryLoc const&,
    std::string const &uri,
    std::string const &relationship,
    ftrange_expr *levels
  );

  std::string const& get_uri() const { return uri_; }
  std::string const& get_relationship() const { return relationship_; }
  ftrange_expr const* get_levels() const { return levels_; }

private:
  std::string uri_;
  std::string relationship_;
  ftrange_expr *levels_;
};

class ftthesaurus_option_expr : public ftmatch_option_expr {
public:
  SERIALIZABLE_CLASS(ftthesaurus_option_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftthesaurus_option_expr,ftmatch_option_expr)
  void serialize( serialization::Archiver& );

  typedef std::list<ftthesaurus_id_expr*> thesaurus_id_list_t;

  ftthesaurus_option_expr(
    QueryLoc const&,
    thesaurus_id_list_t&,
    bool includes_default,
    bool no_thesaurus
  );
  ~ftthesaurus_option_expr();

  thesaurus_id_list_t const& get_thesaurus_id_list() const
    { return thesaurus_id_list_; }

  bool includes_default() const { return includes_default_; }
  bool no_thesaurus() const { return no_thesaurus_; }

private:
  thesaurus_id_list_t thesaurus_id_list_;
  bool includes_default_;
  bool no_thesaurus_;
};

class ftwild_card_option_expr : public ftmatch_option_expr {
public:
  SERIALIZABLE_CLASS(ftwild_card_option_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftwild_card_option_expr,ftmatch_option_expr)
  void serialize( serialization::Archiver& );

  ftwild_card_option_expr(
    QueryLoc const&,
    ft_wild_card_mode::type = ft_wild_card_mode::DEFAULT
  );

  ft_wild_card_mode::type get_mode() const { return mode_; }

private:
  ft_wild_card_mode::type mode_;
};

////////// FTPrimary //////////////////////////////////////////////////////////

class ftprimary_expr : public ftexpr {
public:
  SERIALIZABLE_ABSTRACT_CLASS(ftprimary_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftprimary_expr,ftexpr)
  void serialize( serialization::Archiver &ar ) {
    serialize_baseclass( ar, (ftexpr*)this );
  }

protected:
  ftprimary_expr( QueryLoc const &loc ) : ftexpr( loc ) { }
};

class ftextension_selection_expr : public ftprimary_expr {
public:
  SERIALIZABLE_CLASS(ftextension_selection_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftextension_selection_expr,ftprimary_expr)
  void serialize( serialization::Archiver& );

  ftextension_selection_expr(
    QueryLoc const&,
    /* TODO: pragma_list, */
    ftselection_expr*
  );

  ftselection_expr const* get_ftselection() const { return ftselection_; }

private:
  ftselection_expr *ftselection_;
};

class ftselection_expr : public ftprimary_expr {
public:
  SERIALIZABLE_CLASS(ftselection_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftselection_expr,ftprimary_expr)
  void serialize( serialization::Archiver& );

  typedef std::list<ftpos_filter_expr*> ftpos_filter_list_t;

  ftselection_expr(
    QueryLoc const&,
    ftexpr *ftor,
    ftpos_filter_list_t&
  );
  ~ftselection_expr();

  ftpos_filter_list_t const& get_ftpos_filter_list() const { return list_; }
  ftexpr const* get_ftor() const { return ftor_; };

private:
  ftpos_filter_list_t list_;
  ftexpr *ftor_;
};

class ftwords_times_expr : public ftprimary_expr {
public:
  SERIALIZABLE_CLASS(ftwords_times_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftwords_times_expr,ftprimary_expr)
  void serialize( serialization::Archiver& );

  ftwords_times_expr(
    QueryLoc const&,
    ftwords_expr*,
    ftrange_expr* = NULL
  );
  ~ftwords_times_expr();

  ftwords_expr const* get_words() const { return ftwords_; }
  ftrange_expr const* get_times() const { return fttimes_; }

private:
  ftwords_expr *ftwords_;
  ftrange_expr *fttimes_;
};

//////// FTPosFilter //////////////////////////////////////////////////////////

class ftpos_filter_expr : public ftexpr {
public:
  SERIALIZABLE_ABSTRACT_CLASS(ftpos_filter_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftpos_filter_expr,ftexpr)
  void serialize( serialization::Archiver &ar ) {
    serialize_baseclass( ar, (ftexpr*)this );
  }

protected:
  ftpos_filter_expr( QueryLoc const &loc ) :
    ftexpr( loc )
  {
  }
};

class ftcontent_expr : public ftpos_filter_expr {
public:
  SERIALIZABLE_CLASS(ftcontent_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftcontent_expr,ftpos_filter_expr)
  void serialize( serialization::Archiver &ar ) {
    serialize_baseclass( ar, (ftpos_filter_expr*)this );
  }

  ftcontent_expr( QueryLoc const&, ft_content_mode::type );

  ft_content_mode::type get_mode() const { return mode_; }

private:
  ft_content_mode::type mode_;
};

class ftdistance_expr : public ftpos_filter_expr {
public:
  SERIALIZABLE_CLASS(ftdistance_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftdistance_expr,ftpos_filter_expr)
  void serialize( serialization::Archiver& );

  ftdistance_expr( QueryLoc const&, ftrange_expr*, ft_unit::type );

  ftrange_expr const* get_range() const { return range_; }
  ft_unit::type get_unit() const { return unit_; }

private:
  ftrange_expr *range_;
  ft_unit::type unit_;
};

class ftorder_expr : public ftpos_filter_expr {
public:
  SERIALIZABLE_CLASS(ftorder_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftorder_expr,ftpos_filter_expr)
  void serialize( serialization::Archiver& );

  ftorder_expr( QueryLoc const& );
};

class ftscope_expr : public ftpos_filter_expr {
public:
  SERIALIZABLE_CLASS(ftscope_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftscope_expr,ftpos_filter_expr)
  void serialize( serialization::Archiver& );

  ftscope_expr( QueryLoc const&, ft_scope::type, ft_big_unit::type );

private:
  ft_scope::type scope_;
  ft_big_unit::type unit_;
};

class ftwindow_expr : public ftpos_filter_expr {
public:
  SERIALIZABLE_CLASS(ftwindow_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftwindow_expr,ftpos_filter_expr)
  void serialize( serialization::Archiver& );

  ftwindow_expr( QueryLoc const&, additive_expr_t, ft_unit::type );

  ft_unit::type get_unit() const { return unit_; }
  additive_expr_t get_window() const { return window_; }

private:
  additive_expr_t window_;
  ft_unit::type unit_;
};

///////////////////////////////////////////////////////////////////////////////

class ftand_expr : public ftexpr {
public:
  SERIALIZABLE_CLASS(ftand_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftand_expr,ftexpr)
  void serialize( serialization::Archiver& );

  typedef std::list<ftexpr*> ftexpr_list_t;

  ftand_expr( QueryLoc const&, ftexpr_list_t& );
  ~ftand_expr();

private:
  ftexpr_list_t list_;
};

class ftmild_not_expr : public ftexpr {
public:
  SERIALIZABLE_CLASS(ftmild_not_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftmild_not_expr,ftexpr)
  void serialize( serialization::Archiver& );

  typedef std::list<ftexpr*> ftexpr_list_t;

  ftmild_not_expr( QueryLoc const &loc, ftexpr_list_t &r ) : ftexpr( loc ) {
    list_.swap( r );
  }

  ~ftmild_not_expr();

private:
  ftexpr_list_t list_;
};

class ftor_expr : public ftexpr {
public:
  SERIALIZABLE_CLASS(ftor_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftor_expr,ftexpr)
  void serialize( serialization::Archiver& );

  typedef std::list<ftexpr*> ftexpr_list_t;

  ftor_expr( QueryLoc const &loc, ftexpr_list_t &r ) : ftexpr( loc ) {
    list_.swap( r );
  }

  ~ftor_expr();

private:
  ftexpr_list_t list_;
};

class ftprimary_with_options_expr : public ftexpr {
public:
  SERIALIZABLE_CLASS(ftprimary_with_options_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftprimary_with_options_expr,ftexpr)
  void serialize( serialization::Archiver& );

  ftprimary_with_options_expr( QueryLoc const& );
  ~ftprimary_with_options_expr();

  void set_case_option( ftcase_option_expr *e ) {
    delete case_option_;
    case_option_ = e;
  }

  void set_diacritics( ftdiacritics_option_expr *e ) {
    delete diacritics_option_;
    diacritics_option_ = e;
  }

  void set_extension_option( ftextension_option_expr *e ) {
    delete extension_option_;
    extension_option_ = e;
  }

  void set_language( ftlanguage_option_expr *e ) {
    delete language_option_;
    language_option_ = e;
  }

  void set_primary( ftexpr *e ) {
    delete primary_;
    primary_ = e;
  }

  void set_stem_option( ftstem_option_expr *e ) {
    delete stem_option_;
    stem_option_ = e;
  }

  void set_stop_word_option( ftstop_word_option_expr *e ) {
    delete stop_word_option_;
    stop_word_option_ = e;
  }

  void set_thesaurus_option( ftthesaurus_option_expr *e ) {
    delete thesaurus_option_;
    thesaurus_option_ = e;
  }

  void set_weight( exprnode *e ) {
    delete weight_;
    weight_ = e;
  }

  void set_wild_card( ftwild_card_option_expr *e ) {
    delete wild_card_option_;
    wild_card_option_ = e;
  }

private:
  ftcase_option_expr *case_option_;
  ftdiacritics_option_expr *diacritics_option_;
  ftextension_option_expr *extension_option_;
  ftlanguage_option_expr *language_option_;
  ftexpr *primary_;
  ftstem_option_expr *stem_option_;
  ftstop_word_option_expr *stop_word_option_;
  ftthesaurus_option_expr *thesaurus_option_;
  exprnode *weight_;
  ftwild_card_option_expr *wild_card_option_;
};

class ftrange_expr : public ftexpr {
public:
  SERIALIZABLE_CLASS(ftrange_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftrange_expr,ftexpr)
  void serialize( serialization::Archiver& );

  ftrange_expr(
    QueryLoc const&,
    ft_range_mode::type,
    additive_expr_t expr1,
    additive_expr_t expr2 = NULL
  );

  additive_expr_t get_expr1() const { return expr1_; }
  additive_expr_t get_expr2() const { return expr2_; }
  ft_range_mode::type get_mode() const { return mode_; }

private:
  ft_range_mode::type mode_;
  additive_expr_t expr1_;
  additive_expr_t expr2_;
};

class ftunary_not_expr : public ftexpr {
public:
  SERIALIZABLE_CLASS(ftunary_not_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftunary_not_expr,ftexpr)
  void serialize( serialization::Archiver& );

  ftunary_not_expr( QueryLoc const&, ftexpr *subexpr );
  ~ftunary_not_expr();

  ftexpr const* get_subexpr() const { return subexpr_; }

private:
  ftexpr *subexpr_;
};

class ftwords_expr : public ftexpr {
public:
  SERIALIZABLE_CLASS(ftwords_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ftwords_expr,ftexpr)
  void serialize( serialization::Archiver& );

  ftwords_expr(
    QueryLoc const&,
    expr_t,
    ft_anyall_mode::type = ft_anyall_mode::DEFAULT
  );

  expr_t get_expr() const { return expr_; }
  ft_anyall_mode::type get_mode() const { return mode_; }

  //void set_range( fo_expr *range );
private:
  expr_t expr_;
  ft_anyall_mode::type mode_;
};

} /* namespace zorba */

#endif /* ZORBA_FTEXPR_H */
/* vim:set et sw=2 ts=2: */
