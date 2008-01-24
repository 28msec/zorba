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
#line 131 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"


/* Line 317 of lalr1.cc.  */
#line 46 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"

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
    #line 90 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = driver.filename.getStore();
}
  /* Line 547 of yacc.c.  */
#line 283 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
#line 733 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [main]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr((yyval.node));
		;}
    break;

  case 3:
#line 741 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr((yyval.node));
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.main]\n";
#endif
		;}
    break;

  case 4:
#line 749 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [library]\n";
#endif
		;}
    break;

  case 5:
#line 755 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.library]\n";
#endif
		;}
    break;

  case 6:
#line 767 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version]\n";
#endif
		;}
    break;

  case 7:
#line 773 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version.encoding]\n";
#endif
		;}
    break;

  case 8:
#line 785 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 795 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 810 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 825 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 840 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 849 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 858 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 882 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 899 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 925 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [setter]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 932 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [import]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 939 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [namespace]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 946 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [default namespace]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 958 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [var]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 965 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [function]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 972 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [option]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 981 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [ftoption]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 994 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [boundary space]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 1001 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [default collation]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 1008 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [base uri]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 1015 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [construction]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 1022 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [ordering mode]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 1029 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [empty order]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 1036 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [copy namespaces]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 1045 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [revalidation]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 1058 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [schema]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 1065 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [module]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 1083 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1098 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [preserve]\n";
#endif
			(yyval.node) = new BoundarySpaceDecl((yyloc),
								StaticQueryContext::preserve_space);
		;}
    break;

  case 39:
#line 1106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [strip]\n";
#endif
			(yyval.node) = new BoundarySpaceDecl((yyloc),
								StaticQueryContext::strip_space);
		;}
    break;

  case 40:
#line 1120 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1129 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1144 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1160 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOptionDecl [ ]\n";
#endif
			(yyval.node) = new FTOptionDecl((yyloc),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 44:
#line 1174 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [ordered]\n";
#endif
			(yyval.node) = new OrderingModeDecl((yyloc),
								StaticQueryContext::ordered);
		;}
    break;

  case 45:
#line 1182 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [unordered]\n";
#endif
			(yyval.node) = new OrderingModeDecl((yyloc),
								StaticQueryContext::unordered);
		;}
    break;

  case 46:
#line 1197 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty greatest]\n";
#endif
			(yyval.node) = new EmptyOrderDecl((yyloc),
								StaticQueryContext::empty_greatest);
		;}
    break;

  case 47:
#line 1205 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty least]\n";
#endif
			(yyval.node) = new EmptyOrderDecl((yyloc),
								StaticQueryContext::empty_least);
		;}
    break;

  case 48:
#line 1219 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1237 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1246 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1268 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultCollationMode [ ]\n";
#endif
			(yyval.node) = new DefaultCollationDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 53:
#line 1282 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BaseURIDecl [ ]\n";
#endif
			(yyval.node) = new BaseURIDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 54:
#line 1296 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1306 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1316 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1326 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1342 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1351 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1369 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [namespace]\n";
#endif
			(yyval.node) = new SchemaPrefix((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1376 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [default element]\n";
#endif
			(yyval.node) = new SchemaPrefix((yyloc), true);
		;}
    break;

  case 62:
#line 1389 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1398 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1408 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1417 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1434 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1444 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1454 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1464 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1480 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [preserve]\n";
#endif
			(yyval.node) = new ConstructionDecl((yyloc),
								StaticQueryContext::cons_preserve);
		;}
    break;

  case 71:
#line 1488 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [strip]\n";
#endif
			(yyval.node) = new ConstructionDecl((yyloc),
								StaticQueryContext::cons_strip);
		;}
    break;

  case 72:
#line 1502 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1512 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1523 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1534 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1546 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1558 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1570 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1582 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1594 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1604 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1615 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1638 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1650 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1662 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1674 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1692 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1703 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1720 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1729 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1744 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EnclosedExpr [ ]\n";
#endif
			(yyval.expr) = new EnclosedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1758 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QueryBody [expr]\n";
#endif
			(yyval.expr) = new QueryBody((yyloc),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 94:
#line 1772 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1781 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1796 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [FLWORExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 97:
#line 1803 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [QuantifiedExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1810 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TypeswitchExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1817 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [IfExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1824 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [OrExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1833 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [InsertExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1840 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [DeleteExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1847 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [RenameExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1854 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [ReplaceExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TransformExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1874 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1884 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1906 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1923 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1932 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1947 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [for]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 113:
#line 1954 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [let]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 114:
#line 1967 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForClause [ ]\n";
#endif
			(yyval.node) = new ForClause((yyloc),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 115:
#line 1981 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1990 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2007 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2017 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2028 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2040 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2053 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2064 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2076 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2088 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PositionalVar [ ]\n";
#endif
			(yyval.node) = new PositionalVar((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 126:
#line 2121 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTScoreVar [ ]\n";
#endif
			(yyval.node) = new FTScoreVar((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 127:
#line 2135 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClause [ ]\n";
#endif
			(yyval.node) = new LetClause((yyloc),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)));
			
		;}
    break;

  case 128:
#line 2150 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2159 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2176 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2187 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2199 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2210 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "WhereClause [ ]\n";
#endif
			(yyval.node) = new WhereClause((yyloc),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 135:
#line 2242 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [ ]\n";
#endif
			(yyval.node) = new OrderByClause((yyloc),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 136:
#line 2250 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2265 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2274 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2291 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2315 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2325 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2335 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2345 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2355 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2365 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2375 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2391 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [ascending]\n";
#endif
			(yyval.node) = new OrderDirSpec((yyloc), dir_ascending);
		;}
    break;

  case 149:
#line 2398 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [descending]\n";
#endif
			(yyval.node) = new OrderDirSpec((yyloc), dir_descending);
		;}
    break;

  case 150:
#line 2411 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [greatest]\n";
#endif
			(yyval.node) = new OrderEmptySpec((yyloc),
								StaticQueryContext::empty_greatest);
		;}
    break;

  case 151:
#line 2419 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [least]\n";
#endif
			(yyval.node) = new OrderEmptySpec((yyloc),
								StaticQueryContext::empty_least);
		;}
    break;

  case 152:
#line 2433 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderCollationSpec [ ]\n";
#endif
			(yyval.node) = new OrderCollationSpec((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 153:
#line 2447 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2457 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2473 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2483 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2498 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2507 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2523 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2533 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2550 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2559 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2574 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2583 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2599 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IfExpr [ ]\n";
#endif
			(yyval.expr) = new IfExpr((yyloc),
								(yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 166:
#line 2613 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [and]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 167:
#line 2620 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [or.and]\n";
#endif
			(yyval.expr) = new OrExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 168:
#line 2634 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [comp]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 169:
#line 2641 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [and.comp]\n";
#endif
			(yyval.expr) = new AndExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 170:
#line 2663 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 171:
#line 2670 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2681 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2692 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2709 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 175:
#line 2716 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2726 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 178:
#line 2749 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add.to.add]\n";
#endif
			(yyval.expr) = new RangeExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 179:
#line 2763 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 180:
#line 2770 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult+mult]\n";
#endif
			(yyval.expr) = new AdditiveExpr((yyloc), op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 181:
#line 2777 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult-mult]\n";
#endif
			(yyval.expr) = new AdditiveExpr((yyloc), op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 182:
#line 2790 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [union]\n";
#endif
		;}
    break;

  case 183:
#line 2796 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult*union]\n";
#endif
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 184:
#line 2803 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.div.union]\n";
#endif
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 185:
#line 2810 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.idiv.union]\n";
#endif
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 186:
#line 2817 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.mod.union]\n";
#endif
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 187:
#line 2830 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [interexcept]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 188:
#line 2837 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union.union.interexcept]\n";
#endif
			(yyval.expr) = new UnionExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 189:
#line 2845 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union|interexcept]\n";
#endif
			(yyval.expr) = new UnionExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 190:
#line 2859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [instanceof]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 191:
#line 2866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.inter.instanceof]\n";
#endif
			(yyval.expr) = new IntersectExceptExpr((yyloc), op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 192:
#line 2873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.except.instanceof]\n";
#endif
			(yyval.expr) = new IntersectExceptExpr((yyloc), op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 193:
#line 2886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 194:
#line 2893 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 196:
#line 2915 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2930 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 198:
#line 2937 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2952 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 200:
#line 2959 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2974 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [value]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 202:
#line 2981 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2996 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [+]\n";
#endif
			(yyval.node) = new SignList((yyloc), true);
		;}
    break;

  case 204:
#line 3003 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [-]\n";
#endif
			(yyval.node) = new SignList((yyloc), false);
		;}
    break;

  case 205:
#line 3010 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.+]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 206:
#line 3017 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3032 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [validate]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 208:
#line 3039 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [path]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 209:
#line 3046 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [extension]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 210:
#line 3060 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [=]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_eq);
		;}
    break;

  case 211:
#line 3067 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [!=]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_ne);
		;}
    break;

  case 212:
#line 3074 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_lt);
		;}
    break;

  case 213:
#line 3081 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<=]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_le);
		;}
    break;

  case 214:
#line 3088 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_gt);
		;}
    break;

  case 215:
#line 3095 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>=]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_ge);
		;}
    break;

  case 216:
#line 3108 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [eq]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_eq);
		;}
    break;

  case 217:
#line 3115 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ne]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_ne);
		;}
    break;

  case 218:
#line 3122 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [lt]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_lt);
		;}
    break;

  case 219:
#line 3129 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [le]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_le);
		;}
    break;

  case 220:
#line 3136 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [gt]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_gt);
		;}
    break;

  case 221:
#line 3143 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ge]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_ge);
		;}
    break;

  case 222:
#line 3156 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [is]\n";
#endif
			(yyval.node) = new NodeComp((yyloc), op_is);
		;}
    break;

  case 223:
#line 3163 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [<<]\n";
#endif
			(yyval.node) = new NodeComp((yyloc), op_precedes);
		;}
    break;

  case 224:
#line 3170 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [>>]\n";
#endif
			(yyval.node) = new NodeComp((yyloc), op_follows);
		;}
    break;

  case 225:
#line 3184 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [expr]\n";
#endif
			(yyval.expr) = new ValidateExpr((yyloc), "strict", (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 226:
#line 3191 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3206 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3215 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3230 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3239 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3256 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3302 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/]\n";
#endif
			(yyval.expr) = new PathExpr((yyloc), path_leading_lone_slash, NULL);
		;}
    break;

  case 233:
#line 3309 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/relative]\n";
#endif
			(yyval.expr) = new PathExpr((yyloc), path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 234:
#line 3316 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [//relative]\n";
#endif
			(yyval.expr) = new PathExpr((yyloc), path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 235:
#line 3323 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [relative]\n";
#endif
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = rpe == NULL ? (yysemantic_stack_[(1) - (1)].expr) : new PathExpr((yyloc), path_relative, (yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 236:
#line 3337 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step]\n";
#endif
            AxisStep *as = dynamic_cast<AxisStep *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = as != NULL ? new RelativePathExpr((yyloc), st_slash, new ContextItemExpr((yyloc)), (yysemantic_stack_[(1) - (1)].expr)) : (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 237:
#line 3345 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step/relative]\n";
#endif
			(yyval.expr) = new RelativePathExpr((yyloc), st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 238:
#line 3352 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step//relative]\n";
#endif
			(yyval.expr) = new RelativePathExpr((yyloc), st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 239:
#line 3365 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [axis]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 240:
#line 3372 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [filter]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 241:
#line 3385 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3394 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3403 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3412 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3427 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3436 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [abbrev]\n";
#endif
			(yyval.node) = new ForwardStep((yyloc),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 247:
#line 3450 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [child]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_child);
		;}
    break;

  case 248:
#line 3457 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_descendant);
		;}
    break;

  case 249:
#line 3464 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [attribute]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_attribute);
		;}
    break;

  case 250:
#line 3471 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [self]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_self);
		;}
    break;

  case 251:
#line 3478 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant_or_self]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_descendant_or_self);
		;}
    break;

  case 252:
#line 3485 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following_sibling]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_following_sibling);
		;}
    break;

  case 253:
#line 3492 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_following);
		;}
    break;

  case 254:
#line 3505 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [nodetest]\n";
#endif
			(yyval.node) = new AbbrevForwardStep((yyloc), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 255:
#line 3512 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [@ nodetest]\n";
#endif
			(yyval.node) = new AbbrevForwardStep((yyloc), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 256:
#line 3525 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3534 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3549 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [parent]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_parent);
		;}
    break;

  case 259:
#line 3556 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_ancestor);
		;}
    break;

  case 260:
#line 3563 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding_sibling]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_preceding_sibling);
		;}
    break;

  case 261:
#line 3570 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_preceding);
		;}
    break;

  case 262:
#line 3577 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor_or_self]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_ancestor_or_self);
		;}
    break;

  case 263:
#line 3595 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [kindtest]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 264:
#line 3602 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [nametest]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 265:
#line 3615 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [qname]\n";
#endif
			(yyval.node) = new NameTest((yyloc), new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 266:
#line 3622 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [wildcard]\n";
#endif
			(yyval.node) = new NameTest((yyloc), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 267:
#line 3635 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3645 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3655 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3671 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 271:
#line 3678 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3693 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3702 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3719 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Predicate [ ]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 275:
#line 3733 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [literal]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 276:
#line 3740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [varref]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 277:
#line 3747 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [paren]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 278:
#line 3754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [context_item]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 279:
#line 3761 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [funcall]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 280:
#line 3768 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [cons]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 281:
#line 3775 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [ordered]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 282:
#line 3782 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [unordered]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 283:
#line 3795 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [numeric]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 284:
#line 3802 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [string]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 285:
#line 3815 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [decimal]\n";
#endif
			(yyval.expr) = new NumericLiteral((yyloc), decimal(yylval.decval));
		;}
    break;

  case 286:
#line 3822 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [int]\n";
#endif
			(yyval.expr) = new NumericLiteral((yyloc), yylval.ival);
		;}
    break;

  case 287:
#line 3829 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [double]\n";
#endif
			(yyval.expr) = new NumericLiteral((yyloc), yylval.dval);
		;}
    break;

  case 288:
#line 3842 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarRef [ ]\n";
#endif
			(yyval.expr) = new VarRef((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 289:
#line 3855 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [()]\n";
#endif
			(yyval.expr) = new ParenthesizedExpr((yyloc), NULL);
		;}
    break;

  case 290:
#line 3862 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [(expr)]\n";
#endif
			(yyval.expr) = new ParenthesizedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 291:
#line 3876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ContextItemExpr [.]\n";
#endif
			(yyval.expr) = new ContextItemExpr((yyloc));
		;}
    break;

  case 292:
#line 3889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderedExpr [expr]\n";
#endif
			(yyval.expr) = new OrderedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 293:
#line 3903 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnorderedExpr [expr]\n";
#endif
			(yyval.expr) = new UnorderedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 294:
#line 3962 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3971 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3986 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3995 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4010 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [direct]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 299:
#line 4017 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [computed]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 300:
#line 4030 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [element]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 301:
#line 4037 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [comment]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 4044 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [pi]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 303:
#line 4057 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4068 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4079 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4090 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4101 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4112 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4130 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4139 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4154 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4163 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4180 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4195 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [quote]\n";
#endif
			(yyval.node) = new DirAttributeValue((yyloc),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 315:
#line 4203 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [apos]\n";
#endif
			(yyval.node) = new DirAttributeValue((yyloc),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 316:
#line 4217 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList[empty]\n";
#endif
			(yyval.node) = new QuoteAttrContentList((yyloc));
		;}
    break;

  case 317:
#line 4224 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 318:
#line 4231 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4240 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4260 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4276 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']\n";
#endif
			(yyval.node) = new AposAttrContentList((yyloc));
		;}
    break;

  case 323:
#line 4283 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 324:
#line 4290 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4299 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4308 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4319 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4336 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [quote_attr_content]\n";
#endif
			(yyval.node) = new QuoteAttrValueContent((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 329:
#line 4344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [common_content]\n";
#endif
			(yyval.node) = new QuoteAttrValueContent((yyloc),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 330:
#line 4358 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [apos_attr_content]\n";
#endif
			(yyval.node) = new AposAttrValueContent((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 331:
#line 4366 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [common_content]\n";
#endif
			(yyval.node) = new AposAttrValueContent((yyloc),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 332:
#line 4380 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cons]\n";
#endif
			(yyval.expr) = new DirElemContent((yyloc),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 333:
#line 4388 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [elem_content]\n";
#endif
			(yyval.expr) = new DirElemContent((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 334:
#line 4396 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4405 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4420 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4429 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4438 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [{{]\n";
#endif
			(yyval.expr) = new CommonContent((yyloc),
								cont_escape_lbrace);
		;}
    break;

  case 339:
#line 4446 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [}}]\n";
#endif
			(yyval.expr) = new CommonContent((yyloc),
								cont_escape_rbrace);
		;}
    break;

  case 340:
#line 4454 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [expr]\n";
#endif
			(yyval.expr) = new CommonContent((yyloc),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 341:
#line 4468 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirCommentConstructor [ ]\n";
#endif
			(yyval.expr) = new DirCommentConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 342:
#line 4476 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "DirCommentConstructor [ ]\n";
#endif
      (yyval.expr) = new DirCommentConstructor((yyloc), "");
    ;}
    break;

  case 343:
#line 4494 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target]\n";
#endif
			(yyval.expr) = new DirPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 344:
#line 4502 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target.charlit]\n";
#endif
			(yyval.expr) = new DirPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 345:
#line 4522 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CDataSection [ ]\n";
#endif
			(yyval.expr) = new CDataSection((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 346:
#line 4540 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [doc]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 347:
#line 4547 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [elem]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 348:
#line 4554 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [attr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 349:
#line 4561 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [text]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 350:
#line 4568 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [comment]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 351:
#line 4575 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [pi]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 352:
#line 4588 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompDocConstructor [ ]\n";
#endif
			(yyval.expr) = new CompDocConstructor((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 353:
#line 4602 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [ ]\n";
#endif
			(yyval.expr) = new CompElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 354:
#line 4611 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [content]\n";
#endif
			(yyval.expr) = new CompElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 355:
#line 4620 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name]\n";
#endif
			(yyval.expr) = new CompElemConstructor((yyloc),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 356:
#line 4628 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name.content]\n";
#endif
			(yyval.expr) = new CompElemConstructor((yyloc),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 357:
#line 4656 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [ ]\n";
#endif
			(yyval.expr) = new CompAttrConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 358:
#line 4665 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [val]\n";
#endif
			(yyval.expr) = new CompAttrConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 359:
#line 4674 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name]\n";
#endif
			(yyval.expr) = new CompAttrConstructor((yyloc),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 360:
#line 4682 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name.val]\n";
#endif
			(yyval.expr) = new CompAttrConstructor((yyloc),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 361:
#line 4696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompTextConstructor [content]\n";
#endif
			(yyval.expr) = new CompTextConstructor((yyloc),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 362:
#line 4710 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompCommentConstructor [content]\n";
#endif
			(yyval.expr) = new CompCommentConstructor((yyloc),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 363:
#line 4724 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [ ]\n";
#endif
			(yyval.expr) = new CompPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 364:
#line 4733 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [content]\n";
#endif
			(yyval.expr) = new CompPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 365:
#line 4742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target]\n";
#endif
			(yyval.expr) = new CompPIConstructor((yyloc),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 366:
#line 4750 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target.content]\n";
#endif
			(yyval.expr) = new CompPIConstructor((yyloc),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 367:
#line 4764 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic]\n";
#endif
			(yyval.node) = new SingleType((yyloc),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 368:
#line 4773 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic ?]\n";
#endif
			(yyval.node) = new SingleType((yyloc),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 369:
#line 4788 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeDeclaration [as seqtype]\n";
#endif
			(yyval.node) = new TypeDeclaration((yyloc),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 370:
#line 4802 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type]\n";
#endif
			(yyval.node) = new SequenceType((yyloc),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 371:
#line 4811 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type.occurs]\n";
#endif
			(yyval.node) = new SequenceType((yyloc),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 372:
#line 4820 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [void]\n";
#endif
			(yyval.node) = new SequenceType((yyloc), NULL, NULL);
		;}
    break;

  case 373:
#line 4860 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [?]\n";
#endif
			(yyval.node) = new OccurrenceIndicator((yyloc),
								occurs_optionally);
		;}
    break;

  case 374:
#line 4868 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [*]\n";
#endif
			(yyval.node) = new OccurrenceIndicator((yyloc),
								occurs_zero_or_more);
		;}
    break;

  case 375:
#line 4876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [+]\n";
#endif
			(yyval.node) = new OccurrenceIndicator((yyloc),
								occurs_one_or_more);
		;}
    break;

  case 376:
#line 4890 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [atomic]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 377:
#line 4897 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [kind]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 378:
#line 4904 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [item]\n";
#endif
			(yyval.node) = new ItemType((yyloc),true);
		;}
    break;

  case 379:
#line 4917 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AtomicType [qname]\n";
#endif
			(yyval.node) = new AtomicType((yyloc),
								new QName((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 380:
#line 4931 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [doc]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 381:
#line 4938 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [elem]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 382:
#line 4945 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [attr]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 383:
#line 4952 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_elem]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 384:
#line 4959 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_attr]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 385:
#line 4966 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [pi]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 386:
#line 4973 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [comment]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 387:
#line 4980 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [text]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 388:
#line 4987 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [any]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 389:
#line 5000 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AnyKindTest [ ]\n";
#endif
			(yyval.node) = new AnyKindTest((yyloc));
		;}
    break;

  case 390:
#line 5013 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [ ]\n";
#endif
			(yyval.node) = new DocumentTest((yyloc));
		;}
    break;

  case 391:
#line 5020 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [elem]\n";
#endif
			(yyval.node) = new DocumentTest((yyloc),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 392:
#line 5028 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [schema_elem]\n";
#endif
			(yyval.node) = new DocumentTest((yyloc),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 393:
#line 5042 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TextTest [ ]\n";
#endif
			(yyval.node) = new TextTest((yyloc));
		;}
    break;

  case 394:
#line 5055 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommentTest [ ]\n";
#endif
			(yyval.node) = new CommentTest((yyloc));
		;}
    break;

  case 395:
#line 5068 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ ]\n";
#endif
			(yyval.node) = new PITest((yyloc), "", "");
		;}
    break;

  case 396:
#line 5075 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ncname]\n";
#endif
			(yyval.node) = new PITest((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), "");
		;}
    break;

  case 397:
#line 5082 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [stringlit]\n";
#endif
			(yyval.node) = new PITest((yyloc), "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 398:
#line 5095 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [ ]\n";
#endif
			(yyval.node) = new AttributeTest((yyloc),
								NULL,
								NULL);
		;}
    break;

  case 399:
#line 5104 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name]\n";
#endif
			(yyval.node) = new AttributeTest((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL);
		;}
    break;

  case 400:
#line 5113 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name.type]\n";
#endif
			(yyval.node) = new AttributeTest((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 401:
#line 5122 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*]\n";
#endif
			(yyval.node) = new AttributeTest((yyloc),
								NULL,
								NULL);
		;}
    break;

  case 402:
#line 5131 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*.type]\n";
#endif
			(yyval.node) = new AttributeTest((yyloc),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 403:
#line 5146 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaAttributeTest [ ]\n";
#endif
			(yyval.node) = new SchemaAttributeTest((yyloc),
								new QName((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 404:
#line 5160 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [ ]\n";
#endif
			(yyval.node) = new ElementTest((yyloc),
									NULL,
									NULL);
		;}
    break;

  case 405:
#line 5169 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name]\n";
#endif
			(yyval.node) = new ElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
									NULL);
		;}
    break;

  case 406:
#line 5178 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5187 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5196 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 409:
#line 5206 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5216 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5232 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaElementTest [ ]\n";
#endif
			(yyval.node) = new SchemaElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 412:
#line 5256 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name]\n";
#endif
			(yyval.node) = new TypeName((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 413:
#line 5266 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name?]\n";
#endif
			(yyval.node) = new TypeName((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 414:
#line 5289 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StringLiteral [ ]\n";
#endif
			(yyval.expr) = new StringLiteral((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 415:
#line 5331 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [ ]\n";
#endif
		;}
    break;

  case 416:
#line 5343 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr]\n";
#endif
		;}
    break;

  case 417:
#line 5349 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.as_first]\n";
#endif
		;}
    break;

  case 418:
#line 5355 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.as_last]\n";
#endif
		;}
    break;

  case 419:
#line 5361 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.after]\n";
#endif
		;}
    break;

  case 420:
#line 5367 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.before]\n";
#endif
		;}
    break;

  case 421:
#line 5379 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteExpr [expr]\n";
#endif
		;}
    break;

  case 422:
#line 5391 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceExpr [expr.expr]\n";
#endif
		;}
    break;

  case 423:
#line 5397 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceExpr [value.expr]\n";
#endif
		;}
    break;

  case 424:
#line 5409 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RenameExpr [expr.expr]\n";
#endif
		;}
    break;

  case 425:
#line 5436 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TransformExpr [ ]\n";
#endif
		;}
    break;

  case 426:
#line 5448 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [single]\n";
#endif
		;}
    break;

  case 427:
#line 5454 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [list]\n";
#endif
		;}
    break;

  case 428:
#line 5474 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or]\n";
#endif
		;}
    break;

  case 429:
#line 5480 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity]\n";
#endif
		;}
    break;

  case 430:
#line 5486 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.weight_range]\n";
#endif
		;}
    break;

  case 431:
#line 5492 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity.weight_range]\n";
#endif
		;}
    break;

  case 432:
#line 5504 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_single]\n";
#endif
		;}
    break;

  case 433:
#line 5510 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_single]\n";
#endif
		;}
    break;

  case 434:
#line 5516 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_list]\n";
#endif
		;}
    break;

  case 435:
#line 5522 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_list]\n";
#endif
		;}
    break;

  case 436:
#line 5534 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [and]\n";
#endif
		;}
    break;

  case 437:
#line 5540 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [or.and]\n";
#endif
		;}
    break;

  case 438:
#line 5552 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [mild_not]\n";
#endif
		;}
    break;

  case 439:
#line 5558 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [and.mild_not]\n";
#endif
		;}
    break;

  case 440:
#line 5570 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [unary_not]\n";
#endif
		;}
    break;

  case 441:
#line 5576 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [mild_not.unary_not]\n";
#endif
		;}
    break;

  case 442:
#line 5588 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [words]\n";
#endif
		;}
    break;

  case 443:
#line 5594 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [not.words]\n";
#endif
		;}
    break;

  case 444:
#line 5606 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words]\n";
#endif
		;}
    break;

  case 445:
#line 5612 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words.times]\n";
#endif
		;}
    break;

  case 446:
#line 5618 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [selection]\n";
#endif
		;}
    break;

  case 447:
#line 5630 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value]\n";
#endif
		;}
    break;

  case 448:
#line 5636 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value.any_all_option]\n";
#endif
		;}
    break;

  case 449:
#line 5648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [literal]\n";
#endif
		;}
    break;

  case 450:
#line 5654 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [expr]\n";
#endif
		;}
    break;

  case 451:
#line 5666 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [order]\n";
#endif
		;}
    break;

  case 452:
#line 5672 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [window]\n";
#endif
		;}
    break;

  case 453:
#line 5678 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [distance]\n";
#endif
		;}
    break;

  case 454:
#line 5684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [scope]\n";
#endif
		;}
    break;

  case 455:
#line 5690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [content]\n";
#endif
		;}
    break;

  case 456:
#line 5702 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOrderedIndicator [ ]\n";
#endif
		;}
    break;

  case 457:
#line 5714 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [case]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 458:
#line 5721 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [diacritics]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 459:
#line 5728 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stem]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 460:
#line 5735 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [thesaurus]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 461:
#line 5742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stopword]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 462:
#line 5749 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [language]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 463:
#line 5756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [wildcard]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 464:
#line 5769 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [lower]\n";
#endif
		;}
    break;

  case 465:
#line 5775 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [upper]\n";
#endif
		;}
    break;

  case 466:
#line 5781 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [sensitive]\n";
#endif
		;}
    break;

  case 467:
#line 5787 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [insensitive]\n";
#endif
		;}
    break;

  case 468:
#line 5799 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [with]\n";
#endif
		;}
    break;

  case 469:
#line 5805 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [without]\n";
#endif
		;}
    break;

  case 470:
#line 5811 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [sensitive]\n";
#endif
		;}
    break;

  case 471:
#line 5817 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [insensitive]\n";
#endif
		;}
    break;

  case 472:
#line 5829 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [with]\n";
#endif
		;}
    break;

  case 473:
#line 5835 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [without]\n";
#endif
		;}
    break;

  case 474:
#line 5847 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [id]\n";
#endif
		;}
    break;

  case 475:
#line 5853 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [default]\n";
#endif
		;}
    break;

  case 476:
#line 5859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id)]\n";
#endif
		;}
    break;

  case 477:
#line 5865 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id,id,..)]\n";
#endif
		;}
    break;

  case 478:
#line 5871 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default)]\n";
#endif
		;}
    break;

  case 479:
#line 5877 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default,id,id,..)]\n";
#endif
		;}
    break;

  case 480:
#line 5883 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [without]\n";
#endif
		;}
    break;

  case 481:
#line 5895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [single]\n";
#endif
		;}
    break;

  case 482:
#line 5901 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [list]\n";
#endif
		;}
    break;

  case 483:
#line 5913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name]\n";
#endif
		;}
    break;

  case 484:
#line 5919 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel]\n";
#endif
		;}
    break;

  case 485:
#line 5925 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.range]\n";
#endif
		;}
    break;

  case 486:
#line 5931 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel.range]\n";
#endif
		;}
    break;

  case 487:
#line 5943 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list]\n";
#endif
		;}
    break;

  case 488:
#line 5949 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list.incl_excl]\n";
#endif
		;}
    break;

  case 489:
#line 5955 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default]\n";
#endif
		;}
    break;

  case 490:
#line 5961 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default.incl_excl]\n";
#endif
		;}
    break;

  case 491:
#line 5967 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [without]\n";
#endif
		;}
    break;

  case 492:
#line 5979 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [.]\n";
#endif
		;}
    break;

  case 493:
#line 5985 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [*]\n";
#endif
		;}
    break;

  case 494:
#line 5997 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [.]\n";
#endif
		;}
    break;

  case 495:
#line 6003 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [(*)]\n";
#endif
		;}
    break;

  case 496:
#line 6015 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [.]\n";
#endif
		;}
    break;

  case 497:
#line 6021 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [*]\n";
#endif
		;}
    break;

  case 498:
#line 6033 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [union]\n";
#endif
		;}
    break;

  case 499:
#line 6039 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [except]\n";
#endif
		;}
    break;

  case 500:
#line 6051 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTLanguageOption [ ]\n";
#endif
		;}
    break;

  case 501:
#line 6063 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [with]\n";
#endif
		;}
    break;

  case 502:
#line 6069 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [without]\n";
#endif
		;}
    break;

  case 503:
#line 6081 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [start]\n";
#endif
		;}
    break;

  case 504:
#line 6087 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [end]\n";
#endif
		;}
    break;

  case 505:
#line 6093 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [entire]\n";
#endif
		;}
    break;

  case 506:
#line 6105 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any]\n";
#endif
		;}
    break;

  case 507:
#line 6111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any_word]\n";
#endif
		;}
    break;

  case 508:
#line 6117 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all]\n";
#endif
		;}
    break;

  case 509:
#line 6123 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all_words]\n";
#endif
		;}
    break;

  case 510:
#line 6129 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [phrase]\n";
#endif
		;}
    break;

  case 511:
#line 6141 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [exactly]\n";
#endif
		;}
    break;

  case 512:
#line 6147 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_least]\n";
#endif
		;}
    break;

  case 513:
#line 6153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_most]\n";
#endif
		;}
    break;

  case 514:
#line 6159 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [range]\n";
#endif
		;}
    break;

  case 515:
#line 6171 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDistance [ ]\n";
#endif
		;}
    break;

  case 516:
#line 6183 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWindow [ ]\n";
#endif
		;}
    break;

  case 517:
#line 6195 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [ ]\n";
#endif
		;}
    break;

  case 518:
#line 6207 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [same]\n";
#endif
		;}
    break;

  case 519:
#line 6213 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [different]\n";
#endif
		;}
    break;

  case 520:
#line 6225 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [words]\n";
#endif
		;}
    break;

  case 521:
#line 6231 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [sentences]\n";
#endif
		;}
    break;

  case 522:
#line 6237 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [paragraph]\n";
#endif
		;}
    break;

  case 523:
#line 6249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [sentence]\n";
#endif
		;}
    break;

  case 524:
#line 6255 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [paragraph]\n";
#endif
		;}
    break;

  case 525:
#line 6267 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTIgnoreOption [ ]\n";
#endif
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6114 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -643;
  const short int
  xquery_parser::yypact_[] =
  {
       795,  1366,  1554,  -643,  -643,  -643,  1742,  -643,     1,  -643,
    -643,  -643,  3058,    66,   362,  -643,  3058,   -21,  -643,   144,
     341,   366,   396,   317,    26,   184,   427,    91,   392,   106,
     -62,   426,   430,  -643,  -643,  3058,   264,   432,  -643,  -643,
    -643,  3058,    69,   464,  -643,  -643,   472,  3058,   267,    45,
    -643,  -643,   491,  1930,  -643,   437,   361,  3058,  -643,   510,
      73,  -643,   527,  -643,  -643,   259,   536,   540,  -643,   538,
     538,   464,  -643,   544,  3058,   433,  3058,  3058,  3058,    19,
     570,  -643,  3058,  3058,  3058,  1171,   574,  3430,   600,   983,
    -643,  -643,   415,  3058,   438,   439,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,  -643,   554,  -643,  -643,   215,
    -643,  -643,  -643,  -643,  -643,  -643,   468,   576,  -643,  3548,
     377,   -13,   229,   228,    16,  -643,   501,   440,   580,   581,
    3246,  -643,  -643,  -643,   -42,  -643,  -643,  -643,   378,  -643,
     507,   362,  -643,   507,   362,  -643,  -643,  -643,  -643,   507,
    -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,    47,  -643,
      94,  -643,  -643,    67,  3058,   108,    76,  -643,    82,  -643,
     109,  -643,  -643,  -643,  -643,  -643,  -643,   579,   582,  -643,
     603,   604,  -643,  -643,    -5,   543,   611,  -643,  -643,   265,
     319,   111,  -643,   477,   478,  -643,   112,    88,  -643,    95,
      32,     9,  -643,    -7,   590,  -643,    96,   605,   625,   607,
     517,   628,   620,   -15,   598,  -643,  -643,    97,   558,  -643,
     115,    50,   489,   492,  -643,   631,   537,  3058,   494,   495,
    -643,  -643,    21,    15,   116,  -643,    98,   125,   126,   458,
    -643,     3,  -643,    -2,   627,  3058,   448,   562,   158,  -643,
    -643,  -643,  -643,   641,  -643,  -643,  -643,  -643,  -643,  -643,
    -643,   208,  -643,  -643,    37,   295,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,
     415,   -11,  3058,  3058,  3058,  3058,  3058,  -643,   -32,   508,
    3414,  3414,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,  -643,  -643,  3414,  3414,  3414,
       8,  3414,  3414,  3414,  3414,  3414,  3414,  3414,  3414,  3414,
    3414,  3414,   224,   224,   646,   646,  -643,  -643,  -643,  2118,
    -643,   538,   538,  3058,   507,  -643,  -643,   507,  -643,   507,
    -643,  -643,  3058,  -643,   127,   555,   648,  -643,   648,  -643,
    -643,   -10,   332,  -643,  -643,   645,   199,   224,    84,  -643,
     647,  -643,   257,   224,    93,   224,  -643,  3058,   325,  -643,
    -643,  -643,   560,   652,  -643,   652,  -643,  3058,   568,   602,
    3058,   606,  3058,   608,   -41,   573,    -8,   609,   509,   662,
     599,   662,  -643,   610,   656,  3058,   592,   -43,   618,  -643,
     670,  -643,  -643,  -643,  -643,  -643,  -643,  2306,   142,  -643,
    -643,  3058,   614,  -643,    24,    25,  -643,  -643,   655,  -643,
    -643,  -643,   673,  -643,   243,  3058,  3058,  3058,  3058,   493,
    3058,  3058,   678,  3058,  -643,    37,    37,   208,  -643,   681,
     683,   208,   685,  -643,    39,  -643,   546,  -643,  -643,  -643,
     461,   664,  -643,  -643,   664,  -643,  3058,   557,  3058,   576,
    -643,  -643,  -643,  -643,  3058,     8,   270,  -643,   465,   519,
     484,   479,  -643,  -643,   480,   285,   229,   229,   -12,   228,
     228,   228,   228,    16,    16,  -643,  -643,  -643,  -643,  -643,
    -643,   400,  -643,  -643,  -643,  -643,   616,  -643,  -643,   181,
    -643,  -643,   105,  -643,  -643,  -643,  2494,  -643,   563,   564,
    -643,  -643,  -643,  -643,   691,  -643,  3058,  -643,   296,   649,
     313,   224,  -643,  -643,  -643,   373,   390,   224,  -643,  -643,
    -643,  3058,  2682,   623,   569,   572,   577,   591,  -643,  3058,
     464,  -643,   701,  -643,   703,  3058,   624,  3058,  3058,   -33,
     630,   472,  3058,  -643,   704,   714,   704,  -643,   662,  -643,
    3058,  3058,   650,   491,   584,  -643,   192,   638,  -643,    72,
    -643,  -643,  -643,   748,  -643,  -643,   737,  -643,  -643,    52,
    -643,  -643,  -643,  -643,   107,  -643,   194,    57,  -643,   595,
    3058,  3058,  -643,  -643,  -643,  -643,  3058,  -643,  -643,   660,
     613,  -643,  -643,  -643,  -643,  -643,    17,   208,    85,    99,
     100,   -11,  -643,   739,  -643,  -643,  -643,  -643,   320,   715,
    -643,  3058,  -643,  3058,  -643,   236,   626,  -643,  3414,  -643,
    -643,  -643,  -643,   120,   311,  -643,     8,   120,  3414,  3414,
    3373,  -643,  -643,  -643,  -643,  -643,  -643,  -643,     8,     8,
     311,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,  -643,   239,  -643,  -643,  -643,
     241,  -643,  -643,  -643,  -643,  -643,   395,  -643,  -643,  -643,
    -643,   403,  -643,  -643,   242,  -643,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,  3058,  -643,  -643,  3058,   659,
    3058,  -643,   699,   759,   751,   704,  -643,  -643,  3058,  -643,
    -643,  -643,  2870,   281,   473,  -643,  -643,   615,   766,  -643,
     767,   207,   764,   633,   282,  -643,  -643,  -643,  -643,  -643,
    3058,  3058,  -643,  -643,  3414,  3414,  3414,  3414,   768,   556,
     760,  -643,   760,  -643,  -643,   715,  -643,  -643,  -643,  -643,
    -643,  -643,   228,  -643,  -643,  -643,   195,   484,  -643,  -643,
     262,  3414,  -643,  -643,   479,  -643,   548,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,  -643,  3058,  -643,  3058,  -643,
     662,  -643,  -643,   248,  -643,  -643,   762,   425,  -643,  -643,
    -643,  -643,   642,   583,  -643,  -643,  -643,   629,   632,   777,
     769,  3058,   773,  3058,  -643,  -643,   228,   228,   228,   119,
     311,  -643,   101,  -643,   102,  -643,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,   704,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,   635,   224,  -643,   643,  -643,
    3414,   567,   760,  -643,  -643,  -643,   654,  3058,   228,  -643,
    -643,  3058,  -643,  -643
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,     0,     0,   268,   269,   265,     0,   414,     0,   259,
     262,   249,     0,     0,     0,   247,     0,     0,   285,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   251,     0,     0,     0,   291,   257,
     287,     0,     0,     0,   253,   252,     0,     0,     0,     0,
     286,   232,     0,     0,   204,     0,     0,     0,   258,     0,
       0,   203,     0,   261,   260,     0,     0,     0,   250,     0,
       0,     0,   267,     0,     0,     0,     0,     0,     0,     0,
       0,   415,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     4,     0,     0,     0,     0,    15,    17,    19,    20,
      21,    27,    22,    25,    26,    31,    32,    33,    28,    29,
      35,    36,    23,    30,    24,     9,    93,    94,    96,     0,
     110,   112,   113,    97,    98,    99,   100,   166,   168,   170,
     174,   177,   179,   182,   187,   190,   193,   195,   197,   199,
       0,   201,   207,   209,     0,   229,   208,   235,   236,   239,
     241,     0,   246,   243,     0,   254,   264,   266,   240,   270,
     275,   283,   276,   277,   278,   281,   282,   279,   280,   298,
     300,   301,   302,   299,   346,   347,   348,   349,   350,   351,
     263,   388,   380,   387,   386,   385,   382,   384,   381,   383,
     284,    34,   101,   102,   104,   103,   105,   357,     0,   353,
       0,   294,   296,     0,     0,     0,     0,   398,     0,   255,
       0,   394,    53,    38,    39,    70,    71,     0,     0,    52,
       0,     0,    46,    47,     0,     0,     0,    44,    45,     0,
       0,     0,   390,     0,     0,   288,     0,     0,   404,     0,
       0,     0,   155,     0,   114,   115,     0,    62,     0,    54,
       0,     0,     0,     0,   127,   128,   289,     0,     0,   389,
       0,     0,     0,     0,   395,     0,     0,     0,     0,     0,
     233,   234,     0,     0,     0,   393,     0,     0,     0,     0,
     342,     0,   421,     0,     0,     0,     0,     0,     0,   467,
     466,   471,   470,     0,   464,   465,   469,   473,   491,   480,
     502,   489,   468,   472,     0,     0,   501,    43,   457,   458,
     459,   460,   461,   462,   463,     1,     3,     5,    10,     8,
      12,    13,     0,     0,     0,     0,     0,   111,     0,     0,
       0,     0,   210,   224,   215,   214,   222,   213,   212,   211,
     223,   216,   221,   220,   219,   218,   217,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   206,   205,   202,     0,
     230,     0,     0,     0,   242,   272,   245,   244,   256,   271,
     358,   354,     0,   295,     0,     0,     0,   399,     0,   401,
     362,     0,     0,    40,    41,     0,     0,     0,     0,    88,
       0,    42,     0,     0,     0,     0,    67,     0,     0,   352,
     391,   392,     0,     0,   405,     0,   408,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,     0,    55,     0,     0,     0,     0,   290,
       0,   292,   344,   343,   396,   397,   231,     0,     0,   403,
     411,     0,     0,   303,     0,     0,   311,   361,     0,   293,
     225,   341,     0,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   500,     0,     0,   490,   492,     0,
       0,   487,     0,   475,     0,   474,     0,    16,    18,    95,
     139,   135,   137,   106,   136,   134,     0,     0,     0,   167,
     169,   172,   171,   173,     0,     0,     0,   449,   175,   428,
     436,   438,   440,   442,   444,   447,   181,   180,   178,   184,
     185,   186,   183,   188,   189,   192,   191,   379,   378,   372,
     194,   370,   376,   377,   196,   198,   367,   200,   227,     0,
     237,   238,     0,   273,   297,   226,     0,   412,     0,     0,
      50,    51,    48,    49,    90,    72,     0,    73,     0,     0,
       0,     0,    37,    80,    81,     0,     0,     0,   369,    66,
      69,     0,     0,   412,     0,     0,     0,     0,   157,     0,
       0,   154,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    64,     0,    56,    60,     0,   130,
       0,     0,     0,     0,     0,   363,     0,     0,   153,     0,
     337,   333,   336,     0,   338,   339,     0,   340,   332,     0,
     309,   335,   334,   304,     0,   312,     0,     0,   161,     0,
       0,     0,   419,   420,   416,   424,     0,   422,   426,     0,
       0,   499,   498,   493,   494,   496,     0,   488,   483,     0,
       0,    14,   148,     0,   149,   150,   151,   140,   141,   142,
     143,     0,   107,     0,   108,     0,     0,   443,     0,   176,
     456,   504,   503,     0,     0,   505,     0,     0,     0,     0,
     429,   433,   451,   432,   455,   453,   452,   454,     0,     0,
       0,   445,   508,   509,   506,   507,   510,   448,   373,   375,
     374,   371,   368,   228,   274,   359,     0,   400,   402,    91,
       0,    76,    77,    89,    74,    75,     0,    84,    85,    82,
      83,     0,    68,   355,     0,   413,   406,   407,   409,   410,
     158,   156,   125,   126,   119,     0,   121,   118,     0,     0,
       0,   116,     0,     0,    63,    57,   132,   131,     0,   129,
      11,   364,     0,   322,   316,   313,   345,     0,     0,   310,
       0,     0,     0,     0,     0,   162,     7,   417,   418,   423,
       0,     0,   497,   495,     0,     0,     0,     0,     0,     0,
       0,   478,     0,   476,   152,   144,   145,   146,   138,   109,
     450,   446,   525,   524,   523,   519,     0,   437,   518,   430,
       0,     0,   435,   434,   439,   441,     0,   360,    92,    78,
      79,    86,    87,   356,   123,   120,     0,   122,     0,    59,
       0,   133,   365,     0,   330,   324,     0,   323,   325,   331,
     328,   318,     0,   317,   319,   329,   305,     0,     0,     0,
       0,     0,     0,     0,   427,   425,   512,   513,   511,     0,
     484,   485,     0,   481,     0,   147,   522,   521,   520,   515,
     516,   431,   517,   124,   165,    65,   366,   315,   326,   327,
     314,   320,   321,   306,   307,     0,     0,   163,     0,   159,
       0,     0,     0,   479,   477,   308,     0,     0,   514,   486,
     482,     0,   160,   164
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -643,  -643,  -643,   720,   724,  -643,   712,  -643,   497,   499,
    -306,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -427,  -643,  -643,  -643,  -643,  -643,
     593,   261,  -382,   732,     6,    -6,  -643,  -643,   707,  -643,
    -643,   237,   401,  -247,  -643,  -643,   226,  -643,   502,   511,
     177,  -643,  -643,   183,  -567,  -643,   771,   263,  -643,  -643,
     212,  -643,  -643,   514,   531,   221,  -597,   513,   133,  -344,
     196,   211,  -643,  -643,  -643,  -643,  -643,   723,  -643,  -643,
    -643,  -643,  -643,  -643,   729,  -643,   -46,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,    79,  -643,  -643,  -643,   297,   -69,
    -643,  -345,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,
    -643,  -433,  -643,   251,  -643,   412,  -643,  -643,  -643,  -643,
    -643,    46,    51,  -581,  -390,  -643,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,   515,  -224,  -354,  -643,  -643,
     220,  -361,  -643,  -643,  -643,  -643,  -643,  -643,  -643,   846,
     847,    33,   469,  -643,  -643,  -643,  -643,  -643,  -643,  -643,
    -643,   382,  -643,  -643,   217,   200,   202,   388,  -643,  -643,
     216,  -643,  -481,  -643,  -643,  -643,  -643,   113,  -302,  -643,
     416,   122,  -643,  -438,  -643,  -643,  -643,  -643,  -642,  -643,
    -643,  -643,  -643,   103,   225,  -643
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   594,   252,   111,   112,   113,   114,
     398,   399,   617,   115,   116,   117,   118,   119,   120,   121,
     244,   245,   424,   425,   122,   254,   255,   328,   329,   491,
     492,   657,   658,   659,   660,   123,   241,   242,   124,   627,
     628,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   347,   348,
     349,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   374,   375,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   203,
     168,   169,   170,   619,   455,   456,   755,   832,   833,   826,
     827,   834,   828,   620,   621,   171,   172,   622,   173,   174,
     175,   176,   177,   178,   179,   535,   408,   530,   701,   531,
     532,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   548,   575,   190,   191,   192,   193,   194,   195,   196,
     288,   508,   680,   509,   510,   511,   512,   513,   514,   515,
     681,   682,   307,   308,   309,   310,   311,   852,   853,   312,
     477,   481,   646,   478,   313,   314,   684,   697,   779,   685,
     686,   691,   687,   859,   795,   669
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       202,   533,   533,   485,   596,   507,   436,   198,   200,   534,
     519,   520,   521,   522,   557,   488,   418,   405,   205,   426,
     564,   618,   210,   270,   271,   405,   421,   421,   683,   437,
     464,     7,   796,   610,   611,   452,   533,   612,   759,   643,
     772,   231,   533,   558,   533,   452,   279,   236,   806,   565,
      27,   568,    29,   246,    31,    32,   419,   601,   442,   257,
      18,   610,   611,   260,   405,   612,   585,   613,   419,   249,
     395,   479,   369,   482,   738,   227,   282,   283,   284,   286,
     274,   799,   276,   277,   278,   435,   206,    40,   262,   237,
     462,   786,   787,   209,   322,   613,   263,   626,   550,   588,
     422,   453,   614,   753,   615,    62,   649,   323,   360,   351,
     351,   623,   224,   250,   382,   204,   610,   611,    50,   228,
     612,   551,   504,   386,   764,   496,   226,   361,   505,   388,
     614,   559,   615,   352,   352,   413,   325,   211,   556,   417,
     559,   322,   415,   322,   322,   322,   780,   782,   882,   882,
     613,   220,   322,   396,   397,   322,   322,   480,   322,   322,
     507,   507,   322,   322,   353,    59,   556,   463,   212,   420,
     251,   745,   322,   322,   322,   773,   712,   586,   715,   590,
     759,   451,   650,   718,   720,   614,   618,   615,   454,   322,
     602,   618,   443,    59,   616,    73,   465,   466,   624,   803,
     533,   423,   380,   423,   861,   467,   533,   716,   881,   643,
     384,   423,    87,   721,   527,   280,   610,   611,   855,    79,
     612,   556,   758,    73,   207,   383,   754,   238,   322,   423,
     376,   264,    13,   378,   387,   208,   423,   423,   239,   322,
     389,   506,   560,   561,   527,    17,   414,    79,    59,   381,
     613,   566,   567,   416,   428,   439,   458,   781,   783,   883,
     884,   704,    13,   385,   390,   533,   409,   412,    36,   762,
     441,   457,   763,   448,   266,    17,    42,   760,    73,   469,
     459,   460,   545,   322,   824,   614,   322,   615,   322,   322,
     610,   247,   555,     7,   612,   322,   880,   607,    36,   358,
     475,   354,    79,   774,   775,   543,    42,   528,   543,   221,
     543,   359,    46,   556,   776,   777,   489,   490,   493,   490,
     495,   556,    18,    56,   792,   540,   541,   778,   618,   482,
     709,   507,   355,    52,   810,   800,   703,   528,    60,   812,
     395,   219,   739,   507,   507,   488,    42,   751,    59,    40,
     563,   405,   356,    56,   323,    66,    67,   842,   472,   614,
     793,   615,   483,   829,   835,   794,   653,   473,    60,    75,
     825,   556,   324,   267,     3,   539,   544,   839,    73,   542,
      50,     4,     5,   325,   504,    66,    67,   529,   476,   711,
     505,   790,   248,   865,   807,   556,   808,   813,   357,    75,
      13,   569,    79,   866,   655,   656,   714,   225,   358,   326,
     556,   578,   406,    17,   581,   484,   583,   529,   570,   407,
     359,   549,   232,   402,   403,   571,    67,   556,   824,   599,
     846,   847,   848,   849,   610,   856,    36,   829,   612,   843,
     552,   857,   358,   835,    42,   608,   574,   229,   576,   630,
     377,   631,   258,   606,   359,   230,   379,   235,   858,   632,
     633,   634,   635,   553,   637,   638,   717,   640,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,   610,   719,   516,   517,   612,   556,   809,   240,
     662,    56,   664,   213,   652,   830,   811,   243,   692,   693,
     694,   695,   856,   614,   556,   615,    60,   653,   857,   556,
     665,   222,   223,   214,   868,   533,   253,   556,   215,   259,
      48,    49,   886,    66,    67,   858,   696,   261,   217,   774,
     775,    72,   654,   698,   699,   700,   888,    75,   216,   556,
     776,   777,     1,   371,   372,   655,   656,   265,   218,     2,
       3,   614,   706,   615,   523,   524,   268,     4,     5,     6,
     269,     7,   710,   831,   273,   722,     9,    10,   501,   502,
     503,   525,   526,   730,    11,    12,    13,    14,   724,   734,
     890,   736,   737,    15,   536,   536,   742,   556,    16,    17,
      18,   275,   610,   281,   746,   747,   612,   641,   642,   287,
     315,   322,   320,   321,   330,   830,   331,    33,    34,   350,
     362,    35,    36,    37,    38,    39,    81,    40,   363,    41,
      42,   364,   373,   365,   767,   768,   391,   393,   394,   392,
     769,   400,    44,    45,   401,   410,   411,   427,    87,   429,
     430,   431,   432,   433,   434,   438,   440,   444,    50,   446,
     445,   447,   449,   450,   461,   490,   670,   789,    53,   468,
     470,   614,   471,   615,   474,   498,   527,    56,   547,   546,
     554,   562,   573,   871,   572,   579,    57,   580,    58,    59,
     587,   582,    60,   584,   591,   592,   593,   595,    63,    64,
     598,    65,   600,   603,   604,   626,   629,   556,   597,    66,
      67,    68,   609,   639,   644,   636,   645,    72,   648,    73,
     651,   661,    74,    75,   663,   688,   668,   689,   702,   690,
      77,   707,   708,   405,   395,   725,   732,   726,   733,   814,
     727,   735,   815,    79,   817,   728,   671,   740,   744,   672,
     289,   290,   821,   291,   292,   673,   674,   675,   750,   729,
     748,   743,   752,   676,   293,   756,   294,   757,   823,   766,
     770,   653,   677,   784,   844,   845,   816,   295,   678,   679,
     771,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   818,   819,   791,   820,   837,   838,   836,   840,
     841,   850,   851,   867,   482,   862,   870,   875,   878,     1,
     887,   876,   873,   889,   318,   874,     2,     3,   885,   316,
     863,   891,   864,   317,     4,     5,     6,   486,     7,   487,
     713,     8,   404,     9,    10,   319,   327,   589,   741,   749,
     497,    11,    12,    13,    14,   877,   494,   879,   788,   765,
      15,   785,   272,   731,   499,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,   500,   368,    33,    34,   518,   625,    35,    36,
      37,    38,    39,   370,    40,   761,    41,    42,   869,   872,
     537,   892,   233,   234,   577,   893,    43,   666,   804,    44,
      45,   805,    46,   797,   667,   854,   802,   647,     0,    47,
      48,    49,   798,   860,     0,    50,     0,     0,     0,     0,
       0,     0,    51,    52,     0,    53,     0,    54,     0,    55,
       0,     0,     0,     0,    56,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,    58,    59,     0,     0,    60,
       0,    61,    62,     0,     0,    63,    64,     0,    65,     0,
       0,     0,     0,     0,     0,     0,    66,    67,    68,     0,
      69,    70,    71,     0,    72,     0,    73,     0,     0,    74,
      75,     0,     0,     0,    76,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     1,     0,     0,
      79,     0,    80,     0,     2,     3,    81,    82,    83,    84,
      85,     0,     4,     5,     6,    86,     7,     0,     0,     8,
       0,     9,    10,     0,     0,     0,     0,     0,    87,    11,
      12,    13,    14,     0,     0,     0,     0,     0,    15,     0,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       0,     0,    33,    34,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,    42,     0,     0,     0,     0,
       0,     0,     0,     0,    43,     0,     0,    44,    45,     0,
      46,     0,     0,     0,     0,     0,     0,    47,    48,    49,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
      51,    52,     0,    53,     0,    54,     0,    55,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,    58,    59,     0,     0,    60,     0,    61,
      62,     0,     0,    63,    64,     0,    65,     0,     0,     0,
       0,     0,     0,     0,    66,    67,    68,     0,    69,    70,
      71,     0,    72,     0,    73,     0,     0,    74,    75,     0,
       0,     0,    76,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     1,     0,     0,    79,     0,
       0,     0,     2,     3,    81,    82,    83,    84,    85,     0,
       4,     5,     6,    86,     7,     0,     0,     8,     0,     9,
      10,     0,     0,     0,     0,     0,    87,    11,    12,    13,
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
       0,    63,    64,     0,    65,     0,     0,     0,     0,     0,
       0,     0,    66,    67,    68,     0,    69,    70,    71,     0,
      72,     0,    73,     0,     0,    74,    75,     0,     0,     0,
      76,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     0,    79,     0,     0,     0,
       1,     0,     0,    82,    83,    84,    85,     2,     3,     0,
       0,    86,   285,     0,     0,     4,     5,     6,     0,     7,
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
       0,   197,     0,     0,     0,     0,     0,    66,    67,    68,
       0,    69,    70,    71,     0,    72,     0,    73,     0,     0,
      74,    75,     0,     0,     0,    76,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     1,     0,
       0,    79,     0,     0,     0,     2,     3,     0,    82,    83,
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
      61,    62,     0,     0,    63,    64,     0,    65,     0,   199,
       0,     0,     0,     0,     0,    66,    67,    68,     0,    69,
      70,    71,     0,    72,     0,    73,     0,     0,    74,    75,
       0,     0,     0,    76,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     1,     0,     0,    79,
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
       0,     0,    63,    64,     0,    65,     0,     0,     0,     0,
     201,     0,     0,    66,    67,    68,     0,    69,    70,    71,
       0,    72,     0,    73,     0,     0,    74,    75,     0,     0,
       0,    76,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     1,     0,     0,    79,     0,     0,
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
      63,    64,     0,    65,     0,     0,     0,     0,   256,     0,
       0,    66,    67,    68,     0,    69,    70,    71,     0,    72,
       0,    73,     0,     0,    74,    75,     0,     0,     0,    76,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     1,     0,     0,    79,     0,     0,     0,     2,
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
       0,    65,     0,   538,     0,     0,     0,     0,     0,    66,
      67,    68,     0,    69,    70,    71,     0,    72,     0,    73,
       0,     0,    74,    75,     0,     0,     0,    76,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       1,     0,     0,    79,     0,     0,     0,     2,     3,     0,
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
       0,   605,     0,     0,     0,     0,     0,    66,    67,    68,
       0,    69,    70,    71,     0,    72,     0,    73,     0,     0,
      74,    75,     0,     0,     0,    76,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     1,     0,
       0,    79,     0,     0,     0,     2,     3,     0,    82,    83,
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
      61,    62,     0,     0,    63,    64,     0,    65,     0,   705,
       0,     0,     0,     0,     0,    66,    67,    68,     0,    69,
      70,    71,     0,    72,     0,    73,     0,     0,    74,    75,
       0,     0,     0,    76,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     1,     0,     0,    79,
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
       0,     0,    63,    64,     0,    65,     0,   723,     0,     0,
       0,     0,     0,    66,    67,    68,     0,    69,    70,    71,
       0,    72,     0,    73,     0,     0,    74,    75,     0,     0,
       0,    76,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     1,     0,     0,    79,     0,     0,
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
      63,    64,     0,    65,     0,   822,     0,     0,     0,     0,
       0,    66,    67,    68,     0,    69,    70,    71,     0,    72,
       0,    73,     0,     0,    74,    75,     0,     0,     0,    76,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     1,     0,     0,    79,     0,     0,     0,     2,
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
       0,    65,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,     0,    69,    70,    71,     0,    72,     0,    73,
       0,     0,    74,    75,     0,     0,     0,    76,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       1,     0,     0,    79,     0,     0,     0,     2,     3,     0,
      82,    83,    84,    85,     0,     4,     5,     6,    86,     7,
       0,     0,     8,     0,     9,    10,     0,     0,     0,     0,
       0,     0,    11,    12,    13,    14,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,     0,     0,     0,
       0,     0,     0,    51,     0,     0,    53,     0,   366,     0,
       0,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,    58,    59,     0,     0,
      60,     0,   367,    62,     0,     0,    63,    64,     0,    65,
       0,     0,     0,     0,     0,     0,     0,    66,    67,    68,
       0,    69,    70,     0,     0,    72,     0,    73,     1,     0,
      74,    75,     0,     0,     0,     2,     3,     0,    77,     0,
       0,     0,     0,     4,     5,     6,    78,     7,     0,     0,
       8,    79,     9,    10,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,    16,    17,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,     0,     0,    35,    36,    37,
      38,    39,     0,    40,     0,    41,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,    45,
     670,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,     0,     0,     0,     0,
       0,    51,     0,     0,    53,     0,    54,     0,     0,     0,
       0,     0,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,    57,     0,    58,    59,     0,     0,    60,     0,
      61,    62,     0,     0,    63,    64,     0,    65,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,     0,    69,
      70,     0,     0,    72,     0,    73,     0,     0,    74,    75,
     671,     0,     0,   672,   289,   290,    77,   291,   292,   673,
     674,   675,     0,     0,    78,     0,     0,     0,   293,    79,
     294,     0,     0,     0,     0,     0,   677,     0,     0,     0,
       0,   295,   801,   679,     0,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   332,     0,     0,     0,
       0,     0,     0,     0,   333,     0,     0,   334,     0,   335,
       0,   289,   290,     0,   291,   292,     0,     0,     0,     0,
     336,     0,     0,     0,   337,   293,     0,   294,     0,   338,
       0,     0,     0,     0,     0,   339,     0,     0,   295,     0,
       0,     0,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,     0,     0,     0,     0,   340,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   341,   342,   343,   344,   345,   346
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         6,   362,   363,   305,   431,   350,   253,     1,     2,   363,
     354,   355,   356,   357,   396,   321,   240,    32,    12,   243,
     402,   454,    16,    69,    70,    32,    34,    34,   509,   253,
      32,    23,   674,     9,    10,    20,   397,    13,   619,   477,
      23,    35,   403,   397,   405,    20,    27,    41,   690,   403,
      61,   405,    63,    47,    65,    66,    47,   100,     8,    53,
      52,     9,    10,    57,    32,    13,   107,    43,    47,    24,
      75,    34,   114,    34,   107,   137,    82,    83,    84,    85,
      74,   678,    76,    77,    78,   100,    20,    79,    15,    20,
      87,   658,   659,    14,    47,    43,    23,    40,   108,   107,
     107,    86,    78,    31,    80,   147,    67,   139,    92,   122,
     122,    86,    21,    68,    47,   114,     9,    10,   110,   181,
      13,   131,   114,    47,    67,   157,    20,   111,   120,    47,
      78,    47,    80,   146,   146,    47,   168,   158,   114,   107,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      43,   125,    47,   158,   159,    47,    47,   120,    47,    47,
     505,   506,    47,    47,   177,   141,   114,   164,    24,   160,
     125,   598,    47,    47,    47,   158,   558,   424,   560,   426,
     761,   160,   484,   565,   566,    78,   619,    80,   173,    47,
     437,   624,   142,   141,   170,   171,   198,   199,   173,   680,
     561,   244,   155,   244,   801,   207,   567,   561,   850,   647,
     204,   244,   223,   567,    20,   196,     9,    10,   785,   195,
      13,   114,   170,   171,   158,   158,   154,   158,    47,   244,
     151,   158,    38,   154,   158,   169,   244,   244,   169,    47,
     158,   233,   158,   159,    20,    51,   158,   195,   141,   155,
      43,   158,   159,   158,   158,   158,   158,   158,   158,   158,
     158,   156,    38,   155,   155,   626,   155,   155,    74,    75,
     155,   155,   626,   267,    15,    51,    82,   170,   171,   285,
     155,   155,   155,    47,     3,    78,    47,    80,    47,    47,
       9,    24,    93,    23,    13,    47,   177,   155,    74,   180,
      92,    72,   195,   218,   219,   374,    82,   113,   377,   125,
     379,   192,    97,   114,   229,   230,   322,   323,   324,   325,
     326,   114,    52,   129,   668,   371,   372,   242,   761,    34,
     554,   676,   103,   118,   716,   679,   155,   113,   144,   721,
      75,    24,   589,   688,   689,   651,    82,   155,   141,    79,
      93,    32,   123,   129,   139,   161,   162,    75,   200,    78,
     240,    80,    67,   753,   754,   245,    46,   209,   144,   175,
      89,   114,   157,   114,    12,   369,   382,   170,   171,   373,
     110,    19,    20,   168,   114,   161,   162,   193,   180,    93,
     120,   155,   125,   820,   155,   114,   155,   155,   169,   175,
      38,   407,   195,   155,    84,    85,    93,    15,   180,   194,
     114,   417,    93,    51,   420,   120,   422,   193,    93,   100,
     192,   388,   158,   158,   159,   100,   162,   114,     3,   435,
     774,   775,   776,   777,     9,   240,    74,   827,    13,   157,
     108,   246,   180,   833,    82,   451,   413,    21,   415,   206,
     153,   208,    15,   447,   192,    25,   159,    25,   263,   465,
     466,   467,   468,   131,   470,   471,    93,   473,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     9,    93,   351,   352,    13,   114,    93,    25,
     496,   129,   498,   152,    33,    22,    93,    25,   213,   214,
     215,   216,   240,    78,   114,    80,   144,    46,   246,   114,
     504,    84,    85,   172,    89,   876,    25,   114,   152,   158,
     105,   106,   876,   161,   162,   263,   241,    17,   132,   218,
     219,   169,    71,   133,   134,   135,   880,   175,   172,   114,
     229,   230,     4,   165,   166,    84,    85,    20,   152,    11,
      12,    78,   546,    80,   358,   359,    20,    19,    20,    21,
      20,    23,   556,    90,    20,   571,    28,    29,   347,   348,
     349,   360,   361,   579,    36,    37,    38,    39,   572,   585,
     882,   587,   588,    45,   364,   365,   592,   114,    50,    51,
      52,   158,     9,    23,   600,   601,    13,   475,   476,    25,
       0,    47,   164,   164,   136,    22,    30,    69,    70,   232,
     109,    73,    74,    75,    76,    77,   201,    79,   178,    81,
      82,    41,   115,    42,   630,   631,    47,    24,    24,    47,
     636,    88,    94,    95,    23,   158,   158,    47,   223,    34,
      15,    34,   125,    15,    24,    47,    88,   158,   110,    18,
     158,   114,   158,   158,   196,   661,   137,   663,   120,    32,
     212,    78,   100,    80,    23,   157,    20,   129,    20,   114,
      25,    24,    20,    90,   114,   107,   138,    75,   140,   141,
     107,    75,   144,    75,    75,   176,    24,    88,   150,   151,
      34,   153,   100,    75,    24,    40,    23,   114,    88,   161,
     162,   163,    88,    25,    23,   212,    23,   169,    23,   171,
     164,    47,   174,   175,   157,   231,   251,   238,   102,   239,
     182,   158,   158,    32,    75,   102,    25,   158,    25,   735,
     158,   107,   738,   195,   740,   158,   217,   107,    24,   220,
     221,   222,   748,   224,   225,   226,   227,   228,   164,   158,
     100,    47,   114,   234,   235,     7,   237,    20,   752,   164,
     100,    46,   243,    24,   770,   771,   107,   248,   249,   250,
     157,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,    83,    24,   158,    34,    20,    20,   173,    25,
     157,    23,   236,    31,    34,   247,   154,    20,    25,     4,
     157,    32,   173,   236,    92,   173,    11,    12,   173,    89,
     816,   157,   818,    89,    19,    20,    21,   320,    23,   320,
     559,    26,   229,    28,    29,    93,   119,   426,   591,   603,
     328,    36,    37,    38,    39,   841,   325,   843,   661,   627,
      45,   658,    71,   580,   330,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,   331,   140,    69,    70,   353,   455,    73,    74,
      75,    76,    77,   144,    79,   624,    81,    82,   827,   833,
     365,   887,    36,    36,   415,   891,    91,   505,   688,    94,
      95,   689,    97,   676,   506,   782,   680,   481,    -1,   104,
     105,   106,   677,   800,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,    -1,   120,    -1,   122,    -1,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,    -1,   140,   141,    -1,    -1,   144,
      -1,   146,   147,    -1,    -1,   150,   151,    -1,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,
     165,   166,   167,    -1,   169,    -1,   171,    -1,    -1,   174,
     175,    -1,    -1,    -1,   179,    -1,    -1,   182,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,    -1,     4,    -1,    -1,
     195,    -1,   197,    -1,    11,    12,   201,   202,   203,   204,
     205,    -1,    19,    20,    21,   210,    23,    -1,    -1,    26,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,   223,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    69,    70,    -1,    -1,    73,    74,    75,    76,
      77,    -1,    79,    -1,    81,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    95,    -1,
      97,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,
      -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,    -1,   120,    -1,   122,    -1,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,   140,   141,    -1,    -1,   144,    -1,   146,
     147,    -1,    -1,   150,   151,    -1,   153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,   163,    -1,   165,   166,
     167,    -1,   169,    -1,   171,    -1,    -1,   174,   175,    -1,
      -1,    -1,   179,    -1,    -1,   182,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   190,    -1,     4,    -1,    -1,   195,    -1,
      -1,    -1,    11,    12,   201,   202,   203,   204,   205,    -1,
      19,    20,    21,   210,    23,    -1,    -1,    26,    -1,    28,
      29,    -1,    -1,    -1,    -1,    -1,   223,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      79,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    94,    95,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
      -1,   120,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
      -1,   140,   141,    -1,    -1,   144,    -1,   146,   147,    -1,
      -1,   150,   151,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,    -1,   165,   166,   167,    -1,
     169,    -1,   171,    -1,    -1,   174,   175,    -1,    -1,    -1,
     179,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
       4,    -1,    -1,   202,   203,   204,   205,    11,    12,    -1,
      -1,   210,   211,    -1,    -1,    19,    20,    21,    -1,    23,
      -1,    -1,    26,    -1,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    79,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,    -1,   120,    -1,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,    -1,
     144,    -1,   146,   147,    -1,    -1,   150,   151,    -1,   153,
      -1,   155,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,   165,   166,   167,    -1,   169,    -1,   171,    -1,    -1,
     174,   175,    -1,    -1,    -1,   179,    -1,    -1,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,     4,    -1,
      -1,   195,    -1,    -1,    -1,    11,    12,    -1,   202,   203,
     204,   205,    -1,    19,    20,    21,   210,    23,    -1,    -1,
      26,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    79,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    95,
      -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,   120,    -1,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   141,    -1,    -1,   144,    -1,
     146,   147,    -1,    -1,   150,   151,    -1,   153,    -1,   155,
      -1,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,   165,
     166,   167,    -1,   169,    -1,   171,    -1,    -1,   174,   175,
      -1,    -1,    -1,   179,    -1,    -1,   182,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,    -1,     4,    -1,    -1,   195,
      -1,    -1,    -1,    11,    12,    -1,   202,   203,   204,   205,
      -1,    19,    20,    21,   210,    23,    -1,    -1,    26,    -1,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    -1,    -1,    73,    74,    75,    76,    77,
      -1,    79,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    94,    95,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,    -1,   120,    -1,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,   140,   141,    -1,    -1,   144,    -1,   146,   147,
      -1,    -1,   150,   151,    -1,   153,    -1,    -1,    -1,    -1,
     158,    -1,    -1,   161,   162,   163,    -1,   165,   166,   167,
      -1,   169,    -1,   171,    -1,    -1,   174,   175,    -1,    -1,
      -1,   179,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,    -1,     4,    -1,    -1,   195,    -1,    -1,
      -1,    11,    12,    -1,   202,   203,   204,   205,    -1,    19,
      20,    21,   210,    23,    -1,    -1,    26,    -1,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    -1,    -1,    73,    74,    75,    76,    77,    -1,    79,
      -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    94,    95,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
     120,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
     140,   141,    -1,    -1,   144,    -1,   146,   147,    -1,    -1,
     150,   151,    -1,   153,    -1,    -1,    -1,    -1,   158,    -1,
      -1,   161,   162,   163,    -1,   165,   166,   167,    -1,   169,
      -1,   171,    -1,    -1,   174,   175,    -1,    -1,    -1,   179,
      -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,    -1,     4,    -1,    -1,   195,    -1,    -1,    -1,    11,
      12,    -1,   202,   203,   204,   205,    -1,    19,    20,    21,
     210,    23,    -1,    -1,    26,    -1,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,
      -1,    73,    74,    75,    76,    77,    -1,    79,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,    -1,   120,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   141,
      -1,    -1,   144,    -1,   146,   147,    -1,    -1,   150,   151,
      -1,   153,    -1,   155,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,    -1,   165,   166,   167,    -1,   169,    -1,   171,
      -1,    -1,   174,   175,    -1,    -1,    -1,   179,    -1,    -1,
     182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,
       4,    -1,    -1,   195,    -1,    -1,    -1,    11,    12,    -1,
     202,   203,   204,   205,    -1,    19,    20,    21,   210,    23,
      -1,    -1,    26,    -1,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    79,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,    -1,   120,    -1,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,    -1,
     144,    -1,   146,   147,    -1,    -1,   150,   151,    -1,   153,
      -1,   155,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,   165,   166,   167,    -1,   169,    -1,   171,    -1,    -1,
     174,   175,    -1,    -1,    -1,   179,    -1,    -1,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,     4,    -1,
      -1,   195,    -1,    -1,    -1,    11,    12,    -1,   202,   203,
     204,   205,    -1,    19,    20,    21,   210,    23,    -1,    -1,
      26,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    79,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    95,
      -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,   120,    -1,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   141,    -1,    -1,   144,    -1,
     146,   147,    -1,    -1,   150,   151,    -1,   153,    -1,   155,
      -1,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,   165,
     166,   167,    -1,   169,    -1,   171,    -1,    -1,   174,   175,
      -1,    -1,    -1,   179,    -1,    -1,   182,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,    -1,     4,    -1,    -1,   195,
      -1,    -1,    -1,    11,    12,    -1,   202,   203,   204,   205,
      -1,    19,    20,    21,   210,    23,    -1,    -1,    26,    -1,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    -1,    -1,    73,    74,    75,    76,    77,
      -1,    79,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    94,    95,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,    -1,   120,    -1,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,   140,   141,    -1,    -1,   144,    -1,   146,   147,
      -1,    -1,   150,   151,    -1,   153,    -1,   155,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,    -1,   165,   166,   167,
      -1,   169,    -1,   171,    -1,    -1,   174,   175,    -1,    -1,
      -1,   179,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,    -1,     4,    -1,    -1,   195,    -1,    -1,
      -1,    11,    12,    -1,   202,   203,   204,   205,    -1,    19,
      20,    21,   210,    23,    -1,    -1,    26,    -1,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    -1,    -1,    73,    74,    75,    76,    77,    -1,    79,
      -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    94,    95,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
     120,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
     140,   141,    -1,    -1,   144,    -1,   146,   147,    -1,    -1,
     150,   151,    -1,   153,    -1,   155,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,   165,   166,   167,    -1,   169,
      -1,   171,    -1,    -1,   174,   175,    -1,    -1,    -1,   179,
      -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,    -1,     4,    -1,    -1,   195,    -1,    -1,    -1,    11,
      12,    -1,   202,   203,   204,   205,    -1,    19,    20,    21,
     210,    23,    -1,    -1,    26,    -1,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,
      -1,    73,    74,    75,    76,    77,    -1,    79,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,    -1,   120,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   141,
      -1,    -1,   144,    -1,   146,   147,    -1,    -1,   150,   151,
      -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,    -1,   165,   166,   167,    -1,   169,    -1,   171,
      -1,    -1,   174,   175,    -1,    -1,    -1,   179,    -1,    -1,
     182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,
       4,    -1,    -1,   195,    -1,    -1,    -1,    11,    12,    -1,
     202,   203,   204,   205,    -1,    19,    20,    21,   210,    23,
      -1,    -1,    26,    -1,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    79,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    -1,   120,    -1,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,    -1,
     144,    -1,   146,   147,    -1,    -1,   150,   151,    -1,   153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,   165,   166,    -1,    -1,   169,    -1,   171,     4,    -1,
     174,   175,    -1,    -1,    -1,    11,    12,    -1,   182,    -1,
      -1,    -1,    -1,    19,    20,    21,   190,    23,    -1,    -1,
      26,   195,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    79,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,   117,    -1,    -1,   120,    -1,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   141,    -1,    -1,   144,    -1,
     146,   147,    -1,    -1,   150,   151,    -1,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,   165,
     166,    -1,    -1,   169,    -1,   171,    -1,    -1,   174,   175,
     217,    -1,    -1,   220,   221,   222,   182,   224,   225,   226,
     227,   228,    -1,    -1,   190,    -1,    -1,    -1,   235,   195,
     237,    -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,   248,   249,   250,    -1,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,   101,
      -1,   221,   222,    -1,   224,   225,    -1,    -1,    -1,    -1,
     112,    -1,    -1,    -1,   116,   235,    -1,   237,    -1,   121,
      -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,   248,    -1,
      -1,    -1,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,    -1,    -1,    -1,   149,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   185,   186,   187,   188,   189
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,     4,    11,    12,    19,    20,    21,    23,    26,    28,
      29,    36,    37,    38,    39,    45,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    69,    70,    73,    74,    75,    76,    77,
      79,    81,    82,    91,    94,    95,    97,   104,   105,   106,
     110,   117,   118,   120,   122,   124,   129,   138,   140,   141,
     144,   146,   147,   150,   151,   153,   161,   162,   163,   165,
     166,   167,   169,   171,   174,   175,   179,   182,   190,   195,
     197,   201,   202,   203,   204,   205,   210,   223,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   300,   301,   302,   303,   307,   308,   309,   310,   311,
     312,   313,   318,   329,   332,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   384,   385,
     386,   399,   400,   402,   403,   404,   405,   406,   407,   408,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     427,   428,   429,   430,   431,   432,   433,   155,   308,   155,
     308,   158,   309,   383,   114,   308,    20,   158,   169,   368,
     308,   158,    24,   152,   172,   152,   172,   132,   152,    24,
     125,   125,    84,    85,    21,    15,    20,   137,   181,    21,
      25,   308,   158,   423,   424,    25,   308,    20,   158,   169,
      25,   330,   331,    25,   314,   315,   308,    24,   125,    24,
      68,   125,   299,    25,   319,   320,   158,   308,    15,   158,
     308,    17,    15,    23,   158,    20,    15,   114,    20,    20,
     360,   360,   330,    20,   308,   158,   308,   308,   308,    27,
     196,    23,   309,   309,   309,   211,   309,    25,   434,   221,
     222,   224,   225,   235,   237,   248,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   446,   447,   448,
     449,   450,   453,   458,   459,     0,   277,   278,   280,   307,
     164,   164,    47,   139,   157,   168,   194,   312,   321,   322,
     136,    30,    88,    96,    99,   101,   112,   116,   121,   127,
     149,   184,   185,   186,   187,   188,   189,   352,   353,   354,
     232,   122,   146,   177,    72,   103,   123,   169,   180,   192,
      92,   111,   109,   178,    41,    42,   122,   146,   351,   114,
     358,   165,   166,   115,   372,   373,   368,   372,   368,   372,
     155,   155,    47,   158,   308,   155,    47,   158,    47,   158,
     155,    47,    47,    24,    24,    75,   158,   159,   304,   305,
      88,    23,   158,   159,   304,    32,    93,   100,   410,   155,
     158,   158,   155,    47,   158,    47,   158,   107,   410,    47,
     160,    34,   107,   244,   316,   317,   410,    47,   158,    34,
      15,    34,   125,    15,    24,   100,   317,   410,    47,   158,
      88,   155,     8,   142,   158,   158,    18,   114,   308,   158,
     158,   160,    20,    86,   173,   388,   389,   155,   158,   155,
     155,   196,    87,   164,    32,   198,   199,   207,    32,   309,
     212,   100,   200,   209,    23,    92,   180,   454,   457,    34,
     120,   455,    34,    67,   120,   452,   282,   283,   284,   309,
     309,   323,   324,   309,   323,   309,   157,   322,   157,   337,
     338,   339,   339,   339,   114,   120,   233,   375,   435,   437,
     438,   439,   440,   441,   442,   443,   342,   342,   341,   343,
     343,   343,   343,   344,   344,   345,   345,    20,   113,   193,
     411,   413,   414,   415,   411,   409,   414,   409,   155,   308,
     360,   360,   308,   373,   309,   155,   114,    20,   425,   425,
     108,   131,   108,   131,    25,    93,   114,   306,   411,    47,
     158,   159,    24,    93,   306,   411,   158,   159,   411,   309,
      93,   100,   114,    20,   425,   426,   425,   426,   309,   107,
      75,   309,    75,   309,    75,   107,   317,   107,   107,   316,
     317,    75,   176,    24,   298,    88,   298,    88,    34,   309,
     100,   100,   317,    75,    24,   155,   308,   155,   309,    88,
       9,    10,    13,    43,    78,    80,   170,   306,   385,   387,
     397,   398,   401,    86,   173,   389,    40,   333,   334,    23,
     206,   208,   309,   309,   309,   309,   212,   309,   309,    25,
     309,   455,   455,   457,    23,    23,   456,   454,    23,    67,
     452,   164,    33,    46,    71,    84,    85,   325,   326,   327,
     328,    47,   309,   157,   309,   308,   435,   441,   251,   469,
     137,   217,   220,   226,   227,   228,   234,   243,   249,   250,
     436,   444,   445,   446,   460,   463,   464,   466,   231,   238,
     239,   465,   213,   214,   215,   216,   241,   461,   133,   134,
     135,   412,   102,   155,   156,   155,   308,   158,   158,   410,
     308,    93,   306,   305,    93,   306,   411,    93,   306,    93,
     306,   411,   309,   155,   308,   102,   158,   158,   158,   158,
     309,   331,    25,    25,   309,   107,   309,   309,   107,   317,
     107,   315,   309,    47,    24,   298,   309,   309,   100,   320,
     164,   155,   114,    31,   154,   390,     7,    20,   170,   397,
     170,   387,    75,   411,    67,   334,   164,   309,   309,   309,
     100,   157,    23,   158,   218,   219,   229,   230,   242,   462,
      47,   158,    47,   158,    24,   327,   328,   328,   324,   309,
     155,   158,   343,   240,   245,   468,   462,   438,   468,   340,
     343,   249,   444,   446,   439,   440,   462,   155,   155,    93,
     306,    93,   306,   155,   309,   309,   107,   309,    83,    24,
      34,   309,   155,   308,     3,    89,   393,   394,   396,   398,
      22,    90,   391,   392,   395,   398,   173,    20,    20,   170,
      25,   157,    75,   157,   309,   309,   343,   343,   343,   343,
      23,   236,   451,   452,   451,   328,   240,   246,   263,   467,
     467,   340,   247,   309,   309,   298,   155,    31,    89,   396,
     154,    90,   395,   173,   173,    20,    32,   309,    25,   309,
     177,   462,    47,   158,   158,   173,   411,   157,   343,   236,
     452,   157,   309,   309
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
     357,   358,   359,   359,   359,   359,   360,   360,   360,   361,
     361,   362,   362,   362,   362,   363,   363,   364,   364,   364,
     364,   364,   364,   364,   365,   365,   366,   366,   367,   367,
     367,   367,   367,   368,   368,   369,   369,   370,   370,   370,
     371,   371,   372,   372,   373,   374,   374,   374,   374,   374,
     374,   374,   374,   375,   375,   376,   376,   376,   377,   378,
     378,   379,   380,   381,   382,   382,   383,   383,   384,   384,
     385,   385,   385,   386,   386,   386,   386,   386,   386,   387,
     387,   388,   388,   389,   390,   390,   391,   391,   392,   392,
     392,   392,   393,   393,   394,   394,   394,   394,   395,   395,
     396,   396,   397,   397,   397,   397,   398,   398,   398,   398,
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
  "\"'char literal and pi end'\"", "\"'#charref;'\"",
  "\"'element content'\"", "\"'<QName {>'\"", "\"'pref:*'\"",
  "\"'&entity;'\"", "\"'comment literal'\"", "\"'NCName'\"",
  "\"'pi <NCName {>'\"", "\"'pi target'\"", "\"'pragma literal and end'\"",
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
       275,     0,    -1,   277,    -1,   276,   277,    -1,   278,    -1,
     276,   278,    -1,   197,    23,   164,    -1,   197,    23,    87,
      23,   164,    -1,   280,   307,    -1,   307,    -1,   279,   280,
      -1,   124,    15,    88,    24,   164,    -1,   281,   164,    -1,
     282,   164,    -1,   281,   164,   282,   164,    -1,   283,    -1,
     281,   164,   283,    -1,   284,    -1,   282,   164,   284,    -1,
     285,    -1,   286,    -1,   287,    -1,   289,    -1,   301,    -1,
     303,    -1,   290,    -1,   291,    -1,   288,    -1,   295,    -1,
     296,    -1,   302,    -1,   292,    -1,   293,    -1,   294,    -1,
     428,    -1,   297,    -1,   300,    -1,    62,    15,    88,    24,
      -1,    54,   152,    -1,    54,   172,    -1,    58,   125,    24,
      -1,    59,   125,    24,    -1,    63,    20,    23,    -1,   223,
     446,    -1,    64,   137,    -1,    64,   181,    -1,    60,    84,
      -1,    60,    85,    -1,    56,   152,    47,   108,    -1,    56,
     152,    47,   131,    -1,    56,   132,    47,   108,    -1,    56,
     132,    47,   131,    -1,    57,    24,    -1,    53,    24,    -1,
     106,    24,    -1,   106,   299,    24,    -1,   106,    24,    34,
     298,    -1,   106,   299,    24,    34,   298,    -1,    24,    -1,
     298,    47,    24,    -1,   125,    15,    88,    -1,    68,   125,
      -1,   105,    24,    -1,   105,   125,    15,    88,    24,    -1,
     105,    24,    34,   298,    -1,   105,   125,    15,    88,    24,
      34,   298,    -1,    66,    25,   100,   309,    -1,    66,    25,
      93,    -1,    66,    25,   410,   100,   309,    -1,    66,    25,
     410,    93,    -1,    55,   152,    -1,    55,   172,    -1,    61,
      21,   158,    93,    -1,    61,    21,   158,   306,    -1,    61,
      21,   304,   158,    93,    -1,    61,    21,   304,   158,   306,
      -1,    61,    21,   159,   411,    93,    -1,    61,    21,   159,
     411,   306,    -1,    61,    21,   304,   159,   411,    93,    -1,
      61,    21,   304,   159,   411,   306,    -1,    65,    21,   158,
      93,    -1,    65,    21,   158,   306,    -1,    65,    21,   304,
     158,    93,    -1,    65,    21,   304,   158,   306,    -1,    65,
      21,   159,   411,    93,    -1,    65,    21,   159,   411,   306,
      -1,    65,    21,   304,   159,   411,    93,    -1,    65,    21,
     304,   159,   411,   306,    -1,   305,    -1,   304,    47,   305,
      -1,    75,    25,    -1,    75,    25,   410,    -1,   114,   308,
     155,    -1,   308,    -1,   309,    -1,   308,    47,   309,    -1,
     310,    -1,   329,    -1,   332,    -1,   335,    -1,   336,    -1,
     429,    -1,   430,    -1,   432,    -1,   431,    -1,   433,    -1,
     311,   157,   309,    -1,   311,   321,   157,   309,    -1,   311,
     322,   157,   309,    -1,   311,   321,   322,   157,   309,    -1,
     312,    -1,   311,   312,    -1,   313,    -1,   318,    -1,    97,
     314,    -1,   315,    -1,   314,    47,    75,   315,    -1,    25,
     107,   309,    -1,    25,   410,   107,   309,    -1,    25,   316,
     107,   309,    -1,    25,   410,   316,   107,   309,    -1,    25,
     317,   107,   309,    -1,    25,   410,   317,   107,   309,    -1,
      25,   316,   317,   107,   309,    -1,    25,   410,   316,   317,
     107,   309,    -1,    34,    75,    25,    -1,   244,    75,    25,
      -1,   118,   319,    -1,   320,    -1,   319,    47,    75,   320,
      -1,    25,   100,   309,    -1,    25,   410,   100,   309,    -1,
      25,   317,   100,   309,    -1,    25,   410,   317,   100,   309,
      -1,   194,   309,    -1,   139,   323,    -1,   168,   323,    -1,
     324,    -1,   323,    47,   324,    -1,   309,    -1,   309,   325,
      -1,   326,    -1,   327,    -1,   328,    -1,   326,   327,    -1,
     326,   328,    -1,   327,   328,    -1,   326,   327,   328,    -1,
      33,    -1,    71,    -1,    84,    -1,    85,    -1,    46,    24,
      -1,   167,   330,   160,   309,    -1,    91,   330,   160,   309,
      -1,   331,    -1,   330,    47,    75,   331,    -1,    25,   107,
     309,    -1,    25,   410,   107,   309,    -1,   179,   308,   158,
     333,    67,   157,   309,    -1,   179,   308,   158,   333,    67,
      75,    25,   157,   309,    -1,   334,    -1,   333,   334,    -1,
      40,   411,   157,   309,    -1,    40,    75,    25,    32,   411,
     157,   309,    -1,   104,   308,   158,   176,   309,    83,   309,
      -1,   337,    -1,   336,   136,   337,    -1,   338,    -1,   337,
      30,   338,    -1,   339,    -1,   339,   353,   339,    -1,   339,
     352,   339,    -1,   339,   354,   339,    -1,   340,    -1,   340,
     232,   435,    -1,   340,   232,   435,   469,    -1,   341,    -1,
     341,   177,   341,    -1,   342,    -1,   341,   146,   342,    -1,
     341,   122,   342,    -1,   343,    -1,   342,   169,   343,    -1,
     342,    72,   343,    -1,   342,   103,   343,    -1,   342,   123,
     343,    -1,   344,    -1,   343,   180,   344,    -1,   343,   192,
     344,    -1,   345,    -1,   344,   111,   345,    -1,   344,    92,
     345,    -1,   346,    -1,   346,   109,   411,    -1,   347,    -1,
     347,   178,   411,    -1,   348,    -1,   348,    41,   409,    -1,
     349,    -1,   349,    42,   409,    -1,   351,    -1,   350,   351,
      -1,   146,    -1,   122,    -1,   350,   146,    -1,   350,   122,
      -1,   355,    -1,   359,    -1,   356,    -1,    88,    -1,   127,
      -1,   121,    -1,   116,    -1,   101,    -1,    99,    -1,   184,
      -1,   189,    -1,   188,    -1,   187,    -1,   186,    -1,   185,
      -1,   112,    -1,   149,    -1,    96,    -1,   190,   308,   155,
      -1,    26,   114,   308,   155,    -1,   357,   114,   155,    -1,
     357,   114,   308,   155,    -1,   358,    -1,   357,   358,    -1,
     147,    20,    18,    -1,   117,    -1,   165,   360,    -1,   166,
     360,    -1,   360,    -1,   361,    -1,   361,   165,   360,    -1,
     361,   166,   360,    -1,   362,    -1,   371,    -1,   363,    -1,
     363,   372,    -1,   366,    -1,   366,   372,    -1,   364,   368,
      -1,   365,    -1,    45,    -1,    69,    -1,    36,    -1,   163,
      -1,    70,    -1,    95,    -1,    94,    -1,   368,    -1,    39,
     368,    -1,   367,   368,    -1,    77,    -1,   140,    -1,    28,
      -1,   151,    -1,   150,    -1,    29,    -1,   415,    -1,   369,
      -1,    20,    -1,   370,    -1,   169,    -1,    12,    -1,    19,
      -1,   374,    -1,   374,   372,    -1,   373,    -1,   372,   373,
      -1,   115,   308,   156,    -1,   375,    -1,   377,    -1,   378,
      -1,   379,    -1,   382,    -1,   384,    -1,   380,    -1,   381,
      -1,   376,    -1,   427,    -1,    52,    -1,   110,    -1,    79,
      -1,    75,    25,    -1,   120,   158,    -1,   120,   308,   158,
      -1,    76,    -1,   138,   308,   155,    -1,   182,   308,   155,
      -1,    21,   158,    -1,    21,   383,   158,    -1,   309,    -1,
     383,    47,   309,    -1,   385,    -1,   402,    -1,   386,    -1,
     399,    -1,   400,    -1,   171,    20,    86,    -1,   171,    20,
     388,    86,    -1,   171,    20,   173,   170,    20,   173,    -1,
     171,    20,   173,   387,   170,    20,   173,    -1,   171,    20,
     388,   173,   170,    20,   173,    -1,   171,    20,   388,   173,
     387,   170,    20,   173,    -1,   397,    -1,   387,   397,    -1,
     389,    -1,   388,   389,    -1,    20,    88,   390,    -1,   154,
     391,   154,    -1,    31,   393,    31,    -1,    -1,   392,    -1,
      90,    -1,   395,    -1,   392,    90,    -1,   392,   395,    -1,
      -1,   394,    -1,    89,    -1,   396,    -1,   394,    89,    -1,
     394,   396,    -1,    22,    -1,   398,    -1,     3,    -1,   398,
      -1,   385,    -1,    10,    -1,   401,    -1,   398,    -1,    13,
      -1,     9,    -1,    78,    -1,    80,    -1,   306,    -1,   195,
      27,   196,    -1,   195,   196,    -1,   141,    17,   142,    -1,
     141,    17,     8,    -1,    43,     7,    -1,   403,    -1,   404,
      -1,   405,    -1,   406,    -1,   407,    -1,   408,    -1,    73,
     308,   155,    -1,    11,   155,    -1,    11,   308,   155,    -1,
      81,   308,   155,   114,   155,    -1,    81,   308,   155,   114,
     308,   155,    -1,     4,   155,    -1,     4,   308,   155,    -1,
      37,   308,   155,   114,   155,    -1,    37,   308,   155,   114,
     308,   155,    -1,   174,   308,   155,    -1,    50,   308,   155,
      -1,   153,    15,   114,   155,    -1,   153,    15,   114,   308,
     155,    -1,   153,   114,   308,   155,   114,   155,    -1,   153,
     114,   308,   155,   114,   308,   155,    -1,   414,    -1,   414,
     102,    -1,    32,   411,    -1,   413,    -1,   413,   412,    -1,
     193,    -1,   133,    -1,   135,    -1,   134,    -1,   414,    -1,
     415,    -1,   113,    -1,    20,    -1,   417,    -1,   423,    -1,
     421,    -1,   424,    -1,   422,    -1,   420,    -1,   419,    -1,
     418,    -1,   416,    -1,   129,   158,    -1,    74,   158,    -1,
      74,   423,   158,    -1,    74,   424,   158,    -1,   175,   158,
      -1,    51,   158,    -1,   144,   158,    -1,   144,    15,   158,
      -1,   144,    23,   158,    -1,    38,   158,    -1,    38,    20,
     158,    -1,    38,    20,    47,   425,   158,    -1,    38,   169,
     158,    -1,    38,   169,    47,   425,   158,    -1,   161,    20,
     158,    -1,    82,   158,    -1,    82,    20,   158,    -1,    82,
      20,    47,   425,   158,    -1,    82,    20,    47,   426,   158,
      -1,    82,   169,   158,    -1,    82,   169,    47,   425,   158,
      -1,    82,   169,    47,   426,   158,    -1,   162,    20,   158,
      -1,    20,    -1,    20,   102,    -1,    23,    -1,   201,    -1,
     203,   309,   207,   309,    -1,   203,   309,    32,   206,   309,
      -1,   203,   309,    32,   208,   309,    -1,   203,   309,   198,
     309,    -1,   203,   309,   199,   309,    -1,   202,   309,    -1,
     205,   309,   212,   309,    -1,   205,   211,   309,   212,   309,
      -1,   204,   309,    32,   309,    -1,   210,   434,   209,   309,
     157,   309,    -1,    25,   100,   309,    -1,   434,   200,    25,
     100,   309,    -1,   437,    -1,   437,   436,    -1,   437,   249,
     340,    -1,   437,   436,   249,   340,    -1,   446,    -1,   444,
      -1,   436,   446,    -1,   436,   444,    -1,   438,    -1,   437,
     234,   438,    -1,   439,    -1,   438,   231,   439,    -1,   440,
      -1,   439,   238,   440,    -1,   441,    -1,   233,   441,    -1,
     442,    -1,   442,   465,    -1,   120,   435,   158,    -1,   443,
      -1,   443,   461,    -1,   375,    -1,   114,   308,   155,    -1,
     445,    -1,   464,    -1,   463,    -1,   466,    -1,   460,    -1,
     137,    -1,   447,    -1,   448,    -1,   449,    -1,   450,    -1,
     453,    -1,   458,    -1,   459,    -1,   237,    -1,   248,    -1,
     222,    -1,   221,    -1,   258,    -1,   252,    -1,   225,    -1,
     224,    -1,   259,    -1,   253,    -1,   261,   452,    -1,   261,
      67,    -1,   261,   120,   452,   158,    -1,   261,   120,   452,
      47,   451,   158,    -1,   261,   120,    67,   158,    -1,   261,
     120,    67,    47,   451,   158,    -1,   255,    -1,   452,    -1,
     451,    47,   452,    -1,    34,    23,    -1,    34,    23,   242,
      23,    -1,    34,    23,   462,   236,    -1,    34,    23,   242,
      23,   462,   236,    -1,   260,   455,    -1,   260,   455,   454,
      -1,   257,    -1,   257,   454,    -1,   254,    -1,   457,    -1,
     454,   457,    -1,    34,    23,    -1,   120,   456,   158,    -1,
      23,    -1,   456,    23,    -1,   180,   455,    -1,    92,   455,
      -1,   235,    23,    -1,   262,    -1,   256,    -1,   220,    -1,
     217,    -1,   228,    -1,   215,    -1,   216,    -1,   213,    -1,
     214,    -1,   241,    -1,   229,   343,    -1,   218,   343,    -1,
     219,   343,    -1,   230,   343,   177,   343,    -1,   227,   462,
     467,    -1,   250,   343,   467,    -1,   239,   462,   247,    -1,
     243,   468,    -1,   226,   468,    -1,   263,    -1,   246,    -1,
     240,    -1,   245,    -1,   240,    -1,   251,   343,    -1
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
    1097,  1099,  1103,  1106,  1110,  1114,  1117,  1119,  1121,  1123,
    1125,  1127,  1129,  1133,  1136,  1140,  1146,  1153,  1156,  1160,
    1166,  1173,  1177,  1181,  1186,  1192,  1199,  1207,  1209,  1212,
    1215,  1217,  1220,  1222,  1224,  1226,  1228,  1230,  1232,  1234,
    1236,  1238,  1240,  1242,  1244,  1246,  1248,  1250,  1252,  1254,
    1257,  1260,  1264,  1268,  1271,  1274,  1277,  1281,  1285,  1288,
    1292,  1298,  1302,  1308,  1312,  1315,  1319,  1325,  1331,  1335,
    1341,  1347,  1351,  1353,  1356,  1358,  1360,  1365,  1371,  1377,
    1382,  1387,  1390,  1395,  1401,  1406,  1413,  1417,  1423,  1425,
    1428,  1432,  1437,  1439,  1441,  1444,  1447,  1449,  1453,  1455,
    1459,  1461,  1465,  1467,  1470,  1472,  1475,  1479,  1481,  1484,
    1486,  1490,  1492,  1494,  1496,  1498,  1500,  1502,  1504,  1506,
    1508,  1510,  1512,  1514,  1516,  1518,  1520,  1522,  1524,  1526,
    1528,  1530,  1532,  1534,  1536,  1539,  1542,  1547,  1554,  1559,
    1566,  1568,  1570,  1574,  1577,  1582,  1587,  1594,  1597,  1601,
    1603,  1606,  1608,  1610,  1613,  1616,  1620,  1622,  1625,  1628,
    1631,  1634,  1636,  1638,  1640,  1642,  1644,  1646,  1648,  1650,
    1652,  1654,  1657,  1660,  1663,  1668,  1672,  1676,  1680,  1683,
    1686,  1688,  1690,  1692,  1694,  1696
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   732,   732,   740,   748,   754,   766,   772,   784,   794,
     809,   824,   839,   848,   857,   872,   881,   898,   907,   924,
     931,   938,   945,   957,   964,   971,   980,   993,  1000,  1007,
    1014,  1021,  1028,  1035,  1044,  1057,  1064,  1082,  1097,  1105,
    1119,  1128,  1143,  1159,  1173,  1181,  1196,  1204,  1218,  1227,
    1236,  1245,  1267,  1281,  1295,  1305,  1315,  1325,  1341,  1350,
    1368,  1375,  1388,  1397,  1407,  1416,  1433,  1443,  1453,  1463,
    1479,  1487,  1501,  1511,  1522,  1533,  1545,  1557,  1569,  1581,
    1593,  1603,  1614,  1625,  1637,  1649,  1661,  1673,  1691,  1702,
    1719,  1728,  1743,  1757,  1771,  1780,  1795,  1802,  1809,  1816,
    1823,  1832,  1839,  1846,  1853,  1860,  1873,  1883,  1894,  1905,
    1922,  1931,  1946,  1953,  1966,  1980,  1989,  2006,  2016,  2027,
    2039,  2052,  2063,  2075,  2087,  2105,  2120,  2134,  2149,  2158,
    2175,  2186,  2198,  2209,  2227,  2241,  2249,  2264,  2273,  2290,
    2299,  2314,  2324,  2334,  2344,  2354,  2364,  2374,  2390,  2397,
    2410,  2418,  2432,  2446,  2456,  2472,  2482,  2497,  2506,  2522,
    2532,  2549,  2558,  2573,  2582,  2598,  2612,  2619,  2633,  2640,
    2662,  2669,  2680,  2691,  2708,  2715,  2725,  2741,  2748,  2762,
    2769,  2776,  2789,  2795,  2802,  2809,  2816,  2829,  2836,  2844,
    2858,  2865,  2872,  2885,  2892,  2907,  2914,  2929,  2936,  2951,
    2958,  2973,  2980,  2995,  3002,  3009,  3016,  3031,  3038,  3045,
    3059,  3066,  3073,  3080,  3087,  3094,  3107,  3114,  3121,  3128,
    3135,  3142,  3155,  3162,  3169,  3183,  3190,  3205,  3214,  3229,
    3238,  3255,  3301,  3308,  3315,  3322,  3336,  3344,  3351,  3364,
    3371,  3384,  3393,  3402,  3411,  3426,  3435,  3449,  3456,  3463,
    3470,  3477,  3484,  3491,  3504,  3511,  3524,  3533,  3548,  3555,
    3562,  3569,  3576,  3594,  3601,  3614,  3621,  3634,  3644,  3654,
    3670,  3677,  3692,  3701,  3718,  3732,  3739,  3746,  3753,  3760,
    3767,  3774,  3781,  3794,  3801,  3814,  3821,  3828,  3841,  3854,
    3861,  3875,  3888,  3902,  3961,  3970,  3985,  3994,  4009,  4016,
    4029,  4036,  4043,  4056,  4067,  4078,  4089,  4100,  4111,  4129,
    4138,  4153,  4162,  4179,  4194,  4202,  4217,  4223,  4230,  4239,
    4248,  4259,  4276,  4282,  4289,  4298,  4307,  4318,  4335,  4343,
    4357,  4365,  4379,  4387,  4395,  4404,  4419,  4428,  4437,  4445,
    4453,  4467,  4475,  4493,  4501,  4521,  4539,  4546,  4553,  4560,
    4567,  4574,  4587,  4601,  4610,  4619,  4627,  4655,  4664,  4673,
    4681,  4695,  4709,  4723,  4732,  4741,  4749,  4763,  4772,  4787,
    4801,  4810,  4819,  4859,  4867,  4875,  4889,  4896,  4903,  4916,
    4930,  4937,  4944,  4951,  4958,  4965,  4972,  4979,  4986,  4999,
    5012,  5019,  5027,  5041,  5054,  5067,  5074,  5081,  5094,  5103,
    5112,  5121,  5130,  5145,  5159,  5168,  5177,  5186,  5195,  5205,
    5215,  5231,  5255,  5265,  5288,  5330,  5342,  5348,  5354,  5360,
    5366,  5378,  5390,  5396,  5408,  5435,  5447,  5453,  5473,  5479,
    5485,  5491,  5503,  5509,  5515,  5521,  5533,  5539,  5551,  5557,
    5569,  5575,  5587,  5593,  5605,  5611,  5617,  5629,  5635,  5647,
    5653,  5665,  5671,  5677,  5683,  5689,  5701,  5713,  5720,  5727,
    5734,  5741,  5748,  5755,  5768,  5774,  5780,  5786,  5798,  5804,
    5810,  5816,  5828,  5834,  5846,  5852,  5858,  5864,  5870,  5876,
    5882,  5894,  5900,  5912,  5918,  5924,  5930,  5942,  5948,  5954,
    5960,  5966,  5978,  5984,  5996,  6002,  6014,  6020,  6032,  6038,
    6050,  6062,  6068,  6080,  6086,  6092,  6104,  6110,  6116,  6122,
    6128,  6140,  6146,  6152,  6158,  6170,  6182,  6194,  6206,  6212,
    6224,  6230,  6236,  6248,  6254,  6266
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
  const int xquery_parser::yylast_ = 3737;
  const int xquery_parser::yynnts_ = 196;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 315;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 274;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 528;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace yy

#line 6276 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"



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





