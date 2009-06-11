
/* A Bison parser, made by GNU Bison 2.4.  */

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
#line 45 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"


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
#line 75 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 870 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc  */
#line 92 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 161 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
        case 109: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 754 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 268 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 121: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 753 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 277 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 145: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 752 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 286 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 295 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 304 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 313 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 322 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 331 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 340 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 349 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 358 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 367 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 376 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair_vector); };

/* Line 480 of lalr1.cc  */
#line 385 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair); };

/* Line 480 of lalr1.cc  */
#line 394 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 403 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 412 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 421 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 430 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 439 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 448 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 457 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 466 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 475 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 484 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 493 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 502 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 511 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 520 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 529 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 538 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 547 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 556 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 565 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 574 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 583 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 592 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "IndexDecl2" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 601 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "IndexDecl3" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 610 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "IndexDeclSuffix" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 619 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "IndexField" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 628 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "IndexField1" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 637 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "IndexFieldList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 646 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 655 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 664 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 673 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 682 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 691 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 700 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 709 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 718 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 727 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 736 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 745 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "IndexStatement" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 754 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 763 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 772 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 781 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 790 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 799 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 808 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 817 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 826 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 835 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 844 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 853 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 862 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 880 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 889 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 898 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 907 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 916 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 925 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 934 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 943 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 952 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 961 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 970 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 979 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 988 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 997 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1006 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1015 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1024 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1033 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1042 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1051 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1060 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1069 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1078 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1087 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1096 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1105 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1114 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1123 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1132 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1141 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1150 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1159 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1168 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1177 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1186 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1195 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1204 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1213 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1222 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1231 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1240 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1249 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1258 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1267 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1276 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1285 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1294 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1303 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1312 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1321 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1330 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1339 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1348 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1357 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1366 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1375 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1384 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1393 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1402 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "PragmaList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1411 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1420 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1429 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1438 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1447 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1456 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1465 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1474 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1483 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1492 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1501 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1510 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1519 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1528 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1537 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1546 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1555 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1564 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1573 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1582 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1591 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1600 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1609 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1618 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1627 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1636 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1645 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1654 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1663 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1672 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1681 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1690 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1699 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1708 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "Opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1717 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1726 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "Opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1735 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1744 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1753 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1762 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1771 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1780 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1789 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1798 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1807 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1816 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1825 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1834 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1843 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1852 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1861 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1870 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1879 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1888 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1897 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1906 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1915 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1924 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1933 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1942 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1951 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1960 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1969 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1978 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1987 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1996 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2005 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2014 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2023 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2032 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2041 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2050 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2059 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2068 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2077 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2086 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2095 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2104 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2113 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2122 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2131 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2140 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2149 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
#line 94 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 553 of lalr1.cc  */
#line 2234 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 888 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 898 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 903 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 909 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 914 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 926 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 931 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 941 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 948 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 960 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 972 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), 
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
		}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 984 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 990 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 996 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1008 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1014 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1028 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1034 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 1074 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 1079 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), (yysemantic_stack_[(4) - (4)].pair_vector)); 
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 1087 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.pair_vector) = new std::vector<std::pair<std::string, std::string> > ();
      (yyval.pair_vector)->push_back(*(yysemantic_stack_[(1) - (1)].pair));
      delete (yysemantic_stack_[(1) - (1)].pair);
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1093 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].pair_vector)->push_back(*(yysemantic_stack_[(2) - (2)].pair));
      delete (yysemantic_stack_[(2) - (2)].pair);
      (yyval.pair_vector) = (yysemantic_stack_[(2) - (1)].pair_vector);
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1102 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *s = static_cast<StringLiteral *>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.pair) = new std::pair<std::string, std::string>((yysemantic_stack_[(3) - (1)].strval), s->get_strval());
      delete s;
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1110 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1111 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1112 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1113 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1114 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1115 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1116 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1117 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1118 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1119 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1156 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1168 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		}
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1173 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		}
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1184 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1190 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1202 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1215 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1226 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1231 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1243 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1248 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1259 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1265 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1271 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1277 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1296 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1307 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1318 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1325 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1332 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1339 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1352 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1358 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1373 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1377 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1387 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		}
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1393 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (6)].sval)),
								NULL);
		}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1400 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		}
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1406 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(8) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
		}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1418 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1425 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1431 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1438 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1444 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1448 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1455 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1466 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (SYMTAB ((yysemantic_stack_[(2) - (2)].sval)), NULL);
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1470 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
                               dynamic_cast<SequenceType *> ((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1478 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(5) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								nt->name,
								nt->type,
								(yysemantic_stack_[(5) - (5)].expr));
      delete nt;
		}
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1487 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(4) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      delete nt;
		}
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1494 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(6) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      delete nt;
		}
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1504 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "hash"; }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1506 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "btree"; }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1513 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->create = false;
      (yyval.node) = d;
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1521 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1525 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node))->uniq = true;
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1533 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1537 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node))->method = (yysemantic_stack_[(2) - (1)].strval);
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1545 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(7) - (2)].sval)), (yysemantic_stack_[(7) - (4)].expr), "",
                          dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(7) - (6)].node)));
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1553 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1557 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (1)].node))->coll = SYMTAB ((yysemantic_stack_[(3) - (3)].sval));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1565 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1569 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<SequenceType *> ((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1576 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexFieldList *l = new IndexFieldList (LOC ((yyloc)));
      l->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
      
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1583 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(3) - (1)].node))->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1593 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		}
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1598 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		}
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1610 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1614 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1618 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1622 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1629 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1636 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      if ((yysemantic_stack_[(4) - (2)].node) == NULL)
        (yyval.expr) = (yysemantic_stack_[(4) - (3)].expr);
      else {
        BlockBody *b = dynamic_cast<BlockBody *> ((yysemantic_stack_[(4) - (3)].expr));
        VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(4) - (2)].node));
        if (b == NULL) {
          b = new BlockBody ((yysemantic_stack_[(4) - (3)].expr)->get_location (), vfo);
          b->add ((yysemantic_stack_[(4) - (3)].expr));
        } else {
          b->set_decls (vfo);
        }
        (yyval.expr) = b;
      }
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1655 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      VFO_DeclList *vfo2 = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (2)].node));
      if ((yysemantic_stack_[(3) - (1)].node) == NULL)
        vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back (*vfo2);
      (yyval.node) = vfo;
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1664 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1671 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      vfo->push_back ((yysemantic_stack_[(3) - (3)].node));
      (yyval.node) = vfo;
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1677 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back ((yysemantic_stack_[(2) - (2)].node));
      (yyval.node) = vfo;
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1686 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(1) - (1)].varnametype);
      VarDecl *vd = new VarDecl(LOC ((yyloc)),
                       nt->name,
                       nt->type,
                       NULL);
      vd->set_global (false);
			(yyval.node) = vd;
      delete nt;
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1697 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(3) - (1)].varnametype);
      VarDecl *vd = new VarDecl(LOC ((yyloc)),
                       nt->name,
                       nt->type,
                       (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global (false);
			(yyval.node) = vd;
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1710 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(5) - (3)].sval)), (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1717 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1724 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *b = dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr));
      if (b == NULL) {
        b = new BlockBody ((yysemantic_stack_[(5) - (5)].expr)->get_location ()); 
        b->add ((yysemantic_stack_[(5) - (5)].expr));
      }
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), b);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1736 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1740 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1747 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::create_stmt);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1751 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::drop_stmt);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1755 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::build_stmt);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1762 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1766 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->deterministic = false;
      (yyval.node) = d;
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1772 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1779 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1783 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1787 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->type = (d->type == ParseConstants::fn_extern)
        ? ParseConstants::fn_extern_update
        : ParseConstants::fn_update;
      (yyval.node) = d;
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1795 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1802 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1811 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1823 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1837 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		}
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1845 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1859 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		}
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1865 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1877 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1885 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1896 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1907 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1911 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(2) - (2)].expr)),
        *blk2 = new BlockBody (LOC ((yyloc)));
      blk2->add ((yysemantic_stack_[(2) - (1)].expr));
      for (int i = 0; i < blk->size (); i++)
        blk2->add ((*blk) [i]);
      (yyval.expr) = blk2;
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1923 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1927 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1936 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1940 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p == NULL) {
        expr_p = new Expr (LOC ((yyloc)));
        expr_p->push_back ((yysemantic_stack_[(3) - (1)].expr));
      }
      expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = expr_p;
		}
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1987 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1996 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2003 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2007 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2015 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2019 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2023 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2030 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2034 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2041 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2049 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2060 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 2078 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2084 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2093 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2097 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2107 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		}
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2118 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		}
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2124 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2138 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2145 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2153 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2162 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2172 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2180 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2189 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2198 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		}
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2213 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 2225 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 2236 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		}
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 2248 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 2254 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 2266 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2272 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 2286 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 2294 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2303 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2311 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2323 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2329 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2340 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, SYMTAB ((yysemantic_stack_[(2) - (2)].sval)), "", "");
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2344 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2352 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2356 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2365 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (6)].sval)));
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2369 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2373 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), "");
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2380 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string name = SYMTAB ((yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2395 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2403 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2410 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2416 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2427 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 SYMTAB ((yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2433 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 SYMTAB ((yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2442 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2452 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2457 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		}
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2469 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		}
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2475 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2489 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		}
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2495 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2507 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		}
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2514 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2521 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2528 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		}
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2535 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2542 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2549 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2562 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		}
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2566 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		}
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2576 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2581 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2592 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2603 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2610 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2623 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		}
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2630 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2642 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2648 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2661 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2668 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								SYMTAB ((yysemantic_stack_[(10) - (8)].sval)),
								(yysemantic_stack_[(10) - (10)].expr));
		}
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2682 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		}
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2688 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2700 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2706 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2719 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2730 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2734 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2745 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2749 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2768 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2772 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2780 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2788 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2796 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2803 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2804 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2812 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2820 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2828 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2842 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2846 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		}
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2853 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2866 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2870 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2881 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2885 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2889 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2899 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2903 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2907 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2911 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 2915 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 2925 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 2929 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 2934 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 2945 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 2949 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 2953 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 2963 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 2967 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 2979 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 2983 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 2995 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 2999 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3011 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3015 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3027 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3031 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3043 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		}
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3047 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		}
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3051 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3055 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3067 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3071 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3075 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3085 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		}
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3089 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		}
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3093 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		}
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3097 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		}
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3101 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		}
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3105 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		}
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3115 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		}
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3119 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		}
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3123 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		}
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3133 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3137 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3141 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3145 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3157 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		}
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3163 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3175 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		}
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3181 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3195 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(3) - (2)].sval))),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		}
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3201 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval))),
								"");      
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3243 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		}
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3247 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3251 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3255 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3267 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3277 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 346:

