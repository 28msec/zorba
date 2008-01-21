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
#line 131 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"


/* Line 317 of lalr1.cc.  */
#line 46 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"

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
    #line 90 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = driver.filename.getStore();
}
  /* Line 547 of yacc.c.  */
#line 283 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
#line 731 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [main]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr((yyval.node));
		;}
    break;

  case 3:
#line 739 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr((yyval.node));
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.main]\n";
#endif
		;}
    break;

  case 4:
#line 747 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [library]\n";
#endif
		;}
    break;

  case 5:
#line 753 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.library]\n";
#endif
		;}
    break;

  case 6:
#line 765 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version]\n";
#endif
		;}
    break;

  case 7:
#line 771 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version.encoding]\n";
#endif
		;}
    break;

  case 8:
#line 783 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 793 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 808 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 823 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 838 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 847 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 856 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 871 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 880 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 897 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 906 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 923 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [setter]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 930 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [import]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 937 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [namespace]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 944 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [default namespace]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 956 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [var]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 963 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [function]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 970 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [option]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 979 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [ftoption]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 992 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [boundary space]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 999 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [default collation]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 1006 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [base uri]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 1013 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [construction]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 1020 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [ordering mode]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 1027 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [empty order]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 1034 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [copy namespaces]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 1043 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [revalidation]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 1056 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [schema]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 1063 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [module]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 1081 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1096 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [preserve]\n";
#endif
			(yyval.node) = new BoundarySpaceDecl((yyloc),
								StaticQueryContext::preserve_space);
		;}
    break;

  case 39:
#line 1104 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [strip]\n";
#endif
			(yyval.node) = new BoundarySpaceDecl((yyloc),
								StaticQueryContext::strip_space);
		;}
    break;

  case 40:
#line 1118 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1127 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1142 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1158 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOptionDecl [ ]\n";
#endif
			(yyval.node) = new FTOptionDecl((yyloc),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 44:
#line 1172 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [ordered]\n";
#endif
			(yyval.node) = new OrderingModeDecl((yyloc),
								StaticQueryContext::ordered);
		;}
    break;

  case 45:
#line 1180 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [unordered]\n";
#endif
			(yyval.node) = new OrderingModeDecl((yyloc),
								StaticQueryContext::unordered);
		;}
    break;

  case 46:
#line 1195 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty greatest]\n";
#endif
			(yyval.node) = new EmptyOrderDecl((yyloc),
								StaticQueryContext::empty_greatest);
		;}
    break;

  case 47:
#line 1203 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty least]\n";
#endif
			(yyval.node) = new EmptyOrderDecl((yyloc),
								StaticQueryContext::empty_least);
		;}
    break;

  case 48:
#line 1217 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1226 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1235 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1244 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1266 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultCollationMode [ ]\n";
#endif
			(yyval.node) = new DefaultCollationDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 53:
#line 1280 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BaseURIDecl [ ]\n";
#endif
			(yyval.node) = new BaseURIDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 54:
#line 1294 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1304 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1314 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1324 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1340 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1349 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1367 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [namespace]\n";
#endif
			(yyval.node) = new SchemaPrefix((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1374 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [default element]\n";
#endif
			(yyval.node) = new SchemaPrefix((yyloc), true);
		;}
    break;

  case 62:
#line 1387 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1396 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1406 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1415 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1432 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1442 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1452 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1462 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1478 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [preserve]\n";
#endif
			(yyval.node) = new ConstructionDecl((yyloc),
								StaticQueryContext::cons_preserve);
		;}
    break;

  case 71:
#line 1486 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [strip]\n";
#endif
			(yyval.node) = new ConstructionDecl((yyloc),
								StaticQueryContext::cons_strip);
		;}
    break;

  case 72:
#line 1500 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [external]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,NULL,NULL,
								fn_extern);
		;}
    break;

  case 73:
#line 1510 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [expr]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(4) - (4)].expr)),
								fn_read);
		;}
    break;

  case 74:
#line 1521 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.external]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,NULL,
								fn_extern);
		;}
    break;

  case 75:
#line 1532 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.expr]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(5) - (5)].expr)),
								fn_read);
		;}
    break;

  case 76:
#line 1544 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [as_type.external]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (4)].node)),
								NULL,
								fn_extern);
		;}
    break;

  case 77:
#line 1556 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [as_type.expr]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (4)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(5) - (5)].expr)),
								fn_read);
		;}
    break;

  case 78:
#line 1568 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.as_type.external]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)),
								NULL,
								fn_extern);
		;}
    break;

  case 79:
#line 1580 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.as_type.expr]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(6) - (6)].expr)),
								fn_read);
		;}
    break;

  case 80:
#line 1592 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) external]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,NULL,NULL,
								fn_extern_update);
		;}
    break;

  case 81:
#line 1602 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) expr]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(4) - (4)].expr)),
								fn_update);
		;}
    break;

  case 82:
#line 1613 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.external]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,NULL,
								fn_extern_update);
		;}
    break;

  case 83:
#line 1624 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.expr]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(5) - (5)].expr)),
								fn_update);
		;}
    break;

  case 84:
#line 1636 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) as_type.external]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (4)].node)),
								NULL,
								fn_extern_update);
		;}
    break;

  case 85:
#line 1648 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) as_type.expr]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (4)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(5) - (5)].expr)),
								fn_update);
		;}
    break;

  case 86:
#line 1660 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.as_type.external]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)),
								NULL,
								fn_extern_update);
		;}
    break;

  case 87:
#line 1672 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.as_type.expr]\n";
#endif
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(6) - (6)].expr)),
								fn_update);
		;}
    break;

  case 88:
#line 1690 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1701 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1718 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1727 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1742 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EnclosedExpr [ ]\n";
#endif
			(yyval.expr) = new EnclosedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1756 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QueryBody [expr]\n";
#endif
			(yyval.expr) = new QueryBody((yyloc),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 94:
#line 1770 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1779 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1794 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [FLWORExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 97:
#line 1801 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [QuantifiedExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1808 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TypeswitchExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1815 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [IfExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1822 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [OrExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1831 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [InsertExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1838 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [DeleteExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1845 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [RenameExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1852 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [ReplaceExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1859 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TransformExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1872 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1882 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1893 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1904 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1921 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1930 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1945 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [for]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 113:
#line 1952 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [let]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 114:
#line 1965 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForClause [ ]\n";
#endif
			(yyval.node) = new ForClause((yyloc),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 115:
#line 1979 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1988 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2005 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2015 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2026 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2038 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2051 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2062 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2074 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2086 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2104 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PositionalVar [ ]\n";
#endif
			(yyval.node) = new PositionalVar((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 126:
#line 2119 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTScoreVar [ ]\n";
#endif
			(yyval.node) = new FTScoreVar((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 127:
#line 2133 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClause [ ]\n";
#endif
			(yyval.node) = new LetClause((yyloc),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)));
			
		;}
    break;

  case 128:
#line 2148 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2157 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2174 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2185 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2197 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2208 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2226 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "WhereClause [ ]\n";
#endif
			(yyval.node) = new WhereClause((yyloc),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 135:
#line 2240 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [ ]\n";
#endif
			(yyval.node) = new OrderByClause((yyloc),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 136:
#line 2248 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2263 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2272 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2289 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2298 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2313 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2323 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2333 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2343 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2353 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2363 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2373 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2389 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [ascending]\n";
#endif
			(yyval.node) = new OrderDirSpec((yyloc), dir_ascending);
		;}
    break;

  case 149:
#line 2396 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [descending]\n";
#endif
			(yyval.node) = new OrderDirSpec((yyloc), dir_descending);
		;}
    break;

  case 150:
#line 2409 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [greatest]\n";
#endif
			(yyval.node) = new OrderEmptySpec((yyloc),
								StaticQueryContext::empty_greatest);
		;}
    break;

  case 151:
#line 2417 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [least]\n";
#endif
			(yyval.node) = new OrderEmptySpec((yyloc),
								StaticQueryContext::empty_least);
		;}
    break;

  case 152:
#line 2431 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderCollationSpec [ ]\n";
#endif
			(yyval.node) = new OrderCollationSpec((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 153:
#line 2445 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2455 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2471 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2481 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2496 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2505 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2521 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2531 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2548 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2557 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2572 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2581 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2597 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IfExpr [ ]\n";
#endif
			(yyval.expr) = new IfExpr((yyloc),
								(yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 166:
#line 2611 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [and]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 167:
#line 2618 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [or.and]\n";
#endif
			(yyval.expr) = new OrExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 168:
#line 2632 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [comp]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 169:
#line 2639 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [and.comp]\n";
#endif
			(yyval.expr) = new AndExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 170:
#line 2661 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 171:
#line 2668 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2679 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2690 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2707 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 175:
#line 2714 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2724 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2740 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 178:
#line 2747 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add.to.add]\n";
#endif
			(yyval.expr) = new RangeExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 179:
#line 2761 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 180:
#line 2768 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult+mult]\n";
#endif
			(yyval.expr) = new AdditiveExpr((yyloc), op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 181:
#line 2775 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult-mult]\n";
#endif
			(yyval.expr) = new AdditiveExpr((yyloc), op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 182:
#line 2788 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [union]\n";
#endif
		;}
    break;

  case 183:
#line 2794 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult*union]\n";
#endif
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 184:
#line 2801 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.div.union]\n";
#endif
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 185:
#line 2808 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.idiv.union]\n";
#endif
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 186:
#line 2815 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.mod.union]\n";
#endif
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 187:
#line 2828 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [interexcept]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 188:
#line 2835 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union.union.interexcept]\n";
#endif
			(yyval.expr) = new UnionExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 189:
#line 2843 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union|interexcept]\n";
#endif
			(yyval.expr) = new UnionExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 190:
#line 2857 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [instanceof]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 191:
#line 2864 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.inter.instanceof]\n";
#endif
			(yyval.expr) = new IntersectExceptExpr((yyloc), op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 192:
#line 2871 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.except.instanceof]\n";
#endif
			(yyval.expr) = new IntersectExceptExpr((yyloc), op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 193:
#line 2884 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 194:
#line 2891 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2906 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 196:
#line 2913 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2928 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 198:
#line 2935 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2950 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 200:
#line 2957 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2972 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [value]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 202:
#line 2979 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2994 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [+]\n";
#endif
			(yyval.node) = new SignList((yyloc), true);
		;}
    break;

  case 204:
#line 3001 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [-]\n";
#endif
			(yyval.node) = new SignList((yyloc), false);
		;}
    break;

  case 205:
#line 3008 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.+]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 206:
#line 3015 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3030 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [validate]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 208:
#line 3037 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [path]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 209:
#line 3044 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [extension]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 210:
#line 3058 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [=]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_eq);
		;}
    break;

  case 211:
#line 3065 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [!=]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_ne);
		;}
    break;

  case 212:
#line 3072 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_lt);
		;}
    break;

  case 213:
#line 3079 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<=]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_le);
		;}
    break;

  case 214:
#line 3086 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_gt);
		;}
    break;

  case 215:
#line 3093 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>=]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_ge);
		;}
    break;

  case 216:
#line 3106 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [eq]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_eq);
		;}
    break;

  case 217:
#line 3113 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ne]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_ne);
		;}
    break;

  case 218:
#line 3120 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [lt]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_lt);
		;}
    break;

  case 219:
#line 3127 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [le]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_le);
		;}
    break;

  case 220:
#line 3134 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [gt]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_gt);
		;}
    break;

  case 221:
#line 3141 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ge]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_ge);
		;}
    break;

  case 222:
#line 3154 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [is]\n";
#endif
			(yyval.node) = new NodeComp((yyloc), op_is);
		;}
    break;

  case 223:
#line 3161 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [<<]\n";
#endif
			(yyval.node) = new NodeComp((yyloc), op_precedes);
		;}
    break;

  case 224:
#line 3168 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [>>]\n";
#endif
			(yyval.node) = new NodeComp((yyloc), op_follows);
		;}
    break;

  case 225:
#line 3182 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [expr]\n";
#endif
			(yyval.expr) = new ValidateExpr((yyloc), "strict", (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 226:
#line 3189 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3204 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3213 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3228 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3237 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3254 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3300 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/]\n";
#endif
			(yyval.expr) = new PathExpr((yyloc), path_leading_lone_slash, NULL);
		;}
    break;

  case 233:
#line 3307 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/relative]\n";
#endif
			(yyval.expr) = new PathExpr((yyloc), path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 234:
#line 3314 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [//relative]\n";
#endif
			(yyval.expr) = new PathExpr((yyloc), path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 235:
#line 3321 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [relative]\n";
#endif
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = rpe == NULL ? (yysemantic_stack_[(1) - (1)].expr) : new PathExpr((yyloc), path_relative, (yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 236:
#line 3335 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step]\n";
#endif
            AxisStep *as = dynamic_cast<AxisStep *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = as != NULL ? new RelativePathExpr((yyloc), st_slash, new ContextItemExpr((yyloc)), (yysemantic_stack_[(1) - (1)].expr)) : (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 237:
#line 3343 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step/relative]\n";
#endif
			(yyval.expr) = new RelativePathExpr((yyloc), st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 238:
#line 3350 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step//relative]\n";
#endif
			(yyval.expr) = new RelativePathExpr((yyloc), st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 239:
#line 3363 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [axis]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 240:
#line 3370 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [filter]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 241:
#line 3383 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward]\n";
#endif
			(yyval.expr) = new AxisStep((yyloc),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 242:
#line 3392 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward.predlist]\n";
#endif
			(yyval.expr) = new AxisStep((yyloc),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 243:
#line 3401 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse]\n";
#endif
			(yyval.expr) = new AxisStep((yyloc),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 244:
#line 3410 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse.predlist]\n";
#endif
			(yyval.expr) = new AxisStep((yyloc),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 245:
#line 3425 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [nodetest]\n";
#endif
			(yyval.node) = new ForwardStep((yyloc),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 246:
#line 3434 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [abbrev]\n";
#endif
			(yyval.node) = new ForwardStep((yyloc),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 247:
#line 3448 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [child]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_child);
		;}
    break;

  case 248:
#line 3455 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_descendant);
		;}
    break;

  case 249:
#line 3462 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [attribute]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_attribute);
		;}
    break;

  case 250:
#line 3469 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [self]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_self);
		;}
    break;

  case 251:
#line 3476 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant_or_self]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_descendant_or_self);
		;}
    break;

  case 252:
#line 3483 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following_sibling]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_following_sibling);
		;}
    break;

  case 253:
#line 3490 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_following);
		;}
    break;

  case 254:
#line 3503 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [nodetest]\n";
#endif
			(yyval.node) = new AbbrevForwardStep((yyloc), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 255:
#line 3510 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [@ nodetest]\n";
#endif
			(yyval.node) = new AbbrevForwardStep((yyloc), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 256:
#line 3523 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [nodetest]\n";
#endif
			(yyval.node) = new ReverseStep((yyloc),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 257:
#line 3532 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [..]\n";
#endif
			ReverseAxis* rev_p = new ReverseAxis((yyloc), axis_parent);
			(yyval.node) = new ReverseStep((yyloc),
								rev_p);
		;}
    break;

  case 258:
#line 3547 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [parent]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_parent);
		;}
    break;

  case 259:
#line 3554 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_ancestor);
		;}
    break;

  case 260:
#line 3561 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding_sibling]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_preceding_sibling);
		;}
    break;

  case 261:
#line 3568 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_preceding);
		;}
    break;

  case 262:
#line 3575 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor_or_self]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_ancestor_or_self);
		;}
    break;

  case 263:
#line 3593 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [kindtest]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 264:
#line 3600 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [nametest]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 265:
#line 3613 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [qname]\n";
#endif
			(yyval.node) = new NameTest((yyloc), new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 266:
#line 3620 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [wildcard]\n";
#endif
			(yyval.node) = new NameTest((yyloc), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 267:
#line 3633 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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

  case 268:
#line 3643 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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

  case 269:
#line 3653 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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

  case 270:
#line 3669 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 271:
#line 3676 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary.predlist]\n";
#endif
			(yyval.expr) = new FilterExpr((yyloc),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 272:
#line 3691 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PredicateList [single]\n";
#endif
			PredicateList* pred_list_p = new PredicateList((yyloc));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 273:
#line 3700 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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

  case 274:
#line 3717 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Predicate [ ]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 275:
#line 3731 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [literal]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 276:
#line 3738 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [varref]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 277:
#line 3745 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [paren]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 278:
#line 3752 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [context_item]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 279:
#line 3759 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [funcall]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 280:
#line 3766 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [cons]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 281:
#line 3773 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [ordered]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 282:
#line 3780 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [unordered]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 283:
#line 3793 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [numeric]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 284:
#line 3800 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [string]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 285:
#line 3813 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [decimal]\n";
#endif
			(yyval.expr) = new NumericLiteral((yyloc), decimal(yylval.decval));
		;}
    break;

  case 286:
#line 3820 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [int]\n";
#endif
			(yyval.expr) = new NumericLiteral((yyloc), yylval.ival);
		;}
    break;

  case 287:
#line 3827 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [double]\n";
#endif
			(yyval.expr) = new NumericLiteral((yyloc), yylval.dval);
		;}
    break;

  case 288:
#line 3840 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarRef [ ]\n";
#endif
			(yyval.expr) = new VarRef((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 289:
#line 3853 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [()]\n";
#endif
			(yyval.expr) = new ParenthesizedExpr((yyloc), NULL);
		;}
    break;

  case 290:
#line 3860 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [(expr)]\n";
#endif
			(yyval.expr) = new ParenthesizedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 291:
#line 3874 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ContextItemExpr [.]\n";
#endif
			(yyval.expr) = new ContextItemExpr((yyloc));
		;}
    break;

  case 292:
#line 3887 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderedExpr [expr]\n";
#endif
			(yyval.expr) = new OrderedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 293:
#line 3901 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnorderedExpr [expr]\n";
#endif
			(yyval.expr) = new UnorderedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 294:
#line 3960 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [ ]\n";
#endif
			(yyval.expr) = new FunctionCall((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 295:
#line 3969 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [arglist]\n";
#endif
			(yyval.expr) = new FunctionCall((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 296:
#line 3984 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [single]\n";
#endif
			ArgList* a_list_p = new ArgList((yyloc)); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 297:
#line 3993 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [list]\n";
#endif
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 298:
#line 4008 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [direct]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 299:
#line 4015 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [computed]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 300:
#line 4028 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [element]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 301:
#line 4035 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [comment]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 4042 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [pi]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 303:
#line 4055 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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

  case 304:
#line 4066 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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

  case 305:
#line 4077 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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

  case 306:
#line 4088 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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

  case 307:
#line 4099 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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

  case 308:
#line 4110 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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

  case 309:
#line 4128 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [single]\n";
#endif
			DirElemContentList* elem_content_list_p = new DirElemContentList((yyloc));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 310:
#line 4137 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [list]\n";
#endif
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 311:
#line 4152 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeList [single]\n";
#endif
			DirAttributeList* at_list_p = new DirAttributeList((yyloc));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 312:
#line 4161 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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

  case 313:
#line 4178 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttr [ ]\n";
#endif
			(yyval.node) = new DirAttr((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 314:
#line 4193 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [quote]\n";
#endif
			(yyval.node) = new DirAttributeValue((yyloc),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 315:
#line 4201 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [apos]\n";
#endif
			(yyval.node) = new DirAttributeValue((yyloc),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 316:
#line 4215 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList[empty]\n";
#endif
			(yyval.node) = new QuoteAttrContentList((yyloc));
		;}
    break;

  case 317:
#line 4222 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 318:
#line 4229 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [""]\n";
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList((yyloc));
			qo_list_p->push_back(new QuoteAttrValueContent((yyloc),string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 319:
#line 4238 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [single]\n";
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList((yyloc));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 320:
#line 4247 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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

  case 321:
#line 4258 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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

  case 322:
#line 4274 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']\n";
#endif
			(yyval.node) = new AposAttrContentList((yyloc));
		;}
    break;

  case 323:
#line 4281 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 324:
#line 4288 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']\n";
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList((yyloc));
			at_list_p->push_back(new AposAttrValueContent((yyloc),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 325:
#line 4297 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [single]\n";
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList((yyloc));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 326:
#line 4306 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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

  case 327:
#line 4317 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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

  case 328:
#line 4334 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [quote_attr_content]\n";
#endif
			(yyval.node) = new QuoteAttrValueContent((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 329:
#line 4342 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [common_content]\n";
#endif
			(yyval.node) = new QuoteAttrValueContent((yyloc),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 330:
#line 4356 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [apos_attr_content]\n";
#endif
			(yyval.node) = new AposAttrValueContent((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 331:
#line 4364 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [common_content]\n";
#endif
			(yyval.node) = new AposAttrValueContent((yyloc),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 332:
#line 4378 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cons]\n";
#endif
			(yyval.expr) = new DirElemContent((yyloc),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 333:
#line 4386 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [elem_content]\n";
#endif
			(yyval.expr) = new DirElemContent((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 334:
#line 4394 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cdata]\n";
#endif
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent((yyloc),
								cdata_h);
		;}
    break;

  case 335:
#line 4403 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [common_content]\n";
#endif
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent((yyloc),
								cont_h);
		;}
    break;

  case 336:
#line 4418 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [entity_ref]\n";
#endif
			(yyval.expr) = new CommonContent((yyloc),
								cont_entity,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 337:
#line 4427 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [char_ref]\n";
#endif
			(yyval.expr) = new CommonContent((yyloc),
								cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 338:
#line 4436 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [{{]\n";
#endif
			(yyval.expr) = new CommonContent((yyloc),
								cont_escape_lbrace);
		;}
    break;

  case 339:
#line 4444 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [}}]\n";
#endif
			(yyval.expr) = new CommonContent((yyloc),
								cont_escape_rbrace);
		;}
    break;

  case 340:
#line 4452 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [expr]\n";
#endif
			(yyval.expr) = new CommonContent((yyloc),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 341:
#line 4466 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirCommentConstructor [ ]\n";
#endif
			(yyval.expr) = new DirCommentConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 342:
#line 4485 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target]\n";
#endif
			(yyval.expr) = new DirPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 343:
#line 4493 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target.charlit]\n";
#endif
			(yyval.expr) = new DirPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 344:
#line 4513 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CDataSection [ ]\n";
#endif
			(yyval.expr) = new CDataSection((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 345:
#line 4531 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [doc]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 346:
#line 4538 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [elem]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 347:
#line 4545 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [attr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 348:
#line 4552 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [text]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 349:
#line 4559 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [comment]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 350:
#line 4566 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [pi]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 351:
#line 4579 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompDocConstructor [ ]\n";
#endif
			(yyval.expr) = new CompDocConstructor((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 352:
#line 4593 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [ ]\n";
#endif
			(yyval.expr) = new CompElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 353:
#line 4602 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [content]\n";
#endif
			(yyval.expr) = new CompElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 354:
#line 4611 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name]\n";
#endif
			(yyval.expr) = new CompElemConstructor((yyloc),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 355:
#line 4619 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name.content]\n";
#endif
			(yyval.expr) = new CompElemConstructor((yyloc),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 356:
#line 4647 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [ ]\n";
#endif
			(yyval.expr) = new CompAttrConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 357:
#line 4656 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [val]\n";
#endif
			(yyval.expr) = new CompAttrConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 358:
#line 4665 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name]\n";
#endif
			(yyval.expr) = new CompAttrConstructor((yyloc),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 359:
#line 4673 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name.val]\n";
#endif
			(yyval.expr) = new CompAttrConstructor((yyloc),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 360:
#line 4687 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompTextConstructor [content]\n";
#endif
			(yyval.expr) = new CompTextConstructor((yyloc),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 361:
#line 4701 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompCommentConstructor [content]\n";
#endif
			(yyval.expr) = new CompCommentConstructor((yyloc),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 362:
#line 4715 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [ ]\n";
#endif
			(yyval.expr) = new CompPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 363:
#line 4724 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [content]\n";
#endif
			(yyval.expr) = new CompPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 364:
#line 4733 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target]\n";
#endif
			(yyval.expr) = new CompPIConstructor((yyloc),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 365:
#line 4741 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target.content]\n";
#endif
			(yyval.expr) = new CompPIConstructor((yyloc),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 366:
#line 4755 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic]\n";
#endif
			(yyval.node) = new SingleType((yyloc),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 367:
#line 4764 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic ?]\n";
#endif
			(yyval.node) = new SingleType((yyloc),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 368:
#line 4779 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeDeclaration [as seqtype]\n";
#endif
			(yyval.node) = new TypeDeclaration((yyloc),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 369:
#line 4793 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type]\n";
#endif
			(yyval.node) = new SequenceType((yyloc),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 370:
#line 4802 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type.occurs]\n";
#endif
			(yyval.node) = new SequenceType((yyloc),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 371:
#line 4811 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [void]\n";
#endif
			(yyval.node) = new SequenceType((yyloc), NULL, NULL);
		;}
    break;

  case 372:
#line 4851 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [?]\n";
#endif
			(yyval.node) = new OccurrenceIndicator((yyloc),
								occurs_optionally);
		;}
    break;

  case 373:
#line 4859 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [*]\n";
#endif
			(yyval.node) = new OccurrenceIndicator((yyloc),
								occurs_zero_or_more);
		;}
    break;

  case 374:
#line 4867 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [+]\n";
#endif
			(yyval.node) = new OccurrenceIndicator((yyloc),
								occurs_one_or_more);
		;}
    break;

  case 375:
#line 4881 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [atomic]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 376:
#line 4888 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [kind]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 377:
#line 4895 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [item]\n";
#endif
			(yyval.node) = new ItemType((yyloc),true);
		;}
    break;

  case 378:
#line 4908 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AtomicType [qname]\n";
#endif
			(yyval.node) = new AtomicType((yyloc),
								new QName((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 379:
#line 4922 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [doc]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 380:
#line 4929 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [elem]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 381:
#line 4936 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [attr]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 382:
#line 4943 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_elem]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 383:
#line 4950 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_attr]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 384:
#line 4957 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [pi]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 385:
#line 4964 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [comment]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 386:
#line 4971 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [text]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 387:
#line 4978 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [any]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 388:
#line 4991 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AnyKindTest [ ]\n";
#endif
			(yyval.node) = new AnyKindTest((yyloc));
		;}
    break;

  case 389:
#line 5004 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [ ]\n";
#endif
			(yyval.node) = new DocumentTest((yyloc));
		;}
    break;

  case 390:
#line 5011 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [elem]\n";
#endif
			(yyval.node) = new DocumentTest((yyloc),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 391:
#line 5019 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [schema_elem]\n";
#endif
			(yyval.node) = new DocumentTest((yyloc),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 392:
#line 5033 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TextTest [ ]\n";
#endif
			(yyval.node) = new TextTest((yyloc));
		;}
    break;

  case 393:
#line 5046 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommentTest [ ]\n";
#endif
			(yyval.node) = new CommentTest((yyloc));
		;}
    break;

  case 394:
#line 5059 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ ]\n";
#endif
			(yyval.node) = new PITest((yyloc), "", "");
		;}
    break;

  case 395:
#line 5066 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ncname]\n";
#endif
			(yyval.node) = new PITest((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), "");
		;}
    break;

  case 396:
#line 5073 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [stringlit]\n";
#endif
			(yyval.node) = new PITest((yyloc), "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 397:
#line 5086 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [ ]\n";
#endif
			(yyval.node) = new AttributeTest((yyloc),
								NULL,
								NULL);
		;}
    break;

  case 398:
#line 5095 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name]\n";
#endif
			(yyval.node) = new AttributeTest((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL);
		;}
    break;

  case 399:
#line 5104 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name.type]\n";
#endif
			(yyval.node) = new AttributeTest((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 400:
#line 5113 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*]\n";
#endif
			(yyval.node) = new AttributeTest((yyloc),
								NULL,
								NULL);
		;}
    break;

  case 401:
#line 5122 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*.type]\n";
#endif
			(yyval.node) = new AttributeTest((yyloc),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 402:
#line 5137 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaAttributeTest [ ]\n";
#endif
			(yyval.node) = new SchemaAttributeTest((yyloc),
								new QName((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 403:
#line 5151 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [ ]\n";
#endif
			(yyval.node) = new ElementTest((yyloc),
									NULL,
									NULL);
		;}
    break;

  case 404:
#line 5160 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name]\n";
#endif
			(yyval.node) = new ElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
									NULL);
		;}
    break;

  case 405:
#line 5169 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name.type]\n";
#endif
			(yyval.node) = new ElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 406:
#line 5178 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name.type]\n";
#endif
			(yyval.node) = new ElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 407:
#line 5187 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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

  case 408:
#line 5197 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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

  case 409:
#line 5207 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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

  case 410:
#line 5223 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaElementTest [ ]\n";
#endif
			(yyval.node) = new SchemaElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 411:
#line 5247 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name]\n";
#endif
			(yyval.node) = new TypeName((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 412:
#line 5257 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name?]\n";
#endif
			(yyval.node) = new TypeName((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 413:
#line 5280 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StringLiteral [ ]\n";
#endif
			(yyval.expr) = new StringLiteral((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 414:
#line 5322 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [ ]\n";
#endif
		;}
    break;

  case 415:
#line 5334 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr]\n";
#endif
		;}
    break;

  case 416:
#line 5340 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.as_first]\n";
#endif
		;}
    break;

  case 417:
#line 5346 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.as_last]\n";
#endif
		;}
    break;

  case 418:
#line 5352 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.after]\n";
#endif
		;}
    break;

  case 419:
#line 5358 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.before]\n";
#endif
		;}
    break;

  case 420:
#line 5370 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteExpr [expr]\n";
#endif
		;}
    break;

  case 421:
#line 5382 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceExpr [expr.expr]\n";
#endif
		;}
    break;

  case 422:
#line 5388 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceExpr [value.expr]\n";
#endif
		;}
    break;

  case 423:
#line 5400 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RenameExpr [expr.expr]\n";
#endif
		;}
    break;

  case 424:
#line 5427 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TransformExpr [ ]\n";
#endif
		;}
    break;

  case 425:
#line 5439 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [single]\n";
#endif
		;}
    break;

  case 426:
#line 5445 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [list]\n";
#endif
		;}
    break;

  case 427:
#line 5465 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or]\n";
#endif
		;}
    break;

  case 428:
#line 5471 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity]\n";
#endif
		;}
    break;

  case 429:
#line 5477 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.weight_range]\n";
#endif
		;}
    break;

  case 430:
#line 5483 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity.weight_range]\n";
#endif
		;}
    break;

  case 431:
#line 5495 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_single]\n";
#endif
		;}
    break;

  case 432:
#line 5501 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_single]\n";
#endif
		;}
    break;

  case 433:
#line 5507 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_list]\n";
#endif
		;}
    break;

  case 434:
#line 5513 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_list]\n";
#endif
		;}
    break;

  case 435:
#line 5525 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [and]\n";
#endif
		;}
    break;

  case 436:
#line 5531 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [or.and]\n";
#endif
		;}
    break;

  case 437:
#line 5543 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [mild_not]\n";
#endif
		;}
    break;

  case 438:
#line 5549 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [and.mild_not]\n";
#endif
		;}
    break;

  case 439:
#line 5561 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [unary_not]\n";
#endif
		;}
    break;

  case 440:
#line 5567 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [mild_not.unary_not]\n";
#endif
		;}
    break;

  case 441:
#line 5579 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [words]\n";
#endif
		;}
    break;

  case 442:
#line 5585 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [not.words]\n";
#endif
		;}
    break;

  case 443:
#line 5597 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words]\n";
#endif
		;}
    break;

  case 444:
#line 5603 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words.times]\n";
#endif
		;}
    break;

  case 445:
#line 5609 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [selection]\n";
#endif
		;}
    break;

  case 446:
#line 5621 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value]\n";
#endif
		;}
    break;

  case 447:
#line 5627 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value.any_all_option]\n";
#endif
		;}
    break;

  case 448:
#line 5639 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [literal]\n";
#endif
		;}
    break;

  case 449:
#line 5645 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [expr]\n";
#endif
		;}
    break;

  case 450:
#line 5657 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [order]\n";
#endif
		;}
    break;

  case 451:
#line 5663 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [window]\n";
#endif
		;}
    break;

  case 452:
#line 5669 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [distance]\n";
#endif
		;}
    break;

  case 453:
#line 5675 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [scope]\n";
#endif
		;}
    break;

  case 454:
#line 5681 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [content]\n";
#endif
		;}
    break;

  case 455:
