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

// Take the name prefix into account.
#define yylex   zorbalex

#include "xquery_parser.hpp"

/* User implementation prologue.  */
#line 712 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc.  */
#line 51 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"

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

namespace zorba
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
    #line 67 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = driver.theFilename.getStore();
}
  /* Line 547 of yacc.c.  */
#line 287 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
	yychar = yylex (&yylval, &yylloc);
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
#line 732 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [main]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr((yyval.node));
		;}
    break;

  case 3:
#line 740 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr((yyval.node));
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.main]" << endl;
#endif
		;}
    break;

  case 4:
#line 748 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [library]" << endl;
#endif
		;}
    break;

  case 5:
#line 754 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.library]" << endl;
#endif
		;}
    break;

  case 6:
#line 766 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version]" << endl;
#endif
		;}
    break;

  case 7:
#line 772 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version.encoding]" << endl;
#endif
		;}
    break;

  case 8:
#line 784 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 794 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 809 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 824 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 839 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 848 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 857 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 872 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 881 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 898 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 907 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 924 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [setter]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 931 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [import]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 938 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 945 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [default namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 957 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [var]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 964 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [function]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 971 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [option]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 980 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [ftoption]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 993 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [boundary space]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 1000 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [default collation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 1007 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [base uri]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 1014 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [construction]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 1021 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [ordering mode]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 1028 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [empty order]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 1035 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [copy namespaces]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 1044 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [revalidation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 1057 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [schema]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 1064 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [module]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 1082 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1097 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [preserve]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 39:
#line 1105 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [strip]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 40:
#line 1119 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1128 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1143 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1159 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOptionDecl [ ]" << endl;
#endif
			(yyval.node) = new FTOptionDecl(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 44:
#line 1173 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [ordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 45:
#line 1181 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [unordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 46:
#line 1196 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty greatest]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 47:
#line 1204 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty least]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 48:
#line 1218 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1227 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1236 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1245 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1267 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultCollationMode [ ]" << endl;
#endif
			(yyval.node) = new DefaultCollationDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 53:
#line 1281 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BaseURIDecl [ ]" << endl;
#endif
			(yyval.node) = new BaseURIDecl(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 54:
#line 1295 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1305 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1315 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1325 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1341 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1350 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1368 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [namespace]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1375 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [default element]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(driver.createQueryLoc((yyloc)), true);
		;}
    break;

  case 62:
#line 1388 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1397 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1407 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1416 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1433 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1443 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1453 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1463 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1479 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [preserve]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 71:
#line 1487 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [strip]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(driver.createQueryLoc((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 72:
#line 1501 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1511 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1522 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1533 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1545 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1557 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1569 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1581 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1593 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1603 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1614 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1625 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1637 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1649 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1661 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1673 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1691 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1702 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1719 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1728 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1743 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EnclosedExpr [ ]" << endl;
#endif
			(yyval.expr) = new EnclosedExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1757 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QueryBody [expr]" << endl;
#endif
			(yyval.expr) = new QueryBody(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 94:
#line 1771 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1780 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1795 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [FLWORExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 97:
#line 1802 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [QuantifiedExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1809 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TypeswitchExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1816 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [IfExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1823 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [OrExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1832 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [InsertExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1839 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [DeleteExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1846 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [RenameExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1853 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [ReplaceExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1860 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TransformExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1867 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
      cout << "ExprSingle [TryExpr]" << endl;
#endif
    ;}
    break;

  case 107:
#line 1879 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1889 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1900 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1911 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1928 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1937 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1952 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [for]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 114:
#line 1959 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [let]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 115:
#line 1972 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForClause [ ]" << endl;
#endif
			(yyval.node) = new ForClause(driver.createQueryLoc((yyloc)),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 116:
#line 1986 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1995 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2012 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2022 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2033 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2045 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2058 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2069 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2081 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2093 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2111 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PositionalVar [ ]" << endl;
#endif
			(yyval.node) = new PositionalVar(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 127:
#line 2126 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTScoreVar [ ]" << endl;
#endif
			(yyval.node) = new FTScoreVar(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 128:
#line 2140 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClause [ ]" << endl;
#endif
			(yyval.node) = new LetClause(driver.createQueryLoc((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)));
			
		;}
    break;

  case 129:
#line 2155 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2164 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2181 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2192 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2204 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2215 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2233 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "WhereClause [ ]" << endl;
#endif
			(yyval.node) = new WhereClause(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 136:
#line 2247 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [ ]" << endl;
#endif
			(yyval.node) = new OrderByClause(driver.createQueryLoc((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 137:
#line 2255 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2270 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2279 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2296 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2305 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2320 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2330 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2340 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2350 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2360 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2370 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2380 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2396 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [ascending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(driver.createQueryLoc((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 150:
#line 2403 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [descending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(driver.createQueryLoc((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 151:
#line 2416 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [greatest]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(driver.createQueryLoc((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 152:
#line 2424 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [least]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(driver.createQueryLoc((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 153:
#line 2438 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderCollationSpec [ ]" << endl;
#endif
			(yyval.node) = new OrderCollationSpec(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 154:
#line 2452 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2462 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2478 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2488 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2503 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2512 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2528 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2538 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2555 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2564 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2579 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2588 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2604 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IfExpr [ ]" << endl;
#endif
			(yyval.expr) = new IfExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 167:
#line 2618 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [and]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 168:
#line 2625 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [or.and]" << endl;
#endif
			(yyval.expr) = new OrExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 169:
#line 2639 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [comp]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 170:
#line 2646 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [and.comp]" << endl;
#endif
			(yyval.expr) = new AndExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 171:
#line 2668 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 172:
#line 2675 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2686 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2697 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2714 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 176:
#line 2721 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2731 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2747 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 179:
#line 2754 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add.to.add]" << endl;
#endif
			(yyval.expr) = new RangeExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 180:
#line 2768 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 181:
#line 2775 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult+mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 182:
#line 2782 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult-mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 183:
#line 2795 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [union]" << endl;
#endif
		;}
    break;

  case 184:
#line 2801 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult*union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 185:
#line 2808 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.div.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 186:
#line 2815 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.idiv.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 187:
#line 2822 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.mod.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 188:
#line 2835 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [interexcept]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 189:
#line 2842 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union.union.interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 190:
#line 2850 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union|interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 191:
#line 2864 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [instanceof]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 192:
#line 2871 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.inter.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 193:
#line 2878 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.except.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(driver.createQueryLoc((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 194:
#line 2891 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 195:
#line 2898 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2913 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 197:
#line 2920 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2935 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 199:
#line 2942 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2957 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 201:
#line 2964 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2979 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [value]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 203:
#line 2986 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3001 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [+]" << endl;
#endif
			(yyval.node) = new SignList(driver.createQueryLoc((yyloc)), true);
		;}
    break;

  case 205:
#line 3008 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [-]" << endl;
#endif
			(yyval.node) = new SignList(driver.createQueryLoc((yyloc)), false);
		;}
    break;

  case 206:
#line 3015 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.+]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 207:
#line 3022 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3037 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [validate]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 209:
#line 3044 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [path]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 210:
#line 3051 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [extension]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 211:
#line 3065 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [=]" << endl;
#endif
			(yyval.node) = new GeneralComp(driver.createQueryLoc((yyloc)), ParseConstants::op_eq);
		;}
    break;

  case 212:
#line 3072 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [!=]" << endl;
#endif
			(yyval.node) = new GeneralComp(driver.createQueryLoc((yyloc)), ParseConstants::op_ne);
		;}
    break;

  case 213:
#line 3079 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<]" << endl;
#endif
			(yyval.node) = new GeneralComp(driver.createQueryLoc((yyloc)), ParseConstants::op_lt);
		;}
    break;

  case 214:
#line 3086 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<=]" << endl;
#endif
			(yyval.node) = new GeneralComp(driver.createQueryLoc((yyloc)), ParseConstants::op_le);
		;}
    break;

  case 215:
#line 3093 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>]" << endl;
#endif
			(yyval.node) = new GeneralComp(driver.createQueryLoc((yyloc)), ParseConstants::op_gt);
		;}
    break;

  case 216:
#line 3100 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>=]" << endl;
#endif
			(yyval.node) = new GeneralComp(driver.createQueryLoc((yyloc)), ParseConstants::op_ge);
		;}
    break;

  case 217:
