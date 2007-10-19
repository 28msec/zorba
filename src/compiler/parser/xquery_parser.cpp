/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++

   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


#include "xquery_parser.hpp"

/* User implementation prologue.  */
#line 122 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"


/* Line 317 of lalr1.cc.  */
#line 46 "/Users/mbrantner/misc/code/vanilla/xquery/build/src/compiler/parser/xquery_parser.cpp"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG							\
  for (bool yydebugcond_ = yydebug_; yydebugcond_; yydebugcond_ = false)	\
    (*yycdebug_)

/* Enable debugging if requested.  */
#if YYDEBUG

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab

namespace yy
{
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  xquery_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  xquery_parser::xquery_parser (xquery_driver& driver_yyarg)
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
      driver (driver_yyarg)
  {
  }

  xquery_parser::~xquery_parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  xquery_parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  xquery_parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif /* ! YYDEBUG */

  void
  xquery_parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  xquery_parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

  std::ostream&
  xquery_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  xquery_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  xquery_parser::debug_level_type
  xquery_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  xquery_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }


  int
  xquery_parser::parse ()
  {
    /// Look-ahead and look-ahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the look-ahead.
    semantic_type yylval;
    /// Location of the look-ahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    #line 83 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &driver.file;
}
  /* Line 547 of yacc.c.  */
#line 282 "/Users/mbrantner/misc/code/vanilla/xquery/build/src/compiler/parser/xquery_parser.cpp"
    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;
    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without look-ahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a look-ahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc, driver);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Accept?  */
    if (yyn == yyfinal_)
      goto yyacceptlab;

    /* Shift the look-ahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted unless it is eof.  */
    if (yychar != yyeof_)
      yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:
#line 721 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Module [main]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr((yyval.node));
		;}
    break;

  case 3:
#line 727 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Module [version.main]\n";
		;}
    break;

  case 4:
#line 731 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Module [library]\n";
		;}
    break;

  case 5:
#line 735 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Module [version.library]\n";
		;}
    break;

  case 6:
#line 745 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VersionDecl [version]\n";
		;}
    break;

  case 7:
#line 749 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VersionDecl [version.encoding]\n";
		;}
    break;

  case 8:
#line 759 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "MainModule [prolog.querybody]\n";
			(yyval.node) = new MainModule((yyloc),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)));
		;}
    break;

  case 9:
#line 767 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "MainModule [querybody]\n";
			(yyval.node) = new MainModule((yyloc),
								NULL,
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 10:
#line 780 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "LibraryModule [ ]\n";
			(yyval.node) = new LibraryModule((yyloc),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 11:
#line 793 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ModuleDecl [ ]\n";
			(yyval.node) = new ModuleDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)), 
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (4)].sval)));
		;}
    break;

  case 12:
#line 806 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Prolog [sind]\n";
			(yyval.node) = new Prolog((yyloc),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 13:
#line 813 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Prolog [vfo]\n";
			(yyval.node) = new Prolog((yyloc),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 14:
#line 820 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Prolog [sind.vfo]\n";
			(yyval.node) = new Prolog((yyloc),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 15:
#line 833 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SIND_DeclList [single]\n";
			SIND_DeclList* sindList_p = new SIND_DeclList((yyloc));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 16:
#line 840 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SIND_DeclList [list]\n";
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 17:
#line 855 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VFO_DeclList [single]\n";
			VFO_DeclList* vfoList_p = new VFO_DeclList((yyloc));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 18:
#line 862 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VFO_DeclList [list]\n";
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 19:
#line 877 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SIND_Decl [setter]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 882 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SIND_Decl [import]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 887 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SIND_Decl [namespace]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 892 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SIND_Decl [default namespace]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 902 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VFO_Decl [var]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 907 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VFO_Decl [function]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 912 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VFO_Decl [option]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 919 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VFO_Decl [ftoption]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 930 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Setter [boundary space]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 935 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Setter [default collation]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 940 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Setter [base uri]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 945 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Setter [construction]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 950 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Setter [ordering mode]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 955 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Setter [empty order]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 960 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Setter [copy namespaces]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 967 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Setter [revalidation]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 978 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Import [schema]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 983 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Import [module]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 999 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NamespaceDecl [ ]\n";
			(yyval.node) = new NamespaceDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								driver.symtab.get((off_t)44));
		;}
    break;

  case 38:
#line 1012 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "BoundarySpaceDecl [preserve]\n";
			(yyval.node) = new BoundarySpaceDecl((yyloc),
								static_context::preserve_space);
		;}
    break;

  case 39:
#line 1018 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "BoundarySpaceDecl [strip]\n";
			(yyval.node) = new BoundarySpaceDecl((yyloc),
								static_context::strip_space);
		;}
    break;

  case 40:
#line 1030 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DefaultNamespaceDecl [element]\n";
			(yyval.node) = new DefaultNamespaceDecl((yyloc),
								ns_element_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 41:
#line 1037 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DefaultNamespaceDecl [function]\n";
			(yyval.node) = new DefaultNamespaceDecl((yyloc),
								ns_function_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 42:
#line 1050 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OptionDecl [ ]\n";
			(yyval.node) = new OptionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 43:
#line 1064 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTOptionDecl [ ]\n";
			(yyval.node) = new FTOptionDecl((yyloc),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 44:
#line 1076 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderingDecl [ordered]\n";
			(yyval.node) = new OrderingModeDecl((yyloc),
								dynamic_context::ordered);
		;}
    break;

  case 45:
#line 1082 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderingDecl [unordered]\n";
			(yyval.node) = new OrderingModeDecl((yyloc),
								dynamic_context::unordered);
		;}
    break;

  case 46:
#line 1095 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "EmptyOrderDecl [empty greatest]\n";
			(yyval.node) = new EmptyOrderDecl((yyloc),
								static_context::empty_greatest);
		;}
    break;

  case 47:
#line 1101 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "EmptyOrderDecl [empty least]\n";
			(yyval.node) = new EmptyOrderDecl((yyloc),
								static_context::empty_least);
		;}
    break;

  case 48:
#line 1113 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CopyNamespacesDecl [ ]\n";
			(yyval.node) = new CopyNamespacesDecl((yyloc),
								static_context::preserve_ns,
								static_context::inherit_ns);
		;}
    break;

  case 49:
#line 1120 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CopyNamespacesDecl [ ]\n";
			(yyval.node) = new CopyNamespacesDecl((yyloc),
								static_context::preserve_ns,
								static_context::no_inherit_ns);
		;}
    break;

  case 50:
#line 1127 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CopyNamespacesDecl [ ]\n";
			(yyval.node) = new CopyNamespacesDecl((yyloc),
								static_context::no_preserve_ns,
								static_context::inherit_ns);
		;}
    break;

  case 51:
#line 1134 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CopyNamespacesDecl [ ]\n";
			(yyval.node) = new CopyNamespacesDecl((yyloc),
								static_context::no_preserve_ns,
								static_context::no_inherit_ns);
		;}
    break;

  case 52:
#line 1154 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DefaultCollationMode [ ]\n";
			(yyval.node) = new DefaultCollationDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 53:
#line 1166 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "BaseURIDecl [ ]\n";
			(yyval.node) = new BaseURIDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 54:
#line 1178 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SchemaImport [uri]\n";
			(yyval.node) = new SchemaImport((yyloc),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 55:
#line 1186 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SchemaImport [prefix.uri]\n";
			(yyval.node) = new SchemaImport((yyloc),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(3) - (2)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 56:
#line 1194 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SchemaImport [uri.urilist]\n";
			(yyval.node) = new SchemaImport((yyloc),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 57:
#line 1202 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SchemaImport [prefix.uri.aturi]\n";
			(yyval.node) = new SchemaImport((yyloc),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(5) - (2)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 58:
#line 1216 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "URILiteralList [single]\n";
			URILiteralList* uri_list_p = new URILiteralList((yyloc));
			uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 59:
#line 1223 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "URILiteralList [list]\n";
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 60:
#line 1239 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SchemaPrefix [namespace]\n";
			(yyval.node) = new SchemaPrefix((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1244 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SchemaPrefix [default element]\n";
			(yyval.node) = new SchemaPrefix((yyloc), true);
		;}
    break;

  case 62:
#line 1255 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ModuleImport [uri]\n";
			(yyval.node) = new ModuleImport((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 63:
#line 1262 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ModuleImport [namespace.uri]\n";
			(yyval.node) = new ModuleImport((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)),
								NULL);
		;}
    break;

  case 64:
#line 1270 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ModuleImport [uri.at_uri.list]\n";
			(yyval.node) = new ModuleImport((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 65:
#line 1277 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ModuleImport [namespace.uri.at_uri.list]\n";
			(yyval.node) = new ModuleImport((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (5)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(7) - (7)].node)));
		;}
    break;

  case 66:
#line 1292 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarDecl [expr]\n";
			(yyval.node) = new VarDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 67:
#line 1300 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarDecl [external]\n";
			(yyval.node) = new VarDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								NULL,
								NULL);
		;}
    break;

  case 68:
#line 1308 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarDecl [type.expr]\n";
			(yyval.node) = new VarDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 69:
#line 1316 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarDecl [type.external]\n";
			(yyval.node) = new VarDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (3)].node)),
								NULL);
		;}
    break;

  case 70:
#line 1330 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ConstructionDecl [preserve]\n";
			(yyval.node) = new ConstructionDecl((yyloc),
								static_context::cons_preserve);
		;}
    break;

  case 71:
#line 1336 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ConstructionDecl [strip]\n";
			(yyval.node) = new ConstructionDecl((yyloc),
								static_context::cons_strip);
		;}
    break;

  case 72:
#line 1348 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionDecl [external]\n";
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,NULL,NULL,
								fn_extern);
		;}
    break;

  case 73:
#line 1356 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionDecl [expr]\n";
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(4) - (4)].expr)),
								fn_read);
		;}
    break;

  case 74:
#line 1365 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionDecl [paramlist.external]\n";
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,NULL,
								fn_extern);
		;}
    break;

  case 75:
#line 1374 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionDecl [paramlist.expr]\n";
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(5) - (5)].expr)),
								fn_read);
		;}
    break;

  case 76:
#line 1384 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionDecl [as_type.external]\n";
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (4)].node)),
								NULL,
								fn_extern);
		;}
    break;

  case 77:
#line 1394 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionDecl [as_type.expr]\n";
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (4)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(5) - (5)].expr)),
								fn_read);
		;}
    break;

  case 78:
#line 1404 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionDecl [paramlist.as_type.external]\n";
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)),
								NULL,
								fn_extern);
		;}
    break;

  case 79:
#line 1414 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionDecl [paramlist.as_type.expr]\n";
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(6) - (6)].expr)),
								fn_read);
		;}
    break;

  case 80:
#line 1424 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionDecl [(update) external]\n";
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,NULL,NULL,
								fn_extern_update);
		;}
    break;

  case 81:
#line 1432 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionDecl [(update) expr]\n";
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(4) - (4)].expr)),
								fn_update);
		;}
    break;

  case 82:
#line 1441 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionDecl [(update) paramlist.external]\n";
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,NULL,
								fn_extern_update);
		;}
    break;

  case 83:
#line 1450 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionDecl [(update) paramlist.expr]\n";
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(5) - (5)].expr)),
								fn_update);
		;}
    break;

  case 84:
#line 1460 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionDecl [(update) as_type.external]\n";
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (4)].node)),
								NULL,
								fn_extern_update);
		;}
    break;

  case 85:
#line 1470 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionDecl [(update) as_type.expr]\n";
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (4)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(5) - (5)].expr)),
								fn_update);
		;}
    break;

  case 86:
#line 1480 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionDecl [(update) paramlist.as_type.external]\n";
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)),
								NULL,
								fn_extern_update);
		;}
    break;

  case 87:
#line 1490 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionDecl [(update) paramlist.as_type.expr]\n";
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(6) - (6)].expr)),
								fn_update);
		;}
    break;

  case 88:
#line 1506 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ParamList [single]\n";
			ParamList* plist_p = new ParamList((yyloc));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 89:
#line 1515 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ParamList [list]\n";
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 90:
#line 1530 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Param [varname]\n";
			(yyval.node) = new Param((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 91:
#line 1537 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Param [varname.type]\n";
			(yyval.node) = new Param((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 92:
#line 1550 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "EnclosedExpr [ ]\n";
			(yyval.expr) = new EnclosedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1562 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QueryBody [expr]\n";
			(yyval.expr) = new QueryBody((yyloc),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 94:
#line 1574 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Expr [single]\n";
			Expr* expr_p = new Expr((yyloc));
			expr_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 95:
#line 1581 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Expr [expr.single]\n";
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p) expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
		;}
    break;

  case 96:
#line 1594 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [FLWORExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 97:
#line 1599 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [QuantifiedExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1604 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [TypeswitchExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1609 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [IfExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1614 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [OrExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1621 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [InsertExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1626 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [DeleteExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1631 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [RenameExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1636 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [ReplaceExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1641 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [TransformExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1652 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FLWORExpr [return]\n";
			(yyval.expr) = new FLWORExpr((yyloc),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 107:
#line 1660 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FLWORExpr [where.return]\n";
			cout << "ExprSingle typeid = " << typeid(*(yysemantic_stack_[(4) - (4)].expr)).name() << endl;
			(yyval.expr) = new FLWORExpr((yyloc),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 108:
#line 1670 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FLWORExpr [orderby.return]\n";
			(yyval.expr) = new FLWORExpr((yyloc),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								NULL,
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 109:
#line 1679 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FLWORExpr [where.orderby.return]\n";
			(yyval.expr) = new FLWORExpr((yyloc),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(5) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 110:
#line 1694 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForLetClauseList [single]\n";
			ForLetClauseList* flc_list_p = new ForLetClauseList((yyloc));
			flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = flc_list_p;
		;}
    break;

  case 111:
#line 1701 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForLetClauseList [list]\n";
			ForLetClauseList* flc_list_p = dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(2) - (1)].node));
			if (flc_list_p) flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 112:
#line 1714 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForLetClause [for]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 113:
#line 1719 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForLetClause [let]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 114:
#line 1730 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForClause [ ]\n";
			(yyval.node) = new ForClause((yyloc),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 115:
#line 1742 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarInDeclList [single]\n";
			VarInDeclList* vardecl_list_p = new VarInDeclList((yyloc));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 116:
#line 1749 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarInDeclList [list]\n";
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 117:
#line 1764 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarInDecl [in]\n";
			(yyval.node) = new VarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 118:
#line 1772 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarInDecl [type.in]\n";
			(yyval.node) = new VarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 119:
#line 1781 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarInDecl [posvar.in]\n";
			(yyval.node) = new VarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 120:
#line 1791 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarInDecl [type.posvar.in]\n";
			(yyval.node) = new VarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 121:
#line 1802 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarInDecl [scorevar.in]\n";
			(yyval.node) = new VarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 122:
#line 1811 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarInDecl [type.scorevar.in]\n";
			(yyval.node) = new VarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 123:
#line 1821 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarInDecl [posvar.scorevar.in]\n";
			(yyval.node) = new VarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 124:
#line 1831 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarInDecl [type.posvar.scorevar.in]\n";
			(yyval.node) = new VarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 125:
#line 1847 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PositionalVar [ ]\n";
			(yyval.node) = new PositionalVar((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 126:
#line 1860 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTScoreVar [ ]\n";
			(yyval.node) = new FTScoreVar((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 127:
#line 1872 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "LetClause [ ]\n";
			(yyval.node) = new LetClause((yyloc),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)));
			
		;}
    break;

  case 128:
#line 1885 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarGetsDeclList [single]\n";
			VarGetsDeclList* vgdl_p = new VarGetsDeclList((yyloc));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 129:
#line 1892 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarGetsDeclList [list.single]\n";
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 130:
#line 1907 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarGetsDecl [gets]\n";
			(yyval.node) = new VarGetsDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 131:
#line 1916 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarGetsDecl [type.gets]\n";
			(yyval.node) = new VarGetsDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 132:
#line 1926 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarGetsDecl [scorevar.gets]\n";
			(yyval.node) = new VarGetsDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 133:
#line 1935 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarGetsDecl [type.scorevar.gets]\n";
			(yyval.node) = new VarGetsDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 134:
#line 1951 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "WhereClause [ ]\n";
			(yyval.node) = new WhereClause((yyloc),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 135:
#line 1963 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderByClause [ ]\n";
			(yyval.node) = new OrderByClause((yyloc),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 136:
#line 1969 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderByClause [stable]\n";
			(yyval.node) = new OrderByClause((yyloc),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)),
								true);
		;}
    break;

  case 137:
#line 1982 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderSpecList [single]\n";
			OrderSpecList* osl_p = new OrderSpecList((yyloc));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 138:
#line 1989 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderSpecList [list]\n";
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 139:
#line 2004 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderSpec [single]\n";
			(yyval.node) = new OrderSpec((yyloc),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 140:
#line 2011 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderSpec [single.modifier]\n";
			(yyval.node) = new OrderSpec((yyloc),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 141:
#line 2024 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderModifier [dir]\n";
			(yyval.node) = new OrderModifier((yyloc),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 142:
#line 2032 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderModifier [empty]\n";
			(yyval.node) = new OrderModifier((yyloc),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 143:
#line 2040 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderModifier [collation]\n";
			(yyval.node) = new OrderModifier((yyloc),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 144:
#line 2048 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderModifier [dir.empty]\n";
			(yyval.node) = new OrderModifier((yyloc),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 145:
#line 2056 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderModifier [dir.collation]\n";
			(yyval.node) = new OrderModifier((yyloc),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 146:
#line 2064 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderModifier [empty.collation]\n";
			(yyval.node) = new OrderModifier((yyloc),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 147:
#line 2072 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderModifier [dir.empty.collation]\n";
			(yyval.node) = new OrderModifier((yyloc),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 148:
#line 2086 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderDirSpec [ascending]\n";
			(yyval.node) = new OrderDirSpec((yyloc), dir_ascending);
		;}
    break;

  case 149:
#line 2091 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderDirSpec [descending]\n";
			(yyval.node) = new OrderDirSpec((yyloc), dir_descending);
		;}
    break;

  case 150:
#line 2102 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderEmptySpec [greatest]\n";
			(yyval.node) = new OrderEmptySpec((yyloc),
								static_context::empty_greatest);
		;}
    break;

  case 151:
#line 2108 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderEmptySpec [least]\n";
			(yyval.node) = new OrderEmptySpec((yyloc),
								static_context::empty_least);
		;}
    break;

  case 152:
#line 2120 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderCollationSpec [ ]\n";
			(yyval.node) = new OrderCollationSpec((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 153:
#line 2132 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QuantifiedExpr [some]\n";
			(yyval.expr) = new QuantifiedExpr((yyloc),
								quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 154:
#line 2140 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QuantifiedExpr [every]\n";
			(yyval.expr) = new QuantifiedExpr((yyloc),
								quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 155:
#line 2154 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QVarInDeclList [single]\n";
			QVarInDeclList* qvid_list_p = new QVarInDeclList((yyloc));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 156:
#line 2162 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QVarInDeclList [list]\n";
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (qvid_list_p) {
				qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 157:
#line 2177 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QVarInDecl [in]\n";
			(yyval.node) = new QVarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 158:
#line 2184 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QVarInDecl [type.in]\n";
			(yyval.node) = new QVarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 159:
#line 2198 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "TypeswitchExpr [cases.default.return]\n";
			(yyval.expr) = new TypeswitchExpr((yyloc),
								(yysemantic_stack_[(7) - (2)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(7) - (4)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 160:
#line 2206 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "TypeswitchExpr [cases.default.varname.return]\n";
			(yyval.expr) = new TypeswitchExpr((yyloc),
								(yysemantic_stack_[(9) - (2)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(9) - (4)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval)),
								(yysemantic_stack_[(9) - (9)].expr));
		;}
    break;

  case 161:
#line 2221 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CaseClauseList [single]\n";
			CaseClauseList* cc_list_p = new CaseClauseList((yyloc));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 162:
#line 2228 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CaseClauseList [list]\n";
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 163:
#line 2241 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CaseClause [case.return]\n";
			(yyval.node) = new CaseClause((yyloc),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 164:
#line 2248 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CaseClause [case.as.return]\n";
			(yyval.node) = new CaseClause((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 165:
#line 2262 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "IfExpr [ ]\n";
			(yyval.expr) = new IfExpr((yyloc),
								(yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 166:
#line 2274 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrExpr [and]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 167:
#line 2279 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrExpr [or.and]\n";
			(yyval.expr) = new OrExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 168:
#line 2291 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AndExpr [comp]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 169:
#line 2296 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AndExpr [and.comp]\n";
			(yyval.expr) = new AndExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 170:
#line 2316 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ComparisonExpr [ftcontains]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 171:
#line 2321 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			if (debug) cout << "ComparisonExpr [ftcontains.valcomp.ftcontains]\n";
			(yyval.expr) = new ComparisonExpr((yyloc),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 172:
#line 2330 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			if (debug) cout << "ComparisonExpr [ftcontains.gencomp.ftcontains]\n";
			(yyval.expr) = new ComparisonExpr((yyloc),
								dynamic_cast<GeneralComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 173:
#line 2339 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "is" | "<<" | ">>" */
			if (debug) cout << "ComparisonExpr [ftcontains.nodecomp.ftcontains]\n";
			(yyval.expr) = new ComparisonExpr((yyloc),
								dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 174:
#line 2354 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTContainsExpr [range]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 175:
#line 2359 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTContainsExpr [range.ftselect]\n";
			(yyval.expr) = new FTContainsExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 176:
#line 2367 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTContainsExpr [range.ftselect.ftignore]\n";
			(yyval.expr) = new FTContainsExpr((yyloc),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 177:
#line 2381 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "RangeExpr [add]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 178:
#line 2386 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "RangeExpr [add.to.add]\n";
			(yyval.expr) = new RangeExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 179:
#line 2398 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AdditiveExpr [mult]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 180:
#line 2403 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AdditiveExpr [mult+mult]\n";
			(yyval.expr) = new AdditiveExpr((yyloc), op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 181:
#line 2408 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AdditiveExpr [mult-mult]\n";
			(yyval.expr) = new AdditiveExpr((yyloc), op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 182:
#line 2419 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "MultiplicativeExpr [union]\n";
		;}
    break;

  case 183:
#line 2423 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "MultiplicativeExpr [mult*union]\n";
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 184:
#line 2428 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "MultiplicativeExpr [mult.div.union]\n";
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 185:
#line 2433 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "MultiplicativeExpr [mult.idiv.union]\n";
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 186:
#line 2438 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "MultiplicativeExpr [mult.mod.union]\n";
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 187:
#line 2449 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "UnionExpr [interexcept]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 188:
#line 2454 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "UnionExpr [union.union.interexcept]\n";
			(yyval.expr) = new UnionExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 189:
#line 2460 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "UnionExpr [union|interexcept]\n";
			(yyval.expr) = new UnionExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 190:
#line 2472 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "IntersectExceptExpr [instanceof]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 191:
#line 2477 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "IntersectExceptExpr [interexcept.inter.instanceof]\n";
			(yyval.expr) = new IntersectExceptExpr((yyloc), op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 192:
#line 2482 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "IntersectExceptExpr [interexcept.except.instanceof]\n";
			(yyval.expr) = new IntersectExceptExpr((yyloc), op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 193:
#line 2493 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "InstanceofExpr [treat]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 194:
#line 2498 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "InstanceofExpr [treat.seqtype]\n";
			(yyval.expr) = new InstanceofExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 195:
#line 2511 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "TreatExpr [castable]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 196:
#line 2516 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "TreatExpr [castable.seqtype]\n";
			(yyval.expr) = new TreatExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 197:
#line 2529 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CastableExpr [cast]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 198:
#line 2534 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CastableExpr [cast.singletype]\n";
			(yyval.expr) = new CastableExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 199:
#line 2547 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CastExpr [unary]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 200:
#line 2552 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CastExpr [unary.singletype]\n";
			(yyval.expr) = new CastExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 201:
#line 2565 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "UnaryExpr [value]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 202:
#line 2570 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "UnaryExpr [signlist.value]\n";
			(yyval.expr) = new UnaryExpr((yyloc),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 203:
#line 2583 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SignList [+]\n";
			(yyval.node) = new SignList((yyloc), true);
		;}
    break;

  case 204:
#line 2588 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SignList [-]\n";
			(yyval.node) = new SignList((yyloc), false);
		;}
    break;

  case 205:
#line 2593 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SignList [signlist.+]\n";
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 206:
#line 2598 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SignList [signlist.-]\n";
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 207:
#line 2611 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValueExpr [validate]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 208:
#line 2616 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValueExpr [path]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 209:
#line 2621 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValueExpr [extension]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 210:
#line 2633 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "GeneralComp [=]\n";
			(yyval.node) = new GeneralComp((yyloc), op_eq);
		;}
    break;

  case 211:
#line 2638 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "GeneralComp [!=]\n";
			(yyval.node) = new GeneralComp((yyloc), op_ne);
		;}
    break;

  case 212:
#line 2643 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "GeneralComp [<]\n";
			(yyval.node) = new GeneralComp((yyloc), op_lt);
		;}
    break;

  case 213:
#line 2648 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "GeneralComp [<=]\n";
			(yyval.node) = new GeneralComp((yyloc), op_le);
		;}
    break;

  case 214:
#line 2653 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "GeneralComp [>]\n";
			(yyval.node) = new GeneralComp((yyloc), op_gt);
		;}
    break;

  case 215:
#line 2658 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "GeneralComp [>=]\n";
			(yyval.node) = new GeneralComp((yyloc), op_ge);
		;}
    break;

  case 216:
#line 2669 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValueComp [eq]\n";
			(yyval.node) = new ValueComp((yyloc), op_val_eq);
		;}
    break;

  case 217:
#line 2674 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValueComp [ne]\n";
			(yyval.node) = new ValueComp((yyloc), op_val_ne);
		;}
    break;

  case 218:
#line 2679 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValueComp [lt]\n";
			(yyval.node) = new ValueComp((yyloc), op_val_lt);
		;}
    break;

  case 219:
#line 2684 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValueComp [le]\n";
			(yyval.node) = new ValueComp((yyloc), op_val_le);
		;}
    break;

  case 220:
#line 2689 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValueComp [gt]\n";
			(yyval.node) = new ValueComp((yyloc), op_val_gt);
		;}
    break;

  case 221:
#line 2694 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValueComp [ge]\n";
			(yyval.node) = new ValueComp((yyloc), op_val_ge);
		;}
    break;

  case 222:
#line 2705 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NodeComp [is]\n";
			(yyval.node) = new NodeComp((yyloc), op_is);
		;}
    break;

  case 223:
#line 2710 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NodeComp [<<]\n";
			(yyval.node) = new NodeComp((yyloc), op_precedes);
		;}
    break;

  case 224:
#line 2715 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NodeComp [>>]\n";
			(yyval.node) = new NodeComp((yyloc), op_follows);
		;}
    break;

  case 225:
#line 2727 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValidateExpr [expr]\n";
			(yyval.expr) = new ValidateExpr((yyloc), "strict", (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 226:
#line 2732 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValidateExpr [mode.expr]\n";
			(yyval.expr) = new ValidateExpr((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 227:
#line 2745 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExtensionExpr [pragmalist]\n";
			(yyval.expr) = new ExtensionExpr((yyloc),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 228:
#line 2752 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExtensionExpr [pragmalist.expr]\n";
			(yyval.expr) = new ExtensionExpr((yyloc),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 229:
#line 2765 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PragmaList [single]\n";
			PragmaList* pragma_list_p = new PragmaList((yyloc));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 230:
#line 2772 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PragmaList [list]\n";
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 231:
#line 2787 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Pragma [ ]\n";
			(yyval.node) = new Pragma((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));

		;}
    break;

  case 232:
#line 2831 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PathExpr [/]\n";
			(yyval.expr) = new PathExpr((yyloc), path_leading_lone_slash, NULL);
		;}
    break;

  case 233:
#line 2836 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PathExpr [/relative]\n";
			(yyval.expr) = new PathExpr((yyloc), path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 234:
#line 2841 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PathExpr [//relative]\n";
			(yyval.expr) = new PathExpr((yyloc), path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 235:
#line 2846 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PathExpr [relative]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 236:
#line 2857 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "RelativePathExpr [step]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);						
		;}
    break;

  case 237:
#line 2862 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "RelativePathExpr [step/relative]\n";
			(yyval.expr) = new RelativePathExpr((yyloc), st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 238:
#line 2867 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "RelativePathExpr [step//relative]\n";
			(yyval.expr) = new RelativePathExpr((yyloc), st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 239:
#line 2878 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "StepExpr [axis]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 240:
#line 2883 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "StepExpr [filter]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 241:
#line 2894 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AxisStep [forward]\n";
			(yyval.expr) = new AxisStep((yyloc),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 242:
#line 2901 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AxisStep [forward.predlist]\n";
			(yyval.expr) = new AxisStep((yyloc),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 243:
#line 2908 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AxisStep [reverse]\n";
			(yyval.expr) = new AxisStep((yyloc),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 244:
#line 2915 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AxisStep [reverse.predlist]\n";
			(yyval.expr) = new AxisStep((yyloc),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 245:
#line 2928 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForwardStep [nodetest]\n";
			(yyval.node) = new ForwardStep((yyloc),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 246:
#line 2935 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForwardStep [abbrev]\n";
			(yyval.node) = new ForwardStep((yyloc),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 247:
#line 2947 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForwardAxis [child]\n";
			(yyval.node) = new ForwardAxis((yyloc), axis_child);
		;}
    break;

  case 248:
#line 2952 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForwardAxis [descendant]\n";
			(yyval.node) = new ForwardAxis((yyloc), axis_descendant);
		;}
    break;

  case 249:
#line 2957 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForwardAxis [attribute]\n";
			(yyval.node) = new ForwardAxis((yyloc), axis_attribute);
		;}
    break;

  case 250:
#line 2962 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForwardAxis [self]\n";
			(yyval.node) = new ForwardAxis((yyloc), axis_self);
		;}
    break;

  case 251:
#line 2967 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForwardAxis [descendant_or_self]\n";
			(yyval.node) = new ForwardAxis((yyloc), axis_descendant_or_self);
		;}
    break;

  case 252:
#line 2972 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForwardAxis [following_sibling]\n";
			(yyval.node) = new ForwardAxis((yyloc), axis_following_sibling);
		;}
    break;

  case 253:
#line 2977 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForwardAxis [following]\n";
			(yyval.node) = new ForwardAxis((yyloc), axis_following);
		;}
    break;

  case 254:
#line 2988 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AbbrevForwardStep [nodetest]\n";
			(yyval.node) = new AbbrevForwardStep((yyloc), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 255:
#line 2993 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AbbrevForwardStep [@ nodetest]\n";
			(yyval.node) = new AbbrevForwardStep((yyloc), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 256:
#line 3004 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ReverseStep [nodetest]\n";
			(yyval.node) = new ReverseStep((yyloc),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 257:
#line 3011 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ReverseStep [..]\n";
			ReverseAxis* rev_p = new ReverseAxis((yyloc), axis_parent);
			(yyval.node) = new ReverseStep((yyloc),
								rev_p);
		;}
    break;

  case 258:
#line 3024 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ReverseAxis [parent]\n";
			(yyval.node) = new ReverseAxis((yyloc), axis_parent);
		;}
    break;

  case 259:
#line 3029 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ReverseAxis [ancestor]\n";
			(yyval.node) = new ReverseAxis((yyloc), axis_ancestor);
		;}
    break;

  case 260:
#line 3034 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ReverseAxis [preceding_sibling]\n";
			(yyval.node) = new ReverseAxis((yyloc), axis_preceding_sibling);
		;}
    break;

  case 261:
#line 3039 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ReverseAxis [preceding]\n";
			(yyval.node) = new ReverseAxis((yyloc), axis_preceding);
		;}
    break;

  case 262:
#line 3044 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ReverseAxis [ancestor_or_self]\n";
			(yyval.node) = new ReverseAxis((yyloc), axis_ancestor_or_self);
		;}
    break;

  case 263:
#line 3060 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NodeTest [kindtest]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 264:
#line 3065 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NodeTest [nametest]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 265:
#line 3076 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NameTest [qname]\n";
			(yyval.node) = new NameTest((yyloc), new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 266:
#line 3081 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NameTest [wildcard]\n";
			(yyval.node) = new NameTest((yyloc), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 267:
#line 3092 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Wildcard [*]\n";
			(yyval.node) = new Wildcard((yyloc),
                        "",
                        "",
                        wild_all);
		;}
    break;

  case 268:
#line 3100 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Wildcard [pref:*]\n";
			(yyval.node) = new Wildcard((yyloc),
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        wild_elem);
		;}
    break;

  case 269:
#line 3108 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Wildcard [*:qname]\n";
			(yyval.node) = new Wildcard((yyloc),
                        "",
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        wild_prefix);
		;}
    break;

  case 270:
#line 3122 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FilterExpr [primary]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 271:
#line 3127 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FilterExpr [primary.predlist]\n";
			(yyval.expr) = new FilterExpr((yyloc),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 272:
#line 3140 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PredicateList [single]\n";
			PredicateList* pred_list_p = new PredicateList((yyloc));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 273:
#line 3147 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PredicateList [list]\n";
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 274:
#line 3162 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Predicate [ ]\n";
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 275:
#line 3174 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PrimaryExpr [literal]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 276:
#line 3179 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PrimaryExpr [varref]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 277:
#line 3184 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PrimaryExpr [paren]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 278:
#line 3189 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PrimaryExpr [context_item]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 279:
#line 3194 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PrimaryExpr [funcall]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 280:
#line 3199 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PrimaryExpr [cons]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 281:
#line 3204 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PrimaryExpr [ordered]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 282:
#line 3209 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PrimaryExpr [unordered]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 283:
#line 3220 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Literal [numeric]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 284:
#line 3225 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Literal [string]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 285:
#line 3236 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NumericLiteral [decimal]\n";
			(yyval.expr) = new NumericLiteral((yyloc), decimal(yylval.decval));
		;}
    break;

  case 286:
#line 3241 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NumericLiteral [int]\n";
			(yyval.expr) = new NumericLiteral((yyloc), yylval.ival);
		;}
    break;

  case 287:
#line 3246 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NumericLiteral [double]\n";
			(yyval.expr) = new NumericLiteral((yyloc), yylval.dval);
		;}
    break;

  case 288:
#line 3257 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarRef [ ]\n";
			(yyval.expr) = new VarRef((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 289:
#line 3268 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ParenthesizedExpr [()]\n";
			(yyval.expr) = new ParenthesizedExpr((yyloc), NULL);
		;}
    break;

  case 290:
#line 3273 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ParenthesizedExpr [(expr)]\n";
			(yyval.expr) = new ParenthesizedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 291:
#line 3285 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ContextItemExpr [.]\n";
			(yyval.expr) = new ContextItemExpr((yyloc));
		;}
    break;

  case 292:
#line 3296 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderedExpr [expr]\n";
			(yyval.expr) = new OrderedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 293:
#line 3308 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "UnorderedExpr [expr]\n";
			(yyval.expr) = new UnorderedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 294:
#line 3365 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionCall [ ]\n";
			(yyval.expr) = new FunctionCall((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 295:
#line 3372 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionCall [arglist]\n";
			(yyval.expr) = new FunctionCall((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 296:
#line 3385 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ArgList [single]\n";
			ArgList* a_list_p = new ArgList((yyloc)); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 297:
#line 3392 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ArgList [list]\n";
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 298:
#line 3405 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Constructor [direct]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 299:
#line 3410 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Constructor [computed]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 300:
#line 3421 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirectConstructor [element]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 301:
#line 3426 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirectConstructor [comment]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 3431 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirectConstructor [pi]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 303:
#line 3442 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirElemConstructor [<qname/> ]\n";
			(yyval.expr) = new DirElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 304:
#line 3451 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirElemConstructor [<qname attrlist/> ]\n";
			(yyval.expr) = new DirElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(4) - (3)].node)), 
								NULL);
		;}
    break;

  case 305:
#line 3460 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirElemConstructor [<qname></qname>]\n";
			(yyval.expr) = new DirElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (5)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 306:
#line 3469 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirElemConstructor [<qname>content</qname>]\n";
			(yyval.expr) = new DirElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (6)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(7) - (4)].node)));
		;}
    break;

  case 307:
#line 3478 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirElemConstructor [<qname attrlist></qname>]\n";
			(yyval.expr) = new DirElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (6)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(7) - (3)].node)),
								NULL);
		;}
    break;

  case 308:
#line 3487 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirElemConstructor [<qname attrlist>content</qname>]\n";
			(yyval.expr) = new DirElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(8) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(8) - (5)].node)));
		;}
    break;

  case 309:
#line 3503 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirElemContentList [single]\n";
			DirElemContentList* elem_content_list_p = new DirElemContentList((yyloc));
			elem_content_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 310:
#line 3510 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirElemContentList [list]\n";
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 311:
#line 3523 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirAttributeList [single]\n";
			DirAttributeList* at_list_p = new DirAttributeList((yyloc));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 312:
