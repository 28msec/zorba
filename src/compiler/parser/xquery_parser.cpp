
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* First part of user declarations.  */

/* Line 311 of lalr1.cc  */
#line 45 "/root/zorba/src/compiler/parser/xquery_parser.y"


#include "common/common.h"

#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

#include <string>

#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/api/compilercb.h"
#include "store/api/update_consts.h"

#define SYMTAB( n ) driver.symtab.get ((off_t) n)
#define SYMTAB_PUT( s ) driver.symtab.put (s)
#define LOC( p ) driver.createQueryLoc(p)

namespace zorba 
{
namespace parser
{
  extern const char *the_tumbling, *the_sliding, *the_start, *the_end, *the_only_end, *the_ofor, *the_declare, *the_create;
}
}

#define YYDEBUG 1



/* Line 311 of lalr1.cc  */
#line 75 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 893 "/root/zorba/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc  */
#line 92 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"

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

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

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

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace zorba {

/* Line 380 of lalr1.cc  */
#line 161 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
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
#endif

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
        case 102: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 777 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 268 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 114: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 776 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 277 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 138: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 775 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 286 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 295 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 304 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 313 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 322 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 331 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 340 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 349 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 358 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 367 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 376 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 789 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair_vector); };

/* Line 480 of lalr1.cc  */
#line 385 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 789 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair); };

/* Line 480 of lalr1.cc  */
#line 394 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 403 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 412 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 421 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 430 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 439 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 448 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 457 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 466 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 475 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 484 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 493 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 502 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 511 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 520 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 529 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 538 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 547 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 556 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 565 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 789 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 574 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 583 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 592 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "CollectionModifier" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 601 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 610 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 619 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "IndexProperties" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 628 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "IndexProperties2" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 637 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "IndexProperties3" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 646 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 655 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 664 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 673 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 789 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 682 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 691 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 700 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 709 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 718 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 727 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 736 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 745 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 754 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 763 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 772 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 781 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 790 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 799 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 808 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 817 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 826 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 835 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 844 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 853 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 862 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 871 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 880 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 889 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 898 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 907 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 916 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 925 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 934 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 943 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 952 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 961 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 970 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 979 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 988 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 997 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1006 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1015 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1024 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1033 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1042 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1051 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1060 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1069 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1078 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1087 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1096 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1105 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1114 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1123 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1132 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1141 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1150 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1159 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1168 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1177 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1186 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1195 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1204 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1213 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1222 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1231 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1240 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1249 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1258 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1267 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1276 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1285 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1294 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1303 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1312 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1321 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1330 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1339 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1348 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1357 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1366 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1375 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1384 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1393 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1402 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1411 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "PragmaList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1420 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1429 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1438 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1447 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1456 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1465 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1474 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1483 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1492 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1501 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1510 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1519 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1528 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1537 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1546 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1555 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1564 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1573 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1582 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1591 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1600 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1609 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1618 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1627 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1636 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1645 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1654 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1663 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1672 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1681 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1690 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1699 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1708 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1717 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "Opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1726 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1735 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "Opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1744 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1753 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1762 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1771 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1780 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1789 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1798 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1807 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1816 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1825 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1834 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1843 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1852 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1861 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1870 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1879 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1888 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1897 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1906 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1915 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1924 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1933 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1942 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1951 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1960 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1969 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1978 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1987 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1996 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2005 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2014 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2023 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2032 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 785 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2041 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2050 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2059 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2068 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2077 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2086 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2095 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2104 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2113 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2122 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2131 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2140 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 789 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2149 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2158 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/root/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2167 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;

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

#if YYDEBUG
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
#endif

  int
  xquery_parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 553 of lalr1.cc  */
#line 94 "/root/zorba/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 553 of lalr1.cc  */
#line 2252 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"

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

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
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

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
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
	  case 3:

/* Line 678 of lalr1.cc  */
#line 911 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 921 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 926 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 932 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 937 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 943 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 948 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 960 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 965 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 975 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 982 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 994 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC ((yyloc)), false,
                             static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)),
                             NULL);
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1000 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)), false,
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1012 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), 
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
      dynamic_cast<ModuleDecl *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1025 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC ((yyloc)), true,
                             static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)),
                             NULL);
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1031 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)), true,
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1043 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)));
      // dynamic_cast<ModuleDecl *>($$)->setComment(SYMTAB($1));
		}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1054 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL);
		}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1058 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1062 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)),
                      static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
                      static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1074 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		}
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1080 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1094 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		}
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1100 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1143 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1148 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr))->get_qname(), (yysemantic_stack_[(4) - (4)].pair_vector)); 
      delete (yysemantic_stack_[(4) - (3)].expr);
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1157 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.pair_vector) = new std::vector<std::pair<std::string, std::string> > ();
      (yyval.pair_vector)->push_back(*(yysemantic_stack_[(1) - (1)].pair));
      delete (yysemantic_stack_[(1) - (1)].pair);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1163 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].pair_vector)->push_back(*(yysemantic_stack_[(2) - (2)].pair));
      delete (yysemantic_stack_[(2) - (2)].pair);
      (yyval.pair_vector) = (yysemantic_stack_[(2) - (1)].pair_vector);
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1172 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *s = static_cast<StringLiteral *>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.pair) = new std::pair<std::string, std::string>((yysemantic_stack_[(3) - (1)].strval), s->get_strval());
      delete s;
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1180 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1181 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1182 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1183 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1184 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1185 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1186 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1187 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1188 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1189 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1226 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1238 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1243 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1254 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1260 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1272 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1285 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1296 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1301 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1313 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1318 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1329 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1335 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1341 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1347 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1366 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1377 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1388 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1395 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		}
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1402 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1409 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1422 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1428 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1443 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1447 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		}
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1457 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1464 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (6)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
		}
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1472 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
		}
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1479 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(8) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
		}
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1487 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), true,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1494 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), true,
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (6)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
		}
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1502 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), true,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
		}
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1509 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), true,
								SYMTAB ((yysemantic_stack_[(8) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
		}
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1522 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1529 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1535 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1542 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1548 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1552 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1559 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1570 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1575 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                               dynamic_cast<SequenceType *> ((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1584 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								nt->name,
								nt->type,
								(yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
		}
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1593 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
		}
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1600 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1610 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                               0, 0, 0);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1617 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                               (yysemantic_stack_[(5) - (5)].node), 
                               0, 0);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1624 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                               0, 
                               static_cast<CollectionModifier*>((yysemantic_stack_[(4) - (4)].node)), 
                               0);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1632 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                               (yysemantic_stack_[(6) - (5)].node), 
                               static_cast<CollectionModifier*>((yysemantic_stack_[(6) - (6)].node)), 
                               0);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1640 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                               0, 
                               0, 
                               static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1648 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                               (yysemantic_stack_[(6) - (5)].node), 
                               0, 
                               static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1656 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                               0, 
                               static_cast<CollectionModifier*>((yysemantic_stack_[(5) - (4)].node)), 
                               static_cast<NodeModifier*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1664 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                               (yysemantic_stack_[(7) - (5)].node), 
                               static_cast<CollectionModifier*>((yysemantic_stack_[(7) - (6)].node)), 
                               static_cast<NodeModifier*>((yysemantic_stack_[(7) - (7)].node)));
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1675 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionModifier(LOC((yyloc)), StaticContextConsts::const_);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1679 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionModifier(LOC((yyloc)), StaticContextConsts::append_only);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1683 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionModifier(LOC((yyloc)), StaticContextConsts::queue);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1687 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionModifier(LOC((yyloc)), StaticContextConsts::mutable_coll);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1695 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1699 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1707 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(9) - (3)].expr)),
                         (yysemantic_stack_[(9) - (5)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (7)].node)),
                         dynamic_cast<IndexProperties*>((yysemantic_stack_[(9) - (9)].node)));
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1719 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1724 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexProperties* p = dynamic_cast<IndexProperties*>((yysemantic_stack_[(2) - (2)].node));
      p->setUnique();
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1731 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1738 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1743 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexProperties* p = dynamic_cast<IndexProperties*>((yysemantic_stack_[(2) - (2)].node));
      p->setOrdered();
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1750 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1756 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      // default properties: non-unique, non-ordered, manual
      (yyval.node) = new IndexProperties(LOC((yyloc)), false, false, false);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1761 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperties(LOC((yyloc)), false, false, false);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1766 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperties(LOC((yyloc)), false, false, true);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1774 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* l = new IndexKeyList(LOC((yyloc)));
      l->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1780 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1789 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1794 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1801 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1808 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1821 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		}
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1826 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		}
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1838 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1842 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1846 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1850 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1857 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1864 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      if ((yysemantic_stack_[(4) - (2)].node) == NULL)
      {
        (yyval.expr) = (yysemantic_stack_[(4) - (3)].expr);
      }
      else 
      {
        BlockBody* b = dynamic_cast<BlockBody *>((yysemantic_stack_[(4) - (3)].expr));
        VFO_DeclList* vfo = dynamic_cast<VFO_DeclList *>((yysemantic_stack_[(4) - (2)].node));
        if (b == NULL) 
        {
          b = new BlockBody((yysemantic_stack_[(4) - (3)].expr)->get_location(), vfo);
          b->add((yysemantic_stack_[(4) - (3)].expr));
        }
        else 
        {
          b->set_decls(vfo);
        }

        (yyval.expr) = b;
      }
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1890 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      std::auto_ptr<VFO_DeclList> vfo2(dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (2)].node)));
      if ((yysemantic_stack_[(3) - (1)].node) == NULL)
        vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back (*(vfo2.get()));
      (yyval.node) = vfo;
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1899 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1906 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      vfo->push_back ((yysemantic_stack_[(3) - (3)].node));
      (yyval.node) = vfo;
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1912 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back ((yysemantic_stack_[(2) - (2)].node));
      (yyval.node) = vfo;
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1921 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(1) - (1)].varnametype)));
      VarDecl *vd = new VarDecl(LOC ((yyloc)),
                       nt->name,
                       nt->type,
                       NULL);
      vd->set_global (false);
			(yyval.node) = vd;
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1931 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      VarDecl *vd = new VarDecl(LOC ((yyloc)),
                       nt->name,
                       nt->type,
                       (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global (false);
			(yyval.node) = vd;
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1944 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr))->get_qname(), (yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (3)].expr);
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1952 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1959 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* b = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
      if (b == NULL) 
      {
        b = new BlockBody((yysemantic_stack_[(5) - (5)].expr)->get_location()); 
        b->add((yysemantic_stack_[(5) - (5)].expr));
      }

      (yyval.expr) = new WhileExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), b);
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1973 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1977 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1984 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { 
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(2) - (2)].node))->setComment(SYMTAB((yysemantic_stack_[(2) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1989 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      d->deterministic = false;
      (yyval.node) = d;
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1996 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(3) - (3)].node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2004 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2008 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2012 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->type = (d->type == ParseConstants::fn_extern)
        ? ParseConstants::fn_extern_update
        : ParseConstants::fn_update;
      (yyval.node) = d;
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2020 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2027 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2036 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2048 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2057 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern_sequential);
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2070 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		}
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2078 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2092 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
								NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2099 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2112 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2120 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2131 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2146 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2150 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<BlockBody> blk(dynamic_cast<BlockBody *>((yysemantic_stack_[(2) - (2)].expr)));

      BlockBody* blk2 = new BlockBody(LOC((yyloc)));

      blk2->add((yysemantic_stack_[(2) - (1)].expr));

      for (int i = 0; i < blk->size(); ++i)
        blk2->add((*blk)[i]);

      (yyval.expr) = blk2;
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2166 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2170 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = dynamic_cast<BlockBody *>((yysemantic_stack_[(3) - (1)].expr));
      blk->add((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2179 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2183 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p == NULL) 
      {
        expr_p = new Expr(LOC((yyloc)));
        expr_p->push_back((yysemantic_stack_[(3) - (1)].expr));
      }
      expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = expr_p;
		}
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2228 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr(LOC((yyloc)),
                         dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)),
                         lReturnExpr->get_return_val(),
                         lReturnExpr->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2241 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2248 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2252 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2260 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2264 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2268 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2275 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2279 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2286 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2294 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2305 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2324 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2330 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2339 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2343 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2353 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		}
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2364 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		}
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2370 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2384 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2392 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2401 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2411 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (1)].expr);
		}
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2422 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2431 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (1)].expr);
		}
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2441 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (1)].expr);
		}
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2451 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
      delete (yysemantic_stack_[(6) - (1)].expr);
		}
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2467 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2480 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2492 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		}
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2504 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2510 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2522 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2528 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2542 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2551 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2561 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2570 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (1)].expr);
		}
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2583 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr))->get_qname(),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (2)].expr);
		}
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2590 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (2)].expr);
		}
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2602 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), "", "");
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2607 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2616 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2620 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2629 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr))->get_qname(), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr))->get_qname());
      delete (yysemantic_stack_[(6) - (3)].expr);
      delete (yysemantic_stack_[(6) - (6)].expr);
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2635 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2640 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname(), "");
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2648 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string name = static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))->get_qname();
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
      delete (yysemantic_stack_[(1) - (1)].expr);
                           
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2664 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2672 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2679 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2685 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2696 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
                 NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2703 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2713 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2723 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2728 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		}
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2740 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		}
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2746 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2760 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		}
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2766 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
                         (yysemantic_stack_[(2) - (1)].expr),
                         dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2778 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
                               NULL,
                               NULL);
		}
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2785 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
                               NULL);
		}
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2792 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               NULL,
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2799 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                               NULL);
		}
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2806 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                               NULL,
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2813 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2820 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2833 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		}
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2837 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		}
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2847 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC((yyloc)), StaticContextConsts::empty_greatest);
		}
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2851 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC((yyloc)), StaticContextConsts::empty_least);
		}
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2861 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2872 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2879 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2892 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		}
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2899 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2911 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2918 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2932 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2939 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname(),
								(yysemantic_stack_[(10) - (10)].expr));
      delete (yysemantic_stack_[(10) - (8)].expr);
		}
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2954 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		}
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2960 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2972 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2978 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr))->get_qname(),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
      delete (yysemantic_stack_[(7) - (3)].expr);
		}
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2992 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3003 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3007 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3018 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3022 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3041 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3045 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3053 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3061 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3069 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3076 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3077 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3085 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3093 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3101 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3115 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3119 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		}
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3126 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3139 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3143 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3154 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3158 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3162 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3172 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3176 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3180 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3184 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3188 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3198 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3202 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3207 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3218 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3222 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3226 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3236 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3240 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3252 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3256 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3268 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3272 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3284 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3288 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3300 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3304 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3316 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		}
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3320 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		}
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3324 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3328 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3340 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3344 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3348 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3358 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		}
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3362 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		}
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3366 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		}
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3370 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		}
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3374 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		}
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3378 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		}
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3388 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		}
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3392 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		}
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3396 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		}
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3406 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3410 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3414 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3418 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3430 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		}
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3436 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3448 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		}
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3454 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3468 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		}
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3474 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval))),
								"");      
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3516 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		}
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3520 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3524 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3528 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3540 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3550 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       AxisStep *as = dynamic_cast<AxisStep *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (as != NULL ?
             new RelativePathExpr(LOC ((yyloc)),
                                  ParseConstants::st_slash,
                                  new ContextItemExpr(LOC((yyloc)), true),
                                  (yysemantic_stack_[(1) - (1)].expr)) :
             (yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3561 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3566 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3576 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3580 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3590 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3596 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3602 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3608 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3620 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3626 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3637 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		}
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3641 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		}
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3645 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		}
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3649 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		}
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3653 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		}
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3657 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		}
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3661 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		}
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3671 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node), false);
		}
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3675 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		}
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3685 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3689 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC((yyloc)), rev_p, NULL);
		}
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3700 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		}
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3704 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		}
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3708 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		}
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3712 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		}
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3716 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		}
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3731 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3735 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3745 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3749 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3759 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		}
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3766 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		}
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3773 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		}
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3786 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3790 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3802 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		}
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3808 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3822 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3833 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3837 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3841 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3845 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3849 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3853 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3857 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3861 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3871 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3875 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3885 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		}
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3890 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		}
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3895 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		}
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3906 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3917 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		}
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3921 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3932 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		}
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3942 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3953 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4009 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
								NULL);
		}
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4015 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4027 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		}
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4033 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4045 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4049 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4059 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4063 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4067 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4077 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL,
								NULL,
								NULL);
		}
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4085 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		}
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4093 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
								NULL,
								NULL);
		}
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4101 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		}
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4109 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		}
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4117 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		}
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4132 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		}
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4138 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4150 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4156 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4169 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4186 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4191 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4202 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		}
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4206 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4213 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		}
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4219 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		}
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4225 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4233 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4247 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		}
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4251 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4258 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		}
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4264 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4270 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4278 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4292 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4297 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4308 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4313 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4324 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4329 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4334 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		}
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4340 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		}
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4352 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4358 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		}
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4363 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		}
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4368 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4379 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4384 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4399 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4404 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4421 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4436 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4440 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4444 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4448 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4452 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4456 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4466 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4477 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL);
		}
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4483 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4489 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4494 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4516 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (2)].expr),
								NULL);
		}
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4522 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4528 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4533 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4544 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4554 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4564 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		}
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4570 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4576 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4581 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4592 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		}
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4598 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		}
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4610 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		}
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4621 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		}
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4627 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4633 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		}
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4670 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		}
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4675 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		}
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4680 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		}
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4691 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4695 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4699 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		}
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4709 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4720 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4724 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4728 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4732 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4736 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4740 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4744 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4748 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4752 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4762 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		}
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4772 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		}
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4776 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4781 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4792 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		}
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4802 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		}
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4812 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		}
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4816 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4820 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4830 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4836 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								NULL);
		}
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4842 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4848 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4854 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4866 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
		}
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4877 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		}
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4884 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                           NULL,
                           true);
		}
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4891 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		}
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4898 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		}
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4905 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		}
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4912 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		}
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4919 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		}
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4932 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)));
		}
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4953 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4960 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)),
								true);
		}
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4980 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 5020 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::strict_validation);
		}
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 5024 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::lax_validation);
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 5028 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::skip_validation);
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 5037 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 5043 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 5049 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 5055 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 5061 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 5068 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 5074 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 5080 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 5086 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5092 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5104 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5109 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5119 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5125 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5137 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5163 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5174 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = new CopyVarList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		}
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5180 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		}
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5193 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(), (yysemantic_stack_[(3) - (3)].expr));  
       delete (yysemantic_stack_[(3) - (1)].expr);
    }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5208 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5215 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5221 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5232 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(3) - (2)].name_test_list),
                          (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5239 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(7) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr))->get_qname(),
                          (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (5)].expr);
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5249 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(10) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(10) - (5)].expr))->get_qname(),
                          static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname(),
                          (yysemantic_stack_[(10) - (10)].expr));
       delete (yysemantic_stack_[(10) - (5)].expr);
       delete (yysemantic_stack_[(10) - (8)].expr);
       delete (yysemantic_stack_[(10) - (2)].name_test_list);
    }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5260 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(13) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(13) - (5)].expr))->get_qname(),
                          static_cast<QName*>((yysemantic_stack_[(13) - (8)].expr))->get_qname(),
                          static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr))->get_qname(),
                          (yysemantic_stack_[(13) - (13)].expr));
       delete (yysemantic_stack_[(13) - (5)].expr);
       delete (yysemantic_stack_[(13) - (8)].expr);
       delete (yysemantic_stack_[(13) - (11)].expr);
       delete (yysemantic_stack_[(13) - (2)].name_test_list);
    }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5276 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list = new CatchExpr::NameTestList;
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5282 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list =
        static_cast<CatchExpr::NameTestList *> ((yysemantic_stack_[(3) - (1)].name_test_list));
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5302 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<QName> lQName(static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
      std::string tmp = lQName->get_qname();
      if (tmp.find (':') != std::string::npos) {
        error((yylocation_stack_[(1) - (1)]), "A NCName is expected, found a QName");
        YYERROR;
      }
      (yyval.sval) = SYMTAB_PUT(tmp.c_str());
    }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5320 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))); 
    }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5324 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))); 
    }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5330 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5331 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5332 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5333 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5334 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5335 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5336 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5337 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5338 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5339 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5340 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5341 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5342 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5343 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5344 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5345 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5346 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5347 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5348 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5349 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5350 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5351 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5352 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5353 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5354 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5355 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5356 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5357 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5358 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5359 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5360 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5361 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5362 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5363 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5364 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5365 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5366 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5367 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5368 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5369 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5370 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5371 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5372 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5373 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5374 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5375 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5376 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5377 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5378 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5379 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5380 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5381 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5382 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5383 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5384 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5385 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5386 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5387 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5388 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5389 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5390 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5391 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5392 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5393 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5394 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5395 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5396 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5397 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5398 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5399 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5400 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5401 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5402 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5403 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5404 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5405 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5406 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5407 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5408 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5409 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5410 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5411 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5412 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5413 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5414 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5415 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5416 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5417 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5418 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5419 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5420 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5421 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5422 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5423 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5424 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5425 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5426 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5427 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5428 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5429 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5430 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5431 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5432 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5433 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5434 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5435 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5436 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5437 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5438 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5439 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5440 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5441 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5442 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5443 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5444 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5445 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5446 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5447 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5448 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5449 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5450 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5451 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5452 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5453 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5454 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5455 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5456 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5457 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5458 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5459 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5460 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5461 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5462 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5463 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5464 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5465 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5466 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5467 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5468 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5469 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5470 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5471 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5472 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5473 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5474 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5475 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5476 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5477 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5478 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5479 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5480 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5481 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5482 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5483 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5484 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5485 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("returning"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5486 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5487 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5488 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5489 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5490 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5491 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5492 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5493 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5494 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5495 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5496 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5497 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5498 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5499 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("non"); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5500 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5501 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("manual"); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5502 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("automatic"); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5503 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-format"); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5504 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-separator"); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5505 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("grouping-separator"); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5506 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("infinity"); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5507 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("minus-sign"); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5508 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("NaN"); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5509 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("percent"); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5510 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("per-mille"); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5511 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("zero-digit"); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5512 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("digit"); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5513 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("pattern-separator"); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5514 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collection"); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5515 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("datamodule"); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5516 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node-type"); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5517 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collection-modifier"); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5518 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node-modifier"); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5519 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("const"); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5520 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("append-only"); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5521 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("queue"); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5522 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mutable"); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5523 "/root/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("read-only"); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5535 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5541 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5558 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		}
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5562 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		}
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5566 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5570 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		}
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5580 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5583 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5586 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5589 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5598 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5601 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5610 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5613 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5622 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5625 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5634 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5637 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5646 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5649 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5652 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5661 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5664 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5673 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		}
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5677 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5687 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5690 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5693 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5696 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5699 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5708 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5717 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5721 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5725 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5729 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5733 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5737 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5741 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5751 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5754 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5757 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5760 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5769 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5772 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5775 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5778 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5787 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5790 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5799 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5802 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5805 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5808 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5811 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5814 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5817 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5826 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5829 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5838 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5841 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5844 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5847 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5856 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5859 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5862 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5865 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5868 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5877 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5880 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 5889 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 5892 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 5901 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 5904 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 5913 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 5916 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 5925 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 5934 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 5937 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 5946 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 5949 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 5952 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 5961 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 5964 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 5967 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 5970 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 5973 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 5982 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 5986 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 5990 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 5994 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6004 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6013 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6023 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6032 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6035 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6044 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6047 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6050 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6059 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6062 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6071 "/root/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;



