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
#line 126 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"


/* Line 317 of lalr1.cc.  */
#line 46 "/Users/mbrantner/misc/code/vanilla/datatypes/build/src/compiler/parser/xquery_parser.cpp"

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
    #line 85 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = driver.filename.getStore();
}
  /* Line 555 of yacc.c.  */
#line 283 "/Users/mbrantner/misc/code/vanilla/datatypes/build/src/compiler/parser/xquery_parser.cpp"
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
#line 728 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [main]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr((yyval.node));
		;}
    break;

  case 3:
#line 736 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr((yyval.node));
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.main]" << endl;
#endif
		;}
    break;

  case 4:
#line 744 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [library]" << endl;
#endif
		;}
    break;

  case 5:
#line 750 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.library]" << endl;
#endif
		;}
    break;

  case 6:
#line 762 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version]" << endl;
#endif
		;}
    break;

  case 7:
#line 768 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version.encoding]" << endl;
#endif
		;}
    break;

  case 8:
#line 780 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MainModule [prolog.querybody]" << endl;
#endif
			(yyval.node) = new MainModule(driver.createQueryLoc((yyloc)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)));
		;}
    break;

  case 9:
#line 790 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MainModule [querybody]" << endl;
#endif
			(yyval.node) = new MainModule(driver.createQueryLoc((yyloc)),
								NULL,
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 10:
#line 805 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LibraryModule [ ]" << endl;
#endif
			(yyval.node) = new LibraryModule(driver.createQueryLoc((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 11:
#line 820 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleDecl [ ]" << endl;
#endif
			(yyval.node) = new ModuleDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)), 
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (4)].sval)));
		;}
    break;

  case 12:
#line 835 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Prolog [sind]" << endl;
#endif
			(yyval.node) = new Prolog(driver.createQueryLoc((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 13:
#line 844 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Prolog [vfo]" << endl;
#endif
			(yyval.node) = new Prolog(driver.createQueryLoc((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 14:
#line 853 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Prolog [sind.vfo]" << endl;
#endif
			(yyval.node) = new Prolog(driver.createQueryLoc((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 15:
#line 868 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_DeclList [single]" << endl;
#endif
			SIND_DeclList* sindList_p = new SIND_DeclList(driver.createQueryLoc((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 16:
#line 877 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_DeclList [list]" << endl;
#endif
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 17:
#line 894 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_DeclList [single]" << endl;
#endif
			VFO_DeclList* vfoList_p = new VFO_DeclList(driver.createQueryLoc((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 18:
#line 903 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_DeclList [list]" << endl;
#endif
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 19:
#line 920 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [setter]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 927 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [import]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 934 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 941 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [default namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 953 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [var]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 960 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [function]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 967 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [option]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 976 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [ftoption]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 989 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [boundary space]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 996 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [default collation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 1003 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [base uri]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 1010 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [construction]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 1017 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [ordering mode]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 1024 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [empty order]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 1031 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [copy namespaces]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 1040 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [revalidation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 1053 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [schema]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 1060 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [module]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 1078 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NamespaceDecl [ ]" << endl;
#endif
			(yyval.node) = new NamespaceDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 38:
#line 1093 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [preserve]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 39:
#line 1101 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [strip]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 40:
#line 1115 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultNamespaceDecl [element]" << endl;
#endif
			(yyval.node) = new DefaultNamespaceDecl(driver.createQueryLoc((yyloc)),
								ParseConstants::ns_element_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 41:
#line 1124 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultNamespaceDecl [function]" << endl;
#endif
			(yyval.node) = new DefaultNamespaceDecl(driver.createQueryLoc((yyloc)),
								ParseConstants::ns_function_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 42:
#line 1139 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OptionDecl [ ]" << endl;
#endif
			(yyval.node) = new OptionDecl(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 43:
#line 1155 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOptionDecl [ ]" << endl;
#endif
			(yyval.node) = new FTOptionDecl(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 44:
#line 1169 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [ordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 45:
#line 1177 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [unordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 46:
#line 1192 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty greatest]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 47:
#line 1200 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty least]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 48:
#line 1214 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]" << endl;
#endif
			(yyval.node) = new CopyNamespacesDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 49:
#line 1223 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]" << endl;
#endif
			(yyval.node) = new CopyNamespacesDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 50:
#line 1232 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]" << endl;
#endif
			(yyval.node) = new CopyNamespacesDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 51:
#line 1241 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]" << endl;
#endif
			(yyval.node) = new CopyNamespacesDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 52:
#line 1263 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultCollationMode [ ]" << endl;
#endif
			(yyval.node) = new DefaultCollationDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 53:
#line 1277 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BaseURIDecl [ ]" << endl;
#endif
			(yyval.node) = new BaseURIDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 54:
#line 1291 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [uri]" << endl;
#endif
			(yyval.node) = new SchemaImport(driver.createQueryLoc((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 55:
#line 1301 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [prefix.uri]" << endl;
#endif
			(yyval.node) = new SchemaImport(driver.createQueryLoc((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(3) - (2)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 56:
#line 1311 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [uri.urilist]" << endl;
#endif
			(yyval.node) = new SchemaImport(driver.createQueryLoc((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 57:
#line 1321 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [prefix.uri.aturi]" << endl;
#endif
			(yyval.node) = new SchemaImport(driver.createQueryLoc((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(5) - (2)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 58:
#line 1337 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "URILiteralList [single]" << endl;
#endif
			URILiteralList* uri_list_p = new URILiteralList(driver.createQueryLoc((yyloc)));
			uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 59:
#line 1346 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "URILiteralList [list]" << endl;
#endif
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 60:
#line 1364 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [namespace]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1371 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [default element]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(driver.createQueryLoc((yyloc)), true);
		;}
    break;

  case 62:
#line 1384 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [uri]" << endl;
#endif
			(yyval.node) = new ModuleImport(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 63:
#line 1393 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [namespace.uri]" << endl;
#endif
			(yyval.node) = new ModuleImport(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)),
								NULL);
		;}
    break;

  case 64:
#line 1403 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [uri.at_uri.list]" << endl;
#endif
			(yyval.node) = new ModuleImport(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 65:
#line 1412 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [namespace.uri.at_uri.list]" << endl;
#endif
			(yyval.node) = new ModuleImport(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (5)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(7) - (7)].node)));
		;}
    break;

  case 66:
#line 1429 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [expr]" << endl;
#endif
			(yyval.node) = new VarDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 67:
#line 1439 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [external]" << endl;
#endif
			(yyval.node) = new VarDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								NULL,
								NULL);
		;}
    break;

  case 68:
#line 1449 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [type.expr]" << endl;
#endif
			(yyval.node) = new VarDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 69:
#line 1459 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [type.external]" << endl;
#endif
			(yyval.node) = new VarDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (3)].node)),
								NULL);
		;}
    break;

  case 70:
#line 1475 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [preserve]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 71:
#line 1483 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [strip]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 72:
#line 1497 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,NULL,
								ParseConstants::fn_extern);
		;}
    break;

  case 73:
#line 1507 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(5) - (5)].expr)),
								ParseConstants::fn_read);
		;}
    break;

  case 74:
#line 1518 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,NULL,
								ParseConstants::fn_extern);
		;}
    break;

  case 75:
#line 1529 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(6) - (6)].expr)),
								ParseConstants::fn_read);
		;}
    break;

  case 76:
#line 1541 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [as_type.external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)),
								NULL,
								ParseConstants::fn_extern);
		;}
    break;

  case 77:
#line 1553 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [as_type.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(6) - (6)].expr)),
								ParseConstants::fn_read);
		;}
    break;

  case 78:
#line 1565 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.as_type.external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(7) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								NULL,
								ParseConstants::fn_extern);
		;}
    break;

  case 79:
#line 1577 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.as_type.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(7) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(7) - (7)].expr)),
								ParseConstants::fn_read);
		;}
    break;

  case 80:
#line 1589 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,NULL,
								ParseConstants::fn_extern_update);
		;}
    break;

  case 81:
#line 1599 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(5) - (5)].expr)),
								ParseConstants::fn_update);
		;}
    break;

  case 82:
#line 1610 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,NULL,
								ParseConstants::fn_extern_update);
		;}
    break;

  case 83:
#line 1621 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(6) - (6)].expr)),
								ParseConstants::fn_update);
		;}
    break;

  case 84:
#line 1633 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) as_type.external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)),
								NULL,
								ParseConstants::fn_extern_update);
		;}
    break;

  case 85:
#line 1645 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) as_type.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(6) - (6)].expr)),
								ParseConstants::fn_update);
		;}
    break;

  case 86:
#line 1657 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.as_type.external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(7) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								NULL,
								ParseConstants::fn_extern_update);
		;}
    break;

  case 87:
#line 1669 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.as_type.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(7) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(7) - (7)].expr)),
								ParseConstants::fn_update);
		;}
    break;

  case 88:
#line 1687 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParamList [single]" << endl;
#endif
			ParamList* plist_p = new ParamList(driver.createQueryLoc((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 89:
#line 1698 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParamList [list]" << endl;
#endif
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 90:
#line 1715 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Param [varname]" << endl;
#endif
			(yyval.node) = new Param(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 91:
#line 1724 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Param [varname.type]" << endl;
#endif
			(yyval.node) = new Param(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 92:
#line 1739 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EnclosedExpr [ ]" << endl;
#endif
			(yyval.expr) = new EnclosedExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1753 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QueryBody [expr]" << endl;
#endif
			(yyval.expr) = new QueryBody(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 94:
#line 1767 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Expr [single]" << endl;
#endif
			Expr* expr_p = new Expr(driver.createQueryLoc((yyloc)));
			expr_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 95:
#line 1776 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Expr [expr.single]" << endl;
#endif
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p) expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
		;}
    break;

  case 96:
#line 1791 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [FLWORExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 97:
#line 1798 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [QuantifiedExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1805 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TypeswitchExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1812 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [IfExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1819 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [OrExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1828 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [InsertExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1835 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [DeleteExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1842 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [RenameExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1849 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [ReplaceExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1856 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TransformExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1869 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [return]" << endl;
#endif
			(yyval.expr) = new FLWORExpr(driver.createQueryLoc((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 107:
#line 1879 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [where.return]" << endl;
#endif
			(yyval.expr) = new FLWORExpr(driver.createQueryLoc((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 108:
#line 1890 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [orderby.return]" << endl;
#endif
			(yyval.expr) = new FLWORExpr(driver.createQueryLoc((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								NULL,
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 109:
#line 1901 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [where.orderby.return]" << endl;
#endif
			(yyval.expr) = new FLWORExpr(driver.createQueryLoc((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(5) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 110:
#line 1918 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClauseList [single]" << endl;
#endif
			ForLetClauseList* flc_list_p = new ForLetClauseList(driver.createQueryLoc((yyloc)));
			flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = flc_list_p;
		;}
    break;

  case 111:
#line 1927 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClauseList [list]" << endl;
#endif
			ForLetClauseList* flc_list_p = dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(2) - (1)].node));
			if (flc_list_p) flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 112:
#line 1942 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [for]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 113:
#line 1949 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [let]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 114:
#line 1962 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForClause [ ]" << endl;
#endif
			(yyval.node) = new ForClause(driver.createQueryLoc((yyloc)),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 115:
#line 1976 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDeclList [single]" << endl;
#endif
			VarInDeclList* vardecl_list_p = new VarInDeclList(driver.createQueryLoc((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 116:
#line 1985 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDeclList [list]" << endl;
#endif
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 117:
#line 2002 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [in]" << endl;
#endif
			(yyval.node) = new VarInDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 118:
#line 2012 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 119:
#line 2023 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [posvar.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 120:
#line 2035 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.posvar.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 121:
#line 2048 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [scorevar.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 122:
#line 2059 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.scorevar.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 123:
#line 2071 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [posvar.scorevar.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 124:
#line 2083 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.posvar.scorevar.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 125:
#line 2101 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PositionalVar [ ]" << endl;
#endif
			(yyval.node) = new PositionalVar(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 126:
#line 2116 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTScoreVar [ ]" << endl;
#endif
			(yyval.node) = new FTScoreVar(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 127:
#line 2130 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClause [ ]" << endl;
#endif
			(yyval.node) = new LetClause(driver.createQueryLoc((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)));
			
		;}
    break;

  case 128:
#line 2145 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDeclList [single]" << endl;
#endif
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(driver.createQueryLoc((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 129:
#line 2154 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDeclList [list.single]" << endl;
#endif
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 130:
#line 2171 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [gets]" << endl;
#endif
			(yyval.node) = new VarGetsDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 131:
#line 2182 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [type.gets]" << endl;
#endif
			(yyval.node) = new VarGetsDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 132:
#line 2194 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [scorevar.gets]" << endl;
#endif
			(yyval.node) = new VarGetsDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 133:
#line 2205 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [type.scorevar.gets]" << endl;
#endif
			(yyval.node) = new VarGetsDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 134:
#line 2223 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "WhereClause [ ]" << endl;
#endif
			(yyval.node) = new WhereClause(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 135:
#line 2237 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [ ]" << endl;
#endif
			(yyval.node) = new OrderByClause(driver.createQueryLoc((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 136:
#line 2245 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [stable]" << endl;
#endif
			(yyval.node) = new OrderByClause(driver.createQueryLoc((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)),
								true);
		;}
    break;

  case 137:
#line 2260 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpecList [single]" << endl;
#endif
			OrderSpecList* osl_p = new OrderSpecList(driver.createQueryLoc((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 138:
#line 2269 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpecList [list]" << endl;
#endif
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 139:
#line 2286 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpec [single]" << endl;
#endif
			(yyval.node) = new OrderSpec(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 140:
#line 2295 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpec [single.modifier]" << endl;
#endif
			(yyval.node) = new OrderSpec(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 141:
#line 2310 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir]" << endl;
#endif
			(yyval.node) = new OrderModifier(driver.createQueryLoc((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 142:
#line 2320 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [empty]" << endl;
#endif
			(yyval.node) = new OrderModifier(driver.createQueryLoc((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 143:
#line 2330 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [collation]" << endl;
#endif
			(yyval.node) = new OrderModifier(driver.createQueryLoc((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 144:
#line 2340 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir.empty]" << endl;
#endif
			(yyval.node) = new OrderModifier(driver.createQueryLoc((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 145:
#line 2350 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir.collation]" << endl;
#endif
			(yyval.node) = new OrderModifier(driver.createQueryLoc((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 146:
#line 2360 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [empty.collation]" << endl;
#endif
			(yyval.node) = new OrderModifier(driver.createQueryLoc((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 147:
#line 2370 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir.empty.collation]" << endl;
#endif
			(yyval.node) = new OrderModifier(driver.createQueryLoc((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 148:
#line 2386 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [ascending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(driver.createQueryLoc((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 149:
#line 2393 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [descending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(driver.createQueryLoc((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 150:
#line 2406 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [greatest]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(driver.createQueryLoc((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 151:
#line 2414 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [least]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(driver.createQueryLoc((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 152:
#line 2428 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderCollationSpec [ ]" << endl;
#endif
			(yyval.node) = new OrderCollationSpec(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 153:
#line 2442 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuantifiedExpr [some]" << endl;
#endif
			(yyval.expr) = new QuantifiedExpr(driver.createQueryLoc((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 154:
#line 2452 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuantifiedExpr [every]" << endl;
#endif
			(yyval.expr) = new QuantifiedExpr(driver.createQueryLoc((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 155:
#line 2468 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDeclList [single]" << endl;
#endif
			QVarInDeclList* qvid_list_p = new QVarInDeclList(driver.createQueryLoc((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 156:
#line 2478 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDeclList [list]" << endl;
#endif
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 157:
#line 2493 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDecl [in]" << endl;
#endif
			(yyval.node) = new QVarInDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 158:
#line 2502 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDecl [type.in]" << endl;
#endif
			(yyval.node) = new QVarInDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 159:
#line 2518 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeswitchExpr [cases.default.return]" << endl;
#endif
			(yyval.expr) = new TypeswitchExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(7) - (2)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(7) - (4)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 160:
#line 2528 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeswitchExpr [cases.default.varname.return]" << endl;
#endif
			(yyval.expr) = new TypeswitchExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(9) - (2)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(9) - (4)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval)),
								(yysemantic_stack_[(9) - (9)].expr));
		;}
    break;

  case 161:
#line 2545 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClauseList [single]" << endl;
#endif
			CaseClauseList* cc_list_p = new CaseClauseList(driver.createQueryLoc((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 162:
#line 2554 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClauseList [list]" << endl;
#endif
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 163:
#line 2569 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClause [case.return]" << endl;
#endif
			(yyval.node) = new CaseClause(driver.createQueryLoc((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 164:
#line 2578 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClause [case.as.return]" << endl;
#endif
			(yyval.node) = new CaseClause(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 165:
#line 2594 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IfExpr [ ]" << endl;
#endif
			(yyval.expr) = new IfExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 166:
#line 2608 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [and]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 167:
#line 2615 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [or.and]" << endl;
#endif
			(yyval.expr) = new OrExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 168:
#line 2629 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [comp]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 169:
#line 2636 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [and.comp]" << endl;
#endif
			(yyval.expr) = new AndExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 170:
#line 2658 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 171:
#line 2665 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains.valcomp.ftcontains]" << endl;
#endif
			(yyval.expr) = new ComparisonExpr(driver.createQueryLoc((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 172:
#line 2676 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains.gencomp.ftcontains]" << endl;
#endif
			(yyval.expr) = new ComparisonExpr(driver.createQueryLoc((yyloc)),
								dynamic_cast<GeneralComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 173:
#line 2687 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "is" | "<<" | ">>" */
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains.nodecomp.ftcontains]" << endl;
#endif
			(yyval.expr) = new ComparisonExpr(driver.createQueryLoc((yyloc)),
								dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 174:
#line 2704 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 175:
#line 2711 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range.ftselect]" << endl;
#endif
			(yyval.expr) = new FTContainsExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 176:
#line 2721 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range.ftselect.ftignore]" << endl;
#endif
			(yyval.expr) = new FTContainsExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 177:
#line 2737 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 178:
#line 2744 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add.to.add]" << endl;
#endif
			(yyval.expr) = new RangeExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 179:
#line 2758 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 180:
#line 2765 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult+mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 181:
#line 2772 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult-mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 182:
#line 2785 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [union]" << endl;
#endif
		;}
    break;

  case 183:
#line 2791 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult*union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 184:
#line 2798 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.div.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 185:
#line 2805 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.idiv.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 186:
#line 2812 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.mod.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 187:
#line 2825 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [interexcept]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 188:
#line 2832 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union.union.interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 189:
#line 2840 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union|interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 190:
#line 2854 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [instanceof]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 191:
#line 2861 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.inter.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 192:
#line 2868 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.except.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 193:
#line 2881 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 194:
#line 2888 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat.seqtype]" << endl;
#endif
			(yyval.expr) = new InstanceofExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 195:
#line 2903 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 196:
#line 2910 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable.seqtype]" << endl;
#endif
			(yyval.expr) = new TreatExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 197:
#line 2925 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 198:
#line 2932 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast.singletype]" << endl;
#endif
			(yyval.expr) = new CastableExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 199:
#line 2947 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 200:
#line 2954 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary.singletype]" << endl;
#endif
			(yyval.expr) = new CastExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 201:
#line 2969 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [value]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 202:
#line 2976 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [signlist.value]" << endl;
#endif
			(yyval.expr) = new UnaryExpr(driver.createQueryLoc((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 203:
#line 2991 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [+]" << endl;
#endif
			(yyval.node) = new SignList(driver.createQueryLoc((yyloc)), true);
		;}
    break;

  case 204:
#line 2998 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [-]" << endl;
#endif
			(yyval.node) = new SignList(driver.createQueryLoc((yyloc)), false);
		;}
    break;

  case 205:
#line 3005 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.+]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 206:
#line 3012 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.-]" << endl;
#endif
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 207:
#line 3027 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [validate]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 208:
#line 3034 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [path]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 209:
#line 3041 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [extension]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 210:
#line 3055 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [=]" << endl;
#endif
			(yyval.node) = new GeneralComp(driver.createQueryLoc((yyloc)), ParseConstants::op_eq);
		;}
    break;

  case 211:
#line 3062 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [!=]" << endl;
#endif
			(yyval.node) = new GeneralComp(driver.createQueryLoc((yyloc)), ParseConstants::op_ne);
		;}
    break;

  case 212:
#line 3069 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<]" << endl;
#endif
			(yyval.node) = new GeneralComp(driver.createQueryLoc((yyloc)), ParseConstants::op_lt);
		;}
    break;

  case 213:
#line 3076 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<=]" << endl;
#endif
			(yyval.node) = new GeneralComp(driver.createQueryLoc((yyloc)), ParseConstants::op_le);
		;}
    break;

  case 214:
#line 3083 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>]" << endl;
#endif
			(yyval.node) = new GeneralComp(driver.createQueryLoc((yyloc)), ParseConstants::op_gt);
		;}
    break;

  case 215:
#line 3090 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>=]" << endl;
#endif
			(yyval.node) = new GeneralComp(driver.createQueryLoc((yyloc)), ParseConstants::op_ge);
		;}
    break;

  case 216:
#line 3103 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [eq]" << endl;
#endif
			(yyval.node) = new ValueComp(driver.createQueryLoc((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 217:
#line 3110 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ne]" << endl;
#endif
			(yyval.node) = new ValueComp(driver.createQueryLoc((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 218:
#line 3117 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [lt]" << endl;
#endif
			(yyval.node) = new ValueComp(driver.createQueryLoc((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 219:
#line 3124 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [le]" << endl;
#endif
			(yyval.node) = new ValueComp(driver.createQueryLoc((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 220:
#line 3131 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [gt]" << endl;
#endif
			(yyval.node) = new ValueComp(driver.createQueryLoc((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 221:
#line 3138 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ge]" << endl;
#endif
			(yyval.node) = new ValueComp(driver.createQueryLoc((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 222:
#line 3151 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [is]" << endl;
#endif
			(yyval.node) = new NodeComp(driver.createQueryLoc((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 223:
#line 3158 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [<<]" << endl;
#endif
			(yyval.node) = new NodeComp(driver.createQueryLoc((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 224:
#line 3165 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [>>]" << endl;
#endif
			(yyval.node) = new NodeComp(driver.createQueryLoc((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 225:
#line 3179 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [expr]" << endl;
#endif
			(yyval.expr) = new ValidateExpr(driver.createQueryLoc((yyloc)), "strict", (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 226:
#line 3186 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [mode.expr]" << endl;
#endif
			(yyval.expr) = new ValidateExpr(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 227:
#line 3201 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExtensionExpr [pragmalist]" << endl;
#endif
			(yyval.expr) = new ExtensionExpr(driver.createQueryLoc((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 228:
#line 3210 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExtensionExpr [pragmalist.expr]" << endl;
#endif
			(yyval.expr) = new ExtensionExpr(driver.createQueryLoc((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 229:
#line 3225 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PragmaList [single]" << endl;
#endif
			PragmaList* pragma_list_p = new PragmaList(driver.createQueryLoc((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 230:
#line 3234 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PragmaList [list]" << endl;
#endif
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 231:
#line 3251 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Pragma [ ]" << endl;
#endif
			(yyval.node) = new Pragma(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 232:
#line 3259 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 233:
#line 3302 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/]" << endl;
#endif
			(yyval.expr) = new PathExpr(driver.createQueryLoc((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 234:
#line 3309 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(driver.createQueryLoc((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 235:
#line 3316 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [//relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(driver.createQueryLoc((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 236:
#line 3323 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [relative]" << endl;
#endif
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = rpe == NULL ? (yysemantic_stack_[(1) - (1)].expr) : new PathExpr(driver.createQueryLoc((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 237:
#line 3337 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step]" << endl;
#endif
            AxisStep *as = dynamic_cast<AxisStep *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = as != NULL ? new RelativePathExpr(driver.createQueryLoc((yyloc)), ParseConstants::st_slash, new ContextItemExpr(driver.createQueryLoc((yyloc))), (yysemantic_stack_[(1) - (1)].expr)) : (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 238:
#line 3345 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step/relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(driver.createQueryLoc((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 239:
#line 3352 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step//relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(driver.createQueryLoc((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 240:
#line 3365 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [axis]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 241:
#line 3372 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [filter]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 242:
#line 3385 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward]" << endl;
#endif
			(yyval.expr) = new AxisStep(driver.createQueryLoc((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 243:
#line 3394 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward.predlist]" << endl;
#endif
			(yyval.expr) = new AxisStep(driver.createQueryLoc((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 244:
#line 3403 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse]" << endl;
#endif
			(yyval.expr) = new AxisStep(driver.createQueryLoc((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 245:
#line 3412 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse.predlist]" << endl;
#endif
			(yyval.expr) = new AxisStep(driver.createQueryLoc((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 246:
#line 3427 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [nodetest]" << endl;
#endif
			(yyval.node) = new ForwardStep(driver.createQueryLoc((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 247:
#line 3436 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [abbrev]" << endl;
#endif
			(yyval.node) = new ForwardStep(driver.createQueryLoc((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 248:
#line 3450 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [child]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 249:
#line 3457 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 250:
#line 3464 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [attribute]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 251:
#line 3471 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 252:
#line 3478 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant_or_self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 253:
#line 3485 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following_sibling]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 254:
#line 3492 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 255:
#line 3505 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(driver.createQueryLoc((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 256:
#line 3512 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [@ nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(driver.createQueryLoc((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 257:
#line 3525 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [nodetest]" << endl;
#endif
			(yyval.node) = new ReverseStep(driver.createQueryLoc((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 258:
#line 3534 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [..]" << endl;
#endif
			ReverseAxis* rev_p = new ReverseAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(driver.createQueryLoc((yyloc)),
								rev_p);
		;}
    break;

  case 259:
#line 3549 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [parent]" << endl;
#endif
			(yyval.node) = new ReverseAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 260:
#line 3556 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor]" << endl;
#endif
			(yyval.node) = new ReverseAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 261:
#line 3563 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding_sibling]" << endl;
#endif
			(yyval.node) = new ReverseAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 262:
#line 3570 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding]" << endl;
#endif
			(yyval.node) = new ReverseAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 263:
#line 3577 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor_or_self]" << endl;
#endif
			(yyval.node) = new ReverseAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 264:
#line 3595 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [kindtest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 265:
#line 3602 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [nametest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 266:
#line 3615 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [qname]" << endl;
#endif
			(yyval.node) = new NameTest(driver.createQueryLoc((yyloc)), new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 267:
#line 3622 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [wildcard]" << endl;
#endif
			(yyval.node) = new NameTest(driver.createQueryLoc((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 268:
#line 3635 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Wildcard [*]" << endl;
#endif
			(yyval.node) = new Wildcard(driver.createQueryLoc((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 269:
#line 3645 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Wildcard [pref:*]" << endl;
#endif
			(yyval.node) = new Wildcard(driver.createQueryLoc((yyloc)),
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 270:
#line 3655 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Wildcard [*:qname]" << endl;
#endif
			(yyval.node) = new Wildcard(driver.createQueryLoc((yyloc)),
                        "",
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 271:
#line 3671 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 272:
#line 3678 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary.predlist]" << endl;
#endif
			(yyval.expr) = new FilterExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 273:
#line 3693 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PredicateList [single]" << endl;
#endif
			PredicateList* pred_list_p = new PredicateList(driver.createQueryLoc((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 274:
#line 3702 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PredicateList [list]" << endl;
#endif
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 275:
#line 3719 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Predicate [ ]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 276:
#line 3733 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [literal]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 277:
#line 3740 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [varref]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 278:
#line 3747 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [paren]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 279:
#line 3754 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [context_item]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 280:
#line 3761 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [funcall]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 281:
#line 3768 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [cons]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 282:
#line 3775 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [ordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 283:
#line 3782 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [unordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 284:
#line 3795 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [numeric]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 285:
#line 3802 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [string]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 286:
#line 3815 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [decimal]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(driver.createQueryLoc((yyloc)), *yylval.decval);
      delete yylval.decval;
		;}
    break;

  case 287:
#line 3823 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [int]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(driver.createQueryLoc((yyloc)), *yylval.ival);
      delete yylval.ival;
		;}
    break;

  case 288:
#line 3831 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [double]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(driver.createQueryLoc((yyloc)), *yylval.dval);
      delete yylval.dval;
		;}
    break;

  case 289:
#line 3845 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarRef [ ]" << endl;
#endif
			(yyval.expr) = new VarRef(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 290:
#line 3858 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [()]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(driver.createQueryLoc((yyloc)), NULL);
		;}
    break;

  case 291:
#line 3865 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [(expr)]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 292:
#line 3879 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ContextItemExpr [.]" << endl;
#endif
			(yyval.expr) = new ContextItemExpr(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 293:
#line 3892 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new OrderedExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 294:
#line 3906 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnorderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new UnorderedExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 295:
#line 3965 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [ ]" << endl;
#endif
			(yyval.expr) = new FunctionCall(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 296:
#line 3974 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [arglist]" << endl;
#endif
			(yyval.expr) = new FunctionCall(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 297:
#line 3989 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [single]" << endl;
#endif
			ArgList* a_list_p = new ArgList(driver.createQueryLoc((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 298:
#line 3998 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [list]" << endl;
#endif
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 299:
#line 4013 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [direct]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 300:
#line 4020 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [computed]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 301:
#line 4033 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [element]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 4040 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 303:
#line 4047 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 304:
#line 4060 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname/> ]" << endl;
#endif
			(yyval.expr) = new DirElemConstructor(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 305:
#line 4071 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname attrlist/> ]" << endl;
#endif
			(yyval.expr) = new DirElemConstructor(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(4) - (3)].node)), 
								NULL);
		;}
    break;

  case 306:
#line 4082 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname></qname>]" << endl;
#endif
			(yyval.expr) = new DirElemConstructor(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (5)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 307:
#line 4093 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname>content</qname>]" << endl;
#endif
			(yyval.expr) = new DirElemConstructor(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (6)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(7) - (4)].node)));
		;}
    break;

  case 308:
#line 4104 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname attrlist></qname>]" << endl;
#endif
			(yyval.expr) = new DirElemConstructor(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (6)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(7) - (3)].node)),
								NULL);
		;}
    break;

  case 309:
#line 4115 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname attrlist>content</qname>]" << endl;
#endif
			(yyval.expr) = new DirElemConstructor(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(8) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(8) - (5)].node)));
		;}
    break;

  case 310:
#line 4133 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [single]" << endl;
#endif
			DirElemContentList* elem_content_list_p = new DirElemContentList(driver.createQueryLoc((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 311:
#line 4142 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [list]" << endl;
#endif
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 312:
#line 4157 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeList [single]" << endl;
#endif
			DirAttributeList* at_list_p = new DirAttributeList(driver.createQueryLoc((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 313:
#line 4166 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeList [list]" << endl;
#endif
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 314:
#line 4183 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttr [ ]" << endl;
#endif
			(yyval.node) = new DirAttr(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 315:
#line 4198 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [quote]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(driver.createQueryLoc((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 316:
#line 4206 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [apos]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(driver.createQueryLoc((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 317:
#line 4220 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList[empty]" << endl;
#endif
			(yyval.node) = new QuoteAttrContentList(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 318:
#line 4227 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 319:
#line 4234 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [""]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(driver.createQueryLoc((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(driver.createQueryLoc((yyloc)),string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 320:
#line 4243 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [single]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(driver.createQueryLoc((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 321:
#line 4252 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [list ""]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(driver.createQueryLoc((yyloc)),string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 322:
#line 4263 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [list]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
		;}
    break;

  case 323:
#line 4279 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']" << endl;
#endif
			(yyval.node) = new AposAttrContentList(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 324:
#line 4286 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 325:
#line 4293 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']" << endl;
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList(driver.createQueryLoc((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(driver.createQueryLoc((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 326:
#line 4302 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [single]" << endl;
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList(driver.createQueryLoc((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 327:
#line 4311 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [list.'']" << endl;
#endif
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(driver.createQueryLoc((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 328:
#line 4322 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [list.single]" << endl;
#endif
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 329:
#line 4339 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [quote_attr_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 330:
#line 4347 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(driver.createQueryLoc((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 331:
#line 4361 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [apos_attr_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 332:
#line 4369 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(driver.createQueryLoc((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 333:
#line 4383 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cons]" << endl;
#endif
			(yyval.expr) = new DirElemContent(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 334:
#line 4391 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [elem_content]" << endl;
#endif
			(yyval.expr) = new DirElemContent(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 335:
#line 4399 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cdata]" << endl;
#endif
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(driver.createQueryLoc((yyloc)),
								cdata_h);
		;}
    break;

  case 336:
#line 4408 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [common_content]" << endl;
#endif
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(driver.createQueryLoc((yyloc)),
								cont_h);
		;}
    break;

  case 337:
#line 4423 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [entity_ref]" << endl;
#endif
			(yyval.expr) = new CommonContent(driver.createQueryLoc((yyloc)),
								ParseConstants::cont_entity,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 338:
#line 4432 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [{{]" << endl;
#endif
			(yyval.expr) = new CommonContent(driver.createQueryLoc((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 339:
#line 4440 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [}}]" << endl;
#endif
			(yyval.expr) = new CommonContent(driver.createQueryLoc((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 340:
#line 4448 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [expr]" << endl;
#endif
			(yyval.expr) = new CommonContent(driver.createQueryLoc((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 341:
#line 4462 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirCommentConstructor [ ]" << endl;
#endif
			(yyval.expr) = new DirCommentConstructor(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 342:
#line 4470 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "DirCommentConstructor [ ]" << endl;
#endif
      (yyval.expr) = new DirCommentConstructor(driver.createQueryLoc((yyloc)), "");
    ;}
    break;

  case 343:
#line 4488 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new DirPIConstructor(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 344:
#line 4496 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target.charlit]" << endl;
#endif
			(yyval.expr) = new DirPIConstructor(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 345:
#line 4516 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CDataSection [ ]" << endl;
#endif
			(yyval.expr) = new CDataSection(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 346:
#line 4534 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [doc]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 347:
#line 4541 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [elem]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 348:
#line 4548 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [attr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 349:
#line 4555 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [text]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 350:
#line 4562 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 351:
#line 4569 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 352:
#line 4582 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompDocConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompDocConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 353:
#line 4596 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 354:
#line 4605 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 355:
#line 4614 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 356:
#line 4622 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name.content]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 357:
#line 4650 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 358:
#line 4659 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [val]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 359:
#line 4668 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 360:
#line 4676 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name.val]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 361:
#line 4690 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompTextConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompTextConstructor(driver.createQueryLoc((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 362:
#line 4704 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompCommentConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompCommentConstructor(driver.createQueryLoc((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 363:
#line 4718 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 364:
#line 4727 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 365:
#line 4736 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 366:
#line 4744 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target.content]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 367:
#line 4758 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic]" << endl;
#endif
			(yyval.node) = new SingleType(driver.createQueryLoc((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 368:
#line 4767 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic ?]" << endl;
#endif
			(yyval.node) = new SingleType(driver.createQueryLoc((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 369:
#line 4782 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeDeclaration [as seqtype]" << endl;
#endif
			(yyval.node) = new TypeDeclaration(driver.createQueryLoc((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 370:
#line 4796 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type]" << endl;
#endif
			(yyval.node) = new SequenceType(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 371:
#line 4805 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type.occurs]" << endl;
#endif
			(yyval.node) = new SequenceType(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 372:
#line 4814 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [void]" << endl;
#endif
			(yyval.node) = new SequenceType(driver.createQueryLoc((yyloc)), NULL, NULL);
		;}
    break;

  case 373:
#line 4854 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [?]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(driver.createQueryLoc((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 374:
#line 4862 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [*]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(driver.createQueryLoc((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 375:
#line 4870 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [+]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(driver.createQueryLoc((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 376:
#line 4884 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [atomic]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 377:
#line 4891 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [kind]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 378:
#line 4898 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [item]" << endl;
#endif
			(yyval.node) = new ItemType(driver.createQueryLoc((yyloc)),true);
		;}
    break;

  case 379:
#line 4911 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AtomicType [qname]" << endl;
#endif
			(yyval.node) = new AtomicType(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 380:
#line 4925 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [doc]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 381:
#line 4932 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 382:
#line 4939 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 383:
#line 4946 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 384:
#line 4953 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 385:
#line 4960 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [pi]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 386:
#line 4967 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [comment]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 387:
#line 4974 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [text]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 388:
#line 4981 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [any]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 389:
#line 4994 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AnyKindTest [ ]" << endl;
#endif
			(yyval.node) = new AnyKindTest(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 390:
#line 5007 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [ ]" << endl;
#endif
			(yyval.node) = new DocumentTest(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 391:
#line 5014 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(driver.createQueryLoc((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 392:
#line 5022 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [schema_elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(driver.createQueryLoc((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 393:
#line 5036 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TextTest [ ]" << endl;
#endif
			(yyval.node) = new TextTest(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 394:
#line 5049 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommentTest [ ]" << endl;
#endif
			(yyval.node) = new CommentTest(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 395:
#line 5062 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ ]" << endl;
#endif
			(yyval.node) = new PITest(driver.createQueryLoc((yyloc)), "");
		;}
    break;

  case 396:
#line 5069 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ncname]" << endl;
#endif
			(yyval.node) = new PITest(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 397:
#line 5076 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [stringlit]" << endl;
#endif
			(yyval.node) = new PITest(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 398:
#line 5089 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [ ]" << endl;
#endif
			(yyval.node) = new AttributeTest(driver.createQueryLoc((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 399:
#line 5098 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name]" << endl;
#endif
			(yyval.node) = new AttributeTest(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL);
		;}
    break;

  case 400:
#line 5107 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name.type]" << endl;
#endif
			(yyval.node) = new AttributeTest(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 401:
#line 5116 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*]" << endl;
#endif
			(yyval.node) = new AttributeTest(driver.createQueryLoc((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 402:
#line 5125 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*.type]" << endl;
#endif
			(yyval.node) = new AttributeTest(driver.createQueryLoc((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 403:
#line 5140 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaAttributeTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaAttributeTest(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 404:
#line 5154 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [ ]" << endl;
#endif
			(yyval.node) = new ElementTest(driver.createQueryLoc((yyloc)),
									NULL,
									NULL);
		;}
    break;

  case 405:
#line 5163 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name]" << endl;
#endif
			(yyval.node) = new ElementTest(driver.createQueryLoc((yyloc)),
									new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
									NULL);
		;}
    break;

  case 406:
#line 5172 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name.type]" << endl;
#endif
			(yyval.node) = new ElementTest(driver.createQueryLoc((yyloc)),
									new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 407:
#line 5181 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name.type]" << endl;
#endif
			(yyval.node) = new ElementTest(driver.createQueryLoc((yyloc)),
									new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 408:
#line 5190 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [*]" << endl;
#endif
			(yyval.node) = new ElementTest(driver.createQueryLoc((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 409:
#line 5200 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [*.type]" << endl;
#endif
			(yyval.node) = new ElementTest(driver.createQueryLoc((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)),
									true);
		;}
    break;

  case 410:
#line 5210 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [*.type]" << endl;
#endif
			(yyval.node) = new ElementTest(driver.createQueryLoc((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)),
									true);
		;}
    break;

  case 411:
#line 5226 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaElementTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaElementTest(driver.createQueryLoc((yyloc)),
									new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 412:
#line 5250 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name]" << endl;
#endif
			(yyval.node) = new TypeName(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 413:
#line 5260 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name?]" << endl;
#endif
			(yyval.node) = new TypeName(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 414:
#line 5283 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StringLiteral [ ]" << endl;
#endif
			(yyval.expr) = new StringLiteral(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 415:
#line 5325 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [ ]" << endl;
#endif
		;}
    break;

  case 416:
#line 5337 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr]" << endl;
#endif
		;}
    break;

  case 417:
#line 5343 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.as_first]" << endl;
#endif
		;}
    break;

  case 418:
#line 5349 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.as_last]" << endl;
#endif
		;}
    break;

  case 419:
#line 5355 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.after]" << endl;
#endif
		;}
    break;

  case 420:
#line 5361 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.before]" << endl;
#endif
		;}
    break;

  case 421:
#line 5373 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteExpr [expr]" << endl;
#endif
		;}
    break;

  case 422:
#line 5385 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceExpr [expr.expr]" << endl;
#endif
		;}
    break;

  case 423:
#line 5391 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceExpr [value.expr]" << endl;
#endif
		;}
    break;

  case 424:
#line 5403 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RenameExpr [expr.expr]" << endl;
#endif
		;}
    break;

  case 425:
#line 5430 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TransformExpr [ ]" << endl;
#endif
		;}
    break;

  case 426:
#line 5442 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [single]" << endl;
#endif
		;}
    break;

  case 427:
#line 5448 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [list]" << endl;
#endif
		;}
    break;

  case 428:
#line 5468 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or]" << endl;
#endif
		;}
    break;

  case 429:
#line 5474 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity]" << endl;
#endif
		;}
    break;

  case 430:
#line 5480 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.weight_range]" << endl;
#endif
		;}
    break;

  case 431:
#line 5486 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity.weight_range]" << endl;
#endif
		;}
    break;

  case 432:
#line 5498 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_single]" << endl;
#endif
		;}
    break;

  case 433:
#line 5504 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_single]" << endl;
#endif
		;}
    break;

  case 434:
#line 5510 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_list]" << endl;
#endif
		;}
    break;

  case 435:
#line 5516 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_list]" << endl;
#endif
		;}
    break;

  case 436:
#line 5528 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [and]" << endl;
#endif
		;}
    break;

  case 437:
#line 5534 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [or.and]" << endl;
#endif
		;}
    break;

  case 438:
#line 5546 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [mild_not]" << endl;
#endif
		;}
    break;

  case 439:
#line 5552 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [and.mild_not]" << endl;
#endif
		;}
    break;

  case 440:
#line 5564 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [unary_not]" << endl;
#endif
		;}
    break;

  case 441:
#line 5570 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [mild_not.unary_not]" << endl;
#endif
		;}
    break;

  case 442:
#line 5582 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [words]" << endl;
#endif
		;}
    break;

  case 443:
#line 5588 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [not.words]" << endl;
#endif
		;}
    break;

  case 444:
#line 5600 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words]" << endl;
#endif
		;}
    break;

  case 445:
#line 5606 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words.times]" << endl;
#endif
		;}
    break;

  case 446:
#line 5612 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [selection]" << endl;
#endif
		;}
    break;

  case 447:
#line 5624 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value]" << endl;
#endif
		;}
    break;

  case 448:
#line 5630 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value.any_all_option]" << endl;
#endif
		;}
    break;

  case 449:
#line 5642 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [literal]" << endl;
#endif
		;}
    break;

  case 450:
#line 5648 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [expr]" << endl;
#endif
		;}
    break;

  case 451:
#line 5660 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [order]" << endl;
#endif
		;}
    break;

  case 452:
#line 5666 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [window]" << endl;
#endif
		;}
    break;

  case 453:
#line 5672 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [distance]" << endl;
#endif
		;}
    break;

  case 454:
#line 5678 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [scope]" << endl;
#endif
		;}
    break;

  case 455:
#line 5684 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [content]" << endl;
#endif
		;}
    break;

  case 456:
#line 5696 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOrderedIndicator [ ]" << endl;
#endif
		;}
    break;

  case 457:
#line 5708 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [case]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 458:
#line 5715 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [diacritics]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 459:
#line 5722 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 460:
#line 5729 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [thesaurus]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 461:
#line 5736 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stopword]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 462:
#line 5743 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [language]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 463:
#line 5750 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [wildcard]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 464:
#line 5763 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [lower]" << endl;
#endif
		;}
    break;

  case 465:
#line 5769 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [upper]" << endl;
#endif
		;}
    break;

  case 466:
#line 5775 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [sensitive]" << endl;
#endif
		;}
    break;

  case 467:
#line 5781 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [insensitive]" << endl;
#endif
		;}
    break;

  case 468:
#line 5793 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [with]" << endl;
#endif
		;}
    break;

  case 469:
#line 5799 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [without]" << endl;
#endif
		;}
    break;

  case 470:
#line 5805 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [sensitive]" << endl;
#endif
		;}
    break;

  case 471:
#line 5811 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [insensitive]" << endl;
#endif
		;}
    break;

  case 472:
#line 5823 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [with]" << endl;
#endif
		;}
    break;

  case 473:
#line 5829 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [without]" << endl;
#endif
		;}
    break;

  case 474:
#line 5841 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [id]" << endl;
#endif
		;}
    break;

  case 475:
#line 5847 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [default]" << endl;
#endif
		;}
    break;

  case 476:
#line 5853 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id)]" << endl;
#endif
		;}
    break;

  case 477:
#line 5859 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id,id,..)]" << endl;
#endif
		;}
    break;

  case 478:
#line 5865 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default)]" << endl;
#endif
		;}
    break;

  case 479:
#line 5871 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default,id,id,..)]" << endl;
#endif
		;}
    break;

  case 480:
#line 5877 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [without]" << endl;
#endif
		;}
    break;

  case 481:
#line 5889 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [single]" << endl;
#endif
		;}
    break;

  case 482:
#line 5895 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [list]" << endl;
#endif
		;}
    break;

  case 483:
#line 5907 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name]" << endl;
#endif
		;}
    break;

  case 484:
#line 5913 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel]" << endl;
#endif
		;}
    break;

  case 485:
#line 5919 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.range]" << endl;
#endif
		;}
    break;

  case 486:
#line 5925 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel.range]" << endl;
#endif
		;}
    break;

  case 487:
#line 5937 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list]" << endl;
#endif
		;}
    break;

  case 488:
#line 5943 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list.incl_excl]" << endl;
#endif
		;}
    break;

  case 489:
#line 5949 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default]" << endl;
#endif
		;}
    break;

  case 490:
#line 5955 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default.incl_excl]" << endl;
#endif
		;}
    break;

  case 491:
#line 5961 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [without]" << endl;
#endif
		;}
    break;

  case 492:
#line 5973 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 493:
#line 5979 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 494:
#line 5991 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [.]" << endl;
#endif
		;}
    break;

  case 495:
#line 5997 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [(*)]" << endl;
#endif
		;}
    break;

  case 496:
#line 6009 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 497:
#line 6015 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 498:
#line 6027 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [union]" << endl;
#endif
		;}
    break;

  case 499:
#line 6033 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [except]" << endl;
#endif
		;}
    break;

  case 500:
#line 6045 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTLanguageOption [ ]" << endl;
#endif
		;}
    break;

  case 501:
#line 6057 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [with]" << endl;
#endif
		;}
    break;

  case 502:
#line 6063 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [without]" << endl;
#endif
		;}
    break;

  case 503:
#line 6075 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [start]" << endl;
#endif
		;}
    break;

  case 504:
#line 6081 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [end]" << endl;
#endif
		;}
    break;

  case 505:
#line 6087 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [entire]" << endl;
#endif
		;}
    break;

  case 506:
#line 6099 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any]" << endl;
#endif
		;}
    break;

  case 507:
#line 6105 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any_word]" << endl;
#endif
		;}
    break;

  case 508:
#line 6111 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all]" << endl;
#endif
		;}
    break;

  case 509:
#line 6117 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all_words]" << endl;
#endif
		;}
    break;

  case 510:
#line 6123 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [phrase]" << endl;
#endif
		;}
    break;

  case 511:
#line 6135 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [exactly]" << endl;
#endif
		;}
    break;

  case 512:
#line 6141 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_least]" << endl;
#endif
		;}
    break;

  case 513:
#line 6147 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_most]" << endl;
#endif
		;}
    break;

  case 514:
#line 6153 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [range]" << endl;
#endif
		;}
    break;

  case 515:
#line 6165 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDistance [ ]" << endl;
#endif
		;}
    break;

  case 516:
#line 6177 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWindow [ ]" << endl;
#endif
		;}
    break;

  case 517:
#line 6189 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [ ]" << endl;
#endif
		;}
    break;

  case 518:
#line 6201 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [same]" << endl;
#endif
		;}
    break;

  case 519:
#line 6207 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [different]" << endl;
#endif
		;}
    break;

  case 520:
#line 6219 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [words]" << endl;
#endif
		;}
    break;

  case 521:
#line 6225 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [sentences]" << endl;
#endif
		;}
    break;

  case 522:
#line 6231 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 523:
#line 6243 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [sentence]" << endl;
#endif
		;}
    break;

  case 524:
#line 6249 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 525:
#line 6261 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTIgnoreOption [ " << endl;
#endif
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6114 "/Users/mbrantner/misc/code/vanilla/datatypes/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -672;
  const short int
  xquery_parser::yypact_[] =
  {
       713,  1278,  1466,  -672,  -672,   -22,  -672,    27,  -672,  -672,
    -672,  2970,    18,   543,  -672,  2970,   146,  -672,   315,   -48,
     -16,   124,   352,   292,   327,   307,   339,   465,   466,   -67,
     470,   490,  -672,  -672,  2970,   285,   497,  -672,  -672,  -672,
    2970,    54,   506,  -672,  -672,   513,  2970,   110,    44,  -672,
     519,  1654,  -672,   534,   397,  2970,  -672,   541,    36,  -672,
     303,  -672,  -672,    30,   550,   552,  -672,  3494,   514,   506,
    -672,   558,  2970,   421,  2970,  2970,  2970,     5,   559,  -672,
    2970,  2970,  2970,  1089,   561,  3556,   602,   901,  -672,  -672,
     406,  2970,   439,   440,  -672,  -672,  -672,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,   566,  -672,  -672,   336,  -672,  -672,
    -672,  -672,  -672,  -672,   469,   576,  -672,  3674,   384,   -45,
     266,   121,   204,  -672,   505,   437,   577,   578,  3158,  -672,
    -672,  -672,   -30,  -672,  -672,  -672,   180,  -672,   504,   543,
    -672,   504,   543,  -672,  -672,  -672,  -672,   504,  -672,  -672,
    -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,  -672,  -672,    75,  -672,   104,  1842,
    2970,   111,     8,  -672,    78,  -672,  -672,   114,  -672,  -672,
    -672,  -672,  -672,  -672,   574,   575,  -672,   599,   603,  -672,
    -672,   508,   538,   607,  -672,  -672,   511,   282,   115,  -672,
     474,   475,  -672,   123,    79,  -672,    81,   219,     4,  -672,
       1,   588,  -672,    91,   604,   622,   605,   512,   626,   617,
     -13,   595,  -672,  -672,    95,   557,  -672,   182,    71,   488,
     492,  -672,   631,  -672,   537,  2970,   495,   498,  -672,  -672,
       7,    19,   208,  -672,    96,   233,   235,   463,  -672,   210,
    -672,    10,   628,  2970,   449,   562,   -70,  -672,  -672,  -672,
    -672,   640,  -672,  -672,  -672,  -672,  -672,  -672,  -672,   -17,
    -672,  -672,   241,    40,  -672,  -672,  -672,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,   406,    -3,
    2970,  2970,  2970,  2970,  2970,  -672,   151,   509,  3326,  3326,
    -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,  -672,  3326,  3326,  3326,    13,  3326,
    3326,  3326,  3326,  3326,  3326,  3326,  3326,  3326,  3326,  3326,
     283,   283,   649,   649,  -672,  -672,  -672,  2030,  -672,   514,
     514,  2970,   504,  -672,  -672,   504,  -672,   504,  -672,  -672,
    -672,  -672,    99,   238,   555,   651,  -672,   651,  -672,  -672,
     -32,   -20,  -672,  -672,   261,   647,  -672,   272,   283,  -672,
    2970,   329,  -672,  -672,  -672,   560,   654,  -672,   654,  -672,
    2970,   571,   609,  2970,   611,  2970,   615,   -76,   572,   -10,
     616,   516,   658,   606,   658,  -672,   610,   659,  2970,   597,
     -51,   620,  -672,   675,  -672,  -672,  -672,  -672,  -672,  -672,
    2218,   239,  -672,  -672,  2970,   612,  -672,    57,    29,  -672,
    -672,   661,  -672,  -672,  -672,   679,  -672,   160,  2970,  2970,
    2970,  2970,   491,  2970,  2970,   681,  2970,  -672,   241,   241,
     -17,  -672,   684,   685,   -17,   687,  -672,    51,  -672,   547,
    -672,  -672,  -672,   407,   666,  -672,  -672,   666,  -672,  2970,
     563,  2970,   576,  -672,  -672,  -672,  -672,  2970,    13,   318,
    -672,   464,  3453,   483,   481,  -672,  -672,   477,   200,   266,
     266,   157,   121,   121,   121,   121,   204,   204,  -672,  -672,
    -672,  -672,  -672,  -672,   316,  -672,  -672,  -672,  -672,   619,
    -672,  -672,   240,  -672,  -672,     9,  -672,  2970,  -672,  -672,
    2406,  -672,   564,   567,  -672,  -672,  -672,  -672,   701,     2,
     283,    66,  -672,  -672,    17,   283,    74,  -672,  -672,  -672,
    2970,  2594,   625,   570,   579,   580,   582,  -672,  2970,   506,
    -672,   704,  -672,   705,  2970,   627,  2970,  2970,   -54,   636,
     513,  2970,  -672,   697,   721,   697,  -672,   658,  -672,  2970,
    2970,   646,   519,   584,  -672,   244,   639,  -672,    72,  -672,
    -672,   747,  -672,  -672,  2970,   736,  -672,  -672,    77,  -672,
    -672,  -672,  -672,    97,  -672,   243,    62,  -672,   592,  2970,
    2970,  -672,  -672,  -672,  -672,  2970,  -672,  -672,   657,   623,
    -672,  -672,  -672,  -672,  -672,    22,   -17,   287,   100,   103,
      -3,  -672,   738,  -672,  -672,  -672,  -672,   227,   714,  -672,
    2970,  -672,  2970,  -672,   246,   633,  -672,  3326,  -672,  -672,
    -672,  -672,    65,   382,  -672,    13,    65,  3326,  3326,  3499,
    -672,  -672,  -672,  -672,  -672,  -672,  -672,    13,    13,   382,
    -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,  -672,  -672,   248,  -672,  -672,   749,
    -672,  -672,   195,   709,   328,   283,  -672,  -672,   381,   388,
     283,  -672,  -672,   251,  -672,  -672,  -672,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,  2970,  -672,  -672,  2970,   678,  2970,
    -672,   710,   772,   763,   697,  -672,  -672,  2970,  -672,  -672,
    -672,  2782,   271,   320,  -672,  -672,   252,   629,   779,  -672,
     780,   136,   775,   644,    -8,  -672,  -672,  -672,  -672,  -672,
    2970,  2970,  -672,  -672,  3326,  3326,  3326,  3326,   782,   585,
     769,  -672,   769,  -672,  -672,   714,  -672,  -672,  -672,  -672,
    -672,  -672,   121,  -672,  -672,  -672,   273,   483,  -672,  -672,
     334,  3326,  -672,  -672,   481,  -672,   565,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,   393,  -672,  -672,  -672,  -672,   394,
    -672,  -672,  -672,  2970,  -672,  2970,  -672,   658,  -672,  -672,
     253,  -672,  -672,   783,   359,  -672,  -672,  -672,  -672,   652,
     478,  -672,  -672,  -672,  -672,   638,   642,   797,   788,  2970,
     799,  2970,  -672,  -672,   121,   121,   121,   383,   382,  -672,
     105,  -672,   107,  -672,  -672,  -672,  -672,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,  -672,  -672,  -672,   697,  -672,  -672,
    -672,  -672,  -672,  -672,  -672,  -672,  -672,   653,   283,  -672,
     665,  -672,  3326,   589,   769,  -672,  -672,  -672,   670,  2970,
     121,  -672,  -672,  2970,  -672,  -672
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,     0,     0,   269,   270,   266,   414,     0,   260,   263,
     250,     0,     0,     0,   248,     0,     0,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   249,   252,     0,     0,     0,   292,   258,   288,
       0,     0,     0,   254,   253,     0,     0,     0,     0,   287,
       0,     0,   204,     0,     0,     0,   259,     0,     0,   203,
       0,   262,   261,     0,     0,     0,   251,   233,     0,     0,
     268,     0,     0,     0,     0,     0,     0,     0,     0,   415,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     4,
       0,     0,     0,     0,    15,    17,    19,    20,    21,    27,
      22,    25,    26,    31,    32,    33,    28,    29,    35,    36,
      23,    30,    24,     9,    93,    94,    96,     0,   110,   112,
     113,    97,    98,    99,   100,   166,   168,   170,   174,   177,
     179,   182,   187,   190,   193,   195,   197,   199,     0,   201,
     207,   209,     0,   229,   208,   236,   237,   240,   242,     0,
     247,   244,     0,   255,   265,   267,   241,   271,   276,   284,
     277,   278,   279,   282,   283,   280,   281,   299,   301,   302,
     303,   300,   346,   347,   348,   349,   350,   351,   264,   388,
     380,   387,   386,   385,   382,   384,   381,   383,   285,    34,
     101,   102,   104,   103,   105,   357,     0,   353,     0,     0,
       0,     0,     0,   398,     0,   266,   256,     0,   394,    53,
      38,    39,    70,    71,     0,     0,    52,     0,     0,    46,
      47,     0,     0,     0,    44,    45,     0,     0,     0,   390,
       0,     0,   289,     0,     0,   404,     0,     0,     0,   155,
       0,   114,   115,     0,    62,     0,    54,     0,     0,     0,
       0,   127,   128,   290,     0,     0,   389,     0,     0,     0,
       0,   395,     0,   232,     0,     0,     0,     0,   234,   235,
       0,     0,     0,   393,     0,     0,     0,     0,   342,     0,
     421,     0,     0,     0,     0,     0,     0,   467,   466,   471,
     470,     0,   464,   465,   469,   473,   491,   480,   502,   489,
     468,   472,     0,     0,   501,    43,   457,   458,   459,   460,
     461,   462,   463,     1,     3,     5,    10,     8,    12,    13,
       0,     0,     0,     0,     0,   111,     0,     0,     0,     0,
     210,   224,   215,   214,   222,   213,   212,   211,   223,   216,
     221,   220,   219,   218,   217,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   206,   205,   202,     0,   230,     0,
       0,     0,   243,   273,   246,   245,   257,   272,   358,   354,
     295,   297,     0,     0,     0,     0,   399,     0,   401,   362,
       0,     0,    40,    41,     0,     0,    42,     0,     0,    67,
       0,     0,   352,   391,   392,     0,     0,   405,     0,   408,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,    55,     0,     0,
       0,     0,   291,     0,   293,   344,   343,   396,   397,   231,
       0,     0,   403,   411,     0,     0,   304,     0,     0,   312,
     361,     0,   294,   225,   341,     0,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   500,     0,     0,
     490,   492,     0,     0,   487,     0,   475,     0,   474,     0,
      16,    18,    95,   139,   135,   137,   106,   136,   134,     0,
       0,     0,   167,   169,   172,   171,   173,     0,     0,     0,
     449,   175,   428,   436,   438,   440,   442,   444,   447,   181,
     180,   178,   184,   185,   186,   183,   188,   189,   192,   191,
     379,   378,   372,   194,   370,   376,   377,   196,   198,   367,
     200,   227,     0,   238,   239,     0,   274,     0,   296,   226,
       0,   412,     0,     0,    50,    51,    48,    49,     0,     0,
       0,     0,    88,    37,     0,     0,     0,   369,    66,    69,
       0,     0,   412,     0,     0,     0,     0,   157,     0,     0,
     154,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    64,     0,    56,    60,     0,   130,     0,
       0,     0,     0,     0,   363,     0,     0,   153,     0,   334,
     337,     0,   338,   339,     0,     0,   340,   333,     0,   310,
     336,   335,   305,     0,   313,     0,     0,   161,     0,     0,
       0,   419,   420,   416,   424,     0,   422,   426,     0,     0,
     499,   498,   493,   494,   496,     0,   488,   483,     0,     0,
      14,   148,     0,   149,   150,   151,   140,   141,   142,   143,
       0,   107,     0,   108,     0,     0,   443,     0,   176,   456,
     504,   503,     0,     0,   505,     0,     0,     0,     0,   429,
     433,   451,   432,   455,   453,   452,   454,     0,     0,     0,
     445,   508,   509,   506,   507,   510,   448,   373,   375,   374,
     371,   368,   228,   275,   298,   359,     0,   400,   402,    90,
      72,    73,     0,     0,     0,     0,    80,    81,     0,     0,
       0,    68,   355,     0,   413,   406,   407,   409,   410,   158,
     156,   125,   126,   119,     0,   121,   118,     0,     0,     0,
     116,     0,     0,    63,    57,   132,   131,     0,   129,    11,
     364,     0,   323,   317,   314,   345,     0,     0,     0,   311,
       0,     0,     0,     0,     0,   162,     7,   417,   418,   423,
       0,     0,   497,   495,     0,     0,     0,     0,     0,     0,
       0,   478,     0,   476,   152,   144,   145,   146,   138,   109,
     450,   446,   525,   524,   523,   519,     0,   437,   518,   430,
       0,     0,   435,   434,   439,   441,     0,   360,    91,    76,
      77,    89,    74,    75,     0,    84,    85,    82,    83,     0,
     356,   123,   120,     0,   122,     0,    59,     0,   133,   365,
       0,   331,   325,     0,   324,   326,   332,   329,   319,     0,
     318,   320,   330,    92,   306,     0,     0,     0,     0,     0,
       0,     0,   427,   425,   512,   513,   511,     0,   484,   485,
       0,   481,     0,   147,   522,   521,   520,   515,   516,   431,
     517,    78,    79,    86,    87,   124,   165,    65,   366,   316,
     327,   328,   315,   321,   322,   307,   308,     0,     0,   163,
       0,   159,     0,     0,     0,   479,   477,   309,     0,     0,
     514,   486,   482,     0,   160,   164
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -672,  -672,  -672,   741,   742,  -672,   740,  -672,   518,   520,
    -297,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,  -415,  -672,  -672,  -672,  -672,  -672,
     435,   131,  -520,   748,     6,   -80,  -672,  -672,   723,  -672,
    -672,   263,   422,  -234,  -672,  -672,   254,  -672,   521,   522,
     194,  -672,  -672,   202,  -554,  -672,   781,   279,  -672,  -672,
     236,  -672,  -672,   527,   529,   137,  -576,   510,   106,  -341,
     142,   162,  -672,  -672,  -672,  -672,  -672,   718,  -672,  -672,
    -672,  -672,  -672,  -672,   720,  -672,   -41,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,    70,  -672,  -672,  -672,   -61,   201,
    -672,  -325,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,
    -672,  -427,  -672,   255,  -672,   417,  -672,  -672,  -672,  -672,
    -672,    37,    45,  -544,  -671,  -672,  -672,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,  -672,   507,  -222,  -351,  -672,  -672,
     172,  -355,  -672,  -672,  -672,  -672,  -672,  -672,  -672,   836,
     837,   141,   473,  -672,  -672,  -672,  -672,  -672,  -672,  -672,
    -672,   375,  -672,  -672,   212,   206,   207,   387,  -672,  -672,
     220,  -672,  -472,  -672,  -672,  -672,  -672,   118,  -299,  -672,
     419,   130,  -672,  -431,  -672,  -672,  -672,  -672,  -638,  -672,
    -672,  -672,  -672,   101,   228,  -672
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   583,   249,   109,   110,   111,   112,
     551,   552,   606,   113,   114,   115,   116,   117,   118,   119,
     241,   242,   417,   418,   120,   251,   252,   326,   327,   484,
     485,   646,   647,   648,   649,   121,   238,   239,   122,   616,
     617,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   345,   346,
     347,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   372,   373,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   382,
     166,   167,   168,   608,   448,   449,   744,   829,   830,   823,
     824,   831,   825,   609,   610,   169,   170,   611,   171,   172,
     173,   174,   175,   176,   177,   528,   401,   523,   690,   524,
     525,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   542,   564,   188,   189,   190,   191,   192,   193,   194,
     286,   501,   669,   502,   503,   504,   505,   506,   507,   508,
     670,   671,   305,   306,   307,   308,   309,   850,   851,   310,
     470,   474,   635,   471,   311,   312,   673,   686,   769,   674,
     675,   680,   676,   857,   785,   658
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       280,   281,   282,   284,   478,   526,   526,   196,   198,   585,
     527,   512,   513,   514,   515,   411,   429,   201,   419,   398,
     607,   207,   481,   500,   414,   786,   268,   269,   430,   701,
     672,   574,   277,   398,   707,   414,     6,   202,   445,   632,
     228,   796,   457,   526,   264,   762,   233,   557,   445,   590,
     259,   412,   243,   727,   412,   385,   320,   254,    26,   260,
      28,   257,    30,    31,   749,    17,   599,   840,   246,   600,
     224,   826,   832,   234,   475,   468,   544,   349,   272,   435,
     274,   275,   276,   206,   367,   475,   599,   428,   546,   600,
     375,   789,    39,   776,   777,   700,   377,   577,   199,   545,
     601,   350,   615,   742,   210,   446,   599,   476,   415,   600,
     706,   547,   247,   703,   225,   612,   604,    60,   638,   381,
     601,   703,   320,    49,   211,   387,   406,   497,   408,   754,
     465,   604,   351,   498,   244,   602,   212,   603,   320,   466,
     601,   200,   320,   320,   265,   599,   537,   770,   600,   841,
     772,   320,   884,   826,   884,   602,   213,   603,   320,   832,
     477,   320,   320,   469,   413,   693,   386,   444,   416,   248,
     320,   604,   734,   500,   500,   602,   203,   603,   639,   601,
     763,   607,   800,   575,   803,   579,   607,   204,   806,   808,
     416,   604,   447,   416,   261,   526,   591,   793,    57,   702,
     526,   278,   613,   462,   708,   632,   383,   749,   458,   459,
     883,   604,   235,   436,   602,   859,   603,   460,    57,   374,
      85,   853,   376,   236,   704,   705,   743,   605,    71,   320,
     378,   416,   709,   710,   416,   245,   388,   407,    57,   409,
     482,   483,   486,   483,   488,   416,   499,   748,    71,   421,
     604,   398,    77,   432,   451,   320,   214,   538,   771,   379,
     526,   773,   520,   885,   753,   886,   384,   750,    71,   389,
     402,   441,    77,   642,   821,   472,   215,    57,   405,   349,
     320,    12,   320,   600,   862,   320,   320,   320,   799,   864,
     321,   320,    77,   320,    16,   320,   358,   455,   320,   320,
     320,   356,   520,   350,   208,   783,   837,    71,   489,   604,
     784,   644,   645,   357,   398,   359,   782,    35,   752,   323,
     558,    12,   262,   263,   607,    41,   410,   790,   533,   534,
     567,    77,   600,   570,    16,   572,   548,   434,   352,   209,
     500,     6,   827,   481,   728,   369,   370,   548,   588,   602,
     526,   603,   500,   500,   804,   526,   521,    35,   221,   809,
     822,   473,   821,   450,   597,    41,   619,    41,   620,   353,
      17,   600,    54,   532,   456,   399,   216,   535,   621,   622,
     623,   624,   400,   626,   627,   604,   629,    58,   452,   354,
     453,   219,   220,   539,   596,   692,   521,    39,   602,   740,
     603,   780,   867,   797,    64,    65,   810,   833,   868,   651,
     828,   653,    54,   681,   682,   683,   684,   217,    73,   549,
     550,   802,   559,   844,   845,   846,   847,    58,    49,   560,
     554,   555,   497,    45,   604,   355,   522,   602,   498,   603,
     641,   685,   604,   229,    64,    65,   595,    65,   870,   687,
     688,   689,   218,   642,    50,   509,   510,   694,    73,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,   604,   805,   321,   522,   798,   643,   222,
     711,   807,   494,   495,   496,   223,   861,   863,   719,   226,
     600,   644,   645,   322,   723,   604,   725,   726,   516,   517,
     827,   731,   604,   654,   323,   764,   765,   604,   604,   735,
     736,    47,    48,   854,   356,   227,   766,   767,     1,   855,
     518,   519,   232,   526,     2,     3,   357,   888,   543,   768,
     324,   237,     4,     5,   529,   529,   856,     6,   240,   757,
     758,   890,     8,     9,   250,   759,   696,   563,   255,   565,
      10,    11,    12,    13,     3,   256,   602,   258,   603,    14,
     882,     4,   205,   356,    15,    16,    17,   713,   873,   266,
     483,   267,   779,   536,   854,   357,   536,   271,   536,   273,
     855,    12,   279,    32,    33,   892,   285,    34,    35,    36,
      37,    38,   604,    39,    16,    40,    41,   856,   630,   631,
     764,   765,   313,   318,   319,   328,   329,    79,    43,    44,
     746,   766,   767,   320,   360,   361,   348,    35,   362,   371,
     363,   390,   391,   392,    49,    41,   395,   393,   394,    85,
     396,   397,   403,   404,    51,   420,   423,   425,   422,   424,
     426,   427,   431,    54,   811,   433,   437,   812,   439,   814,
     438,   440,    55,   442,    56,    57,   443,   818,    58,   454,
     461,   463,   464,   467,    61,    62,   491,    63,   520,   540,
     541,   553,    54,   562,   561,    64,    65,    66,   568,   576,
     842,   843,   582,    70,   569,    71,   571,    58,    72,    73,
     573,   580,   581,   587,   584,   592,    75,   589,   586,   593,
     598,   615,   618,   625,    64,    65,   628,   633,   634,    77,
     637,   640,    70,   650,   677,   657,   679,     1,    73,   678,
     652,   691,   697,     2,     3,   698,   699,   714,   715,   721,
     722,     4,     5,   865,   724,   866,     6,   716,   717,     7,
     718,     8,     9,   729,   732,   733,   737,   820,   739,    10,
      11,    12,    13,   741,   745,   747,   756,   760,    14,   879,
     642,   881,   774,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
     761,   398,    32,    33,   548,   813,    34,    35,    36,    37,
      38,   781,    39,   815,    40,    41,   816,   817,   835,   836,
     838,   839,   834,   475,    42,   848,   872,    43,    44,   894,
      45,   875,   860,   895,   869,   876,   877,    46,    47,    48,
     878,   849,   889,    49,   880,   891,   887,   893,   314,   315,
     316,    50,   556,    51,   801,    52,   479,    53,   480,   317,
     325,   578,    54,   730,   778,   487,   738,   490,   720,   775,
     270,    55,   755,    56,    57,   492,   366,    58,   493,    59,
      60,   511,   368,    61,    62,   614,    63,   874,   751,   871,
     530,   230,   231,   655,    64,    65,    66,   787,    67,    68,
      69,   566,    70,   794,    71,   795,   656,    72,    73,   792,
     852,   858,    74,   636,   788,    75,     0,     0,     0,     0,
       0,     0,     0,    76,     0,     1,     0,     0,    77,     0,
      78,     2,     3,     0,    79,    80,    81,    82,    83,     4,
       5,     0,     0,    84,     6,     0,     0,     7,     0,     8,
       9,     0,     0,     0,     0,     0,    85,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,    38,     0,
      39,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,    43,    44,     0,    45,     0,
       0,     0,     0,     0,     0,    46,    47,    48,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,    50,
       0,    51,     0,    52,     0,    53,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,    56,    57,     0,     0,    58,     0,    59,    60,     0,
       0,    61,    62,     0,    63,     0,     0,     0,     0,     0,
       0,     0,    64,    65,    66,     0,    67,    68,    69,     0,
      70,     0,    71,     0,     0,    72,    73,     0,     0,     0,
      74,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     1,     0,     0,    77,     0,     0,     2,
       3,     0,    79,    80,    81,    82,    83,     4,     5,     0,
       0,    84,     6,     0,     0,     7,     0,     8,     9,     0,
       0,     0,     0,     0,    85,    10,    11,    12,    13,     0,
       0,     0,     0,     0,    14,     0,     0,     0,     0,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,    33,
       0,     0,    34,    35,    36,    37,    38,     0,    39,     0,
      40,    41,     0,     0,     0,     0,     0,     0,     0,     0,
      42,     0,     0,    43,    44,     0,    45,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     0,    49,
       0,     0,     0,     0,     0,     0,     0,    50,     0,    51,
       0,    52,     0,     0,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,    56,
      57,     0,     0,    58,     0,    59,    60,     0,     0,    61,
      62,     0,    63,     0,     0,     0,     0,     0,     0,     0,
      64,    65,    66,     0,    67,    68,    69,     0,    70,     0,
      71,     0,     0,    72,    73,     0,     0,     0,    74,     0,
       0,    75,     0,     0,     0,     0,     0,     0,     0,    76,
       0,     0,     1,     0,    77,     0,     0,     0,     2,     3,
       0,    80,    81,    82,    83,     0,     4,     5,     0,    84,
     283,     6,     0,     0,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,     0,     0,
       0,     0,     0,    14,     0,     0,     0,     0,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    33,     0,
       0,    34,    35,    36,    37,    38,     0,    39,     0,    40,
      41,     0,     0,     0,     0,     0,     0,     0,     0,    42,
       0,     0,    43,    44,     0,    45,     0,     0,     0,     0,
       0,     0,    46,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,     0,     0,    50,     0,    51,     0,
      52,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,    56,    57,
       0,     0,    58,     0,    59,    60,     0,     0,    61,    62,
       0,    63,     0,   195,     0,     0,     0,     0,     0,    64,
      65,    66,     0,    67,    68,    69,     0,    70,     0,    71,
       0,     0,    72,    73,     0,     0,     0,    74,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,    76,     0,
       1,     0,     0,    77,     0,     0,     2,     3,     0,     0,
      80,    81,    82,    83,     4,     5,     0,     0,    84,     6,
       0,     0,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,     0,     0,    34,
      35,    36,    37,    38,     0,    39,     0,    40,    41,     0,
       0,     0,     0,     0,     0,     0,     0,    42,     0,     0,
      43,    44,     0,    45,     0,     0,     0,     0,     0,     0,
      46,     0,     0,     0,     0,     0,    49,     0,     0,     0,
       0,     0,     0,     0,    50,     0,    51,     0,    52,     0,
       0,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,    56,    57,     0,     0,
      58,     0,    59,    60,     0,     0,    61,    62,     0,    63,
       0,   197,     0,     0,     0,     0,     0,    64,    65,    66,
       0,    67,    68,    69,     0,    70,     0,    71,     0,     0,
      72,    73,     0,     0,     0,    74,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,    76,     0,     1,     0,
       0,    77,     0,     0,     2,     3,     0,     0,    80,    81,
      82,    83,     4,     5,     0,     0,    84,     6,     0,     0,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,     0,     0,     0,     0,     0,    14,
       0,     0,     0,     0,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,     0,     0,    34,    35,    36,
      37,    38,     0,    39,     0,    40,    41,     0,     0,     0,
       0,     0,     0,     0,     0,    42,     0,     0,    43,    44,
       0,    45,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,     0,     0,    49,     0,     0,     0,     0,     0,
       0,     0,    50,     0,    51,     0,    52,     0,     0,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,    56,    57,     0,     0,    58,     0,
      59,    60,     0,     0,    61,    62,     0,    63,     0,     0,
       0,     0,   253,     0,     0,    64,    65,    66,     0,    67,
      68,    69,     0,    70,     0,    71,     0,     0,    72,    73,
       0,     0,     0,    74,     0,     0,    75,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     1,     0,     0,    77,
       0,     0,     2,     3,     0,     0,    80,    81,    82,    83,
       4,     5,     0,     0,    84,     6,     0,     0,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,    10,    11,
      12,    13,     0,     0,     0,     0,     0,    14,     0,     0,
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
       0,    70,     0,    71,     0,     0,    72,    73,     0,     0,
       0,    74,     0,     0,    75,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     1,     0,     0,    77,     0,     0,
       2,     3,     0,     0,    80,    81,    82,    83,     4,     5,
       0,     0,    84,     6,     0,     0,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,    10,    11,    12,    13,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,     0,    34,    35,    36,    37,    38,     0,    39,
       0,    40,    41,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,     0,    43,    44,     0,    45,     0,     0,
       0,     0,     0,     0,    46,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,    50,     0,
      51,     0,    52,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
      56,    57,     0,     0,    58,     0,    59,    60,     0,     0,
      61,    62,     0,    63,     0,   531,     0,     0,     0,     0,
       0,    64,    65,    66,     0,    67,    68,    69,     0,    70,
       0,    71,     0,     0,    72,    73,     0,     0,     0,    74,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     1,     0,     0,    77,     0,     0,     2,     3,
       0,     0,    80,    81,    82,    83,     4,     5,     0,     0,
      84,     6,     0,     0,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,     0,     0,
       0,     0,     0,    14,     0,     0,     0,     0,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    33,     0,
       0,    34,    35,    36,    37,    38,     0,    39,     0,    40,
      41,     0,     0,     0,     0,     0,     0,     0,     0,    42,
       0,     0,    43,    44,     0,    45,     0,     0,     0,     0,
       0,     0,    46,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,     0,     0,    50,     0,    51,     0,
      52,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,    56,    57,
       0,     0,    58,     0,    59,    60,     0,     0,    61,    62,
       0,    63,     0,   594,     0,     0,     0,     0,     0,    64,
      65,    66,     0,    67,    68,    69,     0,    70,     0,    71,
       0,     0,    72,    73,     0,     0,     0,    74,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,    76,     0,
       1,     0,     0,    77,     0,     0,     2,     3,     0,     0,
      80,    81,    82,    83,     4,     5,     0,     0,    84,     6,
       0,     0,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,     0,     0,    34,
      35,    36,    37,    38,     0,    39,     0,    40,    41,     0,
       0,     0,     0,     0,     0,     0,     0,    42,     0,     0,
      43,    44,     0,    45,     0,     0,     0,     0,     0,     0,
      46,     0,     0,     0,     0,     0,    49,     0,     0,     0,
       0,     0,     0,     0,    50,     0,    51,     0,    52,     0,
       0,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,    56,    57,     0,     0,
      58,     0,    59,    60,     0,     0,    61,    62,     0,    63,
       0,   695,     0,     0,     0,     0,     0,    64,    65,    66,
       0,    67,    68,    69,     0,    70,     0,    71,     0,     0,
      72,    73,     0,     0,     0,    74,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,    76,     0,     1,     0,
       0,    77,     0,     0,     2,     3,     0,     0,    80,    81,
      82,    83,     4,     5,     0,     0,    84,     6,     0,     0,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,     0,     0,     0,     0,     0,    14,
       0,     0,     0,     0,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,     0,     0,    34,    35,    36,
      37,    38,     0,    39,     0,    40,    41,     0,     0,     0,
       0,     0,     0,     0,     0,    42,     0,     0,    43,    44,
       0,    45,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,     0,     0,    49,     0,     0,     0,     0,     0,
       0,     0,    50,     0,    51,     0,    52,     0,     0,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,    56,    57,     0,     0,    58,     0,
      59,    60,     0,     0,    61,    62,     0,    63,     0,   712,
       0,     0,     0,     0,     0,    64,    65,    66,     0,    67,
      68,    69,     0,    70,     0,    71,     0,     0,    72,    73,
       0,     0,     0,    74,     0,     0,    75,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     1,     0,     0,    77,
       0,     0,     2,     3,     0,     0,    80,    81,    82,    83,
       4,     5,     0,     0,    84,     6,     0,     0,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,    10,    11,
      12,    13,     0,     0,     0,     0,     0,    14,     0,     0,
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
       0,     0,    61,    62,     0,    63,     0,   819,     0,     0,
       0,     0,     0,    64,    65,    66,     0,    67,    68,    69,
       0,    70,     0,    71,     0,     0,    72,    73,     0,     0,
       0,    74,     0,     0,    75,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     1,     0,     0,    77,     0,     0,
       2,     3,     0,     0,    80,    81,    82,    83,     4,     5,
       0,     0,    84,     6,     0,     0,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,    10,    11,    12,    13,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,     0,    34,    35,    36,    37,    38,     0,    39,
       0,    40,    41,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,     0,    43,    44,     0,    45,     0,     0,
       0,     0,     0,     0,    46,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,    50,     0,
      51,     0,    52,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
      56,    57,     0,     0,    58,     0,    59,    60,     0,     0,
      61,    62,     0,    63,     0,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,    67,    68,    69,     0,    70,
       0,    71,     0,     0,    72,    73,     0,     0,     0,    74,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     1,     0,     0,    77,     0,     0,     2,     3,
       0,     0,    80,    81,    82,    83,     4,     5,     0,     0,
      84,     6,     0,     0,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,     0,     0,
       0,     0,     0,    14,     0,     0,     0,     0,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    33,     0,
       0,    34,    35,    36,    37,    38,     0,    39,     0,    40,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
     364,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,    56,    57,
       0,     0,    58,     0,   365,    60,     0,     0,    61,    62,
       0,    63,     0,     0,     0,     0,     0,     0,     0,    64,
      65,    66,     0,    67,    68,     0,     0,    70,     0,    71,
       1,     0,    72,    73,     0,     0,     2,     3,     0,     0,
      75,     0,     0,     0,     4,     5,     0,     0,    76,     6,
       0,     0,     7,    77,     8,     9,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,     0,     0,    34,
      35,    36,    37,    38,     0,    39,     0,    40,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      43,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,    52,     0,
       0,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,    56,    57,     0,     0,
      58,     0,    59,    60,     0,     0,    61,    62,     0,    63,
       0,     0,     0,     0,     0,     0,     0,    64,    65,    66,
       0,    67,    68,     0,     0,    70,     0,    71,     1,     0,
      72,    73,     0,     0,     2,     3,     0,     0,    75,     0,
       0,     0,     4,     5,     0,     0,    76,     6,     0,     0,
       0,    77,     8,     9,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,     0,     0,     0,     0,     0,    14,
       0,     0,     0,     0,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,     0,     0,    34,    35,    36,
      37,    38,     0,    39,     0,    40,    41,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    44,
     659,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,    56,    57,   659,     0,    58,     0,
       0,     0,     0,     0,    61,    62,     0,    63,     0,     0,
       0,     0,     0,     0,     0,    64,    65,    66,     0,     0,
       0,     0,     0,     0,     0,    71,     0,     0,    72,    73,
     660,     0,     0,   661,   287,   288,    75,   289,   290,   662,
     663,   664,     0,     0,     0,     0,     0,   665,   291,    77,
     292,     0,     0,     0,     0,     0,   666,     0,     0,     0,
       0,   293,   667,   668,     0,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   660,     0,     0,   661,
     287,   288,     0,   289,   290,   662,   663,   664,     0,     0,
       0,     0,     0,     0,   291,     0,   292,     0,     0,     0,
       0,     0,   666,     0,     0,     0,     0,   293,   791,   668,
       0,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   330,     0,     0,     0,     0,     0,     0,     0,
     331,     0,     0,   332,     0,   333,     0,   287,   288,     0,
     289,   290,     0,     0,     0,     0,   334,     0,     0,     0,
     335,   291,     0,   292,     0,   336,     0,     0,     0,     0,
       0,   337,     0,     0,   293,     0,     0,     0,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,   338,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   339,   340,
     341,   342,   343,   344
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        80,    81,    82,    83,   303,   360,   361,     1,     2,   424,
     361,   352,   353,   354,   355,   237,   250,    11,   240,    32,
     447,    15,   319,   348,    34,   663,    67,    68,   250,   549,
     502,   107,    27,    32,   554,    34,    23,    19,    19,   470,
      34,   679,    32,   398,    14,    23,    40,   398,    19,   100,
      14,    47,    46,   107,    47,    47,    47,    51,    61,    23,
      63,    55,    65,    66,   608,    52,     9,    75,    24,    12,
     137,   742,   743,    19,    34,    92,   108,   122,    72,     8,
      74,    75,    76,    13,   114,    34,     9,   100,   108,    12,
     151,   667,    79,   647,   648,    93,   157,   107,   120,   131,
      43,   146,    40,    31,   152,    86,     9,    67,   107,    12,
      93,   131,    68,    47,   181,    86,   114,   147,    67,   199,
      43,    47,    47,   110,   172,    47,    47,   114,    47,    67,
     200,   114,   177,   120,    24,    78,   152,    80,    47,   209,
      43,   114,    47,    47,   114,     9,    47,    47,    12,   157,
      47,    47,    47,   824,    47,    78,   172,    80,    47,   830,
     120,    47,    47,   180,   160,   156,   158,   160,   244,   125,
      47,   114,   587,   498,   499,    78,   158,    80,   477,    43,
     158,   608,   702,   417,   704,   419,   613,   169,   708,   709,
     244,   114,   173,   244,   158,   550,   430,   669,   141,   550,
     555,   196,   173,   283,   555,   636,   200,   751,   198,   199,
     848,   114,   158,   142,    78,   791,    80,   207,   141,   149,
     223,   775,   152,   169,   158,   159,   154,   170,   171,    47,
     155,   244,   158,   159,   244,   125,   158,   158,   141,   158,
     320,   321,   322,   323,   324,   244,   233,   170,   171,   158,
     114,    32,   195,   158,   158,    47,   132,   158,   158,   155,
     615,   158,    19,   158,   615,   158,   155,   170,   171,   155,
     155,   265,   195,    46,     3,    34,   152,   141,   155,   122,
      47,    38,    47,    12,   804,    47,    47,    47,    93,   809,
     139,    47,   195,    47,    51,    47,    92,    87,    47,    47,
      47,   180,    19,   146,   158,   240,   170,   171,   157,   114,
     245,    84,    85,   192,    32,   111,   657,    74,    75,   168,
     400,    38,    19,    20,   751,    82,   107,   668,   369,   370,
     410,   195,    12,   413,    51,   415,    75,   155,    72,    24,
     665,    23,    22,   640,   578,   165,   166,    75,   428,    78,
     705,    80,   677,   678,   705,   710,   113,    74,    19,   710,
      89,   120,     3,   155,   444,    82,   206,    82,   208,   103,
      52,    12,   129,   367,   164,    93,    24,   371,   458,   459,
     460,   461,   100,   463,   464,   114,   466,   144,   155,   123,
     155,    84,    85,   155,   155,   155,   113,    79,    78,   155,
      80,   155,   817,   155,   161,   162,   155,   155,   155,   489,
      90,   491,   129,   213,   214,   215,   216,   125,   175,   158,
     159,    93,    93,   764,   765,   766,   767,   144,   110,   100,
     158,   159,   114,    97,   114,   169,   193,    78,   120,    80,
      33,   241,   114,   158,   161,   162,   440,   162,    89,   133,
     134,   135,   125,    46,   118,   349,   350,   537,   175,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,   114,    93,   139,   193,   699,    71,    14,
     560,    93,   345,   346,   347,    19,    93,    93,   568,    19,
      12,    84,    85,   157,   574,   114,   576,   577,   356,   357,
      22,   581,   114,   497,   168,   218,   219,   114,   114,   589,
     590,   105,   106,   240,   180,    25,   229,   230,     4,   246,
     358,   359,    25,   878,    10,    11,   192,   878,   387,   242,
     194,    25,    18,    19,   362,   363,   263,    23,    25,   619,
     620,   882,    28,    29,    25,   625,   540,   406,    14,   408,
      36,    37,    38,    39,    11,   158,    78,    16,    80,    45,
     177,    18,    19,   180,    50,    51,    52,   561,    90,    19,
     650,    19,   652,   372,   240,   192,   375,    19,   377,   158,
     246,    38,    23,    69,    70,   884,    25,    73,    74,    75,
      76,    77,   114,    79,    51,    81,    82,   263,   468,   469,
     218,   219,     0,   164,   164,   136,    30,   201,    94,    95,
     604,   229,   230,    47,   109,   178,   232,    74,    41,   115,
      42,    47,    47,    24,   110,    82,    88,    24,   120,   223,
      23,   120,   158,   158,   120,    47,    14,   125,    34,    34,
      14,    24,    47,   129,   724,    88,   158,   727,    17,   729,
     158,   114,   138,   158,   140,   141,   158,   737,   144,   196,
      32,   212,   100,    23,   150,   151,   157,   153,    19,   114,
      19,    24,   129,    19,   114,   161,   162,   163,   107,   107,
     760,   761,    24,   169,    75,   171,    75,   144,   174,   175,
      75,    75,   176,    34,    88,    75,   182,   100,    88,    24,
      88,    40,    23,   212,   161,   162,    25,    23,    23,   195,
      23,   164,   169,    47,   231,   251,   239,     4,   175,   238,
     157,   102,   158,    10,    11,   158,    25,   102,   158,    25,
      25,    18,    19,   813,   107,   815,    23,   158,   158,    26,
     158,    28,    29,   107,    47,    24,   100,   741,   164,    36,
      37,    38,    39,   114,     7,    19,   164,   100,    45,   839,
      46,   841,    24,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
     157,    32,    69,    70,    75,   107,    73,    74,    75,    76,
      77,   158,    79,    83,    81,    82,    24,    34,    19,    19,
      25,   157,   173,    34,    91,    23,   154,    94,    95,   889,
      97,   173,   247,   893,    31,   173,    19,   104,   105,   106,
      32,   236,   157,   110,    25,   236,   173,   157,    87,    87,
      90,   118,   397,   120,   703,   122,   318,   124,   318,    91,
     117,   419,   129,   580,   650,   323,   592,   326,   569,   647,
      69,   138,   616,   140,   141,   328,   138,   144,   329,   146,
     147,   351,   142,   150,   151,   448,   153,   830,   613,   824,
     363,    35,    35,   498,   161,   162,   163,   665,   165,   166,
     167,   408,   169,   677,   171,   678,   499,   174,   175,   669,
     772,   790,   179,   474,   666,   182,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   190,    -1,     4,    -1,    -1,   195,    -1,
     197,    10,    11,    -1,   201,   202,   203,   204,   205,    18,
      19,    -1,    -1,   210,    23,    -1,    -1,    26,    -1,    28,
      29,    -1,    -1,    -1,    -1,    -1,   223,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      69,    70,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      79,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    94,    95,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,   120,    -1,   122,    -1,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
      -1,   140,   141,    -1,    -1,   144,    -1,   146,   147,    -1,
      -1,   150,   151,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,    -1,   165,   166,   167,    -1,
     169,    -1,   171,    -1,    -1,   174,   175,    -1,    -1,    -1,
     179,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,    -1,     4,    -1,    -1,   195,    -1,    -1,    10,
      11,    -1,   201,   202,   203,   204,   205,    18,    19,    -1,
      -1,   210,    23,    -1,    -1,    26,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,   223,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      -1,    -1,    73,    74,    75,    76,    77,    -1,    79,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,
      -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,
     141,    -1,    -1,   144,    -1,   146,   147,    -1,    -1,   150,
     151,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,   163,    -1,   165,   166,   167,    -1,   169,    -1,
     171,    -1,    -1,   174,   175,    -1,    -1,    -1,   179,    -1,
      -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
      -1,    -1,     4,    -1,   195,    -1,    -1,    -1,    10,    11,
      -1,   202,   203,   204,   205,    -1,    18,    19,    -1,   210,
     211,    23,    -1,    -1,    26,    -1,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,
      -1,    73,    74,    75,    76,    77,    -1,    79,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   141,
      -1,    -1,   144,    -1,   146,   147,    -1,    -1,   150,   151,
      -1,   153,    -1,   155,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,    -1,   165,   166,   167,    -1,   169,    -1,   171,
      -1,    -1,   174,   175,    -1,    -1,    -1,   179,    -1,    -1,
     182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,
       4,    -1,    -1,   195,    -1,    -1,    10,    11,    -1,    -1,
     202,   203,   204,   205,    18,    19,    -1,    -1,   210,    23,
      -1,    -1,    26,    -1,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    79,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,   120,    -1,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,    -1,
     144,    -1,   146,   147,    -1,    -1,   150,   151,    -1,   153,
      -1,   155,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,   165,   166,   167,    -1,   169,    -1,   171,    -1,    -1,
     174,   175,    -1,    -1,    -1,   179,    -1,    -1,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,     4,    -1,
      -1,   195,    -1,    -1,    10,    11,    -1,    -1,   202,   203,
     204,   205,    18,    19,    -1,    -1,   210,    23,    -1,    -1,
      26,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    79,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    95,
      -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,    -1,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   141,    -1,    -1,   144,    -1,
     146,   147,    -1,    -1,   150,   151,    -1,   153,    -1,    -1,
      -1,    -1,   158,    -1,    -1,   161,   162,   163,    -1,   165,
     166,   167,    -1,   169,    -1,   171,    -1,    -1,   174,   175,
      -1,    -1,    -1,   179,    -1,    -1,   182,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,    -1,     4,    -1,    -1,   195,
      -1,    -1,    10,    11,    -1,    -1,   202,   203,   204,   205,
      18,    19,    -1,    -1,   210,    23,    -1,    -1,    26,    -1,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    -1,    -1,    73,    74,    75,    76,    77,
      -1,    79,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    94,    95,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,   120,    -1,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,   140,   141,    -1,    -1,   144,    -1,   146,   147,
      -1,    -1,   150,   151,    -1,   153,    -1,    -1,    -1,    -1,
     158,    -1,    -1,   161,   162,   163,    -1,   165,   166,   167,
      -1,   169,    -1,   171,    -1,    -1,   174,   175,    -1,    -1,
      -1,   179,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,    -1,     4,    -1,    -1,   195,    -1,    -1,
      10,    11,    -1,    -1,   202,   203,   204,   205,    18,    19,
      -1,    -1,   210,    23,    -1,    -1,    26,    -1,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    -1,    -1,    73,    74,    75,    76,    77,    -1,    79,
      -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    94,    95,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,
     120,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
     140,   141,    -1,    -1,   144,    -1,   146,   147,    -1,    -1,
     150,   151,    -1,   153,    -1,   155,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,   165,   166,   167,    -1,   169,
      -1,   171,    -1,    -1,   174,   175,    -1,    -1,    -1,   179,
      -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,    -1,     4,    -1,    -1,   195,    -1,    -1,    10,    11,
      -1,    -1,   202,   203,   204,   205,    18,    19,    -1,    -1,
     210,    23,    -1,    -1,    26,    -1,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,
      -1,    73,    74,    75,    76,    77,    -1,    79,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   141,
      -1,    -1,   144,    -1,   146,   147,    -1,    -1,   150,   151,
      -1,   153,    -1,   155,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,    -1,   165,   166,   167,    -1,   169,    -1,   171,
      -1,    -1,   174,   175,    -1,    -1,    -1,   179,    -1,    -1,
     182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,
       4,    -1,    -1,   195,    -1,    -1,    10,    11,    -1,    -1,
     202,   203,   204,   205,    18,    19,    -1,    -1,   210,    23,
      -1,    -1,    26,    -1,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    79,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,   120,    -1,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,    -1,
     144,    -1,   146,   147,    -1,    -1,   150,   151,    -1,   153,
      -1,   155,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,   165,   166,   167,    -1,   169,    -1,   171,    -1,    -1,
     174,   175,    -1,    -1,    -1,   179,    -1,    -1,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,     4,    -1,
      -1,   195,    -1,    -1,    10,    11,    -1,    -1,   202,   203,
     204,   205,    18,    19,    -1,    -1,   210,    23,    -1,    -1,
      26,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    79,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    95,
      -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,    -1,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   141,    -1,    -1,   144,    -1,
     146,   147,    -1,    -1,   150,   151,    -1,   153,    -1,   155,
      -1,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,   165,
     166,   167,    -1,   169,    -1,   171,    -1,    -1,   174,   175,
      -1,    -1,    -1,   179,    -1,    -1,   182,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,    -1,     4,    -1,    -1,   195,
      -1,    -1,    10,    11,    -1,    -1,   202,   203,   204,   205,
      18,    19,    -1,    -1,   210,    23,    -1,    -1,    26,    -1,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    -1,    -1,    73,    74,    75,    76,    77,
      -1,    79,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    94,    95,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,   120,    -1,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,   140,   141,    -1,    -1,   144,    -1,   146,   147,
      -1,    -1,   150,   151,    -1,   153,    -1,   155,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,    -1,   165,   166,   167,
      -1,   169,    -1,   171,    -1,    -1,   174,   175,    -1,    -1,
      -1,   179,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,    -1,     4,    -1,    -1,   195,    -1,    -1,
      10,    11,    -1,    -1,   202,   203,   204,   205,    18,    19,
      -1,    -1,   210,    23,    -1,    -1,    26,    -1,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    -1,    -1,    73,    74,    75,    76,    77,    -1,    79,
      -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    94,    95,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,
     120,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
     140,   141,    -1,    -1,   144,    -1,   146,   147,    -1,    -1,
     150,   151,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,   165,   166,   167,    -1,   169,
      -1,   171,    -1,    -1,   174,   175,    -1,    -1,    -1,   179,
      -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,    -1,     4,    -1,    -1,   195,    -1,    -1,    10,    11,
      -1,    -1,   202,   203,   204,   205,    18,    19,    -1,    -1,
     210,    23,    -1,    -1,    26,    -1,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,
      -1,    73,    74,    75,    76,    77,    -1,    79,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   141,
      -1,    -1,   144,    -1,   146,   147,    -1,    -1,   150,   151,
      -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,    -1,   165,   166,    -1,    -1,   169,    -1,   171,
       4,    -1,   174,   175,    -1,    -1,    10,    11,    -1,    -1,
     182,    -1,    -1,    -1,    18,    19,    -1,    -1,   190,    23,
      -1,    -1,    26,   195,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    79,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,    -1,
     144,    -1,   146,   147,    -1,    -1,   150,   151,    -1,   153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,   165,   166,    -1,    -1,   169,    -1,   171,     4,    -1,
     174,   175,    -1,    -1,    10,    11,    -1,    -1,   182,    -1,
      -1,    -1,    18,    19,    -1,    -1,   190,    23,    -1,    -1,
      -1,   195,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    79,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   141,   137,    -1,   144,    -1,
      -1,    -1,    -1,    -1,   150,   151,    -1,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   171,    -1,    -1,   174,   175,
     217,    -1,    -1,   220,   221,   222,   182,   224,   225,   226,
     227,   228,    -1,    -1,    -1,    -1,    -1,   234,   235,   195,
     237,    -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,   248,   249,   250,    -1,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   217,    -1,    -1,   220,
     221,   222,    -1,   224,   225,   226,   227,   228,    -1,    -1,
      -1,    -1,    -1,    -1,   235,    -1,   237,    -1,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,   248,   249,   250,
      -1,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    -1,    99,    -1,   101,    -1,   221,   222,    -1,
     224,   225,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,
     116,   235,    -1,   237,    -1,   121,    -1,    -1,    -1,    -1,
      -1,   127,    -1,    -1,   248,    -1,    -1,    -1,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
      -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,   185,
     186,   187,   188,   189
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,     4,    10,    11,    18,    19,    23,    26,    28,    29,
      36,    37,    38,    39,    45,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    69,    70,    73,    74,    75,    76,    77,    79,
      81,    82,    91,    94,    95,    97,   104,   105,   106,   110,
     118,   120,   122,   124,   129,   138,   140,   141,   144,   146,
     147,   150,   151,   153,   161,   162,   163,   165,   166,   167,
     169,   171,   174,   175,   179,   182,   190,   195,   197,   201,
     202,   203,   204,   205,   210,   223,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   300,
     301,   302,   303,   307,   308,   309,   310,   311,   312,   313,
     318,   329,   332,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   384,   385,   386,   399,
     400,   402,   403,   404,   405,   406,   407,   408,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   427,   428,
     429,   430,   431,   432,   433,   155,   308,   155,   308,   120,
     114,   308,    19,   158,   169,    19,   368,   308,   158,    24,
     152,   172,   152,   172,   132,   152,    24,   125,   125,    84,
      85,    19,    14,    19,   137,   181,    19,    25,   308,   158,
     423,   424,    25,   308,    19,   158,   169,    25,   330,   331,
      25,   314,   315,   308,    24,   125,    24,    68,   125,   299,
      25,   319,   320,   158,   308,    14,   158,   308,    16,    14,
      23,   158,    19,    20,    14,   114,    19,    19,   360,   360,
     330,    19,   308,   158,   308,   308,   308,    27,   196,    23,
     309,   309,   309,   211,   309,    25,   434,   221,   222,   224,
     225,   235,   237,   248,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   446,   447,   448,   449,   450,
     453,   458,   459,     0,   277,   278,   280,   307,   164,   164,
      47,   139,   157,   168,   194,   312,   321,   322,   136,    30,
      88,    96,    99,   101,   112,   116,   121,   127,   149,   184,
     185,   186,   187,   188,   189,   352,   353,   354,   232,   122,
     146,   177,    72,   103,   123,   169,   180,   192,    92,   111,
     109,   178,    41,    42,   122,   146,   351,   114,   358,   165,
     166,   115,   372,   373,   368,   372,   368,   372,   155,   155,
     158,   309,   383,   308,   155,    47,   158,    47,   158,   155,
      47,    47,    24,    24,   120,    88,    23,   120,    32,    93,
     100,   410,   155,   158,   158,   155,    47,   158,    47,   158,
     107,   410,    47,   160,    34,   107,   244,   316,   317,   410,
      47,   158,    34,    14,    34,   125,    14,    24,   100,   317,
     410,    47,   158,    88,   155,     8,   142,   158,   158,    17,
     114,   308,   158,   158,   160,    19,    86,   173,   388,   389,
     155,   158,   155,   155,   196,    87,   164,    32,   198,   199,
     207,    32,   309,   212,   100,   200,   209,    23,    92,   180,
     454,   457,    34,   120,   455,    34,    67,   120,   452,   282,
     283,   284,   309,   309,   323,   324,   309,   323,   309,   157,
     322,   157,   337,   338,   339,   339,   339,   114,   120,   233,
     375,   435,   437,   438,   439,   440,   441,   442,   443,   342,
     342,   341,   343,   343,   343,   343,   344,   344,   345,   345,
      19,   113,   193,   411,   413,   414,   415,   411,   409,   414,
     409,   155,   308,   360,   360,   308,   373,    47,   158,   155,
     114,    19,   425,   425,   108,   131,   108,   131,    75,   158,
     159,   304,   305,    24,   158,   159,   304,   411,   309,    93,
     100,   114,    19,   425,   426,   425,   426,   309,   107,    75,
     309,    75,   309,    75,   107,   317,   107,   107,   316,   317,
      75,   176,    24,   298,    88,   298,    88,    34,   309,   100,
     100,   317,    75,    24,   155,   308,   155,   309,    88,     9,
      12,    43,    78,    80,   114,   170,   306,   385,   387,   397,
     398,   401,    86,   173,   389,    40,   333,   334,    23,   206,
     208,   309,   309,   309,   309,   212,   309,   309,    25,   309,
     455,   455,   457,    23,    23,   456,   454,    23,    67,   452,
     164,    33,    46,    71,    84,    85,   325,   326,   327,   328,
      47,   309,   157,   309,   308,   435,   441,   251,   469,   137,
     217,   220,   226,   227,   228,   234,   243,   249,   250,   436,
     444,   445,   446,   460,   463,   464,   466,   231,   238,   239,
     465,   213,   214,   215,   216,   241,   461,   133,   134,   135,
     412,   102,   155,   156,   309,   155,   308,   158,   158,    25,
      93,   306,   411,    47,   158,   159,    93,   306,   411,   158,
     159,   309,   155,   308,   102,   158,   158,   158,   158,   309,
     331,    25,    25,   309,   107,   309,   309,   107,   317,   107,
     315,   309,    47,    24,   298,   309,   309,   100,   320,   164,
     155,   114,    31,   154,   390,     7,   308,    19,   170,   397,
     170,   387,    75,   411,    67,   334,   164,   309,   309,   309,
     100,   157,    23,   158,   218,   219,   229,   230,   242,   462,
      47,   158,    47,   158,    24,   327,   328,   328,   324,   309,
     155,   158,   343,   240,   245,   468,   462,   438,   468,   340,
     343,   249,   444,   446,   439,   440,   462,   155,   410,    93,
     306,   305,    93,   306,   411,    93,   306,    93,   306,   411,
     155,   309,   309,   107,   309,    83,    24,    34,   309,   155,
     308,     3,    89,   393,   394,   396,   398,    22,    90,   391,
     392,   395,   398,   155,   173,    19,    19,   170,    25,   157,
      75,   157,   309,   309,   343,   343,   343,   343,    23,   236,
     451,   452,   451,   328,   240,   246,   263,   467,   467,   340,
     247,    93,   306,    93,   306,   309,   309,   298,   155,    31,
      89,   396,   154,    90,   395,   173,   173,    19,    32,   309,
      25,   309,   177,   462,    47,   158,   158,   173,   411,   157,
     343,   236,   452,   157,   309,   309
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
     525,   526,   527,   528
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   274,   275,   275,   275,   275,   276,   276,   277,   277,
     278,   279,   280,   280,   280,   281,   281,   282,   282,   283,
     283,   283,   283,   284,   284,   284,   284,   285,   285,   285,
     285,   285,   285,   285,   285,   286,   286,   287,   288,   288,
     289,   289,   290,   291,   292,   292,   293,   293,   294,   294,
     294,   294,   295,   296,   297,   297,   297,   297,   298,   298,
     299,   299,   300,   300,   300,   300,   301,   301,   301,   301,
     302,   302,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   304,   304,
     305,   305,   306,   307,   308,   308,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   310,   310,   310,   310,
     311,   311,   312,   312,   313,   314,   314,   315,   315,   315,
     315,   315,   315,   315,   315,   316,   317,   318,   319,   319,
     320,   320,   320,   320,   321,   322,   322,   323,   323,   324,
     324,   325,   325,   325,   325,   325,   325,   325,   326,   326,
     327,   327,   328,   329,   329,   330,   330,   331,   331,   332,
     332,   333,   333,   334,   334,   335,   336,   336,   337,   337,
     338,   338,   338,   338,   339,   339,   339,   340,   340,   341,
     341,   341,   342,   342,   342,   342,   342,   343,   343,   343,
     344,   344,   344,   345,   345,   346,   346,   347,   347,   348,
     348,   349,   349,   350,   350,   350,   350,   351,   351,   351,
     352,   352,   352,   352,   352,   352,   353,   353,   353,   353,
     353,   353,   354,   354,   354,   355,   355,   356,   356,   357,
     357,   358,   358,   359,   359,   359,   359,   360,   360,   360,
     361,   361,   362,   362,   362,   362,   363,   363,   364,   364,
     364,   364,   364,   364,   364,   365,   365,   366,   366,   367,
     367,   367,   367,   367,   368,   368,   369,   369,   370,   370,
     370,   371,   371,   372,   372,   373,   374,   374,   374,   374,
     374,   374,   374,   374,   375,   375,   376,   376,   376,   377,
     378,   378,   379,   380,   381,   382,   382,   383,   383,   384,
     384,   385,   385,   385,   386,   386,   386,   386,   386,   386,
     387,   387,   388,   388,   389,   390,   390,   391,   391,   392,
     392,   392,   392,   393,   393,   394,   394,   394,   394,   395,
     395,   396,   396,   397,   397,   397,   397,   398,   398,   398,
     398,   399,   399,   400,   400,   401,   402,   402,   402,   402,
     402,   402,   403,   404,   404,   404,   404,   405,   405,   405,
     405,   406,   407,   408,   408,   408,   408,   409,   409,   410,
     411,   411,   411,   412,   412,   412,   413,   413,   413,   414,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   416,
     417,   417,   417,   418,   419,   420,   420,   420,   421,   421,
     421,   421,   421,   422,   423,   423,   423,   423,   423,   423,
     423,   424,   425,   426,   427,   428,   429,   429,   429,   429,
     429,   430,   431,   431,   432,   433,   434,   434,   435,   435,
     435,   435,   436,   436,   436,   436,   437,   437,   438,   438,
     439,   439,   440,   440,   441,   441,   441,   442,   442,   443,
     443,   444,   444,   444,   444,   444,   445,   446,   446,   446,
     446,   446,   446,   446,   447,   447,   447,   447,   448,   448,
     448,   448,   449,   449,   450,   450,   450,   450,   450,   450,
     450,   451,   451,   452,   452,   452,   452,   453,   453,   453,
     453,   453,   454,   454,   455,   455,   456,   456,   457,   457,
     458,   459,   459,   460,   460,   460,   461,   461,   461,   461,
     461,   462,   462,   462,   462,   463,   464,   465,   466,   466,
     467,   467,   467,   468,   468,   469
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
       1,     3,     2,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     3,     2,     3,     5,     6,     2,     3,     5,
       6,     3,     3,     4,     5,     6,     7,     1,     2,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     3,     2,     2,     2,     3,     3,     2,     3,
       5,     3,     5,     3,     2,     3,     5,     5,     3,     5,
       5,     3,     1,     2,     1,     1,     4,     5,     5,     4,
       4,     2,     4,     5,     4,     6,     3,     5,     1,     2,
       3,     4,     1,     1,     2,     2,     1,     3,     1,     3,
       1,     3,     1,     2,     1,     2,     3,     1,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     4,     6,     4,     6,
       1,     1,     3,     2,     4,     4,     6,     2,     3,     1,
       2,     1,     1,     2,     2,     3,     1,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     4,     3,     3,     3,     2,     2,
       1,     1,     1,     1,     1,     2
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
  "\"'char literal and pi end'\"", "\"'element content'\"",
  "\"'<QName {>'\"", "\"'pref:*'\"", "\"'&entity;'\"",
  "\"'comment literal'\"", "\"'NCName'\"", "\"'pi <NCName {>'\"",
  "\"'pi target'\"", "\"'pragma literal and end'\"", "\"'*:QName'\"",
  "\"'QName'\"", "\"'QName #)'\"", "\"'<QName (>'\"",
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
       275,     0,    -1,   277,    -1,   276,   277,    -1,   278,    -1,
     276,   278,    -1,   197,    23,   164,    -1,   197,    23,    87,
      23,   164,    -1,   280,   307,    -1,   307,    -1,   279,   280,
      -1,   124,    14,    88,    24,   164,    -1,   281,   164,    -1,
     282,   164,    -1,   281,   164,   282,   164,    -1,   283,    -1,
     281,   164,   283,    -1,   284,    -1,   282,   164,   284,    -1,
     285,    -1,   286,    -1,   287,    -1,   289,    -1,   301,    -1,
     303,    -1,   290,    -1,   291,    -1,   288,    -1,   295,    -1,
     296,    -1,   302,    -1,   292,    -1,   293,    -1,   294,    -1,
     428,    -1,   297,    -1,   300,    -1,    62,    14,    88,    24,
      -1,    54,   152,    -1,    54,   172,    -1,    58,   125,    24,
      -1,    59,   125,    24,    -1,    63,    19,    23,    -1,   223,
     446,    -1,    64,   137,    -1,    64,   181,    -1,    60,    84,
      -1,    60,    85,    -1,    56,   152,    47,   108,    -1,    56,
     152,    47,   131,    -1,    56,   132,    47,   108,    -1,    56,
     132,    47,   131,    -1,    57,    24,    -1,    53,    24,    -1,
     106,    24,    -1,   106,   299,    24,    -1,   106,    24,    34,
     298,    -1,   106,   299,    24,    34,   298,    -1,    24,    -1,
     298,    47,    24,    -1,   125,    14,    88,    -1,    68,   125,
      -1,   105,    24,    -1,   105,   125,    14,    88,    24,    -1,
     105,    24,    34,   298,    -1,   105,   125,    14,    88,    24,
      34,   298,    -1,    66,    25,   100,   309,    -1,    66,    25,
      93,    -1,    66,    25,   410,   100,   309,    -1,    66,    25,
     410,    93,    -1,    55,   152,    -1,    55,   172,    -1,    61,
      19,   120,   158,    93,    -1,    61,    19,   120,   158,   306,
      -1,    61,    19,   120,   304,   158,    93,    -1,    61,    19,
     120,   304,   158,   306,    -1,    61,    19,   120,   159,   411,
      93,    -1,    61,    19,   120,   159,   411,   306,    -1,    61,
      19,   120,   304,   159,   411,    93,    -1,    61,    19,   120,
     304,   159,   411,   306,    -1,    65,    19,   120,   158,    93,
      -1,    65,    19,   120,   158,   306,    -1,    65,    19,   120,
     304,   158,    93,    -1,    65,    19,   120,   304,   158,   306,
      -1,    65,    19,   120,   159,   411,    93,    -1,    65,    19,
     120,   159,   411,   306,    -1,    65,    19,   120,   304,   159,
     411,    93,    -1,    65,    19,   120,   304,   159,   411,   306,
      -1,   305,    -1,   304,    47,   305,    -1,    75,    25,    -1,
      75,    25,   410,    -1,   114,   308,   155,    -1,   308,    -1,
     309,    -1,   308,    47,   309,    -1,   310,    -1,   329,    -1,
     332,    -1,   335,    -1,   336,    -1,   429,    -1,   430,    -1,
     432,    -1,   431,    -1,   433,    -1,   311,   157,   309,    -1,
     311,   321,   157,   309,    -1,   311,   322,   157,   309,    -1,
     311,   321,   322,   157,   309,    -1,   312,    -1,   311,   312,
      -1,   313,    -1,   318,    -1,    97,   314,    -1,   315,    -1,
     314,    47,    75,   315,    -1,    25,   107,   309,    -1,    25,
     410,   107,   309,    -1,    25,   316,   107,   309,    -1,    25,
     410,   316,   107,   309,    -1,    25,   317,   107,   309,    -1,
      25,   410,   317,   107,   309,    -1,    25,   316,   317,   107,
     309,    -1,    25,   410,   316,   317,   107,   309,    -1,    34,
      75,    25,    -1,   244,    75,    25,    -1,   118,   319,    -1,
     320,    -1,   319,    47,    75,   320,    -1,    25,   100,   309,
      -1,    25,   410,   100,   309,    -1,    25,   317,   100,   309,
      -1,    25,   410,   317,   100,   309,    -1,   194,   309,    -1,
     139,   323,    -1,   168,   323,    -1,   324,    -1,   323,    47,
     324,    -1,   309,    -1,   309,   325,    -1,   326,    -1,   327,
      -1,   328,    -1,   326,   327,    -1,   326,   328,    -1,   327,
     328,    -1,   326,   327,   328,    -1,    33,    -1,    71,    -1,
      84,    -1,    85,    -1,    46,    24,    -1,   167,   330,   160,
     309,    -1,    91,   330,   160,   309,    -1,   331,    -1,   330,
      47,    75,   331,    -1,    25,   107,   309,    -1,    25,   410,
     107,   309,    -1,   179,   308,   158,   333,    67,   157,   309,
      -1,   179,   308,   158,   333,    67,    75,    25,   157,   309,
      -1,   334,    -1,   333,   334,    -1,    40,   411,   157,   309,
      -1,    40,    75,    25,    32,   411,   157,   309,    -1,   104,
     308,   158,   176,   309,    83,   309,    -1,   337,    -1,   336,
     136,   337,    -1,   338,    -1,   337,    30,   338,    -1,   339,
      -1,   339,   353,   339,    -1,   339,   352,   339,    -1,   339,
     354,   339,    -1,   340,    -1,   340,   232,   435,    -1,   340,
     232,   435,   469,    -1,   341,    -1,   341,   177,   341,    -1,
     342,    -1,   341,   146,   342,    -1,   341,   122,   342,    -1,
     343,    -1,   342,   169,   343,    -1,   342,    72,   343,    -1,
     342,   103,   343,    -1,   342,   123,   343,    -1,   344,    -1,
     343,   180,   344,    -1,   343,   192,   344,    -1,   345,    -1,
     344,   111,   345,    -1,   344,    92,   345,    -1,   346,    -1,
     346,   109,   411,    -1,   347,    -1,   347,   178,   411,    -1,
     348,    -1,   348,    41,   409,    -1,   349,    -1,   349,    42,
     409,    -1,   351,    -1,   350,   351,    -1,   146,    -1,   122,
      -1,   350,   146,    -1,   350,   122,    -1,   355,    -1,   359,
      -1,   356,    -1,    88,    -1,   127,    -1,   121,    -1,   116,
      -1,   101,    -1,    99,    -1,   184,    -1,   189,    -1,   188,
      -1,   187,    -1,   186,    -1,   185,    -1,   112,    -1,   149,
      -1,    96,    -1,   190,   308,   155,    -1,    26,   114,   308,
     155,    -1,   357,   114,   155,    -1,   357,   114,   308,   155,
      -1,   358,    -1,   357,   358,    -1,   147,    19,    17,    -1,
     147,    20,    -1,   165,    -1,   165,   360,    -1,   166,   360,
      -1,   360,    -1,   361,    -1,   361,   165,   360,    -1,   361,
     166,   360,    -1,   362,    -1,   371,    -1,   363,    -1,   363,
     372,    -1,   366,    -1,   366,   372,    -1,   364,   368,    -1,
     365,    -1,    45,    -1,    69,    -1,    36,    -1,   163,    -1,
      70,    -1,    95,    -1,    94,    -1,   368,    -1,    39,   368,
      -1,   367,   368,    -1,    77,    -1,   140,    -1,    28,    -1,
     151,    -1,   150,    -1,    29,    -1,   415,    -1,   369,    -1,
      19,    -1,   370,    -1,   169,    -1,    11,    -1,    18,    -1,
     374,    -1,   374,   372,    -1,   373,    -1,   372,   373,    -1,
     115,   308,   156,    -1,   375,    -1,   377,    -1,   378,    -1,
     379,    -1,   382,    -1,   384,    -1,   380,    -1,   381,    -1,
     376,    -1,   427,    -1,    52,    -1,   110,    -1,    79,    -1,
      75,    25,    -1,   120,   158,    -1,   120,   308,   158,    -1,
      76,    -1,   138,   308,   155,    -1,   182,   308,   155,    -1,
      19,   120,   158,    -1,    19,   120,   383,   158,    -1,   309,
      -1,   383,    47,   309,    -1,   385,    -1,   402,    -1,   386,
      -1,   399,    -1,   400,    -1,   171,    19,    86,    -1,   171,
      19,   388,    86,    -1,   171,    19,   173,   170,    19,   173,
      -1,   171,    19,   173,   387,   170,    19,   173,    -1,   171,
      19,   388,   173,   170,    19,   173,    -1,   171,    19,   388,
     173,   387,   170,    19,   173,    -1,   397,    -1,   387,   397,
      -1,   389,    -1,   388,   389,    -1,    19,    88,   390,    -1,
     154,   391,   154,    -1,    31,   393,    31,    -1,    -1,   392,
      -1,    90,    -1,   395,    -1,   392,    90,    -1,   392,   395,
      -1,    -1,   394,    -1,    89,    -1,   396,    -1,   394,    89,
      -1,   394,   396,    -1,    22,    -1,   398,    -1,     3,    -1,
     398,    -1,   385,    -1,     9,    -1,   401,    -1,   398,    -1,
      12,    -1,    78,    -1,    80,    -1,   306,    -1,   195,    27,
     196,    -1,   195,   196,    -1,   141,    16,   142,    -1,   141,
      16,     8,    -1,    43,     7,    -1,   403,    -1,   404,    -1,
     405,    -1,   406,    -1,   407,    -1,   408,    -1,    73,   308,
     155,    -1,    10,   155,    -1,    10,   308,   155,    -1,    81,
     308,   155,   114,   155,    -1,    81,   308,   155,   114,   308,
     155,    -1,     4,   155,    -1,     4,   308,   155,    -1,    37,
     308,   155,   114,   155,    -1,    37,   308,   155,   114,   308,
     155,    -1,   174,   308,   155,    -1,    50,   308,   155,    -1,
     153,    14,   114,   155,    -1,   153,    14,   114,   308,   155,
      -1,   153,   114,   308,   155,   114,   155,    -1,   153,   114,
     308,   155,   114,   308,   155,    -1,   414,    -1,   414,   102,
      -1,    32,   411,    -1,   413,    -1,   413,   412,    -1,   193,
      -1,   133,    -1,   135,    -1,   134,    -1,   414,    -1,   415,
      -1,   113,    -1,    19,    -1,   417,    -1,   423,    -1,   421,
      -1,   424,    -1,   422,    -1,   420,    -1,   419,    -1,   418,
      -1,   416,    -1,   129,   158,    -1,    74,   158,    -1,    74,
     423,   158,    -1,    74,   424,   158,    -1,   175,   158,    -1,
      51,   158,    -1,   144,   158,    -1,   144,    14,   158,    -1,
     144,    23,   158,    -1,    38,   158,    -1,    38,    19,   158,
      -1,    38,    19,    47,   425,   158,    -1,    38,   169,   158,
      -1,    38,   169,    47,   425,   158,    -1,   161,    19,   158,
      -1,    82,   158,    -1,    82,    19,   158,    -1,    82,    19,
      47,   425,   158,    -1,    82,    19,    47,   426,   158,    -1,
      82,   169,   158,    -1,    82,   169,    47,   425,   158,    -1,
      82,   169,    47,   426,   158,    -1,   162,    19,   158,    -1,
      19,    -1,    19,   102,    -1,    23,    -1,   201,    -1,   203,
     309,   207,   309,    -1,   203,   309,    32,   206,   309,    -1,
     203,   309,    32,   208,   309,    -1,   203,   309,   198,   309,
      -1,   203,   309,   199,   309,    -1,   202,   309,    -1,   205,
     309,   212,   309,    -1,   205,   211,   309,   212,   309,    -1,
     204,   309,    32,   309,    -1,   210,   434,   209,   309,   157,
     309,    -1,    25,   100,   309,    -1,   434,   200,    25,   100,
     309,    -1,   437,    -1,   437,   436,    -1,   437,   249,   340,
      -1,   437,   436,   249,   340,    -1,   446,    -1,   444,    -1,
     436,   446,    -1,   436,   444,    -1,   438,    -1,   437,   234,
     438,    -1,   439,    -1,   438,   231,   439,    -1,   440,    -1,
     439,   238,   440,    -1,   441,    -1,   233,   441,    -1,   442,
      -1,   442,   465,    -1,   120,   435,   158,    -1,   443,    -1,
     443,   461,    -1,   375,    -1,   114,   308,   155,    -1,   445,
      -1,   464,    -1,   463,    -1,   466,    -1,   460,    -1,   137,
      -1,   447,    -1,   448,    -1,   449,    -1,   450,    -1,   453,
      -1,   458,    -1,   459,    -1,   237,    -1,   248,    -1,   222,
      -1,   221,    -1,   258,    -1,   252,    -1,   225,    -1,   224,
      -1,   259,    -1,   253,    -1,   261,   452,    -1,   261,    67,
      -1,   261,   120,   452,   158,    -1,   261,   120,   452,    47,
     451,   158,    -1,   261,   120,    67,   158,    -1,   261,   120,
      67,    47,   451,   158,    -1,   255,    -1,   452,    -1,   451,
      47,   452,    -1,    34,    23,    -1,    34,    23,   242,    23,
      -1,    34,    23,   462,   236,    -1,    34,    23,   242,    23,
     462,   236,    -1,   260,   455,    -1,   260,   455,   454,    -1,
     257,    -1,   257,   454,    -1,   254,    -1,   457,    -1,   454,
     457,    -1,    34,    23,    -1,   120,   456,   158,    -1,    23,
      -1,   456,    23,    -1,   180,   455,    -1,    92,   455,    -1,
     235,    23,    -1,   262,    -1,   256,    -1,   220,    -1,   217,
      -1,   228,    -1,   215,    -1,   216,    -1,   213,    -1,   214,
      -1,   241,    -1,   229,   343,    -1,   218,   343,    -1,   219,
     343,    -1,   230,   343,   177,   343,    -1,   227,   462,   467,
      -1,   250,   343,   467,    -1,   239,   462,   247,    -1,   243,
     468,    -1,   226,   468,    -1,   263,    -1,   246,    -1,   240,
      -1,   245,    -1,   240,    -1,   251,   343,    -1
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
    1116,  1118,  1122,  1125,  1129,  1133,  1136,  1138,  1140,  1142,
    1144,  1146,  1148,  1152,  1155,  1159,  1165,  1172,  1175,  1179,
    1185,  1192,  1196,  1200,  1205,  1211,  1218,  1226,  1228,  1231,
    1234,  1236,  1239,  1241,  1243,  1245,  1247,  1249,  1251,  1253,
    1255,  1257,  1259,  1261,  1263,  1265,  1267,  1269,  1271,  1273,
    1276,  1279,  1283,  1287,  1290,  1293,  1296,  1300,  1304,  1307,
    1311,  1317,  1321,  1327,  1331,  1334,  1338,  1344,  1350,  1354,
    1360,  1366,  1370,  1372,  1375,  1377,  1379,  1384,  1390,  1396,
    1401,  1406,  1409,  1414,  1420,  1425,  1432,  1436,  1442,  1444,
    1447,  1451,  1456,  1458,  1460,  1463,  1466,  1468,  1472,  1474,
    1478,  1480,  1484,  1486,  1489,  1491,  1494,  1498,  1500,  1503,
    1505,  1509,  1511,  1513,  1515,  1517,  1519,  1521,  1523,  1525,
    1527,  1529,  1531,  1533,  1535,  1537,  1539,  1541,  1543,  1545,
    1547,  1549,  1551,  1553,  1555,  1558,  1561,  1566,  1573,  1578,
    1585,  1587,  1589,  1593,  1596,  1601,  1606,  1613,  1616,  1620,
    1622,  1625,  1627,  1629,  1632,  1635,  1639,  1641,  1644,  1647,
    1650,  1653,  1655,  1657,  1659,  1661,  1663,  1665,  1667,  1669,
    1671,  1673,  1676,  1679,  1682,  1687,  1691,  1695,  1699,  1702,
    1705,  1707,  1709,  1711,  1713,  1715
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   727,   727,   735,   743,   749,   761,   767,   779,   789,
     804,   819,   834,   843,   852,   867,   876,   893,   902,   919,
     926,   933,   940,   952,   959,   966,   975,   988,   995,  1002,
    1009,  1016,  1023,  1030,  1039,  1052,  1059,  1077,  1092,  1100,
    1114,  1123,  1138,  1154,  1168,  1176,  1191,  1199,  1213,  1222,
    1231,  1240,  1262,  1276,  1290,  1300,  1310,  1320,  1336,  1345,
    1363,  1370,  1383,  1392,  1402,  1411,  1428,  1438,  1448,  1458,
    1474,  1482,  1496,  1506,  1517,  1528,  1540,  1552,  1564,  1576,
    1588,  1598,  1609,  1620,  1632,  1644,  1656,  1668,  1686,  1697,
    1714,  1723,  1738,  1752,  1766,  1775,  1790,  1797,  1804,  1811,
    1818,  1827,  1834,  1841,  1848,  1855,  1868,  1878,  1889,  1900,
    1917,  1926,  1941,  1948,  1961,  1975,  1984,  2001,  2011,  2022,
    2034,  2047,  2058,  2070,  2082,  2100,  2115,  2129,  2144,  2153,
    2170,  2181,  2193,  2204,  2222,  2236,  2244,  2259,  2268,  2285,
    2294,  2309,  2319,  2329,  2339,  2349,  2359,  2369,  2385,  2392,
    2405,  2413,  2427,  2441,  2451,  2467,  2477,  2492,  2501,  2517,
    2527,  2544,  2553,  2568,  2577,  2593,  2607,  2614,  2628,  2635,
    2657,  2664,  2675,  2686,  2703,  2710,  2720,  2736,  2743,  2757,
    2764,  2771,  2784,  2790,  2797,  2804,  2811,  2824,  2831,  2839,
    2853,  2860,  2867,  2880,  2887,  2902,  2909,  2924,  2931,  2946,
    2953,  2968,  2975,  2990,  2997,  3004,  3011,  3026,  3033,  3040,
    3054,  3061,  3068,  3075,  3082,  3089,  3102,  3109,  3116,  3123,
    3130,  3137,  3150,  3157,  3164,  3178,  3185,  3200,  3209,  3224,
    3233,  3250,  3259,  3301,  3308,  3315,  3322,  3336,  3344,  3351,
    3364,  3371,  3384,  3393,  3402,  3411,  3426,  3435,  3449,  3456,
    3463,  3470,  3477,  3484,  3491,  3504,  3511,  3524,  3533,  3548,
    3555,  3562,  3569,  3576,  3594,  3601,  3614,  3621,  3634,  3644,
    3654,  3670,  3677,  3692,  3701,  3718,  3732,  3739,  3746,  3753,
    3760,  3767,  3774,  3781,  3794,  3801,  3814,  3822,  3830,  3844,
    3857,  3864,  3878,  3891,  3905,  3964,  3973,  3988,  3997,  4012,
    4019,  4032,  4039,  4046,  4059,  4070,  4081,  4092,  4103,  4114,
    4132,  4141,  4156,  4165,  4182,  4197,  4205,  4220,  4226,  4233,
    4242,  4251,  4262,  4279,  4285,  4292,  4301,  4310,  4321,  4338,
    4346,  4360,  4368,  4382,  4390,  4398,  4407,  4422,  4431,  4439,
    4447,  4461,  4469,  4487,  4495,  4515,  4533,  4540,  4547,  4554,
    4561,  4568,  4581,  4595,  4604,  4613,  4621,  4649,  4658,  4667,
    4675,  4689,  4703,  4717,  4726,  4735,  4743,  4757,  4766,  4781,
    4795,  4804,  4813,  4853,  4861,  4869,  4883,  4890,  4897,  4910,
    4924,  4931,  4938,  4945,  4952,  4959,  4966,  4973,  4980,  4993,
    5006,  5013,  5021,  5035,  5048,  5061,  5068,  5075,  5088,  5097,
    5106,  5115,  5124,  5139,  5153,  5162,  5171,  5180,  5189,  5199,
    5209,  5225,  5249,  5259,  5282,  5324,  5336,  5342,  5348,  5354,
    5360,  5372,  5384,  5390,  5402,  5429,  5441,  5447,  5467,  5473,
    5479,  5485,  5497,  5503,  5509,  5515,  5527,  5533,  5545,  5551,
    5563,  5569,  5581,  5587,  5599,  5605,  5611,  5623,  5629,  5641,
    5647,  5659,  5665,  5671,  5677,  5683,  5695,  5707,  5714,  5721,
    5728,  5735,  5742,  5749,  5762,  5768,  5774,  5780,  5792,  5798,
    5804,  5810,  5822,  5828,  5840,  5846,  5852,  5858,  5864,  5870,
    5876,  5888,  5894,  5906,  5912,  5918,  5924,  5936,  5942,  5948,
    5954,  5960,  5972,  5978,  5990,  5996,  6008,  6014,  6026,  6032,
    6044,  6056,  6062,  6074,  6080,  6086,  6098,  6104,  6110,  6116,
    6122,  6134,  6140,  6146,  6152,  6164,  6176,  6188,  6200,  6206,
    6218,  6224,  6230,  6242,  6248,  6260
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
     265,   266,   267,   268,   269,   270,   271,   272,   273
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 3863;
  const int xquery_parser::yynnts_ = 196;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 313;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 274;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 528;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace yy

#line 6270 "/Users/mbrantner/misc/code/vanilla/datatypes/src/compiler/parser/xquery_parser.y"



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





