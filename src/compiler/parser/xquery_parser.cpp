
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
#line 87 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"


#include "common/common.h"

#ifdef WIN32
#pragma warning(disable: 4786)
#endif

#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/api/compilercb.h"
#include "store/api/update_consts.h"
#include "compiler/parser/xquery_driver.h"

#define SYMTAB( n ) driver.symtab.get( (off_t)n )
#define SYMTAB_PUT( s ) driver.symtab.put( s )
#define LOC( p ) driver.createQueryLoc( p )


namespace zorba
{
namespace parser
{
  extern const char *the_tumbling, *the_sliding, *the_start, *the_end, *the_only_end, *the_declare, *the_create;

}
}

#define YYDEBUG 1

using namespace std;
using namespace zorba;



/* Line 311 of lalr1.cc  */
#line 79 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 911 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 1036 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 109 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"

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
#line 178 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
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
        case 110: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 909 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 285 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 124: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 908 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 294 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 149: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 303 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 528 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 537 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2697 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2706 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2715 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2724 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2733 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2742 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 644: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2751 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 645: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2760 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 646: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2769 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 647: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2778 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 648: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2787 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 655: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2796 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 656: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2805 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 657: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2814 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
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
#line 140 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2899 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"

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
#line 1054 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1058 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1062 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1070 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1076 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1080 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1089 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1095 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1103 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1109 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1120 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1125 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1133 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1140 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1147 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1156 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1163 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1171 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1179 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1187 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1198 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1203 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1210 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1217 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 1229 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 1239 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 1246 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 1253 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      // error
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1288 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1293 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1301 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1309 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1317 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1322 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1330 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1335 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1343 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1348 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1356 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1361 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1366 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1371 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1384 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1394 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1399 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1407 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1415 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1426 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1433 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1444 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1449 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1457 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1464 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1471 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1480 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1493 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1501 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1508 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1518 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1525 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1532 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1555 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1561 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1570 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1577 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1587 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1596 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1597 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1598 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1599 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1600 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1601 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1602 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1603 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1604 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1605 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1611 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1619 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1627 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1635 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1642 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1650 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1657 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1662 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1670 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1678 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             (yysemantic_stack_[(4) - (4)].expr),
                             nt->get_annotations(),
                             false);  // not external

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1692 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             NULL,   // no init expr
                             nt->get_annotations(),
                             true);  // external

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1706 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             (yysemantic_stack_[(5) - (5)].expr),     // init expr
                             nt->get_annotations(),
                             true);  // external

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1723 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1728 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1736 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1744 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1755 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1760 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1769 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1774 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1781 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1786 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1796 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1801 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1810 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1816 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1829 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1834 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1842 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theParams,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType,
                            (yysemantic_stack_[(4) - (4)].expr),      // body
                            false,   // not explicitly updating
                            false);  // not external
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1853 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType.getp(),
                            NULL,   // no body
                            false,   // not explicitly updating
                            true);  // external
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1868 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            (yysemantic_stack_[(5) - (5)].expr),    // body
                            true,  // updating
                            false);// not external
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1880 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            NULL,  // no body
                            true,  // updating
                            true); // external
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1895 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1900 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1905 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1910 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1918 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1925 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1936 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1941 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1951 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1960 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1969 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1978 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1990 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1994 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 2000 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 2004 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 2014 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);

      static_cast<AST_IndexDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(8) - (1)].sval)) );
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 2024 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));

      static_cast<AST_IndexDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(9) - (1)].sval)) );
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 2037 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 2043 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 2052 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 2057 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 2064 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 2071 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2083 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2093 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2103 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2114 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICForeignKey( LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (4)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (9)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (12)].expr)),
                            (yysemantic_stack_[(22) - (14)].expr),
                            static_cast<QName*>((yysemantic_stack_[(22) - (17)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (20)].expr)),
                            (yysemantic_stack_[(22) - (22)].expr));
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2130 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      if ((yysemantic_stack_[(1) - (1)].expr) == NULL)
      {
        error((yylocation_stack_[(1) - (1)]), "syntax error, unexpected end of file, the query body should not be empty");
        YYERROR;
      }

      if (dynamic_cast<BlockBody*>((yysemantic_stack_[(1) - (1)].expr)) != NULL)
      {
        BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(1) - (1)].expr));
        blk->setTopLevel(true);
      }

      (yyval.expr) = new QueryBody(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2150 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2154 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2158 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2166 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2170 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2174 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2182 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2187 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2199 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2206 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2216 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(4) - (1)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(4) - (2)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(4) - (4)].expr); // to prevent the Bison warning
      error((yylocation_stack_[(4) - (3)]), "syntax error, unexpected statement (missing semicolon \";\" between statements?)");
      delete (yysemantic_stack_[(4) - (1)].expr); // these need to be deleted here because the parser deallocator will skip them
      delete (yysemantic_stack_[(4) - (2)].expr);
      delete (yysemantic_stack_[(4) - (4)].expr);
      YYERROR;
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2248 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2253 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2261 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      if (dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (2)].expr)) == NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add((yysemantic_stack_[(3) - (2)].expr));
        (yyval.expr) = blk;
      }
      else
      {
        (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
      }
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 2278 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 2286 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 2294 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 2301 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 2308 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2319 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                          NULL,  // no type
                                          NULL,  // no init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 2328 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)), // type
                                          NULL,  // no init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2337 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                          NULL,  // no type
                                          (yysemantic_stack_[(4) - (4)].expr),    // init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2346 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)), // type
                                          (yysemantic_stack_[(5) - (5)].expr),    // init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2359 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2367 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2375 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2383 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
      if (bb == NULL)
      {
        bb = new BlockBody((yysemantic_stack_[(5) - (5)].expr)->get_location());
        bb->add((yysemantic_stack_[(5) - (5)].expr));
      }

      (yyval.expr) = new WhileExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb);
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2398 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2403 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2411 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* re = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr(LOC((yyloc)),
                         dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)),
                         re->get_return_val(),
                         re->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2425 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      exprnode* retExpr = (yysemantic_stack_[(2) - (2)].expr);

      if (dynamic_cast<VarDeclStmt*>(retExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add(retExpr);
        retExpr = blk;
      }

      (yyval.expr) = new ReturnExpr(LOC((yyloc)), retExpr);
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2442 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      exprnode* thenExpr = (yysemantic_stack_[(8) - (6)].expr);
      exprnode* elseExpr = (yysemantic_stack_[(8) - (8)].expr);

      if (dynamic_cast<VarDeclStmt*>(thenExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add(thenExpr);
        thenExpr = blk;
      }

      if (dynamic_cast<VarDeclStmt*>(elseExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add(elseExpr);
        elseExpr = blk;
      }

      (yyval.expr) = new IfExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), thenExpr, elseExpr);
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2467 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2475 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2482 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2493 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 2503 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 2508 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      Expr* expr = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
      if ( !expr )
      {
        expr = new Expr( LOC((yyloc)) );
        expr->push_back( (yysemantic_stack_[(3) - (1)].expr) );
      }
      expr->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.expr) = expr;
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 2521 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (1)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      // Heuristics to improve the error message: if the $1 Expr is a QName (which in turn gets
      // promoted to a PathExpr), chances are that it's not a missing comma, so don't modify
      // the error message.
      if (dynamic_cast<PathExpr*>((yysemantic_stack_[(3) - (1)].expr)) == NULL)
        error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected expression (missing comma \",\" between expressions?)");
      delete (yysemantic_stack_[(3) - (1)].expr); // these need to be deleted here because the parser deallocator will skip them
      delete (yysemantic_stack_[(3) - (3)].expr);
      YYERROR;
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2568 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr *re = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr(LOC((yyloc)),
                         dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)),
                         re->get_return_val(),
                         re->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2582 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2590 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2595 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2603 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2608 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2613 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2621 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2630 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2642 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2652 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2665 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2689 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2696 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2706 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2712 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2721 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2731 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2738 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2746 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2758 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                         NULL,
                         NULL,
                         NULL,
                         (yysemantic_stack_[(3) - (3)].expr),
                         false);
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2768 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         NULL,
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr),
                         true);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2778 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2788 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         NULL,
                         NULL,
                         (yysemantic_stack_[(6) - (6)].expr),
                         true);
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2798 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2808 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (4)].node)),
                         NULL,
                         (yysemantic_stack_[(6) - (6)].expr),
                         true);
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2818 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2828 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(7) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(7) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(7) - (5)].node)),
                         NULL,
                         (yysemantic_stack_[(7) - (7)].expr),
                         true);
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2839 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2848 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2858 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2868 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                         (yysemantic_stack_[(6) - (6)].expr),
                         false);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2884 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2893 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2902 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2910 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2916 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2928 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2936 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2946 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2954 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2966 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2972 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2985 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2989 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2997 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 3001 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 3010 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 3014 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 3018 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 3028 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3036 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3043 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3049 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3059 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3063 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3067 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3075 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3083 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3091 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3103 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3111 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3117 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3127 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3133 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3143 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3147 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3157 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3163 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3169 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3175 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3184 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3193 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3202 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3215 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3219 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3227 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3233 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3243 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3251 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3260 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3273 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3280 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3292 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3296 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3308 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3315 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3321 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3330 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3337 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3343 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3354 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3361 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3367 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3376 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3385 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3392 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3403 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3410 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3422 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3428 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3440 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3446 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3457 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3463 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3474 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3480 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3491 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3497 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3508 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3517 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3521 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3530 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3534 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3542 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3546 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3556 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3563 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3572 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3581 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3586 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3595 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3604 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3613 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3626 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3630 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3642 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3646 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3653 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3657 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3664 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3668 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3677 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3681 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3685 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3693 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3697 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3703 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3709 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3715 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3725 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3729 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3733 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3741 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3745 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3751 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3761 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3765 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3775 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3779 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3789 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3793 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3803 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3807 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3817 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3821 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3830 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3834 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3842 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3846 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3850 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3854 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3864 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3868 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3872 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3879 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3884 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3892 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3896 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3900 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3904 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3908 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3912 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3920 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3924 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3928 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3936 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3940 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3944 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3948 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3959 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3965 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3975 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3981 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3991 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3995 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3999 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4037 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4041 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4051 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4061 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4074 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4083 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      AxisStep* as = dynamic_cast<AxisStep*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (as ?
            new RelativePathExpr(LOC((yyloc)),
                                 ParseConstants::st_slash,
                                 new ContextItemExpr( LOC((yyloc)), true ), (yysemantic_stack_[(1) - (1)].expr), true)
            :
            (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4093 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4097 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4106 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4110 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4119 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4125 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4133 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4139 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4151 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4157 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4167 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4171 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4175 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4179 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4183 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4189 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4195 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4203 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4207 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4215 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4219 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4230 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4234 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4238 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4244 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4248 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4262 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4266 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4274 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4278 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4288 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4292 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4296 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4300 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4309 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4313 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4317 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4321 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4329 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4335 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4345 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4353 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4357 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4361 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4365 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4369 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4373 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4377 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4381 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4385 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4389 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4394 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4398 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4402 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4406 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4414 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4418 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4426 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4433 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4440 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4451 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4459 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4463 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4471 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4479 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4487 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4541 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4545 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4558 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4564 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4574 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4578 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4586 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4590 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4594 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4602 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                NULL,
                NULL,
                NULL
            );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4612 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                NULL,
                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                NULL
            );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4622 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            if (static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr))->get_qname())
            {
              error((yylocation_stack_[(8) - (5)]), "syntax error, end tag </" + static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr))->get_qname().str() + "> does not match start tag <"
                                                   + static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr))->get_qname().str() + ">");
              YYERROR;
            }

            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
                NULL,
                NULL
            );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4639 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            if (static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname())
            {
              error((yylocation_stack_[(9) - (5)]), "syntax error, end tag </" + static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname().str() + "> does not match start tag <"
                                                   + static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname().str() + ">");
              YYERROR;
            }

            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                NULL,
                dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node))
            );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4656 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            if (static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname())
            {
              error((yylocation_stack_[(9) - (5)]), "syntax error, end tag </" + static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname().str() + "> does not match start tag <"
                                                   + static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname().str() + ">");
              YYERROR;
            }

            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
                NULL
            );
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4673 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            if (static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname())
            {
              error((yylocation_stack_[(10) - (5)]), "syntax error, end tag </" + static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname().str() + "> does not match start tag <"
                                                   + static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr))->get_qname().str() + ">");
              YYERROR;
            }

            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)),
                dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node))
            );
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4695 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4701 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4712 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4718 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4729 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4746 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4751 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4760 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4764 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4771 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4777 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4783 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4791 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4803 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4807 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4814 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4820 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4826 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4833 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4844 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4848 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4858 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4862 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4872 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4876 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4880 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4885 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4894 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4900 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4906 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4912 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4920 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4925 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4933 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4938 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4946 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4954 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4959 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4964 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4969 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4974 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4979 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4988 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4996 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5000 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5017 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5021 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5029 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5037 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5045 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5049 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5057 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5065 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5069 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5073 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5108 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5114 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5120 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5130 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5134 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5138 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5142 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5146 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5150 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5154 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5161 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5167 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5177 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5185 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5193 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5197 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5201 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5205 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5209 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5213 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5217 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5221 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5225 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5233 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5241 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5245 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5249 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5259 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5267 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5275 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5279 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5283 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5291 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5295 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5301 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5307 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5311 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5321 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5329 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5333 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5339 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5348 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5357 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5363 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5369 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5379 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5396 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5403 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5418 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5454 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5458 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5466 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5474 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5486 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5490 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5506 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5510 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5521 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5538 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5544 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5550 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5560 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5564 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5570 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5576 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5580 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5586 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5590 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5596 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5602 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5609 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5619 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5624 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5632 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5638 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5648 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5670 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5679 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5685 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5698 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5712 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5719 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5725 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5735 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5744 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5752 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5758 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5776 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5784 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5788 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5795 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5800 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5808 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5812 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5819 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5823 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5830 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5834 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5841 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5845 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5854 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5866 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5870 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5877 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5881 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5889 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5897 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5905 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5909 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5916 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5920 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5928 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5939 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5943 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5951 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5963 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5969 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5978 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5982 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5990 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5994 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5998 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 6005 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 6009 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 6016 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 6020 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 6028 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 6032 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 6036 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 6040 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 6044 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 6052 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 6060 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6072 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6084 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6088 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6092 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6100 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6106 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6116 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6120 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6124 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6128 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6132 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6136 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6140 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6144 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6152 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6156 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6160 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6164 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6172 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6178 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6188 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6198 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6202 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6210 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            FTThesaurusOption::thesaurus_id_list_t *til = NULL;
            if ( (yysemantic_stack_[(2) - (2)].node) ) {
                til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(2) - (2)].node)) );
            }
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), til, !til );
            delete til;
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6220 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            FTThesaurusOption::thesaurus_id_list_t *til = (yysemantic_stack_[(5) - (4)].thesaurus_id_list);
            if ( (yysemantic_stack_[(5) - (3)].node) ) {
                if ( !til )
                    til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(5) - (3)].node)) );
            }
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), til, !(yysemantic_stack_[(5) - (3)].node) );
            delete til;
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6231 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6238 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6242 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6249 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6253 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6260 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6265 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6274 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6283 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6287 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6294 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6298 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6306 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6315 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6322 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6332 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6336 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6343 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6349 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6358 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6362 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6369 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6374 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6386 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6394 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6406 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6414 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6418 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6426 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6430 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6434 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6442 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6450 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6454 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6458 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6462 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6470 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6478 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6490 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6494 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6502 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6516 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6520 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6527 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6532 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6540 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6545 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6554 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6562 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6568 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6578 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6584 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (3)].node));
          (yyval.expr) = new JSONObjectInsertExpr(
              LOC((yyloc)),
              new JSONDirectObjectConstructor(
                  LOC((yyloc)),
                  jpl),
              (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6594 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6601 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6608 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(3) - (3)].expr));

          if (lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(3) - (3)]), "An object invocation is expected. A filter was found instead.");
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(3) - (3)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            YYERROR;
          }

          (yyval.expr) = new JSONDeleteExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0));
        }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6633 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(5) - (3)].expr));

          if(lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(5) - (3)]), "An object invocation is expected. A filter was found instead.");
            delete (yysemantic_stack_[(5) - (5)].expr);
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(5) - (3)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            delete (yysemantic_stack_[(5) - (5)].expr);
            YYERROR;
          }

          (yyval.expr) = new JSONRenameExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0),
                (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6661 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(7) - (5)].expr));

          if(lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(7) - (3)]), "An object invocation is expected. A filter was found instead.");
            delete (yysemantic_stack_[(7) - (7)].expr);
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(7) - (3)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            delete (yysemantic_stack_[(7) - (7)].expr);
            YYERROR;
          }

          (yyval.expr) = new JSONReplaceExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0),
                (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6689 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6693 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6697 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6704 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6711 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6718 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6735 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    {
          auto_ptr<QName> lQName( static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
          zstring const &tmp = lQName->get_qname();
          if ( tmp.find (':') != string::npos ) {
            error((yylocation_stack_[(1) - (1)]), "A NCName is expected, found a QName");
            YYERROR;
          }
          (yyval.sval) = SYMTAB_PUT(tmp.c_str());
        }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6748 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6749 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6750 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6751 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6752 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6753 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6754 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6755 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6756 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6757 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6758 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6759 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6760 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6761 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6762 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6767 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6768 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6769 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6770 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6771 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6772 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6773 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6774 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6775 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6776 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6777 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6778 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6779 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6780 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6781 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6782 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6783 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6784 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6785 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6786 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6787 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6788 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6789 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6790 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6791 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6792 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6793 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6794 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6795 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6796 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6797 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6798 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6799 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6800 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6801 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6802 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6803 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6804 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6805 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6806 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6807 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6808 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6809 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6810 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6811 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6812 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6813 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6814 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6815 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6816 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6817 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6818 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6819 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6820 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6821 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6822 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6823 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6824 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6825 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6826 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6827 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6828 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6829 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6830 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6831 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6832 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6833 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6834 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6835 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6836 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6837 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6838 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6839 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6840 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6841 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6842 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6843 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6844 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6845 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6846 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6847 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6848 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6849 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6850 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6851 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6852 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6853 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6854 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6855 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6856 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6857 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6858 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6859 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6860 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6861 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6862 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6863 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6864 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6865 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6866 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6867 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6868 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6869 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6870 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6871 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6872 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6873 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6874 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6875 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6876 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6877 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6878 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6879 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6880 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6881 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6882 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6883 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6884 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6885 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6886 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6887 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6888 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6889 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6890 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6891 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6892 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6893 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6894 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6895 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6896 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6897 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6898 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6899 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6900 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6901 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6902 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6903 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6904 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6905 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6906 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6907 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6908 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6909 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6910 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6911 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6912 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6913 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6914 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 963:

/* Line 678 of lalr1.cc  */
#line 6915 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 964:

/* Line 678 of lalr1.cc  */
#line 6916 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 965:

/* Line 678 of lalr1.cc  */
#line 6917 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 966:

/* Line 678 of lalr1.cc  */
#line 6918 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 967:

/* Line 678 of lalr1.cc  */
#line 6919 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 968:

/* Line 678 of lalr1.cc  */
#line 6920 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 969:

/* Line 678 of lalr1.cc  */
#line 6921 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 970:

/* Line 678 of lalr1.cc  */
#line 6922 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 971:

/* Line 678 of lalr1.cc  */
#line 6923 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 972:

/* Line 678 of lalr1.cc  */
#line 6924 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 973:

/* Line 678 of lalr1.cc  */
#line 6925 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 974:

/* Line 678 of lalr1.cc  */
#line 6926 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 975:

/* Line 678 of lalr1.cc  */
#line 6927 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 976:

/* Line 678 of lalr1.cc  */
#line 6928 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 977:

/* Line 678 of lalr1.cc  */
#line 6929 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 978:

/* Line 678 of lalr1.cc  */
#line 6930 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 979:

/* Line 678 of lalr1.cc  */
#line 6931 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 980:

/* Line 678 of lalr1.cc  */
#line 6932 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 981:

/* Line 678 of lalr1.cc  */
#line 6933 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 982:

/* Line 678 of lalr1.cc  */
#line 6934 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 983:

/* Line 678 of lalr1.cc  */
#line 6935 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 984:

/* Line 678 of lalr1.cc  */
#line 6936 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 985:

/* Line 678 of lalr1.cc  */
#line 6937 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 986:

/* Line 678 of lalr1.cc  */
#line 6938 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 987:

/* Line 678 of lalr1.cc  */
#line 6939 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 988:

/* Line 678 of lalr1.cc  */
#line 6940 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 989:

/* Line 678 of lalr1.cc  */
#line 6941 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 990:

/* Line 678 of lalr1.cc  */
#line 6942 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 991:

/* Line 678 of lalr1.cc  */
#line 6943 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 992:

/* Line 678 of lalr1.cc  */
#line 6944 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 993:

/* Line 678 of lalr1.cc  */
#line 6945 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 994:

/* Line 678 of lalr1.cc  */
#line 6946 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 995:

/* Line 678 of lalr1.cc  */
#line 6947 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 996:

/* Line 678 of lalr1.cc  */
#line 6948 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 997:

/* Line 678 of lalr1.cc  */
#line 6949 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 998:

/* Line 678 of lalr1.cc  */
#line 6950 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 999:

/* Line 678 of lalr1.cc  */
#line 6951 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1000:

/* Line 678 of lalr1.cc  */
#line 6952 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1001:

/* Line 678 of lalr1.cc  */
#line 6953 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1002:

/* Line 678 of lalr1.cc  */
#line 6954 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1003:

/* Line 678 of lalr1.cc  */
#line 6955 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1004:

/* Line 678 of lalr1.cc  */
#line 6956 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1005:

/* Line 678 of lalr1.cc  */
#line 6957 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1006:

/* Line 678 of lalr1.cc  */
#line 6958 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1007:

/* Line 678 of lalr1.cc  */
#line 6959 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1008:

/* Line 678 of lalr1.cc  */
#line 6960 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1009:

/* Line 678 of lalr1.cc  */
#line 6961 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1010:

/* Line 678 of lalr1.cc  */
#line 6962 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1011:

/* Line 678 of lalr1.cc  */
#line 6963 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1012:

/* Line 678 of lalr1.cc  */
#line 6964 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1013:

/* Line 678 of lalr1.cc  */
#line 6965 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1014:

/* Line 678 of lalr1.cc  */
#line 6966 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1015:

/* Line 678 of lalr1.cc  */
#line 6967 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1016:

/* Line 678 of lalr1.cc  */
#line 6968 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1017:

/* Line 678 of lalr1.cc  */
#line 6969 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1018:

/* Line 678 of lalr1.cc  */
#line 6970 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1019:

/* Line 678 of lalr1.cc  */
#line 6971 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1020:

/* Line 678 of lalr1.cc  */
#line 6976 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 12262 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1499;
  const short int
  xquery_parser::yypact_[] =
  {
      4624, -1499, -1499, -1499,  6178,  6178,  6178, -1499, -1499,    33,
     202, -1499,   933,   367, -1499, -1499, -1499,   227, -1499, -1499,
   -1499,   381,   538,   339,  4343,   561,   600,   803, -1499,   -26,
   -1499, -1499, -1499, -1499, -1499, -1499,   812, -1499,   607,   615,
   -1499, -1499, -1499, -1499,   514, -1499,   822, -1499,   685,   733,
   -1499,   409, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499,   471,   727, -1499, -1499,
   -1499, -1499,   619, 12068, -1499, -1499, -1499,   795, -1499, -1499,
   -1499,   717, -1499,   805,   855, -1499, -1499, 16455, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499,   868, -1499, -1499,   880,
     886, -1499, -1499, -1499, -1499, -1499, -1499, -1499,  5248,  8038,
    8348, 16455, -1499, -1499, -1499, -1499, -1499, -1499, -1499,   873,
   -1499, -1499,   916, 12963, -1499, 13266,   925,   927, -1499, -1499,
   -1499,   934, -1499, 11448, -1499, -1499, -1499, -1499, -1499, -1499,
     910, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,   117,
     851, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,   411,
     919,   476, -1499,   -77,   257, -1499, -1499, -1499, -1499, -1499,
   -1499,   958, -1499,   836,   837,   838, -1499, -1499,   923,   928,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499,  8658,  8968, -1499,   768, -1499, -1499, -1499,
   -1499, -1499,  4936,  6488,  1084, -1499,  6798, -1499, -1499,   721,
      88, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499,    98, -1499, -1499, -1499, -1499,
   -1499, -1499,   128, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499,  6178, -1499, -1499, -1499, -1499,   267, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499,   198, -1499,   895, -1499, -1499,
   -1499,   392, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
     920,   997, -1499,   971,   841,   992,   672,   634,   486,    41,
   -1499,  1042,   894,   994,   996, 10208, -1499,   903, -1499, -1499,
      25, -1499, -1499, 11758, -1499,   775, -1499,   945, 12068, -1499,
     945, 12068, -1499, -1499, -1499,   862, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499,   956,   949, -1499,
   -1499, -1499, -1499, -1499,   922, -1499,  6178,   929,   932,   437,
     437,  1075,   469,   570,   755, 16743, 16455,     4,  1063, 16455,
     965,  1000,   766, 12963,   773,   875, 16455, 16455,   815,   810,
      50, -1499, -1499, -1499, 12963,  6178,   936,  6178,    55, 10518,
   14151, 16455, -1499,   840,   843, 16455,  1007,   405,   976, 10518,
    1133,   104,    66, 16455,  1017,   999,  1029, -1499, 10518, 12666,
   16455, 16455, 16455,  6178,   950, 10518, 10518, 16455,  6178,   985,
     986, -1499, -1499, -1499, 10518, 14439,   987, -1499,   988, -1499,
   -1499, -1499, -1499,   989, -1499,   990, -1499, -1499, -1499, -1499,
   -1499,   991, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   16455, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499,  1006, 16455, -1499, -1499, -1499,   970,  5558,
    1028,   252,  1001,  1002,  1004, 16455,  6178, -1499,  1003,   166,
   -1499,   617, -1499,   113,  1120, 10518, -1499, -1499,   135, -1499,
   -1499, -1499,  1144, -1499, -1499, -1499, -1499, 10518,   952, -1499,
    1134, 10518, 10518, 13566,   975, 10518, 10518, 10518, 10518, 13566,
   10518,   937,   940, 16455,   974,   982, 10518, 10518,  5248,   935,
   -1499,    56, -1499,    44, 10518,  6488, -1499, -1499, -1499, -1499,
   -1499,   933,   803,   100,   122,  1164,  7108,  3081,  7418,  3402,
     717, -1499, -1499,   355,   717, -1499, 10518,  4022, -1499,  1055,
     528,   -26,  1013,  1012,  1015,  6178, 10518, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, 10828, 10828, 10828, -1499, 10828,
   10828, -1499, 10828, -1499, 10828, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, 10828, 10828,  1113, 10828, 10828, 10828, 10828, 10828,
   10828, 10828, 10828, 10828, 10828, 10828, 10828,   955,  1093,  1094,
    1095, -1499, -1499, -1499, 11138,  9278, -1499, -1499, 11448, 11448,
   10518,   945, -1499, -1499,   945, -1499,  9588,   945,  1041,  9898,
   -1499, -1499, -1499,   288, -1499,   316, -1499, -1499, -1499, -1499,
   -1499, -1499,  1085,  1088,   561,  1162, -1499, -1499, 16743,   948,
     535, 16455,  1036,  1037,   948,  1075,  1071,  1067, -1499, -1499,
   -1499,   171,   957,  1107,   905, 16455,  1060, 10518,  1087, 16455,
   16455, -1499,  1074,  1024,  6178, -1499,  1025,   988,   615, -1499,
    1023,  1026,   129, -1499,   408,   413,  1104, -1499,    46, -1499,
   -1499,  1104, 16455,    38, 16455,  1118,   423, -1499,  6178, -1499,
     131, -1499, 12963,  1119,  1169, 12963,  1075,  1122,   606, 16455,
   10518,   -26,   333,  1032, -1499,  1035,  1038,  1039,   263, -1499,
      74,  1043, -1499,   151,   152,  1070, -1499,  1045,  6178,  6178,
     364, -1499,   438,   439,   675, 10518,   320, -1499, -1499, 10518,
   10518, -1499, 10518, 10518, 10518, -1499, 10518, -1499, 10518, -1499,
   16455,  1120, -1499,   361,   390, -1499, -1499, -1499,   393, -1499,
      40, -1499, -1499,  1077,  1078,  1080,  1081,  1086,   862,   956,
   -1499,   389,   493,    -9,    -5,  1143,   591,   979,  1016,  1009,
     -13, -1499,  1096, -1499, -1499,  1053,   160,  5558,   418, 12369,
     935, -1499, -1499, -1499,  1011, -1499,   721,   348,  1212,   180,
   -1499, -1499,   126, -1499, -1499, -1499,   127, -1499,   138, -1499,
   -1499, -1499, -1499, -1499,  3712, -1499, -1499, -1499, 16455,  1079,
   10518,  1130, -1499, -1499, -1499,   997, -1499, -1499, -1499, -1499,
   -1499, 10828, -1499, -1499, -1499,    62, -1499,   634,   634,   585,
     486,   486,   486,   486,    41,    41, -1499, -1499, 15591, 15591,
   16455, 16455, -1499, -1499,   443, -1499, -1499,   292, -1499, -1499,
   -1499,   450, -1499, -1499,   461,   437, -1499, -1499,   749,   763,
     785, -1499,   561, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499,   948, -1499,  1121, 15879,  1108, 10518, -1499,
   -1499, -1499,  1157,  1075,  1075,   948, -1499,   856,  1075,   736,
   16455,   557,   683,  1223, -1499, -1499,   968,   682, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,   171,
      59,  1030,   478, 10518, -1499, 16455,  1161,   959,  1075, -1499,
   -1499, -1499, -1499,  1103, 16455, -1499, 16455, -1499, 16167,  1132,
   15591,  1145, 10518,   -42,  1114,    49,   404,  1008, -1499, -1499,
     747,    38,  1157, 15591,  1146,  1171,  1082,  1069,  1137,  1075,
    1112,  1141,  1178,  1075, 10518,    42, -1499, -1499, -1499,  1123,
   -1499, -1499, -1499, -1499,  1159, 10518, 10518,  1128, -1499,  1181,
    1185,  6178, -1499,  1102,  1105,  1125, 16455, -1499, 16455, -1499,
   10518,  1149,  1098, 10518, -1499,  1172,   175,   200,   234,  1257,
   -1499,   494, -1499,   579, -1499, -1499,  1266, -1499,   790, 10518,
   10518, 10518,   807, 10518, 10518, 10518, 10518, 10518, 10518, 10518,
   10518, 10518, 13566,  1179, 10518, 10518, -1499,  7728,   112,  1051,
   -1499,     6, -1499, 10518,   143,    69,   138,  7418,  3402,  7418,
    1220, -1499, -1499, 10518,   782,  1193, -1499, 16455,  1195, -1499,
   -1499, 10518,    62,   582,   207, -1499,  1018,    91,  1046,  1047,
   -1499, -1499,   875, -1499,  1044,   648,  1152,  1153, 15879,  1156,
    1158,  1160,  1163,  1166, -1499,    16, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,  1173,
   -1499, -1499, -1499, -1499, 10518, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499,   789, -1499,  1276,   827, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499,  1034, -1499, -1499,
    1286, -1499, -1499, -1499, -1499, -1499,   688,  1294, -1499,    92,
   -1499, -1499, -1499,   987,   538,   989,   607,   990,   991,   919,
    1158,  1160,  1163, -1499,    16,    16, 11138,  1040,  1020, -1499,
    1157,    59,  1097,  1140,  6178,  1147,  1148,  1187,  1150,  1151,
   16455, -1499,   568, -1499, 16455, -1499, 10518,  1189, 10518,  1205,
   10518,    67,  1197, 10518,  1198, -1499,  1224,  1228, 10518, 16455,
     995,  1270, -1499, -1499, -1499, -1499, -1499, -1499, 15591, -1499,
    6178,  1075,  1242, -1499, -1499, -1499,  1075,  1242, -1499, 10518,
    1208,  6178, 16455, -1499, -1499, 10518, 10518,   394, -1499,    22,
     483, -1499, 14727,   769, -1499,   802, -1499,  1168, -1499, -1499,
    6178,  1167,  1170, -1499, 10518, -1499, -1499, 10518,  1155,  1181,
    1255, -1499,  1226, -1499,   711, -1499, -1499,  1352, -1499, -1499,
    6178, 16455, -1499,   787, -1499, -1499, -1499,  1174,  1127,  1129,
   -1499, -1499, -1499,  1136,  1139, -1499, -1499, -1499,  1265, -1499,
   -1499, -1499, -1499,  1126,   360, 16455,  1180, -1499,  1209,  1211,
    1214,  1221, -1499,   895,   647, 12369,  1051, -1499,  5868, 12369,
   -1499, -1499,  1212,   713, -1499, -1499, -1499,  1193, -1499,  1075,
   -1499,   926, -1499,    68,  1267, -1499, 10518,   752,  1130,   459,
    1188, -1499,    62,  1131, -1499, -1499,   149, -1499,   -71,    79,
    1135,    62,   -71, 10828, -1499,   158, -1499, -1499, -1499, -1499,
   -1499, -1499,    62,  1229,  1100,   957,    79, -1499, -1499,  1091,
    1300, -1499, -1499, -1499, 13863,  1192,  1196,  1199,  1200,  1201,
    1202,  1203, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499,  1351,   518,  1355,   518,  1138,  1284,
   -1499, -1499,  1222, 16455,  1142, -1499, -1499, 11138, -1499,  1213,
   -1499, -1499, -1499, -1499, -1499, -1499, 10518,  1246, -1499, -1499,
   10518, -1499,   599, -1499, 10518,  1249, 10518, -1499, 10518, 16455,
   16455, -1499,   808, -1499, 10518, -1499,  1272,  1274,  1305,  1075,
    1242, -1499, 10518,  1231, -1499, -1499, -1499,  1218, -1499,    80,
   10518,  6178,  1219,   302, -1499, 16455,   447, -1499, 15015,   356,
   -1499, 15303,  1230, -1499, -1499,  1233, -1499, -1499, -1499, -1499,
   10518,   835,  1257, 16455,   830, -1499,  1234,  1257, 16455, -1499,
   -1499, 10518, 10518, 10518, 10518,  1092, 10518, 10518, -1499, 10518,
   10518, 10518, 10518,  7728,    13, -1499, -1499, -1499, -1499, -1499,
    1267, -1499, -1499, -1499,  1075, 10518, -1499,  1277, -1499, -1499,
   -1499, -1499,  1238, 10828, -1499, -1499, -1499, -1499, -1499,   105,
   10828, 10828,   -86, -1499,  1046, -1499,   397, -1499,  1047,    62,
    1254, -1499, -1499,  1154, -1499, -1499, -1499, -1499,  1318,  1237,
   -1499,   462, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
     549,   549, -1499,   518, -1499, -1499,   475, -1499,  1396,    79,
    1333,  1243, 11138,   -22,  1165,  1261, -1499, -1499, 10518, -1499,
   10518,  1288, -1499, 10518, -1499, -1499, -1499,  1383, -1499, -1499,
    7728, 10518,  1075, -1499, -1499, -1499, 10518, 10518, -1499, -1499,
   -1499,  7728,  7728,  1343,  6178, 15591, 16455,   563, 16455, 10518,
   16455,   664,  7728, -1499,   426,   276,  1257, 16455, -1499,  1244,
    1257, -1499, -1499, -1499, -1499, 10518, -1499, -1499, -1499,   245,
     319,   324, 10518, -1499, -1499, -1499,  1336, 10518, -1499,   486,
   10828, 10828,   585,   684, -1499, -1499, -1499, -1499, -1499, -1499,
   10518, -1499, 15591, -1499, 15591,  1345, -1499, -1499, -1499,  1415,
   -1499, -1499, -1499,  1186,  1338, -1499, -1499,  1346, -1499,   814,
   16455,  1332,  1232, 16455, 11138, -1499, -1499, 10518, -1499,  1337,
   -1499, -1499,  1242, -1499, -1499, 15591, -1499, -1499, -1499,  1362,
   10518,  1273, -1499,  1364,  7728, -1499, 16455,   604,   387, -1499,
    1263,  1257, -1499,  1264, -1499,  1268,  1181,  1185,   463, -1499,
    1336,   585,   585, 10828,   468, -1499, -1499, 15591, -1499, -1499,
    1333, 11138, -1499,  1267,  1175, 16455,  1347,  1239,  1346, -1499,
   16455,   676, 15591,  6178, 15591,  1281, -1499, -1499,  1370,   679,
   -1499, -1499, -1499, -1499,  1285,   556, -1499, -1499, -1499,  1278,
   -1499,  7728,   849, -1499, -1499,   585, -1499, -1499, -1499, -1499,
   -1499, 10518,  1177, 16455,  1353, -1499,  6178,   693, -1499, -1499,
     706, 10518, -1499, -1499, -1499, -1499, -1499, -1499, -1499,  1356,
   -1499,  1176,  1182, 16455, -1499, -1499, 10518,  7728, 16455,  1183,
   10518,  1190,  1287, 11138, -1499, 11138,  7728, -1499,  1271,  1191,
   16455,  1251,  1359, 16455,  1194, 11138, -1499
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       165,   466,   467,   468,   168,   168,   168,   815,  1020,   120,
     122,   621,   907,   916,   856,   820,   818,   800,   908,   911,
     863,   824,   801,   802,     0,   917,   804,   914,   885,   865,
     840,   860,   861,   912,   909,   859,   806,   915,   807,   808,
     956,   968,   955,   857,   876,   870,   809,   858,   811,   810,
     957,   894,   895,   862,   837,   978,   979,   980,   981,   982,
     983,   984,   985,   986,   987,   988,  1002,  1009,   884,   880,
     871,   851,   799,     0,   879,   887,   896,  1003,   875,   492,
     852,   853,   910,  1004,  1010,   872,   889,     0,   498,   455,
     494,   882,   817,   873,   874,   903,   877,   893,   902,  1008,
    1011,   823,   864,   905,   493,   892,   898,   803,     0,     0,
       0,     0,   401,   890,   901,   906,   904,   883,   869,   958,
     867,   868,  1005,     0,   400,     0,  1006,  1012,   899,   854,
     878,  1007,   433,     0,   465,   900,   881,   888,   897,   891,
     959,   845,   850,   849,   848,   847,   846,   812,   866,     0,
     816,   913,   838,   947,   946,   948,   822,   821,   841,   953,
     805,   945,   950,   951,   942,   844,   886,   944,   954,   952,
     943,   842,   949,   963,   964,   961,   962,   960,   813,   965,
     966,   967,   933,   932,   919,   836,   829,   926,   922,   839,
     835,   934,   935,   825,   826,   819,   828,   931,   930,   927,
     923,   940,   941,   939,   929,   925,   918,   827,   938,   937,
     831,   833,   832,   924,   928,   920,   834,   921,   830,   936,
     989,   990,   991,   992,   993,   994,   970,   971,   969,   975,
     976,   977,   972,   973,   974,   843,   995,   996,   997,   998,
     999,  1000,  1001,     0,     0,  1013,  1014,  1015,  1018,  1017,
    1016,  1019,   165,   165,     0,     2,   165,     9,    11,    23,
       0,    28,    31,    36,    37,    38,    39,    40,    41,    42,
      32,    58,    59,    33,    34,     0,    76,    79,    80,    35,
      81,    82,     0,   118,    83,    84,    85,    86,    18,   162,
     163,   164,   171,   174,   485,   175,     0,   176,   177,   178,
     179,   180,   181,   182,   185,     0,   211,   219,   214,   246,
     252,     0,   244,   245,   221,   215,   184,   216,   183,   217,
     220,   352,   354,   356,   366,   368,   372,   374,   377,   382,
     385,   388,   390,   392,   394,     0,   398,   405,   404,   406,
       0,   424,   407,   429,   432,   434,   437,   439,     0,   444,
     441,     0,   452,   462,   464,   438,   469,   476,   490,   477,
     478,   479,   482,   483,   480,   481,   505,   507,   508,   509,
     506,   554,   555,   556,   557,   558,   559,   461,   595,   587,
     594,   593,   592,   589,   591,   588,   590,   491,   484,   622,
     623,    43,   222,   223,   225,   224,   226,   218,   487,   488,
     489,   486,   228,   231,   227,   229,   230,   463,   798,   814,
     907,   916,   914,   816,     0,   166,   167,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,   256,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   274,   275,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   457,   460,   447,     0,     0,   800,   824,   802,   855,
     917,   804,   865,   806,   876,   809,   811,   810,   894,  1002,
    1009,   799,  1003,   853,  1004,  1010,   877,  1008,  1011,   958,
    1005,  1006,  1012,  1007,   959,   953,   945,   951,   942,   842,
     963,   964,   961,   813,   965,  1014,   453,   463,   798,   445,
       0,   192,   446,   449,   800,   801,   802,   806,   807,   808,
     809,   799,   805,   495,     0,   451,   450,   187,     0,     0,
     211,     0,   804,   811,   810,     0,   168,   773,   965,     0,
     219,     0,   496,     0,   521,     0,   456,   796,     0,   797,
     427,   428,     0,   459,   458,   448,   431,     0,     0,   550,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     775,     0,   777,     0,     0,   165,     3,     4,     1,    10,
      12,     0,     0,     0,     0,     6,   165,     0,   165,     0,
       0,   119,   172,     0,     0,   190,     0,     0,   199,     0,
       0,     0,     0,     0,     0,     0,     0,   204,   232,   251,
     247,   253,   248,   250,   249,     0,     0,     0,   417,     0,
       0,   415,     0,   361,     0,   416,   409,   414,   413,   412,
     411,   410,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   403,   402,   399,     0,     0,   425,   430,     0,     0,
       0,   440,   473,   443,   442,   454,     0,   470,     0,     0,
     561,   563,   567,     0,   124,     0,   795,    47,    44,    45,
      48,    49,     0,     0,     0,     0,    50,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   632,   633,
     634,     0,   103,   142,     0,     0,   112,     0,     0,     0,
       0,   127,     0,     0,     0,   601,     0,     0,     0,   597,
       0,     0,     0,   611,     0,     0,   255,   257,     0,   234,
     235,   254,     0,     0,     0,   134,     0,   138,   168,   625,
       0,    60,     0,    69,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,   602,     0,     0,     0,     0,   323,
       0,     0,   600,     0,     0,     0,   619,     0,     0,     0,
       0,   605,     0,     0,   194,     0,     0,   188,   186,     0,
       0,   779,     0,     0,     0,   495,     0,   774,     0,   497,
     522,   521,   518,     0,     0,   552,   551,   426,     0,   549,
       0,   645,   646,   800,   802,   806,   809,   799,   786,     0,
     596,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   651,     0,   202,   203,     0,     0,     0,     0,     0,
     207,   208,   776,   778,     0,     5,    24,     0,    25,     0,
       7,    29,     0,    15,     8,    30,     0,    19,   907,    77,
      16,    78,    20,   193,     0,   191,   212,   213,     0,     0,
       0,     0,   205,   233,   292,   353,   355,   359,   365,   364,
     363,     0,   360,   357,   358,     0,   369,   376,   375,   373,
     379,   380,   381,   378,   383,   384,   387,   386,     0,     0,
       0,     0,   408,   422,     0,   435,   436,     0,   474,   471,
     503,     0,   624,   501,     0,     0,   121,   123,     0,     0,
       0,   102,     0,    92,    94,    95,    96,    97,    99,   100,
     101,    93,    98,    88,    89,     0,     0,   108,     0,   104,
     106,   107,   114,     0,     0,    87,    46,     0,     0,     0,
       0,     0,     0,     0,   723,   728,     0,     0,   724,   758,
     711,   713,   714,   715,   717,   719,   718,   716,   720,     0,
       0,     0,     0,     0,   111,     0,   144,     0,     0,   566,
     560,   598,   599,     0,     0,   615,     0,   612,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
       0,   242,   140,     0,     0,   135,     0,     0,     0,     0,
       0,     0,    62,     0,     0,     0,   273,   279,   276,     0,
     604,   603,   610,   618,     0,     0,     0,     0,   565,     0,
       0,     0,   418,     0,     0,     0,     0,   608,     0,   606,
       0,   195,     0,     0,   780,     0,     0,     0,     0,   521,
     519,     0,   510,     0,   499,   500,     0,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,     0,     0,     0,
     659,     0,   209,     0,     0,     0,     0,   165,     0,   165,
       0,   173,   243,     0,   307,   303,   305,     0,   293,   294,
     362,     0,     0,     0,     0,   689,   370,   662,   666,   668,
     670,   672,   675,   682,   683,   691,   917,   803,     0,   812,
    1018,  1017,  1016,  1019,   389,   570,   576,   577,   580,   626,
     627,   581,   582,   789,   790,   791,   585,   391,   393,   396,
     586,   395,   423,   475,     0,   472,   502,   125,    56,    57,
      54,    55,   131,   130,     0,    90,     0,     0,   109,   110,
     115,    74,    75,    52,    53,    73,   729,     0,   732,   759,
       0,   722,   721,   726,   725,   757,     0,     0,   734,     0,
     730,   733,   712,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,   146,   148,     0,     0,     0,   113,
     116,     0,     0,     0,   168,     0,     0,   619,     0,     0,
       0,   259,     0,   569,     0,   260,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,     0,     0,     0,     0,
     286,     0,   283,   288,   241,   141,   136,   139,     0,   189,
       0,     0,    71,    65,    68,    67,     0,    63,   277,     0,
       0,   168,     0,   321,   325,     0,     0,     0,   328,     0,
       0,   334,     0,     0,   341,     0,   345,     0,   420,   419,
     168,     0,     0,   196,     0,   198,   322,     0,     0,     0,
       0,   522,     0,   511,     0,   545,   542,     0,   546,   547,
       0,     0,   541,     0,   516,   544,   543,     0,     0,     0,
     638,   639,   635,     0,     0,   643,   644,   640,   782,   783,
     649,   787,   647,     0,     0,     0,     0,   653,   804,   811,
     810,   965,   201,     0,     0,     0,   654,   655,     0,     0,
     210,   785,    26,     0,    17,    21,    22,   304,   316,     0,
     317,     0,   308,   309,   310,   311,     0,   296,     0,     0,
       0,   673,   686,     0,   367,   371,     0,   705,     0,     0,
       0,     0,     0,     0,   661,   663,   664,   700,   701,   702,
     704,   703,     0,     0,   677,   676,     0,   680,   684,   698,
     696,   695,   688,   692,     0,     0,     0,     0,     0,     0,
       0,     0,   573,   575,   574,   571,   397,   504,   133,   132,
      91,   105,   746,   727,     0,   751,     0,   751,   740,   735,
     147,   149,     0,     0,     0,   117,   145,     0,    27,     0,
     616,   617,   620,   613,   614,   258,     0,     0,   272,   264,
       0,   268,     0,   262,     0,     0,     0,   281,     0,     0,
       0,   240,   284,   287,     0,   137,     0,     0,    70,     0,
      64,   278,     0,     0,   324,   326,   331,     0,   329,     0,
       0,     0,     0,     0,   335,     0,     0,   349,     0,     0,
     342,     0,     0,   346,   421,     0,   609,   607,   197,   781,
       0,     0,   521,     0,     0,   553,     0,   521,     0,   517,
      14,     0,     0,     0,     0,     0,     0,     0,   652,     0,
       0,     0,     0,     0,     0,   656,   660,   320,   318,   319,
     312,   313,   314,   306,     0,     0,   301,     0,   295,   690,
     681,   687,     0,     0,   760,   761,   771,   770,   769,     0,
       0,     0,     0,   762,   667,   768,     0,   665,   669,     0,
       0,   674,   678,     0,   699,   694,   697,   693,     0,     0,
     583,     0,   578,   631,   572,   793,   794,   792,   579,   747,
       0,     0,   745,   752,   753,   749,     0,   744,     0,   742,
       0,     0,     0,     0,     0,     0,   562,   261,     0,   270,
       0,     0,   266,     0,   269,   282,   290,   291,   285,   239,
       0,     0,     0,    66,   280,   568,     0,     0,   332,   336,
     330,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   564,     0,     0,   521,     0,   548,     0,
     521,   636,   637,   641,   642,     0,   648,   788,   650,     0,
       0,     0,     0,   657,   315,   302,   297,     0,   685,   772,
       0,     0,   764,     0,   710,   709,   708,   707,   706,   671,
       0,   763,     0,   628,     0,     0,   756,   755,   754,     0,
     748,   741,   739,     0,   736,   737,   731,   150,   152,   154,
       0,     0,     0,     0,     0,   265,   263,     0,   271,     0,
     206,   351,    72,   327,   333,     0,   347,   343,   350,     0,
       0,     0,   337,     0,     0,   339,     0,   531,   525,   520,
       0,   521,   512,     0,   784,     0,     0,     0,     0,   300,
     298,   766,   765,     0,     0,   629,   584,     0,   750,   743,
       0,     0,   156,   155,     0,     0,     0,     0,   151,   267,
       0,     0,     0,     0,     0,     0,   539,   533,     0,   532,
     534,   540,   537,   527,     0,   526,   528,   538,   514,     0,
     513,     0,     0,   658,   299,   767,   679,   630,   738,   153,
     157,     0,     0,     0,     0,   289,     0,     0,   340,   338,
       0,     0,   524,   535,   536,   523,   529,   530,   515,     0,
     158,     0,     0,     0,   348,   344,     0,     0,     0,     0,
       0,     0,     0,     0,   160,     0,     0,   159,     0,     0,
       0,     0,     0,     0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1499, -1499,  -205,  -181, -1499,  1227,  1235, -1499,  1225,  -543,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
    -989, -1499, -1499, -1499, -1499,  -216,  -571, -1499,   761,    -2,
   -1499, -1499, -1499, -1499, -1499,   309,   522, -1499, -1499,     9,
    -192,  1068, -1499,  1052, -1499, -1499,  -631, -1499,   470, -1499,
     272, -1499,  -199,  -244, -1499,  -555, -1499,    -3,    11,     8,
    -281,  -170, -1499,  -871, -1499, -1499,   330, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499,   638,   185,  1303,
       0, -1499, -1499, -1499, -1499,   480, -1499, -1499,  -304, -1499,
      23, -1499,  1048,  -928,  -728,  -709, -1499, -1499,   718, -1499,
   -1499,    47,   256, -1499, -1499, -1499,   134, -1498, -1499,   395,
     144, -1499, -1499,   148, -1297, -1499,   969,   240, -1499, -1499,
     237, -1018, -1499, -1499,   235, -1499, -1499, -1247, -1231, -1499,
     231, -1404, -1499, -1499,   872,   874, -1499,  -513,   853, -1499,
   -1499,  -650,   391,  -630,   396,   385, -1499, -1499, -1499,   598,
   -1499, -1499,  1204, -1499, -1499, -1499, -1499, -1499,  -879,  -316,
    -673, -1499,   -98, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
     -19,  -823, -1499,  -533,   659,   326, -1499,  -400, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499,   823, -1499, -1005, -1499,   220,
   -1499,   704,  -789, -1499, -1499, -1499, -1499, -1499,  -238,  -231,
   -1232,  -892, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499,  -753,  -885,  -149,  -810, -1499, -1499, -1499,  -749,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499,  1083,  1089,  -328,
     523,   354, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499, -1499, -1499, -1499,   199, -1499, -1499,   187,
   -1499,   191, -1063, -1499, -1499, -1499,   157,   150,   -18,   417,
   -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499, -1499,
   -1499, -1499, -1499,   159, -1499, -1499, -1499,   -11,   415,   554,
   -1499, -1499, -1499, -1499, -1499,   349, -1499, -1499, -1475, -1499,
   -1499, -1499,  -509, -1499,   123, -1499,   -34, -1499, -1499, -1499,
   -1499, -1308, -1499,   169, -1499, -1499, -1499, -1499, -1499,   966,
   -1499, -1499, -1499, -1499, -1499,  -925, -1499, -1499, -1499,  -383,
    -358,   -65,   977, -1499
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   254,   627,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
    1262,   776,   272,   273,   274,   275,   276,   277,   953,   954,
     955,   278,   279,   280,   959,   960,   961,   281,   439,   282,
     283,   703,   284,   441,   442,   443,   458,   766,   767,   285,
    1213,   286,  1687,  1688,   287,   288,   289,   548,   290,   291,
     292,   293,   294,   769,   295,   296,   531,   297,   298,   299,
     300,   301,   302,   637,   303,   304,   860,   861,   305,   306,
     560,   308,   638,   456,  1020,  1021,   309,   639,   310,   641,
     561,   312,   756,   757,  1250,   465,   313,   466,   467,   763,
    1251,  1252,  1253,   642,   643,  1118,  1119,  1536,   644,  1115,
    1116,  1362,  1363,  1364,  1365,   314,   788,   789,   315,  1277,
    1278,  1479,   316,  1280,  1281,   317,   318,  1283,  1284,  1285,
    1286,  1486,   319,   320,   321,   322,   901,   323,   324,  1374,
     325,   326,   327,   328,   329,   330,   331,   332,   333,  1158,
     334,   335,   336,   337,   662,   663,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   697,   692,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   931,   365,   366,   367,  1313,
     821,   822,   823,  1719,  1764,  1765,  1758,  1759,  1766,  1760,
    1314,  1315,   368,   369,  1316,   370,   371,   372,   373,   374,
     375,   376,  1015,  1487,  1415,  1145,  1571,  1146,  1159,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   795,
    1226,   387,   388,   389,   390,  1148,  1149,  1150,  1151,   391,
     392,   393,   394,   395,   396,   850,   851,   397,  1346,  1347,
    1653,  1101,  1126,  1384,  1385,  1127,  1128,  1129,  1130,  1131,
    1394,  1561,  1562,  1132,  1397,  1133,  1542,  1134,  1135,  1402,
    1403,  1567,  1565,  1386,  1387,  1388,  1389,  1667,   732,   980,
     981,   982,   983,   984,   985,  1200,  1591,  1684,  1201,  1589,
    1682,   986,  1427,  1586,  1582,  1583,  1584,   987,   988,  1390,
    1398,  1552,  1391,  1548,  1375,   398,   399,   400,   401,   551,
     402,   403,   404,   405,   406,  1152,  1153,  1154,  1155,  1263,
     568,   407,   408,   409
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -856;
  const short int
  xquery_parser::yytable_[] =
  {
       307,   414,   417,   418,   307,   307,   307,   640,   527,   599,
     622,   922,   416,   416,   416,   415,   415,   415,   909,   704,
     704,   440,   543,   311,   686,  1035,  1124,   311,   311,   311,
    1013,  1279,  1071,  1144,  1157,   576,  1100,  1047,   707,   910,
     911,   912,   913,   614,  1267,   615,   564,   879,   881,  1014,
     838,  1061,  1490,  1501,   526,   617,   846,   615,   569,  1370,
     572,   873,   877,   880,   882,  1215,  1531,  1532,  1312,  1173,
     619,   606,   607,   871,   875,   727,     9,    10,   773,   777,
    1231,  1509,  1009,   940,  1627,  1239,   742,  1631,  1563,   615,
     621,    11,   463,  1017,  1093,   706,  1690,   425,  1203,   615,
     747,   615,   810,  1204,   747,  1236,   421,   422,   307,   423,
     424,   785,   809,   615,   615,  1685,   549,   748,  1205,   415,
    1206,   748,  1480,   615,   428,  1233,   427,   615,   615,  1207,
     615,   311,   615,   706,   897,   622,   898,   899,  1256,   900,
    1010,   902,  1011,   825,   615,  1011,  1177,   578,   588,   903,
     904,   626,   615,   615,     9,    10,  1208,  1660,  1729,  1348,
    1412,   615,   738,   626,     9,    10,  1652,   615,  1010,  1147,
    1147,  1076,    79,   716,  1359,  1549,   615,   675,   685,   774,
    1480,   874,  1353,  1664,  1269,   425,    90,  1376,  1197,   419,
    1665,   676,  1413,  1012,   426,  1361,  1240,  1546,  -169,   615,
    1666,   615,   125,  1691,  1547,  1198,   717,  1147,  1481,  1180,
    1414,   104,   428,  1106,  1454,  1121,  1349,   429,  1122,   626,
     626,  1046,  1094,  1349,  1086,   969,   775,   970,  1087,   433,
    1077,   464,  1774,  1654,  1661,   615,   626,   589,   626,   125,
     620,  1214,   749,  1124,  1124,   687,   615,   464,   621,   430,
     431,  1110,   307,   307,  1376,  1018,   307,   640,   626,   626,
    1377,  1147,  1483,  1244,   772,  1778,  1617,   626,   622,  1255,
    1490,   971,  1509,   626,  1147,   311,   311,  1470,   616,   311,
    1302,  1683,   626,   527,  1209,  1692,   527,  1241,   618,   434,
     866,   307,  1019,   615,   559,   563,  1215,   879,   881,  1312,
     819,  1751,  1445,  1419,  1237,   626,  1242,   626,  1312,  1541,
     826,  1174,   868,  1003,   311,   464,  1107,  1109,  1027,   464,
     615,  1123,   464,   871,   875,   615,  1270,  1377,  1406,   693,
     435,   579,   695,  1352,   615,  1550,  1551,   739,  1049,  1050,
     464,   626,   966,  1378,  1379,   740,  1380,  1097,  1787,   874,
    1790,   817,   626,  1381,   892,  -170,   615,   863,   420,   810,
    1372,   715,  1298,  1382,   719,   615,  1544,   862,   569,  1717,
    1044,   733,   734,  1465,   624,  1383,  1210,  1211,  1212,   569,
     445,  1105,  -169,   446,   125,   755,   758,  1299,  1120,  1147,
     758,   615,  1742,  1032,   615,   935,  1305,   612,   778,   626,
     872,   876,  1480,  1545,   569,   786,   787,   790,   867,   869,
    1378,  1379,   796,  1380,  1028,  1762,   307,  1031,   884,   615,
     803,  1300,   972,   935,   865,   436,   626,  1044,   601,   603,
    1382,   626,  1725,   437,   629,   973,   811,   974,   630,   311,
     626,   438,  1383,   631,   615,   307,  1780,   307,   975,   976,
     977,  1045,   978,   744,   979,   744,   743,   625,   746,  1718,
     615,   632,   626,   622,   615,   804,    11,  1435,   311,   615,
     311,   626,  1214,   307,  1628,   936,   623,  1163,   307,   790,
    1772,   744,   590,  1078,   791,   477,   744,   591,  1622,   797,
     815,  1072,   449,  1124,  1276,   450,   311,   626,  1010,  1312,
     626,   311,  1124,   937,  1447,  1125,  1726,  1477,  1063,  1147,
    1308,  1727,  1309,  1124,   690,  1004,   696,  1039,   839,  1570,
    1006,  1763,  1100,   764,   839,   626,  1526,   444,   852,   451,
    1024,   452,  1455,  1147,   447,  1167,   879,   881,   879,  -170,
    1310,  1490,  1629,  1432,  1716,  1056,  1058,    79,  1055,   307,
     626,  1243,  1354,  1355,  1356,   666,   307,  1164,  1073,  1334,
     633,    90,   478,   634,   416,  1305,   626,   415,  1164,  1674,
     626,   592,   311,   667,  1074,   626,   622,  1075,   635,   311,
    1181,  1182,  1679,  1276,  1762,  1185,   104,  1082,  1305,  1306,
     925,   926,   765,   481,   453,  1005,  1482,  1517,   307,   454,
    1007,   623,  1099,  1111,   636,   307,   857,  1079,  1080,  1756,
    1025,    11,  1629,  1305,  1537,  1223,   307,   307,   307,   307,
     440,   311,  1081,  1702,  1303,  1057,  1059,  1162,   311,   956,
     479,   480,   472,  1624,   752,   307,   581,  1165,   582,   311,
     311,   311,   311,  1539,   770,  1424,   455,  1773,  1166,  1675,
    1104,   708,  1776,   782,  1580,  1147,   962,  1625,   311,   629,
     793,   794,  1680,   630,  1011,   709,  1664,  1108,   631,   800,
     992,   869,   957,  1665,   996,   997,  1225,   958,  1228,  1308,
    1124,  1309,  1307,  1666,  1756,  1089,   632,   673,  1305,   629,
    1796,  1304,    79,   630,   448,  1011,   674,  1016,   631,  1022,
    1010,   585,  1308,   586,  1309,  1426,    90,   569,  1483,  1310,
     569,  1083,  1084,  1635,  1036,  1446,   632,   457,  1639,  1581,
    1305,  1306,  1125,  1125,  1601,   583,  1085,  1308,  1291,  1309,
    1292,   104,  1310,  1556,   623,  1121,   111,  1757,  1122,  1147,
    1708,   483,  1147,   666,   307,   690,  1600,   696,  1034,  1710,
     824,   669,   710,   123,   611,  1069,   459,  1310,   722,   125,
     723,   667,   828,   470,  1595,  1026,   711,   311,   307,  1010,
     612,   471,   484,  1625,  1311,   485,   416,  1217,  1197,   415,
     670,   879,   856,   858,  1424,   633,  1218,  1735,   634,  1736,
     587,   311,   149,   671,   527,  1198,  1305,  1306,   307,   307,
    1246,  1425,  1308,   818,  1309,  1247,   744,   744,   686,  1053,
    1054,   722,  1793,   723,  1307,   633,  1342,  1060,   634,   725,
    1191,   311,   311,  1112,  1248,  1761,  1767,   460,   672,   636,
     666,  1192,  1310,  1523,  1308,   530,  1309,   461,  1199,  1305,
    1306,   475,   666,  1011,  1426,   724,  1010,  1720,   667,   482,
    1714,  1723,  1777,  1156,  1156,  1160,  1160,   307,  1534,   636,
     667,  1246,  1786,   462,  1310,  1249,  1247,  1761,   111,  1488,
     924,   668,   725,  1767,  1625,   927,  1147,  1358,  1468,  1806,
     311,   726,  1489,  1733,   307,   123,  1625,   440,  1359,   476,
    1307,  1156,  1807,   884,  1535,  1399,  1400,  1168,  1360,   869,
    1662,  1663,  1491,  1625,  1011,  1190,  1503,   311,  1010,  1361,
    1308,  1170,  1309,  1659,  1169,  1492,  1625,   529,  1401,  1689,
    1359,   712,  1172,  1147,   149,  1147,  1418,   532,  1171,   623,
    1220,  1350,  1769,  1307,   726,  1488,  1743,   713,   768,  1227,
    1310,  1227,   768,   758,   111,  1156,  1193,   736,  1634,  1488,
     883,  1175,   737,  1308,   885,  1309,  1147,  1194,  1156,     9,
      10,   123,  1799,  1175,   957,   468,   688,   689,   469,   958,
     421,   422,  1125,   423,   424,   473,  1527,   533,   474,  1466,
     425,  1125,  1508,  1310,  1183,  1184,   544,   111,  1147,   426,
     427,   796,  1125,   796,   728,   729,   730,  1066,  1067,  1068,
     149,   858,   545,  1147,   123,  1147,   691,   428,   546,   694,
    1731,  1732,   429,  1186,  1187,  1188,   690,   928,   696,  1189,
     928,  1689,  1318,   928,  1319,  1637,   565,   839,   943,   944,
     945,   946,   947,   948,   949,   950,   951,   952,   566,  1323,
     640,  1324,  1098,   149,   430,   431,   432,   573,  1246,   574,
     528,   307,  1367,  1247,  1528,  1529,   575,   907,   908,   744,
     916,   917,  1287,   577,   528,  1430,  1431,   580,  1689,   914,
     915,  1676,  1677,  1156,   311,   584,   593,   594,   595,   597,
     596,   598,   604,  1775,   608,   628,  1613,   645,   528,   646,
     664,   665,   677,   433,   678,   679,   684,  1343,   680,   690,
     528,   698,   528,   647,   706,   699,   700,   307,   307,   307,
     718,   648,   649,   701,   650,   440,   702,   720,   721,   735,
    1344,   731,   651,   745,   759,   762,   652,   760,   653,   768,
     311,   311,   311,   654,   771,   779,   781,   792,   798,   799,
    1817,   780,  1818,   446,   450,   469,   474,   485,   805,   809,
     655,  1655,  1826,   434,   807,   820,   816,   812,   813,  1125,
     814,   827,   840,   830,   853,   758,   829,   870,   848,  1448,
     849,   599,   854,   888,   656,   657,   658,   659,   660,   661,
     859,   889,   890,   905,  1462,   891,   918,   919,   920,   921,
     932,   941,   938,  1156,   435,   939,   963,   964,   967,   968,
    1619,   990,   993,   989,   991,   995,   998,   790,   999,  1000,
    1001,  1008,  1023,  1002,  1030,  1029,  1090,  1156,  1033,  1040,
     436,  1439,  1041,  1051,   307,  1042,  1043,  1048,   437,  1052,
     445,   449,   416,   468,   473,   415,   438,  1088,  1095,   484,
    1092,  1091,   892,  1096,  1103,  1106,  1507,   311,  1117,  1113,
     958,  1010,  1195,  1176,  1196,  1221,  1224,  1216,  1222,  1232,
     307,  1238,  1245,  1234,   764,  1258,  1259,  1260,  1473,  1261,
     852,   307,  1264,  1265,  1266,  1275,  1271,  1272,  1290,   416,
     527,  1276,   415,   311,   527,  1282,  1288,  1495,  1295,  1289,
     307,  1294,  1301,  1297,   311,  1317,  1345,  1335,   416,   724,
    1366,   415,  1368,  1373,  1392,    11,  1369,  1393,  1404,  1405,
     307,  1396,  1407,   311,  1408,  1423,  1409,  1416,   744,  1410,
    1422,  1506,  1411,  1428,  1437,   528,  1434,  1433,   528,  1700,
    1438,  1442,  1452,   311,  1440,  1441,  1450,  1443,  1444,  1156,
    1704,  1619,  1459,  1706,  1456,  1458,  1460,  1464,  1343,  1469,
    1472,  1715,  1494,  1500,  1496,  1488,   857,  1497,  1502,  1505,
    1511,  1515,  1512,  1516,  1510,  1520,  1519,  1521,  1593,  1513,
    1522,  1344,  1514,  1359,  1348,  1540,  1559,  1564,  1566,  1572,
    1579,  1543,  1560,  1573,  1585,  1553,  1574,  1575,  1576,  1577,
    1578,  1590,  1592,  1598,  1606,  1607,  1603,  1596,  1610,  1594,
    1611,  1612,   714,   528,  1616,  1621,   528,  1670,  1645,  1588,
     528,   550,  1672,   528,   528,  1615,  1632,  1633,  1638,  1657,
    1623,   528,  1658,  1156,  1673,  1681,  1156,   528,   528,  1197,
    1686,  1694,   528,  1706,  1671,  1697,  1699,  1705,  1636,  1737,
     528,  1722,  1534,  1640,  1738,  1740,   528,   528,   528,   528,
    1745,  1739,  1693,  1741,   528,  1750,  1752,  1746,  1754,  1753,
    1768,  1770,   528,  1792,  1784,  1783,  1771,  1791,  1795,  1809,
    1819,  1803,  1788,  1816,  1808,  1798,  1822,  1823,  1820,  1178,
    1781,   307,  1801,   609,   613,   965,  1421,  1810,   705,  1813,
    1466,   610,   741,  1436,  1257,  1748,  1815,  1779,  1102,  1038,
    1825,  1254,  1538,   761,   311,  1804,  1463,   528,  1357,  1608,
    1533,  1530,  1474,   806,  1478,  1484,  1493,   895,   906,  1161,
     896,   528,   934,  1343,  1504,  1070,  1804,  1797,  1794,  1229,
    1420,   750,   528,  1525,  1518,  1788,  1524,   751,  1554,   683,
    1371,  1669,  1558,  1202,  1557,  1668,  1344,  1395,  1429,  1678,
    1587,  1555,     0,   844,     0,     0,     0,     0,     0,     0,
    1156,  1709,     0,  1711,     0,  1713,     0,     0,     0,     0,
     528,     0,  1721,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1156,     0,  1156,
    1343,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1343,  1343,     0,   307,  1744,     0,     0,  1747,     0,
       0,     0,  1343,  1344,     0,     0,     0,     0,     0,     0,
    1156,     0,     0,     0,  1344,  1344,     0,   311,     0,     0,
       0,  1755,     0,     0,     0,  1344,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1156,     0,     0,     0,     0,     0,     0,     0,
    1782,     0,     0,     0,     0,  1785,     0,  1156,     0,  1156,
       0,     0,     0,     0,     0,   942,     0,     0,   528,     0,
       0,     0,     0,     0,     0,  1649,  1650,  1651,     0,     0,
       0,     0,   528,     0,  1343,     0,   528,   528,  1802,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1344,  1811,   528,
       0,   528,     0,  1812,     0,     0,     0,     0,     0,   528,
       0,     0,   528,   307,     0,  1821,   528,     0,  1824,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1343,     0,     0,     0,     0,   311,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   307,     0,     0,     0,
       0,     0,     0,     0,  1344,     0,     0,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1343,     0,   311,
       0,     0,     0,     0,     0,     0,  1343,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1344,     0,     0,     0,     0,     0,   528,  1728,     0,  1344,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1734,     0,     0,     0,   550,
       0,     0,     0,     0,     0,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   831,   832,     0,     0,   841,   842,
     843,   845,     0,   847,     0,   528,   528,   528,   528,   855,
       0,     0,     0,     0,     0,     0,     0,   864,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   886,
     887,     0,     0,   528,     0,     0,     0,     0,   893,   894,
       0,     0,     0,     0,     0,     0,     0,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
       0,   528,     0,   528,     0,   528,     0,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   930,
     528,     0,   930,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   528,     0,   528,     0,     0,     0,     0,
     994,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1037,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   528,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1062,     0,
       0,     0,  1064,  1065,     0,   528,     0,     0,     0,     0,
       0,   893,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   887,     0,     0,
       0,     0,     0,  1114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   528,     0,     0,
       0,   528,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   528,     0,     0,     0,
       0,     0,     0,     0,     0,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   528,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   528,
       0,  1179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   528,     0,
       0,     0,     0,     0,     0,     0,  1219,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,  1235,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,   528,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1268,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1273,  1274,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1293,     0,     0,  1296,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   528,  1320,  1321,  1322,     0,  1325,  1326,  1327,  1328,
    1329,  1330,  1331,  1332,  1333,     0,     0,  1336,  1337,     0,
       0,     0,     0,     0,     0,     0,  1351,     0,     0,     0,
     528,     0,     0,     0,     0,     0,  1114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   528,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,   528,     0,  1417,   528,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,     0,     0,     0,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1449,
       0,  1451,     0,  1453,     0,     0,  1457,     0,     0,     0,
       0,  1461,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1467,     0,     0,     0,     0,     0,     0,
       0,     0,  1471,     0,     0,     0,     0,     0,  1475,  1476,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1498,     0,     0,
    1499,     0,   528,   528,     0,   528,     0,   528,     0,     0,
       0,     0,     0,     0,   528,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   528,
       0,   528,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   528,     0,  1114,
     528,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   528,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,     0,   528,     0,   528,
       0,   528,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1597,
       0,     0,     0,  1599,     0,     0,     0,  1602,     0,  1604,
     528,  1605,     0,     0,     0,     0,     0,  1609,     0,     0,
       0,     0,     0,     0,     0,  1614,     0,     0,     0,     0,
     528,     0,     0,  1618,  1620,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   528,     0,     0,
     528,     0,     0,  1467,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1641,  1642,  1643,  1644,     0,  1646,
    1647,     0,  1648,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1656,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1695,     0,  1696,     0,     0,  1698,     0,     0,     0,
       0,     0,     0,     0,  1701,     0,     0,     0,     0,  1703,
    1620,     0,     0,     0,     0,     0,     0,  1707,     0,     0,
       0,     0,  1712,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1724,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1730,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1749,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1707,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1789,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -165,   874,     0,  1800,     0,     0,     0,     0,  1805,
       0,     0,     1,     2,  1789,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,  1805,
      11,     0,     0,  1814,    12,   411,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,   110,   111,   112,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,   124,   125,     0,
       0,   126,   127,   128,     0,     0,     0,   129,     0,   130,
     131,     0,   132,   133,     0,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   413,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   246,   247,   248,   249,
     250,   251,  -165,   874,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   878,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   412,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   874,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   412,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   874,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     552,   412,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   553,   554,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   503,    82,    83,    84,    85,    86,
     555,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   556,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     520,   521,   522,   176,   177,   523,   558,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,   248,
     249,   250,   251,  -855,   451,     0,   452,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -855,     0,     0,     0,  -855,
       0,     0,     0,  -855,  -855,     0,     0,     0,  -855,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   453,
       0,     0,  -855,     0,   454,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -855,     0,  -855,  -855,  -855,
       0,     0,  -855,  -855,  -855,  -855,     0,     0,     0,  -855,
    -855,     0,     0,     0,     0,     0,  -855,     0,     0,  -855,
    -855,   455,     0,     0,  -855,     0,     0,     0,     0,  -855,
    -855,     0,     0,     0,     0,  -855,     0,     0,     0,  -855,
       0,     0,     0,  -855,  -855,     0,  -855,     0,  -855,  -855,
       0,     0,     0,  -855,  -855,     0,     0,  -855,  -855,  -855,
    -855,  -855,  -855,     0,     0,  -855,     0,     0,     0,     0,
    -855,  -855,     0,     0,  -855,     0,     0,     0,     0,  -855,
       0,     0,  -855,     0,     0,     0,     0,  -855,  -855,  -855,
    -855,  -855,     0,  -855,  -855,  -855,  -855,  -855,     0,     0,
       0,     0,  -855,  -855,  -855,     0,  -855,  -855,  -855,  -855,
    -855,  -855,     0,  -855,     0,  -855,     0,     0,     0,     0,
    -855,  -855,  -855,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -855,     0,  -855,     0,
    -855,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -855,     0,     0,     0,     0,  -855,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,  -855,     0,  -855,    12,    13,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,    12,
      13,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,   124,   125,     0,     0,   126,   127,   128,     0,
       0,     0,   129,     0,   130,   131,     0,   132,   133,     0,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   246,   247,   248,   249,   250,   251,     0,   605,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,   547,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,   808,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,  1338,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
    1339,  1340,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,   547,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,  1341,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,    12,    13,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,    12,    13,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,    12,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   878,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,  1338,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
    1339,  1340,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,  1341,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,   557,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,   562,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   600,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,   602,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,   923,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,   929,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,   933,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   489,    25,   491,   412,    28,   492,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   494,     0,    45,    46,    47,
     496,   497,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   506,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   681,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   682,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   515,   160,   516,   162,   517,   518,   165,   166,
     167,   168,   169,   170,   519,   172,   520,   521,   522,   176,
     177,   523,   524,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   525,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   489,    25,   491,   412,    28,   492,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   494,     0,    45,    46,    47,
     496,   497,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   506,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   515,   160,   516,   162,   517,   518,   165,   166,
     167,   168,   169,   170,   519,   172,   520,   521,   522,   176,
     177,   523,   524,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   525,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   489,    25,   491,   412,    28,   492,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   494,     0,    45,    46,    47,
     496,   497,    50,   498,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   506,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,     0,     0,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   515,   160,   516,   162,   517,   518,   165,   166,
     167,   168,   169,   170,   519,   172,   520,   521,   522,   176,
     177,   523,   524,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   525,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   489,    25,   491,   412,    28,   492,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   494,     0,    45,    46,    47,
     496,   497,    50,   498,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   506,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,     0,     0,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,     0,
       0,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   515,   160,   516,   162,   517,   518,   165,   166,
     167,   168,   169,   170,   519,   172,   520,   521,   522,   176,
     177,   523,   524,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   525,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   489,    25,   491,   412,    28,   492,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   494,     0,    45,    46,    47,
     496,   497,    50,   498,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   506,     0,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,     0,   106,
     107,   556,   109,     0,   110,   111,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,     0,     0,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,     0,
       0,     0,   134,     0,   135,     0,   136,     0,   138,     0,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   515,   160,   516,   162,   517,   518,   165,   166,
     167,   168,   169,   170,   519,   172,   520,   521,   522,   176,
     177,   523,   524,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   525,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,   410,   411,     0,    14,    15,    16,   486,    18,    19,
      20,   487,    22,   488,   489,   490,   491,   412,    28,   492,
      30,    31,     0,    32,    33,    34,    35,   493,    37,    38,
      39,    40,    41,    42,    43,   494,     0,    45,   495,    47,
     496,   497,    50,   498,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   499,   500,
      68,     0,    69,    70,    71,   501,     0,     0,    74,    75,
      76,     0,     0,   502,    78,     0,     0,     0,     0,    80,
     503,    82,   504,   505,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   506,    97,    98,   507,   508,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   509,   120,   121,
     510,     0,     0,     0,     0,     0,     0,     0,   511,   512,
     128,     0,     0,     0,   129,     0,   130,   513,     0,     0,
       0,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     514,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,     0,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   515,   160,   516,   162,   517,   518,   165,   166,
     167,   168,   169,   170,   519,   172,   520,   521,   522,   176,
     177,   523,   524,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,     0,
       1,     2,   245,   525,   247,   248,   249,   250,   251,     3,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,   410,   411,     0,    14,    15,    16,   534,    18,
      19,    20,   487,   535,   536,   489,   490,   491,   412,    28,
     492,    30,    31,     0,    32,    33,    34,    35,   537,    37,
     538,   539,    40,    41,    42,    43,   494,     0,    45,   540,
      47,   496,   497,    50,   498,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   499,
     500,    68,     0,    69,    70,    71,   541,     0,     0,    74,
      75,    76,     0,     0,   502,    78,     0,     0,     0,     0,
      80,   503,    82,   504,   505,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   506,    97,    98,   507,   508,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   509,   120,
     121,   510,     0,     0,     0,     0,     0,     0,     0,   511,
     512,   128,     0,     0,     0,   129,     0,   130,   513,     0,
       0,     0,     0,   134,     0,   135,     0,   136,   137,   138,
     139,   514,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   413,   151,   152,   153,   154,   155,
     156,   157,   158,   515,   542,   516,   162,   517,   518,   165,
     166,   167,   168,   169,   170,   519,   172,   520,   521,   522,
     176,   177,   523,   524,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,   567,   245,   525,   247,   248,   249,   250,   251,
       7,     8,     0,     0,     0,   783,     0,     0,     0,   410,
     411,     0,    14,    15,    16,   534,    18,    19,    20,   487,
     535,   536,   489,   490,   491,   412,    28,   492,    30,    31,
       0,    32,    33,    34,    35,   537,    37,   538,   539,    40,
      41,    42,    43,   494,     0,    45,   540,    47,   496,   497,
      50,   498,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   499,   500,    68,     0,
      69,    70,    71,   541,     0,     0,    74,    75,    76,     0,
       0,   502,    78,     0,     0,     0,     0,    80,   503,    82,
     504,   505,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   506,    97,    98,   507,   508,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   509,   120,   121,   510,     0,
       0,     0,     0,     0,     0,     0,   511,   512,   128,     0,
       0,     0,   129,   784,   130,   513,     0,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   514,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   413,   151,   152,   153,   154,   155,   156,   157,   158,
     515,   542,   516,   162,   517,   518,   165,   166,   167,   168,
     169,   170,   519,   172,   520,   521,   522,   176,   177,   523,
     524,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     0,   567,
     245,   525,   247,   248,   249,   250,   251,     7,     8,     0,
       0,     0,     0,     0,     0,     0,   410,   411,     0,    14,
      15,    16,   534,    18,    19,    20,   487,   535,   536,   489,
     490,   491,   412,    28,   492,    30,    31,     0,    32,    33,
      34,    35,   537,    37,   538,   539,    40,    41,    42,    43,
     494,     0,    45,   540,    47,   496,   497,    50,   498,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   499,   500,    68,     0,    69,    70,    71,
     541,     0,     0,    74,    75,    76,     0,     0,   502,    78,
       0,     0,     0,     0,    80,   503,    82,   504,   505,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   506,    97,
      98,   507,   508,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   509,   120,   121,   510,     0,     0,     0,     0,
       0,     0,     0,   511,   512,   128,     0,     0,     0,   129,
       0,   130,   513,     0,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   514,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,     0,     0,   413,   151,
     152,   153,   154,   155,   156,   157,   158,   515,   542,   516,
     162,   517,   518,   165,   166,   167,   168,   169,   170,   519,
     172,   520,   521,   522,   176,   177,   523,   524,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     0,     0,   245,   525,   247,
     248,   249,   250,   251,   570,   571,     0,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   410,
     411,     0,    14,    15,    16,   534,    18,    19,    20,   487,
     535,   536,   489,   490,   491,   412,    28,   492,    30,    31,
       0,    32,    33,    34,    35,   537,    37,   538,   539,    40,
      41,    42,    43,   494,     0,    45,   540,    47,   496,   497,
      50,   498,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   499,   500,    68,     0,
      69,    70,    71,   541,     0,     0,    74,    75,    76,     0,
       0,   502,    78,     0,     0,     0,     0,    80,   503,    82,
     504,   505,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   506,    97,    98,   507,   508,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   509,   120,   121,   510,     0,
       0,     0,     0,     0,     0,     0,   511,   512,   128,     0,
       0,     0,   129,     0,   130,   513,     0,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   514,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   413,   151,   152,   153,   154,   155,   156,   157,   158,
     515,   542,   516,   162,   517,   518,   165,   166,   167,   168,
     169,   170,   519,   172,   520,   521,   522,   176,   177,   523,
     524,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     0,     0,
     245,   525,   247,   248,   249,   250,   251,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   410,
     411,     0,    14,    15,    16,   833,    18,    19,    20,    21,
     535,   834,   489,    25,   491,   412,    28,   492,    30,    31,
       0,    32,    33,    34,    35,   835,    37,   538,   539,    40,
      41,    42,    43,   494,     0,    45,   836,    47,   496,   497,
      50,   498,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   499,   500,    68,     0,
      69,    70,    71,   837,     0,     0,    74,    75,    76,     0,
       0,   502,    78,     0,     0,     0,    79,    80,   503,    82,
     504,   505,    85,    86,   555,    88,     0,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   506,    97,    98,   507,   508,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   556,
     109,     0,   110,   111,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   510,     0,
     123,     0,     0,     0,     0,     0,   511,   512,   128,     0,
       0,     0,   129,     0,   130,   513,     0,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   413,   151,   152,   153,   154,   155,   156,   157,   158,
     515,   542,   516,   162,   517,   518,   165,   166,   167,   168,
     169,   170,   519,   172,   520,   521,   522,   176,   177,   523,
     524,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   525,   247,   248,   249,   250,   251,     7,     8,     0,
       0,     0,     0,     0,     0,     0,   410,   411,     0,    14,
      15,    16,   486,    18,    19,    20,   487,    22,   488,   489,
    1136,   491,   412,    28,   492,    30,    31,     0,    32,    33,
      34,    35,   493,    37,    38,    39,    40,    41,    42,    43,
     494,     0,    45,   495,    47,   496,   497,    50,   498,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   499,   500,    68,     0,    69,    70,    71,
     501,     0,     0,    74,    75,    76,     0,     0,   502,    78,
       0,     0,     0,     0,    80,   503,    82,   504,   505,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   506,    97,
      98,   507,   508,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1137,     0,     0,     0,  1138,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   509,   120,   121,   510,     0,     0,     0,     0,
       0,     0,     0,   511,   512,   128,     0,     0,     0,   129,
    1568,   130,   513,     0,     0,     0,     0,  1569,     0,   135,
       0,   136,   137,   138,   139,   514,   141,   142,   143,   144,
     145,   146,     0,     0,  1139,   148,     0,     0,   413,   151,
     152,   153,   154,   155,   156,   157,   158,   515,   160,   516,
     162,   517,   518,   165,   166,   167,   168,   169,   170,   519,
     172,   520,   521,   522,   176,   177,   523,   524,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     7,     8,   245,   525,   247,
    1140,  1141,  1142,  1143,   410,   411,     0,    14,    15,    16,
     534,    18,    19,    20,   487,   535,   536,   489,   490,   491,
     412,    28,   492,    30,    31,     0,    32,    33,    34,    35,
     537,    37,   538,   539,    40,    41,    42,    43,   494,     0,
      45,   540,    47,   496,   497,    50,   498,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   499,   500,    68,     0,    69,    70,    71,   541,     0,
       0,    74,    75,    76,     0,     0,   502,    78,     0,     0,
       0,     0,    80,   503,    82,   504,   505,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   506,    97,    98,   507,
     508,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     509,   120,   121,   510,     0,     0,     0,     0,     0,     0,
       0,   511,   512,   128,     0,     0,     0,   129,   753,   130,
     513,     0,     0,     0,     0,   754,     0,   135,     0,   136,
     137,   138,   139,   514,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,     0,     0,   413,   151,   152,   153,
     154,   155,   156,   157,   158,   515,   542,   516,   162,   517,
     518,   165,   166,   167,   168,   169,   170,   519,   172,   520,
     521,   522,   176,   177,   523,   524,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     7,     8,   245,   525,   247,   248,   249,
     250,   251,   410,   411,     0,    14,    15,    16,   534,    18,
      19,    20,   487,   535,   536,   489,   490,   491,   412,    28,
     492,    30,    31,     0,    32,    33,    34,    35,   537,    37,
     538,   539,    40,    41,    42,    43,   494,     0,    45,   540,
      47,   496,   497,    50,   498,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   499,
     500,    68,     0,    69,    70,    71,   541,     0,     0,    74,
      75,    76,     0,     0,   502,    78,     0,     0,     0,     0,
      80,   503,    82,   504,   505,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   506,    97,    98,   507,   508,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   509,   120,
     121,   510,     0,     0,     0,     0,     0,     0,     0,   511,
     512,   128,     0,     0,     0,   129,   801,   130,   513,     0,
       0,     0,     0,   802,     0,   135,     0,   136,   137,   138,
     139,   514,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   413,   151,   152,   153,   154,   155,
     156,   157,   158,   515,   542,   516,   162,   517,   518,   165,
     166,   167,   168,   169,   170,   519,   172,   520,   521,   522,
     176,   177,   523,   524,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     7,     8,   245,   525,   247,   248,   249,   250,   251,
     410,   411,     0,    14,    15,    16,   486,    18,    19,    20,
     487,    22,   488,   489,  1136,   491,   412,    28,   492,    30,
      31,     0,    32,    33,    34,    35,   493,    37,    38,    39,
      40,    41,    42,    43,   494,     0,    45,   495,    47,   496,
     497,    50,   498,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   499,   500,    68,
       0,    69,    70,    71,   501,     0,     0,    74,    75,    76,
       0,     0,   502,    78,     0,     0,     0,     0,    80,   503,
      82,   504,   505,    85,    86,  1485,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   506,    97,    98,   507,   508,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,  1137,
       0,     0,     0,  1138,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   509,   120,   121,   510,
       0,     0,     0,     0,     0,     0,     0,   511,   512,   128,
       0,     0,     0,   129,     0,   130,   513,     0,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   514,
     141,   142,   143,   144,   145,   146,     0,     0,  1139,   148,
       0,     0,   413,   151,   152,   153,   154,   155,   156,   157,
     158,   515,   160,   516,   162,   517,   518,   165,   166,   167,
     168,   169,   170,   519,   172,   520,   521,   522,   176,   177,
     523,   524,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     7,
       8,   245,   525,   247,  1140,  1141,  1142,  1143,   410,   411,
       0,    14,    15,    16,   486,    18,    19,    20,   487,    22,
     488,   489,  1136,   491,   412,    28,   492,    30,    31,     0,
      32,    33,    34,    35,   493,    37,    38,    39,    40,    41,
      42,    43,   494,     0,    45,   495,    47,   496,   497,    50,
     498,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   499,   500,    68,     0,    69,
      70,    71,   501,     0,     0,    74,    75,    76,     0,     0,
     502,    78,     0,     0,     0,     0,    80,   503,    82,   504,
     505,    85,    86,  1626,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     506,    97,    98,   507,   508,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1137,     0,     0,
       0,  1138,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   509,   120,   121,   510,     0,     0,
       0,     0,     0,     0,     0,   511,   512,   128,     0,     0,
       0,   129,     0,   130,   513,     0,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   514,   141,   142,
     143,   144,   145,   146,     0,     0,  1139,   148,     0,     0,
     413,   151,   152,   153,   154,   155,   156,   157,   158,   515,
     160,   516,   162,   517,   518,   165,   166,   167,   168,   169,
     170,   519,   172,   520,   521,   522,   176,   177,   523,   524,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     7,     8,   245,
     525,   247,  1140,  1141,  1142,  1143,   410,   411,     0,    14,
      15,    16,   486,    18,    19,    20,   487,    22,   488,   489,
    1136,   491,   412,    28,   492,    30,    31,     0,    32,    33,
      34,    35,   493,    37,    38,    39,    40,    41,    42,    43,
     494,     0,    45,   495,    47,   496,   497,    50,   498,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   499,   500,    68,     0,    69,    70,    71,
     501,     0,     0,    74,    75,    76,     0,     0,   502,    78,
       0,     0,     0,     0,    80,   503,    82,   504,   505,    85,
      86,  1630,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   506,    97,
      98,   507,   508,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1137,     0,     0,     0,  1138,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   509,   120,   121,   510,     0,     0,     0,     0,
       0,     0,     0,   511,   512,   128,     0,     0,     0,   129,
       0,   130,   513,     0,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   514,   141,   142,   143,   144,
     145,   146,     0,     0,  1139,   148,     0,     0,   413,   151,
     152,   153,   154,   155,   156,   157,   158,   515,   160,   516,
     162,   517,   518,   165,   166,   167,   168,   169,   170,   519,
     172,   520,   521,   522,   176,   177,   523,   524,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     7,     8,   245,   525,   247,
    1140,  1141,  1142,  1143,   410,   411,     0,    14,    15,    16,
     486,    18,    19,    20,   487,    22,   488,   489,  1136,   491,
     412,    28,   492,    30,    31,     0,    32,    33,    34,    35,
     493,    37,    38,    39,    40,    41,    42,    43,   494,     0,
      45,   495,    47,   496,   497,    50,   498,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   499,   500,    68,     0,    69,    70,    71,   501,     0,
       0,    74,    75,    76,     0,     0,   502,    78,     0,     0,
       0,     0,    80,   503,    82,   504,   505,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   506,    97,    98,   507,
     508,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,  1137,     0,     0,     0,  1138,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     509,   120,   121,   510,     0,     0,     0,     0,     0,     0,
       0,   511,   512,   128,     0,     0,     0,   129,     0,   130,
     513,     0,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   514,   141,   142,   143,   144,   145,   146,
       0,     0,  1139,   148,     0,     0,   413,   151,   152,   153,
     154,   155,   156,   157,   158,   515,   160,   516,   162,   517,
     518,   165,   166,   167,   168,   169,   170,   519,   172,   520,
     521,   522,   176,   177,   523,   524,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     7,     8,   245,   525,   247,  1140,  1141,
    1142,  1143,   410,   411,     0,    14,    15,    16,   486,    18,
      19,    20,   487,    22,   488,   489,  1136,   491,   412,    28,
     492,    30,    31,     0,    32,    33,    34,    35,   493,    37,
      38,    39,    40,    41,    42,    43,   494,     0,    45,   495,
      47,   496,   497,    50,   498,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   499,
     500,    68,     0,    69,    70,    71,   501,     0,     0,    74,
      75,    76,     0,     0,   502,    78,     0,     0,     0,     0,
      80,   503,    82,   504,   505,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   506,    97,    98,   507,   508,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,  1137,     0,     0,     0,  1138,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   509,   120,
     121,   510,     0,     0,     0,     0,     0,     0,     0,   511,
     512,   128,     0,     0,     0,   129,     0,   130,   513,     0,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   514,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   413,   151,   152,   153,   154,   155,
     156,   157,   158,   515,   160,   516,   162,   517,   518,   165,
     166,   167,   168,   169,   170,   519,   172,   520,   521,   522,
     176,   177,   523,   524,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     7,     8,   245,   525,   247,  1140,  1141,  1142,  1143,
     410,   411,     0,    14,    15,    16,   534,    18,    19,    20,
     487,   535,   536,   489,   490,   491,   412,    28,   492,    30,
      31,     0,    32,    33,    34,    35,   537,    37,   538,   539,
      40,    41,    42,    43,   494,     0,    45,   540,    47,   496,
     497,    50,   498,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   499,   500,    68,
       0,    69,    70,    71,   541,     0,     0,    74,    75,    76,
       0,     0,   502,    78,     0,     0,     0,     0,    80,   503,
      82,   504,   505,    85,    86,  1230,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   506,    97,    98,   507,   508,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   509,   120,   121,   510,
       0,     0,     0,     0,     0,     0,     0,   511,   512,   128,
       0,     0,     0,   129,     0,   130,   513,     0,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   514,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
       0,     0,   413,   151,   152,   153,   154,   155,   156,   157,
     158,   515,   542,   516,   162,   517,   518,   165,   166,   167,
     168,   169,   170,   519,   172,   520,   521,   522,   176,   177,
     523,   524,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     7,
       8,   245,   525,   247,   248,   249,   250,   251,   410,   411,
       0,    14,    15,    16,   534,    18,    19,    20,   487,   535,
     536,   489,   490,   491,   412,    28,   492,    30,    31,     0,
      32,    33,    34,    35,   537,    37,   538,   539,    40,    41,
      42,    43,   494,     0,    45,   540,    47,   496,   497,    50,
     498,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   499,   500,    68,     0,    69,
      70,    71,   541,     0,     0,    74,    75,    76,     0,     0,
     502,    78,     0,     0,     0,     0,    80,   503,    82,   504,
     505,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     506,    97,    98,   507,   508,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   509,   120,   121,   510,     0,     0,
       0,     0,     0,     0,     0,   511,   512,   128,     0,     0,
       0,   129,     0,   130,   513,     0,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   514,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     413,   151,   152,   153,   154,   155,   156,   157,   158,   515,
     542,   516,   162,   517,   518,   165,   166,   167,   168,   169,
     170,   519,   172,   520,   521,   522,   176,   177,   523,   524,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     7,     8,   245,
     525,   247,   248,   249,   250,   251,   410,   411,     0,    14,
      15,    16,     0,    18,    19,    20,   487,     0,     0,   489,
     490,     0,   412,    28,   492,    30,    31,     0,    32,    33,
      34,    35,     0,    37,     0,     0,    40,    41,    42,    43,
     494,     0,    45,     0,    47,     0,     0,    50,   498,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   499,   500,    68,     0,    69,    70,    71,
       0,     0,     0,    74,    75,    76,     0,     0,   502,    78,
       0,     0,     0,     0,    80,   503,    82,   504,   505,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   506,    97,
      98,   507,   508,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,     0,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   509,   120,   121,   510,     0,     0,     0,     0,
       0,     0,     0,   511,   512,   128,     0,     0,     0,   129,
       0,   130,   513,     0,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   514,   141,   142,   143,   144,
     145,   146,     0,     0,     0,   148,     0,     0,   413,   151,
     152,   153,   154,   155,   156,   157,   158,   515,     0,   516,
     162,   517,   518,   165,   166,   167,   168,   169,   170,   519,
     172,   520,   521,   522,   176,   177,     0,   524,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     0,     0,   245,   525,   247,
     248,   249,   250,   251
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,     4,     5,     6,     4,     5,     6,   311,    73,   179,
     291,   684,     4,     5,     6,     4,     5,     6,   668,   419,
     420,    12,    87,     0,   340,   778,   905,     4,     5,     6,
     758,  1049,   821,   918,   919,   133,   859,   790,   421,   669,
     670,   671,   672,   259,  1033,     1,   111,   618,   619,   758,
     583,   804,  1283,  1300,    73,   260,   589,     1,   123,  1122,
     125,   616,   617,   618,   619,   990,  1363,  1364,  1073,   940,
     275,   252,   253,   616,   617,   433,    26,    27,   461,   462,
    1008,  1313,    36,   714,  1488,    36,   444,  1491,  1396,     1,
     282,    29,   118,    55,   107,    29,   118,    47,    39,     1,
      45,     1,   107,    44,    45,   147,    37,    38,   108,    40,
      41,   469,   121,     1,     1,  1590,   108,    62,    59,   108,
      61,    62,   100,     1,    74,  1010,    57,     1,     1,    70,
       1,   108,     1,    29,   647,   416,   649,   650,  1023,   652,
      94,   654,    96,     8,     1,    96,   956,    30,   225,   662,
     663,   107,     1,     1,    26,    27,    97,    52,  1656,   153,
     144,     1,   112,   107,    26,    27,   153,     1,    94,   918,
     919,   131,   110,   169,   106,    96,     1,   136,   153,   113,
     100,     1,   113,   269,   142,    47,   124,    96,    96,   156,
     276,   150,   176,   147,    56,   127,   147,   268,     0,     1,
     286,     1,   177,   225,   275,   113,   202,   956,   186,   962,
     194,   149,    74,    33,   147,   153,   210,    79,   156,   107,
     107,   147,   235,   210,   233,    54,   160,    56,   233,   160,
     190,   273,  1730,  1530,   129,     1,   107,   314,   107,   177,
     112,   990,   187,  1122,  1123,   343,     1,   273,   440,   111,
     112,   113,   252,   253,    96,   217,   256,   561,   107,   107,
     169,  1010,  1280,  1016,   160,  1740,   186,   107,   549,  1022,
    1501,   100,  1504,   107,  1023,   252,   253,  1266,   190,   256,
    1069,  1589,   107,   348,   225,   307,   351,  1015,   190,   220,
     190,   291,   254,     1,   109,   110,  1221,   868,   869,  1304,
     187,  1705,  1230,  1174,  1013,   107,  1015,   107,  1313,  1372,
     175,   942,   190,   184,   291,   273,   190,   190,   187,   273,
       1,   259,   273,   866,   867,     1,  1035,   169,  1138,   348,
     261,   214,   351,   190,     1,   256,   257,   287,   187,   187,
     273,   107,   725,   252,   253,   295,   255,   187,  1752,     1,
    1754,   185,   107,   262,   635,     0,     1,   313,   156,   107,
     153,   426,   187,   272,   429,     1,   217,   311,   433,    93,
     107,   436,   437,  1258,   107,   284,   317,   318,   319,   444,
     153,    33,   184,   156,   177,   450,   451,   187,   901,  1138,
     455,     1,  1689,   776,     1,   107,     9,    49,   463,   107,
     616,   617,   100,   254,   469,   470,   471,   472,   613,   614,
     252,   253,   477,   255,   772,    28,   416,   775,   623,     1,
     485,   187,   251,   107,   605,   287,   107,   107,   243,   244,
     272,   107,   187,   295,    42,   264,   184,   266,    46,   416,
     107,   303,   284,    51,     1,   445,  1743,   447,   277,   278,
     279,   188,   281,   445,   283,   447,   445,   190,   447,   183,
       1,    69,   107,   744,     1,   530,    29,  1220,   445,     1,
     447,   107,  1221,   473,   118,   187,   291,   185,   478,   544,
    1727,   473,   225,    94,   473,    76,   478,   230,   186,   478,
     555,   130,   153,  1372,   100,   156,   473,   107,    94,  1504,
     107,   478,  1381,   187,  1232,   905,   187,   113,   188,  1258,
     123,   187,   125,  1392,   154,   107,   156,   184,   583,  1404,
     107,   134,  1345,   118,   589,   107,  1349,   160,   593,     1,
     107,     3,  1241,  1282,   153,   935,  1107,  1108,  1109,   184,
     153,  1772,   186,  1216,   118,   107,   107,   110,   184,   549,
     107,   147,  1107,  1108,  1109,   158,   556,   107,   197,  1092,
     168,   124,   153,   171,   556,     9,   107,   556,   107,   107,
     107,   314,   549,   176,   184,   107,   857,   184,   186,   556,
     963,   964,   107,   100,    28,   968,   149,    94,     9,    10,
     688,   689,   187,   122,    66,   187,   113,   237,   598,    71,
     187,   416,   184,   884,   212,   605,   598,   218,   219,     5,
     187,    29,   186,     9,  1367,   998,   616,   617,   618,   619,
     611,   598,   233,  1612,   130,   187,   187,   184,   605,    94,
     221,   222,   118,   186,   449,   635,   225,   187,   227,   616,
     617,   618,   619,   184,   459,    96,   118,   184,   187,   187,
     866,   182,   184,   468,   136,  1404,   721,   210,   635,    42,
     475,   476,   187,    46,    96,   196,   269,   872,    51,   484,
     735,   876,   137,   276,   739,   740,  1004,   142,  1006,   123,
    1559,   125,   103,   286,     5,    94,    69,   201,     9,    42,
     134,   197,   110,    46,   156,    96,   210,   762,    51,   764,
      94,   225,   123,   227,   125,   156,   124,   772,  1726,   153,
     775,   218,   219,  1502,   779,   147,    69,   156,  1507,   201,
       9,    10,  1122,  1123,  1452,   314,   233,   123,  1056,   125,
    1058,   149,   153,  1383,   549,   153,   157,   133,   156,  1488,
    1625,   122,  1491,   158,   744,   154,   147,   156,   142,   186,
     565,   117,   182,   174,    33,   820,   156,   153,    45,   177,
      47,   176,   577,   156,  1437,   768,   196,   744,   768,    94,
      49,   156,   153,   210,   195,   156,   768,   299,    96,   768,
     146,  1352,   597,   598,    96,   168,   308,  1672,   171,  1674,
     314,   768,   213,   159,   859,   113,     9,    10,   798,   799,
      53,   113,   123,   186,   125,    58,   798,   799,  1124,   798,
     799,    45,   133,    47,   103,   168,  1097,   142,   171,   106,
     263,   798,   799,   888,    77,  1717,  1718,    24,   194,   212,
     158,   274,   153,   186,   123,   118,   125,    34,   156,     9,
      10,   156,   158,    96,   156,    79,    94,  1636,   176,   122,
     186,  1640,  1737,   918,   919,   920,   921,   857,   106,   212,
     176,    53,   186,    60,   153,   118,    58,  1759,   157,   100,
     685,   199,   106,  1765,   210,   690,  1625,    95,  1261,   186,
     857,   168,   113,   199,   884,   174,   210,   878,   106,   156,
     103,   956,   186,  1098,   142,   247,   248,   148,   116,  1104,
    1550,  1551,   100,   210,    96,   970,   195,   884,    94,   127,
     123,   148,   125,  1543,   165,   113,   210,   122,   270,  1592,
     106,   166,   137,  1672,   213,  1674,   137,   122,   165,   744,
     995,  1101,  1721,   103,   168,   100,  1689,   182,   153,  1004,
     153,  1006,   153,  1008,   157,  1010,   263,   137,   113,   100,
     620,   953,   142,   123,   624,   125,  1705,   274,  1023,    26,
      27,   174,   113,   965,   137,   153,   191,   192,   156,   142,
      37,    38,  1372,    40,    41,   153,  1359,   122,   156,  1260,
      47,  1381,   195,   153,   128,   129,   118,   157,  1737,    56,
      57,  1056,  1392,  1058,   221,   222,   223,   812,   813,   814,
     213,   816,   122,  1752,   174,  1754,   347,    74,   122,   350,
    1660,  1661,    79,   277,   278,   279,   154,   691,   156,   283,
     694,  1694,   232,   697,   234,   195,   153,  1092,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,   122,   232,
    1344,   234,   857,   213,   111,   112,   113,   122,    53,   122,
      73,  1051,  1117,    58,   128,   129,   122,   666,   667,  1051,
     675,   676,  1051,   153,    87,  1214,  1215,   216,  1741,   673,
     674,  1580,  1581,  1138,  1051,   156,   118,   241,   241,   156,
     242,   153,   314,  1733,     0,   190,  1469,   167,   111,    92,
     249,    99,    50,   160,   200,   101,   193,  1097,   102,   154,
     123,   145,   125,   132,    29,   156,   184,  1107,  1108,  1109,
      47,   140,   141,   184,   143,  1106,   184,   152,   118,   304,
    1097,   246,   151,   187,   284,   118,   155,   284,   157,   153,
    1107,  1108,  1109,   162,     1,   118,   107,   187,   153,   153,
    1813,   142,  1815,   156,   156,   156,   156,   156,   142,   121,
     179,  1534,  1825,   220,   184,    35,   153,   156,   156,  1559,
     156,    17,   187,    29,   190,  1230,   214,     3,   231,  1234,
     230,  1341,   190,   118,   203,   204,   205,   206,   207,   208,
     245,   168,   170,    70,  1249,   170,   231,    94,    94,    94,
     149,    29,   107,  1258,   261,   107,   160,   160,   127,   132,
    1481,    94,   142,   246,   299,   118,   132,  1272,   184,   184,
     187,   107,    94,   187,    45,    96,   237,  1282,    96,   187,
     287,  1224,   187,   153,  1224,   187,   187,   184,   295,   184,
     153,   153,  1224,   153,   153,  1224,   303,    94,   142,   153,
     231,   225,  1523,   190,   233,    33,  1311,  1224,   118,   170,
     142,    94,    29,   132,   286,    94,   153,   227,   299,   127,
    1260,   147,   254,   118,   118,    94,   184,   198,  1271,   132,
    1335,  1271,   160,   132,    96,   147,   153,   118,   153,  1271,
    1345,   100,  1271,  1260,  1349,   100,   184,  1290,   190,   184,
    1290,   142,    35,   121,  1271,    29,   245,   118,  1290,    79,
     107,  1290,   107,   285,   258,    29,  1121,   260,   156,   156,
    1310,   267,   156,  1290,   156,    29,   156,   144,  1310,   156,
     286,  1310,   156,    29,   227,   348,   306,   287,   351,  1610,
     190,   144,   127,  1310,   187,   187,   147,   187,   187,  1404,
    1621,  1622,   118,  1624,   147,   147,   118,    77,  1348,   107,
     142,  1632,   184,   198,   187,   100,  1348,   187,   132,     7,
     233,    96,   233,   237,   190,   156,   186,   156,  1433,   233,
     156,  1348,   233,   106,   153,   187,   147,   286,    78,   187,
      29,   250,   282,   187,    29,   250,   187,   187,   187,   187,
     187,   107,   170,   147,  1459,  1460,   147,   184,   126,   257,
     126,    96,   425,   426,   186,   186,   429,   153,   316,   271,
     433,   108,    94,   436,   437,   184,   186,   184,   184,   142,
    1485,   444,   184,  1488,   187,    29,  1491,   450,   451,    96,
     187,   170,   455,  1714,   280,   147,    53,    94,  1503,    94,
     463,   197,   106,  1508,    29,   107,   469,   470,   471,   472,
     118,   265,   287,   107,   477,   118,    94,   225,    94,   186,
     197,   197,   485,    93,   225,   118,   198,   186,   183,   293,
     199,   118,  1753,   186,   118,   197,   225,   118,   287,   957,
     305,  1481,   305,   256,   259,   724,  1177,   305,   420,   306,
    1771,   256,   440,  1221,  1024,  1694,   306,  1741,   860,   781,
     306,  1021,  1368,   455,  1481,  1786,  1250,   530,  1113,  1462,
    1366,  1363,  1272,   544,  1277,  1280,  1285,   645,   665,   921,
     646,   544,   699,  1523,  1304,   821,  1807,  1765,  1759,  1006,
    1176,   448,   555,  1346,  1335,  1816,  1345,   448,  1381,   335,
    1123,  1559,  1392,   989,  1385,  1556,  1523,  1132,  1199,  1583,
    1427,  1382,    -1,   587,    -1,    -1,    -1,    -1,    -1,    -1,
    1625,  1626,    -1,  1628,    -1,  1630,    -1,    -1,    -1,    -1,
     593,    -1,  1637,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1672,    -1,  1674,
    1610,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1621,  1622,    -1,  1624,  1690,    -1,    -1,  1693,    -1,
      -1,    -1,  1632,  1610,    -1,    -1,    -1,    -1,    -1,    -1,
    1705,    -1,    -1,    -1,  1621,  1622,    -1,  1624,    -1,    -1,
      -1,  1716,    -1,    -1,    -1,  1632,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1737,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1745,    -1,    -1,    -1,    -1,  1750,    -1,  1752,    -1,  1754,
      -1,    -1,    -1,    -1,    -1,   718,    -1,    -1,   721,    -1,
      -1,    -1,    -1,    -1,    -1,  1520,  1521,  1522,    -1,    -1,
      -1,    -1,   735,    -1,  1714,    -1,   739,   740,  1783,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1714,  1803,   762,
      -1,   764,    -1,  1808,    -1,    -1,    -1,    -1,    -1,   772,
      -1,    -1,   775,  1753,    -1,  1820,   779,    -1,  1823,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1771,    -1,    -1,    -1,    -1,  1753,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1786,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1771,    -1,    -1,   820,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1807,    -1,  1786,
      -1,    -1,    -1,    -1,    -1,    -1,  1816,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1807,    -1,    -1,    -1,    -1,    -1,   859,  1652,    -1,  1816,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1670,    -1,    -1,    -1,   556,
      -1,    -1,    -1,    -1,    -1,   888,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   581,   582,    -1,    -1,   585,   586,
     587,   588,    -1,   590,    -1,   918,   919,   920,   921,   596,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   604,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   626,
     627,    -1,    -1,   956,    -1,    -1,    -1,    -1,   635,   636,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   970,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   995,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1004,    -1,  1006,    -1,  1008,    -1,  1010,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   696,
    1023,    -1,   699,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1056,    -1,  1058,    -1,    -1,    -1,    -1,
     737,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   780,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   805,    -1,
      -1,    -1,   809,   810,    -1,  1138,    -1,    -1,    -1,    -1,
      -1,   818,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   884,    -1,    -1,
      -1,    -1,    -1,   890,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1230,    -1,    -1,
      -1,  1234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1258,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1272,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1282,
      -1,   958,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1311,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   993,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1335,    -1,    -1,  1012,    -1,    -1,    -1,    -1,
      -1,    -1,  1345,    -1,    -1,    -1,  1349,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1034,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1045,  1046,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1060,    -1,    -1,  1063,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1404,  1079,  1080,  1081,    -1,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,    -1,    -1,  1094,  1095,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1103,    -1,    -1,    -1,
    1433,    -1,    -1,    -1,    -1,    -1,  1113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1459,  1460,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1485,    -1,    -1,  1488,    -1,  1164,  1491,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1503,    -1,    -1,    -1,    -1,  1508,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1236,
      -1,  1238,    -1,  1240,    -1,    -1,  1243,    -1,    -1,    -1,
      -1,  1248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1269,    -1,    -1,    -1,    -1,    -1,  1275,  1276,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1294,    -1,    -1,
    1297,    -1,  1625,  1626,    -1,  1628,    -1,  1630,    -1,    -1,
      -1,    -1,    -1,    -1,  1637,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1672,
      -1,  1674,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1690,    -1,  1366,
    1693,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1705,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1716,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1737,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1745,    -1,    -1,    -1,    -1,  1750,    -1,  1752,
      -1,  1754,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1446,
      -1,    -1,    -1,  1450,    -1,    -1,    -1,  1454,    -1,  1456,
    1783,  1458,    -1,    -1,    -1,    -1,    -1,  1464,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1472,    -1,    -1,    -1,    -1,
    1803,    -1,    -1,  1480,  1481,  1808,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1820,    -1,    -1,
    1823,    -1,    -1,  1500,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1511,  1512,  1513,  1514,    -1,  1516,
    1517,    -1,  1519,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1535,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1598,    -1,  1600,    -1,    -1,  1603,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1611,    -1,    -1,    -1,    -1,  1616,
    1617,    -1,    -1,    -1,    -1,    -1,    -1,  1624,    -1,    -1,
      -1,    -1,  1629,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1645,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1657,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1697,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1710,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1753,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,  1781,    -1,    -1,    -1,    -1,  1786,
      -1,    -1,    11,    12,  1791,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,  1806,
      29,    -1,    -1,  1810,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,   158,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,   191,   192,    -1,   194,    -1,   196,    -1,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,    -1,   211,   212,   213,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,    -1,   312,    -1,   314,   315,   316,   317,   318,
     319,   320,     0,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,
     128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,   176,   177,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,   191,   192,    -1,   194,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,    -1,   211,   212,   213,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,     1,   312,    -1,   314,   315,   316,   317,
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,
     128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,   176,   177,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,   191,   192,    -1,   194,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,    -1,   211,   212,   213,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,     1,   312,    -1,   314,   315,   316,   317,
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,
     128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,   176,   177,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,   191,   192,    -1,   194,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,    -1,   211,   212,   213,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,    -1,   312,    -1,   314,   315,   316,   317,
     318,   319,   320,     0,     1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    69,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    94,    95,    96,
      -1,    -1,    99,   100,   101,   102,    -1,    -1,    -1,   106,
     107,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,   116,
     117,   118,    -1,    -1,   121,    -1,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,   136,
      -1,    -1,    -1,   140,   141,    -1,   143,    -1,   145,   146,
      -1,    -1,    -1,   150,   151,    -1,    -1,   154,   155,   156,
     157,   158,   159,    -1,    -1,   162,    -1,    -1,    -1,    -1,
     167,   168,    -1,    -1,   171,    -1,    -1,    -1,    -1,   176,
      -1,    -1,   179,    -1,    -1,    -1,    -1,   184,   185,   186,
     187,   188,    -1,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,   200,   201,    -1,   203,   204,   205,   206,
     207,   208,    -1,   210,    -1,   212,    -1,    -1,    -1,    -1,
     217,   218,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,   235,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,   311,    -1,   313,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,   321,   322,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,    -1,
     124,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,
     194,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,   212,   213,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,    -1,   312,    -1,
     314,   315,   316,   317,   318,   319,   320,    -1,   322,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,   185,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,   313,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,    -1,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,    -1,   151,
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,   194,    -1,   196,    -1,   198,    -1,   200,    -1,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    -1,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,
     152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,    -1,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    -1,    -1,
      11,    12,   314,   315,   316,   317,   318,   319,   320,    20,
      -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    -1,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,   194,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
     211,   212,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
      -1,    -1,    16,   314,   315,   316,   317,   318,   319,   320,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,    -1,   150,   151,   152,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,   212,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,    -1,    -1,    16,
     314,   315,   316,   317,   318,   319,   320,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,   211,   212,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,    -1,    -1,    -1,   314,   315,   316,
     317,   318,   319,   320,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,    -1,   150,   151,   152,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,   212,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,    -1,    -1,    -1,
     314,   315,   316,   317,   318,   319,   320,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,
     124,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,    -1,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,   212,   213,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,    -1,   312,    -1,
     314,   315,   316,   317,   318,   319,   320,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,   156,
      -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,   196,
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,   211,   212,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,    -1,    24,    25,   314,   315,   316,
     317,   318,   319,   320,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    -1,
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
      -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,   188,
     189,    -1,    -1,    -1,    -1,   194,    -1,   196,    -1,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,    -1,   211,   212,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,    -1,    24,    25,   314,   315,   316,   317,   318,
     319,   320,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    -1,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,
      -1,    -1,    -1,   194,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
     211,   212,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
      -1,    24,    25,   314,   315,   316,   317,   318,   319,   320,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    -1,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,   152,
      -1,    -1,    -1,   156,    -1,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,    -1,    24,
      25,   314,   315,   316,   317,   318,   319,   320,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,    -1,   150,   151,   152,    -1,    -1,
      -1,   156,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,    -1,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,    -1,    24,    25,   314,
     315,   316,   317,   318,   319,   320,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,   156,
      -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,   211,   212,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,    -1,    24,    25,   314,   315,   316,
     317,   318,   319,   320,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    -1,
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
      -1,   150,   151,   152,    -1,    -1,    -1,   156,    -1,    -1,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,    -1,   211,   212,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,    -1,    24,    25,   314,   315,   316,   317,   318,
     319,   320,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    -1,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,    -1,    -1,    -1,   156,    -1,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
     211,   212,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
      -1,    24,    25,   314,   315,   316,   317,   318,   319,   320,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    -1,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,   152,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,    -1,    24,
      25,   314,   315,   316,   317,   318,   319,   320,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,    -1,   150,   151,   152,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,    -1,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,    -1,    24,    25,   314,
     315,   316,   317,   318,   319,   320,    33,    34,    -1,    36,
      37,    38,    -1,    40,    41,    42,    43,    -1,    -1,    46,
      47,    -1,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    -1,    60,    -1,    -1,    63,    64,    65,    66,
      67,    -1,    69,    -1,    71,    -1,    -1,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      -1,    -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,   150,   151,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,    -1,   212,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,    -1,    -1,    -1,   314,   315,   316,
     317,   318,   319,   320
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    12,    20,    21,    22,    23,    24,    25,    26,
      27,    29,    33,    34,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    94,
      95,    96,    97,    98,   100,   101,   102,   105,   106,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     124,   126,   127,   128,   129,   131,   135,   136,   137,   138,
     139,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     156,   157,   158,   159,   160,   165,   166,   167,   168,   169,
     170,   171,   172,   174,   176,   177,   180,   181,   182,   186,
     188,   189,   191,   192,   194,   196,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   211,   212,   213,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   259,   260,   261,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   312,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   335,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   356,   357,   358,   359,   360,   361,   365,   366,
     367,   371,   373,   374,   376,   383,   385,   388,   389,   390,
     392,   393,   394,   395,   396,   398,   399,   401,   402,   403,
     404,   405,   406,   408,   409,   412,   413,   414,   415,   420,
     422,   424,   425,   430,   449,   452,   456,   459,   460,   466,
     467,   468,   469,   471,   472,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   484,   485,   486,   487,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   520,   521,   522,   536,   537,
     539,   540,   541,   542,   543,   544,   545,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   565,   566,   567,
     568,   573,   574,   575,   576,   577,   578,   581,   639,   640,
     641,   642,   644,   645,   646,   647,   648,   655,   656,   657,
      33,    34,    49,   215,   391,   392,   393,   391,   391,   156,
     156,    37,    38,    40,    41,    47,    56,    57,    74,    79,
     111,   112,   113,   160,   220,   261,   287,   295,   303,   372,
     373,   377,   378,   379,   160,   153,   156,   153,   156,   153,
     156,     1,     3,    66,    71,   118,   417,   156,   380,   156,
      24,    34,    60,   118,   273,   429,   431,   432,   153,   156,
     156,   156,   118,   153,   156,   156,   156,    76,   153,   221,
     222,   122,   122,   122,   153,   156,    39,    43,    45,    46,
      47,    48,    51,    59,    67,    70,    72,    73,    75,    90,
      91,    97,   105,   112,   114,   115,   135,   138,   139,   169,
     172,   180,   181,   189,   202,   224,   226,   228,   229,   236,
     238,   239,   240,   243,   244,   315,   504,   655,   656,   122,
     118,   400,   122,   122,    39,    44,    45,    59,    61,    62,
      70,    97,   225,   655,   118,   122,   122,   184,   391,   393,
     413,   643,    48,    72,    73,   118,   153,   185,   244,   412,
     414,   424,   187,   412,   655,   153,   122,    16,   654,   655,
      18,    19,   655,   122,   122,   122,   496,   153,    30,   214,
     216,   225,   227,   314,   156,   225,   227,   314,   225,   314,
     225,   230,   314,   118,   241,   241,   242,   156,   153,   395,
     311,   412,   313,   412,   314,   322,   337,   337,     0,   339,
     340,    33,    49,   342,   359,     1,   190,   336,   190,   336,
     112,   374,   394,   412,   107,   190,   107,   336,   190,    42,
      46,    51,    69,   168,   171,   186,   212,   407,   416,   421,
     422,   423,   437,   438,   442,   167,    92,   132,   140,   141,
     143,   151,   155,   157,   162,   179,   203,   204,   205,   206,
     207,   208,   488,   489,   249,    99,   158,   176,   199,   117,
     146,   159,   194,   201,   210,   136,   150,    50,   200,   101,
     102,   158,   176,   486,   193,   153,   493,   496,   191,   192,
     154,   508,   509,   504,   508,   504,   156,   508,   145,   156,
     184,   184,   184,   375,   511,   375,    29,   653,   182,   196,
     182,   196,   166,   182,   656,   655,   169,   202,    47,   655,
     152,   118,    45,    47,    79,   106,   168,   654,   221,   222,
     223,   246,   612,   655,   655,   304,   137,   142,   112,   287,
     295,   377,   654,   392,   393,   187,   392,    45,    62,   187,
     561,   562,   412,   187,   194,   655,   426,   427,   655,   284,
     284,   426,   118,   433,   118,   187,   381,   382,   153,   397,
     412,     1,   160,   653,   113,   160,   355,   653,   655,   118,
     142,   107,   412,    29,   187,   654,   655,   655,   450,   451,
     655,   392,   187,   412,   412,   563,   655,   392,   153,   153,
     412,   187,   194,   655,   655,   142,   450,   184,   184,   121,
     107,   184,   156,   156,   156,   655,   153,   185,   186,   187,
      35,   524,   525,   526,   412,     8,   175,    17,   412,   214,
      29,   413,   413,    39,    45,    59,    70,    97,   507,   655,
     187,   413,   413,   413,   643,   413,   507,   413,   231,   230,
     579,   580,   655,   190,   190,   413,   412,   393,   412,   245,
     410,   411,   311,   313,   413,   337,   190,   336,   190,   336,
       3,   343,   359,   389,     1,   343,   359,   389,    33,   360,
     389,   360,   389,   400,   336,   400,   413,   413,   118,   168,
     170,   170,   394,   413,   413,   468,   469,   471,   471,   471,
     471,   470,   471,   471,   471,    70,   472,   476,   476,   475,
     477,   477,   477,   477,   478,   478,   479,   479,   231,    94,
      94,    94,   494,   184,   412,   496,   496,   412,   509,   187,
     413,   519,   149,   187,   519,   107,   187,   187,   107,   107,
     380,    29,   656,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,   362,   363,   364,    94,   137,   142,   368,
     369,   370,   655,   160,   160,   362,   653,   127,   132,    54,
      56,   100,   251,   264,   266,   277,   278,   279,   281,   283,
     613,   614,   615,   616,   617,   618,   625,   631,   632,   246,
      94,   299,   655,   142,   413,   118,   655,   655,   132,   184,
     184,   187,   187,   184,   107,   187,   107,   187,   107,    36,
      94,    96,   147,   428,   429,   546,   655,    55,   217,   254,
     418,   419,   655,    94,   107,   187,   391,   187,   654,    96,
      45,   654,   653,    96,   142,   546,   655,   413,   432,   184,
     187,   187,   187,   187,   107,   188,   147,   546,   184,   187,
     187,   153,   184,   392,   392,   184,   107,   187,   107,   187,
     142,   546,   413,   188,   413,   413,   412,   412,   412,   655,
     525,   526,   130,   197,   184,   184,   131,   190,    94,   218,
     219,   233,    94,   218,   219,   233,   233,   233,    94,    94,
     237,   225,   231,   107,   235,   142,   190,   187,   412,   184,
     505,   585,   411,   233,   359,    33,    33,   190,   336,   190,
     113,   394,   655,   170,   413,   443,   444,   118,   439,   440,
     471,   153,   156,   259,   492,   511,   586,   589,   590,   591,
     592,   593,   597,   599,   601,   602,    47,   152,   156,   211,
     317,   318,   319,   320,   547,   549,   551,   553,   569,   570,
     571,   572,   649,   650,   651,   652,   655,   547,   483,   552,
     655,   483,   184,   185,   107,   187,   187,   511,   148,   165,
     148,   165,   137,   397,   380,   363,   132,   549,   370,   413,
     546,   653,   653,   128,   129,   653,   277,   278,   279,   283,
     655,   263,   274,   263,   274,    29,   286,    96,   113,   156,
     619,   622,   613,    39,    44,    59,    61,    70,    97,   225,
     317,   318,   319,   384,   553,   649,   227,   299,   308,   413,
     655,    94,   299,   653,   153,   563,   564,   655,   563,   564,
     118,   427,   127,   547,   118,   413,   147,   429,   147,    36,
     147,   428,   429,   147,   546,   254,    53,    58,    77,   118,
     428,   434,   435,   436,   419,   546,   547,   382,    94,   184,
     198,   132,   354,   653,   160,   132,    96,   354,   413,   142,
     429,   153,   118,   413,   413,   147,   100,   453,   454,   455,
     457,   458,   100,   461,   462,   463,   464,   392,   184,   184,
     153,   563,   563,   413,   142,   190,   413,   121,   187,   187,
     187,    35,   526,   130,   197,     9,    10,   103,   123,   125,
     153,   195,   521,   523,   534,   535,   538,    29,   232,   234,
     413,   413,   413,   232,   234,   413,   413,   413,   413,   413,
     413,   413,   413,   413,   507,   118,   413,   413,    48,    72,
      73,   244,   394,   414,   424,   245,   582,   583,   153,   210,
     395,   413,   190,   113,   389,   389,   389,   443,    95,   106,
     116,   127,   445,   446,   447,   448,   107,   655,   107,   412,
     586,   593,   153,   285,   473,   638,    96,   169,   252,   253,
     255,   262,   272,   284,   587,   588,   607,   608,   609,   610,
     633,   636,   258,   260,   594,   612,   267,   598,   634,   247,
     248,   270,   603,   604,   156,   156,   549,   156,   156,   156,
     156,   156,   144,   176,   194,   548,   144,   413,   137,   397,
     565,   369,   286,    29,    96,   113,   156,   626,    29,   619,
     548,   548,   494,   287,   306,   546,   384,   227,   190,   391,
     187,   187,   144,   187,   187,   427,   147,   428,   655,   413,
     147,   413,   127,   413,   147,   429,   147,   413,   147,   118,
     118,   413,   655,   436,    77,   547,   394,   413,   653,   107,
     354,   413,   142,   391,   451,   413,   413,   113,   454,   455,
     100,   186,   113,   455,   458,   118,   465,   547,   100,   113,
     462,   100,   113,   464,   184,   391,   187,   187,   413,   413,
     198,   461,   132,   195,   523,     7,   392,   655,   195,   534,
     190,   233,   233,   233,   233,    96,   237,   237,   580,   186,
     156,   156,   156,   186,   585,   583,   505,   653,   128,   129,
     447,   448,   448,   444,   106,   142,   441,   546,   440,   184,
     187,   586,   600,   250,   217,   254,   268,   275,   637,    96,
     256,   257,   635,   250,   590,   637,   475,   607,   591,   147,
     282,   595,   596,   635,   286,   606,    78,   605,   187,   194,
     547,   550,   187,   187,   187,   187,   187,   187,   187,    29,
     136,   201,   628,   629,   630,    29,   627,   628,   271,   623,
     107,   620,   170,   655,   257,   494,   184,   413,   147,   413,
     147,   428,   413,   147,   413,   413,   655,   655,   435,   413,
     126,   126,    96,   653,   413,   184,   186,   186,   413,   394,
     413,   186,   186,   655,   186,   210,   118,   465,   118,   186,
     118,   465,   186,   184,   113,   526,   655,   195,   184,   526,
     655,   413,   413,   413,   413,   316,   413,   413,   413,   412,
     412,   412,   153,   584,   448,   653,   413,   142,   184,   477,
      52,   129,   475,   475,   269,   276,   286,   611,   611,   592,
     153,   280,    94,   187,   107,   187,   626,   626,   630,   107,
     187,    29,   624,   635,   621,   622,   187,   386,   387,   494,
     118,   225,   307,   287,   170,   413,   413,   147,   413,    53,
     394,   413,   354,   413,   394,    94,   394,   413,   547,   655,
     186,   655,   413,   655,   186,   394,   118,    93,   183,   527,
     526,   655,   197,   526,   413,   187,   187,   187,   412,   441,
     413,   475,   475,   199,   412,   547,   547,    94,    29,   265,
     107,   107,   448,   546,   655,   118,   225,   655,   386,   413,
     118,   465,    94,   186,    94,   655,     5,   133,   530,   531,
     533,   535,    28,   134,   528,   529,   532,   535,   197,   526,
     197,   198,   461,   184,   441,   475,   184,   547,   622,   387,
     448,   305,   655,   118,   225,   655,   186,   465,   394,   413,
     465,   186,    93,   133,   533,   183,   134,   532,   197,   113,
     413,   305,   655,   118,   394,   413,   186,   186,   118,   293,
     305,   655,   655,   306,   413,   306,   186,   494,   494,   199,
     287,   655,   225,   118,   655,   306,   494
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
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   334,   335,   335,   335,   335,   336,   336,   336,   337,
     337,   337,   337,   338,   338,   339,   339,   339,   339,   339,
     339,   339,   339,   340,   340,   340,   340,   341,   342,   342,
     342,   343,   343,   343,   343,   343,   344,   344,   344,   344,
     344,   344,   344,   344,   345,   345,   346,   347,   348,   348,
     349,   349,   350,   350,   351,   351,   351,   351,   352,   352,
     352,   353,   353,   353,   353,   354,   354,   355,   355,   356,
     356,   356,   356,   357,   358,   358,   359,   359,   359,   360,
     360,   360,   360,   360,   360,   360,   360,   361,   361,   362,
     362,   363,   364,   364,   364,   364,   364,   364,   364,   364,
     364,   364,   365,   366,   367,   368,   368,   369,   369,   369,
     370,   371,   371,   371,   372,   372,   372,   372,   373,   373,
     374,   374,   374,   374,   375,   375,   376,   376,   377,   377,
     378,   378,   379,   379,   380,   380,   380,   380,   381,   381,
     382,   382,   383,   383,   383,   383,   384,   384,   384,   384,
     385,   385,   386,   386,   387,   387,   387,   387,   388,   388,
     388,   388,   389,   390,   390,   390,   391,   391,   391,   392,
     392,   393,   393,   393,   394,   394,   394,   394,   394,   394,
     394,   394,   394,   394,   394,   394,   395,   395,   396,   397,
     398,   399,   399,   399,   400,   400,   400,   400,   401,   402,
     403,   404,   405,   405,   406,   407,   408,   409,   410,   410,
     411,   412,   412,   412,   413,   413,   413,   413,   413,   413,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   415,   416,   417,   417,   418,   418,   418,   419,
     419,   420,   420,   421,   422,   422,   422,   423,   423,   423,
     423,   423,   424,   424,   425,   425,   425,   426,   426,   426,
     427,   427,   427,   427,   427,   427,   427,   427,   427,   427,
     427,   427,   428,   429,   430,   431,   431,   432,   432,   432,
     432,   433,   433,   434,   434,   434,   435,   435,   435,   436,
     436,   436,   437,   438,   439,   439,   440,   440,   440,   440,
     440,   440,   441,   442,   442,   443,   443,   444,   444,   445,
     445,   445,   445,   445,   445,   445,   446,   446,   447,   447,
     448,   449,   449,   450,   450,   451,   451,   452,   453,   453,
     454,   455,   455,   456,   457,   457,   458,   459,   459,   460,
     460,   461,   461,   462,   462,   463,   463,   464,   464,   465,
     465,   466,   467,   467,   468,   468,   469,   469,   469,   469,
     469,   470,   469,   469,   469,   469,   471,   471,   472,   472,
     473,   473,   474,   474,   475,   475,   475,   476,   476,   476,
     476,   476,   477,   477,   477,   478,   478,   478,   479,   479,
     480,   480,   481,   481,   482,   482,   483,   483,   484,   484,
     485,   485,   485,   485,   486,   486,   486,   487,   487,   488,
     488,   488,   488,   488,   488,   489,   489,   489,   490,   490,
     490,   490,   491,   491,   492,   492,   493,   493,   493,   494,
     494,   494,   494,   495,   496,   496,   496,   497,   497,   498,
     498,   498,   498,   499,   499,   500,   500,   500,   500,   500,
     500,   500,   501,   501,   502,   502,   503,   503,   503,   503,
     503,   504,   504,   505,   505,   506,   506,   506,   506,   507,
     507,   507,   507,   508,   508,   509,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     511,   511,   512,   512,   512,   513,   514,   514,   515,   516,
     517,   518,   518,   519,   519,   520,   520,   521,   521,   521,
     522,   522,   522,   522,   522,   522,   523,   523,   524,   524,
     525,   526,   526,   527,   527,   528,   528,   529,   529,   529,
     529,   530,   530,   531,   531,   531,   531,   532,   532,   533,
     533,   534,   534,   534,   534,   535,   535,   535,   535,   536,
     536,   537,   537,   538,   539,   539,   539,   539,   539,   539,
     540,   541,   541,   542,   542,   543,   544,   545,   545,   546,
     547,   547,   547,   548,   548,   548,   549,   549,   549,   549,
     549,   549,   549,   550,   550,   551,   552,   553,   553,   553,
     553,   553,   553,   553,   553,   553,   554,   555,   555,   555,
     556,   557,   558,   558,   558,   559,   559,   559,   559,   559,
     560,   561,   561,   561,   561,   561,   561,   561,   562,   563,
     564,   565,   566,   566,   567,   568,   569,   569,   570,   571,
     571,   572,   573,   573,   573,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   575,   575,   576,   576,   577,
     578,   579,   579,   580,   581,   582,   582,   583,   584,   585,
     585,   586,   587,   587,   588,   588,   589,   589,   590,   590,
     591,   591,   592,   592,   593,   594,   594,   595,   595,   596,
     597,   597,   597,   598,   598,   599,   600,   600,   601,   602,
     602,   603,   603,   604,   604,   604,   605,   605,   606,   606,
     607,   607,   607,   607,   607,   608,   609,   610,   611,   611,
     611,   612,   612,   613,   613,   613,   613,   613,   613,   613,
     613,   614,   614,   614,   614,   615,   615,   616,   617,   617,
     618,   618,   618,   619,   619,   620,   620,   621,   621,   622,
     623,   623,   624,   624,   625,   625,   625,   626,   626,   627,
     627,   628,   628,   629,   629,   630,   630,   631,   632,   632,
     633,   633,   633,   634,   635,   635,   635,   635,   636,   636,
     637,   637,   638,   639,   639,   640,   640,   641,   641,   642,
     643,   643,   644,   644,   644,   645,   646,   647,   648,   649,
     649,   649,   650,   651,   652,   653,   654,   654,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     657
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     2,     3,     1,     2,     2,     1,
       2,     1,     2,     4,     6,     3,     3,     5,     1,     3,
       3,     5,     5,     1,     3,     3,     5,     6,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     4,     3,     3,     3,
       3,     3,     5,     5,     5,     5,     5,     5,     1,     1,
       3,     3,     4,     5,     6,     1,     3,     3,     3,     3,
       6,     5,     8,     5,     5,     5,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     4,     3,     1,     1,     1,     2,
       2,     4,     3,     5,     3,     4,     4,     5,     1,     2,
       1,     4,     1,     4,     1,     3,     2,     3,     1,     1,
       4,     4,     5,     5,     2,     3,     4,     5,     1,     3,
       2,     3,     3,     5,     4,     6,     1,     2,     1,     2,
       8,     9,     1,     3,     1,     2,     2,     3,    11,    14,
      13,    22,     1,     1,     1,     0,     1,     1,     0,     1,
       2,     1,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     3,     3,
       2,     3,     2,     3,     2,     3,     4,     5,     5,     2,
       4,     5,     3,     3,     2,     2,     8,     3,     1,     2,
       3,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     1,     2,     4,
       3,     5,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     2,     1,     4,     3,
       3,     5,     4,     6,     4,     6,     5,     7,     4,     5,
       5,     6,     3,     3,     2,     1,     3,     4,     5,     3,
       6,     4,     5,     1,     2,     3,     1,     2,     1,     6,
       3,     3,     2,     3,     1,     3,     2,     4,     5,     6,
       5,     3,     2,     3,     4,     1,     3,     1,     2,     1,
       1,     1,     2,     2,     2,     3,     1,     1,     2,     2,
       2,     5,     5,     1,     4,     3,     4,     8,     1,     2,
       3,     2,     3,     8,     1,     2,     3,     8,    10,     8,
      10,     1,     2,     4,     7,     1,     2,     4,     7,     1,
       3,     8,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     0,     4,     3,     3,     3,     1,     5,     1,     3,
       0,     1,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     4,
       1,     4,     1,     4,     1,     4,     1,     2,     1,     2,
       1,     1,     2,     2,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     5,
       5,     6,     3,     4,     1,     2,     3,     2,     2,     1,
       2,     2,     1,     1,     1,     3,     3,     1,     1,     1,
       2,     1,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     1,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     4,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     1,     4,
       4,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       4,     5,     8,     9,     9,    10,     1,     2,     1,     2,
       6,     0,     1,     3,     3,     0,     1,     1,     1,     2,
       2,     0,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       2,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       4,     3,     7,     3,     7,     4,     4,     3,     7,     2,
       1,     2,     3,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     4,     4,
       3,     3,     3,     4,     4,     3,     4,     6,     4,     6,
       4,     3,     4,     6,     6,     4,     6,     6,     4,     1,
       2,     1,     1,     1,     3,     3,     1,     1,     4,     5,
       6,     3,     3,     3,     3,     5,     7,     7,     5,     5,
       5,     7,     7,     5,     5,     3,     3,     5,     7,     5,
       7,     1,     4,     3,     5,     1,     2,     3,     3,     1,
       3,     2,     0,     1,     1,     2,     1,     3,     1,     3,
       1,     4,     1,     2,     3,     0,     1,     0,     1,     4,
       2,     3,     1,     0,     1,     4,     0,     1,     2,     1,
       3,     0,     1,     2,     2,     1,     0,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     2,     2,     3,     1,     2,
       2,     5,     2,     1,     1,     0,     2,     1,     3,     4,
       0,     2,     0,     2,     4,     4,     3,     2,     3,     1,
       3,     0,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     3,     2,     3,     3,     4,     2,     2,
       1,     1,     3,     2,     3,     2,     3,     2,     3,     3,
       3,     5,     5,     5,     8,     5,     3,     5,     7,     1,
       1,     1,     3,     3,     3,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const xquery_parser::yytname_[] =
  {
    "\"'end of file'\"", "error", "$undefined", "\"'unrecognized'\"",
  "\"'error'\"", "\"'apos attribute content'\"", "\"'char literal'\"",
  "\"'char literal]]>'\"", "\"'char literal and pi end'\"",
  "\"'&#charref;'\"", "\"'element content'\"", "\"'pref:*'\"",
  "\"'ns:*'\"", "\"'&entity;'\"", "\"'comment literal'\"",
  "\"'pi <NCName {>'\"", "\"'NCName_sval'\"", "\"'pragma literal'\"",
  "\"'QName #)'\"", "\"'EQName #)'\"", "\"'*:QName'\"",
  "\"'element QName {'\"", "\"'attribute QName {'\"",
  "\"'processing-instruction NCName {'\"", "\"'QName'\"", "\"'EQName'\"",
  "\"'%QName'\"", "\"'%EQName'\"", "\"'quote attribute content'\"",
  "\"'STRING'\"", "\"'XML comment'\"", "\"'URI'\"", "\"'NCName'\"",
  "\"'declare'\"", "\"'module'\"", "\"'<blank>'\"", "\"'allowing'\"",
  "\"'base-uri'\"", "\"'boundary-space'\"", "\"'comment'\"",
  "\"'construction'\"", "\"'copy-namespaces'\"", "\"'count'\"",
  "\"'document'\"", "\"'document-node'\"", "\"'element'\"", "\"'for'\"",
  "\"'function'\"", "\"'if'\"", "\"'import'\"", "\"'instance'\"",
  "\"'let'\"", "\"'most'\"", "\"'next'\"", "\"'no'\"", "\"'only'\"",
  "\"'option'\"", "\"'ordering'\"", "\"'previous'\"",
  "\"'processing-instruction'\"", "\"'schema'\"", "\"'schema-attribute'\"",
  "\"'schema-element'\"", "\"'sequential'\"", "\"'set'\"", "\"'simple'\"",
  "\"'sliding'\"", "\"'some'\"", "\"'space'\"", "\"'stable'\"",
  "\"'text'\"", "\"'tumbling'\"", "\"'switch'\"", "\"'typeswitch'\"",
  "\"'updating'\"", "\"'validate'\"", "\"'type'\"", "\"'when'\"",
  "\"'word'\"", "\"'decimal-format'\"", "\"'decimal-separator'\"",
  "\"'grouping-separator'\"", "\"'infinity'\"", "\"'minus-sign'\"",
  "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"", "\"'zero-digit'\"",
  "\"'digit'\"", "\"'pattern-separator'\"", "\"'ancestor'\"",
  "\"'ancestor-or-self'\"", "\"'and'\"", "\"'''\"", "\"'as'\"",
  "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'@'\"", "\"'||'\"",
  "\"'case'\"", "\"'castable'\"", "\"'cast'\"", "\"'CDATA[['\"",
  "\"']]'\"", "\"'child'\"", "\"'collation'\"", "\"','\"", "\"'(:'\"",
  "\"':)'\"", "\"'DECIMAL'\"", "\"'context'\"", "\"'variable'\"",
  "\"'default'\"", "\"'descendant'\"", "\"'descendant-or-self'\"",
  "\"'descending'\"", "\"'div'\"", "\"'$'\"", "\"'.'\"", "\"'..'\"",
  "\"':'\"", "\"'::'\"", "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"",
  "\"'else'\"", "\"'empty'\"", "\"'greatest'\"", "\"'least'\"", "\"'/>'\"",
  "\"'encoding'\"", "\"'='\"", "\"''''\"", "\"'\\\"\\\"'\"", "\"'every'\"",
  "\"'except'\"", "\"'external'\"", "\"'following'\"",
  "\"'following-sibling'\"", "\"'follows'\"", "\"'>='\"", "\"':='\"",
  "\"'>'\"", "\"'?'\"", "\"'#'\"", "\"'idiv'\"", "\"'in'\"",
  "\"'inherit'\"", "\"'INTEGER'\"", "\"'intersect'\"", "\"'is'\"",
  "\"'item'\"", "\"'{'\"", "\"'['\"", "\"'<='\"", "\"'('\"", "\"'<'\"",
  "\"'-'\"", "\"'mod'\"", "\"'namespace'\"", "\"'nan'\"", "\"'!='\"",
  "\"'nodecomp'\"", "\"'?""?'\"", "\"'<no inherit>'\"",
  "\"'<no preserve>'\"", "\"'or'\"", "\"'order'\"", "\"'ordered'\"",
  "\"'by'\"", "\"'group'\"", "\"'parent'\"", "\"'%'\"", "\"'<?'\"",
  "\"'?>'\"", "\"'+'\"", "\"'(#'\"", "\"'#)'\"", "\"'<<'\"",
  "\"'preceding'\"", "\"'preceding-sibling'\"", "\"'preserve'\"",
  "\"'\\\"'\"", "\"'}'\"", "\"']'\"", "\"'return'\"", "\"')'\"",
  "\"'satisfies'\"", "\"'self'\"", "\"';'\"", "\"'/'\"", "\"'//'\"",
  "\"'!'\"", "\"'*'\"", "\"'</ (start tag end)'\"", "\"'strip'\"",
  "\"'> (tag end)'\"", "\"'then'\"", "\"'to'\"", "\"'treat'\"",
  "\"'union'\"", "\"'unordered'\"", "\"'eq'\"", "\"'ge'\"", "\"'gt'\"",
  "\"'le'\"", "\"'lt'\"", "\"'ne'\"", "\"'VALUECOMP'\"", "\"'|'\"",
  "\"'empty-sequence'\"", "\"'where'\"", "\"'<!--'\"", "\"'-->'\"",
  "\"'xquery'\"", "\"'version'\"", "\"'start'\"", "\"'after'\"",
  "\"'before'\"", "\"'revalidation'\"", "\"'strict'\"", "\"'lax'\"",
  "\"'skip'\"", "\"'delete'\"", "\"'node'\"", "\"'insert'\"",
  "\"'nodes'\"", "\"'rename'\"", "\"'replace'\"", "\"'value'\"",
  "\"'of'\"", "\"'first'\"", "\"'into'\"", "\"'last'\"", "\"'modify'\"",
  "\"'copy'\"", "\"'with'\"", "\"'break'\"", "\"'continue'\"",
  "\"'exit'\"", "\"'loop'\"", "\"'returning'\"", "\"'while'\"",
  "\"'try'\"", "\"'catch'\"", "\"'using'\"", "\"'all'\"", "\"'any'\"",
  "\"'contains'\"", "\"'content'\"", "\"'diacritics'\"", "\"'different'\"",
  "\"'distance'\"", "\"'end'\"", "\"'entire'\"", "\"'exactly'\"",
  "\"'from'\"", "\"'ftand'\"", "\"'ftnot'\"", "\"'not'\"",
  "\"'ft-option'\"", "\"'ftor'\"", "\"'insensitive'\"", "\"'language'\"",
  "\"'levels'\"", "\"'lowercase'\"", "\"'occurs'\"", "\"'paragraph'\"",
  "\"'paragraphs'\"", "\"'phrase'\"", "\"'relationship'\"", "\"'same'\"",
  "\"'score'\"", "\"'sensitive'\"", "\"'sentence'\"", "\"'sentences'\"",
  "\"'stemming'\"", "\"'stop'\"", "\"'thesaurus'\"", "\"'times'\"",
  "\"'uppercase'\"", "\"'weight'\"", "\"'wildcards'\"", "\"'window'\"",
  "\"'without'\"", "\"'words'\"", "\"'collection'\"", "\"'const'\"",
  "\"'append-only'\"", "\"'queue'\"", "\"'mutable'\"", "\"'read-only'\"",
  "\"'unique'\"", "\"'non'\"", "\"'index'\"", "\"'manually'\"",
  "\"'automatically'\"", "\"'maintained'\"", "\"'on'\"", "\"'range'\"",
  "\"'equality'\"", "\"'general'\"", "\"'integrity'\"", "\"'constraint'\"",
  "\"'check'\"", "\"'key'\"", "\"'foreach'\"", "\"'foreign'\"",
  "\"'keys'\"", "\"'{|'\"", "\"'|}'\"", "\"'{['\"", "\"']}'\"",
  "\"'json'\"", "\"'append'\"", "\"'position'\"", "\"'object'\"",
  "\"'array'\"", "\"'json-item'\"", "\"'structured-item'\"",
  "\"'BOM_UTF8'\"", "\"'#!/shebang\"", "RANGE_REDUCE",
  "SEQUENCE_TYPE_REDUCE", "ADDITIVE_REDUCE", "UNION_REDUCE",
  "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR",
  "UNARY_PREC", "STEP_REDUCE", "SIMPLEMAPEXPR_REDUCE",
  "MULTIPLICATIVE_REDUCE", "$accept", "Module", "ERROR",
  "ModuleWithoutBOM", "VersionDecl", "MainModule", "LibraryModule",
  "ModuleDecl", "SIND_DeclList", "SIND_Decl", "Setter",
  "BoundarySpaceDecl", "DefaultCollationDecl", "BaseURIDecl",
  "ConstructionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "Import", "SchemaImport", "URILiteralList",
  "SchemaPrefix", "ModuleImport", "NamespaceDecl", "DefaultNamespaceDecl",
  "VFO_DeclList", "VFO_Decl", "DecimalFormatDecl",
  "DecimalFormatParamList", "DecimalFormatParam", "DecimalFormatParamName",
  "OptionDecl", "FTOptionDecl", "CtxItemDecl", "CtxItemDecl2",
  "CtxItemDecl3", "CtxItemDecl4", "VarDecl", "VarNameAndType",
  "AnnotationList", "Annotation", "AnnotationLiteralList", "FunctionDecl",
  "FunctionDecl2", "FunctionDeclSimple", "FunctionDeclUpdating",
  "FunctionSig", "ParamList", "Param", "CollectionDecl",
  "CollectionTypeDecl", "IndexDecl", "IndexKeyList", "IndexKeySpec",
  "IntegrityConstraintDecl", "QueryBody", "StatementsAndOptionalExprTop",
  "StatementsAndOptionalExpr", "StatementsAndExpr", "Statements",
  "Statement", "BlockStatement", "BlockExpr",
  "EnclosedStatementsAndOptionalExpr", "VarDeclStatement",
  "BlockVarDeclList", "BlockVarDecl", "AssignStatement", "ApplyStatement",
  "ExitStatement", "WhileStatement", "FlowCtlStatement", "FLWORStatement",
  "ReturnStatement", "IfStatement", "TryStatement", "CatchListStatement",
  "CatchStatement", "Expr", "ExprSingle", "ExprSimple", "FLWORExpr",
  "ReturnExpr", "WindowType", "FLWORWinCondType", "FLWORWinCond",
  "WindowClause", "CountClause", "ForLetWinClause", "FLWORClause",
  "FLWORClauseList", "ForClause", "VarInDeclList", "VarInDecl",
  "PositionalVar", "FTScoreVar", "LetClause", "VarGetsDeclList",
  "VarGetsDecl", "WindowVarDecl", "WindowVars", "WindowVars3",
  "WindowVars2", "WhereClause", "GroupByClause", "GroupSpecList",
  "GroupSpec", "GroupCollationSpec", "OrderByClause", "OrderSpecList",
  "OrderSpec", "OrderModifier", "OrderDirSpec", "OrderEmptySpec",
  "OrderCollationSpec", "QuantifiedExpr", "QVarInDeclList", "QVarInDecl",
  "SwitchExpr", "SwitchCaseClauseList", "SwitchCaseClause",
  "SwitchCaseOperandList", "SwitchStatement", "SwitchCaseStatementList",
  "SwitchCaseStatement", "TypeswitchExpr", "TypeswitchStatement",
  "CaseClauseList", "CaseClause", "CaseStatementList", "CaseStatement",
  "SequenceTypeList", "IfExpr", "OrExpr", "AndExpr", "ComparisonExpr",
  "$@1", "FTContainsExpr", "StringConcatExpr", "opt_FTIgnoreOption",
  "RangeExpr", "AdditiveExpr", "MultiplicativeExpr", "UnionExpr",
  "IntersectExceptExpr", "InstanceofExpr", "TreatExpr", "CastableExpr",
  "CastExpr", "SingleType", "UnaryExpr", "SignList", "ValueExpr",
  "SimpleMapExpr", "ValueComp", "NodeComp", "ValidateExpr",
  "ExtensionExpr", "Pragma_list", "Pragma", "PathExpr", "LeadingSlash",
  "RelativePathExpr", "StepExpr", "AxisStep", "ForwardStep", "ForwardAxis",
  "AbbrevForwardStep", "ReverseStep", "ReverseAxis", "NodeTest",
  "NameTest", "Wildcard", "FilterExpr", "PredicateList", "Predicate",
  "PrimaryExpr", "Literal", "NumericLiteral", "VarRef",
  "ParenthesizedExpr", "ContextItemExpr", "OrderedExpr", "UnorderedExpr",
  "FunctionCall", "ArgList", "Constructor", "DirectConstructor",
  "DirElemConstructor", "DirElemContentList", "DirAttributeList",
  "DirAttr", "OptionalBlank", "DirAttributeValue",
  "opt_QuoteAttrContentList", "QuoteAttrContentList",
  "opt_AposAttrContentList", "AposAttrContentList",
  "QuoteAttrValueContent", "AposAttrValueContent", "DirElemContent",
  "CommonContent", "DirCommentConstructor", "DirPIConstructor",
  "CDataSection", "ComputedConstructor", "CompDocConstructor",
  "CompElemConstructor", "CompAttrConstructor", "CompTextConstructor",
  "CompCommentConstructor", "CompPIConstructor", "TypeDeclaration",
  "SequenceType", "OccurrenceIndicator", "ItemType", "TypeList",
  "GeneralizedAtomicType", "SimpleType", "KindTest", "AnyKindTest",
  "DocumentTest", "TextTest", "CommentTest", "PITest", "AttributeTest",
  "SchemaAttributeTest", "ElementTest", "SchemaElementTest", "TypeName",
  "TypeName_WITH_HOOK", "StringLiteral", "FunctionItemExpr",
  "LiteralFunctionItem", "InlineFunction", "FunctionTest",
  "AnyFunctionTest", "TypedFunctionTest", "ParenthesizedItemType",
  "RevalidationDecl", "InsertExpr", "DeleteExpr", "ReplaceExpr",
  "RenameExpr", "TransformExpr", "VarNameList", "VarNameDecl", "TryExpr",
  "CatchListExpr", "CatchExpr", "BracedExpr", "NameTestList",
  "FTSelection", "opt_FTPosFilter_list", "FTPosFilter_list", "FTOr",
  "FTAnd", "FTMildNot", "FTUnaryNot", "FTPrimaryWithOptions",
  "opt_FTMatchOptions", "opt_FTWeight", "FTWeight", "FTPrimary",
  "opt_FTTimes", "FTExtensionSelection", "opt_FTSelection", "FTWords",
  "FTWordsValue", "opt_FTAnyallOption", "FTAnyallOption", "opt_word",
  "opt_words", "FTPosFilter", "FTOrder", "FTWindow", "FTDistance",
  "FTUnit", "FTMatchOptions", "FTMatchOption", "FTCaseOption",
  "FTDiacriticsOption", "FTExtensionOption", "FTStemOption",
  "FTThesaurusOption", "FTThesaurusID_or_default", "opt_FTThesaurus_list",
  "FTThesaurus_list", "FTThesaurusID", "opt_relationship", "opt_levels",
  "FTStopWordOption", "FTStopWords", "STRING_LITERAL_list",
  "opt_FTStopWordsInclExcl_list", "FTStopWordsInclExcl_list",
  "FTStopWordsInclExcl", "FTLanguageOption", "FTWildCardOption",
  "FTContent", "FTTimes", "FTRange", "FTScope", "FTBigUnit",
  "FTIgnoreOption", "JSONArrayConstructor", "JSONSimpleObjectUnion",
  "JSONAccumulatorObjectUnion", "JSONObjectConstructor", "JSONPairList",
  "JSONInsertExpr", "JSONAppendExpr", "JSONDeleteExpr", "JSONRenameExpr",
  "JSONReplaceExpr", "JSONTest", "JSONItemTest", "JSONObjectTest",
  "JSONArrayTest", "URI_LITERAL", "NCNAME", "QNAME", "FUNCTION_NAME",
  "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       335,     0,    -1,   337,    -1,   321,   337,    -1,   322,   337,
      -1,   321,   322,   337,    -1,     1,    -1,     1,     3,    -1,
     336,     1,    -1,   339,    -1,   338,   339,    -1,   340,    -1,
     338,   340,    -1,   215,   216,    29,   190,    -1,   215,   216,
      29,   131,    29,   190,    -1,   342,   190,   389,    -1,   359,
     190,   389,    -1,   342,   190,   359,   190,   389,    -1,   389,
      -1,   342,   336,   389,    -1,   359,   336,   389,    -1,   342,
     190,   359,   336,   389,    -1,   342,   336,   359,   190,   389,
      -1,   341,    -1,   341,   342,   190,    -1,   341,   359,   190,
      -1,   341,   342,   190,   359,   190,    -1,    34,   160,   654,
     132,   653,   190,    -1,   343,    -1,   342,   190,   343,    -1,
     342,   336,   343,    -1,   344,    -1,   352,    -1,   357,    -1,
     358,    -1,   366,    -1,   345,    -1,   346,    -1,   347,    -1,
     348,    -1,   349,    -1,   350,    -1,   351,    -1,   573,    -1,
      33,    38,   182,    -1,    33,    38,   196,    -1,    33,   113,
     106,   653,    -1,    33,    37,   653,    -1,    33,    40,   182,
      -1,    33,    40,   196,    -1,    33,    57,   169,    -1,    33,
      57,   202,    -1,    33,   113,   168,   127,   128,    -1,    33,
     113,   168,   127,   129,    -1,    33,    41,   182,   107,   148,
      -1,    33,    41,   182,   107,   165,    -1,    33,    41,   166,
     107,   148,    -1,    33,    41,   166,   107,   165,    -1,   353,
      -1,   356,    -1,    49,    24,     1,    -1,    49,    60,   653,
      -1,    49,    60,   355,   653,    -1,    49,    60,   653,    96,
     354,    -1,    49,    60,   355,   653,    96,   354,    -1,   653,
      -1,   354,   107,   653,    -1,   160,   654,   132,    -1,   113,
      45,   160,    -1,    49,    34,   653,    -1,    49,    34,   160,
     654,   132,   653,    -1,    49,    34,   653,    96,   354,    -1,
      49,    34,   160,   654,   132,   653,    96,   354,    -1,    33,
     160,   654,   132,   653,    -1,    33,   113,    45,   160,   653,
      -1,    33,   113,    47,   160,   653,    -1,   360,    -1,   359,
     190,   360,    -1,   359,   336,   360,    -1,   361,    -1,   365,
      -1,   367,    -1,   371,    -1,   376,    -1,   383,    -1,   385,
      -1,   388,    -1,    33,   113,    79,   362,    -1,    33,    79,
     655,   362,    -1,   363,    -1,   362,   363,    -1,   364,   132,
     565,    -1,    80,    -1,    88,    -1,    81,    -1,    82,    -1,
      83,    -1,    84,    -1,    89,    -1,    85,    -1,    86,    -1,
      87,    -1,    33,    56,   655,    29,    -1,    33,   261,   612,
      -1,    33,   111,   152,   368,    -1,    94,   549,   369,    -1,
     369,    -1,   370,    -1,   137,    -1,   137,   370,    -1,   142,
     413,    -1,    33,   372,   142,   413,    -1,    33,   372,   137,
      -1,    33,   372,   137,   142,   413,    -1,   112,   118,   655,
      -1,   112,   118,   655,   546,    -1,   373,   112,   118,   655,
      -1,   373,   112,   118,   655,   546,    -1,   374,    -1,   373,
     374,    -1,    26,    -1,    26,   156,   375,   187,    -1,    27,
      -1,    27,   156,   375,   187,    -1,   511,    -1,   375,   107,
     511,    -1,    33,   377,    -1,    33,   373,   377,    -1,   378,
      -1,   379,    -1,    47,   656,   380,   397,    -1,    47,   656,
     380,   137,    -1,    74,    47,   656,   380,   397,    -1,    74,
      47,   656,   380,   137,    -1,   156,   187,    -1,   156,   381,
     187,    -1,   156,   187,    94,   547,    -1,   156,   381,   187,
      94,   547,    -1,   382,    -1,   381,   107,   382,    -1,   118,
     655,    -1,   118,   655,   546,    -1,    33,   287,   655,    -1,
      33,   287,   655,    94,   384,    -1,    33,   373,   287,   655,
      -1,    33,   373,   287,   655,    94,   384,    -1,   553,    -1,
     553,   548,    -1,   649,    -1,   649,   548,    -1,    33,   295,
     655,   299,   227,   494,   170,   386,    -1,    33,   373,   295,
     655,   299,   227,   494,   170,   386,    -1,   387,    -1,   386,
     107,   387,    -1,   494,    -1,   494,   546,    -1,   494,   448,
      -1,   494,   546,   448,    -1,    33,   303,   304,   655,   299,
     287,   655,   118,   655,   305,   413,    -1,    33,   303,   304,
     655,   299,   287,   655,   225,   118,   655,   305,   293,   306,
     494,    -1,    33,   303,   304,   655,   299,   287,   655,   307,
     225,   118,   655,   305,   413,    -1,    33,   303,   304,   655,
     308,   306,   257,   287,   655,   225,   118,   655,   306,   494,
     199,   287,   655,   225,   118,   655,   306,   494,    -1,   390,
      -1,   392,    -1,   393,    -1,    -1,   392,    -1,   393,    -1,
      -1,   412,    -1,   393,   412,    -1,   394,    -1,   393,   394,
      -1,   393,   412,   336,   394,    -1,   395,    -1,   398,    -1,
     401,    -1,   402,    -1,   403,    -1,   404,    -1,   405,    -1,
     406,    -1,   408,    -1,   460,    -1,   456,    -1,   409,    -1,
     153,   393,   184,    -1,   153,   184,    -1,   153,   391,   184,
      -1,   153,   391,   184,    -1,   399,   190,    -1,   399,   107,
     400,    -1,   112,   400,    -1,   373,   112,   400,    -1,   118,
     655,    -1,   118,   655,   546,    -1,   118,   655,   142,   413,
      -1,   118,   655,   546,   142,   413,    -1,   118,   655,   142,
     413,   190,    -1,   414,   190,    -1,   240,   242,   413,   190,
      -1,   243,   156,   412,   187,   394,    -1,   238,   241,   190,
      -1,   239,   241,   190,    -1,   424,   407,    -1,   186,   394,
      -1,    48,   156,   412,   187,   198,   394,   126,   394,    -1,
     244,   395,   410,    -1,   411,    -1,   410,   411,    -1,   245,
     585,   395,    -1,   413,    -1,   412,   107,   413,    -1,   412,
     336,   413,    -1,   415,    -1,   452,    -1,   459,    -1,   466,
      -1,   581,    -1,   414,    -1,   467,    -1,   449,    -1,   574,
      -1,   575,    -1,   577,    -1,   576,    -1,   578,    -1,   646,
      -1,   644,    -1,   647,    -1,   648,    -1,   645,    -1,   424,
     416,    -1,   186,   413,    -1,    66,   284,    -1,    71,   284,
      -1,   217,    -1,   254,    -1,    55,   254,    -1,   418,   434,
      77,   413,    -1,   418,    77,   413,    -1,    46,   417,   433,
     419,   419,    -1,    46,   417,   433,   419,    -1,    42,   118,
     655,    -1,   425,    -1,   430,    -1,   420,    -1,   422,    -1,
     437,    -1,   442,    -1,   438,    -1,   421,    -1,   422,    -1,
     424,   423,    -1,    46,   118,   426,    -1,    46,     1,   426,
      -1,    46,     3,    -1,   427,    -1,   426,   107,   118,   427,
      -1,   426,   107,   427,    -1,   655,   147,   413,    -1,   655,
      36,   127,   147,   413,    -1,   655,   546,   147,   413,    -1,
     655,   546,    36,   127,   147,   413,    -1,   655,   428,   147,
     413,    -1,   655,    36,   127,   428,   147,   413,    -1,   655,
     546,   428,   147,   413,    -1,   655,   546,    36,   127,   428,
     147,   413,    -1,   655,   429,   147,   413,    -1,   655,   546,
     429,   147,   413,    -1,   655,   428,   429,   147,   413,    -1,
     655,   546,   428,   429,   147,   413,    -1,    96,   118,   655,
      -1,   273,   118,   655,    -1,    51,   431,    -1,   432,    -1,
     431,   107,   432,    -1,   118,   655,   142,   413,    -1,   118,
     655,   546,   142,   413,    -1,   429,   142,   413,    -1,   118,
     655,   546,   429,   142,   413,    -1,   118,   655,   147,   413,
      -1,   118,   655,   546,   147,   413,    -1,   435,    -1,   118,
     655,    -1,   118,   655,   435,    -1,   428,    -1,   428,   436,
      -1,   436,    -1,    58,   118,   655,    53,   118,   655,    -1,
      53,   118,   655,    -1,    58,   118,   655,    -1,   212,   413,
      -1,   171,   170,   439,    -1,   440,    -1,   439,   107,   440,
      -1,   118,   655,    -1,   118,   655,   142,   413,    -1,   118,
     655,   546,   142,   413,    -1,   118,   655,   546,   142,   413,
     441,    -1,   118,   655,   142,   413,   441,    -1,   118,   655,
     441,    -1,   106,   653,    -1,   168,   170,   443,    -1,    69,
     168,   170,   443,    -1,   444,    -1,   443,   107,   444,    -1,
     413,    -1,   413,   445,    -1,   446,    -1,   447,    -1,   448,
      -1,   446,   447,    -1,   446,   448,    -1,   447,   448,    -1,
     446,   447,   448,    -1,    95,    -1,   116,    -1,   127,   128,
      -1,   127,   129,    -1,   106,   653,    -1,    67,   118,   450,
     188,   413,    -1,   135,   118,   450,   188,   413,    -1,   451,
      -1,   450,   107,   118,   451,    -1,   655,   147,   413,    -1,
     655,   546,   147,   413,    -1,    72,   156,   412,   187,   453,
     113,   186,   413,    -1,   454,    -1,   453,   454,    -1,   455,
     186,   413,    -1,   100,   413,    -1,   455,   100,   413,    -1,
      72,   156,   412,   187,   457,   113,   186,   394,    -1,   458,
      -1,   457,   458,    -1,   455,   186,   394,    -1,    73,   156,
     412,   187,   461,   113,   186,   413,    -1,    73,   156,   412,
     187,   461,   113,   118,   655,   186,   413,    -1,    73,   156,
     412,   187,   463,   113,   186,   394,    -1,    73,   156,   412,
     187,   461,   113,   118,   655,   186,   394,    -1,   462,    -1,
     461,   462,    -1,   100,   465,   186,   413,    -1,   100,   118,
     655,    94,   465,   186,   413,    -1,   464,    -1,   463,   464,
      -1,   100,   465,   186,   394,    -1,   100,   118,   655,    94,
     465,   186,   394,    -1,   547,    -1,   465,   210,   547,    -1,
      48,   156,   412,   187,   198,   413,   126,   413,    -1,   468,
      -1,   467,   167,   468,    -1,   469,    -1,   468,    92,   469,
      -1,   471,    -1,   471,   488,   471,    -1,   471,   489,   471,
      -1,   471,   132,   471,    -1,   471,   162,   471,    -1,    -1,
     471,   157,   470,   471,    -1,   471,   155,   471,    -1,   471,
     143,   471,    -1,   471,   141,   471,    -1,   472,    -1,   472,
     249,    70,   586,   473,    -1,   474,    -1,   474,    99,   472,
      -1,    -1,   638,    -1,   475,    -1,   475,   199,   475,    -1,
     476,    -1,   475,   176,   476,    -1,   475,   158,   476,    -1,
     477,    -1,   476,   194,   477,    -1,   476,   117,   477,    -1,
     476,   146,   477,    -1,   476,   159,   477,    -1,   478,    -1,
     477,   201,   478,    -1,   477,   210,   478,    -1,   479,    -1,
     478,   150,   479,    -1,   478,   136,   479,    -1,   480,    -1,
     480,    50,   231,   547,    -1,   481,    -1,   481,   200,    94,
     547,    -1,   482,    -1,   482,   101,    94,   483,    -1,   484,
      -1,   484,   102,    94,   483,    -1,   552,    -1,   552,   144,
      -1,   486,    -1,   485,   486,    -1,   176,    -1,   158,    -1,
     485,   176,    -1,   485,   158,    -1,   490,    -1,   487,    -1,
     491,    -1,   494,    -1,   487,   193,   494,    -1,   203,    -1,
     208,    -1,   207,    -1,   206,    -1,   205,    -1,   204,    -1,
     151,    -1,   179,    -1,   140,    -1,    75,   153,   392,   184,
      -1,    75,   222,   153,   392,   184,    -1,    75,   221,   153,
     392,   184,    -1,    75,    76,   563,   153,   392,   184,    -1,
     492,   153,   184,    -1,   492,   153,   412,   184,    -1,   493,
      -1,   492,   493,    -1,   177,   655,    17,    -1,   177,    18,
      -1,   177,    19,    -1,   495,    -1,   495,   496,    -1,   192,
     496,    -1,   496,    -1,   191,    -1,   497,    -1,   497,   191,
     496,    -1,   497,   192,   496,    -1,   498,    -1,   507,    -1,
     499,    -1,   499,   508,    -1,   502,    -1,   502,   508,    -1,
     500,   504,    -1,   501,    -1,   105,   122,    -1,   114,   122,
      -1,    97,   122,    -1,   189,   122,    -1,   115,   122,    -1,
     139,   122,    -1,   138,   122,    -1,   504,    -1,    98,   504,
      -1,   503,   504,    -1,   120,    -1,   172,   122,    -1,    90,
     122,    -1,   181,   122,    -1,   180,   122,    -1,    91,   122,
      -1,   553,    -1,   505,    -1,   655,    -1,   506,    -1,   194,
      -1,    11,    -1,    12,    -1,    20,    -1,   510,    -1,   507,
     508,    -1,   507,   156,   187,    -1,   507,   156,   519,   187,
      -1,   509,    -1,   508,   509,    -1,   154,   412,   185,    -1,
     511,    -1,   513,    -1,   514,    -1,   515,    -1,   518,    -1,
     520,    -1,   516,    -1,   517,    -1,   566,    -1,   396,    -1,
     642,    -1,   639,    -1,   640,    -1,   641,    -1,   512,    -1,
     565,    -1,   110,    -1,   149,    -1,   124,    -1,   118,   655,
      -1,   156,   187,    -1,   156,   412,   187,    -1,   119,    -1,
     169,   153,   412,   184,    -1,   202,   153,   412,   184,    -1,
     656,   156,   187,    -1,   656,   156,   519,   187,    -1,   413,
      -1,   519,   107,   413,    -1,   521,    -1,   539,    -1,   522,
      -1,   536,    -1,   537,    -1,   157,   655,   526,   130,    -1,
     157,   655,   524,   526,   130,    -1,   157,   655,   526,   197,
     195,   655,   526,   197,    -1,   157,   655,   526,   197,   523,
     195,   655,   526,   197,    -1,   157,   655,   524,   526,   197,
     195,   655,   526,   197,    -1,   157,   655,   524,   526,   197,
     523,   195,   655,   526,   197,    -1,   534,    -1,   523,   534,
      -1,   525,    -1,   524,   525,    -1,    35,   655,   526,   132,
     526,   527,    -1,    -1,    35,    -1,   183,   528,   183,    -1,
      93,   530,    93,    -1,    -1,   529,    -1,   134,    -1,   532,
      -1,   529,   134,    -1,   529,   532,    -1,    -1,   531,    -1,
     133,    -1,   533,    -1,   531,   133,    -1,   531,   533,    -1,
      28,    -1,   535,    -1,     5,    -1,   535,    -1,   521,    -1,
      10,    -1,   538,    -1,   535,    -1,     9,    -1,   123,    -1,
     125,    -1,   153,   392,   184,    -1,   213,    30,   214,    -1,
     213,   214,    -1,   174,   654,   175,    -1,   174,   654,     8,
      -1,   103,     7,    -1,   540,    -1,   541,    -1,   542,    -1,
     543,    -1,   544,    -1,   545,    -1,    43,   153,   392,   184,
      -1,    21,   391,   184,    -1,    45,   153,   412,   184,   153,
     391,   184,    -1,    22,   391,   184,    -1,    97,   153,   412,
     184,   153,   391,   184,    -1,    70,   153,   392,   184,    -1,
      39,   153,   392,   184,    -1,    23,   391,   184,    -1,    59,
     153,   412,   184,   153,   391,   184,    -1,    94,   547,    -1,
     549,    -1,   549,   548,    -1,   211,   156,   187,    -1,   144,
      -1,   194,    -1,   176,    -1,   551,    -1,   553,    -1,   152,
     156,   187,    -1,   320,   156,   187,    -1,   569,    -1,   572,
      -1,   649,    -1,   547,    -1,   550,   107,   547,    -1,   655,
      -1,   655,    -1,   555,    -1,   561,    -1,   559,    -1,   562,
      -1,   560,    -1,   558,    -1,   557,    -1,   556,    -1,   554,
      -1,   225,   156,   187,    -1,    44,   156,   187,    -1,    44,
     156,   561,   187,    -1,    44,   156,   562,   187,    -1,    70,
     156,   187,    -1,    39,   156,   187,    -1,    59,   156,   187,
      -1,    59,   156,   654,   187,    -1,    59,   156,    29,   187,
      -1,    97,   156,   187,    -1,    97,   156,   655,   187,    -1,
      97,   156,   655,   107,   563,   187,    -1,    97,   156,   194,
     187,    -1,    97,   156,   194,   107,   563,   187,    -1,    61,
     156,   655,   187,    -1,    45,   156,   187,    -1,    45,   156,
     655,   187,    -1,    45,   156,   655,   107,   563,   187,    -1,
      45,   156,   655,   107,   564,   187,    -1,    45,   156,   194,
     187,    -1,    45,   156,   194,   107,   563,   187,    -1,    45,
     156,   194,   107,   564,   187,    -1,    62,   156,   655,   187,
      -1,   655,    -1,   655,   144,    -1,    29,    -1,   567,    -1,
     568,    -1,   655,   145,   149,    -1,    47,   380,   397,    -1,
     570,    -1,   571,    -1,    47,   156,   194,   187,    -1,    47,
     156,   187,    94,   547,    -1,    47,   156,   550,   187,    94,
     547,    -1,   156,   549,   187,    -1,    33,   220,   221,    -1,
      33,   220,   222,    -1,    33,   220,   223,    -1,   226,   225,
     413,   233,   413,    -1,   226,   225,   413,    94,   232,   233,
     413,    -1,   226,   225,   413,    94,   234,   233,   413,    -1,
     226,   225,   413,   218,   413,    -1,   226,   225,   413,   219,
     413,    -1,   226,   227,   413,   233,   413,    -1,   226,   227,
     413,    94,   232,   233,   413,    -1,   226,   227,   413,    94,
     234,   233,   413,    -1,   226,   227,   413,   218,   413,    -1,
     226,   227,   413,   219,   413,    -1,   224,   225,   413,    -1,
     224,   227,   413,    -1,   229,   225,   413,   237,   413,    -1,
     229,   230,   231,   225,   413,   237,   413,    -1,   228,   225,
     413,    94,   413,    -1,   236,   118,   579,   235,   413,   186,
     413,    -1,   580,    -1,   579,   107,   118,   580,    -1,   655,
     142,   413,    -1,   244,   153,   412,   184,   582,    -1,   583,
      -1,   582,   583,    -1,   245,   585,   584,    -1,   153,   412,
     184,    -1,   505,    -1,   585,   210,   505,    -1,   589,   587,
      -1,    -1,   588,    -1,   607,    -1,   588,   607,    -1,   590,
      -1,   589,   262,   590,    -1,   591,    -1,   590,   258,   591,
      -1,   592,    -1,   591,   260,   147,   592,    -1,   593,    -1,
     259,   593,    -1,   597,   594,   595,    -1,    -1,   612,    -1,
      -1,   596,    -1,   282,   153,   412,   184,    -1,   601,   598,
      -1,   156,   586,   187,    -1,   599,    -1,    -1,   634,    -1,
     492,   153,   600,   184,    -1,    -1,   586,    -1,   602,   603,
      -1,   511,    -1,   153,   412,   184,    -1,    -1,   604,    -1,
     248,   605,    -1,   247,   606,    -1,   270,    -1,    -1,    78,
      -1,    -1,   286,    -1,   608,    -1,   609,    -1,   610,    -1,
     636,    -1,   633,    -1,   169,    -1,   284,   475,   611,    -1,
     253,   635,   611,    -1,   286,    -1,   276,    -1,   269,    -1,
     246,   613,    -1,   612,   246,   613,    -1,   614,    -1,   615,
      -1,   616,    -1,   631,    -1,   617,    -1,   625,    -1,   618,
      -1,   632,    -1,   100,   274,    -1,   100,   263,    -1,   266,
      -1,   281,    -1,   251,   274,    -1,   251,   263,    -1,    56,
     655,    29,    -1,   277,    -1,    54,   277,    -1,   279,   619,
      -1,   279,   156,   619,   620,   187,    -1,    54,   279,    -1,
     622,    -1,   113,    -1,    -1,   107,   621,    -1,   622,    -1,
     621,   107,   622,    -1,    96,    29,   623,   624,    -1,    -1,
     271,    29,    -1,    -1,   635,   265,    -1,   278,   286,   626,
     628,    -1,   278,   286,   113,   628,    -1,    54,   278,   286,
      -1,    96,    29,    -1,   156,   627,   187,    -1,    29,    -1,
     627,   107,    29,    -1,    -1,   629,    -1,   630,    -1,   629,
     630,    -1,   201,   626,    -1,   136,   626,    -1,   264,    29,
      -1,   283,    -1,    54,   283,    -1,    96,   217,    -1,    96,
     254,    -1,   255,   250,    -1,   267,   635,   280,    -1,   256,
     475,    -1,    96,   129,   475,    -1,    96,    52,   475,    -1,
     257,   475,   199,   475,    -1,   272,   637,    -1,   252,   637,
      -1,   275,    -1,   268,    -1,   285,   250,   477,    -1,   154,
     185,    -1,   154,   412,   185,    -1,   310,   311,    -1,   310,
     412,   311,    -1,   312,   313,    -1,   312,   412,   313,    -1,
     153,   643,   184,    -1,   413,   121,   413,    -1,   643,   107,
     413,   121,   413,    -1,   226,   314,   413,   233,   413,    -1,
     226,   314,   643,   233,   413,    -1,   226,   314,   413,   233,
     413,    96,   316,   413,    -1,   315,   314,   413,   233,   413,
      -1,   224,   314,   507,    -1,   228,   314,   507,    94,   413,
      -1,   229,   314,   230,   231,   507,   237,   413,    -1,   650,
      -1,   651,    -1,   652,    -1,   319,   156,   187,    -1,   317,
     156,   187,    -1,   318,   156,   187,    -1,    29,    -1,    16,
      -1,   655,    -1,   656,    -1,    97,    -1,    39,    -1,    44,
      -1,    45,    -1,   152,    -1,    48,    -1,   225,    -1,    59,
      -1,    61,    -1,    62,    -1,    70,    -1,    73,    -1,    72,
      -1,   211,    -1,   243,    -1,   657,    -1,    24,    -1,   215,
      -1,   127,    -1,    38,    -1,   261,    -1,    37,    -1,   222,
      -1,   221,    -1,   146,    -1,    43,    -1,   259,    -1,   260,
      -1,   274,    -1,   263,    -1,   251,    -1,   285,    -1,   277,
      -1,   279,    -1,   278,    -1,   283,    -1,   255,    -1,   250,
      -1,    78,    -1,   217,    -1,   254,    -1,    52,    -1,   223,
      -1,   236,    -1,   302,    -1,   230,    -1,   203,    -1,   208,
      -1,   207,    -1,   206,    -1,   205,    -1,   204,    -1,    96,
      -1,   111,    -1,   112,    -1,   186,    -1,    46,    -1,    36,
      -1,    66,    -1,    71,    -1,    58,    -1,    53,    -1,    55,
      -1,    77,    -1,    42,    -1,   147,    -1,    51,    -1,   212,
      -1,   170,    -1,   171,    -1,   168,    -1,    69,    -1,    95,
      -1,   116,    -1,   128,    -1,   129,    -1,   106,    -1,    67,
      -1,   135,    -1,   188,    -1,   100,    -1,    94,    -1,   198,
      -1,   126,    -1,   167,    -1,    92,    -1,    50,    -1,   231,
      -1,   101,    -1,   199,    -1,   117,    -1,   159,    -1,   201,
      -1,   150,    -1,   136,    -1,    75,    -1,    76,    -1,   102,
      -1,   200,    -1,   151,    -1,   182,    -1,   196,    -1,   160,
      -1,   137,    -1,   131,    -1,   166,    -1,   148,    -1,   165,
      -1,    33,    -1,    40,    -1,    57,    -1,   113,    -1,    41,
      -1,    56,    -1,   216,    -1,    49,    -1,    60,    -1,    34,
      -1,    47,    -1,   273,    -1,   249,    -1,   282,    -1,   284,
      -1,   253,    -1,   267,    -1,   280,    -1,   272,    -1,   252,
      -1,   266,    -1,   281,    -1,   271,    -1,   265,    -1,   264,
      -1,   248,    -1,   247,    -1,   256,    -1,   257,    -1,   286,
      -1,   276,    -1,   275,    -1,   270,    -1,   268,    -1,   269,
      -1,   229,    -1,   235,    -1,   232,    -1,   226,    -1,   219,
      -1,   218,    -1,   220,    -1,   237,    -1,   227,    -1,   228,
      -1,   234,    -1,   224,    -1,   233,    -1,    65,    -1,    63,
      -1,    74,    -1,   169,    -1,   202,    -1,   242,    -1,   240,
      -1,   241,    -1,   238,    -1,   239,    -1,   244,    -1,   245,
      -1,   246,    -1,    64,    -1,   295,    -1,   293,    -1,   294,
      -1,   299,    -1,   300,    -1,   301,    -1,   296,    -1,   297,
      -1,   298,    -1,    79,    -1,    80,    -1,    81,    -1,    82,
      -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,
      -1,    88,    -1,    89,    -1,   287,    -1,   288,    -1,   289,
      -1,   290,    -1,   291,    -1,   292,    -1,   303,    -1,   304,
      -1,   305,    -1,   306,    -1,   307,    -1,   308,    -1,   309,
      -1,    90,    -1,   105,    -1,   114,    -1,   172,    -1,   180,
      -1,   189,    -1,   138,    -1,    91,    -1,   115,    -1,   139,
      -1,   181,    -1,   314,    -1,   315,    -1,   316,    -1,   319,
      -1,   318,    -1,   317,    -1,   320,    -1,    25,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    11,    15,    17,    20,    23,
      25,    28,    30,    33,    38,    45,    49,    53,    59,    61,
      65,    69,    75,    81,    83,    87,    91,    97,   104,   106,
     110,   114,   116,   118,   120,   122,   124,   126,   128,   130,
     132,   134,   136,   138,   140,   144,   148,   153,   157,   161,
     165,   169,   173,   179,   185,   191,   197,   203,   209,   211,
     213,   217,   221,   226,   232,   239,   241,   245,   249,   253,
     257,   264,   270,   279,   285,   291,   297,   299,   303,   307,
     309,   311,   313,   315,   317,   319,   321,   323,   328,   333,
     335,   338,   342,   344,   346,   348,   350,   352,   354,   356,
     358,   360,   362,   367,   371,   376,   380,   382,   384,   386,
     389,   392,   397,   401,   407,   411,   416,   421,   427,   429,
     432,   434,   439,   441,   446,   448,   452,   455,   459,   461,
     463,   468,   473,   479,   485,   488,   492,   497,   503,   505,
     509,   512,   516,   520,   526,   531,   538,   540,   543,   545,
     548,   557,   567,   569,   573,   575,   578,   581,   585,   597,
     612,   626,   649,   651,   653,   655,   656,   658,   660,   661,
     663,   666,   668,   671,   676,   678,   680,   682,   684,   686,
     688,   690,   692,   694,   696,   698,   700,   704,   707,   711,
     715,   718,   722,   725,   729,   732,   736,   741,   747,   753,
     756,   761,   767,   771,   775,   778,   781,   790,   794,   796,
     799,   803,   805,   809,   813,   815,   817,   819,   821,   823,
     825,   827,   829,   831,   833,   835,   837,   839,   841,   843,
     845,   847,   849,   852,   855,   858,   861,   863,   865,   868,
     873,   877,   883,   888,   892,   894,   896,   898,   900,   902,
     904,   906,   908,   910,   913,   917,   921,   924,   926,   931,
     935,   939,   945,   950,   957,   962,   969,   975,   983,   988,
     994,  1000,  1007,  1011,  1015,  1018,  1020,  1024,  1029,  1035,
    1039,  1046,  1051,  1057,  1059,  1062,  1066,  1068,  1071,  1073,
    1080,  1084,  1088,  1091,  1095,  1097,  1101,  1104,  1109,  1115,
    1122,  1128,  1132,  1135,  1139,  1144,  1146,  1150,  1152,  1155,
    1157,  1159,  1161,  1164,  1167,  1170,  1174,  1176,  1178,  1181,
    1184,  1187,  1193,  1199,  1201,  1206,  1210,  1215,  1224,  1226,
    1229,  1233,  1236,  1240,  1249,  1251,  1254,  1258,  1267,  1278,
    1287,  1298,  1300,  1303,  1308,  1316,  1318,  1321,  1326,  1334,
    1336,  1340,  1349,  1351,  1355,  1357,  1361,  1363,  1367,  1371,
    1375,  1379,  1380,  1385,  1389,  1393,  1397,  1399,  1405,  1407,
    1411,  1412,  1414,  1416,  1420,  1422,  1426,  1430,  1432,  1436,
    1440,  1444,  1448,  1450,  1454,  1458,  1460,  1464,  1468,  1470,
    1475,  1477,  1482,  1484,  1489,  1491,  1496,  1498,  1501,  1503,
    1506,  1508,  1510,  1513,  1516,  1518,  1520,  1522,  1524,  1528,
    1530,  1532,  1534,  1536,  1538,  1540,  1542,  1544,  1546,  1551,
    1557,  1563,  1570,  1574,  1579,  1581,  1584,  1588,  1591,  1594,
    1596,  1599,  1602,  1604,  1606,  1608,  1612,  1616,  1618,  1620,
    1622,  1625,  1627,  1630,  1633,  1635,  1638,  1641,  1644,  1647,
    1650,  1653,  1656,  1658,  1661,  1664,  1666,  1669,  1672,  1675,
    1678,  1681,  1683,  1685,  1687,  1689,  1691,  1693,  1695,  1697,
    1699,  1702,  1706,  1711,  1713,  1716,  1720,  1722,  1724,  1726,
    1728,  1730,  1732,  1734,  1736,  1738,  1740,  1742,  1744,  1746,
    1748,  1750,  1752,  1754,  1756,  1758,  1761,  1764,  1768,  1770,
    1775,  1780,  1784,  1789,  1791,  1795,  1797,  1799,  1801,  1803,
    1805,  1810,  1816,  1825,  1835,  1845,  1856,  1858,  1861,  1863,
    1866,  1873,  1874,  1876,  1880,  1884,  1885,  1887,  1889,  1891,
    1894,  1897,  1898,  1900,  1902,  1904,  1907,  1910,  1912,  1914,
    1916,  1918,  1920,  1922,  1924,  1926,  1928,  1930,  1932,  1936,
    1940,  1943,  1947,  1951,  1954,  1956,  1958,  1960,  1962,  1964,
    1966,  1971,  1975,  1983,  1987,  1995,  2000,  2005,  2009,  2017,
    2020,  2022,  2025,  2029,  2031,  2033,  2035,  2037,  2039,  2043,
    2047,  2049,  2051,  2053,  2055,  2059,  2061,  2063,  2065,  2067,
    2069,  2071,  2073,  2075,  2077,  2079,  2081,  2085,  2089,  2094,
    2099,  2103,  2107,  2111,  2116,  2121,  2125,  2130,  2137,  2142,
    2149,  2154,  2158,  2163,  2170,  2177,  2182,  2189,  2196,  2201,
    2203,  2206,  2208,  2210,  2212,  2216,  2220,  2222,  2224,  2229,
    2235,  2242,  2246,  2250,  2254,  2258,  2264,  2272,  2280,  2286,
    2292,  2298,  2306,  2314,  2320,  2326,  2330,  2334,  2340,  2348,
    2354,  2362,  2364,  2369,  2373,  2379,  2381,  2384,  2388,  2392,
    2394,  2398,  2401,  2402,  2404,  2406,  2409,  2411,  2415,  2417,
    2421,  2423,  2428,  2430,  2433,  2437,  2438,  2440,  2441,  2443,
    2448,  2451,  2455,  2457,  2458,  2460,  2465,  2466,  2468,  2471,
    2473,  2477,  2478,  2480,  2483,  2486,  2488,  2489,  2491,  2492,
    2494,  2496,  2498,  2500,  2502,  2504,  2506,  2510,  2514,  2516,
    2518,  2520,  2523,  2527,  2529,  2531,  2533,  2535,  2537,  2539,
    2541,  2543,  2546,  2549,  2551,  2553,  2556,  2559,  2563,  2565,
    2568,  2571,  2577,  2580,  2582,  2584,  2585,  2588,  2590,  2594,
    2599,  2600,  2603,  2604,  2607,  2612,  2617,  2621,  2624,  2628,
    2630,  2634,  2635,  2637,  2639,  2642,  2645,  2648,  2651,  2653,
    2656,  2659,  2662,  2665,  2669,  2672,  2676,  2680,  2685,  2688,
    2691,  2693,  2695,  2699,  2702,  2706,  2709,  2713,  2716,  2720,
    2724,  2728,  2734,  2740,  2746,  2755,  2761,  2765,  2771,  2779,
    2781,  2783,  2785,  2789,  2793,  2797,  2799,  2801,  2803,  2805,
    2807,  2809,  2811,  2813,  2815,  2817,  2819,  2821,  2823,  2825,
    2827,  2829,  2831,  2833,  2835,  2837,  2839,  2841,  2843,  2845,
    2847,  2849,  2851,  2853,  2855,  2857,  2859,  2861,  2863,  2865,
    2867,  2869,  2871,  2873,  2875,  2877,  2879,  2881,  2883,  2885,
    2887,  2889,  2891,  2893,  2895,  2897,  2899,  2901,  2903,  2905,
    2907,  2909,  2911,  2913,  2915,  2917,  2919,  2921,  2923,  2925,
    2927,  2929,  2931,  2933,  2935,  2937,  2939,  2941,  2943,  2945,
    2947,  2949,  2951,  2953,  2955,  2957,  2959,  2961,  2963,  2965,
    2967,  2969,  2971,  2973,  2975,  2977,  2979,  2981,  2983,  2985,
    2987,  2989,  2991,  2993,  2995,  2997,  2999,  3001,  3003,  3005,
    3007,  3009,  3011,  3013,  3015,  3017,  3019,  3021,  3023,  3025,
    3027,  3029,  3031,  3033,  3035,  3037,  3039,  3041,  3043,  3045,
    3047,  3049,  3051,  3053,  3055,  3057,  3059,  3061,  3063,  3065,
    3067,  3069,  3071,  3073,  3075,  3077,  3079,  3081,  3083,  3085,
    3087,  3089,  3091,  3093,  3095,  3097,  3099,  3101,  3103,  3105,
    3107,  3109,  3111,  3113,  3115,  3117,  3119,  3121,  3123,  3125,
    3127,  3129,  3131,  3133,  3135,  3137,  3139,  3141,  3143,  3145,
    3147,  3149,  3151,  3153,  3155,  3157,  3159,  3161,  3163,  3165,
    3167,  3169,  3171,  3173,  3175,  3177,  3179,  3181,  3183,  3185,
    3187,  3189,  3191,  3193,  3195,  3197,  3199,  3201,  3203,  3205,
    3207,  3209,  3211,  3213,  3215,  3217,  3219,  3221,  3223,  3225,
    3227,  3229,  3231,  3233,  3235,  3237,  3239,  3241,  3243,  3245,
    3247
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1052,  1052,  1053,  1057,  1061,  1069,  1075,  1079,  1088,
    1094,  1102,  1108,  1119,  1124,  1132,  1139,  1146,  1155,  1162,
    1170,  1178,  1186,  1197,  1202,  1209,  1216,  1228,  1238,  1245,
    1252,  1264,  1265,  1266,  1267,  1268,  1273,  1274,  1275,  1276,
    1277,  1278,  1279,  1282,  1287,  1292,  1300,  1308,  1316,  1321,
    1329,  1334,  1342,  1347,  1355,  1360,  1365,  1370,  1378,  1380,
    1383,  1393,  1398,  1406,  1414,  1425,  1432,  1443,  1448,  1456,
    1463,  1470,  1479,  1492,  1500,  1507,  1517,  1524,  1531,  1542,
    1543,  1544,  1545,  1546,  1547,  1548,  1549,  1554,  1560,  1569,
    1576,  1586,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,
    1604,  1605,  1610,  1618,  1626,  1634,  1641,  1649,  1656,  1661,
    1669,  1677,  1691,  1705,  1722,  1727,  1735,  1743,  1754,  1759,
    1768,  1773,  1780,  1785,  1795,  1800,  1809,  1815,  1828,  1833,
    1841,  1852,  1867,  1879,  1894,  1899,  1904,  1909,  1917,  1924,
    1935,  1940,  1950,  1959,  1968,  1977,  1989,  1993,  1999,  2003,
    2013,  2023,  2036,  2042,  2051,  2056,  2063,  2070,  2081,  2091,
    2101,  2111,  2129,  2149,  2153,  2158,  2165,  2169,  2174,  2181,
    2186,  2198,  2205,  2215,  2230,  2231,  2232,  2233,  2234,  2235,
    2236,  2238,  2239,  2240,  2241,  2242,  2247,  2252,  2260,  2277,
    2285,  2293,  2300,  2307,  2318,  2327,  2336,  2345,  2358,  2366,
    2374,  2382,  2397,  2402,  2410,  2424,  2441,  2466,  2474,  2481,
    2492,  2502,  2507,  2520,  2537,  2538,  2539,  2540,  2541,  2542,
    2547,  2548,  2551,  2552,  2553,  2554,  2555,  2558,  2559,  2560,
    2561,  2562,  2567,  2581,  2589,  2594,  2602,  2607,  2612,  2620,
    2629,  2641,  2651,  2664,  2672,  2673,  2674,  2679,  2680,  2681,
    2682,  2683,  2688,  2695,  2705,  2711,  2720,  2730,  2737,  2745,
    2757,  2767,  2777,  2787,  2797,  2807,  2817,  2827,  2838,  2847,
    2857,  2867,  2883,  2892,  2901,  2909,  2915,  2927,  2935,  2945,
    2953,  2965,  2971,  2982,  2984,  2988,  2996,  3000,  3005,  3009,
    3013,  3017,  3027,  3035,  3042,  3048,  3058,  3062,  3066,  3074,
    3082,  3090,  3102,  3110,  3116,  3126,  3132,  3142,  3146,  3156,
    3162,  3168,  3174,  3183,  3192,  3201,  3214,  3218,  3226,  3232,
    3242,  3250,  3259,  3272,  3279,  3291,  3295,  3307,  3314,  3320,
    3329,  3336,  3342,  3353,  3360,  3366,  3375,  3384,  3391,  3402,
    3409,  3421,  3427,  3439,  3445,  3456,  3462,  3473,  3479,  3490,
    3496,  3507,  3516,  3520,  3529,  3533,  3541,  3545,  3555,  3562,
    3571,  3581,  3580,  3594,  3603,  3612,  3625,  3629,  3641,  3645,
    3653,  3656,  3663,  3667,  3676,  3680,  3684,  3692,  3696,  3702,
    3708,  3714,  3724,  3728,  3732,  3740,  3744,  3750,  3760,  3764,
    3774,  3778,  3788,  3792,  3802,  3806,  3816,  3820,  3829,  3833,
    3841,  3845,  3849,  3853,  3863,  3867,  3871,  3878,  3883,  3891,
    3895,  3899,  3903,  3907,  3911,  3919,  3923,  3927,  3935,  3939,
    3943,  3947,  3958,  3964,  3974,  3980,  3990,  3994,  3998,  4036,
    4040,  4050,  4060,  4073,  4082,  4092,  4096,  4105,  4109,  4118,
    4124,  4132,  4138,  4150,  4156,  4166,  4170,  4174,  4178,  4182,
    4188,  4194,  4202,  4206,  4214,  4218,  4229,  4233,  4237,  4243,
    4247,  4261,  4265,  4273,  4277,  4287,  4291,  4295,  4299,  4308,
    4312,  4316,  4320,  4328,  4334,  4344,  4352,  4356,  4360,  4364,
    4368,  4372,  4376,  4380,  4384,  4388,  4393,  4397,  4401,  4405,
    4413,  4417,  4425,  4432,  4439,  4450,  4458,  4462,  4470,  4478,
    4486,  4540,  4544,  4557,  4563,  4573,  4577,  4585,  4589,  4593,
    4601,  4611,  4621,  4638,  4655,  4672,  4694,  4700,  4711,  4717,
    4728,  4739,  4741,  4745,  4750,  4760,  4763,  4770,  4776,  4782,
    4790,  4803,  4806,  4813,  4819,  4825,  4832,  4843,  4847,  4857,
    4861,  4871,  4875,  4879,  4884,  4893,  4899,  4905,  4911,  4919,
    4924,  4932,  4937,  4945,  4953,  4958,  4963,  4968,  4973,  4978,
    4987,  4995,  4999,  5016,  5020,  5028,  5036,  5044,  5048,  5056,
    5064,  5068,  5072,  5107,  5113,  5119,  5129,  5133,  5137,  5141,
    5145,  5149,  5153,  5160,  5166,  5176,  5184,  5192,  5196,  5200,
    5204,  5208,  5212,  5216,  5220,  5224,  5232,  5240,  5244,  5248,
    5258,  5266,  5274,  5278,  5282,  5290,  5294,  5300,  5306,  5310,
    5320,  5328,  5332,  5338,  5347,  5356,  5362,  5368,  5378,  5395,
    5402,  5417,  5453,  5457,  5465,  5473,  5485,  5489,  5497,  5505,
    5509,  5520,  5537,  5543,  5549,  5559,  5563,  5569,  5575,  5579,
    5585,  5589,  5595,  5601,  5608,  5618,  5623,  5631,  5637,  5647,
    5669,  5678,  5684,  5697,  5711,  5718,  5724,  5734,  5743,  5751,
    5757,  5775,  5783,  5787,  5794,  5799,  5807,  5811,  5818,  5822,
    5829,  5833,  5840,  5844,  5853,  5866,  5869,  5877,  5880,  5888,
    5896,  5904,  5908,  5916,  5919,  5927,  5939,  5942,  5950,  5962,
    5968,  5978,  5981,  5989,  5993,  5997,  6005,  6008,  6016,  6019,
    6027,  6031,  6035,  6039,  6043,  6051,  6059,  6071,  6083,  6087,
    6091,  6099,  6105,  6115,  6119,  6123,  6127,  6131,  6135,  6139,
    6143,  6151,  6155,  6159,  6163,  6171,  6177,  6187,  6197,  6201,
    6209,  6219,  6230,  6237,  6241,  6249,  6252,  6259,  6264,  6273,
    6283,  6286,  6293,  6297,  6305,  6314,  6321,  6331,  6335,  6342,
    6348,  6358,  6361,  6368,  6373,  6385,  6393,  6405,  6413,  6417,
    6425,  6429,  6433,  6441,  6449,  6453,  6457,  6461,  6469,  6477,
    6489,  6493,  6501,  6515,  6519,  6526,  6531,  6539,  6544,  6553,
    6561,  6567,  6577,  6583,  6593,  6600,  6607,  6632,  6660,  6688,
    6692,  6696,  6703,  6710,  6717,  6729,  6733,  6734,  6747,  6748,
    6749,  6750,  6751,  6752,  6753,  6754,  6755,  6756,  6757,  6758,
    6759,  6760,  6761,  6762,  6766,  6767,  6768,  6769,  6770,  6771,
    6772,  6773,  6774,  6775,  6776,  6777,  6778,  6779,  6780,  6781,
    6782,  6783,  6784,  6785,  6786,  6787,  6788,  6789,  6790,  6791,
    6792,  6793,  6794,  6795,  6796,  6797,  6798,  6799,  6800,  6801,
    6802,  6803,  6804,  6805,  6806,  6807,  6808,  6809,  6810,  6811,
    6812,  6813,  6814,  6815,  6816,  6817,  6818,  6819,  6820,  6821,
    6822,  6823,  6824,  6825,  6826,  6827,  6828,  6829,  6830,  6831,
    6832,  6833,  6834,  6835,  6836,  6837,  6838,  6839,  6840,  6841,
    6842,  6843,  6844,  6845,  6846,  6847,  6848,  6849,  6850,  6851,
    6852,  6853,  6854,  6855,  6856,  6857,  6858,  6859,  6860,  6861,
    6862,  6863,  6864,  6865,  6866,  6867,  6868,  6869,  6870,  6871,
    6872,  6873,  6874,  6875,  6876,  6877,  6878,  6879,  6880,  6881,
    6882,  6883,  6884,  6885,  6886,  6887,  6888,  6889,  6890,  6891,
    6892,  6893,  6894,  6895,  6896,  6897,  6898,  6899,  6900,  6901,
    6902,  6903,  6904,  6905,  6906,  6907,  6908,  6909,  6910,  6911,
    6912,  6913,  6914,  6915,  6916,  6917,  6918,  6919,  6920,  6921,
    6922,  6923,  6924,  6925,  6926,  6927,  6928,  6929,  6930,  6931,
    6932,  6933,  6934,  6935,  6936,  6937,  6938,  6939,  6940,  6941,
    6942,  6943,  6944,  6945,  6946,  6947,  6948,  6949,  6950,  6951,
    6952,  6953,  6954,  6955,  6956,  6957,  6958,  6959,  6960,  6961,
    6962,  6963,  6964,  6965,  6966,  6967,  6968,  6969,  6970,  6971,
    6976
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 17063;
  const int xquery_parser::yynnts_ = 324;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 608;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 334;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 588;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 17660 "/home/markos/zorba/repo/union-sequence-types/build-opt/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6980 "/home/markos/zorba/repo/union-sequence-types/src/compiler/parser/xquery_parser.y"


namespace zorba {

namespace parser {

const char *the_tumbling = "tumbling", *the_sliding = "sliding",
  *the_start = "start", *the_end = "end", *the_only_end = "only end",
  *the_declare = "declare", *the_create = "create";

} // namespace parser

/*
 *  The error member function registers the errors to the driver.
 */
void xquery_parser::error(zorba::xquery_parser::location_type const& loc, string const& msg)
{
  if (driver.parserError != NULL)
  {
    driver.set_expr(new ParseErrorNode(driver.parserError->loc, driver.parserError->err_code, driver.parserError->msg));
  }
  else
  {
    ParseErrorNode* prevErr = dynamic_cast<ParseErrorNode*>(driver.get_expr());

    if (prevErr != NULL)
    {
      // Error message heuristics: if the current error message has the "(missing comma "," between expressions?)" text,
      // and the old message has a "','" text, then replace the old message with the new one. Unfortunately this 
      // makes the parser error messages harder to internationalize.
      if (msg.find("(missing comma \",\" between expressions?)") != string::npos
          &&
          prevErr->msg.find(zstring("\",\"")) == zstring::npos)
        return;
    }

    // Replace the first occurrence of "unexpected "'QName'"" with "unexpected qualified name %actual_qname%"
    string message = msg;
    int pos;
    std::string unexpected_qname = "unexpected \"'QName'\"";
    if ((pos = message.find(unexpected_qname)) != -1)
      message = message.substr(0, pos) + "unexpected qualified name \"" + driver.symtab.get_last_qname() + "\"" + message.substr(pos+unexpected_qname.length());

    // remove the double quoting "''" from every token description
    while ((pos = message.find("\"'")) != -1 || (pos = message.find("'\"")) != -1)
      message.replace(pos, 2, "\"");
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), err::XPST0003, message));
  }
}

} // namespace zorba