#line 5693 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOrderedIndicator [ ]\n";
#endif
		;}
    break;

  case 456:
#line 5705 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [case]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 457:
#line 5712 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [diacritics]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 458:
#line 5719 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stem]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 459:
#line 5726 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [thesaurus]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 460:
#line 5733 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stopword]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 461:
#line 5740 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [language]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 462:
#line 5747 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [wildcard]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 463:
#line 5760 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [lower]\n";
#endif
		;}
    break;

  case 464:
#line 5766 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [upper]\n";
#endif
		;}
    break;

  case 465:
#line 5772 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [sensitive]\n";
#endif
		;}
    break;

  case 466:
#line 5778 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [insensitive]\n";
#endif
		;}
    break;

  case 467:
#line 5790 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [with]\n";
#endif
		;}
    break;

  case 468:
#line 5796 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [without]\n";
#endif
		;}
    break;

  case 469:
#line 5802 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [sensitive]\n";
#endif
		;}
    break;

  case 470:
#line 5808 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [insensitive]\n";
#endif
		;}
    break;

  case 471:
#line 5820 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [with]\n";
#endif
		;}
    break;

  case 472:
#line 5826 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [without]\n";
#endif
		;}
    break;

  case 473:
#line 5838 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [id]\n";
#endif
		;}
    break;

  case 474:
#line 5844 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [default]\n";
#endif
		;}
    break;

  case 475:
#line 5850 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id)]\n";
#endif
		;}
    break;

  case 476:
#line 5856 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id,id,..)]\n";
#endif
		;}
    break;

  case 477:
#line 5862 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default)]\n";
#endif
		;}
    break;

  case 478:
#line 5868 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default,id,id,..)]\n";
#endif
		;}
    break;

  case 479:
#line 5874 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [without]\n";
#endif
		;}
    break;

  case 480:
#line 5886 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [single]\n";
#endif
		;}
    break;

  case 481:
#line 5892 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [list]\n";
#endif
		;}
    break;

  case 482:
#line 5904 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name]\n";
#endif
		;}
    break;

  case 483:
#line 5910 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel]\n";
#endif
		;}
    break;

  case 484:
#line 5916 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.range]\n";
#endif
		;}
    break;

  case 485:
#line 5922 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel.range]\n";
#endif
		;}
    break;

  case 486:
#line 5934 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list]\n";
#endif
		;}
    break;

  case 487:
#line 5940 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list.incl_excl]\n";
#endif
		;}
    break;

  case 488:
#line 5946 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default]\n";
#endif
		;}
    break;

  case 489:
#line 5952 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default.incl_excl]\n";
#endif
		;}
    break;

  case 490:
#line 5958 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [without]\n";
#endif
		;}
    break;

  case 491:
#line 5970 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [.]\n";
#endif
		;}
    break;

  case 492:
#line 5976 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [*]\n";
#endif
		;}
    break;

  case 493:
#line 5988 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [.]\n";
#endif
		;}
    break;

  case 494:
#line 5994 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [(*)]\n";
#endif
		;}
    break;

  case 495:
#line 6006 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [.]\n";
#endif
		;}
    break;

  case 496:
#line 6012 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [*]\n";
#endif
		;}
    break;

  case 497:
#line 6024 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [union]\n";
#endif
		;}
    break;

  case 498:
#line 6030 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [except]\n";
#endif
		;}
    break;

  case 499:
#line 6042 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTLanguageOption [ ]\n";
#endif
		;}
    break;

  case 500:
#line 6054 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [with]\n";
#endif
		;}
    break;

  case 501:
#line 6060 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [without]\n";
#endif
		;}
    break;

  case 502:
#line 6072 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [start]\n";
#endif
		;}
    break;

  case 503:
#line 6078 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [end]\n";
#endif
		;}
    break;

  case 504:
#line 6084 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [entire]\n";
#endif
		;}
    break;

  case 505:
#line 6096 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any]\n";
#endif
		;}
    break;

  case 506:
#line 6102 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any_word]\n";
#endif
		;}
    break;

  case 507:
#line 6108 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all]\n";
#endif
		;}
    break;

  case 508:
#line 6114 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all_words]\n";
#endif
		;}
    break;

  case 509:
#line 6120 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [phrase]\n";
#endif
		;}
    break;

  case 510:
#line 6132 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [exactly]\n";
#endif
		;}
    break;

  case 511:
#line 6138 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_least]\n";
#endif
		;}
    break;

  case 512:
#line 6144 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_most]\n";
#endif
		;}
    break;

  case 513:
#line 6150 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [range]\n";
#endif
		;}
    break;

  case 514:
#line 6162 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDistance [ ]\n";
#endif
		;}
    break;

  case 515:
#line 6174 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWindow [ ]\n";
#endif
		;}
    break;

  case 516:
#line 6186 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [ ]\n";
#endif
		;}
    break;

  case 517:
#line 6198 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [same]\n";
#endif
		;}
    break;

  case 518:
#line 6204 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [different]\n";
#endif
		;}
    break;

  case 519:
#line 6216 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [words]\n";
#endif
		;}
    break;

  case 520:
#line 6222 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [sentences]\n";
#endif
		;}
    break;

  case 521:
#line 6228 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [paragraph]\n";
#endif
		;}
    break;

  case 522:
#line 6240 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [sentence]\n";
#endif
		;}
    break;

  case 523:
#line 6246 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [paragraph]\n";
#endif
		;}
    break;

  case 524:
#line 6258 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTIgnoreOption [ ]\n";
#endif
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6104 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -648;
  const short int
  xquery_parser::yypact_[] =
  {
       796,  1367,  1555,  -648,  -648,  -648,  1743,  -648,    -2,  -648,
    -648,  -648,  3059,    36,   340,  -648,  3059,   -63,  -648,    95,
     292,   303,   378,   240,     9,    26,   273,   262,   276,   331,
     -29,   344,   356,  -648,  -648,  3059,   232,   384,  -648,  -648,
    -648,  3059,    38,   393,  -648,  -648,   400,  3059,    68,   298,
    -648,  -648,   415,  1931,  -648,   416,   299,  3059,  -648,   473,
      60,  -648,   494,  -648,  -648,   127,   497,   513,  -648,   579,
     579,   393,  -648,   529,  3059,   412,  3059,  3059,  3059,   524,
     535,  -648,  3059,  3059,  3059,  1172,   563,   534,   591,   984,
    -648,  -648,   244,  3059,   433,   437,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,   559,  -648,  -648,   332,
    -648,  -648,  -648,  -648,  -648,  -648,   474,   581,  -648,   493,
     380,   193,   213,   -27,    14,  -648,   504,   441,   580,   583,
    3247,  -648,  -648,  -648,     1,  -648,  -648,  -648,   314,  -648,
     507,   340,  -648,   507,   340,  -648,  -648,  -648,  -648,   507,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,    19,  -648,
      80,  -648,  -648,    13,  3059,   107,    17,  -648,    67,  -648,
     110,  -648,  -648,  -648,  -648,  -648,  -648,   576,   586,  -648,
     604,   610,  -648,  -648,   268,   547,   613,  -648,  -648,   294,
     306,   112,  -648,   479,   480,  -648,   114,    79,  -648,    81,
      42,     0,  -648,    -4,   592,  -648,    84,   606,   626,   609,
     519,   630,   622,   -10,   600,  -648,  -648,    96,   562,  -648,
     115,    85,   505,   506,  -648,   633,   548,  3059,   508,   509,
    -648,  -648,    64,    43,   133,  -648,    97,   224,   229,   469,
     225,  -648,     2,   636,  3059,   457,   570,   123,  -648,  -648,
    -648,  -648,   648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
     174,  -648,  -648,   132,   321,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,   244,
     -13,  3059,  3059,  3059,  3059,  3059,  -648,   253,   515,  3420,
    3420,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  3420,  3420,  3420,    10,
    3420,  3420,  3420,  3420,  3420,  3420,  3420,  3420,  3420,  3420,
    3420,   200,   200,   655,   655,  -648,  -648,  -648,  2119,  -648,
     579,   579,  3059,   507,  -648,  -648,   507,  -648,   507,  -648,
    -648,  3059,  -648,   230,   569,   656,  -648,   656,  -648,  -648,
      47,   222,  -648,  -648,   659,   -17,   200,    86,  -648,   661,
    -648,    23,   200,    88,   200,  -648,  3059,   179,  -648,  -648,
    -648,   572,   667,  -648,   667,  -648,  3059,   584,   615,  3059,
     617,  3059,   618,   -68,   587,   -11,   620,   512,   672,   612,
     672,  -648,   614,   663,  3059,   598,   -59,   628,  -648,   677,
    -648,   564,  -648,  -648,  -648,  -648,  2307,   231,  -648,  -648,
    3059,   616,  -648,    27,    53,  -648,  -648,   665,  -648,  -648,
    -648,   684,  -648,   319,  3059,  3059,  3059,  3059,   498,  3059,
    3059,   686,  3059,  -648,   132,   132,   174,  -648,   689,   690,
     174,   691,  -648,   349,  -648,   545,  -648,  -648,  -648,   450,
     668,  -648,  -648,   668,  -648,  3059,   561,  3059,   581,  -648,
    -648,  -648,  -648,  3059,    10,   372,  -648,   465,  3379,   490,
     484,  -648,  -648,   485,   290,   213,   213,   -28,   -27,   -27,
     -27,   -27,    14,    14,  -648,  -648,  -648,  -648,  -648,  -648,
     434,  -648,  -648,  -648,  -648,   623,  -648,  -648,   242,  -648,
    -648,    75,  -648,  -648,  -648,  2495,  -648,   568,   575,  -648,
    -648,  -648,  -648,   695,  -648,  3059,  -648,   335,   653,   363,
     200,  -648,  -648,  -648,   381,   394,   200,  -648,  -648,  -648,
    3059,  2683,   635,   577,   585,   588,   589,  -648,  3059,   393,
    -648,   713,  -648,   714,  3059,   638,  3059,  3059,   -53,   642,
     400,  3059,  -648,   704,   728,   704,  -648,   672,  -648,  3059,
    3059,   657,   415,   599,  -648,  -648,   243,   650,  -648,    41,
    -648,  -648,  -648,   754,  -648,  -648,   745,  -648,  -648,    58,
    -648,  -648,  -648,  -648,    78,  -648,   212,    73,  -648,   608,
    3059,  3059,  -648,  -648,  -648,  -648,  3059,  -648,  -648,   670,
     611,  -648,  -648,  -648,  -648,  -648,    12,   174,   318,    98,
      99,   -13,  -648,   749,  -648,  -648,  -648,  -648,   413,   729,
    -648,  3059,  -648,  3059,  -648,   245,   619,  -648,  3420,  -648,
    -648,  -648,  -648,   168,   325,  -648,    10,   168,  3420,  3420,
    3425,  -648,  -648,  -648,  -648,  -648,  -648,  -648,    10,    10,
     325,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,   246,  -648,  -648,  -648,
     248,  -648,  -648,  -648,  -648,  -648,   406,  -648,  -648,  -648,
    -648,   414,  -648,  -648,   249,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  3059,  -648,  -648,  3059,   669,
    3059,  -648,   696,   756,   744,   704,  -648,  -648,  3059,  -648,
    -648,  -648,  2871,   358,   398,  -648,   737,   624,   763,  -648,
     764,    89,   760,   641,    29,  -648,  -648,  -648,  -648,  -648,
    3059,  3059,  -648,  -648,  3420,  3420,  3420,  3420,   776,   565,
     766,  -648,   766,  -648,  -648,   729,  -648,  -648,  -648,  -648,
    -648,  -648,   -27,  -648,  -648,  -648,   283,   490,  -648,  -648,
     278,  3420,  -648,  -648,   484,  -648,   556,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  3059,  -648,  3059,  -648,
     672,  -648,  -648,   264,  -648,  -648,   773,   359,  -648,  -648,
    -648,  -648,   651,   472,  -648,  -648,  -648,  -648,   637,   640,
     786,   777,  3059,   793,  3059,  -648,  -648,   -27,   -27,   -27,
     365,   325,  -648,   100,  -648,   103,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,   704,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,   647,   200,  -648,   654,
    -648,  3420,   590,   766,  -648,  -648,  -648,   664,  3059,   -27,
    -648,  -648,  3059,  -648,  -648
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
     292,     0,   342,   395,   396,   231,     0,     0,   402,   410,
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
       0,     0,   411,     0,     0,     0,     0,   157,     0,     0,
     154,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    64,     0,    56,    60,     0,   130,     0,
       0,     0,     0,     0,   343,   362,     0,     0,   153,     0,
     337,   333,   336,     0,   338,   339,     0,   340,   332,     0,
     309,   335,   334,   304,     0,   312,     0,     0,   161,     0,
       0,     0,   418,   419,   415,   423,     0,   421,   425,     0,
       0,   498,   497,   492,   493,   495,     0,   487,   482,     0,
       0,    14,   148,     0,   149,   150,   151,   140,   141,   142,
     143,     0,   107,     0,   108,     0,     0,   442,     0,   176,
     455,   503,   502,     0,     0,   504,     0,     0,     0,     0,
     428,   432,   450,   431,   454,   452,   451,   453,     0,     0,
       0,   444,   507,   508,   505,   506,   509,   447,   372,   374,
     373,   370,   367,   228,   274,   358,     0,   399,   401,    91,
       0,    76,    77,    89,    74,    75,     0,    84,    85,    82,
      83,     0,    68,   354,     0,   412,   405,   406,   408,   409,
     158,   156,   125,   126,   119,     0,   121,   118,     0,     0,
       0,   116,     0,     0,    63,    57,   132,   131,     0,   129,
      11,   363,     0,   322,   316,   313,     0,     0,     0,   310,
       0,     0,     0,     0,     0,   162,     7,   416,   417,   422,
       0,     0,   496,   494,     0,     0,     0,     0,     0,     0,
       0,   477,     0,   475,   152,   144,   145,   146,   138,   109,
     449,   445,   524,   523,   522,   518,     0,   436,   517,   429,
       0,     0,   434,   433,   438,   440,     0,   359,    92,    78,
      79,    86,    87,   355,   123,   120,     0,   122,     0,    59,
       0,   133,   364,     0,   330,   324,     0,   323,   325,   331,
     328,   318,     0,   317,   319,   329,   344,   305,     0,     0,
       0,     0,     0,     0,     0,   426,   424,   511,   512,   510,
       0,   483,   484,     0,   480,     0,   147,   521,   520,   519,
     514,   515,   430,   516,   124,   165,    65,   365,   315,   326,
     327,   314,   320,   321,   306,   307,     0,     0,   163,     0,
     159,     0,     0,     0,   478,   476,   308,     0,     0,   513,
     485,   481,     0,   160,   164
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -648,  -648,  -648,   732,   736,  -648,   734,  -648,   510,   516,
    -307,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -426,  -648,  -648,  -648,  -648,  -648,
     605,   269,  -378,   735,     6,    -6,  -648,  -648,   718,  -648,
    -648,   250,   417,  -248,  -648,  -648,   239,  -648,   538,   537,
     182,  -648,  -648,   204,  -551,  -648,   795,   293,  -648,  -648,
     247,  -648,  -648,   549,   550,   223,  -580,   525,   -19,  -344,
     205,   214,  -648,  -648,  -648,  -648,  -648,   739,  -648,  -648,
    -648,  -648,  -648,  -648,   740,  -648,   -45,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,    61,  -648,  -648,  -648,   -38,   181,
    -648,  -343,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -439,  -648,   257,  -648,   429,  -648,  -648,  -648,  -648,
    -648,    54,    63,  -552,  -313,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,   528,  -224,  -347,  -648,  -648,
     238,  -360,  -648,  -648,  -648,  -648,  -648,  -648,  -648,   857,
     858,   124,   481,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,   392,  -648,  -648,   221,   215,   216,   396,  -648,  -648,
     226,  -648,  -478,  -648,  -648,  -648,  -648,   120,  -301,  -648,
     427,   101,  -648,  -436,  -648,  -648,  -648,  -648,  -647,  -648,
    -648,  -648,  -648,   108,   233,  -648
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   593,   252,   111,   112,   113,   114,
     397,   398,   617,   115,   116,   117,   118,   119,   120,   121,
     244,   245,   423,   424,   122,   254,   255,   327,   328,   490,
     491,   657,   658,   659,   660,   123,   241,   242,   124,   627,
     628,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   346,   347,
     348,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   373,   374,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   203,
     168,   169,   170,   619,   454,   455,   755,   832,   833,   826,
     827,   834,   828,   620,   621,   171,   172,   622,   173,   174,
     175,   176,   177,   178,   179,   534,   407,   529,   701,   530,
     531,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   547,   574,   190,   191,   192,   193,   194,   195,   196,
     287,   507,   680,   508,   509,   510,   511,   512,   513,   514,
     681,   682,   306,   307,   308,   309,   310,   853,   854,   311,
     476,   480,   646,   477,   312,   313,   684,   697,   779,   685,
     686,   691,   687,   860,   795,   669
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       202,   532,   532,   484,   595,   435,   506,   198,   200,   518,
     519,   520,   521,   487,   618,   533,   417,   556,   205,   425,
     404,   420,   210,   563,   270,   271,   404,   796,   420,   436,
     683,     7,   463,   772,   610,   611,   532,   584,   612,   600,
     643,   231,   532,   806,   532,   418,    27,   236,    29,   557,
      31,    32,   738,   246,   206,   564,   237,   567,   381,   257,
      18,   451,   385,   260,   321,   610,   611,   759,   613,   612,
     753,   451,   404,   262,   554,   209,   281,   282,   283,   285,
     274,   263,   276,   277,   278,   610,   611,    40,   434,   612,
     247,   441,   350,   211,   587,   555,   610,   611,   799,   613,
     612,   421,   843,   614,   359,   615,   227,   786,   787,   418,
     204,   626,   387,   368,   562,   376,   351,   212,    50,   613,
     321,   378,   503,   360,   412,   321,   414,   452,   504,   321,
     613,   558,   220,   558,   614,   555,   615,   623,   764,   555,
     266,   321,   321,   780,   782,   883,    62,   416,   883,   221,
     228,   357,   321,   549,   614,   321,   615,   321,   419,   321,
     321,   506,   506,   358,   478,   614,    59,   615,   773,   382,
     555,   745,   379,   386,   422,   585,   550,   589,   321,   712,
     618,   715,   650,   422,   844,   618,   718,   720,   601,   422,
     555,   248,   207,   754,   238,   616,    73,    59,   464,   465,
     532,   555,   803,   208,   882,   239,   532,   466,    87,   759,
     383,   643,   375,   716,   453,   377,   264,    59,   526,   721,
      79,   862,   450,   388,   624,   442,   758,    73,    59,   704,
     526,   422,   422,   380,   856,   413,    13,   415,   422,   267,
     427,   505,   559,   560,   565,   566,   760,    73,    13,    17,
     479,    79,   438,   457,   781,   783,   884,   840,    73,   885,
     384,    17,   219,   389,   474,   408,   532,   411,   440,   321,
     569,    79,    36,   447,   321,   321,   321,   570,   468,   763,
      42,   224,    79,   353,    36,   762,   456,   321,   321,   225,
     321,   321,    42,   321,   321,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   321,
     461,   527,    42,   350,   354,   488,   489,   492,   489,   494,
     249,   471,   618,   527,   792,   539,   540,    56,   551,   709,
     472,   515,   516,   506,   355,   800,   404,   351,   810,    56,
     739,   394,    60,   812,   487,   506,   506,    48,    49,   226,
       3,   552,   475,   481,    60,   222,   223,     4,     5,    66,
      67,   824,   824,   229,   250,   610,   610,   394,   352,   612,
     612,    66,    67,    75,   538,   543,    13,   458,   541,   230,
     356,   481,   459,   544,   607,    75,   482,   462,   232,    17,
     322,   528,    67,     7,   866,   703,   751,   405,   790,   807,
     568,   808,   813,   528,   406,   610,   793,   235,   495,   612,
     577,   794,    36,   580,   649,   582,   240,   867,   830,   324,
      42,   251,    18,   243,   395,   396,   711,    46,   598,   258,
     847,   848,   849,   850,   614,   614,   615,   615,   253,   483,
     829,   835,   213,    81,   608,   825,   869,   555,    52,    40,
     401,   402,   606,   215,   714,   259,   357,   653,   632,   633,
     634,   635,   214,   637,   638,    87,   640,    56,   358,   322,
     555,   555,   717,   216,   614,   555,   615,   370,   371,   610,
      50,   652,    60,   612,   503,   719,   831,   323,   261,   662,
     504,   664,   830,   555,   653,   655,   656,   809,   324,    66,
      67,   692,   693,   694,   695,   811,   555,    72,   217,   665,
     555,   548,   265,    75,   829,   268,   857,   532,   555,   654,
     835,   857,   858,   630,   325,   631,   555,   858,   218,   696,
     887,   269,   655,   656,   774,   775,   573,   889,   575,   859,
     881,   774,   775,   357,   859,   776,   777,   273,   614,   279,
     615,   706,   776,   777,   542,   358,   280,   542,   778,   542,
     872,   710,   522,   523,   722,   698,   699,   700,   275,   500,
     501,   502,   730,   524,   525,   641,   642,   724,   734,   331,
     736,   737,   891,     1,   555,   742,   286,   332,     2,     3,
     333,   314,   334,   746,   747,   319,     4,     5,     6,   320,
       7,   535,   535,   335,   321,     9,    10,   336,   329,   330,
     349,   361,   337,    11,    12,    13,    14,   362,   338,   363,
     372,   390,    15,   364,   767,   768,   392,    16,    17,    18,
     769,   391,   393,   399,   400,   409,   410,   426,   428,   429,
     339,   430,   431,   432,   433,   437,    33,    34,   439,   445,
      35,    36,    37,    38,    39,   489,    40,   789,    41,    42,
     446,   443,   444,   460,   448,   449,   467,   469,   470,   473,
     497,    44,    45,   526,   546,   340,   341,   342,   343,   344,
     345,   545,   553,   561,   571,   572,   591,    50,   579,   578,
     581,   583,   586,   590,   592,   597,   599,    53,   594,   603,
     596,   602,   609,   626,   604,   629,    56,   651,   636,   639,
     644,   645,   648,   661,   668,    57,   663,    58,    59,   688,
     689,    60,   690,   702,   707,   404,   394,    63,    64,   814,
      65,   708,   815,   726,   817,   725,   732,   733,    66,    67,
      68,   727,   821,   735,   728,   729,    72,   740,    73,   743,
     744,    74,    75,   288,   289,   748,   290,   291,   823,    77,
     756,   750,   752,   757,   845,   846,   771,   292,   770,   293,
     766,   784,    79,   653,   816,   791,   820,   818,   819,   836,
     294,   838,   839,   841,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   837,   842,   851,   481,   852,
       1,   863,   868,   871,   876,     2,     3,   877,   874,   888,
     864,   875,   865,     4,     5,     6,   879,     7,   886,   892,
       8,   315,     9,    10,   890,   316,   317,   713,   318,   485,
      11,    12,    13,    14,   403,   486,   878,   326,   880,    15,
     741,   749,   588,   788,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,   493,   785,    33,    34,   496,   272,    35,    36,    37,
      38,    39,   731,    40,   765,    41,    42,   517,   498,   367,
     499,   761,   893,   625,   369,    43,   894,   873,    44,    45,
     870,    46,   536,   233,   234,   576,   666,   797,    47,    48,
      49,   667,   855,   804,    50,   805,   802,   647,   861,     0,
     798,    51,    52,     0,    53,     0,    54,     0,    55,     0,
       0,     0,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,    57,     0,    58,    59,     0,     0,    60,     0,
      61,    62,     0,     0,    63,    64,     0,    65,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,     0,    69,
      70,    71,     0,    72,     0,    73,     0,     0,    74,    75,
       0,     0,     0,    76,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,     0,     1,    79,
       0,    80,     0,     2,     3,    81,    82,    83,    84,    85,
       0,     4,     5,     6,    86,     7,     0,     0,     8,     0,
       9,    10,     0,     0,     0,     0,     0,    87,    11,    12,
      13,    14,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,     0,
       0,    33,    34,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,    42,     0,     0,     0,     0,     0,
       0,     0,     0,    43,     0,     0,    44,    45,     0,    46,
       0,     0,     0,     0,     0,     0,    47,    48,    49,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,    51,
      52,     0,    53,     0,    54,     0,    55,     0,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
      57,     0,    58,    59,     0,     0,    60,     0,    61,    62,
       0,     0,    63,    64,     0,    65,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,     0,    69,    70,    71,
       0,    72,     0,    73,     0,     0,    74,    75,     0,     0,
       0,    76,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     1,    79,     0,     0,
       0,     2,     3,    81,    82,    83,    84,    85,     0,     4,
       5,     6,    86,     7,     0,     0,     8,     0,     9,    10,
       0,     0,     0,     0,     0,    87,    11,    12,    13,    14,
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
      63,    64,     0,    65,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,     0,    69,    70,    71,     0,    72,
       0,    73,     0,     0,    74,    75,     0,     0,     0,    76,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,     0,     0,    79,     0,     0,     0,     0,
       0,     1,    82,    83,    84,    85,     2,     3,     0,     0,
      86,   284,     0,     0,     4,     5,     6,     0,     7,     0,
       0,     8,     0,     9,    10,     0,     0,     0,     0,     0,
       0,    11,    12,    13,    14,     0,     0,     0,     0,     0,
      15,     0,     0,     0,     0,    16,    17,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,    34,     0,     0,    35,    36,
      37,    38,    39,     0,    40,     0,    41,    42,     0,     0,
       0,     0,     0,     0,     0,     0,    43,     0,     0,    44,
      45,     0,    46,     0,     0,     0,     0,     0,     0,    47,
       0,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,    51,    52,     0,    53,     0,    54,     0,     0,
       0,     0,     0,     0,    56,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,    58,    59,     0,     0,    60,
       0,    61,    62,     0,     0,    63,    64,     0,    65,     0,
     197,     0,     0,     0,     0,     0,    66,    67,    68,     0,
      69,    70,    71,     0,    72,     0,    73,     0,     0,    74,
      75,     0,     0,     0,    76,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,     1,
      79,     0,     0,     0,     2,     3,     0,    82,    83,    84,
      85,     0,     4,     5,     6,    86,     7,     0,     0,     8,
       0,     9,    10,     0,     0,     0,     0,     0,     0,    11,
      12,    13,    14,     0,     0,     0,     0,     0,    15,     0,
       0,     0,     0,    16,    17,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    34,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,    42,     0,     0,     0,     0,
       0,     0,     0,     0,    43,     0,     0,    44,    45,     0,
      46,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
      51,    52,     0,    53,     0,    54,     0,     0,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,    58,    59,     0,     0,    60,     0,    61,
      62,     0,     0,    63,    64,     0,    65,     0,   199,     0,
       0,     0,     0,     0,    66,    67,    68,     0,    69,    70,
      71,     0,    72,     0,    73,     0,     0,    74,    75,     0,
       0,     0,    76,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     1,    79,     0,
       0,     0,     2,     3,     0,    82,    83,    84,    85,     0,
       4,     5,     6,    86,     7,     0,     0,     8,     0,     9,
      10,     0,     0,     0,     0,     0,     0,    11,    12,    13,
      14,     0,     0,     0,     0,     0,    15,     0,     0,     0,
       0,    16,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,    42,     0,     0,     0,     0,     0,     0,
       0,     0,    43,     0,     0,    44,    45,     0,    46,     0,
       0,     0,     0,     0,     0,    47,     0,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,     0,    51,    52,
       0,    53,     0,    54,     0,     0,     0,     0,     0,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,    58,    59,     0,     0,    60,     0,    61,    62,     0,
       0,    63,    64,     0,    65,     0,     0,     0,     0,   201,
       0,     0,    66,    67,    68,     0,    69,    70,    71,     0,
      72,     0,    73,     0,     0,    74,    75,     0,     0,     0,
      76,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     1,    79,     0,     0,     0,
       2,     3,     0,    82,    83,    84,    85,     0,     4,     5,
       6,    86,     7,     0,     0,     8,     0,     9,    10,     0,
       0,     0,     0,     0,     0,    11,    12,    13,    14,     0,
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
      64,     0,    65,     0,     0,     0,     0,   256,     0,     0,
      66,    67,    68,     0,    69,    70,    71,     0,    72,     0,
      73,     0,     0,    74,    75,     0,     0,     0,    76,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     1,    79,     0,     0,     0,     2,     3,
       0,    82,    83,    84,    85,     0,     4,     5,     6,    86,
       7,     0,     0,     8,     0,     9,    10,     0,     0,     0,
       0,     0,     0,    11,    12,    13,    14,     0,     0,     0,
       0,     0,    15,     0,     0,     0,     0,    16,    17,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,    34,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,    42,
       0,     0,     0,     0,     0,     0,     0,     0,    43,     0,
       0,    44,    45,     0,    46,     0,     0,     0,     0,     0,
       0,    47,     0,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,    51,    52,     0,    53,     0,    54,
       0,     0,     0,     0,     0,     0,    56,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,    58,    59,     0,
       0,    60,     0,    61,    62,     0,     0,    63,    64,     0,
      65,     0,   537,     0,     0,     0,     0,     0,    66,    67,
      68,     0,    69,    70,    71,     0,    72,     0,    73,     0,
       0,    74,    75,     0,     0,     0,    76,     0,     0,    77,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     1,    79,     0,     0,     0,     2,     3,     0,    82,
      83,    84,    85,     0,     4,     5,     6,    86,     7,     0,
       0,     8,     0,     9,    10,     0,     0,     0,     0,     0,
       0,    11,    12,    13,    14,     0,     0,     0,     0,     0,
      15,     0,     0,     0,     0,    16,    17,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,    34,     0,     0,    35,    36,
      37,    38,    39,     0,    40,     0,    41,    42,     0,     0,
       0,     0,     0,     0,     0,     0,    43,     0,     0,    44,
      45,     0,    46,     0,     0,     0,     0,     0,     0,    47,
       0,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,    51,    52,     0,    53,     0,    54,     0,     0,
       0,     0,     0,     0,    56,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,    58,    59,     0,     0,    60,
       0,    61,    62,     0,     0,    63,    64,     0,    65,     0,
     605,     0,     0,     0,     0,     0,    66,    67,    68,     0,
      69,    70,    71,     0,    72,     0,    73,     0,     0,    74,
      75,     0,     0,     0,    76,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,     1,
      79,     0,     0,     0,     2,     3,     0,    82,    83,    84,
      85,     0,     4,     5,     6,    86,     7,     0,     0,     8,
       0,     9,    10,     0,     0,     0,     0,     0,     0,    11,
      12,    13,    14,     0,     0,     0,     0,     0,    15,     0,
       0,     0,     0,    16,    17,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    34,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,    42,     0,     0,     0,     0,
       0,     0,     0,     0,    43,     0,     0,    44,    45,     0,
      46,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
      51,    52,     0,    53,     0,    54,     0,     0,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,    58,    59,     0,     0,    60,     0,    61,
      62,     0,     0,    63,    64,     0,    65,     0,   705,     0,
       0,     0,     0,     0,    66,    67,    68,     0,    69,    70,
      71,     0,    72,     0,    73,     0,     0,    74,    75,     0,
       0,     0,    76,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     1,    79,     0,
       0,     0,     2,     3,     0,    82,    83,    84,    85,     0,
       4,     5,     6,    86,     7,     0,     0,     8,     0,     9,
      10,     0,     0,     0,     0,     0,     0,    11,    12,    13,
      14,     0,     0,     0,     0,     0,    15,     0,     0,     0,
       0,    16,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,    42,     0,     0,     0,     0,     0,     0,
       0,     0,    43,     0,     0,    44,    45,     0,    46,     0,
       0,     0,     0,     0,     0,    47,     0,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,     0,    51,    52,
       0,    53,     0,    54,     0,     0,     0,     0,     0,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,    58,    59,     0,     0,    60,     0,    61,    62,     0,
       0,    63,    64,     0,    65,     0,   723,     0,     0,     0,
       0,     0,    66,    67,    68,     0,    69,    70,    71,     0,
      72,     0,    73,     0,     0,    74,    75,     0,     0,     0,
      76,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     1,    79,     0,     0,     0,
       2,     3,     0,    82,    83,    84,    85,     0,     4,     5,
       6,    86,     7,     0,     0,     8,     0,     9,    10,     0,
       0,     0,     0,     0,     0,    11,    12,    13,    14,     0,
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
      64,     0,    65,     0,   822,     0,     0,     0,     0,     0,
      66,    67,    68,     0,    69,    70,    71,     0,    72,     0,
      73,     0,     0,    74,    75,     0,     0,     0,    76,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     1,    79,     0,     0,     0,     2,     3,
       0,    82,    83,    84,    85,     0,     4,     5,     6,    86,
       7,     0,     0,     8,     0,     9,    10,     0,     0,     0,
       0,     0,     0,    11,    12,    13,    14,     0,     0,     0,
       0,     0,    15,     0,     0,     0,     0,    16,    17,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,    34,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,    42,
       0,     0,     0,     0,     0,     0,     0,     0,    43,     0,
       0,    44,    45,     0,    46,     0,     0,     0,     0,     0,
       0,    47,     0,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,    51,    52,     0,    53,     0,    54,
       0,     0,     0,     0,     0,     0,    56,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,    58,    59,     0,
       0,    60,     0,    61,    62,     0,     0,    63,    64,     0,
      65,     0,     0,     0,     0,     0,     0,     0,    66,    67,
      68,     0,    69,    70,    71,     0,    72,     0,    73,     0,
       0,    74,    75,     0,     0,     0,    76,     0,     0,    77,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     1,    79,     0,     0,     0,     2,     3,     0,    82,
      83,    84,    85,     0,     4,     5,     6,    86,     7,     0,
       0,     8,     0,     9,    10,     0,     0,     0,     0,     0,
       0,    11,    12,    13,    14,     0,     0,     0,     0,     0,
      15,     0,     0,     0,     0,    16,    17,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,    34,     0,     0,    35,    36,
      37,    38,    39,     0,    40,     0,    41,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,    51,     0,     0,    53,     0,   365,     0,     0,
       0,     0,     0,     0,    56,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,    58,    59,     0,     0,    60,
       0,   366,    62,     0,     0,    63,    64,     0,    65,     0,
       0,     0,     0,     0,     0,     0,    66,    67,    68,     0,
      69,    70,     0,     0,    72,     0,    73,     0,     0,    74,
      75,     0,     0,     0,     1,     0,     0,    77,     0,     2,
       3,     0,     0,     0,     0,    78,     0,     4,     5,     6,
      79,     7,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,     0,     0,    11,    12,    13,    14,     0,     0,
       0,     0,     0,    15,     0,     0,     0,     0,    16,    17,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,     0,
       0,    35,    36,    37,    38,    39,     0,    40,     0,    41,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,    45,   670,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,    51,     0,     0,    53,     0,
      54,     0,     0,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    57,     0,    58,    59,
     670,     0,    60,     0,    61,    62,     0,     0,    63,    64,
       0,    65,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,     0,    69,    70,     0,     0,    72,     0,    73,
       0,     0,    74,    75,   671,     0,     0,   672,   288,   289,
      77,   290,   291,   673,   674,   675,     0,     0,    78,     0,
       0,   676,   292,    79,   293,     0,     0,     0,     0,     0,
     677,     0,     0,     0,     0,   294,   678,   679,     0,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     671,     0,     0,   672,   288,   289,     0,   290,   291,   673,
     674,   675,     0,     0,     0,     0,     0,     0,   292,     0,
     293,     0,     0,     0,     0,     0,   677,     0,     0,     0,
       0,   294,   801,   679,     0,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         6,   361,   362,   304,   430,   253,   349,     1,     2,   353,
     354,   355,   356,   320,   453,   362,   240,   395,    12,   243,
      30,    32,    16,   401,    69,    70,    30,   674,    32,   253,
     508,    21,    30,    21,     7,     8,   396,   105,    11,    98,
     476,    35,   402,   690,   404,    45,    59,    41,    61,   396,
      63,    64,   105,    47,    18,   402,    18,   404,    45,    53,
      50,    18,    45,    57,    45,     7,     8,   619,    41,    11,
      29,    18,    30,    13,    91,    14,    82,    83,    84,    85,
      74,    21,    76,    77,    78,     7,     8,    77,    98,    11,
      22,     6,   120,   156,   105,   112,     7,     8,   678,    41,
      11,   105,    73,    76,    90,    78,   135,   658,   659,    45,
     112,    38,    45,   112,    91,   153,   144,    22,   108,    41,
      45,   159,   112,   109,    45,    45,    45,    84,   118,    45,
      41,    45,   123,    45,    76,   112,    78,    84,    65,   112,
      13,    45,    45,    45,    45,    45,   145,   105,    45,   123,
     179,   178,    45,   106,    76,    45,    78,    45,   158,    45,
      45,   504,   505,   190,    32,    76,   139,    78,   156,   156,
     112,   597,   153,   156,   242,   423,   129,   425,    45,   557,
     619,   559,   483,   242,   155,   624,   564,   565,   436,   242,
     112,   123,   156,   152,   156,   168,   169,   139,   196,   197,
     560,   112,   680,   167,   851,   167,   566,   205,   221,   761,
     204,   647,   151,   560,   171,   154,   156,   139,    18,   566,
     193,   801,   158,   156,   171,   140,   168,   169,   139,   154,
      18,   242,   242,   153,   785,   156,    36,   156,   242,   112,
     156,   231,   156,   157,   156,   157,   168,   169,    36,    49,
     118,   193,   156,   156,   156,   156,   156,   168,   169,   156,
     153,    49,    22,   153,    90,   153,   626,   153,   153,    45,
      91,   193,    72,   267,    45,    45,    45,    98,   284,   626,
      80,    19,   193,    70,    72,    73,   153,    45,    45,    13,
      45,    45,    80,    45,    45,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    45,
      85,   111,    80,   120,   101,   321,   322,   323,   324,   325,
      22,   198,   761,   111,   668,   370,   371,   127,   106,   553,
     207,   350,   351,   676,   121,   679,    30,   144,   716,   127,
     588,    73,   142,   721,   651,   688,   689,   103,   104,    18,
      10,   129,   178,    32,   142,    82,    83,    17,    18,   159,
     160,     3,     3,    19,    66,     7,     7,    73,   175,    11,
      11,   159,   160,   173,   368,   381,    36,   153,   372,    23,
     167,    32,   153,   153,   153,   173,    65,   162,   156,    49,
     137,   191,   160,    21,   820,   153,   153,    91,   153,   153,
     406,   153,   153,   191,    98,     7,   238,    23,   155,    11,
     416,   243,    72,   419,    65,   421,    23,   153,    20,   166,
      80,   123,    50,    23,   156,   157,    91,    95,   434,    13,
     774,   775,   776,   777,    76,    76,    78,    78,    23,   118,
     753,   754,   150,   199,   450,    87,    87,   112,   116,    77,
     156,   157,   446,   150,    91,   156,   178,    44,   464,   465,
     466,   467,   170,   469,   470,   221,   472,   127,   190,   137,
     112,   112,    91,   170,    76,   112,    78,   163,   164,     7,
     108,    31,   142,    11,   112,    91,    88,   155,    15,   495,
     118,   497,    20,   112,    44,    82,    83,    91,   166,   159,
     160,   211,   212,   213,   214,    91,   112,   167,   130,   503,
     112,   387,    18,   173,   827,    18,   238,   877,   112,    69,
     833,   238,   244,   204,   192,   206,   112,   244,   150,   239,
     877,    18,    82,    83,   216,   217,   412,   881,   414,   261,
     175,   216,   217,   178,   261,   227,   228,    18,    76,    25,
      78,   545,   227,   228,   373,   190,    21,   376,   240,   378,
      88,   555,   357,   358,   570,   131,   132,   133,   156,   346,
     347,   348,   578,   359,   360,   474,   475,   571,   584,    86,
     586,   587,   883,     4,   112,   591,    23,    94,     9,    10,
      97,     0,    99,   599,   600,   162,    17,    18,    19,   162,
      21,   363,   364,   110,    45,    26,    27,   114,   134,    28,
     230,   107,   119,    34,    35,    36,    37,   176,   125,    39,
     113,    45,    43,    40,   630,   631,    22,    48,    49,    50,
     636,    45,    22,    86,    21,   156,   156,    45,    32,    13,
     147,    32,   123,    13,    22,    45,    67,    68,    86,    16,
      71,    72,    73,    74,    75,   661,    77,   663,    79,    80,
     112,   156,   156,   194,   156,   156,    30,   210,    98,    21,
     155,    92,    93,    18,    18,   182,   183,   184,   185,   186,
     187,   112,    23,    22,   112,    18,   174,   108,    73,   105,
      73,    73,   105,    73,    22,    32,    98,   118,    86,    22,
      86,    73,    86,    38,   140,    21,   127,   162,   210,    23,
      21,    21,    21,    45,   249,   136,   155,   138,   139,   229,
     236,   142,   237,   100,   156,    30,    73,   148,   149,   735,
     151,   156,   738,   156,   740,   100,    23,    23,   159,   160,
     161,   156,   748,   105,   156,   156,   167,   105,   169,    45,
      22,   172,   173,   219,   220,    98,   222,   223,   752,   180,
       6,   162,   112,    18,   770,   771,   155,   233,    98,   235,
     162,    22,   193,    44,   105,   156,    32,    81,    22,    42,
     246,    18,    18,    23,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   171,   155,    21,    32,   234,
       4,   245,    29,   152,    18,     9,    10,    30,   171,   155,
     816,   171,   818,    17,    18,    19,    23,    21,   171,   155,
      24,    89,    26,    27,   234,    89,    92,   558,    93,   319,
      34,    35,    36,    37,   229,   319,   842,   119,   844,    43,
     590,   602,   425,   661,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   324,   658,    67,    68,   327,    71,    71,    72,    73,
      74,    75,   579,    77,   627,    79,    80,   352,   329,   140,
     330,   624,   888,   454,   144,    89,   892,   833,    92,    93,
     827,    95,   364,    36,    36,   414,   504,   676,   102,   103,
     104,   505,   782,   688,   108,   689,   680,   480,   800,    -1,
     677,   115,   116,    -1,   118,    -1,   120,    -1,   122,    -1,
      -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,   139,    -1,    -1,   142,    -1,
     144,   145,    -1,    -1,   148,   149,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,   161,    -1,   163,
     164,   165,    -1,   167,    -1,   169,    -1,    -1,   172,   173,
      -1,    -1,    -1,   177,    -1,    -1,   180,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,     4,   193,
      -1,   195,    -1,     9,    10,   199,   200,   201,   202,   203,
      -1,    17,    18,    19,   208,    21,    -1,    -1,    24,    -1,
      26,    27,    -1,    -1,    -1,    -1,    -1,   221,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    67,    68,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,    -1,
      -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,   115,
     116,    -1,   118,    -1,   120,    -1,   122,    -1,    -1,    -1,
      -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,   139,    -1,    -1,   142,    -1,   144,   145,
      -1,    -1,   148,   149,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   160,   161,    -1,   163,   164,   165,
      -1,   167,    -1,   169,    -1,    -1,   172,   173,    -1,    -1,
      -1,   177,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,     4,   193,    -1,    -1,
      -1,     9,    10,   199,   200,   201,   202,   203,    -1,    17,
      18,    19,   208,    21,    -1,    -1,    24,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,   221,    34,    35,    36,    37,
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
     148,   149,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   160,   161,    -1,   163,   164,   165,    -1,   167,
      -1,   169,    -1,    -1,   172,   173,    -1,    -1,    -1,   177,
      -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,     4,   200,   201,   202,   203,     9,    10,    -1,    -1,
     208,   209,    -1,    -1,    17,    18,    19,    -1,    21,    -1,
      -1,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,
      73,    74,    75,    -1,    77,    -1,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,   102,
      -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      -1,    -1,   115,   116,    -1,   118,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,   142,
      -1,   144,   145,    -1,    -1,   148,   149,    -1,   151,    -1,
     153,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,    -1,
     163,   164,   165,    -1,   167,    -1,   169,    -1,    -1,   172,
     173,    -1,    -1,    -1,   177,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,     4,
     193,    -1,    -1,    -1,     9,    10,    -1,   200,   201,   202,
     203,    -1,    17,    18,    19,   208,    21,    -1,    -1,    24,
      -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,
      95,    -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,
      -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
     115,   116,    -1,   118,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,   138,   139,    -1,    -1,   142,    -1,   144,
     145,    -1,    -1,   148,   149,    -1,   151,    -1,   153,    -1,
      -1,    -1,    -1,    -1,   159,   160,   161,    -1,   163,   164,
     165,    -1,   167,    -1,   169,    -1,    -1,   172,   173,    -1,
      -1,    -1,   177,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,     4,   193,    -1,
      -1,    -1,     9,    10,    -1,   200,   201,   202,   203,    -1,
      17,    18,    19,   208,    21,    -1,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,    -1,
      -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,   115,   116,
      -1,   118,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,   139,    -1,    -1,   142,    -1,   144,   145,    -1,
      -1,   148,   149,    -1,   151,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,   160,   161,    -1,   163,   164,   165,    -1,
     167,    -1,   169,    -1,    -1,   172,   173,    -1,    -1,    -1,
     177,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,     4,   193,    -1,    -1,    -1,
       9,    10,    -1,   200,   201,   202,   203,    -1,    17,    18,
      19,   208,    21,    -1,    -1,    24,    -1,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    -1,
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
     149,    -1,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,   160,   161,    -1,   163,   164,   165,    -1,   167,    -1,
     169,    -1,    -1,   172,   173,    -1,    -1,    -1,   177,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,     4,   193,    -1,    -1,    -1,     9,    10,
      -1,   200,   201,   202,   203,    -1,    17,    18,    19,   208,
      21,    -1,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    -1,    -1,    -1,    -1,    -1,
      -1,   102,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,   115,   116,    -1,   118,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,
      -1,   142,    -1,   144,   145,    -1,    -1,   148,   149,    -1,
     151,    -1,   153,    -1,    -1,    -1,    -1,    -1,   159,   160,
     161,    -1,   163,   164,   165,    -1,   167,    -1,   169,    -1,
      -1,   172,   173,    -1,    -1,    -1,   177,    -1,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,     4,   193,    -1,    -1,    -1,     9,    10,    -1,   200,
     201,   202,   203,    -1,    17,    18,    19,   208,    21,    -1,
      -1,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,
      73,    74,    75,    -1,    77,    -1,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,   102,
      -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      -1,    -1,   115,   116,    -1,   118,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,   142,
      -1,   144,   145,    -1,    -1,   148,   149,    -1,   151,    -1,
     153,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,    -1,
     163,   164,   165,    -1,   167,    -1,   169,    -1,    -1,   172,
     173,    -1,    -1,    -1,   177,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,     4,
     193,    -1,    -1,    -1,     9,    10,    -1,   200,   201,   202,
     203,    -1,    17,    18,    19,   208,    21,    -1,    -1,    24,
      -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,
      95,    -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,
      -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
     115,   116,    -1,   118,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,   138,   139,    -1,    -1,   142,    -1,   144,
     145,    -1,    -1,   148,   149,    -1,   151,    -1,   153,    -1,
      -1,    -1,    -1,    -1,   159,   160,   161,    -1,   163,   164,
     165,    -1,   167,    -1,   169,    -1,    -1,   172,   173,    -1,
      -1,    -1,   177,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,     4,   193,    -1,
      -1,    -1,     9,    10,    -1,   200,   201,   202,   203,    -1,
      17,    18,    19,   208,    21,    -1,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,    -1,
      -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,   115,   116,
      -1,   118,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,   139,    -1,    -1,   142,    -1,   144,   145,    -1,
      -1,   148,   149,    -1,   151,    -1,   153,    -1,    -1,    -1,
      -1,    -1,   159,   160,   161,    -1,   163,   164,   165,    -1,
     167,    -1,   169,    -1,    -1,   172,   173,    -1,    -1,    -1,
     177,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,     4,   193,    -1,    -1,    -1,
       9,    10,    -1,   200,   201,   202,   203,    -1,    17,    18,
      19,   208,    21,    -1,    -1,    24,    -1,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    -1,
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
     149,    -1,   151,    -1,   153,    -1,    -1,    -1,    -1,    -1,
     159,   160,   161,    -1,   163,   164,   165,    -1,   167,    -1,
     169,    -1,    -1,   172,   173,    -1,    -1,    -1,   177,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,     4,   193,    -1,    -1,    -1,     9,    10,
      -1,   200,   201,   202,   203,    -1,    17,    18,    19,   208,
      21,    -1,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    -1,    -1,    -1,    -1,    -1,
      -1,   102,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,   115,   116,    -1,   118,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,
      -1,   142,    -1,   144,   145,    -1,    -1,   148,   149,    -1,
     151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
     161,    -1,   163,   164,   165,    -1,   167,    -1,   169,    -1,
      -1,   172,   173,    -1,    -1,    -1,   177,    -1,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,     4,   193,    -1,    -1,    -1,     9,    10,    -1,   200,
     201,   202,   203,    -1,    17,    18,    19,   208,    21,    -1,
      -1,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,
      73,    74,    75,    -1,    77,    -1,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      -1,    -1,   115,    -1,    -1,   118,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,   142,
      -1,   144,   145,    -1,    -1,   148,   149,    -1,   151,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,    -1,
     163,   164,    -1,    -1,   167,    -1,   169,    -1,    -1,   172,
     173,    -1,    -1,    -1,     4,    -1,    -1,   180,    -1,     9,
      10,    -1,    -1,    -1,    -1,   188,    -1,    17,    18,    19,
     193,    21,    -1,    -1,    24,    -1,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    77,    -1,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,   135,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,   118,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,
     135,    -1,   142,    -1,   144,   145,    -1,    -1,   148,   149,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,   161,    -1,   163,   164,    -1,    -1,   167,    -1,   169,
      -1,    -1,   172,   173,   215,    -1,    -1,   218,   219,   220,
     180,   222,   223,   224,   225,   226,    -1,    -1,   188,    -1,
      -1,   232,   233,   193,   235,    -1,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,   246,   247,   248,    -1,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     215,    -1,    -1,   218,   219,   220,    -1,   222,   223,   224,
     225,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,
     235,    -1,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,
      -1,   246,   247,   248,    -1,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260
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
     425,   426,   427,   428,   429,   430,   431,   153,   306,   153,
     306,   156,   307,   381,   112,   306,    18,   156,   167,   366,
     306,   156,    22,   150,   170,   150,   170,   130,   150,    22,
     123,   123,    82,    83,    19,    13,    18,   135,   179,    19,
      23,   306,   156,   421,   422,    23,   306,    18,   156,   167,
      23,   328,   329,    23,   312,   313,   306,    22,   123,    22,
      66,   123,   297,    23,   317,   318,   156,   306,    13,   156,
     306,    15,    13,    21,   156,    18,    13,   112,    18,    18,
     358,   358,   328,    18,   306,   156,   306,   306,   306,    25,
      21,   307,   307,   307,   209,   307,    23,   432,   219,   220,
     222,   223,   233,   235,   246,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   444,   445,   446,   447,
     448,   451,   456,   457,     0,   275,   276,   278,   305,   162,
     162,    45,   137,   155,   166,   192,   310,   319,   320,   134,
      28,    86,    94,    97,    99,   110,   114,   119,   125,   147,
     182,   183,   184,   185,   186,   187,   350,   351,   352,   230,
     120,   144,   175,    70,   101,   121,   167,   178,   190,    90,
     109,   107,   176,    39,    40,   120,   144,   349,   112,   356,
     163,   164,   113,   370,   371,   366,   370,   366,   370,   153,
     153,    45,   156,   306,   153,    45,   156,    45,   156,   153,
      45,    45,    22,    22,    73,   156,   157,   302,   303,    86,
      21,   156,   157,   302,    30,    91,    98,   408,   153,   156,
     156,   153,    45,   156,    45,   156,   105,   408,    45,   158,
      32,   105,   242,   314,   315,   408,    45,   156,    32,    13,
      32,   123,    13,    22,    98,   315,   408,    45,   156,    86,
     153,     6,   140,   156,   156,    16,   112,   306,   156,   156,
     158,    18,    84,   171,   386,   387,   153,   156,   153,   153,
     194,    85,   162,    30,   196,   197,   205,    30,   307,   210,
      98,   198,   207,    21,    90,   178,   452,   455,    32,   118,
     453,    32,    65,   118,   450,   280,   281,   282,   307,   307,
     321,   322,   307,   321,   307,   155,   320,   155,   335,   336,
     337,   337,   337,   112,   118,   231,   373,   433,   435,   436,
     437,   438,   439,   440,   441,   340,   340,   339,   341,   341,
     341,   341,   342,   342,   343,   343,    18,   111,   191,   409,
     411,   412,   413,   409,   407,   412,   407,   153,   306,   358,
     358,   306,   371,   307,   153,   112,    18,   423,   423,   106,
     129,   106,   129,    23,    91,   112,   304,   409,    45,   156,
     157,    22,    91,   304,   409,   156,   157,   409,   307,    91,
      98,   112,    18,   423,   424,   423,   424,   307,   105,    73,
     307,    73,   307,    73,   105,   315,   105,   105,   314,   315,
      73,   174,    22,   296,    86,   296,    86,    32,   307,    98,
      98,   315,    73,    22,   140,   153,   306,   153,   307,    86,
       7,     8,    11,    41,    76,    78,   168,   304,   383,   385,
     395,   396,   399,    84,   171,   387,    38,   331,   332,    21,
     204,   206,   307,   307,   307,   307,   210,   307,   307,    23,
     307,   453,   453,   455,    21,    21,   454,   452,    21,    65,
     450,   162,    31,    44,    69,    82,    83,   323,   324,   325,
     326,    45,   307,   155,   307,   306,   433,   439,   249,   467,
     135,   215,   218,   224,   225,   226,   232,   241,   247,   248,
     434,   442,   443,   444,   458,   461,   462,   464,   229,   236,
     237,   463,   211,   212,   213,   214,   239,   459,   131,   132,
     133,   410,   100,   153,   154,   153,   306,   156,   156,   408,
     306,    91,   304,   303,    91,   304,   409,    91,   304,    91,
     304,   409,   307,   153,   306,   100,   156,   156,   156,   156,
     307,   329,    23,    23,   307,   105,   307,   307,   105,   315,
     105,   313,   307,    45,    22,   296,   307,   307,    98,   318,
     162,   153,   112,    29,   152,   388,     6,    18,   168,   395,
     168,   385,    73,   409,    65,   332,   162,   307,   307,   307,
      98,   155,    21,   156,   216,   217,   227,   228,   240,   460,
      45,   156,    45,   156,    22,   325,   326,   326,   322,   307,
     153,   156,   341,   238,   243,   466,   460,   436,   466,   338,
     341,   247,   442,   444,   437,   438,   460,   153,   153,    91,
     304,    91,   304,   153,   307,   307,   105,   307,    81,    22,
      32,   307,   153,   306,     3,    87,   391,   392,   394,   396,
      20,    88,   389,   390,   393,   396,    42,   171,    18,    18,
     168,    23,   155,    73,   155,   307,   307,   341,   341,   341,
     341,    21,   234,   449,   450,   449,   326,   238,   244,   261,
     465,   465,   338,   245,   307,   307,   296,   153,    29,    87,
     394,   152,    88,   393,   171,   171,    18,    30,   307,    23,
     307,   175,   460,    45,   156,   156,   171,   409,   155,   341,
     234,   450,   155,   307,   307
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
     422,   423,   424,   425,   426,   427,   427,   427,   427,   427,
     428,   429,   429,   430,   431,   432,   432,   433,   433,   433,
     433,   434,   434,   434,   434,   435,   435,   436,   436,   437,
     437,   438,   438,   439,   439,   439,   440,   440,   441,   441,
     442,   442,   442,   442,   442,   443,   444,   444,   444,   444,
     444,   444,   444,   445,   445,   445,   445,   446,   446,   446,
     446,   447,   447,   448,   448,   448,   448,   448,   448,   448,
     449,   449,   450,   450,   450,   450,   451,   451,   451,   451,
     451,   452,   452,   453,   453,   454,   454,   455,   455,   456,
     457,   457,   458,   458,   458,   459,   459,   459,   459,   459,
     460,   460,   460,   460,   461,   462,   463,   464,   464,   465,
     465,   465,   466,   466,   467
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
       1,     1,     2,     4,     4,     1,     4,     3,     4,     7,
       9,     1,     2,     4,     7,     7,     1,     3,     1,     3,
       1,     3,     3,     3,     1,     3,     4,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     2,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     4,     1,
       2,     3,     1,     2,     2,     1,     1,     3,     3,     1,
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
       3,     5,     3,     2,     3,     5,     5,     3,     5,     5,
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
       273,     0,    -1,   275,    -1,   274,   275,    -1,   276,    -1,
     274,   276,    -1,   195,    21,   162,    -1,   195,    21,    85,
      21,   162,    -1,   278,   305,    -1,   305,    -1,   277,   278,
      -1,   122,    13,    86,    22,   162,    -1,   279,   162,    -1,
     280,   162,    -1,   279,   162,   280,   162,    -1,   281,    -1,
     279,   162,   281,    -1,   282,    -1,   280,   162,   282,    -1,
     283,    -1,   284,    -1,   285,    -1,   287,    -1,   299,    -1,
     301,    -1,   288,    -1,   289,    -1,   286,    -1,   293,    -1,
     294,    -1,   300,    -1,   290,    -1,   291,    -1,   292,    -1,
     426,    -1,   295,    -1,   298,    -1,    60,    13,    86,    22,
      -1,    52,   150,    -1,    52,   170,    -1,    56,   123,    22,
      -1,    57,   123,    22,    -1,    61,    18,    21,    -1,   221,
     444,    -1,    62,   135,    -1,    62,   179,    -1,    58,    82,
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
     427,    -1,   428,    -1,   430,    -1,   429,    -1,   431,    -1,
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
      -1,   329,    -1,   328,    45,    73,   329,    -1,    23,   105,
     307,    -1,    23,   408,   105,   307,    -1,   177,   306,   156,
     331,    65,   155,   307,    -1,   177,   306,   156,   331,    65,
      73,    23,   155,   307,    -1,   332,    -1,   331,   332,    -1,
      38,   409,   155,   307,    -1,    38,    73,    23,    30,   409,
     155,   307,    -1,   102,   306,   156,   174,   307,    81,   307,
      -1,   335,    -1,   334,   134,   335,    -1,   336,    -1,   335,
      28,   336,    -1,   337,    -1,   337,   351,   337,    -1,   337,
     350,   337,    -1,   337,   352,   337,    -1,   338,    -1,   338,
     230,   433,    -1,   338,   230,   433,   467,    -1,   339,    -1,
     339,   175,   339,    -1,   340,    -1,   339,   144,   340,    -1,
     339,   120,   340,    -1,   341,    -1,   340,   167,   341,    -1,
     340,    70,   341,    -1,   340,   101,   341,    -1,   340,   121,
     341,    -1,   342,    -1,   341,   178,   342,    -1,   341,   190,
     342,    -1,   343,    -1,   342,   109,   343,    -1,   342,    90,
     343,    -1,   344,    -1,   344,   107,   409,    -1,   345,    -1,
     345,   176,   409,    -1,   346,    -1,   346,    39,   407,    -1,
     347,    -1,   347,    40,   407,    -1,   349,    -1,   348,   349,
      -1,   144,    -1,   120,    -1,   348,   144,    -1,   348,   120,
      -1,   353,    -1,   357,    -1,   354,    -1,    86,    -1,   125,
      -1,   119,    -1,   114,    -1,    99,    -1,    97,    -1,   182,
      -1,   187,    -1,   186,    -1,   185,    -1,   184,    -1,   183,
      -1,   110,    -1,   147,    -1,    94,    -1,   188,   306,   153,
      -1,    24,   112,   306,   153,    -1,   355,   112,   153,    -1,
     355,   112,   306,   153,    -1,   356,    -1,   355,   356,    -1,
     145,    18,    16,    -1,   115,    -1,   163,   358,    -1,   164,
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
      -1,   374,    -1,   425,    -1,    50,    -1,   108,    -1,    77,
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
      25,   194,    -1,   139,    15,   140,    -1,   139,    15,     6,
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
      45,   423,   156,    -1,    80,    18,    45,   424,   156,    -1,
      80,   167,   156,    -1,    80,   167,    45,   423,   156,    -1,
      80,   167,    45,   424,   156,    -1,   160,    18,   156,    -1,
      18,    -1,    18,   100,    -1,    21,    -1,   199,    -1,   201,
     307,   205,   307,    -1,   201,   307,    30,   204,   307,    -1,
     201,   307,    30,   206,   307,    -1,   201,   307,   196,   307,
      -1,   201,   307,   197,   307,    -1,   200,   307,    -1,   203,
     307,   210,   307,    -1,   203,   209,   307,   210,   307,    -1,
     202,   307,    30,   307,    -1,   208,   432,   207,   307,   155,
     307,    -1,    23,    98,   307,    -1,   432,   198,    23,    98,
     307,    -1,   435,    -1,   435,   434,    -1,   435,   247,   338,
      -1,   435,   434,   247,   338,    -1,   444,    -1,   442,    -1,
     434,   444,    -1,   434,   442,    -1,   436,    -1,   435,   232,
     436,    -1,   437,    -1,   436,   229,   437,    -1,   438,    -1,
     437,   236,   438,    -1,   439,    -1,   231,   439,    -1,   440,
      -1,   440,   463,    -1,   118,   433,   156,    -1,   441,    -1,
     441,   459,    -1,   373,    -1,   112,   306,   153,    -1,   443,
      -1,   462,    -1,   461,    -1,   464,    -1,   458,    -1,   135,
      -1,   445,    -1,   446,    -1,   447,    -1,   448,    -1,   451,
      -1,   456,    -1,   457,    -1,   235,    -1,   246,    -1,   220,
      -1,   219,    -1,   256,    -1,   250,    -1,   223,    -1,   222,
      -1,   257,    -1,   251,    -1,   259,   450,    -1,   259,    65,
      -1,   259,   118,   450,   156,    -1,   259,   118,   450,    45,
     449,   156,    -1,   259,   118,    65,   156,    -1,   259,   118,
      65,    45,   449,   156,    -1,   253,    -1,   450,    -1,   449,
      45,   450,    -1,    32,    21,    -1,    32,    21,   240,    21,
      -1,    32,    21,   460,   234,    -1,    32,    21,   240,    21,
     460,   234,    -1,   258,   453,    -1,   258,   453,   452,    -1,
     255,    -1,   255,   452,    -1,   252,    -1,   455,    -1,   452,
     455,    -1,    32,    21,    -1,   118,   454,   156,    -1,    21,
      -1,   454,    21,    -1,   178,   453,    -1,    90,   453,    -1,
     233,    21,    -1,   260,    -1,   254,    -1,   218,    -1,   215,
      -1,   226,    -1,   213,    -1,   214,    -1,   211,    -1,   212,
      -1,   239,    -1,   227,   341,    -1,   216,   341,    -1,   217,
     341,    -1,   228,   341,   175,   341,    -1,   225,   460,   465,
      -1,   248,   341,   465,    -1,   237,   460,   245,    -1,   241,
     466,    -1,   224,   466,    -1,   261,    -1,   244,    -1,   238,
      -1,   243,    -1,   238,    -1,   249,   341,    -1
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
     544,   546,   548,   551,   556,   561,   563,   568,   572,   577,
     585,   595,   597,   600,   605,   613,   621,   623,   627,   629,
     633,   635,   639,   643,   647,   649,   653,   658,   660,   664,
     666,   670,   674,   676,   680,   684,   688,   692,   694,   698,
     702,   704,   708,   712,   714,   718,   720,   724,   726,   730,
     732,   736,   738,   741,   743,   745,   748,   751,   753,   755,
     757,   759,   761,   763,   765,   767,   769,   771,   773,   775,
     777,   779,   781,   783,   785,   787,   791,   796,   800,   805,
     807,   810,   814,   816,   819,   822,   824,   826,   830,   834,
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
    1297,  1301,  1307,  1311,  1314,  1318,  1324,  1330,  1334,  1340,
    1346,  1350,  1352,  1355,  1357,  1359,  1364,  1370,  1376,  1381,
    1386,  1389,  1394,  1400,  1405,  1412,  1416,  1422,  1424,  1427,
    1431,  1436,  1438,  1440,  1443,  1446,  1448,  1452,  1454,  1458,
    1460,  1464,  1466,  1469,  1471,  1474,  1478,  1480,  1483,  1485,
    1489,  1491,  1493,  1495,  1497,  1499,  1501,  1503,  1505,  1507,
    1509,  1511,  1513,  1515,  1517,  1519,  1521,  1523,  1525,  1527,
    1529,  1531,  1533,  1535,  1538,  1541,  1546,  1553,  1558,  1565,
    1567,  1569,  1573,  1576,  1581,  1586,  1593,  1596,  1600,  1602,
    1605,  1607,  1609,  1612,  1615,  1619,  1621,  1624,  1627,  1630,
    1633,  1635,  1637,  1639,  1641,  1643,  1645,  1647,  1649,  1651,
    1653,  1656,  1659,  1662,  1667,  1671,  1675,  1679,  1682,  1685,
    1687,  1689,  1691,  1693,  1695
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   730,   730,   738,   746,   752,   764,   770,   782,   792,
     807,   822,   837,   846,   855,   870,   879,   896,   905,   922,
     929,   936,   943,   955,   962,   969,   978,   991,   998,  1005,
    1012,  1019,  1026,  1033,  1042,  1055,  1062,  1080,  1095,  1103,
    1117,  1126,  1141,  1157,  1171,  1179,  1194,  1202,  1216,  1225,
    1234,  1243,  1265,  1279,  1293,  1303,  1313,  1323,  1339,  1348,
    1366,  1373,  1386,  1395,  1405,  1414,  1431,  1441,  1451,  1461,
    1477,  1485,  1499,  1509,  1520,  1531,  1543,  1555,  1567,  1579,
    1591,  1601,  1612,  1623,  1635,  1647,  1659,  1671,  1689,  1700,
    1717,  1726,  1741,  1755,  1769,  1778,  1793,  1800,  1807,  1814,
    1821,  1830,  1837,  1844,  1851,  1858,  1871,  1881,  1892,  1903,
    1920,  1929,  1944,  1951,  1964,  1978,  1987,  2004,  2014,  2025,
    2037,  2050,  2061,  2073,  2085,  2103,  2118,  2132,  2147,  2156,
    2173,  2184,  2196,  2207,  2225,  2239,  2247,  2262,  2271,  2288,
    2297,  2312,  2322,  2332,  2342,  2352,  2362,  2372,  2388,  2395,
    2408,  2416,  2430,  2444,  2454,  2470,  2480,  2495,  2504,  2520,
    2530,  2547,  2556,  2571,  2580,  2596,  2610,  2617,  2631,  2638,
    2660,  2667,  2678,  2689,  2706,  2713,  2723,  2739,  2746,  2760,
    2767,  2774,  2787,  2793,  2800,  2807,  2814,  2827,  2834,  2842,
    2856,  2863,  2870,  2883,  2890,  2905,  2912,  2927,  2934,  2949,
    2956,  2971,  2978,  2993,  3000,  3007,  3014,  3029,  3036,  3043,
    3057,  3064,  3071,  3078,  3085,  3092,  3105,  3112,  3119,  3126,
    3133,  3140,  3153,  3160,  3167,  3181,  3188,  3203,  3212,  3227,
    3236,  3253,  3299,  3306,  3313,  3320,  3334,  3342,  3349,  3362,
    3369,  3382,  3391,  3400,  3409,  3424,  3433,  3447,  3454,  3461,
    3468,  3475,  3482,  3489,  3502,  3509,  3522,  3531,  3546,  3553,
    3560,  3567,  3574,  3592,  3599,  3612,  3619,  3632,  3642,  3652,
    3668,  3675,  3690,  3699,  3716,  3730,  3737,  3744,  3751,  3758,
    3765,  3772,  3779,  3792,  3799,  3812,  3819,  3826,  3839,  3852,
    3859,  3873,  3886,  3900,  3959,  3968,  3983,  3992,  4007,  4014,
    4027,  4034,  4041,  4054,  4065,  4076,  4087,  4098,  4109,  4127,
    4136,  4151,  4160,  4177,  4192,  4200,  4215,  4221,  4228,  4237,
    4246,  4257,  4274,  4280,  4287,  4296,  4305,  4316,  4333,  4341,
    4355,  4363,  4377,  4385,  4393,  4402,  4417,  4426,  4435,  4443,
    4451,  4465,  4484,  4492,  4512,  4530,  4537,  4544,  4551,  4558,
    4565,  4578,  4592,  4601,  4610,  4618,  4646,  4655,  4664,  4672,
    4686,  4700,  4714,  4723,  4732,  4740,  4754,  4763,  4778,  4792,
    4801,  4810,  4850,  4858,  4866,  4880,  4887,  4894,  4907,  4921,
    4928,  4935,  4942,  4949,  4956,  4963,  4970,  4977,  4990,  5003,
    5010,  5018,  5032,  5045,  5058,  5065,  5072,  5085,  5094,  5103,
    5112,  5121,  5136,  5150,  5159,  5168,  5177,  5186,  5196,  5206,
    5222,  5246,  5256,  5279,  5321,  5333,  5339,  5345,  5351,  5357,
    5369,  5381,  5387,  5399,  5426,  5438,  5444,  5464,  5470,  5476,
    5482,  5494,  5500,  5506,  5512,  5524,  5530,  5542,  5548,  5560,
    5566,  5578,  5584,  5596,  5602,  5608,  5620,  5626,  5638,  5644,
    5656,  5662,  5668,  5674,  5680,  5692,  5704,  5711,  5718,  5725,
    5732,  5739,  5746,  5759,  5765,  5771,  5777,  5789,  5795,  5801,
    5807,  5819,  5825,  5837,  5843,  5849,  5855,  5861,  5867,  5873,
    5885,  5891,  5903,  5909,  5915,  5921,  5933,  5939,  5945,  5951,
    5957,  5969,  5975,  5987,  5993,  6005,  6011,  6023,  6029,  6041,
    6053,  6059,  6071,  6077,  6083,  6095,  6101,  6107,  6113,  6119,
    6131,  6137,  6143,  6149,  6161,  6173,  6185,  6197,  6203,  6215,
    6221,  6227,  6239,  6245,  6257
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
  const int xquery_parser::yylast_ = 3685;
  const int xquery_parser::yynnts_ = 196;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 314;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 272;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 526;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace yy

#line 6267 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"



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