#line 3530 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirAttributeList [list]\n";
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 313:
#line 3545 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirAttr [ ]\n";
			(yyval.node) = new DirAttr((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 314:
#line 3558 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirAttributeValue [quote]\n";
			(yyval.node) = new DirAttributeValue((yyloc),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 315:
#line 3564 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirAttributeValue [apos]\n";
			(yyval.node) = new DirAttributeValue((yyloc),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 316:
#line 3576 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QuoteAttrContentList[empty]\n";
			(yyval.node) = new QuoteAttrContentList((yyloc));
		;}
    break;

  case 317:
#line 3581 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 318:
#line 3588 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QuoteAttrContentList [""]\n";
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList((yyloc));
			qo_list_p->push_back(new QuoteAttrValueContent((yyloc),string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 319:
#line 3595 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QuoteAttrContentList [single]\n";
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList((yyloc));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 320:
#line 3602 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QuoteAttrContentList [list ""]\n";
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent((yyloc),string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 321:
#line 3611 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QuoteAttrContentList [list]\n";
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
		;}
    break;

  case 322:
#line 3625 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AposAttrContentList ['']\n";
			(yyval.node) = new AposAttrContentList((yyloc));
		;}
    break;

  case 323:
#line 3630 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 324:
#line 3637 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AposAttrContentList ['']\n";
			AposAttrContentList* at_list_p = new AposAttrContentList((yyloc));
			at_list_p->push_back(new AposAttrValueContent((yyloc),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 325:
#line 3644 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AposAttrContentList [single]\n";
			AposAttrContentList* at_list_p = new AposAttrContentList((yyloc));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 326:
#line 3651 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AposAttrContentList [list.'']\n";
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent((yyloc),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 327:
#line 3660 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AposAttrContentList [list.single]\n";
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 328:
#line 3675 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QuoteAttrValueContent [quote_attr_content]\n";
			(yyval.node) = new QuoteAttrValueContent((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 329:
#line 3681 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QuoteAttrValueContent [common_content]\n";
			(yyval.node) = new QuoteAttrValueContent((yyloc),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 330:
#line 3693 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AposAttrValueContent [apos_attr_content]\n";
			(yyval.node) = new AposAttrValueContent((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 331:
#line 3699 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AposAttrValueContent [common_content]\n";
			(yyval.node) = new AposAttrValueContent((yyloc),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 332:
#line 3711 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirElemContent [cons]\n";
			(yyval.expr) = new DirElemContent((yyloc),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 333:
#line 3717 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirElemContent [elem_content]\n";
			(yyval.expr) = new DirElemContent((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 334:
#line 3723 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirElemContent [cdata]\n";
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent((yyloc),
								cdata_h);
		;}
    break;

  case 335:
#line 3730 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirElemContent [common_content]\n";
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent((yyloc),
								cont_h);
		;}
    break;

  case 336:
#line 3743 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CommonContent [entity_ref]\n";
			(yyval.expr) = new CommonContent((yyloc),
								cont_entity,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 337:
#line 3750 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CommonContent [char_ref]\n";
			(yyval.expr) = new CommonContent((yyloc),
								cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 338:
#line 3757 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CommonContent [{{]\n";
			(yyval.expr) = new CommonContent((yyloc),
								cont_escape_lbrace);
		;}
    break;

  case 339:
#line 3763 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CommonContent [}}]\n";
			(yyval.expr) = new CommonContent((yyloc),
								cont_escape_rbrace);
		;}
    break;

  case 340:
#line 3769 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CommonContent [expr]\n";
			(yyval.expr) = new CommonContent((yyloc),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 341:
#line 3781 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirCommentConstructor [ ]\n";
			(yyval.expr) = new DirCommentConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 342:
#line 3798 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirPIConstructor [target]\n";
			(yyval.expr) = new DirPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 343:
#line 3804 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirPIConstructor [target.charlit]\n";
			(yyval.expr) = new DirPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 344:
#line 3822 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CDataSection [ ]\n";
			(yyval.expr) = new CDataSection((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 345:
#line 3838 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ComputedConstructor [doc]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 346:
#line 3843 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ComputedConstructor [elem]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 347:
#line 3848 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ComputedConstructor [attr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 348:
#line 3853 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ComputedConstructor [text]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 349:
#line 3858 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ComputedConstructor [comment]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 350:
#line 3863 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ComputedConstructor [pi]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 351:
#line 3874 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompDocConstructor [ ]\n";
			(yyval.expr) = new CompDocConstructor((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 352:
#line 3886 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompElemConstructor [ ]\n";
			(yyval.expr) = new CompElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 353:
#line 3893 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompElemConstructor [content]\n";
			(yyval.expr) = new CompElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 354:
#line 3900 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompElemConstructor [name]\n";
			(yyval.expr) = new CompElemConstructor((yyloc),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 355:
#line 3906 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompElemConstructor [name.content]\n";
			(yyval.expr) = new CompElemConstructor((yyloc),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 356:
#line 3930 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompAttrConstructor [ ]\n";
			(yyval.expr) = new CompAttrConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 357:
#line 3937 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompAttrConstructor [val]\n";
			(yyval.expr) = new CompAttrConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 358:
#line 3944 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompAttrConstructor [name]\n";
			(yyval.expr) = new CompAttrConstructor((yyloc),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 359:
#line 3950 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompAttrConstructor [name.val]\n";
			(yyval.expr) = new CompAttrConstructor((yyloc),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 360:
#line 3962 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompTextConstructor [content]\n";
			(yyval.expr) = new CompTextConstructor((yyloc),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 361:
#line 3974 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompCommentConstructor [content]\n";
			(yyval.expr) = new CompCommentConstructor((yyloc),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 362:
#line 3986 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompPIConstructor [ ]\n";
			(yyval.expr) = new CompPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 363:
#line 3993 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompPIConstructor [content]\n";
			(yyval.expr) = new CompPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 364:
#line 4000 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompPIConstructor [target]\n";
			(yyval.expr) = new CompPIConstructor((yyloc),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 365:
#line 4006 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompPIConstructor [target.content]\n";
			(yyval.expr) = new CompPIConstructor((yyloc),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 366:
#line 4018 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SingleType [atomic]\n";
			(yyval.node) = new SingleType((yyloc),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 367:
#line 4025 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SingleType [atomic ?]\n";
			(yyval.node) = new SingleType((yyloc),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 368:
#line 4038 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "TypeDeclaration [as seqtype]\n";
			(yyval.node) = new TypeDeclaration((yyloc),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 369:
#line 4050 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ItemType [type]\n";
			(yyval.node) = new SequenceType((yyloc),
								dynamic_cast<ItemType*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 370:
#line 4057 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ItemType [type.occurs]\n";
			(yyval.node) = new SequenceType((yyloc),
								dynamic_cast<ItemType*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 371:
#line 4064 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ItemType [void]\n";
			(yyval.node) = new SequenceType((yyloc), NULL, NULL);
		;}
    break;

  case 372:
#line 4102 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OccurrenceIndicator [?]\n";
			(yyval.node) = new OccurrenceIndicator((yyloc),
								occurs_optionally);
		;}
    break;

  case 373:
#line 4108 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OccurrenceIndicator [*]\n";
			(yyval.node) = new OccurrenceIndicator((yyloc),
								occurs_zero_or_more);
		;}
    break;

  case 374:
#line 4114 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OccurrenceIndicator [+]\n";
			(yyval.node) = new OccurrenceIndicator((yyloc),
								occurs_one_or_more);
		;}
    break;

  case 375:
#line 4126 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ItemType [atomic]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 376:
#line 4131 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ItemType [kind]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 377:
#line 4136 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ItemType [item]\n";
			(yyval.node) = new ItemType((yyloc),true);
		;}
    break;

  case 378:
#line 4147 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AtomicType [qname]\n";
			(yyval.node) = new AtomicType((yyloc),
								new QName((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 379:
#line 4159 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "KindTest [doc]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 380:
#line 4164 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "KindTest [elem]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 381:
#line 4169 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "KindTest [attr]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 382:
#line 4174 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "KindTest [schema_elem]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 383:
#line 4179 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "KindTest [schema_attr]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 384:
#line 4184 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "KindTest [pi]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 385:
#line 4189 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "KindTest [comment]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 386:
#line 4194 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "KindTest [text]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 387:
#line 4199 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "KindTest [any]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 388:
#line 4210 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AnyKindTest [ ]\n";
			(yyval.node) = new AnyKindTest((yyloc));
		;}
    break;

  case 389:
#line 4221 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DocumentTest [ ]\n";
			(yyval.node) = new DocumentTest((yyloc));
		;}
    break;

  case 390:
#line 4226 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DocumentTest [elem]\n";
			(yyval.node) = new DocumentTest((yyloc),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 391:
#line 4232 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DocumentTest [schema_elem]\n";
			(yyval.node) = new DocumentTest((yyloc),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 392:
#line 4244 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "TextTest [ ]\n";
			(yyval.node) = new TextTest((yyloc));
		;}
    break;

  case 393:
#line 4255 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CommentTest [ ]\n";
			(yyval.node) = new CommentTest((yyloc));
		;}
    break;

  case 394:
#line 4266 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PITest [ ]\n";
			(yyval.node) = new PITest((yyloc), "", "");
		;}
    break;

  case 395:
#line 4271 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PITest [ncname]\n";
			(yyval.node) = new PITest((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), "");
		;}
    break;

  case 396:
#line 4276 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PITest [stringlit]\n";
			(yyval.node) = new PITest((yyloc), "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 397:
#line 4287 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AttributeTest [ ]\n";
			(yyval.node) = new AttributeTest((yyloc),
								NULL,
								NULL);
		;}
    break;

  case 398:
#line 4294 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AttributeTest [name]\n";
			(yyval.node) = new AttributeTest((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL);
		;}
    break;

  case 399:
#line 4301 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AttributeTest [name.type]\n";
			(yyval.node) = new AttributeTest((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 400:
#line 4308 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AttributeTest [*]\n";
			(yyval.node) = new AttributeTest((yyloc),
								NULL,
								NULL);
		;}
    break;

  case 401:
#line 4315 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AttributeTest [*.type]\n";
			(yyval.node) = new AttributeTest((yyloc),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 402:
#line 4328 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SchemaAttributeTest [ ]\n";
			(yyval.node) = new SchemaAttributeTest((yyloc),
								new QName((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 403:
#line 4340 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ElementTest [ ]\n";
			(yyval.node) = new ElementTest((yyloc),
									NULL,
									NULL);
		;}
    break;

  case 404:
#line 4347 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ElementTest [name]\n";
			(yyval.node) = new ElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
									NULL);
		;}
    break;

  case 405:
#line 4354 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ElementTest [name.type]\n";
			(yyval.node) = new ElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 406:
#line 4361 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ElementTest [name.type]\n";
			(yyval.node) = new ElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (4)].node)));
		;}
    break;

  case 407:
#line 4368 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ElementTest [*]\n";
			(yyval.node) = new ElementTest((yyloc),
									NULL,
									NULL,
									true);
		;}
    break;

  case 408:
#line 4376 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ElementTest [*.type]\n";
			(yyval.node) = new ElementTest((yyloc),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)),
									true);
		;}
    break;

  case 409:
#line 4384 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ElementTest [*.type]\n";
			(yyval.node) = new ElementTest((yyloc),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (4)].node)),
									true);
		;}
    break;

  case 410:
#line 4398 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SchemaElementTest [ ]\n";
			(yyval.node) = new SchemaElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 411:
#line 4420 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "TypeName [name]\n";
			(yyval.node) = new TypeName((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 412:
#line 4426 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "TypeName [name?]\n";
			(yyval.node) = new TypeName((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 413:
#line 4447 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "StringLiteral [ ]\n";
			(yyval.expr) = new StringLiteral((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 414:
#line 4487 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "RevalidationDecl [ ]\n";
		;}
    break;

  case 415:
#line 4497 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "InsertExpr [expr]\n";
		;}
    break;

  case 416:
#line 4501 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "InsertExpr [expr.as_first]\n";
		;}
    break;

  case 417:
#line 4505 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "InsertExpr [expr.as_last]\n";
		;}
    break;

  case 418:
#line 4509 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "InsertExpr [expr.after]\n";
		;}
    break;

  case 419:
#line 4513 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "InsertExpr [expr.before]\n";
		;}
    break;

  case 420:
#line 4523 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DeleteExpr [expr]\n";
		;}
    break;

  case 421:
#line 4533 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ReplaceExpr [expr.expr]\n";
		;}
    break;

  case 422:
#line 4537 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ReplaceExpr [value.expr]\n";
		;}
    break;

  case 423:
#line 4547 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "RenameExpr [expr.expr]\n";
		;}
    break;

  case 424:
#line 4572 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "TransformExpr [ ]\n";
		;}
    break;

  case 425:
#line 4582 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarNameList [single]\n";
		;}
    break;

  case 426:
#line 4586 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarNameList [list]\n";
		;}
    break;

  case 427:
#line 4604 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTSelection [or]\n";
		;}
    break;

  case 428:
#line 4608 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTSelection [or.match_proximity]\n";
		;}
    break;

  case 429:
#line 4612 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTSelection [or.weight_range]\n";
		;}
    break;

  case 430:
#line 4616 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTSelection [or.match_proximity.weight_range]\n";
		;}
    break;

  case 431:
#line 4626 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOptionProximityList [option_single]\n";
		;}
    break;

  case 432:
#line 4630 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOptionProximityList [proximity_single]\n";
		;}
    break;

  case 433:
#line 4634 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOptionProximityList [option_list]\n";
		;}
    break;

  case 434:
#line 4638 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOptionProximityList [proximity_list]\n";
		;}
    break;

  case 435:
#line 4648 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTOr [and]\n";
		;}
    break;

  case 436:
#line 4652 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTOr [or.and]\n";
		;}
    break;

  case 437:
#line 4662 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTAnd [mild_not]\n";
		;}
    break;

  case 438:
#line 4666 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTAnd [and.mild_not]\n";
		;}
    break;

  case 439:
#line 4676 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMildNot [unary_not]\n";
		;}
    break;

  case 440:
#line 4680 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMildNot [mild_not.unary_not]\n";
		;}
    break;

  case 441:
#line 4690 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTUnaryNot [words]\n";
		;}
    break;

  case 442:
#line 4694 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTUnaryNot [not.words]\n";
		;}
    break;

  case 443:
#line 4704 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWordsSelection [words]\n";
		;}
    break;

  case 444:
#line 4708 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWordsSelection [words.times]\n";
		;}
    break;

  case 445:
#line 4712 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWordsSelection [selection]\n";
		;}
    break;

  case 446:
#line 4722 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWords [value]\n";
		;}
    break;

  case 447:
#line 4726 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWords [value.any_all_option]\n";
		;}
    break;

  case 448:
#line 4736 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWordsValue [literal]\n";
		;}
    break;

  case 449:
#line 4740 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWordsValue [expr]\n";
		;}
    break;

  case 450:
#line 4750 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTProximity [order]\n";
		;}
    break;

  case 451:
#line 4754 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTProximity [window]\n";
		;}
    break;

  case 452:
#line 4758 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTProximity [distance]\n";
		;}
    break;

  case 453:
#line 4762 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTProximity [scope]\n";
		;}
    break;

  case 454:
#line 4766 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTProximity [content]\n";
		;}
    break;

  case 455:
#line 4776 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTOrderedIndicator [ ]\n";
		;}
    break;

  case 456:
#line 4786 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOption [case]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 457:
#line 4791 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOption [diacritics]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 458:
#line 4796 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOption [stem]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 459:
#line 4801 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOption [thesaurus]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 460:
#line 4806 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOption [stopword]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 461:
#line 4811 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOption [language]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 462:
#line 4816 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOption [wildcard]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 463:
#line 4827 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTCaseOption [lower]\n";
		;}
    break;

  case 464:
#line 4831 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTCaseOption [upper]\n";
		;}
    break;

  case 465:
#line 4835 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTCaseOption [sensitive]\n";
		;}
    break;

  case 466:
#line 4839 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTCaseOption [insensitive]\n";
		;}
    break;

  case 467:
#line 4849 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTDiacriticsOption [with]\n";
		;}
    break;

  case 468:
#line 4853 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTDiacriticsOption [without]\n";
		;}
    break;

  case 469:
#line 4857 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTDiacriticsOption [sensitive]\n";
		;}
    break;

  case 470:
#line 4861 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTDiacriticsOption [insensitive]\n";
		;}
    break;

  case 471:
#line 4871 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTStemOption [with]\n";
		;}
    break;

  case 472:
#line 4875 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTStemOption [without]\n";
		;}
    break;

  case 473:
#line 4885 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusOption [id]\n";
		;}
    break;

  case 474:
#line 4889 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusOption [default]\n";
		;}
    break;

  case 475:
#line 4893 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusOption [(id)]\n";
		;}
    break;

  case 476:
#line 4897 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusOption [(id,id,..)]\n";
		;}
    break;

  case 477:
#line 4901 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusOption [(default)]\n";
		;}
    break;

  case 478:
#line 4905 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusOption [(default,id,id,..)]\n";
		;}
    break;

  case 479:
#line 4909 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusOption [without]\n";
		;}
    break;

  case 480:
#line 4919 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusList [single]\n";
		;}
    break;

  case 481:
#line 4923 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusList [list]\n";
		;}
    break;

  case 482:
#line 4933 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusID [name]\n";
		;}
    break;

  case 483:
#line 4937 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusID [name.rel]\n";
		;}
    break;

  case 484:
#line 4941 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusID [name.range]\n";
		;}
    break;

  case 485:
#line 4945 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusID [name.rel.range]\n";
		;}
    break;

  case 486:
#line 4955 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTStopwordOption [list]\n";
		;}
    break;

  case 487:
#line 4959 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTStopwordOption [list.incl_excl]\n";
		;}
    break;

  case 488:
#line 4963 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTStopwordOption [default]\n";
		;}
    break;

  case 489:
#line 4967 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTStopwordOption [default.incl_excl]\n";
		;}
    break;

  case 490:
#line 4971 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTStopwordOption [without]\n";
		;}
    break;

  case 491:
#line 4981 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTInclExclStringLiteralList [.]\n";
		;}
    break;

  case 492:
#line 4985 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTInclExclStringLiteralList [*]\n";
		;}
    break;

  case 493:
#line 4995 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTRefOrList [.]\n";
		;}
    break;

  case 494:
#line 4999 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTRefOrList [(*)]\n";
		;}
    break;

  case 495:
#line 5009 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTStringLiteralList [.]\n";
		;}
    break;

  case 496:
#line 5013 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTStringLiteralList [*]\n";
		;}
    break;

  case 497:
#line 5023 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTInclExclStringLiteral [union]\n";
		;}
    break;

  case 498:
#line 5027 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTInclExclStringLiteral [except]\n";
		;}
    break;

  case 499:
#line 5037 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTLanguageOption [ ]\n";
		;}
    break;

  case 500:
#line 5047 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWildcardOption [with]\n";
		;}
    break;

  case 501:
#line 5051 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWildcardOption [without]\n";
		;}
    break;

  case 502:
#line 5061 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTContent [start]\n";
		;}
    break;

  case 503:
#line 5065 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTContent [end]\n";
		;}
    break;

  case 504:
#line 5069 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTContent [entire]\n";
		;}
    break;

  case 505:
#line 5079 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTAnyallOption [any]\n";
		;}
    break;

  case 506:
#line 5083 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTAnyallOption [any_word]\n";
		;}
    break;

  case 507:
#line 5087 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTAnyallOption [all]\n";
		;}
    break;

  case 508:
#line 5091 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTAnyallOption [all_words]\n";
		;}
    break;

  case 509:
#line 5095 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTAnyallOption [phrase]\n";
		;}
    break;

  case 510:
#line 5105 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTRange [exactly]\n";
		;}
    break;

  case 511:
#line 5109 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTRange [at_least]\n";
		;}
    break;

  case 512:
#line 5113 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTRange [at_most]\n";
		;}
    break;

  case 513:
#line 5117 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTRange [range]\n";
		;}
    break;

  case 514:
#line 5127 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTDistance [ ]\n";
		;}
    break;

  case 515:
#line 5137 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWindow [ ]\n";
		;}
    break;

  case 516:
#line 5147 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTTimes [ ]\n";
		;}
    break;

  case 517:
#line 5157 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTTimes [same]\n";
		;}
    break;

  case 518:
#line 5161 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTTimes [different]\n";
		;}
    break;

  case 519:
#line 5171 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTUnit [words]\n";
		;}
    break;

  case 520:
#line 5175 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTUnit [sentences]\n";
		;}
    break;

  case 521:
#line 5179 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTUnit [paragraph]\n";
		;}
    break;

  case 522:
#line 5189 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTBigUnit [sentence]\n";
		;}
    break;

  case 523:
#line 5193 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTBigUnit [paragraph]\n";
		;}
    break;

  case 524:
#line 5203 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTIgnoreOption [ ]\n";
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 5060 "/Users/mbrantner/misc/code/vanilla/xquery/build/src/compiler/parser/xquery_parser.cpp"
	default: break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse look-ahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    if (yyn == yyfinal_)
      goto yyacceptlab;

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the look-ahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		   &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyeof_ && yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  xquery_parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int xquery_parser::yypact_ninf_ = -641;
  const short int
  xquery_parser::yypact_[] =
  {
       795,  1366,  1554,  -641,  -641,  -641,  1742,  -641,     1,  -641,
    -641,  -641,  3058,    16,   367,  -641,  3058,   131,  -641,   148,
     -54,   -38,   152,   279,   230,   234,    17,   294,   316,   331,
     -26,   352,   394,  -641,  -641,  3058,   212,   420,  -641,  -641,
    -641,  3058,    57,   428,  -641,  -641,   460,  3058,    52,   282,
    -641,  -641,   477,  1930,  -641,   497,   356,  3058,  -641,   510,
      59,  -641,   514,  -641,  -641,    28,   537,   552,  -641,  3592,
    3592,   428,  -641,   554,  3058,   418,  3058,  3058,  3058,   564,
     560,  -641,  3058,  3058,  3058,  1171,   563,   523,   587,   983,
    -641,  -641,   417,  3058,   427,   431,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,   543,  -641,  -641,   330,
    -641,  -641,  -641,  -641,  -641,  -641,   461,   566,  -641,   641,
     366,   -27,    -7,   122,   392,  -641,   490,   422,   561,   559,
    3246,  -641,  -641,  -641,   197,  -641,  -641,  -641,   334,  -641,
     488,   367,  -641,   488,   367,  -641,  -641,  -641,  -641,   488,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,    63,  -641,
      83,  -641,  -641,    26,  3058,    98,    65,  -641,    84,  -641,
     109,  -641,  -641,  -641,  -641,  -641,  -641,   557,   558,  -641,
     582,   583,  -641,  -641,   164,   520,   588,  -641,  -641,   264,
     249,   112,  -641,   452,   454,  -641,   117,    88,  -641,    94,
     201,   453,   414,   -13,   568,  -641,    97,   585,   601,   586,
     492,   606,   598,    -3,   576,  -641,  -641,    99,   538,  -641,
     121,    61,   469,   471,  -641,   616,   527,  3058,   484,   485,
    -641,  -641,   487,    34,   124,  -641,   100,   190,   207,   448,
     229,  -641,    -1,   617,  3058,   438,   551,   250,  -641,  -641,
    -641,  -641,   629,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
      21,  -641,  -641,    41,   293,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,   417,
       5,  3058,  3058,  3058,  3058,  3058,  -641,   287,   496,  3419,
    3419,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  3419,  3419,  3419,    12,
    3419,  3419,  3419,  3419,  3419,  3419,  3419,  3419,  3419,  3419,
    3419,   223,   223,   636,   636,  -641,  -641,  -641,  2118,  -641,
    3592,  3592,  3058,   488,  -641,  -641,   488,  -641,   488,  -641,
    -641,  3058,  -641,   226,   544,   642,  -641,   642,  -641,  -641,
       9,   268,  -641,  -641,   650,   343,   223,    90,  -641,   652,
    -641,   344,   223,    92,   223,  -641,  3058,   397,  -641,  -641,
    -641,   572,   642,  -641,   642,  -641,  3058,   573,  3058,   428,
     612,  3058,   613,   -17,   584,    -4,   614,   517,   666,   607,
     666,  -641,   608,   663,  3058,   599,   -48,   623,  -641,   677,
    -641,   562,  -641,  -641,  -641,   555,  2306,   228,  -641,  -641,
    3058,   620,  -641,    29,    35,  -641,  -641,   662,  -641,  -641,
    -641,   697,  -641,   280,  3058,  3058,  3058,  3058,   509,  3058,
    3058,   698,  3058,  -641,    41,    41,    21,  -641,   699,   701,
      21,   702,  -641,    66,  -641,   570,  -641,  -641,  -641,   421,
     679,  -641,  -641,   679,  -641,  3058,   575,  3058,   566,  -641,
    -641,  -641,  -641,  3058,    12,   301,  -641,   476,   411,   499,
     498,  -641,  -641,   500,   317,    -7,    -7,    14,   122,   122,
     122,   122,   392,   392,  -641,  -641,  -641,  -641,  -641,  -641,
     426,  -641,  -641,  -641,  -641,   633,  -641,  -641,   235,  -641,
    -641,    76,  -641,  -641,  -641,  2494,   644,   580,   591,  -641,
    -641,  -641,  -641,   711,  -641,  3058,  -641,   350,   675,   396,
     223,  -641,  -641,  -641,   401,   423,   223,  -641,  -641,  -641,
    3058,  2682,   252,   266,  -641,  3058,  -641,  -641,   726,  -641,
     727,  3058,   647,  3058,  3058,   -14,   648,   460,  3058,  -641,
     709,   737,   709,  -641,   666,  -641,  3058,  3058,   665,   477,
     602,  -641,  -641,  -641,   236,   653,  -641,    22,  -641,  -641,
    -641,   761,  -641,  -641,   750,  -641,  -641,    49,  -641,  -641,
    -641,  -641,    95,  -641,   196,   329,  -641,   609,  3058,  3058,
    -641,  -641,  -641,  -641,  3058,  -641,  -641,   672,   630,  -641,
    -641,  -641,  -641,  -641,    33,    21,   210,   101,   102,     5,
    -641,   762,  -641,  -641,  -641,  -641,   319,   728,  -641,  3058,
    -641,  3058,  -641,   240,   631,  -641,  3419,  -641,  -641,  -641,
    -641,   180,   320,  -641,    12,   180,  3419,  3419,   457,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,    12,    12,   320,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,   246,  -641,  -641,  -641,  -641,   251,
    -641,  -641,  -641,  -641,  -641,   432,  -641,  -641,  -641,  -641,
     433,  -641,  -641,   253,   634,  -641,   635,  -641,  -641,  -641,
    -641,  -641,  3058,  -641,  -641,  3058,   681,  3058,  -641,   708,
     770,   763,   709,  -641,  -641,  3058,  -641,  -641,  -641,  2870,
     283,   429,  -641,   751,   625,   776,  -641,   779,   115,   775,
     645,    78,  -641,  -641,  -641,  -641,  -641,  3058,  3058,  -641,
    -641,  3419,  3419,  3419,  3419,   780,   569,   774,  -641,   774,
    -641,  -641,   728,  -641,  -641,  -641,  -641,  -641,  -641,   122,
    -641,  -641,  -641,  -157,   499,  -641,  -641,   255,  3419,  -641,
    -641,   498,  -641,   565,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  3058,  -641,  3058,  -641,   666,
    -641,  -641,   254,  -641,  -641,   773,   286,  -641,  -641,  -641,
    -641,   655,   495,  -641,  -641,  -641,  -641,   637,   646,   797,
     788,  3058,   810,  3058,  -641,  -641,   122,   122,   122,   -23,
     320,  -641,   104,  -641,   105,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,   709,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,   649,   223,  -641,   684,  -641,
    3419,   600,   774,  -641,  -641,  -641,   685,  3058,   122,  -641,
    -641,  3058,  -641,  -641
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,     0,     0,   268,   269,   265,     0,   413,     0,   259,
     262,   249,     0,     0,     0,   247,     0,     0,   285,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   251,     0,     0,     0,   291,   257,
     287,     0,     0,     0,   253,   252,     0,     0,     0,     0,
     286,   232,     0,     0,   204,     0,     0,     0,   258,     0,
       0,   203,     0,   261,   260,     0,     0,     0,   250,     0,
       0,     0,   267,     0,     0,     0,     0,     0,     0,     0,
       0,   414,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     4,     0,     0,     0,     0,    15,    17,    19,    20,
      21,    27,    22,    25,    26,    31,    32,    33,    28,    29,
      35,    36,    23,    30,    24,     9,    93,    94,    96,     0,
     110,   112,   113,    97,    98,    99,   100,   166,   168,   170,
     174,   177,   179,   182,   187,   190,   193,   195,   197,   199,
       0,   201,   207,   209,     0,   229,   208,   235,   236,   239,
     241,     0,   246,   243,     0,   254,   264,   266,   240,   270,
     275,   283,   276,   277,   278,   281,   282,   279,   280,   298,
     300,   301,   302,   299,   345,   346,   347,   348,   349,   350,
     263,   387,   379,   386,   385,   384,   381,   383,   380,   382,
     284,    34,   101,   102,   104,   103,   105,   356,     0,   352,
       0,   294,   296,     0,     0,     0,     0,   397,     0,   255,
       0,   393,    53,    38,    39,    70,    71,     0,     0,    52,
       0,     0,    46,    47,     0,     0,     0,    44,    45,     0,
       0,     0,   389,     0,     0,   288,     0,     0,   403,     0,
       0,     0,   155,     0,   114,   115,     0,    62,     0,    54,
       0,     0,     0,     0,   127,   128,   289,     0,     0,   388,
       0,     0,     0,     0,   394,     0,     0,     0,     0,     0,
     233,   234,     0,     0,     0,   392,     0,     0,     0,     0,
       0,   420,     0,     0,     0,     0,     0,     0,   466,   465,
     470,   469,     0,   463,   464,   468,   472,   490,   479,   501,
     488,   467,   471,     0,     0,   500,    43,   456,   457,   458,
     459,   460,   461,   462,     1,     3,     5,    10,     8,    12,
      13,     0,     0,     0,     0,     0,   111,     0,     0,     0,
       0,   210,   224,   215,   214,   222,   213,   212,   211,   223,
     216,   221,   220,   219,   218,   217,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   206,   205,   202,     0,   230,
       0,     0,     0,   242,   272,   245,   244,   256,   271,   357,
     353,     0,   295,     0,     0,     0,   398,     0,   400,   361,
       0,     0,    40,    41,     0,     0,     0,     0,    88,     0,
      42,     0,     0,     0,     0,    67,     0,     0,   351,   390,
     391,     0,     0,   404,     0,   407,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,     0,    55,     0,     0,     0,     0,   290,     0,
     292,     0,   342,   395,   396,     0,     0,     0,   402,   410,
       0,     0,   303,     0,     0,   311,   360,     0,   293,   225,
     341,     0,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   499,     0,     0,   489,   491,     0,     0,
     486,     0,   474,     0,   473,     0,    16,    18,    95,   139,
     135,   137,   106,   136,   134,     0,     0,     0,   167,   169,
     172,   171,   173,     0,     0,     0,   448,   175,   427,   435,
     437,   439,   441,   443,   446,   181,   180,   178,   184,   185,
     186,   183,   188,   189,   192,   191,   378,   377,   371,   194,
     369,   375,   376,   196,   198,   366,   200,   227,     0,   237,
     238,     0,   273,   297,   226,     0,   411,     0,     0,    50,
      51,    48,    49,    90,    72,     0,    73,     0,     0,     0,
       0,    37,    80,    81,     0,     0,     0,   368,    66,    69,
       0,     0,     0,     0,   157,     0,   154,   156,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      64,     0,    56,    60,     0,   130,     0,     0,     0,     0,
       0,   343,   231,   362,     0,     0,   153,     0,   337,   333,
     336,     0,   338,   339,     0,   340,   332,     0,   309,   335,
     334,   304,     0,   312,     0,     0,   161,     0,     0,     0,
     418,   419,   415,   423,     0,   421,   425,     0,     0,   498,
     497,   492,   493,   495,     0,   487,   482,     0,     0,    14,
     148,     0,   149,   150,   151,   140,   141,   142,   143,     0,
     107,     0,   108,     0,     0,   442,     0,   176,   455,   503,
     502,     0,     0,   504,     0,     0,     0,     0,   428,   432,
     450,   431,   454,   452,   451,   453,     0,     0,     0,   444,
     507,   508,   505,   506,   509,   447,   372,   374,   373,   370,
     367,   228,   274,   358,     0,   412,   399,   401,    91,     0,
      76,    77,    89,    74,    75,     0,    84,    85,    82,    83,
       0,    68,   354,     0,     0,   405,     0,   408,   158,   125,
     126,   119,     0,   121,   118,     0,     0,     0,   116,     0,
       0,    63,    57,   132,   131,     0,   129,    11,   363,     0,
     322,   316,   313,     0,     0,     0,   310,     0,     0,     0,
       0,     0,   162,     7,   416,   417,   422,     0,     0,   496,
     494,     0,     0,     0,     0,     0,     0,     0,   477,     0,
     475,   152,   144,   145,   146,   138,   109,   449,   445,   524,
     523,   522,   518,     0,   436,   517,   429,     0,     0,   434,
     433,   438,   440,     0,   359,    92,    78,    79,    86,    87,
     355,   406,   409,   123,   120,     0,   122,     0,    59,     0,
     133,   364,     0,   330,   324,     0,   323,   325,   331,   328,
     318,     0,   317,   319,   329,   344,   305,     0,     0,     0,
       0,     0,     0,     0,   426,   424,   511,   512,   510,     0,
     483,   484,     0,   480,     0,   147,   521,   520,   519,   514,
     515,   430,   516,   124,   165,    65,   365,   315,   326,   327,
     314,   320,   321,   306,   307,     0,     0,   163,     0,   159,
       0,     0,     0,   478,   476,   308,     0,     0,   513,   485,
     481,     0,   160,   164
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -641,  -641,  -641,   747,   752,  -641,   768,  -641,   542,   545,
    -305,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -429,  -641,  -641,  -641,  -641,  -641,
     651,   284,  -379,   772,     8,    -6,  -641,  -641,   754,  -641,
    -641,   289,   446,  -246,  -641,  -641,   278,  -641,   556,   567,
     219,  -641,  -641,   233,  -598,  -641,   -65,  -641,  -641,  -641,
     257,  -641,  -641,   550,   571,   214,  -579,   534,   192,  -342,
     193,   206,  -641,  -641,  -641,  -641,  -641,   753,  -641,  -641,
    -641,  -641,  -641,  -641,   748,  -641,   -44,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,    69,  -641,  -641,  -641,   380,   176,
    -641,  -341,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -430,  -641,   272,  -641,   441,  -641,  -641,  -641,  -641,
    -641,    64,    74,  -582,  -440,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,   540,  -222,  -357,  -641,  -641,
     204,  -358,  -641,  -641,  -641,  -641,  -641,  -641,  -641,   866,
     869,   -82,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
     402,  -641,  -641,   238,   221,   222,   403,  -641,  -641,   241,
    -641,  -478,  -641,  -641,  -641,  -641,   135,  -302,  -641,   436,
     110,  -641,  -434,  -641,  -641,  -641,  -641,  -640,  -641,  -641,
    -641,  -641,   123,   243,  -641
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   590,   252,   111,   112,   113,   114,
     397,   398,   615,   115,   116,   117,   118,   119,   120,   121,
     244,   245,   423,   424,   122,   254,   255,   327,   328,   490,
     491,   655,   656,   657,   658,   123,   241,   242,   124,   625,
     626,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   346,   347,
     348,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   373,   374,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   203,
     168,   169,   170,   617,   454,   455,   752,   831,   832,   825,
     826,   833,   827,   618,   619,   171,   172,   620,   173,   174,
     175,   176,   177,   178,   179,   534,   407,   529,   699,   530,
     531,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   547,   190,   191,   192,   193,   194,   195,   196,   287,
     507,   678,   508,   509,   510,   511,   512,   513,   514,   679,
     680,   306,   307,   308,   309,   310,   852,   853,   311,   476,
     480,   644,   477,   312,   313,   682,   695,   776,   683,   684,
     689,   685,   859,   792,   667
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       202,   592,   484,   532,   532,   533,   272,   435,   506,   198,
     200,   518,   519,   520,   521,   487,   556,   404,   417,   420,
     205,   425,   563,   616,   210,   270,   271,   404,   420,   463,
     681,   436,   793,     7,   206,   756,   608,   609,   532,   557,
     610,   266,   641,   231,   532,   564,   532,   567,   803,   236,
     597,   750,   451,   451,   769,   246,   608,   609,   783,   784,
     610,   257,    18,   353,    27,   260,    29,   441,    31,    32,
     611,   381,   262,   478,   247,   237,   281,   282,   283,   285,
     263,   856,   274,   209,   276,   277,   278,   857,   581,    40,
     611,   735,   421,   350,   354,   434,   213,   796,   481,   222,
     223,   584,   608,   609,   858,   612,   610,   613,   321,   227,
     385,   474,   215,   204,   355,   549,   214,   351,   452,   621,
      50,   321,   608,   609,   503,   612,   610,   613,   321,   387,
     504,   647,   216,   412,   350,   558,   611,   558,   550,   414,
     267,   555,   321,   321,   321,   321,   777,   779,   352,   882,
     882,   842,   880,   228,   321,   357,   611,   321,   351,   479,
     356,   555,   321,   506,   506,   742,   321,   358,    59,   321,
     212,   612,   207,   613,   751,   248,   756,   582,   711,   586,
     714,   648,   382,   208,   855,   717,   719,   616,    59,   770,
     598,   612,   616,   613,   422,   464,   465,   614,    73,   475,
     800,   442,   532,   715,   466,   453,   622,   555,   532,   720,
     881,   641,   383,   238,   526,   264,   379,   755,    73,   861,
     375,   386,    79,   377,   239,   422,    87,   555,   422,   422,
     702,   404,    13,   843,    59,   321,   380,   394,   422,   422,
     388,   526,    79,   505,   413,    17,   559,   560,   565,   566,
     415,   384,   321,   427,    59,   438,   457,   778,   780,    13,
     883,   884,   389,   757,    73,   408,   532,   760,    36,   759,
     411,   321,    17,   321,   440,   447,    42,   456,   468,   404,
     321,   321,   217,   839,    73,   321,   823,   211,    79,   823,
     608,   321,    42,   608,   610,    36,   321,   610,   321,   321,
     357,   219,   218,    42,   249,   548,   416,   527,    79,   368,
     828,   834,   358,   224,   461,   488,   489,   492,   489,   494,
     395,   396,     7,    56,   789,   481,   539,   540,   616,   225,
     572,   708,   573,   506,   527,   797,   807,   394,    60,   736,
     405,   809,    62,   458,   487,   506,   506,   406,   250,   226,
      56,    18,   724,   220,   577,    66,    67,   221,   482,   612,
     459,   613,   612,   651,   613,    60,   726,   624,   232,    75,
     824,   229,    67,   868,   551,   543,   538,     3,    40,   544,
     541,   605,    66,    67,     4,     5,   828,   528,   701,   748,
     865,   462,   834,   787,   761,   555,    75,   552,   555,   804,
     568,   653,   654,    13,   805,   251,   810,   866,   725,    50,
     574,   483,   576,   503,   528,   579,    17,   230,   790,   504,
     401,   402,   727,   791,   322,    46,   771,   772,   595,   846,
     847,   848,   849,   357,   554,   562,   608,   773,   774,    36,
     610,   710,   495,   235,   606,   358,    52,    42,   471,   829,
     775,   240,   650,   324,   604,   555,   555,   472,   630,   631,
     632,   633,   555,   635,   636,   651,   638,   322,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,   359,   243,   628,   323,   629,   713,   569,   660,
     652,   662,   716,   856,    56,   570,   324,   370,   371,   857,
     253,   360,   608,   653,   654,   612,   610,   613,   555,    60,
     258,   663,   259,   555,   718,   829,   858,   830,   532,   886,
      48,    49,   325,   806,   808,   261,    66,    67,   690,   691,
     692,   693,   265,   376,    72,   555,   771,   772,   888,   378,
      75,   555,   515,   516,   555,   555,   668,   773,   774,   542,
     522,   523,   542,   704,   542,   268,   694,   696,   697,   698,
     500,   501,   502,   709,   721,   524,   525,   535,   535,   728,
     269,   612,   273,   613,   275,   731,   279,   733,   734,   723,
     890,   280,   739,   871,   639,   640,   286,   314,   321,   319,
     743,   744,   668,   320,   330,   329,   349,   361,   362,   364,
     363,   372,   390,   391,   392,   393,   399,   555,   409,   400,
     410,   418,   419,   426,   429,   431,    81,   428,   430,   432,
     433,   437,   764,   765,   439,   443,   669,   444,   766,   670,
     288,   289,   445,   290,   291,   671,   672,   673,    87,   446,
     448,   449,   460,   674,   292,   450,   293,   467,   469,   470,
     473,   497,   675,   489,   526,   786,   545,   294,   676,   677,
     546,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   669,   553,   561,   670,   288,   289,   575,   290,
     291,   671,   672,   673,   571,   578,   580,   587,   589,   583,
     292,   588,   293,   591,   593,   594,   599,   596,   675,   600,
     624,   602,   601,   294,   798,   677,   607,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   627,   634,
     642,   637,   643,   646,   659,   666,   813,   331,   686,   814,
     661,   816,   649,   700,   687,   332,   706,   688,   333,   820,
     334,   404,   288,   289,   705,   290,   291,   707,   394,   729,
     730,   335,   732,   737,   740,   336,   292,   822,   293,   741,
     337,   844,   845,   745,   747,   749,   338,   753,   754,   294,
     767,   763,   651,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   781,   768,   815,   788,   339,   817,
     811,   812,   818,   835,   837,   819,   836,   838,   840,     1,
     841,   850,   867,   851,     2,     3,   481,   870,   873,   863,
     862,   864,     4,     5,     6,   875,     7,   874,   876,     8,
     885,     9,    10,   340,   341,   342,   343,   344,   345,    11,
      12,    13,    14,   878,   889,   877,   315,   879,    15,   887,
     891,   316,   712,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
     317,   485,    33,    34,   486,   318,    35,    36,    37,    38,
      39,   585,    40,   326,    41,    42,   738,   746,   785,   498,
     403,   892,   762,   496,    43,   893,   517,    44,    45,   782,
      46,   493,   369,   367,   758,   623,   872,    47,    48,    49,
     869,   499,   233,    50,   536,   234,   664,   801,   665,   802,
      51,    52,   794,    53,   854,    54,   645,    55,   795,   799,
     860,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,    58,    59,     0,     0,    60,     0,    61,
      62,     0,     0,    63,    64,     0,    65,     0,     0,     0,
       0,     0,     0,     0,    66,    67,    68,     0,    69,    70,
      71,     0,    72,     0,    73,     0,     0,    74,    75,     0,
       0,     0,    76,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     1,    79,     0,
      80,     0,     2,     3,    81,    82,    83,    84,    85,     0,
       4,     5,     6,    86,     7,     0,     0,     8,     0,     9,
      10,     0,     0,     0,     0,     0,    87,    11,    12,    13,
      14,     0,     0,     0,     0,     0,    15,     0,     0,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     0,     0,
      33,    34,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,    42,     0,     0,     0,     0,     0,     0,
       0,     0,    43,     0,     0,    44,    45,     0,    46,     0,
       0,     0,     0,     0,     0,    47,    48,    49,     0,     0,
       0,    50,     0,     0,     0,     0,     0,     0,    51,    52,
       0,    53,     0,    54,     0,    55,     0,     0,     0,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,    58,    59,     0,     0,    60,     0,    61,    62,     0,
       0,    63,    64,     0,    65,     0,     0,     0,     0,     0,
       0,     0,    66,    67,    68,     0,    69,    70,    71,     0,
      72,     0,    73,     0,     0,    74,    75,     0,     0,     0,
      76,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     1,    79,     0,     0,     0,
       2,     3,    81,    82,    83,    84,    85,     0,     4,     5,
       6,    86,     7,     0,     0,     8,     0,     9,    10,     0,
       0,     0,     0,     0,    87,    11,    12,    13,    14,     0,
       0,     0,     0,     0,    15,     0,     0,     0,     0,    16,
      17,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,    34,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,    42,     0,     0,     0,     0,     0,     0,     0,     0,
      43,     0,     0,    44,    45,     0,    46,     0,     0,     0,
       0,     0,     0,    47,     0,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,    51,    52,     0,    53,
       0,    54,     0,     0,     0,     0,     0,     0,    56,     0,
       0,     0,     0,     0,     0,     0,     0,    57,     0,    58,
      59,     0,     0,    60,     0,    61,    62,     0,     0,    63,
      64,     0,    65,     0,     0,     0,     0,     0,     0,     0,
      66,    67,    68,     0,    69,    70,    71,     0,    72,     0,
      73,     0,     0,    74,    75,     0,     0,     0,    76,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,    79,     0,     0,     0,     0,     0,
       1,    82,    83,    84,    85,     2,     3,     0,     0,    86,
     284,     0,     0,     4,     5,     6,     0,     7,     0,     0,
       8,     0,     9,    10,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,    16,    17,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,     0,     0,    35,    36,    37,
      38,    39,     0,    40,     0,    41,    42,     0,     0,     0,
       0,     0,     0,     0,     0,    43,     0,     0,    44,    45,
       0,    46,     0,     0,     0,     0,     0,     0,    47,     0,
       0,     0,     0,     0,    50,     0,     0,     0,     0,     0,
       0,    51,    52,     0,    53,     0,    54,     0,     0,     0,
       0,     0,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,    57,     0,    58,    59,     0,     0,    60,     0,
      61,    62,     0,     0,    63,    64,     0,    65,     0,   197,
       0,     0,     0,     0,     0,    66,    67,    68,     0,    69,
      70,    71,     0,    72,     0,    73,     0,     0,    74,    75,
       0,     0,     0,    76,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,     0,     1,    79,
       0,     0,     0,     2,     3,     0,    82,    83,    84,    85,
       0,     4,     5,     6,    86,     7,     0,     0,     8,     0,
       9,    10,     0,     0,     0,     0,     0,     0,    11,    12,
      13,    14,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,    16,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,    42,     0,     0,     0,     0,     0,
       0,     0,     0,    43,     0,     0,    44,    45,     0,    46,
       0,     0,     0,     0,     0,     0,    47,     0,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,    51,
      52,     0,    53,     0,    54,     0,     0,     0,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
      57,     0,    58,    59,     0,     0,    60,     0,    61,    62,
       0,     0,    63,    64,     0,    65,     0,   199,     0,     0,
       0,     0,     0,    66,    67,    68,     0,    69,    70,    71,
       0,    72,     0,    73,     0,     0,    74,    75,     0,     0,
       0,    76,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     1,    79,     0,     0,
       0,     2,     3,     0,    82,    83,    84,    85,     0,     4,
       5,     6,    86,     7,     0,     0,     8,     0,     9,    10,
       0,     0,     0,     0,     0,     0,    11,    12,    13,    14,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
      16,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,     0,     0,    35,    36,    37,    38,    39,     0,    40,
       0,    41,    42,     0,     0,     0,     0,     0,     0,     0,
       0,    43,     0,     0,    44,    45,     0,    46,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
      50,     0,     0,     0,     0,     0,     0,    51,    52,     0,
      53,     0,    54,     0,     0,     0,     0,     0,     0,    56,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
      58,    59,     0,     0,    60,     0,    61,    62,     0,     0,
      63,    64,     0,    65,     0,     0,     0,     0,   201,     0,
       0,    66,    67,    68,     0,    69,    70,    71,     0,    72,
       0,    73,     0,     0,    74,    75,     0,     0,     0,    76,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,     0,     1,    79,     0,     0,     0,     2,
       3,     0,    82,    83,    84,    85,     0,     4,     5,     6,
      86,     7,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,     0,     0,    11,    12,    13,    14,     0,     0,
       0,     0,     0,    15,     0,     0,     0,     0,    16,    17,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,     0,
       0,    35,    36,    37,    38,    39,     0,    40,     0,    41,
      42,     0,     0,     0,     0,     0,     0,     0,     0,    43,
       0,     0,    44,    45,     0,    46,     0,     0,     0,     0,
       0,     0,    47,     0,     0,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,    51,    52,     0,    53,     0,
      54,     0,     0,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    57,     0,    58,    59,
       0,     0,    60,     0,    61,    62,     0,     0,    63,    64,
       0,    65,     0,     0,     0,     0,   256,     0,     0,    66,
      67,    68,     0,    69,    70,    71,     0,    72,     0,    73,
       0,     0,    74,    75,     0,     0,     0,    76,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       0,     0,     1,    79,     0,     0,     0,     2,     3,     0,
      82,    83,    84,    85,     0,     4,     5,     6,    86,     7,
       0,     0,     8,     0,     9,    10,     0,     0,     0,     0,
       0,     0,    11,    12,    13,    14,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,    42,     0,
       0,     0,     0,     0,     0,     0,     0,    43,     0,     0,
      44,    45,     0,    46,     0,     0,     0,     0,     0,     0,
      47,     0,     0,     0,     0,     0,    50,     0,     0,     0,
       0,     0,     0,    51,    52,     0,    53,     0,    54,     0,
       0,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,    58,    59,     0,     0,
      60,     0,    61,    62,     0,     0,    63,    64,     0,    65,
       0,   537,     0,     0,     0,     0,     0,    66,    67,    68,
       0,    69,    70,    71,     0,    72,     0,    73,     0,     0,
      74,    75,     0,     0,     0,    76,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
       1,    79,     0,     0,     0,     2,     3,     0,    82,    83,
      84,    85,     0,     4,     5,     6,    86,     7,     0,     0,
       8,     0,     9,    10,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,    16,    17,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,     0,     0,    35,    36,    37,
      38,    39,     0,    40,     0,    41,    42,     0,     0,     0,
       0,     0,     0,     0,     0,    43,     0,     0,    44,    45,
       0,    46,     0,     0,     0,     0,     0,     0,    47,     0,
       0,     0,     0,     0,    50,     0,     0,     0,     0,     0,
       0,    51,    52,     0,    53,     0,    54,     0,     0,     0,
       0,     0,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,    57,     0,    58,    59,     0,     0,    60,     0,
      61,    62,     0,     0,    63,    64,     0,    65,     0,   603,
       0,     0,     0,     0,     0,    66,    67,    68,     0,    69,
      70,    71,     0,    72,     0,    73,     0,     0,    74,    75,
       0,     0,     0,    76,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,     0,     1,    79,
       0,     0,     0,     2,     3,     0,    82,    83,    84,    85,
       0,     4,     5,     6,    86,     7,     0,     0,     8,     0,
       9,    10,     0,     0,     0,     0,     0,     0,    11,    12,
      13,    14,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,    16,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,    42,     0,     0,     0,     0,     0,
       0,     0,     0,    43,     0,     0,    44,    45,     0,    46,
       0,     0,     0,     0,     0,     0,    47,     0,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,    51,
      52,     0,    53,     0,    54,     0,     0,     0,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
      57,     0,    58,    59,     0,     0,    60,     0,    61,    62,
       0,     0,    63,    64,     0,    65,     0,   703,     0,     0,
       0,     0,     0,    66,    67,    68,     0,    69,    70,    71,
       0,    72,     0,    73,     0,     0,    74,    75,     0,     0,
       0,    76,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     1,    79,     0,     0,
       0,     2,     3,     0,    82,    83,    84,    85,     0,     4,
       5,     6,    86,     7,     0,     0,     8,     0,     9,    10,
       0,     0,     0,     0,     0,     0,    11,    12,    13,    14,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
      16,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,     0,     0,    35,    36,    37,    38,    39,     0,    40,
       0,    41,    42,     0,     0,     0,     0,     0,     0,     0,
       0,    43,     0,     0,    44,    45,     0,    46,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
      50,     0,     0,     0,     0,     0,     0,    51,    52,     0,
      53,     0,    54,     0,     0,     0,     0,     0,     0,    56,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
      58,    59,     0,     0,    60,     0,    61,    62,     0,     0,
      63,    64,     0,    65,     0,   722,     0,     0,     0,     0,
       0,    66,    67,    68,     0,    69,    70,    71,     0,    72,
       0,    73,     0,     0,    74,    75,     0,     0,     0,    76,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,     0,     1,    79,     0,     0,     0,     2,
       3,     0,    82,    83,    84,    85,     0,     4,     5,     6,
      86,     7,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,     0,     0,    11,    12,    13,    14,     0,     0,
       0,     0,     0,    15,     0,     0,     0,     0,    16,    17,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,     0,
       0,    35,    36,    37,    38,    39,     0,    40,     0,    41,
      42,     0,     0,     0,     0,     0,     0,     0,     0,    43,
       0,     0,    44,    45,     0,    46,     0,     0,     0,     0,
       0,     0,    47,     0,     0,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,    51,    52,     0,    53,     0,
      54,     0,     0,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    57,     0,    58,    59,
       0,     0,    60,     0,    61,    62,     0,     0,    63,    64,
       0,    65,     0,   821,     0,     0,     0,     0,     0,    66,
      67,    68,     0,    69,    70,    71,     0,    72,     0,    73,
       0,     0,    74,    75,     0,     0,     0,    76,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       0,     0,     1,    79,     0,     0,     0,     2,     3,     0,
      82,    83,    84,    85,     0,     4,     5,     6,    86,     7,
       0,     0,     8,     0,     9,    10,     0,     0,     0,     0,
       0,     0,    11,    12,    13,    14,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,    42,     0,
       0,     0,     0,     0,     0,     0,     0,    43,     0,     0,
      44,    45,     0,    46,     0,     0,     0,     0,     0,     0,
      47,     0,     0,     0,     0,     0,    50,     0,     0,     0,
       0,     0,     0,    51,    52,     0,    53,     0,    54,     0,
       0,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,    58,    59,     0,     0,
      60,     0,    61,    62,     0,     0,    63,    64,     0,    65,
       0,     0,     0,     0,     0,     0,     0,    66,    67,    68,
       0,    69,    70,    71,     0,    72,     0,    73,     0,     0,
      74,    75,     0,     0,     0,    76,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
       1,    79,     0,     0,     0,     2,     3,     0,    82,    83,
      84,    85,     0,     4,     5,     6,    86,     7,     0,     0,
       8,     0,     9,    10,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,    16,    17,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,     0,     0,    35,    36,    37,
      38,    39,     0,    40,     0,    41,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,     0,     0,     0,     0,
       0,    51,     0,     0,    53,     0,   365,     0,     0,     0,
       0,     0,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,    57,     0,    58,    59,     0,     0,    60,     0,
     366,    62,     0,     0,    63,    64,     0,    65,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,     0,    69,
      70,     0,     0,    72,     0,    73,     0,     0,    74,    75,
       0,     0,     0,     1,     0,     0,    77,     0,     2,     3,
       0,     0,     0,     0,    78,     0,     4,     5,     6,    79,
       7,     0,     0,     8,     0,     9,    10,     0,     0,     0,
       0,     0,     0,    11,    12,    13,    14,     0,     0,     0,
       0,     0,    15,     0,     0,     0,     0,    16,    17,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,    34,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    44,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,    51,     0,     0,    53,     0,    54,
       0,     0,     0,     0,     0,     0,    56,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,    58,    59,     0,
       0,    60,     0,    61,    62,     0,     0,    63,    64,     0,
      65,     0,     0,     0,     0,     0,     0,     0,    66,    67,
      68,     0,    69,    70,     0,     0,    72,     0,    73,     0,
       0,    74,    75,     0,     0,     0,     1,     0,     0,    77,
       0,     2,     3,     0,     0,     0,     0,    78,     0,     4,
       5,     6,    79,     7,     0,     0,     0,     0,     9,    10,
       0,     0,     0,     0,     0,     0,    11,    12,    13,    14,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
      16,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,     0,     0,    35,    36,    37,    38,    39,     0,    40,
       0,    41,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
      58,    59,     0,     0,    60,     0,     0,     0,     0,     0,
      63,    64,     0,    65,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,     0,     0,     0,     0,     0,    72,
       0,    73,     0,     0,    74,    75,     0,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         6,   430,   304,   361,   362,   362,    71,   253,   349,     1,
       2,   353,   354,   355,   356,   320,   395,    30,   240,    32,
      12,   243,   401,   453,    16,    69,    70,    30,    32,    30,
     508,   253,   672,    21,    18,   617,     7,     8,   396,   396,
      11,    13,   476,    35,   402,   402,   404,   404,   688,    41,
      98,    29,    18,    18,    21,    47,     7,     8,   656,   657,
      11,    53,    50,    70,    59,    57,    61,     6,    63,    64,
      41,    45,    13,    32,    22,    18,    82,    83,    84,    85,
      21,   238,    74,    14,    76,    77,    78,   244,   105,    77,
      41,   105,   105,   120,   101,    98,   150,   676,    32,    82,
      83,   105,     7,     8,   261,    76,    11,    78,    45,   135,
      45,    90,   150,   112,   121,   106,   170,   144,    84,    84,
     108,    45,     7,     8,   112,    76,    11,    78,    45,    45,
     118,    65,   170,    45,   120,    45,    41,    45,   129,    45,
     112,   112,    45,    45,    45,    45,    45,    45,   175,    45,
      45,    73,   175,   179,    45,   178,    41,    45,   144,   118,
     167,   112,    45,   504,   505,   594,    45,   190,   139,    45,
      22,    76,   156,    78,   152,   123,   758,   423,   557,   425,
     559,   483,   156,   167,   782,   564,   565,   617,   139,   156,
     436,    76,   622,    78,   242,   196,   197,   168,   169,   178,
     678,   140,   560,   560,   205,   171,   171,   112,   566,   566,
     850,   645,   204,   156,    18,   156,   153,   168,   169,   798,
     151,   156,   193,   154,   167,   242,   221,   112,   242,   242,
     154,    30,    36,   155,   139,    45,   153,    73,   242,   242,
     156,    18,   193,   231,   156,    49,   156,   157,   156,   157,
     156,   153,    45,   156,   139,   156,   156,   156,   156,    36,
     156,   156,   153,   168,   169,   153,   624,   624,    72,    73,
     153,    45,    49,    45,   153,   267,    80,   153,   284,    30,
      45,    45,   130,   168,   169,    45,     3,   156,   193,     3,
       7,    45,    80,     7,    11,    72,    45,    11,    45,    45,
     178,    22,   150,    80,    22,   387,   105,   111,   193,   112,
     750,   751,   190,    19,    85,   321,   322,   323,   324,   325,
     156,   157,    21,   127,   666,    32,   370,   371,   758,    13,
     412,   553,   414,   674,   111,   677,   715,    73,   142,   585,
      91,   720,   145,   153,   649,   686,   687,    98,    66,    18,
     127,    50,   100,   123,   419,   159,   160,   123,    65,    76,
     153,    78,    76,    44,    78,   142,   100,    38,   156,   173,
      87,    19,   160,    87,   106,   381,   368,    10,    77,   153,
     372,   153,   159,   160,    17,    18,   826,   191,   153,   153,
     819,   162,   832,   153,    65,   112,   173,   129,   112,   153,
     406,    82,    83,    36,   153,   123,   153,   153,   156,   108,
     416,   118,   418,   112,   191,   421,    49,    23,   238,   118,
     156,   157,   156,   243,   137,    95,   216,   217,   434,   771,
     772,   773,   774,   178,    91,    91,     7,   227,   228,    72,
      11,    91,   155,    23,   450,   190,   116,    80,   198,    20,
     240,    23,    31,   166,   446,   112,   112,   207,   464,   465,
     466,   467,   112,   469,   470,    44,   472,   137,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    90,    23,   204,   155,   206,    91,    91,   495,
      69,   497,    91,   238,   127,    98,   166,   163,   164,   244,
      23,   109,     7,    82,    83,    76,    11,    78,   112,   142,
      13,   503,   156,   112,    91,    20,   261,    88,   876,   876,
     103,   104,   192,    91,    91,    15,   159,   160,   211,   212,
     213,   214,    18,   153,   167,   112,   216,   217,   880,   159,
     173,   112,   350,   351,   112,   112,   135,   227,   228,   373,
     357,   358,   376,   545,   378,    18,   239,   131,   132,   133,
     346,   347,   348,   555,   570,   359,   360,   363,   364,   575,
      18,    76,    18,    78,   156,   581,    12,   583,   584,   571,
     882,    21,   588,    88,   474,   475,    23,     0,    45,   162,
     596,   597,   135,   162,    28,   134,   230,   107,   176,    40,
      39,   113,    45,    45,    22,    22,    86,   112,   156,    21,
     156,   158,   198,    45,    13,   123,   199,    32,    32,    13,
      22,    45,   628,   629,    86,   156,   215,   156,   634,   218,
     219,   220,    16,   222,   223,   224,   225,   226,   221,   112,
     156,   156,   194,   232,   233,   158,   235,    30,   210,    98,
      21,   155,   241,   659,    18,   661,   112,   246,   247,   248,
      18,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   215,    23,    22,   218,   219,   220,   105,   222,
     223,   224,   225,   226,   112,    73,    73,    73,    22,   105,
     233,   174,   235,    86,    86,    32,    73,    98,   241,    22,
      38,   146,   140,   246,   247,   248,    86,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    21,   210,
      21,    23,    21,    21,    45,   249,   732,    86,   229,   735,
     155,   737,   162,   100,   236,    94,   156,   237,    97,   745,
      99,    30,   219,   220,   100,   222,   223,   156,    73,    23,
      23,   110,   105,   105,    45,   114,   233,   749,   235,    22,
     119,   767,   768,    98,   162,   112,   125,     6,    18,   246,
      98,   162,    44,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    22,   155,   105,   156,   147,    81,
     156,   156,    22,    42,    18,    32,   171,    18,    23,     4,
     155,    21,    29,   234,     9,    10,    32,   152,   171,   815,
     245,   817,    17,    18,    19,    18,    21,   171,    30,    24,
     171,    26,    27,   182,   183,   184,   185,   186,   187,    34,
      35,    36,    37,    23,   234,   841,    89,   843,    43,   155,
     155,    89,   558,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      92,   319,    67,    68,   319,    93,    71,    72,    73,    74,
      75,   425,    77,   119,    79,    80,   587,   599,   659,   329,
     229,   887,   625,   327,    89,   891,   352,    92,    93,   656,
      95,   324,   144,   140,   622,   454,   832,   102,   103,   104,
     826,   330,    36,   108,   364,    36,   504,   686,   505,   687,
     115,   116,   674,   118,   779,   120,   480,   122,   675,   678,
     797,    -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,   138,   139,    -1,    -1,   142,    -1,   144,
     145,    -1,    -1,   148,   149,    -1,   151,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,   161,    -1,   163,   164,
     165,    -1,   167,    -1,   169,    -1,    -1,   172,   173,    -1,
      -1,    -1,   177,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,     4,   193,    -1,
     195,    -1,     9,    10,   199,   200,   201,   202,   203,    -1,
      17,    18,    19,   208,    21,    -1,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    -1,    -1,   221,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      67,    68,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,   104,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,   115,   116,
      -1,   118,    -1,   120,    -1,   122,    -1,    -1,    -1,    -1,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,   139,    -1,    -1,   142,    -1,   144,   145,    -1,
      -1,   148,   149,    -1,   151,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   160,   161,    -1,   163,   164,   165,    -1,
     167,    -1,   169,    -1,    -1,   172,   173,    -1,    -1,    -1,
     177,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,     4,   193,    -1,    -1,    -1,
       9,    10,   199,   200,   201,   202,   203,    -1,    17,    18,
      19,   208,    21,    -1,    -1,    24,    -1,    26,    27,    -1,
      -1,    -1,    -1,    -1,   221,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    92,    93,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,   108,
      -1,    -1,    -1,    -1,    -1,    -1,   115,   116,    -1,   118,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     139,    -1,    -1,   142,    -1,   144,   145,    -1,    -1,   148,
     149,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,   161,    -1,   163,   164,   165,    -1,   167,    -1,
     169,    -1,    -1,   172,   173,    -1,    -1,    -1,   177,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
       4,   200,   201,   202,   203,     9,    10,    -1,    -1,   208,
     209,    -1,    -1,    17,    18,    19,    -1,    21,    -1,    -1,
      24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,
      74,    75,    -1,    77,    -1,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,
      -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,
      -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,
      -1,   115,   116,    -1,   118,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,   139,    -1,    -1,   142,    -1,
     144,   145,    -1,    -1,   148,   149,    -1,   151,    -1,   153,
      -1,    -1,    -1,    -1,    -1,   159,   160,   161,    -1,   163,
     164,   165,    -1,   167,    -1,   169,    -1,    -1,   172,   173,
      -1,    -1,    -1,   177,    -1,    -1,   180,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,     4,   193,
      -1,    -1,    -1,     9,    10,    -1,   200,   201,   202,   203,
      -1,    17,    18,    19,   208,    21,    -1,    -1,    24,    -1,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,
      -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,   115,
     116,    -1,   118,    -1,   120,    -1,    -1,    -1,    -1,    -1,
      -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,   139,    -1,    -1,   142,    -1,   144,   145,
      -1,    -1,   148,   149,    -1,   151,    -1,   153,    -1,    -1,
      -1,    -1,    -1,   159,   160,   161,    -1,   163,   164,   165,
      -1,   167,    -1,   169,    -1,    -1,   172,   173,    -1,    -1,
      -1,   177,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,     4,   193,    -1,    -1,
      -1,     9,    10,    -1,   200,   201,   202,   203,    -1,    17,
      18,    19,   208,    21,    -1,    -1,    24,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    71,    72,    73,    74,    75,    -1,    77,
      -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    95,    -1,    -1,
      -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,
     108,    -1,    -1,    -1,    -1,    -1,    -1,   115,   116,    -1,
     118,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,   139,    -1,    -1,   142,    -1,   144,   145,    -1,    -1,
     148,   149,    -1,   151,    -1,    -1,    -1,    -1,   156,    -1,
      -1,   159,   160,   161,    -1,   163,   164,   165,    -1,   167,
      -1,   169,    -1,    -1,   172,   173,    -1,    -1,    -1,   177,
      -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,     4,   193,    -1,    -1,    -1,     9,
      10,    -1,   200,   201,   202,   203,    -1,    17,    18,    19,
     208,    21,    -1,    -1,    24,    -1,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    77,    -1,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    93,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,   108,    -1,
      -1,    -1,    -1,    -1,    -1,   115,   116,    -1,   118,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,
      -1,    -1,   142,    -1,   144,   145,    -1,    -1,   148,   149,
      -1,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
     160,   161,    -1,   163,   164,   165,    -1,   167,    -1,   169,
      -1,    -1,   172,   173,    -1,    -1,    -1,   177,    -1,    -1,
     180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,     4,   193,    -1,    -1,    -1,     9,    10,    -1,
     200,   201,   202,   203,    -1,    17,    18,    19,   208,    21,
      -1,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      92,    93,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,
     102,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,    -1,    -1,   115,   116,    -1,   118,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,
     142,    -1,   144,   145,    -1,    -1,   148,   149,    -1,   151,
      -1,   153,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,
      -1,   163,   164,   165,    -1,   167,    -1,   169,    -1,    -1,
     172,   173,    -1,    -1,    -1,   177,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
       4,   193,    -1,    -1,    -1,     9,    10,    -1,   200,   201,
     202,   203,    -1,    17,    18,    19,   208,    21,    -1,    -1,
      24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,
      74,    75,    -1,    77,    -1,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,
      -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,
      -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,
      -1,   115,   116,    -1,   118,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,   139,    -1,    -1,   142,    -1,
     144,   145,    -1,    -1,   148,   149,    -1,   151,    -1,   153,
      -1,    -1,    -1,    -1,    -1,   159,   160,   161,    -1,   163,
     164,   165,    -1,   167,    -1,   169,    -1,    -1,   172,   173,
      -1,    -1,    -1,   177,    -1,    -1,   180,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,     4,   193,
      -1,    -1,    -1,     9,    10,    -1,   200,   201,   202,   203,
      -1,    17,    18,    19,   208,    21,    -1,    -1,    24,    -1,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,
      -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,   115,
     116,    -1,   118,    -1,   120,    -1,    -1,    -1,    -1,    -1,
      -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,   139,    -1,    -1,   142,    -1,   144,   145,
      -1,    -1,   148,   149,    -1,   151,    -1,   153,    -1,    -1,
      -1,    -1,    -1,   159,   160,   161,    -1,   163,   164,   165,
      -1,   167,    -1,   169,    -1,    -1,   172,   173,    -1,    -1,
      -1,   177,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,     4,   193,    -1,    -1,
      -1,     9,    10,    -1,   200,   201,   202,   203,    -1,    17,
      18,    19,   208,    21,    -1,    -1,    24,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    71,    72,    73,    74,    75,    -1,    77,
      -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    95,    -1,    -1,
      -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,
     108,    -1,    -1,    -1,    -1,    -1,    -1,   115,   116,    -1,
     118,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,   139,    -1,    -1,   142,    -1,   144,   145,    -1,    -1,
     148,   149,    -1,   151,    -1,   153,    -1,    -1,    -1,    -1,
      -1,   159,   160,   161,    -1,   163,   164,   165,    -1,   167,
      -1,   169,    -1,    -1,   172,   173,    -1,    -1,    -1,   177,
      -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,     4,   193,    -1,    -1,    -1,     9,
      10,    -1,   200,   201,   202,   203,    -1,    17,    18,    19,
     208,    21,    -1,    -1,    24,    -1,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    77,    -1,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    93,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,   108,    -1,
      -1,    -1,    -1,    -1,    -1,   115,   116,    -1,   118,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,
      -1,    -1,   142,    -1,   144,   145,    -1,    -1,   148,   149,
      -1,   151,    -1,   153,    -1,    -1,    -1,    -1,    -1,   159,
     160,   161,    -1,   163,   164,   165,    -1,   167,    -1,   169,
      -1,    -1,   172,   173,    -1,    -1,    -1,   177,    -1,    -1,
     180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,     4,   193,    -1,    -1,    -1,     9,    10,    -1,
     200,   201,   202,   203,    -1,    17,    18,    19,   208,    21,
      -1,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      92,    93,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,
     102,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,    -1,    -1,   115,   116,    -1,   118,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,
     142,    -1,   144,   145,    -1,    -1,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,
      -1,   163,   164,   165,    -1,   167,    -1,   169,    -1,    -1,
     172,   173,    -1,    -1,    -1,   177,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
       4,   193,    -1,    -1,    -1,     9,    10,    -1,   200,   201,
     202,   203,    -1,    17,    18,    19,   208,    21,    -1,    -1,
      24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,
      74,    75,    -1,    77,    -1,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    -1,   118,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,   139,    -1,    -1,   142,    -1,
     144,   145,    -1,    -1,   148,   149,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,   161,    -1,   163,
     164,    -1,    -1,   167,    -1,   169,    -1,    -1,   172,   173,
      -1,    -1,    -1,     4,    -1,    -1,   180,    -1,     9,    10,
      -1,    -1,    -1,    -1,   188,    -1,    17,    18,    19,   193,
      21,    -1,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,   115,    -1,    -1,   118,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,
      -1,   142,    -1,   144,   145,    -1,    -1,   148,   149,    -1,
     151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
     161,    -1,   163,   164,    -1,    -1,   167,    -1,   169,    -1,
      -1,   172,   173,    -1,    -1,    -1,     4,    -1,    -1,   180,
      -1,     9,    10,    -1,    -1,    -1,    -1,   188,    -1,    17,
      18,    19,   193,    21,    -1,    -1,    -1,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    71,    72,    73,    74,    75,    -1,    77,
      -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,   139,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
     148,   149,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   160,   161,    -1,    -1,    -1,    -1,    -1,   167,
      -1,   169,    -1,    -1,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   193
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,     4,     9,    10,    17,    18,    19,    21,    24,    26,
      27,    34,    35,    36,    37,    43,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    67,    68,    71,    72,    73,    74,    75,
      77,    79,    80,    89,    92,    93,    95,   102,   103,   104,
     108,   115,   116,   118,   120,   122,   127,   136,   138,   139,
     142,   144,   145,   148,   149,   151,   159,   160,   161,   163,
     164,   165,   167,   169,   172,   173,   177,   180,   188,   193,
     195,   199,   200,   201,   202,   203,   208,   221,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   298,   299,   300,   301,   305,   306,   307,   308,   309,
     310,   311,   316,   327,   330,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   382,   383,
     384,   397,   398,   400,   401,   402,   403,   404,   405,   406,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     424,   425,   426,   427,   428,   429,   430,   153,   306,   153,
     306,   156,   307,   381,   112,   306,    18,   156,   167,   366,
     306,   156,    22,   150,   170,   150,   170,   130,   150,    22,
     123,   123,    82,    83,    19,    13,    18,   135,   179,    19,
      23,   306,   156,   421,   422,    23,   306,    18,   156,   167,
      23,   328,   329,    23,   312,   313,   306,    22,   123,    22,
      66,   123,   297,    23,   317,   318,   156,   306,    13,   156,
     306,    15,    13,    21,   156,    18,    13,   112,    18,    18,
     358,   358,   328,    18,   306,   156,   306,   306,   306,    12,
      21,   307,   307,   307,   209,   307,    23,   431,   219,   220,
     222,   223,   233,   235,   246,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   443,   444,   445,   446,
     447,   450,   455,   456,     0,   275,   276,   278,   305,   162,
     162,    45,   137,   155,   166,   192,   310,   319,   320,   134,
      28,    86,    94,    97,    99,   110,   114,   119,   125,   147,
     182,   183,   184,   185,   186,   187,   350,   351,   352,   230,
     120,   144,   175,    70,   101,   121,   167,   178,   190,    90,
     109,   107,   176,    39,    40,   120,   144,   349,   112,   356,
     163,   164,   113,   370,   371,   366,   370,   366,   370,   153,
     153,    45,   156,   306,   153,    45,   156,    45,   156,   153,
      45,    45,    22,    22,    73,   156,   157,   302,   303,    86,
      21,   156,   157,   302,    30,    91,    98,   408,   153,   156,
     156,   153,    45,   156,    45,   156,   105,   408,   158,   198,
      32,   105,   242,   314,   315,   408,    45,   156,    32,    13,
      32,   123,    13,    22,    98,   315,   408,    45,   156,    86,
     153,     6,   140,   156,   156,    16,   112,   306,   156,   156,
     158,    18,    84,   171,   386,   387,   153,   156,   153,   153,
     194,    85,   162,    30,   196,   197,   205,    30,   307,   210,
      98,   198,   207,    21,    90,   178,   451,   454,    32,   118,
     452,    32,    65,   118,   449,   280,   281,   282,   307,   307,
     321,   322,   307,   321,   307,   155,   320,   155,   335,   336,
     337,   337,   337,   112,   118,   231,   373,   432,   434,   435,
     436,   437,   438,   439,   440,   340,   340,   339,   341,   341,
     341,   341,   342,   342,   343,   343,    18,   111,   191,   409,
     411,   412,   413,   409,   407,   412,   407,   153,   306,   358,
     358,   306,   371,   307,   153,   112,    18,   423,   423,   106,
     129,   106,   129,    23,    91,   112,   304,   409,    45,   156,
     157,    22,    91,   304,   409,   156,   157,   409,   307,    91,
      98,   112,   423,   423,   307,   105,   307,   328,    73,   307,
      73,   105,   315,   105,   105,   314,   315,    73,   174,    22,
     296,    86,   296,    86,    32,   307,    98,    98,   315,    73,
      22,   140,   146,   153,   306,   153,   307,    86,     7,     8,
      11,    41,    76,    78,   168,   304,   383,   385,   395,   396,
     399,    84,   171,   387,    38,   331,   332,    21,   204,   206,
     307,   307,   307,   307,   210,   307,   307,    23,   307,   452,
     452,   454,    21,    21,   453,   451,    21,    65,   449,   162,
      31,    44,    69,    82,    83,   323,   324,   325,   326,    45,
     307,   155,   307,   306,   432,   438,   249,   466,   135,   215,
     218,   224,   225,   226,   232,   241,   247,   248,   433,   441,
     442,   443,   457,   460,   461,   463,   229,   236,   237,   462,
     211,   212,   213,   214,   239,   458,   131,   132,   133,   410,
     100,   153,   154,   153,   306,   100,   156,   156,   408,   306,
      91,   304,   303,    91,   304,   409,    91,   304,    91,   304,
     409,   307,   153,   306,   100,   156,   100,   156,   307,    23,
      23,   307,   105,   307,   307,   105,   315,   105,   313,   307,
      45,    22,   296,   307,   307,    98,   318,   162,   153,   112,
      29,   152,   388,     6,    18,   168,   395,   168,   385,    73,
     409,    65,   332,   162,   307,   307,   307,    98,   155,    21,
     156,   216,   217,   227,   228,   240,   459,    45,   156,    45,
     156,    22,   325,   326,   326,   322,   307,   153,   156,   341,
     238,   243,   465,   459,   435,   465,   338,   341,   247,   441,
     443,   436,   437,   459,   153,   153,    91,   304,    91,   304,
     153,   156,   156,   307,   307,   105,   307,    81,    22,    32,
     307,   153,   306,     3,    87,   391,   392,   394,   396,    20,
      88,   389,   390,   393,   396,    42,   171,    18,    18,   168,
      23,   155,    73,   155,   307,   307,   341,   341,   341,   341,
      21,   234,   448,   449,   448,   326,   238,   244,   261,   464,
     464,   338,   245,   307,   307,   296,   153,    29,    87,   394,
     152,    88,   393,   171,   171,    18,    30,   307,    23,   307,
     175,   459,    45,   156,   156,   171,   409,   155,   341,   234,
     449,   155,   307,   307
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  xquery_parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   272,   273,   273,   273,   273,   274,   274,   275,   275,
     276,   277,   278,   278,   278,   279,   279,   280,   280,   281,
     281,   281,   281,   282,   282,   282,   282,   283,   283,   283,
     283,   283,   283,   283,   283,   284,   284,   285,   286,   286,
     287,   287,   288,   289,   290,   290,   291,   291,   292,   292,
     292,   292,   293,   294,   295,   295,   295,   295,   296,   296,
     297,   297,   298,   298,   298,   298,   299,   299,   299,   299,
     300,   300,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   302,   302,
     303,   303,   304,   305,   306,   306,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   308,   308,   308,   308,
     309,   309,   310,   310,   311,   312,   312,   313,   313,   313,
     313,   313,   313,   313,   313,   314,   315,   316,   317,   317,
     318,   318,   318,   318,   319,   320,   320,   321,   321,   322,
     322,   323,   323,   323,   323,   323,   323,   323,   324,   324,
     325,   325,   326,   327,   327,   328,   328,   329,   329,   330,
     330,   331,   331,   332,   332,   333,   334,   334,   335,   335,
     336,   336,   336,   336,   337,   337,   337,   338,   338,   339,
     339,   339,   340,   340,   340,   340,   340,   341,   341,   341,
     342,   342,   342,   343,   343,   344,   344,   345,   345,   346,
     346,   347,   347,   348,   348,   348,   348,   349,   349,   349,
     350,   350,   350,   350,   350,   350,   351,   351,   351,   351,
     351,   351,   352,   352,   352,   353,   353,   354,   354,   355,
     355,   356,   357,   357,   357,   357,   358,   358,   358,   359,
     359,   360,   360,   360,   360,   361,   361,   362,   362,   362,
     362,   362,   362,   362,   363,   363,   364,   364,   365,   365,
     365,   365,   365,   366,   366,   367,   367,   368,   368,   368,
     369,   369,   370,   370,   371,   372,   372,   372,   372,   372,
     372,   372,   372,   373,   373,   374,   374,   374,   375,   376,
     376,   377,   378,   379,   380,   380,   381,   381,   382,   382,
     383,   383,   383,   384,   384,   384,   384,   384,   384,   385,
     385,   386,   386,   387,   388,   388,   389,   389,   390,   390,
     390,   390,   391,   391,   392,   392,   392,   392,   393,   393,
     394,   394,   395,   395,   395,   395,   396,   396,   396,   396,
     396,   397,   398,   398,   399,   400,   400,   400,   400,   400,
     400,   401,   402,   402,   402,   402,   403,   403,   403,   403,
     404,   405,   406,   406,   406,   406,   407,   407,   408,   409,
     409,   409,   410,   410,   410,   411,   411,   411,   412,   413,
     413,   413,   413,   413,   413,   413,   413,   413,   414,   415,
     415,   415,   416,   417,   418,   418,   418,   419,   419,   419,
     419,   419,   420,   421,   421,   421,   421,   421,   421,   421,
     422,   423,   423,   424,   425,   426,   426,   426,   426,   426,
     427,   428,   428,   429,   430,   431,   431,   432,   432,   432,
     432,   433,   433,   433,   433,   434,   434,   435,   435,   436,
     436,   437,   437,   438,   438,   438,   439,   439,   440,   440,
     441,   441,   441,   441,   441,   442,   443,   443,   443,   443,
     443,   443,   443,   444,   444,   444,   444,   445,   445,   445,
     445,   446,   446,   447,   447,   447,   447,   447,   447,   447,
     448,   448,   449,   449,   449,   449,   450,   450,   450,   450,
     450,   451,   451,   452,   452,   453,   453,   454,   454,   455,
     456,   456,   457,   457,   457,   458,   458,   458,   458,   458,
     459,   459,   459,   459,   460,   461,   462,   463,   463,   464,
     464,   464,   465,   465,   466
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     3,     5,     2,     1,
       2,     5,     2,     2,     4,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     2,     2,
       3,     3,     3,     2,     2,     2,     2,     2,     4,     4,
       4,     4,     2,     2,     2,     3,     4,     5,     1,     3,
       3,     2,     2,     5,     4,     7,     4,     3,     5,     4,
       2,     2,     4,     4,     5,     5,     5,     5,     6,     6,
       4,     4,     5,     5,     5,     5,     6,     6,     1,     3,
       2,     3,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     4,     5,
       1,     2,     1,     1,     2,     1,     4,     3,     4,     4,
       5,     4,     5,     5,     6,     3,     3,     2,     1,     4,
       3,     4,     4,     5,     2,     2,     2,     1,     3,     1,
       2,     1,     1,     1,     2,     2,     2,     3,     1,     1,
       1,     1,     2,     4,     4,     1,     3,     3,     4,     7,
       9,     1,     2,     4,     7,     7,     1,     3,     1,     3,
       1,     3,     3,     3,     1,     3,     4,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     2,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     4,     1,
       2,     4,     1,     2,     2,     1,     1,     3,     3,     1,
       1,     1,     2,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     1,     3,     3,     2,     3,     1,     3,     1,     1,
       1,     1,     1,     3,     4,     6,     7,     7,     8,     1,
       2,     1,     2,     3,     3,     3,     0,     1,     1,     1,
       2,     2,     0,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     4,     3,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     5,     6,     2,     3,     5,     6,
       3,     3,     4,     5,     6,     7,     1,     2,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     3,     2,     2,     2,     3,     3,     2,     3,     5,
       3,     5,     3,     2,     3,     5,     6,     3,     5,     6,
       3,     1,     2,     1,     1,     4,     5,     5,     4,     4,
       2,     4,     5,     4,     6,     3,     5,     1,     2,     3,
       4,     1,     1,     2,     2,     1,     3,     1,     3,     1,
       3,     1,     2,     1,     2,     3,     1,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     4,     6,     4,     6,     1,
       1,     3,     2,     4,     4,     6,     2,     3,     1,     2,
       1,     1,     2,     2,     3,     1,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     4,     3,     3,     3,     2,     2,     1,
       1,     1,     1,     1,     2
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const xquery_parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined",
  "\"'apos attribute content'\"", "\"'<attribute QName {>'\"",
  "\"'<at URI>'\"", "\"'char literal'\"", "\"'#charref;'\"",
  "\"'element content'\"", "\"'<QName {>'\"", "\"'pref:*'\"",
  "\"'&entity;'\"", "\"'comment literal'\"", "\"'NCName'\"",
  "\"'pi <NCName {>'\"", "\"'pi target'\"", "\"'pragma literal'\"",
  "\"'*:QName'\"", "\"'QName'\"", "\"'<QName (>'\"",
  "\"'quote attribute content'\"", "\"'STRING'\"", "\"'URI'\"",
  "\"'variable name'\"", "\"'validate mode'\"", "\"'XML comment'\"",
  "\"'ancestor::'\"", "\"'ancestor-or-self::'\"", "\"'and'\"", "\"'''\"",
  "\"'as'\"", "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"",
  "\"'attribute::'\"", "\"'<attribute {>'\"", "\"'<attribute (>'\"",
  "\"'@'\"", "\"'case'\"", "\"'<castable as>'\"", "\"'<cast as>'\"",
  "\"'CDATA[['\"", "\"']]'\"", "\"'child::'\"", "\"'collation'\"",
  "\"','\"", "\"'(:'\"", "\"':)'\"", "\"'<comment {>'\"",
  "\"'<comment (>'\"", "\"'DECIMAL'\"", "\"'<declare base URI>'\"",
  "\"'<declare boundary space>'\"", "\"'<declare construction>'\"",
  "\"'<declare copy namespaces>'\"", "\"'<declare default collation>'\"",
  "\"'<declare default element>'\"", "\"'<declare default function>'\"",
  "\"'<declare default order>'\"", "\"'<declare function>'\"",
  "\"'<declare namespace>'\"", "\"'<declare option>'\"",
  "\"'<declare ordering>'\"", "\"'<declare updating function>'\"",
  "\"'<declare var $>'\"", "\"'default'\"", "\"'<default element>'\"",
  "\"'descendant::'\"", "\"'descendant-or-self::'\"", "\"'descending'\"",
  "\"'div'\"", "\"'<document {>'\"", "\"'<document node (>'\"", "\"'$'\"",
  "\"'.'\"", "\"'..'\"", "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"",
  "\"'<element {>'\"", "\"'<element (>'\"", "\"'else'\"",
  "\"'<empty greatest>'\"", "\"'<empty least>'\"", "\"'/>'\"",
  "\"'encoding'\"", "\"'='\"", "\"''''\"", "\"'\\\"\\\"'\"",
  "\"'<every $>'\"", "\"'except'\"", "\"'external'\"", "\"'following::'\"",
  "\"'following-sibling::'\"", "\"'follows'\"", "\"'<for $>'\"",
  "\"'general comp'\"", "\"'>='\"", "\"':='\"", "\"'>'\"", "\"'?'\"",
  "\"'idiv'\"", "\"'<if (>'\"", "\"'<import module>\"",
  "\"'<import schema>'\"", "\"'in'\"", "\"'inherit'\"",
  "\"'<instance of>'\"", "\"'INTEGER'\"", "\"'intersect'\"", "\"'is'\"",
  "\"'item()'\"", "\"'{'\"", "\"'['\"", "\"'<='\"", "\"'[ / ]'\"",
  "\"'<let $>'\"", "\"'<let score $>'\"", "\"'('\"", "\"'<'\"", "\"'-'\"",
  "\"'mod'\"", "\"'<module namespace>'\"", "\"'namespace'\"", "\"'nan'\"",
  "\"'!='\"", "\"'nodecomp'\"", "\"'<node (>'\"", "\"'?\\?'\"",
  "\"'<no inherit>'\"", "\"'<no preserve>'\"", "\"'occurs ?'\"",
  "\"'occurs +'\"", "\"'occurs *'\"", "\"'or'\"", "\"'ordered'\"",
  "\"'ordered {'\"", "\"'<order by>'\"", "\"'parent::'\"", "\"'<?'\"",
  "\"'?>'\"", "\"'<pi {>'\"", "\"'<pi (>'\"", "\"'PI TARGET'\"", "\"'+'\"",
  "\"'PRAGMA BEGIN'\"", "\"'PRAGMA END'\"", "\"'<<'\"",
  "\"'preceding::'\"", "\"'preceding-sibling::'\"", "\"'preserve'\"",
  "\"'<processing instruction>'\"", "\"'\\\"'\"", "\"'}'\"", "\"']'\"",
  "\"'return'\"", "\"')'\"", "\"'<) as>'\"", "\"'satisfies'\"",
  "\"'<schema attribute ('\"", "\"'<schema element (>'\"", "\"'self::'\"",
  "\"';'\"", "\"'/'\"", "\"'//'\"", "\"'<some $>'\"",
  "\"'<stable order by>'\"", "\"'*'\"", "\"'start tag end >'\"",
  "\"'start tag <'\"", "\"'strip'\"", "\"'</'\"", "\"'<text {>'\"",
  "\"'<text (>'\"", "\"'then'\"", "\"'to'\"", "\"'<treat as>'\"",
  "\"'<typeswitch (>'\"", "\"'union'\"", "\"'unordered'\"",
  "\"'<unordered (>'\"", "\"'unrecognized'\"", "\"'eq'\"", "\"'ge'\"",
  "\"'gt'\"", "\"'le'\"", "\"'lt'\"", "\"'ne'\"", "\"'<validate {>'\"",
  "\"'VALUECOMP'\"", "\"'|'\"", "\"'void()'\"", "\"'where'\"", "\"'<!'\"",
  "\"'-->'\"", "\"'<XQuery Version>'\"", "\"'after'\"", "\"'before'\"",
  "\"'<, $>'\"", "\"'<declare revalidation mode>'\"", "\"'<do delete>'\"",
  "\"'<do insert>'\"", "\"'<do rename>'\"", "\"'<do replace>'\"",
  "\"'<first into>'\"", "\"'into'\"", "\"'<lastinto>'\"", "\"'modify'\"",
  "\"'<transform copy $>'\"", "\"'<value of>'\"", "\"'with'\"",
  "\"'all'\"", "\"'<all words>'\"", "\"'any'\"", "\"'<any words>'\"",
  "\"'<at end>'\"", "\"'<at least>'\"", "\"'<at most>'\"",
  "\"'<at start>'\"", "\"'<case insensitive>'\"", "\"'<casesensitive>'\"",
  "\"'<declare ftoption>'\"", "\"'<diacritics insensitive>'\"",
  "\"'<diacritics sensitive>'\"", "\"'different'\"", "\"'distance'\"",
  "\"'<entire content>'\"", "\"'exactly'\"", "\"'from'\"", "\"'&&'\"",
  "\"'ftcontains'\"", "\"'ftnot'\"", "\"'||'\"", "\"'language'\"",
  "\"'levels'\"", "\"'lowercase'\"", "\"'<not in>'\"", "\"'occurs'\"",
  "\"'paragraph'\"", "\"'phrase'\"", "\"'relationship'\"", "\"'same'\"",
  "\"'score'\"", "\"'sentence'\"", "\"'sentences'\"", "\"'times'\"",
  "\"'uppercase'\"", "\"'weight'\"", "\"'window'\"",
  "\"'<without content>'\"", "\"'<without diacritics>'\"",
  "\"'<without stemming>'\"", "\"'<without stop words>'\"",
  "\"'<without thesaurus>'\"", "\"'<without wildcards>'\"",
  "\"'<with default stop words>'\"", "\"'<with diacritics>'\"",
  "\"'<with stemming>'\"", "\"'<with stop words>'\"",
  "\"'<with thesaurus>'\"", "\"'<with wildcards>'\"", "\"'words'\"",
  "FTCONTAINS_REDUCE", "RANGE_REDUCE", "ADDITIVE_REDUCE",
  "MULTIPLICATIVE_REDUCE", "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE",
  "QVARINDECLLIST_REDUCE", "UNARY_PREC", "SEQUENCE_TYPE_REDUCE",
  "STEP_REDUCE", "$accept", "Module", "VersionDecl", "MainModule",
  "LibraryModule", "ModuleDecl", "Prolog", "SIND_DeclList", "VFO_DeclList",
  "SIND_Decl", "VFO_Decl", "Setter", "Import", "NamespaceDecl",
  "BoundarySpaceDecl", "DefaultNamespaceDecl", "OptionDecl",
  "FTOptionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "DefaultCollationDecl", "BaseURIDecl",
  "SchemaImport", "URILiteralList", "SchemaPrefix", "ModuleImport",
  "VarDecl", "ConstructionDecl", "FunctionDecl", "ParamList", "Param",
  "EnclosedExpr", "QueryBody", "Expr", "ExprSingle", "FLWORExpr",
  "ForLetClauseList", "ForLetClause", "ForClause", "VarInDeclList",
  "VarInDecl", "PositionalVar", "FTScoreVar", "LetClause",
  "VarGetsDeclList", "VarGetsDecl", "WhereClause", "OrderByClause",
  "OrderSpecList", "OrderSpec", "OrderModifier", "OrderDirSpec",
  "OrderEmptySpec", "OrderCollationSpec", "QuantifiedExpr",
  "QVarInDeclList", "QVarInDecl", "TypeswitchExpr", "CaseClauseList",
  "CaseClause", "IfExpr", "OrExpr", "AndExpr", "ComparisonExpr",
  "FTContainsExpr", "RangeExpr", "AdditiveExpr", "MultiplicativeExpr",
  "UnionExpr", "IntersectExceptExpr", "InstanceofExpr", "TreatExpr",
  "CastableExpr", "CastExpr", "UnaryExpr", "SignList", "ValueExpr",
  "GeneralComp", "ValueComp", "NodeComp", "ValidateExpr", "ExtensionExpr",
  "PragmaList", "Pragma", "PathExpr", "RelativePathExpr", "StepExpr",
  "AxisStep", "ForwardStep", "ForwardAxis", "AbbrevForwardStep",
  "ReverseStep", "ReverseAxis", "NodeTest", "NameTest", "Wildcard",
  "FilterExpr", "PredicateList", "Predicate", "PrimaryExpr", "Literal",
  "NumericLiteral", "VarRef", "ParenthesizedExpr", "ContextItemExpr",
  "OrderedExpr", "UnorderedExpr", "FunctionCall", "ArgList", "Constructor",
  "DirectConstructor", "DirElemConstructor", "DirElemContentList",
  "DirAttributeList", "DirAttr", "DirAttributeValue",
  "Opt_QuoteAttrContentList", "QuoteAttrContentList",
  "Opt_AposAttrContentList", "AposAttrContentList",
  "QuoteAttrValueContent", "AposAttrValueContent", "DirElemContent",
  "CommonContent", "DirCommentConstructor", "DirPIConstructor",
  "CDataSection", "ComputedConstructor", "CompDocConstructor",
  "CompElemConstructor", "CompAttrConstructor", "CompTextConstructor",
  "CompCommentConstructor", "CompPIConstructor", "SingleType",
  "TypeDeclaration", "SequenceType", "OccurrenceIndicator", "ItemType",
  "AtomicType", "KindTest", "AnyKindTest", "DocumentTest", "TextTest",
  "CommentTest", "PITest", "AttributeTest", "SchemaAttributeTest",
  "ElementTest", "SchemaElementTest", "TypeName", "StringLiteral",
  "RevalidationDecl", "InsertExpr", "DeleteExpr", "ReplaceExpr",
  "RenameExpr", "TransformExpr", "VarNameList", "FTSelection",
  "FTMatchOptionProximityList", "FTOr", "FTAnd", "FTMildnot", "FTUnaryNot",
  "FTWordsSelection", "FTWords", "FTWordsValue", "FTProximity",
  "FTOrderedIndicator", "FTMatchOption", "FTCaseOption",
  "FTDiacriticsOption", "FTStemOption", "FTThesaurusOption",
  "FTThesaurusList", "FTThesaurusID", "FTStopwordOption",
  "FTInclExclStringLiteralList", "FTRefOrList", "FTStringLiteralList",
  "FTInclExclStringLiteral", "FTLanguageOption", "FTWildcardOption",
  "FTContent", "FTAnyallOption", "FTRange", "FTDistance", "FTWindow",
  "FTTimes", "FTScope", "FTUnit", "FTBigUnit", "FTIgnoreOption", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       273,     0,    -1,   275,    -1,   274,   275,    -1,   276,    -1,
     274,   276,    -1,   195,    21,   162,    -1,   195,    21,    85,
      21,   162,    -1,   278,   305,    -1,   305,    -1,   277,   278,
      -1,   122,    13,    86,    22,   162,    -1,   279,   162,    -1,
     280,   162,    -1,   279,   162,   280,   162,    -1,   281,    -1,
     279,   162,   281,    -1,   282,    -1,   280,   162,   282,    -1,
     283,    -1,   284,    -1,   285,    -1,   287,    -1,   299,    -1,
     301,    -1,   288,    -1,   289,    -1,   286,    -1,   293,    -1,
     294,    -1,   300,    -1,   290,    -1,   291,    -1,   292,    -1,
     425,    -1,   295,    -1,   298,    -1,    60,    13,    86,    22,
      -1,    52,   150,    -1,    52,   170,    -1,    56,   123,    22,
      -1,    57,   123,    22,    -1,    61,    18,    21,    -1,   221,
     443,    -1,    62,   135,    -1,    62,   179,    -1,    58,    82,
      -1,    58,    83,    -1,    54,   150,    45,   106,    -1,    54,
     150,    45,   129,    -1,    54,   130,    45,   106,    -1,    54,
     130,    45,   129,    -1,    55,    22,    -1,    51,    22,    -1,
     104,    22,    -1,   104,   297,    22,    -1,   104,    22,    32,
     296,    -1,   104,   297,    22,    32,   296,    -1,    22,    -1,
     296,    45,    22,    -1,   123,    13,    86,    -1,    66,   123,
      -1,   103,    22,    -1,   103,   123,    13,    86,    22,    -1,
     103,    22,    32,   296,    -1,   103,   123,    13,    86,    22,
      32,   296,    -1,    64,    23,    98,   307,    -1,    64,    23,
      91,    -1,    64,    23,   408,    98,   307,    -1,    64,    23,
     408,    91,    -1,    53,   150,    -1,    53,   170,    -1,    59,
      19,   156,    91,    -1,    59,    19,   156,   304,    -1,    59,
      19,   302,   156,    91,    -1,    59,    19,   302,   156,   304,
      -1,    59,    19,   157,   409,    91,    -1,    59,    19,   157,
     409,   304,    -1,    59,    19,   302,   157,   409,    91,    -1,
      59,    19,   302,   157,   409,   304,    -1,    63,    19,   156,
      91,    -1,    63,    19,   156,   304,    -1,    63,    19,   302,
     156,    91,    -1,    63,    19,   302,   156,   304,    -1,    63,
      19,   157,   409,    91,    -1,    63,    19,   157,   409,   304,
      -1,    63,    19,   302,   157,   409,    91,    -1,    63,    19,
     302,   157,   409,   304,    -1,   303,    -1,   302,    45,   303,
      -1,    73,    23,    -1,    73,    23,   408,    -1,   112,   306,
     153,    -1,   306,    -1,   307,    -1,   306,    45,   307,    -1,
     308,    -1,   327,    -1,   330,    -1,   333,    -1,   334,    -1,
     426,    -1,   427,    -1,   429,    -1,   428,    -1,   430,    -1,
     309,   155,   307,    -1,   309,   319,   155,   307,    -1,   309,
     320,   155,   307,    -1,   309,   319,   320,   155,   307,    -1,
     310,    -1,   309,   310,    -1,   311,    -1,   316,    -1,    95,
     312,    -1,   313,    -1,   312,    45,    73,   313,    -1,    23,
     105,   307,    -1,    23,   408,   105,   307,    -1,    23,   314,
     105,   307,    -1,    23,   408,   314,   105,   307,    -1,    23,
     315,   105,   307,    -1,    23,   408,   315,   105,   307,    -1,
      23,   314,   315,   105,   307,    -1,    23,   408,   314,   315,
     105,   307,    -1,    32,    73,    23,    -1,   242,    73,    23,
      -1,   116,   317,    -1,   318,    -1,   317,    45,    73,   318,
      -1,    23,    98,   307,    -1,    23,   408,    98,   307,    -1,
      23,   315,    98,   307,    -1,    23,   408,   315,    98,   307,
      -1,   192,   307,    -1,   137,   321,    -1,   166,   321,    -1,
     322,    -1,   321,    45,   322,    -1,   307,    -1,   307,   323,
      -1,   324,    -1,   325,    -1,   326,    -1,   324,   325,    -1,
     324,   326,    -1,   325,   326,    -1,   324,   325,   326,    -1,
      31,    -1,    69,    -1,    82,    -1,    83,    -1,    44,    22,
      -1,   165,   328,   158,   307,    -1,    89,   328,   158,   307,
      -1,   329,    -1,   329,   198,   328,    -1,    23,   105,   307,
      -1,    23,   408,   105,   307,    -1,   177,   306,   156,   331,
      65,   155,   307,    -1,   177,   306,   156,   331,    65,    73,
      23,   155,   307,    -1,   332,    -1,   331,   332,    -1,    38,
     409,   155,   307,    -1,    38,    73,    23,    30,   409,   155,
     307,    -1,   102,   306,   156,   174,   307,    81,   307,    -1,
     335,    -1,   334,   134,   335,    -1,   336,    -1,   335,    28,
     336,    -1,   337,    -1,   337,   351,   337,    -1,   337,   350,
     337,    -1,   337,   352,   337,    -1,   338,    -1,   338,   230,
     432,    -1,   338,   230,   432,   466,    -1,   339,    -1,   339,
     175,   339,    -1,   340,    -1,   339,   144,   340,    -1,   339,
     120,   340,    -1,   341,    -1,   340,   167,   341,    -1,   340,
      70,   341,    -1,   340,   101,   341,    -1,   340,   121,   341,
      -1,   342,    -1,   341,   178,   342,    -1,   341,   190,   342,
      -1,   343,    -1,   342,   109,   343,    -1,   342,    90,   343,
      -1,   344,    -1,   344,   107,   409,    -1,   345,    -1,   345,
     176,   409,    -1,   346,    -1,   346,    39,   407,    -1,   347,
      -1,   347,    40,   407,    -1,   349,    -1,   348,   349,    -1,
     144,    -1,   120,    -1,   348,   144,    -1,   348,   120,    -1,
     353,    -1,   357,    -1,   354,    -1,    86,    -1,   125,    -1,
     119,    -1,   114,    -1,    99,    -1,    97,    -1,   182,    -1,
     187,    -1,   186,    -1,   185,    -1,   184,    -1,   183,    -1,
     110,    -1,   147,    -1,    94,    -1,   188,   306,   153,    -1,
      24,   112,   306,   153,    -1,   355,   112,   153,    -1,   355,
     112,   306,   153,    -1,   356,    -1,   355,   356,    -1,   145,
      18,    16,   146,    -1,   115,    -1,   163,   358,    -1,   164,
     358,    -1,   358,    -1,   359,    -1,   359,   163,   358,    -1,
     359,   164,   358,    -1,   360,    -1,   369,    -1,   361,    -1,
     361,   370,    -1,   364,    -1,   364,   370,    -1,   362,   366,
      -1,   363,    -1,    43,    -1,    67,    -1,    34,    -1,   161,
      -1,    68,    -1,    93,    -1,    92,    -1,   366,    -1,    37,
     366,    -1,   365,   366,    -1,    75,    -1,   138,    -1,    26,
      -1,   149,    -1,   148,    -1,    27,    -1,   413,    -1,   367,
      -1,    18,    -1,   368,    -1,   167,    -1,    10,    -1,    17,
      -1,   372,    -1,   372,   370,    -1,   371,    -1,   370,   371,
      -1,   113,   306,   154,    -1,   373,    -1,   375,    -1,   376,
      -1,   377,    -1,   380,    -1,   382,    -1,   378,    -1,   379,
      -1,   374,    -1,   424,    -1,    50,    -1,   108,    -1,    77,
      -1,    73,    23,    -1,   118,   156,    -1,   118,   306,   156,
      -1,    74,    -1,   136,   306,   153,    -1,   180,   306,   153,
      -1,    19,   156,    -1,    19,   381,   156,    -1,   307,    -1,
     381,    45,   307,    -1,   383,    -1,   400,    -1,   384,    -1,
     397,    -1,   398,    -1,   169,    18,    84,    -1,   169,    18,
     386,    84,    -1,   169,    18,   171,   168,    18,   171,    -1,
     169,    18,   171,   385,   168,    18,   171,    -1,   169,    18,
     386,   171,   168,    18,   171,    -1,   169,    18,   386,   171,
     385,   168,    18,   171,    -1,   395,    -1,   385,   395,    -1,
     387,    -1,   386,   387,    -1,    18,    86,   388,    -1,   152,
     389,   152,    -1,    29,   391,    29,    -1,    -1,   390,    -1,
      88,    -1,   393,    -1,   390,    88,    -1,   390,   393,    -1,
      -1,   392,    -1,    87,    -1,   394,    -1,   392,    87,    -1,
     392,   394,    -1,    20,    -1,   396,    -1,     3,    -1,   396,
      -1,   383,    -1,     8,    -1,   399,    -1,   396,    -1,    11,
      -1,     7,    -1,    76,    -1,    78,    -1,   304,    -1,   193,
      12,   194,    -1,   139,    15,   140,    -1,   139,    15,     6,
     140,    -1,    41,     6,    42,    -1,   401,    -1,   402,    -1,
     403,    -1,   404,    -1,   405,    -1,   406,    -1,    71,   306,
     153,    -1,     9,   153,    -1,     9,   306,   153,    -1,    79,
     306,   153,   112,   153,    -1,    79,   306,   153,   112,   306,
     153,    -1,     4,   153,    -1,     4,   306,   153,    -1,    35,
     306,   153,   112,   153,    -1,    35,   306,   153,   112,   306,
     153,    -1,   172,   306,   153,    -1,    48,   306,   153,    -1,
     151,    13,   112,   153,    -1,   151,    13,   112,   306,   153,
      -1,   151,   112,   306,   153,   112,   153,    -1,   151,   112,
     306,   153,   112,   306,   153,    -1,   412,    -1,   412,   100,
      -1,    30,   409,    -1,   411,    -1,   411,   410,    -1,   191,
      -1,   131,    -1,   133,    -1,   132,    -1,   412,    -1,   413,
      -1,   111,    -1,    18,    -1,   415,    -1,   421,    -1,   419,
      -1,   422,    -1,   420,    -1,   418,    -1,   417,    -1,   416,
      -1,   414,    -1,   127,   156,    -1,    72,   156,    -1,    72,
     421,   156,    -1,    72,   422,   156,    -1,   173,   156,    -1,
      49,   156,    -1,   142,   156,    -1,   142,    13,   156,    -1,
     142,    21,   156,    -1,    36,   156,    -1,    36,    18,   156,
      -1,    36,    18,    45,   423,   156,    -1,    36,   167,   156,
      -1,    36,   167,    45,   423,   156,    -1,   159,    18,   156,
      -1,    80,   156,    -1,    80,    18,   156,    -1,    80,    18,
      45,   423,   156,    -1,    80,    18,    45,   423,   100,   156,
      -1,    80,   167,   156,    -1,    80,   167,    45,   423,   156,
      -1,    80,   167,    45,   423,   100,   156,    -1,   160,    18,
     156,    -1,    18,    -1,    18,   100,    -1,    21,    -1,   199,
      -1,   201,   307,   205,   307,    -1,   201,   307,    30,   204,
     307,    -1,   201,   307,    30,   206,   307,    -1,   201,   307,
     196,   307,    -1,   201,   307,   197,   307,    -1,   200,   307,
      -1,   203,   307,   210,   307,    -1,   203,   209,   307,   210,
     307,    -1,   202,   307,    30,   307,    -1,   208,   431,   207,
     307,   155,   307,    -1,    23,    98,   307,    -1,   431,   198,
      23,    98,   307,    -1,   434,    -1,   434,   433,    -1,   434,
     247,   338,    -1,   434,   433,   247,   338,    -1,   443,    -1,
     441,    -1,   433,   443,    -1,   433,   441,    -1,   435,    -1,
     434,   232,   435,    -1,   436,    -1,   435,   229,   436,    -1,
     437,    -1,   436,   236,   437,    -1,   438,    -1,   231,   438,
      -1,   439,    -1,   439,   462,    -1,   118,   432,   156,    -1,
     440,    -1,   440,   458,    -1,   373,    -1,   112,   306,   153,
      -1,   442,    -1,   461,    -1,   460,    -1,   463,    -1,   457,
      -1,   135,    -1,   444,    -1,   445,    -1,   446,    -1,   447,
      -1,   450,    -1,   455,    -1,   456,    -1,   235,    -1,   246,
      -1,   220,    -1,   219,    -1,   256,    -1,   250,    -1,   223,
      -1,   222,    -1,   257,    -1,   251,    -1,   259,   449,    -1,
     259,    65,    -1,   259,   118,   449,   156,    -1,   259,   118,
     449,    45,   448,   156,    -1,   259,   118,    65,   156,    -1,
     259,   118,    65,    45,   448,   156,    -1,   253,    -1,   449,
      -1,   448,    45,   449,    -1,    32,    21,    -1,    32,    21,
     240,    21,    -1,    32,    21,   459,   234,    -1,    32,    21,
     240,    21,   459,   234,    -1,   258,   452,    -1,   258,   452,
     451,    -1,   255,    -1,   255,   451,    -1,   252,    -1,   454,
      -1,   451,   454,    -1,    32,    21,    -1,   118,   453,   156,
      -1,    21,    -1,   453,    21,    -1,   178,   452,    -1,    90,
     452,    -1,   233,    21,    -1,   260,    -1,   254,    -1,   218,
      -1,   215,    -1,   226,    -1,   213,    -1,   214,    -1,   211,
      -1,   212,    -1,   239,    -1,   227,   341,    -1,   216,   341,
      -1,   217,   341,    -1,   228,   341,   175,   341,    -1,   225,
     459,   464,    -1,   248,   341,   464,    -1,   237,   459,   245,
      -1,   241,   465,    -1,   224,   465,    -1,   261,    -1,   244,
      -1,   238,    -1,   243,    -1,   238,    -1,   249,   341,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    13,    17,    23,    26,
      28,    31,    37,    40,    43,    48,    50,    54,    56,    60,
      62,    64,    66,    68,    70,    72,    74,    76,    78,    80,
      82,    84,    86,    88,    90,    92,    94,    96,   101,   104,
     107,   111,   115,   119,   122,   125,   128,   131,   134,   139,
     144,   149,   154,   157,   160,   163,   167,   172,   178,   180,
     184,   188,   191,   194,   200,   205,   213,   218,   222,   228,
     233,   236,   239,   244,   249,   255,   261,   267,   273,   280,
     287,   292,   297,   303,   309,   315,   321,   328,   335,   337,
     341,   344,   348,   352,   354,   356,   360,   362,   364,   366,
     368,   370,   372,   374,   376,   378,   380,   384,   389,   394,
     400,   402,   405,   407,   409,   412,   414,   419,   423,   428,
     433,   439,   444,   450,   456,   463,   467,   471,   474,   476,
     481,   485,   490,   495,   501,   504,   507,   510,   512,   516,
     518,   521,   523,   525,   527,   530,   533,   536,   540,   542,
     544,   546,   548,   551,   556,   561,   563,   567,   571,   576,
     584,   594,   596,   599,   604,   612,   620,   622,   626,   628,
     632,   634,   638,   642,   646,   648,   652,   657,   659,   663,
     665,   669,   673,   675,   679,   683,   687,   691,   693,   697,
     701,   703,   707,   711,   713,   717,   719,   723,   725,   729,
     731,   735,   737,   740,   742,   744,   747,   750,   752,   754,
     756,   758,   760,   762,   764,   766,   768,   770,   772,   774,
     776,   778,   780,   782,   784,   786,   790,   795,   799,   804,
     806,   809,   814,   816,   819,   822,   824,   826,   830,   834,
     836,   838,   840,   843,   845,   848,   851,   853,   855,   857,
     859,   861,   863,   865,   867,   869,   872,   875,   877,   879,
     881,   883,   885,   887,   889,   891,   893,   895,   897,   899,
     901,   903,   906,   908,   911,   915,   917,   919,   921,   923,
     925,   927,   929,   931,   933,   935,   937,   939,   941,   944,
     947,   951,   953,   957,   961,   964,   968,   970,   974,   976,
     978,   980,   982,   984,   988,   993,  1000,  1008,  1016,  1025,
    1027,  1030,  1032,  1035,  1039,  1043,  1047,  1048,  1050,  1052,
    1054,  1057,  1060,  1061,  1063,  1065,  1067,  1070,  1073,  1075,
    1077,  1079,  1081,  1083,  1085,  1087,  1089,  1091,  1093,  1095,
    1097,  1099,  1103,  1107,  1112,  1116,  1118,  1120,  1122,  1124,
    1126,  1128,  1132,  1135,  1139,  1145,  1152,  1155,  1159,  1165,
    1172,  1176,  1180,  1185,  1191,  1198,  1206,  1208,  1211,  1214,
    1216,  1219,  1221,  1223,  1225,  1227,  1229,  1231,  1233,  1235,
    1237,  1239,  1241,  1243,  1245,  1247,  1249,  1251,  1253,  1256,
    1259,  1263,  1267,  1270,  1273,  1276,  1280,  1284,  1287,  1291,
    1297,  1301,  1307,  1311,  1314,  1318,  1324,  1331,  1335,  1341,
    1348,  1352,  1354,  1357,  1359,  1361,  1366,  1372,  1378,  1383,
    1388,  1391,  1396,  1402,  1407,  1414,  1418,  1424,  1426,  1429,
    1433,  1438,  1440,  1442,  1445,  1448,  1450,  1454,  1456,  1460,
    1462,  1466,  1468,  1471,  1473,  1476,  1480,  1482,  1485,  1487,
    1491,  1493,  1495,  1497,  1499,  1501,  1503,  1505,  1507,  1509,
    1511,  1513,  1515,  1517,  1519,  1521,  1523,  1525,  1527,  1529,
    1531,  1533,  1535,  1537,  1540,  1543,  1548,  1555,  1560,  1567,
    1569,  1571,  1575,  1578,  1583,  1588,  1595,  1598,  1602,  1604,
    1607,  1609,  1611,  1614,  1617,  1621,  1623,  1626,  1629,  1632,
    1635,  1637,  1639,  1641,  1643,  1645,  1647,  1649,  1651,  1653,
    1655,  1658,  1661,  1664,  1669,  1673,  1677,  1681,  1684,  1687,
    1689,  1691,  1693,  1695,  1697
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   720,   720,   726,   730,   734,   744,   748,   758,   766,
     779,   792,   805,   812,   819,   832,   839,   854,   861,   876,
     881,   886,   891,   901,   906,   911,   918,   929,   934,   939,
     944,   949,   954,   959,   966,   977,   982,   998,  1011,  1017,
    1029,  1036,  1049,  1063,  1075,  1081,  1094,  1100,  1112,  1119,
    1126,  1133,  1153,  1165,  1177,  1185,  1193,  1201,  1215,  1222,
    1238,  1243,  1254,  1261,  1269,  1276,  1291,  1299,  1307,  1315,
    1329,  1335,  1347,  1355,  1364,  1373,  1383,  1393,  1403,  1413,
    1423,  1431,  1440,  1449,  1459,  1469,  1479,  1489,  1505,  1514,
    1529,  1536,  1549,  1561,  1573,  1580,  1593,  1598,  1603,  1608,
    1613,  1620,  1625,  1630,  1635,  1640,  1651,  1659,  1669,  1678,
    1693,  1700,  1713,  1718,  1729,  1741,  1748,  1763,  1771,  1780,
    1790,  1801,  1810,  1820,  1830,  1846,  1859,  1871,  1884,  1891,
    1906,  1915,  1925,  1934,  1950,  1962,  1968,  1981,  1988,  2003,
    2010,  2023,  2031,  2039,  2047,  2055,  2063,  2071,  2085,  2090,
    2101,  2107,  2119,  2131,  2139,  2153,  2161,  2176,  2183,  2197,
    2205,  2220,  2227,  2240,  2247,  2261,  2273,  2278,  2290,  2295,
    2315,  2320,  2329,  2338,  2353,  2358,  2366,  2380,  2385,  2397,
    2402,  2407,  2418,  2422,  2427,  2432,  2437,  2448,  2453,  2459,
    2471,  2476,  2481,  2492,  2497,  2510,  2515,  2528,  2533,  2546,
    2551,  2564,  2569,  2582,  2587,  2592,  2597,  2610,  2615,  2620,
    2632,  2637,  2642,  2647,  2652,  2657,  2668,  2673,  2678,  2683,
    2688,  2693,  2704,  2709,  2714,  2726,  2731,  2744,  2751,  2764,
    2771,  2786,  2830,  2835,  2840,  2845,  2856,  2861,  2866,  2877,
    2882,  2893,  2900,  2907,  2914,  2927,  2934,  2946,  2951,  2956,
    2961,  2966,  2971,  2976,  2987,  2992,  3003,  3010,  3023,  3028,
    3033,  3038,  3043,  3059,  3064,  3075,  3080,  3091,  3099,  3107,
    3121,  3126,  3139,  3146,  3161,  3173,  3178,  3183,  3188,  3193,
    3198,  3203,  3208,  3219,  3224,  3235,  3240,  3245,  3256,  3267,
    3272,  3284,  3295,  3307,  3364,  3371,  3384,  3391,  3404,  3409,
    3420,  3425,  3430,  3441,  3450,  3459,  3468,  3477,  3486,  3502,
    3509,  3522,  3529,  3544,  3557,  3563,  3576,  3580,  3587,  3594,
    3601,  3610,  3625,  3629,  3636,  3643,  3650,  3659,  3674,  3680,
    3692,  3698,  3710,  3716,  3722,  3729,  3742,  3749,  3756,  3762,
    3768,  3780,  3797,  3803,  3821,  3837,  3842,  3847,  3852,  3857,
    3862,  3873,  3885,  3892,  3899,  3905,  3929,  3936,  3943,  3949,
    3961,  3973,  3985,  3992,  3999,  4005,  4017,  4024,  4037,  4049,
    4056,  4063,  4101,  4107,  4113,  4125,  4130,  4135,  4146,  4158,
    4163,  4168,  4173,  4178,  4183,  4188,  4193,  4198,  4209,  4220,
    4225,  4231,  4243,  4254,  4265,  4270,  4275,  4286,  4293,  4300,
    4307,  4314,  4327,  4339,  4346,  4353,  4360,  4367,  4375,  4383,
    4397,  4419,  4425,  4446,  4486,  4496,  4500,  4504,  4508,  4512,
    4522,  4532,  4536,  4546,  4571,  4581,  4585,  4603,  4607,  4611,
    4615,  4625,  4629,  4633,  4637,  4647,  4651,  4661,  4665,  4675,
    4679,  4689,  4693,  4703,  4707,  4711,  4721,  4725,  4735,  4739,
    4749,  4753,  4757,  4761,  4765,  4775,  4785,  4790,  4795,  4800,
    4805,  4810,  4815,  4826,  4830,  4834,  4838,  4848,  4852,  4856,
    4860,  4870,  4874,  4884,  4888,  4892,  4896,  4900,  4904,  4908,
    4918,  4922,  4932,  4936,  4940,  4944,  4954,  4958,  4962,  4966,
    4970,  4980,  4984,  4994,  4998,  5008,  5012,  5022,  5026,  5036,
    5046,  5050,  5060,  5064,  5068,  5078,  5082,  5086,  5090,  5094,
    5104,  5108,  5112,  5116,  5126,  5136,  5146,  5156,  5160,  5170,
    5174,  5178,  5188,  5192,  5202
  };

  // Print the state stack on the debug stream.
  void
  xquery_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  xquery_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "), ";
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  xquery_parser::token_number_type
  xquery_parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 3785;
  const int xquery_parser::yynnts_ = 195;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 314;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 272;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 526;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace yy

#line 5210 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"




/*
	The error member function registers the errors to the driver.
*/

void yy::xquery_parser::error(
	yy::xquery_parser::location_type const& loc,
	std::string const& msg)
{
  driver.error(loc, msg);
}



/*
static void print_token_value(FILE *file, int type, YYSTYPE value)
{
	if (type==VAR) {
		fprintf (file, "%s", value.tptr->name);
	}
	else if (type==NUM) {
		fprintf (file, "%d", value.val);
	}
}
*/