#line 3113 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [eq]" << endl;
#endif
			(yyval.node) = new ValueComp(driver.createQueryLoc((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 218:
#line 3120 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ne]" << endl;
#endif
			(yyval.node) = new ValueComp(driver.createQueryLoc((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 219:
#line 3127 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [lt]" << endl;
#endif
			(yyval.node) = new ValueComp(driver.createQueryLoc((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 220:
#line 3134 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [le]" << endl;
#endif
			(yyval.node) = new ValueComp(driver.createQueryLoc((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 221:
#line 3141 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [gt]" << endl;
#endif
			(yyval.node) = new ValueComp(driver.createQueryLoc((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 222:
#line 3148 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ge]" << endl;
#endif
			(yyval.node) = new ValueComp(driver.createQueryLoc((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 223:
#line 3161 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [is]" << endl;
#endif
			(yyval.node) = new NodeComp(driver.createQueryLoc((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 224:
#line 3168 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [<<]" << endl;
#endif
			(yyval.node) = new NodeComp(driver.createQueryLoc((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 225:
#line 3175 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [>>]" << endl;
#endif
			(yyval.node) = new NodeComp(driver.createQueryLoc((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 226:
#line 3189 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [expr]" << endl;
#endif
			(yyval.expr) = new ValidateExpr(driver.createQueryLoc((yyloc)), "strict", (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 227:
#line 3196 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3211 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3220 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3235 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3244 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3261 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3269 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 234:
#line 3312 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/]" << endl;
#endif
			(yyval.expr) = new PathExpr(driver.createQueryLoc((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 235:
#line 3319 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(driver.createQueryLoc((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 236:
#line 3326 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [//relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(driver.createQueryLoc((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 237:
#line 3333 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [relative]" << endl;
#endif
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = rpe == NULL ? (yysemantic_stack_[(1) - (1)].expr) : new PathExpr(driver.createQueryLoc((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 238:
#line 3347 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step]" << endl;
#endif
            AxisStep *as = dynamic_cast<AxisStep *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = as != NULL ? new RelativePathExpr(driver.createQueryLoc((yyloc)), ParseConstants::st_slash, new ContextItemExpr(driver.createQueryLoc((yyloc))), (yysemantic_stack_[(1) - (1)].expr)) : (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 239:
#line 3355 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step/relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(driver.createQueryLoc((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 240:
#line 3362 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step//relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(driver.createQueryLoc((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 241:
#line 3375 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [axis]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 242:
#line 3382 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [filter]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 243:
#line 3395 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3404 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3413 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3422 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3437 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3446 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [abbrev]" << endl;
#endif
			(yyval.node) = new ForwardStep(driver.createQueryLoc((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 249:
#line 3460 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [child]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 250:
#line 3467 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 251:
#line 3474 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [attribute]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 252:
#line 3481 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 253:
#line 3488 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant_or_self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 254:
#line 3495 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following_sibling]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 255:
#line 3502 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following]" << endl;
#endif
			(yyval.node) = new ForwardAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 256:
#line 3515 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(driver.createQueryLoc((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 257:
#line 3522 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [@ nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(driver.createQueryLoc((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 258:
#line 3535 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3544 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3559 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [parent]" << endl;
#endif
			(yyval.node) = new ReverseAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 261:
#line 3566 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor]" << endl;
#endif
			(yyval.node) = new ReverseAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 262:
#line 3573 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding_sibling]" << endl;
#endif
			(yyval.node) = new ReverseAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 263:
#line 3580 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding]" << endl;
#endif
			(yyval.node) = new ReverseAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 264:
#line 3587 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor_or_self]" << endl;
#endif
			(yyval.node) = new ReverseAxis(driver.createQueryLoc((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 265:
#line 3605 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [kindtest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 266:
#line 3612 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [nametest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 267:
#line 3625 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [qname]" << endl;
#endif
			(yyval.node) = new NameTest(driver.createQueryLoc((yyloc)), new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 268:
#line 3632 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [wildcard]" << endl;
#endif
			(yyval.node) = new NameTest(driver.createQueryLoc((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 269:
#line 3645 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3655 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3665 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3681 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 273:
#line 3688 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3703 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3712 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3729 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Predicate [ ]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 277:
#line 3743 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [literal]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 278:
#line 3750 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [varref]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 279:
#line 3757 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [paren]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 280:
#line 3764 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [context_item]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 281:
#line 3771 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [funcall]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 282:
#line 3778 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [cons]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 283:
#line 3785 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [ordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 284:
#line 3792 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [unordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 285:
#line 3805 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [numeric]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 286:
#line 3812 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [string]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 287:
#line 3825 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [decimal]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(driver.createQueryLoc((yyloc)), *yylval.decval);
      delete yylval.decval;
		;}
    break;

  case 288:
#line 3833 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [int]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(driver.createQueryLoc((yyloc)), *yylval.ival);
      delete yylval.ival;
		;}
    break;

  case 289:
#line 3841 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [double]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(driver.createQueryLoc((yyloc)), *yylval.dval);
      delete yylval.dval;
		;}
    break;

  case 290:
#line 3855 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarRef [ ]" << endl;
#endif
			(yyval.expr) = new VarRef(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 291:
#line 3868 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [()]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(driver.createQueryLoc((yyloc)), NULL);
		;}
    break;

  case 292:
#line 3875 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [(expr)]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 293:
#line 3889 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ContextItemExpr [.]" << endl;
#endif
			(yyval.expr) = new ContextItemExpr(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 294:
#line 3902 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new OrderedExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 295:
#line 3916 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnorderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new UnorderedExpr(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 296:
#line 3975 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3984 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3999 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4008 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4023 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [direct]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 301:
#line 4030 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [computed]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 4043 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [element]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 303:
#line 4050 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 304:
#line 4057 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 305:
#line 4070 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4081 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4092 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4103 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4114 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4125 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4143 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4152 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4167 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4176 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4193 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4208 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [quote]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(driver.createQueryLoc((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 317:
#line 4216 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [apos]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(driver.createQueryLoc((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 318:
#line 4230 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList[empty]" << endl;
#endif
			(yyval.node) = new QuoteAttrContentList(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 319:
#line 4237 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 320:
#line 4244 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4253 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4262 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4273 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4289 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']" << endl;
#endif
			(yyval.node) = new AposAttrContentList(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 325:
#line 4296 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 326:
#line 4303 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4312 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4321 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4332 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4349 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [quote_attr_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 331:
#line 4357 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(driver.createQueryLoc((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 332:
#line 4371 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [apos_attr_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 333:
#line 4379 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(driver.createQueryLoc((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 334:
#line 4393 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cons]" << endl;
#endif
			(yyval.expr) = new DirElemContent(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 335:
#line 4401 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [elem_content]" << endl;
#endif
			(yyval.expr) = new DirElemContent(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 336:
#line 4409 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4418 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4433 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [char_ref]\n";
#endif
			(yyval.expr) = new CommonContent(driver.createQueryLoc((yyloc)),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 339:
#line 4442 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [{{]" << endl;
#endif
			(yyval.expr) = new CommonContent(driver.createQueryLoc((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 340:
#line 4450 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [}}]" << endl;
#endif
			(yyval.expr) = new CommonContent(driver.createQueryLoc((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 341:
#line 4458 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [expr]" << endl;
#endif
			(yyval.expr) = new CommonContent(driver.createQueryLoc((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 342:
#line 4472 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirCommentConstructor [ ]" << endl;
#endif
			(yyval.expr) = new DirCommentConstructor(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 343:
#line 4480 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "DirCommentConstructor [ ]" << endl;
#endif
      (yyval.expr) = new DirCommentConstructor(driver.createQueryLoc((yyloc)), "");
    ;}
    break;

  case 344:
#line 4498 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new DirPIConstructor(driver.createQueryLoc((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 345:
#line 4506 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4526 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CDataSection [ ]" << endl;
#endif
			(yyval.expr) = new CDataSection(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 347:
#line 4544 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [doc]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 348:
#line 4551 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [elem]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 349:
#line 4558 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [attr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 350:
#line 4565 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [text]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 351:
#line 4572 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 352:
#line 4579 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 353:
#line 4592 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompDocConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompDocConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 354:
#line 4606 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4615 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4624 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 357:
#line 4632 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name.content]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 358:
#line 4660 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4669 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4678 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 361:
#line 4686 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name.val]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 362:
#line 4700 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompTextConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompTextConstructor(driver.createQueryLoc((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 363:
#line 4714 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompCommentConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompCommentConstructor(driver.createQueryLoc((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 364:
#line 4728 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4737 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4746 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 367:
#line 4754 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target.content]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(driver.createQueryLoc((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 368:
#line 4768 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4777 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4792 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeDeclaration [as seqtype]" << endl;
#endif
			(yyval.node) = new TypeDeclaration(driver.createQueryLoc((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 371:
#line 4806 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4815 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4824 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [void]" << endl;
#endif
			(yyval.node) = new SequenceType(driver.createQueryLoc((yyloc)), NULL, NULL);
		;}
    break;

  case 374:
#line 4864 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [?]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(driver.createQueryLoc((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 375:
#line 4872 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [*]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(driver.createQueryLoc((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 376:
#line 4880 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [+]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(driver.createQueryLoc((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 377:
#line 4894 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [atomic]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 378:
#line 4901 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [kind]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 379:
#line 4908 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [item]" << endl;
#endif
			(yyval.node) = new ItemType(driver.createQueryLoc((yyloc)),true);
		;}
    break;

  case 380:
#line 4921 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AtomicType [qname]" << endl;
#endif
			(yyval.node) = new AtomicType(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 381:
#line 4935 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [doc]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 382:
#line 4942 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 383:
#line 4949 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 384:
#line 4956 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 385:
#line 4963 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 386:
#line 4970 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [pi]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 387:
#line 4977 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [comment]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 388:
#line 4984 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [text]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 389:
#line 4991 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [any]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 390:
#line 5004 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AnyKindTest [ ]" << endl;
#endif
			(yyval.node) = new AnyKindTest(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 391:
#line 5017 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [ ]" << endl;
#endif
			(yyval.node) = new DocumentTest(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 392:
#line 5024 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(driver.createQueryLoc((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 393:
#line 5032 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [schema_elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(driver.createQueryLoc((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 394:
#line 5046 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TextTest [ ]" << endl;
#endif
			(yyval.node) = new TextTest(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 395:
#line 5059 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommentTest [ ]" << endl;
#endif
			(yyval.node) = new CommentTest(driver.createQueryLoc((yyloc)));
		;}
    break;

  case 396:
#line 5072 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ ]" << endl;
#endif
			(yyval.node) = new PITest(driver.createQueryLoc((yyloc)), "");
		;}
    break;

  case 397:
#line 5079 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ncname]" << endl;
#endif
			(yyval.node) = new PITest(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 398:
#line 5086 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [stringlit]" << endl;
#endif
			(yyval.node) = new PITest(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 399:
#line 5099 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5108 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5117 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5126 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5135 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5150 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaAttributeTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaAttributeTest(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 405:
#line 5164 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5173 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5182 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5191 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5200 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5210 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5220 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5236 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaElementTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaElementTest(driver.createQueryLoc((yyloc)),
									new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 413:
#line 5260 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name]" << endl;
#endif
			(yyval.node) = new TypeName(driver.createQueryLoc((yyloc)),
								new QName(driver.createQueryLoc((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 414:
#line 5270 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5293 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StringLiteral [ ]" << endl;
#endif
			(yyval.expr) = new StringLiteral(driver.createQueryLoc((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 416:
#line 5335 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [strict]" << endl;
#endif
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 417:
#line 5343 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [lax]" << endl;
#endif
    ;}
    break;

  case 418:
#line 5349 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [skip]" << endl;
#endif
    ;}
    break;

  case 419:
#line 5360 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5369 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5378 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5387 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5396 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5406 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5415 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5424 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5433 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5442 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5457 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5467 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5482 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5491 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5506 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RenameExpr [expr.expr]" << endl;
#endif
       (yyval.expr) = new RenameExpr(
                  driver.createQueryLoc((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 434:
#line 5535 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TransformExpr [ ]" << endl;
#endif
		;}
    break;

  case 435:
#line 5547 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [single]" << endl;
#endif
		;}
    break;

  case 436:
#line 5553 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [list]" << endl;
#endif
		;}
    break;

  case 437:
#line 5565 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "VarNameDecl [" << driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)) << "]" << endl;
#endif
    ;}
    break;

  case 438:
#line 5581 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TryExpr []" << endl;
#endif
       (yyval.expr) = new TryExpr(driver.createQueryLoc((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 439:
#line 5591 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5601 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5615 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5625 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5652 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or]" << endl;
#endif
		;}
    break;

  case 444:
#line 5658 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity]" << endl;
#endif
		;}
    break;

  case 445:
#line 5664 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.weight_range]" << endl;
#endif
		;}
    break;

  case 446:
#line 5670 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity.weight_range]" << endl;
#endif
		;}
    break;

  case 447:
#line 5682 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_single]" << endl;
#endif
		;}
    break;

  case 448:
#line 5688 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_single]" << endl;
#endif
		;}
    break;

  case 449:
#line 5694 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_list]" << endl;
#endif
		;}
    break;

  case 450:
#line 5700 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_list]" << endl;
#endif
		;}
    break;

  case 451:
#line 5712 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [and]" << endl;
#endif
		;}
    break;

  case 452:
#line 5718 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [or.and]" << endl;
#endif
		;}
    break;

  case 453:
#line 5730 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [mild_not]" << endl;
#endif
		;}
    break;

  case 454:
#line 5736 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [and.mild_not]" << endl;
#endif
		;}
    break;

  case 455:
#line 5748 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [unary_not]" << endl;
#endif
		;}
    break;

  case 456:
#line 5754 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [mild_not.unary_not]" << endl;
#endif
		;}
    break;

  case 457:
#line 5766 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [words]" << endl;
#endif
		;}
    break;

  case 458:
#line 5772 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [not.words]" << endl;
#endif
		;}
    break;

  case 459:
#line 5784 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words]" << endl;
#endif
		;}
    break;

  case 460:
#line 5790 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words.times]" << endl;
#endif
		;}
    break;

  case 461:
#line 5796 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [selection]" << endl;
#endif
		;}
    break;

  case 462:
#line 5808 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value]" << endl;
#endif
		;}
    break;

  case 463:
#line 5814 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value.any_all_option]" << endl;
#endif
		;}
    break;

  case 464:
#line 5826 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [literal]" << endl;
#endif
		;}
    break;

  case 465:
#line 5832 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [expr]" << endl;
#endif
		;}
    break;

  case 466:
#line 5844 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [order]" << endl;
#endif
		;}
    break;

  case 467:
#line 5850 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [window]" << endl;
#endif
		;}
    break;

  case 468:
#line 5856 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [distance]" << endl;
#endif
		;}
    break;

  case 469:
#line 5862 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [scope]" << endl;
#endif
		;}
    break;

  case 470:
#line 5868 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [content]" << endl;
#endif
		;}
    break;

  case 471:
#line 5880 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOrderedIndicator [ ]" << endl;
#endif
		;}
    break;

  case 472:
#line 5892 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [case]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 473:
#line 5899 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [diacritics]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 474:
#line 5906 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 475:
#line 5913 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [thesaurus]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 476:
#line 5920 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stopword]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 477:
#line 5927 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [language]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 478:
#line 5934 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [wildcard]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 479:
#line 5947 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [lower]" << endl;
#endif
		;}
    break;

  case 480:
#line 5953 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [upper]" << endl;
#endif
		;}
    break;

  case 481:
#line 5959 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [sensitive]" << endl;
#endif
		;}
    break;

  case 482:
#line 5965 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [insensitive]" << endl;
#endif
		;}
    break;

  case 483:
#line 5977 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [with]" << endl;
#endif
		;}
    break;

  case 484:
#line 5983 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [without]" << endl;
#endif
		;}
    break;

  case 485:
#line 5989 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [sensitive]" << endl;
#endif
		;}
    break;

  case 486:
#line 5995 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [insensitive]" << endl;
#endif
		;}
    break;

  case 487:
#line 6007 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [with]" << endl;
#endif
		;}
    break;

  case 488:
#line 6013 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [without]" << endl;
#endif
		;}
    break;

  case 489:
#line 6025 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [id]" << endl;
#endif
		;}
    break;

  case 490:
#line 6031 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [default]" << endl;
#endif
		;}
    break;

  case 491:
#line 6037 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id)]" << endl;
#endif
		;}
    break;

  case 492:
#line 6043 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id,id,..)]" << endl;
#endif
		;}
    break;

  case 493:
#line 6049 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default)]" << endl;
#endif
		;}
    break;

  case 494:
#line 6055 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default,id,id,..)]" << endl;
#endif
		;}
    break;

  case 495:
#line 6061 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [without]" << endl;
#endif
		;}
    break;

  case 496:
#line 6073 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [single]" << endl;
#endif
		;}
    break;

  case 497:
#line 6079 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [list]" << endl;
#endif
		;}
    break;

  case 498:
#line 6091 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name]" << endl;
#endif
		;}
    break;

  case 499:
#line 6097 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel]" << endl;
#endif
		;}
    break;

  case 500:
#line 6103 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.range]" << endl;
#endif
		;}
    break;

  case 501:
#line 6109 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel.range]" << endl;
#endif
		;}
    break;

  case 502:
#line 6121 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list]" << endl;
#endif
		;}
    break;

  case 503:
#line 6127 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list.incl_excl]" << endl;
#endif
		;}
    break;

  case 504:
#line 6133 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default]" << endl;
#endif
		;}
    break;

  case 505:
#line 6139 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default.incl_excl]" << endl;
#endif
		;}
    break;

  case 506:
#line 6145 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [without]" << endl;
#endif
		;}
    break;

  case 507:
#line 6157 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 508:
#line 6163 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 509:
#line 6175 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [.]" << endl;
#endif
		;}
    break;

  case 510:
#line 6181 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [(*)]" << endl;
#endif
		;}
    break;

  case 511:
#line 6193 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 512:
#line 6199 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 513:
#line 6211 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [union]" << endl;
#endif
		;}
    break;

  case 514:
#line 6217 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [except]" << endl;
#endif
		;}
    break;

  case 515:
#line 6229 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTLanguageOption [ ]" << endl;
#endif
		;}
    break;

  case 516:
#line 6241 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [with]" << endl;
#endif
		;}
    break;

  case 517:
#line 6247 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [without]" << endl;
#endif
		;}
    break;

  case 518:
#line 6259 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [start]" << endl;
#endif
		;}
    break;

  case 519:
#line 6265 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [end]" << endl;
#endif
		;}
    break;

  case 520:
#line 6271 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [entire]" << endl;
#endif
		;}
    break;

  case 521:
#line 6283 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any]" << endl;
#endif
		;}
    break;

  case 522:
#line 6289 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any_word]" << endl;
#endif
		;}
    break;

  case 523:
#line 6295 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all]" << endl;
#endif
		;}
    break;

  case 524:
#line 6301 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all_words]" << endl;
#endif
		;}
    break;

  case 525:
#line 6307 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [phrase]" << endl;
#endif
		;}
    break;

  case 526:
#line 6319 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [exactly]" << endl;
#endif
		;}
    break;

  case 527:
#line 6325 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_least]" << endl;
#endif
		;}
    break;

  case 528:
#line 6331 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_most]" << endl;
#endif
		;}
    break;

  case 529:
#line 6337 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [range]" << endl;
#endif
		;}
    break;

  case 530:
#line 6349 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDistance [ ]" << endl;
#endif
		;}
    break;

  case 531:
#line 6361 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWindow [ ]" << endl;
#endif
		;}
    break;

  case 532:
#line 6373 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [ ]" << endl;
#endif
		;}
    break;

  case 533:
#line 6385 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [same]" << endl;
#endif
		;}
    break;

  case 534:
#line 6391 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [different]" << endl;
#endif
		;}
    break;

  case 535:
#line 6403 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [words]" << endl;
#endif
		;}
    break;

  case 536:
#line 6409 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [sentences]" << endl;
#endif
		;}
    break;

  case 537:
#line 6415 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 538:
#line 6427 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [sentence]" << endl;
#endif
		;}
    break;

  case 539:
#line 6433 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 540:
#line 6445 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTIgnoreOption [ ]" << endl;
#endif
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6320 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -654;
  const short int
  xquery_parser::yypact_[] =
  {
       745,  1161,  1369,  -654,  -654,    23,  -654,    37,  -654,  -654,
    -654,  3033,    56,   440,  -654,  3033,   -22,  -654,   266,    -6,
     191,    16,   323,   172,   175,   377,   341,   365,   351,   -49,
     390,   421,  -654,  -654,  3033,   339,   464,  -654,  -654,  -654,
    3033,    72,   474,  -654,  -654,   478,  3033,   253,   223,  -654,
     502,  1577,  -654,   451,   373,  3033,  -654,   465,    69,  -654,
     456,  -654,  -654,   268,   520,   525,  -654,  3539,  3390,   474,
    -654,   528,  3033,   415,  3033,  3033,  3033,    -4,   379,   386,
    3033,  3033,  3033,  3033,  3033,  3033,  3033,   550,   467,  3580,
     580,   953,  -654,  -654,   248,  3033,   427,   433,  -654,  -654,
    -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,
    -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,   561,  -654,
    -654,   315,  -654,  -654,  -654,  -654,  -654,  -654,   480,   597,
    -654,  3268,   397,   338,   383,   336,    13,  -654,   536,   469,
     609,   610,   567,  -654,  -654,  -654,   -20,  -654,  -654,  -654,
     385,  -654,   538,   440,  -654,   538,   440,  -654,  -654,  -654,
    -654,   538,  -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,
    -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,
    -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,
    -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,
    -654,    14,  -654,    91,  1785,  3033,   103,    27,  -654,    35,
    -654,  -654,   124,  -654,  -654,  -654,  -654,  -654,  -654,   604,
     607,  -654,   631,   632,  -654,  -654,   537,   570,   636,  -654,
    -654,   540,   283,   126,  -654,   505,   506,  -654,   128,    65,
    -654,    90,   308,     7,  -654,    -1,   618,  -654,   102,   633,
     654,   638,   545,   659,   650,   -13,   628,  -654,  -654,   108,
     588,  -654,   203,    40,   522,   523,  -654,   661,  -654,   568,
    3033,   526,   527,  -654,  -654,    19,    24,   245,  -654,   109,
     251,   271,   490,  -654,   201,  -654,  -654,  -654,  -654,  -654,
      17,    58,   651,   472,   475,   590,    -3,  -654,  3033,  -654,
    -654,  -654,  -654,   669,  -654,  -654,  -654,  -654,  -654,  -654,
    -654,   -21,  -654,  -654,   244,   252,  -654,  -654,  -654,  -654,
    -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,
     248,     2,  3033,  3033,  3033,  3033,  3033,  -654,   -23,   541,
    3241,  3241,  -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,
    -654,  -654,  -654,  -654,  -654,  -654,  -654,  3241,  3241,  3241,
       5,  3241,  3241,  3241,  3241,  3241,  3241,  3241,  3241,  3241,
    3241,  3241,   405,   405,   674,   674,  -654,  -654,  -654,  1993,
    -654,  3390,  3390,  3033,   538,  -654,  -654,   538,  -654,   538,
    -654,  -654,  -654,  -654,   110,   273,   581,   675,  -654,   675,
    -654,  -654,    -5,     0,  -654,  -654,   255,   673,  -654,   294,
     405,  -654,  3033,     9,  -654,  -654,  -654,   585,   681,  -654,
     681,  -654,  3033,   594,   627,  3033,   634,  3033,   635,   -18,
     596,   -12,   637,   530,   691,   639,   691,  -654,   643,   682,
    3033,   619,   -64,   646,  -654,   698,  -654,  -654,  -654,  -654,
    -654,  -654,  2201,   274,  -654,  -654,  3033,   647,  -654,    33,
      36,  -654,  -654,   683,  -654,  -654,  -654,   701,  -654,   209,
    3033,  3033,  3033,   324,  3033,  3033,  3033,  3033,  3033,  3033,
    3033,   662,  3033,   571,  -654,   244,   244,   -21,  -654,   702,
     711,   -21,   716,  -654,    62,  -654,   576,  -654,  -654,  -654,
     436,   696,  -654,  -654,   696,  -654,  3033,   587,  3033,   597,
    -654,  -654,  -654,  -654,  3033,     5,   388,  -654,   488,  3492,
     509,   503,  -654,  -654,   507,   321,   383,   383,   211,   336,
     336,   336,   336,    13,    13,  -654,  -654,  -654,  -654,  -654,
    -654,   487,  -654,  -654,  -654,  -654,   648,  -654,  -654,   275,
    -654,  -654,    70,  -654,  3033,  -654,  -654,  2409,  -654,   593,
     595,  -654,  -654,  -654,  -654,   729,    25,   405,    22,  -654,
    -654,    47,   405,   106,  -654,  -654,  -654,  3033,  2617,   656,
     602,   608,   612,   614,  -654,  3033,   474,  -654,   740,  -654,
     742,  3033,   668,  3033,  3033,   -10,   670,   478,  3033,  -654,
     731,   752,   731,  -654,   691,  -654,  3033,  3033,   679,   502,
     616,  -654,   276,   672,  -654,    89,  -654,  -654,   782,  -654,
    -654,  3033,   770,  -654,  -654,    50,  -654,  -654,  -654,  -654,
      64,  -654,   242,    74,  -654,   629,  3033,  3033,  -654,  -654,
    -654,  3033,  3033,  -654,  -654,  -654,  -654,  -654,  -654,  -654,
     550,   655,   573,  -654,  -654,  -654,  -654,  -654,    41,   -21,
     375,   111,   113,     2,  -654,   768,  -654,  -654,  -654,  -654,
     243,   748,  -654,  3033,  -654,  3033,  -654,   279,   658,  -654,
    3241,  -654,  -654,  -654,  -654,   217,   389,  -654,     5,   217,
    3241,  3241,  3538,  -654,  -654,  -654,  -654,  -654,  -654,  -654,
       5,     5,   389,  -654,  -654,  -654,  -654,  -654,  -654,  -654,
    -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,   287,
    -654,  -654,   781,  -654,  -654,   263,   750,   356,   405,  -654,
    -654,   371,   378,   405,  -654,  -654,   290,  -654,  -654,  -654,
    -654,  -654,  -654,  -654,  -654,  -654,  -654,  3033,  -654,  -654,
    3033,   710,  3033,  -654,   746,   799,   794,   731,  -654,  -654,
    3033,  -654,  -654,  -654,  2825,   327,   410,  -654,  -654,   292,
     657,   812,  -654,   813,    92,   808,   677,   210,  -654,  -654,
    -654,  -654,  -654,  -654,  -654,  3033,    67,   573,  -654,  -654,
    -654,  3241,  3241,  3241,  3241,   814,   599,   801,  -654,   801,
    -654,  -654,   748,  -654,  -654,  -654,  -654,  -654,  -654,   336,
    -654,  -654,  -654,  -148,   509,  -654,  -654,   313,  3241,  -654,
    -654,   503,  -654,   592,  -654,  -654,  -654,  -654,  -654,  -654,
    -654,   381,  -654,  -654,  -654,  -654,   418,  -654,  -654,  -654,
    3033,  -654,  3033,  -654,   691,  -654,  -654,   295,  -654,  -654,
     815,   330,  -654,  -654,  -654,  -654,   689,   458,  -654,  -654,
    -654,  -654,   680,   684,   828,   816,  3033,   827,  3033,  -654,
     115,  -654,   336,   336,   336,   353,   389,  -654,   116,  -654,
     118,  -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,
    -654,  -654,  -654,  -654,  -654,   731,  -654,  -654,  -654,  -654,
    -654,  -654,  -654,  -654,  -654,   685,   405,  -654,   697,  -654,
     784,   747,  3241,   620,   801,  -654,  -654,  -654,   699,  3033,
     835,  -654,   336,  -654,  -654,  3033,  -654,   706,  -654,   747,
    -654
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
       0,   364,     0,     0,   154,     0,   338,   335,     0,   339,
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
      -654,  -654,  -654,   776,   778,  -654,   777,  -654,   542,   543,
    -312,  -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,
    -654,  -654,  -654,  -654,  -420,  -654,  -654,  -654,  -654,  -654,
     468,   148,  -536,   783,     6,   -80,  -654,  -654,   755,  -654,
    -654,   282,   449,  -228,  -654,  -654,   280,  -654,   544,   546,
     212,  -654,  -654,   213,  -617,  -654,   819,   305,  -654,  -654,
     261,  -654,  -654,   555,   557,   272,  -619,   539,   193,  -354,
     196,   262,  -654,  -654,  -654,  -654,  -654,   758,  -654,  -654,
    -654,  -654,  -654,  -654,   757,  -654,   -29,  -654,  -654,  -654,
    -654,  -654,  -654,  -654,    87,   119,  -654,  -654,   369,   188,
    -654,  -338,  -654,  -654,  -654,  -654,  -654,  -654,  -654,  -654,
    -654,  -428,  -654,   284,  -654,   441,  -654,  -654,  -654,  -654,
    -654,    49,    53,  -584,  -469,  -654,  -654,  -654,  -654,  -654,
    -654,  -654,  -654,  -654,  -654,   535,  -227,  -359,  -654,  -654,
     260,  -347,  -654,  -654,  -654,  -654,  -654,  -654,  -654,   881,
     883,  -265,   499,  -654,  -654,  -654,  -654,  -654,  -654,  -654,
    -654,   277,  -654,  -654,   135,   408,  -654,  -654,   236,   226,
     228,   414,  -654,  -654,   239,  -654,  -483,  -654,  -654,  -654,
    -654,   133,  -306,  -654,   442,   154,  -654,  -440,  -654,  -654,
    -654,  -654,  -653,  -654,  -654,  -654,  -654,   117,   246,  -654
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
     410,   212,   517,   426,   282,   543,   543,   441,   442,     6,
     724,   624,   410,   813,   426,   730,   695,   607,   273,   274,
     233,   772,   616,   617,   457,   481,   238,   655,   447,   823,
     469,   574,   248,   803,   804,   424,   457,   259,    17,   616,
     617,   262,   332,   543,    26,   789,    28,   424,    30,    31,
     726,   816,   485,   616,   617,   397,   207,   618,   277,     3,
     279,   280,   281,   399,   264,    39,     4,   210,   440,   229,
     591,   473,   239,   265,   618,   379,   594,   492,   750,   882,
     211,   616,   617,   576,   561,   883,   370,   427,   618,   563,
     577,   458,   619,   418,   620,   632,    49,   333,   332,   723,
     514,   765,   884,   629,   393,   371,   515,   562,    60,   619,
     661,   620,   564,   230,   560,   506,   618,   213,   420,   332,
     621,   729,   777,   619,   204,   620,   335,   215,   621,   219,
     332,   332,   205,   580,   726,   582,   332,   332,   554,   797,
     486,   799,   621,   910,   914,   621,   914,   216,   425,   220,
     390,   619,   332,   620,   332,    57,   332,   517,   517,   621,
     456,   727,   728,   448,   757,   881,   398,   428,   662,   827,
     772,   830,    57,   283,   400,   833,   835,   624,   459,   887,
     790,   592,   624,   596,   622,    71,    57,   621,   725,   820,
     630,   395,   482,   731,   608,   208,   470,   471,   483,   655,
     543,   771,    71,   913,   419,   543,   209,   716,   266,    77,
     472,   240,    89,   428,    57,   773,    71,    70,   428,   428,
     386,   428,   241,   388,   766,   516,    77,   391,   251,   421,
     428,   332,   499,   500,   503,   500,   505,   474,   475,   396,
      77,   433,   537,   864,    71,   732,   733,   444,   463,   555,
     798,   476,   800,   776,   911,   915,   453,   916,   249,   489,
     401,    12,   414,   269,   417,   543,   867,   492,    77,   467,
     665,   214,   252,   332,    16,   890,   853,   859,   222,   332,
     892,   223,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   410,    35,   775,   332,
     493,   332,   332,   332,   332,    41,   809,   332,   667,   668,
     848,   565,   575,   848,   361,   332,   616,   817,   332,   616,
     332,   410,   584,   332,   217,   587,   624,   589,   221,   253,
     517,   498,   550,   551,    47,    48,   538,   826,   362,   446,
     605,   226,   517,   517,   218,   490,   468,   751,   868,   831,
     565,   228,    54,   494,   836,   921,   614,   411,   621,   250,
     227,   543,   853,   270,   412,   549,   543,    58,   859,   552,
     638,   639,   640,   930,   643,   644,   645,   646,   647,   648,
     649,   462,   651,   284,    64,    65,   619,   464,   620,   619,
     231,   620,     6,    45,   566,   567,   422,   849,    73,   616,
     898,   636,    41,   637,   895,   537,   674,   465,   676,   556,
     613,   715,   763,   854,    50,   807,   539,   872,   873,   874,
     875,    17,   621,   824,    12,   621,   837,   232,   860,    79,
     829,   896,     3,   571,   572,   333,   364,    16,   612,     4,
     210,   361,   224,   225,   810,   832,   260,   616,    39,   811,
     664,   621,   834,   334,   717,   889,   267,   268,    89,    12,
      35,   854,   263,   665,   335,   362,   621,   365,    41,   619,
     237,   620,    16,   621,   368,   825,   621,   734,   234,    49,
     242,   855,    65,   514,   245,   742,   369,   366,   666,   515,
     336,   746,   891,   748,   749,    35,   363,   368,   754,   538,
     677,   667,   668,    41,   387,   621,   758,   759,   255,   369,
     389,   912,   261,   621,   368,    54,   641,   619,   642,   620,
     271,   704,   705,   706,   707,   272,   369,   918,   276,   901,
      58,   381,   382,   367,   526,   527,   780,   781,   922,   543,
     882,   782,   783,   719,   533,   534,   883,    64,    65,   708,
      54,     1,   553,   621,   278,   553,   295,   553,     2,     3,
     325,    73,   298,   884,   736,    58,     4,     5,   285,   286,
     287,     6,   330,   500,     7,   806,     8,     9,   331,   539,
     791,   792,    64,    65,    10,    11,    12,    13,   924,   332,
      70,   793,   794,    14,   791,   792,    73,   340,    15,    16,
      17,   710,   711,   712,   795,   793,   794,   769,   341,   511,
     512,   513,   535,   536,   546,   546,   360,    32,    33,   653,
     654,    34,    35,    36,    37,    38,   372,    39,   373,    40,
      41,   374,   402,   375,   383,   403,   404,   405,   406,   407,
     408,   409,    43,    44,   415,   416,   432,   838,   434,   435,
     839,   437,   841,   436,   438,   439,   443,   445,    49,   451,
     845,   449,   450,   452,   477,   454,   455,   466,    51,   478,
     376,   480,   479,   484,   537,   558,   557,    54,   570,   508,
     578,   579,   585,   586,   593,   869,    55,   598,    56,    57,
     588,   590,    58,   597,   377,    60,   599,   604,    61,    62,
     606,    63,   609,   610,   632,   635,   656,   652,   601,    64,
      65,    66,   603,    67,    68,   657,   615,    70,   650,    71,
     660,   663,    72,    73,   673,   675,   680,   700,   701,     1,
      75,   714,   720,   702,   721,   722,     2,     3,    76,   737,
     893,   738,   894,    77,     4,     5,   744,   739,   745,     6,
     847,   740,     7,   741,     8,     9,   747,   756,   752,   755,
     760,   762,    10,    11,    12,    13,   907,   764,   909,   768,
     770,    14,   786,   801,   779,   665,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,   785,   410,    32,    33,   808,   840,    34,
      35,    36,    37,    38,   843,    39,   565,    40,    41,   844,
     842,   861,   862,   863,   865,   866,   492,    42,   876,   926,
      43,    44,   877,    45,   900,   928,   888,   897,   905,   906,
      46,    47,    48,   908,   903,   919,    49,   925,   904,   917,
     920,   927,   621,   923,    50,   929,    51,   326,    52,   327,
      53,   328,   496,   497,   828,    54,   337,   573,   329,   753,
     595,   504,   507,   802,    55,   805,    56,    57,   275,   761,
      58,   743,    59,    60,   778,   509,    61,    62,   510,    63,
     378,   631,   528,   380,   899,   870,   902,    64,    65,    66,
     547,    67,    68,    69,   774,    70,   235,    71,   236,   583,
      72,    73,   871,   678,   814,    74,   821,   784,    75,   822,
     679,   819,   880,   659,   886,   815,    76,     0,     0,     0,
       0,    77,     0,    78,     0,     0,    79,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,     1,     0,     0,
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
      82,    83,    84,    85,    86,     1,     0,     0,     0,    87,
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
      84,    85,    86,     1,     0,     0,     0,    87,     0,    88,
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
      86,     1,     0,     0,     0,    87,     0,    88,     2,     3,
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
       0,     0,    80,    81,    82,    83,    84,    85,    86,     1,
       0,     0,     0,    87,     0,    88,     2,     3,     0,     0,
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
      80,    81,    82,    83,    84,    85,    86,     1,     0,     0,
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
      82,    83,    84,    85,    86,     1,     0,     0,     0,    87,
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
      84,    85,    86,     1,     0,     0,     0,    87,     0,    88,
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
      86,     1,     0,     0,     0,    87,     0,    88,     2,     3,
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
       0,     0,    80,    81,    82,    83,    84,    85,    86,     1,
       0,     0,     0,    87,     0,    88,     2,     3,     0,     0,
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
      80,    81,    82,    83,    84,    85,    86,     1,     0,     0,
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
      82,    83,    84,    85,    86,     1,     0,     0,     0,    87,
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
       0,     0,    49,     0,     0,     0,     0,   342,     0,     0,
       0,     0,    51,     0,    52,   343,     0,     0,   344,     0,
     345,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,   346,    56,    57,     0,   347,    58,     0,    59,    60,
     348,     0,    61,    62,     1,    63,   349,     0,     0,     0,
       0,     2,     3,    64,    65,    66,     0,    67,    68,     4,
       5,    70,     0,    71,     6,     0,    72,    73,   350,     8,
       9,     0,     0,     0,    75,     0,     0,    10,    11,    12,
      13,     0,    76,     0,     0,     0,    14,    77,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   351,   352,   353,   354,   355,   356,     0,
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
     682,     0,     0,     0,    43,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,   682,     0,    55,     0,
      56,    57,     0,     0,    58,     0,     0,     0,     0,     0,
      61,    62,     0,    63,     0,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,     0,     0,     0,     0,     0,
       0,    71,     0,     0,    72,    73,   683,     0,     0,   684,
     299,   300,    75,   301,   302,   685,   686,   687,     0,     0,
       0,     0,     0,   688,   303,    77,   304,     0,     0,     0,
       0,     0,   689,     0,     0,     0,     0,   305,   690,   691,
       0,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   683,     0,     0,   684,   299,   300,     0,   301,
     302,   685,   686,   687,     0,     0,     0,     0,     0,     0,
     303,     0,   304,     0,     0,     0,     0,     0,   689,     0,
       0,     0,     0,   305,   818,   691,     0,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   299,   300,
       0,   301,   302,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   303,     0,   304,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   305,     0,     0,     0,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        80,    81,    82,    83,    84,    85,    86,     1,     2,   315,
     364,   365,   366,   367,   373,   242,   436,    11,   245,   331,
      33,    15,   360,    35,    28,   372,   373,   255,   255,    24,
     566,   459,    33,   686,    35,   571,   519,   101,    67,    68,
      34,   625,     9,    10,    20,    48,    40,   487,     8,   702,
      33,   410,    46,   670,   671,    48,    20,    51,    53,     9,
      10,    55,    48,   410,    62,    24,    64,    48,    66,    67,
      48,   690,    93,     9,    10,    48,    20,    44,    72,    12,
      74,    75,    76,    48,    15,    80,    19,    20,   101,   138,
     108,    33,    20,    24,    44,   115,   108,    35,   108,   247,
      13,     9,    10,    94,   109,   253,    93,   108,    44,   109,
     101,    87,    79,    48,    81,    41,   111,   140,    48,    94,
     115,    32,   270,    87,   204,   112,   121,   132,   148,    79,
      68,    81,   132,   182,   399,   158,    44,   159,    48,    48,
     115,    94,    68,    79,   121,    81,   169,   153,   115,   133,
      48,    48,   115,   418,    48,   420,    48,    48,    48,    48,
     181,    48,   115,    48,    48,   115,    48,   173,   161,   153,
     156,    79,    48,    81,    48,   142,    48,   515,   516,   115,
     161,   159,   160,   143,   604,   802,   159,   251,   494,   725,
     774,   727,   142,   197,   159,   731,   732,   625,   174,   818,
     159,   429,   630,   431,   171,   172,   142,   115,   567,   692,
     174,   205,   215,   572,   442,   159,   199,   200,   298,   659,
     567,   171,   172,   876,   159,   572,   170,   157,   159,   196,
     213,   159,   230,   251,   142,   171,   172,   170,   251,   251,
     153,   251,   170,   156,   155,   240,   196,   156,    25,   159,
     251,    48,   332,   333,   334,   335,   336,   199,   200,   156,
     196,   159,    20,   171,   172,   159,   160,   159,   159,   159,
     159,   213,   159,   632,   159,   159,   270,   159,    25,    35,
     156,    39,   156,    15,   156,   632,    76,    35,   196,    88,
      47,    25,    69,    48,    52,   831,   765,   766,   126,    48,
     836,   126,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    33,    75,    76,    48,
      68,    48,    48,    48,    48,    83,   680,    48,    85,    86,
       3,    76,   412,     3,   123,    48,     9,   691,    48,     9,
      48,    33,   422,    48,   153,   425,   774,   427,    25,   126,
     688,   663,   381,   382,   106,   107,   114,    94,   147,   156,
     440,    20,   700,   701,   173,   121,   165,   595,   158,   728,
      76,    20,   130,   121,   733,   911,   456,    94,   115,   126,
      15,   728,   851,   115,   101,   379,   733,   145,   857,   383,
     470,   471,   472,   929,   474,   475,   476,   477,   478,   479,
     480,   156,   482,    24,   162,   163,    79,   156,    81,    79,
      20,    81,    24,    98,   159,   160,   108,    90,   176,     9,
      90,   212,    83,   214,   844,    20,   506,   156,   508,   156,
     156,   156,   156,    23,   119,   156,   194,   791,   792,   793,
     794,    53,   115,   156,    39,   115,   156,    26,   156,   201,
      94,   156,    12,   159,   160,   140,    73,    52,   452,    19,
      20,   123,    85,    86,   247,    94,    15,     9,    80,   252,
      34,   115,    94,   158,   554,    94,    20,    21,   230,    39,
      75,    23,    17,    47,   169,   147,   115,   104,    83,    79,
      26,    81,    52,   115,   181,   722,   115,   577,   159,   111,
      26,    91,   163,   115,    26,   585,   193,   124,    72,   121,
     195,   591,    94,   593,   594,    75,   178,   181,   598,   114,
     514,    85,    86,    83,   155,   115,   606,   607,    26,   193,
     161,   178,   159,   115,   181,   130,   212,    79,   214,    81,
      20,   220,   221,   222,   223,    20,   193,   906,    20,    91,
     145,   166,   167,   170,   361,   362,   636,   637,   912,   906,
     247,   641,   642,   557,   368,   369,   253,   162,   163,   248,
     130,     4,   384,   115,   159,   387,    26,   389,    11,    12,
       0,   176,   115,   270,   578,   145,    19,    20,   202,   203,
     204,    24,   165,   673,    27,   675,    29,    30,   165,   194,
     225,   226,   162,   163,    37,    38,    39,    40,   914,    48,
     170,   236,   237,    46,   225,   226,   176,   137,    51,    52,
      53,   134,   135,   136,   249,   236,   237,   621,    31,   357,
     358,   359,   370,   371,   374,   375,   239,    70,    71,   485,
     486,    74,    75,    76,    77,    78,   110,    80,   179,    82,
      83,    42,    48,    43,   116,    48,    25,    25,   121,    89,
      24,   121,    95,    96,   159,   159,    48,   747,    35,    15,
     750,   126,   752,    35,    15,    25,    48,    89,   111,    18,
     760,   159,   159,   115,    33,   159,   159,   197,   121,   217,
     123,   101,   217,    24,    20,    20,   115,   130,    25,   158,
     115,    20,   108,    76,   108,   785,   139,   177,   141,   142,
      76,    76,   145,    76,   147,   148,    25,    35,   151,   152,
     101,   154,    76,    25,    41,    24,    24,   156,    89,   162,
     163,   164,    89,   166,   167,    24,    89,   170,    76,   172,
      24,   165,   175,   176,    48,   158,   258,   238,   245,     4,
     183,   103,   159,   246,   159,    26,    11,    12,   191,   103,
     840,   159,   842,   196,    19,    20,    26,   159,    26,    24,
     764,   159,    27,   159,    29,    30,   108,    25,   108,    48,
     101,   165,    37,    38,    39,    40,   866,   115,   868,     7,
      20,    46,   219,    25,   165,    47,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,   158,    33,    70,    71,   159,   108,    74,
      75,    76,    77,    78,    25,    80,    76,    82,    83,    35,
      84,   174,    20,    20,    26,   158,    35,    92,    24,   919,
      95,    96,   243,    98,   155,   925,   254,    32,    20,    33,
     105,   106,   107,    26,   174,   158,   111,   158,   174,   174,
      76,    26,   115,   243,   119,   159,   121,    91,   123,    91,
     125,    94,   330,   330,   726,   130,   121,   409,    95,   597,
     431,   335,   338,   670,   139,   673,   141,   142,    69,   609,
     145,   586,   147,   148,   633,   340,   151,   152,   341,   154,
     142,   460,   363,   146,   851,   786,   857,   162,   163,   164,
     375,   166,   167,   168,   630,   170,    35,   172,    35,   420,
     175,   176,   787,   515,   688,   180,   700,   650,   183,   701,
     516,   692,   799,   491,   817,   689,   191,    -1,    -1,    -1,
      -1,   196,    -1,   198,    -1,    -1,   201,    -1,    -1,    -1,
     205,   206,   207,   208,   209,   210,   211,     4,    -1,    -1,
      -1,   216,    -1,   218,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    -1,   230,    -1,    24,    -1,    -1,
      27,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    70,    71,    -1,    -1,    74,    75,    76,
      77,    78,    -1,    80,    -1,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    96,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,   121,    -1,   123,    -1,   125,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,    -1,   141,   142,    -1,    -1,   145,    -1,
     147,   148,    -1,    -1,   151,   152,    -1,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   163,   164,    -1,   166,
     167,   168,    -1,   170,    -1,   172,    -1,    -1,   175,   176,
      -1,    -1,    -1,   180,    -1,    -1,   183,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,   205,   206,
     207,   208,   209,   210,   211,     4,    -1,    -1,    -1,   216,
      -1,   218,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    -1,   230,    -1,    24,    -1,    -1,    27,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
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
      -1,   170,    -1,   172,    -1,    -1,   175,   176,    -1,    -1,
      -1,   180,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   206,   207,   208,
     209,   210,   211,     4,    -1,    -1,    -1,   216,    -1,   218,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    -1,    -1,    74,    75,    76,    77,    78,    -1,    80,
      -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
     121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
     141,   142,    -1,    -1,   145,    -1,   147,   148,    -1,    -1,
     151,   152,    -1,   154,    -1,   156,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,    -1,   166,   167,   168,    -1,   170,
      -1,   172,    -1,    -1,   175,   176,    -1,    -1,    -1,   180,
      -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,   210,
     211,     4,    -1,    -1,    -1,   216,    -1,   218,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    -1,    -1,
      -1,    24,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,
      -1,    74,    75,    76,    77,    78,    -1,    80,    -1,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    95,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,   141,   142,
      -1,    -1,   145,    -1,   147,   148,    -1,    -1,   151,   152,
      -1,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,   162,
     163,   164,    -1,   166,   167,   168,    -1,   170,    -1,   172,
      -1,    -1,   175,   176,    -1,    -1,    -1,   180,    -1,    -1,
     183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   206,   207,   208,   209,   210,   211,     4,
      -1,    -1,    -1,   216,    -1,   218,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    24,
      -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,    74,
      75,    76,    77,    78,    -1,    80,    -1,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      95,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,   121,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,    -1,   141,   142,    -1,    -1,
     145,    -1,   147,   148,    -1,    -1,   151,   152,    -1,   154,
      -1,    -1,    -1,    -1,   159,    -1,    -1,   162,   163,   164,
      -1,   166,   167,   168,    -1,   170,    -1,   172,    -1,    -1,
     175,   176,    -1,    -1,    -1,   180,    -1,    -1,   183,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   206,   207,   208,   209,   210,   211,     4,    -1,    -1,
      -1,   216,    -1,   218,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    -1,    -1,    -1,    24,    -1,    -1,
      27,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    -1,    -1,    74,    75,    76,
      77,    78,    -1,    80,    -1,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    96,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,   121,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,    -1,   141,   142,    -1,    -1,   145,    -1,
     147,   148,    -1,    -1,   151,   152,    -1,   154,    -1,   156,
      -1,    -1,    -1,    -1,    -1,   162,   163,   164,    -1,   166,
     167,   168,    -1,   170,    -1,   172,    -1,    -1,   175,   176,
      -1,    -1,    -1,   180,    -1,    -1,   183,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   206,
     207,   208,   209,   210,   211,     4,    -1,    -1,    -1,   216,
      -1,   218,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
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
      -1,   170,    -1,   172,    -1,    -1,   175,   176,    -1,    -1,
      -1,   180,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   206,   207,   208,
     209,   210,   211,     4,    -1,    -1,    -1,   216,    -1,   218,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    -1,    -1,    74,    75,    76,    77,    78,    -1,    80,
      -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
     121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
     141,   142,    -1,    -1,   145,    -1,   147,   148,    -1,    -1,
     151,   152,    -1,   154,    -1,   156,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,    -1,   166,   167,   168,    -1,   170,
      -1,   172,    -1,    -1,   175,   176,    -1,    -1,    -1,   180,
      -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,   210,
     211,     4,    -1,    -1,    -1,   216,    -1,   218,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    -1,    -1,
      -1,    24,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,
      -1,    74,    75,    76,    77,    78,    -1,    80,    -1,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    95,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,   141,   142,
      -1,    -1,   145,    -1,   147,   148,    -1,    -1,   151,   152,
      -1,   154,    -1,   156,    -1,    -1,    -1,    -1,    -1,   162,
     163,   164,    -1,   166,   167,   168,    -1,   170,    -1,   172,
      -1,    -1,   175,   176,    -1,    -1,    -1,   180,    -1,    -1,
     183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   206,   207,   208,   209,   210,   211,     4,
      -1,    -1,    -1,   216,    -1,   218,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    24,
      -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,    74,
      75,    76,    77,    78,    -1,    80,    -1,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      95,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,   121,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,    -1,   141,   142,    -1,    -1,
     145,    -1,   147,   148,    -1,    -1,   151,   152,    -1,   154,
      -1,   156,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,
      -1,   166,   167,   168,    -1,   170,    -1,   172,    -1,    -1,
     175,   176,    -1,    -1,    -1,   180,    -1,    -1,   183,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   206,   207,   208,   209,   210,   211,     4,    -1,    -1,
      -1,   216,    -1,   218,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    -1,    -1,    -1,    24,    -1,    -1,
      27,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    -1,    -1,    74,    75,    76,
      77,    78,    -1,    80,    -1,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    96,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,   121,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,    -1,   141,   142,    -1,    -1,   145,    -1,
     147,   148,    -1,    -1,   151,   152,    -1,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   163,   164,    -1,   166,
     167,   168,    -1,   170,    -1,   172,    -1,    -1,   175,   176,
      -1,    -1,    -1,   180,    -1,    -1,   183,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   206,
     207,   208,   209,   210,   211,     4,    -1,    -1,    -1,   216,
      -1,   218,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    -1,   121,    -1,   123,    97,    -1,    -1,   100,    -1,
     102,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   113,   141,   142,    -1,   117,   145,    -1,   147,   148,
     122,    -1,   151,   152,     4,   154,   128,    -1,    -1,    -1,
      -1,    11,    12,   162,   163,   164,    -1,   166,   167,    19,
      20,   170,    -1,   172,    24,    -1,   175,   176,   150,    29,
      30,    -1,    -1,    -1,   183,    -1,    -1,    37,    38,    39,
      40,    -1,   191,    -1,    -1,    -1,    46,   196,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,   186,   187,   188,   189,   190,    -1,
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
     138,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   139,    -1,
     141,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,
     151,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,    -1,    -1,   175,   176,   224,    -1,    -1,   227,
     228,   229,   183,   231,   232,   233,   234,   235,    -1,    -1,
      -1,    -1,    -1,   241,   242,   196,   244,    -1,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   224,    -1,    -1,   227,   228,   229,    -1,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,    -1,    -1,
     242,    -1,   244,    -1,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    -1,    -1,   255,   256,   257,    -1,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   228,   229,
      -1,   231,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   242,    -1,   244,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269
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
     170,   172,   175,   176,   180,   183,   191,   196,   198,   201,
     205,   206,   207,   208,   209,   210,   211,   216,   218,   230,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   308,   309,   310,   311,   315,   316,   317,
     318,   319,   320,   321,   326,   337,   340,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     392,   393,   394,   407,   408,   410,   411,   412,   413,   414,
     415,   416,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   435,   436,   437,   438,   439,   440,   441,   444,
     156,   316,   156,   316,   121,   115,   316,    20,   159,   170,
      20,   376,   316,   159,    25,   153,   173,   153,   173,   133,
     153,    25,   126,   126,    85,    86,    20,    15,    20,   138,
     182,    20,    26,   316,   159,   431,   432,    26,   316,    20,
     159,   170,    26,   338,   339,    26,   322,   323,   316,    25,
     126,    25,    69,   126,   307,    26,   327,   328,   159,   316,
      15,   159,   316,    17,    15,    24,   159,    20,    21,    15,
     115,    20,    20,   368,   368,   338,    20,   316,   159,   316,
     316,   316,    28,   197,    24,   202,   203,   204,   317,   317,
     317,   317,   317,   317,   317,    26,   442,   443,   115,   228,
     229,   231,   232,   242,   244,   255,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   458,   459,   460,
     461,   462,   465,   470,   471,     0,   285,   286,   288,   315,
     165,   165,    48,   140,   158,   169,   195,   320,   329,   330,
     137,    31,    89,    97,   100,   102,   113,   117,   122,   128,
     150,   185,   186,   187,   188,   189,   190,   360,   361,   362,
     239,   123,   147,   178,    73,   104,   124,   170,   181,   193,
      93,   112,   110,   179,    42,    43,   123,   147,   359,   115,
     366,   166,   167,   116,   380,   381,   376,   380,   376,   380,
     156,   156,   159,   317,   391,   316,   156,    48,   159,    48,
     159,   156,    48,    48,    25,    25,   121,    89,    24,   121,
      33,    94,   101,   418,   156,   159,   159,   156,    48,   159,
      48,   159,   108,   418,    48,   161,    35,   108,   251,   324,
     325,   418,    48,   159,    35,    15,    35,   126,    15,    25,
     101,   325,   418,    48,   159,    89,   156,     8,   143,   159,
     159,    18,   115,   316,   159,   159,   161,    20,    87,   174,
     396,   397,   156,   159,   156,   156,   197,    88,   165,    33,
     199,   200,   213,    33,   199,   200,   213,    33,   217,   217,
     101,    48,   215,   317,    24,    93,   181,   466,   469,    35,
     121,   467,    35,    68,   121,   464,   290,   291,   292,   317,
     317,   331,   332,   317,   331,   317,   158,   330,   158,   345,
     346,   347,   347,   347,   115,   121,   240,   383,   447,   449,
     450,   451,   452,   453,   454,   455,   350,   350,   349,   351,
     351,   351,   351,   352,   352,   353,   353,    20,   114,   194,
     419,   421,   422,   423,   419,   417,   422,   417,   156,   316,
     368,   368,   316,   381,    48,   159,   156,   115,    20,   433,
     433,   109,   132,   109,   132,    76,   159,   160,   312,   313,
      25,   159,   160,   312,   419,   317,    94,   101,   115,    20,
     433,   434,   433,   434,   317,   108,    76,   317,    76,   317,
      76,   108,   325,   108,   108,   324,   325,    76,   177,    25,
     306,    89,   306,    89,    35,   317,   101,   101,   325,    76,
      25,   156,   316,   156,   317,    89,     9,    10,    44,    79,
      81,   115,   171,   314,   393,   395,   405,   406,   409,    87,
     174,   397,    41,   341,   342,    24,   212,   214,   317,   317,
     317,   212,   214,   317,   317,   317,   317,   317,   317,   317,
      76,   317,   156,   467,   467,   469,    24,    24,   468,   466,
      24,    68,   464,   165,    34,    47,    72,    85,    86,   333,
     334,   335,   336,    48,   317,   158,   317,   316,   447,   453,
     258,   481,   138,   224,   227,   233,   234,   235,   241,   250,
     256,   257,   448,   456,   457,   458,   472,   475,   476,   478,
     238,   245,   246,   477,   220,   221,   222,   223,   248,   473,
     134,   135,   136,   420,   103,   156,   157,   317,   156,   316,
     159,   159,    26,    94,   314,   419,    48,   159,   160,    94,
     314,   419,   159,   160,   317,   156,   316,   103,   159,   159,
     159,   159,   317,   339,    26,    26,   317,   108,   317,   317,
     108,   325,   108,   323,   317,    48,    25,   306,   317,   317,
     101,   328,   165,   156,   115,    32,   155,   398,     7,   316,
      20,   171,   405,   171,   395,    76,   419,    68,   342,   165,
     317,   317,   317,   317,   443,   158,   219,   445,   446,    24,
     159,   225,   226,   236,   237,   249,   474,    48,   159,    48,
     159,    25,   335,   336,   336,   332,   317,   156,   159,   351,
     247,   252,   480,   474,   450,   480,   348,   351,   256,   456,
     458,   451,   452,   474,   156,   418,    94,   314,   313,    94,
     314,   419,    94,   314,    94,   314,   419,   156,   317,   317,
     108,   317,    84,    25,    35,   317,   156,   316,     3,    90,
     401,   402,   404,   406,    23,    91,   399,   400,   403,   406,
     156,   174,    20,    20,   171,    26,   158,    76,   158,   317,
     377,   446,   351,   351,   351,   351,    24,   243,   463,   464,
     463,   336,   247,   253,   270,   479,   479,   348,   254,    94,
     314,    94,   314,   317,   317,   306,   156,    32,    90,   404,
     155,    91,   403,   174,   174,    20,    33,   317,    26,   317,
      48,   159,   178,   474,    48,   159,   159,   174,   419,   158,
      76,   314,   351,   243,   464,   158,   317,    26,   317,   159,
     314
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
     535,   536
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   282,   283,   283,   283,   283,   284,   284,   285,   285,
     286,   287,   288,   288,   288,   289,   289,   290,   290,   291,
     291,   291,   291,   292,   292,   292,   292,   293,   293,   293,
     293,   293,   293,   293,   293,   294,   294,   295,   296,   296,
     297,   297,   298,   299,   300,   300,   301,   301,   302,   302,
     302,   302,   303,   304,   305,   305,   305,   305,   306,   306,
     307,   307,   308,   308,   308,   308,   309,   309,   309,   309,
     310,   310,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   312,   312,
     313,   313,   314,   315,   316,   316,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   318,   318,   318,
     318,   319,   319,   320,   320,   321,   322,   322,   323,   323,
     323,   323,   323,   323,   323,   323,   324,   325,   326,   327,
     327,   328,   328,   328,   328,   329,   330,   330,   331,   331,
     332,   332,   333,   333,   333,   333,   333,   333,   333,   334,
     334,   335,   335,   336,   337,   337,   338,   338,   339,   339,
     340,   340,   341,   341,   342,   342,   343,   344,   344,   345,
     345,   346,   346,   346,   346,   347,   347,   347,   348,   348,
     349,   349,   349,   350,   350,   350,   350,   350,   351,   351,
     351,   352,   352,   352,   353,   353,   354,   354,   355,   355,
     356,   356,   357,   357,   358,   358,   358,   358,   359,   359,
     359,   360,   360,   360,   360,   360,   360,   361,   361,   361,
     361,   361,   361,   362,   362,   362,   363,   363,   364,   364,
     365,   365,   366,   366,   367,   367,   367,   367,   368,   368,
     368,   369,   369,   370,   370,   370,   370,   371,   371,   372,
     372,   372,   372,   372,   372,   372,   373,   373,   374,   374,
     375,   375,   375,   375,   375,   376,   376,   377,   377,   378,
     378,   378,   379,   379,   380,   380,   381,   382,   382,   382,
     382,   382,   382,   382,   382,   383,   383,   384,   384,   384,
     385,   386,   386,   387,   388,   389,   390,   390,   391,   391,
     392,   392,   393,   393,   393,   394,   394,   394,   394,   394,
     394,   395,   395,   396,   396,   397,   398,   398,   399,   399,
     400,   400,   400,   400,   401,   401,   402,   402,   402,   402,
     403,   403,   404,   404,   405,   405,   405,   405,   406,   406,
     406,   406,   407,   407,   408,   408,   409,   410,   410,   410,
     410,   410,   410,   411,   412,   412,   412,   412,   413,   413,
     413,   413,   414,   415,   416,   416,   416,   416,   417,   417,
     418,   419,   419,   419,   420,   420,   420,   421,   421,   421,
     422,   423,   423,   423,   423,   423,   423,   423,   423,   423,
     424,   425,   425,   425,   426,   427,   428,   428,   428,   429,
     429,   429,   429,   429,   430,   431,   431,   431,   431,   431,
     431,   431,   432,   433,   434,   435,   436,   436,   436,   437,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   438,
     438,   439,   439,   440,   441,   442,   442,   443,   444,   445,
     445,   446,   446,   447,   447,   447,   447,   448,   448,   448,
     448,   449,   449,   450,   450,   451,   451,   452,   452,   453,
     453,   453,   454,   454,   455,   455,   456,   456,   456,   456,
     456,   457,   458,   458,   458,   458,   458,   458,   458,   459,
     459,   459,   459,   460,   460,   460,   460,   461,   461,   462,
     462,   462,   462,   462,   462,   462,   463,   463,   464,   464,
     464,   464,   465,   465,   465,   465,   465,   466,   466,   467,
     467,   468,   468,   469,   469,   470,   471,   471,   472,   472,
     472,   473,   473,   473,   473,   473,   474,   474,   474,   474,
     475,   476,   477,   478,   478,   479,   479,   479,   480,   480,
     481
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
       283,     0,    -1,   285,    -1,   284,   285,    -1,   286,    -1,
     284,   286,    -1,   198,    24,   165,    -1,   198,    24,    88,
      24,   165,    -1,   288,   315,    -1,   315,    -1,   287,   288,
      -1,   125,    15,    89,    25,   165,    -1,   289,   165,    -1,
     290,   165,    -1,   289,   165,   290,   165,    -1,   291,    -1,
     289,   165,   291,    -1,   292,    -1,   290,   165,   292,    -1,
     293,    -1,   294,    -1,   295,    -1,   297,    -1,   309,    -1,
     311,    -1,   298,    -1,   299,    -1,   296,    -1,   303,    -1,
     304,    -1,   310,    -1,   300,    -1,   301,    -1,   302,    -1,
     436,    -1,   305,    -1,   308,    -1,    63,    15,    89,    25,
      -1,    55,   153,    -1,    55,   173,    -1,    59,   126,    25,
      -1,    60,   126,    25,    -1,    64,    20,    24,    -1,   230,
     458,    -1,    65,   138,    -1,    65,   182,    -1,    61,    85,
      -1,    61,    86,    -1,    57,   153,    48,   109,    -1,    57,
     153,    48,   132,    -1,    57,   133,    48,   109,    -1,    57,
     133,    48,   132,    -1,    58,    25,    -1,    54,    25,    -1,
     107,    25,    -1,   107,   307,    25,    -1,   107,    25,    35,
     306,    -1,   107,   307,    25,    35,   306,    -1,    25,    -1,
     306,    48,    25,    -1,   126,    15,    89,    -1,    69,   126,
      -1,   106,    25,    -1,   106,   126,    15,    89,    25,    -1,
     106,    25,    35,   306,    -1,   106,   126,    15,    89,    25,
      35,   306,    -1,    67,    26,   101,   317,    -1,    67,    26,
      94,    -1,    67,    26,   418,   101,   317,    -1,    67,    26,
     418,    94,    -1,    56,   153,    -1,    56,   173,    -1,    62,
      20,   121,   159,    94,    -1,    62,    20,   121,   159,   314,
      -1,    62,    20,   121,   312,   159,    94,    -1,    62,    20,
     121,   312,   159,   314,    -1,    62,    20,   121,   160,   419,
      94,    -1,    62,    20,   121,   160,   419,   314,    -1,    62,
      20,   121,   312,   160,   419,    94,    -1,    62,    20,   121,
     312,   160,   419,   314,    -1,    66,    20,   121,   159,    94,
      -1,    66,    20,   121,   159,   314,    -1,    66,    20,   121,
     312,   159,    94,    -1,    66,    20,   121,   312,   159,   314,
      -1,    66,    20,   121,   160,   419,    94,    -1,    66,    20,
     121,   160,   419,   314,    -1,    66,    20,   121,   312,   160,
     419,    94,    -1,    66,    20,   121,   312,   160,   419,   314,
      -1,   313,    -1,   312,    48,   313,    -1,    76,    26,    -1,
      76,    26,   418,    -1,   115,   316,   156,    -1,   316,    -1,
     317,    -1,   316,    48,   317,    -1,   318,    -1,   337,    -1,
     340,    -1,   343,    -1,   344,    -1,   437,    -1,   438,    -1,
     440,    -1,   439,    -1,   441,    -1,   444,    -1,   319,   158,
     317,    -1,   319,   329,   158,   317,    -1,   319,   330,   158,
     317,    -1,   319,   329,   330,   158,   317,    -1,   320,    -1,
     319,   320,    -1,   321,    -1,   326,    -1,    98,   322,    -1,
     323,    -1,   322,    48,    76,   323,    -1,    26,   108,   317,
      -1,    26,   418,   108,   317,    -1,    26,   324,   108,   317,
      -1,    26,   418,   324,   108,   317,    -1,    26,   325,   108,
     317,    -1,    26,   418,   325,   108,   317,    -1,    26,   324,
     325,   108,   317,    -1,    26,   418,   324,   325,   108,   317,
      -1,    35,    76,    26,    -1,   251,    76,    26,    -1,   119,
     327,    -1,   328,    -1,   327,    48,    76,   328,    -1,    26,
     101,   317,    -1,    26,   418,   101,   317,    -1,    26,   325,
     101,   317,    -1,    26,   418,   325,   101,   317,    -1,   195,
     317,    -1,   140,   331,    -1,   169,   331,    -1,   332,    -1,
     331,    48,   332,    -1,   317,    -1,   317,   333,    -1,   334,
      -1,   335,    -1,   336,    -1,   334,   335,    -1,   334,   336,
      -1,   335,   336,    -1,   334,   335,   336,    -1,    34,    -1,
      72,    -1,    85,    -1,    86,    -1,    47,    25,    -1,   168,
     338,   161,   317,    -1,    92,   338,   161,   317,    -1,   339,
      -1,   338,    48,    76,   339,    -1,    26,   108,   317,    -1,
      26,   418,   108,   317,    -1,   180,   316,   159,   341,    68,
     158,   317,    -1,   180,   316,   159,   341,    68,    76,    26,
     158,   317,    -1,   342,    -1,   341,   342,    -1,    41,   419,
     158,   317,    -1,    41,    76,    26,    33,   419,   158,   317,
      -1,   105,   316,   159,   177,   317,    84,   317,    -1,   345,
      -1,   344,   137,   345,    -1,   346,    -1,   345,    31,   346,
      -1,   347,    -1,   347,   361,   347,    -1,   347,   360,   347,
      -1,   347,   362,   347,    -1,   348,    -1,   348,   239,   447,
      -1,   348,   239,   447,   481,    -1,   349,    -1,   349,   178,
     349,    -1,   350,    -1,   349,   147,   350,    -1,   349,   123,
     350,    -1,   351,    -1,   350,   170,   351,    -1,   350,    73,
     351,    -1,   350,   104,   351,    -1,   350,   124,   351,    -1,
     352,    -1,   351,   181,   352,    -1,   351,   193,   352,    -1,
     353,    -1,   352,   112,   353,    -1,   352,    93,   353,    -1,
     354,    -1,   354,   110,   419,    -1,   355,    -1,   355,   179,
     419,    -1,   356,    -1,   356,    42,   417,    -1,   357,    -1,
     357,    43,   417,    -1,   359,    -1,   358,   359,    -1,   147,
      -1,   123,    -1,   358,   147,    -1,   358,   123,    -1,   363,
      -1,   367,    -1,   364,    -1,    89,    -1,   128,    -1,   122,
      -1,   117,    -1,   102,    -1,   100,    -1,   185,    -1,   190,
      -1,   189,    -1,   188,    -1,   187,    -1,   186,    -1,   113,
      -1,   150,    -1,    97,    -1,   191,   316,   156,    -1,    27,
     115,   316,   156,    -1,   365,   115,   156,    -1,   365,   115,
     316,   156,    -1,   366,    -1,   365,   366,    -1,   148,    20,
      18,    -1,   148,    21,    -1,   166,    -1,   166,   368,    -1,
     167,   368,    -1,   368,    -1,   369,    -1,   369,   166,   368,
      -1,   369,   167,   368,    -1,   370,    -1,   379,    -1,   371,
      -1,   371,   380,    -1,   374,    -1,   374,   380,    -1,   372,
     376,    -1,   373,    -1,    46,    -1,    70,    -1,    37,    -1,
     164,    -1,    71,    -1,    96,    -1,    95,    -1,   376,    -1,
      40,   376,    -1,   375,   376,    -1,    78,    -1,   141,    -1,
      29,    -1,   152,    -1,   151,    -1,    30,    -1,   423,    -1,
     377,    -1,    20,    -1,   378,    -1,   170,    -1,    12,    -1,
      19,    -1,   382,    -1,   382,   380,    -1,   381,    -1,   380,
     381,    -1,   116,   316,   157,    -1,   383,    -1,   385,    -1,
     386,    -1,   387,    -1,   390,    -1,   392,    -1,   388,    -1,
     389,    -1,   384,    -1,   435,    -1,    53,    -1,   111,    -1,
      80,    -1,    76,    26,    -1,   121,   159,    -1,   121,   316,
     159,    -1,    77,    -1,   139,   316,   156,    -1,   183,   316,
     156,    -1,    20,   121,   159,    -1,    20,   121,   391,   159,
      -1,   317,    -1,   391,    48,   317,    -1,   393,    -1,   410,
      -1,   394,    -1,   407,    -1,   408,    -1,   172,    20,    87,
      -1,   172,    20,   396,    87,    -1,   172,    20,   174,   171,
      20,   174,    -1,   172,    20,   174,   395,   171,    20,   174,
      -1,   172,    20,   396,   174,   171,    20,   174,    -1,   172,
      20,   396,   174,   395,   171,    20,   174,    -1,   405,    -1,
     395,   405,    -1,   397,    -1,   396,   397,    -1,    20,    89,
     398,    -1,   155,   399,   155,    -1,    32,   401,    32,    -1,
      -1,   400,    -1,    91,    -1,   403,    -1,   400,    91,    -1,
     400,   403,    -1,    -1,   402,    -1,    90,    -1,   404,    -1,
     402,    90,    -1,   402,   404,    -1,    23,    -1,   406,    -1,
       3,    -1,   406,    -1,   393,    -1,    10,    -1,   409,    -1,
     406,    -1,     9,    -1,    79,    -1,    81,    -1,   314,    -1,
     196,    28,   197,    -1,   196,   197,    -1,   142,    17,   143,
      -1,   142,    17,     8,    -1,    44,     7,    -1,   411,    -1,
     412,    -1,   413,    -1,   414,    -1,   415,    -1,   416,    -1,
      74,   316,   156,    -1,    11,   156,    -1,    11,   316,   156,
      -1,    82,   316,   156,   115,   156,    -1,    82,   316,   156,
     115,   316,   156,    -1,     4,   156,    -1,     4,   316,   156,
      -1,    38,   316,   156,   115,   156,    -1,    38,   316,   156,
     115,   316,   156,    -1,   175,   316,   156,    -1,    51,   316,
     156,    -1,   154,    15,   115,   156,    -1,   154,    15,   115,
     316,   156,    -1,   154,   115,   316,   156,   115,   156,    -1,
     154,   115,   316,   156,   115,   316,   156,    -1,   422,    -1,
     422,   103,    -1,    33,   419,    -1,   421,    -1,   421,   420,
      -1,   194,    -1,   134,    -1,   136,    -1,   135,    -1,   422,
      -1,   423,    -1,   114,    -1,    20,    -1,   425,    -1,   431,
      -1,   429,    -1,   432,    -1,   430,    -1,   428,    -1,   427,
      -1,   426,    -1,   424,    -1,   130,   159,    -1,    75,   159,
      -1,    75,   431,   159,    -1,    75,   432,   159,    -1,   176,
     159,    -1,    52,   159,    -1,   145,   159,    -1,   145,    15,
     159,    -1,   145,    24,   159,    -1,    39,   159,    -1,    39,
      20,   159,    -1,    39,    20,    48,   433,   159,    -1,    39,
     170,   159,    -1,    39,   170,    48,   433,   159,    -1,   162,
      20,   159,    -1,    83,   159,    -1,    83,    20,   159,    -1,
      83,    20,    48,   433,   159,    -1,    83,    20,    48,   434,
     159,    -1,    83,   170,   159,    -1,    83,   170,    48,   433,
     159,    -1,    83,   170,    48,   434,   159,    -1,   163,    20,
     159,    -1,    20,    -1,    20,   103,    -1,    24,    -1,   201,
     202,    -1,   201,   203,    -1,   201,   204,    -1,   207,   317,
     213,   317,    -1,   207,   317,    33,   212,   317,    -1,   207,
     317,    33,   214,   317,    -1,   207,   317,   199,   317,    -1,
     207,   317,   200,   317,    -1,   208,   317,   213,   317,    -1,
     208,   317,    33,   212,   317,    -1,   208,   317,    33,   214,
     317,    -1,   208,   317,   199,   317,    -1,   208,   317,   200,
     317,    -1,   205,   317,    -1,   206,   317,    -1,   210,   317,
     217,   317,    -1,   211,   317,   217,   317,    -1,   209,   317,
      33,   317,    -1,   216,   442,   215,   317,   158,   317,    -1,
     443,    -1,   442,    48,    76,   443,    -1,    26,   101,   317,
      -1,   218,   115,   317,   156,   445,    -1,   446,    -1,   445,
     446,    -1,   219,   377,   159,   314,    -1,   219,   377,    48,
      76,    26,   159,   314,    -1,   449,    -1,   449,   448,    -1,
     449,   256,   348,    -1,   449,   448,   256,   348,    -1,   458,
      -1,   456,    -1,   448,   458,    -1,   448,   456,    -1,   450,
      -1,   449,   241,   450,    -1,   451,    -1,   450,   238,   451,
      -1,   452,    -1,   451,   245,   452,    -1,   453,    -1,   240,
     453,    -1,   454,    -1,   454,   477,    -1,   121,   447,   159,
      -1,   455,    -1,   455,   473,    -1,   383,    -1,   115,   316,
     156,    -1,   457,    -1,   476,    -1,   475,    -1,   478,    -1,
     472,    -1,   138,    -1,   459,    -1,   460,    -1,   461,    -1,
     462,    -1,   465,    -1,   470,    -1,   471,    -1,   244,    -1,
     255,    -1,   229,    -1,   228,    -1,   265,    -1,   259,    -1,
     232,    -1,   231,    -1,   266,    -1,   260,    -1,   268,   464,
      -1,   268,    68,    -1,   268,   121,   464,   159,    -1,   268,
     121,   464,    48,   463,   159,    -1,   268,   121,    68,   159,
      -1,   268,   121,    68,    48,   463,   159,    -1,   262,    -1,
     464,    -1,   463,    48,   464,    -1,    35,    24,    -1,    35,
      24,   249,    24,    -1,    35,    24,   474,   243,    -1,    35,
      24,   249,    24,   474,   243,    -1,   267,   467,    -1,   267,
     467,   466,    -1,   264,    -1,   264,   466,    -1,   261,    -1,
     469,    -1,   466,   469,    -1,    35,    24,    -1,   121,   468,
     159,    -1,    24,    -1,   468,    24,    -1,   181,   467,    -1,
      93,   467,    -1,   242,    24,    -1,   269,    -1,   263,    -1,
     227,    -1,   224,    -1,   235,    -1,   222,    -1,   223,    -1,
     220,    -1,   221,    -1,   248,    -1,   236,   351,    -1,   225,
     351,    -1,   226,   351,    -1,   237,   351,   178,   351,    -1,
     234,   474,   479,    -1,   257,   351,   479,    -1,   246,   474,
     254,    -1,   250,   480,    -1,   233,   480,    -1,   270,    -1,
     253,    -1,   247,    -1,   252,    -1,   247,    -1,   258,   351,
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
         0,   731,   731,   739,   747,   753,   765,   771,   783,   793,
     808,   823,   838,   847,   856,   871,   880,   897,   906,   923,
     930,   937,   944,   956,   963,   970,   979,   992,   999,  1006,
    1013,  1020,  1027,  1034,  1043,  1056,  1063,  1081,  1096,  1104,
    1118,  1127,  1142,  1158,  1172,  1180,  1195,  1203,  1217,  1226,
    1235,  1244,  1266,  1280,  1294,  1304,  1314,  1324,  1340,  1349,
    1367,  1374,  1387,  1396,  1406,  1415,  1432,  1442,  1452,  1462,
    1478,  1486,  1500,  1510,  1521,  1532,  1544,  1556,  1568,  1580,
    1592,  1602,  1613,  1624,  1636,  1648,  1660,  1672,  1690,  1701,
    1718,  1727,  1742,  1756,  1770,  1779,  1794,  1801,  1808,  1815,
    1822,  1831,  1838,  1845,  1852,  1859,  1866,  1878,  1888,  1899,
    1910,  1927,  1936,  1951,  1958,  1971,  1985,  1994,  2011,  2021,
    2032,  2044,  2057,  2068,  2080,  2092,  2110,  2125,  2139,  2154,
    2163,  2180,  2191,  2203,  2214,  2232,  2246,  2254,  2269,  2278,
    2295,  2304,  2319,  2329,  2339,  2349,  2359,  2369,  2379,  2395,
    2402,  2415,  2423,  2437,  2451,  2461,  2477,  2487,  2502,  2511,
    2527,  2537,  2554,  2563,  2578,  2587,  2603,  2617,  2624,  2638,
    2645,  2667,  2674,  2685,  2696,  2713,  2720,  2730,  2746,  2753,
    2767,  2774,  2781,  2794,  2800,  2807,  2814,  2821,  2834,  2841,
    2849,  2863,  2870,  2877,  2890,  2897,  2912,  2919,  2934,  2941,
    2956,  2963,  2978,  2985,  3000,  3007,  3014,  3021,  3036,  3043,
    3050,  3064,  3071,  3078,  3085,  3092,  3099,  3112,  3119,  3126,
    3133,  3140,  3147,  3160,  3167,  3174,  3188,  3195,  3210,  3219,
    3234,  3243,  3260,  3269,  3311,  3318,  3325,  3332,  3346,  3354,
    3361,  3374,  3381,  3394,  3403,  3412,  3421,  3436,  3445,  3459,
    3466,  3473,  3480,  3487,  3494,  3501,  3514,  3521,  3534,  3543,
    3558,  3565,  3572,  3579,  3586,  3604,  3611,  3624,  3631,  3644,
    3654,  3664,  3680,  3687,  3702,  3711,  3728,  3742,  3749,  3756,
    3763,  3770,  3777,  3784,  3791,  3804,  3811,  3824,  3832,  3840,
    3854,  3867,  3874,  3888,  3901,  3915,  3974,  3983,  3998,  4007,
    4022,  4029,  4042,  4049,  4056,  4069,  4080,  4091,  4102,  4113,
    4124,  4142,  4151,  4166,  4175,  4192,  4207,  4215,  4230,  4236,
    4243,  4252,  4261,  4272,  4289,  4295,  4302,  4311,  4320,  4331,
    4348,  4356,  4370,  4378,  4392,  4400,  4408,  4417,  4432,  4441,
    4449,  4457,  4471,  4479,  4497,  4505,  4525,  4543,  4550,  4557,
    4564,  4571,  4578,  4591,  4605,  4614,  4623,  4631,  4659,  4668,
    4677,  4685,  4699,  4713,  4727,  4736,  4745,  4753,  4767,  4776,
    4791,  4805,  4814,  4823,  4863,  4871,  4879,  4893,  4900,  4907,
    4920,  4934,  4941,  4948,  4955,  4962,  4969,  4976,  4983,  4990,
    5003,  5016,  5023,  5031,  5045,  5058,  5071,  5078,  5085,  5098,
    5107,  5116,  5125,  5134,  5149,  5163,  5172,  5181,  5190,  5199,
    5209,  5219,  5235,  5259,  5269,  5292,  5334,  5342,  5348,  5359,
    5368,  5377,  5386,  5395,  5405,  5414,  5423,  5432,  5441,  5456,
    5466,  5481,  5490,  5505,  5534,  5546,  5552,  5564,  5580,  5590,
    5600,  5614,  5624,  5651,  5657,  5663,  5669,  5681,  5687,  5693,
    5699,  5711,  5717,  5729,  5735,  5747,  5753,  5765,  5771,  5783,
    5789,  5795,  5807,  5813,  5825,  5831,  5843,  5849,  5855,  5861,
    5867,  5879,  5891,  5898,  5905,  5912,  5919,  5926,  5933,  5946,
    5952,  5958,  5964,  5976,  5982,  5988,  5994,  6006,  6012,  6024,
    6030,  6036,  6042,  6048,  6054,  6060,  6072,  6078,  6090,  6096,
    6102,  6108,  6120,  6126,  6132,  6138,  6144,  6156,  6162,  6174,
    6180,  6192,  6198,  6210,  6216,  6228,  6240,  6246,  6258,  6264,
    6270,  6282,  6288,  6294,  6300,  6306,  6318,  6324,  6330,  6336,
    6348,  6360,  6372,  6384,  6390,  6402,  6408,  6414,  6426,  6432,
    6444
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
     275,   276,   277,   278,   279,   280,   281
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 3849;
  const int xquery_parser::yynnts_ = 200;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 325;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 282;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 536;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 6454 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"



/*
	The error member function registers the errors to the driver.
*/

void zorba::xquery_parser::error(
	zorba::xquery_parser::location_type const& loc,
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





