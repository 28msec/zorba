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
#line 126 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

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
    #line 87 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = driver.filename;
}
  /* Line 555 of yacc.c.  */
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
#line 726 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Module [main]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr((yyval.node));
		;}
    break;

  case 3:
#line 732 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Module [version.main]\n";
		;}
    break;

  case 4:
#line 736 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Module [library]\n";
		;}
    break;

  case 5:
#line 740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Module [version.library]\n";
		;}
    break;

  case 6:
#line 750 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VersionDecl [version]\n";
		;}
    break;

  case 7:
#line 754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VersionDecl [version.encoding]\n";
		;}
    break;

  case 8:
#line 764 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "MainModule [prolog.querybody]\n";
			(yyval.node) = new MainModule((yyloc),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)));
		;}
    break;

  case 9:
#line 772 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "MainModule [querybody]\n";
			(yyval.node) = new MainModule((yyloc),
								NULL,
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 10:
#line 785 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "LibraryModule [ ]\n";
			(yyval.node) = new LibraryModule((yyloc),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 11:
#line 798 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ModuleDecl [ ]\n";
			(yyval.node) = new ModuleDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)), 
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (4)].sval)));
		;}
    break;

  case 12:
#line 811 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Prolog [sind]\n";
			(yyval.node) = new Prolog((yyloc),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 13:
#line 818 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Prolog [vfo]\n";
			(yyval.node) = new Prolog((yyloc),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 14:
#line 825 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Prolog [sind.vfo]\n";
			(yyval.node) = new Prolog((yyloc),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 15:
#line 838 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SIND_DeclList [single]\n";
			SIND_DeclList* sindList_p = new SIND_DeclList((yyloc));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 16:
#line 845 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 860 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VFO_DeclList [single]\n";
			VFO_DeclList* vfoList_p = new VFO_DeclList((yyloc));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 18:
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 882 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SIND_Decl [setter]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 887 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SIND_Decl [import]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SIND_Decl [namespace]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 897 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SIND_Decl [default namespace]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VFO_Decl [var]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 912 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VFO_Decl [function]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 917 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VFO_Decl [option]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 924 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VFO_Decl [ftoption]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 935 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Setter [boundary space]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 940 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Setter [default collation]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 945 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Setter [base uri]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 950 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Setter [construction]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 955 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Setter [ordering mode]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 960 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Setter [empty order]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 965 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Setter [copy namespaces]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 972 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Setter [revalidation]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 983 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Import [schema]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 988 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Import [module]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 1004 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NamespaceDecl [ ]\n";
			(yyval.node) = new NamespaceDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								driver.symtab.get((off_t)44));
		;}
    break;

  case 38:
#line 1017 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "BoundarySpaceDecl [preserve]\n";
			(yyval.node) = new BoundarySpaceDecl((yyloc),
								StaticQueryContext::preserve_space);
		;}
    break;

  case 39:
#line 1023 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "BoundarySpaceDecl [strip]\n";
			(yyval.node) = new BoundarySpaceDecl((yyloc),
								StaticQueryContext::strip_space);
		;}
    break;

  case 40:
#line 1035 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DefaultNamespaceDecl [element]\n";
			(yyval.node) = new DefaultNamespaceDecl((yyloc),
								ns_element_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 41:
#line 1042 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DefaultNamespaceDecl [function]\n";
			(yyval.node) = new DefaultNamespaceDecl((yyloc),
								ns_function_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 42:
#line 1055 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OptionDecl [ ]\n";
			(yyval.node) = new OptionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 43:
#line 1069 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTOptionDecl [ ]\n";
			(yyval.node) = new FTOptionDecl((yyloc),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 44:
#line 1081 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderingDecl [ordered]\n";
			(yyval.node) = new OrderingModeDecl((yyloc),
								StaticQueryContext::ordered);
		;}
    break;

  case 45:
#line 1087 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderingDecl [unordered]\n";
			(yyval.node) = new OrderingModeDecl((yyloc),
								StaticQueryContext::unordered);
		;}
    break;

  case 46:
#line 1100 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "EmptyOrderDecl [empty greatest]\n";
			(yyval.node) = new EmptyOrderDecl((yyloc),
								StaticQueryContext::empty_greatest);
		;}
    break;

  case 47:
#line 1106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "EmptyOrderDecl [empty least]\n";
			(yyval.node) = new EmptyOrderDecl((yyloc),
								StaticQueryContext::empty_least);
		;}
    break;

  case 48:
#line 1118 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CopyNamespacesDecl [ ]\n";
			(yyval.node) = new CopyNamespacesDecl((yyloc),
								StaticQueryContext::preserve_ns,
								StaticQueryContext::inherit_ns);
		;}
    break;

  case 49:
#line 1125 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CopyNamespacesDecl [ ]\n";
			(yyval.node) = new CopyNamespacesDecl((yyloc),
								StaticQueryContext::preserve_ns,
								StaticQueryContext::no_inherit_ns);
		;}
    break;

  case 50:
#line 1132 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CopyNamespacesDecl [ ]\n";
			(yyval.node) = new CopyNamespacesDecl((yyloc),
								StaticQueryContext::no_preserve_ns,
								StaticQueryContext::inherit_ns);
		;}
    break;

  case 51:
#line 1139 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CopyNamespacesDecl [ ]\n";
			(yyval.node) = new CopyNamespacesDecl((yyloc),
								StaticQueryContext::no_preserve_ns,
								StaticQueryContext::no_inherit_ns);
		;}
    break;

  case 52:
#line 1159 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DefaultCollationMode [ ]\n";
			(yyval.node) = new DefaultCollationDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 53:
#line 1171 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "BaseURIDecl [ ]\n";
			(yyval.node) = new BaseURIDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 54:
#line 1183 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SchemaImport [uri]\n";
			(yyval.node) = new SchemaImport((yyloc),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 55:
#line 1191 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SchemaImport [prefix.uri]\n";
			(yyval.node) = new SchemaImport((yyloc),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(3) - (2)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 56:
#line 1199 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SchemaImport [uri.urilist]\n";
			(yyval.node) = new SchemaImport((yyloc),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 57:
#line 1207 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SchemaImport [prefix.uri.aturi]\n";
			(yyval.node) = new SchemaImport((yyloc),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(5) - (2)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 58:
#line 1221 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "URILiteralList [single]\n";
			URILiteralList* uri_list_p = new URILiteralList((yyloc));
			uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 59:
#line 1228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1244 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SchemaPrefix [namespace]\n";
			(yyval.node) = new SchemaPrefix((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SchemaPrefix [default element]\n";
			(yyval.node) = new SchemaPrefix((yyloc), true);
		;}
    break;

  case 62:
#line 1260 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ModuleImport [uri]\n";
			(yyval.node) = new ModuleImport((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 63:
#line 1267 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ModuleImport [namespace.uri]\n";
			(yyval.node) = new ModuleImport((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)),
								NULL);
		;}
    break;

  case 64:
#line 1275 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ModuleImport [uri.at_uri.list]\n";
			(yyval.node) = new ModuleImport((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 65:
#line 1282 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ModuleImport [namespace.uri.at_uri.list]\n";
			(yyval.node) = new ModuleImport((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (5)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(7) - (7)].node)));
		;}
    break;

  case 66:
#line 1297 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarDecl [expr]\n";
			(yyval.node) = new VarDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 67:
#line 1305 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarDecl [external]\n";
			(yyval.node) = new VarDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								NULL,
								NULL);
		;}
    break;

  case 68:
#line 1313 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarDecl [type.expr]\n";
			(yyval.node) = new VarDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 69:
#line 1321 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarDecl [type.external]\n";
			(yyval.node) = new VarDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (3)].node)),
								NULL);
		;}
    break;

  case 70:
#line 1335 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ConstructionDecl [preserve]\n";
			(yyval.node) = new ConstructionDecl((yyloc),
								StaticQueryContext::cons_preserve);
		;}
    break;

  case 71:
#line 1341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ConstructionDecl [strip]\n";
			(yyval.node) = new ConstructionDecl((yyloc),
								StaticQueryContext::cons_strip);
		;}
    break;

  case 72:
#line 1353 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionDecl [external]\n";
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,NULL,NULL,
								fn_extern);
		;}
    break;

  case 73:
#line 1361 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1370 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1379 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1389 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1399 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1409 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1419 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1429 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionDecl [(update) external]\n";
			(yyval.node) = new FunctionDecl((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,NULL,NULL,
								fn_extern_update);
		;}
    break;

  case 81:
#line 1437 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1446 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1455 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1465 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1475 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1485 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1495 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1511 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1520 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1535 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Param [varname]\n";
			(yyval.node) = new Param((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 91:
#line 1542 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Param [varname.type]\n";
			(yyval.node) = new Param((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 92:
#line 1555 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "EnclosedExpr [ ]\n";
			(yyval.expr) = new EnclosedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1567 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QueryBody [expr]\n";
			(yyval.expr) = new QueryBody((yyloc),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 94:
#line 1579 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Expr [single]\n";
			Expr* expr_p = new Expr((yyloc));
			expr_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 95:
#line 1586 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Expr [expr.single]\n";
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p) expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
		;}
    break;

  case 96:
#line 1599 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [FLWORExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 97:
#line 1604 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [QuantifiedExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1609 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [TypeswitchExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1614 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [IfExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1619 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [OrExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [InsertExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1631 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [DeleteExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1636 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [RenameExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1641 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [ReplaceExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1646 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExprSingle [TransformExpr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1657 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FLWORExpr [return]\n";
			(yyval.expr) = new FLWORExpr((yyloc),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 107:
#line 1665 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1675 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1699 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForLetClauseList [single]\n";
			ForLetClauseList* flc_list_p = new ForLetClauseList((yyloc));
			flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = flc_list_p;
		;}
    break;

  case 111:
#line 1706 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForLetClauseList [list]\n";
			ForLetClauseList* flc_list_p = dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(2) - (1)].node));
			if (flc_list_p) flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 112:
#line 1719 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForLetClause [for]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 113:
#line 1724 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForLetClause [let]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 114:
#line 1735 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForClause [ ]\n";
			(yyval.node) = new ForClause((yyloc),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 115:
#line 1747 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarInDeclList [single]\n";
			VarInDeclList* vardecl_list_p = new VarInDeclList((yyloc));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 116:
#line 1754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1769 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarInDecl [in]\n";
			(yyval.node) = new VarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 118:
#line 1777 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1786 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1796 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1807 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1816 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1826 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1836 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1852 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PositionalVar [ ]\n";
			(yyval.node) = new PositionalVar((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 126:
#line 1865 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTScoreVar [ ]\n";
			(yyval.node) = new FTScoreVar((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 127:
#line 1877 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "LetClause [ ]\n";
			(yyval.node) = new LetClause((yyloc),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)));
			
		;}
    break;

  case 128:
#line 1890 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarGetsDeclList [single]\n";
			VarGetsDeclList* vgdl_p = new VarGetsDeclList((yyloc));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 129:
#line 1897 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1912 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1921 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1931 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1940 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1956 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "WhereClause [ ]\n";
			(yyval.node) = new WhereClause((yyloc),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 135:
#line 1968 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderByClause [ ]\n";
			(yyval.node) = new OrderByClause((yyloc),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 136:
#line 1974 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderByClause [stable]\n";
			(yyval.node) = new OrderByClause((yyloc),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)),
								true);
		;}
    break;

  case 137:
#line 1987 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderSpecList [single]\n";
			OrderSpecList* osl_p = new OrderSpecList((yyloc));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 138:
#line 1994 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2009 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderSpec [single]\n";
			(yyval.node) = new OrderSpec((yyloc),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 140:
#line 2016 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderSpec [single.modifier]\n";
			(yyval.node) = new OrderSpec((yyloc),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 141:
#line 2029 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderModifier [dir]\n";
			(yyval.node) = new OrderModifier((yyloc),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 142:
#line 2037 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderModifier [empty]\n";
			(yyval.node) = new OrderModifier((yyloc),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 143:
#line 2045 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderModifier [collation]\n";
			(yyval.node) = new OrderModifier((yyloc),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 144:
#line 2053 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderModifier [dir.empty]\n";
			(yyval.node) = new OrderModifier((yyloc),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 145:
#line 2061 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderModifier [dir.collation]\n";
			(yyval.node) = new OrderModifier((yyloc),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 146:
#line 2069 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderModifier [empty.collation]\n";
			(yyval.node) = new OrderModifier((yyloc),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 147:
#line 2077 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderModifier [dir.empty.collation]\n";
			(yyval.node) = new OrderModifier((yyloc),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 148:
#line 2091 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderDirSpec [ascending]\n";
			(yyval.node) = new OrderDirSpec((yyloc), dir_ascending);
		;}
    break;

  case 149:
#line 2096 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderDirSpec [descending]\n";
			(yyval.node) = new OrderDirSpec((yyloc), dir_descending);
		;}
    break;

  case 150:
#line 2107 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderEmptySpec [greatest]\n";
			(yyval.node) = new OrderEmptySpec((yyloc),
								StaticQueryContext::empty_greatest);
		;}
    break;

  case 151:
#line 2113 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderEmptySpec [least]\n";
			(yyval.node) = new OrderEmptySpec((yyloc),
								StaticQueryContext::empty_least);
		;}
    break;

  case 152:
#line 2125 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderCollationSpec [ ]\n";
			(yyval.node) = new OrderCollationSpec((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 153:
#line 2137 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QuantifiedExpr [some]\n";
			(yyval.expr) = new QuantifiedExpr((yyloc),
								quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 154:
#line 2145 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QuantifiedExpr [every]\n";
			(yyval.expr) = new QuantifiedExpr((yyloc),
								quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 155:
#line 2159 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QVarInDeclList [single]\n";
			QVarInDeclList* qvid_list_p = new QVarInDeclList((yyloc));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 156:
#line 2167 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2182 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QVarInDecl [in]\n";
			(yyval.node) = new QVarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 158:
#line 2189 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QVarInDecl [type.in]\n";
			(yyval.node) = new QVarInDecl((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 159:
#line 2203 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "TypeswitchExpr [cases.default.return]\n";
			(yyval.expr) = new TypeswitchExpr((yyloc),
								(yysemantic_stack_[(7) - (2)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(7) - (4)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 160:
#line 2211 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2226 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CaseClauseList [single]\n";
			CaseClauseList* cc_list_p = new CaseClauseList((yyloc));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 162:
#line 2233 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CaseClauseList [list]\n";
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 163:
#line 2246 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CaseClause [case.return]\n";
			(yyval.node) = new CaseClause((yyloc),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 164:
#line 2253 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CaseClause [case.as.return]\n";
			(yyval.node) = new CaseClause((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 165:
#line 2267 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "IfExpr [ ]\n";
			(yyval.expr) = new IfExpr((yyloc),
								(yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 166:
#line 2279 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrExpr [and]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 167:
#line 2284 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrExpr [or.and]\n";
			(yyval.expr) = new OrExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 168:
#line 2296 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AndExpr [comp]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 169:
#line 2301 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AndExpr [and.comp]\n";
			(yyval.expr) = new AndExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 170:
#line 2321 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ComparisonExpr [ftcontains]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 171:
#line 2326 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2335 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2359 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTContainsExpr [range]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 175:
#line 2364 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTContainsExpr [range.ftselect]\n";
			(yyval.expr) = new FTContainsExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 176:
#line 2372 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTContainsExpr [range.ftselect.ftignore]\n";
			(yyval.expr) = new FTContainsExpr((yyloc),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 177:
#line 2386 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "RangeExpr [add]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 178:
#line 2391 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "RangeExpr [add.to.add]\n";
			(yyval.expr) = new RangeExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 179:
#line 2403 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AdditiveExpr [mult]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 180:
#line 2408 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AdditiveExpr [mult+mult]\n";
			(yyval.expr) = new AdditiveExpr((yyloc), op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 181:
#line 2413 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AdditiveExpr [mult-mult]\n";
			(yyval.expr) = new AdditiveExpr((yyloc), op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 182:
#line 2424 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "MultiplicativeExpr [union]\n";
		;}
    break;

  case 183:
#line 2428 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "MultiplicativeExpr [mult*union]\n";
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 184:
#line 2433 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "MultiplicativeExpr [mult.div.union]\n";
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 185:
#line 2438 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "MultiplicativeExpr [mult.idiv.union]\n";
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 186:
#line 2443 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "MultiplicativeExpr [mult.mod.union]\n";
			(yyval.expr) = new MultiplicativeExpr((yyloc), op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 187:
#line 2454 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "UnionExpr [interexcept]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 188:
#line 2459 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "UnionExpr [union.union.interexcept]\n";
			(yyval.expr) = new UnionExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 189:
#line 2465 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "UnionExpr [union|interexcept]\n";
			(yyval.expr) = new UnionExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 190:
#line 2477 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "IntersectExceptExpr [instanceof]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 191:
#line 2482 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "IntersectExceptExpr [interexcept.inter.instanceof]\n";
			(yyval.expr) = new IntersectExceptExpr((yyloc), op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 192:
#line 2487 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "IntersectExceptExpr [interexcept.except.instanceof]\n";
			(yyval.expr) = new IntersectExceptExpr((yyloc), op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 193:
#line 2498 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "InstanceofExpr [treat]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 194:
#line 2503 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "InstanceofExpr [treat.seqtype]\n";
			(yyval.expr) = new InstanceofExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 195:
#line 2516 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "TreatExpr [castable]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 196:
#line 2521 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "TreatExpr [castable.seqtype]\n";
			(yyval.expr) = new TreatExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 197:
#line 2534 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CastableExpr [cast]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 198:
#line 2539 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CastableExpr [cast.singletype]\n";
			(yyval.expr) = new CastableExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 199:
#line 2552 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CastExpr [unary]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 200:
#line 2557 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CastExpr [unary.singletype]\n";
			(yyval.expr) = new CastExpr((yyloc),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 201:
#line 2570 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "UnaryExpr [value]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 202:
#line 2575 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "UnaryExpr [signlist.value]\n";
			(yyval.expr) = new UnaryExpr((yyloc),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 203:
#line 2588 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SignList [+]\n";
			(yyval.node) = new SignList((yyloc), true);
		;}
    break;

  case 204:
#line 2593 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SignList [-]\n";
			(yyval.node) = new SignList((yyloc), false);
		;}
    break;

  case 205:
#line 2598 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SignList [signlist.+]\n";
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 206:
#line 2603 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SignList [signlist.-]\n";
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 207:
#line 2616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValueExpr [validate]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 208:
#line 2621 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValueExpr [path]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 209:
#line 2626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValueExpr [extension]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 210:
#line 2638 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "GeneralComp [=]\n";
			(yyval.node) = new GeneralComp((yyloc), op_eq);
		;}
    break;

  case 211:
#line 2643 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "GeneralComp [!=]\n";
			(yyval.node) = new GeneralComp((yyloc), op_ne);
		;}
    break;

  case 212:
#line 2648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "GeneralComp [<]\n";
			(yyval.node) = new GeneralComp((yyloc), op_lt);
		;}
    break;

  case 213:
#line 2653 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "GeneralComp [<=]\n";
			(yyval.node) = new GeneralComp((yyloc), op_le);
		;}
    break;

  case 214:
#line 2658 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "GeneralComp [>]\n";
			(yyval.node) = new GeneralComp((yyloc), op_gt);
		;}
    break;

  case 215:
#line 2663 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "GeneralComp [>=]\n";
			(yyval.node) = new GeneralComp((yyloc), op_ge);
		;}
    break;

  case 216:
#line 2674 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValueComp [eq]\n";
			(yyval.node) = new ValueComp((yyloc), op_val_eq);
		;}
    break;

  case 217:
#line 2679 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValueComp [ne]\n";
			(yyval.node) = new ValueComp((yyloc), op_val_ne);
		;}
    break;

  case 218:
#line 2684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValueComp [lt]\n";
			(yyval.node) = new ValueComp((yyloc), op_val_lt);
		;}
    break;

  case 219:
#line 2689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValueComp [le]\n";
			(yyval.node) = new ValueComp((yyloc), op_val_le);
		;}
    break;

  case 220:
#line 2694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValueComp [gt]\n";
			(yyval.node) = new ValueComp((yyloc), op_val_gt);
		;}
    break;

  case 221:
#line 2699 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValueComp [ge]\n";
			(yyval.node) = new ValueComp((yyloc), op_val_ge);
		;}
    break;

  case 222:
#line 2710 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NodeComp [is]\n";
			(yyval.node) = new NodeComp((yyloc), op_is);
		;}
    break;

  case 223:
#line 2715 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NodeComp [<<]\n";
			(yyval.node) = new NodeComp((yyloc), op_precedes);
		;}
    break;

  case 224:
#line 2720 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NodeComp [>>]\n";
			(yyval.node) = new NodeComp((yyloc), op_follows);
		;}
    break;

  case 225:
#line 2732 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValidateExpr [expr]\n";
			(yyval.expr) = new ValidateExpr((yyloc), "strict", (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 226:
#line 2737 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ValidateExpr [mode.expr]\n";
			(yyval.expr) = new ValidateExpr((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 227:
#line 2750 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExtensionExpr [pragmalist]\n";
			(yyval.expr) = new ExtensionExpr((yyloc),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 228:
#line 2757 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ExtensionExpr [pragmalist.expr]\n";
			(yyval.expr) = new ExtensionExpr((yyloc),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 229:
#line 2770 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PragmaList [single]\n";
			PragmaList* pragma_list_p = new PragmaList((yyloc));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 230:
#line 2777 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2792 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Pragma [ ]\n";
			(yyval.node) = new Pragma((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));

		;}
    break;

  case 232:
#line 2836 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PathExpr [/]\n";
			(yyval.expr) = new PathExpr((yyloc), path_leading_lone_slash, NULL);
		;}
    break;

  case 233:
#line 2841 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PathExpr [/relative]\n";
			(yyval.expr) = new PathExpr((yyloc), path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 234:
#line 2846 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PathExpr [//relative]\n";
			(yyval.expr) = new PathExpr((yyloc), path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 235:
#line 2851 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PathExpr [relative]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 236:
#line 2862 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "RelativePathExpr [step]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);						
		;}
    break;

  case 237:
#line 2867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "RelativePathExpr [step/relative]\n";
			(yyval.expr) = new RelativePathExpr((yyloc), st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 238:
#line 2872 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "RelativePathExpr [step//relative]\n";
			(yyval.expr) = new RelativePathExpr((yyloc), st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 239:
#line 2883 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "StepExpr [axis]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 240:
#line 2888 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "StepExpr [filter]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 241:
#line 2899 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AxisStep [forward]\n";
			(yyval.expr) = new AxisStep((yyloc),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 242:
#line 2906 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AxisStep [forward.predlist]\n";
			(yyval.expr) = new AxisStep((yyloc),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 243:
#line 2913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AxisStep [reverse]\n";
			(yyval.expr) = new AxisStep((yyloc),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 244:
#line 2920 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AxisStep [reverse.predlist]\n";
			(yyval.expr) = new AxisStep((yyloc),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 245:
#line 2933 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForwardStep [nodetest]\n";
			(yyval.node) = new ForwardStep((yyloc),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 246:
#line 2940 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForwardStep [abbrev]\n";
			(yyval.node) = new ForwardStep((yyloc),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 247:
#line 2952 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForwardAxis [child]\n";
			(yyval.node) = new ForwardAxis((yyloc), axis_child);
		;}
    break;

  case 248:
#line 2957 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForwardAxis [descendant]\n";
			(yyval.node) = new ForwardAxis((yyloc), axis_descendant);
		;}
    break;

  case 249:
#line 2962 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForwardAxis [attribute]\n";
			(yyval.node) = new ForwardAxis((yyloc), axis_attribute);
		;}
    break;

  case 250:
#line 2967 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForwardAxis [self]\n";
			(yyval.node) = new ForwardAxis((yyloc), axis_self);
		;}
    break;

  case 251:
#line 2972 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForwardAxis [descendant_or_self]\n";
			(yyval.node) = new ForwardAxis((yyloc), axis_descendant_or_self);
		;}
    break;

  case 252:
#line 2977 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForwardAxis [following_sibling]\n";
			(yyval.node) = new ForwardAxis((yyloc), axis_following_sibling);
		;}
    break;

  case 253:
#line 2982 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ForwardAxis [following]\n";
			(yyval.node) = new ForwardAxis((yyloc), axis_following);
		;}
    break;

  case 254:
#line 2993 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AbbrevForwardStep [nodetest]\n";
			(yyval.node) = new AbbrevForwardStep((yyloc), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 255:
#line 2998 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AbbrevForwardStep [@ nodetest]\n";
			(yyval.node) = new AbbrevForwardStep((yyloc), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 256:
#line 3009 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ReverseStep [nodetest]\n";
			(yyval.node) = new ReverseStep((yyloc),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 257:
#line 3016 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ReverseStep [..]\n";
			ReverseAxis* rev_p = new ReverseAxis((yyloc), axis_parent);
			(yyval.node) = new ReverseStep((yyloc),
								rev_p);
		;}
    break;

  case 258:
#line 3029 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ReverseAxis [parent]\n";
			(yyval.node) = new ReverseAxis((yyloc), axis_parent);
		;}
    break;

  case 259:
#line 3034 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ReverseAxis [ancestor]\n";
			(yyval.node) = new ReverseAxis((yyloc), axis_ancestor);
		;}
    break;

  case 260:
#line 3039 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ReverseAxis [preceding_sibling]\n";
			(yyval.node) = new ReverseAxis((yyloc), axis_preceding_sibling);
		;}
    break;

  case 261:
#line 3044 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ReverseAxis [preceding]\n";
			(yyval.node) = new ReverseAxis((yyloc), axis_preceding);
		;}
    break;

  case 262:
#line 3049 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ReverseAxis [ancestor_or_self]\n";
			(yyval.node) = new ReverseAxis((yyloc), axis_ancestor_or_self);
		;}
    break;

  case 263:
#line 3065 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NodeTest [kindtest]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 264:
#line 3070 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NodeTest [nametest]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 265:
#line 3081 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NameTest [qname]\n";
			(yyval.node) = new NameTest((yyloc), new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 266:
#line 3086 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NameTest [wildcard]\n";
			(yyval.node) = new NameTest((yyloc), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 267:
#line 3097 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Wildcard [*]\n";
			(yyval.node) = new Wildcard((yyloc),
                        "",
                        "",
                        wild_all);
		;}
    break;

  case 268:
#line 3105 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Wildcard [pref:*]\n";
			(yyval.node) = new Wildcard((yyloc),
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        wild_elem);
		;}
    break;

  case 269:
#line 3113 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Wildcard [*:qname]\n";
			(yyval.node) = new Wildcard((yyloc),
                        "",
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        wild_prefix);
		;}
    break;

  case 270:
#line 3127 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FilterExpr [primary]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 271:
#line 3132 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FilterExpr [primary.predlist]\n";
			(yyval.expr) = new FilterExpr((yyloc),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 272:
#line 3145 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PredicateList [single]\n";
			PredicateList* pred_list_p = new PredicateList((yyloc));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 273:
#line 3152 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3167 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Predicate [ ]\n";
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 275:
#line 3179 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PrimaryExpr [literal]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 276:
#line 3184 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PrimaryExpr [varref]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 277:
#line 3189 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PrimaryExpr [paren]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 278:
#line 3194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PrimaryExpr [context_item]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 279:
#line 3199 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PrimaryExpr [funcall]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 280:
#line 3204 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PrimaryExpr [cons]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 281:
#line 3209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PrimaryExpr [ordered]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 282:
#line 3214 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PrimaryExpr [unordered]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 283:
#line 3225 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Literal [numeric]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 284:
#line 3230 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Literal [string]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 285:
#line 3241 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NumericLiteral [decimal]\n";
			(yyval.expr) = new NumericLiteral((yyloc), decimal(yylval.decval));
		;}
    break;

  case 286:
#line 3246 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NumericLiteral [int]\n";
			(yyval.expr) = new NumericLiteral((yyloc), yylval.ival);
		;}
    break;

  case 287:
#line 3251 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "NumericLiteral [double]\n";
			(yyval.expr) = new NumericLiteral((yyloc), yylval.dval);
		;}
    break;

  case 288:
#line 3262 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarRef [ ]\n";
			(yyval.expr) = new VarRef((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 289:
#line 3273 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ParenthesizedExpr [()]\n";
			(yyval.expr) = new ParenthesizedExpr((yyloc), NULL);
		;}
    break;

  case 290:
#line 3278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ParenthesizedExpr [(expr)]\n";
			(yyval.expr) = new ParenthesizedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 291:
#line 3290 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ContextItemExpr [.]\n";
			(yyval.expr) = new ContextItemExpr((yyloc));
		;}
    break;

  case 292:
#line 3301 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OrderedExpr [expr]\n";
			(yyval.expr) = new OrderedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 293:
#line 3313 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "UnorderedExpr [expr]\n";
			(yyval.expr) = new UnorderedExpr((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 294:
#line 3370 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionCall [ ]\n";
			(yyval.expr) = new FunctionCall((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 295:
#line 3377 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FunctionCall [arglist]\n";
			(yyval.expr) = new FunctionCall((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 296:
#line 3390 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ArgList [single]\n";
			ArgList* a_list_p = new ArgList((yyloc)); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 297:
#line 3397 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ArgList [list]\n";
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 298:
#line 3410 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Constructor [direct]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 299:
#line 3415 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "Constructor [computed]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 300:
#line 3426 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirectConstructor [element]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 301:
#line 3431 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirectConstructor [comment]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 3436 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirectConstructor [pi]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 303:
#line 3447 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3456 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3465 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3474 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3483 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3492 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3508 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirElemContentList [single]\n";
			DirElemContentList* elem_content_list_p = new DirElemContentList((yyloc));
			elem_content_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 310:
#line 3515 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirElemContentList [list]\n";
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 311:
#line 3528 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirAttributeList [single]\n";
			DirAttributeList* at_list_p = new DirAttributeList((yyloc));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 312:
#line 3535 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3550 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirAttr [ ]\n";
			(yyval.node) = new DirAttr((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 314:
#line 3563 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirAttributeValue [quote]\n";
			(yyval.node) = new DirAttributeValue((yyloc),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 315:
#line 3569 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirAttributeValue [apos]\n";
			(yyval.node) = new DirAttributeValue((yyloc),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 316:
#line 3581 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QuoteAttrContentList[empty]\n";
			(yyval.node) = new QuoteAttrContentList((yyloc));
		;}
    break;

  case 317:
#line 3586 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 318:
#line 3593 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QuoteAttrContentList [""]\n";
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList((yyloc));
			qo_list_p->push_back(new QuoteAttrValueContent((yyloc),string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 319:
#line 3600 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QuoteAttrContentList [single]\n";
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList((yyloc));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 320:
#line 3607 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QuoteAttrContentList [list]\n";
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
		;}
    break;

  case 322:
#line 3630 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AposAttrContentList ['']\n";
			(yyval.node) = new AposAttrContentList((yyloc));
		;}
    break;

  case 323:
#line 3635 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 324:
#line 3642 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AposAttrContentList ['']\n";
			AposAttrContentList* at_list_p = new AposAttrContentList((yyloc));
			at_list_p->push_back(new AposAttrValueContent((yyloc),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 325:
#line 3649 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AposAttrContentList [single]\n";
			AposAttrContentList* at_list_p = new AposAttrContentList((yyloc));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 326:
#line 3656 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3665 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QuoteAttrValueContent [quote_attr_content]\n";
			(yyval.node) = new QuoteAttrValueContent((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 329:
#line 3686 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "QuoteAttrValueContent [common_content]\n";
			(yyval.node) = new QuoteAttrValueContent((yyloc),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 330:
#line 3698 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AposAttrValueContent [apos_attr_content]\n";
			(yyval.node) = new AposAttrValueContent((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 331:
#line 3704 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AposAttrValueContent [common_content]\n";
			(yyval.node) = new AposAttrValueContent((yyloc),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 332:
#line 3716 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirElemContent [cons]\n";
			(yyval.expr) = new DirElemContent((yyloc),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 333:
#line 3722 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirElemContent [elem_content]\n";
			(yyval.expr) = new DirElemContent((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 334:
#line 3728 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirElemContent [cdata]\n";
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent((yyloc),
								cdata_h);
		;}
    break;

  case 335:
#line 3735 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirElemContent [common_content]\n";
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent((yyloc),
								cont_h);
		;}
    break;

  case 336:
#line 3748 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CommonContent [entity_ref]\n";
			(yyval.expr) = new CommonContent((yyloc),
								cont_entity,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 337:
#line 3755 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CommonContent [char_ref]\n";
			(yyval.expr) = new CommonContent((yyloc),
								cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 338:
#line 3762 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CommonContent [{{]\n";
			(yyval.expr) = new CommonContent((yyloc),
								cont_escape_lbrace);
		;}
    break;

  case 339:
#line 3768 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CommonContent [}}]\n";
			(yyval.expr) = new CommonContent((yyloc),
								cont_escape_rbrace);
		;}
    break;

  case 340:
#line 3774 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CommonContent [expr]\n";
			(yyval.expr) = new CommonContent((yyloc),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 341:
#line 3786 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirCommentConstructor [ ]\n";
			(yyval.expr) = new DirCommentConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 342:
#line 3803 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirPIConstructor [target]\n";
			(yyval.expr) = new DirPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 343:
#line 3809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DirPIConstructor [target.charlit]\n";
			(yyval.expr) = new DirPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (3)].sval)));
		;}
    break;

  case 344:
#line 3827 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CDataSection [ ]\n";
			(yyval.expr) = new CDataSection((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 345:
#line 3843 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ComputedConstructor [doc]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 346:
#line 3848 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ComputedConstructor [elem]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 347:
#line 3853 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ComputedConstructor [attr]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 348:
#line 3858 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ComputedConstructor [text]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 349:
#line 3863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ComputedConstructor [comment]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 350:
#line 3868 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ComputedConstructor [pi]\n";
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 351:
#line 3879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompDocConstructor [ ]\n";
			(yyval.expr) = new CompDocConstructor((yyloc),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 352:
#line 3891 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompElemConstructor [ ]\n";
			(yyval.expr) = new CompElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 353:
#line 3898 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompElemConstructor [content]\n";
			(yyval.expr) = new CompElemConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 354:
#line 3905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompElemConstructor [name]\n";
			(yyval.expr) = new CompElemConstructor((yyloc),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 355:
#line 3911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompElemConstructor [name.content]\n";
			(yyval.expr) = new CompElemConstructor((yyloc),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 356:
#line 3935 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompAttrConstructor [ ]\n";
			(yyval.expr) = new CompAttrConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 357:
#line 3942 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompAttrConstructor [val]\n";
			(yyval.expr) = new CompAttrConstructor((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 358:
#line 3949 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompAttrConstructor [name]\n";
			(yyval.expr) = new CompAttrConstructor((yyloc),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 359:
#line 3955 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompAttrConstructor [name.val]\n";
			(yyval.expr) = new CompAttrConstructor((yyloc),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 360:
#line 3967 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompTextConstructor [content]\n";
			(yyval.expr) = new CompTextConstructor((yyloc),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 361:
#line 3979 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompCommentConstructor [content]\n";
			(yyval.expr) = new CompCommentConstructor((yyloc),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 362:
#line 3991 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompPIConstructor [ ]\n";
			(yyval.expr) = new CompPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 363:
#line 3998 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompPIConstructor [content]\n";
			(yyval.expr) = new CompPIConstructor((yyloc),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 364:
#line 4005 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompPIConstructor [target]\n";
			(yyval.expr) = new CompPIConstructor((yyloc),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 365:
#line 4011 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CompPIConstructor [target.content]\n";
			(yyval.expr) = new CompPIConstructor((yyloc),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 366:
#line 4023 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SingleType [atomic]\n";
			(yyval.node) = new SingleType((yyloc),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 367:
#line 4030 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SingleType [atomic ?]\n";
			(yyval.node) = new SingleType((yyloc),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 368:
#line 4043 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "TypeDeclaration [as seqtype]\n";
			(yyval.node) = new TypeDeclaration((yyloc),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 369:
#line 4055 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ItemType [type]\n";
			(yyval.node) = new SequenceType((yyloc),
								dynamic_cast<ItemType*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 370:
#line 4062 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ItemType [type.occurs]\n";
			(yyval.node) = new SequenceType((yyloc),
								dynamic_cast<ItemType*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 371:
#line 4069 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ItemType [void]\n";
			(yyval.node) = new SequenceType((yyloc), NULL, NULL);
		;}
    break;

  case 372:
#line 4107 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OccurrenceIndicator [?]\n";
			(yyval.node) = new OccurrenceIndicator((yyloc),
								occurs_optionally);
		;}
    break;

  case 373:
#line 4113 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OccurrenceIndicator [*]\n";
			(yyval.node) = new OccurrenceIndicator((yyloc),
								occurs_zero_or_more);
		;}
    break;

  case 374:
#line 4119 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "OccurrenceIndicator [+]\n";
			(yyval.node) = new OccurrenceIndicator((yyloc),
								occurs_one_or_more);
		;}
    break;

  case 375:
#line 4131 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ItemType [atomic]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 376:
#line 4136 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ItemType [kind]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 377:
#line 4141 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ItemType [item]\n";
			(yyval.node) = new ItemType((yyloc),true);
		;}
    break;

  case 378:
#line 4152 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AtomicType [qname]\n";
			(yyval.node) = new AtomicType((yyloc),
								new QName((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 379:
#line 4164 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "KindTest [doc]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 380:
#line 4169 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "KindTest [elem]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 381:
#line 4174 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "KindTest [attr]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 382:
#line 4179 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "KindTest [schema_elem]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 383:
#line 4184 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "KindTest [schema_attr]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 384:
#line 4189 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "KindTest [pi]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 385:
#line 4194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "KindTest [comment]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 386:
#line 4199 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "KindTest [text]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 387:
#line 4204 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "KindTest [any]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 388:
#line 4215 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AnyKindTest [ ]\n";
			(yyval.node) = new AnyKindTest((yyloc));
		;}
    break;

  case 389:
#line 4226 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DocumentTest [ ]\n";
			(yyval.node) = new DocumentTest((yyloc));
		;}
    break;

  case 390:
#line 4231 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DocumentTest [elem]\n";
			(yyval.node) = new DocumentTest((yyloc),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 391:
#line 4237 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DocumentTest [schema_elem]\n";
			(yyval.node) = new DocumentTest((yyloc),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 392:
#line 4249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "TextTest [ ]\n";
			(yyval.node) = new TextTest((yyloc));
		;}
    break;

  case 393:
#line 4260 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "CommentTest [ ]\n";
			(yyval.node) = new CommentTest((yyloc));
		;}
    break;

  case 394:
#line 4271 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PITest [ ]\n";
			(yyval.node) = new PITest((yyloc), "", "");
		;}
    break;

  case 395:
#line 4276 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PITest [ncname]\n";
			(yyval.node) = new PITest((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), "");
		;}
    break;

  case 396:
#line 4281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "PITest [stringlit]\n";
			(yyval.node) = new PITest((yyloc), "", driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 397:
#line 4292 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AttributeTest [ ]\n";
			(yyval.node) = new AttributeTest((yyloc),
								NULL,
								NULL);
		;}
    break;

  case 398:
#line 4299 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AttributeTest [name]\n";
			(yyval.node) = new AttributeTest((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL);
		;}
    break;

  case 399:
#line 4306 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AttributeTest [name.type]\n";
			(yyval.node) = new AttributeTest((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 400:
#line 4313 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AttributeTest [*]\n";
			(yyval.node) = new AttributeTest((yyloc),
								NULL,
								NULL);
		;}
    break;

  case 401:
#line 4320 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "AttributeTest [*.type]\n";
			(yyval.node) = new AttributeTest((yyloc),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 402:
#line 4333 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SchemaAttributeTest [ ]\n";
			(yyval.node) = new SchemaAttributeTest((yyloc),
								new QName((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 403:
#line 4345 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ElementTest [ ]\n";
			(yyval.node) = new ElementTest((yyloc),
									NULL,
									NULL);
		;}
    break;

  case 404:
#line 4352 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ElementTest [name]\n";
			(yyval.node) = new ElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
									NULL);
		;}
    break;

  case 405:
#line 4359 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ElementTest [name.type]\n";
			(yyval.node) = new ElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 406:
#line 4366 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ElementTest [name.type]\n";
			(yyval.node) = new ElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 407:
#line 4373 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ElementTest [*]\n";
			(yyval.node) = new ElementTest((yyloc),
									NULL,
									NULL,
									true);
		;}
    break;

  case 408:
#line 4381 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ElementTest [*.type]\n";
			(yyval.node) = new ElementTest((yyloc),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)),
									true);
		;}
    break;

  case 409:
#line 4389 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ElementTest [*.type]\n";
			(yyval.node) = new ElementTest((yyloc),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)),
									true);
		;}
    break;

  case 410:
#line 4403 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "SchemaElementTest [ ]\n";
			(yyval.node) = new SchemaElementTest((yyloc),
									new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 411:
#line 4425 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "TypeName [name]\n";
			(yyval.node) = new TypeName((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 412:
#line 4433 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "TypeName [name?]\n";
			(yyval.node) = new TypeName((yyloc),
								new QName((yyloc),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 413:
#line 4454 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "StringLiteral [ ]\n";
			(yyval.expr) = new StringLiteral((yyloc), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 414:
#line 4494 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "RevalidationDecl [ ]\n";
		;}
    break;

  case 415:
#line 4504 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "InsertExpr [expr]\n";
		;}
    break;

  case 416:
#line 4508 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "InsertExpr [expr.as_first]\n";
		;}
    break;

  case 417:
#line 4512 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "InsertExpr [expr.as_last]\n";
		;}
    break;

  case 418:
#line 4516 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "InsertExpr [expr.after]\n";
		;}
    break;

  case 419:
#line 4520 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "InsertExpr [expr.before]\n";
		;}
    break;

  case 420:
#line 4530 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "DeleteExpr [expr]\n";
		;}
    break;

  case 421:
#line 4540 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ReplaceExpr [expr.expr]\n";
		;}
    break;

  case 422:
#line 4544 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "ReplaceExpr [value.expr]\n";
		;}
    break;

  case 423:
#line 4554 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "RenameExpr [expr.expr]\n";
		;}
    break;

  case 424:
#line 4579 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "TransformExpr [ ]\n";
		;}
    break;

  case 425:
#line 4589 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarNameList [single]\n";
		;}
    break;

  case 426:
#line 4593 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "VarNameList [list]\n";
		;}
    break;

  case 427:
#line 4611 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTSelection [or]\n";
		;}
    break;

  case 428:
#line 4615 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTSelection [or.match_proximity]\n";
		;}
    break;

  case 429:
#line 4619 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTSelection [or.weight_range]\n";
		;}
    break;

  case 430:
#line 4623 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTSelection [or.match_proximity.weight_range]\n";
		;}
    break;

  case 431:
#line 4633 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOptionProximityList [option_single]\n";
		;}
    break;

  case 432:
#line 4637 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOptionProximityList [proximity_single]\n";
		;}
    break;

  case 433:
#line 4641 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOptionProximityList [option_list]\n";
		;}
    break;

  case 434:
#line 4645 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOptionProximityList [proximity_list]\n";
		;}
    break;

  case 435:
#line 4655 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTOr [and]\n";
		;}
    break;

  case 436:
#line 4659 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTOr [or.and]\n";
		;}
    break;

  case 437:
#line 4669 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTAnd [mild_not]\n";
		;}
    break;

  case 438:
#line 4673 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTAnd [and.mild_not]\n";
		;}
    break;

  case 439:
#line 4683 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMildNot [unary_not]\n";
		;}
    break;

  case 440:
#line 4687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMildNot [mild_not.unary_not]\n";
		;}
    break;

  case 441:
#line 4697 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTUnaryNot [words]\n";
		;}
    break;

  case 442:
#line 4701 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTUnaryNot [not.words]\n";
		;}
    break;

  case 443:
#line 4711 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWordsSelection [words]\n";
		;}
    break;

  case 444:
#line 4715 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWordsSelection [words.times]\n";
		;}
    break;

  case 445:
#line 4719 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWordsSelection [selection]\n";
		;}
    break;

  case 446:
#line 4729 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWords [value]\n";
		;}
    break;

  case 447:
#line 4733 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWords [value.any_all_option]\n";
		;}
    break;

  case 448:
#line 4743 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWordsValue [literal]\n";
		;}
    break;

  case 449:
#line 4747 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWordsValue [expr]\n";
		;}
    break;

  case 450:
#line 4757 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTProximity [order]\n";
		;}
    break;

  case 451:
#line 4761 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTProximity [window]\n";
		;}
    break;

  case 452:
#line 4765 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTProximity [distance]\n";
		;}
    break;

  case 453:
#line 4769 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTProximity [scope]\n";
		;}
    break;

  case 454:
#line 4773 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTProximity [content]\n";
		;}
    break;

  case 455:
#line 4783 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTOrderedIndicator [ ]\n";
		;}
    break;

  case 456:
#line 4793 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOption [case]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 457:
#line 4798 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOption [diacritics]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 458:
#line 4803 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOption [stem]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 459:
#line 4808 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOption [thesaurus]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 460:
#line 4813 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOption [stopword]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 461:
#line 4818 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOption [language]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 462:
#line 4823 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTMatchOption [wildcard]\n";
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 463:
#line 4834 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTCaseOption [lower]\n";
		;}
    break;

  case 464:
#line 4838 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTCaseOption [upper]\n";
		;}
    break;

  case 465:
#line 4842 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTCaseOption [sensitive]\n";
		;}
    break;

  case 466:
#line 4846 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTCaseOption [insensitive]\n";
		;}
    break;

  case 467:
#line 4856 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTDiacriticsOption [with]\n";
		;}
    break;

  case 468:
#line 4860 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTDiacriticsOption [without]\n";
		;}
    break;

  case 469:
#line 4864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTDiacriticsOption [sensitive]\n";
		;}
    break;

  case 470:
#line 4868 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTDiacriticsOption [insensitive]\n";
		;}
    break;

  case 471:
#line 4878 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTStemOption [with]\n";
		;}
    break;

  case 472:
#line 4882 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTStemOption [without]\n";
		;}
    break;

  case 473:
#line 4892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusOption [id]\n";
		;}
    break;

  case 474:
#line 4896 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusOption [default]\n";
		;}
    break;

  case 475:
#line 4900 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusOption [(id)]\n";
		;}
    break;

  case 476:
#line 4904 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusOption [(id,id,..)]\n";
		;}
    break;

  case 477:
#line 4908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusOption [(default)]\n";
		;}
    break;

  case 478:
#line 4912 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusOption [(default,id,id,..)]\n";
		;}
    break;

  case 479:
#line 4916 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusOption [without]\n";
		;}
    break;

  case 480:
#line 4926 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusList [single]\n";
		;}
    break;

  case 481:
#line 4930 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusList [list]\n";
		;}
    break;

  case 482:
#line 4940 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusID [name]\n";
		;}
    break;

  case 483:
#line 4944 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusID [name.rel]\n";
		;}
    break;

  case 484:
#line 4948 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusID [name.range]\n";
		;}
    break;

  case 485:
#line 4952 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTThesaurusID [name.rel.range]\n";
		;}
    break;

  case 486:
#line 4962 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTStopwordOption [list]\n";
		;}
    break;

  case 487:
#line 4966 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTStopwordOption [list.incl_excl]\n";
		;}
    break;

  case 488:
#line 4970 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTStopwordOption [default]\n";
		;}
    break;

  case 489:
#line 4974 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTStopwordOption [default.incl_excl]\n";
		;}
    break;

  case 490:
#line 4978 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTStopwordOption [without]\n";
		;}
    break;

  case 491:
#line 4988 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTInclExclStringLiteralList [.]\n";
		;}
    break;

  case 492:
#line 4992 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTInclExclStringLiteralList [*]\n";
		;}
    break;

  case 493:
#line 5002 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTRefOrList [.]\n";
		;}
    break;

  case 494:
#line 5006 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTRefOrList [(*)]\n";
		;}
    break;

  case 495:
#line 5016 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTStringLiteralList [.]\n";
		;}
    break;

  case 496:
#line 5020 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTStringLiteralList [*]\n";
		;}
    break;

  case 497:
#line 5030 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTInclExclStringLiteral [union]\n";
		;}
    break;

  case 498:
#line 5034 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTInclExclStringLiteral [except]\n";
		;}
    break;

  case 499:
#line 5044 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTLanguageOption [ ]\n";
		;}
    break;

  case 500:
#line 5054 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWildcardOption [with]\n";
		;}
    break;

  case 501:
#line 5058 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWildcardOption [without]\n";
		;}
    break;

  case 502:
#line 5068 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTContent [start]\n";
		;}
    break;

  case 503:
#line 5072 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTContent [end]\n";
		;}
    break;

  case 504:
#line 5076 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTContent [entire]\n";
		;}
    break;

  case 505:
#line 5086 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTAnyallOption [any]\n";
		;}
    break;

  case 506:
#line 5090 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTAnyallOption [any_word]\n";
		;}
    break;

  case 507:
#line 5094 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTAnyallOption [all]\n";
		;}
    break;

  case 508:
#line 5098 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTAnyallOption [all_words]\n";
		;}
    break;

  case 509:
#line 5102 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTAnyallOption [phrase]\n";
		;}
    break;

  case 510:
#line 5112 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTRange [exactly]\n";
		;}
    break;

  case 511:
#line 5116 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTRange [at_least]\n";
		;}
    break;

  case 512:
#line 5120 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTRange [at_most]\n";
		;}
    break;

  case 513:
#line 5124 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTRange [range]\n";
		;}
    break;

  case 514:
#line 5134 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTDistance [ ]\n";
		;}
    break;

  case 515:
#line 5144 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTWindow [ ]\n";
		;}
    break;

  case 516:
#line 5154 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTTimes [ ]\n";
		;}
    break;

  case 517:
#line 5164 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTTimes [same]\n";
		;}
    break;

  case 518:
#line 5168 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTTimes [different]\n";
		;}
    break;

  case 519:
#line 5178 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTUnit [words]\n";
		;}
    break;

  case 520:
#line 5182 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTUnit [sentences]\n";
		;}
    break;

  case 521:
#line 5186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTUnit [paragraph]\n";
		;}
    break;

  case 522:
#line 5196 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTBigUnit [sentence]\n";
		;}
    break;

  case 523:
#line 5200 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTBigUnit [paragraph]\n";
		;}
    break;

  case 524:
#line 5210 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
			if (debug) cout << "FTIgnoreOption [ ]\n";
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 5061 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -649;
  const short int
  xquery_parser::yypact_[] =
  {
       796,  1367,  1555,  -649,  -649,  -649,  1743,  -649,   -57,  -649,
    -649,  -649,  3059,    22,   139,  -649,  3059,   -36,  -649,   242,
     154,   157,   236,   271,   188,   241,   440,   311,   346,   349,
     -60,   358,   368,  -649,  -649,  3059,   261,   376,  -649,  -649,
    -649,  3059,    28,   383,  -649,  -649,   397,  3059,    44,   262,
    -649,  -649,   417,  1931,  -649,   389,   286,  3059,  -649,   447,
      24,  -649,   437,  -649,  -649,   201,   455,   470,  -649,   601,
     601,   383,  -649,   487,  3059,   309,  3059,  3059,  3059,   502,
     513,  -649,  3059,  3059,  3059,  1172,   519,  3467,   536,   984,
    -649,  -649,   644,  3059,   400,   411,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,   526,  -649,  -649,   332,
    -649,  -649,  -649,  -649,  -649,  -649,   441,   546,  -649,   416,
     354,   -48,   202,   180,   199,  -649,   469,   403,   544,   547,
    3247,  -649,  -649,  -649,   -31,  -649,  -649,  -649,   386,  -649,
     473,   139,  -649,   473,   139,  -649,  -649,  -649,  -649,   473,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,    12,  -649,
      23,  -649,  -649,    61,  3059,    80,    72,  -649,    81,  -649,
      91,  -649,  -649,  -649,  -649,  -649,  -649,   543,   545,  -649,
     567,   569,  -649,  -649,   176,   506,   574,  -649,  -649,   247,
     338,   107,  -649,   448,   450,  -649,   109,    86,  -649,    89,
     238,   438,   399,    -7,   562,  -649,    90,   576,   596,   580,
     490,   602,   592,    -4,   571,  -649,  -649,    92,   531,  -649,
     110,    33,   465,   467,  -649,   608,   517,  3059,   474,   476,
    -649,  -649,   475,    20,   124,  -649,    96,   127,   189,   445,
     -11,  -649,    19,   604,  3059,   430,   548,   -91,  -649,  -649,
    -649,  -649,   620,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
     -19,  -649,  -649,   121,   221,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,   644,
      38,  3059,  3059,  3059,  3059,  3059,  -649,   279,   488,  3420,
    3420,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  3420,  3420,  3420,    10,
    3420,  3420,  3420,  3420,  3420,  3420,  3420,  3420,  3420,  3420,
    3420,   308,   308,   624,   624,  -649,  -649,  -649,  2119,  -649,
     601,   601,  3059,   473,  -649,  -649,   473,  -649,   473,  -649,
    -649,  3059,  -649,   198,   533,   629,  -649,   629,  -649,  -649,
     225,   289,  -649,  -649,   625,   244,   308,     7,  -649,   630,
    -649,   335,   308,    70,   308,  -649,  3059,   355,  -649,  -649,
    -649,   541,   636,  -649,   636,  -649,  3059,   550,  3059,   383,
     584,  3059,   586,   -72,   555,   -17,   588,   489,   640,   578,
     640,  -649,   579,   634,  3059,   572,   -74,   594,  -649,   649,
    -649,   537,  -649,  -649,  -649,   538,  2307,   212,  -649,  -649,
    3059,   593,  -649,    54,    49,  -649,  -649,   645,  -649,  -649,
    -649,   661,  -649,   297,  3059,  3059,  3059,  3059,   477,  3059,
    3059,   662,  3059,  -649,   121,   121,   -19,  -649,   665,   667,
     -19,   668,  -649,    59,  -649,   528,  -649,  -649,  -649,   410,
     646,  -649,  -649,   646,  -649,  3059,   556,  3059,   546,  -649,
    -649,  -649,  -649,  3059,    10,   331,  -649,   443,  3379,   481,
     478,  -649,  -649,   479,   272,   202,   202,   -15,   180,   180,
     180,   180,   199,   199,  -649,  -649,  -649,  -649,  -649,  -649,
     415,  -649,  -649,  -649,  -649,   612,  -649,  -649,   220,  -649,
    -649,    55,  -649,  -649,  -649,  2495,  -649,   557,   559,  -649,
    -649,  -649,  -649,   687,  -649,  3059,  -649,   404,   647,   409,
     308,  -649,  -649,  -649,   413,   421,   308,  -649,  -649,  -649,
    3059,  2683,   618,   565,   566,   568,   570,  -649,  3059,  -649,
    -649,   700,  -649,   702,  3059,   622,  3059,  3059,   -55,   626,
     397,  3059,  -649,   685,   711,   685,  -649,   640,  -649,  3059,
    3059,   637,   417,   582,  -649,  -649,  -649,   226,   633,  -649,
      29,  -649,  -649,  -649,   730,  -649,  -649,   720,  -649,  -649,
      62,  -649,  -649,  -649,  -649,    82,  -649,   265,    48,  -649,
     589,  3059,  3059,  -649,  -649,  -649,  -649,  3059,  -649,  -649,
     643,   591,  -649,  -649,  -649,  -649,  -649,    30,   -19,   280,
      98,   100,    38,  -649,   731,  -649,  -649,  -649,  -649,   393,
     710,  -649,  3059,  -649,  3059,  -649,   229,   599,  -649,  3420,
    -649,  -649,  -649,  -649,   -99,   328,  -649,    10,   -99,  3420,
    3420,  3425,  -649,  -649,  -649,  -649,  -649,  -649,  -649,    10,
      10,   328,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,   231,  -649,  -649,
    -649,   237,  -649,  -649,  -649,  -649,  -649,   427,  -649,  -649,
    -649,  -649,   428,  -649,  -649,   240,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  3059,  -649,  -649,  3059,   651,
    3059,  -649,   676,   737,   734,   685,  -649,  -649,  3059,  -649,
    -649,  -649,  2871,   284,   394,  -649,   721,   598,   749,  -649,
     753,   101,   752,   617,   232,  -649,  -649,  -649,  -649,  -649,
    3059,  3059,  -649,  -649,  3420,  3420,  3420,  3420,   755,   549,
     745,  -649,   745,  -649,  -649,   710,  -649,  -649,  -649,  -649,
    -649,  -649,   180,  -649,  -649,  -649,   213,   481,  -649,  -649,
     233,  3420,  -649,  -649,   478,  -649,   534,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  3059,  -649,  3059,  -649,
     640,  -649,  -649,   245,  -649,  -649,   751,   285,  -649,  -649,
    -649,  -649,   632,   402,  -649,  -649,  -649,  -649,   607,   611,
     767,   756,  3059,   764,  3059,  -649,  -649,   180,   180,   180,
     353,   328,  -649,   102,  -649,   105,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,   685,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,   619,   308,  -649,   638,
    -649,  3420,   554,   745,  -649,  -649,  -649,   641,  3059,   180,
    -649,  -649,  3059,  -649,  -649
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
       0,     0,   411,     0,     0,     0,     0,   157,     0,   154,
     156,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    64,     0,    56,    60,     0,   130,     0,
       0,     0,     0,     0,   343,   231,   362,     0,     0,   153,
       0,   337,   333,   336,     0,   338,   339,     0,   340,   332,
       0,   309,   335,   334,   304,     0,   312,     0,     0,   161,
       0,     0,     0,   418,   419,   415,   423,     0,   421,   425,
       0,     0,   498,   497,   492,   493,   495,     0,   487,   482,
       0,     0,    14,   148,     0,   149,   150,   151,   140,   141,
     142,   143,     0,   107,     0,   108,     0,     0,   442,     0,
     176,   455,   503,   502,     0,     0,   504,     0,     0,     0,
       0,   428,   432,   450,   431,   454,   452,   451,   453,     0,
       0,     0,   444,   507,   508,   505,   506,   509,   447,   372,
     374,   373,   370,   367,   228,   274,   358,     0,   399,   401,
      91,     0,    76,    77,    89,    74,    75,     0,    84,    85,
      82,    83,     0,    68,   354,     0,   412,   405,   406,   408,
     409,   158,   125,   126,   119,     0,   121,   118,     0,     0,
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
      -649,  -649,  -649,   703,   706,  -649,   697,  -649,   472,   480,
    -303,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -426,  -649,  -649,  -649,  -649,  -649,
     573,   239,  -367,   705,     6,    -6,  -649,  -649,   682,  -649,
    -649,   214,   378,  -240,  -649,  -649,   205,  -649,   482,   484,
     149,  -649,  -649,   159,  -549,  -649,   -66,  -649,  -649,  -649,
     191,  -649,  -649,   492,   486,   206,  -594,   483,   207,  -344,
     208,   200,  -649,  -649,  -649,  -649,  -649,   684,  -649,  -649,
    -649,  -649,  -649,  -649,   681,  -649,   -49,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,    78,  -649,  -649,  -649,   379,   -76,
    -649,  -343,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -421,  -649,   203,  -649,   372,  -649,  -649,  -649,  -649,
    -649,     1,     0,  -556,  -444,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,   497,  -224,  -348,  -649,  -649,
     204,  -360,  -649,  -649,  -649,  -649,  -649,  -649,  -649,   793,
     801,  -266,   426,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,   337,  -649,  -649,   165,   173,   182,   361,  -649,  -649,
     193,  -649,  -473,  -649,  -649,  -649,  -649,    97,  -301,  -649,
     398,    95,  -649,  -446,  -649,  -649,  -649,  -649,  -648,  -649,
    -649,  -649,  -649,    77,   209,  -649
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   593,   252,   111,   112,   113,   114,
     397,   398,   618,   115,   116,   117,   118,   119,   120,   121,
     244,   245,   423,   424,   122,   254,   255,   327,   328,   490,
     491,   658,   659,   660,   661,   123,   241,   242,   124,   628,
     629,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   346,   347,
     348,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   373,   374,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   203,
     168,   169,   170,   620,   454,   455,   755,   832,   833,   826,
     827,   834,   828,   621,   622,   171,   172,   623,   173,   174,
     175,   176,   177,   178,   179,   534,   407,   529,   702,   530,
     531,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   547,   574,   190,   191,   192,   193,   194,   195,   196,
     287,   507,   681,   508,   509,   510,   511,   512,   513,   514,
     682,   683,   306,   307,   308,   309,   310,   853,   854,   311,
     476,   480,   647,   477,   312,   313,   685,   698,   779,   686,
     687,   692,   688,   860,   795,   670
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       202,   532,   532,   484,   595,   272,   506,   198,   200,   518,
     519,   520,   521,   435,   533,   420,   417,   487,   205,   425,
     270,   271,   210,   404,   600,   420,   404,   796,   556,   436,
     644,     7,   619,   584,   563,   684,   532,   262,   451,   441,
     206,   231,   532,   806,   532,   263,   237,   236,   557,   463,
     738,   772,   558,   246,   564,   204,   567,   321,   753,   257,
      18,   611,   612,   260,   759,   613,   247,   451,   321,   611,
     612,   474,   350,   613,   461,   227,   281,   282,   283,   285,
     274,   368,   276,   277,   278,   799,   627,    40,   587,   611,
     612,   481,   209,   613,   434,   614,   351,    27,   421,    29,
     321,    31,    32,   614,   452,   350,   381,   471,   611,   612,
     786,   787,   613,   764,    62,   558,   472,   385,    50,   228,
     211,   548,   503,   614,   650,   321,   387,   352,   504,   351,
     615,   412,   616,   624,   414,   321,   321,   321,   615,   793,
     616,   321,   614,   780,   794,   782,   573,   883,   575,     3,
     883,   462,   321,   478,   321,   321,     4,     5,   615,   475,
     616,   506,   506,   559,   560,   379,   555,   248,   422,   321,
     422,   745,   321,   442,   555,    13,   380,   615,   207,   616,
     264,   754,   651,   585,   238,   589,   773,   422,    17,   208,
     713,   453,   716,    59,   555,   239,   601,   719,   721,   619,
     532,    59,   644,   882,   619,   759,   532,   862,   803,   705,
     383,    36,   717,   555,   266,   464,   465,   382,   722,    42,
     625,    59,   617,    73,   466,   422,   565,   566,   386,   375,
     758,    73,   377,   384,   321,   422,   856,   388,   422,   479,
      59,   505,   413,   321,   389,   415,   427,    79,   438,   394,
     760,    73,   457,   481,   781,    79,   783,   321,   884,    87,
     408,   885,   411,   440,   212,   321,    56,   532,   404,   840,
      73,   321,   353,   447,   321,    79,   321,   456,   468,   763,
     458,    60,   321,   526,   249,   321,   482,   824,   824,   359,
     321,   611,   611,   219,    79,   613,   613,   542,    66,    67,
     542,    13,   542,   354,   213,   843,    72,   215,   360,   829,
     835,   220,    75,   267,    17,   488,   489,   492,   489,   494,
     394,   539,   540,   355,   214,   792,   526,   216,   250,   710,
     224,   549,   395,   396,   506,   554,   800,    36,   762,   483,
     619,    42,   459,   416,    13,    42,   506,   506,   739,   487,
     810,   544,     7,   580,   550,   812,   555,    17,   357,   225,
     615,   615,   616,   616,   221,   608,   217,   226,   404,   356,
     358,   825,   869,   704,   538,   543,   527,   229,   541,   751,
      36,    18,   790,   829,   807,   251,   218,   844,    42,   835,
     808,   230,    56,   813,   866,   551,   555,   555,   867,   235,
     568,   611,   258,   401,   402,   613,   240,    60,    40,   611,
     577,   357,   579,   613,   830,   582,   322,   232,   552,   527,
     243,    67,   830,   358,    66,    67,   562,    46,   598,   405,
     847,   848,   849,   850,   495,    56,   406,   654,    75,    50,
     253,   653,   259,   503,   609,   324,   569,   555,    52,   504,
      60,   857,   607,   570,   654,   265,   528,   858,   633,   634,
     635,   636,   261,   638,   639,   275,   641,    66,    67,   322,
     615,   857,   616,   268,   859,   656,   657,   858,   615,   655,
     616,    75,   831,   693,   694,   695,   696,   323,   269,   663,
     872,   665,   656,   657,   859,   712,   774,   775,   324,   528,
     715,   631,   331,   632,   718,   273,   555,   776,   777,   666,
     332,   697,   720,   333,   555,   334,   555,   532,   809,   811,
     778,   555,   222,   223,   325,   555,   335,   279,   881,   887,
     336,   357,   376,   555,   280,   337,   314,   889,   378,   555,
     555,   338,   286,   358,   774,   775,   699,   700,   701,   370,
     371,   707,   500,   501,   502,   776,   777,   515,   516,   524,
     525,   711,   319,   339,   723,   522,   523,   535,   535,   642,
     643,   321,   731,   320,   330,   329,   361,   725,   734,   362,
     736,   737,   891,   363,   349,   742,   372,   364,   390,   392,
     391,   393,   399,   746,   747,   400,   418,   419,   340,   341,
     342,   343,   344,   345,   409,     1,   410,   426,   428,   429,
       2,     3,   430,   431,   433,   432,   437,   439,     4,     5,
       6,   443,     7,   444,   445,   767,   768,     9,    10,   446,
     448,   769,   449,   450,   467,    11,    12,    13,    14,   460,
     469,   473,   526,   497,    15,   545,   470,   546,   553,    16,
      17,    18,   561,   571,   572,   578,   489,   581,   789,   583,
     586,   590,   592,   591,   594,   596,   597,   602,    33,    34,
     599,   603,    35,    36,    37,    38,    39,   604,    40,   610,
      41,    42,   630,   627,   605,   640,   645,   637,   646,   649,
     652,   662,   669,    44,    45,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    50,
     689,   664,   703,   708,   690,   709,   691,   404,   726,    53,
     394,   727,   728,   732,   729,   733,   730,   735,    56,   814,
     743,   740,   815,   744,   817,   748,   756,    57,   757,    58,
      59,   770,   821,    60,   750,   752,   771,    48,    49,    63,
      64,   766,    65,   784,   654,   791,   816,   818,   823,   819,
      66,    67,    68,   836,   845,   846,   820,   838,    72,   837,
      73,   839,   842,    74,    75,   841,   851,   481,   874,   863,
     868,    77,   875,   852,   871,   876,   877,   879,   890,   317,
     886,   485,   315,   888,    79,   316,   892,   714,   318,   486,
       1,   326,   403,   588,   741,     2,     3,   749,   493,   496,
     864,   788,   865,     4,     5,     6,   499,     7,   785,   765,
       8,   498,     9,    10,   367,   369,   626,   870,   761,   233,
      11,    12,    13,    14,   873,   517,   878,   234,   880,    15,
     576,   667,   797,    81,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,   536,   804,    33,    34,    87,   668,    35,    36,    37,
      38,    39,   805,    40,   802,    41,    42,   861,   648,   855,
       0,     0,   893,     0,     0,    43,   894,   798,    44,    45,
       0,    46,     0,     0,     0,     0,     0,     0,    47,    48,
      49,     0,     0,     0,    50,     0,     0,     0,     0,     0,
       0,    51,    52,     0,    53,     0,    54,     0,    55,     0,
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
     606,     0,     0,     0,     0,     0,    66,    67,    68,     0,
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
      62,     0,     0,    63,    64,     0,    65,     0,   706,     0,
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
       0,    63,    64,     0,    65,     0,   724,     0,     0,     0,
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
       0,     0,    44,    45,   671,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,    51,     0,     0,    53,     0,
      54,     0,     0,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    57,     0,    58,    59,
     671,     0,    60,     0,    61,    62,     0,     0,    63,    64,
       0,    65,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,     0,    69,    70,     0,     0,    72,     0,    73,
       0,     0,    74,    75,   672,     0,     0,   673,   288,   289,
      77,   290,   291,   674,   675,   676,     0,     0,    78,     0,
       0,   677,   292,    79,   293,     0,     0,     0,     0,     0,
     678,     0,     0,     0,     0,   294,   679,   680,     0,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     672,     0,     0,   673,   288,   289,     0,   290,   291,   674,
     675,   676,     0,     0,     0,     0,     0,     0,   292,     0,
     293,     0,     0,     0,     0,     0,   678,     0,     0,     0,
       0,   294,   801,   680,     0,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   288,   289,     0,   290,
     291,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     292,     0,   293,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   294,     0,     0,     0,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         6,   361,   362,   304,   430,    71,   349,     1,     2,   353,
     354,   355,   356,   253,   362,    32,   240,   320,    12,   243,
      69,    70,    16,    30,    98,    32,    30,   675,   395,   253,
     476,    21,   453,   105,   401,   508,   396,    13,    18,     6,
      18,    35,   402,   691,   404,    21,    18,    41,   396,    30,
     105,    21,    45,    47,   402,   112,   404,    45,    29,    53,
      50,     7,     8,    57,   620,    11,    22,    18,    45,     7,
       8,    90,   120,    11,    85,   135,    82,    83,    84,    85,
      74,   112,    76,    77,    78,   679,    38,    77,   105,     7,
       8,    32,    14,    11,    98,    41,   144,    59,   105,    61,
      45,    63,    64,    41,    84,   120,    45,   198,     7,     8,
     659,   660,    11,    65,   145,    45,   207,    45,   108,   179,
     156,   387,   112,    41,    65,    45,    45,   175,   118,   144,
      76,    45,    78,    84,    45,    45,    45,    45,    76,   238,
      78,    45,    41,    45,   243,    45,   412,    45,   414,    10,
      45,   162,    45,    32,    45,    45,    17,    18,    76,   178,
      78,   504,   505,   156,   157,   153,   112,   123,   242,    45,
     242,   597,    45,   140,   112,    36,   153,    76,   156,    78,
     156,   152,   483,   423,   156,   425,   156,   242,    49,   167,
     557,   171,   559,   139,   112,   167,   436,   564,   565,   620,
     560,   139,   648,   851,   625,   761,   566,   801,   681,   154,
     204,    72,   560,   112,    13,   196,   197,   156,   566,    80,
     171,   139,   168,   169,   205,   242,   156,   157,   156,   151,
     168,   169,   154,   153,    45,   242,   785,   156,   242,   118,
     139,   231,   156,    45,   153,   156,   156,   193,   156,    73,
     168,   169,   156,    32,   156,   193,   156,    45,   156,   221,
     153,   156,   153,   153,    22,    45,   127,   627,    30,   168,
     169,    45,    70,   267,    45,   193,    45,   153,   284,   627,
     153,   142,    45,    18,    22,    45,    65,     3,     3,    90,
      45,     7,     7,    22,   193,    11,    11,   373,   159,   160,
     376,    36,   378,   101,   150,    73,   167,   150,   109,   753,
     754,   123,   173,   112,    49,   321,   322,   323,   324,   325,
      73,   370,   371,   121,   170,   669,    18,   170,    66,   553,
      19,   106,   156,   157,   677,    91,   680,    72,    73,   118,
     761,    80,   153,   105,    36,    80,   689,   690,   588,   652,
     717,   153,    21,   419,   129,   722,   112,    49,   178,    13,
      76,    76,    78,    78,   123,   153,   130,    18,    30,   167,
     190,    87,    87,   153,   368,   381,   111,    19,   372,   153,
      72,    50,   153,   827,   153,   123,   150,   155,    80,   833,
     153,    23,   127,   153,   820,   106,   112,   112,   153,    23,
     406,     7,    13,   156,   157,    11,    23,   142,    77,     7,
     416,   178,   418,    11,    20,   421,   137,   156,   129,   111,
      23,   160,    20,   190,   159,   160,    91,    95,   434,    91,
     774,   775,   776,   777,   155,   127,    98,    44,   173,   108,
      23,    31,   156,   112,   450,   166,    91,   112,   116,   118,
     142,   238,   446,    98,    44,    18,   191,   244,   464,   465,
     466,   467,    15,   469,   470,   156,   472,   159,   160,   137,
      76,   238,    78,    18,   261,    82,    83,   244,    76,    69,
      78,   173,    88,   211,   212,   213,   214,   155,    18,   495,
      88,   497,    82,    83,   261,    91,   216,   217,   166,   191,
      91,   204,    86,   206,    91,    18,   112,   227,   228,   503,
      94,   239,    91,    97,   112,    99,   112,   877,    91,    91,
     240,   112,    82,    83,   192,   112,   110,    25,   175,   877,
     114,   178,   153,   112,    21,   119,     0,   881,   159,   112,
     112,   125,    23,   190,   216,   217,   131,   132,   133,   163,
     164,   545,   346,   347,   348,   227,   228,   350,   351,   359,
     360,   555,   162,   147,   570,   357,   358,   363,   364,   474,
     475,    45,   578,   162,    28,   134,   107,   571,   584,   176,
     586,   587,   883,    39,   230,   591,   113,    40,    45,    22,
      45,    22,    86,   599,   600,    21,   158,   198,   182,   183,
     184,   185,   186,   187,   156,     4,   156,    45,    32,    13,
       9,    10,    32,   123,    22,    13,    45,    86,    17,    18,
      19,   156,    21,   156,    16,   631,   632,    26,    27,   112,
     156,   637,   156,   158,    30,    34,    35,    36,    37,   194,
     210,    21,    18,   155,    43,   112,    98,    18,    23,    48,
      49,    50,    22,   112,    18,   105,   662,    73,   664,    73,
     105,    73,    22,   174,    86,    86,    32,    73,    67,    68,
      98,    22,    71,    72,    73,    74,    75,   140,    77,    86,
      79,    80,    21,    38,   146,    23,    21,   210,    21,    21,
     162,    45,   249,    92,    93,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   108,
     229,   155,   100,   156,   236,   156,   237,    30,   100,   118,
      73,   156,   156,    23,   156,    23,   156,   105,   127,   735,
      45,   105,   738,    22,   740,    98,     6,   136,    18,   138,
     139,    98,   748,   142,   162,   112,   155,   103,   104,   148,
     149,   162,   151,    22,    44,   156,   105,    81,   752,    22,
     159,   160,   161,    42,   770,   771,    32,    18,   167,   171,
     169,    18,   155,   172,   173,    23,    21,    32,   171,   245,
      29,   180,   171,   234,   152,    18,    30,    23,   234,    92,
     171,   319,    89,   155,   193,    89,   155,   558,    93,   319,
       4,   119,   229,   425,   590,     9,    10,   602,   324,   327,
     816,   662,   818,    17,    18,    19,   330,    21,   659,   628,
      24,   329,    26,    27,   140,   144,   454,   827,   625,    36,
      34,    35,    36,    37,   833,   352,   842,    36,   844,    43,
     414,   504,   677,   199,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   364,   689,    67,    68,   221,   505,    71,    72,    73,
      74,    75,   690,    77,   681,    79,    80,   800,   480,   782,
      -1,    -1,   888,    -1,    -1,    89,   892,   678,    92,    93,
      -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,
      -1,   115,   116,    -1,   118,    -1,   120,    -1,   122,    -1,
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
     255,   256,   257,   258,   259,   260,   219,   220,    -1,   222,
     223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     233,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,    -1,    -1,    -1,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260
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
     156,   153,    45,   156,    45,   156,   105,   408,   158,   198,
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
      98,   112,    18,   423,   424,   423,   424,   307,   105,   307,
     328,    73,   307,    73,   105,   315,   105,   105,   314,   315,
      73,   174,    22,   296,    86,   296,    86,    32,   307,    98,
      98,   315,    73,    22,   140,   146,   153,   306,   153,   307,
      86,     7,     8,    11,    41,    76,    78,   168,   304,   383,
     385,   395,   396,   399,    84,   171,   387,    38,   331,   332,
      21,   204,   206,   307,   307,   307,   307,   210,   307,   307,
      23,   307,   453,   453,   455,    21,    21,   454,   452,    21,
      65,   450,   162,    31,    44,    69,    82,    83,   323,   324,
     325,   326,    45,   307,   155,   307,   306,   433,   439,   249,
     467,   135,   215,   218,   224,   225,   226,   232,   241,   247,
     248,   434,   442,   443,   444,   458,   461,   462,   464,   229,
     236,   237,   463,   211,   212,   213,   214,   239,   459,   131,
     132,   133,   410,   100,   153,   154,   153,   306,   156,   156,
     408,   306,    91,   304,   303,    91,   304,   409,    91,   304,
      91,   304,   409,   307,   153,   306,   100,   156,   156,   156,
     156,   307,    23,    23,   307,   105,   307,   307,   105,   315,
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
      -1,   329,    -1,   329,   198,   328,    -1,    23,   105,   307,
      -1,    23,   408,   105,   307,    -1,   177,   306,   156,   331,
      65,   155,   307,    -1,   177,   306,   156,   331,    65,    73,
      23,   155,   307,    -1,   332,    -1,   331,   332,    -1,    38,
     409,   155,   307,    -1,    38,    73,    23,    30,   409,   155,
     307,    -1,   102,   306,   156,   174,   307,    81,   307,    -1,
     335,    -1,   334,   134,   335,    -1,   336,    -1,   335,    28,
     336,    -1,   337,    -1,   337,   351,   337,    -1,   337,   350,
     337,    -1,   337,   352,   337,    -1,   338,    -1,   338,   230,
     433,    -1,   338,   230,   433,   467,    -1,   339,    -1,   339,
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
         0,   725,   725,   731,   735,   739,   749,   753,   763,   771,
     784,   797,   810,   817,   824,   837,   844,   859,   866,   881,
     886,   891,   896,   906,   911,   916,   923,   934,   939,   944,
     949,   954,   959,   964,   971,   982,   987,  1003,  1016,  1022,
    1034,  1041,  1054,  1068,  1080,  1086,  1099,  1105,  1117,  1124,
    1131,  1138,  1158,  1170,  1182,  1190,  1198,  1206,  1220,  1227,
    1243,  1248,  1259,  1266,  1274,  1281,  1296,  1304,  1312,  1320,
    1334,  1340,  1352,  1360,  1369,  1378,  1388,  1398,  1408,  1418,
    1428,  1436,  1445,  1454,  1464,  1474,  1484,  1494,  1510,  1519,
    1534,  1541,  1554,  1566,  1578,  1585,  1598,  1603,  1608,  1613,
    1618,  1625,  1630,  1635,  1640,  1645,  1656,  1664,  1674,  1683,
    1698,  1705,  1718,  1723,  1734,  1746,  1753,  1768,  1776,  1785,
    1795,  1806,  1815,  1825,  1835,  1851,  1864,  1876,  1889,  1896,
    1911,  1920,  1930,  1939,  1955,  1967,  1973,  1986,  1993,  2008,
    2015,  2028,  2036,  2044,  2052,  2060,  2068,  2076,  2090,  2095,
    2106,  2112,  2124,  2136,  2144,  2158,  2166,  2181,  2188,  2202,
    2210,  2225,  2232,  2245,  2252,  2266,  2278,  2283,  2295,  2300,
    2320,  2325,  2334,  2343,  2358,  2363,  2371,  2385,  2390,  2402,
    2407,  2412,  2423,  2427,  2432,  2437,  2442,  2453,  2458,  2464,
    2476,  2481,  2486,  2497,  2502,  2515,  2520,  2533,  2538,  2551,
    2556,  2569,  2574,  2587,  2592,  2597,  2602,  2615,  2620,  2625,
    2637,  2642,  2647,  2652,  2657,  2662,  2673,  2678,  2683,  2688,
    2693,  2698,  2709,  2714,  2719,  2731,  2736,  2749,  2756,  2769,
    2776,  2791,  2835,  2840,  2845,  2850,  2861,  2866,  2871,  2882,
    2887,  2898,  2905,  2912,  2919,  2932,  2939,  2951,  2956,  2961,
    2966,  2971,  2976,  2981,  2992,  2997,  3008,  3015,  3028,  3033,
    3038,  3043,  3048,  3064,  3069,  3080,  3085,  3096,  3104,  3112,
    3126,  3131,  3144,  3151,  3166,  3178,  3183,  3188,  3193,  3198,
    3203,  3208,  3213,  3224,  3229,  3240,  3245,  3250,  3261,  3272,
    3277,  3289,  3300,  3312,  3369,  3376,  3389,  3396,  3409,  3414,
    3425,  3430,  3435,  3446,  3455,  3464,  3473,  3482,  3491,  3507,
    3514,  3527,  3534,  3549,  3562,  3568,  3581,  3585,  3592,  3599,
    3606,  3615,  3630,  3634,  3641,  3648,  3655,  3664,  3679,  3685,
    3697,  3703,  3715,  3721,  3727,  3734,  3747,  3754,  3761,  3767,
    3773,  3785,  3802,  3808,  3826,  3842,  3847,  3852,  3857,  3862,
    3867,  3878,  3890,  3897,  3904,  3910,  3934,  3941,  3948,  3954,
    3966,  3978,  3990,  3997,  4004,  4010,  4022,  4029,  4042,  4054,
    4061,  4068,  4106,  4112,  4118,  4130,  4135,  4140,  4151,  4163,
    4168,  4173,  4178,  4183,  4188,  4193,  4198,  4203,  4214,  4225,
    4230,  4236,  4248,  4259,  4270,  4275,  4280,  4291,  4298,  4305,
    4312,  4319,  4332,  4344,  4351,  4358,  4365,  4372,  4380,  4388,
    4402,  4424,  4432,  4453,  4493,  4503,  4507,  4511,  4515,  4519,
    4529,  4539,  4543,  4553,  4578,  4588,  4592,  4610,  4614,  4618,
    4622,  4632,  4636,  4640,  4644,  4654,  4658,  4668,  4672,  4682,
    4686,  4696,  4700,  4710,  4714,  4718,  4728,  4732,  4742,  4746,
    4756,  4760,  4764,  4768,  4772,  4782,  4792,  4797,  4802,  4807,
    4812,  4817,  4822,  4833,  4837,  4841,  4845,  4855,  4859,  4863,
    4867,  4877,  4881,  4891,  4895,  4899,  4903,  4907,  4911,  4915,
    4925,  4929,  4939,  4943,  4947,  4951,  4961,  4965,  4969,  4973,
    4977,  4987,  4991,  5001,  5005,  5015,  5019,  5029,  5033,  5043,
    5053,  5057,  5067,  5071,  5075,  5085,  5089,  5093,  5097,  5101,
    5111,  5115,  5119,  5123,  5133,  5143,  5153,  5163,  5167,  5177,
    5181,  5185,  5195,  5199,  5209
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
  const int xquery_parser::yylast_ = 3727;
  const int xquery_parser::yynnts_ = 196;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 314;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 272;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 526;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace yy

#line 5217 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"



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





