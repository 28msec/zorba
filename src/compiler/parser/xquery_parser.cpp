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
#line 127 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"


/* Line 317 of lalr1.cc.  */
#line 46 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"

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
    #line 86 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = driver.filename.getStore();
}
  /* Line 547 of yacc.c.  */
#line 283 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
#line 747 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [main]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr((yyval.node));
		;}
    break;

  case 3:
#line 755 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr((yyval.node));
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.main]" << endl;
#endif
		;}
    break;

  case 4:
#line 763 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [library]" << endl;
#endif
		;}
    break;

  case 5:
#line 769 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.library]" << endl;
#endif
		;}
    break;

  case 6:
#line 781 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version]" << endl;
#endif
		;}
    break;

  case 7:
#line 787 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version.encoding]" << endl;
#endif
		;}
    break;

  case 8:
#line 799 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 809 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 824 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 839 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 854 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 863 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 872 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 887 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 896 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 913 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 922 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 939 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [setter]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 946 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [import]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 953 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 960 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [default namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 972 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [var]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 979 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [function]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 986 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [option]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 995 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [ftoption]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 1008 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [boundary space]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 1015 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [default collation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 1022 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [base uri]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 1029 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [construction]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 1036 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [ordering mode]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 1043 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [empty order]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 1050 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [copy namespaces]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 1059 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [revalidation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 1072 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [schema]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 1079 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [module]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 1097 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1112 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [preserve]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 39:
#line 1120 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [strip]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 40:
#line 1134 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1143 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1158 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1174 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOptionDecl [ ]" << endl;
#endif
			(yyval.node) = new FTOptionDecl(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 44:
#line 1188 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [ordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 45:
#line 1196 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [unordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 46:
#line 1211 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty greatest]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 47:
#line 1219 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty least]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 48:
#line 1233 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1242 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1251 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1260 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1282 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultCollationMode [ ]" << endl;
#endif
			(yyval.node) = new DefaultCollationDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 53:
#line 1296 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BaseURIDecl [ ]" << endl;
#endif
			(yyval.node) = new BaseURIDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 54:
#line 1310 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1320 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1330 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1340 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1356 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1365 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1383 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [namespace]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1390 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [default element]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(driver.createQueryLoc((yyloc)), true);
		;}
    break;

  case 62:
#line 1403 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1412 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1422 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1431 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1448 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1458 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1468 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1478 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1494 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [preserve]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 71:
#line 1502 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [strip]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 72:
#line 1516 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1526 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1537 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1548 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1560 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1572 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1584 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1596 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1608 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1618 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1629 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1640 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1652 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1664 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1676 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1688 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1706 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1717 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1734 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1743 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1758 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EnclosedExpr [ ]" << endl;
#endif
			(yyval.expr) = new EnclosedExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1772 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QueryBody [expr]" << endl;
#endif
			(yyval.expr) = new QueryBody(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 94:
#line 1786 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1795 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1810 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [FLWORExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 97:
#line 1817 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [QuantifiedExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1824 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TypeswitchExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1831 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [IfExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1838 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [OrExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1847 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [InsertExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1854 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [DeleteExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1861 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [RenameExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1868 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [ReplaceExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1875 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TransformExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1882 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
      cout << "ExprSingle [TryExpr]" << endl;
#endif
    ;}
    break;

  case 107:
#line 1894 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 108:
#line 1904 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 109:
#line 1915 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 110:
#line 1926 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 111:
#line 1943 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClauseList [single]" << endl;
#endif
			ForLetClauseList* flc_list_p = new ForLetClauseList(driver.createQueryLoc((yyloc)));
			flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = flc_list_p;
		;}
    break;

  case 112:
#line 1952 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClauseList [list]" << endl;
#endif
			ForLetClauseList* flc_list_p = dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(2) - (1)].node));
			if (flc_list_p) flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 113:
#line 1967 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [for]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 114:
#line 1974 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [let]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 115:
#line 1987 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForClause [ ]" << endl;
#endif
			(yyval.node) = new ForClause(driver.createQueryLoc((yyloc)),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 116:
#line 2001 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDeclList [single]" << endl;
#endif
			VarInDeclList* vardecl_list_p = new VarInDeclList(driver.createQueryLoc((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 117:
#line 2010 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 118:
#line 2027 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 119:
#line 2037 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 120:
#line 2048 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 121:
#line 2060 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 122:
#line 2073 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 123:
#line 2084 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 124:
#line 2096 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 125:
#line 2108 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 126:
#line 2126 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PositionalVar [ ]" << endl;
#endif
			(yyval.node) = new PositionalVar(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 127:
#line 2141 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTScoreVar [ ]" << endl;
#endif
			(yyval.node) = new FTScoreVar(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 128:
#line 2155 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClause [ ]" << endl;
#endif
			(yyval.node) = new LetClause(driver.createQueryLoc((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)));
			
		;}
    break;

  case 129:
#line 2170 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDeclList [single]" << endl;
#endif
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(driver.createQueryLoc((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 130:
#line 2179 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 131:
#line 2196 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 132:
#line 2207 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 133:
#line 2219 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 134:
#line 2230 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 135:
#line 2248 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "WhereClause [ ]" << endl;
#endif
			(yyval.node) = new WhereClause(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 136:
#line 2262 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [ ]" << endl;
#endif
			(yyval.node) = new OrderByClause(driver.createQueryLoc((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 137:
#line 2270 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [stable]" << endl;
#endif
			(yyval.node) = new OrderByClause(driver.createQueryLoc((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)),
								true);
		;}
    break;

  case 138:
#line 2285 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpecList [single]" << endl;
#endif
			OrderSpecList* osl_p = new OrderSpecList(driver.createQueryLoc((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 139:
#line 2294 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 140:
#line 2311 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpec [single]" << endl;
#endif
			(yyval.node) = new OrderSpec(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 141:
#line 2320 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpec [single.modifier]" << endl;
#endif
			(yyval.node) = new OrderSpec(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 142:
#line 2335 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 143:
#line 2345 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 144:
#line 2355 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 145:
#line 2365 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 146:
#line 2375 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 147:
#line 2385 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 148:
#line 2395 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 149:
#line 2411 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [ascending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(driver.createQueryLoc((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 150:
#line 2418 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [descending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(driver.createQueryLoc((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 151:
#line 2431 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [greatest]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(driver.createQueryLoc((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 152:
#line 2439 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [least]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(driver.createQueryLoc((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 153:
#line 2453 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderCollationSpec [ ]" << endl;
#endif
			(yyval.node) = new OrderCollationSpec(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 154:
#line 2467 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 155:
#line 2477 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 156:
#line 2493 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDeclList [single]" << endl;
#endif
			QVarInDeclList* qvid_list_p = new QVarInDeclList(driver.createQueryLoc((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 157:
#line 2503 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDeclList [list]" << endl;
#endif
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 158:
#line 2518 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDecl [in]" << endl;
#endif
			(yyval.node) = new QVarInDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 159:
#line 2527 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 160:
#line 2543 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 161:
#line 2553 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 162:
#line 2570 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClauseList [single]" << endl;
#endif
			CaseClauseList* cc_list_p = new CaseClauseList(driver.createQueryLoc((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 163:
#line 2579 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClauseList [list]" << endl;
#endif
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 164:
#line 2594 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClause [case.return]" << endl;
#endif
			(yyval.node) = new CaseClause(driver.createQueryLoc((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 165:
#line 2603 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 166:
#line 2619 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IfExpr [ ]" << endl;
#endif
			(yyval.expr) = new IfExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 167:
#line 2633 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [and]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 168:
#line 2640 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [or.and]" << endl;
#endif
			(yyval.expr) = new OrExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 169:
#line 2654 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [comp]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 170:
#line 2661 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [and.comp]" << endl;
#endif
			(yyval.expr) = new AndExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 171:
#line 2683 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 172:
#line 2690 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 173:
#line 2701 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 174:
#line 2712 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 175:
#line 2729 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 176:
#line 2736 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 177:
#line 2746 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 178:
#line 2762 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 179:
#line 2769 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add.to.add]" << endl;
#endif
			(yyval.expr) = new RangeExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 180:
#line 2783 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 181:
#line 2790 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult+mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 182:
#line 2797 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult-mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 183:
#line 2810 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [union]" << endl;
#endif
		;}
    break;

  case 184:
#line 2816 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult*union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 185:
#line 2823 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.div.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 186:
#line 2830 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.idiv.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 187:
#line 2837 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.mod.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 188:
#line 2850 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [interexcept]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 189:
#line 2857 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union.union.interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 190:
#line 2865 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union|interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 191:
#line 2879 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [instanceof]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 192:
#line 2886 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.inter.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 193:
#line 2893 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.except.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 194:
#line 2906 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 195:
#line 2913 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat.seqtype]" << endl;
#endif
			(yyval.expr) = new InstanceofExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 196:
#line 2928 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 197:
#line 2935 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable.seqtype]" << endl;
#endif
			(yyval.expr) = new TreatExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 198:
#line 2950 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 199:
#line 2957 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast.singletype]" << endl;
#endif
			(yyval.expr) = new CastableExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 200:
#line 2972 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 201:
#line 2979 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary.singletype]" << endl;
#endif
			(yyval.expr) = new CastExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 202:
#line 2994 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [value]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 203:
#line 3001 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [signlist.value]" << endl;
#endif
			(yyval.expr) = new UnaryExpr(driver.createQueryLoc((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 204:
#line 3016 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [+]" << endl;
#endif
			(yyval.node) = new SignList(driver.createQueryLoc((yyloc)), true);
		;}
    break;

  case 205:
#line 3023 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [-]" << endl;
#endif
			(yyval.node) = new SignList(driver.createQueryLoc((yyloc)), false);
		;}
    break;

  case 206:
#line 3030 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.+]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 207:
#line 3037 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.-]" << endl;
#endif
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 208:
#line 3052 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [validate]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 209:
#line 3059 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [path]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 210:
#line 3066 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [extension]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 211:
#line 3080 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [=]" << endl;
#endif
			(yyval.node) = new GeneralComp(driver.createQueryLoc((yyloc)), ParseConstants::op_eq);
		;}
    break;

  case 212:
#line 3087 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [!=]" << endl;
#endif
			(yyval.node) = new GeneralComp(driver.createQueryLoc((yyloc)), ParseConstants::op_ne);
		;}
    break;

  case 213:
#line 3094 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<]" << endl;
#endif
			(yyval.node) = new GeneralComp(driver.createQueryLoc((yyloc)), ParseConstants::op_lt);
		;}
    break;

  case 214:
#line 3101 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<=]" << endl;
#endif
			(yyval.node) = new GeneralComp(driver.createQueryLoc((yyloc)), ParseConstants::op_le);
		;}
    break;

  case 215:
#line 3108 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>]" << endl;
#endif
			(yyval.node) = new GeneralComp(driver.createQueryLoc((yyloc)), ParseConstants::op_gt);
		;}
    break;

  case 216:
#line 3115 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>=]" << endl;
#endif
			(yyval.node) = new GeneralComp(driver.createQueryLoc((yyloc)), ParseConstants::op_ge);
		;}
    break;

  case 217:
#line 3128 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [eq]" << endl;
#endif
			(yyval.node) = new ValueComp(driver.createQueryLoc((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 218:
#line 3135 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ne]" << endl;
#endif
			(yyval.node) = new ValueComp(driver.createQueryLoc((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 219:
#line 3142 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [lt]" << endl;
#endif
			(yyval.node) = new ValueComp(driver.createQueryLoc((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 220:
#line 3149 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [le]" << endl;
#endif
			(yyval.node) = new ValueComp(driver.createQueryLoc((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 221:
#line 3156 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [gt]" << endl;
#endif
			(yyval.node) = new ValueComp(driver.createQueryLoc((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 222:
#line 3163 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ge]" << endl;
#endif
			(yyval.node) = new ValueComp(driver.createQueryLoc((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 223:
#line 3176 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [is]" << endl;
#endif
			(yyval.node) = new NodeComp(driver.createQueryLoc((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 224:
#line 3183 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [<<]" << endl;
#endif
			(yyval.node) = new NodeComp(driver.createQueryLoc((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 225:
#line 3190 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [>>]" << endl;
#endif
			(yyval.node) = new NodeComp(driver.createQueryLoc((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 226:
#line 3204 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [expr]" << endl;
#endif
			(yyval.expr) = new ValidateExpr(driver.createQueryLoc((yyloc)), "strict", (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 227:
#line 3211 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [mode.expr]" << endl;
#endif
			(yyval.expr) = new ValidateExpr(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 228:
#line 3226 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExtensionExpr [pragmalist]" << endl;
#endif
			(yyval.expr) = new ExtensionExpr(driver.createQueryLoc((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 229:
#line 3235 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExtensionExpr [pragmalist.expr]" << endl;
#endif
			(yyval.expr) = new ExtensionExpr(driver.createQueryLoc((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 230:
#line 3250 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PragmaList [single]" << endl;
#endif
			PragmaList* pragma_list_p = new PragmaList(driver.createQueryLoc((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 231:
#line 3259 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 232:
#line 3276 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Pragma [ ]" << endl;
#endif
			(yyval.node) = new Pragma(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 233:
#line 3284 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 234:
#line 3327 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/]" << endl;
#endif
			(yyval.expr) = new PathExpr(driver.createQueryLoc((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 235:
#line 3334 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(driver.createQueryLoc((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 236:
#line 3341 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [//relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(driver.createQueryLoc((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 237:
#line 3348 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [relative]" << endl;
#endif
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = rpe == NULL ? (yysemantic_stack_[(1) - (1)].expr) : new PathExpr(driver.createQueryLoc((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 238:
#line 3362 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step]" << endl;
#endif
            AxisStep *as = dynamic_cast<AxisStep *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = as != NULL ? new RelativePathExpr(driver.createQueryLoc((yyloc)), ParseConstants::st_slash, new ContextItemExpr(driver.createQueryLoc((yyloc))), (yysemantic_stack_[(1) - (1)].expr)) : (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 239:
#line 3370 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step/relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(driver.createQueryLoc((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 240:
#line 3377 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step//relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(driver.createQueryLoc((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 241:
#line 3390 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [axis]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 242:
#line 3397 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [filter]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 243:
#line 3410 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward]" << endl;
#endif
			(yyval.expr) = new AxisStep(driver.createQueryLoc((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 244:
#line 3419 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward.predlist]" << endl;
#endif
			(yyval.expr) = new AxisStep(driver.createQueryLoc((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 245:
#line 3428 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse]" << endl;
#endif
			(yyval.expr) = new AxisStep(driver.createQueryLoc((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 246:
#line 3437 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse.predlist]" << endl;
#endif
			(yyval.expr) = new AxisStep(driver.createQueryLoc((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 247:
#line 3452 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [nodetest]" << endl;
#endif
			(yyval.node) = new ForwardStep(driver.createQueryLoc((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 248:
#line 3461 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [abbrev]" << endl;
#endif
			(yyval.node) = new ForwardStep(driver.createQueryLoc((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 249:
#line 3475 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [child]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 250:
#line 3482 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 251:
#line 3489 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [attribute]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 252:
#line 3496 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 253:
#line 3503 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant_or_self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 254:
#line 3510 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following_sibling]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 255:
#line 3517 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 256:
#line 3530 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(driver.createQueryLoc((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 257:
#line 3537 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [@ nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(driver.createQueryLoc((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 258:
#line 3550 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [nodetest]" << endl;
#endif
			(yyval.node) = new ReverseStep(driver.createQueryLoc((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 259:
#line 3559 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [..]" << endl;
#endif
			ReverseAxis* rev_p = new ReverseAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(driver.createQueryLoc((yyloc)),
								rev_p);
		;}
    break;

  case 260:
#line 3574 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [parent]" << endl;
#endif
			(yyval.node) = new ReverseAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 261:
#line 3581 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor]" << endl;
#endif
			(yyval.node) = new ReverseAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 262:
#line 3588 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding_sibling]" << endl;
#endif
			(yyval.node) = new ReverseAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 263:
#line 3595 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding]" << endl;
#endif
			(yyval.node) = new ReverseAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 264:
#line 3602 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor_or_self]" << endl;
#endif
			(yyval.node) = new ReverseAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 265:
#line 3620 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [kindtest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 266:
#line 3627 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [nametest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 267:
#line 3640 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [qname]" << endl;
#endif
			(yyval.node) = new NameTest(driver.createQueryLoc((yyloc)), new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 268:
#line 3647 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [wildcard]" << endl;
#endif
			(yyval.node) = new NameTest(driver.createQueryLoc((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 269:
#line 3660 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 270:
#line 3670 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 271:
#line 3680 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 272:
#line 3696 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 273:
#line 3703 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary.predlist]" << endl;
#endif
			(yyval.expr) = new FilterExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 274:
#line 3718 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PredicateList [single]" << endl;
#endif
			PredicateList* pred_list_p = new PredicateList(driver.createQueryLoc((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 275:
#line 3727 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 276:
#line 3744 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Predicate [ ]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 277:
#line 3758 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [literal]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 278:
#line 3765 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [varref]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 279:
#line 3772 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [paren]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 280:
#line 3779 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [context_item]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 281:
#line 3786 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [funcall]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 282:
#line 3793 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [cons]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 283:
#line 3800 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [ordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 284:
#line 3807 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [unordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 285:
#line 3820 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [numeric]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 286:
#line 3827 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [string]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 287:
#line 3840 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [decimal]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(driver.createQueryLoc((yyloc)), *yylval.decval);
      delete yylval.decval;
		;}
    break;

  case 288:
#line 3848 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [int]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(driver.createQueryLoc((yyloc)), *yylval.ival);
      delete yylval.ival;
		;}
    break;

  case 289:
#line 3856 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [double]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(driver.createQueryLoc((yyloc)), *yylval.dval);
      delete yylval.dval;
		;}
    break;

  case 290:
#line 3870 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarRef [ ]" << endl;
#endif
			(yyval.expr) = new VarRef(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 291:
#line 3883 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [()]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(driver.createQueryLoc((yyloc)), NULL);
		;}
    break;

  case 292:
#line 3890 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [(expr)]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 293:
#line 3904 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ContextItemExpr [.]" << endl;
#endif
			(yyval.expr) = new ContextItemExpr(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 294:
#line 3917 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new OrderedExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 295:
#line 3931 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnorderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new UnorderedExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 296:
#line 3990 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [ ]" << endl;
#endif
			(yyval.expr) = new FunctionCall(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 297:
#line 3999 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [arglist]" << endl;
#endif
			(yyval.expr) = new FunctionCall(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 298:
#line 4014 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [single]" << endl;
#endif
			ArgList* a_list_p = new ArgList(driver.createQueryLoc((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 299:
#line 4023 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [list]" << endl;
#endif
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 300:
#line 4038 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [direct]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 301:
#line 4045 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [computed]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 4058 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [element]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 303:
#line 4065 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 304:
#line 4072 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 305:
#line 4085 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 306:
#line 4096 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 307:
#line 4107 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 308:
#line 4118 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 309:
#line 4129 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 310:
#line 4140 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 311:
#line 4158 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [single]" << endl;
#endif
			DirElemContentList* elem_content_list_p = new DirElemContentList(driver.createQueryLoc((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 312:
#line 4167 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [list]" << endl;
#endif
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 313:
#line 4182 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeList [single]" << endl;
#endif
			DirAttributeList* at_list_p = new DirAttributeList(driver.createQueryLoc((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 314:
#line 4191 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 315:
#line 4208 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttr [ ]" << endl;
#endif
			(yyval.node) = new DirAttr(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 316:
#line 4223 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [quote]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(driver.createQueryLoc((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 317:
#line 4231 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [apos]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(driver.createQueryLoc((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 318:
#line 4245 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList[empty]" << endl;
#endif
			(yyval.node) = new QuoteAttrContentList(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 319:
#line 4252 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 320:
#line 4259 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [""]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(driver.createQueryLoc((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(driver.createQueryLoc((yyloc)),string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 321:
#line 4268 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [single]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(driver.createQueryLoc((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 322:
#line 4277 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 323:
#line 4288 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 324:
#line 4304 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']" << endl;
#endif
			(yyval.node) = new AposAttrContentList(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 325:
#line 4311 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 326:
#line 4318 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']" << endl;
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList(driver.createQueryLoc((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(driver.createQueryLoc((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 327:
#line 4327 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [single]" << endl;
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList(driver.createQueryLoc((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 328:
#line 4336 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 329:
#line 4347 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 330:
#line 4364 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [quote_attr_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 331:
#line 4372 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(driver.createQueryLoc((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 332:
#line 4386 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [apos_attr_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 333:
#line 4394 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(driver.createQueryLoc((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 334:
#line 4408 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cons]" << endl;
#endif
			(yyval.expr) = new DirElemContent(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 335:
#line 4416 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [elem_content]" << endl;
#endif
			(yyval.expr) = new DirElemContent(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 336:
#line 4424 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cdata]" << endl;
#endif
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(driver.createQueryLoc((yyloc)),
								cdata_h);
		;}
    break;

  case 337:
#line 4433 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [common_content]" << endl;
#endif
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(driver.createQueryLoc((yyloc)),
								cont_h);
		;}
    break;

  case 338:
#line 4448 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [entity_ref]" << endl;
#endif
			(yyval.expr) = new CommonContent(driver.createQueryLoc((yyloc)),
								ParseConstants::cont_entity,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 339:
#line 4457 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [{{]" << endl;
#endif
			(yyval.expr) = new CommonContent(driver.createQueryLoc((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 340:
#line 4465 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [}}]" << endl;
#endif
			(yyval.expr) = new CommonContent(driver.createQueryLoc((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 341:
#line 4473 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [expr]" << endl;
#endif
			(yyval.expr) = new CommonContent(driver.createQueryLoc((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 342:
#line 4487 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirCommentConstructor [ ]" << endl;
#endif
			(yyval.expr) = new DirCommentConstructor(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 343:
#line 4495 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "DirCommentConstructor [ ]" << endl;
#endif
      (yyval.expr) = new DirCommentConstructor(driver.createQueryLoc((yyloc)), "");
    ;}
    break;

  case 344:
#line 4513 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new DirPIConstructor(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 345:
#line 4521 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target.charlit]" << endl;
#endif
			(yyval.expr) = new DirPIConstructor(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 346:
#line 4541 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CDataSection [ ]" << endl;
#endif
			(yyval.expr) = new CDataSection(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 347:
#line 4559 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [doc]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 348:
#line 4566 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [elem]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 349:
#line 4573 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [attr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 350:
#line 4580 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [text]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 351:
#line 4587 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 352:
#line 4594 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 353:
#line 4607 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompDocConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompDocConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 354:
#line 4621 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 355:
#line 4630 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 356:
#line 4639 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 357:
#line 4647 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name.content]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 358:
#line 4675 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 359:
#line 4684 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [val]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 360:
#line 4693 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 361:
#line 4701 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name.val]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 362:
#line 4715 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompTextConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompTextConstructor(driver.createQueryLoc((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 363:
#line 4729 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompCommentConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompCommentConstructor(driver.createQueryLoc((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 364:
#line 4743 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 365:
#line 4752 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 366:
#line 4761 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 367:
#line 4769 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target.content]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 368:
#line 4783 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic]" << endl;
#endif
			(yyval.node) = new SingleType(driver.createQueryLoc((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 369:
#line 4792 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic ?]" << endl;
#endif
			(yyval.node) = new SingleType(driver.createQueryLoc((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 370:
#line 4807 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeDeclaration [as seqtype]" << endl;
#endif
			(yyval.node) = new TypeDeclaration(driver.createQueryLoc((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 371:
#line 4821 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type]" << endl;
#endif
			(yyval.node) = new SequenceType(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 372:
#line 4830 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type.occurs]" << endl;
#endif
			(yyval.node) = new SequenceType(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 373:
#line 4839 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [void]" << endl;
#endif
			(yyval.node) = new SequenceType(driver.createQueryLoc((yyloc)), NULL, NULL);
		;}
    break;

  case 374:
#line 4879 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [?]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(driver.createQueryLoc((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 375:
#line 4887 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [*]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(driver.createQueryLoc((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 376:
#line 4895 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [+]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(driver.createQueryLoc((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 377:
#line 4909 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [atomic]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 378:
#line 4916 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [kind]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 379:
#line 4923 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [item]" << endl;
#endif
			(yyval.node) = new ItemType(driver.createQueryLoc((yyloc)),true);
		;}
    break;

  case 380:
#line 4936 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AtomicType [qname]" << endl;
#endif
			(yyval.node) = new AtomicType(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 381:
#line 4950 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [doc]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 382:
#line 4957 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 383:
#line 4964 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 384:
#line 4971 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 385:
#line 4978 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 386:
#line 4985 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [pi]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 387:
#line 4992 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [comment]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 388:
#line 4999 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [text]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 389:
#line 5006 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [any]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 390:
#line 5019 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AnyKindTest [ ]" << endl;
#endif
			(yyval.node) = new AnyKindTest(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 391:
#line 5032 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [ ]" << endl;
#endif
			(yyval.node) = new DocumentTest(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 392:
#line 5039 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(driver.createQueryLoc((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 393:
#line 5047 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [schema_elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(driver.createQueryLoc((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 394:
#line 5061 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TextTest [ ]" << endl;
#endif
			(yyval.node) = new TextTest(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 395:
#line 5074 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommentTest [ ]" << endl;
#endif
			(yyval.node) = new CommentTest(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 396:
#line 5087 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ ]" << endl;
#endif
			(yyval.node) = new PITest(driver.createQueryLoc((yyloc)), "");
		;}
    break;

  case 397:
#line 5094 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ncname]" << endl;
#endif
			(yyval.node) = new PITest(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 398:
#line 5101 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [stringlit]" << endl;
#endif
			(yyval.node) = new PITest(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 399:
#line 5114 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [ ]" << endl;
#endif
			(yyval.node) = new AttributeTest(driver.createQueryLoc((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 400:
#line 5123 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name]" << endl;
#endif
			(yyval.node) = new AttributeTest(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL);
		;}
    break;

  case 401:
#line 5132 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name.type]" << endl;
#endif
			(yyval.node) = new AttributeTest(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 402:
#line 5141 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*]" << endl;
#endif
			(yyval.node) = new AttributeTest(driver.createQueryLoc((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 403:
#line 5150 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*.type]" << endl;
#endif
			(yyval.node) = new AttributeTest(driver.createQueryLoc((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 404:
#line 5165 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaAttributeTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaAttributeTest(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 405:
#line 5179 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [ ]" << endl;
#endif
			(yyval.node) = new ElementTest(driver.createQueryLoc((yyloc)),
									NULL,
									NULL);
		;}
    break;

  case 406:
#line 5188 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name]" << endl;
#endif
			(yyval.node) = new ElementTest(driver.createQueryLoc((yyloc)),
									new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
									NULL);
		;}
    break;

  case 407:
#line 5197 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5206 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name.type]" << endl;
#endif
			(yyval.node) = new ElementTest(driver.createQueryLoc((yyloc)),
									new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 409:
#line 5215 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 410:
#line 5225 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5235 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
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

  case 412:
#line 5251 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaElementTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaElementTest(driver.createQueryLoc((yyloc)),
									new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 413:
#line 5275 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name]" << endl;
#endif
			(yyval.node) = new TypeName(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 414:
#line 5285 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name?]" << endl;
#endif
			(yyval.node) = new TypeName(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 415:
#line 5308 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StringLiteral [ ]" << endl;
#endif
			(yyval.expr) = new StringLiteral(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 416:
#line 5350 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [strict]" << endl;
#endif
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 417:
#line 5358 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [lax]" << endl;
#endif
    ;}
    break;

  case 418:
#line 5364 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [skip]" << endl;
#endif
    ;}
    break;

  case 419:
#line 5375 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  driver.createQueryLoc((yyloc)),
                  InsertExpr::NODE_INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 420:
#line 5384 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.as_first]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  driver.createQueryLoc((yyloc)),
                  InsertExpr::NODE_AS_FIRST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 421:
#line 5393 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.as_last]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  driver.createQueryLoc((yyloc)),
                  InsertExpr::NODE_AS_LAST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 422:
#line 5402 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.after]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  driver.createQueryLoc((yyloc)),
                  InsertExpr::NODE_AFTER, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 423:
#line 5411 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.before]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  driver.createQueryLoc((yyloc)),
                  InsertExpr::NODE_BEFORE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 424:
#line 5421 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  driver.createQueryLoc((yyloc)),
                  InsertExpr::NODES_INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 425:
#line 5430 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.as_first]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  driver.createQueryLoc((yyloc)),
                  InsertExpr::NODES_AS_FIRST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 426:
#line 5439 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.as_last]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  driver.createQueryLoc((yyloc)),
                  InsertExpr::NODES_AS_LAST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 427:
#line 5448 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.after]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  driver.createQueryLoc((yyloc)),
                  InsertExpr::NODES_AFTER, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 428:
#line 5457 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.before]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  driver.createQueryLoc((yyloc)),
                  InsertExpr::NODES_BEFORE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 429:
#line 5472 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteNodeExpr [expr]" << endl;
#endif
       (yyval.expr) = new DeleteExpr(
                  driver.createQueryLoc((yyloc)),
                  DeleteExpr::NODE, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 430:
#line 5482 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteNodesExpr [expr]" << endl;
#endif
       (yyval.expr) = new DeleteExpr(
                  driver.createQueryLoc((yyloc)),
                  DeleteExpr::NODES, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 431:
#line 5497 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceExpr [expr.expr]" << endl;
#endif
       (yyval.expr) = new ReplaceExpr(
                  driver.createQueryLoc((yyloc)),
                  ReplaceExpr::WITH, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 432:
#line 5506 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceValueOfExpr [value.expr]" << endl;
#endif
       (yyval.expr) = new ReplaceExpr(
                  driver.createQueryLoc((yyloc)),
                  ReplaceExpr::VALUE_OF_WITH, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 433:
#line 5521 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RenameExpr [expr.expr]" << endl;
#endif
       (yyval.expr) = new RenameExpr(
                  driver.createQueryLoc((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 434:
#line 5550 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TransformExpr [ ]" << endl;
#endif
		;}
    break;

  case 435:
#line 5562 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [single]" << endl;
#endif
		;}
    break;

  case 436:
#line 5568 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [list]" << endl;
#endif
		;}
    break;

  case 437:
#line 5580 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "VarNameDecl [" << driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)) << "]" << endl;
#endif
    ;}
    break;

  case 438:
#line 5596 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TryExpr []" << endl;
#endif
       (yyval.expr) = new TryExpr(driver.createQueryLoc((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 439:
#line 5606 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchList [single]" << endl;
#endif
       CatchListExpr* aCatchListExpr = new CatchListExpr(driver.createQueryLoc((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 440:
#line 5616 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchList [list]" << endl;
#endif
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 441:
#line 5630 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchExpr [NameTest]" << endl;
#endif
       (yyval.expr) = new CatchExpr(driver.createQueryLoc((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 442:
#line 5640 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchExpr [NameTest,VarName]" << endl;
#endif
       QName* lQName = new QName(
                         driver.createQueryLoc((yyloc)), 
                         driver.symtab.get((off_t)(yysemantic_stack_[(7) - (5)].sval))
                       );
       (yyval.expr) = new CatchExpr(driver.createQueryLoc((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(7) - (2)].node)),
                          lQName,
                          (yysemantic_stack_[(7) - (7)].expr));
    ;}
    break;

  case 443:
#line 5667 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or]" << endl;
#endif
		;}
    break;

  case 444:
#line 5673 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity]" << endl;
#endif
		;}
    break;

  case 445:
#line 5679 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.weight_range]" << endl;
#endif
		;}
    break;

  case 446:
#line 5685 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity.weight_range]" << endl;
#endif
		;}
    break;

  case 447:
#line 5697 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_single]" << endl;
#endif
		;}
    break;

  case 448:
#line 5703 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_single]" << endl;
#endif
		;}
    break;

  case 449:
#line 5709 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_list]" << endl;
#endif
		;}
    break;

  case 450:
#line 5715 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_list]" << endl;
#endif
		;}
    break;

  case 451:
#line 5727 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [and]" << endl;
#endif
		;}
    break;

  case 452:
#line 5733 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [or.and]" << endl;
#endif
		;}
    break;

  case 453:
#line 5745 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [mild_not]" << endl;
#endif
		;}
    break;

  case 454:
#line 5751 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [and.mild_not]" << endl;
#endif
		;}
    break;

  case 455:
#line 5763 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [unary_not]" << endl;
#endif
		;}
    break;

  case 456:
#line 5769 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [mild_not.unary_not]" << endl;
#endif
		;}
    break;

  case 457:
#line 5781 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [words]" << endl;
#endif
		;}
    break;

  case 458:
#line 5787 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [not.words]" << endl;
#endif
		;}
    break;

  case 459:
#line 5799 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words]" << endl;
#endif
		;}
    break;

  case 460:
#line 5805 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words.times]" << endl;
#endif
		;}
    break;

  case 461:
#line 5811 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [selection]" << endl;
#endif
		;}
    break;

  case 462:
#line 5823 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value]" << endl;
#endif
		;}
    break;

  case 463:
#line 5829 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value.any_all_option]" << endl;
#endif
		;}
    break;

  case 464:
#line 5841 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [literal]" << endl;
#endif
		;}
    break;

  case 465:
#line 5847 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [expr]" << endl;
#endif
		;}
    break;

  case 466:
#line 5859 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [order]" << endl;
#endif
		;}
    break;

  case 467:
#line 5865 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [window]" << endl;
#endif
		;}
    break;

  case 468:
#line 5871 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [distance]" << endl;
#endif
		;}
    break;

  case 469:
#line 5877 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [scope]" << endl;
#endif
		;}
    break;

  case 470:
#line 5883 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [content]" << endl;
#endif
		;}
    break;

  case 471:
#line 5895 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOrderedIndicator [ ]" << endl;
#endif
		;}
    break;

  case 472:
#line 5907 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [case]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 473:
#line 5914 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [diacritics]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 474:
#line 5921 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 475:
#line 5928 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [thesaurus]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 476:
#line 5935 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stopword]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 477:
#line 5942 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [language]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 478:
#line 5949 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [wildcard]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 479:
#line 5962 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [lower]" << endl;
#endif
		;}
    break;

  case 480:
#line 5968 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [upper]" << endl;
#endif
		;}
    break;

  case 481:
#line 5974 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [sensitive]" << endl;
#endif
		;}
    break;

  case 482:
#line 5980 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [insensitive]" << endl;
#endif
		;}
    break;

  case 483:
#line 5992 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [with]" << endl;
#endif
		;}
    break;

  case 484:
#line 5998 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [without]" << endl;
#endif
		;}
    break;

  case 485:
#line 6004 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [sensitive]" << endl;
#endif
		;}
    break;

  case 486:
#line 6010 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [insensitive]" << endl;
#endif
		;}
    break;

  case 487:
#line 6022 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [with]" << endl;
#endif
		;}
    break;

  case 488:
#line 6028 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [without]" << endl;
#endif
		;}
    break;

  case 489:
#line 6040 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [id]" << endl;
#endif
		;}
    break;

  case 490:
#line 6046 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [default]" << endl;
#endif
		;}
    break;

  case 491:
#line 6052 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id)]" << endl;
#endif
		;}
    break;

  case 492:
#line 6058 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id,id,..)]" << endl;
#endif
		;}
    break;

  case 493:
#line 6064 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default)]" << endl;
#endif
		;}
    break;

  case 494:
#line 6070 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default,id,id,..)]" << endl;
#endif
		;}
    break;

  case 495:
#line 6076 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [without]" << endl;
#endif
		;}
    break;

  case 496:
#line 6088 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [single]" << endl;
#endif
		;}
    break;

  case 497:
#line 6094 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [list]" << endl;
#endif
		;}
    break;

  case 498:
#line 6106 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name]" << endl;
#endif
		;}
    break;

  case 499:
#line 6112 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel]" << endl;
#endif
		;}
    break;

  case 500:
#line 6118 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.range]" << endl;
#endif
		;}
    break;

  case 501:
#line 6124 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel.range]" << endl;
#endif
		;}
    break;

  case 502:
#line 6136 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list]" << endl;
#endif
		;}
    break;

  case 503:
#line 6142 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list.incl_excl]" << endl;
#endif
		;}
    break;

  case 504:
#line 6148 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default]" << endl;
#endif
		;}
    break;

  case 505:
#line 6154 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default.incl_excl]" << endl;
#endif
		;}
    break;

  case 506:
#line 6160 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [without]" << endl;
#endif
		;}
    break;

  case 507:
#line 6172 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 508:
#line 6178 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 509:
#line 6190 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [.]" << endl;
#endif
		;}
    break;

  case 510:
#line 6196 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [(*)]" << endl;
#endif
		;}
    break;

  case 511:
#line 6208 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 512:
#line 6214 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 513:
#line 6226 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [union]" << endl;
#endif
		;}
    break;

  case 514:
#line 6232 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [except]" << endl;
#endif
		;}
    break;

  case 515:
#line 6244 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTLanguageOption [ ]" << endl;
#endif
		;}
    break;

  case 516:
#line 6256 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [with]" << endl;
#endif
		;}
    break;

  case 517:
#line 6262 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [without]" << endl;
#endif
		;}
    break;

  case 518:
#line 6274 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [start]" << endl;
#endif
		;}
    break;

  case 519:
#line 6280 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [end]" << endl;
#endif
		;}
    break;

  case 520:
#line 6286 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [entire]" << endl;
#endif
		;}
    break;

  case 521:
#line 6298 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any]" << endl;
#endif
		;}
    break;

  case 522:
#line 6304 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any_word]" << endl;
#endif
		;}
    break;

  case 523:
#line 6310 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all]" << endl;
#endif
		;}
    break;

  case 524:
#line 6316 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all_words]" << endl;
#endif
		;}
    break;

  case 525:
#line 6322 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [phrase]" << endl;
#endif
		;}
    break;

  case 526:
#line 6334 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [exactly]" << endl;
#endif
		;}
    break;

  case 527:
#line 6340 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_least]" << endl;
#endif
		;}
    break;

  case 528:
#line 6346 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_most]" << endl;
#endif
		;}
    break;

  case 529:
#line 6352 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [range]" << endl;
#endif
		;}
    break;

  case 530:
#line 6364 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDistance [ ]" << endl;
#endif
		;}
    break;

  case 531:
#line 6376 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWindow [ ]" << endl;
#endif
		;}
    break;

  case 532:
#line 6388 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [ ]" << endl;
#endif
		;}
    break;

  case 533:
#line 6400 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [same]" << endl;
#endif
		;}
    break;

  case 534:
#line 6406 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [different]" << endl;
#endif
		;}
    break;

  case 535:
#line 6418 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [words]" << endl;
#endif
		;}
    break;

  case 536:
#line 6424 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [sentences]" << endl;
#endif
		;}
    break;

  case 537:
#line 6430 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 538:
#line 6442 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [sentence]" << endl;
#endif
		;}
    break;

  case 539:
#line 6448 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 540:
#line 6460 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTIgnoreOption [ ]" << endl;
#endif
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6316 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -658;
  const short int
  xquery_parser::yypact_[] =
  {
       746,  1162,  1370,  -658,  -658,    -5,  -658,    27,  -658,  -658,
    -658,  3034,    17,   443,  -658,  3034,   131,  -658,   128,   171,
     212,   -27,   268,   172,   193,   468,   310,   334,   335,   -54,
     342,   340,  -658,  -658,  3034,   326,   345,  -658,  -658,  -658,
    3034,    76,   426,  -658,  -658,   471,  3034,    87,   263,  -658,
     479,  1578,  -658,   404,   265,  3034,  -658,   394,    75,  -658,
     571,  -658,  -658,    48,   437,   466,  -658,  3740,  3578,   426,
    -658,   474,  3034,   366,  3034,  3034,  3034,    -3,   489,   412,
    3034,  3034,  3034,  3034,  3034,  3034,  3034,   506,   420,  3682,
     541,   954,  -658,  -658,   250,  3034,   381,   401,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,   523,  -658,
    -658,   403,  -658,  -658,  -658,  -658,  -658,  -658,   447,   543,
    -658,  3743,   347,   -28,   380,   -26,   173,  -658,   485,   418,
     568,   569,  3242,  -658,  -658,  -658,   -21,  -658,  -658,  -658,
     213,  -658,   502,   443,  -658,   502,   443,  -658,  -658,  -658,
    -658,   502,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,    26,  -658,    44,  1786,  3034,   125,    24,  -658,    89,
    -658,  -658,   127,  -658,  -658,  -658,  -658,  -658,  -658,   593,
     595,  -658,   619,   620,  -658,  -658,   525,   558,   625,  -658,
    -658,   529,    40,   204,  -658,   492,   493,  -658,   222,   100,
    -658,   101,    58,     8,  -658,     0,   608,  -658,   106,   634,
     655,   637,   548,   660,   651,   -12,   629,  -658,  -658,   108,
     589,  -658,   232,    41,   521,   526,  -658,   673,  -658,   577,
    3034,   534,   535,  -658,  -658,    13,    31,   246,  -658,   109,
     249,   251,   498,  -658,   -22,  -658,  -658,  -658,  -658,  -658,
      11,    32,   663,   481,   483,   600,   -14,  -658,  3034,  -658,
    -658,  -658,  -658,   678,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,   191,  -658,  -658,   238,   301,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
     250,    -7,  3034,  3034,  3034,  3034,  3034,  -658,   -47,   545,
    3410,  3410,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  3410,  3410,  3410,
      18,  3410,  3410,  3410,  3410,  3410,  3410,  3410,  3410,  3410,
    3410,  3410,   393,   393,   684,   684,  -658,  -658,  -658,  1994,
    -658,  3578,  3578,  3034,   502,  -658,  -658,   502,  -658,   502,
    -658,  -658,  -658,  -658,   110,   254,   592,   688,  -658,   688,
    -658,  -658,     4,    36,  -658,  -658,   224,   700,  -658,   328,
     393,  -658,  3034,    46,  -658,  -658,  -658,   594,   693,  -658,
     693,  -658,  3034,   618,   652,  3034,   653,  3034,   654,   -70,
     623,   -11,   656,   550,   708,   645,   708,  -658,   646,   701,
    3034,   636,   -52,   662,  -658,   714,  -658,  -658,  -658,  -658,
    -658,  -658,  2202,   274,  -658,  -658,  3034,   657,  -658,    65,
      34,  -658,  -658,   699,  -658,  -658,  -658,   717,  -658,   252,
    3034,  3034,  3034,   356,  3034,  3034,  3034,  3034,  3034,  3034,
    3034,   666,  3034,   587,  -658,   238,   238,   191,  -658,   720,
     721,   191,   723,  -658,   257,  -658,   583,  -658,  -658,  -658,
     431,   702,  -658,  -658,   702,  -658,  3034,   591,  3034,   543,
    -658,  -658,  -658,  -658,  3034,    18,   496,  -658,   494,   398,
     515,   509,  -658,  -658,   510,   360,   380,   380,    -9,   -26,
     -26,   -26,   -26,   173,   173,  -658,  -658,  -658,  -658,  -658,
    -658,   500,  -658,  -658,  -658,  -658,   659,  -658,  -658,   275,
    -658,  -658,    20,  -658,  3034,  -658,  -658,  2410,  -658,   596,
     601,  -658,  -658,  -658,  -658,   733,    16,   393,    82,  -658,
    -658,   352,   393,    84,  -658,  -658,  -658,  3034,  2618,   661,
     609,   610,   613,   615,  -658,  3034,   426,  -658,   741,  -658,
     751,  3034,   670,  3034,  3034,   -60,   671,   471,  3034,  -658,
     732,   756,   732,  -658,   708,  -658,  3034,  3034,   681,   479,
     626,  -658,   278,   675,  -658,    70,  -658,  -658,   780,  -658,
    -658,  3034,   773,  -658,  -658,    91,  -658,  -658,  -658,  -658,
     107,  -658,   298,    47,  -658,   630,  3034,  3034,  -658,  -658,
    -658,  3034,  3034,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
     506,   638,   575,  -658,  -658,  -658,  -658,  -658,    79,   191,
     353,   112,   113,    -7,  -658,   789,  -658,  -658,  -658,  -658,
      38,   768,  -658,  3034,  -658,  3034,  -658,   280,   668,  -658,
    3410,  -658,  -658,  -658,  -658,  -147,   308,  -658,    18,  -147,
    3410,  3410,   455,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
      18,    18,   308,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,   281,
    -658,  -658,   785,  -658,  -658,   362,   743,   385,   393,  -658,
    -658,   387,   396,   393,  -658,  -658,   291,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  -658,  -658,  3034,  -658,  -658,
    3034,   722,  3034,  -658,   747,   800,   797,   732,  -658,  -658,
    3034,  -658,  -658,  -658,  2826,   327,   460,  -658,  -658,   293,
     665,   813,  -658,   814,   149,   809,   679,    -6,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,  3034,    57,   575,  -658,  -658,
    -658,  3410,  3410,  3410,  3410,   812,   602,   808,  -658,   808,
    -658,  -658,   768,  -658,  -658,  -658,  -658,  -658,  -658,   -26,
    -658,  -658,  -658,   201,   515,  -658,  -658,   277,  3410,  -658,
    -658,   509,  -658,   604,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,   414,  -658,  -658,  -658,  -658,   416,  -658,  -658,  -658,
    3034,  -658,  3034,  -658,   708,  -658,  -658,   294,  -658,  -658,
     815,   354,  -658,  -658,  -658,  -658,   694,   486,  -658,  -658,
    -658,  -658,   674,   676,   834,   822,  3034,   830,  3034,  -658,
     116,  -658,   -26,   -26,   -26,   359,   308,  -658,   117,  -658,
     123,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,   732,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,   685,   393,  -658,   703,  -658,
     784,   748,  3410,   621,   808,  -658,  -658,  -658,   704,  3034,
     840,  -658,   -26,  -658,  -658,  3034,  -658,   709,  -658,   748,
    -658
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,     0,     0,   270,   271,   267,   415,     0,   261,   264,
     251,     0,     0,     0,   249,     0,     0,   287,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,   253,     0,     0,     0,   293,   259,   289,
       0,     0,     0,   255,   254,     0,     0,     0,     0,   288,
       0,     0,   205,     0,     0,     0,   260,     0,     0,   204,
       0,   263,   262,     0,     0,     0,   252,   234,     0,     0,
     269,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     4,     0,     0,     0,     0,    15,    17,
      19,    20,    21,    27,    22,    25,    26,    31,    32,    33,
      28,    29,    35,    36,    23,    30,    24,     9,    93,    94,
      96,     0,   111,   113,   114,    97,    98,    99,   100,   167,
     169,   171,   175,   178,   180,   183,   188,   191,   194,   196,
     198,   200,     0,   202,   208,   210,     0,   230,   209,   237,
     238,   241,   243,     0,   248,   245,     0,   256,   266,   268,
     242,   272,   277,   285,   278,   279,   280,   283,   284,   281,
     282,   300,   302,   303,   304,   301,   347,   348,   349,   350,
     351,   352,   265,   389,   381,   388,   387,   386,   383,   385,
     382,   384,   286,    34,   101,   102,   104,   103,   105,   106,
     358,     0,   354,     0,     0,     0,     0,     0,   399,     0,
     267,   257,     0,   395,    53,    38,    39,    70,    71,     0,
       0,    52,     0,     0,    46,    47,     0,     0,     0,    44,
      45,     0,     0,     0,   391,     0,     0,   290,     0,     0,
     405,     0,     0,     0,   156,     0,   115,   116,     0,    62,
       0,    54,     0,     0,     0,     0,   128,   129,   291,     0,
       0,   390,     0,     0,     0,     0,   396,     0,   233,     0,
       0,     0,     0,   235,   236,     0,     0,     0,   394,     0,
       0,     0,     0,   343,     0,   416,   417,   418,   429,   430,
       0,     0,     0,     0,     0,     0,     0,   435,     0,   482,
     481,   486,   485,     0,   479,   480,   484,   488,   506,   495,
     517,   504,   483,   487,     0,     0,   516,    43,   472,   473,
     474,   475,   476,   477,   478,     1,     3,     5,    10,     8,
      12,    13,     0,     0,     0,     0,     0,   112,     0,     0,
       0,     0,   211,   225,   216,   215,   223,   214,   213,   212,
     224,   217,   222,   221,   220,   219,   218,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   207,   206,   203,     0,
     231,     0,     0,     0,   244,   274,   247,   246,   258,   273,
     359,   355,   296,   298,     0,     0,     0,     0,   400,     0,
     402,   363,     0,     0,    40,    41,     0,     0,    42,     0,
       0,    67,     0,     0,   353,   392,   393,     0,     0,   406,
       0,   409,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,    55,
       0,     0,     0,     0,   292,     0,   294,   345,   344,   397,
     398,   232,     0,     0,   404,   412,     0,     0,   305,     0,
       0,   313,   362,     0,   295,   226,   342,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   515,     0,     0,   505,   507,     0,
       0,   502,     0,   490,     0,   489,     0,    16,    18,    95,
     140,   136,   138,   107,   137,   135,     0,     0,     0,   168,
     170,   173,   172,   174,     0,     0,     0,   464,   176,   443,
     451,   453,   455,   457,   459,   462,   182,   181,   179,   185,
     186,   187,   184,   189,   190,   193,   192,   380,   379,   373,
     195,   371,   377,   378,   197,   199,   368,   201,   228,     0,
     239,   240,     0,   275,     0,   297,   227,     0,   413,     0,
       0,    50,    51,    48,    49,     0,     0,     0,     0,    88,
      37,     0,     0,     0,   370,    66,    69,     0,     0,   413,
       0,     0,     0,     0,   158,     0,     0,   155,     0,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      64,     0,    56,    60,     0,   131,     0,     0,     0,     0,
       0,   364,     0,     0,   154,     0,   335,   338,     0,   339,
     340,     0,     0,   341,   334,     0,   311,   337,   336,   306,
       0,   314,     0,     0,   162,     0,     0,     0,   422,   423,
     419,     0,     0,   427,   428,   424,   433,   431,   432,   437,
       0,     0,     0,   514,   513,   508,   509,   511,     0,   503,
     498,     0,     0,    14,   149,     0,   150,   151,   152,   141,
     142,   143,   144,     0,   108,     0,   109,     0,     0,   458,
       0,   177,   471,   519,   518,     0,     0,   520,     0,     0,
       0,     0,   444,   448,   466,   447,   470,   468,   467,   469,
       0,     0,     0,   460,   523,   524,   521,   522,   525,   463,
     374,   376,   375,   372,   369,   229,   276,   299,   360,     0,
     401,   403,    90,    72,    73,     0,     0,     0,     0,    80,
      81,     0,     0,     0,    68,   356,     0,   414,   407,   408,
     410,   411,   159,   157,   126,   127,   120,     0,   122,   119,
       0,     0,     0,   117,     0,     0,    63,    57,   133,   132,
       0,   130,    11,   365,     0,   324,   318,   315,   346,     0,
       0,     0,   312,     0,     0,     0,     0,     0,   163,     7,
     420,   421,   425,   426,   436,     0,     0,   438,   439,   512,
     510,     0,     0,     0,     0,     0,     0,     0,   493,     0,
     491,   153,   145,   146,   147,   139,   110,   465,   461,   540,
     539,   538,   534,     0,   452,   533,   445,     0,     0,   450,
     449,   454,   456,     0,   361,    91,    76,    77,    89,    74,
      75,     0,    84,    85,    82,    83,     0,   357,   124,   121,
       0,   123,     0,    59,     0,   134,   366,     0,   332,   326,
       0,   325,   327,   333,   330,   320,     0,   319,   321,   331,
      92,   307,     0,     0,     0,     0,     0,     0,     0,   434,
       0,   440,   527,   528,   526,     0,   499,   500,     0,   496,
       0,   148,   537,   536,   535,   530,   531,   446,   532,    78,
      79,    86,    87,   125,   166,    65,   367,   317,   328,   329,
     316,   322,   323,   308,   309,     0,     0,   164,     0,   160,
       0,     0,     0,     0,     0,   494,   492,   310,     0,     0,
       0,   441,   529,   501,   497,     0,   161,     0,   165,     0,
     442
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -658,  -658,  -658,   778,   781,  -658,   777,  -658,   544,   546,
    -312,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -420,  -658,  -658,  -658,  -658,  -658,
     464,   151,  -536,   783,     6,   -80,  -658,  -658,   758,  -658,
    -658,   283,   450,  -228,  -658,  -658,   273,  -658,   547,   553,
     210,  -658,  -658,   219,  -585,  -658,   825,   305,  -658,  -658,
     262,  -658,  -658,   560,   557,    56,  -624,   538,   237,  -354,
     234,   266,  -658,  -658,  -658,  -658,  -658,   760,  -658,  -658,
    -658,  -658,  -658,  -658,   757,  -658,   -29,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,    93,   118,  -658,  -658,   133,    33,
    -658,  -338,  -658,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,  -428,  -658,   276,  -658,   445,  -658,  -658,  -658,  -658,
    -658,    53,    63,  -546,  -432,  -658,  -658,  -658,  -658,  -658,
    -658,  -658,  -658,  -658,  -658,   549,  -227,  -359,  -658,  -658,
     245,  -347,  -658,  -658,  -658,  -658,  -658,  -658,  -658,   881,
     883,    72,   499,  -658,  -658,  -658,  -658,  -658,  -658,  -658,
    -658,   272,  -658,  -658,   136,   411,  -658,  -658,   239,   229,
     230,   417,  -658,  -658,   240,  -658,  -477,  -658,  -658,  -658,
    -658,   135,  -306,  -658,   439,   137,  -658,  -443,  -658,  -658,
    -658,  -658,  -657,  -658,  -658,  -658,  -658,   120,   253,  -658
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   600,   254,   113,   114,   115,   116,
     568,   569,   623,   117,   118,   119,   120,   121,   122,   123,
     246,   247,   429,   430,   124,   256,   257,   338,   339,   501,
     502,   669,   670,   671,   672,   125,   243,   244,   126,   633,
     634,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   357,   358,
     359,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   384,   385,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   394,
     170,   171,   172,   625,   460,   461,   767,   856,   857,   850,
     851,   858,   852,   626,   627,   173,   174,   628,   175,   176,
     177,   178,   179,   180,   181,   545,   413,   540,   713,   541,
     542,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   559,   581,   192,   193,   194,   195,   196,   197,   198,
     296,   297,   199,   787,   788,   518,   692,   519,   520,   521,
     522,   523,   524,   525,   693,   694,   317,   318,   319,   320,
     321,   878,   879,   322,   487,   491,   658,   488,   323,   324,
     696,   709,   796,   697,   698,   703,   699,   885,   812,   681
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       288,   289,   290,   291,   292,   293,   294,   201,   203,   495,
     529,   530,   531,   532,   544,   423,   602,   206,   431,   498,
     410,   212,   517,   426,   282,   543,   543,   441,   442,   813,
     724,   624,   410,   481,   426,   730,   207,   591,   273,   274,
     233,     6,   695,   469,   655,   823,   238,   750,   607,   447,
     457,   574,   248,   457,    26,   424,    28,   259,    30,    31,
     424,   262,   269,   543,   473,   467,   816,   332,     3,   867,
      17,   397,   410,   332,   616,     4,   210,   617,   277,   772,
     279,   280,   281,   229,   665,   803,   804,   632,   440,   264,
     410,   332,   333,   379,   361,   239,   594,    39,   265,   810,
     616,   765,   789,   617,   811,   219,   211,   427,   618,   723,
     506,   249,   561,   361,   777,   204,   616,   458,   362,   617,
     629,   335,   667,   668,   393,   220,    60,   230,    49,   726,
     621,   726,   514,   411,   618,   562,   399,   362,   515,   576,
     412,   205,   468,   619,   563,   620,   577,   418,   420,   363,
     618,   868,   214,   332,   368,   332,   332,   554,   616,   797,
     799,   617,   270,   910,   914,   422,   369,   564,   425,   619,
     914,   620,   332,   456,   332,   208,   716,   517,   517,   621,
     428,   390,   398,   448,   757,   619,   209,   620,   662,   827,
     428,   830,   618,   283,   887,   833,   835,   624,   428,   391,
     482,   592,   624,   596,   459,   621,    57,   630,   725,   470,
     471,   395,   250,   731,   608,   820,   655,   881,   483,   913,
     543,   621,    89,   472,   766,   543,    70,   619,   772,   620,
     474,   475,    57,   266,   240,   622,    71,   790,   428,   428,
     727,   728,   732,   733,   476,   241,   386,   400,    57,   388,
     428,   332,   499,   500,   503,   500,   505,   516,   419,   421,
      77,   771,    71,   621,   433,   370,   444,   463,   555,   332,
     798,   800,   489,   776,   911,   915,   453,   773,    71,   332,
     396,   916,   401,   485,   371,   543,    77,   251,   387,   213,
      57,   492,   221,   332,   389,   890,   332,   222,   332,   565,
     892,   332,    77,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,   537,   223,   864,
      71,   332,   332,   215,   661,   332,   809,   332,   332,   226,
     848,   252,   575,   853,   859,   492,    12,   817,   332,   617,
     332,   332,   584,   216,    77,   587,   624,   589,   227,    16,
     517,   498,   550,   551,   228,    47,    48,   848,   490,   414,
     605,   231,   517,   517,   217,   232,   617,   751,   493,   831,
     237,   486,    35,   775,   836,   921,   614,   417,   381,   382,
      41,   543,   566,   567,   218,   549,   543,   446,   253,   552,
     638,   639,   640,   930,   643,   644,   645,   646,   647,   648,
     649,   462,   651,   565,   464,   619,   465,   620,    41,   556,
     263,   538,   537,   511,   512,   513,   849,   553,   260,   853,
     553,   494,   553,   261,   895,   859,   674,    54,   676,   613,
     715,    12,   619,   763,   620,   807,   824,   872,   873,   874,
     875,   621,    58,   898,    16,   729,   837,   882,   860,   896,
      79,   242,   364,   883,     3,   826,   271,   368,   612,    64,
      65,     4,   210,   636,   664,   637,   621,    35,   621,   369,
     884,   560,   617,    73,   717,    41,   621,   665,   829,    89,
     832,    12,   854,   365,   234,   272,   571,   572,    65,   834,
     580,   539,   582,   276,    16,   825,   245,   734,   617,   621,
      45,   621,   666,   366,   255,   742,   538,   889,   854,   891,
     621,   746,   284,   748,   749,   667,   668,    35,   754,     6,
     677,    50,    54,   882,   278,    41,   758,   759,   621,   883,
     621,   295,   791,   792,   298,   682,   912,    58,   619,   368,
     620,   325,   333,   793,   794,   330,   884,   918,    17,   367,
     855,   369,   224,   225,    64,    65,   780,   781,   922,   543,
     334,   782,   783,   719,   619,   331,   620,   641,    73,   642,
     332,   335,    54,   341,   621,    39,   901,   791,   792,   704,
     705,   706,   707,   340,   736,   360,   539,    58,   793,   794,
     267,   268,   682,   500,   372,   806,   373,   336,   526,   527,
     621,   795,   533,   534,    64,    65,    49,   708,   924,   374,
     514,   375,    70,   285,   286,   287,   515,   383,    73,   546,
     546,   683,   653,   654,   684,   299,   300,   769,   301,   302,
     685,   686,   687,   710,   711,   712,   535,   536,   688,   303,
     402,   304,   403,   404,   405,   406,   407,   689,   408,   409,
     415,   416,   305,   690,   691,   432,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   838,   434,   435,
     839,   436,   841,   437,   438,   439,   443,   445,   683,   449,
     845,   684,   299,   300,   450,   301,   302,   685,   686,   687,
     451,   452,   454,   455,   466,   477,   303,   478,   304,   479,
     480,   484,   508,   537,   689,   869,   557,   558,   578,   305,
     818,   691,   579,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   570,   585,   598,   586,   588,   590,
     593,   597,   599,   601,   603,   604,   606,   609,   610,   632,
     635,   650,   652,   656,   657,   615,   660,   663,   675,   673,
       1,   680,   700,   701,   720,   702,     2,     3,   722,   721,
     893,   714,   894,   737,     4,     5,   744,   738,   739,     6,
     847,   740,     7,   741,     8,     9,   745,   747,   752,   755,
     756,   760,    10,    11,    12,    13,   907,   768,   909,   764,
     762,    14,   770,   786,   779,   785,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,   801,   665,    32,    33,   410,   565,    34,
      35,    36,    37,    38,   843,    39,   808,    40,    41,   840,
     842,   844,   862,   863,   865,   876,   866,    42,   861,   926,
      43,    44,   492,    45,   877,   928,   897,   903,   900,   904,
      46,    47,    48,   905,   906,   908,    49,   888,   917,   920,
     919,   925,   621,   923,    50,   927,    51,   929,    52,   326,
      53,   328,   327,   573,   496,    54,   497,   828,   329,   337,
     753,   595,   761,   805,    55,   507,    56,    57,   504,   802,
      58,   743,    59,    60,   275,   778,    61,    62,   510,    63,
     509,   528,   378,   380,   870,   631,   774,    64,    65,    66,
     902,    67,    68,    69,   899,    70,   235,    71,   236,   583,
      72,    73,   784,   871,   547,    74,   678,   814,    75,   821,
     659,   822,   819,   679,   880,     0,    76,   886,     0,     0,
       0,    77,   815,    78,     0,     0,    79,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,     0,     1,     0,
       0,    87,     0,    88,     2,     3,     0,     0,     0,     0,
       0,     0,     4,     5,     0,    89,     0,     6,     0,     0,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,     0,     0,     0,     0,     0,    14,
       0,     0,     0,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,     0,    32,    33,     0,     0,    34,    35,    36,
      37,    38,     0,    39,     0,    40,    41,     0,     0,     0,
       0,     0,     0,     0,     0,    42,     0,     0,    43,    44,
       0,    45,     0,     0,     0,     0,     0,     0,    46,    47,
      48,     0,     0,     0,    49,     0,     0,     0,     0,     0,
       0,     0,    50,     0,    51,     0,    52,     0,    53,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,    56,    57,     0,     0,    58,     0,
      59,    60,     0,     0,    61,    62,     0,    63,     0,     0,
       0,     0,     0,     0,     0,    64,    65,    66,     0,    67,
      68,    69,     0,    70,     0,    71,     0,     0,    72,    73,
       0,     0,     0,    74,     0,     0,    75,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     0,     0,     0,    77,
       0,     0,     0,     0,    79,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,     0,     1,     0,     0,    87,
       0,    88,     2,     3,     0,     0,     0,     0,     0,     0,
       4,     5,     0,    89,     0,     6,     0,     0,     7,     0,
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
       0,     0,    61,    62,     0,    63,     0,   200,     0,     0,
       0,     0,     0,    64,    65,    66,     0,    67,    68,    69,
       0,    70,     0,    71,     0,     0,    72,    73,     0,     0,
       0,    74,     0,     0,    75,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     0,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,     0,     1,     0,     0,    87,     0,    88,
       2,     3,     0,     0,     0,     0,     0,     0,     4,     5,
       0,     0,     0,     6,     0,     0,     7,     0,     8,     9,
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
      61,    62,     0,    63,     0,   202,     0,     0,     0,     0,
       0,    64,    65,    66,     0,    67,    68,    69,     0,    70,
       0,    71,     0,     0,    72,    73,     0,     0,     0,    74,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,     0,     1,     0,     0,    87,     0,    88,     2,     3,
       0,     0,     0,     0,     0,     0,     4,     5,     0,     0,
       0,     6,     0,     0,     7,     0,     8,     9,     0,     0,
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
       0,    63,     0,     0,     0,     0,   258,     0,     0,    64,
      65,    66,     0,    67,    68,    69,     0,    70,     0,    71,
       0,     0,    72,    73,     0,     0,     0,    74,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,    76,     0,
       0,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,     0,
       1,     0,     0,    87,     0,    88,     2,     3,     0,     0,
       0,     0,     0,     0,     4,     5,     0,     0,     0,     6,
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
       0,     0,     0,     0,   392,     0,     0,    64,    65,    66,
       0,    67,    68,    69,     0,    70,     0,    71,     0,     0,
      72,    73,     0,     0,     0,    74,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,    76,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,     0,     1,     0,
       0,    87,     0,    88,     2,     3,     0,     0,     0,     0,
       0,     0,     4,     5,     0,     0,     0,     6,     0,     0,
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
      59,    60,     0,     0,    61,    62,     0,    63,     0,   548,
       0,     0,     0,     0,     0,    64,    65,    66,     0,    67,
      68,    69,     0,    70,     0,    71,     0,     0,    72,    73,
       0,     0,     0,    74,     0,     0,    75,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     0,     0,     0,    77,
       0,     0,     0,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,     0,     1,     0,     0,    87,
       0,    88,     2,     3,     0,     0,     0,     0,     0,     0,
       4,     5,     0,     0,     0,     6,     0,     0,     7,     0,
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
       0,     0,    61,    62,     0,    63,     0,   611,     0,     0,
       0,     0,     0,    64,    65,    66,     0,    67,    68,    69,
       0,    70,     0,    71,     0,     0,    72,    73,     0,     0,
       0,    74,     0,     0,    75,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     0,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,     0,     1,     0,     0,    87,     0,    88,
       2,     3,     0,     0,     0,     0,     0,     0,     4,     5,
       0,     0,     0,     6,     0,     0,     7,     0,     8,     9,
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
      61,    62,     0,    63,     0,   718,     0,     0,     0,     0,
       0,    64,    65,    66,     0,    67,    68,    69,     0,    70,
       0,    71,     0,     0,    72,    73,     0,     0,     0,    74,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,     0,     1,     0,     0,    87,     0,    88,     2,     3,
       0,     0,     0,     0,     0,     0,     4,     5,     0,     0,
       0,     6,     0,     0,     7,     0,     8,     9,     0,     0,
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
       0,    63,     0,   735,     0,     0,     0,     0,     0,    64,
      65,    66,     0,    67,    68,    69,     0,    70,     0,    71,
       0,     0,    72,    73,     0,     0,     0,    74,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,    76,     0,
       0,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,     0,
       1,     0,     0,    87,     0,    88,     2,     3,     0,     0,
       0,     0,     0,     0,     4,     5,     0,     0,     0,     6,
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
       0,   846,     0,     0,     0,     0,     0,    64,    65,    66,
       0,    67,    68,    69,     0,    70,     0,    71,     0,     0,
      72,    73,     0,     0,     0,    74,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,    76,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,     0,     1,     0,
       0,    87,     0,    88,     2,     3,     0,     0,     0,     0,
       0,     0,     4,     5,     0,     0,     0,     6,     0,     0,
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
       0,     0,     0,     0,     0,    64,    65,    66,     0,    67,
      68,    69,     0,    70,     0,    71,     0,     0,    72,    73,
       0,     0,     0,    74,     0,     0,    75,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     0,     0,     0,    77,
       0,     0,     0,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,     0,     1,     0,     0,    87,
       0,    88,     2,     3,     0,     0,     0,     0,     0,     0,
       4,     5,     0,     0,     0,     6,     0,     0,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,    10,    11,
      12,    13,     0,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,   376,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,    58,     0,   377,    60,
       0,     0,    61,    62,     0,    63,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,     0,    67,    68,     0,
       0,    70,     0,    71,     1,     0,    72,    73,     0,     0,
       2,     3,     0,     0,    75,     0,     0,     0,     4,     5,
       0,     0,    76,     6,     0,     0,     7,    77,     8,     9,
       0,     0,     0,     0,     0,     0,    10,    11,    12,    13,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,     0,    34,    35,    36,    37,    38,     0,    39,
       0,    40,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    43,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,    52,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
      56,    57,     0,     0,    58,     0,    59,    60,     0,     0,
      61,    62,     0,    63,     0,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,    67,    68,     0,     0,    70,
       0,    71,     1,     0,    72,    73,     0,     0,     2,     3,
       0,     0,    75,     0,     0,     0,     4,     5,     0,     0,
      76,     6,     0,     0,     0,    77,     8,     9,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,     0,     0,
       0,     0,     0,    14,     0,     0,     0,     0,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    33,     0,
       0,    34,    35,    36,    37,    38,     0,    39,     0,    40,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,    56,    57,
       0,     0,    58,     0,     0,     0,     0,     0,    61,    62,
       0,    63,     0,     0,     0,     0,     0,     0,     0,    64,
      65,    66,     0,     0,     1,     0,     0,    70,     0,    71,
       2,     3,    72,    73,     0,     0,     0,     0,     4,     5,
      75,     0,     0,     6,     0,     0,     0,     0,     8,     9,
       0,     0,     0,    77,     0,     0,    10,    11,    12,    13,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,     0,    34,    35,    36,    37,    38,     0,    39,
       0,    40,    41,     0,     0,     0,     0,     0,     0,     0,
       0,   342,     0,     0,    43,    44,     0,     0,     0,   343,
       0,     0,   344,     0,   345,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,   346,     0,     0,     0,   347,
      51,     0,     0,     0,   348,     0,     0,     0,     0,    54,
     349,     0,     0,     0,     0,     0,     0,     0,    55,     0,
      56,    57,     0,     0,    58,     0,     0,     0,     0,     0,
      61,    62,   350,    63,     0,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,     0,     0,     0,     0,   299,
     300,    71,   301,   302,    72,    73,     0,     0,     0,     0,
       0,     0,    75,   303,     0,   304,     0,   351,   352,   353,
     354,   355,   356,     0,     0,    77,   305,     0,     0,     0,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        80,    81,    82,    83,    84,    85,    86,     1,     2,   315,
     364,   365,   366,   367,   373,   242,   436,    11,   245,   331,
      32,    15,   360,    34,    27,   372,   373,   255,   255,   686,
     566,   459,    32,    47,    34,   571,    19,   107,    67,    68,
      34,    23,   519,    32,   487,   702,    40,   107,   100,     8,
      19,   410,    46,    19,    61,    47,    63,    51,    65,    66,
      47,    55,    14,   410,    32,    87,   690,    47,    11,    75,
      52,    47,    32,    47,     9,    18,    19,    12,    72,   625,
      74,    75,    76,   137,    46,   670,   671,    40,   100,    14,
      32,    47,   139,   114,   122,    19,   107,    79,    23,   246,
       9,    31,    23,    12,   251,   132,    13,   107,    43,    93,
     157,    24,   108,   122,    67,   120,     9,    86,   146,    12,
      86,   168,    84,    85,   204,   152,   147,   181,   110,    47,
     114,    47,   114,    93,    43,   131,    47,   146,   120,    93,
     100,   114,   164,    78,   108,    80,   100,    47,    47,   177,
      43,   157,    24,    47,   180,    47,    47,    47,     9,    47,
      47,    12,   114,    47,    47,   107,   192,   131,   160,    78,
      47,    80,    47,   160,    47,   158,   156,   515,   516,   114,
     250,   155,   158,   142,   604,    78,   169,    80,   494,   725,
     250,   727,    43,   196,   818,   731,   732,   625,   250,   155,
     214,   429,   630,   431,   173,   114,   141,   173,   567,   198,
     199,   205,   125,   572,   442,   692,   659,   802,   298,   876,
     567,   114,   229,   212,   154,   572,   169,    78,   774,    80,
     198,   199,   141,   158,   158,   170,   171,   158,   250,   250,
     158,   159,   158,   159,   212,   169,   153,   158,   141,   156,
     250,    47,   332,   333,   334,   335,   336,   239,   158,   158,
     195,   170,   171,   114,   158,    92,   158,   158,   158,    47,
     158,   158,    34,   632,   158,   158,   270,   170,   171,    47,
     155,   158,   155,    92,   111,   632,   195,    24,   155,   158,
     141,    34,    24,    47,   161,   831,    47,   125,    47,    75,
     836,    47,   195,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    19,   125,   170,
     171,    47,    47,   152,    67,    47,   680,    47,    47,    19,
       3,    68,   412,   765,   766,    34,    38,   691,    47,    12,
      47,    47,   422,   172,   195,   425,   774,   427,    14,    51,
     688,   663,   381,   382,    19,   105,   106,     3,   120,   155,
     440,    19,   700,   701,   152,    25,    12,   595,    67,   728,
      25,   180,    74,    75,   733,   911,   456,   155,   165,   166,
      82,   728,   158,   159,   172,   379,   733,   155,   125,   383,
     470,   471,   472,   929,   474,   475,   476,   477,   478,   479,
     480,   155,   482,    75,   155,    78,   155,    80,    82,   155,
      16,   113,    19,   357,   358,   359,    89,   384,    14,   851,
     387,   120,   389,   158,   844,   857,   506,   129,   508,   155,
     155,    38,    78,   155,    80,   155,   155,   791,   792,   793,
     794,   114,   144,    89,    51,    93,   155,   246,   155,   155,
     200,    25,    72,   252,    11,    93,    19,   180,   452,   161,
     162,    18,    19,   211,    33,   213,   114,    74,   114,   192,
     269,   399,    12,   175,   554,    82,   114,    46,    93,   229,
      93,    38,    22,   103,   158,    19,   158,   159,   162,    93,
     418,   193,   420,    19,    51,   722,    25,   577,    12,   114,
      97,   114,    71,   123,    25,   585,   113,    93,    22,    93,
     114,   591,    23,   593,   594,    84,    85,    74,   598,    23,
     514,   118,   129,   246,   158,    82,   606,   607,   114,   252,
     114,    25,   224,   225,   114,   137,   177,   144,    78,   180,
      80,     0,   139,   235,   236,   164,   269,   906,    52,   169,
      90,   192,    84,    85,   161,   162,   636,   637,   912,   906,
     157,   641,   642,   557,    78,   164,    80,   211,   175,   213,
      47,   168,   129,    30,   114,    79,    90,   224,   225,   219,
     220,   221,   222,   136,   578,   238,   193,   144,   235,   236,
      19,    20,   137,   673,   109,   675,   178,   194,   361,   362,
     114,   248,   368,   369,   161,   162,   110,   247,   914,    41,
     114,    42,   169,   201,   202,   203,   120,   115,   175,   374,
     375,   223,   485,   486,   226,   227,   228,   621,   230,   231,
     232,   233,   234,   133,   134,   135,   370,   371,   240,   241,
      47,   243,    47,    24,    24,   120,    88,   249,    23,   120,
     158,   158,   254,   255,   256,    47,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   747,    34,    14,
     750,    34,   752,   125,    14,    24,    47,    88,   223,   158,
     760,   226,   227,   228,   158,   230,   231,   232,   233,   234,
      17,   114,   158,   158,   196,    32,   241,   216,   243,   216,
     100,    23,   157,    19,   249,   785,   114,    19,   114,   254,
     255,   256,    19,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    24,   107,   176,    75,    75,    75,
     107,    75,    24,    88,    88,    34,   100,    75,    24,    40,
      23,    75,   155,    23,    23,    88,    23,   164,   157,    47,
       4,   257,   237,   244,   158,   245,    10,    11,    25,   158,
     840,   102,   842,   102,    18,    19,    25,   158,   158,    23,
     764,   158,    26,   158,    28,    29,    25,   107,   107,    47,
      24,   100,    36,    37,    38,    39,   866,     7,   868,   114,
     164,    45,    19,   218,   164,   157,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    24,    46,    69,    70,    32,    75,    73,
      74,    75,    76,    77,    24,    79,   158,    81,    82,   107,
      83,    34,    19,    19,    25,    23,   157,    91,   173,   919,
      94,    95,    34,    97,   242,   925,    31,   173,   154,   173,
     104,   105,   106,    19,    32,    25,   110,   253,   173,    75,
     157,   157,   114,   242,   118,    25,   120,   158,   122,    91,
     124,    94,    91,   409,   330,   129,   330,   726,    95,   121,
     597,   431,   609,   673,   138,   338,   140,   141,   335,   670,
     144,   586,   146,   147,    69,   633,   150,   151,   341,   153,
     340,   363,   142,   146,   786,   460,   630,   161,   162,   163,
     857,   165,   166,   167,   851,   169,    35,   171,    35,   420,
     174,   175,   650,   787,   375,   179,   515,   688,   182,   700,
     491,   701,   692,   516,   799,    -1,   190,   817,    -1,    -1,
      -1,   195,   689,   197,    -1,    -1,   200,    -1,    -1,    -1,
     204,   205,   206,   207,   208,   209,   210,    -1,     4,    -1,
      -1,   215,    -1,   217,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    -1,   229,    -1,    23,    -1,    -1,
      26,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    -1,    69,    70,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    79,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    95,
      -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,
     106,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,   120,    -1,   122,    -1,   124,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   141,    -1,    -1,   144,    -1,
     146,   147,    -1,    -1,   150,   151,    -1,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,   165,
     166,   167,    -1,   169,    -1,   171,    -1,    -1,   174,   175,
      -1,    -1,    -1,   179,    -1,    -1,   182,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,   200,    -1,    -1,    -1,   204,   205,
     206,   207,   208,   209,   210,    -1,     4,    -1,    -1,   215,
      -1,   217,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    -1,   229,    -1,    23,    -1,    -1,    26,    -1,
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
      -1,    -1,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,   205,   206,   207,
     208,   209,   210,    -1,     4,    -1,    -1,   215,    -1,   217,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,    -1,    23,    -1,    -1,    26,    -1,    28,    29,
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
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,   205,   206,   207,   208,   209,
     210,    -1,     4,    -1,    -1,   215,    -1,   217,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,
      -1,    23,    -1,    -1,    26,    -1,    28,    29,    -1,    -1,
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
      -1,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,   161,
     162,   163,    -1,   165,   166,   167,    -1,   169,    -1,   171,
      -1,    -1,   174,   175,    -1,    -1,    -1,   179,    -1,    -1,
     182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,   205,   206,   207,   208,   209,   210,    -1,
       4,    -1,    -1,   215,    -1,   217,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    23,
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
      -1,    -1,    -1,    -1,   158,    -1,    -1,   161,   162,   163,
      -1,   165,   166,   167,    -1,   169,    -1,   171,    -1,    -1,
     174,   175,    -1,    -1,    -1,   179,    -1,    -1,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,   205,   206,   207,   208,   209,   210,    -1,     4,    -1,
      -1,   215,    -1,   217,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    23,    -1,    -1,
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
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   205,
     206,   207,   208,   209,   210,    -1,     4,    -1,    -1,   215,
      -1,   217,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,    -1,    23,    -1,    -1,    26,    -1,
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
      -1,    -1,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,   205,   206,   207,
     208,   209,   210,    -1,     4,    -1,    -1,   215,    -1,   217,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,    -1,    23,    -1,    -1,    26,    -1,    28,    29,
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
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,   205,   206,   207,   208,   209,
     210,    -1,     4,    -1,    -1,   215,    -1,   217,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,
      -1,    23,    -1,    -1,    26,    -1,    28,    29,    -1,    -1,
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
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,   205,   206,   207,   208,   209,   210,    -1,
       4,    -1,    -1,   215,    -1,   217,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    23,
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
      -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,   205,   206,   207,   208,   209,   210,    -1,     4,    -1,
      -1,   215,    -1,   217,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    23,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,   165,
     166,   167,    -1,   169,    -1,   171,    -1,    -1,   174,   175,
      -1,    -1,    -1,   179,    -1,    -1,   182,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   205,
     206,   207,   208,   209,   210,    -1,     4,    -1,    -1,   215,
      -1,   217,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,    -1,    23,    -1,    -1,    26,    -1,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    -1,    -1,    73,    74,    75,    76,    77,
      -1,    79,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,   140,   141,    -1,    -1,   144,    -1,   146,   147,
      -1,    -1,   150,   151,    -1,   153,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,    -1,   165,   166,    -1,
      -1,   169,    -1,   171,     4,    -1,   174,   175,    -1,    -1,
      10,    11,    -1,    -1,   182,    -1,    -1,    -1,    18,    19,
      -1,    -1,   190,    23,    -1,    -1,    26,   195,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    -1,    -1,    73,    74,    75,    76,    77,    -1,    79,
      -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
     140,   141,    -1,    -1,   144,    -1,   146,   147,    -1,    -1,
     150,   151,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,   165,   166,    -1,    -1,   169,
      -1,   171,     4,    -1,   174,   175,    -1,    -1,    10,    11,
      -1,    -1,   182,    -1,    -1,    -1,    18,    19,    -1,    -1,
     190,    23,    -1,    -1,    -1,   195,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,
      -1,    73,    74,    75,    76,    77,    -1,    79,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   141,
      -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,   150,   151,
      -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,    -1,    -1,     4,    -1,    -1,   169,    -1,   171,
      10,    11,   174,   175,    -1,    -1,    -1,    -1,    18,    19,
     182,    -1,    -1,    23,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    -1,   195,    -1,    -1,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    -1,    -1,    73,    74,    75,    76,    77,    -1,    79,
      -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    94,    95,    -1,    -1,    -1,    96,
      -1,    -1,    99,    -1,   101,    -1,    -1,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,   116,
     120,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,   129,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
     140,   141,    -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,
     150,   151,   149,   153,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,   227,
     228,   171,   230,   231,   174,   175,    -1,    -1,    -1,    -1,
      -1,    -1,   182,   241,    -1,   243,    -1,   184,   185,   186,
     187,   188,   189,    -1,    -1,   195,   254,    -1,    -1,    -1,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268
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
     169,   171,   174,   175,   179,   182,   190,   195,   197,   200,
     204,   205,   206,   207,   208,   209,   210,   215,   217,   229,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   307,   308,   309,   310,   314,   315,   316,
     317,   318,   319,   320,   325,   336,   339,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     391,   392,   393,   406,   407,   409,   410,   411,   412,   413,
     414,   415,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   434,   435,   436,   437,   438,   439,   440,   443,
     155,   315,   155,   315,   120,   114,   315,    19,   158,   169,
      19,   375,   315,   158,    24,   152,   172,   152,   172,   132,
     152,    24,   125,   125,    84,    85,    19,    14,    19,   137,
     181,    19,    25,   315,   158,   430,   431,    25,   315,    19,
     158,   169,    25,   337,   338,    25,   321,   322,   315,    24,
     125,    24,    68,   125,   306,    25,   326,   327,   158,   315,
      14,   158,   315,    16,    14,    23,   158,    19,    20,    14,
     114,    19,    19,   367,   367,   337,    19,   315,   158,   315,
     315,   315,    27,   196,    23,   201,   202,   203,   316,   316,
     316,   316,   316,   316,   316,    25,   441,   442,   114,   227,
     228,   230,   231,   241,   243,   254,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   457,   458,   459,
     460,   461,   464,   469,   470,     0,   284,   285,   287,   314,
     164,   164,    47,   139,   157,   168,   194,   319,   328,   329,
     136,    30,    88,    96,    99,   101,   112,   116,   121,   127,
     149,   184,   185,   186,   187,   188,   189,   359,   360,   361,
     238,   122,   146,   177,    72,   103,   123,   169,   180,   192,
      92,   111,   109,   178,    41,    42,   122,   146,   358,   114,
     365,   165,   166,   115,   379,   380,   375,   379,   375,   379,
     155,   155,   158,   316,   390,   315,   155,    47,   158,    47,
     158,   155,    47,    47,    24,    24,   120,    88,    23,   120,
      32,    93,   100,   417,   155,   158,   158,   155,    47,   158,
      47,   158,   107,   417,    47,   160,    34,   107,   250,   323,
     324,   417,    47,   158,    34,    14,    34,   125,    14,    24,
     100,   324,   417,    47,   158,    88,   155,     8,   142,   158,
     158,    17,   114,   315,   158,   158,   160,    19,    86,   173,
     395,   396,   155,   158,   155,   155,   196,    87,   164,    32,
     198,   199,   212,    32,   198,   199,   212,    32,   216,   216,
     100,    47,   214,   316,    23,    92,   180,   465,   468,    34,
     120,   466,    34,    67,   120,   463,   289,   290,   291,   316,
     316,   330,   331,   316,   330,   316,   157,   329,   157,   344,
     345,   346,   346,   346,   114,   120,   239,   382,   446,   448,
     449,   450,   451,   452,   453,   454,   349,   349,   348,   350,
     350,   350,   350,   351,   351,   352,   352,    19,   113,   193,
     418,   420,   421,   422,   418,   416,   421,   416,   155,   315,
     367,   367,   315,   380,    47,   158,   155,   114,    19,   432,
     432,   108,   131,   108,   131,    75,   158,   159,   311,   312,
      24,   158,   159,   311,   418,   316,    93,   100,   114,    19,
     432,   433,   432,   433,   316,   107,    75,   316,    75,   316,
      75,   107,   324,   107,   107,   323,   324,    75,   176,    24,
     305,    88,   305,    88,    34,   316,   100,   100,   324,    75,
      24,   155,   315,   155,   316,    88,     9,    12,    43,    78,
      80,   114,   170,   313,   392,   394,   404,   405,   408,    86,
     173,   396,    40,   340,   341,    23,   211,   213,   316,   316,
     316,   211,   213,   316,   316,   316,   316,   316,   316,   316,
      75,   316,   155,   466,   466,   468,    23,    23,   467,   465,
      23,    67,   463,   164,    33,    46,    71,    84,    85,   332,
     333,   334,   335,    47,   316,   157,   316,   315,   446,   452,
     257,   480,   137,   223,   226,   232,   233,   234,   240,   249,
     255,   256,   447,   455,   456,   457,   471,   474,   475,   477,
     237,   244,   245,   476,   219,   220,   221,   222,   247,   472,
     133,   134,   135,   419,   102,   155,   156,   316,   155,   315,
     158,   158,    25,    93,   313,   418,    47,   158,   159,    93,
     313,   418,   158,   159,   316,   155,   315,   102,   158,   158,
     158,   158,   316,   338,    25,    25,   316,   107,   316,   316,
     107,   324,   107,   322,   316,    47,    24,   305,   316,   316,
     100,   327,   164,   155,   114,    31,   154,   397,     7,   315,
      19,   170,   404,   170,   394,    75,   418,    67,   341,   164,
     316,   316,   316,   316,   442,   157,   218,   444,   445,    23,
     158,   224,   225,   235,   236,   248,   473,    47,   158,    47,
     158,    24,   334,   335,   335,   331,   316,   155,   158,   350,
     246,   251,   479,   473,   449,   479,   347,   350,   255,   455,
     457,   450,   451,   473,   155,   417,    93,   313,   312,    93,
     313,   418,    93,   313,    93,   313,   418,   155,   316,   316,
     107,   316,    83,    24,    34,   316,   155,   315,     3,    89,
     400,   401,   403,   405,    22,    90,   398,   399,   402,   405,
     155,   173,    19,    19,   170,    25,   157,    75,   157,   316,
     376,   445,   350,   350,   350,   350,    23,   242,   462,   463,
     462,   335,   246,   252,   269,   478,   478,   347,   253,    93,
     313,    93,   313,   316,   316,   305,   155,    31,    89,   403,
     154,    90,   402,   173,   173,    19,    32,   316,    25,   316,
      47,   158,   177,   473,    47,   158,   158,   173,   418,   157,
      75,   313,   350,   242,   463,   157,   316,    25,   316,   158,
     313
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
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   281,   282,   282,   282,   282,   283,   283,   284,   284,
     285,   286,   287,   287,   287,   288,   288,   289,   289,   290,
     290,   290,   290,   291,   291,   291,   291,   292,   292,   292,
     292,   292,   292,   292,   292,   293,   293,   294,   295,   295,
     296,   296,   297,   298,   299,   299,   300,   300,   301,   301,
     301,   301,   302,   303,   304,   304,   304,   304,   305,   305,
     306,   306,   307,   307,   307,   307,   308,   308,   308,   308,
     309,   309,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   311,   311,
     312,   312,   313,   314,   315,   315,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   317,   317,   317,
     317,   318,   318,   319,   319,   320,   321,   321,   322,   322,
     322,   322,   322,   322,   322,   322,   323,   324,   325,   326,
     326,   327,   327,   327,   327,   328,   329,   329,   330,   330,
     331,   331,   332,   332,   332,   332,   332,   332,   332,   333,
     333,   334,   334,   335,   336,   336,   337,   337,   338,   338,
     339,   339,   340,   340,   341,   341,   342,   343,   343,   344,
     344,   345,   345,   345,   345,   346,   346,   346,   347,   347,
     348,   348,   348,   349,   349,   349,   349,   349,   350,   350,
     350,   351,   351,   351,   352,   352,   353,   353,   354,   354,
     355,   355,   356,   356,   357,   357,   357,   357,   358,   358,
     358,   359,   359,   359,   359,   359,   359,   360,   360,   360,
     360,   360,   360,   361,   361,   361,   362,   362,   363,   363,
     364,   364,   365,   365,   366,   366,   366,   366,   367,   367,
     367,   368,   368,   369,   369,   369,   369,   370,   370,   371,
     371,   371,   371,   371,   371,   371,   372,   372,   373,   373,
     374,   374,   374,   374,   374,   375,   375,   376,   376,   377,
     377,   377,   378,   378,   379,   379,   380,   381,   381,   381,
     381,   381,   381,   381,   381,   382,   382,   383,   383,   383,
     384,   385,   385,   386,   387,   388,   389,   389,   390,   390,
     391,   391,   392,   392,   392,   393,   393,   393,   393,   393,
     393,   394,   394,   395,   395,   396,   397,   397,   398,   398,
     399,   399,   399,   399,   400,   400,   401,   401,   401,   401,
     402,   402,   403,   403,   404,   404,   404,   404,   405,   405,
     405,   405,   406,   406,   407,   407,   408,   409,   409,   409,
     409,   409,   409,   410,   411,   411,   411,   411,   412,   412,
     412,   412,   413,   414,   415,   415,   415,   415,   416,   416,
     417,   418,   418,   418,   419,   419,   419,   420,   420,   420,
     421,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     423,   424,   424,   424,   425,   426,   427,   427,   427,   428,
     428,   428,   428,   428,   429,   430,   430,   430,   430,   430,
     430,   430,   431,   432,   433,   434,   435,   435,   435,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   437,
     437,   438,   438,   439,   440,   441,   441,   442,   443,   444,
     444,   445,   445,   446,   446,   446,   446,   447,   447,   447,
     447,   448,   448,   449,   449,   450,   450,   451,   451,   452,
     452,   452,   453,   453,   454,   454,   455,   455,   455,   455,
     455,   456,   457,   457,   457,   457,   457,   457,   457,   458,
     458,   458,   458,   459,   459,   459,   459,   460,   460,   461,
     461,   461,   461,   461,   461,   461,   462,   462,   463,   463,
     463,   463,   464,   464,   464,   464,   464,   465,   465,   466,
     466,   467,   467,   468,   468,   469,   470,   470,   471,   471,
     471,   472,   472,   472,   472,   472,   473,   473,   473,   473,
     474,   475,   476,   477,   477,   478,   478,   478,   479,   479,
     480
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
       1,     1,     1,     1,     1,     1,     1,     3,     4,     4,
       5,     1,     2,     1,     1,     2,     1,     4,     3,     4,
       4,     5,     4,     5,     5,     6,     3,     3,     2,     1,
       4,     3,     4,     4,     5,     2,     2,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     2,     2,     3,     1,
       1,     1,     1,     2,     4,     4,     1,     4,     3,     4,
       7,     9,     1,     2,     4,     7,     7,     1,     3,     1,
       3,     1,     3,     3,     3,     1,     3,     4,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     3,     4,
       1,     2,     3,     2,     1,     2,     2,     1,     1,     3,
       3,     1,     1,     1,     2,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     3,     3,     3,     4,     1,     3,
       1,     1,     1,     1,     1,     3,     4,     6,     7,     7,
       8,     1,     2,     1,     2,     3,     3,     3,     0,     1,
       1,     1,     2,     2,     0,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     5,     6,     2,     3,
       5,     6,     3,     3,     4,     5,     6,     7,     1,     2,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     3,     2,     2,     2,     3,     3,     2,
       3,     5,     3,     5,     3,     2,     3,     5,     5,     3,
       5,     5,     3,     1,     2,     1,     2,     2,     2,     4,
       5,     5,     4,     4,     4,     5,     5,     4,     4,     2,
       2,     4,     4,     4,     6,     1,     4,     3,     5,     1,
       2,     4,     7,     1,     2,     3,     4,     1,     1,     2,
       2,     1,     3,     1,     3,     1,     3,     1,     2,     1,
       2,     3,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     4,     6,     4,     6,     1,     1,     3,     2,     4,
       4,     6,     2,     3,     1,     2,     1,     1,     2,     2,
       3,     1,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     4,
       3,     3,     3,     2,     2,     1,     1,     1,     1,     1,
       2
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
  "\"'before'\"", "\"'<declare revalidation>'\"", "\"'strict'\"",
  "\"'lax'\"", "\"'skip'\"", "\"'<delete node>'\"", "\"'<delete nodes>'\"",
  "\"'<insert node>'\"", "\"'<insert nodes>'\"", "\"'<rename>'\"",
  "\"'<replace node>'\"", "\"'<replace value of node>'\"",
  "\"'<first into>'\"", "\"'into'\"", "\"'<lastinto>'\"", "\"'modify'\"",
  "\"'<copy $>'\"", "\"'with'\"", "\"'<try>'\"", "\"'<catch (>'\"",
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
  "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR", "UNARY_PREC",
  "SEQUENCE_TYPE_REDUCE", "STEP_REDUCE", "$accept", "Module",
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
  "VarNameDecl", "TryExpr", "CatchListExpr", "CatchExpr", "FTSelection",
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
       282,     0,    -1,   284,    -1,   283,   284,    -1,   285,    -1,
     283,   285,    -1,   197,    23,   164,    -1,   197,    23,    87,
      23,   164,    -1,   287,   314,    -1,   314,    -1,   286,   287,
      -1,   124,    14,    88,    24,   164,    -1,   288,   164,    -1,
     289,   164,    -1,   288,   164,   289,   164,    -1,   290,    -1,
     288,   164,   290,    -1,   291,    -1,   289,   164,   291,    -1,
     292,    -1,   293,    -1,   294,    -1,   296,    -1,   308,    -1,
     310,    -1,   297,    -1,   298,    -1,   295,    -1,   302,    -1,
     303,    -1,   309,    -1,   299,    -1,   300,    -1,   301,    -1,
     435,    -1,   304,    -1,   307,    -1,    62,    14,    88,    24,
      -1,    54,   152,    -1,    54,   172,    -1,    58,   125,    24,
      -1,    59,   125,    24,    -1,    63,    19,    23,    -1,   229,
     457,    -1,    64,   137,    -1,    64,   181,    -1,    60,    84,
      -1,    60,    85,    -1,    56,   152,    47,   108,    -1,    56,
     152,    47,   131,    -1,    56,   132,    47,   108,    -1,    56,
     132,    47,   131,    -1,    57,    24,    -1,    53,    24,    -1,
     106,    24,    -1,   106,   306,    24,    -1,   106,    24,    34,
     305,    -1,   106,   306,    24,    34,   305,    -1,    24,    -1,
     305,    47,    24,    -1,   125,    14,    88,    -1,    68,   125,
      -1,   105,    24,    -1,   105,   125,    14,    88,    24,    -1,
     105,    24,    34,   305,    -1,   105,   125,    14,    88,    24,
      34,   305,    -1,    66,    25,   100,   316,    -1,    66,    25,
      93,    -1,    66,    25,   417,   100,   316,    -1,    66,    25,
     417,    93,    -1,    55,   152,    -1,    55,   172,    -1,    61,
      19,   120,   158,    93,    -1,    61,    19,   120,   158,   313,
      -1,    61,    19,   120,   311,   158,    93,    -1,    61,    19,
     120,   311,   158,   313,    -1,    61,    19,   120,   159,   418,
      93,    -1,    61,    19,   120,   159,   418,   313,    -1,    61,
      19,   120,   311,   159,   418,    93,    -1,    61,    19,   120,
     311,   159,   418,   313,    -1,    65,    19,   120,   158,    93,
      -1,    65,    19,   120,   158,   313,    -1,    65,    19,   120,
     311,   158,    93,    -1,    65,    19,   120,   311,   158,   313,
      -1,    65,    19,   120,   159,   418,    93,    -1,    65,    19,
     120,   159,   418,   313,    -1,    65,    19,   120,   311,   159,
     418,    93,    -1,    65,    19,   120,   311,   159,   418,   313,
      -1,   312,    -1,   311,    47,   312,    -1,    75,    25,    -1,
      75,    25,   417,    -1,   114,   315,   155,    -1,   315,    -1,
     316,    -1,   315,    47,   316,    -1,   317,    -1,   336,    -1,
     339,    -1,   342,    -1,   343,    -1,   436,    -1,   437,    -1,
     439,    -1,   438,    -1,   440,    -1,   443,    -1,   318,   157,
     316,    -1,   318,   328,   157,   316,    -1,   318,   329,   157,
     316,    -1,   318,   328,   329,   157,   316,    -1,   319,    -1,
     318,   319,    -1,   320,    -1,   325,    -1,    97,   321,    -1,
     322,    -1,   321,    47,    75,   322,    -1,    25,   107,   316,
      -1,    25,   417,   107,   316,    -1,    25,   323,   107,   316,
      -1,    25,   417,   323,   107,   316,    -1,    25,   324,   107,
     316,    -1,    25,   417,   324,   107,   316,    -1,    25,   323,
     324,   107,   316,    -1,    25,   417,   323,   324,   107,   316,
      -1,    34,    75,    25,    -1,   250,    75,    25,    -1,   118,
     326,    -1,   327,    -1,   326,    47,    75,   327,    -1,    25,
     100,   316,    -1,    25,   417,   100,   316,    -1,    25,   324,
     100,   316,    -1,    25,   417,   324,   100,   316,    -1,   194,
     316,    -1,   139,   330,    -1,   168,   330,    -1,   331,    -1,
     330,    47,   331,    -1,   316,    -1,   316,   332,    -1,   333,
      -1,   334,    -1,   335,    -1,   333,   334,    -1,   333,   335,
      -1,   334,   335,    -1,   333,   334,   335,    -1,    33,    -1,
      71,    -1,    84,    -1,    85,    -1,    46,    24,    -1,   167,
     337,   160,   316,    -1,    91,   337,   160,   316,    -1,   338,
      -1,   337,    47,    75,   338,    -1,    25,   107,   316,    -1,
      25,   417,   107,   316,    -1,   179,   315,   158,   340,    67,
     157,   316,    -1,   179,   315,   158,   340,    67,    75,    25,
     157,   316,    -1,   341,    -1,   340,   341,    -1,    40,   418,
     157,   316,    -1,    40,    75,    25,    32,   418,   157,   316,
      -1,   104,   315,   158,   176,   316,    83,   316,    -1,   344,
      -1,   343,   136,   344,    -1,   345,    -1,   344,    30,   345,
      -1,   346,    -1,   346,   360,   346,    -1,   346,   359,   346,
      -1,   346,   361,   346,    -1,   347,    -1,   347,   238,   446,
      -1,   347,   238,   446,   480,    -1,   348,    -1,   348,   177,
     348,    -1,   349,    -1,   348,   146,   349,    -1,   348,   122,
     349,    -1,   350,    -1,   349,   169,   350,    -1,   349,    72,
     350,    -1,   349,   103,   350,    -1,   349,   123,   350,    -1,
     351,    -1,   350,   180,   351,    -1,   350,   192,   351,    -1,
     352,    -1,   351,   111,   352,    -1,   351,    92,   352,    -1,
     353,    -1,   353,   109,   418,    -1,   354,    -1,   354,   178,
     418,    -1,   355,    -1,   355,    41,   416,    -1,   356,    -1,
     356,    42,   416,    -1,   358,    -1,   357,   358,    -1,   146,
      -1,   122,    -1,   357,   146,    -1,   357,   122,    -1,   362,
      -1,   366,    -1,   363,    -1,    88,    -1,   127,    -1,   121,
      -1,   116,    -1,   101,    -1,    99,    -1,   184,    -1,   189,
      -1,   188,    -1,   187,    -1,   186,    -1,   185,    -1,   112,
      -1,   149,    -1,    96,    -1,   190,   315,   155,    -1,    26,
     114,   315,   155,    -1,   364,   114,   155,    -1,   364,   114,
     315,   155,    -1,   365,    -1,   364,   365,    -1,   147,    19,
      17,    -1,   147,    20,    -1,   165,    -1,   165,   367,    -1,
     166,   367,    -1,   367,    -1,   368,    -1,   368,   165,   367,
      -1,   368,   166,   367,    -1,   369,    -1,   378,    -1,   370,
      -1,   370,   379,    -1,   373,    -1,   373,   379,    -1,   371,
     375,    -1,   372,    -1,    45,    -1,    69,    -1,    36,    -1,
     163,    -1,    70,    -1,    95,    -1,    94,    -1,   375,    -1,
      39,   375,    -1,   374,   375,    -1,    77,    -1,   140,    -1,
      28,    -1,   151,    -1,   150,    -1,    29,    -1,   422,    -1,
     376,    -1,    19,    -1,   377,    -1,   169,    -1,    11,    -1,
      18,    -1,   381,    -1,   381,   379,    -1,   380,    -1,   379,
     380,    -1,   115,   315,   156,    -1,   382,    -1,   384,    -1,
     385,    -1,   386,    -1,   389,    -1,   391,    -1,   387,    -1,
     388,    -1,   383,    -1,   434,    -1,    52,    -1,   110,    -1,
      79,    -1,    75,    25,    -1,   120,   158,    -1,   120,   315,
     158,    -1,    76,    -1,   138,   315,   155,    -1,   182,   315,
     155,    -1,    19,   120,   158,    -1,    19,   120,   390,   158,
      -1,   316,    -1,   390,    47,   316,    -1,   392,    -1,   409,
      -1,   393,    -1,   406,    -1,   407,    -1,   171,    19,    86,
      -1,   171,    19,   395,    86,    -1,   171,    19,   173,   170,
      19,   173,    -1,   171,    19,   173,   394,   170,    19,   173,
      -1,   171,    19,   395,   173,   170,    19,   173,    -1,   171,
      19,   395,   173,   394,   170,    19,   173,    -1,   404,    -1,
     394,   404,    -1,   396,    -1,   395,   396,    -1,    19,    88,
     397,    -1,   154,   398,   154,    -1,    31,   400,    31,    -1,
      -1,   399,    -1,    90,    -1,   402,    -1,   399,    90,    -1,
     399,   402,    -1,    -1,   401,    -1,    89,    -1,   403,    -1,
     401,    89,    -1,   401,   403,    -1,    22,    -1,   405,    -1,
       3,    -1,   405,    -1,   392,    -1,     9,    -1,   408,    -1,
     405,    -1,    12,    -1,    78,    -1,    80,    -1,   313,    -1,
     195,    27,   196,    -1,   195,   196,    -1,   141,    16,   142,
      -1,   141,    16,     8,    -1,    43,     7,    -1,   410,    -1,
     411,    -1,   412,    -1,   413,    -1,   414,    -1,   415,    -1,
      73,   315,   155,    -1,    10,   155,    -1,    10,   315,   155,
      -1,    81,   315,   155,   114,   155,    -1,    81,   315,   155,
     114,   315,   155,    -1,     4,   155,    -1,     4,   315,   155,
      -1,    37,   315,   155,   114,   155,    -1,    37,   315,   155,
     114,   315,   155,    -1,   174,   315,   155,    -1,    50,   315,
     155,    -1,   153,    14,   114,   155,    -1,   153,    14,   114,
     315,   155,    -1,   153,   114,   315,   155,   114,   155,    -1,
     153,   114,   315,   155,   114,   315,   155,    -1,   421,    -1,
     421,   102,    -1,    32,   418,    -1,   420,    -1,   420,   419,
      -1,   193,    -1,   133,    -1,   135,    -1,   134,    -1,   421,
      -1,   422,    -1,   113,    -1,    19,    -1,   424,    -1,   430,
      -1,   428,    -1,   431,    -1,   429,    -1,   427,    -1,   426,
      -1,   425,    -1,   423,    -1,   129,   158,    -1,    74,   158,
      -1,    74,   430,   158,    -1,    74,   431,   158,    -1,   175,
     158,    -1,    51,   158,    -1,   144,   158,    -1,   144,    14,
     158,    -1,   144,    23,   158,    -1,    38,   158,    -1,    38,
      19,   158,    -1,    38,    19,    47,   432,   158,    -1,    38,
     169,   158,    -1,    38,   169,    47,   432,   158,    -1,   161,
      19,   158,    -1,    82,   158,    -1,    82,    19,   158,    -1,
      82,    19,    47,   432,   158,    -1,    82,    19,    47,   433,
     158,    -1,    82,   169,   158,    -1,    82,   169,    47,   432,
     158,    -1,    82,   169,    47,   433,   158,    -1,   162,    19,
     158,    -1,    19,    -1,    19,   102,    -1,    23,    -1,   200,
     201,    -1,   200,   202,    -1,   200,   203,    -1,   206,   316,
     212,   316,    -1,   206,   316,    32,   211,   316,    -1,   206,
     316,    32,   213,   316,    -1,   206,   316,   198,   316,    -1,
     206,   316,   199,   316,    -1,   207,   316,   212,   316,    -1,
     207,   316,    32,   211,   316,    -1,   207,   316,    32,   213,
     316,    -1,   207,   316,   198,   316,    -1,   207,   316,   199,
     316,    -1,   204,   316,    -1,   205,   316,    -1,   209,   316,
     216,   316,    -1,   210,   316,   216,   316,    -1,   208,   316,
      32,   316,    -1,   215,   441,   214,   316,   157,   316,    -1,
     442,    -1,   441,    47,    75,   442,    -1,    25,   100,   316,
      -1,   217,   114,   316,   155,   444,    -1,   445,    -1,   444,
     445,    -1,   218,   376,   158,   313,    -1,   218,   376,    47,
      75,    25,   158,   313,    -1,   448,    -1,   448,   447,    -1,
     448,   255,   347,    -1,   448,   447,   255,   347,    -1,   457,
      -1,   455,    -1,   447,   457,    -1,   447,   455,    -1,   449,
      -1,   448,   240,   449,    -1,   450,    -1,   449,   237,   450,
      -1,   451,    -1,   450,   244,   451,    -1,   452,    -1,   239,
     452,    -1,   453,    -1,   453,   476,    -1,   120,   446,   158,
      -1,   454,    -1,   454,   472,    -1,   382,    -1,   114,   315,
     155,    -1,   456,    -1,   475,    -1,   474,    -1,   477,    -1,
     471,    -1,   137,    -1,   458,    -1,   459,    -1,   460,    -1,
     461,    -1,   464,    -1,   469,    -1,   470,    -1,   243,    -1,
     254,    -1,   228,    -1,   227,    -1,   264,    -1,   258,    -1,
     231,    -1,   230,    -1,   265,    -1,   259,    -1,   267,   463,
      -1,   267,    67,    -1,   267,   120,   463,   158,    -1,   267,
     120,   463,    47,   462,   158,    -1,   267,   120,    67,   158,
      -1,   267,   120,    67,    47,   462,   158,    -1,   261,    -1,
     463,    -1,   462,    47,   463,    -1,    34,    23,    -1,    34,
      23,   248,    23,    -1,    34,    23,   473,   242,    -1,    34,
      23,   248,    23,   473,   242,    -1,   266,   466,    -1,   266,
     466,   465,    -1,   263,    -1,   263,   465,    -1,   260,    -1,
     468,    -1,   465,   468,    -1,    34,    23,    -1,   120,   467,
     158,    -1,    23,    -1,   467,    23,    -1,   180,   466,    -1,
      92,   466,    -1,   241,    23,    -1,   268,    -1,   262,    -1,
     226,    -1,   223,    -1,   234,    -1,   221,    -1,   222,    -1,
     219,    -1,   220,    -1,   247,    -1,   235,   350,    -1,   224,
     350,    -1,   225,   350,    -1,   236,   350,   177,   350,    -1,
     233,   473,   478,    -1,   256,   350,   478,    -1,   245,   473,
     253,    -1,   249,   479,    -1,   232,   479,    -1,   269,    -1,
     252,    -1,   246,    -1,   251,    -1,   246,    -1,   257,   350,
      -1
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
     384,   386,   388,   390,   392,   394,   396,   398,   402,   407,
     412,   418,   420,   423,   425,   427,   430,   432,   437,   441,
     446,   451,   457,   462,   468,   474,   481,   485,   489,   492,
     494,   499,   503,   508,   513,   519,   522,   525,   528,   530,
     534,   536,   539,   541,   543,   545,   548,   551,   554,   558,
     560,   562,   564,   566,   569,   574,   579,   581,   586,   590,
     595,   603,   613,   615,   618,   623,   631,   639,   641,   645,
     647,   651,   653,   657,   661,   665,   667,   671,   676,   678,
     682,   684,   688,   692,   694,   698,   702,   706,   710,   712,
     716,   720,   722,   726,   730,   732,   736,   738,   742,   744,
     748,   750,   754,   756,   759,   761,   763,   766,   769,   771,
     773,   775,   777,   779,   781,   783,   785,   787,   789,   791,
     793,   795,   797,   799,   801,   803,   805,   809,   814,   818,
     823,   825,   828,   832,   835,   837,   840,   843,   845,   847,
     851,   855,   857,   859,   861,   864,   866,   869,   872,   874,
     876,   878,   880,   882,   884,   886,   888,   890,   893,   896,
     898,   900,   902,   904,   906,   908,   910,   912,   914,   916,
     918,   920,   922,   924,   927,   929,   932,   936,   938,   940,
     942,   944,   946,   948,   950,   952,   954,   956,   958,   960,
     962,   965,   968,   972,   974,   978,   982,   986,   991,   993,
     997,   999,  1001,  1003,  1005,  1007,  1011,  1016,  1023,  1031,
    1039,  1048,  1050,  1053,  1055,  1058,  1062,  1066,  1070,  1071,
    1073,  1075,  1077,  1080,  1083,  1084,  1086,  1088,  1090,  1093,
    1096,  1098,  1100,  1102,  1104,  1106,  1108,  1110,  1112,  1114,
    1116,  1118,  1120,  1124,  1127,  1131,  1135,  1138,  1140,  1142,
    1144,  1146,  1148,  1150,  1154,  1157,  1161,  1167,  1174,  1177,
    1181,  1187,  1194,  1198,  1202,  1207,  1213,  1220,  1228,  1230,
    1233,  1236,  1238,  1241,  1243,  1245,  1247,  1249,  1251,  1253,
    1255,  1257,  1259,  1261,  1263,  1265,  1267,  1269,  1271,  1273,
    1275,  1278,  1281,  1285,  1289,  1292,  1295,  1298,  1302,  1306,
    1309,  1313,  1319,  1323,  1329,  1333,  1336,  1340,  1346,  1352,
    1356,  1362,  1368,  1372,  1374,  1377,  1379,  1382,  1385,  1388,
    1393,  1399,  1405,  1410,  1415,  1420,  1426,  1432,  1437,  1442,
    1445,  1448,  1453,  1458,  1463,  1470,  1472,  1477,  1481,  1487,
    1489,  1492,  1497,  1505,  1507,  1510,  1514,  1519,  1521,  1523,
    1526,  1529,  1531,  1535,  1537,  1541,  1543,  1547,  1549,  1552,
    1554,  1557,  1561,  1563,  1566,  1568,  1572,  1574,  1576,  1578,
    1580,  1582,  1584,  1586,  1588,  1590,  1592,  1594,  1596,  1598,
    1600,  1602,  1604,  1606,  1608,  1610,  1612,  1614,  1616,  1618,
    1621,  1624,  1629,  1636,  1641,  1648,  1650,  1652,  1656,  1659,
    1664,  1669,  1676,  1679,  1683,  1685,  1688,  1690,  1692,  1695,
    1698,  1702,  1704,  1707,  1710,  1713,  1716,  1718,  1720,  1722,
    1724,  1726,  1728,  1730,  1732,  1734,  1736,  1739,  1742,  1745,
    1750,  1754,  1758,  1762,  1765,  1768,  1770,  1772,  1774,  1776,
    1778
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   746,   746,   754,   762,   768,   780,   786,   798,   808,
     823,   838,   853,   862,   871,   886,   895,   912,   921,   938,
     945,   952,   959,   971,   978,   985,   994,  1007,  1014,  1021,
    1028,  1035,  1042,  1049,  1058,  1071,  1078,  1096,  1111,  1119,
    1133,  1142,  1157,  1173,  1187,  1195,  1210,  1218,  1232,  1241,
    1250,  1259,  1281,  1295,  1309,  1319,  1329,  1339,  1355,  1364,
    1382,  1389,  1402,  1411,  1421,  1430,  1447,  1457,  1467,  1477,
    1493,  1501,  1515,  1525,  1536,  1547,  1559,  1571,  1583,  1595,
    1607,  1617,  1628,  1639,  1651,  1663,  1675,  1687,  1705,  1716,
    1733,  1742,  1757,  1771,  1785,  1794,  1809,  1816,  1823,  1830,
    1837,  1846,  1853,  1860,  1867,  1874,  1881,  1893,  1903,  1914,
    1925,  1942,  1951,  1966,  1973,  1986,  2000,  2009,  2026,  2036,
    2047,  2059,  2072,  2083,  2095,  2107,  2125,  2140,  2154,  2169,
    2178,  2195,  2206,  2218,  2229,  2247,  2261,  2269,  2284,  2293,
    2310,  2319,  2334,  2344,  2354,  2364,  2374,  2384,  2394,  2410,
    2417,  2430,  2438,  2452,  2466,  2476,  2492,  2502,  2517,  2526,
    2542,  2552,  2569,  2578,  2593,  2602,  2618,  2632,  2639,  2653,
    2660,  2682,  2689,  2700,  2711,  2728,  2735,  2745,  2761,  2768,
    2782,  2789,  2796,  2809,  2815,  2822,  2829,  2836,  2849,  2856,
    2864,  2878,  2885,  2892,  2905,  2912,  2927,  2934,  2949,  2956,
    2971,  2978,  2993,  3000,  3015,  3022,  3029,  3036,  3051,  3058,
    3065,  3079,  3086,  3093,  3100,  3107,  3114,  3127,  3134,  3141,
    3148,  3155,  3162,  3175,  3182,  3189,  3203,  3210,  3225,  3234,
    3249,  3258,  3275,  3284,  3326,  3333,  3340,  3347,  3361,  3369,
    3376,  3389,  3396,  3409,  3418,  3427,  3436,  3451,  3460,  3474,
    3481,  3488,  3495,  3502,  3509,  3516,  3529,  3536,  3549,  3558,
    3573,  3580,  3587,  3594,  3601,  3619,  3626,  3639,  3646,  3659,
    3669,  3679,  3695,  3702,  3717,  3726,  3743,  3757,  3764,  3771,
    3778,  3785,  3792,  3799,  3806,  3819,  3826,  3839,  3847,  3855,
    3869,  3882,  3889,  3903,  3916,  3930,  3989,  3998,  4013,  4022,
    4037,  4044,  4057,  4064,  4071,  4084,  4095,  4106,  4117,  4128,
    4139,  4157,  4166,  4181,  4190,  4207,  4222,  4230,  4245,  4251,
    4258,  4267,  4276,  4287,  4304,  4310,  4317,  4326,  4335,  4346,
    4363,  4371,  4385,  4393,  4407,  4415,  4423,  4432,  4447,  4456,
    4464,  4472,  4486,  4494,  4512,  4520,  4540,  4558,  4565,  4572,
    4579,  4586,  4593,  4606,  4620,  4629,  4638,  4646,  4674,  4683,
    4692,  4700,  4714,  4728,  4742,  4751,  4760,  4768,  4782,  4791,
    4806,  4820,  4829,  4838,  4878,  4886,  4894,  4908,  4915,  4922,
    4935,  4949,  4956,  4963,  4970,  4977,  4984,  4991,  4998,  5005,
    5018,  5031,  5038,  5046,  5060,  5073,  5086,  5093,  5100,  5113,
    5122,  5131,  5140,  5149,  5164,  5178,  5187,  5196,  5205,  5214,
    5224,  5234,  5250,  5274,  5284,  5307,  5349,  5357,  5363,  5374,
    5383,  5392,  5401,  5410,  5420,  5429,  5438,  5447,  5456,  5471,
    5481,  5496,  5505,  5520,  5549,  5561,  5567,  5579,  5595,  5605,
    5615,  5629,  5639,  5666,  5672,  5678,  5684,  5696,  5702,  5708,
    5714,  5726,  5732,  5744,  5750,  5762,  5768,  5780,  5786,  5798,
    5804,  5810,  5822,  5828,  5840,  5846,  5858,  5864,  5870,  5876,
    5882,  5894,  5906,  5913,  5920,  5927,  5934,  5941,  5948,  5961,
    5967,  5973,  5979,  5991,  5997,  6003,  6009,  6021,  6027,  6039,
    6045,  6051,  6057,  6063,  6069,  6075,  6087,  6093,  6105,  6111,
    6117,  6123,  6135,  6141,  6147,  6153,  6159,  6171,  6177,  6189,
    6195,  6207,  6213,  6225,  6231,  6243,  6255,  6261,  6273,  6279,
    6285,  6297,  6303,  6309,  6315,  6321,  6333,  6339,  6345,  6351,
    6363,  6375,  6387,  6399,  6405,  6417,  6423,  6429,  6441,  6447,
    6459
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
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 3950;
  const int xquery_parser::yynnts_ = 200;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 325;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 281;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 535;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace yy

#line 6469 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"



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