/* Line 678 of lalr1.cc  */
#line 3288 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3293 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3303 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3307 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3317 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3323 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3329 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3335 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3347 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3353 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3364 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		}
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3368 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		}
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3372 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		}
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3376 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		}
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3380 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		}
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3384 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		}
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3388 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		}
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3398 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node), false);
		}
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3402 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		}
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3412 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3416 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC((yyloc)), rev_p, NULL);
		}
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3427 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		}
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3431 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		}
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3435 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		}
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3439 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		}
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3443 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		}
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3458 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3462 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3472 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		}
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3476 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3486 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		}
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3493 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		}
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3500 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		}
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3513 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3517 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3529 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		}
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3535 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3549 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3560 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3564 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3568 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3572 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3576 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3580 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3584 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3588 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3598 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3602 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3612 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		}
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3617 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		}
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3622 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		}
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3633 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3643 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		}
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3647 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3658 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		}
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3668 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3679 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3735 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		}
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3741 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3753 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		}
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3759 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3771 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3775 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3785 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3789 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3793 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3803 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		}
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3811 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		}
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3819 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(8) - (6)].sval))),
								NULL,
								NULL);
		}
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3827 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (7)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		}
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3835 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		}
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3843 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(10) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(10) - (8)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		}
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3858 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		}
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3864 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3876 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3882 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3895 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3912 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3917 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3928 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		}
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3932 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3939 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		}
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3945 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		}
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 3951 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 3959 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 3973 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		}
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 3977 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 3984 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		}
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 3990 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 3996 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4004 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4018 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4023 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4034 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4039 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4050 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4055 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4060 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		}
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4066 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		}
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4078 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4084 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		}
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4089 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		}
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4094 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4105 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4110 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4125 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4130 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4147 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4162 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4166 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4170 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4174 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4178 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4182 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4192 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4203 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		}
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4209 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4215 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4220 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4242 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		}
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4248 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4254 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4259 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4270 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4280 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4290 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		}
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4296 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4302 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4307 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4318 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		}
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4324 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		}
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4336 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		}
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4347 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		}
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4353 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4359 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		}
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4396 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		}
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4401 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		}
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4406 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		}
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4417 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4421 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4425 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		}
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4435 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		}
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4446 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4450 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4454 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4458 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4462 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4466 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4470 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4474 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4478 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4488 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		}
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4498 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		}
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4502 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4507 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4518 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		}
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4528 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		}
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4538 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		}
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4542 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4546 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4556 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4562 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
								NULL);
		}
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4568 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4574 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4580 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4592 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval))));
		}
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4603 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		}
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4610 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
                           NULL,
                           true);
		}
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4617 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		}
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4624 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		}
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4631 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		}
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4638 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		}
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4645 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		}
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4658 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))));
		}
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4679 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		}
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4686 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (1)].sval))),
								true);
		}
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4706 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4746 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::strict_validation);
		}
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4750 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::lax_validation);
    }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4754 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::skip_validation);
    }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4763 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4769 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4775 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4781 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4787 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4794 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4800 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4806 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4812 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4818 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4830 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4835 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4845 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4851 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4863 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4889 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4900 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = new CopyVarList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		}
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4906 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		}
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4919 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4933 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4940 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4946 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4957 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(3) - (2)].name_test_list),
                          (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4964 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(7) - (2)].name_test_list),
                          SYMTAB ((yysemantic_stack_[(7) - (5)].sval)),
                          (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4973 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(10) - (2)].name_test_list),
                          SYMTAB ((yysemantic_stack_[(10) - (5)].sval)),
                          SYMTAB ((yysemantic_stack_[(10) - (8)].sval)),
                          (yysemantic_stack_[(10) - (10)].expr));
       delete (yysemantic_stack_[(10) - (2)].name_test_list);
    }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4982 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(13) - (2)].name_test_list),
                          SYMTAB ((yysemantic_stack_[(13) - (5)].sval)),
                          SYMTAB ((yysemantic_stack_[(13) - (8)].sval)),
                          SYMTAB ((yysemantic_stack_[(13) - (11)].sval)),
                          (yysemantic_stack_[(13) - (13)].expr));
       delete (yysemantic_stack_[(13) - (2)].name_test_list);
    }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4995 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list = new CatchExpr::NameTestList;
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 5001 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list =
        static_cast<CatchExpr::NameTestList *> ((yysemantic_stack_[(3) - (1)].name_test_list));
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 5021 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string tmp = SYMTAB ((yysemantic_stack_[(1) - (1)].sval));
      if (tmp.find (':') != std::string::npos) {
        error((yylocation_stack_[(1) - (1)]), "A NCName is expected, found a QName");
        YYERROR;
      }
      (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval);
    }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 5037 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5040 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5041 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5042 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5043 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5044 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5045 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5046 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5047 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5048 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5049 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5050 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5051 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5052 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5053 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5054 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5055 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5056 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5057 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5058 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5059 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5060 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5061 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5062 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5063 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5064 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5065 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5066 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5067 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5068 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5069 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5070 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5071 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5072 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5073 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5074 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5075 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5076 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5077 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5078 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5079 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5080 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5081 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5082 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5083 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5084 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5085 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5086 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5087 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5088 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5089 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5090 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5091 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5092 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5093 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5094 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5095 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5096 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5097 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5098 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5099 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5100 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5101 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5102 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5103 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5104 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5105 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5106 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5107 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5108 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5109 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5110 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5111 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5112 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5113 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5114 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5115 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5116 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5117 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5118 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5119 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5120 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5121 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5122 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5123 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5124 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5125 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5126 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5127 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5128 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5129 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5130 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5131 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5132 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5133 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5134 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5135 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5136 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5137 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5138 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5139 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5140 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5141 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5142 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5143 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5144 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5145 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5146 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5147 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5148 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5149 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5150 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5151 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5152 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5153 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5154 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5155 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5156 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5157 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5158 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5159 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5160 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5161 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5162 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5163 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5164 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5165 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5166 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5167 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5168 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5169 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5170 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5171 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5172 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5173 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5174 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5175 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5176 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5177 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5178 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5179 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5180 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5181 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5182 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5183 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5184 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5185 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5186 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5187 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5188 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5189 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5190 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5191 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5192 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5193 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5194 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5195 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5196 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5197 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5198 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5199 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5200 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5201 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5202 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5203 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5204 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5205 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5206 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5207 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("create"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5208 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("build"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5209 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5210 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5211 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("hash"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5212 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("btree"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5213 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("drop"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5214 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-format"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5215 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-separator"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5216 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("grouping-separator"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5217 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("infinity"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5218 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("minus-sign"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5219 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("NaN"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5220 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("percent"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5221 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("per-mille"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5222 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("zero-digit"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5223 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("digit"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5224 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("pattern-separator"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5236 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5242 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5259 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		}
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5263 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		}
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5267 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5271 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		}
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5281 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5284 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5287 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5290 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5299 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5302 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5311 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5314 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5323 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5326 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5335 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5338 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5347 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5350 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5353 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5362 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5365 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5374 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		}
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5378 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5388 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5391 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5394 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5397 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5400 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5409 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5418 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5422 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5426 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5430 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5434 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5438 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5442 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5452 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5455 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5458 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5461 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5470 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5473 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5476 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5479 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5488 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5491 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5500 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5503 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5506 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5509 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5512 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5515 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5518 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5527 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5530 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5539 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5542 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5545 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5548 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5557 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5560 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5563 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5566 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5569 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5578 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5581 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5590 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5593 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5602 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5605 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5614 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5617 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5626 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5635 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5638 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5647 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5650 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5653 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5662 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5665 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5668 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5671 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5674 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5683 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5687 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5691 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5695 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5705 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5714 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5724 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5733 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5736 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5745 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5748 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5751 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5760 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5763 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5772 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;



/* Line 678 of lalr1.cc  */
#line 9708 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1198;
  const short int
  xquery_parser::yypact_[] =
  {
      1376, -1198, -1198, -1198, -1198,    10,    -5,   257, -1198,   346,
     244,    41,   290,  7630,   169,   406,   430,    25, -1198, -1198,
   -1198, -1198, -1198, -1198,   316,  6560, -1198,    76,   245, -1198,
     334, -1198, -1198, -1198,   379,   390, -1198,   371,   234,   512,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,   431,
     446, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198,  7895, -1198,  6018, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,  9485, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198,   502, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,  1650,
    9485, -1198, -1198, -1198, -1198, -1198, -1198,   472, -1198, -1198,
   -1198, -1198,  7098, -1198,  7365, -1198, -1198, -1198, -1198, -1198,
    9485, -1198, -1198,  5745, -1198, -1198, -1198, -1198, -1198, -1198,
     484, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,    16,
     432, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,   117,
     496,   308, -1198,   428,   295, -1198, -1198, -1198, -1198, -1198,
   -1198,   533, -1198,   503, -1198,   537, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198,   376,   380,   381, -1198, -1198, -1198, -1198, -1198,
    4107,   661, -1198,  4380, -1198, -1198,   442,  4653,   478,   479,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
     -19, -1198, -1198, -1198, -1198,   294,  9485, -1198, -1198, -1198,
   -1198, -1198,   505,   575, -1198,   500,   418,   258,   259,   223,
     310, -1198,   595,   480,   571,   572,  4926, -1198, -1198, -1198,
     -51, -1198, -1198,  5745, -1198,   262, -1198,   526,  6018, -1198,
     526,  6018, -1198, -1198, -1198, -1198,   526, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198,   525, -1198, -1198, -1198, -1198,
    4653, -1198, -1198,  4653,  9485,  4653,   542,   543,  4653, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198,  4653,  8160, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198,   545,  4653,  4653,   514,  4653,   515,  9485,   665,   666,
     509,   509,   665,  9485,   -67,   -50,   687,   -39,   -65,  9485,
     562,   594,   255,  7098,   377,    66,   332,   687, -1198, -1198,
     433, -1198, -1198, -1198, -1198, -1198,  4653, -1198,  4653,  6829,
     569, -1198,    30,    42,  9485,  7098,  9485,  9485,  4653,   449,
     452, -1198,   605,   606,  9485,     7,  4653,  8425,   576,   579,
     581,   583,   587,   588, -1198, -1198, -1198,  9485, -1198,   546,
     698,  4653,    44, -1198,   712,   559, -1198,  4653,   534, -1198,
     722,  4653,  4653,   563,  4653,  4653,  4653,  4653,   517,  9485,
    4653,  9485,   687,   687,   687, -1198, -1198, -1198, -1198,    25,
      76, -1198, -1198,   442,   709,  4653, -1198,  4653,   585,   390,
     234,   512,   634,   586,   597,  4653,  4653, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198,   647, -1198,   -49,  5199,  5199,  5199,
   -1198,  5199,  5199, -1198,  5199, -1198,  5199, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198,  5199,  5199,     4,  5199,  5199,  5199,
    5199,  5199,  5199,  5199,  5199,  5199,  5199,  5199,   538,   671,
     673,   674, -1198, -1198, -1198,  1923, -1198, -1198,  5745,  5745,
    4653,   526, -1198, -1198,   526, -1198,   526,  2196,  5472, -1198,
     589,   619, -1198,   590,  4653,  4653,   591,   593, -1198,   -30,
     -18,  2469,   596,   598, -1198,   600, -1198,   622, -1198,  9485,
   -1198, -1198, -1198, -1198,   756, -1198, -1198, -1198, -1198, -1198,
   -1198,   676,   677, -1198, -1198,   602,   284,  9485,   408,   628,
     629,   602,   687,   662,   658, -1198, -1198, -1198,   342,    -7,
     351,   768, -1198, -1198,   232, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198,   507, -1198,   608,   612,   611, -1198,
     613,  2742,  7098,   701,   763,  7098,   687,   707,   -23, -1198,
     -16,   675,   664,   699, -1198,   -46,   631, -1198, -1198,  9485,
     -26, -1198,   625,   579,   431, -1198,   626,   632,   636, -1198,
      49,   118,  3015,   -21, -1198,  9485,   698, -1198,   -70,   637,
   -1198, -1198, -1198, -1198,   638, -1198,   -57, -1198, -1198, -1198,
     -38,   -35,   725,   592,   599,   -34, -1198,   680,   642,   172,
   -1198, -1198, -1198, -1198, -1198,   640, -1198,   159, -1198, -1198,
     -15,   657,  9485,  4653,   711, -1198, -1198,   713,  8955,   714,
    4653,   715,   -87,   690,   -43,   575, -1198, -1198, -1198, -1198,
   -1198,  5199, -1198, -1198, -1198,  4653,     4,   165, -1198,   570,
     493,   601,   603, -1198, -1198,   604,   171,   259,   259,   188,
     223,   223,   223,   223,   310,   310, -1198, -1198,  8955,  8955,
    9485,  9485, -1198,   659, -1198, -1198,   660, -1198, -1198, -1198,
     130,   594,     2,   663,    10,  4653, -1198,   667,   668,   744,
     695,  9485, -1198,  9485, -1198, -1198,   669, -1198, -1198, -1198,
      13,   343,   622, -1198,   222,   263, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198,   602, -1198,   716,  9220,
     710,  4653, -1198, -1198, -1198,   757,   717,  4653,   687,   687,
     602, -1198,   476,   687, -1198, -1198,   582, -1198, -1198,   580,
      20, -1198, -1198, -1198, -1198, -1198, -1198,   607, -1198, -1198,
    4653,   670,   705, -1198, -1198, -1198,   678,   729,   687,   703,
     731,   767,   687,   747,  4653,  4653,   723,   687,  4653,   748,
    4653,   728,   -53, -1198,     8,   623, -1198, -1198,   392,   -26,
   -1198, -1198, -1198,   719,  9485, -1198,  9485, -1198, -1198,   696,
    4653,   848, -1198,    31, -1198,   160, -1198, -1198,   856, -1198,
     315,  4653,  4653,  4653,   361,  4653,  4653,  4653,  4653,  4653,
    4653,   760,  4653,  4653,   645,   732,   765,   709,   805, -1198,
    4653, -1198,   359,   778, -1198,  9485,   779, -1198,  9485,   734,
     735, -1198,   190, -1198, -1198, -1198,  9485, -1198,  9485,  4653,
     745,  4653,  4653,   -69,   746, -1198,   718,   708, -1198,   644,
   -1198,   121, -1198,   299,    12,   652,     4,   299,  5199,  5199,
     568, -1198, -1198, -1198, -1198, -1198, -1198, -1198,     4,   758,
      12, -1198,   630,   846, -1198, -1198, -1198, -1198, -1198,   762,
   -1198, -1198, -1198,  4653, -1198,   766, -1198,   594, -1198, -1198,
   -1198,   727, -1198, -1198,  8690,   266, -1198,  3288,   726,   737,
     769,   738,   739, -1198,  9485,   811,   143, -1198, -1198,  4653,
   -1198,    10, -1198, -1198, -1198, -1198, -1198,   887,   438, -1198,
   -1198, -1198,  4653, -1198, -1198, -1198, -1198, -1198, -1198,   639,
      -6,   889, -1198,    21, -1198, -1198,   750,  4653,  3561, -1198,
     687,   807, -1198, -1198, -1198,   687,   807,  9485, -1198, -1198,
    4653,   736, -1198,  9485, -1198,  4653,  4653,   775,  4653,   774,
   -1198,   809,   810,  4653,  9485,   540,   860, -1198, -1198, -1198,
    3834,   742,   751, -1198, -1198, -1198,   800, -1198,   174, -1198,
   -1198,   924, -1198, -1198,  4653,  9485, -1198, -1198,   345, -1198,
   -1198, -1198,   752,   720,   721, -1198, -1198, -1198,   724,   730,
   -1198, -1198, -1198, -1198, -1198,   706,  9485,   753, -1198,  6291,
     645, -1198,  4653,  9485,   778, -1198,   687, -1198,   483, -1198,
     124,   827, -1198,  4653,   831,   711, -1198,   759,   764, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198,  4653, -1198, -1198,  4653,
     797,  4653, -1198, -1198,  5199, -1198, -1198, -1198, -1198, -1198,
      15,  5199,  5199,   280, -1198,   601, -1198, -1198,   208,  5199,
   -1198, -1198,   603,     4,   679, -1198, -1198, -1198, -1198,  4653,
   -1198, -1198,  9485,   761,     3, -1198, -1198,   772, -1198, -1198,
   -1198, -1198, -1198,   757,  8955,   828,   854,   773, -1198, -1198,
   -1198, -1198,   151,   928,   934,   151,   -22,   144,   146,   803,
     833, -1198,   782,   862,   687,   807, -1198, -1198, -1198, -1198,
   -1198, -1198,  4653, -1198,  4653,  9485,  9485, -1198,   405, -1198,
    4653, -1198,   784, -1198, -1198,   848,  9485,   454, -1198,   785,
     848,  9485, -1198, -1198,  4653,  4653,  4653,  4653,  4653, -1198,
    4653, -1198,   197, -1198,   786, -1198, -1198, -1198, -1198,   827,
   -1198, -1198, -1198,   687, -1198, -1198, -1198, -1198, -1198, -1198,
    4653, -1198,   223,  5199,  5199,   223,   288, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198,   873,  4653,  9485,  4653,
   -1198, -1198, -1198, -1198,  8955, -1198,    -6,    -6,   151, -1198,
   -1198, -1198,    40,   151,   947,   733,   874, -1198,   874, -1198,
    4653,   166,  4653, -1198,   687, -1198, -1198, -1198,   902, -1198,
   -1198, -1198, -1198,   -28,   848,  9485, -1198,   781,   848, -1198,
   -1198, -1198, -1198, -1198, -1198,   853,  6291, -1198, -1198, -1198,
   -1198, -1198,   223,   223,  5199,  8955, -1198,   790, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198,    12, -1198,   205, -1198,   209,
   -1198,   869,   757,  4653, -1198, -1198,   807,   858,   153,   249,
   -1198,   787,   848, -1198,   788,  9485, -1198,   223,   795,  4653,
     740,   874, -1198, -1198,   687, -1198, -1198,  9485, -1198, -1198,
     885,   273, -1198, -1198, -1198, -1198,   804,   366, -1198, -1198,
   -1198,   791, -1198,   210,  4653, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198,   861,   835, -1198,
    9485, -1198,   215,   868,   835,  9485, -1198,   808,   835, -1198
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   377,   378,   559,   524,   716,   717,   720,   718,   721,
     719,   650,   574,   566,   582,   573,   564,   662,   672,   711,
     710,   712,   713,   709,   568,   570,   597,   669,   632,   626,
     671,   667,   594,   670,   726,   621,   663,   724,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   664,   578,   572,
     565,   666,   641,   571,   576,   735,   736,   737,   738,   739,
     740,   741,   742,   743,   744,   745,   368,   371,   640,   636,
     627,   607,   563,   358,     0,   635,   643,   651,   356,   631,
     394,   608,   609,   665,   357,   360,   628,   645,     0,   400,
     366,   396,   638,   562,   629,   630,   658,   633,   649,   657,
     362,   361,   581,   620,   660,   395,   648,   653,   567,     0,
       0,   315,   646,   656,   661,   659,   639,   714,   625,   623,
     624,   367,     0,   314,     0,   370,   369,   654,   610,   634,
       0,   359,   344,     0,   376,   655,   637,   644,   652,   647,
     715,   601,   606,   605,   604,   603,   602,   575,   622,     0,
     561,   668,   595,   701,   700,   702,   580,   579,   598,   707,
     569,   699,   704,   705,   696,   600,   642,   698,   708,   706,
     697,   599,   703,   722,   723,   725,   688,   687,   584,   577,
     586,   585,   681,   677,   592,   596,   593,   690,   691,   674,
     583,   686,   685,   682,   678,   695,   689,   684,   680,   673,
     694,   693,   679,   683,   675,   676,   587,   588,   590,   692,
     589,   591,   728,   729,   734,   730,   727,   732,   733,   731,
       0,     0,     2,     0,     4,     6,     0,     0,     0,     0,
      17,    19,    31,    21,    22,    23,    47,    24,    28,    29,
      51,    52,    53,    48,    49,    55,    56,    26,    25,    30,
      50,   173,   172,   169,   170,   171,   174,    27,    11,   150,
     151,   155,   157,   189,   195,     0,     0,   187,   188,   158,
     159,   160,   161,   271,   273,   275,   285,   288,   290,   293,
     298,   301,   304,   306,   308,   310,     0,   312,   318,   320,
       0,   336,   319,   340,   343,   345,   348,   350,     0,   355,
     352,     0,   363,   373,   375,   349,   379,   384,   392,   385,
     386,   387,   390,   391,   388,   389,   407,   409,   410,   411,
     408,   456,   457,   458,   459,   460,   461,   372,   498,   490,
     497,   496,   495,   492,   494,   491,   493,   393,    54,   162,
     163,   165,   164,   166,   167,   374,   560,   168,   121,   118,
       0,   129,   130,     0,     0,     0,     0,     0,     0,   716,
     717,   720,   721,   719,   650,   574,   566,   582,   573,   564,
     662,   568,   570,   669,   632,   671,   726,   621,   724,   611,
     612,   572,   565,   563,   633,     0,     0,   714,   715,   561,
     707,   569,   699,   705,   696,   599,   722,   725,   728,   729,
     734,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    99,
       0,   100,   101,   103,   134,   137,     0,   557,     0,     0,
       0,   558,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   197,     0,     0,     0,     0,     0,     0,     0,   566,
     573,   564,   570,   563,   364,   374,   397,     0,   398,     0,
     423,     0,     0,   339,     0,     0,   342,     0,     0,   452,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     1,     5,     7,     0,
       0,    12,    10,    14,    15,     0,   153,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   175,   194,   190,
     196,   191,   193,   192,   199,   200,     0,     0,     0,     0,
     329,     0,     0,   327,     0,   280,     0,   328,   321,   326,
     325,   324,   323,   322,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   317,   316,   313,     0,   337,   341,     0,     0,
       0,   351,   381,   354,   353,   365,   380,     0,     0,   127,
       0,     0,   522,     0,     0,     0,     0,     0,   514,     0,
       0,     0,     0,     0,   503,     0,   504,     0,   139,     0,
     140,   136,   135,   138,     0,   112,   113,    64,    65,   556,
      73,     0,     0,    58,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   525,   526,   527,     0,     0,
       0,     0,   784,   785,     0,    63,   777,   778,   779,   780,
     781,   782,   783,   102,     0,   104,     0,     0,     0,   505,
       0,     0,     0,    82,     0,     0,     0,    74,     0,   260,
       0,     0,     0,   212,   213,     0,     0,   177,   178,     0,
       0,   198,     0,     0,     0,   500,     0,     0,     0,   508,
       0,     0,     0,     0,   399,   424,   423,   420,     0,     0,
     454,   453,   338,   513,     0,   451,     0,   538,   539,   499,
       0,     0,     0,     0,     0,     0,   544,     0,     0,     0,
     215,   232,   131,   133,   132,     0,    18,     0,    20,   156,
       0,     0,     0,     0,     0,   176,   233,     0,     0,     0,
       0,     0,     0,     0,     0,   272,   274,   278,   284,   283,
     282,     0,   279,   276,   277,     0,     0,     0,   769,   286,
     748,   756,   758,   760,   762,   764,   767,   292,   291,   289,
     295,   296,   297,   294,   299,   300,   303,   302,     0,     0,
       0,     0,   334,     0,   346,   347,     0,   382,   403,   405,
       0,   662,     0,     0,     0,     0,   330,     0,     0,     0,
       0,     0,   518,     0,   515,   463,     0,   462,   471,   472,
       0,     0,     0,    62,     0,     0,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    33,    34,     0,     0,
      90,     0,    86,    88,    89,    93,    96,     0,     0,     0,
      32,    72,     0,     0,   786,   787,     0,   788,   792,     0,
       0,   821,   790,   791,   820,   789,   793,     0,   800,   822,
       0,     0,     0,   507,   506,   473,     0,     0,     0,     0,
       0,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   747,     0,     0,   179,   180,     0,   185,
     521,   501,   502,     0,     0,   511,     0,   509,   467,     0,
       0,   423,   421,     0,   412,     0,   401,   402,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,   154,
       0,   186,   244,   240,   242,     0,   234,   235,     0,   567,
     575,   479,   480,   486,   487,   489,     0,   202,     0,     0,
       0,     0,     0,     0,     0,   281,     0,     0,   763,     0,
     287,     0,   776,     0,     0,     0,     0,     0,     0,     0,
     749,   753,   771,   752,   775,   773,   772,   774,     0,     0,
       0,   765,   828,   826,   830,   768,   305,   307,   309,   477,
     311,   335,   383,     0,   404,   124,   123,     0,   120,   119,
     128,     0,   332,   331,     0,     0,   266,     0,     0,     0,
     522,     0,     0,   464,     0,   114,     0,   144,   142,     0,
     141,     0,    70,    71,    68,    69,    35,     0,     0,    91,
      92,    94,     0,    95,    60,    61,    66,    67,    57,     0,
       0,     0,   795,     0,   794,   811,     0,     0,     0,   474,
       0,    84,    78,    81,    80,     0,    76,     0,   258,   262,
       0,     0,   126,     0,   217,     0,     0,     0,     0,     0,
     181,     0,     0,     0,     0,   226,     0,   223,   228,   184,
       0,     0,     0,   468,   259,   424,     0,   413,     0,   447,
     444,     0,   448,   449,     0,     0,   450,   443,     0,   418,
     446,   445,     0,     0,     0,   531,   532,   528,     0,     0,
     536,   537,   533,   542,   540,     0,     0,     0,   546,     0,
     547,   548,     0,     0,   241,   253,     0,   254,     0,   245,
     246,   247,   248,     0,   237,     0,   201,     0,     0,   483,
     485,   484,   481,   210,   211,   204,     0,   206,   203,     0,
       0,     0,   770,   766,     0,   823,   824,   844,   843,   839,
       0,     0,     0,     0,   825,   757,   838,   750,     0,     0,
     755,   754,   759,     0,     0,   829,   827,   478,   406,     0,
     122,   333,     0,     0,     0,   267,   465,     0,   519,   520,
     523,   516,   517,   146,     0,     0,   115,     0,   143,    36,
      87,    97,   809,     0,     0,   807,   803,     0,     0,     0,
       0,   475,     0,    83,     0,    77,   261,   263,    13,   214,
     219,   218,     0,   221,     0,     0,     0,   183,   224,   227,
       0,   469,     0,   512,   510,   423,     0,     0,   455,     0,
     423,     0,   419,     9,     0,     0,     0,     0,     0,   545,
       0,   554,     0,   549,     0,   216,   257,   255,   256,   249,
     250,   251,   243,     0,   238,   236,   488,   482,   208,   205,
       0,   207,   845,     0,     0,   831,     0,   842,   841,   840,
     835,   836,   751,   761,   837,   125,     0,     0,     0,     0,
     466,   147,   116,   145,     0,   149,     0,     0,   810,   812,
     814,   816,     0,   808,     0,     0,     0,   798,     0,   796,
       0,     0,     0,   476,     0,    79,   220,   222,   231,   230,
     225,   182,   470,     0,   423,     0,   148,     0,   423,   529,
     530,   534,   535,   541,   543,     0,     0,   550,   746,   252,
     239,   209,   833,   832,     0,     0,   268,     0,   264,   117,
     819,   818,   813,   817,   815,   804,   805,     0,   801,     0,
     110,   106,   108,     0,   105,   270,    85,     0,   433,   427,
     422,     0,   423,   414,     0,     0,   555,   834,     0,     0,
       0,     0,   799,   797,     0,   109,   111,     0,   441,   435,
       0,   434,   436,   442,   439,   429,     0,   428,   430,   440,
     416,     0,   415,     0,     0,   265,   806,   802,   107,   229,
     426,   437,   438,   425,   431,   432,   417,     0,     0,   269,
       0,   551,     0,     0,     0,     0,   552,     0,     0,   553
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1198, -1198,   776, -1198,   770,   771, -1198,   777, -1198,   486,
     489,  -482, -1198,   365,  -472, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,  -853,
   -1198, -1198, -1198, -1198,   -31,   177,   577, -1198, -1198, -1198,
   -1198,   573,   578,  -353, -1198, -1198, -1198,   199, -1198,  -756,
   -1198, -1198,    18, -1198, -1198, -1198, -1198, -1198, -1198,   204,
     105, -1198, -1198,  -183, -1198, -1197,   780,   -66, -1198,   499,
    -342, -1198, -1198, -1198, -1198,   131, -1198, -1198,   749, -1198,
   -1198, -1198, -1198, -1198,    81,  -492,  -642, -1198, -1198, -1198,
     -41, -1198, -1198,  -205,   -48,   -98, -1198, -1198, -1198,  -109,
   -1198, -1198,    99,  -103, -1198, -1198,   -99, -1002, -1198,   555,
     -24, -1198, -1198,    29, -1198, -1198,   498,   501, -1198,  -496,
    -926,   477,    77,  -534,    72,    75, -1198, -1198, -1198, -1198,
   -1198,   755, -1198, -1198, -1198, -1198, -1198,   741, -1198, -1198,
    -123, -1198, -1198, -1198, -1198, -1198, -1198, -1198,   -47, -1083,
   -1198, -1198,   189,   -44, -1198,  -541, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198,  -870, -1198,   -45, -1198,   344,
    -684, -1198, -1198, -1198, -1198, -1198,  -359,  -349, -1049,  -848,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
     264,  -659,  -748, -1198,   217,  -135,  -715, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198,   584,   609,  -500,   250,    27, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198,   -68, -1198, -1198,   -73,
   -1198,  -412,  -115,   -13, -1198, -1198,   296, -1198, -1198,    89,
      78,  -116,   301, -1198, -1198,    90, -1198,  -721, -1198, -1198,
   -1198, -1198,  -249,  -837, -1198,  -142,  -641, -1198,  -713, -1198,
   -1198, -1198, -1198,  -956, -1198, -1198, -1198, -1198,  -104,    98,
   -1198
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   816,   817,   818,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,  1041,
     656,   246,   247,   822,   823,   824,   985,   248,   430,   249,
     431,   432,   433,  1350,  1351,  1301,   250,   801,   251,   349,
     578,   782,   986,   252,   253,   254,   255,   256,   257,   434,
     435,   600,  1006,  1007,  1086,  1010,   258,   259,   507,   260,
     261,   262,   517,   452,   878,   879,   263,   518,   264,   520,
     265,   266,   267,   524,   525,  1065,   733,   268,   663,   709,
     664,   670,  1066,  1067,  1068,   710,   521,   522,   926,   927,
    1254,   523,   923,   924,  1119,  1120,  1121,  1122,   269,   658,
     659,   270,   995,   996,   271,   272,   273,   274,   741,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   544,   545,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   571,   572,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   780,   315,   316,   317,  1088,   686,   687,
     688,  1360,  1386,  1387,  1380,  1381,  1388,  1382,  1089,  1090,
     318,   319,  1091,   320,   321,   322,   323,   324,   325,   326,
     978,   734,   931,  1132,   932,   933,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   581,   999,   337,   338,
     339,   340,   341,   342,   343,   705,   706,   344,  1110,  1111,
    1242,  1042,   440,   345,   346,   347,   749,   960,   750,   751,
     752,   753,   754,   755,   756,   961,   962,   635,   636,   637,
     638,   639,  1347,  1348,   640,  1288,  1195,  1292,  1289,   641,
     642,   964,   975,  1153,   965,   966,   971,   967,  1270,  1149,
     950
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       401,   866,   893,  1034,   610,   748,   872,   472,   579,  1046,
     476,   580,   441,   934,  1164,   644,   760,   761,   762,   763,
     976,   977,   718,   871,     4,  1087,  1241,   464,   990,   963,
     653,   657,  1157,   737,   732,   738,   739,   478,   740,  1232,
     742,   875,   673,   469,   728,  1327,   729,   728,   743,   744,
     609,   690,   729,   934,   934,   900,   939,   894,   904,   458,
    1343,   465,   609,  1263,  1358,   407,   408,   409,   410,   411,
     412,   898,   911,  1150,  1139,   466,   791,   728,   413,   674,
     712,   713,   714,   863,   414,   863,  1056,   505,   793,  1193,
     940,   505,   944,   870,   730,   415,   416,   470,   565,   417,
     942,   728,   418,   419,   934,   836,   666,  1150,   987,   441,
     605,   474,   613,    80,   607,  1031,  1031,   475,  1250,  1251,
    1278,   124,   895,   611,   606,    91,   614,   865,   442,   899,
    1004,   443,  1032,  1197,   354,   420,   421,   422,   612,   697,
     698,  1264,   700,   701,   702,   703,  1194,   608,   708,   105,
    1359,  1058,   792,   745,   654,   884,   746,  1378,  1077,   348,
     864,  1079,   890,   719,   794,   628,  1021,   506,  1079,  1080,
     567,   919,  1033,   725,   726,   731,   901,   902,  1232,   905,
     906,   423,  1079,  1080,  1279,     4,   652,   876,   988,   675,
     355,   903,  1205,   731,   907,  1005,  1198,   912,   655,   407,
     408,   409,   410,   411,   412,   748,   748,  1076,  1087,   731,
     831,  1411,   413,   731,   691,  1059,   731,  1416,  1087,   731,
     877,  1419,  1344,  1078,   886,   479,  1151,  1152,   350,  1116,
    1057,   885,   915,  1272,   837,   779,   983,   419,  1294,  1161,
    1295,   424,   943,  1366,   861,   945,  1173,  1329,  1118,  1185,
    1296,   573,  1298,   526,   575,  1188,   747,  1079,   356,   357,
    1151,  1152,  1081,   838,   839,   425,   840,   841,  1384,   420,
     421,   918,  1353,  1082,    80,  1083,  1081,  1378,   916,   934,
    1082,  1079,  1083,  1379,  1286,   465,    91,   351,   465,   583,
     619,   998,   586,  1001,  1082,   620,  1083,   449,   450,   629,
     887,  1140,  1084,   426,   427,   428,   429,   630,   624,  1084,
     105,  1371,   984,   110,   745,  1371,  1407,   746,   402,   587,
     631,  1413,   632,  1084,   650,  1186,  1297,   110,  1299,   122,
     661,  1129,   633,   621,  1145,   634,   592,   593,   481,   595,
     482,   582,   547,   122,  1016,   508,  1009,  1287,  1354,  1325,
    1085,   451,   509,  1079,  1080,   510,   511,  1087,  1016,   548,
     622,  1130,   444,   512,  1226,   994,  1012,  1146,   149,  1082,
     646,  1083,   647,   590,  1079,   550,   352,   819,  1174,  1131,
    1385,   922,   149,  1013,  1071,  1384,  1072,  1372,   937,  1370,
     678,  1373,  1408,  1082,   597,  1083,   353,  1414,  1084,   425,
     604,   551,  1326,  1401,   554,   689,   615,  1014,   972,   973,
     441,   694,   547,   555,   552,   748,  1024,  1025,   820,   554,
     623,  1028,  1084,   821,  1015,  1158,   441,   748,   555,   548,
     974,   660,   441,   662,   665,   718,  1282,   426,   427,   428,
     429,   672,   358,   556,   681,   774,   775,  1081,   553,   568,
     569,  1356,   549,  1115,   660,  1051,   557,  1061,  1062,   513,
    1063,   514,  1079,  1080,  1116,  1082,  1267,  1083,   436,   934,
    1061,  1062,  1268,   845,  1117,   515,   707,  1008,   711,  1020,
    1269,   499,  1334,  1118,   554,  1023,  1082,   729,  1083,   574,
     445,   500,  1009,   555,  1084,   576,   446,  1404,   110,   773,
     729,   516,   846,   847,   776,   848,   849,   447,  1036,  1064,
    1383,  1389,   783,   598,   122,  1084,   487,   603,   787,   788,
     448,   488,  1048,  1049,  1281,   796,  1052,   777,  1054,   484,
     777,   485,   777,  1383,  1397,  1231,  1339,   857,  1267,  1389,
     860,  1313,   826,  1093,  1268,  1094,  1317,   827,  1074,   407,
     408,   409,  1269,   149,   412,   403,  1081,  1147,   404,  1095,
    1096,  1097,  1148,  1100,  1101,  1102,  1103,  1104,  1105,   934,
    1107,  1108,   820,   453,  1082,  1342,  1083,   821,   922,   405,
    1342,   834,   406,   454,   835,   856,   802,  1368,   951,  1098,
     842,  1099,   628,   843,   625,   626,   627,  1135,   455,  1137,
    1138,  1026,  1027,  1084,   825,  1061,  1062,   110,  1247,  1248,
    1262,   427,   428,   429,   601,   602,   889,  1265,  1266,   467,
     934,   471,   748,   122,   757,   758,   764,   765,  1203,   529,
    1361,   766,   767,   477,  1364,   979,   979,   530,   531,   441,
     532,  1168,   441,   480,  1315,  1340,  1341,   533,   483,   486,
     489,   534,   490,   535,   491,   492,   874,   952,   536,   493,
     494,   496,   149,   951,   503,   504,   528,   628,   527,   546,
     558,   560,   891,   561,   537,   559,   570,   577,  1391,   946,
    1191,   806,   807,   808,   809,   810,   811,   812,   813,   814,
     815,   584,   585,  1375,   591,  1200,   594,   596,   538,   539,
     540,   541,   542,   543,  1246,   407,   599,   609,  1207,   921,
     616,   617,   427,  1210,  1211,   935,  1213,   667,   651,   991,
     668,  1217,   669,   671,   685,   682,   629,   692,   684,  1332,
    1333,   386,   952,   404,   630,   406,   953,   954,   955,   439,
     457,   693,   696,   695,   704,   699,   956,   631,   717,   632,
     721,   722,   723,   727,   957,   935,   935,   935,   935,   633,
     958,   959,   634,   724,   769,   768,   770,   771,   785,   786,
    1244,   784,   790,   789,   800,   797,   803,   798,  1000,   799,
    1000,   922,   804,   805,   828,   829,   832,   833,   844,   850,
     851,   852,  1305,   853,  1258,   854,   858,  1259,   859,  1261,
    1367,   629,   862,   868,   867,   869,   935,   880,   881,   630,
     873,   953,   954,   955,   882,   883,   896,   897,   908,   913,
     910,   914,   631,   920,   632,   909,   917,  1275,   925,   957,
     928,   936,   938,   941,   633,  1159,   959,   634,   981,   949,
     982,  1330,   989,   994,   997,  1017,   992,   993,  1003,   821,
     728,   968,  1030,  1029,  1038,   969,  1022,  1039,  1040,  1043,
    1044,   970,  1045,  1037,  1047,  1053,  1050,  1055,  1070,  1060,
    1306,   582,  1307,   582,  1075,  1073,  1092,  1106,  1311,  1035,
    1109,  1112,  1113,   621,  1123,  1125,  1127,  1128,  1136,  1141,
    1143,  1144,  1319,  1320,  1321,  1322,  1323,  1142,  1324,  1154,
    1166,  1163,  1165,  1167,  1184,  1169,  1171,     4,  1178,  1196,
    1180,  1192,  1124,  1204,  1212,   526,  1199,  1214,  1331,  1179,
    1181,  1182,  1208,  1133,  1223,  1134,  1215,  1216,  1220,  1225,
    1228,  1177,  1116,  1224,  1240,  1336,  1253,  1338,  1233,  1238,
    1260,  1256,  1277,  1187,  1274,  1004,  1257,  1284,  1290,  1234,
    1235,  1280,  1285,  1236,  1291,  1300,  1302,  1304,  1352,  1237,
    1355,  1303,  1398,  1312,  1316,  1328,  1335,  1345,  1357,  1031,
    1365,  1369,  1202,  1363,  1374,  1377,  1394,  1400,  1410,  1390,
    1392,   935,  1403,  1406,  1009,  1415,   830,  1190,  1346,   715,
    1418,  1183,   716,   497,   498,  1396,   495,  1019,   618,   643,
    1376,  1011,  1283,   501,  1222,  1170,   720,   502,   645,  1126,
    1069,  1352,  1209,  1310,   519,  1245,  1255,  1219,  1229,  1114,
    1252,  1249,   683,  1206,  1175,   735,   759,  1395,  1405,   736,
     892,   566,  1402,  1227,   660,   980,  1018,  1243,  1239,   676,
     665,   564,   947,  1002,  1189,  1155,  1162,  1273,   948,  1349,
    1160,  1218,  1409,  1293,  1271,  1156,     0,     0,     0,     0,
       0,     0,     0,     0,   677,     0,     0,     0,     0,     0,
       0,     0,  1230,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   707,     0,     0,   465,     0,     0,     0,
     711,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1276,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   935,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1308,  1309,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1314,     0,     0,     0,     0,  1318,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1337,     0,     0,     0,     0,
       0,   935,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1362,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   465,     0,     0,     0,     0,     0,     0,
       0,     0,   935,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1393,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1399,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,  1412,     0,     0,
       0,     0,  1417,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,     0,     0,
      78,    79,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,    91,     0,    92,
      93,    94,    95,     0,    96,     0,     0,     0,    97,    98,
      99,   100,   101,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   108,     0,     0,     0,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,   124,     0,
       0,   125,   126,   127,     0,     0,     0,   128,     0,   129,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   150,   151,     0,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   370,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   373,
      28,    29,   375,    31,    32,    33,     0,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    77,     0,     0,    78,    79,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,    91,     0,    92,    93,    94,    95,     0,    96,     0,
       0,     0,    97,    98,    99,   100,   101,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,   109,   110,   111,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,   124,     0,     0,   125,   126,   127,     0,     0,
       0,   128,   468,   129,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     389,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,   370,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   373,    28,    29,   375,    31,    32,    33,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,     0,    78,    79,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,     0,    92,    93,    94,    95,
       0,    96,     0,     0,     0,    97,    98,    99,   100,   101,
       0,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,     0,     0,     0,   109,   110,   111,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,   124,     0,     0,   125,   126,
     127,     0,   772,     0,   128,     0,   129,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   389,   151,     0,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   370,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   373,    28,    29,   375,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,     0,     0,
      78,    79,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,    91,     0,    92,
      93,    94,    95,     0,    96,     0,     0,     0,    97,    98,
      99,   100,   101,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   108,     0,     0,     0,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,   124,     0,
       0,   125,   126,   127,     0,     0,     0,   128,   778,   129,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   389,   151,     0,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,   370,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   373,    28,
      29,   375,    31,    32,    33,     0,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,     0,    78,    79,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
      91,     0,    92,    93,    94,    95,     0,    96,     0,     0,
       0,    97,    98,    99,   100,   101,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   109,   110,   111,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,   124,     0,     0,   125,   126,   127,     0,   795,     0,
     128,     0,   129,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   389,
     151,     0,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   370,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   373,    28,    29,   375,    31,    32,    33,     0,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,     0,     0,    78,    79,     0,     0,
       0,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,    91,     0,    92,    93,    94,    95,     0,
      96,     0,     0,     0,    97,    98,    99,   100,   101,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     108,     0,     0,     0,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,   124,     0,     0,   125,   126,   127,
       0,   855,     0,   128,     0,   129,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   389,   151,     0,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   370,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   373,    28,    29,   375,    31,    32,
      33,     0,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,     0,    78,
      79,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,    91,     0,    92,    93,
      94,    95,     0,    96,     0,     0,     0,    97,    98,    99,
     100,   101,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,     0,     0,     0,   109,   110,   111,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,   124,     0,     0,
     125,   126,   127,     0,   888,     0,   128,     0,   129,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   389,   151,     0,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   370,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   373,    28,    29,
     375,    31,    32,    33,     0,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
       0,     0,    78,    79,     0,     0,     0,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     0,    91,
       0,    92,    93,    94,    95,     0,    96,     0,     0,     0,
      97,    98,    99,   100,   101,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,   108,     0,     0,     0,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
     124,     0,     0,   125,   126,   127,     0,  1176,     0,   128,
       0,   129,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   389,   151,
       0,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     370,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     373,    28,    29,   375,    31,    32,    33,     0,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,     0,    78,    79,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,     0,    92,    93,    94,    95,     0,    96,
       0,     0,     0,    97,    98,    99,   100,   101,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   108,
       0,     0,     0,   109,   110,   111,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,   124,     0,     0,   125,   126,   127,     0,
    1201,     0,   128,     0,   129,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   389,   151,     0,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,   189,   190,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,   370,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   373,    28,    29,   375,    31,    32,    33,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,     0,     0,    78,    79,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,    91,     0,    92,    93,    94,
      95,     0,    96,     0,     0,     0,    97,    98,    99,   100,
     101,     0,     0,     0,     0,     0,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,   111,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,   124,     0,     0,   125,
     126,   127,     0,  1221,     0,   128,     0,   129,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   389,   151,     0,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,     0,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
       0,    78,    79,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,    91,     0,
      92,    93,    94,    95,     0,    96,     0,     0,     0,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,   108,     0,     0,     0,   109,
     110,   111,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,   124,
       0,     0,   125,   126,   127,     0,     0,     0,   128,     0,
     129,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   150,   151,     0,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,   190,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    77,     0,     0,    78,    79,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,    91,     0,    92,    93,    94,    95,     0,    96,     0,
       0,     0,    97,    98,    99,   100,   101,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,   109,   110,   111,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,   124,     0,     0,   125,   126,   127,     0,     0,
       0,   128,     0,   129,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     389,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,   370,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   373,    28,    29,   375,    31,    32,    33,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,     0,    78,    79,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,     0,    92,    93,    94,    95,
       0,    96,     0,     0,     0,    97,    98,    99,   100,   101,
       0,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,     0,     0,     0,   109,   110,   111,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,   124,     0,     0,   125,   126,
     127,     0,     0,     0,   128,     0,   129,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   389,   151,     0,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,     0,     0,   359,   360,   361,     8,   362,   363,    11,
     365,    13,    14,    15,    16,   370,    18,    19,    20,    21,
      22,    23,   371,    25,    26,   373,   374,    29,   375,    31,
      32,    33,     0,   376,   377,    36,   378,   379,   380,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,     0,     0,
      78,    79,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,    91,     0,    92,
      93,    94,    95,     0,    96,     0,     0,     0,   384,    98,
      99,   100,   101,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   108,     0,     0,     0,   109,   110,
     562,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   563,   124,     0,
       0,   125,   126,   127,     0,     0,     0,   128,     0,   129,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   389,   151,     0,   152,
     153,   154,   155,   156,   157,   158,   390,   160,   392,   162,
     393,   394,   165,   166,   167,   168,   169,   170,   395,   172,
     396,   174,   397,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   398,   399,   400,   215,   216,   217,   218,   219,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     0,   359,   360,   361,     8,
     362,   363,    11,   365,    13,    14,    15,    16,   370,    18,
      19,    20,    21,    22,    23,   371,    25,    26,   373,   374,
      29,   375,    31,    32,    33,     0,   376,   377,    36,   378,
     379,   380,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,     0,    78,    79,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
      91,     0,    92,    93,    94,    95,     0,    96,     0,     0,
       0,   384,    98,    99,   100,   101,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   109,   110,   111,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,   124,     0,     0,   125,   126,   127,     0,     0,     0,
     128,     0,   129,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   389,
     151,     0,   152,   153,   154,   155,   156,   157,   158,   390,
     160,   392,   162,   393,   394,   165,   166,   167,   168,   169,
     170,   395,   172,   396,   174,   397,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   398,   399,   400,   215,   216,   217,
     218,   219,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   781,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   373,    28,    29,   375,    31,    32,    33,     0,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,     0,     0,    78,    79,     0,     0,
       0,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,    91,     0,    92,    93,    94,    95,     0,
      96,     0,     0,     0,    97,    98,    99,   100,   101,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     108,     0,     0,     0,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,   124,     0,     0,   125,   126,   127,
       0,     0,     0,   128,     0,   129,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   389,   151,     0,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     0,   359,   360,   361,     8,   362,   363,   364,   365,
      13,    14,    15,    16,   370,    18,    19,    20,    21,    22,
      23,   371,    25,    26,   373,   374,    29,   375,    31,    32,
      33,     0,   376,   377,    36,   378,   379,   380,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,     0,    78,
      79,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,    91,     0,    92,    93,
      94,    95,     0,    96,     0,     0,     0,   384,    98,    99,
     100,   101,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,     0,     0,     0,   109,   110,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,     0,     0,     0,     0,
     125,   126,   127,     0,     0,     0,   128,     0,   129,   130,
     131,     0,     0,     0,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   389,   151,     0,   152,   153,
     154,   155,   156,   157,   158,   390,   160,   392,   162,   393,
     394,   165,   166,   167,   168,   169,   170,   395,   172,   396,
     174,   397,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     398,   399,   400,   215,   216,   217,   218,   219,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     0,     0,
       0,     0,     0,     0,     0,   359,   360,   361,     8,   362,
     363,   364,   365,   459,   367,   460,   461,   370,    18,    19,
      20,    21,    22,    23,   371,   462,    26,   373,   374,    29,
     375,    31,    32,    33,     0,   376,   377,    36,   378,   379,
     380,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,     0,    68,
       0,    69,    70,    71,   463,     0,     0,    75,    76,    77,
       0,     0,     0,    79,     0,     0,     0,     0,    81,    82,
      83,     0,     0,    86,    87,     0,     0,     0,     0,     0,
       0,    92,    93,    94,    95,     0,    96,     0,     0,     0,
     384,    98,    99,     0,     0,     0,     0,     0,     0,     0,
     102,   103,   104,     0,   106,   107,   108,     0,     0,     0,
       0,     0,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   387,   118,   119,   120,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,     0,     0,     0,   128,
       0,   129,   130,     0,     0,     0,     0,   134,     0,   135,
       0,   136,   137,   138,   139,   388,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,     0,     0,   389,   151,
       0,   152,   153,   154,   155,   156,   157,   158,   390,   160,
     392,   162,   393,   394,   165,   166,   167,   168,   169,   170,
     395,   172,   396,   174,   397,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   398,   399,   400,   215,   216,   217,   218,
     219,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     0,     0,     0,     0,     0,     0,     0,   359,   360,
     361,     8,   362,   363,   364,   365,   366,   367,   368,   369,
     370,    18,    19,    20,    21,    22,    23,   371,   372,    26,
     373,   374,    29,   375,    31,    32,    33,     0,   376,   377,
      36,   378,   379,   380,    40,    41,    42,    43,    44,    45,
      46,    47,    48,   381,   382,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
       0,     0,    68,     0,    69,    70,    71,   383,     0,     0,
      75,    76,    77,     0,     0,     0,    79,     0,     0,     0,
       0,    81,    82,    83,     0,     0,    86,    87,     0,     0,
       0,     0,     0,     0,    92,    93,    94,    95,     0,    96,
       0,     0,     0,   384,    98,    99,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,     0,   106,   107,   108,
       0,     0,     0,     0,     0,     0,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   387,   118,   119,   120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,     0,
       0,     0,   128,     0,   129,     0,     0,     0,     0,     0,
     134,     0,   135,     0,   136,   137,   138,   139,   388,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   389,   151,     0,   152,   153,   154,   155,   156,   157,
     158,   390,   391,   392,   162,   393,   394,   165,   166,   167,
     168,   169,   170,   395,   172,   396,   174,   397,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,   189,   190,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   398,   399,   400,   215,
     216,   217,   218,   219,   437,     0,     0,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     0,   359,   360,   361,
       8,   362,   363,   364,   365,   366,   367,   368,   369,   370,
      18,    19,    20,    21,    22,    23,   371,   372,    26,   373,
     374,    29,   375,    31,    32,    33,     0,   376,   377,    36,
     378,   379,   380,    40,    41,    42,    43,    44,    45,    46,
      47,    48,   381,   382,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,    68,     0,    69,    70,    71,   383,     0,     0,    75,
      76,    77,     0,     0,     0,    79,     0,     0,     0,     0,
      81,    82,    83,     0,     0,    86,    87,     0,     0,     0,
       0,     0,     0,    92,    93,    94,    95,     0,    96,     0,
       0,     0,   384,    98,    99,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,     0,   106,   107,   108,   438,
       0,     0,   439,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   387,   118,   119,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
       0,   128,     0,   129,     0,     0,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   388,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     389,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     390,   391,   392,   162,   393,   394,   165,   166,   167,   168,
     169,   170,   395,   172,   396,   174,   397,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   398,   399,   400,   215,   216,
     217,   218,   219,   437,     0,     0,     0,     3,     0,   648,
       0,     0,     0,     0,     0,     0,   359,   360,   361,     8,
     362,   363,   364,   365,   366,   367,   368,   369,   370,    18,
      19,    20,    21,    22,    23,   371,   372,    26,   373,   374,
      29,   375,    31,    32,    33,     0,   376,   377,    36,   378,
     379,   380,    40,    41,    42,    43,    44,    45,    46,    47,
      48,   381,   382,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,     0,
      68,     0,    69,    70,    71,   383,     0,     0,    75,    76,
      77,     0,     0,     0,    79,     0,     0,     0,     0,    81,
      82,    83,     0,     0,    86,    87,     0,     0,     0,     0,
       0,     0,    92,    93,    94,    95,     0,    96,     0,     0,
       0,   384,    98,    99,     0,     0,     0,     0,     0,     0,
       0,   102,   103,   104,     0,   106,   107,   108,     0,     0,
       0,     0,     0,     0,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   387,   118,   119,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,     0,     0,     0,
     128,   649,   129,     0,     0,     0,     0,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   388,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,     0,     0,   389,
     151,     0,   152,   153,   154,   155,   156,   157,   158,   390,
     391,   392,   162,   393,   394,   165,   166,   167,   168,   169,
     170,   395,   172,   396,   174,   397,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   398,   399,   400,   215,   216,   217,
     218,   219,   437,     0,     0,     0,     3,     0,     0,     0,
       0,     0,     0,     0,     0,   359,   360,   361,     8,   362,
     363,   364,   365,   366,   367,   368,   369,   370,    18,    19,
      20,    21,    22,    23,   371,   372,    26,   373,   374,    29,
     375,    31,    32,    33,     0,   376,   377,    36,   378,   379,
     380,    40,    41,    42,    43,    44,    45,    46,    47,    48,
     381,   382,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,     0,    68,
       0,    69,    70,    71,   383,     0,     0,    75,    76,    77,
       0,     0,     0,    79,     0,     0,     0,     0,    81,    82,
      83,     0,     0,    86,    87,     0,     0,     0,     0,     0,
       0,    92,    93,    94,    95,     0,    96,     0,     0,     0,
     384,    98,    99,     0,     0,     0,     0,     0,     0,     0,
     102,   103,   104,     0,   106,   107,   108,     0,     0,     0,
       0,     0,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   387,   118,   119,   120,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,     0,     0,     0,   128,
       0,   129,     0,     0,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   388,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,     0,     0,   389,   151,
       0,   152,   153,   154,   155,   156,   157,   158,   390,   391,
     392,   162,   393,   394,   165,   166,   167,   168,   169,   170,
     395,   172,   396,   174,   397,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   398,   399,   400,   215,   216,   217,   218,
     219,   473,     0,     3,     0,     0,     0,     0,     0,     0,
       0,     0,   359,   360,   361,     8,   362,   363,   364,   365,
     366,   367,   368,   369,   370,    18,    19,    20,    21,    22,
      23,   371,   372,    26,   373,   374,    29,   375,    31,    32,
      33,     0,   376,   377,    36,   378,   379,   380,    40,    41,
      42,    43,    44,    45,    46,    47,    48,   381,   382,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,     0,    68,     0,    69,    70,
      71,   383,     0,     0,    75,    76,    77,     0,     0,     0,
      79,     0,     0,     0,     0,    81,    82,    83,     0,     0,
      86,    87,     0,     0,     0,     0,     0,     0,    92,    93,
      94,    95,     0,    96,     0,     0,     0,   384,    98,    99,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
       0,   106,   107,   108,     0,     0,     0,     0,     0,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   387,
     118,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,     0,     0,     0,   128,     0,   129,     0,
       0,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   388,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   389,   151,     0,   152,   153,
     154,   155,   156,   157,   158,   390,   391,   392,   162,   393,
     394,   165,   166,   167,   168,   169,   170,   395,   172,   396,
     174,   397,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     398,   399,   400,   215,   216,   217,   218,   219,     3,     0,
       0,     0,     0,     0,     0,     0,     0,   359,   360,   361,
       8,   362,   363,   364,   365,   366,   367,   368,   369,   370,
      18,    19,    20,    21,    22,    23,   371,   372,    26,   373,
     374,    29,   375,    31,    32,    33,     0,   376,   377,    36,
     378,   379,   380,    40,    41,    42,    43,    44,    45,    46,
      47,    48,   381,   382,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,    68,     0,    69,    70,    71,   383,     0,     0,    75,
      76,    77,     0,     0,     0,    79,     0,     0,     0,     0,
      81,    82,    83,     0,     0,    86,    87,     0,     0,     0,
       0,     0,     0,    92,    93,    94,    95,     0,    96,     0,
       0,     0,   384,    98,    99,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,     0,   106,   107,   108,   385,
       0,     0,   386,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   387,   118,   119,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
       0,   128,     0,   129,     0,     0,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   388,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     389,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     390,   391,   392,   162,   393,   394,   165,   166,   167,   168,
     169,   170,   395,   172,   396,   174,   397,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   398,   399,   400,   215,   216,
     217,   218,   219,     3,     0,     0,     0,     0,     0,     0,
       0,     0,   359,   360,   361,     8,   362,   363,   364,   365,
     366,   367,   368,   369,   370,    18,    19,    20,    21,    22,
      23,   371,   372,    26,   373,   374,    29,   375,    31,    32,
      33,     0,   376,   377,    36,   378,   379,   380,    40,    41,
      42,    43,    44,    45,    46,    47,    48,   381,   382,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,     0,    68,     0,    69,    70,
      71,   383,     0,     0,    75,    76,    77,     0,     0,     0,
      79,     0,     0,     0,     0,    81,    82,    83,     0,     0,
      86,    87,     0,     0,     0,     0,     0,     0,    92,    93,
      94,    95,     0,    96,     0,     0,     0,   384,    98,    99,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
       0,   106,   107,   108,   456,     0,     0,   457,     0,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   387,
     118,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,     0,     0,     0,   128,     0,   129,     0,
       0,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   388,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   389,   151,     0,   152,   153,
     154,   155,   156,   157,   158,   390,   391,   392,   162,   393,
     394,   165,   166,   167,   168,   169,   170,   395,   172,   396,
     174,   397,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     398,   399,   400,   215,   216,   217,   218,   219,     3,     0,
       0,     0,     0,     0,     0,     0,     0,   359,   360,   361,
       8,   362,   363,   364,   365,   366,   367,   368,   369,   370,
      18,    19,    20,    21,    22,    23,   371,   372,    26,   373,
     374,    29,   375,    31,    32,    33,     0,   376,   377,    36,
     378,   379,   380,    40,    41,    42,    43,    44,    45,    46,
      47,    48,   381,   382,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,    68,     0,    69,    70,    71,   383,     0,     0,    75,
      76,    77,     0,     0,     0,    79,     0,     0,     0,     0,
      81,    82,    83,     0,     0,    86,    87,     0,     0,     0,
       0,     0,     0,    92,    93,    94,    95,     0,    96,     0,
       0,     0,   384,    98,    99,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,     0,   106,   107,   108,     0,
       0,     0,     0,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   387,   118,   119,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
       0,   128,   588,   129,     0,     0,     0,     0,     0,   589,
       0,   135,     0,   136,   137,   138,   139,   388,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     389,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     390,   391,   392,   162,   393,   394,   165,   166,   167,   168,
     169,   170,   395,   172,   396,   174,   397,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   398,   399,   400,   215,   216,
     217,   218,   219,     3,     0,     0,     0,     0,     0,     0,
       0,     0,   359,   360,   361,     8,   362,   363,   364,   365,
     366,   367,   368,   369,   370,    18,    19,    20,    21,    22,
      23,   371,   372,    26,   373,   374,    29,   375,    31,    32,
      33,     0,   376,   377,    36,   378,   379,   380,    40,    41,
      42,    43,    44,    45,    46,    47,    48,   381,   382,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,     0,    68,     0,    69,    70,
      71,   383,     0,     0,    75,    76,    77,     0,     0,     0,
      79,     0,     0,     0,     0,    81,    82,    83,     0,     0,
      86,    87,     0,     0,     0,     0,     0,     0,    92,    93,
      94,    95,     0,    96,     0,     0,     0,   384,    98,    99,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
       0,   106,   107,   108,     0,     0,     0,     0,     0,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   387,
     118,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,     0,     0,     0,   128,   679,   129,     0,
       0,     0,     0,     0,   680,     0,   135,     0,   136,   137,
     138,   139,   388,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   389,   151,     0,   152,   153,
     154,   155,   156,   157,   158,   390,   391,   392,   162,   393,
     394,   165,   166,   167,   168,   169,   170,   395,   172,   396,
     174,   397,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     398,   399,   400,   215,   216,   217,   218,   219,     3,     0,
       0,     0,     0,     0,     0,     0,     0,   359,   360,   361,
       8,   362,   363,   364,   365,   459,   367,   460,   461,   370,
      18,    19,    20,    21,    22,    23,   371,   462,    26,   373,
     374,    29,   375,    31,    32,    33,     0,   376,   377,    36,
     378,   379,   380,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,    68,     0,    69,    70,    71,   463,     0,     0,    75,
      76,    77,     0,     0,     0,    79,     0,     0,     0,     0,
      81,    82,    83,     0,     0,    86,    87,  1172,     0,     0,
       0,     0,     0,    92,    93,    94,    95,     0,    96,     0,
       0,     0,   384,    98,    99,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,     0,   106,   107,   929,     0,
       0,     0,     0,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   387,   118,   119,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
       0,   128,     0,   129,   130,     0,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   388,   141,   142,
     143,   144,   145,   146,     0,     0,   930,   148,     0,     0,
     389,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     390,   160,   392,   162,   393,   394,   165,   166,   167,   168,
     169,   170,   395,   172,   396,   174,   397,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   398,   399,   400,   215,   216,
     217,   218,   219,     3,     0,     0,     0,     0,     0,     0,
       0,     0,   359,   360,   361,     8,   362,   363,   364,   365,
     459,   367,   460,   461,   370,    18,    19,    20,    21,    22,
      23,   371,   462,    26,   373,   374,    29,   375,    31,    32,
      33,     0,   376,   377,    36,   378,   379,   380,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,     0,    68,     0,    69,    70,
      71,   463,     0,     0,    75,    76,    77,     0,     0,     0,
      79,     0,     0,     0,     0,    81,    82,    83,     0,     0,
      86,    87,     0,     0,     0,     0,     0,     0,    92,    93,
      94,    95,     0,    96,     0,     0,     0,   384,    98,    99,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
       0,   106,   107,   929,     0,     0,     0,     0,     0,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   387,
     118,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,     0,     0,     0,   128,     0,   129,   130,
       0,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   388,   141,   142,   143,   144,   145,   146,     0,
       0,   930,   148,     0,     0,   389,   151,     0,   152,   153,
     154,   155,   156,   157,   158,   390,   160,   392,   162,   393,
     394,   165,   166,   167,   168,   169,   170,   395,   172,   396,
     174,   397,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     398,   399,   400,   215,   216,   217,   218,   219,     3,     0,
       0,     0,     0,     0,     0,     0,     0,   359,   360,   361,
       8,   362,   363,   364,   365,   459,   367,   460,   461,   370,
      18,    19,    20,    21,    22,    23,   371,   462,    26,   373,
     374,    29,   375,    31,    32,    33,     0,   376,   377,    36,
     378,   379,   380,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,    68,     0,    69,    70,    71,   463,     0,     0,    75,
      76,    77,     0,     0,     0,    79,     0,     0,     0,     0,
      81,    82,    83,     0,     0,    86,    87,     0,     0,     0,
       0,     0,     0,    92,    93,    94,    95,     0,    96,     0,
       0,     0,   384,    98,    99,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,     0,   106,   107,   929,     0,
       0,     0,     0,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   387,   118,   119,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
       0,   128,     0,   129,   130,     0,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   388,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     389,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     390,   160,   392,   162,   393,   394,   165,   166,   167,   168,
     169,   170,   395,   172,   396,   174,   397,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   398,   399,   400,   215,   216,
     217,   218,   219,     3,     0,     0,     0,     0,     0,     0,
       0,     0,   359,   360,   361,     8,   362,   363,   364,   365,
     366,   367,   368,   369,   370,    18,    19,    20,    21,    22,
      23,   371,   372,    26,   373,   374,    29,   375,    31,    32,
      33,     0,   376,   377,    36,   378,   379,   380,    40,    41,
      42,    43,    44,    45,    46,    47,    48,   381,   382,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,     0,    68,     0,    69,    70,
      71,   383,     0,     0,    75,    76,    77,     0,     0,     0,
      79,     0,     0,     0,     0,    81,    82,    83,     0,     0,
      86,    87,     0,     0,     0,     0,     0,     0,    92,    93,
      94,    95,     0,    96,     0,     0,     0,   384,    98,    99,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
       0,   106,   107,   108,     0,     0,     0,     0,     0,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   387,
     118,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,     0,     0,     0,   128,     0,   129,     0,
       0,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   388,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   389,   151,     0,   152,   153,
     154,   155,   156,   157,   158,   390,   391,   392,   162,   393,
     394,   165,   166,   167,   168,   169,   170,   395,   172,   396,
     174,   397,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     398,   399,   400,   215,   216,   217,   218,   219
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        13,   660,   686,   840,   416,   546,   665,   122,   350,   862,
     133,   353,    25,   728,   970,   427,   550,   551,   552,   553,
     768,   769,   504,   665,    20,   895,  1109,    74,   784,   750,
     442,   443,   958,   529,   526,   531,   532,    21,   534,  1088,
     536,    67,    35,   109,    93,  1242,    95,    93,   544,   545,
      20,     7,    95,   768,   769,    93,   143,   127,    93,    72,
      20,    74,    20,    48,    92,    40,    41,    42,    43,    44,
      45,   128,   106,    95,   143,    88,   106,    93,    53,    72,
     492,   493,   494,   106,    59,   106,   139,   106,   106,    95,
     732,   106,   734,   139,   143,    70,    71,   110,   149,    74,
     143,    93,    77,    78,   819,   112,   448,    95,   106,   122,
     177,   124,   177,   109,   164,    95,    95,   130,  1120,  1121,
     117,   172,   192,   162,   191,   121,   191,   143,    52,   186,
     117,    55,   112,   112,    93,   110,   111,   112,   177,   481,
     482,   126,   484,   485,   486,   487,   152,   197,   490,   145,
     178,   143,   182,   149,   112,   106,   152,     4,   127,   149,
     183,     8,   183,   505,   182,    99,   825,   186,     8,     9,
     293,   186,   152,   515,   516,   262,   214,   215,  1227,   214,
     215,   156,     8,     9,   181,    20,   156,   213,   186,   182,
     149,   229,  1045,   262,   229,   182,  1033,   231,   156,    40,
      41,    42,    43,    44,    45,   746,   747,   891,  1078,   262,
     622,  1408,    53,   262,   170,   874,   262,  1414,  1088,   262,
     246,  1418,   182,   192,   106,   209,   248,   249,   233,   105,
     872,   182,    60,  1159,   241,   577,   106,    78,   260,   960,
    1196,   216,   734,  1326,   656,   741,   994,  1249,   124,   106,
     106,   298,   106,   266,   301,  1011,   252,     8,   217,   218,
     248,   249,   102,   270,   271,   240,   273,   274,    19,   110,
     111,   112,   106,   120,   109,   122,   102,     4,   106,   994,
     120,     8,   122,   130,   133,   298,   121,    30,   301,   355,
      35,   791,   358,   793,   120,    40,   122,    63,    64,   233,
     182,   943,   149,   278,   279,   280,   281,   241,   423,   149,
     145,   106,   182,   153,   149,   106,   106,   152,   149,   385,
     254,   106,   256,   149,   439,   182,   182,   153,   182,   169,
     445,   141,   266,    78,   213,   269,   402,   403,   221,   405,
     223,   354,   154,   169,   816,    51,   149,   196,   182,   152,
     190,   117,    58,     8,     9,    61,    62,  1227,   830,   171,
     105,   171,   117,    69,   190,    99,   144,   246,   208,   120,
     436,   122,   438,   386,     8,   116,    30,    93,   112,   189,
     131,   723,   208,   161,   884,    19,   886,   182,   730,  1345,
     456,   182,   182,   120,   407,   122,   152,   182,   149,   240,
     413,   142,   205,   130,   196,   471,   419,   144,   237,   238,
     423,   477,   154,   205,   155,   956,   828,   829,   134,   196,
     165,   833,   149,   139,   161,   959,   439,   968,   205,   171,
     259,   444,   445,   446,   447,   917,  1184,   278,   279,   280,
     281,   454,   152,   133,   457,   568,   569,   102,   189,   187,
     188,  1304,   194,    94,   467,   867,   146,    65,    66,   165,
      68,   167,     8,     9,   105,   120,   258,   122,   152,  1184,
      65,    66,   264,   241,   115,   181,   489,   134,   491,   821,
     272,    39,   194,   124,   196,   827,   120,    95,   122,   300,
     156,    49,   149,   205,   149,   306,   117,   131,   153,   565,
      95,   207,   270,   271,   570,   273,   274,   117,   850,   117,
    1358,  1359,   578,   408,   169,   149,   221,   412,   584,   585,
     149,   226,   864,   865,  1183,   591,   868,   571,   870,   221,
     574,   223,   576,  1381,  1371,   190,  1284,   652,   258,  1387,
     655,  1225,   134,   228,   264,   230,  1230,   139,   890,    40,
      41,    42,   272,   208,    45,   149,   102,   258,   152,   901,
     902,   903,   263,   905,   906,   907,   908,   909,   910,  1284,
     912,   913,   134,    61,   120,  1288,   122,   139,   920,   149,
    1293,   239,   152,   152,   242,   651,   599,  1335,    95,   228,
     239,   230,    99,   242,   217,   218,   219,   939,   152,   941,
     942,   125,   126,   149,   617,    65,    66,   153,   125,   126,
    1144,   279,   280,   281,   410,   411,   682,  1151,  1152,   117,
    1335,   149,  1163,   169,   547,   548,   554,   555,  1040,   129,
    1314,   556,   557,   149,  1318,   770,   771,   137,   138,   652,
     140,   983,   655,   211,   190,  1286,  1287,   147,   152,   221,
     117,   151,   149,   153,   117,   279,   669,   164,   158,   279,
     279,     0,   208,    95,   186,   186,    91,    99,   163,   251,
      75,   100,   685,   101,   174,   195,   150,   152,  1362,   745,
    1022,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,   149,   149,  1352,   149,  1037,   182,   182,   198,   199,
     200,   201,   202,   203,  1116,    40,    40,    20,  1050,   722,
     148,   117,   279,  1055,  1056,   728,  1058,   268,   149,   785,
     268,  1063,   117,   117,    26,   149,   233,    15,   182,  1263,
    1264,   152,   164,   152,   241,   152,   243,   244,   245,   152,
     152,   182,    20,   209,   227,   182,   253,   254,    39,   256,
     165,   117,   166,   106,   261,   768,   769,   770,   771,   266,
     267,   268,   269,   166,    93,   227,    93,    93,   149,   179,
    1112,   182,   179,   182,   152,   179,    20,   179,   791,   179,
     793,  1123,   106,   106,   156,   156,   124,   129,    20,   282,
     182,   179,  1204,   182,  1136,   182,    95,  1139,    35,  1141,
    1334,   233,    95,   139,   129,   106,   819,   182,   182,   241,
     179,   243,   244,   245,   182,   179,   179,   179,    93,   139,
     221,   179,   254,   166,   256,   233,   186,  1169,   117,   261,
     117,   117,   117,   143,   266,   267,   268,   269,   179,   269,
     180,  1253,   179,    99,   149,   129,   179,   179,   179,   139,
      93,   250,   272,   271,   149,   252,   139,   179,   129,   156,
     129,   257,    95,   193,   117,   117,   143,   139,   149,   246,
    1212,   884,  1214,   886,    26,   179,    20,   117,  1220,   272,
     235,   149,   117,    78,   106,   106,   152,   152,   143,   143,
     182,   247,  1234,  1235,  1236,  1237,  1238,   179,  1240,   247,
      54,   143,   272,   141,    93,   139,   179,    20,   182,    20,
     141,   272,   925,   106,   139,   928,   166,   143,  1260,   182,
     182,   182,   186,   936,   182,   938,   117,   117,    68,   129,
       6,   997,   105,   182,   181,  1277,   105,  1279,   186,   233,
     143,   182,   181,  1009,   265,   117,   182,    93,    20,   229,
     229,   179,   179,   229,    20,   152,   123,    95,  1300,   229,
    1302,   179,  1374,   179,   179,   179,    93,    20,    66,    95,
     117,   181,  1038,   192,   105,   117,   181,    92,   117,   192,
     192,   994,   178,   192,   149,   117,   621,  1018,   255,   503,
     182,  1004,   503,   223,   223,   255,   220,   820,   421,   426,
    1353,   802,  1185,   226,  1070,   987,   507,   227,   430,   928,
     879,  1353,  1053,  1218,   265,  1113,  1125,  1065,  1084,   920,
    1123,  1120,   467,  1047,   995,   527,   549,  1369,  1387,   528,
     686,   290,  1381,  1078,  1047,   771,   819,  1110,  1106,   455,
    1053,   286,   746,   793,  1017,   956,   968,  1163,   747,  1298,
     960,  1064,  1394,  1195,  1158,   957,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   455,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1085,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1106,    -1,    -1,  1109,    -1,    -1,    -1,
    1113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1215,  1216,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1226,    -1,    -1,    -1,    -1,  1231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1278,    -1,    -1,    -1,    -1,
      -1,  1284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1315,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1326,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1365,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1377,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,  1410,    -1,    -1,
      -1,    -1,  1415,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,   121,    -1,   123,
     124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,    -1,    -1,    -1,   142,   143,
     144,   145,   146,   147,   148,    -1,    -1,    -1,   152,   153,
     154,   155,   156,    -1,    -1,    -1,    -1,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,   171,   172,    -1,
      -1,   175,   176,   177,    -1,    -1,    -1,   181,    -1,   183,
     184,   185,    -1,   187,   188,   189,    -1,   191,    -1,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
      -1,    -1,   206,   207,   208,    -1,   210,   211,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,   121,    -1,   123,   124,   125,   126,    -1,   128,    -1,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,   142,   143,   144,   145,   146,   147,   148,    -1,
      -1,    -1,   152,   153,   154,   155,   156,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,   171,   172,    -1,    -1,   175,   176,   177,    -1,    -1,
      -1,   181,   182,   183,   184,   185,    -1,   187,   188,   189,
      -1,   191,    -1,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,    -1,    -1,   206,   207,   208,    -1,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,    -1,   104,   105,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    -1,   121,    -1,   123,   124,   125,   126,
      -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,   152,   153,   154,   155,   156,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,   171,   172,    -1,    -1,   175,   176,
     177,    -1,   179,    -1,   181,    -1,   183,   184,   185,    -1,
     187,   188,   189,    -1,   191,    -1,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,    -1,    -1,   206,
     207,   208,    -1,   210,   211,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,   121,    -1,   123,
     124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,    -1,    -1,    -1,   142,   143,
     144,   145,   146,   147,   148,    -1,    -1,    -1,   152,   153,
     154,   155,   156,    -1,    -1,    -1,    -1,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,   171,   172,    -1,
      -1,   175,   176,   177,    -1,    -1,    -1,   181,   182,   183,
     184,   185,    -1,   187,   188,   189,    -1,   191,    -1,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
      -1,    -1,   206,   207,   208,    -1,   210,   211,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
     121,    -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,   152,   153,   154,   155,   156,    -1,    -1,    -1,    -1,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
     171,   172,    -1,    -1,   175,   176,   177,    -1,   179,    -1,
     181,    -1,   183,   184,   185,    -1,   187,   188,   189,    -1,
     191,    -1,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,    -1,    -1,   206,   207,   208,    -1,   210,
     211,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,   252,    -1,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,   121,    -1,   123,   124,   125,   126,    -1,
     128,    -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,   152,   153,   154,   155,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,   171,   172,    -1,    -1,   175,   176,   177,
      -1,   179,    -1,   181,    -1,   183,   184,   185,    -1,   187,
     188,   189,    -1,   191,    -1,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,    -1,    -1,   206,   207,
     208,    -1,   210,   211,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    -1,   121,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,   152,   153,   154,
     155,   156,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,   171,   172,    -1,    -1,
     175,   176,   177,    -1,   179,    -1,   181,    -1,   183,   184,
     185,    -1,   187,   188,   189,    -1,   191,    -1,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,    -1,
      -1,   206,   207,   208,    -1,   210,   211,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,   121,
      -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,
     132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
     142,   143,   144,   145,   146,   147,   148,    -1,    -1,    -1,
     152,   153,   154,   155,   156,    -1,    -1,    -1,    -1,   161,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,   171,
     172,    -1,    -1,   175,   176,   177,    -1,   179,    -1,   181,
      -1,   183,   184,   185,    -1,   187,   188,   189,    -1,   191,
      -1,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,    -1,    -1,   206,   207,   208,    -1,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,   121,    -1,   123,   124,   125,   126,    -1,   128,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,   152,   153,   154,   155,   156,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,   171,   172,    -1,    -1,   175,   176,   177,    -1,
     179,    -1,   181,    -1,   183,   184,   185,    -1,   187,   188,
     189,    -1,   191,    -1,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,    -1,    -1,   206,   207,   208,
      -1,   210,   211,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,   121,    -1,   123,   124,   125,
     126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,
     136,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,
     146,   147,   148,    -1,    -1,    -1,   152,   153,   154,   155,
     156,    -1,    -1,    -1,    -1,   161,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,   171,   172,    -1,    -1,   175,
     176,   177,    -1,   179,    -1,   181,    -1,   183,   184,   185,
      -1,   187,   188,   189,    -1,   191,    -1,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,    -1,    -1,
     206,   207,   208,    -1,   210,   211,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,   121,    -1,
     123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,   152,
     153,   154,   155,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,   171,   172,
      -1,    -1,   175,   176,   177,    -1,    -1,    -1,   181,    -1,
     183,   184,   185,    -1,   187,   188,   189,    -1,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,    -1,    -1,   206,   207,   208,    -1,   210,   211,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,   121,    -1,   123,   124,   125,   126,    -1,   128,    -1,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,   142,   143,   144,   145,   146,   147,   148,    -1,
      -1,    -1,   152,   153,   154,   155,   156,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,   171,   172,    -1,    -1,   175,   176,   177,    -1,    -1,
      -1,   181,    -1,   183,   184,   185,    -1,   187,   188,   189,
      -1,   191,    -1,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,    -1,    -1,   206,   207,   208,    -1,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,    -1,   104,   105,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    -1,   121,    -1,   123,   124,   125,   126,
      -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,   152,   153,   154,   155,   156,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,   171,   172,    -1,    -1,   175,   176,
     177,    -1,    -1,    -1,   181,    -1,   183,   184,   185,    -1,
     187,   188,   189,    -1,   191,    -1,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,    -1,    -1,   206,
     207,   208,    -1,   210,   211,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,   121,    -1,   123,
     124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,    -1,    -1,    -1,   142,   143,
     144,   145,   146,   147,   148,    -1,    -1,    -1,   152,   153,
     154,   155,   156,    -1,    -1,    -1,    -1,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,   171,   172,    -1,
      -1,   175,   176,   177,    -1,    -1,    -1,   181,    -1,   183,
     184,   185,    -1,   187,   188,   189,    -1,   191,    -1,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
      -1,    -1,   206,   207,   208,    -1,   210,   211,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
     121,    -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,   152,   153,   154,   155,   156,    -1,    -1,    -1,    -1,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
     171,   172,    -1,    -1,   175,   176,   177,    -1,    -1,    -1,
     181,    -1,   183,   184,   185,    -1,   187,   188,   189,    -1,
     191,    -1,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,    -1,    -1,   206,   207,   208,    -1,   210,
     211,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,   252,    -1,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,   121,    -1,   123,   124,   125,   126,    -1,
     128,    -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,   152,   153,   154,   155,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,   171,   172,    -1,    -1,   175,   176,   177,
      -1,    -1,    -1,   181,    -1,   183,   184,   185,    -1,   187,
     188,   189,    -1,   191,    -1,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,    -1,    -1,   206,   207,
     208,    -1,   210,   211,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    -1,   121,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,   152,   153,    -1,
     155,   156,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,
     175,   176,   177,    -1,    -1,    -1,   181,    -1,   183,   184,
     185,    -1,    -1,    -1,   189,    -1,   191,    -1,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,    -1,
      -1,   206,   207,   208,    -1,   210,   211,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    -1,    91,
      -1,    93,    94,    95,    96,    -1,    -1,    99,   100,   101,
      -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,   110,   111,
     112,    -1,    -1,   115,   116,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,   143,   144,    -1,   146,   147,   148,    -1,    -1,    -1,
      -1,    -1,    -1,   155,   156,    -1,    -1,    -1,    -1,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,   181,
      -1,   183,   184,    -1,    -1,    -1,    -1,   189,    -1,   191,
      -1,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,    -1,    -1,   206,   207,    -1,    -1,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    -1,    91,    -1,    93,    94,    95,    96,    -1,    -1,
      99,   100,   101,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,   110,   111,   112,    -1,    -1,   115,   116,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,   125,   126,    -1,   128,
      -1,    -1,    -1,   132,   133,   134,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,   144,    -1,   146,   147,   148,
      -1,    -1,    -1,    -1,    -1,    -1,   155,   156,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,   181,    -1,   183,    -1,    -1,    -1,    -1,    -1,
     189,    -1,   191,    -1,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,    -1,    -1,   206,   207,    -1,
      -1,   210,   211,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,    14,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    93,    94,    95,    96,    -1,    -1,    99,
     100,   101,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
     110,   111,   112,    -1,    -1,   115,   116,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,   125,   126,    -1,   128,    -1,
      -1,    -1,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,   144,    -1,   146,   147,   148,   149,
      -1,    -1,   152,    -1,    -1,   155,   156,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,   181,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,    -1,    -1,   206,   207,    -1,    -1,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,    14,    -1,    -1,    -1,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    -1,
      91,    -1,    93,    94,    95,    96,    -1,    -1,    99,   100,
     101,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,   110,
     111,   112,    -1,    -1,   115,   116,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   143,   144,    -1,   146,   147,   148,    -1,    -1,
      -1,    -1,    -1,    -1,   155,   156,    -1,    -1,    -1,    -1,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,    -1,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,    -1,    -1,   206,   207,    -1,    -1,   210,
     211,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,   252,    -1,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    -1,    91,
      -1,    93,    94,    95,    96,    -1,    -1,    99,   100,   101,
      -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,   110,   111,
     112,    -1,    -1,   115,   116,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,   143,   144,    -1,   146,   147,   148,    -1,    -1,    -1,
      -1,    -1,    -1,   155,   156,    -1,    -1,    -1,    -1,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,   181,
      -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,
      -1,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,    -1,    -1,   206,   207,    -1,    -1,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    -1,    93,    94,
      95,    96,    -1,    -1,    99,   100,   101,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,   110,   111,   112,    -1,    -1,
     115,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
      -1,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
     155,   156,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,   181,    -1,   183,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,    -1,
      -1,   206,   207,    -1,    -1,   210,   211,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    93,    94,    95,    96,    -1,    -1,    99,
     100,   101,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
     110,   111,   112,    -1,    -1,   115,   116,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,   125,   126,    -1,   128,    -1,
      -1,    -1,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,   144,    -1,   146,   147,   148,   149,
      -1,    -1,   152,    -1,    -1,   155,   156,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,   181,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,    -1,    -1,   206,   207,    -1,    -1,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    -1,    93,    94,
      95,    96,    -1,    -1,    99,   100,   101,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,   110,   111,   112,    -1,    -1,
     115,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
      -1,   146,   147,   148,   149,    -1,    -1,   152,    -1,    -1,
     155,   156,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,   181,    -1,   183,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,    -1,
      -1,   206,   207,    -1,    -1,   210,   211,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    93,    94,    95,    96,    -1,    -1,    99,
     100,   101,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
     110,   111,   112,    -1,    -1,   115,   116,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,   125,   126,    -1,   128,    -1,
      -1,    -1,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,   144,    -1,   146,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,   155,   156,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,    -1,    -1,   189,
      -1,   191,    -1,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,    -1,    -1,   206,   207,    -1,    -1,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    -1,    93,    94,
      95,    96,    -1,    -1,    99,   100,   101,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,   110,   111,   112,    -1,    -1,
     115,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
      -1,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
     155,   156,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,    -1,    -1,   189,    -1,   191,    -1,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,    -1,
      -1,   206,   207,    -1,    -1,   210,   211,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    93,    94,    95,    96,    -1,    -1,    99,
     100,   101,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
     110,   111,   112,    -1,    -1,   115,   116,   117,    -1,    -1,
      -1,    -1,    -1,   123,   124,   125,   126,    -1,   128,    -1,
      -1,    -1,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,   144,    -1,   146,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,   155,   156,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,   181,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,    -1,    -1,   206,   207,    -1,    -1,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    -1,    93,    94,
      95,    96,    -1,    -1,    99,   100,   101,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,   110,   111,   112,    -1,    -1,
     115,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
      -1,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
     155,   156,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,   181,    -1,   183,   184,
      -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,    -1,
      -1,   206,   207,    -1,    -1,   210,   211,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    93,    94,    95,    96,    -1,    -1,    99,
     100,   101,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
     110,   111,   112,    -1,    -1,   115,   116,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,   125,   126,    -1,   128,    -1,
      -1,    -1,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,   144,    -1,   146,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,   155,   156,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,   181,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,    -1,    -1,   206,   207,    -1,    -1,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    -1,    93,    94,
      95,    96,    -1,    -1,    99,   100,   101,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,   110,   111,   112,    -1,    -1,
     115,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
      -1,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
     155,   156,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,   181,    -1,   183,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,    -1,
      -1,   206,   207,    -1,    -1,   210,   211,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    10,    17,    18,    20,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   104,   105,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   121,   123,   124,   125,   126,   128,   132,   133,   134,
     135,   136,   142,   143,   144,   145,   146,   147,   148,   152,
     153,   154,   155,   156,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   171,   172,   175,   176,   177,   181,   183,
     184,   185,   187,   188,   189,   191,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   206,   207,   208,
     210,   211,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   251,
     252,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   329,   330,   335,   337,
     344,   346,   351,   352,   353,   354,   355,   356,   364,   365,
     367,   368,   369,   374,   376,   378,   379,   380,   385,   406,
     409,   412,   413,   414,   415,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   462,   463,   464,   478,   479,
     481,   482,   483,   484,   485,   486,   487,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   506,   507,   508,
     509,   510,   511,   512,   515,   521,   522,   523,   149,   347,
     233,    30,    30,   152,    93,   149,   217,   218,   152,    27,
      28,    29,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    46,    47,    49,    50,    52,    57,    58,    60,    61,
      62,    72,    73,    96,   132,   149,   152,   164,   197,   210,
     220,   221,   222,   224,   225,   232,   234,   236,   275,   276,
     277,   521,   149,   149,   152,   149,   152,    40,    41,    42,
      43,    44,    45,    53,    59,    70,    71,    74,    77,    78,
     110,   111,   112,   156,   216,   240,   278,   279,   280,   281,
     336,   338,   339,   340,   357,   358,   152,    14,   149,   152,
     520,   521,    52,    55,   117,   156,   117,   117,   149,    63,
      64,   117,   371,    61,   152,   152,   149,   152,   521,    35,
      37,    38,    47,    96,   446,   521,   521,   117,   182,   365,
     521,   149,   520,    16,   521,   521,   438,   149,    21,   209,
     211,   221,   223,   152,   221,   223,   221,   221,   226,   117,
     149,   117,   279,   279,   279,   300,     0,   302,   303,    39,
      49,   305,   364,   186,   186,   106,   186,   366,    51,    58,
      61,    62,    69,   165,   167,   181,   207,   370,   375,   376,
     377,   394,   395,   399,   381,   382,   521,   163,    91,   129,
     137,   138,   140,   147,   151,   153,   158,   174,   198,   199,
     200,   201,   202,   203,   430,   431,   251,   154,   171,   194,
     116,   142,   155,   189,   196,   205,   133,   146,    75,   195,
     100,   101,   154,   171,   429,   149,   435,   438,   187,   188,
     150,   450,   451,   446,   450,   446,   450,   152,   348,   368,
     368,   504,   521,   365,   149,   149,   365,   365,   182,   189,
     521,   149,   365,   365,   182,   365,   182,   521,   358,    40,
     359,   357,   357,   358,   521,   177,   191,   164,   197,    20,
     519,   162,   177,   177,   191,   521,   148,   117,   334,    35,
      40,    78,   105,   165,   520,   217,   218,   219,    99,   233,
     241,   254,   256,   266,   269,   535,   536,   537,   538,   539,
     542,   547,   548,   339,   519,   340,   365,   365,    20,   182,
     520,   149,   156,   519,   112,   156,   328,   519,   407,   408,
     521,   520,   521,   386,   388,   521,   368,   268,   268,   117,
     389,   117,   521,    35,    72,   182,   502,   503,   365,   182,
     189,   521,   149,   407,   182,    26,   466,   467,   468,   365,
       7,   170,    15,   182,   365,   209,    20,   368,   368,   182,
     368,   368,   368,   368,   227,   513,   514,   521,   368,   387,
     393,   521,   519,   519,   519,   307,   308,    39,   309,   368,
     367,   165,   117,   166,   166,   368,   368,   106,    93,    95,
     143,   262,   383,   384,   489,   414,   415,   417,   417,   417,
     417,   416,   417,   417,   417,   149,   152,   252,   453,   524,
     526,   527,   528,   529,   530,   531,   532,   420,   420,   419,
     421,   421,   421,   421,   422,   422,   423,   423,   227,    93,
      93,    93,   179,   365,   438,   438,   365,   451,   182,   368,
     461,    39,   349,   365,   182,   149,   179,   365,   365,   182,
     179,   106,   182,   106,   182,   179,   365,   179,   179,   179,
     152,   345,   521,    20,   106,   106,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,   311,   312,   313,    93,
     134,   139,   331,   332,   333,   521,   134,   139,   156,   156,
     311,   519,   124,   129,   239,   242,   112,   241,   270,   271,
     273,   274,   239,   242,    20,   241,   270,   271,   273,   274,
     282,   182,   179,   182,   182,   179,   365,   520,    95,    35,
     520,   519,    95,   106,   183,   143,   489,   129,   139,   106,
     139,   384,   489,   179,   521,    67,   213,   246,   372,   373,
     182,   182,   182,   179,   106,   182,   106,   182,   179,   365,
     183,   521,   467,   468,   127,   192,   179,   179,   128,   186,
      93,   214,   215,   229,    93,   214,   215,   229,    93,   233,
     221,   106,   231,   139,   179,    60,   106,   186,   112,   186,
     166,   521,   368,   400,   401,   117,   396,   397,   117,   148,
     206,   490,   492,   493,   494,   521,   117,   368,   117,   143,
     384,   143,   143,   383,   384,   417,   365,   524,   530,   269,
     558,    95,   164,   243,   244,   245,   253,   261,   267,   268,
     525,   533,   534,   535,   549,   552,   553,   555,   250,   252,
     257,   554,   237,   238,   259,   550,   490,   490,   488,   493,
     488,   179,   180,   106,   182,   334,   350,   106,   186,   179,
     347,   365,   179,   179,    99,   410,   411,   149,   504,   505,
     521,   504,   505,   179,   117,   182,   360,   361,   134,   149,
     363,   345,   144,   161,   144,   161,   312,   129,   492,   333,
     368,   489,   139,   368,   519,   519,   125,   126,   519,   271,
     272,    95,   112,   152,   541,   272,   368,   193,   149,   179,
     129,   327,   519,   156,   129,    95,   327,   117,   368,   368,
     143,   519,   368,   117,   368,   139,   139,   384,   143,   489,
     246,    65,    66,    68,   117,   383,   390,   391,   392,   373,
     149,   504,   504,   179,   368,    26,   468,   127,   192,     8,
       9,   102,   120,   122,   149,   190,   362,   463,   465,   476,
     477,   480,    20,   228,   230,   368,   368,   368,   228,   230,
     368,   368,   368,   368,   368,   368,   117,   368,   368,   235,
     516,   517,   149,   117,   400,    94,   105,   115,   124,   402,
     403,   404,   405,   106,   521,   106,   382,   152,   152,   141,
     171,   189,   491,   521,   521,   368,   143,   368,   368,   143,
     384,   143,   179,   182,   247,   213,   246,   258,   263,   557,
      95,   248,   249,   551,   247,   527,   557,   418,   421,   267,
     533,   535,   528,   143,   551,   272,    54,   141,   368,   139,
     350,   179,   117,   490,   112,   411,   179,   365,   182,   182,
     141,   182,   182,   521,    93,   106,   182,   365,   347,   506,
     332,   368,   272,    95,   152,   544,    20,   112,   541,   166,
     368,   179,   365,   519,   106,   327,   408,   368,   186,   388,
     368,   368,   139,   368,   143,   117,   117,   368,   521,   392,
      68,   179,   365,   182,   182,   129,   190,   465,     6,   365,
     521,   190,   476,   186,   229,   229,   229,   229,   233,   514,
     181,   447,   518,   517,   368,   393,   519,   125,   126,   404,
     405,   405,   401,   105,   398,   397,   182,   182,   368,   368,
     143,   368,   421,    48,   126,   421,   421,   258,   264,   272,
     556,   556,   418,   529,   265,   368,   521,   181,   117,   181,
     179,   489,   490,   361,    93,   179,   133,   196,   543,   546,
      20,    20,   545,   543,   260,   551,   106,   182,   106,   182,
     152,   343,   123,   179,    95,   519,   368,   368,   521,   521,
     391,   368,   179,   468,   521,   190,   179,   468,   521,   368,
     368,   368,   368,   368,   368,   152,   205,   363,   179,   405,
     519,   368,   421,   421,   194,    93,   368,   521,   368,   490,
     544,   544,   546,    20,   182,    20,   255,   540,   541,   540,
     341,   342,   368,   106,   182,   368,   327,    66,    92,   178,
     469,   468,   521,   192,   468,   117,   447,   421,   490,   181,
     551,   106,   182,   182,   105,   489,   341,   117,     4,   130,
     472,   473,   475,   477,    19,   131,   470,   471,   474,   477,
     192,   468,   192,   521,   181,   368,   255,   541,   519,   521,
      92,   130,   475,   178,   131,   474,   192,   106,   182,   368,
     117,   363,   521,   106,   182,   117,   363,   521,   182,   363
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
     545,   546,   547,   548,   549,   550,   551,   552
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   298,   299,   299,   300,   300,   300,   300,   301,   301,
     302,   302,   303,   304,   305,   305,   305,   306,   306,   307,
     307,   308,   308,   308,   308,   309,   309,   309,   309,   309,
     309,   309,   310,   310,   311,   311,   312,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   314,   314,   314,
     314,   314,   314,   314,   314,   315,   315,   316,   317,   317,
     318,   318,   319,   320,   321,   321,   322,   322,   323,   323,
     323,   323,   324,   325,   326,   326,   326,   326,   327,   327,
     328,   328,   329,   329,   329,   329,   330,   331,   331,   332,
     332,   332,   333,   334,   334,   335,   335,   335,   336,   336,
     337,   338,   338,   339,   339,   340,   341,   341,   342,   342,
     343,   343,   344,   344,   345,   345,   345,   345,   346,   347,
     348,   348,   349,   349,   350,   350,   351,   352,   353,   354,
     354,   355,   355,   355,   356,   356,   356,   357,   357,   357,
     357,   358,   358,   359,   360,   360,   361,   361,   362,   363,
     364,   365,   365,   366,   366,   367,   367,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   369,   370,   371,   371,   372,
     372,   372,   373,   373,   374,   374,   375,   376,   376,   376,
     377,   377,   377,   377,   377,   378,   378,   379,   379,   380,
     381,   381,   382,   382,   382,   382,   382,   382,   382,   382,
     383,   384,   385,   386,   386,   387,   387,   388,   388,   388,
     388,   389,   389,   390,   390,   390,   391,   391,   391,   392,
     392,   392,   393,   394,   395,   396,   396,   397,   397,   398,
     399,   399,   400,   400,   401,   401,   402,   402,   402,   402,
     402,   402,   402,   403,   403,   404,   404,   405,   406,   406,
     407,   407,   408,   408,   409,   409,   410,   410,   411,   411,
     412,   413,   413,   414,   414,   415,   415,   415,   415,   415,
     416,   415,   415,   415,   415,   417,   417,   417,   418,   418,
     419,   419,   419,   420,   420,   420,   420,   420,   421,   421,
     421,   422,   422,   422,   423,   423,   424,   424,   425,   425,
     426,   426,   427,   427,   428,   428,   428,   428,   429,   429,
     429,   430,   430,   430,   430,   430,   430,   431,   431,   431,
     432,   432,   432,   432,   433,   433,   434,   434,   435,   435,
     436,   436,   436,   436,   437,   438,   438,   438,   439,   439,
     440,   440,   440,   440,   441,   441,   442,   442,   442,   442,
     442,   442,   442,   443,   443,   444,   444,   445,   445,   445,
     445,   445,   446,   446,   447,   447,   448,   448,   448,   449,
     449,   450,   450,   451,   452,   452,   452,   452,   452,   452,
     452,   452,   453,   453,   454,   454,   454,   455,   456,   456,
     457,   458,   459,   460,   460,   461,   461,   462,   462,   463,
     463,   463,   464,   464,   464,   464,   464,   464,   465,   465,
     466,   466,   467,   468,   468,   469,   469,   470,   470,   471,
     471,   471,   471,   472,   472,   473,   473,   473,   473,   474,
     474,   475,   475,   476,   476,   476,   476,   477,   477,   477,
     477,   478,   478,   479,   479,   480,   481,   481,   481,   481,
     481,   481,   482,   483,   483,   483,   483,   484,   484,   484,
     484,   485,   486,   487,   487,   487,   487,   488,   488,   489,
     490,   490,   490,   491,   491,   491,   492,   492,   492,   493,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   495,
     496,   496,   496,   497,   498,   499,   499,   499,   500,   500,
     500,   500,   500,   501,   502,   502,   502,   502,   502,   502,
     502,   503,   504,   505,   506,   507,   507,   507,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   509,   509,
     510,   510,   511,   512,   513,   513,   514,   515,   516,   516,
     517,   517,   517,   517,   518,   518,   519,   520,   520,   521,
     521,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   523,   523,   524,   524,
     524,   524,   525,   525,   525,   525,   526,   526,   527,   527,
     528,   528,   529,   529,   530,   530,   530,   531,   531,   532,
     532,   533,   533,   533,   533,   533,   534,   535,   535,   535,
     535,   535,   535,   535,   536,   536,   536,   536,   537,   537,
     537,   537,   538,   538,   539,   539,   539,   539,   539,   539,
     539,   540,   540,   541,   541,   541,   541,   542,   542,   542,
     542,   542,   543,   543,   544,   544,   545,   545,   546,   546,
     547,   548,   548,   549,   549,   549,   550,   550,   550,   550,
     550,   551,   551,   551,   551,   552,   553,   554,   555,   555,
     556,   556,   556,   557,   557,   558
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     1,     2,     4,     6,
       2,     1,     2,     6,     2,     2,     4,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     3,     3,
       5,     5,     4,     3,     3,     3,     5,     5,     5,     5,
       5,     5,     4,     3,     3,     4,     5,     6,     1,     3,
       3,     3,     3,     6,     5,     8,     4,     3,     1,     1,
       1,     2,     2,     2,     3,     5,     4,     6,     1,     1,
       2,     1,     2,     1,     2,     7,     1,     3,     1,     2,
       2,     3,     3,     3,     2,     3,     4,     5,     2,     4,
       3,     0,     3,     2,     1,     3,     5,     3,     5,     2,
       2,     3,     3,     3,     2,     3,     3,     1,     2,     2,
       2,     4,     4,     4,     1,     3,     2,     3,     3,     3,
       1,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     2,     4,     3,     5,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     2,
       1,     4,     3,     4,     4,     5,     4,     5,     5,     6,
       3,     3,     3,     1,     4,     1,     4,     3,     4,     4,
       5,     4,     5,     1,     2,     3,     1,     2,     1,     6,
       3,     3,     1,     2,     3,     1,     3,     2,     3,     2,
       3,     4,     1,     3,     1,     2,     1,     1,     1,     2,
       2,     2,     3,     1,     1,     2,     2,     2,     5,     5,
       1,     4,     3,     4,     8,    10,     1,     2,     4,     7,
       8,     1,     3,     1,     3,     1,     3,     3,     3,     3,
       0,     4,     3,     3,     3,     1,     3,     4,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     4,     1,     4,     1,     4,
       1,     4,     1,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     5,     6,     3,     4,     1,     2,     3,     2,
       1,     2,     2,     1,     1,     1,     3,     3,     1,     1,
       1,     2,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     4,     4,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     4,     5,     8,     9,     9,    10,     1,     2,
       1,     2,     6,     0,     1,     3,     3,     0,     1,     1,
       1,     2,     2,     0,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     4,     4,     5,     6,     7,     4,     5,     6,
       7,     4,     4,     4,     5,     6,     7,     1,     2,     2,
       1,     2,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     4,     4,     3,     3,     3,     4,     4,     3,     4,
       6,     4,     6,     3,     3,     4,     6,     6,     4,     6,
       6,     4,     1,     2,     1,     3,     3,     3,     5,     7,
       7,     5,     5,     5,     7,     7,     5,     5,     3,     3,
       5,     7,     5,     7,     1,     4,     3,     5,     1,     2,
       3,     7,    10,    13,     1,     3,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     7,     4,     1,     2,
       3,     4,     1,     1,     2,     2,     1,     3,     1,     3,
       1,     4,     1,     2,     1,     2,     3,     1,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     3,     5,     7,     5,     7,
       2,     1,     3,     2,     4,     4,     6,     4,     5,     4,
       5,     3,     1,     2,     2,     3,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     1,     2,
       1,     2,     3,     3,     4,     3,     3,     3,     2,     2,
       1,     1,     1,     1,     1,     3
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
  "\"'STRING'\"", "\"'XML comment'\"", "\"'QName'\"", "\"'URI'\"",
  "\"'NCName'\"", "\"'KEYWORD'\"", "\"<blank>\"", "\"'block'\"",
  "\"'exit'\"", "\"'break'\"", "\"'loop'\"", "\"'continue'\"",
  "\"'while'\"", "\"'validate'\"", "\"'typeswitch'\"", "\"'element'\"",
  "\"'document'\"", "\"'text'\"", "\"'comment'\"", "\"'declare'\"",
  "\"'function'\"", "\"'updating'\"", "\"'sequential'\"",
  "\"'deterministic'\"", "\"'nondeterministic'\"", "\"'simple'\"",
  "\"'if'\"", "\"'processing-instruction'\"", "\"'most'\"", "\"'import'\"",
  "\"'some'\"", "\"'stable'\"", "\"'module'\"", "\"'option'\"",
  "\"'word'\"", "\"'schema'\"", "\"'space'\"", "\"'set'\"", "\"'let'\"",
  "\"'construction'\"", "\"'eval'\"", "\"'for'\"", "\"'outer'\"",
  "\"'sliding'\"", "\"'tumbling'\"", "\"'previous'\"", "\"'next'\"",
  "\"'only'\"", "\"'when'\"", "\"'count'\"", "\"'ordering'\"",
  "\"'base-uri'\"", "\"'schema-element'\"", "\"'document-node'\"",
  "\"'copy-namespaces'\"", "\"'instance'\"", "\"'schema-attribute'\"",
  "\"'boundary-space'\"", "\"'decimal-format'\"",
  "\"'decimal-separator'\"", "\"'grouping-separator'\"", "\"'infinity'\"",
  "\"'minus-sign'\"", "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"",
  "\"'zero-digit'\"", "\"'digit'\"", "\"'pattern-separator'\"",
  "\"'ancestor::'\"", "\"'ancestor-or-self::'\"", "\"'and'\"", "\"'''\"",
  "\"'as'\"", "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"",
  "\"'attribute::'\"", "\"'@'\"", "\"'case'\"", "\"'castable'\"",
  "\"'cast'\"", "\"'CDATA[['\"", "\"']]'\"", "\"'child::'\"",
  "\"'collation'\"", "\"','\"", "\"'(:'\"", "\"':)'\"", "\"'DECIMAL'\"",
  "\"'context'\"", "\"'variable'\"", "\"'default'\"", "\"'descendant::'\"",
  "\"'descendant-or-self::'\"", "\"'descending'\"", "\"'div'\"", "\"'$'\"",
  "\"'.'\"", "\"'..'\"", "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"",
  "\"'else'\"", "\"'empty'\"", "\"'greatest'\"", "\"'least'\"", "\"'/>'\"",
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
  "\"'copy'\"", "\"'with'\"", "\"'try'\"", "\"'catch'\"", "\"'using'\"",
  "\"'all'\"", "\"'any'\"", "\"'casesensitive'\"", "\"'ft-option'\"",
  "\"'diacritics'\"", "\"'insensitive'\"", "\"'different'\"",
  "\"'distance'\"", "\"'entire'\"", "\"'end'\"", "\"'content'\"",
  "\"'exactly'\"", "\"'from'\"", "\"'&&'\"", "\"'ftcontains'\"",
  "\"'not'\"", "\"'||'\"", "\"'language'\"", "\"'levels'\"",
  "\"'lowercase'\"", "\"'occurs'\"", "\"'paragraph'\"", "\"'phrase'\"",
  "\"'relationship'\"", "\"'same'\"", "\"'score'\"", "\"'sentence'\"",
  "\"'sentences'\"", "\"'times'\"", "\"'uppercase'\"", "\"'weight'\"",
  "\"'window'\"", "\"'without'\"", "\"'stemming'\"", "\"'stop'\"",
  "\"'words'\"", "\"'thesaurus'\"", "\"'wildcards'\"", "\"'create'\"",
  "\"'build'\"", "\"'drop'\"", "\"'unique'\"", "\"'index'\"", "\"'hash'\"",
  "\"'btree'\"", "\"'on'\"", "\"'BOM_UTF8'\"", "FTCONTAINS_REDUCE",
  "RANGE_REDUCE", "ADDITIVE_REDUCE", "MULTIPLICATIVE_REDUCE",
  "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE",
  "COMMA_DOLLAR", "UNARY_PREC", "SEQUENCE_TYPE_REDUCE", "OCCURS_STAR",
  "OCCURS_PLUS", "OCCURS_HOOK", "STEP_REDUCE", "$accept", "Module",
  "ModuleWithoutBOM", "VersionDecl", "MainModule", "LibraryModule",
  "ModuleDecl", "Prolog", "SIND_DeclList", "VFO_DeclList", "SIND_Decl",
  "VFO_Decl", "DecimalFormatDecl", "DecimalFormatParamList",
  "DecimalFormatParam", "DecimalFormatParamName", "Setter", "Import",
  "NamespaceDecl", "BoundarySpaceDecl", "DefaultNamespaceDecl",
  "OptionDecl", "FTOptionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "DefaultCollationDecl", "BaseURIDecl",
  "SchemaImport", "URILiteralList", "SchemaPrefix", "ModuleImport",
  "CtxItemDecl", "CtxItemDecl2", "CtxItemDecl3", "CtxItemDecl4",
  "VarNameAndType", "VarDecl", "IndexingMethod", "IndexDecl", "IndexDecl2",
  "IndexDecl3", "IndexDeclSuffix", "IndexField", "IndexField1",
  "IndexFieldList", "ConstructionDecl", "FunctionSig", "BlockExpr",
  "Block", "BlockDecls", "BlockVarDeclList", "BlockVarDecl", "AssignExpr",
  "ExitExpr", "WhileExpr", "FlowCtlStatement", "IndexStatement",
  "FunctionDecl", "FunctionDecl2", "FunctionDecl3", "FunctionDecl4",
  "ParamList", "Param", "EnclosedExpr", "BracedExpr", "QueryBody", "Expr",
  "ApplyExpr", "ConcatExpr", "ExprSingle", "FLWORExpr", "ReturnExpr",
  "WindowType", "FLWORWinCondType", "FLWORWinCond", "WindowClause",
  "CountClause", "ForLetWinClause", "FLWORClause", "FLWORClauseList",
  "ForDollar", "ForClause", "VarInDeclList", "VarInDecl", "PositionalVar",
  "FTScoreVar", "LetClause", "VarGetsDeclList", "EvalVarDeclList",
  "VarGetsDecl", "WindowVarDecl", "WindowVars", "WindowVars3",
  "WindowVars2", "EvalVarDecl", "WhereClause", "GroupByClause",
  "GroupSpecList", "GroupSpec", "GroupCollationSpec", "OrderByClause",
  "OrderSpecList", "OrderSpec", "OrderModifier", "OrderDirSpec",
  "OrderEmptySpec", "OrderCollationSpec", "QuantifiedExpr",
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
       299,     0,    -1,   300,    -1,   283,   300,    -1,   302,    -1,
     301,   302,    -1,   303,    -1,   301,   303,    -1,   210,   211,
      20,   186,    -1,   210,   211,    20,   128,    20,   186,    -1,
     305,   364,    -1,   364,    -1,   304,   305,    -1,    52,   156,
     520,   129,   519,   186,    -1,   306,   186,    -1,   307,   186,
      -1,   306,   186,   307,   186,    -1,   308,    -1,   306,   186,
     308,    -1,   309,    -1,   307,   186,   309,    -1,   314,    -1,
     315,    -1,   316,    -1,   318,    -1,   335,    -1,   330,    -1,
     356,    -1,   319,    -1,   320,    -1,   337,    -1,   310,    -1,
      39,   112,    78,   311,    -1,    39,    78,   521,   311,    -1,
     312,    -1,   311,   312,    -1,   313,   129,   506,    -1,    79,
      -1,    80,    -1,    81,    -1,    82,    -1,    83,    -1,    84,
      -1,    85,    -1,    86,    -1,    87,    -1,    88,    -1,   317,
      -1,   324,    -1,   325,    -1,   344,    -1,   321,    -1,   322,
      -1,   323,    -1,   507,    -1,   326,    -1,   329,    -1,    39,
     156,   520,   129,   519,    -1,    39,    77,   177,    -1,    39,
      77,   191,    -1,    39,   112,    35,   156,   519,    -1,    39,
     112,    40,   156,   519,    -1,    39,    53,   521,    20,    -1,
      39,   240,   535,    -1,    39,    70,   164,    -1,    39,    70,
     197,    -1,    39,   112,   165,   124,   125,    -1,    39,   112,
     165,   124,   126,    -1,    39,    74,   177,   106,   144,    -1,
      39,    74,   177,   106,   161,    -1,    39,    74,   162,   106,
     144,    -1,    39,    74,   162,   106,   161,    -1,    39,   112,
     105,   519,    -1,    39,    71,   519,    -1,    49,    55,   519,
      -1,    49,    55,   328,   519,    -1,    49,    55,   519,    95,
     327,    -1,    49,    55,   328,   519,    95,   327,    -1,   519,
      -1,   327,   106,   519,    -1,   156,   520,   129,    -1,   112,
      35,   156,    -1,    49,    52,   519,    -1,    49,    52,   156,
     520,   129,   519,    -1,    49,    52,   519,    95,   327,    -1,
      49,    52,   156,   520,   129,   519,    95,   327,    -1,    39,
     110,   148,   331,    -1,    93,   492,   332,    -1,   332,    -1,
     333,    -1,   134,    -1,   134,   333,    -1,   139,   368,    -1,
     117,   521,    -1,   117,   521,   489,    -1,    39,   111,   334,
     139,   368,    -1,    39,   111,   334,   134,    -1,    39,   111,
     334,   134,   139,   368,    -1,   280,    -1,   281,    -1,    39,
     338,    -1,   339,    -1,   278,   339,    -1,   340,    -1,   336,
     340,    -1,   279,   519,   282,   368,   166,   343,   182,    -1,
     342,    -1,   342,   105,   519,    -1,   368,    -1,   368,   489,
      -1,   152,   341,    -1,   343,   106,   341,    -1,    39,    59,
     177,    -1,    39,    59,   191,    -1,   152,   182,    -1,   152,
     360,   182,    -1,   152,   182,    93,   490,    -1,   152,   360,
     182,    93,   490,    -1,    27,   347,    -1,   149,   348,   365,
     179,    -1,   348,   349,   186,    -1,    -1,   349,   106,   350,
      -1,    39,   350,    -1,   334,    -1,   334,   139,   368,    -1,
      57,   117,   521,   139,   368,    -1,    28,   233,   368,    -1,
      32,   152,   368,   182,   347,    -1,    29,    30,    -1,    31,
      30,    -1,   275,   279,   519,    -1,   277,   279,   519,    -1,
     276,   279,   519,    -1,    39,   357,    -1,    39,    44,   357,
      -1,    39,    43,   357,    -1,   358,    -1,    45,   358,    -1,
      41,   358,    -1,    42,   359,    -1,    40,   521,   345,   363,
      -1,    40,   521,   345,   134,    -1,    40,   521,   345,   347,
      -1,   361,    -1,   360,   106,   361,    -1,   117,   521,    -1,
     117,   521,   489,    -1,   149,   365,   179,    -1,   149,   365,
     179,    -1,   365,    -1,   367,    -1,   367,   366,    -1,   186,
      -1,   366,   367,   186,    -1,   368,    -1,   367,   106,   368,
      -1,   369,    -1,   406,    -1,   409,    -1,   412,    -1,   413,
      -1,   508,    -1,   509,    -1,   511,    -1,   510,    -1,   512,
      -1,   515,    -1,   523,    -1,   352,    -1,   353,    -1,   354,
      -1,   351,    -1,   346,    -1,   355,    -1,   378,   370,    -1,
     181,   368,    -1,    63,   268,    -1,    64,   268,    -1,   213,
      -1,   246,    -1,    67,   246,    -1,   372,   390,    68,   368,
      -1,   372,    68,   368,    -1,    61,   371,   389,   373,   373,
      -1,    61,   371,   389,   373,    -1,    69,   117,   521,    -1,
     380,    -1,   385,    -1,   374,    -1,   376,    -1,   394,    -1,
     399,    -1,   395,    -1,   375,    -1,   376,    -1,   378,   377,
      -1,    61,   117,    -1,    62,    61,   117,    -1,   379,   381,
      -1,   382,    -1,   381,   106,   117,   382,    -1,   521,   143,
     368,    -1,   521,   489,   143,   368,    -1,   521,   383,   143,
     368,    -1,   521,   489,   383,   143,   368,    -1,   521,   384,
     143,   368,    -1,   521,   489,   384,   143,   368,    -1,   521,
     383,   384,   143,   368,    -1,   521,   489,   383,   384,   143,
     368,    -1,    95,   117,   521,    -1,   262,   117,   521,    -1,
      58,   117,   386,    -1,   388,    -1,   386,   106,   117,   388,
      -1,   393,    -1,   387,   106,   117,   393,    -1,   521,   139,
     368,    -1,   521,   489,   139,   368,    -1,   521,   384,   139,
     368,    -1,   521,   489,   384,   139,   368,    -1,   117,   521,
     143,   368,    -1,   117,   521,   489,   143,   368,    -1,   391,
      -1,   117,   521,    -1,   117,   521,   391,    -1,   383,    -1,
     383,   392,    -1,   392,    -1,    65,   117,   521,    66,   117,
     521,    -1,    66,   117,   521,    -1,    65,   117,   521,    -1,
     521,    -1,   207,   368,    -1,   167,   166,   396,    -1,   397,
      -1,   396,   106,   397,    -1,   117,   521,    -1,   117,   521,
     398,    -1,   105,   519,    -1,   165,   166,   400,    -1,    51,
     165,   166,   400,    -1,   401,    -1,   400,   106,   401,    -1,
     368,    -1,   368,   402,    -1,   403,    -1,   404,    -1,   405,
      -1,   403,   404,    -1,   403,   405,    -1,   404,   405,    -1,
     403,   404,   405,    -1,    94,    -1,   115,    -1,   124,   125,
      -1,   124,   126,    -1,   105,   519,    -1,    50,   117,   407,
     183,   368,    -1,   132,   117,   407,   183,   368,    -1,   408,
      -1,   407,   106,   117,   408,    -1,   521,   143,   368,    -1,
     521,   489,   143,   368,    -1,    34,   152,   365,   182,   410,
     112,   181,   368,    -1,    34,   152,   365,   182,   410,   112,
     117,   521,   181,   368,    -1,   411,    -1,   410,   411,    -1,
      99,   490,   181,   368,    -1,    99,   117,   521,    93,   490,
     181,   368,    -1,    46,   152,   365,   182,   193,   368,   123,
     368,    -1,   414,    -1,   413,   163,   414,    -1,   415,    -1,
     414,    91,   415,    -1,   417,    -1,   417,   430,   417,    -1,
     417,   431,   417,    -1,   417,   129,   417,    -1,   417,   158,
     417,    -1,    -1,   417,   153,   416,   417,    -1,   417,   151,
     417,    -1,   417,   140,   417,    -1,   417,   138,   417,    -1,
     418,    -1,   418,   251,   524,    -1,   418,   251,   524,   558,
      -1,   419,    -1,   419,   194,   419,    -1,   420,    -1,   419,
     171,   420,    -1,   419,   154,   420,    -1,   421,    -1,   420,
     189,   421,    -1,   420,   116,   421,    -1,   420,   142,   421,
      -1,   420,   155,   421,    -1,   422,    -1,   421,   196,   422,
      -1,   421,   205,   422,    -1,   423,    -1,   422,   146,   423,
      -1,   422,   133,   423,    -1,   424,    -1,   424,    75,   227,
     490,    -1,   425,    -1,   425,   195,    93,   490,    -1,   426,
      -1,   426,   100,    93,   488,    -1,   427,    -1,   427,   101,
      93,   488,    -1,   429,    -1,   428,   429,    -1,   171,    -1,
     154,    -1,   428,   171,    -1,   428,   154,    -1,   432,    -1,
     436,    -1,   433,    -1,   198,    -1,   203,    -1,   202,    -1,
     201,    -1,   200,    -1,   199,    -1,   147,    -1,   174,    -1,
     137,    -1,    33,   149,   365,   179,    -1,    33,   218,   149,
     365,   179,    -1,    33,   217,   149,   365,   179,    -1,    33,
      93,   504,   149,   365,   179,    -1,   434,   149,   179,    -1,
     434,   149,   365,   179,    -1,   435,    -1,   434,   435,    -1,
     172,   521,    15,    -1,   172,    16,    -1,   437,    -1,   437,
     438,    -1,   188,   438,    -1,   438,    -1,   187,    -1,   439,
      -1,   439,   187,   438,    -1,   439,   188,   438,    -1,   440,
      -1,   449,    -1,   441,    -1,   441,   450,    -1,   444,    -1,
     444,   450,    -1,   442,   446,    -1,   443,    -1,   104,    -1,
     113,    -1,    97,    -1,   185,    -1,   114,    -1,   136,    -1,
     135,    -1,   446,    -1,    98,   446,    -1,   445,   446,    -1,
     119,    -1,   168,    -1,    89,    -1,   176,    -1,   175,    -1,
      90,    -1,   494,    -1,   447,    -1,   521,    -1,   448,    -1,
     189,    -1,    10,    -1,    17,    -1,   452,    -1,   452,   450,
      -1,   451,    -1,   450,   451,    -1,   150,   365,   180,    -1,
     453,    -1,   455,    -1,   456,    -1,   457,    -1,   460,    -1,
     462,    -1,   458,    -1,   459,    -1,   454,    -1,   506,    -1,
     109,    -1,   145,    -1,   121,    -1,   117,   521,    -1,   152,
     182,    -1,   152,   365,   182,    -1,   118,    -1,   164,   149,
     365,   179,    -1,   197,   149,   365,   179,    -1,   521,   152,
     182,    -1,   521,   152,   461,   182,    -1,   368,    -1,   461,
     106,   368,    -1,   463,    -1,   481,    -1,   464,    -1,   478,
      -1,   479,    -1,   153,   521,   468,   127,    -1,   153,   521,
     466,   468,   127,    -1,   153,   521,   468,   192,   190,   521,
     468,   192,    -1,   153,   521,   468,   192,   465,   190,   521,
     468,   192,    -1,   153,   521,   466,   468,   192,   190,   521,
     468,   192,    -1,   153,   521,   466,   468,   192,   465,   190,
     521,   468,   192,    -1,   476,    -1,   465,   476,    -1,   467,
      -1,   466,   467,    -1,    26,   521,   468,   129,   468,   469,
      -1,    -1,    26,    -1,   178,   470,   178,    -1,    92,   472,
      92,    -1,    -1,   471,    -1,   131,    -1,   474,    -1,   471,
     131,    -1,   471,   474,    -1,    -1,   473,    -1,   130,    -1,
     475,    -1,   473,   130,    -1,   473,   475,    -1,    19,    -1,
     477,    -1,     4,    -1,   477,    -1,   463,    -1,     9,    -1,
     480,    -1,   477,    -1,     8,    -1,   120,    -1,   122,    -1,
     362,    -1,   208,    21,   209,    -1,   208,   209,    -1,   169,
     520,   170,    -1,   169,   520,     7,    -1,   102,     6,    -1,
     482,    -1,   483,    -1,   484,    -1,   485,    -1,   486,    -1,
     487,    -1,    36,   149,   365,   179,    -1,    35,   521,   149,
     179,    -1,    35,   521,   149,   365,   179,    -1,    35,   149,
     365,   179,   149,   179,    -1,    35,   149,   365,   179,   149,
     365,   179,    -1,    96,   521,   149,   179,    -1,    96,   521,
     149,   365,   179,    -1,    96,   149,   365,   179,   149,   179,
      -1,    96,   149,   365,   179,   149,   365,   179,    -1,    37,
     149,   365,   179,    -1,    38,   149,   365,   179,    -1,    47,
     520,   149,   179,    -1,    47,   520,   149,   365,   179,    -1,
      47,   149,   365,   179,   149,   179,    -1,    47,   149,   365,
     179,   149,   365,   179,    -1,   493,    -1,   493,   141,    -1,
      93,   490,    -1,   492,    -1,   492,   491,    -1,   206,   152,
     182,    -1,   141,    -1,   189,    -1,   171,    -1,   493,    -1,
     494,    -1,   148,   152,   182,    -1,   521,    -1,   496,    -1,
     502,    -1,   500,    -1,   503,    -1,   501,    -1,   499,    -1,
     498,    -1,   497,    -1,   495,    -1,   221,   152,   182,    -1,
      73,   152,   182,    -1,    73,   152,   502,   182,    -1,    73,
     152,   503,   182,    -1,    37,   152,   182,    -1,    38,   152,
     182,    -1,    47,   152,   182,    -1,    47,   152,   520,   182,
      -1,    47,   152,    20,   182,    -1,    96,   152,   182,    -1,
      96,   152,   521,   182,    -1,    96,   152,   521,   106,   504,
     182,    -1,    96,   152,   189,   182,    -1,    96,   152,   189,
     106,   504,   182,    -1,   184,   521,   182,    -1,    35,   152,
     182,    -1,    35,   152,   521,   182,    -1,    35,   152,   521,
     106,   504,   182,    -1,    35,   152,   521,   106,   505,   182,
      -1,    35,   152,   189,   182,    -1,    35,   152,   189,   106,
     504,   182,    -1,    35,   152,   189,   106,   505,   182,    -1,
      72,   152,   521,   182,    -1,   521,    -1,   521,   141,    -1,
      20,    -1,    39,   216,   217,    -1,    39,   216,   218,    -1,
      39,   216,   219,    -1,   222,   221,   368,   229,   368,    -1,
     222,   221,   368,    93,   228,   229,   368,    -1,   222,   221,
     368,    93,   230,   229,   368,    -1,   222,   221,   368,   214,
     368,    -1,   222,   221,   368,   215,   368,    -1,   222,   223,
     368,   229,   368,    -1,   222,   223,   368,    93,   228,   229,
     368,    -1,   222,   223,   368,    93,   230,   229,   368,    -1,
     222,   223,   368,   214,   368,    -1,   222,   223,   368,   215,
     368,    -1,   220,   221,   368,    -1,   220,   223,   368,    -1,
     225,   221,   368,   233,   368,    -1,   225,   226,   227,   221,
     368,   233,   368,    -1,   224,   221,   368,    93,   368,    -1,
     232,   117,   513,   231,   368,   181,   368,    -1,   514,    -1,
     513,   106,   117,   514,    -1,   521,   139,   368,    -1,   234,
     149,   368,   179,   516,    -1,   517,    -1,   516,   517,    -1,
     235,   518,   363,    -1,   235,   518,   152,   117,   521,   182,
     363,    -1,   235,   518,   152,   117,   521,   106,   117,   521,
     182,   363,    -1,   235,   518,   152,   117,   521,   106,   117,
     521,   106,   117,   521,   182,   363,    -1,   447,    -1,   518,
     205,   447,    -1,    20,    -1,    14,    -1,   521,    -1,    18,
      -1,   522,    -1,   210,    -1,   124,    -1,    96,    -1,    38,
      -1,    73,    -1,    35,    -1,   148,    -1,    46,    -1,   221,
      -1,    47,    -1,    76,    -1,    72,    -1,    37,    -1,    34,
      -1,   206,    -1,    77,    -1,   240,    -1,    71,    -1,   218,
      -1,   217,    -1,   142,    -1,    36,    -1,   252,    -1,   239,
      -1,   242,    -1,   241,    -1,   269,    -1,   270,    -1,   273,
      -1,   271,    -1,   274,    -1,   245,    -1,   247,    -1,    54,
      -1,   213,    -1,   246,    -1,    48,    -1,   219,    -1,   232,
      -1,   226,    -1,   198,    -1,   203,    -1,   202,    -1,   201,
      -1,   200,    -1,   199,    -1,    95,    -1,   110,    -1,   111,
      -1,   181,    -1,    61,    -1,    62,    -1,    63,    -1,    64,
      -1,    65,    -1,    66,    -1,    67,    -1,    68,    -1,    69,
      -1,   143,    -1,    58,    -1,   207,    -1,   166,    -1,   167,
      -1,   165,    -1,    51,    -1,    94,    -1,   115,    -1,   125,
      -1,   126,    -1,   105,    -1,    50,    -1,   132,    -1,   183,
      -1,    99,    -1,    93,    -1,   193,    -1,   123,    -1,   163,
      -1,    91,    -1,    75,    -1,   227,    -1,   100,    -1,   194,
      -1,   116,    -1,   155,    -1,   196,    -1,   146,    -1,   133,
      -1,    33,    -1,   101,    -1,   195,    -1,   147,    -1,   177,
      -1,   191,    -1,   156,    -1,   134,    -1,   128,    -1,   162,
      -1,   144,    -1,   161,    -1,    39,    -1,    59,    -1,    70,
      -1,   112,    -1,    74,    -1,    53,    -1,   211,    -1,    49,
      -1,    55,    -1,    52,    -1,    40,    -1,   262,    -1,   251,
      -1,   267,    -1,   268,    -1,   244,    -1,   257,    -1,   265,
      -1,   261,    -1,   243,    -1,   256,    -1,   266,    -1,   260,
      -1,   255,    -1,   254,    -1,   238,    -1,   237,    -1,   259,
      -1,   248,    -1,   249,    -1,   272,    -1,   264,    -1,   263,
      -1,   258,    -1,   225,    -1,   231,    -1,   228,    -1,   222,
      -1,   215,    -1,   214,    -1,   216,    -1,   233,    -1,   223,
      -1,   224,    -1,   230,    -1,   220,    -1,   229,    -1,    45,
      -1,    42,    -1,    41,    -1,    43,    -1,    44,    -1,   164,
      -1,   197,    -1,    27,    -1,    28,    -1,    30,    -1,    32,
      -1,    29,    -1,    31,    -1,   234,    -1,   235,    -1,    60,
      -1,   236,    -1,    57,    -1,   279,    -1,   275,    -1,   276,
      -1,   278,    -1,   282,    -1,   280,    -1,   281,    -1,   277,
      -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,    82,
      -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,
      -1,    88,    -1,   236,   117,   387,    60,   149,   368,   179,
      -1,    60,   149,   368,   179,    -1,   526,    -1,   526,   525,
      -1,   526,   267,   418,    -1,   526,   525,   267,   418,    -1,
     535,    -1,   533,    -1,   525,   535,    -1,   525,   533,    -1,
     527,    -1,   526,   253,   527,    -1,   528,    -1,   527,   250,
     528,    -1,   529,    -1,   528,   252,   143,   529,    -1,   530,
      -1,   252,   530,    -1,   531,    -1,   531,   554,    -1,   152,
     524,   182,    -1,   532,    -1,   532,   550,    -1,   453,    -1,
     149,   365,   179,    -1,   534,    -1,   553,    -1,   552,    -1,
     555,    -1,   549,    -1,   164,    -1,   536,    -1,   537,    -1,
     538,    -1,   539,    -1,   542,    -1,   547,    -1,   548,    -1,
     256,    -1,   266,    -1,    99,   239,    -1,    99,   242,    -1,
     233,   241,    -1,   269,   241,    -1,   241,   239,    -1,   241,
     242,    -1,   233,   270,    -1,   269,   270,    -1,   233,   273,
     541,    -1,   233,   273,   112,    -1,   233,   273,   152,   541,
     182,    -1,   233,   273,   152,   541,   106,   540,   182,    -1,
     233,   273,   152,   112,   182,    -1,   233,   273,   152,   112,
     106,   540,   182,    -1,   269,   273,    -1,   541,    -1,   540,
     106,   541,    -1,    95,    20,    -1,    95,    20,   260,    20,
      -1,    95,    20,   551,   255,    -1,    95,    20,   260,    20,
     551,   255,    -1,   233,   271,   272,   544,    -1,   233,   271,
     272,   544,   543,    -1,   233,   112,   271,   272,    -1,   233,
     112,   271,   272,   543,    -1,   269,   271,   272,    -1,   546,
      -1,   543,   546,    -1,    95,    20,    -1,   152,   545,   182,
      -1,    20,    -1,   545,    20,    -1,   196,   544,    -1,   133,
     544,    -1,   254,    20,    -1,   233,   274,    -1,   269,   274,
      -1,    95,   213,    -1,    95,   246,    -1,   245,   247,    -1,
     238,    -1,   238,    54,    -1,   237,    -1,   237,   272,    -1,
     259,    -1,   248,   421,    -1,    95,   126,   421,    -1,    95,
      48,   421,    -1,   249,   421,   194,   421,    -1,   244,   551,
     556,    -1,   268,   421,   556,    -1,   257,   551,   265,    -1,
     261,   557,    -1,   243,   557,    -1,   272,    -1,   264,    -1,
     258,    -1,   263,    -1,   258,    -1,   269,   247,   421,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    13,    15,    18,    23,
      30,    33,    35,    38,    45,    48,    51,    56,    58,    62,
      64,    68,    70,    72,    74,    76,    78,    80,    82,    84,
      86,    88,    90,    95,   100,   102,   105,   109,   111,   113,
     115,   117,   119,   121,   123,   125,   127,   129,   131,   133,
     135,   137,   139,   141,   143,   145,   147,   149,   155,   159,
     163,   169,   175,   180,   184,   188,   192,   198,   204,   210,
     216,   222,   228,   233,   237,   241,   246,   252,   259,   261,
     265,   269,   273,   277,   284,   290,   299,   304,   308,   310,
     312,   314,   317,   320,   323,   327,   333,   338,   345,   347,
     349,   352,   354,   357,   359,   362,   370,   372,   376,   378,
     381,   384,   388,   392,   396,   399,   403,   408,   414,   417,
     422,   426,   427,   431,   434,   436,   440,   446,   450,   456,
     459,   462,   466,   470,   474,   477,   481,   485,   487,   490,
     493,   496,   501,   506,   511,   513,   517,   520,   524,   528,
     532,   534,   536,   539,   541,   545,   547,   551,   553,   555,
     557,   559,   561,   563,   565,   567,   569,   571,   573,   575,
     577,   579,   581,   583,   585,   587,   590,   593,   596,   599,
     601,   603,   606,   611,   615,   621,   626,   630,   632,   634,
     636,   638,   640,   642,   644,   646,   648,   651,   654,   658,
     661,   663,   668,   672,   677,   682,   688,   693,   699,   705,
     712,   716,   720,   724,   726,   731,   733,   738,   742,   747,
     752,   758,   763,   769,   771,   774,   778,   780,   783,   785,
     792,   796,   800,   802,   805,   809,   811,   815,   818,   822,
     825,   829,   834,   836,   840,   842,   845,   847,   849,   851,
     854,   857,   860,   864,   866,   868,   871,   874,   877,   883,
     889,   891,   896,   900,   905,   914,   925,   927,   930,   935,
     943,   952,   954,   958,   960,   964,   966,   970,   974,   978,
     982,   983,   988,   992,   996,  1000,  1002,  1006,  1011,  1013,
    1017,  1019,  1023,  1027,  1029,  1033,  1037,  1041,  1045,  1047,
    1051,  1055,  1057,  1061,  1065,  1067,  1072,  1074,  1079,  1081,
    1086,  1088,  1093,  1095,  1098,  1100,  1102,  1105,  1108,  1110,
    1112,  1114,  1116,  1118,  1120,  1122,  1124,  1126,  1128,  1130,
    1132,  1137,  1143,  1149,  1156,  1160,  1165,  1167,  1170,  1174,
    1177,  1179,  1182,  1185,  1187,  1189,  1191,  1195,  1199,  1201,
    1203,  1205,  1208,  1210,  1213,  1216,  1218,  1220,  1222,  1224,
    1226,  1228,  1230,  1232,  1234,  1237,  1240,  1242,  1244,  1246,
    1248,  1250,  1252,  1254,  1256,  1258,  1260,  1262,  1264,  1266,
    1268,  1271,  1273,  1276,  1280,  1282,  1284,  1286,  1288,  1290,
    1292,  1294,  1296,  1298,  1300,  1302,  1304,  1306,  1309,  1312,
    1316,  1318,  1323,  1328,  1332,  1337,  1339,  1343,  1345,  1347,
    1349,  1351,  1353,  1358,  1364,  1373,  1383,  1393,  1404,  1406,
    1409,  1411,  1414,  1421,  1422,  1424,  1428,  1432,  1433,  1435,
    1437,  1439,  1442,  1445,  1446,  1448,  1450,  1452,  1455,  1458,
    1460,  1462,  1464,  1466,  1468,  1470,  1472,  1474,  1476,  1478,
    1480,  1482,  1486,  1489,  1493,  1497,  1500,  1502,  1504,  1506,
    1508,  1510,  1512,  1517,  1522,  1528,  1535,  1543,  1548,  1554,
    1561,  1569,  1574,  1579,  1584,  1590,  1597,  1605,  1607,  1610,
    1613,  1615,  1618,  1622,  1624,  1626,  1628,  1630,  1632,  1636,
    1638,  1640,  1642,  1644,  1646,  1648,  1650,  1652,  1654,  1656,
    1660,  1664,  1669,  1674,  1678,  1682,  1686,  1691,  1696,  1700,
    1705,  1712,  1717,  1724,  1728,  1732,  1737,  1744,  1751,  1756,
    1763,  1770,  1775,  1777,  1780,  1782,  1786,  1790,  1794,  1800,
    1808,  1816,  1822,  1828,  1834,  1842,  1850,  1856,  1862,  1866,
    1870,  1876,  1884,  1890,  1898,  1900,  1905,  1909,  1915,  1917,
    1920,  1924,  1932,  1943,  1957,  1959,  1963,  1965,  1967,  1969,
    1971,  1973,  1975,  1977,  1979,  1981,  1983,  1985,  1987,  1989,
    1991,  1993,  1995,  1997,  1999,  2001,  2003,  2005,  2007,  2009,
    2011,  2013,  2015,  2017,  2019,  2021,  2023,  2025,  2027,  2029,
    2031,  2033,  2035,  2037,  2039,  2041,  2043,  2045,  2047,  2049,
    2051,  2053,  2055,  2057,  2059,  2061,  2063,  2065,  2067,  2069,
    2071,  2073,  2075,  2077,  2079,  2081,  2083,  2085,  2087,  2089,
    2091,  2093,  2095,  2097,  2099,  2101,  2103,  2105,  2107,  2109,
    2111,  2113,  2115,  2117,  2119,  2121,  2123,  2125,  2127,  2129,
    2131,  2133,  2135,  2137,  2139,  2141,  2143,  2145,  2147,  2149,
    2151,  2153,  2155,  2157,  2159,  2161,  2163,  2165,  2167,  2169,
    2171,  2173,  2175,  2177,  2179,  2181,  2183,  2185,  2187,  2189,
    2191,  2193,  2195,  2197,  2199,  2201,  2203,  2205,  2207,  2209,
    2211,  2213,  2215,  2217,  2219,  2221,  2223,  2225,  2227,  2229,
    2231,  2233,  2235,  2237,  2239,  2241,  2243,  2245,  2247,  2249,
    2251,  2253,  2255,  2257,  2259,  2261,  2263,  2265,  2267,  2269,
    2271,  2273,  2275,  2277,  2279,  2281,  2283,  2285,  2287,  2289,
    2291,  2293,  2295,  2297,  2299,  2301,  2303,  2305,  2307,  2309,
    2311,  2313,  2315,  2317,  2319,  2321,  2323,  2325,  2327,  2329,
    2331,  2333,  2335,  2337,  2339,  2341,  2343,  2351,  2356,  2358,
    2361,  2365,  2370,  2372,  2374,  2377,  2380,  2382,  2386,  2388,
    2392,  2394,  2399,  2401,  2404,  2406,  2409,  2413,  2415,  2418,
    2420,  2424,  2426,  2428,  2430,  2432,  2434,  2436,  2438,  2440,
    2442,  2444,  2446,  2448,  2450,  2452,  2454,  2457,  2460,  2463,
    2466,  2469,  2472,  2475,  2478,  2482,  2486,  2492,  2500,  2506,
    2514,  2517,  2519,  2523,  2526,  2531,  2536,  2543,  2548,  2554,
    2559,  2565,  2569,  2571,  2574,  2577,  2581,  2583,  2586,  2589,
    2592,  2595,  2598,  2601,  2604,  2607,  2610,  2612,  2615,  2617,
    2620,  2622,  2625,  2629,  2633,  2638,  2642,  2646,  2650,  2653,
    2656,  2658,  2660,  2662,  2664,  2666
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   886,   886,   887,   897,   902,   908,   913,   925,   930,
     940,   947,   959,   971,   983,   989,   995,  1007,  1013,  1027,
    1033,  1047,  1048,  1049,  1050,  1056,  1057,  1058,  1059,  1062,
    1065,  1067,  1073,  1078,  1086,  1092,  1101,  1110,  1111,  1112,
    1113,  1114,  1115,  1116,  1117,  1118,  1119,  1126,  1127,  1128,
    1129,  1130,  1131,  1132,  1135,  1142,  1143,  1155,  1167,  1172,
    1183,  1189,  1201,  1214,  1225,  1230,  1242,  1247,  1258,  1264,
    1270,  1276,  1295,  1306,  1317,  1324,  1331,  1338,  1351,  1357,
    1372,  1376,  1386,  1392,  1399,  1405,  1417,  1424,  1430,  1437,
    1443,  1447,  1454,  1465,  1469,  1477,  1486,  1493,  1503,  1505,
    1512,  1520,  1524,  1532,  1536,  1544,  1552,  1556,  1564,  1568,
    1575,  1582,  1592,  1597,  1609,  1613,  1617,  1621,  1628,  1635,
    1654,  1664,  1670,  1676,  1685,  1696,  1709,  1716,  1723,  1735,
    1739,  1746,  1750,  1754,  1761,  1765,  1771,  1778,  1782,  1786,
    1794,  1801,  1810,  1822,  1836,  1844,  1858,  1864,  1876,  1884,
    1895,  1906,  1910,  1922,  1926,  1935,  1939,  1955,  1956,  1957,
    1958,  1959,  1962,  1963,  1964,  1965,  1966,  1968,  1969,  1972,
    1973,  1974,  1975,  1976,  1979,  1986,  1995,  2002,  2006,  2014,
    2018,  2022,  2029,  2033,  2040,  2048,  2059,  2068,  2069,  2070,
    2074,  2074,  2074,  2074,  2074,  2077,  2083,  2092,  2096,  2106,
    2117,  2123,  2137,  2144,  2152,  2161,  2171,  2179,  2188,  2197,
    2212,  2224,  2235,  2247,  2253,  2265,  2271,  2285,  2293,  2302,
    2310,  2322,  2328,  2338,  2339,  2343,  2351,  2355,  2360,  2364,
    2368,  2372,  2379,  2394,  2402,  2409,  2415,  2426,  2432,  2441,
    2451,  2456,  2468,  2474,  2488,  2494,  2506,  2513,  2520,  2527,
    2534,  2541,  2548,  2561,  2565,  2575,  2580,  2591,  2602,  2609,
    2622,  2629,  2641,  2647,  2660,  2667,  2681,  2687,  2699,  2705,
    2718,  2729,  2733,  2744,  2748,  2767,  2771,  2779,  2787,  2795,
    2803,  2803,  2811,  2819,  2827,  2841,  2845,  2852,  2865,  2869,
    2880,  2884,  2888,  2898,  2902,  2906,  2910,  2914,  2924,  2928,
    2933,  2944,  2948,  2952,  2962,  2966,  2978,  2982,  2994,  2998,
    3010,  3014,  3026,  3030,  3042,  3046,  3050,  3054,  3066,  3070,
    3074,  3084,  3088,  3092,  3096,  3100,  3104,  3114,  3118,  3122,
    3132,  3136,  3140,  3144,  3156,  3162,  3174,  3180,  3194,  3201,
    3242,  3246,  3250,  3254,  3266,  3276,  3287,  3292,  3302,  3306,
    3316,  3322,  3328,  3334,  3346,  3352,  3363,  3367,  3371,  3375,
    3379,  3383,  3387,  3397,  3401,  3411,  3415,  3426,  3430,  3434,
    3438,  3442,  3457,  3461,  3471,  3475,  3485,  3492,  3499,  3512,
    3516,  3528,  3534,  3548,  3559,  3563,  3567,  3571,  3575,  3579,
    3583,  3587,  3597,  3601,  3611,  3616,  3621,  3632,  3642,  3646,
    3657,  3667,  3678,  3734,  3740,  3752,  3758,  3770,  3774,  3784,
    3788,  3792,  3802,  3810,  3818,  3826,  3834,  3842,  3857,  3863,
    3875,  3881,  3894,  3903,  3905,  3911,  3916,  3928,  3931,  3938,
    3944,  3950,  3958,  3973,  3976,  3983,  3989,  3995,  4003,  4017,
    4022,  4033,  4038,  4049,  4054,  4059,  4065,  4077,  4083,  4088,
    4093,  4104,  4109,  4124,  4129,  4146,  4161,  4165,  4169,  4173,
    4177,  4181,  4191,  4202,  4208,  4214,  4219,  4241,  4247,  4253,
    4258,  4269,  4279,  4289,  4295,  4301,  4306,  4317,  4323,  4335,
    4346,  4352,  4358,  4395,  4400,  4405,  4416,  4420,  4424,  4434,
    4445,  4449,  4453,  4457,  4461,  4465,  4469,  4473,  4477,  4487,
    4497,  4501,  4506,  4517,  4527,  4537,  4541,  4545,  4555,  4561,
    4567,  4573,  4579,  4591,  4602,  4609,  4616,  4623,  4630,  4637,
    4644,  4657,  4678,  4685,  4705,  4745,  4749,  4753,  4762,  4768,
    4774,  4780,  4786,  4793,  4799,  4805,  4811,  4817,  4829,  4834,
    4844,  4850,  4862,  4888,  4899,  4905,  4918,  4932,  4939,  4945,
    4956,  4963,  4972,  4981,  4994,  5000,  5010,  5019,  5020,  5037,
    5037,  5040,  5041,  5042,  5043,  5044,  5045,  5046,  5047,  5048,
    5049,  5050,  5051,  5052,  5053,  5054,  5055,  5056,  5057,  5058,
    5059,  5060,  5061,  5062,  5063,  5064,  5065,  5066,  5067,  5068,
    5069,  5070,  5071,  5072,  5073,  5074,  5075,  5076,  5077,  5078,
    5079,  5080,  5081,  5082,  5083,  5084,  5085,  5086,  5087,  5088,
    5089,  5090,  5091,  5092,  5093,  5094,  5095,  5096,  5097,  5098,
    5099,  5100,  5101,  5102,  5103,  5104,  5105,  5106,  5107,  5108,
    5109,  5110,  5111,  5112,  5113,  5114,  5115,  5116,  5117,  5118,
    5119,  5120,  5121,  5122,  5123,  5124,  5125,  5126,  5127,  5128,
    5129,  5130,  5131,  5132,  5133,  5134,  5135,  5136,  5137,  5138,
    5139,  5140,  5141,  5142,  5143,  5144,  5145,  5146,  5147,  5148,
    5149,  5150,  5151,  5152,  5153,  5154,  5155,  5156,  5157,  5158,
    5159,  5160,  5161,  5162,  5163,  5164,  5165,  5166,  5167,  5168,
    5169,  5170,  5171,  5172,  5173,  5174,  5175,  5176,  5177,  5178,
    5179,  5180,  5181,  5182,  5183,  5184,  5185,  5186,  5187,  5188,
    5189,  5190,  5191,  5192,  5193,  5194,  5195,  5196,  5197,  5198,
    5199,  5200,  5201,  5202,  5203,  5204,  5205,  5206,  5207,  5208,
    5209,  5210,  5211,  5212,  5213,  5214,  5215,  5216,  5217,  5218,
    5219,  5220,  5221,  5222,  5223,  5224,  5235,  5241,  5258,  5262,
    5266,  5270,  5280,  5283,  5286,  5289,  5298,  5301,  5310,  5313,
    5322,  5325,  5334,  5337,  5346,  5349,  5352,  5361,  5364,  5373,
    5377,  5387,  5390,  5393,  5396,  5399,  5408,  5417,  5421,  5425,
    5429,  5433,  5437,  5441,  5451,  5454,  5457,  5460,  5469,  5472,
    5475,  5478,  5487,  5490,  5499,  5502,  5505,  5508,  5511,  5514,
    5517,  5526,  5529,  5538,  5541,  5544,  5547,  5556,  5559,  5562,
    5565,  5568,  5577,  5580,  5589,  5592,  5601,  5604,  5613,  5616,
    5625,  5634,  5637,  5646,  5649,  5652,  5661,  5664,  5667,  5670,
    5673,  5682,  5686,  5690,  5694,  5704,  5713,  5723,  5732,  5735,
    5744,  5747,  5750,  5759,  5762,  5771
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
     295,   296,   297
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 9767;
  const int xquery_parser::yynnts_ = 261;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 496;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 298;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 552;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 13341 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 5779 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"


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