/* Line 678 of lalr1.cc  */
#line 10152 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"
	default:
          break;
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
	/* If just tried and failed to reuse lookahead token after an
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

    /* Else will try to reuse lookahead token after shifting the error
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

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
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
    if (yychar != yyempty_)
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
  const short int xquery_parser::yypact_ninf_ = -1301;
  const short int
  xquery_parser::yypact_[] =
  {
      1428, -1301, -1301, -1301, -1301,   120,    18,   207,   203,  7866,
      73,   454,   461, -1301, -1301, -1301, -1301, -1301, -1301,   234,
      -4,  6764, -1301,   210, -1301, -1301, -1301, -1301,   288,   335,
   -1301,   278,   349,   417, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301, -1301,   380,   400, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301,  8139, -1301,  6206, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301,  9777, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301,   447, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301, -1301,  1710,  9777, -1301, -1301, -1301, -1301, -1301,
   -1301,   436, -1301, -1301, -1301, -1301,  7318, -1301,  7593, -1301,
   -1301, -1301, -1301, -1301,  9777, -1301, -1301,  5925, -1301, -1301,
   -1301, -1301, -1301, -1301,   448, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301, -1301,    15,   393, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301, -1301,   315,   473,   352, -1301,   422,   277, -1301,
   -1301, -1301, -1301, -1301, -1301,   534, -1301, -1301,   498,   430,
     432, -1301,   439,   515,   525, -1301,   579, -1301, -1301, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301, -1301,   552, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,  4239,
     705, -1301,  4520, -1301, -1301,   221, -1301,   221,  4801,   532,
     558, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301,   -39, -1301, -1301, -1301, -1301,   519,  9777, -1301, -1301,
   -1301, -1301, -1301,   553,   657, -1301,   652,   497,   303,   217,
     345,    -8, -1301,   675,   566,   665,   673,  5082, -1301, -1301,
   -1301,    88, -1301, -1301,  5925, -1301,    77, -1301,   628,  6206,
   -1301,   628,  6206, -1301, -1301, -1301, -1301,   628, -1301, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301,   631, -1301, -1301,  9777,
     750,   752,   467,   467,   750,  9777,   175,    64,   767,   256,
     304,  9777,   647,   680,   310,  7318,   488,    40,  9777,  9777,
   -1301, -1301,  7318,  9777,  4801,   649,   653,  4801, -1301, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,  4801,
    8412, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,   655,  4801,
    4801,   618,  4801,   624,  4801,    36,    43,    59, -1301,  4801,
    7041,   658, -1301,  9777,  9777,  9777,  4801,   533,   537, -1301,
     692,   694,  9777,    34,  4801,  8685,   664,   662,   663,   666,
     667,   668, -1301, -1301, -1301,  9777, -1301,   634,   783,  4801,
      42, -1301,   799,   640, -1301,  4801,   614, -1301,   797,  4801,
    4801,   643,  4801,  4801,  4801,  4801,   600,  9777, -1301, -1301,
    4801, -1301, -1301,  4801,  4801,  9777,  7318, -1301, -1301, -1301,
   -1301, -1301,   120,    -4, -1301, -1301, -1301,   221,   796,  4801,
   -1301,  4801,   669,   335,   349,   417,   713,   670,   671,  4801,
    4801, -1301, -1301, -1301, -1301, -1301, -1301, -1301,   725, -1301,
      -3,  5363,  5363,  5363, -1301,  5363,  5363, -1301,  5363, -1301,
    5363, -1301, -1301, -1301, -1301, -1301, -1301, -1301,  5363,  5363,
       8,  5363,  5363,  5363,  5363,  5363,  5363,  5363,  5363,  5363,
    5363,  5363,   605,   740,   742,   745, -1301, -1301, -1301,  1991,
   -1301, -1301,  5925,  5925,  4801,   628, -1301, -1301,   628, -1301,
     628,  2272,   687, -1301,  9777, -1301, -1301, -1301, -1301,   813,
   -1301, -1301, -1301, -1301, -1301, -1301,   735,   736, -1301, -1301,
     651,   282,  9777,   457,   688,   690,   651,   767,   719,   720,
   -1301, -1301, -1301,   388,    57,   395,   821, -1301, -1301,   338,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,   174,   559,
     729,   711, -1301,   682,  4801,  4801,   681,   683, -1301,    22,
      39,  2553,   685,   689, -1301,   691, -1301,   684,  7318,   772,
     832,  7318,   767,   776,  7318,   777,   695,   693, -1301,   696,
    2834,    12, -1301,   143,   734,   770, -1301,   -56,   698, -1301,
   -1301,  9777,   -20, -1301,   707,   662,   380, -1301,   709,   710,
     708, -1301,   132,   150,  3115,    17, -1301,  9777,   783, -1301,
     -14,   714, -1301, -1301, -1301, -1301,   715, -1301,    28, -1301,
   -1301, -1301,   -28,    33,   802,   672,   676,   -46, -1301,   757,
    5644, -1301,   716,   721,    70, -1301, -1301,   773,   717, -1301,
      32, -1301, -1301,   -34,   733,  9777,  4801,   784, -1301, -1301,
     787,  9231,   789,  4801,   790,   -86,   766,   -50,   657, -1301,
   -1301, -1301, -1301, -1301,  5363, -1301, -1301, -1301,  4801,     8,
     478, -1301,   636,   405,   656,   659, -1301, -1301,   646,   274,
     217,   217,   200,   345,   345,   345,   345,    -8,    -8, -1301,
   -1301,  9231,  9231,  9777,  9777, -1301,   737, -1301, -1301,   739,
   -1301, -1301, -1301,   171,    58,   302,   687, -1301,   301,   312,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
     651, -1301,   785,  9504,   778,  4801, -1301, -1301, -1301,   822,
     781,  4801,   767,   767,   651, -1301,   536,   767, -1301, -1301,
     644, -1301, -1301,   642,   270, -1301, -1301, -1301, -1301, -1301,
   -1301,   645, -1301, -1301,   109,   414,   392,   637, -1301,  4801,
     767,  4801, -1301,   746,   747,   828,   779,  9777, -1301,  9777,
   -1301, -1301,   751, -1301, -1301, -1301,   738,   800,   767,   780,
     803,   838,   767,   806,   767,   791, -1301, -1301, -1301,   760,
     824,  4801,  4801,   801,  4801,   825,  4801,   810,   -80, -1301,
     231,   699, -1301, -1301,   366,   -20, -1301, -1301, -1301,   804,
    9777, -1301,  9777, -1301, -1301,   775,  4801,   917, -1301,   204,
   -1301,   121, -1301, -1301,   928, -1301,   365,  4801,  4801,  4801,
     420,  4801,  4801,  4801,  4801,  4801,  4801,   839,  4801,  4801,
     680,   -27,   782,   498,   722,   808,   841,   767,   796,   881,
   -1301,  4801, -1301,   530,   856, -1301,  9777,   857, -1301,  9777,
     814,   815, -1301,   336, -1301, -1301, -1301,  9777, -1301,  9777,
    4801,   826,  4801,  4801,   -81,   827, -1301,   786,   792, -1301,
     718, -1301,   137, -1301,   347,   -47,   724,     8,   347,  5363,
    5363,   512, -1301, -1301, -1301, -1301, -1301, -1301, -1301,     8,
     830,   -47, -1301,   697,   914, -1301, -1301, -1301, -1301, -1301,
     834, -1301, -1301, -1301,  4801, -1301,  9777,   878,   176, -1301,
   -1301,  4801, -1301,   306, -1301, -1301, -1301, -1301, -1301,   952,
     492, -1301, -1301, -1301,  4801, -1301, -1301, -1301, -1301, -1301,
   -1301,   701,   -11,   954, -1301,    20, -1301, -1301,   663,   666,
     667,   400,   668,   473,   429, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301,   816,   798,   807, -1301, -1301,  8958,   403, -1301,
    3396,   805,   809,   842,   811,   817, -1301,  4801,   767,   879,
   -1301, -1301, -1301,   767,   879,   767,   879,  3677, -1301,  9777,
   -1301, -1301,  4801, -1301,  9777, -1301,  4801,  4801,   849,  4801,
     846, -1301,   873,   875,  4801,  9777,   623,   927, -1301, -1301,
   -1301,  3958,   818,   820, -1301, -1301, -1301,   867, -1301,   368,
   -1301, -1301,   984, -1301, -1301,  4801,  9777, -1301, -1301,   394,
   -1301, -1301, -1301,   819,   774,   788, -1301, -1301, -1301,   793,
     794, -1301, -1301, -1301, -1301, -1301,   771,  9777,   829, -1301,
     868, -1301,   680, -1301, -1301, -1301,  6487,   722, -1301,  4801,
    9777,   823,   856, -1301,   767, -1301,   596, -1301,   144,   901,
   -1301,  4801,   903,   784, -1301,   831,   836, -1301, -1301, -1301,
   -1301, -1301, -1301, -1301,  4801, -1301, -1301,  4801,   869,  4801,
   -1301, -1301,  5363, -1301, -1301, -1301, -1301, -1301,    46,  5363,
    5363,   241, -1301,   656, -1301, -1301,   343,  5363, -1301, -1301,
     659,     8,   744, -1301, -1301, -1301, -1301,   822,  9231,   894,
     921,   840, -1301, -1301, -1301, -1301, -1301,   -29,   993,   994,
     -29,    16,   179,   186,   637, -1301,   872, -1301, -1301,  9777,
     844,    53, -1301, -1301,   847, -1301, -1301, -1301, -1301, -1301,
     904,   933,   767,   879,   934, -1301,   851, -1301, -1301, -1301,
   -1301, -1301,  4801, -1301,  4801,  9777,  9777, -1301,    55, -1301,
    4801, -1301,   852, -1301, -1301,   917,  9777,   452, -1301,   853,
     917,  9777, -1301, -1301,  4801,  4801,  4801,  4801,  4801, -1301,
    4801,  4801, -1301, -1301,   194, -1301,   854, -1301, -1301, -1301,
   -1301, -1301,   901, -1301, -1301, -1301,   767, -1301, -1301, -1301,
   -1301, -1301, -1301,  4801, -1301,   345,  5363,  5363,   345,   361,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301,  9231, -1301,   -11,   -11,   -29, -1301, -1301, -1301,    25,
     -29,  1007,   795,   941, -1301,   941, -1301, -1301,  4801,   196,
     944,  4801,  9777,  4801, -1301,  4801,   767, -1301,   767, -1301,
   -1301, -1301,   972, -1301, -1301, -1301, -1301,   -10,   917,  9777,
   -1301,   848,   917, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
     922,  6487, -1301, -1301, -1301, -1301, -1301,   345,   345,  5363,
   -1301, -1301, -1301, -1301, -1301, -1301,   -47, -1301,   211, -1301,
     215, -1301,   604,  4801,    99,  9231, -1301,   860, -1301, -1301,
     879,   879,   925,   169,   280, -1301,   855,   917, -1301,   858,
    9777, -1301,   345,   812,   941, -1301, -1301, -1301,   530, -1301,
     445,   445,    13,   754, -1301, -1301, -1301, -1301, -1301,   862,
    4801,  9777, -1301, -1301,   956,   240, -1301, -1301, -1301, -1301,
     866,   297, -1301, -1301, -1301,   859, -1301,   216, -1301, -1301,
   -1301, -1301, -1301, -1301,    13,  4801, -1301, -1301, -1301, -1301,
   -1301, -1301, -1301, -1301, -1301,   932,   905, -1301, -1301,  9777,
   -1301,   222,   935,   905,  9777, -1301,   871,   905, -1301
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   401,   402,   583,   548,   686,   695,   674,   598,   590,
     606,   597,   588,   696,   735,   734,   736,   737,   733,   592,
     693,   594,   621,   656,   650,   691,   618,   694,   751,   645,
     687,   749,   635,   636,   637,   638,   639,   640,   641,   642,
     643,   688,   602,   596,   589,   690,   665,   595,   600,   758,
     759,   760,   761,   762,   763,   764,   765,   766,   767,   768,
     392,   395,   664,   660,   651,   631,   587,   382,     0,   659,
     667,   675,   380,   655,   418,   632,   633,   689,   381,   384,
     652,   669,     0,   424,   390,   420,   662,   586,   653,   654,
     682,   657,   673,   681,   386,   385,   605,   644,   684,   419,
     672,   677,   591,     0,     0,   339,   670,   680,   685,   683,
     663,   738,   649,   647,   648,   391,     0,   338,     0,   394,
     393,   678,   634,   658,     0,   383,   368,     0,   400,   679,
     661,   668,   676,   671,   739,   625,   630,   629,   628,   627,
     626,   599,   646,     0,   585,   692,   619,   725,   724,   726,
     604,   603,   622,   731,   593,   723,   728,   729,   720,   624,
     666,   722,   732,   730,   721,   623,   727,   740,   741,   742,
     745,   743,   746,   744,   747,   748,   750,   712,   711,   608,
     601,   610,   609,   705,   701,   616,   620,   617,   714,   715,
     698,   607,   710,   709,   706,   702,   719,   713,   708,   704,
     697,   718,   717,   703,   707,   699,   700,   611,   612,   614,
     716,   613,   615,   770,   769,   771,   772,   773,   774,   775,
     776,   777,   778,   753,   754,   752,   756,   757,   755,     0,
       0,     2,     0,     4,     6,    14,     8,    17,     0,     0,
       0,    23,    25,    38,    27,    28,    29,    54,    30,    34,
      35,    58,    59,    60,    55,    56,    62,    63,    32,    31,
      36,    37,    57,   198,   197,   194,   195,   196,    33,    13,
     175,   176,   180,   182,   213,   219,     0,     0,   211,   212,
     183,   184,   185,   186,   295,   297,   299,   309,   312,   314,
     317,   322,   325,   328,   330,   332,   334,     0,   336,   342,
     344,     0,   360,   343,   364,   367,   369,   372,   374,     0,
     379,   376,     0,   387,   397,   399,   373,   403,   408,   416,
     409,   410,   411,   414,   415,   412,   413,   431,   433,   434,
     435,   432,   480,   481,   482,   483,   484,   485,   396,   522,
     514,   521,   520,   519,   516,   518,   515,   517,   417,    61,
     187,   188,   190,   189,   191,   192,   398,   584,   193,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     158,   161,     0,     0,     0,     0,     0,     0,   686,   695,
     674,   598,   590,   606,   597,   588,   592,   693,   594,   656,
     751,   645,   749,   635,   636,   596,   589,   587,   657,     0,
       0,   738,   739,   585,   731,   593,   723,   729,   720,   623,
     741,   742,   745,   746,   744,   747,   750,   770,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   581,     0,
       0,     0,   582,     0,     0,     0,     0,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,   590,   597,   588,
     594,   587,   388,   398,   421,     0,   422,     0,   447,     0,
       0,   363,     0,     0,   366,     0,     0,   476,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,   145,
       0,   156,   157,     0,     0,     0,     0,     3,     1,     5,
       7,     9,     0,     0,    15,    18,    12,    20,    21,     0,
     178,   177,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   199,   218,   214,   220,   215,   217,   216,   223,   224,
       0,     0,     0,     0,   353,     0,     0,   351,     0,   304,
       0,   352,   345,   350,   349,   348,   347,   346,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   341,   340,   337,     0,
     361,   365,     0,     0,     0,   375,   405,   378,   377,   389,
     404,     0,     0,   163,     0,   164,   160,   159,   162,     0,
     139,   140,    71,    72,   580,    80,     0,     0,    65,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     549,   550,   551,     0,     0,     0,     0,   817,   818,     0,
      70,   810,   811,   812,   813,   814,   815,   816,   109,     0,
       0,     0,   546,     0,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,   527,     0,   528,     0,     0,    89,
       0,     0,     0,    81,     0,    93,     0,     0,   529,     0,
       0,     0,   284,     0,     0,   236,   237,     0,     0,   201,
     202,     0,     0,   222,     0,     0,     0,   524,     0,     0,
       0,   532,     0,     0,     0,     0,   423,   448,   447,   444,
       0,     0,   478,   477,   362,   537,     0,   475,     0,   562,
     563,   523,     0,     0,     0,     0,     0,     0,   568,     0,
       0,   154,     0,     0,     0,   239,   256,     0,     0,    24,
       0,    26,   181,     0,     0,     0,     0,     0,   200,   257,
       0,     0,     0,     0,     0,     0,     0,     0,   296,   298,
     302,   308,   307,   306,     0,   303,   300,   301,     0,     0,
       0,   802,   310,   781,   789,   791,   793,   795,   797,   800,
     316,   315,   313,   319,   320,   321,   318,   323,   324,   327,
     326,     0,     0,     0,     0,   358,     0,   370,   371,     0,
     406,   427,   429,     0,     0,     0,     0,    69,     0,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      40,    41,     0,     0,   101,     0,    97,    99,   100,   104,
     107,     0,     0,     0,    39,    79,     0,     0,   819,   820,
       0,   821,   825,     0,     0,   854,   823,   824,   853,   822,
     826,     0,   833,   855,     0,     0,     0,   111,   113,     0,
       0,     0,   354,     0,     0,     0,     0,     0,   542,     0,
     539,   487,     0,   486,   495,   496,     0,     0,     0,     0,
       0,    82,     0,     0,     0,     0,   531,   530,   497,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   780,
       0,     0,   203,   204,     0,   209,   545,   525,   526,     0,
       0,   535,     0,   533,   491,     0,     0,   447,   445,     0,
     436,     0,   425,   426,     0,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     686,     0,     0,     0,     0,     0,     0,     0,    22,     0,
     179,     0,   210,   268,   264,   266,     0,   258,   259,     0,
     591,   599,   503,   504,   510,   511,   513,     0,   226,     0,
       0,     0,     0,     0,     0,     0,   305,     0,     0,   796,
       0,   311,     0,   809,     0,     0,     0,     0,     0,     0,
       0,   782,   786,   804,   785,   808,   806,   805,   807,     0,
       0,     0,   798,   861,   859,   863,   801,   329,   331,   333,
     501,   335,   359,   407,     0,   428,     0,   141,     0,   169,
     166,     0,   165,     0,    77,    78,    75,    76,    42,     0,
       0,   102,   103,   105,     0,   106,    67,    68,    73,    74,
      64,     0,     0,     0,   828,     0,   827,   844,     0,     0,
       0,     0,     0,     0,   110,   117,   118,   119,   120,   122,
     121,   115,     0,     0,     0,   356,   355,     0,     0,   290,
       0,     0,     0,   546,     0,     0,   488,     0,     0,    91,
      85,    88,    87,     0,    83,     0,    95,     0,   498,     0,
     282,   286,     0,   153,     0,   241,     0,     0,     0,     0,
       0,   205,     0,     0,     0,     0,   250,     0,   247,   252,
     208,     0,     0,     0,   492,   283,   448,     0,   437,     0,
     471,   468,     0,   472,   473,     0,     0,   474,   467,     0,
     442,   470,   469,     0,     0,     0,   555,   556,   552,     0,
       0,   560,   561,   557,   566,   564,     0,     0,     0,   570,
     151,   150,     0,   147,   146,   155,     0,   571,   572,     0,
       0,     0,   265,   277,     0,   278,     0,   269,   270,   271,
     272,     0,   261,     0,   225,     0,     0,   507,   509,   508,
     505,   234,   235,   228,     0,   230,   227,     0,     0,     0,
     803,   799,     0,   856,   857,   877,   876,   872,     0,     0,
       0,     0,   858,   790,   871,   783,     0,     0,   788,   787,
     792,     0,     0,   862,   860,   502,   430,   171,     0,     0,
     142,     0,   168,   167,    43,    98,   108,   842,     0,     0,
     840,   836,     0,     0,   112,   114,     0,    16,   357,     0,
       0,     0,   291,   489,     0,   543,   544,   547,   540,   541,
       0,    90,     0,    84,    94,   499,     0,   285,   287,   238,
     243,   242,     0,   245,     0,     0,     0,   207,   248,   251,
       0,   493,     0,   536,   534,   447,     0,     0,   479,     0,
     447,     0,   443,    11,     0,     0,     0,     0,     0,   569,
       0,     0,   149,   578,     0,   573,     0,   240,    19,   281,
     279,   280,   273,   274,   275,   267,     0,   262,   260,   512,
     506,   232,   229,     0,   231,   878,     0,     0,   864,     0,
     875,   874,   873,   868,   869,   784,   794,   870,   172,   143,
     170,     0,   174,     0,     0,   843,   845,   847,   849,     0,
     841,     0,     0,     0,   831,     0,   829,   116,     0,     0,
       0,     0,     0,     0,   490,     0,     0,    86,     0,   500,
     244,   246,   255,   254,   249,   206,   494,     0,   447,     0,
     173,     0,   447,   553,   554,   558,   559,   565,   567,   152,
       0,     0,   574,   779,   276,   263,   233,   866,   865,     0,
     144,   852,   851,   846,   850,   848,   837,   838,     0,   834,
       0,   133,   135,     0,   130,     0,   292,     0,   288,   294,
      92,    96,     0,   457,   451,   446,     0,   447,   438,     0,
       0,   579,   867,     0,     0,   832,   830,   136,   137,   134,
     130,   130,   130,     0,   131,   132,   123,   124,   127,     0,
       0,     0,   465,   459,     0,   458,   460,   466,   463,   453,
       0,   452,   454,   464,   440,     0,   439,     0,   839,   835,
     138,   128,   129,   125,   130,     0,   289,   253,   450,   461,
     462,   449,   455,   456,   441,     0,     0,   126,   293,     0,
     575,     0,     0,     0,     0,   576,     0,     0,   577
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1301, -1301,   833, -1301,   837,   843, -1301,   845, -1301,   469,
   -1301,   541,   542,  -491, -1301,   446,  -272, -1301, -1301, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301,  -844, -1301, -1301, -1301, -1301,    41,   250,   686, -1301,
   -1301,    21,  -814, -1301, -1301, -1300,  -693, -1301,  -327, -1301,
     271, -1301,  -839, -1301, -1301,   -74, -1301, -1301, -1301, -1301,
   -1301,   373,  -240, -1301, -1301,  -138, -1301, -1228,   835,   -97,
   -1301,   555,  -392, -1301, -1301, -1301, -1301,   178, -1301, -1301,
     850, -1301, -1301, -1301, -1301, -1301,   125,  -499,  -641, -1301,
   -1301, -1301,    -6, -1301, -1301,  -178,   -15,   -68, -1301, -1301,
   -1301,   -79, -1301, -1301,   147,   -72, -1282, -1301,   -67, -1087,
   -1301,   615,    14, -1301, -1301,    37, -1301, -1301,   551,   554,
   -1301,  -501,  -942,   531,   188,  -547,   187,   191, -1301, -1301,
   -1301, -1301, -1301,   861, -1301, -1301, -1301, -1301, -1301,   863,
   -1301, -1301,  -108, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
     -35, -1111, -1301, -1301,   130,   108, -1301,  -539, -1301, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301, -1301,  -877, -1301,   -12,
   -1301,   401,  -684, -1301, -1301, -1301, -1301, -1301,  -343,  -335,
   -1058,  -840, -1301, -1301, -1301, -1301, -1301, -1301, -1301, -1301,
   -1301, -1301,   317,  -662,  -756, -1301,   289,   -13,  -729, -1301,
   -1301, -1301, -1301, -1301, -1301, -1301,   641,   648,  -417,   244,
      86, -1301, -1301, -1301, -1301, -1301, -1301, -1301,   -31, -1301,
   -1301,   -38, -1301,  -355,  -102,    -9, -1301, -1301,   351, -1301,
   -1301,   131,   123,   -88,   354, -1301, -1301,   134, -1301,  -724,
   -1301, -1301, -1301, -1301,  -219,  -821, -1301,  -103,  -544, -1301,
    -694, -1301, -1301, -1301, -1301,  -960, -1301, -1301, -1301, -1301,
     -78,   141, -1301
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   800,   801,   802,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,  1059,   652,   257,   258,   806,   807,   808,  1130,   259,
     260,   837,   838,   261,  1416,  1417,  1418,  1329,  1381,   262,
     785,   263,   489,   710,   921,  1131,   264,   265,   266,   267,
     268,   380,   381,   585,   998,   999,  1107,  1002,   269,   270,
     511,   271,   272,   273,   521,   450,   884,   885,   274,   522,
     275,   524,   276,   277,   278,   528,   529,  1086,   736,   279,
     665,   714,   666,   672,  1087,  1088,  1089,   715,   525,   526,
     937,   938,  1287,   527,   934,   935,  1147,  1148,  1149,  1150,
     280,   661,   662,   281,  1048,  1049,   282,   283,   284,   285,
     744,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   548,   549,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   575,   576,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   783,   326,   327,   328,  1109,
     688,   689,   690,  1395,  1430,  1431,  1424,  1425,  1432,  1426,
    1110,  1111,   329,   330,  1112,   331,   332,   333,   334,   335,
     336,   337,   989,   737,   942,  1160,   943,   944,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   631,  1052,
     348,   349,   350,   351,   352,   353,   354,   707,   708,   355,
    1137,  1138,  1274,  1060,   441,   356,   357,   358,   752,   971,
     753,   754,   755,   756,   757,   758,   759,   972,   973,   620,
     621,   622,   623,   624,  1378,  1379,   625,  1315,  1210,  1319,
    1316,   626,   627,   975,   986,  1181,   976,   977,   982,   978,
    1303,  1177,   961
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       428,   873,   945,  1026,   899,   878,   467,   763,   764,   765,
     766,   751,   442,   595,   470,   987,   988,   721,  1064,   474,
    1066,  1192,   435,  1041,  1108,  1273,   877,  1185,     4,   974,
     731,   735,   740,   462,   741,   742,   476,   743,   732,   745,
     881,  1178,   945,   945,   436,  1374,  1362,   746,   747,   692,
     950,  1262,  1077,   917,   668,  1167,   594,   456,   906,   463,
     509,  1283,  1284,   594,   675,   509,   359,   360,   361,   362,
     363,   364,  1132,   464,   945,  1393,   876,  1208,   365,   594,
     649,   653,   655,   731,  1135,   732,   953,   699,   700,  1296,
     702,   703,   704,   705,   951,   468,   955,  1313,   711,   676,
    1407,   712,   713,   371,  1178,  1034,   900,   442,  1023,   472,
      74,   870,  1443,  1082,  1083,   473,   870,   722,   560,   910,
     583,   847,    85,   925,   588,  1212,  1440,   728,   729,  1100,
    1101,   561,   613,   733,  1209,   372,   373,   929,   849,   675,
     510,  1028,  1029,   732,  1457,   930,    99,  1013,   650,   904,
     748,  1030,  1133,   749,   359,   360,   361,   362,   363,   364,
    1314,  1394,   820,  1332,  1203,  1297,   365,   382,   996,   926,
    1410,   901,   366,  1422,   676,  1031,   734,  1100,   918,   907,
     908,   734,   734,   367,   368,   648,   882,   369,   871,   782,
     370,   371,   651,   896,   909,  1364,   571,   848,  1032,  1262,
    1375,  1179,  1180,  1411,  1213,   693,   734,   905,   654,   677,
     751,   751,   734,  1097,   850,   429,  1102,   477,  1080,  1233,
    1215,   592,  1108,   372,   373,   374,   883,  1333,  1460,   731,
     569,   890,  1108,   997,  1103,  1465,  1104,  1078,   954,  1468,
     911,   912,  1144,   956,  1422,  1305,   502,  1189,  1100,   892,
    1401,  1322,   815,   118,   593,   913,  1410,   572,   573,   734,
     750,  1146,   503,  1105,  1179,  1180,   614,   104,   530,   375,
     994,   437,   377,   609,   577,  1199,  1321,   579,  1323,   872,
     630,   615,  1103,   116,  1104,  1325,   124,   633,  1100,  1411,
     636,  1220,  1423,   383,   616,  1383,   617,   861,   821,  1428,
     463,  1414,  1415,   463,  1106,  1100,   618,   891,   378,   619,
    1404,  1105,   637,  1168,  1404,  1455,  1428,   731,   945,   379,
     443,  1462,   143,  1033,  1098,   893,   554,   822,   823,   376,
     824,   825,   642,   643,   933,   645,  1001,   647,   659,  1360,
     604,   948,   656,  1173,   605,   590,   995,   551,   387,   384,
     582,  1200,   555,  1103,  1324,  1104,   589,   680,  1023,   591,
     377,  1326,   600,  1449,   552,   556,   442,  1079,   803,   628,
     629,  1384,   691,   442,   632,  1024,  1100,  1101,   696,   434,
    1108,   606,  1105,  1174,  1412,  1413,  1405,  1414,  1415,  1099,
    1406,  1456,  1361,  1103,   717,  1104,   378,  1463,   444,   557,
    1327,   640,  1100,  1101,  1429,   447,   448,   379,   607,   804,
    1103,   596,  1104,  1012,   805,  1025,  1403,   385,   386,  1015,
     446,  1452,  1105,  1186,  1082,  1083,   597,  1084,   751,  1000,
    1051,   442,  1054,  1202,   663,   664,   667,   721,  1004,  1105,
     751,   578,  1309,   674,  1001,   445,   683,   580,   488,  1006,
     551,   834,   835,   836,   732,  1005,   663,  1016,  1017,   449,
    1100,  1101,  1020,  1102,   777,   778,  1007,   552,   608,   945,
    1157,   451,   776,  1092,   598,  1093,  1085,   779,   709,  1070,
    1071,  1103,  1073,  1104,  1075,  1043,   716,   442,   599,  1102,
     553,   485,  1390,   962,  1391,  1047,   486,   613,     4,  1300,
    1158,   359,   360,   361,  1095,  1301,   364,  1103,  1221,  1104,
    1105,   983,   984,  1302,   104,  1116,  1117,  1118,  1159,  1121,
    1122,  1123,  1124,  1125,  1126,   452,  1128,  1129,  1008,   479,
     116,   480,   558,   985,   558,  1308,  1105,   843,   844,   933,
     104,   559,  1008,   559,   852,   453,   857,  1102,  1369,   860,
     558,  1256,   863,  1427,  1433,  1370,   116,   465,  1163,   559,
    1165,  1166,   963,   869,   512,  1103,   482,  1104,   483,   143,
     513,  1347,  1141,   514,   515,   786,  1351,  1261,   469,   829,
      74,   516,   945,  1439,   810,  1427,  1114,   895,  1115,   811,
     475,  1433,    85,   809,  1105,   143,   430,   478,   104,   431,
     962,  1300,  1196,   432,   613,  1175,   433,  1301,   830,   831,
    1176,   832,   833,   922,   116,  1302,    99,  1143,   481,   804,
     748,  1373,  1206,   749,   805,  1295,  1373,   818,  1144,  1419,
     819,   614,  1298,  1299,   826,  1349,   484,   827,  1145,   442,
     488,  1119,   442,  1120,   487,   442,   615,  1146,   964,   965,
     966,   957,   751,   143,  1018,  1019,   945,   490,   967,   616,
     493,   617,   880,   491,  1396,  1230,   968,   494,  1399,   963,
     492,   618,   969,   970,   619,  1039,  1040,   517,   897,   518,
    1238,  1082,  1083,   780,  1240,  1241,   780,  1243,   780,   495,
     731,  1143,  1247,   519,  1035,  1036,  1037,  1038,   610,   611,
     612,   496,  1144,  1231,   504,   498,   505,   835,   836,   531,
    1234,   507,  1145,  1435,  1280,  1281,   932,  1441,  1442,   520,
    1408,  1146,   946,   790,   791,   792,   793,   794,   795,   796,
     797,   798,   799,  1414,  1415,   586,   587,   508,   614,   760,
     761,   532,  1042,   562,  1044,   767,   768,  1276,   550,  1367,
    1368,   769,   770,   615,   563,   964,   965,   966,   564,   933,
     990,   990,   946,   946,   946,   946,   616,   565,   617,  1371,
    1372,   574,  1291,   968,   533,  1292,   581,  1294,   618,  1187,
     970,   619,   534,   535,   359,   536,   584,   594,   601,  1279,
     602,   634,   537,   644,   946,   635,   538,   641,   539,   646,
     660,   669,   671,   540,   673,   670,   684,   410,   431,   686,
     687,   433,   440,   455,   694,   695,   697,   698,   701,   541,
     706,   720,  1402,   725,   730,   771,   772,   724,   773,   726,
     727,   774,   784,   787,   788,   789,   816,   812,  1053,   813,
    1053,   828,   817,   542,   543,   544,   545,   546,   547,   839,
    1340,   840,  1341,   841,   842,   846,   845,   853,  1345,   856,
     858,   854,   859,   855,   862,   864,   874,   865,   866,   875,
     879,   867,  1353,  1354,  1355,  1356,  1357,  1337,  1358,  1359,
     889,   632,   886,   632,   887,   888,   902,   903,   914,   919,
     916,   923,   931,   924,   936,   927,   928,   939,   915,   947,
     949,  1366,   952,   981,  1201,   960,   979,  1009,   731,   992,
     805,   980,   993,  1014,  1022,  1021,   836,  1027,  1045,  1046,
    1047,  1050,  1058,  1056,  1057,  1062,  1063,  1152,  1065,  1061,
     530,  1365,  1068,  1067,  1069,  1074,  1382,  1072,  1161,  1386,
    1162,  1388,  1076,  1389,  1096,  1081,  1091,  1094,  1113,  1127,
    1139,  1140,   606,  1224,  1134,  1151,  1153,  1136,  1170,  1155,
    1156,  1194,  1164,  1169,  1198,  1172,  1191,  1171,  1195,  1193,
    1236,  1182,     4,  1207,  1211,  1216,  1227,  1217,  1232,  1218,
    1225,  1242,  1244,  1245,  1226,  1246,  1228,  1197,  1250,  1255,
    1258,  1382,  1229,  1253,  1252,  1254,  1264,  1268,  1263,  1144,
    1271,  1286,  1278,  1270,   996,  1293,  1289,  1311,  1259,  1307,
    1265,  1290,  1312,  1317,  1318,  1266,  1267,  1328,  1331,  1334,
    1335,  1336,  1338,  1339,  1346,  1350,  1363,  1376,  1446,  1023,
    1385,  1392,  1400,  1398,  1420,  1421,  1445,  1451,   946,  1444,
    1434,  1448,  1459,  1436,  1454,  1464,  1467,  1001,   718,   719,
    1377,  1205,   814,  1458,  1011,  1214,  1409,  1003,  1272,   603,
     663,  1310,   497,  1090,  1154,   667,   723,  1438,  1239,   499,
    1344,  1249,  1277,   506,  1288,   500,  1248,   501,  1142,  1285,
     685,  1282,   738,  1237,   762,  1222,   739,  1257,  1453,   898,
    1450,   991,  1010,  1055,   678,  1204,  1269,  1260,  1183,  1275,
     958,   679,  1190,  1306,   959,  1188,  1380,  1320,  1304,  1184,
       0,     0,     0,     0,     0,     0,     0,     0,   709,     0,
       0,     0,     0,     0,     0,     0,   523,   463,     0,     0,
       0,   716,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   568,     0,
       0,     0,     0,     0,   570,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   946,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1330,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1342,  1343,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1348,     0,     0,
       0,     0,  1352,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   946,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1387,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1397,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   463,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   946,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1437,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1447,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
    1461,     0,     0,     5,     6,  1466,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,    72,    73,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,   103,   104,   105,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,   117,   118,     0,     0,   119,   120,   121,     0,
       0,     0,   122,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   144,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   388,   389,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   397,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,    72,    73,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,    85,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,   105,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,   117,   118,     0,     0,   119,   120,
     121,     0,     0,     0,   122,   466,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   413,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   427,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   388,   389,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   397,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,    72,    73,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,    85,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,   103,   104,   105,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,   117,   118,     0,     0,   119,
     120,   121,     0,   775,     0,   122,     0,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   413,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   427,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   388,   389,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   397,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,   103,   104,   105,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,   117,   118,     0,     0,
     119,   120,   121,     0,     0,     0,   122,   781,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   413,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   427,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   388,   389,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   397,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
     105,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,   117,   118,     0,
       0,   119,   120,   121,     0,   851,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   413,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   427,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   388,
     389,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   397,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,    72,    73,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,   868,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   413,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   427,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     388,   389,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,   397,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,     0,    72,    73,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,    85,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
     103,   104,   105,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,   117,
     118,     0,     0,   119,   120,   121,     0,   894,     0,   122,
       0,   123,   124,   125,     0,   126,   127,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   413,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     427,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   388,   389,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   397,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,   103,   104,   105,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     0,
     117,   118,     0,     0,   119,   120,   121,     0,  1223,     0,
     122,     0,   123,   124,   125,     0,   126,   127,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   413,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   427,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,   388,   389,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,   397,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,     0,    72,    73,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,    85,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,  1235,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     413,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   427,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   388,   389,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   397,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,    72,    73,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,   103,   104,   105,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,   117,   118,     0,     0,   119,   120,   121,     0,
    1251,     0,   122,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   413,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   427,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     5,     6,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,     0,    72,    73,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,    85,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,   103,   104,   105,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,   117,   118,     0,     0,   119,   120,   121,
       0,     0,     0,   122,     0,   123,   124,   125,     0,   126,
     127,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   144,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,     5,     6,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,    72,    73,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,    85,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,   105,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,   117,   118,     0,     0,   119,   120,
     121,     0,     0,     0,   122,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   413,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   388,   389,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   397,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,    72,    73,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,    85,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,   103,   104,   105,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,   117,   118,     0,     0,   119,
     120,   121,     0,     0,     0,   122,     0,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   413,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   427,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   388,   389,     0,
       7,   391,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,   396,   397,    21,    22,   399,    24,    25,    26,
      27,     0,   400,   401,    30,   402,   403,   404,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   408,    92,    93,
      94,    95,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,   103,   104,   566,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,   567,   118,     0,     0,
     119,   120,   121,     0,     0,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   413,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   414,   154,   416,   156,   417,
     418,   159,   160,   161,   162,   163,   164,   419,   166,   167,
     420,   421,   422,   171,   423,   424,   425,   175,   426,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   427,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   388,   389,
       0,     7,   391,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,   396,   397,    21,    22,   399,    24,    25,
      26,    27,     0,   400,   401,    30,   402,   403,   404,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   408,    92,
      93,    94,    95,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
     105,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,   117,   118,     0,
       0,   119,   120,   121,     0,     0,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   413,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   414,   154,   416,   156,
     417,   418,   159,   160,   161,   162,   163,   164,   419,   166,
     167,   420,   421,   422,   171,   423,   424,   425,   175,   426,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   427,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   920,
     389,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   397,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,    72,    73,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   413,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   427,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     388,   389,     0,   390,   391,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,   396,   397,    21,    22,   399,
      24,    25,    26,    27,     0,   400,   401,    30,   402,   403,
     404,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,     0,    72,    73,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,    85,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     408,    92,    93,    94,    95,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
     103,   104,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,     0,   119,   120,   121,     0,     0,     0,   122,
       0,   123,   124,   125,     0,     0,     0,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   413,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   414,   154,
     416,   156,   417,   418,   159,   160,   161,   162,   163,   164,
     419,   166,   167,   420,   421,   422,   171,   423,   424,   425,
     175,   426,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     427,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     0,     0,     0,     0,
       0,   388,   389,     0,   390,   391,   457,   393,   458,   459,
      13,    14,    15,    16,    17,    18,   396,   397,   460,    22,
     399,    24,    25,    26,    27,     0,   400,   401,    30,   402,
     403,   404,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   461,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   408,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   411,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,   124,     0,     0,     0,     0,   128,     0,
     129,     0,   130,   131,   132,   133,   412,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   413,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   414,
     154,   416,   156,   417,   418,   159,   160,   161,   162,   163,
     164,   419,   166,   167,   420,   421,   422,   171,   423,   424,
     425,   175,   426,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   427,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     0,     0,     0,
       0,     0,   388,   389,     0,   390,   391,   392,   393,   394,
     395,    13,    14,    15,    16,    17,    18,   396,   397,   398,
      22,   399,    24,    25,    26,    27,     0,   400,   401,    30,
     402,   403,   404,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   405,   406,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   407,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   408,    92,    93,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   411,   112,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,     0,     0,     0,     0,     0,   128,
       0,   129,     0,   130,   131,   132,   133,   412,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     413,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     414,   415,   416,   156,   417,   418,   159,   160,   161,   162,
     163,   164,   419,   166,   167,   420,   421,   422,   171,   423,
     424,   425,   175,   426,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   427,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   438,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,   388,
     389,     0,   390,   391,   392,   393,   394,   395,    13,    14,
      15,    16,    17,    18,   396,   397,   398,    22,   399,    24,
      25,    26,    27,     0,   400,   401,    30,   402,   403,   404,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   405,
     406,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   407,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   408,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,   439,     0,     0,   440,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   411,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,     0,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   412,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   413,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   414,   415,   416,
     156,   417,   418,   159,   160,   161,   162,   163,   164,   419,
     166,   167,   420,   421,   422,   171,   423,   424,   425,   175,
     426,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   427,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   438,     0,     0,     0,     3,
       0,   657,     0,     0,     0,     0,   388,   389,     0,   390,
     391,   392,   393,   394,   395,    13,    14,    15,    16,    17,
      18,   396,   397,   398,    22,   399,    24,    25,    26,    27,
       0,   400,   401,    30,   402,   403,   404,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   405,   406,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     407,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   408,    92,    93,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   411,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,   658,   123,     0,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   412,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   413,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   414,   415,   416,   156,   417,   418,
     159,   160,   161,   162,   163,   164,   419,   166,   167,   420,
     421,   422,   171,   423,   424,   425,   175,   426,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   427,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   438,     0,     0,     0,     3,     0,     0,     0,
       0,     0,     0,   388,   389,     0,   390,   391,   392,   393,
     394,   395,    13,    14,    15,    16,    17,    18,   396,   397,
     398,    22,   399,    24,    25,    26,    27,     0,   400,   401,
      30,   402,   403,   404,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   405,   406,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   407,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   408,    92,    93,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,     0,   100,   101,   102,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   411,   112,   113,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,   122,     0,   123,     0,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   412,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   413,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   414,   415,   416,   156,   417,   418,   159,   160,   161,
     162,   163,   164,   419,   166,   167,   420,   421,   422,   171,
     423,   424,   425,   175,   426,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   427,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   471,
       0,     3,     0,     0,     0,     0,     0,     0,   388,   389,
       0,   390,   391,   392,   393,   394,   395,    13,    14,    15,
      16,    17,    18,   396,   397,   398,    22,   399,    24,    25,
      26,    27,     0,   400,   401,    30,   402,   403,   404,    34,
      35,    36,    37,    38,    39,    40,    41,    42,   405,   406,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   407,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   408,    92,
      93,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     411,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,     0,   123,
       0,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   412,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   413,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   414,   415,   416,   156,
     417,   418,   159,   160,   161,   162,   163,   164,   419,   166,
     167,   420,   421,   422,   171,   423,   424,   425,   175,   426,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   427,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,     3,     0,     0,     0,     0,     0,
       0,   388,   389,     0,   390,   391,   392,   393,   394,   395,
      13,    14,    15,    16,    17,    18,   396,   397,   398,    22,
     399,    24,    25,    26,    27,     0,   400,   401,    30,   402,
     403,   404,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   405,   406,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   407,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   408,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,   409,     0,
       0,   410,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   411,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   412,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   413,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   414,
     415,   416,   156,   417,   418,   159,   160,   161,   162,   163,
     164,   419,   166,   167,   420,   421,   422,   171,   423,   424,
     425,   175,   426,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   427,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,     3,     0,     0,
       0,     0,     0,     0,   388,   389,     0,   390,   391,   392,
     393,   394,   395,    13,    14,    15,    16,    17,    18,   396,
     397,   398,    22,   399,    24,    25,    26,    27,     0,   400,
     401,    30,   402,   403,   404,    34,    35,    36,    37,    38,
      39,    40,    41,    42,   405,   406,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    62,     0,    63,    64,    65,   407,     0,
       0,    69,    70,    71,     0,     0,     0,    73,     0,     0,
       0,     0,    75,    76,    77,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,   408,    92,    93,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,   454,     0,     0,   455,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   411,   112,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,   123,     0,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   412,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   413,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   414,   415,   416,   156,   417,   418,   159,   160,
     161,   162,   163,   164,   419,   166,   167,   420,   421,   422,
     171,   423,   424,   425,   175,   426,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   427,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
       3,     0,     0,     0,     0,     0,     0,   388,   389,     0,
     390,   391,   392,   393,   394,   395,    13,    14,    15,    16,
      17,    18,   396,   397,   398,    22,   399,    24,    25,    26,
      27,     0,   400,   401,    30,   402,   403,   404,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   405,   406,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   407,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   408,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   411,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,   638,   123,     0,
       0,     0,     0,     0,   639,     0,   129,     0,   130,   131,
     132,   133,   412,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   413,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   414,   415,   416,   156,   417,
     418,   159,   160,   161,   162,   163,   164,   419,   166,   167,
     420,   421,   422,   171,   423,   424,   425,   175,   426,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   427,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,     3,     0,     0,     0,     0,     0,     0,
     388,   389,     0,   390,   391,   392,   393,   394,   395,    13,
      14,    15,    16,    17,    18,   396,   397,   398,    22,   399,
      24,    25,    26,    27,     0,   400,   401,    30,   402,   403,
     404,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     405,   406,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    62,
       0,    63,    64,    65,   407,     0,     0,    69,    70,    71,
       0,     0,     0,    73,     0,     0,     0,     0,    75,    76,
      77,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     408,    92,    93,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   411,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
     681,   123,     0,     0,     0,     0,     0,   682,     0,   129,
       0,   130,   131,   132,   133,   412,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   413,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   414,   415,
     416,   156,   417,   418,   159,   160,   161,   162,   163,   164,
     419,   166,   167,   420,   421,   422,   171,   423,   424,   425,
     175,   426,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     427,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,     3,     0,     0,     0,
       0,     0,     0,   388,   389,     0,   390,   391,   457,   393,
     458,   459,    13,    14,    15,    16,    17,    18,   396,   397,
     460,    22,   399,    24,    25,    26,    27,     0,   400,   401,
      30,   402,   403,   404,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   461,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,  1219,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   408,    92,    93,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,     0,   100,   101,   940,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   411,   112,   113,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,   122,     0,   123,   124,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   412,   135,
     136,   137,   138,   139,   140,     0,     0,   941,   142,     0,
       0,   413,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   414,   154,   416,   156,   417,   418,   159,   160,   161,
     162,   163,   164,   419,   166,   167,   420,   421,   422,   171,
     423,   424,   425,   175,   426,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   427,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,     3,
       0,     0,     0,     0,     0,     0,   388,   389,     0,   390,
     391,   457,   393,   458,   459,    13,    14,    15,    16,    17,
      18,   396,   397,   460,    22,   399,    24,    25,    26,    27,
       0,   400,   401,    30,   402,   403,   404,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     461,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   408,    92,    93,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   940,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   411,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,   123,   124,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   412,   135,   136,   137,   138,   139,   140,     0,     0,
     941,   142,     0,     0,   413,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   414,   154,   416,   156,   417,   418,
     159,   160,   161,   162,   163,   164,   419,   166,   167,   420,
     421,   422,   171,   423,   424,   425,   175,   426,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   427,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,     3,     0,     0,     0,     0,     0,     0,   388,
     389,     0,   390,   391,   457,   393,   458,   459,    13,    14,
      15,    16,    17,    18,   396,   397,   460,    22,   399,    24,
      25,    26,    27,     0,   400,   401,    30,   402,   403,   404,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   461,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   408,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   940,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   411,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,   124,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   412,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   413,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   414,   154,   416,
     156,   417,   418,   159,   160,   161,   162,   163,   164,   419,
     166,   167,   420,   421,   422,   171,   423,   424,   425,   175,
     426,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   427,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,     3,     0,     0,     0,     0,
       0,     0,   388,   389,     0,   390,   391,   392,   393,   394,
     395,    13,    14,    15,    16,    17,    18,   396,   397,   398,
      22,   399,    24,    25,    26,    27,     0,   400,   401,    30,
     402,   403,   404,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   405,   406,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   407,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   408,    92,    93,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   411,   112,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,     0,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   412,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     413,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     414,   415,   416,   156,   417,   418,   159,   160,   161,   162,
     163,   164,   419,   166,   167,   420,   421,   422,   171,   423,
     424,   425,   175,   426,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   427,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         9,   663,   731,   824,   688,   667,   103,   554,   555,   556,
     557,   550,    21,   368,   116,   771,   772,   508,   862,   127,
     864,   981,    26,   837,   901,  1136,   667,   969,    20,   753,
      86,   530,   533,    68,   535,   536,    21,   538,    88,   540,
      60,    88,   771,   772,    48,    20,  1274,   548,   549,     7,
     136,  1109,   132,    99,   446,   136,    20,    66,    86,    68,
      99,  1148,  1149,    20,    30,    99,    34,    35,    36,    37,
      38,    39,    99,    82,   803,    85,   132,    88,    46,    20,
     435,   436,   437,    86,   923,    88,   136,   479,   480,    43,
     482,   483,   484,   485,   735,   104,   737,   126,   490,    65,
    1382,   493,   494,    71,    88,   834,   120,   116,    88,   118,
     102,    99,  1412,    58,    59,   124,    99,   509,   126,    86,
     360,    99,   114,    53,   364,   105,  1408,   519,   520,     8,
       9,   139,    92,   136,   145,   103,   104,   105,    99,    30,
     179,    32,    33,    88,  1444,   179,   138,   809,   105,   121,
     142,    42,   179,   145,    34,    35,    36,    37,    38,    39,
     189,   171,   105,   110,  1003,   119,    46,   149,   110,    99,
     157,   185,    52,     4,    65,    66,   262,     8,   224,   207,
     208,   262,   262,    63,    64,   149,   206,    67,   176,   581,
      70,    71,   149,   176,   222,  1282,   304,   175,    89,  1257,
     175,   248,   249,   190,  1025,   163,   262,   179,   149,   175,
     749,   750,   262,   897,   175,   142,    95,   202,   880,  1063,
    1034,   157,  1099,   103,   104,   105,   246,   174,  1456,    86,
     142,    99,  1109,   175,   113,  1463,   115,   878,   737,  1467,
     207,   208,    98,   744,     4,  1187,    25,   971,     8,    99,
    1361,  1211,   607,   165,   190,   222,   157,   180,   181,   262,
     252,   117,    41,   142,   248,   249,   226,   146,   277,   149,
      99,   275,   240,   375,   309,    99,   260,   312,    99,   136,
     382,   241,   113,   162,   115,    99,   177,   384,     8,   190,
     387,  1047,   123,    86,   254,    99,   256,   652,   241,    19,
     309,   288,   289,   312,   183,     8,   266,   175,   276,   269,
      99,   142,   409,   954,    99,    99,    19,    86,  1047,   287,
     110,    99,   201,   214,   120,   175,   109,   270,   271,   209,
     273,   274,   429,   430,   726,   432,   142,   434,   440,   145,
      30,   733,   439,   206,    34,   170,   175,   147,   145,   142,
     359,   175,   135,   113,   175,   115,   365,   454,    88,   184,
     240,   175,   371,   123,   164,   148,   375,   136,    86,   378,
     379,   175,   469,   382,   383,   105,     8,     9,   475,   145,
    1257,    71,   142,   246,   285,   286,   175,   288,   289,   185,
     175,   175,   198,   113,   496,   115,   276,   175,   110,   182,
    1214,   410,     8,     9,   124,    56,    57,   287,    98,   127,
     113,   155,   115,   805,   132,   145,  1376,   210,   211,   811,
     142,   124,   142,   970,    58,    59,   170,    61,   967,   127,
     847,   440,   849,   127,   443,   444,   445,   928,   137,   142,
     979,   311,  1198,   452,   142,   110,   455,   317,   142,   137,
     147,   277,   278,   279,    88,   154,   465,   812,   813,   110,
       8,     9,   817,    95,   572,   573,   154,   164,   158,  1198,
     134,    54,   569,   890,   170,   892,   110,   574,   487,   871,
     872,   113,   874,   115,   876,   840,   495,   496,   184,    95,
     187,   214,  1336,    88,  1338,    92,   219,    92,    20,   258,
     164,    34,    35,    36,   896,   264,    39,   113,   105,   115,
     142,   237,   238,   272,   146,   907,   908,   909,   182,   911,
     912,   913,   914,   915,   916,   145,   918,   919,   800,   214,
     162,   216,   189,   259,   189,  1197,   142,   634,   635,   931,
     146,   198,   814,   198,   641,   145,   648,    95,   187,   651,
     189,   183,   654,  1393,  1394,  1311,   162,   110,   950,   198,
     952,   953,   157,   660,    45,   113,   214,   115,   216,   201,
      51,  1255,   927,    54,    55,   584,  1260,   183,   142,   241,
     102,    62,  1311,  1404,   127,  1425,   221,   684,   223,   132,
     142,  1431,   114,   602,   142,   201,   142,   204,   146,   145,
      88,   258,   994,   142,    92,   258,   145,   264,   270,   271,
     263,   273,   274,   710,   162,   272,   138,    87,   145,   127,
     142,  1315,  1014,   145,   132,  1172,  1320,   239,    98,  1385,
     242,   226,  1179,  1180,   239,   183,   214,   242,   108,   648,
     142,   221,   651,   223,   110,   654,   241,   117,   243,   244,
     245,   748,  1191,   201,   118,   119,  1385,   227,   253,   254,
     145,   256,   671,   231,  1348,  1057,   261,   142,  1352,   157,
     231,   266,   267,   268,   269,   283,   284,   158,   687,   160,
    1072,    58,    59,   575,  1076,  1077,   578,  1079,   580,   110,
      86,    87,  1084,   174,   280,   281,   282,   283,   210,   211,
     212,   149,    98,  1058,   235,     0,   237,   278,   279,   156,
    1065,   179,   108,  1397,   118,   119,   725,  1410,  1411,   200,
    1382,   117,   731,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,   288,   289,   362,   363,   179,   226,   551,
     552,    84,   839,    68,   841,   558,   559,  1139,   251,  1296,
    1297,   560,   561,   241,   188,   243,   244,   245,    93,  1151,
     773,   774,   771,   772,   773,   774,   254,    94,   256,  1313,
    1314,   143,  1164,   261,   122,  1167,   145,  1169,   266,   267,
     268,   269,   130,   131,    34,   133,    34,    20,   141,  1144,
     110,   142,   140,   175,   803,   142,   144,   142,   146,   175,
     142,   268,   110,   151,   110,   268,   142,   145,   145,   175,
      27,   145,   145,   145,    15,   175,   202,    20,   175,   167,
     220,    25,  1369,   110,    99,   220,    86,   158,    86,   159,
     159,    86,   145,    20,    99,    99,   117,   149,   847,   149,
     849,    20,   122,   191,   192,   193,   194,   195,   196,   290,
    1242,   122,  1244,   142,   172,   172,   175,   172,  1250,   175,
      88,   172,    30,   172,    88,    88,   132,   172,   175,    99,
     172,   175,  1264,  1265,  1266,  1267,  1268,  1232,  1270,  1271,
     172,   890,   175,   892,   175,   175,   172,   172,    86,   132,
     214,   175,   159,   172,   110,   122,   179,   110,   226,   110,
     110,  1293,   136,   257,  1001,   269,   250,   122,    86,   172,
     132,   252,   173,   132,   272,   271,   279,   272,   172,   172,
      92,   142,   122,   172,   186,   122,    88,   936,   122,   149,
     939,  1286,   172,   142,   110,   110,  1328,   136,   947,  1331,
     949,  1333,   132,  1335,    27,   246,   142,   172,    20,   110,
     142,   110,    71,  1050,   172,    99,    99,   235,   172,   145,
     145,    47,   136,   136,    86,   247,   136,   175,   134,   272,
    1067,   247,    20,   272,    20,   159,   134,   179,    99,   172,
     175,   132,   136,   110,   175,   110,   175,   996,    61,   122,
       6,  1383,   175,   175,  1091,   175,   222,   226,   179,    98,
     132,    98,   179,   174,   110,   136,   175,    86,  1105,   265,
     222,   175,   172,    20,    20,   222,   222,   145,   174,   172,
     116,    88,    88,   172,   172,   172,   172,    20,  1420,    88,
      86,    59,   110,   185,   174,   110,   174,   171,  1047,   285,
     185,    85,   110,   185,   185,   110,   175,   142,   507,   507,
     255,  1010,   606,  1445,   804,  1034,  1383,   786,  1132,   373,
    1069,  1199,   229,   885,   939,  1074,   511,   255,  1074,   232,
    1248,  1086,  1140,   238,  1153,   232,  1085,   232,   931,  1151,
     465,  1148,   531,  1069,   553,  1048,   532,  1099,  1431,   688,
    1425,   774,   803,   849,   453,  1009,  1127,  1106,   967,  1137,
     749,   453,   979,  1191,   750,   971,  1325,  1210,  1186,   968,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   276,  1136,    -1,    -1,
      -1,  1140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   297,    -1,
      -1,    -1,    -1,    -1,   301,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1245,  1246,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1256,    -1,    -1,
      -1,    -1,  1261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1311,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1332,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1361,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1385,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
    1459,    -1,    -1,    25,    26,  1464,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    97,    98,    -1,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,   114,    -1,   116,   117,   118,   119,    -1,   121,
      -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,   135,   136,   137,   138,   139,   140,   141,
      -1,    -1,    -1,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,    -1,   164,   165,    -1,    -1,   168,   169,   170,    -1,
      -1,    -1,   174,    -1,   176,   177,   178,    -1,   180,   181,
     182,    -1,   184,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,   199,   200,   201,
      -1,   203,   204,    -1,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    97,    98,    -1,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,   114,    -1,   116,   117,   118,   119,
      -1,   121,    -1,    -1,    -1,   125,   126,   127,   128,   129,
      -1,    -1,    -1,    -1,    -1,   135,   136,   137,   138,   139,
     140,   141,    -1,    -1,    -1,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,   159,
     160,   161,   162,    -1,   164,   165,    -1,    -1,   168,   169,
     170,    -1,    -1,    -1,   174,   175,   176,   177,   178,    -1,
     180,   181,   182,    -1,   184,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,   199,
     200,   201,    -1,   203,   204,    -1,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    97,    98,
      -1,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,   114,    -1,   116,   117,   118,
     119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,   128,
     129,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,   138,
     139,   140,   141,    -1,    -1,    -1,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,   160,   161,   162,    -1,   164,   165,    -1,    -1,   168,
     169,   170,    -1,   172,    -1,   174,    -1,   176,   177,   178,
      -1,   180,   181,   182,    -1,   184,    -1,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
     199,   200,   201,    -1,   203,   204,    -1,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    97,
      98,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,   114,    -1,   116,   117,
     118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
     138,   139,   140,   141,    -1,    -1,    -1,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,   162,    -1,   164,   165,    -1,    -1,
     168,   169,   170,    -1,    -1,    -1,   174,   175,   176,   177,
     178,    -1,   180,   181,   182,    -1,   184,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,   199,   200,   201,    -1,   203,   204,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      97,    98,    -1,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    -1,   114,    -1,   116,
     117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,   135,   136,
     137,   138,   139,   140,   141,    -1,    -1,    -1,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,   158,   159,   160,   161,   162,    -1,   164,   165,    -1,
      -1,   168,   169,   170,    -1,   172,    -1,   174,    -1,   176,
     177,   178,    -1,   180,   181,   182,    -1,   184,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,   199,   200,   201,    -1,   203,   204,    -1,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    97,    98,    -1,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    -1,   114,    -1,
     116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,   138,   139,   140,   141,    -1,    -1,    -1,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,   164,   165,
      -1,    -1,   168,   169,   170,    -1,   172,    -1,   174,    -1,
     176,   177,   178,    -1,   180,   181,   182,    -1,   184,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,   199,   200,   201,    -1,   203,   204,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    97,    98,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    -1,   114,
      -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,
     125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,
     135,   136,   137,   138,   139,   140,   141,    -1,    -1,    -1,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,
     155,   156,   157,   158,   159,   160,   161,   162,    -1,   164,
     165,    -1,    -1,   168,   169,   170,    -1,   172,    -1,   174,
      -1,   176,   177,   178,    -1,   180,   181,   182,    -1,   184,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,   199,   200,   201,    -1,   203,   204,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    97,    98,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
     114,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,   138,   139,   140,   141,    -1,    -1,
      -1,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,   161,   162,    -1,
     164,   165,    -1,    -1,   168,   169,   170,    -1,   172,    -1,
     174,    -1,   176,   177,   178,    -1,   180,   181,   182,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,   201,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    97,    98,    -1,    -1,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,   114,    -1,   116,   117,   118,   119,    -1,   121,    -1,
      -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,
      -1,    -1,   135,   136,   137,   138,   139,   140,   141,    -1,
      -1,    -1,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,   162,
      -1,   164,   165,    -1,    -1,   168,   169,   170,    -1,   172,
      -1,   174,    -1,   176,   177,   178,    -1,   180,   181,   182,
      -1,   184,    -1,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,   199,   200,   201,    -1,
     203,   204,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    97,    98,    -1,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,   114,    -1,   116,   117,   118,   119,    -1,   121,
      -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,   135,   136,   137,   138,   139,   140,   141,
      -1,    -1,    -1,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,    -1,   164,   165,    -1,    -1,   168,   169,   170,    -1,
     172,    -1,   174,    -1,   176,   177,   178,    -1,   180,   181,
     182,    -1,   184,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,   199,   200,   201,
      -1,   203,   204,    -1,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    -1,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    97,    98,    -1,    -1,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    -1,   114,    -1,   116,   117,   118,   119,    -1,
     121,    -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,   135,   136,   137,   138,   139,   140,
     141,    -1,    -1,    -1,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,   160,
     161,   162,    -1,   164,   165,    -1,    -1,   168,   169,   170,
      -1,    -1,    -1,   174,    -1,   176,   177,   178,    -1,   180,
     181,   182,    -1,   184,    -1,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,   199,   200,
     201,    -1,   203,   204,    -1,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,   252,    -1,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    97,    98,    -1,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,   114,    -1,   116,   117,   118,   119,
      -1,   121,    -1,    -1,    -1,   125,   126,   127,   128,   129,
      -1,    -1,    -1,    -1,    -1,   135,   136,   137,   138,   139,
     140,   141,    -1,    -1,    -1,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,   159,
     160,   161,   162,    -1,   164,   165,    -1,    -1,   168,   169,
     170,    -1,    -1,    -1,   174,    -1,   176,   177,   178,    -1,
     180,   181,   182,    -1,   184,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,   199,
     200,   201,    -1,   203,   204,    -1,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    97,    98,
      -1,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,   114,    -1,   116,   117,   118,
     119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,   128,
     129,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,   138,
     139,   140,   141,    -1,    -1,    -1,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,   160,   161,   162,    -1,   164,   165,    -1,    -1,   168,
     169,   170,    -1,    -1,    -1,   174,    -1,   176,   177,   178,
      -1,   180,   181,   182,    -1,   184,    -1,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
     199,   200,   201,    -1,   203,   204,    -1,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    97,
      98,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,   114,    -1,   116,   117,
     118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
     138,   139,   140,   141,    -1,    -1,    -1,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,   162,    -1,   164,   165,    -1,    -1,
     168,   169,   170,    -1,    -1,    -1,   174,    -1,   176,   177,
     178,    -1,   180,   181,   182,    -1,   184,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,   199,   200,   201,    -1,   203,   204,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      97,    98,    -1,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    -1,   114,    -1,   116,
     117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,   135,   136,
     137,   138,   139,   140,   141,    -1,    -1,    -1,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,   158,   159,   160,   161,   162,    -1,   164,   165,    -1,
      -1,   168,   169,   170,    -1,    -1,    -1,   174,    -1,   176,
     177,   178,    -1,   180,   181,   182,    -1,   184,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,   199,   200,   201,    -1,   203,   204,    -1,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    97,    98,    -1,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    -1,   114,    -1,
     116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,   138,   139,   140,   141,    -1,    -1,    -1,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,   164,   165,
      -1,    -1,   168,   169,   170,    -1,    -1,    -1,   174,    -1,
     176,   177,   178,    -1,   180,   181,   182,    -1,   184,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,   199,   200,   201,    -1,   203,   204,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    97,    98,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    -1,   114,
      -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,
     125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,
     135,   136,   137,   138,   139,   140,   141,    -1,    -1,    -1,
     145,   146,    -1,   148,   149,    -1,    -1,    -1,    -1,   154,
     155,   156,   157,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,    -1,   168,   169,   170,    -1,    -1,    -1,   174,
      -1,   176,   177,   178,    -1,    -1,    -1,   182,    -1,   184,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,   199,   200,   201,    -1,   203,   204,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    -1,    86,    87,    88,    89,    -1,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   103,
     104,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,    -1,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,    -1,   176,   177,    -1,    -1,    -1,    -1,   182,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,    92,
      93,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
     103,   104,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,   116,   117,   118,   119,    -1,   121,    -1,
      -1,    -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,   136,   137,    -1,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,   174,    -1,   176,    -1,    -1,    -1,    -1,    -1,   182,
      -1,   184,    -1,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,
     203,   204,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,    14,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    -1,    84,    -1,
      86,    87,    88,    89,    -1,    -1,    92,    93,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,   103,   104,   105,
      -1,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,    -1,   139,   140,   141,   142,    -1,    -1,   145,
      -1,    -1,   148,   149,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,    -1,
     176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,   199,   200,    -1,    -1,   203,   204,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,    14,    -1,    -1,    -1,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    84,    -1,    86,    87,    88,
      89,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,   103,   104,   105,    -1,    -1,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,
     119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,    -1,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,   174,   175,   176,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,    -1,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
     199,   200,    -1,    -1,   203,   204,    -1,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,
      92,    93,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,   103,   104,   105,    -1,    -1,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,   116,   117,   118,   119,    -1,   121,
      -1,    -1,    -1,   125,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,   136,   137,    -1,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,
      -1,    -1,   174,    -1,   176,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,   199,   200,    -1,
      -1,   203,   204,    -1,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,    16,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    -1,    84,    -1,    86,
      87,    88,    89,    -1,    -1,    92,    93,    94,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,   103,   104,   105,    -1,
      -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,
     137,    -1,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,   174,    -1,   176,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,   199,   200,    -1,    -1,   203,   204,    -1,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    -1,    86,    87,    88,    89,    -1,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   103,
     104,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,    -1,   139,   140,   141,   142,    -1,
      -1,   145,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    84,    -1,    86,    87,    88,    89,    -1,
      -1,    92,    93,    94,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,   103,   104,   105,    -1,    -1,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,    -1,
     121,    -1,    -1,    -1,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   135,   136,   137,    -1,   139,   140,
     141,   142,    -1,    -1,   145,    -1,    -1,   148,   149,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,   174,    -1,   176,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   184,    -1,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,   199,   200,
      -1,    -1,   203,   204,    -1,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,   252,    -1,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    -1,    84,    -1,    86,    87,
      88,    89,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,   103,   104,   105,    -1,    -1,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,
     118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
      -1,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   170,    -1,    -1,    -1,   174,   175,   176,    -1,
      -1,    -1,    -1,    -1,   182,    -1,   184,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,   199,   200,    -1,    -1,   203,   204,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    -1,    -1,    84,
      -1,    86,    87,    88,    89,    -1,    -1,    92,    93,    94,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   103,   104,
     105,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     135,   136,   137,    -1,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,   154,
     155,   156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,
     175,   176,    -1,    -1,    -1,    -1,    -1,   182,    -1,   184,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,   204,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,
      92,    93,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,   103,   104,   105,    -1,    -1,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,   116,   117,   118,   119,    -1,   121,
      -1,    -1,    -1,   125,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,   136,   137,    -1,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,
      -1,    -1,   174,    -1,   176,   177,    -1,    -1,    -1,    -1,
      -1,    -1,   184,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,   199,   200,    -1,
      -1,   203,   204,    -1,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    84,    -1,    86,    87,    88,
      89,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,   103,   104,   105,    -1,    -1,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,
     119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,    -1,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,   174,    -1,   176,   177,    -1,
      -1,    -1,    -1,    -1,    -1,   184,    -1,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
     199,   200,    -1,    -1,   203,   204,    -1,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    -1,    84,    -1,
      86,    87,    88,    89,    -1,    -1,    92,    93,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,   103,   104,   105,
      -1,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,    -1,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,    -1,
     176,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,   199,   200,    -1,    -1,   203,   204,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,    92,
      93,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
     103,   104,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,   116,   117,   118,   119,    -1,   121,    -1,
      -1,    -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,   136,   137,    -1,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,   174,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   184,    -1,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,
     203,   204,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    10,    17,    18,    20,    25,    26,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    97,    98,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   114,   116,   117,   118,   119,
     121,   125,   126,   127,   128,   129,   135,   136,   137,   138,
     139,   140,   141,   145,   146,   147,   148,   149,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   164,   165,   168,
     169,   170,   174,   176,   177,   178,   180,   181,   182,   184,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   199,   200,   201,   203,   204,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     251,   252,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   339,   340,   345,
     346,   349,   355,   357,   362,   363,   364,   365,   366,   374,
     375,   377,   378,   379,   384,   386,   388,   389,   390,   395,
     416,   419,   422,   423,   424,   425,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   472,   473,   474,   488,
     489,   491,   492,   493,   494,   495,   496,   497,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   516,   517,
     518,   519,   520,   521,   522,   525,   531,   532,   533,    34,
      35,    36,    37,    38,    39,    46,    52,    63,    64,    67,
      70,    71,   103,   104,   105,   149,   209,   240,   276,   287,
     367,   368,   149,    86,   142,   210,   211,   145,    25,    26,
      28,    29,    30,    31,    32,    33,    40,    41,    42,    44,
      50,    51,    53,    54,    55,    65,    66,    89,   125,   142,
     145,   157,   190,   203,   213,   214,   215,   217,   218,   225,
     228,   229,   230,   232,   233,   234,   236,   275,   531,   142,
     142,   145,   142,   145,   145,    26,    48,   275,    14,   142,
     145,   530,   531,   110,   110,   110,   142,    56,    57,   110,
     381,    54,   145,   145,   142,   145,   531,    30,    32,    33,
      42,    89,   456,   531,   531,   110,   175,   375,   531,   142,
     530,    16,   531,   531,   448,   142,    21,   202,   204,   214,
     216,   145,   214,   216,   214,   214,   219,   110,   142,   358,
     227,   231,   231,   145,   142,   110,   149,   308,     0,   310,
     311,   313,    25,    41,   315,   315,   374,   179,   179,    99,
     179,   376,    45,    51,    54,    55,    62,   158,   160,   174,
     200,   380,   385,   386,   387,   404,   405,   409,   391,   392,
     531,   156,    84,   122,   130,   131,   133,   140,   144,   146,
     151,   167,   191,   192,   193,   194,   195,   196,   440,   441,
     251,   147,   164,   187,   109,   135,   148,   182,   189,   198,
     126,   139,    68,   188,    93,    94,   147,   164,   439,   142,
     445,   448,   180,   181,   143,   460,   461,   456,   460,   456,
     460,   145,   531,   368,    34,   369,   367,   367,   368,   531,
     170,   184,   157,   190,    20,   529,   155,   170,   170,   184,
     531,   141,   110,   344,    30,    34,    71,    98,   158,   530,
     210,   211,   212,    92,   226,   241,   254,   256,   266,   269,
     545,   546,   547,   548,   549,   552,   557,   558,   531,   531,
     530,   514,   531,   375,   142,   142,   375,   375,   175,   182,
     531,   142,   375,   375,   175,   375,   175,   375,   149,   529,
     105,   149,   338,   529,   149,   529,   375,    20,   175,   530,
     142,   417,   418,   531,   531,   396,   398,   531,   378,   268,
     268,   110,   399,   110,   531,    30,    65,   175,   512,   513,
     375,   175,   182,   531,   142,   417,   175,    27,   476,   477,
     478,   375,     7,   163,    15,   175,   375,   202,    20,   378,
     378,   175,   378,   378,   378,   378,   220,   523,   524,   531,
     359,   378,   378,   378,   397,   403,   531,   530,   317,   318,
      25,   319,   378,   377,   158,   110,   159,   159,   378,   378,
      99,    86,    88,   136,   262,   393,   394,   499,   424,   425,
     427,   427,   427,   427,   426,   427,   427,   427,   142,   145,
     252,   463,   534,   536,   537,   538,   539,   540,   541,   542,
     430,   430,   429,   431,   431,   431,   431,   432,   432,   433,
     433,   220,    86,    86,    86,   172,   375,   448,   448,   375,
     461,   175,   378,   471,   145,   356,   531,    20,    99,    99,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
     321,   322,   323,    86,   127,   132,   341,   342,   343,   531,
     127,   132,   149,   149,   321,   529,   117,   122,   239,   242,
     105,   241,   270,   271,   273,   274,   239,   242,    20,   241,
     270,   271,   273,   274,   277,   278,   279,   347,   348,   290,
     122,   142,   172,   375,   375,   175,   172,    99,   175,    99,
     175,   172,   375,   172,   172,   172,   175,   530,    88,    30,
     530,   529,    88,   530,    88,   172,   175,   175,   172,   375,
      99,   176,   136,   499,   132,    99,   132,   394,   499,   172,
     531,    60,   206,   246,   382,   383,   175,   175,   175,   172,
      99,   175,    99,   175,   172,   375,   176,   531,   477,   478,
     120,   185,   172,   172,   121,   179,    86,   207,   208,   222,
      86,   207,   208,   222,    86,   226,   214,    99,   224,   132,
      25,   360,   375,   175,   172,    53,    99,   122,   179,   105,
     179,   159,   531,   378,   410,   411,   110,   406,   407,   110,
     141,   199,   500,   502,   503,   504,   531,   110,   378,   110,
     136,   394,   136,   136,   393,   394,   427,   375,   534,   540,
     269,   568,    88,   157,   243,   244,   245,   253,   261,   267,
     268,   535,   543,   544,   545,   559,   562,   563,   565,   250,
     252,   257,   564,   237,   238,   259,   560,   500,   500,   498,
     503,   498,   172,   173,    99,   175,   110,   175,   370,   371,
     127,   142,   373,   356,   137,   154,   137,   154,   322,   122,
     502,   343,   378,   499,   132,   378,   529,   529,   118,   119,
     529,   271,   272,    88,   105,   145,   551,   272,    32,    33,
      42,    66,    89,   214,   504,   280,   281,   282,   283,   283,
     284,   348,   375,   529,   375,   172,   172,    92,   420,   421,
     142,   514,   515,   531,   514,   515,   172,   186,   122,   337,
     529,   149,   122,    88,   337,   122,   337,   142,   172,   110,
     378,   378,   136,   378,   110,   378,   132,   132,   394,   136,
     499,   246,    58,    59,    61,   110,   393,   400,   401,   402,
     383,   142,   514,   514,   172,   378,    27,   478,   120,   185,
       8,     9,    95,   113,   115,   142,   183,   372,   473,   475,
     486,   487,   490,    20,   221,   223,   378,   378,   378,   221,
     223,   378,   378,   378,   378,   378,   378,   110,   378,   378,
     344,   361,    99,   179,   172,   358,   235,   526,   527,   142,
     110,   529,   410,    87,    98,   108,   117,   412,   413,   414,
     415,    99,   531,    99,   392,   145,   145,   134,   164,   182,
     501,   531,   531,   378,   136,   378,   378,   136,   394,   136,
     172,   175,   247,   206,   246,   258,   263,   567,    88,   248,
     249,   561,   247,   537,   567,   428,   431,   267,   543,   545,
     538,   136,   561,   272,    47,   134,   378,   531,    86,    99,
     175,   375,   127,   358,   516,   342,   378,   272,    88,   145,
     554,    20,   105,   551,   347,   348,   159,   179,   172,   110,
     500,   105,   421,   172,   375,   175,   175,   134,   175,   175,
     378,   529,    99,   337,   529,   172,   375,   418,   378,   398,
     378,   378,   132,   378,   136,   110,   110,   378,   531,   402,
      61,   172,   375,   175,   175,   122,   183,   475,     6,   375,
     531,   183,   486,   179,   222,   222,   222,   222,   226,   524,
     174,   132,   361,   457,   528,   527,   378,   403,   179,   529,
     118,   119,   414,   415,   415,   411,    98,   408,   407,   175,
     175,   378,   378,   136,   378,   431,    43,   119,   431,   431,
     258,   264,   272,   566,   566,   428,   539,   265,   499,   500,
     371,    86,   172,   126,   189,   553,   556,    20,    20,   555,
     553,   260,   561,    99,   175,    99,   175,   348,   145,   353,
     531,   174,   110,   174,   172,   116,    88,   529,    88,   172,
     378,   378,   531,   531,   401,   378,   172,   478,   531,   183,
     172,   478,   531,   378,   378,   378,   378,   378,   378,   378,
     145,   198,   373,   172,   415,   529,   378,   431,   431,   187,
     500,   554,   554,   556,    20,   175,    20,   255,   550,   551,
     550,   354,   378,    99,   175,    86,   378,   531,   378,   378,
     337,   337,    59,    85,   171,   479,   478,   531,   185,   478,
     110,   457,   431,   561,    99,   175,   175,   412,   499,   354,
     157,   190,   285,   286,   288,   289,   350,   351,   352,   500,
     174,   110,     4,   123,   482,   483,   485,   487,    19,   124,
     480,   481,   484,   487,   185,   478,   185,   531,   255,   551,
     412,   352,   352,   351,   285,   174,   378,   531,    85,   123,
     485,   171,   124,   484,   185,    99,   175,   351,   378,   110,
     373,   531,    99,   175,   110,   373,   531,   175,   373
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
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   306,   307,   307,   308,   308,   308,   308,   308,   308,
     309,   309,   310,   310,   311,   311,   312,   313,   313,   314,
     315,   315,   315,   316,   316,   317,   317,   318,   318,   318,
     318,   319,   319,   319,   319,   319,   319,   319,   319,   320,
     320,   321,   321,   322,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   324,   324,   324,   324,   324,   324,
     324,   324,   325,   325,   326,   327,   327,   328,   328,   329,
     330,   331,   331,   332,   332,   333,   333,   333,   333,   334,
     335,   336,   336,   336,   336,   337,   337,   338,   338,   339,
     339,   339,   339,   339,   339,   339,   339,   340,   341,   341,
     342,   342,   342,   343,   344,   344,   345,   345,   345,   346,
     346,   346,   346,   346,   346,   346,   346,   347,   347,   347,
     347,   348,   348,   349,   350,   350,   350,   351,   351,   351,
     352,   352,   352,   353,   353,   354,   354,   354,   354,   355,
     355,   356,   356,   356,   356,   357,   358,   359,   359,   360,
     360,   361,   361,   362,   363,   364,   365,   365,   366,   366,
     366,   367,   367,   367,   367,   368,   368,   369,   369,   370,
     370,   371,   371,   372,   373,   374,   375,   375,   376,   376,
     377,   377,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   379,
     380,   381,   381,   382,   382,   382,   383,   383,   384,   384,
     385,   386,   386,   386,   387,   387,   387,   387,   387,   388,
     388,   389,   389,   390,   391,   391,   392,   392,   392,   392,
     392,   392,   392,   392,   393,   394,   395,   396,   396,   397,
     397,   398,   398,   398,   398,   399,   399,   400,   400,   400,
     401,   401,   401,   402,   402,   402,   403,   404,   405,   406,
     406,   407,   407,   408,   409,   409,   410,   410,   411,   411,
     412,   412,   412,   412,   412,   412,   412,   413,   413,   414,
     414,   415,   416,   416,   417,   417,   418,   418,   419,   419,
     420,   420,   421,   421,   422,   423,   423,   424,   424,   425,
     425,   425,   425,   425,   426,   425,   425,   425,   425,   427,
     427,   427,   428,   428,   429,   429,   429,   430,   430,   430,
     430,   430,   431,   431,   431,   432,   432,   432,   433,   433,
     434,   434,   435,   435,   436,   436,   437,   437,   438,   438,
     438,   438,   439,   439,   439,   440,   440,   440,   440,   440,
     440,   441,   441,   441,   442,   442,   442,   442,   443,   443,
     444,   444,   445,   445,   446,   446,   446,   446,   447,   448,
     448,   448,   449,   449,   450,   450,   450,   450,   451,   451,
     452,   452,   452,   452,   452,   452,   452,   453,   453,   454,
     454,   455,   455,   455,   455,   455,   456,   456,   457,   457,
     458,   458,   458,   459,   459,   460,   460,   461,   462,   462,
     462,   462,   462,   462,   462,   462,   463,   463,   464,   464,
     464,   465,   466,   466,   467,   468,   469,   470,   470,   471,
     471,   472,   472,   473,   473,   473,   474,   474,   474,   474,
     474,   474,   475,   475,   476,   476,   477,   478,   478,   479,
     479,   480,   480,   481,   481,   481,   481,   482,   482,   483,
     483,   483,   483,   484,   484,   485,   485,   486,   486,   486,
     486,   487,   487,   487,   487,   488,   488,   489,   489,   490,
     491,   491,   491,   491,   491,   491,   492,   493,   493,   493,
     493,   494,   494,   494,   494,   495,   496,   497,   497,   497,
     497,   498,   498,   499,   500,   500,   500,   501,   501,   501,
     502,   502,   502,   503,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   505,   506,   506,   506,   507,   508,   509,
     509,   509,   510,   510,   510,   510,   510,   511,   512,   512,
     512,   512,   512,   512,   512,   513,   514,   515,   516,   517,
     517,   517,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   519,   519,   520,   520,   521,   522,   523,   523,
     524,   525,   526,   526,   527,   527,   527,   527,   528,   528,
     529,   530,   530,   531,   531,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   533,
     533,   534,   534,   534,   534,   535,   535,   535,   535,   536,
     536,   537,   537,   538,   538,   539,   539,   540,   540,   540,
     541,   541,   542,   542,   543,   543,   543,   543,   543,   544,
     545,   545,   545,   545,   545,   545,   545,   546,   546,   546,
     546,   547,   547,   547,   547,   548,   548,   549,   549,   549,
     549,   549,   549,   549,   550,   550,   551,   551,   551,   551,
     552,   552,   552,   552,   552,   553,   553,   554,   554,   555,
     555,   556,   556,   557,   558,   558,   559,   559,   559,   560,
     560,   560,   560,   560,   561,   561,   561,   561,   562,   563,
     564,   565,   565,   566,   566,   566,   567,   567,   568
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       4,     6,     2,     1,     1,     2,     6,     1,     2,     6,
       2,     2,     4,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     3,     3,     5,     5,     4,
       3,     3,     3,     5,     5,     5,     5,     5,     5,     4,
       3,     3,     4,     5,     6,     1,     3,     3,     3,     3,
       6,     5,     8,     3,     6,     5,     8,     4,     3,     1,
       1,     1,     2,     2,     2,     3,     5,     4,     6,     3,
       5,     4,     6,     4,     6,     5,     7,     2,     2,     2,
       2,     2,     2,     9,     1,     2,     3,     1,     2,     2,
       0,     1,     1,     2,     3,     1,     2,     2,     3,     3,
       3,     2,     3,     4,     5,     2,     4,     3,     0,     3,
       2,     1,     3,     5,     3,     5,     2,     2,     2,     3,
       3,     1,     2,     2,     2,     4,     4,     4,     4,     1,
       3,     2,     3,     3,     3,     1,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     2,     4,     3,     5,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     2,     1,     4,     3,     4,     4,     5,
       4,     5,     5,     6,     3,     3,     3,     1,     4,     1,
       4,     3,     4,     4,     5,     4,     5,     1,     2,     3,
       1,     2,     1,     6,     3,     3,     1,     2,     3,     1,
       3,     2,     3,     2,     3,     4,     1,     3,     1,     2,
       1,     1,     1,     2,     2,     2,     3,     1,     1,     2,
       2,     2,     5,     5,     1,     4,     3,     4,     8,    10,
       1,     2,     4,     7,     8,     1,     3,     1,     3,     1,
       3,     3,     3,     3,     0,     4,     3,     3,     3,     1,
       3,     4,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     4,
       1,     4,     1,     4,     1,     4,     1,     2,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     5,     6,     3,     4,
       1,     2,     3,     2,     1,     2,     2,     1,     1,     1,
       3,     3,     1,     1,     1,     2,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     1,     4,     4,     3,     4,     1,
       3,     1,     1,     1,     1,     1,     4,     5,     8,     9,
       9,    10,     1,     2,     1,     2,     6,     0,     1,     3,
       3,     0,     1,     1,     1,     2,     2,     0,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     4,     4,     5,     6,
       7,     4,     5,     6,     7,     4,     4,     4,     5,     6,
       7,     1,     2,     2,     1,     2,     3,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     4,     4,     3,     3,     3,
       4,     4,     3,     4,     6,     4,     6,     3,     3,     4,
       6,     6,     4,     6,     6,     4,     1,     2,     1,     3,
       3,     3,     5,     7,     7,     5,     5,     5,     7,     7,
       5,     5,     3,     3,     5,     7,     5,     7,     1,     4,
       3,     5,     1,     2,     3,     7,    10,    13,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     7,
       4,     1,     2,     3,     4,     1,     1,     2,     2,     1,
       3,     1,     3,     1,     4,     1,     2,     1,     2,     3,
       1,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     3,     5,
       7,     5,     7,     2,     1,     3,     2,     4,     4,     6,
       4,     5,     4,     5,     3,     1,     2,     2,     3,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     1,     2,     1,     2,     3,     3,     4,     3,     3,
       3,     2,     2,     1,     1,     1,     1,     1,     3
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const xquery_parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "\"'unrecognized'\"",
  "\"'apos attribute content'\"", "\"'char literal'\"",
  "\"'char literal]]>'\"", "\"'char literal and pi end'\"",
  "\"'#charref;'\"", "\"'element content'\"", "\"'pref:*'\"",
  "\"'&entity;'\"", "\"'comment literal'\"", "\"'pi <NCName {>'\"",
  "\"'NCName_sval'\"", "\"'pragma literal'\"", "\"'QName #)'\"",
  "\"'*:QName'\"", "\"'QName_sval'\"", "\"'quote attribute content'\"",
  "\"'STRING'\"", "\"'XML comment'\"", "\"'URI'\"", "\"'NCName'\"",
  "\"'KEYWORD'\"", "\"'declare'\"", "\"'module'\"", "\"<blank>\"",
  "\"'validate'\"", "\"'typeswitch'\"", "\"'element'\"", "\"'document'\"",
  "\"'text'\"", "\"'comment'\"", "\"'function'\"", "\"'updating'\"",
  "\"'sequential'\"", "\"'deterministic'\"", "\"'nondeterministic'\"",
  "\"'simple'\"", "\"'if'\"", "\"'import'\"",
  "\"'processing-instruction'\"", "\"'most'\"", "\"'some'\"",
  "\"'stable'\"", "\"'option'\"", "\"'word'\"", "\"'schema'\"",
  "\"'space'\"", "\"'set'\"", "\"'let'\"", "\"'construction'\"",
  "\"'eval'\"", "\"'for'\"", "\"'outer'\"", "\"'sliding'\"",
  "\"'tumbling'\"", "\"'previous'\"", "\"'next'\"", "\"'only'\"",
  "\"'when'\"", "\"'count'\"", "\"'ordering'\"", "\"'base-uri'\"",
  "\"'schema-element'\"", "\"'document-node'\"", "\"'copy-namespaces'\"",
  "\"'instance'\"", "\"'schema-attribute'\"", "\"'boundary-space'\"",
  "\"'decimal-format'\"", "\"'decimal-separator'\"",
  "\"'grouping-separator'\"", "\"'infinity'\"", "\"'minus-sign'\"",
  "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"", "\"'zero-digit'\"",
  "\"'digit'\"", "\"'pattern-separator'\"", "\"'ancestor::'\"",
  "\"'ancestor-or-self::'\"", "\"'and'\"", "\"'''\"", "\"'as'\"",
  "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'attribute::'\"",
  "\"'@'\"", "\"'case'\"", "\"'castable'\"", "\"'cast'\"", "\"'CDATA[['\"",
  "\"']]'\"", "\"'child::'\"", "\"'collation'\"", "\"','\"", "\"'(:'\"",
  "\"':)'\"", "\"'DECIMAL'\"", "\"'context'\"", "\"'variable'\"",
  "\"'default'\"", "\"'descendant::'\"", "\"'descendant-or-self::'\"",
  "\"'descending'\"", "\"'div'\"", "\"'$'\"", "\"'.'\"", "\"'..'\"",
  "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"", "\"'else'\"",
  "\"'empty'\"", "\"'greatest'\"", "\"'least'\"", "\"'/>'\"",
  "\"'encoding'\"", "\"'='\"", "\"''''\"", "\"'\\\"\\\"'\"", "\"'every'\"",
  "\"'except'\"", "\"'external'\"", "\"'following::'\"",
  "\"'following-sibling::'\"", "\"'follows'\"", "\"'>='\"", "\"':='\"",
  "\"'>'\"", "\"'?'\"", "\"'idiv'\"", "\"'in'\"", "\"'inherit'\"",
  "\"'INTEGER'\"", "\"'intersect'\"", "\"'is'\"", "\"'item'\"", "\"'{'\"",
  "\"'['\"", "\"'<='\"", "\"'('\"", "\"'<'\"", "\"'-'\"", "\"'mod'\"",
  "\"'namespace'\"", "\"'nan'\"", "\"'!='\"", "\"'nodecomp'\"",
  "\"'?""?'\"", "\"'<no inherit>'\"", "\"'<no preserve>'\"", "\"'or'\"",
  "\"'ordered'\"", "\"'order'\"", "\"'by'\"", "\"'group'\"",
  "\"'parent::'\"", "\"'<?'\"", "\"'?>'\"", "\"'+'\"",
  "\"'PRAGMA BEGIN'\"", "\"'PRAGMA END'\"", "\"'<<'\"",
  "\"'preceding::'\"", "\"'preceding-sibling::'\"", "\"'preserve'\"",
  "\"'\\\"'\"", "\"'}'\"", "\"']'\"", "\"'return'\"", "\"')'\"",
  "\"'satisfies'\"", "\"'<schema attribute ('\"", "\"'self::'\"",
  "\"';'\"", "\"'/'\"", "\"'//'\"", "\"'*'\"", "\"</ (start tag end)\"",
  "\"'strip'\"", "\"> (tag end)\"", "\"'then'\"", "\"'to'\"",
  "\"'treat'\"", "\"'union'\"", "\"'unordered'\"", "\"'eq'\"", "\"'ge'\"",
  "\"'gt'\"", "\"'le'\"", "\"'lt'\"", "\"'ne'\"", "\"'VALUECOMP'\"",
  "\"'|'\"", "\"'empty-sequence'\"", "\"'where'\"", "\"'<!--'\"",
  "\"'-->'\"", "\"'xquery'\"", "\"'version'\"", "\"'#)'\"", "\"'start'\"",
  "\"'after'\"", "\"'before'\"", "\"'revalidation'\"", "\"'strict'\"",
  "\"'lax'\"", "\"'skip'\"", "\"'delete'\"", "\"'node'\"", "\"'insert'\"",
  "\"'nodes'\"", "\"'rename'\"", "\"'replace'\"", "\"'value'\"",
  "\"'of'\"", "\"'first'\"", "\"'into'\"", "\"'last'\"", "\"'modify'\"",
  "\"'copy'\"", "\"'with'\"", "\"'returning'\"", "\"'block'\"",
  "\"'exit'\"", "\"'break'\"", "\"'loop'\"", "\"'continue'\"",
  "\"'while'\"", "\"'try'\"", "\"'catch'\"", "\"'using'\"", "\"'all'\"",
  "\"'any'\"", "\"'casesensitive'\"", "\"'ft-option'\"",
  "\"'diacritics'\"", "\"'insensitive'\"", "\"'different'\"",
  "\"'distance'\"", "\"'entire'\"", "\"'end'\"", "\"'content'\"",
  "\"'exactly'\"", "\"'from'\"", "\"'&&'\"", "\"'ftcontains'\"",
  "\"'not'\"", "\"'||'\"", "\"'language'\"", "\"'levels'\"",
  "\"'lowercase'\"", "\"'occurs'\"", "\"'paragraph'\"", "\"'phrase'\"",
  "\"'relationship'\"", "\"'same'\"", "\"'score'\"", "\"'sentence'\"",
  "\"'sentences'\"", "\"'times'\"", "\"'uppercase'\"", "\"'weight'\"",
  "\"'window'\"", "\"'without'\"", "\"'stemming'\"", "\"'stop'\"",
  "\"'words'\"", "\"'thesaurus'\"", "\"'wildcards'\"", "\"'datamodule'\"",
  "\"'collection'\"", "\"'node-type'\"", "\"'collection-modifier'\"",
  "\"'node-modifier'\"", "\"'const'\"", "\"'append-only'\"", "\"'queue'\"",
  "\"'mutable'\"", "\"'read-only'\"", "\"'unique'\"", "\"'non'\"",
  "\"'index'\"", "\"'manual'\"", "\"'automatic'\"", "\"'on'\"",
  "\"'BOM_UTF8'\"", "FTCONTAINS_REDUCE", "RANGE_REDUCE", "ADDITIVE_REDUCE",
  "MULTIPLICATIVE_REDUCE", "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE",
  "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR", "UNARY_PREC",
  "SEQUENCE_TYPE_REDUCE", "OCCURS_STAR", "OCCURS_PLUS", "OCCURS_HOOK",
  "STEP_REDUCE", "$accept", "Module", "ModuleWithoutBOM", "VersionDecl",
  "MainModule", "LibraryModule", "ModuleDecl", "DataModule",
  "DataModuleDecl", "Prolog", "SIND_DeclList", "VFO_DeclList", "SIND_Decl",
  "VFO_Decl", "DecimalFormatDecl", "DecimalFormatParamList",
  "DecimalFormatParam", "DecimalFormatParamName", "Setter", "Import",
  "NamespaceDecl", "BoundarySpaceDecl", "DefaultNamespaceDecl",
  "OptionDecl", "FTOptionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "DefaultCollationDecl", "BaseURIDecl",
  "SchemaImport", "URILiteralList", "SchemaPrefix", "ModuleImport",
  "CtxItemDecl", "CtxItemDecl2", "CtxItemDecl3", "CtxItemDecl4",
  "VarNameAndType", "VarDecl", "CollectionDecl", "CollectionModifier",
  "NodeModifier", "IndexDecl", "IndexProperties", "IndexProperties2",
  "IndexProperties3", "IndexKeyList", "IndexKeySpec", "ConstructionDecl",
  "FunctionSig", "BlockExpr", "Block", "BlockDecls", "BlockVarDeclList",
  "BlockVarDecl", "AssignExpr", "ExitExpr", "WhileExpr",
  "FlowCtlStatement", "FunctionDecl", "FunctionDecl2", "FunctionDecl3",
  "FunctionDecl4", "ParamList", "Param", "EnclosedExpr", "BracedExpr",
  "QueryBody", "Expr", "ApplyExpr", "ConcatExpr", "ExprSingle",
  "FLWORExpr", "ReturnExpr", "WindowType", "FLWORWinCondType",
  "FLWORWinCond", "WindowClause", "CountClause", "ForLetWinClause",
  "FLWORClause", "FLWORClauseList", "ForDollar", "ForClause",
  "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar", "LetClause",
  "VarGetsDeclList", "EvalVarDeclList", "VarGetsDecl", "WindowVarDecl",
  "WindowVars", "WindowVars3", "WindowVars2", "EvalVarDecl", "WhereClause",
  "GroupByClause", "GroupSpecList", "GroupSpec", "GroupCollationSpec",
  "OrderByClause", "OrderSpecList", "OrderSpec", "OrderModifier",
  "OrderDirSpec", "OrderEmptySpec", "OrderCollationSpec", "QuantifiedExpr",
  "QVarInDeclList", "QVarInDecl", "TypeswitchExpr", "CaseClauseList",
  "CaseClause", "IfExpr", "OrExpr", "AndExpr", "ComparisonExpr", "$@1",
  "FTContainsExpr", "RangeExpr", "AdditiveExpr", "MultiplicativeExpr",
  "UnionExpr", "IntersectExceptExpr", "InstanceofExpr", "TreatExpr",
  "CastableExpr", "CastExpr", "UnaryExpr", "SignList", "ValueExpr",
  "ValueComp", "NodeComp", "ValidateExpr", "ExtensionExpr", "PragmaList",
  "Pragma", "PathExpr", "LeadingSlash", "RelativePathExpr", "StepExpr",
  "AxisStep", "ForwardStep", "ForwardAxis", "AbbrevForwardStep",
  "ReverseStep", "ReverseAxis", "NodeTest", "NameTest", "Wildcard",
  "FilterExpr", "PredicateList", "Predicate", "PrimaryExpr", "Literal",
  "NumericLiteral", "VarRef", "ParenthesizedExpr", "ContextItemExpr",
  "OrderedExpr", "UnorderedExpr", "FunctionCall", "ArgList", "Constructor",
  "DirectConstructor", "DirElemConstructor", "DirElemContentList",
  "DirAttributeList", "DirAttr", "OptionalBlank", "DirAttributeValue",
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
  "VarNameDecl", "TryExpr", "CatchListExpr", "CatchExpr", "NameTestList",
  "URI_LITERAL", "NCNAME", "QNAME", "KEYWORD", "EvalExpr", "FTSelection",
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
       307,     0,    -1,   308,    -1,   291,   308,    -1,   310,    -1,
     309,   310,    -1,   311,    -1,   309,   311,    -1,   313,    -1,
     309,   313,    -1,   203,   204,    20,   179,    -1,   203,   204,
      20,   121,    20,   179,    -1,   315,   374,    -1,   374,    -1,
     312,    -1,   312,   315,    -1,    26,   149,   530,   122,   529,
     179,    -1,   314,    -1,   314,   315,    -1,   275,   149,   530,
     122,   529,   179,    -1,   316,   179,    -1,   317,   179,    -1,
     316,   179,   317,   179,    -1,   318,    -1,   316,   179,   318,
      -1,   319,    -1,   317,   179,   319,    -1,   324,    -1,   325,
      -1,   326,    -1,   328,    -1,   345,    -1,   340,    -1,   366,
      -1,   329,    -1,   330,    -1,   346,    -1,   349,    -1,   320,
      -1,    25,   105,    71,   321,    -1,    25,    71,   531,   321,
      -1,   322,    -1,   321,   322,    -1,   323,   122,   516,    -1,
      72,    -1,    73,    -1,    74,    -1,    75,    -1,    76,    -1,
      77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,
     327,    -1,   334,    -1,   335,    -1,   355,    -1,   331,    -1,
     332,    -1,   333,    -1,   517,    -1,   336,    -1,   339,    -1,
      25,   149,   530,   122,   529,    -1,    25,    70,   170,    -1,
      25,    70,   184,    -1,    25,   105,    30,   149,   529,    -1,
      25,   105,    34,   149,   529,    -1,    25,    46,   531,    20,
      -1,    25,   240,   545,    -1,    25,    63,   157,    -1,    25,
      63,   190,    -1,    25,   105,   158,   117,   118,    -1,    25,
     105,   158,   117,   119,    -1,    25,    67,   170,    99,   137,
      -1,    25,    67,   170,    99,   154,    -1,    25,    67,   155,
      99,   137,    -1,    25,    67,   155,    99,   154,    -1,    25,
     105,    98,   529,    -1,    25,    64,   529,    -1,    41,    48,
     529,    -1,    41,    48,   338,   529,    -1,    41,    48,   529,
      88,   337,    -1,    41,    48,   338,   529,    88,   337,    -1,
     529,    -1,   337,    99,   529,    -1,   149,   530,   122,    -1,
     105,    30,   149,    -1,    41,    26,   529,    -1,    41,    26,
     149,   530,   122,   529,    -1,    41,    26,   529,    88,   337,
      -1,    41,    26,   149,   530,   122,   529,    88,   337,    -1,
      41,   275,   529,    -1,    41,   275,   149,   530,   122,   529,
      -1,    41,   275,   529,    88,   337,    -1,    41,   275,   149,
     530,   122,   529,    88,   337,    -1,    25,   103,   141,   341,
      -1,    86,   502,   342,    -1,   342,    -1,   343,    -1,   127,
      -1,   127,   343,    -1,   132,   378,    -1,   110,   531,    -1,
     110,   531,   499,    -1,    25,   104,   344,   132,   378,    -1,
      25,   104,   344,   127,    -1,    25,   104,   344,   127,   132,
     378,    -1,    25,   276,   531,    -1,    25,   276,   531,   277,
     504,    -1,    25,   276,   531,   347,    -1,    25,   276,   531,
     277,   504,   347,    -1,    25,   276,   531,   348,    -1,    25,
     276,   531,   277,   504,   348,    -1,    25,   276,   531,   347,
     348,    -1,    25,   276,   531,   277,   504,   347,   348,    -1,
     278,   280,    -1,   278,   281,    -1,   278,   282,    -1,   278,
     283,    -1,   279,   284,    -1,   279,   283,    -1,    25,   287,
     531,   290,   375,   159,   353,   175,   350,    -1,   351,    -1,
     285,   351,    -1,   286,   285,   351,    -1,   352,    -1,   157,
     352,    -1,   190,   352,    -1,    -1,   288,    -1,   289,    -1,
     145,   354,    -1,   353,    99,   354,    -1,   378,    -1,   378,
     412,    -1,   378,   499,    -1,   378,   499,   412,    -1,    25,
      52,   170,    -1,    25,    52,   184,    -1,   145,   175,    -1,
     145,   370,   175,    -1,   145,   175,    86,   500,    -1,   145,
     370,   175,    86,   500,    -1,   228,   358,    -1,   142,   359,
     375,   172,    -1,   359,   360,   179,    -1,    -1,   360,    99,
     361,    -1,    25,   361,    -1,   344,    -1,   344,   132,   378,
      -1,    50,   110,   531,   132,   378,    -1,   229,   227,   378,
      -1,   233,   145,   378,   175,   358,    -1,   230,   231,    -1,
     232,   231,    -1,    25,   367,    -1,    25,    38,   367,    -1,
      25,    37,   367,    -1,   368,    -1,    39,   368,    -1,    35,
     368,    -1,    36,   369,    -1,    34,   531,   356,   373,    -1,
      34,   531,   356,   127,    -1,    34,   531,   356,   358,    -1,
      34,   531,   356,   127,    -1,   371,    -1,   370,    99,   371,
      -1,   110,   531,    -1,   110,   531,   499,    -1,   142,   375,
     172,    -1,   142,   375,   172,    -1,   375,    -1,   377,    -1,
     377,   376,    -1,   179,    -1,   376,   377,   179,    -1,   378,
      -1,   377,    99,   378,    -1,   379,    -1,   416,    -1,   419,
      -1,   422,    -1,   423,    -1,   518,    -1,   519,    -1,   521,
      -1,   520,    -1,   522,    -1,   525,    -1,   533,    -1,   363,
      -1,   364,    -1,   365,    -1,   362,    -1,   357,    -1,   388,
     380,    -1,   174,   378,    -1,    56,   268,    -1,    57,   268,
      -1,   206,    -1,   246,    -1,    60,   246,    -1,   382,   400,
      61,   378,    -1,   382,    61,   378,    -1,    54,   381,   399,
     383,   383,    -1,    54,   381,   399,   383,    -1,    62,   110,
     531,    -1,   390,    -1,   395,    -1,   384,    -1,   386,    -1,
     404,    -1,   409,    -1,   405,    -1,   385,    -1,   386,    -1,
     388,   387,    -1,    54,   110,    -1,    55,    54,   110,    -1,
     389,   391,    -1,   392,    -1,   391,    99,   110,   392,    -1,
     531,   136,   378,    -1,   531,   499,   136,   378,    -1,   531,
     393,   136,   378,    -1,   531,   499,   393,   136,   378,    -1,
     531,   394,   136,   378,    -1,   531,   499,   394,   136,   378,
      -1,   531,   393,   394,   136,   378,    -1,   531,   499,   393,
     394,   136,   378,    -1,    88,   110,   531,    -1,   262,   110,
     531,    -1,    51,   110,   396,    -1,   398,    -1,   396,    99,
     110,   398,    -1,   403,    -1,   397,    99,   110,   403,    -1,
     531,   132,   378,    -1,   531,   499,   132,   378,    -1,   531,
     394,   132,   378,    -1,   531,   499,   394,   132,   378,    -1,
     110,   531,   136,   378,    -1,   110,   531,   499,   136,   378,
      -1,   401,    -1,   110,   531,    -1,   110,   531,   401,    -1,
     393,    -1,   393,   402,    -1,   402,    -1,    58,   110,   531,
      59,   110,   531,    -1,    59,   110,   531,    -1,    58,   110,
     531,    -1,   531,    -1,   200,   378,    -1,   160,   159,   406,
      -1,   407,    -1,   406,    99,   407,    -1,   110,   531,    -1,
     110,   531,   408,    -1,    98,   529,    -1,   158,   159,   410,
      -1,    45,   158,   159,   410,    -1,   411,    -1,   410,    99,
     411,    -1,   378,    -1,   378,   412,    -1,   413,    -1,   414,
      -1,   415,    -1,   413,   414,    -1,   413,   415,    -1,   414,
     415,    -1,   413,   414,   415,    -1,    87,    -1,   108,    -1,
     117,   118,    -1,   117,   119,    -1,    98,   529,    -1,    44,
     110,   417,   176,   378,    -1,   125,   110,   417,   176,   378,
      -1,   418,    -1,   417,    99,   110,   418,    -1,   531,   136,
     378,    -1,   531,   499,   136,   378,    -1,    29,   145,   375,
     175,   420,   105,   174,   378,    -1,    29,   145,   375,   175,
     420,   105,   110,   531,   174,   378,    -1,   421,    -1,   420,
     421,    -1,    92,   500,   174,   378,    -1,    92,   110,   531,
      86,   500,   174,   378,    -1,    40,   145,   375,   175,   186,
     378,   116,   378,    -1,   424,    -1,   423,   156,   424,    -1,
     425,    -1,   424,    84,   425,    -1,   427,    -1,   427,   440,
     427,    -1,   427,   441,   427,    -1,   427,   122,   427,    -1,
     427,   151,   427,    -1,    -1,   427,   146,   426,   427,    -1,
     427,   144,   427,    -1,   427,   133,   427,    -1,   427,   131,
     427,    -1,   428,    -1,   428,   251,   534,    -1,   428,   251,
     534,   568,    -1,   429,    -1,   429,   187,   429,    -1,   430,
      -1,   429,   164,   430,    -1,   429,   147,   430,    -1,   431,
      -1,   430,   182,   431,    -1,   430,   109,   431,    -1,   430,
     135,   431,    -1,   430,   148,   431,    -1,   432,    -1,   431,
     189,   432,    -1,   431,   198,   432,    -1,   433,    -1,   432,
     139,   433,    -1,   432,   126,   433,    -1,   434,    -1,   434,
      68,   220,   500,    -1,   435,    -1,   435,   188,    86,   500,
      -1,   436,    -1,   436,    93,    86,   498,    -1,   437,    -1,
     437,    94,    86,   498,    -1,   439,    -1,   438,   439,    -1,
     164,    -1,   147,    -1,   438,   164,    -1,   438,   147,    -1,
     442,    -1,   446,    -1,   443,    -1,   191,    -1,   196,    -1,
     195,    -1,   194,    -1,   193,    -1,   192,    -1,   140,    -1,
     167,    -1,   130,    -1,    28,   142,   375,   172,    -1,    28,
     211,   142,   375,   172,    -1,    28,   210,   142,   375,   172,
      -1,    28,    86,   514,   142,   375,   172,    -1,   444,   142,
     172,    -1,   444,   142,   375,   172,    -1,   445,    -1,   444,
     445,    -1,   165,   531,    15,    -1,   165,    16,    -1,   447,
      -1,   447,   448,    -1,   181,   448,    -1,   448,    -1,   180,
      -1,   449,    -1,   449,   180,   448,    -1,   449,   181,   448,
      -1,   450,    -1,   459,    -1,   451,    -1,   451,   460,    -1,
     454,    -1,   454,   460,    -1,   452,   456,    -1,   453,    -1,
      97,    -1,   106,    -1,    90,    -1,   178,    -1,   107,    -1,
     129,    -1,   128,    -1,   456,    -1,    91,   456,    -1,   455,
     456,    -1,   112,    -1,   161,    -1,    82,    -1,   169,    -1,
     168,    -1,    83,    -1,   504,    -1,   457,    -1,   531,    -1,
     458,    -1,   182,    -1,    10,    -1,    17,    -1,   462,    -1,
     462,   460,    -1,   461,    -1,   460,   461,    -1,   143,   375,
     173,    -1,   463,    -1,   465,    -1,   466,    -1,   467,    -1,
     470,    -1,   472,    -1,   468,    -1,   469,    -1,   464,    -1,
     516,    -1,   102,    -1,   138,    -1,   114,    -1,   110,   531,
      -1,   145,   175,    -1,   145,   375,   175,    -1,   111,    -1,
     157,   142,   375,   172,    -1,   190,   142,   375,   172,    -1,
     531,   145,   175,    -1,   531,   145,   471,   175,    -1,   378,
      -1,   471,    99,   378,    -1,   473,    -1,   491,    -1,   474,
      -1,   488,    -1,   489,    -1,   146,   531,   478,   120,    -1,
     146,   531,   476,   478,   120,    -1,   146,   531,   478,   185,
     183,   531,   478,   185,    -1,   146,   531,   478,   185,   475,
     183,   531,   478,   185,    -1,   146,   531,   476,   478,   185,
     183,   531,   478,   185,    -1,   146,   531,   476,   478,   185,
     475,   183,   531,   478,   185,    -1,   486,    -1,   475,   486,
      -1,   477,    -1,   476,   477,    -1,    27,   531,   478,   122,
     478,   479,    -1,    -1,    27,    -1,   171,   480,   171,    -1,
      85,   482,    85,    -1,    -1,   481,    -1,   124,    -1,   484,
      -1,   481,   124,    -1,   481,   484,    -1,    -1,   483,    -1,
     123,    -1,   485,    -1,   483,   123,    -1,   483,   485,    -1,
      19,    -1,   487,    -1,     4,    -1,   487,    -1,   473,    -1,
       9,    -1,   490,    -1,   487,    -1,     8,    -1,   113,    -1,
     115,    -1,   372,    -1,   201,    21,   202,    -1,   201,   202,
      -1,   162,   530,   163,    -1,   162,   530,     7,    -1,    95,
       6,    -1,   492,    -1,   493,    -1,   494,    -1,   495,    -1,
     496,    -1,   497,    -1,    31,   142,   375,   172,    -1,    30,
     531,   142,   172,    -1,    30,   531,   142,   375,   172,    -1,
      30,   142,   375,   172,   142,   172,    -1,    30,   142,   375,
     172,   142,   375,   172,    -1,    89,   531,   142,   172,    -1,
      89,   531,   142,   375,   172,    -1,    89,   142,   375,   172,
     142,   172,    -1,    89,   142,   375,   172,   142,   375,   172,
      -1,    32,   142,   375,   172,    -1,    33,   142,   375,   172,
      -1,    42,   530,   142,   172,    -1,    42,   530,   142,   375,
     172,    -1,    42,   142,   375,   172,   142,   172,    -1,    42,
     142,   375,   172,   142,   375,   172,    -1,   503,    -1,   503,
     134,    -1,    86,   500,    -1,   502,    -1,   502,   501,    -1,
     199,   145,   175,    -1,   134,    -1,   182,    -1,   164,    -1,
     503,    -1,   504,    -1,   141,   145,   175,    -1,   531,    -1,
     506,    -1,   512,    -1,   510,    -1,   513,    -1,   511,    -1,
     509,    -1,   508,    -1,   507,    -1,   505,    -1,   214,   145,
     175,    -1,    66,   145,   175,    -1,    66,   145,   512,   175,
      -1,    66,   145,   513,   175,    -1,    32,   145,   175,    -1,
      33,   145,   175,    -1,    42,   145,   175,    -1,    42,   145,
     530,   175,    -1,    42,   145,    20,   175,    -1,    89,   145,
     175,    -1,    89,   145,   531,   175,    -1,    89,   145,   531,
      99,   514,   175,    -1,    89,   145,   182,   175,    -1,    89,
     145,   182,    99,   514,   175,    -1,   177,   531,   175,    -1,
      30,   145,   175,    -1,    30,   145,   531,   175,    -1,    30,
     145,   531,    99,   514,   175,    -1,    30,   145,   531,    99,
     515,   175,    -1,    30,   145,   182,   175,    -1,    30,   145,
     182,    99,   514,   175,    -1,    30,   145,   182,    99,   515,
     175,    -1,    65,   145,   531,   175,    -1,   531,    -1,   531,
     134,    -1,    20,    -1,    25,   209,   210,    -1,    25,   209,
     211,    -1,    25,   209,   212,    -1,   215,   214,   378,   222,
     378,    -1,   215,   214,   378,    86,   221,   222,   378,    -1,
     215,   214,   378,    86,   223,   222,   378,    -1,   215,   214,
     378,   207,   378,    -1,   215,   214,   378,   208,   378,    -1,
     215,   216,   378,   222,   378,    -1,   215,   216,   378,    86,
     221,   222,   378,    -1,   215,   216,   378,    86,   223,   222,
     378,    -1,   215,   216,   378,   207,   378,    -1,   215,   216,
     378,   208,   378,    -1,   213,   214,   378,    -1,   213,   216,
     378,    -1,   218,   214,   378,   226,   378,    -1,   218,   219,
     220,   214,   378,   226,   378,    -1,   217,   214,   378,    86,
     378,    -1,   225,   110,   523,   224,   378,   174,   378,    -1,
     524,    -1,   523,    99,   110,   524,    -1,   531,   132,   378,
      -1,   234,   142,   378,   172,   526,    -1,   527,    -1,   526,
     527,    -1,   235,   528,   373,    -1,   235,   528,   145,   110,
     531,   175,   373,    -1,   235,   528,   145,   110,   531,    99,
     110,   531,   175,   373,    -1,   235,   528,   145,   110,   531,
      99,   110,   531,    99,   110,   531,   175,   373,    -1,   457,
      -1,   528,   198,   457,    -1,    20,    -1,    14,    -1,   531,
      -1,    18,    -1,   532,    -1,   203,    -1,   117,    -1,    89,
      -1,    33,    -1,    66,    -1,    30,    -1,   141,    -1,    40,
      -1,   214,    -1,    42,    -1,    69,    -1,    65,    -1,    32,
      -1,    29,    -1,   199,    -1,    70,    -1,   240,    -1,    64,
      -1,   211,    -1,   210,    -1,   135,    -1,    31,    -1,   252,
      -1,   239,    -1,   242,    -1,   241,    -1,   269,    -1,   270,
      -1,   273,    -1,   271,    -1,   274,    -1,   245,    -1,   247,
      -1,    47,    -1,   206,    -1,   246,    -1,    43,    -1,   212,
      -1,   225,    -1,   219,    -1,   191,    -1,   196,    -1,   195,
      -1,   194,    -1,   193,    -1,   192,    -1,    88,    -1,   103,
      -1,   104,    -1,   174,    -1,    54,    -1,    55,    -1,    56,
      -1,    57,    -1,    58,    -1,    59,    -1,    60,    -1,    61,
      -1,    62,    -1,   136,    -1,    51,    -1,   200,    -1,   159,
      -1,   160,    -1,   158,    -1,    45,    -1,    87,    -1,   108,
      -1,   118,    -1,   119,    -1,    98,    -1,    44,    -1,   125,
      -1,   176,    -1,    92,    -1,    86,    -1,   186,    -1,   116,
      -1,   156,    -1,    84,    -1,    68,    -1,   220,    -1,    93,
      -1,   187,    -1,   109,    -1,   148,    -1,   189,    -1,   139,
      -1,   126,    -1,    28,    -1,    94,    -1,   188,    -1,   140,
      -1,   170,    -1,   184,    -1,   149,    -1,   127,    -1,   121,
      -1,   155,    -1,   137,    -1,   154,    -1,    25,    -1,    52,
      -1,    63,    -1,   105,    -1,    67,    -1,    46,    -1,   204,
      -1,    41,    -1,    48,    -1,    26,    -1,    34,    -1,   262,
      -1,   251,    -1,   267,    -1,   268,    -1,   244,    -1,   257,
      -1,   265,    -1,   261,    -1,   243,    -1,   256,    -1,   266,
      -1,   260,    -1,   255,    -1,   254,    -1,   238,    -1,   237,
      -1,   259,    -1,   248,    -1,   249,    -1,   272,    -1,   264,
      -1,   263,    -1,   258,    -1,   218,    -1,   224,    -1,   221,
      -1,   215,    -1,   208,    -1,   207,    -1,   209,    -1,   226,
      -1,   216,    -1,   217,    -1,   223,    -1,   213,    -1,   222,
      -1,    39,    -1,    36,    -1,    35,    -1,    37,    -1,    38,
      -1,   157,    -1,   190,    -1,   227,    -1,   228,    -1,   229,
      -1,   231,    -1,   233,    -1,   230,    -1,   232,    -1,   234,
      -1,   235,    -1,    53,    -1,   236,    -1,    50,    -1,   287,
      -1,   285,    -1,   286,    -1,   290,    -1,   288,    -1,   289,
      -1,    71,    -1,    72,    -1,    73,    -1,    74,    -1,    75,
      -1,    76,    -1,    77,    -1,    78,    -1,    79,    -1,    80,
      -1,    81,    -1,   276,    -1,   275,    -1,   277,    -1,   278,
      -1,   279,    -1,   280,    -1,   281,    -1,   282,    -1,   283,
      -1,   284,    -1,   236,   110,   397,    53,   142,   378,   172,
      -1,    53,   142,   378,   172,    -1,   536,    -1,   536,   535,
      -1,   536,   267,   428,    -1,   536,   535,   267,   428,    -1,
     545,    -1,   543,    -1,   535,   545,    -1,   535,   543,    -1,
     537,    -1,   536,   253,   537,    -1,   538,    -1,   537,   250,
     538,    -1,   539,    -1,   538,   252,   136,   539,    -1,   540,
      -1,   252,   540,    -1,   541,    -1,   541,   564,    -1,   145,
     534,   175,    -1,   542,    -1,   542,   560,    -1,   463,    -1,
     142,   375,   172,    -1,   544,    -1,   563,    -1,   562,    -1,
     565,    -1,   559,    -1,   157,    -1,   546,    -1,   547,    -1,
     548,    -1,   549,    -1,   552,    -1,   557,    -1,   558,    -1,
     256,    -1,   266,    -1,    92,   239,    -1,    92,   242,    -1,
     226,   241,    -1,   269,   241,    -1,   241,   239,    -1,   241,
     242,    -1,   226,   270,    -1,   269,   270,    -1,   226,   273,
     551,    -1,   226,   273,   105,    -1,   226,   273,   145,   551,
     175,    -1,   226,   273,   145,   551,    99,   550,   175,    -1,
     226,   273,   145,   105,   175,    -1,   226,   273,   145,   105,
      99,   550,   175,    -1,   269,   273,    -1,   551,    -1,   550,
      99,   551,    -1,    88,    20,    -1,    88,    20,   260,    20,
      -1,    88,    20,   561,   255,    -1,    88,    20,   260,    20,
     561,   255,    -1,   226,   271,   272,   554,    -1,   226,   271,
     272,   554,   553,    -1,   226,   105,   271,   272,    -1,   226,
     105,   271,   272,   553,    -1,   269,   271,   272,    -1,   556,
      -1,   553,   556,    -1,    88,    20,    -1,   145,   555,   175,
      -1,    20,    -1,   555,    20,    -1,   189,   554,    -1,   126,
     554,    -1,   254,    20,    -1,   226,   274,    -1,   269,   274,
      -1,    88,   206,    -1,    88,   246,    -1,   245,   247,    -1,
     238,    -1,   238,    47,    -1,   237,    -1,   237,   272,    -1,
     259,    -1,   248,   431,    -1,    88,   119,   431,    -1,    88,
      43,   431,    -1,   249,   431,   187,   431,    -1,   244,   561,
     566,    -1,   268,   431,   566,    -1,   257,   561,   265,    -1,
     261,   567,    -1,   243,   567,    -1,   272,    -1,   264,    -1,
     258,    -1,   263,    -1,   258,    -1,   269,   247,   431,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    13,    15,    18,    20,
      23,    28,    35,    38,    40,    42,    45,    52,    54,    57,
      64,    67,    70,    75,    77,    81,    83,    87,    89,    91,
      93,    95,    97,    99,   101,   103,   105,   107,   109,   111,
     116,   121,   123,   126,   130,   132,   134,   136,   138,   140,
     142,   144,   146,   148,   150,   152,   154,   156,   158,   160,
     162,   164,   166,   168,   170,   176,   180,   184,   190,   196,
     201,   205,   209,   213,   219,   225,   231,   237,   243,   249,
     254,   258,   262,   267,   273,   280,   282,   286,   290,   294,
     298,   305,   311,   320,   324,   331,   337,   346,   351,   355,
     357,   359,   361,   364,   367,   370,   374,   380,   385,   392,
     396,   402,   407,   414,   419,   426,   432,   440,   443,   446,
     449,   452,   455,   458,   468,   470,   473,   477,   479,   482,
     485,   486,   488,   490,   493,   497,   499,   502,   505,   509,
     513,   517,   520,   524,   529,   535,   538,   543,   547,   548,
     552,   555,   557,   561,   567,   571,   577,   580,   583,   586,
     590,   594,   596,   599,   602,   605,   610,   615,   620,   625,
     627,   631,   634,   638,   642,   646,   648,   650,   653,   655,
     659,   661,   665,   667,   669,   671,   673,   675,   677,   679,
     681,   683,   685,   687,   689,   691,   693,   695,   697,   699,
     702,   705,   708,   711,   713,   715,   718,   723,   727,   733,
     738,   742,   744,   746,   748,   750,   752,   754,   756,   758,
     760,   763,   766,   770,   773,   775,   780,   784,   789,   794,
     800,   805,   811,   817,   824,   828,   832,   836,   838,   843,
     845,   850,   854,   859,   864,   870,   875,   881,   883,   886,
     890,   892,   895,   897,   904,   908,   912,   914,   917,   921,
     923,   927,   930,   934,   937,   941,   946,   948,   952,   954,
     957,   959,   961,   963,   966,   969,   972,   976,   978,   980,
     983,   986,   989,   995,  1001,  1003,  1008,  1012,  1017,  1026,
    1037,  1039,  1042,  1047,  1055,  1064,  1066,  1070,  1072,  1076,
    1078,  1082,  1086,  1090,  1094,  1095,  1100,  1104,  1108,  1112,
    1114,  1118,  1123,  1125,  1129,  1131,  1135,  1139,  1141,  1145,
    1149,  1153,  1157,  1159,  1163,  1167,  1169,  1173,  1177,  1179,
    1184,  1186,  1191,  1193,  1198,  1200,  1205,  1207,  1210,  1212,
    1214,  1217,  1220,  1222,  1224,  1226,  1228,  1230,  1232,  1234,
    1236,  1238,  1240,  1242,  1244,  1249,  1255,  1261,  1268,  1272,
    1277,  1279,  1282,  1286,  1289,  1291,  1294,  1297,  1299,  1301,
    1303,  1307,  1311,  1313,  1315,  1317,  1320,  1322,  1325,  1328,
    1330,  1332,  1334,  1336,  1338,  1340,  1342,  1344,  1346,  1349,
    1352,  1354,  1356,  1358,  1360,  1362,  1364,  1366,  1368,  1370,
    1372,  1374,  1376,  1378,  1380,  1383,  1385,  1388,  1392,  1394,
    1396,  1398,  1400,  1402,  1404,  1406,  1408,  1410,  1412,  1414,
    1416,  1418,  1421,  1424,  1428,  1430,  1435,  1440,  1444,  1449,
    1451,  1455,  1457,  1459,  1461,  1463,  1465,  1470,  1476,  1485,
    1495,  1505,  1516,  1518,  1521,  1523,  1526,  1533,  1534,  1536,
    1540,  1544,  1545,  1547,  1549,  1551,  1554,  1557,  1558,  1560,
    1562,  1564,  1567,  1570,  1572,  1574,  1576,  1578,  1580,  1582,
    1584,  1586,  1588,  1590,  1592,  1594,  1598,  1601,  1605,  1609,
    1612,  1614,  1616,  1618,  1620,  1622,  1624,  1629,  1634,  1640,
    1647,  1655,  1660,  1666,  1673,  1681,  1686,  1691,  1696,  1702,
    1709,  1717,  1719,  1722,  1725,  1727,  1730,  1734,  1736,  1738,
    1740,  1742,  1744,  1748,  1750,  1752,  1754,  1756,  1758,  1760,
    1762,  1764,  1766,  1768,  1772,  1776,  1781,  1786,  1790,  1794,
    1798,  1803,  1808,  1812,  1817,  1824,  1829,  1836,  1840,  1844,
    1849,  1856,  1863,  1868,  1875,  1882,  1887,  1889,  1892,  1894,
    1898,  1902,  1906,  1912,  1920,  1928,  1934,  1940,  1946,  1954,
    1962,  1968,  1974,  1978,  1982,  1988,  1996,  2002,  2010,  2012,
    2017,  2021,  2027,  2029,  2032,  2036,  2044,  2055,  2069,  2071,
    2075,  2077,  2079,  2081,  2083,  2085,  2087,  2089,  2091,  2093,
    2095,  2097,  2099,  2101,  2103,  2105,  2107,  2109,  2111,  2113,
    2115,  2117,  2119,  2121,  2123,  2125,  2127,  2129,  2131,  2133,
    2135,  2137,  2139,  2141,  2143,  2145,  2147,  2149,  2151,  2153,
    2155,  2157,  2159,  2161,  2163,  2165,  2167,  2169,  2171,  2173,
    2175,  2177,  2179,  2181,  2183,  2185,  2187,  2189,  2191,  2193,
    2195,  2197,  2199,  2201,  2203,  2205,  2207,  2209,  2211,  2213,
    2215,  2217,  2219,  2221,  2223,  2225,  2227,  2229,  2231,  2233,
    2235,  2237,  2239,  2241,  2243,  2245,  2247,  2249,  2251,  2253,
    2255,  2257,  2259,  2261,  2263,  2265,  2267,  2269,  2271,  2273,
    2275,  2277,  2279,  2281,  2283,  2285,  2287,  2289,  2291,  2293,
    2295,  2297,  2299,  2301,  2303,  2305,  2307,  2309,  2311,  2313,
    2315,  2317,  2319,  2321,  2323,  2325,  2327,  2329,  2331,  2333,
    2335,  2337,  2339,  2341,  2343,  2345,  2347,  2349,  2351,  2353,
    2355,  2357,  2359,  2361,  2363,  2365,  2367,  2369,  2371,  2373,
    2375,  2377,  2379,  2381,  2383,  2385,  2387,  2389,  2391,  2393,
    2395,  2397,  2399,  2401,  2403,  2405,  2407,  2409,  2411,  2413,
    2415,  2417,  2419,  2421,  2423,  2425,  2427,  2429,  2431,  2433,
    2435,  2437,  2439,  2441,  2443,  2445,  2447,  2449,  2451,  2453,
    2455,  2457,  2459,  2461,  2463,  2465,  2467,  2469,  2471,  2473,
    2481,  2486,  2488,  2491,  2495,  2500,  2502,  2504,  2507,  2510,
    2512,  2516,  2518,  2522,  2524,  2529,  2531,  2534,  2536,  2539,
    2543,  2545,  2548,  2550,  2554,  2556,  2558,  2560,  2562,  2564,
    2566,  2568,  2570,  2572,  2574,  2576,  2578,  2580,  2582,  2584,
    2587,  2590,  2593,  2596,  2599,  2602,  2605,  2608,  2612,  2616,
    2622,  2630,  2636,  2644,  2647,  2649,  2653,  2656,  2661,  2666,
    2673,  2678,  2684,  2689,  2695,  2699,  2701,  2704,  2707,  2711,
    2713,  2716,  2719,  2722,  2725,  2728,  2731,  2734,  2737,  2740,
    2742,  2745,  2747,  2750,  2752,  2755,  2759,  2763,  2768,  2772,
    2776,  2780,  2783,  2786,  2788,  2790,  2792,  2794,  2796
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   909,   909,   910,   920,   925,   931,   936,   942,   947,
     959,   964,   974,   981,   993,   999,  1011,  1024,  1030,  1042,
    1053,  1057,  1061,  1073,  1079,  1093,  1099,  1113,  1114,  1115,
    1116,  1122,  1123,  1124,  1125,  1128,  1131,  1134,  1136,  1142,
    1147,  1156,  1162,  1171,  1180,  1181,  1182,  1183,  1184,  1185,
    1186,  1187,  1188,  1189,  1196,  1197,  1198,  1199,  1200,  1201,
    1202,  1205,  1212,  1213,  1225,  1237,  1242,  1253,  1259,  1271,
    1284,  1295,  1300,  1312,  1317,  1328,  1334,  1340,  1346,  1365,
    1376,  1387,  1394,  1401,  1408,  1421,  1427,  1442,  1446,  1456,
    1463,  1471,  1478,  1486,  1493,  1501,  1508,  1521,  1528,  1534,
    1541,  1547,  1551,  1558,  1569,  1574,  1583,  1592,  1599,  1609,
    1616,  1623,  1631,  1639,  1647,  1655,  1663,  1674,  1678,  1682,
    1686,  1694,  1698,  1706,  1718,  1723,  1730,  1737,  1742,  1749,
    1756,  1760,  1765,  1773,  1779,  1788,  1793,  1800,  1807,  1820,
    1825,  1837,  1841,  1845,  1849,  1856,  1863,  1889,  1899,  1905,
    1911,  1920,  1930,  1943,  1951,  1958,  1972,  1976,  1983,  1988,
    1995,  2003,  2007,  2011,  2019,  2026,  2035,  2047,  2056,  2069,
    2077,  2091,  2098,  2111,  2119,  2130,  2145,  2149,  2165,  2169,
    2178,  2182,  2199,  2200,  2201,  2202,  2203,  2206,  2207,  2208,
    2209,  2210,  2212,  2213,  2216,  2217,  2218,  2219,  2220,  2227,
    2240,  2247,  2251,  2259,  2263,  2267,  2274,  2278,  2285,  2293,
    2304,  2314,  2315,  2316,  2320,  2320,  2320,  2320,  2320,  2323,
    2329,  2338,  2342,  2352,  2363,  2369,  2383,  2391,  2400,  2410,
    2421,  2430,  2440,  2450,  2466,  2479,  2491,  2503,  2509,  2521,
    2527,  2541,  2550,  2560,  2569,  2582,  2589,  2600,  2601,  2606,
    2615,  2619,  2624,  2628,  2634,  2639,  2647,  2663,  2671,  2678,
    2684,  2695,  2702,  2712,  2722,  2727,  2739,  2745,  2759,  2765,
    2777,  2784,  2791,  2798,  2805,  2812,  2819,  2832,  2836,  2846,
    2850,  2860,  2871,  2878,  2891,  2898,  2910,  2917,  2931,  2938,
    2953,  2959,  2971,  2977,  2991,  3002,  3006,  3017,  3021,  3040,
    3044,  3052,  3060,  3068,  3076,  3076,  3084,  3092,  3100,  3114,
    3118,  3125,  3138,  3142,  3153,  3157,  3161,  3171,  3175,  3179,
    3183,  3187,  3197,  3201,  3206,  3217,  3221,  3225,  3235,  3239,
    3251,  3255,  3267,  3271,  3283,  3287,  3299,  3303,  3315,  3319,
    3323,  3327,  3339,  3343,  3347,  3357,  3361,  3365,  3369,  3373,
    3377,  3387,  3391,  3395,  3405,  3409,  3413,  3417,  3429,  3435,
    3447,  3453,  3467,  3474,  3515,  3519,  3523,  3527,  3539,  3549,
    3560,  3565,  3575,  3579,  3589,  3595,  3601,  3607,  3619,  3625,
    3636,  3640,  3644,  3648,  3652,  3656,  3660,  3670,  3674,  3684,
    3688,  3699,  3703,  3707,  3711,  3715,  3730,  3734,  3744,  3748,
    3758,  3765,  3772,  3785,  3789,  3801,  3807,  3821,  3832,  3836,
    3840,  3844,  3848,  3852,  3856,  3860,  3870,  3874,  3884,  3889,
    3894,  3905,  3916,  3920,  3931,  3941,  3952,  4008,  4014,  4026,
    4032,  4044,  4048,  4058,  4062,  4066,  4076,  4084,  4092,  4100,
    4108,  4116,  4131,  4137,  4149,  4155,  4168,  4177,  4179,  4185,
    4190,  4202,  4205,  4212,  4218,  4224,  4232,  4247,  4250,  4257,
    4263,  4269,  4277,  4291,  4296,  4307,  4312,  4323,  4328,  4333,
    4339,  4351,  4357,  4362,  4367,  4378,  4383,  4398,  4403,  4420,
    4435,  4439,  4443,  4447,  4451,  4455,  4465,  4476,  4482,  4488,
    4493,  4515,  4521,  4527,  4532,  4543,  4553,  4563,  4569,  4575,
    4580,  4591,  4597,  4609,  4620,  4626,  4632,  4669,  4674,  4679,
    4690,  4694,  4698,  4708,  4719,  4723,  4727,  4731,  4735,  4739,
    4743,  4747,  4751,  4761,  4771,  4775,  4780,  4791,  4801,  4811,
    4815,  4819,  4829,  4835,  4841,  4847,  4853,  4865,  4876,  4883,
    4890,  4897,  4904,  4911,  4918,  4931,  4952,  4959,  4979,  5019,
    5023,  5027,  5036,  5042,  5048,  5054,  5060,  5067,  5073,  5079,
    5085,  5091,  5103,  5108,  5118,  5124,  5136,  5162,  5173,  5179,
    5192,  5207,  5214,  5220,  5231,  5238,  5248,  5259,  5275,  5281,
    5291,  5300,  5301,  5319,  5323,  5330,  5331,  5332,  5333,  5334,
    5335,  5336,  5337,  5338,  5339,  5340,  5341,  5342,  5343,  5344,
    5345,  5346,  5347,  5348,  5349,  5350,  5351,  5352,  5353,  5354,
    5355,  5356,  5357,  5358,  5359,  5360,  5361,  5362,  5363,  5364,
    5365,  5366,  5367,  5368,  5369,  5370,  5371,  5372,  5373,  5374,
    5375,  5376,  5377,  5378,  5379,  5380,  5381,  5382,  5383,  5384,
    5385,  5386,  5387,  5388,  5389,  5390,  5391,  5392,  5393,  5394,
    5395,  5396,  5397,  5398,  5399,  5400,  5401,  5402,  5403,  5404,
    5405,  5406,  5407,  5408,  5409,  5410,  5411,  5412,  5413,  5414,
    5415,  5416,  5417,  5418,  5419,  5420,  5421,  5422,  5423,  5424,
    5425,  5426,  5427,  5428,  5429,  5430,  5431,  5432,  5433,  5434,
    5435,  5436,  5437,  5438,  5439,  5440,  5441,  5442,  5443,  5444,
    5445,  5446,  5447,  5448,  5449,  5450,  5451,  5452,  5453,  5454,
    5455,  5456,  5457,  5458,  5459,  5460,  5461,  5462,  5463,  5464,
    5465,  5466,  5467,  5468,  5469,  5470,  5471,  5472,  5473,  5474,
    5475,  5476,  5477,  5478,  5479,  5480,  5481,  5482,  5483,  5484,
    5485,  5486,  5487,  5488,  5489,  5490,  5491,  5492,  5493,  5494,
    5495,  5496,  5497,  5498,  5499,  5500,  5501,  5502,  5503,  5504,
    5505,  5506,  5507,  5508,  5509,  5510,  5511,  5512,  5513,  5514,
    5515,  5516,  5517,  5518,  5519,  5520,  5521,  5522,  5523,  5534,
    5540,  5557,  5561,  5565,  5569,  5579,  5582,  5585,  5588,  5597,
    5600,  5609,  5612,  5621,  5624,  5633,  5636,  5645,  5648,  5651,
    5660,  5663,  5672,  5676,  5686,  5689,  5692,  5695,  5698,  5707,
    5716,  5720,  5724,  5728,  5732,  5736,  5740,  5750,  5753,  5756,
    5759,  5768,  5771,  5774,  5777,  5786,  5789,  5798,  5801,  5804,
    5807,  5810,  5813,  5816,  5825,  5828,  5837,  5840,  5843,  5846,
    5855,  5858,  5861,  5864,  5867,  5876,  5879,  5888,  5891,  5900,
    5903,  5912,  5915,  5924,  5933,  5936,  5945,  5948,  5951,  5960,
    5963,  5966,  5969,  5972,  5981,  5985,  5989,  5993,  6003,  6012,
    6022,  6031,  6034,  6043,  6046,  6049,  6058,  6061,  6070
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
	       << " (line " << yylno << "):" << std::endl;
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
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 10067;
  const int xquery_parser::yynnts_ = 263;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 498;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 306;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 560;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 13891 "/root/zorba/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6078 "/root/zorba/src/compiler/parser/xquery_parser.y"


namespace zorba {

namespace parser {

const char *the_tumbling = "tumbling", *the_sliding = "sliding",
  *the_start = "start", *the_end = "end", *the_only_end = "only end",
  *the_ofor = "ofor", *the_declare = "declare", *the_create = "create";

}

/*
	The error member function registers the errors to the driver.
*/

void xquery_parser::error(zorba::xquery_parser::location_type const& loc, std::string const& msg)
{
  driver.set_expr (new ParseErrorNode (driver.createQueryLoc (loc), XPST0003, msg));
}

}


#if 0
static void print_token_value(FILE *file, int type, YYSTYPE value)
{
	if (type==VAR) {
		fprintf (file, "%s", value.tptr->name);
	}
	else if (type==NUM) {
		fprintf (file, "%d", value.val);
	}
}
#endif

