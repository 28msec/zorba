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
#line 127 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"


/* Line 317 of lalr1.cc.  */
#line 46 "/Users/mbrantner/misc/code/vanilla/xquery/build/src/compiler/parser/xquery_parser.cpp"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
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
  xquery_parser::xquery_parser (xquery_driver& driver_yyarg, void* yyscanner_yyarg)
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
      driver (driver_yyarg),
      yyscanner (yyscanner_yyarg)
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
    #line 86 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = driver.filename.getStore();
}
  /* Line 555 of yacc.c.  */
#line 283 "/Users/mbrantner/misc/code/vanilla/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
	yychar = yylex (&yylval, &yylloc, driver, yyscanner);
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
#line 730 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [main]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr((yyval.node));
		;}
    break;

  case 3:
#line 738 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr((yyval.node));
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.main]\n";
#endif
		;}
    break;

  case 4:
#line 746 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [library]\n";
#endif
		;}
    break;

  case 5:
#line 752 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.library]\n";
#endif
		;}
    break;

  case 6:
#line 764 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version]\n";
#endif
		;}
    break;

  case 7:
#line 770 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version.encoding]\n";
#endif
		;}
    break;

  case 8:
#line 782 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MainModule [prolog.querybody]\n";
#endif
			(yyval.node) = new MainModule((yyloc),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)));
		;}
    break;

  case 9:
#line 792 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MainModule [querybody]\n";
#endif
			(yyval.node) = new MainModule((yyloc),
								NULL,
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 10:
#line 807 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LibraryModule [ ]\n";
#endif
			(yyval.node) = new LibraryModule((yyloc),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 11:
#line 822 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleDecl [ ]\n";
#endif
			(yyval.node) = new ModuleDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)), 
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (4)].sval)));
		;}
    break;

  case 12:
#line 837 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Prolog [sind]\n";
#endif
			(yyval.node) = new Prolog((yyloc),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 13:
#line 846 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Prolog [vfo]\n";
#endif
			(yyval.node) = new Prolog((yyloc),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 14:
#line 855 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Prolog [sind.vfo]\n";
#endif
			(yyval.node) = new Prolog((yyloc),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 15:
#line 870 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_DeclList [single]\n";
#endif
			SIND_DeclList* sindList_p = new SIND_DeclList((yyloc));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 16:
#line 879 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_DeclList [list]\n";
#endif
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 17:
#line 896 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_DeclList [single]\n";
#endif
			VFO_DeclList* vfoList_p = new VFO_DeclList((yyloc));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 18:
#line 905 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_DeclList [list]\n";
#endif
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 19:
#line 922 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [setter]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 929 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [import]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 936 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [namespace]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 943 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [default namespace]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 955 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [var]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 962 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [function]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 969 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [option]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 978 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [ftoption]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 991 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [boundary space]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 998 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [default collation]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 1005 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [base uri]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 1012 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [construction]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 1019 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [ordering mode]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 1026 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [empty order]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 1033 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [copy namespaces]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 1042 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [revalidation]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 1055 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [schema]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 1062 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [module]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 1080 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NamespaceDecl [ ]\n";
#endif
			(yyval.node) = new NamespaceDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 38:
#line 1095 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [preserve]\n";
#endif
			(yyval.node) = new BoundarySpaceDecl((yyloc),
								StaticQueryContext::preserve_space);
		;}
    break;

  case 39:
#line 1103 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [strip]\n";
#endif
			(yyval.node) = new BoundarySpaceDecl((yyloc),
								StaticQueryContext::strip_space);
		;}
    break;

  case 40:
#line 1117 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultNamespaceDecl [element]\n";
#endif
			(yyval.node) = new DefaultNamespaceDecl((yyloc),
								ns_element_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 41:
#line 1126 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultNamespaceDecl [function]\n";
#endif
			(yyval.node) = new DefaultNamespaceDecl((yyloc),
								ns_function_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 42:
#line 1141 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OptionDecl [ ]\n";
#endif
			(yyval.node) = new OptionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 43:
#line 1157 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOptionDecl [ ]\n";
#endif
			(yyval.node) = new FTOptionDecl((yyloc),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 44:
#line 1171 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [ordered]\n";
#endif
			(yyval.node) = new OrderingModeDecl((yyloc),
								StaticQueryContext::ordered);
		;}
    break;

  case 45:
#line 1179 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [unordered]\n";
#endif
			(yyval.node) = new OrderingModeDecl((yyloc),
								StaticQueryContext::unordered);
		;}
    break;

  case 46:
#line 1194 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty greatest]\n";
#endif
			(yyval.node) = new EmptyOrderDecl((yyloc),
								StaticQueryContext::empty_greatest);
		;}
    break;

  case 47:
#line 1202 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty least]\n";
#endif
			(yyval.node) = new EmptyOrderDecl((yyloc),
								StaticQueryContext::empty_least);
		;}
    break;

  case 48:
#line 1216 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]\n";
#endif
			(yyval.node) = new CopyNamespacesDecl((yyloc),
								StaticQueryContext::preserve_ns,
								StaticQueryContext::inherit_ns);
		;}
    break;

  case 49:
#line 1225 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]\n";
#endif
			(yyval.node) = new CopyNamespacesDecl((yyloc),
								StaticQueryContext::preserve_ns,
								StaticQueryContext::no_inherit_ns);
		;}
    break;

  case 50:
#line 1234 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]\n";
#endif
			(yyval.node) = new CopyNamespacesDecl((yyloc),
								StaticQueryContext::no_preserve_ns,
								StaticQueryContext::inherit_ns);
		;}
    break;

  case 51:
#line 1243 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]\n";
#endif
			(yyval.node) = new CopyNamespacesDecl((yyloc),
								StaticQueryContext::no_preserve_ns,
								StaticQueryContext::no_inherit_ns);
		;}
    break;

  case 52:
#line 1265 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultCollationMode [ ]\n";
#endif
			(yyval.node) = new DefaultCollationDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 53:
#line 1279 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BaseURIDecl [ ]\n";
#endif
			(yyval.node) = new BaseURIDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 54:
#line 1293 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [uri]\n";
#endif
			(yyval.node) = new SchemaImport((yyloc),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 55:
#line 1303 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [prefix.uri]\n";
#endif
			(yyval.node) = new SchemaImport((yyloc),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(3) - (2)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 56:
#line 1313 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [uri.urilist]\n";
#endif
			(yyval.node) = new SchemaImport((yyloc),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 57:
#line 1323 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [prefix.uri.aturi]\n";
#endif
			(yyval.node) = new SchemaImport((yyloc),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(5) - (2)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 58:
#line 1339 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "URILiteralList [single]\n";
#endif
			URILiteralList* uri_list_p = new URILiteralList((yyloc));
			uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 59:
#line 1348 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "URILiteralList [list]\n";
#endif
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 60:
#line 1366 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [namespace]\n";
#endif
			(yyval.node) = new SchemaPrefix((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1373 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [default element]\n";
#endif
			(yyval.node) = new SchemaPrefix((yyloc), true);
		;}
    break;

  case 62:
#line 1386 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [uri]\n";
#endif
			(yyval.node) = new ModuleImport((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 63:
#line 1395 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [namespace.uri]\n";
#endif
			(yyval.node) = new ModuleImport((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)),
								NULL);
		;}
    break;

  case 64:
#line 1405 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [uri.at_uri.list]\n";
#endif
			(yyval.node) = new ModuleImport((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 65:
#line 1414 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [namespace.uri.at_uri.list]\n";
#endif
			(yyval.node) = new ModuleImport((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (5)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(7) - (7)].node)));
		;}
    break;

  case 66:
#line 1431 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [expr]\n";
#endif
			(yyval.node) = new VarDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 67:
#line 1441 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [external]\n";
#endif
			(yyval.node) = new VarDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								NULL,
								NULL);
		;}
    break;

  case 68:
#line 1451 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [type.expr]\n";
#endif
			(yyval.node) = new VarDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 69:
#line 1461 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [type.external]\n";
#endif
			(yyval.node) = new VarDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (3)].node)),
								NULL);
		;}
    break;

  case 70:
#line 1477 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [preserve]\n";
#endif
			(yyval.node) = new ConstructionDecl((yyloc),
								StaticQueryContext::cons_preserve);
		;}
    break;

  case 71:
#line 1485 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [strip]\n";
#endif
			(yyval.node) = new ConstructionDecl((yyloc),
								StaticQueryContext::cons_strip);
		;}
    break;

  case 72:
#line 1499 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [external]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,NULL,
								fn_extern);
		;}
    break;

  case 73:
#line 1509 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [expr]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(5) - (5)].expr)),
								fn_read);
		;}
    break;

  case 74:
#line 1520 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.external]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,NULL,
								fn_extern);
		;}
    break;

  case 75:
#line 1531 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.expr]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(6) - (6)].expr)),
								fn_read);
		;}
    break;

  case 76:
#line 1543 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [as_type.external]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)),
								NULL,
								fn_extern);
		;}
    break;

  case 77:
#line 1555 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [as_type.expr]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(6) - (6)].expr)),
								fn_read);
		;}
    break;

  case 78:
#line 1567 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.as_type.external]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(7) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								NULL,
								fn_extern);
		;}
    break;

  case 79:
#line 1579 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.as_type.expr]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(7) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(7) - (7)].expr)),
								fn_read);
		;}
    break;

  case 80:
#line 1591 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) external]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,NULL,
								fn_extern_update);
		;}
    break;

  case 81:
#line 1601 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) expr]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(5) - (5)].expr)),
								fn_update);
		;}
    break;

  case 82:
#line 1612 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.external]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,NULL,
								fn_extern_update);
		;}
    break;

  case 83:
#line 1623 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.expr]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(6) - (6)].expr)),
								fn_update);
		;}
    break;

  case 84:
#line 1635 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) as_type.external]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)),
								NULL,
								fn_extern_update);
		;}
    break;

  case 85:
#line 1647 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) as_type.expr]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(6) - (6)].expr)),
								fn_update);
		;}
    break;

  case 86:
#line 1659 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.as_type.external]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(7) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								NULL,
								fn_extern_update);
		;}
    break;

  case 87:
#line 1671 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.as_type.expr]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(7) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(7) - (7)].expr)),
								fn_update);
		;}
    break;

  case 88:
#line 1689 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParamList [single]\n";
#endif
			ParamList* plist_p = new ParamList((yyloc));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 89:
#line 1700 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParamList [list]\n";
#endif
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 90:
#line 1717 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Param [varname]\n";
#endif
			(yyval.node) = new Param((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 91:
#line 1726 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Param [varname.type]\n";
#endif
			(yyval.node) = new Param((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 92:
#line 1741 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EnclosedExpr [ ]\n";
#endif
			(yyval.expr) = new EnclosedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1755 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QueryBody [expr]\n";
#endif
			(yyval.expr) = new QueryBody((yyloc),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 94:
#line 1769 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Expr [single]\n";
#endif
			Expr* expr_p = new Expr((yyloc));
			expr_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 95:
#line 1778 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Expr [expr.single]\n";
#endif
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p) expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
		;}
    break;

  case 96:
#line 1793 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [FLWORExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 97:
#line 1800 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [QuantifiedExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1807 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TypeswitchExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1814 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [IfExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1821 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [OrExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1830 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [InsertExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1837 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [DeleteExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1844 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [RenameExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1851 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [ReplaceExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1858 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TransformExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1871 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [return]\n";
#endif
			(yyval.expr) = new FLWORExpr((yyloc),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 107:
#line 1881 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [where.return]\n";
#endif
			(yyval.expr) = new FLWORExpr((yyloc),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 108:
#line 1892 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [orderby.return]\n";
#endif
			(yyval.expr) = new FLWORExpr((yyloc),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								NULL,
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 109:
#line 1903 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [where.orderby.return]\n";
#endif
			(yyval.expr) = new FLWORExpr((yyloc),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(5) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 110:
#line 1920 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClauseList [single]\n";
#endif
			ForLetClauseList* flc_list_p = new ForLetClauseList((yyloc));
			flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = flc_list_p;
		;}
    break;

  case 111:
#line 1929 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClauseList [list]\n";
#endif
			ForLetClauseList* flc_list_p = dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(2) - (1)].node));
			if (flc_list_p) flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 112:
#line 1944 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [for]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 113:
#line 1951 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [let]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 114:
#line 1964 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForClause [ ]\n";
#endif
			(yyval.node) = new ForClause((yyloc),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 115:
#line 1978 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDeclList [single]\n";
#endif
			VarInDeclList* vardecl_list_p = new VarInDeclList((yyloc));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 116:
#line 1987 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDeclList [list]\n";
#endif
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 117:
#line 2004 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [in]\n";
#endif
			(yyval.node) = new VarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 118:
#line 2014 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.in]\n";
#endif
			(yyval.node) = new VarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 119:
#line 2025 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [posvar.in]\n";
#endif
			(yyval.node) = new VarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 120:
#line 2037 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.posvar.in]\n";
#endif
			(yyval.node) = new VarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 121:
#line 2050 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [scorevar.in]\n";
#endif
			(yyval.node) = new VarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 122:
#line 2061 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.scorevar.in]\n";
#endif
			(yyval.node) = new VarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 123:
#line 2073 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [posvar.scorevar.in]\n";
#endif
			(yyval.node) = new VarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 124:
#line 2085 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.posvar.scorevar.in]\n";
#endif
			(yyval.node) = new VarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 125:
#line 2103 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PositionalVar [ ]\n";
#endif
			(yyval.node) = new PositionalVar((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 126:
#line 2118 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTScoreVar [ ]\n";
#endif
			(yyval.node) = new FTScoreVar((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 127:
#line 2132 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClause [ ]\n";
#endif
			(yyval.node) = new LetClause((yyloc),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)));
			
		;}
    break;

  case 128:
#line 2147 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDeclList [single]\n";
#endif
			VarGetsDeclList* vgdl_p = new VarGetsDeclList((yyloc));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 129:
#line 2156 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDeclList [list.single]\n";
#endif
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 130:
#line 2173 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [gets]\n";
#endif
			(yyval.node) = new VarGetsDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 131:
#line 2184 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [type.gets]\n";
#endif
			(yyval.node) = new VarGetsDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 132:
#line 2196 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [scorevar.gets]\n";
#endif
			(yyval.node) = new VarGetsDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 133:
#line 2207 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [type.scorevar.gets]\n";
#endif
			(yyval.node) = new VarGetsDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 134:
#line 2225 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "WhereClause [ ]\n";
#endif
			(yyval.node) = new WhereClause((yyloc),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 135:
#line 2239 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [ ]\n";
#endif
			(yyval.node) = new OrderByClause((yyloc),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 136:
#line 2247 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [stable]\n";
#endif
			(yyval.node) = new OrderByClause((yyloc),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)),
								true);
		;}
    break;

  case 137:
#line 2262 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpecList [single]\n";
#endif
			OrderSpecList* osl_p = new OrderSpecList((yyloc));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 138:
#line 2271 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpecList [list]\n";
#endif
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 139:
#line 2288 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpec [single]\n";
#endif
			(yyval.node) = new OrderSpec((yyloc),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 140:
#line 2297 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpec [single.modifier]\n";
#endif
			(yyval.node) = new OrderSpec((yyloc),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 141:
#line 2312 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir]\n";
#endif
			(yyval.node) = new OrderModifier((yyloc),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 142:
#line 2322 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [empty]\n";
#endif
			(yyval.node) = new OrderModifier((yyloc),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 143:
#line 2332 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [collation]\n";
#endif
			(yyval.node) = new OrderModifier((yyloc),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 144:
#line 2342 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir.empty]\n";
#endif
			(yyval.node) = new OrderModifier((yyloc),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 145:
#line 2352 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir.collation]\n";
#endif
			(yyval.node) = new OrderModifier((yyloc),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 146:
#line 2362 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [empty.collation]\n";
#endif
			(yyval.node) = new OrderModifier((yyloc),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 147:
#line 2372 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir.empty.collation]\n";
#endif
			(yyval.node) = new OrderModifier((yyloc),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 148:
#line 2388 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [ascending]\n";
#endif
			(yyval.node) = new OrderDirSpec((yyloc), dir_ascending);
		;}
    break;

  case 149:
#line 2395 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [descending]\n";
#endif
			(yyval.node) = new OrderDirSpec((yyloc), dir_descending);
		;}
    break;

  case 150:
#line 2408 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [greatest]\n";
#endif
			(yyval.node) = new OrderEmptySpec((yyloc),
								StaticQueryContext::empty_greatest);
		;}
    break;

  case 151:
#line 2416 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [least]\n";
#endif
			(yyval.node) = new OrderEmptySpec((yyloc),
								StaticQueryContext::empty_least);
		;}
    break;

  case 152:
#line 2430 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderCollationSpec [ ]\n";
#endif
			(yyval.node) = new OrderCollationSpec((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 153:
#line 2444 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuantifiedExpr [some]\n";
#endif
			(yyval.expr) = new QuantifiedExpr((yyloc),
								quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 154:
#line 2454 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuantifiedExpr [every]\n";
#endif
			(yyval.expr) = new QuantifiedExpr((yyloc),
								quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 155:
#line 2470 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDeclList [single]\n";
#endif
			QVarInDeclList* qvid_list_p = new QVarInDeclList((yyloc));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 156:
#line 2480 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDeclList [list]\n";
#endif
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 157:
#line 2495 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDecl [in]\n";
#endif
			(yyval.node) = new QVarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 158:
#line 2504 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDecl [type.in]\n";
#endif
			(yyval.node) = new QVarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 159:
#line 2520 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeswitchExpr [cases.default.return]\n";
#endif
			(yyval.expr) = new TypeswitchExpr((yyloc),
								(yysemantic_stack_[(7) - (2)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(7) - (4)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 160:
#line 2530 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeswitchExpr [cases.default.varname.return]\n";
#endif
			(yyval.expr) = new TypeswitchExpr((yyloc),
								(yysemantic_stack_[(9) - (2)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(9) - (4)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval)),
								(yysemantic_stack_[(9) - (9)].expr));
		;}
    break;

  case 161:
#line 2547 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClauseList [single]\n";
#endif
			CaseClauseList* cc_list_p = new CaseClauseList((yyloc));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 162:
#line 2556 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClauseList [list]\n";
#endif
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 163:
#line 2571 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClause [case.return]\n";
#endif
			(yyval.node) = new CaseClause((yyloc),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 164:
#line 2580 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClause [case.as.return]\n";
#endif
			(yyval.node) = new CaseClause((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 165:
#line 2596 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IfExpr [ ]\n";
#endif
			(yyval.expr) = new IfExpr((yyloc),
								(yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 166:
#line 2610 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [and]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 167:
#line 2617 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [or.and]\n";
#endif
			(yyval.expr) = new OrExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 168:
#line 2631 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [comp]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 169:
#line 2638 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [and.comp]\n";
#endif
			(yyval.expr) = new AndExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 170:
#line 2660 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 171:
#line 2667 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains.valcomp.ftcontains]\n";
#endif
			(yyval.expr) = new ComparisonExpr((yyloc),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 172:
#line 2678 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains.gencomp.ftcontains]\n";
#endif
			(yyval.expr) = new ComparisonExpr((yyloc),
								dynamic_cast<GeneralComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 173:
#line 2689 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "is" | "<<" | ">>" */
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains.nodecomp.ftcontains]\n";
#endif
			(yyval.expr) = new ComparisonExpr((yyloc),
								dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 174:
#line 2706 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 175:
#line 2713 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range.ftselect]\n";
#endif
			(yyval.expr) = new FTContainsExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 176:
#line 2723 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range.ftselect.ftignore]\n";
#endif
			(yyval.expr) = new FTContainsExpr((yyloc),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 177:
#line 2739 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 178:
#line 2746 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add.to.add]\n";
#endif
			(yyval.expr) = new RangeExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 179:
#line 2760 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 180:
#line 2767 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult+mult]\n";
#endif
			(yyval.expr) = new AdditiveExpr((yyloc), op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 181:
#line 2774 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult-mult]\n";
#endif
			(yyval.expr) = new AdditiveExpr((yyloc), op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 182:
#line 2787 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [union]\n";
#endif
		;}
    break;

  case 183:
#line 2793 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult*union]\n";
#endif
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 184:
#line 2800 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.div.union]\n";
#endif
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 185:
#line 2807 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.idiv.union]\n";
#endif
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 186:
#line 2814 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.mod.union]\n";
#endif
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 187:
#line 2827 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [interexcept]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 188:
#line 2834 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union.union.interexcept]\n";
#endif
			(yyval.expr) = new UnionExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 189:
#line 2842 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union|interexcept]\n";
#endif
			(yyval.expr) = new UnionExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 190:
#line 2856 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [instanceof]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 191:
#line 2863 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.inter.instanceof]\n";
#endif
			(yyval.expr) = new IntersectExceptExpr((yyloc), op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 192:
#line 2870 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.except.instanceof]\n";
#endif
			(yyval.expr) = new IntersectExceptExpr((yyloc), op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 193:
#line 2883 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 194:
#line 2890 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat.seqtype]\n";
#endif
			(yyval.expr) = new InstanceofExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 195:
#line 2905 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 196:
#line 2912 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable.seqtype]\n";
#endif
			(yyval.expr) = new TreatExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 197:
#line 2927 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 198:
#line 2934 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast.singletype]\n";
#endif
			(yyval.expr) = new CastableExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 199:
#line 2949 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 200:
#line 2956 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary.singletype]\n";
#endif
			(yyval.expr) = new CastExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 201:
#line 2971 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [value]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 202:
#line 2978 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [signlist.value]\n";
#endif
			(yyval.expr) = new UnaryExpr((yyloc),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 203:
#line 2993 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [+]\n";
#endif
			(yyval.node) = new SignList((yyloc), true);
		;}
    break;

  case 204:
#line 3000 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [-]\n";
#endif
			(yyval.node) = new SignList((yyloc), false);
		;}
    break;

  case 205:
#line 3007 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.+]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 206:
#line 3014 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.-]\n";
#endif
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 207:
#line 3029 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [validate]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 208:
#line 3036 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [path]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 209:
#line 3043 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [extension]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 210:
#line 3057 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [=]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_eq);
		;}
    break;

  case 211:
#line 3064 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [!=]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_ne);
		;}
    break;

  case 212:
#line 3071 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_lt);
		;}
    break;

  case 213:
#line 3078 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<=]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_le);
		;}
    break;

  case 214:
#line 3085 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_gt);
		;}
    break;

  case 215:
#line 3092 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>=]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_ge);
		;}
    break;

  case 216:
#line 3105 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [eq]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_eq);
		;}
    break;

  case 217:
#line 3112 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ne]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_ne);
		;}
    break;

  case 218:
#line 3119 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [lt]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_lt);
		;}
    break;

  case 219:
#line 3126 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [le]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_le);
		;}
    break;

  case 220:
#line 3133 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [gt]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_gt);
		;}
    break;

  case 221:
#line 3140 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ge]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_ge);
		;}
    break;

  case 222:
#line 3153 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [is]\n";
#endif
			(yyval.node) = new NodeComp((yyloc), op_is);
		;}
    break;

  case 223:
#line 3160 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [<<]\n";
#endif
			(yyval.node) = new NodeComp((yyloc), op_precedes);
		;}
    break;

  case 224:
#line 3167 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [>>]\n";
#endif
			(yyval.node) = new NodeComp((yyloc), op_follows);
		;}
    break;

  case 225:
#line 3181 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [expr]\n";
#endif
			(yyval.expr) = new ValidateExpr((yyloc), "strict", (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 226:
#line 3188 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [mode.expr]\n";
#endif
			(yyval.expr) = new ValidateExpr((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 227:
#line 3203 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExtensionExpr [pragmalist]\n";
#endif
			(yyval.expr) = new ExtensionExpr((yyloc),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 228:
#line 3212 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExtensionExpr [pragmalist.expr]\n";
#endif
			(yyval.expr) = new ExtensionExpr((yyloc),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 229:
#line 3227 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PragmaList [single]\n";
#endif
			PragmaList* pragma_list_p = new PragmaList((yyloc));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 230:
#line 3236 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PragmaList [list]\n";
#endif
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 231:
#line 3253 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Pragma [ ]\n";
#endif
			(yyval.node) = new Pragma((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 232:
#line 3261 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 233:
#line 3304 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/]\n";
#endif
			(yyval.expr) = new PathExpr((yyloc), path_leading_lone_slash, NULL);
		;}
    break;

  case 234:
#line 3311 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/relative]\n";
#endif
			(yyval.expr) = new PathExpr((yyloc), path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 235:
#line 3318 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [//relative]\n";
#endif
			(yyval.expr) = new PathExpr((yyloc), path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 236:
#line 3325 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [relative]\n";
#endif
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = rpe == NULL ? (yysemantic_stack_[(1) - (1)].expr) : new PathExpr((yyloc), path_relative, (yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 237:
#line 3339 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step]\n";
#endif
            AxisStep *as = dynamic_cast<AxisStep *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = as != NULL ? new RelativePathExpr((yyloc), st_slash, new ContextItemExpr((yyloc)), (yysemantic_stack_[(1) - (1)].expr)) : (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 238:
#line 3347 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step/relative]\n";
#endif
			(yyval.expr) = new RelativePathExpr((yyloc), st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 239:
#line 3354 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step//relative]\n";
#endif
			(yyval.expr) = new RelativePathExpr((yyloc), st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 240:
#line 3367 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [axis]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 241:
#line 3374 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [filter]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 242:
#line 3387 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward]\n";
#endif
			(yyval.expr) = new AxisStep((yyloc),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 243:
#line 3396 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward.predlist]\n";
#endif
			(yyval.expr) = new AxisStep((yyloc),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 244:
#line 3405 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse]\n";
#endif
			(yyval.expr) = new AxisStep((yyloc),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 245:
#line 3414 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse.predlist]\n";
#endif
			(yyval.expr) = new AxisStep((yyloc),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 246:
#line 3429 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [nodetest]\n";
#endif
			(yyval.node) = new ForwardStep((yyloc),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 247:
#line 3438 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [abbrev]\n";
#endif
			(yyval.node) = new ForwardStep((yyloc),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 248:
#line 3452 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [child]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_child);
		;}
    break;

  case 249:
#line 3459 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_descendant);
		;}
    break;

  case 250:
#line 3466 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [attribute]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_attribute);
		;}
    break;

  case 251:
#line 3473 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [self]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_self);
		;}
    break;

  case 252:
#line 3480 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant_or_self]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_descendant_or_self);
		;}
    break;

  case 253:
#line 3487 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following_sibling]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_following_sibling);
		;}
    break;

  case 254:
#line 3494 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_following);
		;}
    break;

  case 255:
#line 3507 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [nodetest]\n";
#endif
			(yyval.node) = new AbbrevForwardStep((yyloc), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 256:
#line 3514 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [@ nodetest]\n";
#endif
			(yyval.node) = new AbbrevForwardStep((yyloc), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 257:
#line 3527 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [nodetest]\n";
#endif
			(yyval.node) = new ReverseStep((yyloc),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 258:
#line 3536 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [..]\n";
#endif
			ReverseAxis* rev_p = new ReverseAxis((yyloc), axis_parent);
			(yyval.node) = new ReverseStep((yyloc),
								rev_p);
		;}
    break;

  case 259:
#line 3551 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [parent]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_parent);
		;}
    break;

  case 260:
#line 3558 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_ancestor);
		;}
    break;

  case 261:
#line 3565 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding_sibling]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_preceding_sibling);
		;}
    break;

  case 262:
#line 3572 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_preceding);
		;}
    break;

  case 263:
#line 3579 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor_or_self]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_ancestor_or_self);
		;}
    break;

  case 264:
#line 3597 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [kindtest]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 265:
#line 3604 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [nametest]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 266:
#line 3617 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [qname]\n";
#endif
			(yyval.node) = new NameTest((yyloc), new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 267:
#line 3624 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [wildcard]\n";
#endif
			(yyval.node) = new NameTest((yyloc), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 268:
#line 3637 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Wildcard [*]\n";
#endif
			(yyval.node) = new Wildcard((yyloc),
                        "",
                        "",
                        wild_all);
		;}
    break;

  case 269:
#line 3647 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Wildcard [pref:*]\n";
#endif
			(yyval.node) = new Wildcard((yyloc),
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        wild_elem);
		;}
    break;

  case 270:
#line 3657 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Wildcard [*:qname]\n";
#endif
			(yyval.node) = new Wildcard((yyloc),
                        "",
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        wild_prefix);
		;}
    break;

  case 271:
#line 3673 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 272:
#line 3680 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary.predlist]\n";
#endif
			(yyval.expr) = new FilterExpr((yyloc),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 273:
#line 3695 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PredicateList [single]\n";
#endif
			PredicateList* pred_list_p = new PredicateList((yyloc));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 274:
#line 3704 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PredicateList [list]\n";
#endif
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 275:
#line 3721 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Predicate [ ]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 276:
#line 3735 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [literal]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 277:
#line 3742 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [varref]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 278:
#line 3749 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [paren]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 279:
#line 3756 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [context_item]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 280:
#line 3763 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [funcall]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 281:
#line 3770 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [cons]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 282:
#line 3777 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [ordered]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 283:
#line 3784 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [unordered]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 284:
#line 3797 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [numeric]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 285:
#line 3804 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [string]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 286:
#line 3817 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [decimal]\n";
#endif
			(yyval.expr) = new NumericLiteral((yyloc), *yylval.decval);
      delete yylval.decval;
		;}
    break;

  case 287:
#line 3825 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [int]\n";
#endif
			(yyval.expr) = new NumericLiteral((yyloc), *yylval.ival);
      delete yylval.ival;
		;}
    break;

  case 288:
#line 3833 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [double]\n";
#endif
			(yyval.expr) = new NumericLiteral((yyloc), *yylval.dval);
      delete yylval.dval;
		;}
    break;

  case 289:
#line 3847 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarRef [ ]\n";
#endif
			(yyval.expr) = new VarRef((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 290:
#line 3860 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [()]\n";
#endif
			(yyval.expr) = new ParenthesizedExpr((yyloc), NULL);
		;}
    break;

  case 291:
#line 3867 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [(expr)]\n";
#endif
			(yyval.expr) = new ParenthesizedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 292:
#line 3881 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ContextItemExpr [.]\n";
#endif
			(yyval.expr) = new ContextItemExpr((yyloc));
		;}
    break;

  case 293:
#line 3894 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderedExpr [expr]\n";
#endif
			(yyval.expr) = new OrderedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 294:
#line 3908 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnorderedExpr [expr]\n";
#endif
			(yyval.expr) = new UnorderedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 295:
#line 3967 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [ ]\n";
#endif
			(yyval.expr) = new FunctionCall((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 296:
#line 3976 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [arglist]\n";
#endif
			(yyval.expr) = new FunctionCall((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 297:
#line 3991 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [single]\n";
#endif
			ArgList* a_list_p = new ArgList((yyloc)); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 298:
#line 4000 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [list]\n";
#endif
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 299:
#line 4015 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [direct]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 300:
#line 4022 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [computed]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 301:
#line 4035 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [element]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 4042 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [comment]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 303:
#line 4049 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [pi]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 304:
#line 4062 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname/> ]\n";
#endif
			(yyval.expr) = new DirElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 305:
#line 4073 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname attrlist/> ]\n";
#endif
			(yyval.expr) = new DirElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(4) - (3)].node)), 
								NULL);
		;}
    break;

  case 306:
#line 4084 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname></qname>]\n";
#endif
			(yyval.expr) = new DirElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (5)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 307:
#line 4095 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname>content</qname>]\n";
#endif
			(yyval.expr) = new DirElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (6)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(7) - (4)].node)));
		;}
    break;

  case 308:
#line 4106 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname attrlist></qname>]\n";
#endif
			(yyval.expr) = new DirElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (6)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(7) - (3)].node)),
								NULL);
		;}
    break;

  case 309:
#line 4117 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname attrlist>content</qname>]\n";
#endif
			(yyval.expr) = new DirElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(8) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(8) - (5)].node)));
		;}
    break;

  case 310:
#line 4135 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [single]\n";
#endif
			DirElemContentList* elem_content_list_p = new DirElemContentList((yyloc));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 311:
#line 4144 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [list]\n";
#endif
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 312:
#line 4159 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeList [single]\n";
#endif
			DirAttributeList* at_list_p = new DirAttributeList((yyloc));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 313:
#line 4168 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeList [list]\n";
#endif
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 314:
#line 4185 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttr [ ]\n";
#endif
			(yyval.node) = new DirAttr((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 315:
#line 4200 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [quote]\n";
#endif
			(yyval.node) = new DirAttributeValue((yyloc),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 316:
#line 4208 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [apos]\n";
#endif
			(yyval.node) = new DirAttributeValue((yyloc),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 317:
#line 4222 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList[empty]\n";
#endif
			(yyval.node) = new QuoteAttrContentList((yyloc));
		;}
    break;

  case 318:
#line 4229 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 319:
#line 4236 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [""]\n";
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList((yyloc));
			qo_list_p->push_back(new QuoteAttrValueContent((yyloc),string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 320:
#line 4245 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [single]\n";
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList((yyloc));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 321:
#line 4254 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [list ""]\n";
#endif
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent((yyloc),string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 322:
#line 4265 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [list]\n";
#endif
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
		;}
    break;

  case 323:
#line 4281 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']\n";
#endif
			(yyval.node) = new AposAttrContentList((yyloc));
		;}
    break;

  case 324:
#line 4288 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 325:
#line 4295 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']\n";
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList((yyloc));
			at_list_p->push_back(new AposAttrValueContent((yyloc),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 326:
#line 4304 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [single]\n";
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList((yyloc));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 327:
#line 4313 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [list.'']\n";
#endif
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent((yyloc),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 328:
#line 4324 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [list.single]\n";
#endif
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 329:
#line 4341 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [quote_attr_content]\n";
#endif
			(yyval.node) = new QuoteAttrValueContent((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 330:
#line 4349 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [common_content]\n";
#endif
			(yyval.node) = new QuoteAttrValueContent((yyloc),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 331:
#line 4363 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [apos_attr_content]\n";
#endif
			(yyval.node) = new AposAttrValueContent((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 332:
#line 4371 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [common_content]\n";
#endif
			(yyval.node) = new AposAttrValueContent((yyloc),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 333:
#line 4385 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cons]\n";
#endif
			(yyval.expr) = new DirElemContent((yyloc),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 334:
#line 4393 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [elem_content]\n";
#endif
			(yyval.expr) = new DirElemContent((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 335:
#line 4401 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cdata]\n";
#endif
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent((yyloc),
								cdata_h);
		;}
    break;

  case 336:
#line 4410 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [common_content]\n";
#endif
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent((yyloc),
								cont_h);
		;}
    break;

  case 337:
#line 4425 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [entity_ref]\n";
#endif
			(yyval.expr) = new CommonContent((yyloc),
								cont_entity,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 338:
#line 4434 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [char_ref]\n";
#endif
			(yyval.expr) = new CommonContent((yyloc),
								cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 339:
#line 4443 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [{{]\n";
#endif
			(yyval.expr) = new CommonContent((yyloc),
								cont_escape_lbrace);
		;}
    break;

  case 340:
#line 4451 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [}}]\n";
#endif
			(yyval.expr) = new CommonContent((yyloc),
								cont_escape_rbrace);
		;}
    break;

  case 341:
#line 4459 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [expr]\n";
#endif
			(yyval.expr) = new CommonContent((yyloc),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 342:
#line 4473 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirCommentConstructor [ ]\n";
#endif
			(yyval.expr) = new DirCommentConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 343:
#line 4481 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "DirCommentConstructor [ ]\n";
#endif
      (yyval.expr) = new DirCommentConstructor((yyloc), "");
    ;}
    break;

  case 344:
#line 4499 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target]\n";
#endif
			(yyval.expr) = new DirPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 345:
#line 4507 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target.charlit]\n";
#endif
			(yyval.expr) = new DirPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 346:
#line 4527 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CDataSection [ ]\n";
#endif
			(yyval.expr) = new CDataSection((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 347:
#line 4545 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [doc]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 348:
#line 4552 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [elem]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 349:
#line 4559 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [attr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 350:
#line 4566 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [text]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 351:
#line 4573 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [comment]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 352:
#line 4580 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [pi]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 353:
#line 4593 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompDocConstructor [ ]\n";
#endif
			(yyval.expr) = new CompDocConstructor((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 354:
#line 4607 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [ ]\n";
#endif
			(yyval.expr) = new CompElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 355:
#line 4616 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [content]\n";
#endif
			(yyval.expr) = new CompElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 356:
#line 4625 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name]\n";
#endif
			(yyval.expr) = new CompElemConstructor((yyloc),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 357:
#line 4633 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name.content]\n";
#endif
			(yyval.expr) = new CompElemConstructor((yyloc),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 358:
#line 4661 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [ ]\n";
#endif
			(yyval.expr) = new CompAttrConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 359:
#line 4670 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [val]\n";
#endif
			(yyval.expr) = new CompAttrConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 360:
#line 4679 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name]\n";
#endif
			(yyval.expr) = new CompAttrConstructor((yyloc),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 361:
#line 4687 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name.val]\n";
#endif
			(yyval.expr) = new CompAttrConstructor((yyloc),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 362:
#line 4701 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompTextConstructor [content]\n";
#endif
			(yyval.expr) = new CompTextConstructor((yyloc),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 363:
#line 4715 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompCommentConstructor [content]\n";
#endif
			(yyval.expr) = new CompCommentConstructor((yyloc),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 364:
#line 4729 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [ ]\n";
#endif
			(yyval.expr) = new CompPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 365:
#line 4738 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [content]\n";
#endif
			(yyval.expr) = new CompPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 366:
#line 4747 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target]\n";
#endif
			(yyval.expr) = new CompPIConstructor((yyloc),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 367:
#line 4755 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target.content]\n";
#endif
			(yyval.expr) = new CompPIConstructor((yyloc),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 368:
#line 4769 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic]\n";
#endif
			(yyval.node) = new SingleType((yyloc),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 369:
#line 4778 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic ?]\n";
#endif
			(yyval.node) = new SingleType((yyloc),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 370:
#line 4793 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeDeclaration [as seqtype]\n";
#endif
			(yyval.node) = new TypeDeclaration((yyloc),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 371:
#line 4807 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type]\n";
#endif
			(yyval.node) = new SequenceType((yyloc),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 372:
#line 4816 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type.occurs]\n";
#endif
			(yyval.node) = new SequenceType((yyloc),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 373:
#line 4825 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [void]\n";
#endif
			(yyval.node) = new SequenceType((yyloc), NULL, NULL);
		;}
    break;

  case 374:
#line 4865 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [?]\n";
#endif
			(yyval.node) = new OccurrenceIndicator((yyloc),
								occurs_optionally);
		;}
    break;

  case 375:
#line 4873 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [*]\n";
#endif
			(yyval.node) = new OccurrenceIndicator((yyloc),
								occurs_zero_or_more);
		;}
    break;

  case 376:
#line 4881 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [+]\n";
#endif
			(yyval.node) = new OccurrenceIndicator((yyloc),
								occurs_one_or_more);
		;}
    break;

  case 377:
#line 4895 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [atomic]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 378:
#line 4902 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [kind]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 379:
#line 4909 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [item]\n";
#endif
			(yyval.node) = new ItemType((yyloc),true);
		;}
    break;

  case 380:
#line 4922 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AtomicType [qname]\n";
#endif
			(yyval.node) = new AtomicType((yyloc),
								new QName((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 381:
#line 4936 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [doc]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 382:
#line 4943 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [elem]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 383:
#line 4950 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [attr]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 384:
#line 4957 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_elem]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 385:
#line 4964 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_attr]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 386:
#line 4971 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [pi]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 387:
#line 4978 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [comment]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 388:
#line 4985 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [text]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 389:
#line 4992 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [any]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 390:
#line 5005 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AnyKindTest [ ]\n";
#endif
			(yyval.node) = new AnyKindTest((yyloc));
		;}
    break;

  case 391:
#line 5018 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [ ]\n";
#endif
			(yyval.node) = new DocumentTest((yyloc));
		;}
    break;

  case 392:
#line 5025 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [elem]\n";
#endif
			(yyval.node) = new DocumentTest((yyloc),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 393:
#line 5033 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [schema_elem]\n";
#endif
			(yyval.node) = new DocumentTest((yyloc),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 394:
#line 5047 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TextTest [ ]\n";
#endif
			(yyval.node) = new TextTest((yyloc));
		;}
    break;

  case 395:
#line 5060 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommentTest [ ]\n";
#endif
			(yyval.node) = new CommentTest((yyloc));
		;}
    break;

  case 396:
#line 5073 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ ]\n";
#endif
			(yyval.node) = new PITest((yyloc), "");
		;}
    break;

  case 397:
#line 5080 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ncname]\n";
#endif
			(yyval.node) = new PITest((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 398:
#line 5087 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [stringlit]\n";
#endif
			(yyval.node) = new PITest((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 399:
#line 5100 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [ ]\n";
#endif
			(yyval.node) = new AttributeTest((yyloc),
								NULL,
								NULL);
		;}
    break;

  case 400:
#line 5109 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name]\n";
#endif
			(yyval.node) = new AttributeTest((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL);
		;}
    break;

  case 401:
#line 5118 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name.type]\n";
#endif
			(yyval.node) = new AttributeTest((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 402:
#line 5127 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*]\n";
#endif
			(yyval.node) = new AttributeTest((yyloc),
								NULL,
								NULL);
		;}
    break;

  case 403:
#line 5136 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*.type]\n";
#endif
			(yyval.node) = new AttributeTest((yyloc),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 404:
#line 5151 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaAttributeTest [ ]\n";
#endif
			(yyval.node) = new SchemaAttributeTest((yyloc),
								new QName((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 405:
#line 5165 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [ ]\n";
#endif
			(yyval.node) = new ElementTest((yyloc),
									NULL,
									NULL);
		;}
    break;

  case 406:
#line 5174 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name]\n";
#endif
			(yyval.node) = new ElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
									NULL);
		;}
    break;

  case 407:
#line 5183 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name.type]\n";
#endif
			(yyval.node) = new ElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 408:
#line 5192 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name.type]\n";
#endif
			(yyval.node) = new ElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 409:
#line 5201 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [*]\n";
#endif
			(yyval.node) = new ElementTest((yyloc),
									NULL,
									NULL,
									true);
		;}
    break;

  case 410:
#line 5211 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [*.type]\n";
#endif
			(yyval.node) = new ElementTest((yyloc),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)),
									true);
		;}
    break;

  case 411:
#line 5221 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [*.type]\n";
#endif
			(yyval.node) = new ElementTest((yyloc),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)),
									true);
		;}
    break;

  case 412:
#line 5237 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaElementTest [ ]\n";
#endif
			(yyval.node) = new SchemaElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 413:
#line 5261 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name]\n";
#endif
			(yyval.node) = new TypeName((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 414:
#line 5271 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name?]\n";
#endif
			(yyval.node) = new TypeName((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 415:
#line 5294 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StringLiteral [ ]\n";
#endif
			(yyval.expr) = new StringLiteral((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 416:
#line 5336 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [ ]\n";
#endif
		;}
    break;

  case 417:
#line 5348 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr]\n";
#endif
		;}
    break;

  case 418:
#line 5354 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.as_first]\n";
#endif
		;}
    break;

  case 419:
#line 5360 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.as_last]\n";
#endif
		;}
    break;

  case 420:
#line 5366 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.after]\n";
#endif
		;}
    break;

  case 421:
#line 5372 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.before]\n";
#endif
		;}
    break;

  case 422:
#line 5384 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteExpr [expr]\n";
#endif
		;}
    break;

  case 423:
#line 5396 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceExpr [expr.expr]\n";
#endif
		;}
    break;

  case 424:
#line 5402 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceExpr [value.expr]\n";
#endif
		;}
    break;

  case 425:
#line 5414 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RenameExpr [expr.expr]\n";
#endif
		;}
    break;

  case 426:
#line 5441 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TransformExpr [ ]\n";
#endif
		;}
    break;

  case 427:
#line 5453 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [single]\n";
#endif
		;}
    break;

  case 428:
#line 5459 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [list]\n";
#endif
		;}
    break;

  case 429:
#line 5479 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or]\n";
#endif
		;}
    break;

  case 430:
#line 5485 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity]\n";
#endif
		;}
    break;

  case 431:
#line 5491 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.weight_range]\n";
#endif
		;}
    break;

  case 432:
#line 5497 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity.weight_range]\n";
#endif
		;}
    break;

  case 433:
#line 5509 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_single]\n";
#endif
		;}
    break;

  case 434:
#line 5515 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_single]\n";
#endif
		;}
    break;

  case 435:
#line 5521 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_list]\n";
#endif
		;}
    break;

  case 436:
#line 5527 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_list]\n";
#endif
		;}
    break;

  case 437:
#line 5539 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [and]\n";
#endif
		;}
    break;

  case 438:
#line 5545 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [or.and]\n";
#endif
		;}
    break;

  case 439:
#line 5557 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [mild_not]\n";
#endif
		;}
    break;

  case 440:
#line 5563 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [and.mild_not]\n";
#endif
		;}
    break;

  case 441:
#line 5575 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [unary_not]\n";
#endif
		;}
    break;

  case 442:
#line 5581 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [mild_not.unary_not]\n";
#endif
		;}
    break;

  case 443:
#line 5593 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [words]\n";
#endif
		;}
    break;

  case 444:
#line 5599 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [not.words]\n";
#endif
		;}
    break;

  case 445:
#line 5611 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words]\n";
#endif
		;}
    break;

  case 446:
#line 5617 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words.times]\n";
#endif
		;}
    break;

  case 447:
#line 5623 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [selection]\n";
#endif
		;}
    break;

  case 448:
#line 5635 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value]\n";
#endif
		;}
    break;

  case 449:
#line 5641 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value.any_all_option]\n";
#endif
		;}
    break;

  case 450:
#line 5653 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [literal]\n";
#endif
		;}
    break;

  case 451:
#line 5659 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [expr]\n";
#endif
		;}
    break;

  case 452:
#line 5671 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [order]\n";
#endif
		;}
    break;

  case 453:
#line 5677 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [window]\n";
#endif
		;}
    break;

  case 454:
#line 5683 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [distance]\n";
#endif
		;}
    break;

  case 455:
#line 5689 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [scope]\n";
#endif
		;}
    break;

  case 456:
#line 5695 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [content]\n";
#endif
		;}
    break;

  case 457:
#line 5707 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOrderedIndicator [ ]\n";
#endif
		;}
    break;

  case 458:
#line 5719 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [case]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 459:
#line 5726 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [diacritics]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 460:
#line 5733 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stem]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 461:
#line 5740 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [thesaurus]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 462:
#line 5747 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stopword]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 463:
#line 5754 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [language]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 464:
#line 5761 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [wildcard]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 465:
#line 5774 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [lower]\n";
#endif
		;}
    break;

  case 466:
#line 5780 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [upper]\n";
#endif
		;}
    break;

  case 467:
#line 5786 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [sensitive]\n";
#endif
		;}
    break;

  case 468:
#line 5792 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [insensitive]\n";
#endif
		;}
    break;

  case 469:
#line 5804 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [with]\n";
#endif
		;}
    break;

  case 470:
#line 5810 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [without]\n";
#endif
		;}
    break;

  case 471:
#line 5816 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [sensitive]\n";
#endif
		;}
    break;

  case 472:
#line 5822 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [insensitive]\n";
#endif
		;}
    break;

  case 473:
#line 5834 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [with]\n";
#endif
		;}
    break;

  case 474:
#line 5840 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [without]\n";
#endif
		;}
    break;

  case 475:
#line 5852 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [id]\n";
#endif
		;}
    break;

  case 476:
#line 5858 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [default]\n";
#endif
		;}
    break;

  case 477:
#line 5864 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id)]\n";
#endif
		;}
    break;

  case 478:
#line 5870 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id,id,..)]\n";
#endif
		;}
    break;

  case 479:
#line 5876 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default)]\n";
#endif
		;}
    break;

  case 480:
#line 5882 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default,id,id,..)]\n";
#endif
		;}
    break;

  case 481:
#line 5888 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [without]\n";
#endif
		;}
    break;

  case 482:
#line 5900 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [single]\n";
#endif
		;}
    break;

  case 483:
#line 5906 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [list]\n";
#endif
		;}
    break;

  case 484:
#line 5918 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name]\n";
#endif
		;}
    break;

  case 485:
#line 5924 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel]\n";
#endif
		;}
    break;

  case 486:
#line 5930 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.range]\n";
#endif
		;}
    break;

  case 487:
#line 5936 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel.range]\n";
#endif
		;}
    break;

  case 488:
#line 5948 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list]\n";
#endif
		;}
    break;

  case 489:
#line 5954 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list.incl_excl]\n";
#endif
		;}
    break;

  case 490:
#line 5960 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default]\n";
#endif
		;}
    break;

  case 491:
#line 5966 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default.incl_excl]\n";
#endif
		;}
    break;

  case 492:
#line 5972 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [without]\n";
#endif
		;}
    break;

  case 493:
#line 5984 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [.]\n";
#endif
		;}
    break;

  case 494:
#line 5990 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [*]\n";
#endif
		;}
    break;

  case 495:
#line 6002 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [.]\n";
#endif
		;}
    break;

  case 496:
#line 6008 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [(*)]\n";
#endif
		;}
    break;

  case 497:
#line 6020 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [.]\n";
#endif
		;}
    break;

  case 498:
#line 6026 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [*]\n";
#endif
		;}
    break;

  case 499:
#line 6038 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [union]\n";
#endif
		;}
    break;

  case 500:
#line 6044 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [except]\n";
#endif
		;}
    break;

  case 501:
#line 6056 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTLanguageOption [ ]\n";
#endif
		;}
    break;

  case 502:
#line 6068 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [with]\n";
#endif
		;}
    break;

  case 503:
#line 6074 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [without]\n";
#endif
		;}
    break;

  case 504:
#line 6086 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [start]\n";
#endif
		;}
    break;

  case 505:
#line 6092 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [end]\n";
#endif
		;}
    break;

  case 506:
#line 6098 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [entire]\n";
#endif
		;}
    break;

  case 507:
#line 6110 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any]\n";
#endif
		;}
    break;

  case 508:
#line 6116 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any_word]\n";
#endif
		;}
    break;

  case 509:
#line 6122 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all]\n";
#endif
		;}
    break;

  case 510:
#line 6128 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all_words]\n";
#endif
		;}
    break;

  case 511:
#line 6134 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [phrase]\n";
#endif
		;}
    break;

  case 512:
#line 6146 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [exactly]\n";
#endif
		;}
    break;

  case 513:
#line 6152 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_least]\n";
#endif
		;}
    break;

  case 514:
#line 6158 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_most]\n";
#endif
		;}
    break;

  case 515:
#line 6164 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [range]\n";
#endif
		;}
    break;

  case 516:
#line 6176 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDistance [ ]\n";
#endif
		;}
    break;

  case 517:
#line 6188 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWindow [ ]\n";
#endif
		;}
    break;

  case 518:
#line 6200 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [ ]\n";
#endif
		;}
    break;

  case 519:
#line 6212 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [same]\n";
#endif
		;}
    break;

  case 520:
#line 6218 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [different]\n";
#endif
		;}
    break;

  case 521:
#line 6230 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [words]\n";
#endif
		;}
    break;

  case 522:
#line 6236 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [sentences]\n";
#endif
		;}
    break;

  case 523:
#line 6242 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [paragraph]\n";
#endif
		;}
    break;

  case 524:
#line 6254 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [sentence]\n";
#endif
		;}
    break;

  case 525:
#line 6260 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [paragraph]\n";
#endif
		;}
    break;

  case 526:
#line 6272 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTIgnoreOption [ ]\n";
#endif
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6126 "/Users/mbrantner/misc/code/vanilla/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
	error (yylloc, yysyntax_error_ (yystate));
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
  xquery_parser::yysyntax_error_ (int yystate)
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
  const short int xquery_parser::yypact_ninf_ = -635;
  const short int
  xquery_parser::yypact_[] =
  {
       713,  1241,  1411,  -635,  -635,    25,  -635,   -16,  -635,  -635,
    -635,  2771,    51,   354,  -635,  2771,   144,  -635,   296,   -69,
     -46,   224,   334,   236,   270,   420,   349,   412,   416,   -73,
     469,   467,  -635,  -635,  2771,   202,   472,  -635,  -635,  -635,
    2771,    54,   487,  -635,  -635,   489,  2771,    30,    28,  -635,
     493,  1581,  -635,   417,   373,  2771,  -635,   478,    63,  -635,
     559,  -635,  -635,   260,   483,   506,  -635,  3239,  3090,   487,
    -635,   518,  2771,   385,  2771,  2771,  2771,    12,   533,  -635,
    2771,  2771,  2771,  1071,   538,  3286,   570,   901,  -635,  -635,
     405,  2771,   407,   437,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,   511,  -635,  -635,   409,  -635,  -635,
    -635,  -635,  -635,  -635,   440,   580,  -635,   613,   383,   -47,
     263,   250,   217,  -635,   510,   443,   586,   587,   523,  -635,
    -635,  -635,   -40,  -635,  -635,  -635,   421,  -635,   521,   354,
    -635,   521,   354,  -635,  -635,  -635,  -635,   521,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,    96,  -635,   111,  1751,
    2771,   120,    99,  -635,   100,  -635,  -635,   181,  -635,  -635,
    -635,  -635,  -635,  -635,   590,   591,  -635,   615,   616,  -635,
    -635,   522,   553,   623,  -635,  -635,   528,   230,   189,  -635,
     492,   495,  -635,   229,   102,  -635,   103,    37,     4,  -635,
      -7,   604,  -635,   105,   620,   641,   624,   534,   646,   638,
     -11,   618,  -635,  -635,   110,   578,  -635,   234,    26,   513,
     514,  -635,   651,  -635,   561,  2771,   519,   520,  -635,  -635,
       6,    38,   238,  -635,   114,   239,   241,   486,  -635,   -22,
    -635,    -2,   647,  2771,   471,   593,   215,  -635,  -635,  -635,
    -635,   664,  -635,  -635,  -635,  -635,  -635,  -635,  -635,   -20,
    -635,  -635,   197,   333,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,   405,    -5,
    2771,  2771,  2771,  2771,  2771,  -635,   -30,   539,  2941,  2941,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  2941,  2941,  2941,    11,  2941,
    2941,  2941,  2941,  2941,  2941,  2941,  2941,  2941,  2941,  2941,
     121,   121,   671,   671,  -635,  -635,  -635,  1921,  -635,  3090,
    3090,  2771,   521,  -635,  -635,   521,  -635,   521,  -635,  -635,
    -635,  -635,   115,   242,   577,   676,  -635,   676,  -635,  -635,
     -21,   214,  -635,  -635,   232,   675,  -635,   362,   121,  -635,
    2771,   218,  -635,  -635,  -635,   588,   681,  -635,   681,  -635,
    2771,   596,   629,  2771,   631,  2771,   632,   -70,   601,    -6,
     635,   535,   691,   633,   691,  -635,   634,   683,  2771,   619,
     -68,   645,  -635,   702,  -635,  -635,  -635,  -635,  -635,  -635,
    2091,   243,  -635,  -635,  2771,   639,  -635,    59,    43,  -635,
    -635,   688,  -635,  -635,  -635,   707,  -635,   278,  2771,  2771,
    2771,  2771,   525,  2771,  2771,   718,  2771,  -635,   197,   197,
     -20,  -635,   715,   721,   -20,   722,  -635,    47,  -635,   583,
    -635,  -635,  -635,   406,   701,  -635,  -635,   701,  -635,  2771,
     597,  2771,   580,  -635,  -635,  -635,  -635,  2771,    11,   393,
    -635,   502,  3198,   524,   543,  -635,  -635,   517,   367,   263,
     263,   175,   250,   250,   250,   250,   217,   217,  -635,  -635,
    -635,  -635,  -635,  -635,   347,  -635,  -635,  -635,  -635,   655,
    -635,  -635,   244,  -635,  -635,    57,  -635,  2771,  -635,  -635,
    2261,  -635,   602,   622,  -635,  -635,  -635,  -635,   759,    22,
     121,    66,  -635,  -635,   219,   121,    94,  -635,  -635,  -635,
    2771,  2431,   689,   627,   648,   653,   654,  -635,  2771,   487,
    -635,   768,  -635,   771,  2771,   696,  2771,  2771,   -25,   698,
     489,  2771,  -635,   767,   791,   767,  -635,   691,  -635,  2771,
    2771,   716,   493,   656,  -635,   247,   708,  -635,    15,  -635,
    -635,  -635,   815,  -635,  -635,  2771,   805,  -635,  -635,    76,
    -635,  -635,  -635,  -635,    85,  -635,   226,    65,  -635,   661,
    2771,  2771,  -635,  -635,  -635,  -635,  2771,  -635,  -635,   726,
     670,  -635,  -635,  -635,  -635,  -635,    69,   -20,  -107,   185,
     188,    -5,  -635,   804,  -635,  -635,  -635,  -635,    49,   783,
    -635,  2771,  -635,  2771,  -635,   248,   672,  -635,  2941,  -635,
    -635,  -635,  -635,    70,   394,  -635,    11,    70,  2941,  2941,
    3244,  -635,  -635,  -635,  -635,  -635,  -635,  -635,    11,    11,
     394,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,   251,  -635,  -635,
     800,  -635,  -635,   255,   761,   311,   121,  -635,  -635,   324,
     336,   121,  -635,  -635,   257,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  2771,  -635,  -635,  2771,   727,
    2771,  -635,   755,   816,   807,   767,  -635,  -635,  2771,  -635,
    -635,  -635,  2601,   329,   477,  -635,  -635,   258,   666,   824,
    -635,   825,   108,   820,   690,    -9,  -635,  -635,  -635,  -635,
    -635,  2771,  2771,  -635,  -635,  2941,  2941,  2941,  2941,   823,
     612,   818,  -635,   818,  -635,  -635,   783,  -635,  -635,  -635,
    -635,  -635,  -635,   250,  -635,  -635,  -635,    53,   524,  -635,
    -635,   344,  2941,  -635,  -635,   543,  -635,   603,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,   340,  -635,  -635,  -635,  -635,
     364,  -635,  -635,  -635,  2771,  -635,  2771,  -635,   691,  -635,
    -635,   259,  -635,  -635,   827,   439,  -635,  -635,  -635,  -635,
     695,   542,  -635,  -635,  -635,  -635,   682,   692,   837,   829,
    2771,   842,  2771,  -635,  -635,   250,   250,   250,   355,   394,
    -635,   201,  -635,   223,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,   767,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,   697,   121,
    -635,   705,  -635,  2941,   636,   818,  -635,  -635,  -635,   711,
    2771,   250,  -635,  -635,  2771,  -635,  -635
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,     0,     0,   269,   270,   266,   415,     0,   260,   263,
     250,     0,     0,     0,   248,     0,     0,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   249,   252,     0,     0,     0,   292,   258,   288,
       0,     0,     0,   254,   253,     0,     0,     0,     0,   287,
       0,     0,   204,     0,     0,     0,   259,     0,     0,   203,
       0,   262,   261,     0,     0,     0,   251,   233,     0,     0,
     268,     0,     0,     0,     0,     0,     0,     0,     0,   416,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     4,
       0,     0,     0,     0,    15,    17,    19,    20,    21,    27,
      22,    25,    26,    31,    32,    33,    28,    29,    35,    36,
      23,    30,    24,     9,    93,    94,    96,     0,   110,   112,
     113,    97,    98,    99,   100,   166,   168,   170,   174,   177,
     179,   182,   187,   190,   193,   195,   197,   199,     0,   201,
     207,   209,     0,   229,   208,   236,   237,   240,   242,     0,
     247,   244,     0,   255,   265,   267,   241,   271,   276,   284,
     277,   278,   279,   282,   283,   280,   281,   299,   301,   302,
     303,   300,   347,   348,   349,   350,   351,   352,   264,   389,
     381,   388,   387,   386,   383,   385,   382,   384,   285,    34,
     101,   102,   104,   103,   105,   358,     0,   354,     0,     0,
       0,     0,     0,   399,     0,   266,   256,     0,   395,    53,
      38,    39,    70,    71,     0,     0,    52,     0,     0,    46,
      47,     0,     0,     0,    44,    45,     0,     0,     0,   391,
       0,     0,   289,     0,     0,   405,     0,     0,     0,   155,
       0,   114,   115,     0,    62,     0,    54,     0,     0,     0,
       0,   127,   128,   290,     0,     0,   390,     0,     0,     0,
       0,   396,     0,   232,     0,     0,     0,     0,   234,   235,
       0,     0,     0,   394,     0,     0,     0,     0,   343,     0,
     422,     0,     0,     0,     0,     0,     0,   468,   467,   472,
     471,     0,   465,   466,   470,   474,   492,   481,   503,   490,
     469,   473,     0,     0,   502,    43,   458,   459,   460,   461,
     462,   463,   464,     1,     3,     5,    10,     8,    12,    13,
       0,     0,     0,     0,     0,   111,     0,     0,     0,     0,
     210,   224,   215,   214,   222,   213,   212,   211,   223,   216,
     221,   220,   219,   218,   217,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   206,   205,   202,     0,   230,     0,
       0,     0,   243,   273,   246,   245,   257,   272,   359,   355,
     295,   297,     0,     0,     0,     0,   400,     0,   402,   363,
       0,     0,    40,    41,     0,     0,    42,     0,     0,    67,
       0,     0,   353,   392,   393,     0,     0,   406,     0,   409,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,    55,     0,     0,
       0,     0,   291,     0,   293,   345,   344,   397,   398,   231,
       0,     0,   404,   412,     0,     0,   304,     0,     0,   312,
     362,     0,   294,   225,   342,     0,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   501,     0,     0,
     491,   493,     0,     0,   488,     0,   476,     0,   475,     0,
      16,    18,    95,   139,   135,   137,   106,   136,   134,     0,
       0,     0,   167,   169,   172,   171,   173,     0,     0,     0,
     450,   175,   429,   437,   439,   441,   443,   445,   448,   181,
     180,   178,   184,   185,   186,   183,   188,   189,   192,   191,
     380,   379,   373,   194,   371,   377,   378,   196,   198,   368,
     200,   227,     0,   238,   239,     0,   274,     0,   296,   226,
       0,   413,     0,     0,    50,    51,    48,    49,     0,     0,
       0,     0,    88,    37,     0,     0,     0,   370,    66,    69,
       0,     0,   413,     0,     0,     0,     0,   157,     0,     0,
     154,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    64,     0,    56,    60,     0,   130,     0,
       0,     0,     0,     0,   364,     0,     0,   153,     0,   338,
     334,   337,     0,   339,   340,     0,     0,   341,   333,     0,
     310,   336,   335,   305,     0,   313,     0,     0,   161,     0,
       0,     0,   420,   421,   417,   425,     0,   423,   427,     0,
       0,   500,   499,   494,   495,   497,     0,   489,   484,     0,
       0,    14,   148,     0,   149,   150,   151,   140,   141,   142,
     143,     0,   107,     0,   108,     0,     0,   444,     0,   176,
     457,   505,   504,     0,     0,   506,     0,     0,     0,     0,
     430,   434,   452,   433,   456,   454,   453,   455,     0,     0,
       0,   446,   509,   510,   507,   508,   511,   449,   374,   376,
     375,   372,   369,   228,   275,   298,   360,     0,   401,   403,
      90,    72,    73,     0,     0,     0,     0,    80,    81,     0,
       0,     0,    68,   356,     0,   414,   407,   408,   410,   411,
     158,   156,   125,   126,   119,     0,   121,   118,     0,     0,
       0,   116,     0,     0,    63,    57,   132,   131,     0,   129,
      11,   365,     0,   323,   317,   314,   346,     0,     0,     0,
     311,     0,     0,     0,     0,     0,   162,     7,   418,   419,
     424,     0,     0,   498,   496,     0,     0,     0,     0,     0,
       0,     0,   479,     0,   477,   152,   144,   145,   146,   138,
     109,   451,   447,   526,   525,   524,   520,     0,   438,   519,
     431,     0,     0,   436,   435,   440,   442,     0,   361,    91,
      76,    77,    89,    74,    75,     0,    84,    85,    82,    83,
       0,   357,   123,   120,     0,   122,     0,    59,     0,   133,
     366,     0,   331,   325,     0,   324,   326,   332,   329,   319,
       0,   318,   320,   330,    92,   306,     0,     0,     0,     0,
       0,     0,     0,   428,   426,   513,   514,   512,     0,   485,
     486,     0,   482,     0,   147,   523,   522,   521,   516,   517,
     432,   518,    78,    79,    86,    87,   124,   165,    65,   367,
     316,   327,   328,   315,   321,   322,   307,   308,     0,     0,
     163,     0,   159,     0,     0,     0,   480,   478,   309,     0,
       0,   515,   487,   483,     0,   160,   164
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -635,  -635,  -635,   785,   787,  -635,   780,  -635,   560,   564,
    -300,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -406,  -635,  -635,  -635,  -635,  -635,
     490,   180,  -517,   795,     5,   -80,  -635,  -635,   773,  -635,
    -635,   312,   475,  -235,  -635,  -635,   303,  -635,   565,   574,
     249,  -635,  -635,   253,  -600,  -635,   830,   337,  -635,  -635,
     281,  -635,  -635,   575,   573,   129,  -576,   556,   246,  -344,
     233,   268,  -635,  -635,  -635,  -635,  -635,   770,  -635,  -635,
    -635,  -635,  -635,  -635,   772,  -635,   -43,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,    31,  -635,  -635,  -635,   299,   240,
    -635,  -327,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -424,  -635,   308,  -635,   462,  -635,  -635,  -635,  -635,
    -635,    92,   101,  -573,  -390,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,   566,  -223,  -356,  -635,  -635,
     269,  -348,  -635,  -635,  -635,  -635,  -635,  -635,  -635,   892,
     897,    41,   526,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,   435,  -635,  -635,   276,   265,   256,   445,  -635,  -635,
     266,  -635,  -459,  -635,  -635,  -635,  -635,   172,  -299,  -635,
     474,   167,  -635,  -429,  -635,  -635,  -635,  -635,  -634,  -635,
    -635,  -635,  -635,   155,   282,  -635
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   583,   249,   109,   110,   111,   112,
     551,   552,   607,   113,   114,   115,   116,   117,   118,   119,
     241,   242,   417,   418,   120,   251,   252,   326,   327,   484,
     485,   647,   648,   649,   650,   121,   238,   239,   122,   617,
     618,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   345,   346,
     347,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   372,   373,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   382,
     166,   167,   168,   609,   448,   449,   745,   830,   831,   824,
     825,   832,   826,   610,   611,   169,   170,   612,   171,   172,
     173,   174,   175,   176,   177,   528,   401,   523,   691,   524,
     525,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   542,   564,   188,   189,   190,   191,   192,   193,   194,
     286,   501,   670,   502,   503,   504,   505,   506,   507,   508,
     671,   672,   305,   306,   307,   308,   309,   851,   852,   310,
     470,   474,   636,   471,   311,   312,   674,   687,   770,   675,
     676,   681,   677,   858,   786,   659
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       280,   281,   282,   284,   478,   527,   196,   198,   512,   513,
     514,   515,   526,   526,   411,   429,   201,   419,   585,   481,
     207,   500,   398,   608,   268,   269,   398,   430,   414,   414,
     787,   457,   702,   590,   435,     6,   750,   708,   574,   228,
     277,   633,   557,   673,   206,   233,   797,   743,   777,   778,
     526,   243,   412,   246,   412,   244,   254,    26,   445,    28,
     257,    30,    31,   445,    17,   224,   455,   841,   599,   600,
     398,   202,   601,   468,   234,   367,   349,   272,   259,   274,
     275,   276,   475,   728,   210,   599,   600,   260,   544,   601,
     428,    39,   790,   763,   599,   600,   643,   247,   601,   200,
     350,   415,   577,   602,   211,   320,   616,   212,    60,   225,
     321,   545,   765,   766,   704,   639,   701,   599,   600,   381,
     602,   601,    49,   767,   768,   446,   497,   213,   489,   602,
     613,   351,   498,   755,   645,   646,   769,   605,   603,   323,
     604,   520,   704,   456,   320,   410,   199,   385,   387,   842,
     406,   408,   602,   320,   248,   603,   245,   604,   320,   320,
      12,   469,   320,   537,   603,   413,   604,   444,   320,   436,
     744,   500,   500,    16,   605,   416,   854,   416,   640,   750,
     374,   735,   575,   376,   579,   608,   801,   603,   804,   604,
     608,   605,   807,   809,   703,   591,    35,   458,   459,   709,
     605,    57,   526,   462,    41,   383,   460,   526,   633,   278,
     203,   794,   447,   235,   694,   884,   860,   614,    57,    85,
     416,   204,   261,   605,   236,   705,   706,    57,   764,   320,
     606,    71,   472,   771,   416,   521,   773,   320,   416,   416,
     482,   483,   486,   483,   488,   499,   520,   749,    71,   885,
      57,    54,   378,   710,   711,    77,   751,    71,   386,   388,
     754,   407,   409,   398,   421,    12,    58,   379,   526,   432,
     441,   885,    77,   451,   538,   264,   384,   320,    16,   838,
      71,    77,   320,    64,    65,    41,   320,   320,   863,   320,
     320,   320,   320,   865,   855,   320,   320,    73,   349,   320,
     856,    35,   753,   208,    77,   320,   320,   320,   548,    41,
     358,   784,   559,   707,   783,   522,   785,   857,   473,   560,
     558,   209,   350,   546,   399,   791,   533,   534,   608,   359,
     567,   400,   822,   570,   605,   572,   352,   389,   599,   500,
     521,   481,   601,   729,   772,   402,   547,   774,   588,   800,
     805,   500,   500,   827,   833,   810,    54,   214,   526,   216,
     886,   229,   217,   526,   597,    65,     3,   353,   475,   221,
     605,    58,   532,     4,   205,   265,   535,   215,   622,   623,
     624,   625,   887,   627,   628,   405,   630,   354,    64,    65,
     434,   549,   550,    12,   450,   452,   218,   453,   539,   596,
     693,   476,    73,   741,   781,   803,    16,   798,   603,   652,
     604,   654,   868,   811,   834,   869,   465,     6,   806,   823,
     522,   845,   846,   847,   848,   466,   605,   222,   543,    35,
     808,   356,   255,   355,   862,   827,   223,    41,   548,   605,
     642,   833,   822,   357,   605,   595,    17,   563,   599,   565,
     375,   605,   601,   643,   477,   605,   377,   695,   864,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    39,   494,   495,   496,   799,   644,   605,
     712,   688,   689,   690,    54,   620,   599,   621,   720,   226,
     601,   645,   646,   227,   724,   258,   726,   727,   232,    58,
     828,   732,   655,   266,    49,   219,   220,    45,   497,   736,
     737,    47,    48,   237,   498,   240,    64,    65,   603,   250,
     604,   554,   555,   889,    70,   356,   267,     1,    50,   871,
      73,   526,   256,   883,     2,     3,   356,   357,   271,   891,
     758,   759,     4,     5,   273,   697,   760,     6,   357,   321,
       7,   599,     8,     9,   605,   601,   603,   279,   604,   320,
      10,    11,    12,    13,   285,   828,   714,   322,   829,    14,
     313,   483,   318,   780,    15,    16,    17,   328,   323,   262,
     263,   682,   683,   684,   685,   855,   893,   369,   370,   516,
     517,   856,   605,    32,    33,   509,   510,    34,    35,    36,
      37,    38,   319,    39,   324,    40,    41,    79,   857,   686,
     747,   329,   536,   765,   766,   536,   348,   536,    43,    44,
     360,   603,   361,   604,   767,   768,   518,   519,   362,    85,
     363,   529,   529,   874,    49,   631,   632,   371,   390,   391,
     392,   393,   395,   394,    51,   812,   364,   396,   813,   397,
     815,   403,   420,    54,   404,   422,   423,   605,   819,   424,
     425,   426,    55,   427,    56,    57,   431,   433,    58,   439,
     365,    60,   437,   438,    61,    62,   440,    63,   442,   443,
     461,   843,   844,   454,   463,    64,    65,    66,   467,    67,
      68,   520,   540,    70,   464,    71,   541,   491,    72,    73,
     553,   562,   330,   561,   568,   569,    75,   571,   573,   576,
     331,   580,   581,   332,    76,   333,   582,     1,   587,    77,
     589,   592,   584,   586,     2,     3,   334,   593,   598,   616,
     335,   619,     4,     5,   866,   336,   867,     6,   626,   634,
       7,   337,     8,     9,   629,   635,   638,   821,   641,   651,
      10,    11,    12,    13,   658,   653,   678,   680,   692,    14,
     880,   698,   882,   338,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,   699,   679,    32,    33,   700,   716,    34,    35,    36,
      37,    38,   715,    39,   722,    40,    41,   723,   339,   340,
     341,   342,   343,   344,   725,    42,   730,   717,    43,    44,
     895,    45,   718,   719,   896,   733,   734,   738,    46,    47,
      48,   740,   746,   742,    49,   748,   757,   761,   762,   775,
     643,   782,    50,   398,    51,   814,    52,   548,    53,   816,
     835,   817,   818,    54,   836,   837,   839,   849,   840,   850,
     873,   861,    55,   475,    56,    57,   876,   878,    58,   870,
      59,    60,   879,   890,    61,    62,   877,    63,   881,   894,
     316,   888,   314,   892,   315,    64,    65,    66,   479,    67,
      68,    69,   480,    70,   802,    71,   317,   556,    72,    73,
     325,   490,   731,    74,   578,   739,    75,   487,   756,   270,
     779,   776,   493,   492,    76,     1,   721,   511,   366,    77,
     615,    78,     2,     3,   368,    79,    80,    81,    82,    83,
       4,     5,   752,   875,    84,     6,   872,   230,     7,   530,
       8,     9,   231,   656,   566,   796,   793,    85,    10,    11,
      12,    13,   788,   795,   657,   853,   859,    14,   637,   789,
       0,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,     0,    43,    44,     0,    45,
       0,     0,     0,     0,     0,     0,    46,    47,    48,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    51,     0,    52,     0,    53,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,     0,    67,    68,    69,
       0,    70,     0,    71,     0,     1,    72,    73,     0,     0,
       0,    74,     2,     3,    75,     0,     0,     0,     0,     0,
       4,     5,    76,     0,     0,     6,     0,    77,     7,     0,
       8,     9,     0,    79,    80,    81,    82,    83,    10,    11,
      12,    13,    84,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    15,    16,    17,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,     0,    43,    44,     0,    45,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    51,     0,    52,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,     0,    67,    68,    69,
       0,    70,     0,    71,     0,     1,    72,    73,     0,     0,
       0,    74,     2,     3,    75,     0,     0,     0,     0,     0,
       4,     5,    76,     0,     0,     6,     0,    77,     7,     0,
       8,     9,     0,     0,    80,    81,    82,    83,    10,    11,
      12,    13,    84,   283,     0,     0,     0,    14,     0,     0,
       0,     0,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,     0,    43,    44,     0,    45,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    51,     0,    52,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,   195,     0,     0,
       0,     0,     0,    64,    65,    66,     0,    67,    68,    69,
       0,    70,     0,    71,     0,     1,    72,    73,     0,     0,
       0,    74,     2,     3,    75,     0,     0,     0,     0,     0,
       4,     5,    76,     0,     0,     6,     0,    77,     7,     0,
       8,     9,     0,     0,    80,    81,    82,    83,    10,    11,
      12,    13,    84,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,     0,    43,    44,     0,    45,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    51,     0,    52,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,   197,     0,     0,
       0,     0,     0,    64,    65,    66,     0,    67,    68,    69,
       0,    70,     0,    71,     0,     1,    72,    73,     0,     0,
       0,    74,     2,     3,    75,     0,     0,     0,     0,     0,
       4,     5,    76,     0,     0,     6,     0,    77,     7,     0,
       8,     9,     0,     0,    80,    81,    82,    83,    10,    11,
      12,    13,    84,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,     0,    43,    44,     0,    45,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    51,     0,    52,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,     0,     0,     0,
     253,     0,     0,    64,    65,    66,     0,    67,    68,    69,
       0,    70,     0,    71,     0,     1,    72,    73,     0,     0,
       0,    74,     2,     3,    75,     0,     0,     0,     0,     0,
       4,     5,    76,     0,     0,     6,     0,    77,     7,     0,
       8,     9,     0,     0,    80,    81,    82,    83,    10,    11,
      12,    13,    84,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,     0,    43,    44,     0,    45,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    51,     0,    52,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,     0,     0,     0,
     380,     0,     0,    64,    65,    66,     0,    67,    68,    69,
       0,    70,     0,    71,     0,     1,    72,    73,     0,     0,
       0,    74,     2,     3,    75,     0,     0,     0,     0,     0,
       4,     5,    76,     0,     0,     6,     0,    77,     7,     0,
       8,     9,     0,     0,    80,    81,    82,    83,    10,    11,
      12,    13,    84,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,     0,    43,    44,     0,    45,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    51,     0,    52,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,   531,     0,     0,
       0,     0,     0,    64,    65,    66,     0,    67,    68,    69,
       0,    70,     0,    71,     0,     1,    72,    73,     0,     0,
       0,    74,     2,     3,    75,     0,     0,     0,     0,     0,
       4,     5,    76,     0,     0,     6,     0,    77,     7,     0,
       8,     9,     0,     0,    80,    81,    82,    83,    10,    11,
      12,    13,    84,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,     0,    43,    44,     0,    45,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    51,     0,    52,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,   594,     0,     0,
       0,     0,     0,    64,    65,    66,     0,    67,    68,    69,
       0,    70,     0,    71,     0,     1,    72,    73,     0,     0,
       0,    74,     2,     3,    75,     0,     0,     0,     0,     0,
       4,     5,    76,     0,     0,     6,     0,    77,     7,     0,
       8,     9,     0,     0,    80,    81,    82,    83,    10,    11,
      12,    13,    84,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,     0,    43,    44,     0,    45,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    51,     0,    52,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,   696,     0,     0,
       0,     0,     0,    64,    65,    66,     0,    67,    68,    69,
       0,    70,     0,    71,     0,     1,    72,    73,     0,     0,
       0,    74,     2,     3,    75,     0,     0,     0,     0,     0,
       4,     5,    76,     0,     0,     6,     0,    77,     7,     0,
       8,     9,     0,     0,    80,    81,    82,    83,    10,    11,
      12,    13,    84,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,     0,    43,    44,     0,    45,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    51,     0,    52,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,   713,     0,     0,
       0,     0,     0,    64,    65,    66,     0,    67,    68,    69,
       0,    70,     0,    71,     0,     1,    72,    73,     0,     0,
       0,    74,     2,     3,    75,     0,     0,     0,     0,     0,
       4,     5,    76,     0,     0,     6,     0,    77,     7,     0,
       8,     9,     0,     0,    80,    81,    82,    83,    10,    11,
      12,    13,    84,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,     0,    43,    44,     0,    45,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    51,     0,    52,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,   820,     0,     0,
       0,     0,     0,    64,    65,    66,     0,    67,    68,    69,
       0,    70,     0,    71,     0,     1,    72,    73,     0,     0,
       0,    74,     2,     3,    75,     0,     0,     0,     0,     0,
       4,     5,    76,     0,     0,     6,     0,    77,     7,     0,
       8,     9,     0,     0,    80,    81,    82,    83,    10,    11,
      12,    13,    84,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,     0,    43,    44,     0,    45,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    51,     0,    52,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,     0,    67,    68,    69,
       0,    70,     0,    71,     0,     1,    72,    73,     0,     0,
       0,    74,     2,     3,    75,     0,     0,     0,     0,     0,
       4,     5,    76,     0,     0,     6,     0,    77,     7,     0,
       8,     9,     0,     0,    80,    81,    82,    83,    10,    11,
      12,    13,    84,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,    52,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     1,    63,     0,     0,     0,     0,
       0,     2,     3,    64,    65,    66,     0,    67,    68,     4,
       5,    70,     0,    71,     6,     0,    72,    73,     0,     8,
       9,     0,     0,     0,    75,     0,     0,    10,    11,    12,
      13,     0,    76,     0,     0,     0,    14,    77,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,    38,     0,
      39,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    43,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,    56,    57,     0,     0,    58,     0,     0,     0,     0,
       0,    61,    62,     1,    63,     0,     0,     0,     0,     0,
       2,     3,    64,    65,    66,     0,     0,     0,     4,     5,
      70,     0,    71,     6,     0,    72,    73,     0,     8,     9,
       0,     0,     0,    75,     0,     0,    10,    11,    12,    13,
       0,     0,     0,     0,     0,    14,    77,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,     0,    34,    35,    36,    37,    38,     0,    39,
       0,    40,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    43,    44,   660,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
      56,    57,   660,     0,    58,     0,     0,     0,     0,     0,
      61,    62,     0,    63,     0,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,     0,     0,     0,     0,     0,
       0,    71,     0,     0,    72,    73,   661,     0,     0,   662,
     287,   288,    75,   289,   290,   663,   664,   665,     0,     0,
       0,     0,     0,   666,   291,    77,   292,     0,     0,     0,
       0,     0,   667,     0,     0,     0,     0,   293,   668,   669,
       0,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   661,     0,     0,   662,   287,   288,     0,   289,
     290,   663,   664,   665,     0,     0,     0,     0,     0,     0,
     291,     0,   292,     0,     0,     0,     0,     0,   667,     0,
       0,     0,     0,   293,   792,   669,     0,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   287,   288,
       0,   289,   290,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,     0,   292,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   293,     0,     0,     0,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        80,    81,    82,    83,   303,   361,     1,     2,   352,   353,
     354,   355,   360,   361,   237,   250,    11,   240,   424,   319,
      15,   348,    33,   447,    67,    68,    33,   250,    35,    35,
     664,    33,   549,   101,     8,    24,   609,   554,   108,    34,
      28,   470,   398,   502,    13,    40,   680,    32,   648,   649,
     398,    46,    48,    25,    48,    25,    51,    62,    20,    64,
      55,    66,    67,    20,    53,   138,    88,    76,     9,    10,
      33,    20,    13,    93,    20,   115,   123,    72,    15,    74,
      75,    76,    35,   108,   153,     9,    10,    24,   109,    13,
     101,    80,   668,    24,     9,    10,    47,    69,    13,   115,
     147,   108,   108,    44,   173,    48,    41,   153,   148,   182,
     140,   132,   219,   220,    48,    68,    94,     9,    10,   199,
      44,    13,   111,   230,   231,    87,   115,   173,   158,    44,
      87,   178,   121,    68,    85,    86,   243,   115,    79,   169,
      81,    20,    48,   165,    48,   108,   121,    48,    48,   158,
      48,    48,    44,    48,   126,    79,   126,    81,    48,    48,
      39,   181,    48,    48,    79,   161,    81,   161,    48,   143,
     155,   498,   499,    52,   115,   245,   776,   245,   477,   752,
     149,   587,   417,   152,   419,   609,   703,    79,   705,    81,
     614,   115,   709,   710,   550,   430,    75,   199,   200,   555,
     115,   142,   550,   283,    83,   200,   208,   555,   637,   197,
     159,   670,   174,   159,   157,   849,   792,   174,   142,   224,
     245,   170,   159,   115,   170,   159,   160,   142,   159,    48,
     171,   172,    35,    48,   245,   114,    48,    48,   245,   245,
     320,   321,   322,   323,   324,   234,    20,   171,   172,    48,
     142,   130,   156,   159,   160,   196,   171,   172,   159,   159,
     616,   159,   159,    33,   159,    39,   145,   156,   616,   159,
     265,    48,   196,   159,   159,    15,   156,    48,    52,   171,
     172,   196,    48,   162,   163,    83,    48,    48,   805,    48,
      48,    48,    48,   810,   241,    48,    48,   176,   123,    48,
     247,    75,    76,   159,   196,    48,    48,    48,    76,    83,
      93,   241,    94,    94,   658,   194,   246,   264,   121,   101,
     400,    25,   147,   109,    94,   669,   369,   370,   752,   112,
     410,   101,     3,   413,   115,   415,    73,   156,     9,   666,
     114,   641,    13,   578,   159,   156,   132,   159,   428,    94,
     706,   678,   679,   743,   744,   711,   130,   133,   706,    25,
     159,   159,   126,   711,   444,   163,    12,   104,    35,    20,
     115,   145,   367,    19,    20,   115,   371,   153,   458,   459,
     460,   461,   159,   463,   464,   156,   466,   124,   162,   163,
     156,   159,   160,    39,   156,   156,   126,   156,   156,   156,
     156,    68,   176,   156,   156,    94,    52,   156,    79,   489,
      81,   491,   818,   156,   156,   156,   201,    24,    94,    90,
     194,   765,   766,   767,   768,   210,   115,    15,   387,    75,
      94,   181,    15,   170,    94,   825,    20,    83,    76,   115,
      34,   831,     3,   193,   115,   440,    53,   406,     9,   408,
     151,   115,    13,    47,   121,   115,   157,   537,    94,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    80,   345,   346,   347,   700,    72,   115,
     560,   134,   135,   136,   130,   207,     9,   209,   568,    20,
      13,    85,    86,    26,   574,    17,   576,   577,    26,   145,
      23,   581,   497,    20,   111,    85,    86,    98,   115,   589,
     590,   106,   107,    26,   121,    26,   162,   163,    79,    26,
      81,   159,   160,   879,   170,   181,    20,     4,   119,    90,
     176,   879,   159,   178,    11,    12,   181,   193,    20,   883,
     620,   621,    19,    20,   159,   540,   626,    24,   193,   140,
      27,     9,    29,    30,   115,    13,    79,    24,    81,    48,
      37,    38,    39,    40,    26,    23,   561,   158,    91,    46,
       0,   651,   165,   653,    51,    52,    53,   137,   169,    20,
      21,   214,   215,   216,   217,   241,   885,   166,   167,   356,
     357,   247,   115,    70,    71,   349,   350,    74,    75,    76,
      77,    78,   165,    80,   195,    82,    83,   202,   264,   242,
     605,    31,   372,   219,   220,   375,   233,   377,    95,    96,
     110,    79,   179,    81,   230,   231,   358,   359,    42,   224,
      43,   362,   363,    91,   111,   468,   469,   116,    48,    48,
      25,    25,    89,   121,   121,   725,   123,    24,   728,   121,
     730,   159,    48,   130,   159,    35,    15,   115,   738,    35,
     126,    15,   139,    25,   141,   142,    48,    89,   145,    18,
     147,   148,   159,   159,   151,   152,   115,   154,   159,   159,
      33,   761,   762,   197,   213,   162,   163,   164,    24,   166,
     167,    20,   115,   170,   101,   172,    20,   158,   175,   176,
      25,    20,    89,   115,   108,    76,   183,    76,    76,   108,
      97,    76,   177,   100,   191,   102,    25,     4,    35,   196,
     101,    76,    89,    89,    11,    12,   113,    25,    89,    41,
     117,    24,    19,    20,   814,   122,   816,    24,   213,    24,
      27,   128,    29,    30,    26,    24,    24,   742,   165,    48,
      37,    38,    39,    40,   252,   158,   232,   240,   103,    46,
     840,   159,   842,   150,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,   159,   239,    70,    71,    26,   159,    74,    75,    76,
      77,    78,   103,    80,    26,    82,    83,    26,   185,   186,
     187,   188,   189,   190,   108,    92,   108,   159,    95,    96,
     890,    98,   159,   159,   894,    48,    25,   101,   105,   106,
     107,   165,     7,   115,   111,    20,   165,   101,   158,    25,
      47,   159,   119,    33,   121,   108,   123,    76,   125,    84,
     174,    25,    35,   130,    20,    20,    26,    24,   158,   237,
     155,   248,   139,    35,   141,   142,   174,    20,   145,    32,
     147,   148,    33,   158,   151,   152,   174,   154,    26,   158,
      90,   174,    87,   237,    87,   162,   163,   164,   318,   166,
     167,   168,   318,   170,   704,   172,    91,   397,   175,   176,
     117,   326,   580,   180,   419,   592,   183,   323,   617,    69,
     651,   648,   329,   328,   191,     4,   569,   351,   138,   196,
     448,   198,    11,    12,   142,   202,   203,   204,   205,   206,
      19,    20,   614,   831,   211,    24,   825,    35,    27,   363,
      29,    30,    35,   498,   408,   679,   670,   224,    37,    38,
      39,    40,   666,   678,   499,   773,   791,    46,   474,   667,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,   123,    -1,   125,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,   141,   142,    -1,    -1,   145,    -1,   147,   148,
      -1,    -1,   151,   152,    -1,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,    -1,   166,   167,   168,
      -1,   170,    -1,   172,    -1,     4,   175,   176,    -1,    -1,
      -1,   180,    11,    12,   183,    -1,    -1,    -1,    -1,    -1,
      19,    20,   191,    -1,    -1,    24,    -1,   196,    27,    -1,
      29,    30,    -1,   202,   203,   204,   205,   206,    37,    38,
      39,    40,   211,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,   224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,   141,   142,    -1,    -1,   145,    -1,   147,   148,
      -1,    -1,   151,   152,    -1,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,    -1,   166,   167,   168,
      -1,   170,    -1,   172,    -1,     4,   175,   176,    -1,    -1,
      -1,   180,    11,    12,   183,    -1,    -1,    -1,    -1,    -1,
      19,    20,   191,    -1,    -1,    24,    -1,   196,    27,    -1,
      29,    30,    -1,    -1,   203,   204,   205,   206,    37,    38,
      39,    40,   211,   212,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,   141,   142,    -1,    -1,   145,    -1,   147,   148,
      -1,    -1,   151,   152,    -1,   154,    -1,   156,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,    -1,   166,   167,   168,
      -1,   170,    -1,   172,    -1,     4,   175,   176,    -1,    -1,
      -1,   180,    11,    12,   183,    -1,    -1,    -1,    -1,    -1,
      19,    20,   191,    -1,    -1,    24,    -1,   196,    27,    -1,
      29,    30,    -1,    -1,   203,   204,   205,   206,    37,    38,
      39,    40,   211,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,   141,   142,    -1,    -1,   145,    -1,   147,   148,
      -1,    -1,   151,   152,    -1,   154,    -1,   156,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,    -1,   166,   167,   168,
      -1,   170,    -1,   172,    -1,     4,   175,   176,    -1,    -1,
      -1,   180,    11,    12,   183,    -1,    -1,    -1,    -1,    -1,
      19,    20,   191,    -1,    -1,    24,    -1,   196,    27,    -1,
      29,    30,    -1,    -1,   203,   204,   205,   206,    37,    38,
      39,    40,   211,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,   141,   142,    -1,    -1,   145,    -1,   147,   148,
      -1,    -1,   151,   152,    -1,   154,    -1,    -1,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,    -1,   166,   167,   168,
      -1,   170,    -1,   172,    -1,     4,   175,   176,    -1,    -1,
      -1,   180,    11,    12,   183,    -1,    -1,    -1,    -1,    -1,
      19,    20,   191,    -1,    -1,    24,    -1,   196,    27,    -1,
      29,    30,    -1,    -1,   203,   204,   205,   206,    37,    38,
      39,    40,   211,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,   141,   142,    -1,    -1,   145,    -1,   147,   148,
      -1,    -1,   151,   152,    -1,   154,    -1,    -1,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,    -1,   166,   167,   168,
      -1,   170,    -1,   172,    -1,     4,   175,   176,    -1,    -1,
      -1,   180,    11,    12,   183,    -1,    -1,    -1,    -1,    -1,
      19,    20,   191,    -1,    -1,    24,    -1,   196,    27,    -1,
      29,    30,    -1,    -1,   203,   204,   205,   206,    37,    38,
      39,    40,   211,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,   141,   142,    -1,    -1,   145,    -1,   147,   148,
      -1,    -1,   151,   152,    -1,   154,    -1,   156,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,    -1,   166,   167,   168,
      -1,   170,    -1,   172,    -1,     4,   175,   176,    -1,    -1,
      -1,   180,    11,    12,   183,    -1,    -1,    -1,    -1,    -1,
      19,    20,   191,    -1,    -1,    24,    -1,   196,    27,    -1,
      29,    30,    -1,    -1,   203,   204,   205,   206,    37,    38,
      39,    40,   211,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,   141,   142,    -1,    -1,   145,    -1,   147,   148,
      -1,    -1,   151,   152,    -1,   154,    -1,   156,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,    -1,   166,   167,   168,
      -1,   170,    -1,   172,    -1,     4,   175,   176,    -1,    -1,
      -1,   180,    11,    12,   183,    -1,    -1,    -1,    -1,    -1,
      19,    20,   191,    -1,    -1,    24,    -1,   196,    27,    -1,
      29,    30,    -1,    -1,   203,   204,   205,   206,    37,    38,
      39,    40,   211,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,   141,   142,    -1,    -1,   145,    -1,   147,   148,
      -1,    -1,   151,   152,    -1,   154,    -1,   156,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,    -1,   166,   167,   168,
      -1,   170,    -1,   172,    -1,     4,   175,   176,    -1,    -1,
      -1,   180,    11,    12,   183,    -1,    -1,    -1,    -1,    -1,
      19,    20,   191,    -1,    -1,    24,    -1,   196,    27,    -1,
      29,    30,    -1,    -1,   203,   204,   205,   206,    37,    38,
      39,    40,   211,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,   141,   142,    -1,    -1,   145,    -1,   147,   148,
      -1,    -1,   151,   152,    -1,   154,    -1,   156,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,    -1,   166,   167,   168,
      -1,   170,    -1,   172,    -1,     4,   175,   176,    -1,    -1,
      -1,   180,    11,    12,   183,    -1,    -1,    -1,    -1,    -1,
      19,    20,   191,    -1,    -1,    24,    -1,   196,    27,    -1,
      29,    30,    -1,    -1,   203,   204,   205,   206,    37,    38,
      39,    40,   211,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,   141,   142,    -1,    -1,   145,    -1,   147,   148,
      -1,    -1,   151,   152,    -1,   154,    -1,   156,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,    -1,   166,   167,   168,
      -1,   170,    -1,   172,    -1,     4,   175,   176,    -1,    -1,
      -1,   180,    11,    12,   183,    -1,    -1,    -1,    -1,    -1,
      19,    20,   191,    -1,    -1,    24,    -1,   196,    27,    -1,
      29,    30,    -1,    -1,   203,   204,   205,   206,    37,    38,
      39,    40,   211,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,   141,   142,    -1,    -1,   145,    -1,   147,   148,
      -1,    -1,   151,   152,    -1,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,    -1,   166,   167,   168,
      -1,   170,    -1,   172,    -1,     4,   175,   176,    -1,    -1,
      -1,   180,    11,    12,   183,    -1,    -1,    -1,    -1,    -1,
      19,    20,   191,    -1,    -1,    24,    -1,   196,    27,    -1,
      29,    30,    -1,    -1,   203,   204,   205,   206,    37,    38,
      39,    40,   211,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,   141,   142,    -1,    -1,   145,    -1,   147,   148,
      -1,    -1,   151,   152,     4,   154,    -1,    -1,    -1,    -1,
      -1,    11,    12,   162,   163,   164,    -1,   166,   167,    19,
      20,   170,    -1,   172,    24,    -1,   175,   176,    -1,    29,
      30,    -1,    -1,    -1,   183,    -1,    -1,    37,    38,    39,
      40,    -1,   191,    -1,    -1,    -1,    46,   196,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    -1,
      80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,   141,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,     4,   154,    -1,    -1,    -1,    -1,    -1,
      11,    12,   162,   163,   164,    -1,    -1,    -1,    19,    20,
     170,    -1,   172,    24,    -1,   175,   176,    -1,    29,    30,
      -1,    -1,    -1,   183,    -1,    -1,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    46,   196,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    -1,    -1,    74,    75,    76,    77,    78,    -1,    80,
      -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
     141,   142,   138,    -1,   145,    -1,    -1,    -1,    -1,    -1,
     151,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,    -1,    -1,   175,   176,   218,    -1,    -1,   221,
     222,   223,   183,   225,   226,   227,   228,   229,    -1,    -1,
      -1,    -1,    -1,   235,   236,   196,   238,    -1,    -1,    -1,
      -1,    -1,   244,    -1,    -1,    -1,    -1,   249,   250,   251,
      -1,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   218,    -1,    -1,   221,   222,   223,    -1,   225,
     226,   227,   228,   229,    -1,    -1,    -1,    -1,    -1,    -1,
     236,    -1,   238,    -1,    -1,    -1,    -1,    -1,   244,    -1,
      -1,    -1,    -1,   249,   250,   251,    -1,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   222,   223,
      -1,   225,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,     4,    11,    12,    19,    20,    24,    27,    29,    30,
      37,    38,    39,    40,    46,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    70,    71,    74,    75,    76,    77,    78,    80,
      82,    83,    92,    95,    96,    98,   105,   106,   107,   111,
     119,   121,   123,   125,   130,   139,   141,   142,   145,   147,
     148,   151,   152,   154,   162,   163,   164,   166,   167,   168,
     170,   172,   175,   176,   180,   183,   191,   196,   198,   202,
     203,   204,   205,   206,   211,   224,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   301,
     302,   303,   304,   308,   309,   310,   311,   312,   313,   314,
     319,   330,   333,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   385,   386,   387,   400,
     401,   403,   404,   405,   406,   407,   408,   409,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   428,   429,
     430,   431,   432,   433,   434,   156,   309,   156,   309,   121,
     115,   309,    20,   159,   170,    20,   369,   309,   159,    25,
     153,   173,   153,   173,   133,   153,    25,   126,   126,    85,
      86,    20,    15,    20,   138,   182,    20,    26,   309,   159,
     424,   425,    26,   309,    20,   159,   170,    26,   331,   332,
      26,   315,   316,   309,    25,   126,    25,    69,   126,   300,
      26,   320,   321,   159,   309,    15,   159,   309,    17,    15,
      24,   159,    20,    21,    15,   115,    20,    20,   361,   361,
     331,    20,   309,   159,   309,   309,   309,    28,   197,    24,
     310,   310,   310,   212,   310,    26,   435,   222,   223,   225,
     226,   236,   238,   249,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   447,   448,   449,   450,   451,
     454,   459,   460,     0,   278,   279,   281,   308,   165,   165,
      48,   140,   158,   169,   195,   313,   322,   323,   137,    31,
      89,    97,   100,   102,   113,   117,   122,   128,   150,   185,
     186,   187,   188,   189,   190,   353,   354,   355,   233,   123,
     147,   178,    73,   104,   124,   170,   181,   193,    93,   112,
     110,   179,    42,    43,   123,   147,   352,   115,   359,   166,
     167,   116,   373,   374,   369,   373,   369,   373,   156,   156,
     159,   310,   384,   309,   156,    48,   159,    48,   159,   156,
      48,    48,    25,    25,   121,    89,    24,   121,    33,    94,
     101,   411,   156,   159,   159,   156,    48,   159,    48,   159,
     108,   411,    48,   161,    35,   108,   245,   317,   318,   411,
      48,   159,    35,    15,    35,   126,    15,    25,   101,   318,
     411,    48,   159,    89,   156,     8,   143,   159,   159,    18,
     115,   309,   159,   159,   161,    20,    87,   174,   389,   390,
     156,   159,   156,   156,   197,    88,   165,    33,   199,   200,
     208,    33,   310,   213,   101,   201,   210,    24,    93,   181,
     455,   458,    35,   121,   456,    35,    68,   121,   453,   283,
     284,   285,   310,   310,   324,   325,   310,   324,   310,   158,
     323,   158,   338,   339,   340,   340,   340,   115,   121,   234,
     376,   436,   438,   439,   440,   441,   442,   443,   444,   343,
     343,   342,   344,   344,   344,   344,   345,   345,   346,   346,
      20,   114,   194,   412,   414,   415,   416,   412,   410,   415,
     410,   156,   309,   361,   361,   309,   374,    48,   159,   156,
     115,    20,   426,   426,   109,   132,   109,   132,    76,   159,
     160,   305,   306,    25,   159,   160,   305,   412,   310,    94,
     101,   115,    20,   426,   427,   426,   427,   310,   108,    76,
     310,    76,   310,    76,   108,   318,   108,   108,   317,   318,
      76,   177,    25,   299,    89,   299,    89,    35,   310,   101,
     101,   318,    76,    25,   156,   309,   156,   310,    89,     9,
      10,    13,    44,    79,    81,   115,   171,   307,   386,   388,
     398,   399,   402,    87,   174,   390,    41,   334,   335,    24,
     207,   209,   310,   310,   310,   310,   213,   310,   310,    26,
     310,   456,   456,   458,    24,    24,   457,   455,    24,    68,
     453,   165,    34,    47,    72,    85,    86,   326,   327,   328,
     329,    48,   310,   158,   310,   309,   436,   442,   252,   470,
     138,   218,   221,   227,   228,   229,   235,   244,   250,   251,
     437,   445,   446,   447,   461,   464,   465,   467,   232,   239,
     240,   466,   214,   215,   216,   217,   242,   462,   134,   135,
     136,   413,   103,   156,   157,   310,   156,   309,   159,   159,
      26,    94,   307,   412,    48,   159,   160,    94,   307,   412,
     159,   160,   310,   156,   309,   103,   159,   159,   159,   159,
     310,   332,    26,    26,   310,   108,   310,   310,   108,   318,
     108,   316,   310,    48,    25,   299,   310,   310,   101,   321,
     165,   156,   115,    32,   155,   391,     7,   309,    20,   171,
     398,   171,   388,    76,   412,    68,   335,   165,   310,   310,
     310,   101,   158,    24,   159,   219,   220,   230,   231,   243,
     463,    48,   159,    48,   159,    25,   328,   329,   329,   325,
     310,   156,   159,   344,   241,   246,   469,   463,   439,   469,
     341,   344,   250,   445,   447,   440,   441,   463,   156,   411,
      94,   307,   306,    94,   307,   412,    94,   307,    94,   307,
     412,   156,   310,   310,   108,   310,    84,    25,    35,   310,
     156,   309,     3,    90,   394,   395,   397,   399,    23,    91,
     392,   393,   396,   399,   156,   174,    20,    20,   171,    26,
     158,    76,   158,   310,   310,   344,   344,   344,   344,    24,
     237,   452,   453,   452,   329,   241,   247,   264,   468,   468,
     341,   248,    94,   307,    94,   307,   310,   310,   299,   156,
      32,    90,   397,   155,    91,   396,   174,   174,    20,    33,
     310,    26,   310,   178,   463,    48,   159,   159,   174,   412,
     158,   344,   237,   453,   158,   310,   310
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
     525,   526,   527,   528,   529
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   275,   276,   276,   276,   276,   277,   277,   278,   278,
     279,   280,   281,   281,   281,   282,   282,   283,   283,   284,
     284,   284,   284,   285,   285,   285,   285,   286,   286,   286,
     286,   286,   286,   286,   286,   287,   287,   288,   289,   289,
     290,   290,   291,   292,   293,   293,   294,   294,   295,   295,
     295,   295,   296,   297,   298,   298,   298,   298,   299,   299,
     300,   300,   301,   301,   301,   301,   302,   302,   302,   302,
     303,   303,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   305,   305,
     306,   306,   307,   308,   309,   309,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   311,   311,   311,   311,
     312,   312,   313,   313,   314,   315,   315,   316,   316,   316,
     316,   316,   316,   316,   316,   317,   318,   319,   320,   320,
     321,   321,   321,   321,   322,   323,   323,   324,   324,   325,
     325,   326,   326,   326,   326,   326,   326,   326,   327,   327,
     328,   328,   329,   330,   330,   331,   331,   332,   332,   333,
     333,   334,   334,   335,   335,   336,   337,   337,   338,   338,
     339,   339,   339,   339,   340,   340,   340,   341,   341,   342,
     342,   342,   343,   343,   343,   343,   343,   344,   344,   344,
     345,   345,   345,   346,   346,   347,   347,   348,   348,   349,
     349,   350,   350,   351,   351,   351,   351,   352,   352,   352,
     353,   353,   353,   353,   353,   353,   354,   354,   354,   354,
     354,   354,   355,   355,   355,   356,   356,   357,   357,   358,
     358,   359,   359,   360,   360,   360,   360,   361,   361,   361,
     362,   362,   363,   363,   363,   363,   364,   364,   365,   365,
     365,   365,   365,   365,   365,   366,   366,   367,   367,   368,
     368,   368,   368,   368,   369,   369,   370,   370,   371,   371,
     371,   372,   372,   373,   373,   374,   375,   375,   375,   375,
     375,   375,   375,   375,   376,   376,   377,   377,   377,   378,
     379,   379,   380,   381,   382,   383,   383,   384,   384,   385,
     385,   386,   386,   386,   387,   387,   387,   387,   387,   387,
     388,   388,   389,   389,   390,   391,   391,   392,   392,   393,
     393,   393,   393,   394,   394,   395,   395,   395,   395,   396,
     396,   397,   397,   398,   398,   398,   398,   399,   399,   399,
     399,   399,   400,   400,   401,   401,   402,   403,   403,   403,
     403,   403,   403,   404,   405,   405,   405,   405,   406,   406,
     406,   406,   407,   408,   409,   409,   409,   409,   410,   410,
     411,   412,   412,   412,   413,   413,   413,   414,   414,   414,
     415,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     417,   418,   418,   418,   419,   420,   421,   421,   421,   422,
     422,   422,   422,   422,   423,   424,   424,   424,   424,   424,
     424,   424,   425,   426,   427,   428,   429,   430,   430,   430,
     430,   430,   431,   432,   432,   433,   434,   435,   435,   436,
     436,   436,   436,   437,   437,   437,   437,   438,   438,   439,
     439,   440,   440,   441,   441,   442,   442,   442,   443,   443,
     444,   444,   445,   445,   445,   445,   445,   446,   447,   447,
     447,   447,   447,   447,   447,   448,   448,   448,   448,   449,
     449,   449,   449,   450,   450,   451,   451,   451,   451,   451,
     451,   451,   452,   452,   453,   453,   453,   453,   454,   454,
     454,   454,   454,   455,   455,   456,   456,   457,   457,   458,
     458,   459,   460,   460,   461,   461,   461,   462,   462,   462,
     462,   462,   463,   463,   463,   463,   464,   465,   466,   467,
     467,   468,   468,   468,   469,   469,   470
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
       2,     2,     5,     5,     6,     6,     6,     6,     7,     7,
       5,     5,     6,     6,     6,     6,     7,     7,     1,     3,
       2,     3,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     4,     5,
       1,     2,     1,     1,     2,     1,     4,     3,     4,     4,
       5,     4,     5,     5,     6,     3,     3,     2,     1,     4,
       3,     4,     4,     5,     2,     2,     2,     1,     3,     1,
       2,     1,     1,     1,     2,     2,     2,     3,     1,     1,
       1,     1,     2,     4,     4,     1,     4,     3,     4,     7,
       9,     1,     2,     4,     7,     7,     1,     3,     1,     3,
       1,     3,     3,     3,     1,     3,     4,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     2,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     4,     1,
       2,     3,     2,     1,     2,     2,     1,     1,     3,     3,
       1,     1,     1,     2,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     1,     3,     3,     3,     4,     1,     3,     1,
       1,     1,     1,     1,     3,     4,     6,     7,     7,     8,
       1,     2,     1,     2,     3,     3,     3,     0,     1,     1,
       1,     2,     2,     0,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     5,     6,     2,     3,
       5,     6,     3,     3,     4,     5,     6,     7,     1,     2,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     3,     2,     2,     2,     3,     3,     2,
       3,     5,     3,     5,     3,     2,     3,     5,     5,     3,
       5,     5,     3,     1,     2,     1,     1,     4,     5,     5,
       4,     4,     2,     4,     5,     4,     6,     3,     5,     1,
       2,     3,     4,     1,     1,     2,     2,     1,     3,     1,
       3,     1,     3,     1,     2,     1,     2,     3,     1,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     4,     6,     4,
       6,     1,     1,     3,     2,     4,     4,     6,     2,     3,
       1,     2,     1,     1,     2,     2,     3,     1,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     4,     3,     3,     3,     2,
       2,     1,     1,     1,     1,     1,     2
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const xquery_parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined",
  "\"'apos attribute content'\"", "\"'<attribute QName {>'\"",
  "\"'<at URI>'\"", "\"'char literal'\"", "\"'char literal]]>'\"",
  "\"'char literal and pi end'\"", "\"'#charref;'\"",
  "\"'element content'\"", "\"'<QName {>'\"", "\"'pref:*'\"",
  "\"'&entity;'\"", "\"'comment literal'\"", "\"'NCName'\"",
  "\"'pi <NCName {>'\"", "\"'pi target'\"", "\"'pragma literal and end'\"",
  "\"'*:QName'\"", "\"'QName'\"", "\"'QName #)'\"", "\"'<QName (>'\"",
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
  "\"'processing instruction'\"", "\"'\\\"'\"", "\"'}'\"", "\"']'\"",
  "\"'return'\"", "\"')'\"", "\"'<) as>'\"", "\"'satisfies'\"",
  "\"'<schema attribute ('\"", "\"'<schema element (>'\"", "\"'self::'\"",
  "\"';'\"", "\"'/'\"", "\"'//'\"", "\"'<some $>'\"",
  "\"'<stable order by>'\"", "\"'*'\"", "\"'start tag end >'\"",
  "\"'start tag <'\"", "\"'strip'\"", "\"'</'\"", "\"'<text {>'\"",
  "\"'<text (>'\"", "\"'then'\"", "\"'to'\"", "\"'<treat as>'\"",
  "\"'<typeswitch (>'\"", "\"'union'\"", "\"'unordered'\"",
  "\"'<unordered (>'\"", "\"'unrecognized'\"", "\"'eq'\"", "\"'ge'\"",
  "\"'gt'\"", "\"'le'\"", "\"'lt'\"", "\"'ne'\"", "\"'<validate {>'\"",
  "\"'VALUECOMP'\"", "\"'|'\"", "\"'void()'\"", "\"'where'\"",
  "\"'<!--'\"", "\"'-->'\"", "\"'<XQuery Version>'\"", "\"'after'\"",
  "\"'before'\"", "\"'<, $>'\"", "\"'<declare revalidation mode>'\"",
  "\"'<do delete>'\"", "\"'<do insert>'\"", "\"'<do rename>'\"",
  "\"'<do replace>'\"", "\"'<first into>'\"", "\"'into'\"",
  "\"'<lastinto>'\"", "\"'modify'\"", "\"'<transform copy $>'\"",
  "\"'<value of>'\"", "\"'with'\"", "\"'all'\"", "\"'<all words>'\"",
  "\"'any'\"", "\"'<any words>'\"", "\"'<at end>'\"", "\"'<at least>'\"",
  "\"'<at most>'\"", "\"'<at start>'\"", "\"'<case insensitive>'\"",
  "\"'<casesensitive>'\"", "\"'<declare ftoption>'\"",
  "\"'<diacritics insensitive>'\"", "\"'<diacritics sensitive>'\"",
  "\"'different'\"", "\"'distance'\"", "\"'<entire content>'\"",
  "\"'exactly'\"", "\"'from'\"", "\"'&&'\"", "\"'ftcontains'\"",
  "\"'ftnot'\"", "\"'||'\"", "\"'language'\"", "\"'levels'\"",
  "\"'lowercase'\"", "\"'<not in>'\"", "\"'occurs'\"", "\"'paragraph'\"",
  "\"'phrase'\"", "\"'relationship'\"", "\"'same'\"", "\"'score'\"",
  "\"'sentence'\"", "\"'sentences'\"", "\"'times'\"", "\"'uppercase'\"",
  "\"'weight'\"", "\"'window'\"", "\"'<without content>'\"",
  "\"'<without diacritics>'\"", "\"'<without stemming>'\"",
  "\"'<without stop words>'\"", "\"'<without thesaurus>'\"",
  "\"'<without wildcards>'\"", "\"'<with default stop words>'\"",
  "\"'<with diacritics>'\"", "\"'<with stemming>'\"",
  "\"'<with stop words>'\"", "\"'<with thesaurus>'\"",
  "\"'<with wildcards>'\"", "\"'words'\"", "FTCONTAINS_REDUCE",
  "RANGE_REDUCE", "ADDITIVE_REDUCE", "MULTIPLICATIVE_REDUCE",
  "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE",
  "UNARY_PREC", "SEQUENCE_TYPE_REDUCE", "STEP_REDUCE", "$accept", "Module",
  "VersionDecl", "MainModule", "LibraryModule", "ModuleDecl", "Prolog",
  "SIND_DeclList", "VFO_DeclList", "SIND_Decl", "VFO_Decl", "Setter",
  "Import", "NamespaceDecl", "BoundarySpaceDecl", "DefaultNamespaceDecl",
  "OptionDecl", "FTOptionDecl", "OrderingModeDecl", "EmptyOrderDecl",
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
  "ElementTest", "SchemaElementTest", "TypeName", "TypeName_WITH_HOOK",
  "StringLiteral", "RevalidationDecl", "InsertExpr", "DeleteExpr",
  "ReplaceExpr", "RenameExpr", "TransformExpr", "VarNameList",
  "FTSelection", "FTMatchOptionProximityList", "FTOr", "FTAnd",
  "FTMildnot", "FTUnaryNot", "FTWordsSelection", "FTWords", "FTWordsValue",
  "FTProximity", "FTOrderedIndicator", "FTMatchOption", "FTCaseOption",
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
       276,     0,    -1,   278,    -1,   277,   278,    -1,   279,    -1,
     277,   279,    -1,   198,    24,   165,    -1,   198,    24,    88,
      24,   165,    -1,   281,   308,    -1,   308,    -1,   280,   281,
      -1,   125,    15,    89,    25,   165,    -1,   282,   165,    -1,
     283,   165,    -1,   282,   165,   283,   165,    -1,   284,    -1,
     282,   165,   284,    -1,   285,    -1,   283,   165,   285,    -1,
     286,    -1,   287,    -1,   288,    -1,   290,    -1,   302,    -1,
     304,    -1,   291,    -1,   292,    -1,   289,    -1,   296,    -1,
     297,    -1,   303,    -1,   293,    -1,   294,    -1,   295,    -1,
     429,    -1,   298,    -1,   301,    -1,    63,    15,    89,    25,
      -1,    55,   153,    -1,    55,   173,    -1,    59,   126,    25,
      -1,    60,   126,    25,    -1,    64,    20,    24,    -1,   224,
     447,    -1,    65,   138,    -1,    65,   182,    -1,    61,    85,
      -1,    61,    86,    -1,    57,   153,    48,   109,    -1,    57,
     153,    48,   132,    -1,    57,   133,    48,   109,    -1,    57,
     133,    48,   132,    -1,    58,    25,    -1,    54,    25,    -1,
     107,    25,    -1,   107,   300,    25,    -1,   107,    25,    35,
     299,    -1,   107,   300,    25,    35,   299,    -1,    25,    -1,
     299,    48,    25,    -1,   126,    15,    89,    -1,    69,   126,
      -1,   106,    25,    -1,   106,   126,    15,    89,    25,    -1,
     106,    25,    35,   299,    -1,   106,   126,    15,    89,    25,
      35,   299,    -1,    67,    26,   101,   310,    -1,    67,    26,
      94,    -1,    67,    26,   411,   101,   310,    -1,    67,    26,
     411,    94,    -1,    56,   153,    -1,    56,   173,    -1,    62,
      20,   121,   159,    94,    -1,    62,    20,   121,   159,   307,
      -1,    62,    20,   121,   305,   159,    94,    -1,    62,    20,
     121,   305,   159,   307,    -1,    62,    20,   121,   160,   412,
      94,    -1,    62,    20,   121,   160,   412,   307,    -1,    62,
      20,   121,   305,   160,   412,    94,    -1,    62,    20,   121,
     305,   160,   412,   307,    -1,    66,    20,   121,   159,    94,
      -1,    66,    20,   121,   159,   307,    -1,    66,    20,   121,
     305,   159,    94,    -1,    66,    20,   121,   305,   159,   307,
      -1,    66,    20,   121,   160,   412,    94,    -1,    66,    20,
     121,   160,   412,   307,    -1,    66,    20,   121,   305,   160,
     412,    94,    -1,    66,    20,   121,   305,   160,   412,   307,
      -1,   306,    -1,   305,    48,   306,    -1,    76,    26,    -1,
      76,    26,   411,    -1,   115,   309,   156,    -1,   309,    -1,
     310,    -1,   309,    48,   310,    -1,   311,    -1,   330,    -1,
     333,    -1,   336,    -1,   337,    -1,   430,    -1,   431,    -1,
     433,    -1,   432,    -1,   434,    -1,   312,   158,   310,    -1,
     312,   322,   158,   310,    -1,   312,   323,   158,   310,    -1,
     312,   322,   323,   158,   310,    -1,   313,    -1,   312,   313,
      -1,   314,    -1,   319,    -1,    98,   315,    -1,   316,    -1,
     315,    48,    76,   316,    -1,    26,   108,   310,    -1,    26,
     411,   108,   310,    -1,    26,   317,   108,   310,    -1,    26,
     411,   317,   108,   310,    -1,    26,   318,   108,   310,    -1,
      26,   411,   318,   108,   310,    -1,    26,   317,   318,   108,
     310,    -1,    26,   411,   317,   318,   108,   310,    -1,    35,
      76,    26,    -1,   245,    76,    26,    -1,   119,   320,    -1,
     321,    -1,   320,    48,    76,   321,    -1,    26,   101,   310,
      -1,    26,   411,   101,   310,    -1,    26,   318,   101,   310,
      -1,    26,   411,   318,   101,   310,    -1,   195,   310,    -1,
     140,   324,    -1,   169,   324,    -1,   325,    -1,   324,    48,
     325,    -1,   310,    -1,   310,   326,    -1,   327,    -1,   328,
      -1,   329,    -1,   327,   328,    -1,   327,   329,    -1,   328,
     329,    -1,   327,   328,   329,    -1,    34,    -1,    72,    -1,
      85,    -1,    86,    -1,    47,    25,    -1,   168,   331,   161,
     310,    -1,    92,   331,   161,   310,    -1,   332,    -1,   331,
      48,    76,   332,    -1,    26,   108,   310,    -1,    26,   411,
     108,   310,    -1,   180,   309,   159,   334,    68,   158,   310,
      -1,   180,   309,   159,   334,    68,    76,    26,   158,   310,
      -1,   335,    -1,   334,   335,    -1,    41,   412,   158,   310,
      -1,    41,    76,    26,    33,   412,   158,   310,    -1,   105,
     309,   159,   177,   310,    84,   310,    -1,   338,    -1,   337,
     137,   338,    -1,   339,    -1,   338,    31,   339,    -1,   340,
      -1,   340,   354,   340,    -1,   340,   353,   340,    -1,   340,
     355,   340,    -1,   341,    -1,   341,   233,   436,    -1,   341,
     233,   436,   470,    -1,   342,    -1,   342,   178,   342,    -1,
     343,    -1,   342,   147,   343,    -1,   342,   123,   343,    -1,
     344,    -1,   343,   170,   344,    -1,   343,    73,   344,    -1,
     343,   104,   344,    -1,   343,   124,   344,    -1,   345,    -1,
     344,   181,   345,    -1,   344,   193,   345,    -1,   346,    -1,
     345,   112,   346,    -1,   345,    93,   346,    -1,   347,    -1,
     347,   110,   412,    -1,   348,    -1,   348,   179,   412,    -1,
     349,    -1,   349,    42,   410,    -1,   350,    -1,   350,    43,
     410,    -1,   352,    -1,   351,   352,    -1,   147,    -1,   123,
      -1,   351,   147,    -1,   351,   123,    -1,   356,    -1,   360,
      -1,   357,    -1,    89,    -1,   128,    -1,   122,    -1,   117,
      -1,   102,    -1,   100,    -1,   185,    -1,   190,    -1,   189,
      -1,   188,    -1,   187,    -1,   186,    -1,   113,    -1,   150,
      -1,    97,    -1,   191,   309,   156,    -1,    27,   115,   309,
     156,    -1,   358,   115,   156,    -1,   358,   115,   309,   156,
      -1,   359,    -1,   358,   359,    -1,   148,    20,    18,    -1,
     148,    21,    -1,   166,    -1,   166,   361,    -1,   167,   361,
      -1,   361,    -1,   362,    -1,   362,   166,   361,    -1,   362,
     167,   361,    -1,   363,    -1,   372,    -1,   364,    -1,   364,
     373,    -1,   367,    -1,   367,   373,    -1,   365,   369,    -1,
     366,    -1,    46,    -1,    70,    -1,    37,    -1,   164,    -1,
      71,    -1,    96,    -1,    95,    -1,   369,    -1,    40,   369,
      -1,   368,   369,    -1,    78,    -1,   141,    -1,    29,    -1,
     152,    -1,   151,    -1,    30,    -1,   416,    -1,   370,    -1,
      20,    -1,   371,    -1,   170,    -1,    12,    -1,    19,    -1,
     375,    -1,   375,   373,    -1,   374,    -1,   373,   374,    -1,
     116,   309,   157,    -1,   376,    -1,   378,    -1,   379,    -1,
     380,    -1,   383,    -1,   385,    -1,   381,    -1,   382,    -1,
     377,    -1,   428,    -1,    53,    -1,   111,    -1,    80,    -1,
      76,    26,    -1,   121,   159,    -1,   121,   309,   159,    -1,
      77,    -1,   139,   309,   156,    -1,   183,   309,   156,    -1,
      20,   121,   159,    -1,    20,   121,   384,   159,    -1,   310,
      -1,   384,    48,   310,    -1,   386,    -1,   403,    -1,   387,
      -1,   400,    -1,   401,    -1,   172,    20,    87,    -1,   172,
      20,   389,    87,    -1,   172,    20,   174,   171,    20,   174,
      -1,   172,    20,   174,   388,   171,    20,   174,    -1,   172,
      20,   389,   174,   171,    20,   174,    -1,   172,    20,   389,
     174,   388,   171,    20,   174,    -1,   398,    -1,   388,   398,
      -1,   390,    -1,   389,   390,    -1,    20,    89,   391,    -1,
     155,   392,   155,    -1,    32,   394,    32,    -1,    -1,   393,
      -1,    91,    -1,   396,    -1,   393,    91,    -1,   393,   396,
      -1,    -1,   395,    -1,    90,    -1,   397,    -1,   395,    90,
      -1,   395,   397,    -1,    23,    -1,   399,    -1,     3,    -1,
     399,    -1,   386,    -1,    10,    -1,   402,    -1,   399,    -1,
      13,    -1,     9,    -1,    79,    -1,    81,    -1,   307,    -1,
     196,    28,   197,    -1,   196,   197,    -1,   142,    17,   143,
      -1,   142,    17,     8,    -1,    44,     7,    -1,   404,    -1,
     405,    -1,   406,    -1,   407,    -1,   408,    -1,   409,    -1,
      74,   309,   156,    -1,    11,   156,    -1,    11,   309,   156,
      -1,    82,   309,   156,   115,   156,    -1,    82,   309,   156,
     115,   309,   156,    -1,     4,   156,    -1,     4,   309,   156,
      -1,    38,   309,   156,   115,   156,    -1,    38,   309,   156,
     115,   309,   156,    -1,   175,   309,   156,    -1,    51,   309,
     156,    -1,   154,    15,   115,   156,    -1,   154,    15,   115,
     309,   156,    -1,   154,   115,   309,   156,   115,   156,    -1,
     154,   115,   309,   156,   115,   309,   156,    -1,   415,    -1,
     415,   103,    -1,    33,   412,    -1,   414,    -1,   414,   413,
      -1,   194,    -1,   134,    -1,   136,    -1,   135,    -1,   415,
      -1,   416,    -1,   114,    -1,    20,    -1,   418,    -1,   424,
      -1,   422,    -1,   425,    -1,   423,    -1,   421,    -1,   420,
      -1,   419,    -1,   417,    -1,   130,   159,    -1,    75,   159,
      -1,    75,   424,   159,    -1,    75,   425,   159,    -1,   176,
     159,    -1,    52,   159,    -1,   145,   159,    -1,   145,    15,
     159,    -1,   145,    24,   159,    -1,    39,   159,    -1,    39,
      20,   159,    -1,    39,    20,    48,   426,   159,    -1,    39,
     170,   159,    -1,    39,   170,    48,   426,   159,    -1,   162,
      20,   159,    -1,    83,   159,    -1,    83,    20,   159,    -1,
      83,    20,    48,   426,   159,    -1,    83,    20,    48,   427,
     159,    -1,    83,   170,   159,    -1,    83,   170,    48,   426,
     159,    -1,    83,   170,    48,   427,   159,    -1,   163,    20,
     159,    -1,    20,    -1,    20,   103,    -1,    24,    -1,   202,
      -1,   204,   310,   208,   310,    -1,   204,   310,    33,   207,
     310,    -1,   204,   310,    33,   209,   310,    -1,   204,   310,
     199,   310,    -1,   204,   310,   200,   310,    -1,   203,   310,
      -1,   206,   310,   213,   310,    -1,   206,   212,   310,   213,
     310,    -1,   205,   310,    33,   310,    -1,   211,   435,   210,
     310,   158,   310,    -1,    26,   101,   310,    -1,   435,   201,
      26,   101,   310,    -1,   438,    -1,   438,   437,    -1,   438,
     250,   341,    -1,   438,   437,   250,   341,    -1,   447,    -1,
     445,    -1,   437,   447,    -1,   437,   445,    -1,   439,    -1,
     438,   235,   439,    -1,   440,    -1,   439,   232,   440,    -1,
     441,    -1,   440,   239,   441,    -1,   442,    -1,   234,   442,
      -1,   443,    -1,   443,   466,    -1,   121,   436,   159,    -1,
     444,    -1,   444,   462,    -1,   376,    -1,   115,   309,   156,
      -1,   446,    -1,   465,    -1,   464,    -1,   467,    -1,   461,
      -1,   138,    -1,   448,    -1,   449,    -1,   450,    -1,   451,
      -1,   454,    -1,   459,    -1,   460,    -1,   238,    -1,   249,
      -1,   223,    -1,   222,    -1,   259,    -1,   253,    -1,   226,
      -1,   225,    -1,   260,    -1,   254,    -1,   262,   453,    -1,
     262,    68,    -1,   262,   121,   453,   159,    -1,   262,   121,
     453,    48,   452,   159,    -1,   262,   121,    68,   159,    -1,
     262,   121,    68,    48,   452,   159,    -1,   256,    -1,   453,
      -1,   452,    48,   453,    -1,    35,    24,    -1,    35,    24,
     243,    24,    -1,    35,    24,   463,   237,    -1,    35,    24,
     243,    24,   463,   237,    -1,   261,   456,    -1,   261,   456,
     455,    -1,   258,    -1,   258,   455,    -1,   255,    -1,   458,
      -1,   455,   458,    -1,    35,    24,    -1,   121,   457,   159,
      -1,    24,    -1,   457,    24,    -1,   181,   456,    -1,    93,
     456,    -1,   236,    24,    -1,   263,    -1,   257,    -1,   221,
      -1,   218,    -1,   229,    -1,   216,    -1,   217,    -1,   214,
      -1,   215,    -1,   242,    -1,   230,   344,    -1,   219,   344,
      -1,   220,   344,    -1,   231,   344,   178,   344,    -1,   228,
     463,   468,    -1,   251,   344,   468,    -1,   240,   463,   248,
      -1,   244,   469,    -1,   227,   469,    -1,   264,    -1,   247,
      -1,   241,    -1,   246,    -1,   241,    -1,   252,   344,    -1
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
     233,   236,   239,   245,   251,   258,   265,   272,   279,   287,
     295,   301,   307,   314,   321,   328,   335,   343,   351,   353,
     357,   360,   364,   368,   370,   372,   376,   378,   380,   382,
     384,   386,   388,   390,   392,   394,   396,   400,   405,   410,
     416,   418,   421,   423,   425,   428,   430,   435,   439,   444,
     449,   455,   460,   466,   472,   479,   483,   487,   490,   492,
     497,   501,   506,   511,   517,   520,   523,   526,   528,   532,
     534,   537,   539,   541,   543,   546,   549,   552,   556,   558,
     560,   562,   564,   567,   572,   577,   579,   584,   588,   593,
     601,   611,   613,   616,   621,   629,   637,   639,   643,   645,
     649,   651,   655,   659,   663,   665,   669,   674,   676,   680,
     682,   686,   690,   692,   696,   700,   704,   708,   710,   714,
     718,   720,   724,   728,   730,   734,   736,   740,   742,   746,
     748,   752,   754,   757,   759,   761,   764,   767,   769,   771,
     773,   775,   777,   779,   781,   783,   785,   787,   789,   791,
     793,   795,   797,   799,   801,   803,   807,   812,   816,   821,
     823,   826,   830,   833,   835,   838,   841,   843,   845,   849,
     853,   855,   857,   859,   862,   864,   867,   870,   872,   874,
     876,   878,   880,   882,   884,   886,   888,   891,   894,   896,
     898,   900,   902,   904,   906,   908,   910,   912,   914,   916,
     918,   920,   922,   925,   927,   930,   934,   936,   938,   940,
     942,   944,   946,   948,   950,   952,   954,   956,   958,   960,
     963,   966,   970,   972,   976,   980,   984,   989,   991,   995,
     997,   999,  1001,  1003,  1005,  1009,  1014,  1021,  1029,  1037,
    1046,  1048,  1051,  1053,  1056,  1060,  1064,  1068,  1069,  1071,
    1073,  1075,  1078,  1081,  1082,  1084,  1086,  1088,  1091,  1094,
    1096,  1098,  1100,  1102,  1104,  1106,  1108,  1110,  1112,  1114,
    1116,  1118,  1120,  1124,  1127,  1131,  1135,  1138,  1140,  1142,
    1144,  1146,  1148,  1150,  1154,  1157,  1161,  1167,  1174,  1177,
    1181,  1187,  1194,  1198,  1202,  1207,  1213,  1220,  1228,  1230,
    1233,  1236,  1238,  1241,  1243,  1245,  1247,  1249,  1251,  1253,
    1255,  1257,  1259,  1261,  1263,  1265,  1267,  1269,  1271,  1273,
    1275,  1278,  1281,  1285,  1289,  1292,  1295,  1298,  1302,  1306,
    1309,  1313,  1319,  1323,  1329,  1333,  1336,  1340,  1346,  1352,
    1356,  1362,  1368,  1372,  1374,  1377,  1379,  1381,  1386,  1392,
    1398,  1403,  1408,  1411,  1416,  1422,  1427,  1434,  1438,  1444,
    1446,  1449,  1453,  1458,  1460,  1462,  1465,  1468,  1470,  1474,
    1476,  1480,  1482,  1486,  1488,  1491,  1493,  1496,  1500,  1502,
    1505,  1507,  1511,  1513,  1515,  1517,  1519,  1521,  1523,  1525,
    1527,  1529,  1531,  1533,  1535,  1537,  1539,  1541,  1543,  1545,
    1547,  1549,  1551,  1553,  1555,  1557,  1560,  1563,  1568,  1575,
    1580,  1587,  1589,  1591,  1595,  1598,  1603,  1608,  1615,  1618,
    1622,  1624,  1627,  1629,  1631,  1634,  1637,  1641,  1643,  1646,
    1649,  1652,  1655,  1657,  1659,  1661,  1663,  1665,  1667,  1669,
    1671,  1673,  1675,  1678,  1681,  1684,  1689,  1693,  1697,  1701,
    1704,  1707,  1709,  1711,  1713,  1715,  1717
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   729,   729,   737,   745,   751,   763,   769,   781,   791,
     806,   821,   836,   845,   854,   869,   878,   895,   904,   921,
     928,   935,   942,   954,   961,   968,   977,   990,   997,  1004,
    1011,  1018,  1025,  1032,  1041,  1054,  1061,  1079,  1094,  1102,
    1116,  1125,  1140,  1156,  1170,  1178,  1193,  1201,  1215,  1224,
    1233,  1242,  1264,  1278,  1292,  1302,  1312,  1322,  1338,  1347,
    1365,  1372,  1385,  1394,  1404,  1413,  1430,  1440,  1450,  1460,
    1476,  1484,  1498,  1508,  1519,  1530,  1542,  1554,  1566,  1578,
    1590,  1600,  1611,  1622,  1634,  1646,  1658,  1670,  1688,  1699,
    1716,  1725,  1740,  1754,  1768,  1777,  1792,  1799,  1806,  1813,
    1820,  1829,  1836,  1843,  1850,  1857,  1870,  1880,  1891,  1902,
    1919,  1928,  1943,  1950,  1963,  1977,  1986,  2003,  2013,  2024,
    2036,  2049,  2060,  2072,  2084,  2102,  2117,  2131,  2146,  2155,
    2172,  2183,  2195,  2206,  2224,  2238,  2246,  2261,  2270,  2287,
    2296,  2311,  2321,  2331,  2341,  2351,  2361,  2371,  2387,  2394,
    2407,  2415,  2429,  2443,  2453,  2469,  2479,  2494,  2503,  2519,
    2529,  2546,  2555,  2570,  2579,  2595,  2609,  2616,  2630,  2637,
    2659,  2666,  2677,  2688,  2705,  2712,  2722,  2738,  2745,  2759,
    2766,  2773,  2786,  2792,  2799,  2806,  2813,  2826,  2833,  2841,
    2855,  2862,  2869,  2882,  2889,  2904,  2911,  2926,  2933,  2948,
    2955,  2970,  2977,  2992,  2999,  3006,  3013,  3028,  3035,  3042,
    3056,  3063,  3070,  3077,  3084,  3091,  3104,  3111,  3118,  3125,
    3132,  3139,  3152,  3159,  3166,  3180,  3187,  3202,  3211,  3226,
    3235,  3252,  3261,  3303,  3310,  3317,  3324,  3338,  3346,  3353,
    3366,  3373,  3386,  3395,  3404,  3413,  3428,  3437,  3451,  3458,
    3465,  3472,  3479,  3486,  3493,  3506,  3513,  3526,  3535,  3550,
    3557,  3564,  3571,  3578,  3596,  3603,  3616,  3623,  3636,  3646,
    3656,  3672,  3679,  3694,  3703,  3720,  3734,  3741,  3748,  3755,
    3762,  3769,  3776,  3783,  3796,  3803,  3816,  3824,  3832,  3846,
    3859,  3866,  3880,  3893,  3907,  3966,  3975,  3990,  3999,  4014,
    4021,  4034,  4041,  4048,  4061,  4072,  4083,  4094,  4105,  4116,
    4134,  4143,  4158,  4167,  4184,  4199,  4207,  4222,  4228,  4235,
    4244,  4253,  4264,  4281,  4287,  4294,  4303,  4312,  4323,  4340,
    4348,  4362,  4370,  4384,  4392,  4400,  4409,  4424,  4433,  4442,
    4450,  4458,  4472,  4480,  4498,  4506,  4526,  4544,  4551,  4558,
    4565,  4572,  4579,  4592,  4606,  4615,  4624,  4632,  4660,  4669,
    4678,  4686,  4700,  4714,  4728,  4737,  4746,  4754,  4768,  4777,
    4792,  4806,  4815,  4824,  4864,  4872,  4880,  4894,  4901,  4908,
    4921,  4935,  4942,  4949,  4956,  4963,  4970,  4977,  4984,  4991,
    5004,  5017,  5024,  5032,  5046,  5059,  5072,  5079,  5086,  5099,
    5108,  5117,  5126,  5135,  5150,  5164,  5173,  5182,  5191,  5200,
    5210,  5220,  5236,  5260,  5270,  5293,  5335,  5347,  5353,  5359,
    5365,  5371,  5383,  5395,  5401,  5413,  5440,  5452,  5458,  5478,
    5484,  5490,  5496,  5508,  5514,  5520,  5526,  5538,  5544,  5556,
    5562,  5574,  5580,  5592,  5598,  5610,  5616,  5622,  5634,  5640,
    5652,  5658,  5670,  5676,  5682,  5688,  5694,  5706,  5718,  5725,
    5732,  5739,  5746,  5753,  5760,  5773,  5779,  5785,  5791,  5803,
    5809,  5815,  5821,  5833,  5839,  5851,  5857,  5863,  5869,  5875,
    5881,  5887,  5899,  5905,  5917,  5923,  5929,  5935,  5947,  5953,
    5959,  5965,  5971,  5983,  5989,  6001,  6007,  6019,  6025,  6037,
    6043,  6055,  6067,  6073,  6085,  6091,  6097,  6109,  6115,  6121,
    6127,  6133,  6145,  6151,  6157,  6163,  6175,  6187,  6199,  6211,
    6217,  6229,  6235,  6241,  6253,  6259,  6271
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
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 3549;
  const int xquery_parser::yynnts_ = 196;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 313;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 275;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 529;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace yy

#line 6281 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"



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





