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
#line 732 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [main]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr((yyval.node));
		;}
    break;

  case 3:
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr((yyval.node));
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.main]\n";
#endif
		;}
    break;

  case 4:
#line 748 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [library]\n";
#endif
		;}
    break;

  case 5:
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.library]\n";
#endif
		;}
    break;

  case 6:
#line 766 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version]\n";
#endif
		;}
    break;

  case 7:
#line 772 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version.encoding]\n";
#endif
		;}
    break;

  case 8:
#line 784 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 794 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 824 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 839 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 848 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 857 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 872 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 881 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 898 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 924 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [setter]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 931 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [import]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 938 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [namespace]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 945 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [default namespace]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 957 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [var]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 964 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [function]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 971 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [option]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 980 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [ftoption]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 993 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [boundary space]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 1000 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [default collation]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 1007 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [base uri]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 1014 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [construction]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 1021 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [ordering mode]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 1028 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [empty order]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 1035 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [copy namespaces]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 1044 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [revalidation]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 1057 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [schema]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 1064 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [module]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 1082 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1097 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [preserve]\n";
#endif
			(yyval.node) = new BoundarySpaceDecl((yyloc),
								StaticQueryContext::preserve_space);
		;}
    break;

  case 39:
#line 1105 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [strip]\n";
#endif
			(yyval.node) = new BoundarySpaceDecl((yyloc),
								StaticQueryContext::strip_space);
		;}
    break;

  case 40:
#line 1119 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1128 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1143 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1159 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOptionDecl [ ]\n";
#endif
			(yyval.node) = new FTOptionDecl((yyloc),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 44:
#line 1173 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [ordered]\n";
#endif
			(yyval.node) = new OrderingModeDecl((yyloc),
								StaticQueryContext::ordered);
		;}
    break;

  case 45:
#line 1181 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [unordered]\n";
#endif
			(yyval.node) = new OrderingModeDecl((yyloc),
								StaticQueryContext::unordered);
		;}
    break;

  case 46:
#line 1196 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty greatest]\n";
#endif
			(yyval.node) = new EmptyOrderDecl((yyloc),
								StaticQueryContext::empty_greatest);
		;}
    break;

  case 47:
#line 1204 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty least]\n";
#endif
			(yyval.node) = new EmptyOrderDecl((yyloc),
								StaticQueryContext::empty_least);
		;}
    break;

  case 48:
#line 1218 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1227 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1236 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1245 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1267 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultCollationMode [ ]\n";
#endif
			(yyval.node) = new DefaultCollationDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 53:
#line 1281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BaseURIDecl [ ]\n";
#endif
			(yyval.node) = new BaseURIDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 54:
#line 1295 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1305 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1315 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1325 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1350 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1368 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [namespace]\n";
#endif
			(yyval.node) = new SchemaPrefix((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1375 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [default element]\n";
#endif
			(yyval.node) = new SchemaPrefix((yyloc), true);
		;}
    break;

  case 62:
#line 1388 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1397 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1407 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1416 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1433 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1443 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1453 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1463 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1479 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [preserve]\n";
#endif
			(yyval.node) = new ConstructionDecl((yyloc),
								StaticQueryContext::cons_preserve);
		;}
    break;

  case 71:
#line 1487 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [strip]\n";
#endif
			(yyval.node) = new ConstructionDecl((yyloc),
								StaticQueryContext::cons_strip);
		;}
    break;

  case 72:
#line 1501 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1511 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1522 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1533 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1545 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1557 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1569 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1581 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1593 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1603 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1614 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1625 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1637 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1649 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1661 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1673 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1691 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1702 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1719 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1728 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1743 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EnclosedExpr [ ]\n";
#endif
			(yyval.expr) = new EnclosedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1757 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QueryBody [expr]\n";
#endif
			(yyval.expr) = new QueryBody((yyloc),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 94:
#line 1771 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1780 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1795 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [FLWORExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 97:
#line 1802 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [QuantifiedExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TypeswitchExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1816 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [IfExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1823 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [OrExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1832 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [InsertExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1839 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [DeleteExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1846 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [RenameExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1853 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [ReplaceExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1860 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TransformExpr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1883 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1894 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1922 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1931 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1946 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [for]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 113:
#line 1953 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [let]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 114:
#line 1966 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForClause [ ]\n";
#endif
			(yyval.node) = new ForClause((yyloc),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 115:
#line 1980 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1989 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2006 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2016 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2027 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2039 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2052 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2063 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2075 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2087 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2105 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PositionalVar [ ]\n";
#endif
			(yyval.node) = new PositionalVar((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 126:
#line 2120 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTScoreVar [ ]\n";
#endif
			(yyval.node) = new FTScoreVar((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 127:
#line 2134 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClause [ ]\n";
#endif
			(yyval.node) = new LetClause((yyloc),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)));
			
		;}
    break;

  case 128:
#line 2149 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2158 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2175 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2198 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2227 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "WhereClause [ ]\n";
#endif
			(yyval.node) = new WhereClause((yyloc),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 135:
#line 2241 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [ ]\n";
#endif
			(yyval.node) = new OrderByClause((yyloc),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 136:
#line 2249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2264 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2273 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2290 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2299 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2314 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2324 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2334 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2354 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2364 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2374 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2390 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [ascending]\n";
#endif
			(yyval.node) = new OrderDirSpec((yyloc), dir_ascending);
		;}
    break;

  case 149:
#line 2397 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [descending]\n";
#endif
			(yyval.node) = new OrderDirSpec((yyloc), dir_descending);
		;}
    break;

  case 150:
#line 2410 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [greatest]\n";
#endif
			(yyval.node) = new OrderEmptySpec((yyloc),
								StaticQueryContext::empty_greatest);
		;}
    break;

  case 151:
#line 2418 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [least]\n";
#endif
			(yyval.node) = new OrderEmptySpec((yyloc),
								StaticQueryContext::empty_least);
		;}
    break;

  case 152:
#line 2432 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderCollationSpec [ ]\n";
#endif
			(yyval.node) = new OrderCollationSpec((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 153:
#line 2446 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2456 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2472 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2482 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2497 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2506 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2522 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2532 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2549 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2558 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2573 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2582 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2598 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IfExpr [ ]\n";
#endif
			(yyval.expr) = new IfExpr((yyloc),
								(yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 166:
#line 2612 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [and]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 167:
#line 2619 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [or.and]\n";
#endif
			(yyval.expr) = new OrExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 168:
#line 2633 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [comp]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 169:
#line 2640 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [and.comp]\n";
#endif
			(yyval.expr) = new AndExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 170:
#line 2662 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 171:
#line 2669 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2691 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2708 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 175:
#line 2715 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2725 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2741 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 178:
#line 2748 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add.to.add]\n";
#endif
			(yyval.expr) = new RangeExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 179:
#line 2762 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 180:
#line 2769 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult+mult]\n";
#endif
			(yyval.expr) = new AdditiveExpr((yyloc), op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 181:
#line 2776 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult-mult]\n";
#endif
			(yyval.expr) = new AdditiveExpr((yyloc), op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 182:
#line 2789 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [union]\n";
#endif
		;}
    break;

  case 183:
#line 2795 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult*union]\n";
#endif
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 184:
#line 2802 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.div.union]\n";
#endif
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 185:
#line 2809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.idiv.union]\n";
#endif
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 186:
#line 2816 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.mod.union]\n";
#endif
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 187:
#line 2829 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [interexcept]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 188:
#line 2836 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union.union.interexcept]\n";
#endif
			(yyval.expr) = new UnionExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 189:
#line 2844 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union|interexcept]\n";
#endif
			(yyval.expr) = new UnionExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 190:
#line 2858 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [instanceof]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 191:
#line 2865 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.inter.instanceof]\n";
#endif
			(yyval.expr) = new IntersectExceptExpr((yyloc), op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 192:
#line 2872 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.except.instanceof]\n";
#endif
			(yyval.expr) = new IntersectExceptExpr((yyloc), op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 193:
#line 2885 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 194:
#line 2892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 196:
#line 2914 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2929 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 198:
#line 2936 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2951 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 200:
#line 2958 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2973 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [value]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 202:
#line 2980 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2995 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [+]\n";
#endif
			(yyval.node) = new SignList((yyloc), true);
		;}
    break;

  case 204:
#line 3002 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [-]\n";
#endif
			(yyval.node) = new SignList((yyloc), false);
		;}
    break;

  case 205:
#line 3009 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.+]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 206:
#line 3016 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3031 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [validate]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 208:
#line 3038 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [path]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 209:
#line 3045 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [extension]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 210:
#line 3059 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [=]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_eq);
		;}
    break;

  case 211:
#line 3066 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [!=]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_ne);
		;}
    break;

  case 212:
#line 3073 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_lt);
		;}
    break;

  case 213:
#line 3080 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<=]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_le);
		;}
    break;

  case 214:
#line 3087 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_gt);
		;}
    break;

  case 215:
#line 3094 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>=]\n";
#endif
			(yyval.node) = new GeneralComp((yyloc), op_ge);
		;}
    break;

  case 216:
#line 3107 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [eq]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_eq);
		;}
    break;

  case 217:
#line 3114 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ne]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_ne);
		;}
    break;

  case 218:
#line 3121 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [lt]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_lt);
		;}
    break;

  case 219:
#line 3128 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [le]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_le);
		;}
    break;

  case 220:
#line 3135 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [gt]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_gt);
		;}
    break;

  case 221:
#line 3142 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ge]\n";
#endif
			(yyval.node) = new ValueComp((yyloc), op_val_ge);
		;}
    break;

  case 222:
#line 3155 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [is]\n";
#endif
			(yyval.node) = new NodeComp((yyloc), op_is);
		;}
    break;

  case 223:
#line 3162 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [<<]\n";
#endif
			(yyval.node) = new NodeComp((yyloc), op_precedes);
		;}
    break;

  case 224:
#line 3169 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [>>]\n";
#endif
			(yyval.node) = new NodeComp((yyloc), op_follows);
		;}
    break;

  case 225:
#line 3183 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [expr]\n";
#endif
			(yyval.expr) = new ValidateExpr((yyloc), "strict", (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 226:
#line 3190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3205 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3214 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3229 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3238 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3255 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3301 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/]\n";
#endif
			(yyval.expr) = new PathExpr((yyloc), path_leading_lone_slash, NULL);
		;}
    break;

  case 233:
#line 3308 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/relative]\n";
#endif
			(yyval.expr) = new PathExpr((yyloc), path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 234:
#line 3315 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [//relative]\n";
#endif
			(yyval.expr) = new PathExpr((yyloc), path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 235:
#line 3322 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [relative]\n";
#endif
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = rpe == NULL ? (yysemantic_stack_[(1) - (1)].expr) : new PathExpr((yyloc), path_relative, (yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 236:
#line 3336 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step]\n";
#endif
            AxisStep *as = dynamic_cast<AxisStep *>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = as != NULL ? new RelativePathExpr((yyloc), st_slash, new ContextItemExpr((yyloc)), (yysemantic_stack_[(1) - (1)].expr)) : (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 237:
#line 3344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step/relative]\n";
#endif
			(yyval.expr) = new RelativePathExpr((yyloc), st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 238:
#line 3351 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step//relative]\n";
#endif
			(yyval.expr) = new RelativePathExpr((yyloc), st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 239:
#line 3364 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [axis]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 240:
#line 3371 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [filter]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 241:
#line 3384 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3393 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3402 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3411 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3426 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3435 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [abbrev]\n";
#endif
			(yyval.node) = new ForwardStep((yyloc),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 247:
#line 3449 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [child]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_child);
		;}
    break;

  case 248:
#line 3456 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_descendant);
		;}
    break;

  case 249:
#line 3463 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [attribute]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_attribute);
		;}
    break;

  case 250:
#line 3470 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [self]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_self);
		;}
    break;

  case 251:
#line 3477 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant_or_self]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_descendant_or_self);
		;}
    break;

  case 252:
#line 3484 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following_sibling]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_following_sibling);
		;}
    break;

  case 253:
#line 3491 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following]\n";
#endif
			(yyval.node) = new ForwardAxis((yyloc), axis_following);
		;}
    break;

  case 254:
#line 3504 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [nodetest]\n";
#endif
			(yyval.node) = new AbbrevForwardStep((yyloc), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 255:
#line 3511 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [@ nodetest]\n";
#endif
			(yyval.node) = new AbbrevForwardStep((yyloc), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 256:
#line 3524 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3533 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3548 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [parent]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_parent);
		;}
    break;

  case 259:
#line 3555 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_ancestor);
		;}
    break;

  case 260:
#line 3562 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding_sibling]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_preceding_sibling);
		;}
    break;

  case 261:
#line 3569 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_preceding);
		;}
    break;

  case 262:
#line 3576 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor_or_self]\n";
#endif
			(yyval.node) = new ReverseAxis((yyloc), axis_ancestor_or_self);
		;}
    break;

  case 263:
#line 3594 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [kindtest]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 264:
#line 3601 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [nametest]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 265:
#line 3614 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [qname]\n";
#endif
			(yyval.node) = new NameTest((yyloc), new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 266:
#line 3621 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [wildcard]\n";
#endif
			(yyval.node) = new NameTest((yyloc), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 267:
#line 3634 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3644 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3654 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3670 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 271:
#line 3677 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3692 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3701 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3718 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Predicate [ ]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 275:
#line 3732 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [literal]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 276:
#line 3739 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [varref]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 277:
#line 3746 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [paren]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 278:
#line 3753 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [context_item]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 279:
#line 3760 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [funcall]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 280:
#line 3767 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [cons]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 281:
#line 3774 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [ordered]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 282:
#line 3781 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [unordered]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 283:
#line 3794 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [numeric]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 284:
#line 3801 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [string]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 285:
#line 3814 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [decimal]\n";
#endif
			(yyval.expr) = new NumericLiteral((yyloc), decimal(yylval.decval));
		;}
    break;

  case 286:
#line 3821 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [int]\n";
#endif
			(yyval.expr) = new NumericLiteral((yyloc), yylval.ival);
		;}
    break;

  case 287:
#line 3828 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [double]\n";
#endif
			(yyval.expr) = new NumericLiteral((yyloc), yylval.dval);
		;}
    break;

  case 288:
#line 3841 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarRef [ ]\n";
#endif
			(yyval.expr) = new VarRef((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 289:
#line 3854 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [()]\n";
#endif
			(yyval.expr) = new ParenthesizedExpr((yyloc), NULL);
		;}
    break;

  case 290:
#line 3861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [(expr)]\n";
#endif
			(yyval.expr) = new ParenthesizedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 291:
#line 3875 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ContextItemExpr [.]\n";
#endif
			(yyval.expr) = new ContextItemExpr((yyloc));
		;}
    break;

  case 292:
#line 3888 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderedExpr [expr]\n";
#endif
			(yyval.expr) = new OrderedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 293:
#line 3902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnorderedExpr [expr]\n";
#endif
			(yyval.expr) = new UnorderedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 294:
#line 3961 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3970 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3985 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3994 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4009 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [direct]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 299:
#line 4016 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [computed]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 300:
#line 4029 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [element]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 301:
#line 4036 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [comment]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 4043 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [pi]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 303:
#line 4056 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4067 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4078 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4089 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4100 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4129 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4138 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4162 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4179 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [quote]\n";
#endif
			(yyval.node) = new DirAttributeValue((yyloc),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 315:
#line 4202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [apos]\n";
#endif
			(yyval.node) = new DirAttributeValue((yyloc),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 316:
#line 4216 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList[empty]\n";
#endif
			(yyval.node) = new QuoteAttrContentList((yyloc));
		;}
    break;

  case 317:
#line 4223 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 318:
#line 4230 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4239 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4248 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4259 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4275 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']\n";
#endif
			(yyval.node) = new AposAttrContentList((yyloc));
		;}
    break;

  case 323:
#line 4282 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 324:
#line 4289 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4298 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4307 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4318 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4335 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [quote_attr_content]\n";
#endif
			(yyval.node) = new QuoteAttrValueContent((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 329:
#line 4343 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [common_content]\n";
#endif
			(yyval.node) = new QuoteAttrValueContent((yyloc),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 330:
#line 4357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [apos_attr_content]\n";
#endif
			(yyval.node) = new AposAttrValueContent((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 331:
#line 4365 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [common_content]\n";
#endif
			(yyval.node) = new AposAttrValueContent((yyloc),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 332:
#line 4379 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cons]\n";
#endif
			(yyval.expr) = new DirElemContent((yyloc),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 333:
#line 4387 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [elem_content]\n";
#endif
			(yyval.expr) = new DirElemContent((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 334:
#line 4395 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4404 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4419 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4428 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4437 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [{{]\n";
#endif
			(yyval.expr) = new CommonContent((yyloc),
								cont_escape_lbrace);
		;}
    break;

  case 339:
#line 4445 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [}}]\n";
#endif
			(yyval.expr) = new CommonContent((yyloc),
								cont_escape_rbrace);
		;}
    break;

  case 340:
#line 4453 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [expr]\n";
#endif
			(yyval.expr) = new CommonContent((yyloc),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 341:
#line 4467 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirCommentConstructor [ ]\n";
#endif
			(yyval.expr) = new DirCommentConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 342:
#line 4486 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target]\n";
#endif
			(yyval.expr) = new DirPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 343:
#line 4494 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target.charlit]\n";
#endif
			(yyval.expr) = new DirPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 344:
#line 4514 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CDataSection [ ]\n";
#endif
			(yyval.expr) = new CDataSection((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 345:
#line 4532 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [doc]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 346:
#line 4539 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [elem]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 347:
#line 4546 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [attr]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 348:
#line 4553 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [text]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 349:
#line 4560 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [comment]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 350:
#line 4567 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [pi]\n";
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 351:
#line 4580 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompDocConstructor [ ]\n";
#endif
			(yyval.expr) = new CompDocConstructor((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 352:
#line 4594 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4603 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4612 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name]\n";
#endif
			(yyval.expr) = new CompElemConstructor((yyloc),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 355:
#line 4620 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name.content]\n";
#endif
			(yyval.expr) = new CompElemConstructor((yyloc),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 356:
#line 4648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4657 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4666 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name]\n";
#endif
			(yyval.expr) = new CompAttrConstructor((yyloc),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 359:
#line 4674 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name.val]\n";
#endif
			(yyval.expr) = new CompAttrConstructor((yyloc),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 360:
#line 4688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompTextConstructor [content]\n";
#endif
			(yyval.expr) = new CompTextConstructor((yyloc),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 361:
#line 4702 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompCommentConstructor [content]\n";
#endif
			(yyval.expr) = new CompCommentConstructor((yyloc),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 362:
#line 4716 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4725 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4734 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target]\n";
#endif
			(yyval.expr) = new CompPIConstructor((yyloc),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 365:
#line 4742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target.content]\n";
#endif
			(yyval.expr) = new CompPIConstructor((yyloc),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 366:
#line 4756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4765 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4780 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeDeclaration [as seqtype]\n";
#endif
			(yyval.node) = new TypeDeclaration((yyloc),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 369:
#line 4794 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4803 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4812 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [void]\n";
#endif
			(yyval.node) = new SequenceType((yyloc), NULL, NULL);
		;}
    break;

  case 372:
#line 4852 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [?]\n";
#endif
			(yyval.node) = new OccurrenceIndicator((yyloc),
								occurs_optionally);
		;}
    break;

  case 373:
#line 4860 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [*]\n";
#endif
			(yyval.node) = new OccurrenceIndicator((yyloc),
								occurs_zero_or_more);
		;}
    break;

  case 374:
#line 4868 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [+]\n";
#endif
			(yyval.node) = new OccurrenceIndicator((yyloc),
								occurs_one_or_more);
		;}
    break;

  case 375:
#line 4882 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [atomic]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 376:
#line 4889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [kind]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 377:
#line 4896 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [item]\n";
#endif
			(yyval.node) = new ItemType((yyloc),true);
		;}
    break;

  case 378:
#line 4909 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AtomicType [qname]\n";
#endif
			(yyval.node) = new AtomicType((yyloc),
								new QName((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 379:
#line 4923 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [doc]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 380:
#line 4930 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [elem]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 381:
#line 4937 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [attr]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 382:
#line 4944 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_elem]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 383:
#line 4951 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_attr]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 384:
#line 4958 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [pi]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 385:
#line 4965 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [comment]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 386:
#line 4972 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [text]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 387:
#line 4979 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [any]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 388:
#line 4992 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AnyKindTest [ ]\n";
#endif
			(yyval.node) = new AnyKindTest((yyloc));
		;}
    break;

  case 389:
#line 5005 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [ ]\n";
#endif
			(yyval.node) = new DocumentTest((yyloc));
		;}
    break;

  case 390:
#line 5012 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [elem]\n";
#endif
			(yyval.node) = new DocumentTest((yyloc),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 391:
#line 5020 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [schema_elem]\n";
#endif
			(yyval.node) = new DocumentTest((yyloc),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 392:
#line 5034 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TextTest [ ]\n";
#endif
			(yyval.node) = new TextTest((yyloc));
		;}
    break;

  case 393:
#line 5047 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommentTest [ ]\n";
#endif
			(yyval.node) = new CommentTest((yyloc));
		;}
    break;

  case 394:
#line 5060 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ ]\n";
#endif
			(yyval.node) = new PITest((yyloc), "", "");
		;}
    break;

  case 395:
#line 5067 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ncname]\n";
#endif
			(yyval.node) = new PITest((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), "");
		;}
    break;

  case 396:
#line 5074 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [stringlit]\n";
#endif
			(yyval.node) = new PITest((yyloc), "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 397:
#line 5087 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5096 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5105 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5114 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5123 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5138 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaAttributeTest [ ]\n";
#endif
			(yyval.node) = new SchemaAttributeTest((yyloc),
								new QName((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 403:
#line 5152 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5161 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5170 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5179 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5188 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5198 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5208 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5224 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaElementTest [ ]\n";
#endif
			(yyval.node) = new SchemaElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 411:
#line 5248 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name]\n";
#endif
			(yyval.node) = new TypeName((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 412:
#line 5258 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StringLiteral [ ]\n";
#endif
			(yyval.expr) = new StringLiteral((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 414:
#line 5323 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [ ]\n";
#endif
		;}
    break;

  case 415:
#line 5335 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr]\n";
#endif
		;}
    break;

  case 416:
#line 5341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.as_first]\n";
#endif
		;}
    break;

  case 417:
#line 5347 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.as_last]\n";
#endif
		;}
    break;

  case 418:
#line 5353 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.after]\n";
#endif
		;}
    break;

  case 419:
#line 5359 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.before]\n";
#endif
		;}
    break;

  case 420:
#line 5371 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteExpr [expr]\n";
#endif
		;}
    break;

  case 421:
#line 5383 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceExpr [expr.expr]\n";
#endif
		;}
    break;

  case 422:
#line 5389 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceExpr [value.expr]\n";
#endif
		;}
    break;

  case 423:
#line 5401 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RenameExpr [expr.expr]\n";
#endif
		;}
    break;

  case 424:
#line 5428 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TransformExpr [ ]\n";
#endif
		;}
    break;

  case 425:
#line 5440 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [single]\n";
#endif
		;}
    break;

  case 426:
#line 5446 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [list]\n";
#endif
		;}
    break;

  case 427:
#line 5466 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or]\n";
#endif
		;}
    break;

  case 428:
#line 5472 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity]\n";
#endif
		;}
    break;

  case 429:
#line 5478 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.weight_range]\n";
#endif
		;}
    break;

  case 430:
#line 5484 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity.weight_range]\n";
#endif
		;}
    break;

  case 431:
#line 5496 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_single]\n";
#endif
		;}
    break;

  case 432:
#line 5502 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_single]\n";
#endif
		;}
    break;

  case 433:
#line 5508 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_list]\n";
#endif
		;}
    break;

  case 434:
#line 5514 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_list]\n";
#endif
		;}
    break;

  case 435:
#line 5526 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [and]\n";
#endif
		;}
    break;

  case 436:
#line 5532 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [or.and]\n";
#endif
		;}
    break;

  case 437:
#line 5544 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [mild_not]\n";
#endif
		;}
    break;

  case 438:
#line 5550 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [and.mild_not]\n";
#endif
		;}
    break;

  case 439:
#line 5562 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [unary_not]\n";
#endif
		;}
    break;

  case 440:
#line 5568 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [mild_not.unary_not]\n";
#endif
		;}
    break;

  case 441:
#line 5580 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [words]\n";
#endif
		;}
    break;

  case 442:
#line 5586 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [not.words]\n";
#endif
		;}
    break;

  case 443:
#line 5598 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words]\n";
#endif
		;}
    break;

  case 444:
#line 5604 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words.times]\n";
#endif
		;}
    break;

  case 445:
#line 5610 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [selection]\n";
#endif
		;}
    break;

  case 446:
#line 5622 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value]\n";
#endif
		;}
    break;

  case 447:
#line 5628 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value.any_all_option]\n";
#endif
		;}
    break;

  case 448:
#line 5640 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [literal]\n";
#endif
		;}
    break;

  case 449:
#line 5646 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [expr]\n";
#endif
		;}
    break;

  case 450:
#line 5658 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [order]\n";
#endif
		;}
    break;

  case 451:
#line 5664 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [window]\n";
#endif
		;}
    break;

  case 452:
#line 5670 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [distance]\n";
#endif
		;}
    break;

  case 453:
#line 5676 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [scope]\n";
#endif
		;}
    break;

  case 454:
#line 5682 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [content]\n";
#endif
		;}
    break;

  case 455:
#line 5694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOrderedIndicator [ ]\n";
#endif
		;}
    break;

  case 456:
#line 5706 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [case]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 457:
#line 5713 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [diacritics]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 458:
#line 5720 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stem]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 459:
#line 5727 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [thesaurus]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 460:
#line 5734 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stopword]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 461:
#line 5741 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [language]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 462:
#line 5748 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [wildcard]\n";
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 463:
#line 5761 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [lower]\n";
#endif
		;}
    break;

  case 464:
#line 5767 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [upper]\n";
#endif
		;}
    break;

  case 465:
#line 5773 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [sensitive]\n";
#endif
		;}
    break;

  case 466:
#line 5779 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [insensitive]\n";
#endif
		;}
    break;

  case 467:
#line 5791 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [with]\n";
#endif
		;}
    break;

  case 468:
#line 5797 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [without]\n";
#endif
		;}
    break;

  case 469:
#line 5803 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [sensitive]\n";
#endif
		;}
    break;

  case 470:
#line 5809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [insensitive]\n";
#endif
		;}
    break;

  case 471:
#line 5821 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [with]\n";
#endif
		;}
    break;

  case 472:
#line 5827 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [without]\n";
#endif
		;}
    break;

  case 473:
#line 5839 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [id]\n";
#endif
		;}
    break;

  case 474:
#line 5845 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [default]\n";
#endif
		;}
    break;

  case 475:
#line 5851 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id)]\n";
#endif
		;}
    break;

  case 476:
#line 5857 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id,id,..)]\n";
#endif
		;}
    break;

  case 477:
#line 5863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default)]\n";
#endif
		;}
    break;

  case 478:
#line 5869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default,id,id,..)]\n";
#endif
		;}
    break;

  case 479:
#line 5875 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [without]\n";
#endif
		;}
    break;

  case 480:
#line 5887 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [single]\n";
#endif
		;}
    break;

  case 481:
#line 5893 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [list]\n";
#endif
		;}
    break;

  case 482:
#line 5905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name]\n";
#endif
		;}
    break;

  case 483:
#line 5911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel]\n";
#endif
		;}
    break;

  case 484:
#line 5917 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.range]\n";
#endif
		;}
    break;

  case 485:
#line 5923 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel.range]\n";
#endif
		;}
    break;

  case 486:
#line 5935 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list]\n";
#endif
		;}
    break;

  case 487:
#line 5941 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list.incl_excl]\n";
#endif
		;}
    break;

  case 488:
#line 5947 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default]\n";
#endif
		;}
    break;

  case 489:
#line 5953 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default.incl_excl]\n";
#endif
		;}
    break;

  case 490:
#line 5959 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [without]\n";
#endif
		;}
    break;

  case 491:
#line 5971 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [.]\n";
#endif
		;}
    break;

  case 492:
#line 5977 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [*]\n";
#endif
		;}
    break;

  case 493:
#line 5989 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [.]\n";
#endif
		;}
    break;

  case 494:
#line 5995 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [(*)]\n";
#endif
		;}
    break;

  case 495:
#line 6007 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [.]\n";
#endif
		;}
    break;

  case 496:
#line 6013 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [*]\n";
#endif
		;}
    break;

  case 497:
#line 6025 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [union]\n";
#endif
		;}
    break;

  case 498:
#line 6031 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [except]\n";
#endif
		;}
    break;

  case 499:
#line 6043 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTLanguageOption [ ]\n";
#endif
		;}
    break;

  case 500:
#line 6055 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [with]\n";
#endif
		;}
    break;

  case 501:
#line 6061 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [without]\n";
#endif
		;}
    break;

  case 502:
#line 6073 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [start]\n";
#endif
		;}
    break;

  case 503:
#line 6079 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [end]\n";
#endif
		;}
    break;

  case 504:
#line 6085 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [entire]\n";
#endif
		;}
    break;

  case 505:
#line 6097 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any]\n";
#endif
		;}
    break;

  case 506:
#line 6103 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any_word]\n";
#endif
		;}
    break;

  case 507:
#line 6109 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all]\n";
#endif
		;}
    break;

  case 508:
#line 6115 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all_words]\n";
#endif
		;}
    break;

  case 509:
#line 6121 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [phrase]\n";
#endif
		;}
    break;

  case 510:
#line 6133 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [exactly]\n";
#endif
		;}
    break;

  case 511:
#line 6139 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_least]\n";
#endif
		;}
    break;

  case 512:
#line 6145 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_most]\n";
#endif
		;}
    break;

  case 513:
#line 6151 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [range]\n";
#endif
		;}
    break;

  case 514:
#line 6163 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDistance [ ]\n";
#endif
		;}
    break;

  case 515:
#line 6175 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWindow [ ]\n";
#endif
		;}
    break;

  case 516:
#line 6187 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [ ]\n";
#endif
		;}
    break;

  case 517:
#line 6199 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [same]\n";
#endif
		;}
    break;

  case 518:
#line 6205 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [different]\n";
#endif
		;}
    break;

  case 519:
#line 6217 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [words]\n";
#endif
		;}
    break;

  case 520:
#line 6223 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [sentences]\n";
#endif
		;}
    break;

  case 521:
#line 6229 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [paragraph]\n";
#endif
		;}
    break;

  case 522:
#line 6241 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [sentence]\n";
#endif
		;}
    break;

  case 523:
#line 6247 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [paragraph]\n";
#endif
		;}
    break;

  case 524:
#line 6259 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTIgnoreOption [ ]\n";
#endif
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 6104 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -640;
  const short int
  xquery_parser::yypact_[] =
  {
       794,  1365,  1553,  -640,  -640,  -640,  1741,  -640,    54,  -640,
    -640,  -640,  3057,    -4,   372,  -640,  3057,   -32,  -640,   263,
     -47,   137,   -22,   276,   177,   214,   188,   332,   349,   346,
     -42,   361,   410,  -640,  -640,  3057,   338,   424,  -640,  -640,
    -640,  3057,    14,   433,  -640,  -640,   438,  3057,   165,   230,
    -640,  -640,   441,  1929,  -640,   476,   353,  3057,  -640,   485,
      34,  -640,   484,  -640,  -640,   220,   493,   495,  -640,   538,
     538,   433,  -640,   497,  3057,   364,  3057,  3057,  3057,   513,
     521,  -640,  3057,  3057,  3057,  1170,   528,  3426,   559,   982,
    -640,  -640,   420,  3057,   408,   429,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,   569,  -640,  -640,   247,
    -640,  -640,  -640,  -640,  -640,  -640,   449,   588,  -640,  3544,
     390,   190,   238,   -80,   344,  -640,   514,   448,   586,   587,
    3245,  -640,  -640,  -640,     0,  -640,  -640,  -640,   303,  -640,
     516,   372,  -640,   516,   372,  -640,  -640,  -640,  -640,   516,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,    93,  -640,
     101,  -640,  -640,    52,  3057,   104,    55,  -640,    74,  -640,
     105,  -640,  -640,  -640,  -640,  -640,  -640,   581,   589,  -640,
     610,   611,  -640,  -640,   210,   549,   615,  -640,  -640,   239,
     326,   106,  -640,   481,   482,  -640,   108,    80,  -640,    82,
      43,    11,  -640,    -3,   594,  -640,    86,   608,   629,   612,
     520,   632,   625,    -7,   603,  -640,  -640,    87,   563,  -640,
     109,    79,   494,   496,  -640,   635,   545,  3057,   502,   503,
    -640,  -640,    16,    32,   110,  -640,    88,   111,   120,   466,
       5,  -640,    21,   631,  3057,   452,   565,    99,  -640,  -640,
    -640,  -640,   643,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
     192,  -640,  -640,   237,    40,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,   420,
       4,  3057,  3057,  3057,  3057,  3057,  -640,   217,   511,  3410,
    3410,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  3410,  3410,  3410,     3,
    3410,  3410,  3410,  3410,  3410,  3410,  3410,  3410,  3410,  3410,
    3410,   277,   277,   649,   649,  -640,  -640,  -640,  2117,  -640,
     538,   538,  3057,   516,  -640,  -640,   516,  -640,   516,  -640,
    -640,  3057,  -640,   123,   556,   651,  -640,   651,  -640,  -640,
     195,   242,  -640,  -640,   647,   199,   277,    72,  -640,   650,
    -640,   285,   277,    84,   277,  -640,  3057,    22,  -640,  -640,
    -640,   561,   653,  -640,   653,  -640,  3057,   570,   605,  3057,
     606,  3057,   609,   -66,   576,   -19,   617,   509,   662,   599,
     662,  -640,   602,   659,  3057,   595,   -44,   619,  -640,   672,
    -640,  -640,  -640,  -640,  -640,  -640,  2305,   127,  -640,  -640,
    3057,   614,  -640,    23,    42,  -640,  -640,   657,  -640,  -640,
    -640,   675,  -640,   -97,  3057,  3057,  3057,  3057,   491,  3057,
    3057,   679,  3057,  -640,   237,   237,   192,  -640,   682,   683,
     192,   685,  -640,   254,  -640,   546,  -640,  -640,  -640,   461,
     664,  -640,  -640,   664,  -640,  3057,   557,  3057,   588,  -640,
    -640,  -640,  -640,  3057,     3,   273,  -640,   464,   519,   486,
     478,  -640,  -640,   479,   355,   238,   238,   -26,   -80,   -80,
     -80,   -80,   344,   344,  -640,  -640,  -640,  -640,  -640,  -640,
     421,  -640,  -640,  -640,  -640,   620,  -640,  -640,   128,  -640,
    -640,    61,  -640,  -640,  -640,  2493,  -640,   566,   567,  -640,
    -640,  -640,  -640,   687,  -640,  3057,  -640,   334,   646,   357,
     277,  -640,  -640,  -640,   358,   395,   277,  -640,  -640,  -640,
    3057,  2681,   621,   568,   572,   573,   577,  -640,  3057,   433,
    -640,   702,  -640,   703,  3057,   630,  3057,  3057,   -46,   641,
     438,  3057,  -640,   691,   725,   691,  -640,   662,  -640,  3057,
    3057,   652,   441,   591,  -640,   149,   636,  -640,    12,  -640,
    -640,  -640,   744,  -640,  -640,   737,  -640,  -640,    63,  -640,
    -640,  -640,  -640,    81,  -640,   219,    49,  -640,   596,  3057,
    3057,  -640,  -640,  -640,  -640,  3057,  -640,  -640,   661,   613,
    -640,  -640,  -640,  -640,  -640,    48,   192,   309,    89,    91,
       4,  -640,   735,  -640,  -640,  -640,  -640,   451,   717,  -640,
    3057,  -640,  3057,  -640,   182,   624,  -640,  3410,  -640,  -640,
    -640,  -640,   160,   373,  -640,     3,   160,  3410,  3410,  3369,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,     3,     3,   373,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,   215,  -640,  -640,  -640,   222,
    -640,  -640,  -640,  -640,  -640,   406,  -640,  -640,  -640,  -640,
     428,  -640,  -640,   233,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  3057,  -640,  -640,  3057,   676,  3057,
    -640,   701,   742,   751,   691,  -640,  -640,  3057,  -640,  -640,
    -640,  2869,   282,   415,  -640,   743,   616,   766,  -640,   768,
     136,   765,   634,   -25,  -640,  -640,  -640,  -640,  -640,  3057,
    3057,  -640,  -640,  3410,  3410,  3410,  3410,   769,   558,   759,
    -640,   759,  -640,  -640,   717,  -640,  -640,  -640,  -640,  -640,
    -640,   -80,  -640,  -640,  -640,   194,   486,  -640,  -640,   162,
    3410,  -640,  -640,   478,  -640,   548,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  3057,  -640,  3057,  -640,   662,
    -640,  -640,   234,  -640,  -640,   767,   409,  -640,  -640,  -640,
    -640,   642,   434,  -640,  -640,  -640,  -640,   627,   628,   777,
     770,  3057,   778,  3057,  -640,  -640,   -80,   -80,   -80,   407,
     373,  -640,    95,  -640,    97,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,   691,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,   638,   277,  -640,   667,  -640,
    3410,   571,   759,  -640,  -640,  -640,   668,  3057,   -80,  -640,
    -640,  3057,  -640,  -640
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
     292,   343,   342,   395,   396,   231,     0,     0,   402,   410,
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
       0,     0,     0,     0,   362,     0,     0,   153,     0,   337,
     333,   336,     0,   338,   339,     0,   340,   332,     0,   309,
     335,   334,   304,     0,   312,     0,     0,   161,     0,     0,
       0,   418,   419,   415,   423,     0,   421,   425,     0,     0,
     498,   497,   492,   493,   495,     0,   487,   482,     0,     0,
      14,   148,     0,   149,   150,   151,   140,   141,   142,   143,
       0,   107,     0,   108,     0,     0,   442,     0,   176,   455,
     503,   502,     0,     0,   504,     0,     0,     0,     0,   428,
     432,   450,   431,   454,   452,   451,   453,     0,     0,     0,
     444,   507,   508,   505,   506,   509,   447,   372,   374,   373,
     370,   367,   228,   274,   358,     0,   399,   401,    91,     0,
      76,    77,    89,    74,    75,     0,    84,    85,    82,    83,
       0,    68,   354,     0,   412,   405,   406,   408,   409,   158,
     156,   125,   126,   119,     0,   121,   118,     0,     0,     0,
     116,     0,     0,    63,    57,   132,   131,     0,   129,    11,
     363,     0,   322,   316,   313,     0,     0,     0,   310,     0,
       0,     0,     0,     0,   162,     7,   416,   417,   422,     0,
       0,   496,   494,     0,     0,     0,     0,     0,     0,     0,
     477,     0,   475,   152,   144,   145,   146,   138,   109,   449,
     445,   524,   523,   522,   518,     0,   436,   517,   429,     0,
       0,   434,   433,   438,   440,     0,   359,    92,    78,    79,
      86,    87,   355,   123,   120,     0,   122,     0,    59,     0,
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
      -640,  -640,  -640,   714,   718,  -640,   716,  -640,   498,   499,
    -304,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -425,  -640,  -640,  -640,  -640,  -640,
     597,   262,  -378,   722,     6,    -6,  -640,  -640,   706,  -640,
    -640,   243,   402,  -240,  -640,  -640,   226,  -640,   507,   512,
     180,  -640,  -640,   184,  -561,  -640,   771,   260,  -640,  -640,
     235,  -640,  -640,   531,   534,   257,  -610,   524,   179,  -344,
     205,   240,  -640,  -640,  -640,  -640,  -640,   731,  -640,  -640,
    -640,  -640,  -640,  -640,   721,  -640,   -49,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,    71,  -640,  -640,  -640,   151,   129,
    -640,  -343,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -434,  -640,   250,  -640,   423,  -640,  -640,  -640,  -640,
    -640,    46,    53,  -560,  -424,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,   518,  -214,  -358,  -640,  -640,
     245,  -359,  -640,  -640,  -640,  -640,  -640,  -640,  -640,   844,
     847,    29,   472,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,   385,  -640,  -640,   216,   206,   204,   389,  -640,  -640,
     221,  -640,  -481,  -640,  -640,  -640,  -640,   114,  -303,  -640,
     416,   122,  -640,  -440,  -640,  -640,  -640,  -640,  -639,  -640,
    -640,  -640,  -640,   102,   228,  -640
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   593,   252,   111,   112,   113,   114,
     397,   398,   616,   115,   116,   117,   118,   119,   120,   121,
     244,   245,   423,   424,   122,   254,   255,   327,   328,   490,
     491,   656,   657,   658,   659,   123,   241,   242,   124,   626,
     627,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   346,   347,
     348,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   373,   374,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   203,
     168,   169,   170,   618,   454,   455,   754,   831,   832,   825,
     826,   833,   827,   619,   620,   171,   172,   621,   173,   174,
     175,   176,   177,   178,   179,   534,   407,   529,   700,   530,
     531,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   547,   574,   190,   191,   192,   193,   194,   195,   196,
     287,   507,   679,   508,   509,   510,   511,   512,   513,   514,
     680,   681,   306,   307,   308,   309,   310,   852,   853,   311,
     476,   480,   645,   477,   312,   313,   683,   696,   778,   684,
     685,   690,   686,   859,   794,   668
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       202,   484,   532,   532,   533,   595,   506,   198,   200,   518,
     519,   520,   521,   435,   420,   206,   487,   556,   205,   617,
     270,   271,   210,   563,   404,     7,   417,   682,   404,   425,
     420,   609,   610,   237,   795,   611,   642,   532,   557,   436,
     584,   231,   752,   532,   564,   532,   567,   236,   262,   842,
     805,   451,   463,   246,    18,   600,   263,   418,   758,   257,
     737,   451,   418,   260,    27,   612,    29,   798,    31,    32,
     771,   609,   610,   481,   404,   611,   281,   282,   283,   285,
     274,    40,   276,   277,   278,   209,   441,   587,   625,   609,
     610,   461,   434,   611,   227,   350,   785,   786,   381,   357,
     613,   385,   614,   421,   213,   612,   482,   321,   629,   217,
     630,   358,    50,   368,   569,   763,   503,   452,   558,   351,
     387,   570,   504,   612,   214,   211,   412,   622,   414,   218,
     558,   843,   321,   321,   321,   779,   555,   781,   228,   321,
     613,   882,   614,   882,   609,   610,    62,   321,   611,   416,
     321,   321,   321,   207,   321,   321,   321,   321,   613,   483,
     614,   506,   506,    59,   208,   753,   321,   204,   462,   321,
     419,   238,   744,   321,   321,   450,   555,   422,   612,   711,
     649,   714,   239,   585,   617,   589,   717,   719,   247,   617,
     861,   264,   615,    73,   555,   321,   601,   422,   802,   422,
     758,   532,   715,    59,   453,   772,   642,   532,   720,   382,
     383,   881,   386,   613,   623,   614,   703,    79,   464,   465,
     442,    59,   375,   855,   422,   377,    87,   466,   321,   559,
     560,   388,   757,    73,   266,   505,   422,   413,   526,   415,
     422,   565,   566,   427,   438,   457,   780,   379,   782,   555,
     759,    73,   883,   249,   884,   380,    13,    79,   384,   389,
     408,   321,   411,   440,   456,   458,   532,   762,   321,    17,
     478,   222,   223,   447,   459,    79,    59,   544,   468,   321,
     321,   606,   702,   474,   394,   823,   212,   481,   215,   248,
     609,   554,    36,   761,   611,     7,   526,   250,   471,   219,
      42,   220,   549,   750,   376,   839,    73,   472,   216,   353,
     378,   350,   555,   394,    13,   488,   489,   492,   489,   494,
     648,   539,   540,   791,    18,   550,   617,    17,   828,   834,
      79,   527,   506,   267,   799,   351,   789,   809,   221,   708,
     354,   357,   811,    46,   506,   506,   487,    56,   738,   551,
      36,    40,   224,   358,   251,   322,   479,   404,    42,   613,
     355,   614,    60,   225,    52,   226,   352,   395,   396,   806,
     824,   475,   552,   495,   538,   543,   807,   562,   541,    66,
      67,   229,    50,     3,   324,   322,   503,   812,   866,   527,
       4,     5,   504,    75,   865,   555,   401,   402,   555,   792,
     568,   856,   828,   323,   793,    56,   356,   857,   834,    13,
     577,   528,   823,   580,   324,   582,   548,   609,   405,    42,
      60,   611,    17,   609,   858,   406,   710,   611,   598,   846,
     847,   848,   849,   856,   230,   359,   829,    66,    67,   857,
     325,   573,   609,   575,   607,    36,   611,   555,   235,   713,
     716,    75,   605,    42,   360,   829,   858,   240,   631,   632,
     633,   634,   243,   636,   637,   253,   639,   370,   371,   528,
     555,   555,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,   613,   718,   614,   661,
     258,   663,   613,   651,   614,   232,   652,   868,   808,    67,
      56,   261,   542,   265,   830,   542,   652,   542,   555,   664,
     259,   613,   268,   614,   269,    60,   273,   532,   886,   555,
     810,   275,   555,   871,    48,    49,   773,   774,   555,   515,
     516,   653,    66,    67,   654,   655,   888,   775,   776,   279,
      72,   555,     1,   280,   654,   655,    75,   555,     2,     3,
     777,   705,   286,   697,   698,   699,     4,     5,     6,   314,
       7,   709,   522,   523,   721,     9,    10,   691,   692,   693,
     694,   319,   729,    11,    12,    13,    14,   723,   733,   890,
     735,   736,    15,   880,   329,   741,   357,    16,    17,    18,
     773,   774,   320,   745,   746,   695,   640,   641,   358,   524,
     525,   775,   776,   500,   501,   502,    33,    34,   535,   535,
      35,    36,    37,    38,    39,   321,    40,   330,    41,    42,
      81,   349,   361,   766,   767,   362,   363,   390,   364,   768,
     372,    44,    45,   392,   393,   391,   399,   400,   409,   410,
     426,   428,    87,   429,   431,   430,   432,    50,   433,   437,
     439,   443,   445,   444,   489,   669,   788,    53,   446,   448,
     449,   460,   467,   469,   470,   473,    56,   497,   526,   545,
     546,   553,   572,   561,   571,    57,   578,    58,    59,   579,
     581,    60,   586,   583,   591,   592,   594,    63,    64,   596,
      65,   590,   597,   602,   599,   603,   625,   628,    66,    67,
      68,   608,   635,   638,   643,   644,    72,   647,    73,   650,
     660,    74,    75,   662,   667,   688,   687,   689,   404,    77,
     394,   701,   724,   706,   707,   725,   731,   732,   813,   726,
     727,   814,    79,   816,   728,   670,   734,   742,   671,   288,
     289,   820,   290,   291,   672,   673,   674,   739,   743,   751,
     755,   747,   675,   292,   749,   293,   756,   822,   783,   765,
     769,   676,   652,   844,   845,   818,   294,   677,   678,   770,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   790,   815,   817,   819,   837,   835,   838,   836,   840,
     841,   850,   481,   851,   862,   870,   875,   867,     1,   873,
     874,   876,   878,   315,     2,     3,   889,   316,   317,   863,
     885,   864,     4,     5,     6,   318,     7,   485,   486,     8,
     712,     9,    10,   887,   891,   326,   403,   588,   748,    11,
      12,    13,    14,   740,   496,   877,   493,   879,    15,   730,
     787,   784,   272,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
     498,   764,    33,    34,   499,   369,    35,    36,    37,    38,
      39,   367,    40,   760,    41,    42,   517,   624,   872,   869,
     233,   892,   536,   234,    43,   893,   576,    44,    45,   665,
      46,   796,   804,   803,   666,   854,   646,    47,    48,    49,
     801,   860,     0,    50,   797,     0,     0,     0,     0,     0,
      51,    52,     0,    53,     0,    54,     0,    55,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,    58,    59,     0,     0,    60,     0,    61,
      62,     0,     0,    63,    64,     0,    65,     0,     0,     0,
       0,     0,     0,     0,    66,    67,    68,     0,    69,    70,
      71,     0,    72,     0,    73,     0,     0,    74,    75,     0,
       0,     0,    76,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     1,     0,    79,     0,
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
       0,    78,     0,     0,     1,     0,    79,     0,     0,     0,
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
       0,     0,     0,     0,    79,     0,     0,     0,     0,     1,
       0,    82,    83,    84,    85,     2,     3,     0,     0,    86,
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
       0,     0,     0,     0,    78,     0,     0,     1,     0,    79,
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
       0,     0,    78,     0,     0,     1,     0,    79,     0,     0,
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
      78,     0,     0,     1,     0,    79,     0,     0,     0,     2,
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
       0,     1,     0,    79,     0,     0,     0,     2,     3,     0,
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
       0,     0,     0,     0,     0,     0,    78,     0,     0,     1,
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
      61,    62,     0,     0,    63,    64,     0,    65,     0,   604,
       0,     0,     0,     0,     0,    66,    67,    68,     0,    69,
      70,    71,     0,    72,     0,    73,     0,     0,    74,    75,
       0,     0,     0,    76,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,     1,     0,    79,
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
       0,     0,    63,    64,     0,    65,     0,   704,     0,     0,
       0,     0,     0,    66,    67,    68,     0,    69,    70,    71,
       0,    72,     0,    73,     0,     0,    74,    75,     0,     0,
       0,    76,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,     1,     0,    79,     0,     0,
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
      78,     0,     0,     1,     0,    79,     0,     0,     0,     2,
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
       0,     1,     0,    79,     0,     0,     0,     2,     3,     0,
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
       0,     0,     0,     0,     0,     0,    78,     0,     0,     1,
       0,    79,     0,     0,     0,     2,     3,     0,    82,    83,
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
      70,     0,     0,    72,     1,    73,     0,     0,    74,    75,
       2,     3,     0,     0,     0,     0,    77,     0,     4,     5,
       6,     0,     7,     0,    78,     8,     0,     9,    10,    79,
       0,     0,     0,     0,     0,    11,    12,    13,    14,     0,
       0,     0,     0,     0,    15,     0,     0,     0,     0,    16,
      17,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,    34,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    45,   669,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,    51,     0,     0,    53,
       0,    54,     0,     0,     0,     0,     0,     0,    56,     0,
       0,     0,     0,     0,     0,     0,     0,    57,     0,    58,
      59,     0,     0,    60,     0,    61,    62,     0,     0,    63,
      64,     0,    65,     0,     0,     0,     0,     0,     0,     0,
      66,    67,    68,     0,    69,    70,     0,     0,    72,     0,
      73,     0,     0,    74,    75,   670,     0,     0,   671,   288,
     289,    77,   290,   291,   672,   673,   674,     0,     0,    78,
       0,     0,     0,   292,    79,   293,     0,     0,     0,     0,
       0,   676,     0,     0,     0,     0,   294,   800,   678,     0,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   331,     0,     0,     0,     0,     0,     0,     0,   332,
       0,     0,   333,     0,   334,     0,   288,   289,     0,   290,
     291,     0,     0,     0,     0,   335,     0,     0,     0,   336,
     292,     0,   293,     0,   337,     0,     0,     0,     0,     0,
     338,     0,     0,   294,     0,     0,     0,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,     0,     0,
       0,     0,   339,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   340,   341,   342,
     343,   344,   345
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         6,   304,   361,   362,   362,   430,   349,     1,     2,   353,
     354,   355,   356,   253,    33,    19,   320,   395,    12,   453,
      69,    70,    16,   401,    31,    22,   240,   508,    31,   243,
      33,     8,     9,    19,   673,    12,   476,   396,   396,   253,
     106,    35,    30,   402,   402,   404,   404,    41,    14,    74,
     689,    19,    31,    47,    51,    99,    22,    46,   618,    53,
     106,    19,    46,    57,    60,    42,    62,   677,    64,    65,
      22,     8,     9,    33,    31,    12,    82,    83,    84,    85,
      74,    78,    76,    77,    78,    14,     7,   106,    39,     8,
       9,    86,    99,    12,   136,   121,   657,   658,    46,   179,
      77,    46,    79,   106,   151,    42,    66,    46,   205,   131,
     207,   191,   109,   113,    92,    66,   113,    85,    46,   145,
      46,    99,   119,    42,   171,   157,    46,    85,    46,   151,
      46,   156,    46,    46,    46,    46,   113,    46,   180,    46,
      77,    46,    79,    46,     8,     9,   146,    46,    12,   106,
      46,    46,    46,   157,    46,    46,    46,    46,    77,   119,
      79,   504,   505,   140,   168,   153,    46,   113,   163,    46,
     159,   157,   597,    46,    46,   159,   113,   243,    42,   557,
     483,   559,   168,   423,   618,   425,   564,   565,    23,   623,
     800,   157,   169,   170,   113,    46,   436,   243,   679,   243,
     760,   560,   560,   140,   172,   157,   646,   566,   566,   157,
     204,   850,   157,    77,   172,    79,   155,   194,   197,   198,
     141,   140,   151,   784,   243,   154,   222,   206,    46,   157,
     158,   157,   169,   170,    14,   232,   243,   157,    19,   157,
     243,   157,   158,   157,   157,   157,   157,   154,   157,   113,
     169,   170,   157,    23,   157,   154,    37,   194,   154,   154,
     154,    46,   154,   154,   154,   154,   625,   625,    46,    50,
      33,    83,    84,   267,   154,   194,   140,   154,   284,    46,
      46,   154,   154,    91,    74,     3,    23,    33,   151,   124,
       8,    92,    73,    74,    12,    22,    19,    67,   199,    23,
      81,   124,   107,   154,   153,   169,   170,   208,   171,    71,
     159,   121,   113,    74,    37,   321,   322,   323,   324,   325,
      66,   370,   371,   667,    51,   130,   760,    50,   752,   753,
     194,   112,   675,   113,   678,   145,   154,   715,   124,   553,
     102,   179,   720,    96,   687,   688,   650,   128,   588,   107,
      73,    78,    20,   191,   124,   138,   119,    31,    81,    77,
     122,    79,   143,    14,   117,    19,   176,   157,   158,   154,
      88,   179,   130,   156,   368,   381,   154,    92,   372,   160,
     161,    20,   109,    11,   167,   138,   113,   154,   154,   112,
      18,    19,   119,   174,   819,   113,   157,   158,   113,   239,
     406,   239,   826,   156,   244,   128,   168,   245,   832,    37,
     416,   192,     3,   419,   167,   421,   387,     8,    92,    81,
     143,    12,    50,     8,   262,    99,    92,    12,   434,   773,
     774,   775,   776,   239,    24,    91,    21,   160,   161,   245,
     193,   412,     8,   414,   450,    73,    12,   113,    24,    92,
      92,   174,   446,    81,   110,    21,   262,    24,   464,   465,
     466,   467,    24,   469,   470,    24,   472,   164,   165,   192,
     113,   113,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    77,    92,    79,   495,
      14,   497,    77,    32,    79,   157,    45,    88,    92,   161,
     128,    16,   373,    19,    89,   376,    45,   378,   113,   503,
     157,    77,    19,    79,    19,   143,    19,   876,   876,   113,
      92,   157,   113,    89,   104,   105,   217,   218,   113,   350,
     351,    70,   160,   161,    83,    84,   880,   228,   229,    26,
     168,   113,     4,    22,    83,    84,   174,   113,    10,    11,
     241,   545,    24,   132,   133,   134,    18,    19,    20,     0,
      22,   555,   357,   358,   570,    27,    28,   212,   213,   214,
     215,   163,   578,    35,    36,    37,    38,   571,   584,   882,
     586,   587,    44,   176,   135,   591,   179,    49,    50,    51,
     217,   218,   163,   599,   600,   240,   474,   475,   191,   359,
     360,   228,   229,   346,   347,   348,    68,    69,   363,   364,
      72,    73,    74,    75,    76,    46,    78,    29,    80,    81,
     200,   231,   108,   629,   630,   177,    40,    46,    41,   635,
     114,    93,    94,    23,    23,    46,    87,    22,   157,   157,
      46,    33,   222,    14,   124,    33,    14,   109,    23,    46,
      87,   157,    17,   157,   660,   136,   662,   119,   113,   157,
     157,   195,    31,   211,    99,    22,   128,   156,    19,   113,
      19,    24,    19,    23,   113,   137,   106,   139,   140,    74,
      74,   143,   106,    74,   175,    23,    87,   149,   150,    87,
     152,    74,    33,    74,    99,    23,    39,    22,   160,   161,
     162,    87,   211,    24,    22,    22,   168,    22,   170,   163,
      46,   173,   174,   156,   250,   237,   230,   238,    31,   181,
      74,   101,   101,   157,   157,   157,    24,    24,   734,   157,
     157,   737,   194,   739,   157,   216,   106,    46,   219,   220,
     221,   747,   223,   224,   225,   226,   227,   106,    23,   113,
       6,    99,   233,   234,   163,   236,    19,   751,    23,   163,
      99,   242,    45,   769,   770,    23,   247,   248,   249,   156,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   157,   106,    82,    33,    19,    43,    19,   172,    24,
     156,    22,    33,   235,   246,   153,    19,    30,     4,   172,
     172,    31,    24,    89,    10,    11,   235,    89,    92,   815,
     172,   817,    18,    19,    20,    93,    22,   319,   319,    25,
     558,    27,    28,   156,   156,   119,   229,   425,   602,    35,
      36,    37,    38,   590,   327,   841,   324,   843,    44,   579,
     660,   657,    71,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     329,   626,    68,    69,   330,   144,    72,    73,    74,    75,
      76,   140,    78,   623,    80,    81,   352,   454,   832,   826,
      36,   887,   364,    36,    90,   891,   414,    93,    94,   504,
      96,   675,   688,   687,   505,   781,   480,   103,   104,   105,
     679,   799,    -1,   109,   676,    -1,    -1,    -1,    -1,    -1,
     116,   117,    -1,   119,    -1,   121,    -1,   123,    -1,    -1,
      -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,    -1,   139,   140,    -1,    -1,   143,    -1,   145,
     146,    -1,    -1,   149,   150,    -1,   152,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,   162,    -1,   164,   165,
     166,    -1,   168,    -1,   170,    -1,    -1,   173,   174,    -1,
      -1,    -1,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,    -1,    -1,     4,    -1,   194,    -1,
     196,    -1,    10,    11,   200,   201,   202,   203,   204,    -1,
      18,    19,    20,   209,    22,    -1,    -1,    25,    -1,    27,
      28,    -1,    -1,    -1,    -1,    -1,   222,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    -1,
      68,    69,    -1,    -1,    72,    73,    74,    75,    76,    -1,
      78,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    94,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,    -1,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,
      -1,   119,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,   139,   140,    -1,    -1,   143,    -1,   145,   146,    -1,
      -1,   149,   150,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   161,   162,    -1,   164,   165,   166,    -1,
     168,    -1,   170,    -1,    -1,   173,   174,    -1,    -1,    -1,
     178,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,    -1,    -1,     4,    -1,   194,    -1,    -1,    -1,
      10,    11,   200,   201,   202,   203,   204,    -1,    18,    19,
      20,   209,    22,    -1,    -1,    25,    -1,    27,    28,    -1,
      -1,    -1,    -1,    -1,   222,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    49,
      50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      -1,    -1,    72,    73,    74,    75,    76,    -1,    78,    -1,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    93,    94,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,   119,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,   139,
     140,    -1,    -1,   143,    -1,   145,   146,    -1,    -1,   149,
     150,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   161,   162,    -1,   164,   165,   166,    -1,   168,    -1,
     170,    -1,    -1,   173,   174,    -1,    -1,    -1,   178,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
      -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,     4,
      -1,   201,   202,   203,   204,    10,    11,    -1,    -1,   209,
     210,    -1,    -1,    18,    19,    20,    -1,    22,    -1,    -1,
      25,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    -1,    -1,    72,    73,    74,
      75,    76,    -1,    78,    -1,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    94,
      -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,   117,    -1,   119,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,   139,   140,    -1,    -1,   143,    -1,
     145,   146,    -1,    -1,   149,   150,    -1,   152,    -1,   154,
      -1,    -1,    -1,    -1,    -1,   160,   161,   162,    -1,   164,
     165,   166,    -1,   168,    -1,   170,    -1,    -1,   173,   174,
      -1,    -1,    -1,   178,    -1,    -1,   181,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,    -1,    -1,     4,    -1,   194,
      -1,    -1,    -1,    10,    11,    -1,   201,   202,   203,   204,
      -1,    18,    19,    20,   209,    22,    -1,    -1,    25,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    -1,    -1,    72,    73,    74,    75,    76,
      -1,    78,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    93,    94,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,    -1,   119,    -1,   121,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,    -1,   139,   140,    -1,    -1,   143,    -1,   145,   146,
      -1,    -1,   149,   150,    -1,   152,    -1,   154,    -1,    -1,
      -1,    -1,    -1,   160,   161,   162,    -1,   164,   165,   166,
      -1,   168,    -1,   170,    -1,    -1,   173,   174,    -1,    -1,
      -1,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,    -1,    -1,     4,    -1,   194,    -1,    -1,
      -1,    10,    11,    -1,   201,   202,   203,   204,    -1,    18,
      19,    20,   209,    22,    -1,    -1,    25,    -1,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    93,    94,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,
     119,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
     139,   140,    -1,    -1,   143,    -1,   145,   146,    -1,    -1,
     149,   150,    -1,   152,    -1,    -1,    -1,    -1,   157,    -1,
      -1,   160,   161,   162,    -1,   164,   165,   166,    -1,   168,
      -1,   170,    -1,    -1,   173,   174,    -1,    -1,    -1,   178,
      -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,    -1,    -1,     4,    -1,   194,    -1,    -1,    -1,    10,
      11,    -1,   201,   202,   203,   204,    -1,    18,    19,    20,
     209,    22,    -1,    -1,    25,    -1,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    49,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    -1,
      -1,    72,    73,    74,    75,    76,    -1,    78,    -1,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    93,    94,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,    -1,   119,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,   139,   140,
      -1,    -1,   143,    -1,   145,   146,    -1,    -1,   149,   150,
      -1,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,   160,
     161,   162,    -1,   164,   165,   166,    -1,   168,    -1,   170,
      -1,    -1,   173,   174,    -1,    -1,    -1,   178,    -1,    -1,
     181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,
      -1,     4,    -1,   194,    -1,    -1,    -1,    10,    11,    -1,
     201,   202,   203,   204,    -1,    18,    19,    20,   209,    22,
      -1,    -1,    25,    -1,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    49,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    -1,    -1,    72,
      73,    74,    75,    76,    -1,    78,    -1,    80,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    94,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,   116,   117,    -1,   119,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,    -1,   139,   140,    -1,    -1,
     143,    -1,   145,   146,    -1,    -1,   149,   150,    -1,   152,
      -1,   154,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,
      -1,   164,   165,   166,    -1,   168,    -1,   170,    -1,    -1,
     173,   174,    -1,    -1,    -1,   178,    -1,    -1,   181,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,     4,
      -1,   194,    -1,    -1,    -1,    10,    11,    -1,   201,   202,
     203,   204,    -1,    18,    19,    20,   209,    22,    -1,    -1,
      25,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    -1,    -1,    72,    73,    74,
      75,    76,    -1,    78,    -1,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    94,
      -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,   117,    -1,   119,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,   139,   140,    -1,    -1,   143,    -1,
     145,   146,    -1,    -1,   149,   150,    -1,   152,    -1,   154,
      -1,    -1,    -1,    -1,    -1,   160,   161,   162,    -1,   164,
     165,   166,    -1,   168,    -1,   170,    -1,    -1,   173,   174,
      -1,    -1,    -1,   178,    -1,    -1,   181,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,    -1,    -1,     4,    -1,   194,
      -1,    -1,    -1,    10,    11,    -1,   201,   202,   203,   204,
      -1,    18,    19,    20,   209,    22,    -1,    -1,    25,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    -1,    -1,    72,    73,    74,    75,    76,
      -1,    78,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    93,    94,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,    -1,   119,    -1,   121,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,    -1,   139,   140,    -1,    -1,   143,    -1,   145,   146,
      -1,    -1,   149,   150,    -1,   152,    -1,   154,    -1,    -1,
      -1,    -1,    -1,   160,   161,   162,    -1,   164,   165,   166,
      -1,   168,    -1,   170,    -1,    -1,   173,   174,    -1,    -1,
      -1,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,    -1,    -1,     4,    -1,   194,    -1,    -1,
      -1,    10,    11,    -1,   201,   202,   203,   204,    -1,    18,
      19,    20,   209,    22,    -1,    -1,    25,    -1,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    93,    94,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,
     119,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
     139,   140,    -1,    -1,   143,    -1,   145,   146,    -1,    -1,
     149,   150,    -1,   152,    -1,   154,    -1,    -1,    -1,    -1,
      -1,   160,   161,   162,    -1,   164,   165,   166,    -1,   168,
      -1,   170,    -1,    -1,   173,   174,    -1,    -1,    -1,   178,
      -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,    -1,    -1,     4,    -1,   194,    -1,    -1,    -1,    10,
      11,    -1,   201,   202,   203,   204,    -1,    18,    19,    20,
     209,    22,    -1,    -1,    25,    -1,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    49,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    -1,
      -1,    72,    73,    74,    75,    76,    -1,    78,    -1,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    93,    94,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,    -1,   119,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,   139,   140,
      -1,    -1,   143,    -1,   145,   146,    -1,    -1,   149,   150,
      -1,   152,    -1,   154,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,    -1,   164,   165,   166,    -1,   168,    -1,   170,
      -1,    -1,   173,   174,    -1,    -1,    -1,   178,    -1,    -1,
     181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,
      -1,     4,    -1,   194,    -1,    -1,    -1,    10,    11,    -1,
     201,   202,   203,   204,    -1,    18,    19,    20,   209,    22,
      -1,    -1,    25,    -1,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    49,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    -1,    -1,    72,
      73,    74,    75,    76,    -1,    78,    -1,    80,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    94,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,   116,   117,    -1,   119,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,    -1,   139,   140,    -1,    -1,
     143,    -1,   145,   146,    -1,    -1,   149,   150,    -1,   152,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,
      -1,   164,   165,   166,    -1,   168,    -1,   170,    -1,    -1,
     173,   174,    -1,    -1,    -1,   178,    -1,    -1,   181,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,     4,
      -1,   194,    -1,    -1,    -1,    10,    11,    -1,   201,   202,
     203,   204,    -1,    18,    19,    20,   209,    22,    -1,    -1,
      25,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    -1,    -1,    72,    73,    74,
      75,    76,    -1,    78,    -1,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    -1,   119,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,   139,   140,    -1,    -1,   143,    -1,
     145,   146,    -1,    -1,   149,   150,    -1,   152,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   161,   162,    -1,   164,
     165,    -1,    -1,   168,     4,   170,    -1,    -1,   173,   174,
      10,    11,    -1,    -1,    -1,    -1,   181,    -1,    18,    19,
      20,    -1,    22,    -1,   189,    25,    -1,    27,    28,   194,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    49,
      50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      -1,    -1,    72,    73,    74,    75,    76,    -1,    78,    -1,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,   136,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,   119,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,   139,
     140,    -1,    -1,   143,    -1,   145,   146,    -1,    -1,   149,
     150,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   161,   162,    -1,   164,   165,    -1,    -1,   168,    -1,
     170,    -1,    -1,   173,   174,   216,    -1,    -1,   219,   220,
     221,   181,   223,   224,   225,   226,   227,    -1,    -1,   189,
      -1,    -1,    -1,   234,   194,   236,    -1,    -1,    -1,    -1,
      -1,   242,    -1,    -1,    -1,    -1,   247,   248,   249,    -1,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    98,    -1,   100,    -1,   220,   221,    -1,   223,
     224,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,   115,
     234,    -1,   236,    -1,   120,    -1,    -1,    -1,    -1,    -1,
     126,    -1,    -1,   247,    -1,    -1,    -1,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   184,   185,
     186,   187,   188
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,     4,    10,    11,    18,    19,    20,    22,    25,    27,
      28,    35,    36,    37,    38,    44,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    68,    69,    72,    73,    74,    75,    76,
      78,    80,    81,    90,    93,    94,    96,   103,   104,   105,
     109,   116,   117,   119,   121,   123,   128,   137,   139,   140,
     143,   145,   146,   149,   150,   152,   160,   161,   162,   164,
     165,   166,   168,   170,   173,   174,   178,   181,   189,   194,
     196,   200,   201,   202,   203,   204,   209,   222,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   299,   300,   301,   302,   306,   307,   308,   309,   310,
     311,   312,   317,   328,   331,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   383,   384,
     385,   398,   399,   401,   402,   403,   404,   405,   406,   407,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     426,   427,   428,   429,   430,   431,   432,   154,   307,   154,
     307,   157,   308,   382,   113,   307,    19,   157,   168,   367,
     307,   157,    23,   151,   171,   151,   171,   131,   151,    23,
     124,   124,    83,    84,    20,    14,    19,   136,   180,    20,
      24,   307,   157,   422,   423,    24,   307,    19,   157,   168,
      24,   329,   330,    24,   313,   314,   307,    23,   124,    23,
      67,   124,   298,    24,   318,   319,   157,   307,    14,   157,
     307,    16,    14,    22,   157,    19,    14,   113,    19,    19,
     359,   359,   329,    19,   307,   157,   307,   307,   307,    26,
      22,   308,   308,   308,   210,   308,    24,   433,   220,   221,
     223,   224,   234,   236,   247,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   445,   446,   447,   448,
     449,   452,   457,   458,     0,   276,   277,   279,   306,   163,
     163,    46,   138,   156,   167,   193,   311,   320,   321,   135,
      29,    87,    95,    98,   100,   111,   115,   120,   126,   148,
     183,   184,   185,   186,   187,   188,   351,   352,   353,   231,
     121,   145,   176,    71,   102,   122,   168,   179,   191,    91,
     110,   108,   177,    40,    41,   121,   145,   350,   113,   357,
     164,   165,   114,   371,   372,   367,   371,   367,   371,   154,
     154,    46,   157,   307,   154,    46,   157,    46,   157,   154,
      46,    46,    23,    23,    74,   157,   158,   303,   304,    87,
      22,   157,   158,   303,    31,    92,    99,   409,   154,   157,
     157,   154,    46,   157,    46,   157,   106,   409,    46,   159,
      33,   106,   243,   315,   316,   409,    46,   157,    33,    14,
      33,   124,    14,    23,    99,   316,   409,    46,   157,    87,
     154,     7,   141,   157,   157,    17,   113,   307,   157,   157,
     159,    19,    85,   172,   387,   388,   154,   157,   154,   154,
     195,    86,   163,    31,   197,   198,   206,    31,   308,   211,
      99,   199,   208,    22,    91,   179,   453,   456,    33,   119,
     454,    33,    66,   119,   451,   281,   282,   283,   308,   308,
     322,   323,   308,   322,   308,   156,   321,   156,   336,   337,
     338,   338,   338,   113,   119,   232,   374,   434,   436,   437,
     438,   439,   440,   441,   442,   341,   341,   340,   342,   342,
     342,   342,   343,   343,   344,   344,    19,   112,   192,   410,
     412,   413,   414,   410,   408,   413,   408,   154,   307,   359,
     359,   307,   372,   308,   154,   113,    19,   424,   424,   107,
     130,   107,   130,    24,    92,   113,   305,   410,    46,   157,
     158,    23,    92,   305,   410,   157,   158,   410,   308,    92,
      99,   113,    19,   424,   425,   424,   425,   308,   106,    74,
     308,    74,   308,    74,   106,   316,   106,   106,   315,   316,
      74,   175,    23,   297,    87,   297,    87,    33,   308,    99,
      99,   316,    74,    23,   154,   307,   154,   308,    87,     8,
       9,    12,    42,    77,    79,   169,   305,   384,   386,   396,
     397,   400,    85,   172,   388,    39,   332,   333,    22,   205,
     207,   308,   308,   308,   308,   211,   308,   308,    24,   308,
     454,   454,   456,    22,    22,   455,   453,    22,    66,   451,
     163,    32,    45,    70,    83,    84,   324,   325,   326,   327,
      46,   308,   156,   308,   307,   434,   440,   250,   468,   136,
     216,   219,   225,   226,   227,   233,   242,   248,   249,   435,
     443,   444,   445,   459,   462,   463,   465,   230,   237,   238,
     464,   212,   213,   214,   215,   240,   460,   132,   133,   134,
     411,   101,   154,   155,   154,   307,   157,   157,   409,   307,
      92,   305,   304,    92,   305,   410,    92,   305,    92,   305,
     410,   308,   154,   307,   101,   157,   157,   157,   157,   308,
     330,    24,    24,   308,   106,   308,   308,   106,   316,   106,
     314,   308,    46,    23,   297,   308,   308,    99,   319,   163,
     154,   113,    30,   153,   389,     6,    19,   169,   396,   169,
     386,    74,   410,    66,   333,   163,   308,   308,   308,    99,
     156,    22,   157,   217,   218,   228,   229,   241,   461,    46,
     157,    46,   157,    23,   326,   327,   327,   323,   308,   154,
     157,   342,   239,   244,   467,   461,   437,   467,   339,   342,
     248,   443,   445,   438,   439,   461,   154,   154,    92,   305,
      92,   305,   154,   308,   308,   106,   308,    82,    23,    33,
     308,   154,   307,     3,    88,   392,   393,   395,   397,    21,
      89,   390,   391,   394,   397,    43,   172,    19,    19,   169,
      24,   156,    74,   156,   308,   308,   342,   342,   342,   342,
      22,   235,   450,   451,   450,   327,   239,   245,   262,   466,
     466,   339,   246,   308,   308,   297,   154,    30,    88,   395,
     153,    89,   394,   172,   172,    19,    31,   308,    24,   308,
     176,   461,    46,   157,   157,   172,   410,   156,   342,   235,
     451,   156,   308,   308
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
     525,   526,   527
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   273,   274,   274,   274,   274,   275,   275,   276,   276,
     277,   278,   279,   279,   279,   280,   280,   281,   281,   282,
     282,   282,   282,   283,   283,   283,   283,   284,   284,   284,
     284,   284,   284,   284,   284,   285,   285,   286,   287,   287,
     288,   288,   289,   290,   291,   291,   292,   292,   293,   293,
     293,   293,   294,   295,   296,   296,   296,   296,   297,   297,
     298,   298,   299,   299,   299,   299,   300,   300,   300,   300,
     301,   301,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   303,   303,
     304,   304,   305,   306,   307,   307,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   309,   309,   309,   309,
     310,   310,   311,   311,   312,   313,   313,   314,   314,   314,
     314,   314,   314,   314,   314,   315,   316,   317,   318,   318,
     319,   319,   319,   319,   320,   321,   321,   322,   322,   323,
     323,   324,   324,   324,   324,   324,   324,   324,   325,   325,
     326,   326,   327,   328,   328,   329,   329,   330,   330,   331,
     331,   332,   332,   333,   333,   334,   335,   335,   336,   336,
     337,   337,   337,   337,   338,   338,   338,   339,   339,   340,
     340,   340,   341,   341,   341,   341,   341,   342,   342,   342,
     343,   343,   343,   344,   344,   345,   345,   346,   346,   347,
     347,   348,   348,   349,   349,   349,   349,   350,   350,   350,
     351,   351,   351,   351,   351,   351,   352,   352,   352,   352,
     352,   352,   353,   353,   353,   354,   354,   355,   355,   356,
     356,   357,   358,   358,   358,   358,   359,   359,   359,   360,
     360,   361,   361,   361,   361,   362,   362,   363,   363,   363,
     363,   363,   363,   363,   364,   364,   365,   365,   366,   366,
     366,   366,   366,   367,   367,   368,   368,   369,   369,   369,
     370,   370,   371,   371,   372,   373,   373,   373,   373,   373,
     373,   373,   373,   374,   374,   375,   375,   375,   376,   377,
     377,   378,   379,   380,   381,   381,   382,   382,   383,   383,
     384,   384,   384,   385,   385,   385,   385,   385,   385,   386,
     386,   387,   387,   388,   389,   389,   390,   390,   391,   391,
     391,   391,   392,   392,   393,   393,   393,   393,   394,   394,
     395,   395,   396,   396,   396,   396,   397,   397,   397,   397,
     397,   398,   399,   399,   400,   401,   401,   401,   401,   401,
     401,   402,   403,   403,   403,   403,   404,   404,   404,   404,
     405,   406,   407,   407,   407,   407,   408,   408,   409,   410,
     410,   410,   411,   411,   411,   412,   412,   412,   413,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   415,   416,
     416,   416,   417,   418,   419,   419,   419,   420,   420,   420,
     420,   420,   421,   422,   422,   422,   422,   422,   422,   422,
     423,   424,   425,   426,   427,   428,   428,   428,   428,   428,
     429,   430,   430,   431,   432,   433,   433,   434,   434,   434,
     434,   435,   435,   435,   435,   436,   436,   437,   437,   438,
     438,   439,   439,   440,   440,   440,   441,   441,   442,   442,
     443,   443,   443,   443,   443,   444,   445,   445,   445,   445,
     445,   445,   445,   446,   446,   446,   446,   447,   447,   447,
     447,   448,   448,   449,   449,   449,   449,   449,   449,   449,
     450,   450,   451,   451,   451,   451,   452,   452,   452,   452,
     452,   453,   453,   454,   454,   455,   455,   456,   456,   457,
     458,   458,   459,   459,   459,   460,   460,   460,   460,   460,
     461,   461,   461,   461,   462,   463,   464,   465,   465,   466,
     466,   466,   467,   467,   468
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
       1,     3,     3,     3,     3,     1,     1,     1,     1,     1,
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
  "\"'<at URI>'\"", "\"'char literal'\"", "\"'char literal and pi end'\"",
  "\"'#charref;'\"", "\"'element content'\"", "\"'<QName {>'\"",
  "\"'pref:*'\"", "\"'&entity;'\"", "\"'comment literal'\"",
  "\"'NCName'\"", "\"'pi <NCName {>'\"", "\"'pi target'\"",
  "\"'pragma literal and end'\"", "\"'*:QName'\"", "\"'QName'\"",
  "\"'<QName (>'\"", "\"'quote attribute content'\"", "\"'STRING'\"",
  "\"'URI'\"", "\"'variable name'\"", "\"'validate mode'\"",
  "\"'XML comment'\"", "\"'ancestor::'\"", "\"'ancestor-or-self::'\"",
  "\"'and'\"", "\"'''\"", "\"'as'\"", "\"'ascending'\"", "\"'at'\"",
  "\"'attribute'\"", "\"'attribute::'\"", "\"'<attribute {>'\"",
  "\"'<attribute (>'\"", "\"'@'\"", "\"'case'\"", "\"'<castable as>'\"",
  "\"'<cast as>'\"", "\"'CDATA[['\"", "\"']]'\"", "\"'child::'\"",
  "\"'collation'\"", "\"','\"", "\"'(:'\"", "\"':)'\"",
  "\"'<comment {>'\"", "\"'<comment (>'\"", "\"'DECIMAL'\"",
  "\"'<declare base URI>'\"", "\"'<declare boundary space>'\"",
  "\"'<declare construction>'\"", "\"'<declare copy namespaces>'\"",
  "\"'<declare default collation>'\"", "\"'<declare default element>'\"",
  "\"'<declare default function>'\"", "\"'<declare default order>'\"",
  "\"'<declare function>'\"", "\"'<declare namespace>'\"",
  "\"'<declare option>'\"", "\"'<declare ordering>'\"",
  "\"'<declare updating function>'\"", "\"'<declare var $>'\"",
  "\"'default'\"", "\"'<default element>'\"", "\"'descendant::'\"",
  "\"'descendant-or-self::'\"", "\"'descending'\"", "\"'div'\"",
  "\"'<document {>'\"", "\"'<document node (>'\"", "\"'$'\"", "\"'.'\"",
  "\"'..'\"", "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"",
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
       274,     0,    -1,   276,    -1,   275,   276,    -1,   277,    -1,
     275,   277,    -1,   196,    22,   163,    -1,   196,    22,    86,
      22,   163,    -1,   279,   306,    -1,   306,    -1,   278,   279,
      -1,   123,    14,    87,    23,   163,    -1,   280,   163,    -1,
     281,   163,    -1,   280,   163,   281,   163,    -1,   282,    -1,
     280,   163,   282,    -1,   283,    -1,   281,   163,   283,    -1,
     284,    -1,   285,    -1,   286,    -1,   288,    -1,   300,    -1,
     302,    -1,   289,    -1,   290,    -1,   287,    -1,   294,    -1,
     295,    -1,   301,    -1,   291,    -1,   292,    -1,   293,    -1,
     427,    -1,   296,    -1,   299,    -1,    61,    14,    87,    23,
      -1,    53,   151,    -1,    53,   171,    -1,    57,   124,    23,
      -1,    58,   124,    23,    -1,    62,    19,    22,    -1,   222,
     445,    -1,    63,   136,    -1,    63,   180,    -1,    59,    83,
      -1,    59,    84,    -1,    55,   151,    46,   107,    -1,    55,
     151,    46,   130,    -1,    55,   131,    46,   107,    -1,    55,
     131,    46,   130,    -1,    56,    23,    -1,    52,    23,    -1,
     105,    23,    -1,   105,   298,    23,    -1,   105,    23,    33,
     297,    -1,   105,   298,    23,    33,   297,    -1,    23,    -1,
     297,    46,    23,    -1,   124,    14,    87,    -1,    67,   124,
      -1,   104,    23,    -1,   104,   124,    14,    87,    23,    -1,
     104,    23,    33,   297,    -1,   104,   124,    14,    87,    23,
      33,   297,    -1,    65,    24,    99,   308,    -1,    65,    24,
      92,    -1,    65,    24,   409,    99,   308,    -1,    65,    24,
     409,    92,    -1,    54,   151,    -1,    54,   171,    -1,    60,
      20,   157,    92,    -1,    60,    20,   157,   305,    -1,    60,
      20,   303,   157,    92,    -1,    60,    20,   303,   157,   305,
      -1,    60,    20,   158,   410,    92,    -1,    60,    20,   158,
     410,   305,    -1,    60,    20,   303,   158,   410,    92,    -1,
      60,    20,   303,   158,   410,   305,    -1,    64,    20,   157,
      92,    -1,    64,    20,   157,   305,    -1,    64,    20,   303,
     157,    92,    -1,    64,    20,   303,   157,   305,    -1,    64,
      20,   158,   410,    92,    -1,    64,    20,   158,   410,   305,
      -1,    64,    20,   303,   158,   410,    92,    -1,    64,    20,
     303,   158,   410,   305,    -1,   304,    -1,   303,    46,   304,
      -1,    74,    24,    -1,    74,    24,   409,    -1,   113,   307,
     154,    -1,   307,    -1,   308,    -1,   307,    46,   308,    -1,
     309,    -1,   328,    -1,   331,    -1,   334,    -1,   335,    -1,
     428,    -1,   429,    -1,   431,    -1,   430,    -1,   432,    -1,
     310,   156,   308,    -1,   310,   320,   156,   308,    -1,   310,
     321,   156,   308,    -1,   310,   320,   321,   156,   308,    -1,
     311,    -1,   310,   311,    -1,   312,    -1,   317,    -1,    96,
     313,    -1,   314,    -1,   313,    46,    74,   314,    -1,    24,
     106,   308,    -1,    24,   409,   106,   308,    -1,    24,   315,
     106,   308,    -1,    24,   409,   315,   106,   308,    -1,    24,
     316,   106,   308,    -1,    24,   409,   316,   106,   308,    -1,
      24,   315,   316,   106,   308,    -1,    24,   409,   315,   316,
     106,   308,    -1,    33,    74,    24,    -1,   243,    74,    24,
      -1,   117,   318,    -1,   319,    -1,   318,    46,    74,   319,
      -1,    24,    99,   308,    -1,    24,   409,    99,   308,    -1,
      24,   316,    99,   308,    -1,    24,   409,   316,    99,   308,
      -1,   193,   308,    -1,   138,   322,    -1,   167,   322,    -1,
     323,    -1,   322,    46,   323,    -1,   308,    -1,   308,   324,
      -1,   325,    -1,   326,    -1,   327,    -1,   325,   326,    -1,
     325,   327,    -1,   326,   327,    -1,   325,   326,   327,    -1,
      32,    -1,    70,    -1,    83,    -1,    84,    -1,    45,    23,
      -1,   166,   329,   159,   308,    -1,    90,   329,   159,   308,
      -1,   330,    -1,   329,    46,    74,   330,    -1,    24,   106,
     308,    -1,    24,   409,   106,   308,    -1,   178,   307,   157,
     332,    66,   156,   308,    -1,   178,   307,   157,   332,    66,
      74,    24,   156,   308,    -1,   333,    -1,   332,   333,    -1,
      39,   410,   156,   308,    -1,    39,    74,    24,    31,   410,
     156,   308,    -1,   103,   307,   157,   175,   308,    82,   308,
      -1,   336,    -1,   335,   135,   336,    -1,   337,    -1,   336,
      29,   337,    -1,   338,    -1,   338,   352,   338,    -1,   338,
     351,   338,    -1,   338,   353,   338,    -1,   339,    -1,   339,
     231,   434,    -1,   339,   231,   434,   468,    -1,   340,    -1,
     340,   176,   340,    -1,   341,    -1,   340,   145,   341,    -1,
     340,   121,   341,    -1,   342,    -1,   341,   168,   342,    -1,
     341,    71,   342,    -1,   341,   102,   342,    -1,   341,   122,
     342,    -1,   343,    -1,   342,   179,   343,    -1,   342,   191,
     343,    -1,   344,    -1,   343,   110,   344,    -1,   343,    91,
     344,    -1,   345,    -1,   345,   108,   410,    -1,   346,    -1,
     346,   177,   410,    -1,   347,    -1,   347,    40,   408,    -1,
     348,    -1,   348,    41,   408,    -1,   350,    -1,   349,   350,
      -1,   145,    -1,   121,    -1,   349,   145,    -1,   349,   121,
      -1,   354,    -1,   358,    -1,   355,    -1,    87,    -1,   126,
      -1,   120,    -1,   115,    -1,   100,    -1,    98,    -1,   183,
      -1,   188,    -1,   187,    -1,   186,    -1,   185,    -1,   184,
      -1,   111,    -1,   148,    -1,    95,    -1,   189,   307,   154,
      -1,    25,   113,   307,   154,    -1,   356,   113,   154,    -1,
     356,   113,   307,   154,    -1,   357,    -1,   356,   357,    -1,
     146,    19,    17,    -1,   116,    -1,   164,   359,    -1,   165,
     359,    -1,   359,    -1,   360,    -1,   360,   164,   359,    -1,
     360,   165,   359,    -1,   361,    -1,   370,    -1,   362,    -1,
     362,   371,    -1,   365,    -1,   365,   371,    -1,   363,   367,
      -1,   364,    -1,    44,    -1,    68,    -1,    35,    -1,   162,
      -1,    69,    -1,    94,    -1,    93,    -1,   367,    -1,    38,
     367,    -1,   366,   367,    -1,    76,    -1,   139,    -1,    27,
      -1,   150,    -1,   149,    -1,    28,    -1,   414,    -1,   368,
      -1,    19,    -1,   369,    -1,   168,    -1,    11,    -1,    18,
      -1,   373,    -1,   373,   371,    -1,   372,    -1,   371,   372,
      -1,   114,   307,   155,    -1,   374,    -1,   376,    -1,   377,
      -1,   378,    -1,   381,    -1,   383,    -1,   379,    -1,   380,
      -1,   375,    -1,   426,    -1,    51,    -1,   109,    -1,    78,
      -1,    74,    24,    -1,   119,   157,    -1,   119,   307,   157,
      -1,    75,    -1,   137,   307,   154,    -1,   181,   307,   154,
      -1,    20,   157,    -1,    20,   382,   157,    -1,   308,    -1,
     382,    46,   308,    -1,   384,    -1,   401,    -1,   385,    -1,
     398,    -1,   399,    -1,   170,    19,    85,    -1,   170,    19,
     387,    85,    -1,   170,    19,   172,   169,    19,   172,    -1,
     170,    19,   172,   386,   169,    19,   172,    -1,   170,    19,
     387,   172,   169,    19,   172,    -1,   170,    19,   387,   172,
     386,   169,    19,   172,    -1,   396,    -1,   386,   396,    -1,
     388,    -1,   387,   388,    -1,    19,    87,   389,    -1,   153,
     390,   153,    -1,    30,   392,    30,    -1,    -1,   391,    -1,
      89,    -1,   394,    -1,   391,    89,    -1,   391,   394,    -1,
      -1,   393,    -1,    88,    -1,   395,    -1,   393,    88,    -1,
     393,   395,    -1,    21,    -1,   397,    -1,     3,    -1,   397,
      -1,   384,    -1,     9,    -1,   400,    -1,   397,    -1,    12,
      -1,     8,    -1,    77,    -1,    79,    -1,   305,    -1,   194,
      26,   195,    -1,   140,    16,   141,    -1,   140,    16,     7,
      -1,    42,     6,    43,    -1,   402,    -1,   403,    -1,   404,
      -1,   405,    -1,   406,    -1,   407,    -1,    72,   307,   154,
      -1,    10,   154,    -1,    10,   307,   154,    -1,    80,   307,
     154,   113,   154,    -1,    80,   307,   154,   113,   307,   154,
      -1,     4,   154,    -1,     4,   307,   154,    -1,    36,   307,
     154,   113,   154,    -1,    36,   307,   154,   113,   307,   154,
      -1,   173,   307,   154,    -1,    49,   307,   154,    -1,   152,
      14,   113,   154,    -1,   152,    14,   113,   307,   154,    -1,
     152,   113,   307,   154,   113,   154,    -1,   152,   113,   307,
     154,   113,   307,   154,    -1,   413,    -1,   413,   101,    -1,
      31,   410,    -1,   412,    -1,   412,   411,    -1,   192,    -1,
     132,    -1,   134,    -1,   133,    -1,   413,    -1,   414,    -1,
     112,    -1,    19,    -1,   416,    -1,   422,    -1,   420,    -1,
     423,    -1,   421,    -1,   419,    -1,   418,    -1,   417,    -1,
     415,    -1,   128,   157,    -1,    73,   157,    -1,    73,   422,
     157,    -1,    73,   423,   157,    -1,   174,   157,    -1,    50,
     157,    -1,   143,   157,    -1,   143,    14,   157,    -1,   143,
      22,   157,    -1,    37,   157,    -1,    37,    19,   157,    -1,
      37,    19,    46,   424,   157,    -1,    37,   168,   157,    -1,
      37,   168,    46,   424,   157,    -1,   160,    19,   157,    -1,
      81,   157,    -1,    81,    19,   157,    -1,    81,    19,    46,
     424,   157,    -1,    81,    19,    46,   425,   157,    -1,    81,
     168,   157,    -1,    81,   168,    46,   424,   157,    -1,    81,
     168,    46,   425,   157,    -1,   161,    19,   157,    -1,    19,
      -1,    19,   101,    -1,    22,    -1,   200,    -1,   202,   308,
     206,   308,    -1,   202,   308,    31,   205,   308,    -1,   202,
     308,    31,   207,   308,    -1,   202,   308,   197,   308,    -1,
     202,   308,   198,   308,    -1,   201,   308,    -1,   204,   308,
     211,   308,    -1,   204,   210,   308,   211,   308,    -1,   203,
     308,    31,   308,    -1,   209,   433,   208,   308,   156,   308,
      -1,    24,    99,   308,    -1,   433,   199,    24,    99,   308,
      -1,   436,    -1,   436,   435,    -1,   436,   248,   339,    -1,
     436,   435,   248,   339,    -1,   445,    -1,   443,    -1,   435,
     445,    -1,   435,   443,    -1,   437,    -1,   436,   233,   437,
      -1,   438,    -1,   437,   230,   438,    -1,   439,    -1,   438,
     237,   439,    -1,   440,    -1,   232,   440,    -1,   441,    -1,
     441,   464,    -1,   119,   434,   157,    -1,   442,    -1,   442,
     460,    -1,   374,    -1,   113,   307,   154,    -1,   444,    -1,
     463,    -1,   462,    -1,   465,    -1,   459,    -1,   136,    -1,
     446,    -1,   447,    -1,   448,    -1,   449,    -1,   452,    -1,
     457,    -1,   458,    -1,   236,    -1,   247,    -1,   221,    -1,
     220,    -1,   257,    -1,   251,    -1,   224,    -1,   223,    -1,
     258,    -1,   252,    -1,   260,   451,    -1,   260,    66,    -1,
     260,   119,   451,   157,    -1,   260,   119,   451,    46,   450,
     157,    -1,   260,   119,    66,   157,    -1,   260,   119,    66,
      46,   450,   157,    -1,   254,    -1,   451,    -1,   450,    46,
     451,    -1,    33,    22,    -1,    33,    22,   241,    22,    -1,
      33,    22,   461,   235,    -1,    33,    22,   241,    22,   461,
     235,    -1,   259,   454,    -1,   259,   454,   453,    -1,   256,
      -1,   256,   453,    -1,   253,    -1,   456,    -1,   453,   456,
      -1,    33,    22,    -1,   119,   455,   157,    -1,    22,    -1,
     455,    22,    -1,   179,   454,    -1,    91,   454,    -1,   234,
      22,    -1,   261,    -1,   255,    -1,   219,    -1,   216,    -1,
     227,    -1,   214,    -1,   215,    -1,   212,    -1,   213,    -1,
     240,    -1,   228,   342,    -1,   217,   342,    -1,   218,   342,
      -1,   229,   342,   176,   342,    -1,   226,   461,   466,    -1,
     249,   342,   466,    -1,   238,   461,   246,    -1,   242,   467,
      -1,   225,   467,    -1,   262,    -1,   245,    -1,   239,    -1,
     244,    -1,   239,    -1,   250,   342,    -1
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
    1097,  1099,  1103,  1107,  1111,  1115,  1117,  1119,  1121,  1123,
    1125,  1127,  1131,  1134,  1138,  1144,  1151,  1154,  1158,  1164,
    1171,  1175,  1179,  1184,  1190,  1197,  1205,  1207,  1210,  1213,
    1215,  1218,  1220,  1222,  1224,  1226,  1228,  1230,  1232,  1234,
    1236,  1238,  1240,  1242,  1244,  1246,  1248,  1250,  1252,  1255,
    1258,  1262,  1266,  1269,  1272,  1275,  1279,  1283,  1286,  1290,
    1296,  1300,  1306,  1310,  1313,  1317,  1323,  1329,  1333,  1339,
    1345,  1349,  1351,  1354,  1356,  1358,  1363,  1369,  1375,  1380,
    1385,  1388,  1393,  1399,  1404,  1411,  1415,  1421,  1423,  1426,
    1430,  1435,  1437,  1439,  1442,  1445,  1447,  1451,  1453,  1457,
    1459,  1463,  1465,  1468,  1470,  1473,  1477,  1479,  1482,  1484,
    1488,  1490,  1492,  1494,  1496,  1498,  1500,  1502,  1504,  1506,
    1508,  1510,  1512,  1514,  1516,  1518,  1520,  1522,  1524,  1526,
    1528,  1530,  1532,  1534,  1537,  1540,  1545,  1552,  1557,  1564,
    1566,  1568,  1572,  1575,  1580,  1585,  1592,  1595,  1599,  1601,
    1604,  1606,  1608,  1611,  1614,  1618,  1620,  1623,  1626,  1629,
    1632,  1634,  1636,  1638,  1640,  1642,  1644,  1646,  1648,  1650,
    1652,  1655,  1658,  1661,  1666,  1670,  1674,  1678,  1681,  1684,
    1686,  1688,  1690,  1692,  1694
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
    1822,  1831,  1838,  1845,  1852,  1859,  1872,  1882,  1893,  1904,
    1921,  1930,  1945,  1952,  1965,  1979,  1988,  2005,  2015,  2026,
    2038,  2051,  2062,  2074,  2086,  2104,  2119,  2133,  2148,  2157,
    2174,  2185,  2197,  2208,  2226,  2240,  2248,  2263,  2272,  2289,
    2298,  2313,  2323,  2333,  2343,  2353,  2363,  2373,  2389,  2396,
    2409,  2417,  2431,  2445,  2455,  2471,  2481,  2496,  2505,  2521,
    2531,  2548,  2557,  2572,  2581,  2597,  2611,  2618,  2632,  2639,
    2661,  2668,  2679,  2690,  2707,  2714,  2724,  2740,  2747,  2761,
    2768,  2775,  2788,  2794,  2801,  2808,  2815,  2828,  2835,  2843,
    2857,  2864,  2871,  2884,  2891,  2906,  2913,  2928,  2935,  2950,
    2957,  2972,  2979,  2994,  3001,  3008,  3015,  3030,  3037,  3044,
    3058,  3065,  3072,  3079,  3086,  3093,  3106,  3113,  3120,  3127,
    3134,  3141,  3154,  3161,  3168,  3182,  3189,  3204,  3213,  3228,
    3237,  3254,  3300,  3307,  3314,  3321,  3335,  3343,  3350,  3363,
    3370,  3383,  3392,  3401,  3410,  3425,  3434,  3448,  3455,  3462,
    3469,  3476,  3483,  3490,  3503,  3510,  3523,  3532,  3547,  3554,
    3561,  3568,  3575,  3593,  3600,  3613,  3620,  3633,  3643,  3653,
    3669,  3676,  3691,  3700,  3717,  3731,  3738,  3745,  3752,  3759,
    3766,  3773,  3780,  3793,  3800,  3813,  3820,  3827,  3840,  3853,
    3860,  3874,  3887,  3901,  3960,  3969,  3984,  3993,  4008,  4015,
    4028,  4035,  4042,  4055,  4066,  4077,  4088,  4099,  4110,  4128,
    4137,  4152,  4161,  4178,  4193,  4201,  4216,  4222,  4229,  4238,
    4247,  4258,  4275,  4281,  4288,  4297,  4306,  4317,  4334,  4342,
    4356,  4364,  4378,  4386,  4394,  4403,  4418,  4427,  4436,  4444,
    4452,  4466,  4485,  4493,  4513,  4531,  4538,  4545,  4552,  4559,
    4566,  4579,  4593,  4602,  4611,  4619,  4647,  4656,  4665,  4673,
    4687,  4701,  4715,  4724,  4733,  4741,  4755,  4764,  4779,  4793,
    4802,  4811,  4851,  4859,  4867,  4881,  4888,  4895,  4908,  4922,
    4929,  4936,  4943,  4950,  4957,  4964,  4971,  4978,  4991,  5004,
    5011,  5019,  5033,  5046,  5059,  5066,  5073,  5086,  5095,  5104,
    5113,  5122,  5137,  5151,  5160,  5169,  5178,  5187,  5197,  5207,
    5223,  5247,  5257,  5280,  5322,  5334,  5340,  5346,  5352,  5358,
    5370,  5382,  5388,  5400,  5427,  5439,  5445,  5465,  5471,  5477,
    5483,  5495,  5501,  5507,  5513,  5525,  5531,  5543,  5549,  5561,
    5567,  5579,  5585,  5597,  5603,  5609,  5621,  5627,  5639,  5645,
    5657,  5663,  5669,  5675,  5681,  5693,  5705,  5712,  5719,  5726,
    5733,  5740,  5747,  5760,  5766,  5772,  5778,  5790,  5796,  5802,
    5808,  5820,  5826,  5838,  5844,  5850,  5856,  5862,  5868,  5874,
    5886,  5892,  5904,  5910,  5916,  5922,  5934,  5940,  5946,  5952,
    5958,  5970,  5976,  5988,  5994,  6006,  6012,  6024,  6030,  6042,
    6054,  6060,  6072,  6078,  6084,  6096,  6102,  6108,  6114,  6120,
    6132,  6138,  6144,  6150,  6162,  6174,  6186,  6198,  6204,  6216,
    6222,  6228,  6240,  6246,  6258
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
     265,   266,   267,   268,   269,   270,   271,   272
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 3732;
  const int xquery_parser::yynnts_ = 196;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 314;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 273;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 527;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace yy

#line 6268 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"



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





