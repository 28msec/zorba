
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
#line 87 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"


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
#line 79 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 902 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 1018 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 109 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 178 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
#line 900 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 285 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 124: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 899 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 294 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 149: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 898 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 303 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 528 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 537 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2697 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2706 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2715 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2724 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2733 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2742 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2751 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2760 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 649: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2769 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 650: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2778 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 651: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2787 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
#line 140 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2872 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1036 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1045 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1054 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1060 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1068 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1074 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1085 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1090 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1098 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1105 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1112 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1121 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1128 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1136 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1144 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1152 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1163 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1168 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1175 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1182 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1194 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1204 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1211 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1218 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      // error
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1253 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1258 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1266 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1274 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1282 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1287 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1295 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1300 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1308 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1313 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1321 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1328 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1335 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1342 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1357 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1367 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1372 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1380 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1388 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1399 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1406 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1417 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1422 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1430 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1437 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1444 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1453 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1466 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1474 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1481 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1491 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1498 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1505 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1528 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1534 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1543 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1550 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1560 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1569 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1570 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1571 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1572 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1573 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1574 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1575 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1576 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1577 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1578 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1584 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1592 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1600 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1608 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1615 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1623 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1630 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1635 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1643 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1651 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (2)].varnametype)));

      (yyval.node) = new VarDecl(LOC((yyloc)),
                       nt->theName,
                       nt->theType,
                       (yysemantic_stack_[(4) - (4)].expr),
                       nt->get_annotations(),
                       true,    // global
                       false);  // not external

      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1666 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (2)].varnametype)));

      (yyval.node) = new VarDecl(LOC((yyloc)),
                       nt->theName,
                       nt->theType,
                       NULL,   // no init expr
                       nt->get_annotations(),
                       true,   // global
                       true);  // external

      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1681 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (2)].varnametype)));

      (yyval.node) = new VarDecl(LOC((yyloc)),
                       nt->theName,
                       nt->theType,
                       (yysemantic_stack_[(5) - (5)].expr),     // init expr
                       nt->get_annotations(),
                       true,   // global
                       true);  // external

      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1699 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1704 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1712 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1720 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1731 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1736 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1745 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1750 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1757 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1762 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1772 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1777 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1786 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1792 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1805 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1810 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1818 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 127:

/* Line 678 of lalr1.cc  */
#line 1829 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 128:

/* Line 678 of lalr1.cc  */
#line 1844 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 129:

/* Line 678 of lalr1.cc  */
#line 1856 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 130:

/* Line 678 of lalr1.cc  */
#line 1871 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1876 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1881 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1886 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1894 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1901 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1912 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1927 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1934 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1941 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1948 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1958 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1962 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1972 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1980 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1991 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1997 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 2006 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 2011 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 2018 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 2025 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 2037 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 2047 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 2057 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 2068 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 156:

/* Line 678 of lalr1.cc  */
#line 2084 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ((yysemantic_stack_[(1) - (1)].expr) == NULL)
      {
        error((yylocation_stack_[(1) - (1)]), "syntax error, unexpected end of file, the query should not be empty");
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

  case 157:

/* Line 678 of lalr1.cc  */
#line 2104 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2108 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2112 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2120 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2124 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2128 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2136 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2141 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2153 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2160 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2189 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2194 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2202 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 182:

/* Line 678 of lalr1.cc  */
#line 2219 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2227 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2235 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2242 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2249 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2259 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                NULL,  // no type
                                NULL,  // no init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2271 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)), // type
                                NULL,  // no init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external

      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 2284 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                NULL,  // no type
                                (yysemantic_stack_[(4) - (4)].expr),    // init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 2296 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)), // type
                                (yysemantic_stack_[(5) - (5)].expr),    // init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 2312 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 2320 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 2328 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2336 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 195:

/* Line 678 of lalr1.cc  */
#line 2351 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2356 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2364 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 198:

/* Line 678 of lalr1.cc  */
#line 2378 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 199:

/* Line 678 of lalr1.cc  */
#line 2395 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 200:

/* Line 678 of lalr1.cc  */
#line 2420 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2428 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2435 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2446 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2456 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2461 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 224:

/* Line 678 of lalr1.cc  */
#line 2506 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 225:

/* Line 678 of lalr1.cc  */
#line 2520 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2528 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2533 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2541 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2546 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2551 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2559 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2568 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2580 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 234:

/* Line 678 of lalr1.cc  */
#line 2590 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2603 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2627 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2634 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2644 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2652 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2659 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2669 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 250:

/* Line 678 of lalr1.cc  */
#line 2679 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 251:

/* Line 678 of lalr1.cc  */
#line 2689 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 252:

/* Line 678 of lalr1.cc  */
#line 2699 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 253:

/* Line 678 of lalr1.cc  */
#line 2709 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 254:

/* Line 678 of lalr1.cc  */
#line 2719 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 255:

/* Line 678 of lalr1.cc  */
#line 2729 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 256:

/* Line 678 of lalr1.cc  */
#line 2739 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 257:

/* Line 678 of lalr1.cc  */
#line 2750 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2759 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 259:

/* Line 678 of lalr1.cc  */
#line 2769 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 260:

/* Line 678 of lalr1.cc  */
#line 2779 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 261:

/* Line 678 of lalr1.cc  */
#line 2795 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2804 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2813 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2821 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2827 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2839 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2847 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2857 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2865 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2877 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2883 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2896 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2900 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2908 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2912 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2921 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2925 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2929 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2939 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2947 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2954 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2960 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2971 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2975 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2984 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2992 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2998 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 3008 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 3014 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 3024 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3028 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3038 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3044 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3050 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3056 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3065 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3074 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3083 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3096 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3100 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3108 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3114 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3124 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3132 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3141 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3154 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3161 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3173 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3177 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3189 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3196 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3202 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3211 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3218 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3224 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3235 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3242 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3248 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3257 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3266 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3273 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3284 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3291 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3303 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3309 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3321 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3327 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3338 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3344 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3355 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3361 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3372 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3381 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3385 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3394 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3398 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3406 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3410 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 341:

/* Line 678 of lalr1.cc  */
#line 3420 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3427 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3436 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3445 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3450 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3459 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3468 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3477 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3490 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3494 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3506 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3510 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3517 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3521 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3528 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3532 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3541 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3545 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3549 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3557 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3561 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3567 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3573 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3579 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3589 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3593 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3597 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3605 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3609 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3615 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3625 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3629 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3639 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3643 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3653 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3657 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3667 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3671 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3681 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3685 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3693 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3697 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3701 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3705 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3715 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3719 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3723 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3731 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3735 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3739 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3743 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3747 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3751 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3759 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3763 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3767 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3775 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3779 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3783 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3787 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3798 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3804 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3814 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3820 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3830 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3834 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3838 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3876 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3880 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3890 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3900 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3913 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3922 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 414:

/* Line 678 of lalr1.cc  */
#line 3932 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3936 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3945 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3949 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3958 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3964 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3972 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3978 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3990 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3996 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 4006 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 4010 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 4014 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4018 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4022 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4028 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4034 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4042 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4046 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4054 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4058 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4069 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4073 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4077 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4083 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4087 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4101 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4105 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4113 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4117 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4127 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4131 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4135 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4139 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4148 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4152 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4156 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4160 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4168 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4174 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4184 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4192 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4196 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4200 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4204 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4208 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4212 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4216 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4220 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4224 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4228 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4233 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4237 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4241 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4245 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4253 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4257 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4265 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4272 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4279 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4290 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4298 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4302 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4310 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4318 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4326 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4380 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4384 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4397 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4403 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4413 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4417 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4425 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4429 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4433 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4441 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 490:

/* Line 678 of lalr1.cc  */
#line 4451 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 491:

/* Line 678 of lalr1.cc  */
#line 4461 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
                NULL,
                NULL
            );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4471 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                NULL,
                dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node))
            );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4481 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
                NULL
            );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4491 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)),
                dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node))
            );
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4506 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4512 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4523 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4529 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4540 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4557 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4562 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4571 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4575 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4582 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4588 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4594 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4602 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4614 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4618 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4625 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4631 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4637 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4644 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4655 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4659 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4669 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4673 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4683 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4687 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4691 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4696 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4705 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4711 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4717 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4723 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4731 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4736 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4744 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4749 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4757 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4765 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4770 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4775 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4780 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4785 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4790 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4799 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4807 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4811 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4828 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4832 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4840 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4848 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4856 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4860 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4868 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4874 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4884 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4892 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4896 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4900 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4935 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4941 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4947 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4957 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4961 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4965 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4969 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4973 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4977 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4981 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4988 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 4994 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5004 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5012 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5016 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5020 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5024 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5028 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5032 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5036 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5040 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5044 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5052 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5060 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5064 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5068 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5078 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5086 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5094 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5098 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5102 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5110 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5114 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5120 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5126 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5130 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5140 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5148 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5152 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5158 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5167 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5176 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5182 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5188 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5198 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5215 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5222 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5237 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5273 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5277 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5285 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5293 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5305 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5309 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5317 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5325 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5329 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5340 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5357 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5363 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5369 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5379 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5383 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5389 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5395 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5399 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5405 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5409 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5415 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5421 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5428 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5438 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5443 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5451 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5457 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5467 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5489 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5504 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5517 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5531 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5538 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5544 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5554 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5563 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5571 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5577 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5595 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5603 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5607 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5614 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5619 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5627 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5631 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5638 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5642 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5649 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5653 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5660 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5664 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5673 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5685 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5689 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5696 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5700 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5708 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5716 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5724 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5728 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5735 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5739 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5747 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5758 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5762 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5770 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5782 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5788 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5797 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5801 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5809 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5813 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5817 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5824 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5828 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5835 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5839 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5847 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5851 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5855 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5859 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5863 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5871 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5879 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5891 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5903 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5911 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5919 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5925 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5935 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5939 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5943 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5947 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5951 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5955 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5959 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5963 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5971 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5975 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5979 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5983 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5991 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5997 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6007 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6017 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6021 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6029 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 711:

/* Line 678 of lalr1.cc  */
#line 6039 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 712:

/* Line 678 of lalr1.cc  */
#line 6050 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6057 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6061 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6068 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6072 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6079 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6084 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6093 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6102 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6106 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6113 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6117 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6125 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6134 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6141 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6151 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6155 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6162 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6168 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6177 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6181 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6188 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6193 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6205 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6213 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6225 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6233 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6237 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6245 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6249 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6253 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6261 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6269 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6273 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6277 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6281 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6289 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6297 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6309 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6313 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6321 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6335 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSON_ObjectConstructor( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6342 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_PairConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6346 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          JSON_PairList* jpl;
          if (dynamic_cast<JSON_PairConstructor*>((yysemantic_stack_[(5) - (1)].node)) != NULL)
            jpl = new JSON_PairList( LOC((yyloc)) );
          else
            jpl = dynamic_cast<JSON_PairList*>((yysemantic_stack_[(5) - (1)].node));
          jpl->push_back(new JSON_PairConstructor( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)) );
          (yyval.node) = jpl;
        }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6359 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSON_ArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6363 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSON_ArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6370 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSON_ObjectConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6375 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSON_ObjectConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6383 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSON_ObjectConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6388 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSON_ObjectConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6396 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in
        }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6400 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in
        }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6407 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in
        }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6414 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in
        }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6421 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in
        }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6428 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in
        }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6435 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6439 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6443 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6450 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6457 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6464 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6481 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 778:

/* Line 678 of lalr1.cc  */
#line 6494 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6495 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6496 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6497 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6498 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6499 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6500 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6501 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6502 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6503 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6504 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6505 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6506 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6507 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6508 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6513 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6514 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6515 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6516 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6517 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6518 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6519 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6520 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6521 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6522 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6523 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6524 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6525 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6526 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6527 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6528 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6529 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6530 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6531 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6532 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6533 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6534 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6535 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6536 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6537 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6538 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6539 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6540 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6541 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6542 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6543 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6544 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6545 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6546 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6547 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6548 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6549 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6550 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6551 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6552 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6553 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6554 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6555 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6556 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6557 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6558 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6559 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6560 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6561 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6562 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6563 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6564 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6565 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6566 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6567 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6568 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6569 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6570 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6571 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6572 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6573 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6574 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6575 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6576 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6577 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6578 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6579 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6580 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6581 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6582 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6583 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6584 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6585 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6586 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6587 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6588 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6589 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6590 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6591 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6592 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6593 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6594 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6595 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6596 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6597 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6598 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6599 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6600 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6601 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6602 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6603 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6604 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6605 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6606 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6607 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6608 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6609 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6610 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6611 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6612 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6613 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6614 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6615 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6616 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6617 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6618 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6619 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6620 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6621 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6622 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6623 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6624 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6625 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6626 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6627 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6628 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6629 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6630 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6631 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6632 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6633 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6634 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6635 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6636 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6637 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6638 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6639 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6640 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6641 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6642 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6643 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6644 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6645 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6646 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6647 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6648 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6649 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6650 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6651 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6652 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6653 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6654 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6655 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6656 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6657 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6658 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6659 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6660 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6661 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6662 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6663 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6664 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6665 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6666 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6667 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6668 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6669 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6670 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6671 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6672 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6673 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6674 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6675 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6676 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6677 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6678 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6679 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6680 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6681 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 963:

/* Line 678 of lalr1.cc  */
#line 6682 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 964:

/* Line 678 of lalr1.cc  */
#line 6683 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 965:

/* Line 678 of lalr1.cc  */
#line 6684 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 966:

/* Line 678 of lalr1.cc  */
#line 6685 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 967:

/* Line 678 of lalr1.cc  */
#line 6686 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 968:

/* Line 678 of lalr1.cc  */
#line 6687 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 969:

/* Line 678 of lalr1.cc  */
#line 6688 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 970:

/* Line 678 of lalr1.cc  */
#line 6689 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 971:

/* Line 678 of lalr1.cc  */
#line 6690 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 972:

/* Line 678 of lalr1.cc  */
#line 6691 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 973:

/* Line 678 of lalr1.cc  */
#line 6692 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 974:

/* Line 678 of lalr1.cc  */
#line 6693 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 975:

/* Line 678 of lalr1.cc  */
#line 6694 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 976:

/* Line 678 of lalr1.cc  */
#line 6695 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 977:

/* Line 678 of lalr1.cc  */
#line 6696 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 978:

/* Line 678 of lalr1.cc  */
#line 6697 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 979:

/* Line 678 of lalr1.cc  */
#line 6698 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 980:

/* Line 678 of lalr1.cc  */
#line 6699 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 981:

/* Line 678 of lalr1.cc  */
#line 6700 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 982:

/* Line 678 of lalr1.cc  */
#line 6701 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 983:

/* Line 678 of lalr1.cc  */
#line 6702 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 984:

/* Line 678 of lalr1.cc  */
#line 6703 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 985:

/* Line 678 of lalr1.cc  */
#line 6704 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 986:

/* Line 678 of lalr1.cc  */
#line 6705 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 987:

/* Line 678 of lalr1.cc  */
#line 6706 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 988:

/* Line 678 of lalr1.cc  */
#line 6707 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 989:

/* Line 678 of lalr1.cc  */
#line 6708 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 990:

/* Line 678 of lalr1.cc  */
#line 6709 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 991:

/* Line 678 of lalr1.cc  */
#line 6710 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 992:

/* Line 678 of lalr1.cc  */
#line 6711 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 993:

/* Line 678 of lalr1.cc  */
#line 6712 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 994:

/* Line 678 of lalr1.cc  */
#line 6713 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 995:

/* Line 678 of lalr1.cc  */
#line 6714 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 996:

/* Line 678 of lalr1.cc  */
#line 6715 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 997:

/* Line 678 of lalr1.cc  */
#line 6716 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 998:

/* Line 678 of lalr1.cc  */
#line 6721 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 11912 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1435;
  const short int
  xquery_parser::yypact_[] =
  {
      2939, -1435, -1435, -1435,  4485,  4485,  4485, -1435, -1435,    76,
     226, -1435,    64,   -13, -1435, -1435, -1435,   728, -1435, -1435,
   -1435,    33,   251,   739,   516,   458,   491,   725, -1435,   -26,
   -1435, -1435, -1435, -1435, -1435, -1435,   753, -1435,   605,   648,
   -1435, -1435, -1435, -1435,   304, -1435,   755, -1435,   701,   721,
   -1435,    82, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435,   327,   333, -1435, -1435,
   -1435, -1435,    43, 10356, -1435, -1435, -1435,   764, -1435, -1435,
   -1435,   751, -1435,   768,   790, -1435, -1435, 14441, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435,   799, -1435, -1435,   801,
     814, -1435, -1435, -1435, -1435, -1435, -1435, -1435,  3249,  6339,
    6648, 14441, -1435, -1435, -1435, -1435, -1435, -1435, -1435,   779,
   -1435, -1435,   816, 11248, -1435, 11550,   825,   832, -1435, -1435,
   -1435,   838, -1435,  9738, -1435, -1435, -1435, -1435, -1435, -1435,
     781, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,    79,
     749, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,   -75,
     806,    -3, -1435,   -76,   164, -1435, -1435, -1435, -1435, -1435,
   -1435,   848, -1435,   746,   748,   756, -1435, -1435,   836,   840,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435,  6957,  7266, -1435,   681, -1435, -1435, -1435,
   -1435,  4794,   996, -1435,  5103, -1435, -1435,   394,    78, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435,    84, -1435, -1435, -1435, -1435, -1435, -1435,
     328, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,  4485,
   -1435, -1435, -1435, -1435,    30, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435,   891, -1435,   809, -1435, -1435, -1435,   165,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,   833,   909,
   -1435,   810,   754,   904,   536,   557,   653,   503, -1435,   954,
     807,   906,   903,  8502, -1435, -1435, -1435,   547, -1435, -1435,
   10047, -1435,   710, -1435,   854, 10356, -1435,   854, 10356, -1435,
   -1435, -1435,   775, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435,   865,   855, -1435, -1435, -1435, -1435,
   -1435,   834, -1435,  4485,   839,   841,   336,   336,   991,   632,
     633,   214, 14728, 14441,   439,   975, 14441,   872,   908,   147,
   11248,   694,   782, 14441, 14441,   726,    75,    48, -1435, -1435,
   -1435, 11248,  4485,   843,  4485,   112,  8811, 13293,   745,   757,
   14441,   913,    27,   879,  8811,  1033,   106,    71, 14441,   918,
     895,   931, -1435,  8811, 10952, 14441, 14441, 14441,  4485,   852,
    8811,  8811, 14441,  4485,   888,   889, -1435, -1435, -1435,  8811,
   13580,   890, -1435,   892, -1435, -1435, -1435, -1435,   896, -1435,
     897, -1435, -1435, -1435, -1435, -1435,   898, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, 14441, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,   902, 14441,
   -1435, -1435, -1435,   867,  3558,   928,   224,   899,   900,   901,
   14441,  4485, -1435,   907,    57, -1435,   176, -1435,   145,  1024,
    8811, -1435, -1435,    74, -1435, -1435, -1435,  1045, -1435, -1435,
   -1435, -1435,  8811,   850, -1435,  1035,  8811,  8811, 11849,   878,
    8811,  8811,  8811,  8811, 11849,  8811,   837,   844, 14441,   876,
     880,  8811,  8811,  3249,   824, -1435,   -40, -1435,   -52,  8811,
   -1435, -1435, -1435, -1435,    64,   725,   117,   123,  1066,  5412,
    5412,  5721,  5721,   751, -1435, -1435,   891,   751, -1435,  8811,
   -1435,   956,   516,   -26,   910,   905,   912,  4485,  8811, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435,  9120,  9120,  9120,
   -1435,  9120,  9120, -1435,  9120, -1435,  9120, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435,  9120,  9120,  1006,  9120,  9120,  9120,
    9120,  9120,  9120,  9120,  9120,  9120,  9120,  9120,  9120,   847,
     985,   989,   990, -1435, -1435, -1435,  7575, -1435, -1435,  9738,
    9738,  8811,   854, -1435, -1435,   854, -1435,  7884,   854,   936,
    8193, -1435, -1435, -1435,   232, -1435,   260, -1435, -1435, -1435,
   -1435, -1435, -1435,   980,   981,   458,  1061, -1435, -1435, 14728,
     893,   494, 14441,   932,   933,   893,   991,   964,   962, -1435,
   -1435, -1435,   502,   856,  1001,   802, 14441,   957,  8811,   992,
   14441, 14441, -1435,   971,   923,  4485, -1435,   924,   892,   648,
   -1435,   925,   926,   249, -1435,   266,   270, -1435, -1435,  1002,
   -1435,    36, 14441,    34, 14441,  1017,   274, -1435,  4485, -1435,
     299, -1435, 11248,  1018,  1070, 11248,   991,  1020,    73, 14441,
    8811,   -26,   298,   930, -1435,   935,   937,   938,   126, -1435,
     307,   934, -1435,   313,   316,   966, -1435,   939,  4485,  4485,
     308, -1435,   319,   322,   456,  8811,   197, -1435, -1435,  8811,
    8811, -1435,  8811,  8811,  8811, -1435,  8811, -1435,  8811, -1435,
   14441,  1024, -1435,   302,   309, -1435, -1435, -1435,   331, -1435,
      38, -1435, -1435,   967,   973,   974,   976,   977,   972,   865,
   -1435,   131,   142,   911,  1037,   978,   914,   915,   916,    93,
   -1435,   993, -1435, -1435,   942,   323,  3867,   446, 10656,   824,
   -1435, -1435, -1435,   940,   394,   556,  1100,  1100, -1435, -1435,
     127, -1435, -1435,   128, -1435,    67, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, 14441,   970,  8811,  1023, -1435, -1435, -1435,
     909, -1435, -1435, -1435, -1435, -1435,  9120, -1435, -1435, -1435,
      42, -1435,   557,   557,   610,   653,   653,   653,   653,   503,
     503, -1435, -1435, 13867, 13867, 14441, 14441, -1435,   453, -1435,
   -1435,   204, -1435, -1435, -1435,   330, -1435, -1435,   338,   336,
   -1435, -1435,   560,   583,   525, -1435,   458, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435,   893, -1435,  1004,
   14154,  1000,  8811, -1435, -1435, -1435,  1050,   991,   991,   893,
   -1435,   608,   991,   667, 14441,   -80,   548,  1116, -1435, -1435,
     862,   529, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435,   502,   111,   927,   566,  8811, -1435, 14441,
    1054,   851,   991, -1435, -1435, -1435, -1435,   998, 14441, -1435,
   14441, -1435,  1034,  1027, 13867,  1038,  8811,   -28,  1008,    40,
     347,   917, -1435, -1435,   651,    34,  1050, 13867,  1039,  1065,
     979,   963,  1030,   991,  1005,  1032,  1071,   991,  8811,    29,
   -1435, -1435, -1435,  1013, -1435, -1435, -1435, -1435,  1051,  8811,
    8811,  1021, -1435,  1072,  1073,  4485, -1435,   987,   994,  1022,
   14441, -1435, 14441, -1435,  8811,  1040,   984,  8811, -1435,  1056,
     341,   349,   376,  1144, -1435,   437, -1435,   152, -1435, -1435,
    1151, -1435,  8811,   574,  8811,  8811,  8811,   695,  8811,  8811,
    8811,  8811,  8811,  8811,  8811,  8811, 11849,  1063,  8811,  8811,
   -1435,  6030,  1028,  1031,  1036,  1041,   809,   669,   944, -1435,
     321, -1435,  8811,   138,    46,    67,  5721,  5721,  5721,  1104,
   -1435,  8811,   692,  1079, -1435, 14441,  1082, -1435, -1435,  8811,
      42,   451,   553, -1435,   920,   430,   941,   943, -1435, -1435,
     782, -1435,   929,   530,  1044,  1049, 14154,  1052,  1055,  1057,
    1058,  1060, -1435,   480, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435,  1046, -1435, -1435,
   -1435,  8811, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435,   664, -1435,  1162,   513, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435,   921, -1435, -1435,  1164, -1435, -1435,
   -1435, -1435, -1435,   576,  1167, -1435,   696, -1435, -1435, -1435,
     890,   251,   896,   605,   897,   898,   806, -1435,   480,  9429,
     945,   919, -1435,  1050,   111,   995,  1007,  4485,  1014,  1042,
    1074,  1047,  1048, 14441,    58, -1435, 14441, -1435,  8811,  1075,
    8811,  1083,  8811,    16,  1076,  8811,  1078, -1435,  1099,  1101,
    8811, 14441,   772,  1143, -1435, -1435, -1435, -1435, -1435, -1435,
   13867, -1435,  4485,   991,  1119, -1435, -1435, -1435,   991,  1119,
   -1435,  8811,  1085,  4485, 14441, -1435, -1435,  8811,  8811,   627,
   -1435,   139,   722, -1435, 12432,   732, -1435,   747, -1435,  1059,
   -1435, -1435,  4485,  1053,  1062, -1435,  8811, -1435, -1435,  8811,
    1067,  1072,  1128, -1435,  1107, -1435,   545, -1435, -1435,  1225,
   -1435, -1435,  4485, 14441, -1435,   713, -1435, -1435, -1435,  1043,
    1064,  1009,  1012, -1435, -1435, -1435,  1015,  1016, -1435, -1435,
   -1435,  1140, -1435,  1068, -1435,  1010,  1089, 14441,  1077, -1435,
   -1435,  8811,  8811,  8811,  4176,  6030, 10656,   944, -1435, 10656,
   -1435, -1435,  1100,   296, -1435, -1435, -1435,  1079, -1435,   991,
   -1435,   812, -1435,   345,  1148, -1435,  8811,  1150,  1023,   461,
    1081, -1435,    42,  1011, -1435, -1435,   464, -1435,   604,    -8,
    1026,    42,   604,  9120, -1435,   332, -1435, -1435, -1435, -1435,
   -1435, -1435,    42,  1110,   988,   856,    -8, -1435, -1435,   997,
    1181, -1435, -1435, -1435, 12145,  1086,  1091,  1092,  1094,  1096,
    1097,  1098, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435,  1236,   391,  1237,   391,  1019,  1179,
   -1435,  1117, 14441,  1080, -1435, -1435,  9429, -1435,  1106, -1435,
   -1435, -1435, -1435, -1435, -1435,  8811,  1141, -1435, -1435,  8811,
   -1435,   447, -1435,  8811,  1146,  8811, -1435,  8811, 14441, 14441,
   -1435,   668, -1435,  8811, -1435,  1165,  1168,  1200,   991,  1119,
   -1435,  8811,  1113, -1435, -1435, -1435,  1115, -1435,   143,  8811,
    4485,  1118,   245, -1435, 14441,  1120, 12719,    24, -1435, 13006,
    1121, -1435, -1435,  1124, -1435, -1435, -1435, -1435,  8811,   752,
    1144, 14441,   736, -1435,  1125,  1144, 14441, -1435, -1435, -1435,
    8811,  8811,  8811,  8811,   999,  1208,  8811,  8811, -1435,  8811,
     383,   390,   398,   413, -1435, -1435, -1435, -1435, -1435,  1148,
   -1435, -1435, -1435,   991, -1435, -1435, -1435, -1435, -1435,  1126,
    9120, -1435, -1435, -1435, -1435, -1435,   387,  9120,  9120,   538,
   -1435,   941, -1435,   194, -1435,   943,    42,  1152, -1435, -1435,
    1087, -1435, -1435, -1435, -1435,  1209,  1129, -1435,   434, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435,   441,   441, -1435,
     391, -1435, -1435,   442, -1435,  1282,    -8,  1216,  1131,  9429,
     -11,  1084,  1149, -1435, -1435,  8811, -1435,  8811,  1166, -1435,
    8811, -1435, -1435, -1435,  1267, -1435, -1435,  6030,  8811,   991,
   -1435, -1435, -1435,  8811,  8811, -1435, -1435, -1435,  6030,  6030,
    1227,  4485, 14441,  1136, 14441,  8811, 14441,  1137,  6030, -1435,
     353,    47,  1144, 14441, -1435,  1130,  1144, -1435, -1435, -1435,
   -1435,  8811,  8811, -1435,  1147, -1435,  1133,  1072,  1073,  8811,
   -1435, -1435, -1435, -1435,   653,  9120,  9120,   610,   575, -1435,
   -1435, -1435, -1435, -1435, -1435,  8811, -1435, 13867, -1435, 13867,
    1233, -1435, -1435, -1435,  1299, -1435, -1435, -1435,  1090,  1224,
   -1435, -1435,  1228, -1435,    91, 14441,  1220,  1122, 14441,  9429,
   -1435, -1435,  8811, -1435,  1221, -1435, -1435,  1119, -1435, -1435,
   13867, -1435, -1435,  1246,  8811,  1155, -1435,  1248,  6030, -1435,
   14441,   409,   637, -1435,  1153,  1144, -1435,  1154, -1435, -1435,
    1123,  6030,   763,   483,   610,   610,  9120,   485, -1435, -1435,
   13867, -1435, -1435,  1216,  9429, -1435,  1148,  1069, 14441,  1235,
    1127,  1228, -1435, 14441,  1157, 13867,  4485, 13867,  1172, -1435,
   -1435,  1268,   526, -1435, -1435, -1435, -1435,  1177,   649, -1435,
   -1435, -1435,  1169, -1435,  8811,  1244, -1435,   610, -1435, -1435,
   -1435, -1435, -1435,  8811,  1088, 14441,  1249, -1435,  4485,  1182,
   -1435, -1435,  1185,  8811, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, 14441, -1435,  1103,  1093, 14441, -1435, -1435,  8811,
    6030,  1188,  1095,  8811,  1102,  6030,  9429, -1435,  9429, -1435,
    1183,  1105, 14441,  1158,  1259, 14441,  1108,  9429, -1435
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       159,   445,   446,   447,   162,   162,   162,   794,   998,   116,
     118,   601,   886,   895,   835,   799,   797,   779,   887,   890,
     842,   803,   780,   781,   834,   896,   783,   893,   864,   844,
     819,   839,   840,   891,   888,   838,   785,   894,   786,   787,
     935,   947,   934,   836,   855,   849,   788,   837,   790,   789,
     936,   873,   874,   841,   816,   957,   958,   959,   960,   961,
     962,   963,   964,   965,   966,   967,   981,   988,   863,   859,
     850,   830,   778,     0,   858,   866,   875,   982,   854,   471,
     831,   832,   889,   983,   989,   851,   868,     0,   477,   434,
     473,   861,   796,   852,   853,   882,   856,   872,   881,   987,
     990,   802,   843,   884,   472,   871,   877,   782,     0,     0,
       0,     0,   382,   869,   880,   885,   883,   862,   848,   937,
     846,   847,   984,     0,   381,     0,   985,   991,   878,   833,
     857,   986,   412,     0,   444,   879,   860,   867,   876,   870,
     938,   824,   829,   828,   827,   826,   825,   791,   845,     0,
     795,   892,   817,   926,   925,   927,   801,   800,   820,   932,
     784,   924,   929,   930,   921,   823,   865,   923,   933,   931,
     922,   821,   928,   942,   943,   940,   941,   939,   792,   944,
     945,   946,   912,   911,   898,   815,   808,   905,   901,   818,
     814,   913,   914,   804,   805,   798,   807,   910,   909,   906,
     902,   919,   920,   918,   908,   904,   897,   806,   917,   916,
     810,   812,   811,   903,   907,   899,   813,   900,   809,   915,
     968,   969,   970,   971,   972,   973,   949,   950,   948,   954,
     955,   956,   951,   952,   953,   822,   974,   975,   976,   977,
     978,   979,   980,     0,     0,   992,   993,   994,   996,   995,
     997,   159,     0,     2,   159,     5,     7,    19,     0,    24,
      27,    32,    33,    34,    35,    36,    37,    38,    28,    54,
      55,    29,    30,     0,    72,    75,    76,    31,    77,    78,
       0,   114,    79,    80,    81,    82,    14,   156,   157,   158,
     165,   167,   464,   168,     0,   169,   170,   171,   172,   173,
     174,   175,   178,   163,   204,   211,   206,   238,   244,     0,
     236,   237,   213,   207,   177,   208,   176,   209,   212,   335,
     337,   339,   349,   351,   355,   357,   360,   365,   368,   371,
     373,   375,   377,     0,   379,   385,   387,     0,   403,   386,
     408,   411,   413,   416,   418,     0,   423,   420,     0,   431,
     441,   443,   417,   448,   455,   469,   456,   457,   458,   461,
     462,   459,   460,   484,   486,   487,   488,   485,   533,   534,
     535,   536,   537,   538,   440,   575,   567,   574,   573,   572,
     569,   571,   568,   570,   470,   463,   602,   603,    39,   214,
     215,   217,   216,   218,   210,   465,   466,   467,   468,   220,
     219,   221,   222,   223,   442,   777,   793,   886,   895,   893,
     795,     0,   160,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,   124,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   263,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   436,   439,   426,     0,
       0,   779,   803,   781,   834,   896,   783,   844,   785,   855,
     788,   790,   789,   873,   981,   988,   778,   982,   832,   983,
     989,   856,   987,   990,   937,   984,   985,   991,   986,   938,
     932,   924,   930,   921,   821,   942,   943,   940,   792,   944,
     993,   432,   442,   777,   424,     0,   185,   425,   428,   779,
     780,   781,   785,   786,   787,   788,   778,   784,   474,     0,
     430,   429,   180,     0,     0,   204,     0,   783,   790,   789,
       0,   162,   756,   944,     0,   211,     0,   475,     0,   500,
       0,   435,   775,     0,   776,   406,   407,     0,   438,   437,
     427,   410,     0,     0,   529,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   758,     0,   760,     0,     0,
       3,     1,     6,     8,     0,     0,     0,     0,     0,   159,
     159,   159,   159,     0,   115,   166,   164,     0,   183,     0,
     192,     0,     0,     0,     0,     0,     0,     0,     0,   197,
     224,   243,   239,   245,   240,   242,   241,     0,     0,     0,
     396,     0,     0,   394,     0,   344,     0,   395,   388,   393,
     392,   391,   390,   389,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   384,   383,   380,     0,   404,   409,     0,
       0,     0,   419,   452,   422,   421,   433,     0,   449,     0,
       0,   540,   542,   546,     0,   120,     0,   774,    43,    40,
      41,    44,    45,     0,     0,     0,     0,    46,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   612,
     613,   614,     0,    99,   138,     0,     0,   108,     0,     0,
       0,     0,   123,     0,     0,     0,   581,     0,     0,     0,
     577,     0,     0,     0,   591,     0,     0,   226,   227,   246,
     247,     0,     0,     0,     0,   130,     0,   134,   162,   605,
       0,    56,     0,    65,     0,     0,     0,    57,     0,     0,
       0,     0,     0,     0,   582,     0,     0,     0,     0,   308,
       0,     0,   580,     0,     0,     0,   599,     0,     0,     0,
       0,   585,     0,     0,   187,     0,     0,   181,   179,     0,
       0,   753,     0,     0,     0,   474,     0,   757,     0,   476,
     501,   500,   497,     0,     0,   531,   530,   405,     0,   528,
       0,   625,   626,   779,   781,   785,   788,   778,     0,     0,
     576,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     631,     0,   195,   196,     0,     0,     0,     0,     0,   200,
     201,   759,   761,     0,    20,     0,    21,     0,     4,    25,
       0,    11,    26,     0,    15,   886,    73,    12,    74,    16,
     186,   184,   205,     0,     0,     0,     0,   198,   225,   281,
     336,   338,   342,   348,   347,   346,     0,   343,   340,   341,
       0,   352,   359,   358,   356,   362,   363,   364,   361,   366,
     367,   370,   369,     0,     0,     0,     0,   401,     0,   414,
     415,     0,   453,   450,   482,     0,   604,   480,     0,     0,
     117,   119,     0,     0,     0,    98,     0,    88,    90,    91,
      92,    93,    95,    96,    97,    89,    94,    84,    85,     0,
       0,   104,     0,   100,   102,   103,   110,     0,     0,    83,
      42,     0,     0,     0,     0,     0,     0,     0,   703,   708,
       0,     0,   704,   738,   691,   693,   694,   695,   697,   699,
     698,   696,   700,     0,     0,     0,     0,     0,   107,     0,
     140,     0,     0,   545,   539,   578,   579,     0,     0,   595,
       0,   592,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   228,   229,     0,   234,   136,     0,     0,   131,
       0,     0,     0,     0,     0,     0,    58,     0,     0,     0,
     262,   268,   265,     0,   584,   583,   590,   598,     0,     0,
       0,     0,   544,     0,     0,     0,   397,     0,     0,     0,
       0,   588,     0,   586,     0,   188,     0,     0,   754,     0,
       0,     0,     0,   500,   498,     0,   489,     0,   478,   479,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     193,     0,   783,   790,   789,   944,     0,     0,     0,   639,
       0,   202,     0,     0,     0,     0,   159,   159,   159,     0,
     235,     0,   292,   288,   290,     0,   282,   283,   345,     0,
       0,     0,     0,   669,   353,   642,   646,   648,   650,   652,
     655,   662,   663,   671,   896,   782,     0,   791,     0,   996,
     995,   997,   372,   551,   557,   558,   561,   606,   607,   562,
     563,   768,   769,   770,   566,   374,   376,   548,   378,   402,
     454,     0,   451,   481,   121,    52,    53,    50,    51,   127,
     126,     0,    86,     0,     0,   105,   106,   111,    70,    71,
      48,    49,    69,   709,     0,   712,   739,     0,   702,   701,
     706,   705,   737,     0,     0,   714,     0,   710,   713,   692,
       0,     0,     0,     0,     0,     0,     0,   139,   142,     0,
       0,     0,   109,   112,     0,     0,     0,   162,     0,     0,
     599,     0,     0,     0,     0,   550,     0,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   230,     0,     0,
       0,     0,   275,     0,   272,   277,   233,   137,   132,   135,
       0,   182,     0,     0,    67,    61,    64,    63,     0,    59,
     266,     0,     0,   162,     0,   306,   310,     0,     0,     0,
     313,     0,     0,   319,     0,     0,   326,     0,   330,     0,
     399,   398,   162,     0,     0,   189,     0,   191,   307,     0,
       0,     0,     0,   501,     0,   490,     0,   524,   521,     0,
     525,   526,     0,     0,   520,     0,   495,   523,   522,     0,
       0,     0,     0,   618,   619,   615,     0,     0,   623,   624,
     620,   762,   629,     0,   627,     0,     0,     0,     0,   633,
     194,     0,     0,     0,     0,     0,     0,   634,   635,     0,
     203,   767,    22,     0,    13,    17,    18,   289,   301,     0,
     302,     0,   293,   294,   295,   296,     0,   285,     0,     0,
       0,   653,   666,     0,   350,   354,     0,   685,     0,     0,
       0,     0,     0,     0,   641,   643,   644,   680,   681,   682,
     684,   683,     0,     0,   657,   656,     0,   660,   664,   678,
     676,   675,   668,   672,     0,     0,     0,     0,     0,     0,
       0,     0,   554,   556,   555,   552,   549,   483,   129,   128,
      87,   101,   726,   707,     0,   731,     0,   731,   720,   715,
     143,     0,     0,     0,   113,   141,     0,    23,     0,   596,
     597,   600,   593,   594,   248,     0,     0,   261,   253,     0,
     257,     0,   251,     0,     0,     0,   270,     0,     0,     0,
     232,   273,   276,     0,   133,     0,     0,    66,     0,    60,
     267,     0,     0,   309,   311,   316,     0,   314,     0,     0,
       0,     0,     0,   320,     0,     0,     0,     0,   327,     0,
       0,   331,   400,     0,   589,   587,   190,   755,     0,     0,
     500,     0,     0,   532,     0,   500,     0,   496,    10,   764,
       0,     0,     0,     0,     0,     0,     0,     0,   632,     0,
       0,     0,     0,     0,   636,   640,   305,   303,   304,   297,
     298,   299,   291,     0,   286,   284,   670,   661,   667,     0,
       0,   740,   741,   751,   750,   749,     0,     0,     0,     0,
     742,   647,   748,     0,   645,   649,     0,     0,   654,   658,
       0,   679,   674,   677,   673,     0,     0,   564,     0,   559,
     611,   553,   772,   773,   771,   560,   727,     0,     0,   725,
     732,   733,   729,     0,   724,     0,   722,     0,     0,     0,
       0,     0,     0,   541,   250,     0,   259,     0,     0,   255,
       0,   258,   271,   279,   280,   274,   231,     0,     0,     0,
      62,   269,   547,     0,     0,   317,   321,   315,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   543,
       0,     0,   500,     0,   527,     0,   500,   616,   617,   621,
     622,     0,     0,   628,     0,   630,     0,     0,     0,     0,
     637,   300,   287,   665,   752,     0,     0,   744,     0,   690,
     689,   688,   687,   686,   651,     0,   743,     0,   608,     0,
       0,   736,   735,   734,     0,   728,   721,   719,     0,   716,
     717,   711,   144,   146,   148,     0,     0,     0,     0,     0,
     254,   252,     0,   260,     0,   199,   334,    68,   312,   318,
       0,   332,   328,     0,     0,     0,   322,     0,     0,   324,
       0,   510,   504,   499,     0,   500,   491,     0,   763,   765,
       0,     0,     0,     0,   746,   745,     0,     0,   609,   565,
       0,   730,   723,     0,     0,   150,   149,     0,     0,     0,
       0,   145,   256,     0,     0,     0,     0,     0,     0,   518,
     512,     0,   511,   513,   519,   516,   506,     0,   505,   507,
     517,   493,     0,   492,     0,     0,   638,   747,   659,   610,
     718,   147,   151,     0,     0,     0,     0,   278,     0,     0,
     325,   323,     0,     0,   503,   514,   515,   502,   508,   509,
     494,   766,     0,   152,     0,     0,     0,   333,   329,     0,
       0,     0,     0,     0,     0,     0,     0,   154,     0,   153,
       0,     0,     0,     0,     0,     0,     0,     0,   155
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1435, -1435,  -234,  1139, -1435,  1142,  1145, -1435,  1161,  -532,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
    -976, -1435, -1435, -1435, -1435,  -210,  -576, -1435,   678,  -208,
   -1435, -1435, -1435, -1435, -1435,   215,   457, -1435, -1435,    -9,
    -153,   986, -1435,   968, -1435, -1435,  -640, -1435,   393, -1435,
     200, -1435,  -263,  -306, -1435,  -551, -1435,     5,    45,    23,
    -223,  -172, -1435,  -876, -1435, -1435,   255, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435,   561,    94,  1191,
       0, -1435, -1435, -1435, -1435,   407, -1435, -1435,  -292, -1435,
       8, -1435, -1435,   207,  -726,  -721, -1435, -1435,   650, -1435,
   -1435,   -22,   190, -1435, -1435, -1435,    77, -1435, -1435,   326,
      83, -1435, -1435,    80, -1280, -1435,   885,   174, -1435, -1435,
     171,  -995, -1435, -1435,   170, -1435, -1435, -1237, -1239, -1435,
     166, -1435, -1435,   797,   798, -1435,  -529,   778, -1435, -1435,
    -645,   297,  -641,   293,   301, -1435, -1435, -1435, -1435, -1435,
    1109, -1435, -1435, -1435, -1435,  -853,  -321, -1145, -1435,   -99,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435,   -29,  -815, -1435,
   -1435,   479,   206,  -538,  -415, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435,   750, -1435, -1004, -1435,   151, -1435,   628,  -792,
   -1435, -1435, -1435, -1435, -1435,  -300,  -291, -1226,  -938, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,   537,
    -737,  -805,   246,  -796, -1435,    65,  -806, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435,  1003,  1025,  -298,   455,   283, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435,   132, -1435, -1435,   124, -1435,   129, -1058,
   -1435, -1435, -1435,    89,    81,   -84,   343, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
      92, -1435, -1435, -1435,   -77,   339,   489, -1435, -1435, -1435,
   -1435, -1435,   272, -1435, -1435, -1434, -1435, -1435, -1435,  -574,
   -1435,    56, -1435,   -96, -1435, -1435, -1435, -1435, -1270, -1435,
     104, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435, -1435,
   -1435, -1435, -1435, -1435, -1435, -1435,  -376,  -368,   -55,   922,
   -1435
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   252,   857,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
    1244,   766,   270,   271,   272,   273,   274,   275,   937,   938,
     939,   276,   277,   278,   943,   944,   945,   279,   436,   280,
     281,   694,   282,   438,   439,   440,   453,   756,   757,   283,
    1197,   284,  1662,  1663,   285,   286,   287,   543,   288,   289,
     290,   291,   292,   759,   293,   294,   526,   295,   296,   297,
     298,   299,   300,   629,   301,   302,   849,   850,   303,   304,
     555,   306,   630,   451,  1004,  1005,   307,   631,   308,   633,
     556,   310,   749,   750,  1232,   460,   311,   461,   462,   753,
    1233,  1234,  1235,   634,   635,  1106,  1107,  1514,   636,  1103,
    1104,  1342,  1343,  1344,  1345,   312,   778,   779,   313,  1259,
    1260,  1458,   314,  1262,  1263,   315,   316,  1265,  1266,  1267,
    1268,   317,   318,   319,   320,   886,   321,   322,  1354,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   654,   655,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   682,   683,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   915,   362,   363,   364,  1295,   811,   812,   813,
    1693,  1737,  1738,  1731,  1732,  1739,  1733,  1296,  1297,   365,
     366,  1298,   367,   368,   369,   370,   371,   372,   373,  1146,
     999,  1132,  1395,  1133,  1548,  1134,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   785,  1209,   384,   385,
     386,   387,  1136,  1137,  1138,  1139,   388,   389,   390,   391,
     392,   393,   839,   840,   394,  1327,  1328,  1630,  1090,  1114,
    1364,  1365,  1115,  1116,  1117,  1118,  1119,  1374,  1538,  1539,
    1120,  1377,  1121,  1519,  1122,  1123,  1382,  1383,  1544,  1542,
    1366,  1367,  1368,  1369,  1642,   723,   964,   965,   966,   967,
     968,   969,  1187,  1568,  1659,  1188,  1566,  1657,   970,  1407,
    1563,  1559,  1560,  1561,   971,   972,  1370,  1378,  1529,  1371,
    1525,  1355,   395,   546,   396,   397,   398,   399,   400,   401,
     402,   403,  1140,  1141,  1142,  1143,  1245,   563,   404,   405,
     406
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       305,   695,   695,   437,   305,   305,   305,   594,   309,   411,
     414,   415,   309,   309,   309,   894,   677,   632,   522,  1055,
     895,   896,   897,   898,   610,   997,  1468,   413,   413,   413,
     998,  1019,   538,  1089,   571,   866,   868,  1112,  1261,   612,
     828,  1249,   698,  1031,   521,  1479,   835,   607,  1160,   412,
     412,   412,  1350,  1294,  1411,   619,   559,  1045,   861,   864,
     867,   869,   718,  1510,  1511,   924,   615,   619,   564,  1487,
     567,    11,   993,   733,     9,    10,  1221,   859,   862,   608,
     763,   767,   815,   418,   419,   608,   420,   421,  1526,  1001,
       9,    10,   458,     9,    10,   422,   775,  1135,  1135,  1145,
     697,   418,   419,   424,   420,   421,  1540,  1665,   305,   573,
     882,   422,   883,   884,   422,   885,   309,   887,   608,  1218,
     423,   424,   425,   423,   608,   888,   889,   614,   608,   608,
     994,   544,   995,  1660,  1135,   697,   995,   617,   425,   608,
    1691,   425,  1604,   426,  1164,   754,   426,   441,   583,   576,
    1190,   577,    79,   412,   995,  1191,   738,   738,   472,  1333,
     729,  1287,  1288,  1433,   619,   478,    90,   994,  1198,  1060,
    1192,  1251,  1193,   739,   739,   427,   428,   429,   427,   428,
    1099,  1194,  1178,   996,   764,   994,   444,  1222,  1135,  1215,
     615,   104,   713,  1179,   714,  1109,   479,  1339,  1110,   480,
    1077,  1135,  1238,   554,   558,  1425,   430,   621,  1195,  1167,
    1605,   622,   727,  1666,   755,  1018,   623,   728,   621,   125,
     618,   580,   622,   581,   430,  1063,   715,   623,  1061,  1631,
    1692,   765,   416,  1028,   624,   473,  1067,   584,   578,  1459,
    1468,   678,   807,  1459,   459,   624,   459,  1527,  1528,   816,
    1002,   305,   619,   716,   305,  1289,  1487,  1112,  1112,   309,
     852,  1284,   309,  1226,   632,   431,   762,  1462,   609,  1237,
     851,  1572,  1449,  1223,   611,  1290,  1219,  1291,  1224,  1750,
     866,   868,  1294,   431,   614,  1399,  1161,  1003,   459,   305,
     522,  1294,   574,   522,  1518,  1667,  1658,   309,  1252,   740,
    1111,   459,   474,   475,  1028,  1292,   432,   854,   459,   111,
     582,   619,   459,   856,  1029,   717,   684,  1096,  1098,   686,
    1135,   615,   859,   862,   432,  1460,   123,  1078,  1332,  1594,
    1386,   800,   809,   625,   730,  1196,   626,   596,   598,   919,
     950,   713,   731,   714,   625,  1459,  1293,   626,  1064,  1065,
     433,   627,   658,   433,     9,    10,   619,  1108,   434,  1068,
    1069,   434,   808,  1066,   149,    11,   435,   919,   706,   435,
     659,   710,   855,   988,  1070,   564,   628,   990,   724,   725,
     703,  1008,   417,   616,  1715,  1047,   564,   628,   585,  1150,
    1016,  1702,   746,   586,  1012,   751,   704,  1015,  1198,   860,
     863,   994,   716,   768,   877,   619,   619,   445,   801,   564,
     776,   777,   780,   305,  1729,   619,   619,   786,  1287,   920,
     619,   309,   467,   619,  1664,   793,  1040,   604,  1356,  1042,
     619,  1599,  1056,   987,  1135,  1444,  1752,  1151,   619,  1635,
     613,   994,   305,   605,   305,  1151,    79,   921,   619,   476,
     309,  1339,   309,   989,  1030,   477,   619,   991,  1135,  1465,
      90,  1009,  1639,  1468,   717,   735,  1414,   735,   305,  1640,
     794,  1690,  1341,   305,  1324,  1113,   309,   587,  1294,  1641,
      11,   309,  1023,   619,   780,   104,  1011,   734,  1426,   737,
     619,   735,  1039,  1058,  1225,   805,   735,   619,  1057,  1112,
    1033,  1357,  1434,  1034,  1154,   619,  1041,   616,  1112,  1043,
    1081,  1089,   615,   781,  1505,  1059,  1636,  1152,   787,  1112,
     866,   868,   866,   829,  1664,  1153,  1356,  1557,  1280,   829,
    1329,  1729,  1290,   841,  1291,  1287,  1281,  1404,  1316,  1605,
     743,  1649,  1730,   995,   305,  1334,  1335,  1336,   760,  1654,
     994,   305,   309,   619,  1287,  1288,   953,   772,   954,   309,
     619,    79,  1292,  1282,   783,   784,  1629,  1285,   619,  1664,
    1626,  1168,  1169,   790,   413,    90,  1172,  1627,  1135,  1547,
     909,   910,   448,  1358,  1359,  1628,  1360,   449,   940,  1094,
     619,  1558,   619,   305,  1577,   437,   412,  1406,  1044,  1357,
     104,   309,   955,  1362,  1109,   605,  1206,  1110,   707,   305,
     305,   305,   305,  1677,   452,  1363,   846,   309,   309,   309,
     309,  1650,  1329,   615,  1392,  1184,  1097,   305,   125,  1655,
    1088,   941,  1462,  1286,   450,   309,   942,  1149,   616,   667,
     708,  1789,  1185,  1790,  1093,  1516,  1287,   454,  1289,  1290,
     941,  1291,  1798,   668,   814,   942,  1393,   946,  1287,  1765,
    1135,  1603,  1159,  1135,  1607,  1735,   818,  1746,  1290,  1748,
    1291,   976,  1404,  1394,   661,   980,   981,  1735,   758,  1292,
    1521,  1358,  1359,  1112,  1360,  1186,   845,   847,  1611,  1405,
    1208,  1361,  1211,  1615,   658,  1113,  1113,  1000,  1292,  1006,
     676,  1362,   111,   662,  1228,  1578,  1352,   564,  1155,  1229,
     564,   621,   659,  1363,  1020,   622,   663,  1522,  1533,   123,
     623,  1228,  1287,  1288,   125,  1156,  1229,  1258,  1230,  1162,
     125,  1157,  1406,   658,   660,   305,  1170,  1171,   624,  1481,
    1456,  1162,  1273,   309,  1274,  1287,  1288,   995,  1158,   455,
     664,   659,   956,  1734,  1740,  1053,   866,   149,   305,   456,
    1290,   465,  1291,  1010,   995,   957,   309,   958,   658,  1231,
     908,  1736,  1290,  1706,  1291,   911,  1379,  1380,   959,   960,
     961,   413,   962,  1768,   963,   457,   659,  1338,   305,   305,
    1292,   677,  1184,   522,  1734,   632,   309,   309,  1339,  1381,
    1740,  1398,  1292,   412,   466,  1301,  1639,  1302,  1340,  1185,
    1180,   735,   735,  1640,   699,   701,  1289,   758,  1100,  1341,
    1694,  1181,  1258,  1641,  1697,  1228,   685,   700,   702,   616,
    1229,   688,  1466,  1037,  1038,  1461,  1290,   625,  1291,  1289,
     626,  1135,  1708,  1135,  1709,  1467,  1086,  1469,  1144,  1144,
    1144,  1144,  1466,   665,  1087,  1325,   437,   470,  1320,  1290,
    1470,  1291,   666,  1466,  1200,  1610,  1292,  1447,   870,   525,
     111,  1523,   871,  1201,  1135,  1724,  1745,   471,  1524,  1634,
     628,   442,  1637,  1638,   443,  1144,   524,   123,   912,  1292,
     527,   912,   446,   111,   912,   447,  1050,  1051,  1052,  1177,
     847,   679,   680,  1742,  1135,  1749,   463,  1486,   468,   464,
     123,   469,   528,   594,   719,   720,   721,   539,  1330,  1135,
    1759,  1135,  1762,   540,  1203,   149,  1306,  1716,  1307,   681,
    1613,   687,   560,  1210,   572,  1210,   541,  1113,   561,  1144,
    1507,  1508,   639,  1173,  1174,  1175,  1113,   568,   149,  1176,
     640,   641,  1144,   642,   569,   892,   893,  1113,   899,   900,
     570,   643,   579,  1506,   575,   644,   588,   645,   901,   902,
    1147,  1147,   646,   927,   928,   929,   930,   931,   932,   933,
     934,   935,   936,  1651,  1652,   786,   589,   786,   590,   647,
    1704,  1705,   592,   593,   599,   523,   601,   591,   619,   620,
     637,   638,   656,   657,   669,   672,   670,   671,   681,   523,
     689,   690,   648,   649,   650,   651,   652,   653,   691,  1445,
     697,   829,   709,   692,   711,   693,   712,   722,   747,   726,
     736,   752,   758,   523,   761,   305,   769,   770,   771,   782,
     748,   788,   789,   309,   795,   523,   443,   523,   447,   799,
    1347,   797,   464,   469,   480,   802,   803,   804,   735,   810,
     806,  1747,   817,   819,   820,   830,   842,   837,   848,   858,
     843,  1144,  1590,   838,   873,   875,   890,   903,   874,   904,
    1269,  1086,   876,   905,   906,   916,   437,   922,   923,  1087,
     925,   951,   947,   948,   952,   974,   305,   305,   305,   977,
     975,   973,   877,   982,   309,   309,   309,   983,   984,   992,
     979,  1007,   985,   986,  1013,  1014,  1017,  1024,  1032,  1035,
     442,  1113,  1025,  1036,  1026,  1027,   446,   463,  1062,   468,
     479,  1072,  1080,  1095,  1073,  1079,  1163,  1632,  1092,  1075,
    1101,  1105,   942,  1071,   994,  1182,  1076,  1183,  1204,  1205,
    1074,  1207,  1213,  1199,  1214,  1220,  1216,   754,   751,  1240,
    1242,  1427,  1243,  1241,  1247,  1246,  1253,  1248,  1257,  1254,
    1227,  1270,  1258,  1264,  1277,  1272,  1441,  1279,  1271,  1283,
    1299,  1317,  1276,   715,  1321,  1144,  1346,  1322,  1326,  1348,
    1396,    11,  1323,  1403,  1324,  1376,  1408,  1417,  1372,   780,
    1384,  1419,  1373,  1349,  1353,  1385,  1402,   305,  1387,  1144,
    1431,  1388,  1418,  1389,  1390,   309,  1391,  1438,  1421,  1439,
    1443,  1416,  1429,  1435,  1413,  1437,  1448,  1451,  1466,  1420,
     413,  1412,  1483,  1488,  1422,  1423,  1494,  1596,  1485,  1480,
    1474,  1490,   305,  1472,  1491,  1497,  1496,  1492,  1493,  1475,
     309,  1489,   412,   305,  1339,  1495,  1513,  1536,  1452,  1543,
    1520,   309,   841,  1499,  1478,  1556,  1562,   523,  1517,  1537,
     523,   522,   305,  1549,   522,  1530,   413,  1473,  1550,  1551,
     309,  1552,  1541,  1553,  1554,  1555,  1567,  1569,  1575,  1565,
    1573,  1587,   305,  1580,  1588,   413,  1589,  1592,   412,   545,
     309,  1593,  1622,  1647,  1598,  1645,  1601,  1608,  1609,  1614,
    1633,  1656,  1184,  1672,  1621,   735,  1648,   412,  1661,  1669,
    1674,  1680,  1684,  1688,  1086,  1086,  1696,  1710,  1711,  1144,
    1701,  1713,  1087,  1087,  1700,  1714,  1571,  1484,  1718,  1723,
    1725,  1726,  1727,  1758,   705,   523,  1719,   846,   523,  1741,
    1743,  1756,   523,  1755,  1712,   523,   523,  1570,  1763,  1744,
    1767,  1764,  1772,   523,  1675,  1770,  1646,  1776,  1779,   523,
    1668,  1780,   523,  1753,  1785,  1679,  1596,  1795,  1681,  1401,
     523,  1791,  1794,  1583,  1584,  1689,   523,   523,   523,   523,
     600,  1792,  1774,   949,   523,  1782,   602,  1783,  1165,   603,
    1786,  1239,   523,   696,  1415,   732,  1721,  1788,  1751,  1600,
    1091,  1144,  1236,  1797,  1144,  1500,  1501,  1502,   606,  1585,
    1424,  1022,  1442,  1509,   796,  1515,  1612,  1337,  1453,  1512,
    1457,  1616,  1463,  1471,   880,   891,   881,  1482,  1769,  1054,
     918,  1766,   675,  1148,  1410,  1212,  1400,   523,   741,  1498,
    1531,  1504,  1644,  1535,  1351,  1503,  1643,  1534,  1409,  1375,
     305,   523,  1189,  1564,  1653,  1681,  1532,     0,   309,     0,
     742,     0,   523,     0,     0,     0,     0,     0,  1445,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1760,     0,     0,     0,     0,     0,     0,
     523,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1777,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1683,     0,  1685,
       0,  1687,     0,     0,     0,     0,     0,  1777,  1695,     0,
       0,     0,  1760,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1086,     0,     0,
       0,     0,  1144,     0,  1144,  1087,     0,     0,  1086,  1086,
       0,   305,     0,     0,     0,     0,  1087,  1087,  1086,   309,
    1717,     0,     0,  1720,     0,     0,  1087,     0,     0,     0,
       0,     0,     0,     0,     0,  1144,     0,     0,     0,     0,
       0,   926,     0,     0,   523,  1728,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   523,     0,
       0,     0,   523,   523,     0,  1144,     0,     0,     0,     0,
       0,     0,     0,  1754,     0,     0,     0,     0,  1757,     0,
    1144,     0,  1144,     0,   523,     0,   523,     0,     0,     0,
       0,     0,     0,     0,   523,     0,     0,   523,  1086,     0,
       0,   523,     0,     0,     0,     0,  1087,     0,     0,     0,
    1775,  1086,     0,     0,     0,     0,     0,     0,     0,  1087,
       0,     0,     0,     0,     0,     0,     0,  1781,     0,     0,
       0,  1784,     0,  1703,     0,     0,   305,     0,     0,     0,
       0,     0,   523,     0,   309,     0,     0,  1793,     0,  1707,
    1796,     0,   545,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   305,     0,
       0,     0,     0,     0,     0,     0,   309,   821,   822,     0,
     523,   831,   832,   833,   834,     0,   836,     0,     0,     0,
    1086,     0,   844,     0,     0,  1086,     0,     0,  1087,     0,
     853,     0,     0,  1087,     0,   523,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     872,     0,     0,     0,     0,     0,     0,     0,   878,   879,
       0,     0,     0,     0,     0,   523,   523,   523,   523,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   523,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   523,     0,   914,     0,
       0,   914,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   523,     0,     0,     0,     0,     0,     0,     0,     0,
     523,     0,   523,     0,     0,     0,   523,     0,     0,   978,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   523,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1021,   523,     0,   523,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1046,     0,     0,     0,
    1048,  1049,     0,     0,     0,     0,     0,     0,     0,   878,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   523,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   523,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1166,     0,   523,     0,     0,   523,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   523,     0,     0,     0,     0,     0,     0,
       0,     0,   523,     0,     0,     0,     0,     0,  1202,     0,
       0,     0,     0,     0,     0,     0,   523,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   523,  1217,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1250,
       0,     0,     0,     0,     0,   523,     0,     0,     0,     0,
    1255,  1256,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1275,     0,     0,  1278,   523,
       0,     0,     0,     0,     0,     0,     0,     0,   523,     0,
       0,   523,     0,  1300,     0,  1303,  1304,  1305,     0,  1308,
    1309,  1310,  1311,  1312,  1313,  1314,  1315,     0,     0,  1318,
    1319,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1331,     0,     0,     0,     0,     0,     0,
       0,     0,  1102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   523,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   523,     0,     0,     0,     0,     0,
       0,     0,  1397,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     523,   523,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   523,     0,   523,     0,
       0,   523,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   523,     0,     0,     0,     0,   523,  1428,
       0,  1430,     0,  1432,     0,     0,  1436,     0,     0,     0,
       0,  1440,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1446,     0,     0,     0,     0,     0,     0,
       0,     0,  1450,     0,     0,     0,     0,     0,  1454,  1455,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1476,     0,     0,
    1477,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   523,     0,   523,     0,   523,     0,
       0,     0,     0,     0,     0,   523,     0,  1102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   523,
       0,   523,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   523,     0,     0,
     523,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   523,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   523,     0,     0,     0,  1574,     0,     0,     0,
    1576,     0,     0,     0,  1579,     0,  1581,     0,  1582,     0,
       0,     0,   523,     0,  1586,     0,     0,     0,     0,     0,
     523,     0,  1591,     0,     0,   523,     0,   523,     0,   523,
    1595,  1597,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1446,
       0,     0,     0,     0,     0,     0,     0,   523,     0,     0,
       0,  1617,  1618,  1619,  1620,     0,     0,  1623,  1624,     0,
    1625,     0,     0,     0,   523,     0,     0,     0,   523,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   523,     0,     0,   523,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1670,     0,  1671,     0,
       0,  1673,     0,     0,     0,     0,     0,     0,     0,  1676,
       0,     0,     0,     0,  1678,  1597,     0,     0,     0,     0,
       0,     0,  1682,     0,     0,     0,  1686,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1698,  1699,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1722,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1682,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1761,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1771,     0,     0,     0,     0,
       0,     0,     0,     0,  1773,     0,     0,     0,     0,  1778,
       1,     2,     0,     0,  1761,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
    1778,     0,    12,    13,  1787,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   108,   109,     0,   110,   111,   112,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,   124,   125,     0,     0,   126,
     127,   128,     0,     0,     0,   129,     0,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
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
     244,     0,   245,   246,   247,     0,   248,   249,   250,   251,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,   407,   408,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   409,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   108,   109,     0,   110,   111,   112,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,   124,   125,     0,     0,   126,
     127,   128,     0,   542,     0,   129,     0,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   410,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,     0,   248,   249,   250,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   407,   408,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   409,    28,    29,
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
     128,     0,   798,     0,   129,     0,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   410,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   246,   247,     0,   248,   249,   250,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,     0,     0,     0,
     407,   408,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,  1082,   409,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,  1083,
    1084,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108,   109,     0,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   124,   125,     0,     0,   126,   127,   128,
       0,   798,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   410,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
    1085,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   246,   247,     0,   248,   249,   250,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,   407,
     408,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,  1082,   409,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,  1083,  1084,
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
     542,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     410,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,  1085,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,     0,   245,
     246,   247,     0,   248,   249,   250,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,     0,    11,     0,     0,     0,   407,   408,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   409,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   124,   125,     0,     0,   126,   127,   128,     0,     0,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   410,
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
     247,     0,   248,   249,   250,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,    12,    13,     0,
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
     129,     0,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,     0,   245,   246,   247,
       0,   248,   249,   250,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,     0,     0,     0,    12,    13,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     0,   110,
     111,   112,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,   124,
     125,     0,     0,   126,   127,   128,     0,     0,     0,   129,
       0,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   410,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,     0,
     248,   249,   250,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,    12,   408,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,    32,    33,    34,
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
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   410,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   246,   247,     0,   248,
     249,   250,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,     0,     0,     0,   865,   408,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     409,    28,    29,    30,    31,     0,    32,    33,    34,    35,
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
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   410,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     0,   244,     0,   245,   246,   247,     0,   248,   249,
     250,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,   407,   408,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,  1082,   409,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,  1083,  1084,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,   110,   111,   112,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,   124,   125,     0,     0,
     126,   127,   128,     0,     0,     0,   129,     0,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   410,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,  1085,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   246,   247,     0,   248,   249,   250,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   407,   408,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   547,   409,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,   548,   549,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   498,    82,    83,    84,    85,    86,   550,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   551,   109,     0,   110,   111,   112,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,   124,   125,     0,     0,   126,
     127,   128,     0,     0,   552,   129,     0,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   410,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   515,   516,   517,   176,
     177,   518,   553,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,     0,   248,   249,   250,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   407,   408,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   547,   409,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     548,   549,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     498,    82,    83,    84,    85,    86,   550,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   551,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,   557,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   410,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   515,   516,   517,   176,   177,
     518,   553,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   246,   247,     0,   248,   249,   250,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     407,   408,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   547,   409,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,   548,
     549,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   498,
      82,    83,    84,    85,    86,   550,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     551,   109,     0,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   124,   125,     0,     0,   126,   127,   128,
       0,     0,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   410,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   515,   516,   517,   176,   177,   518,
     553,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   595,   244,     0,
     245,   246,   247,     0,   248,   249,   250,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   407,
     408,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   547,   409,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,   548,   549,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   498,    82,
      83,    84,    85,    86,   550,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   551,
     109,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,   124,   125,     0,     0,   126,   127,   128,     0,
       0,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     410,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   515,   516,   517,   176,   177,   518,   553,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,   597,   245,
     246,   247,     0,   248,   249,   250,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   407,   408,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   547,   409,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,   548,   549,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   498,    82,    83,
      84,    85,    86,   550,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   551,   109,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   124,   125,     0,     0,   126,   127,   128,     0,   907,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   410,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   515,   516,   517,   176,   177,   518,   553,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,     0,   248,   249,   250,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   407,   408,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   547,   409,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   548,   549,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   498,    82,    83,    84,
      85,    86,   550,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   551,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,   913,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   410,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   515,   516,   517,   176,   177,   518,   553,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,     0,   245,   246,   247,
       0,   248,   249,   250,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   407,   408,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   547,   409,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,   548,   549,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   498,    82,    83,    84,    85,
      86,   550,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   551,   109,     0,   110,
     111,   112,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,   124,
     125,     0,     0,   126,   127,   128,     0,     0,     0,   129,
     917,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   410,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     515,   516,   517,   176,   177,   518,   553,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,     0,
     248,   249,   250,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   407,   408,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   484,    25,
     486,   409,    28,   487,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   489,
       0,    45,    46,    47,   491,   492,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   498,    82,    83,    84,    85,    86,
     550,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   501,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   551,   109,     0,   110,   111,
     673,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   674,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   410,   151,   152,   153,
     154,   155,   156,   157,   158,   510,   160,   511,   162,   512,
     513,   165,   166,   167,   168,   169,   170,   514,   172,   515,
     516,   517,   176,   177,   518,   519,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   520,   247,     0,   248,
     249,   250,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   407,   408,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   547,
     409,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,   548,   549,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,   498,    82,    83,    84,    85,    86,   550,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   551,   109,     0,   110,   111,   112,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,   124,   125,     0,
       0,   126,   127,   128,     0,     0,     0,   129,     0,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   410,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   515,   516,
     517,   176,   177,   518,   553,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     0,   244,     0,   245,   246,   247,     0,   248,   249,
     250,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   407,   408,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   484,    25,   486,   409,
      28,   487,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   489,     0,    45,
      46,    47,   491,   492,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   498,    82,    83,    84,    85,    86,   550,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   501,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   551,   109,     0,   110,   111,   112,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,   124,   125,     0,     0,
     126,   127,   128,     0,     0,     0,   129,     0,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   410,   151,   152,   153,   154,   155,
     156,   157,   158,   510,   160,   511,   162,   512,   513,   165,
     166,   167,   168,   169,   170,   514,   172,   515,   516,   517,
     176,   177,   518,   519,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   520,   247,     0,   248,   249,   250,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   407,   408,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   484,    25,   486,   409,    28,
     487,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,   489,     0,    45,    46,
      47,   491,   492,    50,   493,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   498,    82,    83,    84,    85,    86,   550,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   501,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   551,   109,     0,   110,   111,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,     0,     0,     0,     0,   126,
     127,   128,     0,     0,     0,   129,     0,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   410,   151,   152,   153,   154,   155,   156,
     157,   158,   510,   160,   511,   162,   512,   513,   165,   166,
     167,   168,   169,   170,   514,   172,   515,   516,   517,   176,
     177,   518,   519,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   520,   247,     0,   248,   249,   250,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   407,   408,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   484,    25,   486,   409,    28,   487,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   489,     0,    45,    46,    47,
     491,   492,    50,   493,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     498,    82,    83,    84,    85,    86,   550,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   501,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   551,   109,     0,   110,   111,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,     0,     0,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,     0,
       0,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   410,   151,   152,   153,   154,   155,   156,   157,
     158,   510,   160,   511,   162,   512,   513,   165,   166,   167,
     168,   169,   170,   514,   172,   515,   516,   517,   176,   177,
     518,   519,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   520,   247,     0,   248,   249,   250,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     407,   408,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   484,    25,   486,   409,    28,   487,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   489,     0,    45,    46,    47,   491,
     492,    50,   493,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   498,
      82,    83,    84,    85,    86,   550,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   501,     0,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,     0,   106,   107,
     551,   109,     0,   110,   111,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,     0,     0,     0,     0,   126,   127,   128,
       0,     0,     0,   129,     0,   130,   131,     0,     0,     0,
     134,     0,   135,     0,   136,     0,   138,     0,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   410,   151,   152,   153,   154,   155,   156,   157,   158,
     510,   160,   511,   162,   512,   513,   165,   166,   167,   168,
     169,   170,   514,   172,   515,   516,   517,   176,   177,   518,
     519,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   520,   247,     0,   248,   249,   250,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   407,
     408,     0,    14,    15,    16,   481,    18,    19,    20,   482,
      22,   483,   484,   485,   486,   409,    28,   487,    30,    31,
       0,    32,    33,    34,    35,   488,    37,    38,    39,    40,
      41,    42,    43,   489,     0,    45,   490,    47,   491,   492,
      50,   493,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   494,   495,    68,     0,
      69,    70,    71,   496,     0,     0,    74,    75,    76,     0,
       0,   497,    78,     0,     0,     0,     0,    80,   498,    82,
     499,   500,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   501,    97,    98,   502,   503,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   504,   120,   121,   505,     0,
       0,     0,     0,     0,     0,     0,   506,   507,   128,     0,
       0,     0,   129,     0,   130,   508,     0,     0,     0,   134,
       0,   135,     0,   136,   137,   138,   139,   509,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     410,   151,   152,   153,   154,   155,   156,   157,   158,   510,
     160,   511,   162,   512,   513,   165,   166,   167,   168,   169,
     170,   514,   172,   515,   516,   517,   176,   177,   518,   519,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     1,     2,   245,
     520,   247,     0,   248,   249,   250,     3,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   407,
     408,     0,    14,    15,    16,   529,    18,    19,    20,   482,
     530,   531,   484,   485,   486,   409,    28,   487,    30,    31,
       0,    32,    33,    34,    35,   532,    37,   533,   534,    40,
      41,    42,    43,   489,     0,    45,   535,    47,   491,   492,
      50,   493,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   494,   495,    68,     0,
      69,    70,    71,   536,     0,     0,    74,    75,    76,     0,
       0,   497,    78,     0,     0,     0,     0,    80,   498,    82,
     499,   500,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   501,    97,    98,   502,   503,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   504,   120,   121,   505,     0,
       0,     0,     0,     0,     0,     0,   506,   507,   128,     0,
       0,     0,   129,     0,   130,   508,     0,     0,     0,   134,
       0,   135,     0,   136,   137,   138,   139,   509,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     410,   151,   152,   153,   154,   155,   156,   157,   158,   510,
     537,   511,   162,   512,   513,   165,   166,   167,   168,   169,
     170,   514,   172,   515,   516,   517,   176,   177,   518,   519,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     0,   562,   245,
     520,   247,     0,   248,   249,   250,     7,     8,     0,     0,
       0,   773,     0,     0,     0,   407,   408,     0,    14,    15,
      16,   529,    18,    19,    20,   482,   530,   531,   484,   485,
     486,   409,    28,   487,    30,    31,     0,    32,    33,    34,
      35,   532,    37,   533,   534,    40,    41,    42,    43,   489,
       0,    45,   535,    47,   491,   492,    50,   493,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   494,   495,    68,     0,    69,    70,    71,   536,
       0,     0,    74,    75,    76,     0,     0,   497,    78,     0,
       0,     0,     0,    80,   498,    82,   499,   500,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   501,    97,    98,
     502,   503,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   504,   120,   121,   505,     0,     0,     0,     0,     0,
       0,     0,   506,   507,   128,     0,     0,     0,   129,   774,
     130,   508,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   509,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,     0,     0,   410,   151,   152,   153,
     154,   155,   156,   157,   158,   510,   537,   511,   162,   512,
     513,   165,   166,   167,   168,   169,   170,   514,   172,   515,
     516,   517,   176,   177,   518,   519,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     0,   562,   245,   520,   247,     0,   248,
     249,   250,     7,     8,     0,     0,     0,     0,     0,     0,
       0,   407,   408,     0,    14,    15,    16,   529,    18,    19,
      20,   482,   530,   531,   484,   485,   486,   409,    28,   487,
      30,    31,     0,    32,    33,    34,    35,   532,    37,   533,
     534,    40,    41,    42,    43,   489,     0,    45,   535,    47,
     491,   492,    50,   493,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   494,   495,
      68,     0,    69,    70,    71,   536,     0,     0,    74,    75,
      76,     0,     0,   497,    78,     0,     0,     0,     0,    80,
     498,    82,   499,   500,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   501,    97,    98,   502,   503,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   504,   120,   121,
     505,     0,     0,     0,     0,     0,     0,     0,   506,   507,
     128,     0,     0,     0,   129,     0,   130,   508,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   509,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
       0,     0,   410,   151,   152,   153,   154,   155,   156,   157,
     158,   510,   537,   511,   162,   512,   513,   165,   166,   167,
     168,   169,   170,   514,   172,   515,   516,   517,   176,   177,
     518,   519,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     0,
       0,   245,   520,   247,     0,   248,   249,   250,   565,   566,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,   407,   408,     0,    14,    15,    16,   529,
      18,    19,    20,   482,   530,   531,   484,   485,   486,   409,
      28,   487,    30,    31,     0,    32,    33,    34,    35,   532,
      37,   533,   534,    40,    41,    42,    43,   489,     0,    45,
     535,    47,   491,   492,    50,   493,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     494,   495,    68,     0,    69,    70,    71,   536,     0,     0,
      74,    75,    76,     0,     0,   497,    78,     0,     0,     0,
       0,    80,   498,    82,   499,   500,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   501,    97,    98,   502,   503,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   504,
     120,   121,   505,     0,     0,     0,     0,     0,     0,     0,
     506,   507,   128,     0,     0,     0,   129,     0,   130,   508,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   509,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   410,   151,   152,   153,   154,   155,
     156,   157,   158,   510,   537,   511,   162,   512,   513,   165,
     166,   167,   168,   169,   170,   514,   172,   515,   516,   517,
     176,   177,   518,   519,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,     0,   245,   520,   247,     0,   248,   249,   250,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   407,   408,     0,    14,    15,    16,   823,    18,
      19,    20,    21,   530,   824,   484,    25,   486,   409,    28,
     487,    30,    31,     0,    32,    33,    34,    35,   825,    37,
     533,   534,    40,    41,    42,    43,   489,     0,    45,   826,
      47,   491,   492,    50,   493,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   494,
     495,    68,     0,    69,    70,    71,   827,     0,     0,    74,
      75,    76,     0,     0,   497,    78,     0,     0,     0,    79,
      80,   498,    82,   499,   500,    85,    86,   550,    88,     0,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   501,    97,    98,   502,   503,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   551,   109,     0,   110,   111,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   505,     0,   123,     0,     0,     0,     0,     0,   506,
     507,   128,     0,     0,     0,   129,     0,   130,   508,     0,
       0,     0,     0,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   410,   151,   152,   153,   154,   155,   156,
     157,   158,   510,   537,   511,   162,   512,   513,   165,   166,
     167,   168,   169,   170,   514,   172,   515,   516,   517,   176,
     177,   518,   519,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   520,   247,     0,   248,   249,   250,     7,
       8,     0,     0,     0,     0,     0,     0,     0,   407,   408,
       0,    14,    15,    16,   481,    18,    19,    20,   482,    22,
     483,   484,  1124,   486,   409,    28,   487,    30,    31,     0,
      32,    33,    34,    35,   488,    37,    38,    39,    40,    41,
      42,    43,   489,     0,    45,   490,    47,   491,   492,    50,
     493,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   494,   495,    68,     0,    69,
      70,    71,   496,     0,     0,    74,    75,    76,     0,     0,
     497,    78,     0,     0,     0,     0,    80,   498,    82,   499,
     500,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     501,    97,    98,   502,   503,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1125,     0,     0,
       0,  1126,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   504,   120,   121,   505,     0,     0,
       0,     0,     0,     0,     0,   506,   507,   128,     0,     0,
       0,   129,  1545,   130,   508,     0,     0,     0,  1546,     0,
     135,     0,   136,   137,   138,   139,   509,   141,   142,   143,
     144,   145,   146,     0,     0,  1127,   148,     0,     0,   410,
     151,   152,   153,   154,   155,   156,   157,   158,   510,   160,
     511,   162,   512,   513,   165,   166,   167,   168,   169,   170,
     514,   172,   515,   516,   517,   176,   177,   518,   519,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     7,     8,   245,   520,
     247,  1128,  1129,  1130,  1131,   407,   408,     0,    14,    15,
      16,   481,    18,    19,    20,   482,    22,   483,   484,  1124,
     486,   409,    28,   487,    30,    31,     0,    32,    33,    34,
      35,   488,    37,    38,    39,    40,    41,    42,    43,   489,
       0,    45,   490,    47,   491,   492,    50,   493,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   494,   495,    68,     0,    69,    70,    71,   496,
       0,     0,    74,    75,    76,     0,     0,   497,    78,     0,
       0,     0,     0,    80,   498,    82,   499,   500,    85,    86,
    1464,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   501,    97,    98,
     502,   503,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,  1125,     0,     0,     0,  1126,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   504,   120,   121,   505,     0,     0,     0,     0,     0,
       0,     0,   506,   507,   128,     0,     0,     0,   129,     0,
     130,   508,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   509,   141,   142,   143,   144,   145,   146,
       0,     0,  1127,   148,     0,     0,   410,   151,   152,   153,
     154,   155,   156,   157,   158,   510,   160,   511,   162,   512,
     513,   165,   166,   167,   168,   169,   170,   514,   172,   515,
     516,   517,   176,   177,   518,   519,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     7,     8,   245,   520,   247,  1128,  1129,
    1130,  1131,   407,   408,     0,    14,    15,    16,   481,    18,
      19,    20,   482,    22,   483,   484,  1124,   486,   409,    28,
     487,    30,    31,     0,    32,    33,    34,    35,   488,    37,
      38,    39,    40,    41,    42,    43,   489,     0,    45,   490,
      47,   491,   492,    50,   493,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   494,
     495,    68,     0,    69,    70,    71,   496,     0,     0,    74,
      75,    76,     0,     0,   497,    78,     0,     0,     0,     0,
      80,   498,    82,   499,   500,    85,    86,  1602,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   501,    97,    98,   502,   503,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,  1125,     0,     0,     0,  1126,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   504,   120,
     121,   505,     0,     0,     0,     0,     0,     0,     0,   506,
     507,   128,     0,     0,     0,   129,     0,   130,   508,     0,
       0,     0,     0,     0,   135,     0,   136,   137,   138,   139,
     509,   141,   142,   143,   144,   145,   146,     0,     0,  1127,
     148,     0,     0,   410,   151,   152,   153,   154,   155,   156,
     157,   158,   510,   160,   511,   162,   512,   513,   165,   166,
     167,   168,   169,   170,   514,   172,   515,   516,   517,   176,
     177,   518,   519,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,     0,
       7,     8,   245,   520,   247,  1128,  1129,  1130,  1131,   407,
     408,     0,    14,    15,    16,   481,    18,    19,    20,   482,
      22,   483,   484,  1124,   486,   409,    28,   487,    30,    31,
       0,    32,    33,    34,    35,   488,    37,    38,    39,    40,
      41,    42,    43,   489,     0,    45,   490,    47,   491,   492,
      50,   493,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   494,   495,    68,     0,
      69,    70,    71,   496,     0,     0,    74,    75,    76,     0,
       0,   497,    78,     0,     0,     0,     0,    80,   498,    82,
     499,   500,    85,    86,  1606,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   501,    97,    98,   502,   503,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,  1125,     0,
       0,     0,  1126,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   504,   120,   121,   505,     0,
       0,     0,     0,     0,     0,     0,   506,   507,   128,     0,
       0,     0,   129,     0,   130,   508,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   509,   141,   142,
     143,   144,   145,   146,     0,     0,  1127,   148,     0,     0,
     410,   151,   152,   153,   154,   155,   156,   157,   158,   510,
     160,   511,   162,   512,   513,   165,   166,   167,   168,   169,
     170,   514,   172,   515,   516,   517,   176,   177,   518,   519,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     7,     8,   245,
     520,   247,  1128,  1129,  1130,  1131,   407,   408,     0,    14,
      15,    16,   529,    18,    19,    20,   482,   530,   531,   484,
     485,   486,   409,    28,   487,    30,    31,     0,    32,    33,
      34,    35,   532,    37,   533,   534,    40,    41,    42,    43,
     489,     0,    45,   535,    47,   491,   492,    50,   493,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   494,   495,    68,     0,    69,    70,    71,
     536,     0,     0,    74,    75,    76,     0,     0,   497,    78,
       0,     0,     0,     0,    80,   498,    82,   499,   500,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   501,    97,
      98,   502,   503,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   504,   120,   121,   505,     0,     0,     0,     0,
       0,     0,     0,   506,   507,   128,     0,     0,     0,   129,
     744,   130,   508,     0,     0,     0,   745,     0,   135,     0,
     136,   137,   138,   139,   509,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,     0,     0,   410,   151,   152,
     153,   154,   155,   156,   157,   158,   510,   537,   511,   162,
     512,   513,   165,   166,   167,   168,   169,   170,   514,   172,
     515,   516,   517,   176,   177,   518,   519,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     7,     8,   245,   520,   247,     0,
     248,   249,   250,   407,   408,     0,    14,    15,    16,   529,
      18,    19,    20,   482,   530,   531,   484,   485,   486,   409,
      28,   487,    30,    31,     0,    32,    33,    34,    35,   532,
      37,   533,   534,    40,    41,    42,    43,   489,     0,    45,
     535,    47,   491,   492,    50,   493,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     494,   495,    68,     0,    69,    70,    71,   536,     0,     0,
      74,    75,    76,     0,     0,   497,    78,     0,     0,     0,
       0,    80,   498,    82,   499,   500,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   501,    97,    98,   502,   503,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   504,
     120,   121,   505,     0,     0,     0,     0,     0,     0,     0,
     506,   507,   128,     0,     0,     0,   129,   791,   130,   508,
       0,     0,     0,   792,     0,   135,     0,   136,   137,   138,
     139,   509,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   410,   151,   152,   153,   154,   155,
     156,   157,   158,   510,   537,   511,   162,   512,   513,   165,
     166,   167,   168,   169,   170,   514,   172,   515,   516,   517,
     176,   177,   518,   519,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     7,     8,   245,   520,   247,     0,   248,   249,   250,
     407,   408,     0,    14,    15,    16,   481,    18,    19,    20,
     482,    22,   483,   484,  1124,   486,   409,    28,   487,    30,
      31,     0,    32,    33,    34,    35,   488,    37,    38,    39,
      40,    41,    42,    43,   489,     0,    45,   490,    47,   491,
     492,    50,   493,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   494,   495,    68,
       0,    69,    70,    71,   496,     0,     0,    74,    75,    76,
       0,     0,   497,    78,     0,     0,     0,     0,    80,   498,
      82,   499,   500,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   501,    97,    98,   502,   503,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,  1125,
       0,     0,     0,  1126,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   504,   120,   121,   505,
       0,     0,     0,     0,     0,     0,     0,   506,   507,   128,
       0,     0,     0,   129,     0,   130,   508,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   509,   141,
     142,   143,   144,   145,   146,     0,     0,  1127,   148,     0,
       0,   410,   151,   152,   153,   154,   155,   156,   157,   158,
     510,   160,   511,   162,   512,   513,   165,   166,   167,   168,
     169,   170,   514,   172,   515,   516,   517,   176,   177,   518,
     519,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     7,     8,
     245,   520,   247,  1128,  1129,  1130,  1131,   407,   408,     0,
      14,    15,    16,   481,    18,    19,    20,   482,    22,   483,
     484,  1124,   486,   409,    28,   487,    30,    31,     0,    32,
      33,    34,    35,   488,    37,    38,    39,    40,    41,    42,
      43,   489,     0,    45,   490,    47,   491,   492,    50,   493,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   494,   495,    68,     0,    69,    70,
      71,   496,     0,     0,    74,    75,    76,     0,     0,   497,
      78,     0,     0,     0,     0,    80,   498,    82,   499,   500,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   501,
      97,    98,   502,   503,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,  1125,     0,     0,     0,
    1126,     0,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   504,   120,   121,   505,     0,     0,     0,
       0,     0,     0,     0,   506,   507,   128,     0,     0,     0,
     129,     0,   130,   508,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   509,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,     0,     0,   410,   151,
     152,   153,   154,   155,   156,   157,   158,   510,   160,   511,
     162,   512,   513,   165,   166,   167,   168,   169,   170,   514,
     172,   515,   516,   517,   176,   177,   518,   519,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     7,     8,   245,   520,   247,
    1128,  1129,  1130,  1131,   407,   408,     0,    14,    15,    16,
     529,    18,    19,    20,   482,   530,   531,   484,   485,   486,
     409,    28,   487,    30,    31,     0,    32,    33,    34,    35,
     532,    37,   533,   534,    40,    41,    42,    43,   489,     0,
      45,   535,    47,   491,   492,    50,   493,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   494,   495,    68,     0,    69,    70,    71,   536,     0,
       0,    74,    75,    76,     0,     0,   497,    78,     0,     0,
       0,     0,    80,   498,    82,   499,   500,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   501,    97,    98,   502,
     503,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     504,   120,   121,   505,     0,     0,     0,     0,     0,     0,
       0,   506,   507,   128,     0,     0,     0,   129,     0,   130,
     508,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   509,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   410,   151,   152,   153,   154,
     155,   156,   157,   158,   510,   537,   511,   162,   512,   513,
     165,   166,   167,   168,   169,   170,   514,   172,   515,   516,
     517,   176,   177,   518,   519,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     7,     8,   245,   520,   247,     0,   248,   249,
     250,   407,   408,     0,    14,    15,    16,     0,    18,    19,
      20,   482,     0,     0,   484,   485,     0,   409,    28,   487,
      30,    31,     0,    32,    33,    34,    35,     0,    37,     0,
       0,    40,    41,    42,    43,   489,     0,    45,     0,    47,
       0,     0,    50,   493,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   494,   495,
      68,     0,    69,    70,    71,     0,     0,     0,    74,    75,
      76,     0,     0,   497,    78,     0,     0,     0,     0,    80,
     498,    82,   499,   500,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   501,    97,    98,   502,   503,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
       0,     0,     0,     0,     0,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   504,   120,   121,
     505,     0,     0,     0,     0,     0,     0,     0,   506,   507,
     128,     0,     0,     0,   129,     0,   130,   508,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   509,
     141,   142,   143,   144,   145,   146,     0,     0,     0,   148,
       0,     0,   410,   151,   152,   153,   154,   155,   156,   157,
     158,   510,     0,   511,   162,   512,   513,   165,   166,   167,
     168,   169,   170,   514,   172,   515,   516,   517,   176,   177,
       0,   519,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     0,
       0,   245,   520,   247,     0,   248,   249,   250
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   416,   417,    12,     4,     5,     6,   179,     0,     4,
       5,     6,     4,     5,     6,   660,   337,   309,    73,   811,
     661,   662,   663,   664,   258,   751,  1265,     4,     5,     6,
     751,   768,    87,   848,   133,   611,   612,   890,  1033,   273,
     578,  1017,   418,   780,    73,  1282,   584,   257,   924,     4,
       5,     6,  1110,  1057,  1199,   107,   111,   794,   609,   610,
     611,   612,   430,  1343,  1344,   705,   289,   107,   123,  1295,
     125,    29,    36,   441,    26,    27,    36,   609,   610,     1,
     456,   457,     8,    37,    38,     1,    40,    41,    96,    55,
      26,    27,   118,    26,    27,    47,   464,   903,   904,   904,
      29,    37,    38,    57,    40,    41,  1376,   118,   108,    30,
     639,    47,   641,   642,    47,   644,   108,   646,     1,   147,
      56,    57,    74,    56,     1,   654,   655,   280,     1,     1,
      94,   108,    96,  1567,   940,    29,    96,   107,    74,     1,
      93,    74,   118,    79,   940,   118,    79,   160,   224,   224,
      39,   226,   110,   108,    96,    44,    45,    45,    76,   113,
     112,     9,    10,   147,   107,   122,   124,    94,   974,   131,
      59,   142,    61,    62,    62,   111,   112,   113,   111,   112,
     113,    70,   262,   147,   113,    94,   153,   147,   994,   994,
     413,   149,    45,   273,    47,   153,   153,   106,   156,   156,
     107,  1007,  1007,   109,   110,   147,   160,    42,    97,   946,
     186,    46,   137,   224,   187,   142,    51,   142,    42,   177,
     190,   224,    46,   226,   160,    94,    79,    51,   190,  1509,
     183,   160,   156,   107,    69,   153,    94,   313,   313,   100,
    1479,   340,   185,   100,   272,    69,   272,   255,   256,   175,
     216,   251,   107,   106,   254,   103,  1482,  1110,  1111,   251,
     312,  1053,   254,  1000,   556,   219,   160,  1262,   190,  1006,
     310,  1416,  1248,   999,   190,   123,   997,   125,   999,  1713,
     856,   857,  1286,   219,   437,  1161,   926,   253,   272,   289,
     345,  1295,   213,   348,  1352,   306,  1566,   289,  1019,   187,
     258,   272,   220,   221,   107,   153,   260,   190,   272,   157,
     313,   107,   272,   190,   188,   168,   345,   190,   190,   348,
    1126,   544,   854,   855,   260,   186,   174,   234,   190,   186,
    1126,   107,   187,   168,   286,   224,   171,   243,   244,   107,
     716,    45,   294,    47,   168,   100,   194,   171,   217,   218,
     286,   186,   158,   286,    26,    27,   107,   886,   294,   217,
     218,   294,   186,   232,   212,    29,   302,   107,   423,   302,
     176,   426,   606,   107,   232,   430,   211,   107,   433,   434,
     166,   107,   156,   289,  1664,   188,   441,   211,   224,   185,
     766,  1628,   447,   229,   762,   450,   182,   765,  1204,   609,
     610,    94,   106,   458,   627,   107,   107,   156,   184,   464,
     465,   466,   467,   413,     5,   107,   107,   472,     9,   187,
     107,   413,   118,   107,  1569,   480,   107,    33,    96,   107,
     107,   186,   130,   184,  1240,  1240,  1716,   107,   107,    52,
     112,    94,   442,    49,   444,   107,   110,   187,   107,   122,
     442,   106,   444,   187,   147,   122,   107,   187,  1264,  1264,
     124,   187,   268,  1702,   168,   442,  1203,   444,   468,   275,
     525,   118,   127,   473,   153,   890,   468,   313,  1482,   285,
      29,   473,   184,   107,   539,   149,   187,   442,  1214,   444,
     107,   468,   184,   184,   147,   550,   473,   107,   196,  1352,
     187,   169,  1223,   187,   919,   107,   187,   413,  1361,   187,
     187,  1326,   735,   468,  1329,   184,   129,   187,   473,  1372,
    1096,  1097,  1098,   578,  1669,   187,    96,   136,   187,   584,
     209,     5,   123,   588,   125,     9,   187,    96,  1076,   186,
     446,   107,   133,    96,   544,  1096,  1097,  1098,   454,   107,
      94,   551,   544,   107,     9,    10,    54,   463,    56,   551,
     107,   110,   153,   187,   470,   471,   153,   130,   107,  1714,
     187,   947,   948,   479,   551,   124,   952,   187,  1384,  1384,
     679,   680,    66,   251,   252,   187,   254,    71,    94,    33,
     107,   200,   107,   593,   147,   604,   551,   156,   142,   169,
     149,   593,   100,   271,   153,    49,   982,   156,   169,   609,
     610,   611,   612,  1589,   156,   283,   593,   609,   610,   611,
     612,   187,   209,   846,   144,    96,   860,   627,   177,   187,
     184,   137,  1627,   196,   118,   627,   142,   184,   544,   136,
     201,  1786,   113,  1788,   854,   184,     9,   156,   103,   123,
     137,   125,  1797,   150,   560,   142,   176,   712,     9,   133,
    1466,  1466,   137,  1469,  1469,    28,   572,   184,   123,   184,
     125,   726,    96,   193,   117,   730,   731,    28,   153,   153,
     216,   251,   252,  1536,   254,   156,   592,   593,  1480,   113,
     988,   261,   990,  1485,   158,  1110,  1111,   752,   153,   754,
     153,   271,   157,   146,    53,  1431,   153,   762,   148,    58,
     765,    42,   176,   283,   769,    46,   159,   253,  1363,   174,
      51,    53,     9,    10,   177,   165,    58,   100,    77,   937,
     177,   148,   156,   158,   198,   735,   128,   129,    69,   194,
     113,   949,  1040,   735,  1042,     9,    10,    96,   165,    24,
     193,   176,   250,  1691,  1692,   810,  1332,   212,   758,    34,
     123,   156,   125,   758,    96,   263,   758,   265,   158,   118,
     676,   134,   123,   198,   125,   681,   246,   247,   276,   277,
     278,   758,   280,   134,   282,    60,   176,    95,   788,   789,
     153,  1112,    96,   848,  1732,  1087,   788,   789,   106,   269,
    1738,   137,   153,   758,   156,   231,   268,   233,   116,   113,
     262,   788,   789,   275,   182,   182,   103,   153,   873,   127,
    1612,   273,   100,   285,  1616,    53,   347,   195,   195,   735,
      58,   352,   100,   788,   789,   113,   123,   168,   125,   103,
     171,  1647,  1647,  1649,  1649,   113,   846,   100,   903,   904,
     905,   906,   100,   200,   846,   186,   865,   156,  1081,   123,
     113,   125,   209,   100,   298,   113,   153,  1243,   613,   118,
     157,   267,   617,   307,  1680,  1680,   113,   156,   274,  1520,
     211,   153,  1527,  1528,   156,   940,   122,   174,   682,   153,
     122,   685,   153,   157,   688,   156,   802,   803,   804,   954,
     806,   191,   192,  1695,  1710,  1710,   153,   194,   153,   156,
     174,   156,   122,  1085,   220,   221,   222,   118,  1090,  1725,
    1725,  1727,  1727,   122,   979,   212,   231,  1664,   233,   154,
     194,   156,   153,   988,   153,   990,   122,  1352,   122,   994,
     128,   129,   132,   276,   277,   278,  1361,   122,   212,   282,
     140,   141,  1007,   143,   122,   658,   659,  1372,   665,   666,
     122,   151,   156,  1339,   215,   155,   118,   157,   667,   668,
     905,   906,   162,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,  1557,  1558,  1040,   240,  1042,   240,   179,
    1635,  1636,   156,   153,   313,    73,     0,   241,   107,   190,
     167,    92,   248,    99,    50,   102,   199,   101,   154,    87,
     145,   156,   202,   203,   204,   205,   206,   207,   184,  1242,
      29,  1076,    47,   184,   152,   184,   118,   245,   283,   303,
     187,   118,   153,   111,     1,  1035,   118,   142,   107,   187,
     283,   153,   153,  1035,   142,   123,   156,   125,   156,   121,
    1105,   184,   156,   156,   156,   156,   156,   156,  1035,    35,
     153,  1706,    17,   213,    29,   187,   190,   230,   244,     3,
     190,  1126,  1448,   229,   118,   170,    70,   230,   168,    94,
    1035,  1081,   170,    94,    94,   149,  1095,   107,   107,  1081,
      29,   127,   160,   160,   132,    94,  1096,  1097,  1098,   142,
     298,   245,  1325,   132,  1096,  1097,  1098,   184,   184,   107,
     118,    94,   187,   187,    96,    45,    96,   187,   184,   153,
     153,  1536,   187,   184,   187,   187,   153,   153,   156,   153,
     153,    94,   190,    33,   156,   142,   132,  1513,   198,   224,
     170,   118,   142,   232,    94,    29,   230,   285,    94,   298,
     236,   153,   118,   226,   127,   147,   118,   118,  1213,    94,
     197,  1216,   132,   184,   132,   160,   153,    96,   147,   118,
     253,   184,   100,   100,   190,   153,  1231,   121,   184,    35,
      29,   118,   142,    79,   156,  1240,   107,   156,   244,   107,
     144,    29,   156,    29,   153,   266,    29,   190,   257,  1254,
     156,   187,   259,  1109,   284,   156,   285,  1207,   156,  1264,
     127,   156,  1207,   156,   156,  1207,   156,   118,   144,   118,
      77,   226,   147,   147,   305,   147,   107,   142,   100,   187,
    1207,   286,     7,   190,   187,   187,    96,  1460,  1293,   132,
     187,   232,  1242,   184,   232,   156,   236,   232,   232,   187,
    1242,   187,  1207,  1253,   106,   187,   106,   147,  1253,    78,
     249,  1253,  1317,   186,   197,    29,    29,   345,   187,   281,
     348,  1326,  1272,   187,  1329,   249,  1253,  1272,   187,   187,
    1272,   187,   285,   187,   187,   187,   107,   170,   147,   270,
     184,   126,  1292,   147,   126,  1272,    96,   184,  1253,   108,
    1292,   186,    94,    94,   186,   153,   186,   186,   184,   184,
     184,    29,    96,   147,   315,  1292,   187,  1272,   187,   170,
      53,    94,   186,   186,  1324,  1325,   196,    94,    29,  1384,
     197,   107,  1324,  1325,   187,   107,   256,  1292,   118,   118,
      94,   186,    94,   186,   422,   423,   224,  1324,   426,   196,
     196,   224,   430,   118,   264,   433,   434,  1412,   186,   236,
     183,    93,   118,   441,  1587,   196,   279,   118,   186,   447,
     286,   186,   450,   304,   186,  1598,  1599,   118,  1601,  1164,
     458,   198,   224,  1438,  1439,  1608,   464,   465,   466,   467,
     251,   286,   304,   715,   472,   292,   254,   304,   941,   254,
     305,  1008,   480,   417,  1204,   437,  1669,   305,  1714,  1464,
     849,  1466,  1005,   305,  1469,  1321,  1322,  1323,   257,  1441,
    1213,   771,  1232,  1343,   539,  1348,  1481,  1101,  1254,  1346,
    1259,  1486,  1262,  1267,   637,   657,   638,  1286,  1738,   811,
     690,  1732,   333,   906,  1198,   990,  1163,   525,   445,  1317,
    1361,  1327,  1536,  1372,  1111,  1326,  1533,  1365,  1186,  1120,
    1460,   539,   973,  1407,  1560,  1688,  1362,    -1,  1460,    -1,
     445,    -1,   550,    -1,    -1,    -1,    -1,    -1,  1701,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1726,    -1,    -1,    -1,    -1,    -1,    -1,
     588,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1758,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1602,    -1,  1604,
      -1,  1606,    -1,    -1,    -1,    -1,    -1,  1780,  1613,    -1,
      -1,    -1,  1785,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1587,    -1,    -1,
      -1,    -1,  1647,    -1,  1649,  1587,    -1,    -1,  1598,  1599,
      -1,  1601,    -1,    -1,    -1,    -1,  1598,  1599,  1608,  1601,
    1665,    -1,    -1,  1668,    -1,    -1,  1608,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1680,    -1,    -1,    -1,    -1,
      -1,   709,    -1,    -1,   712,  1690,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   726,    -1,
      -1,    -1,   730,   731,    -1,  1710,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1718,    -1,    -1,    -1,    -1,  1723,    -1,
    1725,    -1,  1727,    -1,   752,    -1,   754,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   762,    -1,    -1,   765,  1688,    -1,
      -1,   769,    -1,    -1,    -1,    -1,  1688,    -1,    -1,    -1,
    1755,  1701,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1701,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1772,    -1,    -1,
      -1,  1776,    -1,  1629,    -1,    -1,  1726,    -1,    -1,    -1,
      -1,    -1,   810,    -1,  1726,    -1,    -1,  1792,    -1,  1645,
    1795,    -1,   551,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1758,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1758,   576,   577,    -1,
     848,   580,   581,   582,   583,    -1,   585,    -1,    -1,    -1,
    1780,    -1,   591,    -1,    -1,  1785,    -1,    -1,  1780,    -1,
     599,    -1,    -1,  1785,    -1,   873,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     619,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   627,   628,
      -1,    -1,    -1,    -1,    -1,   903,   904,   905,   906,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   940,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   954,    -1,   687,    -1,
      -1,   690,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   979,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     988,    -1,   990,    -1,    -1,    -1,   994,    -1,    -1,   728,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1007,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   770,  1040,    -1,  1042,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   795,    -1,    -1,    -1,
     799,   800,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   808,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1126,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   875,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   942,    -1,  1213,    -1,    -1,  1216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1240,    -1,    -1,    -1,    -1,    -1,   977,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1264,   996,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1018,
      -1,    -1,    -1,    -1,    -1,  1293,    -1,    -1,    -1,    -1,
    1029,  1030,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1044,    -1,    -1,  1047,  1317,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1326,    -1,
      -1,  1329,    -1,  1062,    -1,  1064,  1065,  1066,    -1,  1068,
    1069,  1070,  1071,  1072,  1073,  1074,  1075,    -1,    -1,  1078,
    1079,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1092,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1384,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1412,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1438,  1439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1464,    -1,  1466,    -1,
      -1,  1469,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1481,    -1,    -1,    -1,    -1,  1486,  1218,
      -1,  1220,    -1,  1222,    -1,    -1,  1225,    -1,    -1,    -1,
      -1,  1230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1251,    -1,    -1,    -1,    -1,    -1,  1257,  1258,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1276,    -1,    -1,
    1279,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1602,    -1,  1604,    -1,  1606,    -1,
      -1,    -1,    -1,    -1,    -1,  1613,    -1,  1346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1647,
      -1,  1649,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1665,    -1,    -1,
    1668,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1680,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1690,    -1,    -1,    -1,  1425,    -1,    -1,    -1,
    1429,    -1,    -1,    -1,  1433,    -1,  1435,    -1,  1437,    -1,
      -1,    -1,  1710,    -1,  1443,    -1,    -1,    -1,    -1,    -1,
    1718,    -1,  1451,    -1,    -1,  1723,    -1,  1725,    -1,  1727,
    1459,  1460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1478,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1755,    -1,    -1,
      -1,  1490,  1491,  1492,  1493,    -1,    -1,  1496,  1497,    -1,
    1499,    -1,    -1,    -1,  1772,    -1,    -1,    -1,  1776,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1792,    -1,    -1,  1795,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1575,    -1,  1577,    -1,
      -1,  1580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1588,
      -1,    -1,    -1,    -1,  1593,  1594,    -1,    -1,    -1,    -1,
      -1,    -1,  1601,    -1,    -1,    -1,  1605,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1621,  1622,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1672,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1684,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1726,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1744,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1753,    -1,    -1,    -1,    -1,  1758,
      11,    12,    -1,    -1,  1763,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    -1,
    1779,    -1,    33,    34,  1783,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
     191,   192,   193,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
     311,    -1,   313,   314,   315,    -1,   317,   318,   319,   320,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,
     191,   192,   193,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
     311,    -1,   313,   314,   315,    -1,   317,   318,   319,    11,
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
     192,   193,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,   210,   211,
     212,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    -1,   311,
      -1,   313,   314,   315,    -1,   317,   318,   319,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,   192,
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,   311,    -1,
     313,   314,   315,    -1,   317,   318,   319,    11,    12,    -1,
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
     184,    -1,   186,    -1,   188,   189,    -1,   191,   192,   193,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,   212,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,   311,    -1,   313,
     314,   315,    -1,   317,   318,   319,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,   124,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,   191,   192,   193,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,   311,    -1,   313,   314,
     315,    -1,   317,   318,   319,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
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
     186,    -1,   188,   189,    -1,   191,   192,   193,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,   210,   211,   212,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,    -1,   311,    -1,   313,   314,   315,
      -1,   317,   318,   319,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,   191,   192,   193,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,   311,    -1,   313,   314,   315,    -1,
     317,   318,   319,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     188,   189,    -1,   191,   192,   193,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,   210,   211,   212,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,    -1,   311,    -1,   313,   314,   315,    -1,   317,
     318,   319,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
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
     189,    -1,   191,   192,   193,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,   311,    -1,   313,   314,   315,    -1,   317,   318,
     319,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,   191,   192,   193,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
     210,   211,   212,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      -1,   311,    -1,   313,   314,   315,    -1,   317,   318,   319,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,    -1,   185,   186,    -1,   188,   189,    -1,
     191,   192,   193,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
     311,    -1,   313,   314,   315,    -1,   317,   318,   319,    11,
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
     192,   193,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,   210,   211,
     212,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    -1,   311,
      -1,   313,   314,   315,    -1,   317,   318,   319,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,    -1,
     313,   314,   315,    -1,   317,   318,   319,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
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
      -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,   193,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,   212,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,   311,   312,   313,
     314,   315,    -1,   317,   318,   319,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,   124,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,   184,
      -1,   186,    -1,   188,   189,    -1,   191,   192,   193,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,   311,    -1,   313,   314,
     315,    -1,   317,   318,   319,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
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
     186,   187,   188,   189,    -1,   191,   192,   193,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,   210,   211,   212,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,    -1,   311,    -1,   313,   314,   315,
      -1,   317,   318,   319,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,   189,    -1,   191,   192,   193,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,   311,    -1,   313,   314,   315,    -1,
     317,   318,   319,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     188,   189,    -1,   191,   192,   193,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,   210,   211,   212,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,    -1,   311,    -1,   313,   314,   315,    -1,   317,
     318,   319,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
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
     189,    -1,   191,   192,   193,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,   311,    -1,   313,   314,   315,    -1,   317,   318,
     319,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,   191,   192,   193,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
     210,   211,   212,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      -1,   311,    -1,   313,   314,   315,    -1,   317,   318,   319,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
     191,   192,   193,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
     311,    -1,   313,   314,   315,    -1,   317,   318,   319,    11,
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
      -1,   193,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,   210,   211,
     212,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    -1,   311,
      -1,   313,   314,   315,    -1,   317,   318,   319,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,    -1,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,    -1,   151,   152,
     153,   154,    -1,   156,   157,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
     193,    -1,   195,    -1,   197,    -1,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,   311,    -1,
     313,   314,   315,    -1,   317,   318,   319,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
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
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,   193,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,    -1,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    -1,    -1,    11,    12,   313,
     314,   315,    -1,   317,   318,   319,    20,    -1,    -1,    -1,
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
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,   193,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,    -1,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    -1,    -1,    -1,    16,   313,
     314,   315,    -1,   317,   318,   319,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,
     188,   189,    -1,    -1,    -1,    -1,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,   210,   211,    -1,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,    -1,    -1,    -1,    16,   313,   314,   315,    -1,   317,
     318,   319,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,   210,   211,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    -1,    -1,    -1,
      -1,   313,   314,   315,    -1,   317,   318,   319,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    -1,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,
     150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,    -1,    -1,    -1,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
     210,   211,    -1,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    -1,
      -1,    -1,    -1,   313,   314,   315,    -1,   317,   318,   319,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    -1,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
     311,    -1,   313,   314,   315,    -1,   317,   318,   319,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
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
      -1,   156,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,   187,   188,   189,    -1,    -1,    -1,   193,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,   210,   211,    -1,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    -1,    -1,    24,    25,   313,   314,
     315,   316,   317,   318,   319,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,    -1,   150,   151,   152,    -1,    -1,    -1,   156,    -1,
      -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,   210,   211,    -1,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,    -1,    -1,    24,    25,   313,   314,   315,   316,   317,
     318,   319,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    -1,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,    -1,    -1,    -1,   156,    -1,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    -1,    -1,
      24,    25,   313,   314,   315,   316,   317,   318,   319,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,    -1,   150,   151,   152,    -1,
      -1,    -1,   156,    -1,    -1,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,    -1,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    -1,    -1,    24,    25,   313,
     314,   315,   316,   317,   318,   319,    33,    34,    -1,    36,
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
     187,   188,   189,    -1,    -1,    -1,   193,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,   210,   211,    -1,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    -1,    -1,    24,    25,   313,   314,   315,    -1,
     317,   318,   319,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    -1,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,
     150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,   187,   188,   189,
      -1,    -1,    -1,   193,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
     210,   211,    -1,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    -1,
      -1,    24,    25,   313,   314,   315,    -1,   317,   318,   319,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    -1,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,   152,
      -1,    -1,    -1,   156,    -1,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,    -1,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    -1,    -1,    24,    25,
     313,   314,   315,   316,   317,   318,   319,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,
     156,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,   210,   211,    -1,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    -1,    -1,    24,    25,   313,   314,   315,
     316,   317,   318,   319,    33,    34,    -1,    36,    37,    38,
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
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,    -1,    -1,    -1,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,   210,   211,    -1,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      -1,    -1,    24,    25,   313,   314,   315,    -1,   317,   318,
     319,    33,    34,    -1,    36,    37,    38,    -1,    40,    41,
      42,    43,    -1,    -1,    46,    47,    -1,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    -1,    60,    -1,
      -1,    63,    64,    65,    66,    67,    -1,    69,    -1,    71,
      -1,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    -1,    -1,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,    -1,   211,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    -1,    -1,    -1,
      -1,   313,   314,   315,    -1,   317,   318,   319
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
     188,   189,   191,   192,   193,   195,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   210,   211,   212,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   258,   259,   260,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   311,   313,   314,   315,   317,   318,
     319,   320,   332,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     353,   354,   355,   356,   357,   358,   362,   363,   364,   368,
     370,   371,   373,   380,   382,   385,   386,   387,   389,   390,
     391,   392,   393,   395,   396,   398,   399,   400,   401,   402,
     403,   405,   406,   409,   410,   411,   412,   417,   419,   421,
     422,   427,   446,   449,   453,   456,   457,   462,   463,   464,
     465,   467,   468,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   514,   515,   516,   530,   531,   533,   534,   535,
     536,   537,   538,   539,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   559,   560,   561,   562,   567,   568,
     569,   570,   571,   572,   575,   633,   635,   636,   637,   638,
     639,   640,   641,   642,   649,   650,   651,    33,    34,    49,
     214,   388,   389,   390,   388,   388,   156,   156,    37,    38,
      40,    41,    47,    56,    57,    74,    79,   111,   112,   113,
     160,   219,   260,   286,   294,   302,   369,   370,   374,   375,
     376,   160,   153,   156,   153,   156,   153,   156,    66,    71,
     118,   414,   156,   377,   156,    24,    34,    60,   118,   272,
     426,   428,   429,   153,   156,   156,   156,   118,   153,   156,
     156,   156,    76,   153,   220,   221,   122,   122,   122,   153,
     156,    39,    43,    45,    46,    47,    48,    51,    59,    67,
      70,    72,    73,    75,    90,    91,    97,   105,   112,   114,
     115,   135,   138,   139,   169,   172,   180,   181,   189,   201,
     223,   225,   227,   228,   235,   237,   238,   239,   242,   243,
     314,   498,   649,   650,   122,   118,   397,   122,   122,    39,
      44,    45,    59,    61,    62,    70,    97,   224,   649,   118,
     122,   122,   184,   388,   390,   410,   634,    48,    72,    73,
     118,   153,   185,   243,   409,   411,   421,   187,   409,   649,
     153,   122,    16,   648,   649,    18,    19,   649,   122,   122,
     122,   490,   153,    30,   213,   215,   224,   226,   313,   156,
     224,   226,   313,   224,   313,   224,   229,   313,   118,   240,
     240,   241,   156,   153,   392,   310,   409,   312,   409,   313,
     334,     0,   336,   337,    33,    49,   339,   356,     1,   190,
     333,   190,   333,   112,   371,   391,   409,   107,   190,   107,
     190,    42,    46,    51,    69,   168,   171,   186,   211,   404,
     413,   418,   419,   420,   434,   435,   439,   167,    92,   132,
     140,   141,   143,   151,   155,   157,   162,   179,   202,   203,
     204,   205,   206,   207,   482,   483,   248,    99,   158,   176,
     198,   117,   146,   159,   193,   200,   209,   136,   150,    50,
     199,   101,   102,   158,   176,   481,   153,   487,   490,   191,
     192,   154,   502,   503,   498,   502,   498,   156,   502,   145,
     156,   184,   184,   184,   372,   505,   372,    29,   647,   182,
     195,   182,   195,   166,   182,   650,   649,   169,   201,    47,
     649,   152,   118,    45,    47,    79,   106,   168,   648,   220,
     221,   222,   245,   606,   649,   649,   303,   137,   142,   112,
     286,   294,   374,   648,   389,   390,   187,   389,    45,    62,
     187,   555,   556,   409,   187,   193,   649,   283,   283,   423,
     424,   649,   118,   430,   118,   187,   378,   379,   153,   394,
     409,     1,   160,   647,   113,   160,   352,   647,   649,   118,
     142,   107,   409,    29,   187,   648,   649,   649,   447,   448,
     649,   389,   187,   409,   409,   557,   649,   389,   153,   153,
     409,   187,   193,   649,   649,   142,   447,   184,   184,   121,
     107,   184,   156,   156,   156,   649,   153,   185,   186,   187,
      35,   518,   519,   520,   409,     8,   175,    17,   409,   213,
      29,   410,   410,    39,    45,    59,    70,    97,   504,   649,
     187,   410,   410,   410,   410,   504,   410,   230,   229,   573,
     574,   649,   190,   190,   410,   409,   390,   409,   244,   407,
     408,   310,   312,   410,   190,   333,   190,   333,     3,   340,
     356,   386,   340,   356,   386,    33,   357,   386,   357,   386,
     397,   397,   410,   118,   168,   170,   170,   391,   410,   410,
     464,   465,   467,   467,   467,   467,   466,   467,   467,   467,
      70,   468,   472,   472,   471,   473,   473,   473,   473,   474,
     474,   475,   475,   230,    94,    94,    94,   184,   409,   490,
     490,   409,   503,   187,   410,   513,   149,   187,   513,   107,
     187,   187,   107,   107,   377,    29,   650,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,   359,   360,   361,
      94,   137,   142,   365,   366,   367,   649,   160,   160,   359,
     647,   127,   132,    54,    56,   100,   250,   263,   265,   276,
     277,   278,   280,   282,   607,   608,   609,   610,   611,   612,
     619,   625,   626,   245,    94,   298,   649,   142,   410,   118,
     649,   649,   132,   184,   184,   187,   187,   184,   107,   187,
     107,   187,   107,    36,    94,    96,   147,   425,   426,   541,
     649,    55,   216,   253,   415,   416,   649,    94,   107,   187,
     388,   187,   648,    96,    45,   648,   647,    96,   142,   541,
     649,   410,   429,   184,   187,   187,   187,   187,   107,   188,
     147,   541,   184,   187,   187,   153,   184,   389,   389,   184,
     107,   187,   107,   187,   142,   541,   410,   188,   410,   410,
     409,   409,   409,   649,   519,   520,   130,   196,   184,   184,
     131,   190,   156,    94,   217,   218,   232,    94,   217,   218,
     232,   232,    94,   156,   236,   224,   230,   107,   234,   142,
     190,   187,    48,    72,    73,   243,   411,   421,   184,   499,
     579,   408,   198,   356,    33,    33,   190,   333,   190,   113,
     649,   170,   410,   440,   441,   118,   436,   437,   467,   153,
     156,   258,   486,   505,   580,   583,   584,   585,   586,   587,
     591,   593,   595,   596,    47,   152,   156,   210,   316,   317,
     318,   319,   542,   544,   546,   547,   563,   564,   565,   566,
     643,   644,   645,   646,   649,   542,   540,   546,   540,   184,
     185,   107,   187,   187,   505,   148,   165,   148,   165,   137,
     394,   377,   360,   132,   544,   367,   410,   541,   647,   647,
     128,   129,   647,   276,   277,   278,   282,   649,   262,   273,
     262,   273,    29,   285,    96,   113,   156,   613,   616,   607,
      39,    44,    59,    61,    70,    97,   224,   381,   547,   226,
     298,   307,   410,   649,    94,   298,   647,   153,   557,   558,
     649,   557,   558,   118,   127,   542,   118,   410,   147,   426,
     147,    36,   147,   425,   426,   147,   541,   253,    53,    58,
      77,   118,   425,   431,   432,   433,   416,   541,   542,   379,
      94,   184,   197,   132,   351,   647,   160,   132,    96,   351,
     410,   142,   426,   153,   118,   410,   410,   147,   100,   450,
     451,   452,   454,   455,   100,   458,   459,   460,   461,   389,
     184,   184,   153,   557,   557,   410,   142,   190,   410,   121,
     187,   187,   187,    35,   520,   130,   196,     9,    10,   103,
     123,   125,   153,   194,   515,   517,   528,   529,   532,    29,
     410,   231,   233,   410,   410,   410,   231,   233,   410,   410,
     410,   410,   410,   410,   410,   410,   504,   118,   410,   410,
     391,   156,   156,   156,   153,   186,   244,   576,   577,   209,
     392,   410,   190,   113,   386,   386,   386,   440,    95,   106,
     116,   127,   442,   443,   444,   445,   107,   649,   107,   409,
     580,   587,   153,   284,   469,   632,    96,   169,   251,   252,
     254,   261,   271,   283,   581,   582,   601,   602,   603,   604,
     627,   630,   257,   259,   588,   606,   266,   592,   628,   246,
     247,   269,   597,   598,   156,   156,   544,   156,   156,   156,
     156,   156,   144,   176,   193,   543,   144,   410,   137,   394,
     559,   366,   285,    29,    96,   113,   156,   620,    29,   613,
     543,   488,   286,   305,   541,   381,   226,   190,   388,   187,
     187,   144,   187,   187,   424,   147,   425,   649,   410,   147,
     410,   127,   410,   147,   426,   147,   410,   147,   118,   118,
     410,   649,   433,    77,   542,   391,   410,   647,   107,   351,
     410,   142,   388,   448,   410,   410,   113,   451,   452,   100,
     186,   113,   452,   455,   118,   542,   100,   113,   459,   100,
     113,   461,   184,   388,   187,   187,   410,   410,   197,   458,
     132,   194,   517,     7,   389,   649,   194,   528,   190,   187,
     232,   232,   232,   232,    96,   187,   236,   156,   574,   186,
     409,   409,   409,   579,   577,   499,   647,   128,   129,   444,
     445,   445,   441,   106,   438,   437,   184,   187,   580,   594,
     249,   216,   253,   267,   274,   631,    96,   255,   256,   629,
     249,   584,   631,   471,   601,   585,   147,   281,   589,   590,
     629,   285,   600,    78,   599,   187,   193,   542,   545,   187,
     187,   187,   187,   187,   187,   187,    29,   136,   200,   622,
     623,   624,    29,   621,   622,   270,   617,   107,   614,   170,
     649,   256,   488,   184,   410,   147,   410,   147,   425,   410,
     147,   410,   410,   649,   649,   432,   410,   126,   126,    96,
     647,   410,   184,   186,   186,   410,   391,   410,   186,   186,
     649,   186,   118,   542,   118,   186,   118,   542,   186,   184,
     113,   520,   649,   194,   184,   520,   649,   410,   410,   410,
     410,   315,    94,   410,   410,   410,   187,   187,   187,   153,
     578,   445,   647,   184,   473,    52,   129,   471,   471,   268,
     275,   285,   605,   605,   586,   153,   279,    94,   187,   107,
     187,   620,   620,   624,   107,   187,    29,   618,   629,   615,
     616,   187,   383,   384,   488,   118,   224,   306,   286,   170,
     410,   410,   147,   410,    53,   391,   410,   351,   410,   391,
      94,   391,   410,   649,   186,   649,   410,   649,   186,   391,
     118,    93,   183,   521,   520,   649,   196,   520,   410,   410,
     187,   197,   458,   409,   471,   471,   198,   409,   542,   542,
      94,    29,   264,   107,   107,   445,   541,   649,   118,   224,
     649,   383,   410,   118,   542,    94,   186,    94,   649,     5,
     133,   524,   525,   527,   529,    28,   134,   522,   523,   526,
     529,   196,   520,   196,   236,   113,   184,   471,   184,   542,
     616,   384,   445,   304,   649,   118,   224,   649,   186,   542,
     391,   410,   542,   186,    93,   133,   527,   183,   134,   526,
     196,   410,   118,   410,   304,   649,   118,   391,   410,   186,
     186,   649,   292,   304,   649,   186,   305,   410,   305,   488,
     488,   198,   286,   649,   224,   118,   649,   305,   488
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
     585
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   331,   332,   332,   333,   334,   334,   334,   334,   335,
     335,   336,   336,   336,   336,   336,   336,   336,   336,   337,
     337,   337,   337,   338,   339,   339,   339,   340,   340,   340,
     340,   340,   341,   341,   341,   341,   341,   341,   341,   341,
     342,   342,   343,   344,   345,   345,   346,   346,   347,   347,
     348,   348,   348,   348,   349,   349,   349,   350,   350,   350,
     350,   351,   351,   352,   352,   353,   353,   353,   353,   354,
     355,   355,   356,   356,   356,   357,   357,   357,   357,   357,
     357,   357,   357,   358,   358,   359,   359,   360,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   362,   363,
     364,   365,   365,   366,   366,   366,   367,   368,   368,   368,
     369,   369,   369,   369,   370,   370,   371,   371,   371,   371,
     372,   372,   373,   373,   374,   374,   375,   375,   376,   376,
     377,   377,   377,   377,   378,   378,   379,   379,   380,   380,
     380,   380,   381,   381,   382,   382,   383,   383,   384,   384,
     384,   384,   385,   385,   385,   385,   386,   387,   387,   387,
     388,   388,   388,   389,   389,   390,   390,   391,   391,   391,
     391,   391,   391,   391,   391,   391,   391,   391,   391,   392,
     392,   393,   394,   395,   396,   396,   396,   397,   397,   397,
     397,   398,   399,   400,   401,   402,   402,   403,   404,   405,
     406,   407,   407,   408,   409,   409,   410,   410,   410,   410,
     410,   410,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   412,   413,   414,   414,   415,   415,
     415,   416,   416,   417,   417,   418,   419,   419,   419,   420,
     420,   420,   420,   420,   421,   421,   422,   423,   423,   424,
     424,   424,   424,   424,   424,   424,   424,   424,   424,   424,
     424,   425,   426,   427,   428,   428,   429,   429,   429,   429,
     430,   430,   431,   431,   431,   432,   432,   432,   433,   433,
     433,   434,   435,   436,   436,   437,   437,   438,   439,   439,
     440,   440,   441,   441,   442,   442,   442,   442,   442,   442,
     442,   443,   443,   444,   444,   445,   446,   446,   447,   447,
     448,   448,   449,   450,   450,   451,   452,   452,   453,   454,
     454,   455,   456,   456,   457,   457,   458,   458,   459,   459,
     460,   460,   461,   461,   462,   463,   463,   464,   464,   465,
     465,   465,   465,   465,   466,   465,   465,   465,   465,   467,
     467,   468,   468,   469,   469,   470,   470,   471,   471,   471,
     472,   472,   472,   472,   472,   473,   473,   473,   474,   474,
     474,   475,   475,   476,   476,   477,   477,   478,   478,   479,
     479,   480,   480,   480,   480,   481,   481,   481,   482,   482,
     482,   482,   482,   482,   483,   483,   483,   484,   484,   484,
     484,   485,   485,   486,   486,   487,   487,   487,   488,   488,
     488,   488,   489,   490,   490,   490,   491,   491,   492,   492,
     492,   492,   493,   493,   494,   494,   494,   494,   494,   494,
     494,   495,   495,   496,   496,   497,   497,   497,   497,   497,
     498,   498,   499,   499,   500,   500,   500,   500,   501,   501,
     501,   501,   502,   502,   503,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   505,
     505,   506,   506,   506,   507,   508,   508,   509,   510,   511,
     512,   512,   513,   513,   514,   514,   515,   515,   515,   516,
     516,   516,   516,   516,   516,   517,   517,   518,   518,   519,
     520,   520,   521,   521,   522,   522,   523,   523,   523,   523,
     524,   524,   525,   525,   525,   525,   526,   526,   527,   527,
     528,   528,   528,   528,   529,   529,   529,   529,   530,   530,
     531,   531,   532,   533,   533,   533,   533,   533,   533,   534,
     535,   535,   536,   536,   537,   538,   539,   539,   540,   540,
     541,   542,   542,   542,   543,   543,   543,   544,   544,   544,
     544,   544,   544,   544,   545,   545,   546,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   548,   549,   549,   549,
     550,   551,   552,   552,   552,   553,   553,   553,   553,   553,
     554,   555,   555,   555,   555,   555,   555,   555,   556,   557,
     558,   559,   560,   560,   561,   562,   563,   563,   564,   565,
     565,   566,   567,   567,   567,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   569,   569,   570,   570,   571,
     572,   573,   573,   574,   575,   576,   576,   577,   578,   579,
     579,   580,   581,   581,   582,   582,   583,   583,   584,   584,
     585,   585,   586,   586,   587,   588,   588,   589,   589,   590,
     591,   591,   591,   592,   592,   593,   594,   594,   595,   596,
     596,   597,   597,   598,   598,   598,   599,   599,   600,   600,
     601,   601,   601,   601,   601,   602,   603,   604,   605,   605,
     605,   606,   606,   607,   607,   607,   607,   607,   607,   607,
     607,   608,   608,   608,   608,   609,   609,   610,   611,   611,
     612,   612,   612,   613,   613,   614,   614,   615,   615,   616,
     617,   617,   618,   618,   619,   619,   619,   620,   620,   621,
     621,   622,   622,   623,   623,   624,   624,   625,   626,   626,
     627,   627,   627,   628,   629,   629,   629,   629,   630,   630,
     631,   631,   632,   633,   634,   634,   635,   635,   636,   636,
     637,   637,   638,   638,   639,   640,   641,   642,   643,   643,
     643,   644,   645,   646,   647,   648,   648,   649,   649,   649,
     649,   649,   649,   649,   649,   649,   649,   649,   649,   649,
     649,   649,   649,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   651
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     2,     1,     2,     1,     2,     4,
       6,     3,     3,     5,     1,     3,     3,     5,     5,     1,
       3,     3,     5,     6,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     3,     3,     3,     3,     3,     5,     5,
       5,     5,     5,     5,     1,     1,     3,     3,     4,     5,
       6,     1,     3,     3,     3,     3,     6,     5,     8,     5,
       5,     5,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       4,     3,     1,     1,     1,     2,     2,     4,     3,     5,
       3,     4,     4,     5,     1,     2,     1,     4,     1,     4,
       1,     3,     2,     3,     1,     1,     4,     4,     5,     5,
       2,     3,     4,     5,     1,     3,     2,     3,     3,     5,
       4,     6,     1,     2,     8,     9,     1,     3,     1,     2,
       2,     3,    11,    14,    13,    22,     1,     1,     1,     0,
       1,     1,     0,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     3,     2,     3,     2,     3,     2,     3,     4,
       5,     5,     2,     4,     5,     3,     3,     2,     2,     8,
       3,     1,     2,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     1,
       2,     4,     3,     5,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     1,     4,     3,
       5,     4,     6,     4,     6,     5,     7,     4,     5,     5,
       6,     3,     3,     2,     1,     3,     4,     5,     3,     6,
       4,     5,     1,     2,     3,     1,     2,     1,     6,     3,
       3,     2,     3,     1,     3,     2,     3,     2,     3,     4,
       1,     3,     1,     2,     1,     1,     1,     2,     2,     2,
       3,     1,     1,     2,     2,     2,     5,     5,     1,     4,
       3,     4,     8,     1,     2,     3,     2,     3,     8,     1,
       2,     3,     8,    10,     8,    10,     1,     2,     4,     7,
       1,     2,     4,     7,     8,     1,     3,     1,     3,     1,
       3,     3,     3,     3,     0,     4,     3,     3,     3,     1,
       5,     1,     3,     0,     1,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     4,     1,     4,     1,     4,     1,     4,     1,
       2,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     5,     5,
       6,     3,     4,     1,     2,     3,     2,     2,     1,     2,
       2,     1,     1,     1,     3,     3,     1,     1,     1,     2,
       1,     2,     2,     1,     2,     2,     2,     2,     2,     2,
       2,     1,     2,     2,     1,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     4,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     3,     1,     4,     4,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     4,
       5,     8,     9,     9,    10,     1,     2,     1,     2,     6,
       0,     1,     3,     3,     0,     1,     1,     1,     2,     2,
       0,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     4,
       3,     7,     3,     7,     4,     4,     3,     7,     1,     2,
       2,     1,     2,     3,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
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
       1,     1,     3,     3,     3,     5,     2,     3,     2,     3,
       2,     3,     5,     8,     6,     8,    10,     5,     1,     1,
       1,     3,     3,     3,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
  "\"'*'\"", "\"'</ (start tag end)'\"", "\"'strip'\"",
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
  "\"'BOM_UTF8'\"", "RANGE_REDUCE", "SEQUENCE_TYPE_REDUCE",
  "ADDITIVE_REDUCE", "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE",
  "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR", "UNARY_PREC", "STEP_REDUCE",
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
  "IfExpr", "OrExpr", "AndExpr", "ComparisonExpr", "$@1", "FTContainsExpr",
  "StringConcatExpr", "opt_FTIgnoreOption", "RangeExpr", "AdditiveExpr",
  "MultiplicativeExpr", "UnionExpr", "IntersectExceptExpr",
  "InstanceofExpr", "TreatExpr", "CastableExpr", "CastExpr", "UnaryExpr",
  "SignList", "ValueExpr", "ValueComp", "NodeComp", "ValidateExpr",
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
  "CompCommentConstructor", "CompPIConstructor", "SingleType",
  "TypeDeclaration", "SequenceType", "OccurrenceIndicator", "ItemType",
  "TypeList", "AtomicType", "KindTest", "AnyKindTest", "DocumentTest",
  "TextTest", "CommentTest", "PITest", "AttributeTest",
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
  "FTIgnoreOption", "JSONObjectConstructor", "JSONPairList",
  "JSONArrayConstructor", "JSONSimpleObjectUnion",
  "JSONAccumulatorObjectUnion", "JSONInsertExpr", "JSONDeleteExpr",
  "JSONRenameExpr", "JSONReplaceExpr", "JSONAppendExpr", "JSONTest",
  "JSONItemTest", "JSONObjectTest", "JSONArrayTest", "URI_LITERAL",
  "NCNAME", "QNAME", "FUNCTION_NAME", "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       332,     0,    -1,   334,    -1,   320,   334,    -1,     1,     3,
      -1,   336,    -1,   335,   336,    -1,   337,    -1,   335,   337,
      -1,   214,   215,    29,   190,    -1,   214,   215,    29,   131,
      29,   190,    -1,   339,   190,   386,    -1,   356,   190,   386,
      -1,   339,   190,   356,   190,   386,    -1,   386,    -1,   339,
     333,   386,    -1,   356,   333,   386,    -1,   339,   190,   356,
     333,   386,    -1,   339,   333,   356,   190,   386,    -1,   338,
      -1,   338,   339,   190,    -1,   338,   356,   190,    -1,   338,
     339,   190,   356,   190,    -1,    34,   160,   648,   132,   647,
     190,    -1,   340,    -1,   339,   190,   340,    -1,   339,   333,
     340,    -1,   341,    -1,   349,    -1,   354,    -1,   355,    -1,
     363,    -1,   342,    -1,   343,    -1,   344,    -1,   345,    -1,
     346,    -1,   347,    -1,   348,    -1,   567,    -1,    33,    38,
     182,    -1,    33,    38,   195,    -1,    33,   113,   106,   647,
      -1,    33,    37,   647,    -1,    33,    40,   182,    -1,    33,
      40,   195,    -1,    33,    57,   169,    -1,    33,    57,   201,
      -1,    33,   113,   168,   127,   128,    -1,    33,   113,   168,
     127,   129,    -1,    33,    41,   182,   107,   148,    -1,    33,
      41,   182,   107,   165,    -1,    33,    41,   166,   107,   148,
      -1,    33,    41,   166,   107,   165,    -1,   350,    -1,   353,
      -1,    49,    24,     1,    -1,    49,    60,   647,    -1,    49,
      60,   352,   647,    -1,    49,    60,   647,    96,   351,    -1,
      49,    60,   352,   647,    96,   351,    -1,   647,    -1,   351,
     107,   647,    -1,   160,   648,   132,    -1,   113,    45,   160,
      -1,    49,    34,   647,    -1,    49,    34,   160,   648,   132,
     647,    -1,    49,    34,   647,    96,   351,    -1,    49,    34,
     160,   648,   132,   647,    96,   351,    -1,    33,   160,   648,
     132,   647,    -1,    33,   113,    45,   160,   647,    -1,    33,
     113,    47,   160,   647,    -1,   357,    -1,   356,   190,   357,
      -1,   356,   333,   357,    -1,   358,    -1,   362,    -1,   364,
      -1,   368,    -1,   373,    -1,   380,    -1,   382,    -1,   385,
      -1,    33,   113,    79,   359,    -1,    33,    79,   649,   359,
      -1,   360,    -1,   359,   360,    -1,   361,   132,   559,    -1,
      80,    -1,    88,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    89,    -1,    85,    -1,    86,    -1,    87,    -1,
      33,    56,   649,    29,    -1,    33,   260,   606,    -1,    33,
     111,   152,   365,    -1,    94,   544,   366,    -1,   366,    -1,
     367,    -1,   137,    -1,   137,   367,    -1,   142,   410,    -1,
      33,   369,   142,   410,    -1,    33,   369,   137,    -1,    33,
     369,   137,   142,   410,    -1,   112,   118,   649,    -1,   112,
     118,   649,   541,    -1,   370,   112,   118,   649,    -1,   370,
     112,   118,   649,   541,    -1,   371,    -1,   370,   371,    -1,
      26,    -1,    26,   156,   372,   187,    -1,    27,    -1,    27,
     156,   372,   187,    -1,   505,    -1,   372,   107,   505,    -1,
      33,   374,    -1,    33,   370,   374,    -1,   375,    -1,   376,
      -1,    47,   650,   377,   394,    -1,    47,   650,   377,   137,
      -1,    74,    47,   650,   377,   394,    -1,    74,    47,   650,
     377,   137,    -1,   156,   187,    -1,   156,   378,   187,    -1,
     156,   187,    94,   542,    -1,   156,   378,   187,    94,   542,
      -1,   379,    -1,   378,   107,   379,    -1,   118,   649,    -1,
     118,   649,   541,    -1,    33,   286,   649,    -1,    33,   286,
     649,    94,   381,    -1,    33,   370,   286,   649,    -1,    33,
     370,   286,   649,    94,   381,    -1,   547,    -1,   547,   543,
      -1,    33,   294,   649,   298,   226,   488,   170,   383,    -1,
      33,   370,   294,   649,   298,   226,   488,   170,   383,    -1,
     384,    -1,   383,   107,   384,    -1,   488,    -1,   488,   541,
      -1,   488,   445,    -1,   488,   541,   445,    -1,    33,   302,
     303,   649,   298,   286,   649,   118,   649,   304,   410,    -1,
      33,   302,   303,   649,   298,   286,   649,   224,   118,   649,
     304,   292,   305,   488,    -1,    33,   302,   303,   649,   298,
     286,   649,   306,   224,   118,   649,   304,   410,    -1,    33,
     302,   303,   649,   307,   305,   256,   286,   649,   224,   118,
     649,   305,   488,   198,   286,   649,   224,   118,   649,   305,
     488,    -1,   387,    -1,   389,    -1,   390,    -1,    -1,   389,
      -1,   390,    -1,    -1,   409,    -1,   390,   409,    -1,   391,
      -1,   390,   391,    -1,   392,    -1,   395,    -1,   398,    -1,
     399,    -1,   400,    -1,   401,    -1,   402,    -1,   403,    -1,
     405,    -1,   457,    -1,   453,    -1,   406,    -1,   153,   390,
     184,    -1,   153,   184,    -1,   153,   388,   184,    -1,   153,
     388,   184,    -1,   396,   190,    -1,   396,   107,   397,    -1,
     112,   397,    -1,   370,   112,   397,    -1,   118,   649,    -1,
     118,   649,   541,    -1,   118,   649,   142,   410,    -1,   118,
     649,   541,   142,   410,    -1,   118,   649,   142,   410,   190,
      -1,   411,   190,    -1,   239,   241,   410,   190,    -1,   242,
     156,   409,   187,   391,    -1,   237,   240,   190,    -1,   238,
     240,   190,    -1,   421,   404,    -1,   186,   391,    -1,    48,
     156,   409,   187,   197,   391,   126,   391,    -1,   243,   392,
     407,    -1,   408,    -1,   407,   408,    -1,   244,   579,   392,
      -1,   410,    -1,   409,   107,   410,    -1,   412,    -1,   449,
      -1,   456,    -1,   462,    -1,   575,    -1,   411,    -1,   463,
      -1,   446,    -1,   568,    -1,   569,    -1,   571,    -1,   570,
      -1,   572,    -1,   639,    -1,   638,    -1,   640,    -1,   641,
      -1,   642,    -1,   421,   413,    -1,   186,   410,    -1,    66,
     283,    -1,    71,   283,    -1,   216,    -1,   253,    -1,    55,
     253,    -1,   415,   431,    77,   410,    -1,   415,    77,   410,
      -1,    46,   414,   430,   416,   416,    -1,    46,   414,   430,
     416,    -1,    42,   118,   649,    -1,   422,    -1,   427,    -1,
     417,    -1,   419,    -1,   434,    -1,   439,    -1,   435,    -1,
     418,    -1,   419,    -1,   421,   420,    -1,    46,   118,   423,
      -1,   424,    -1,   423,   107,   118,   424,    -1,   649,   147,
     410,    -1,   649,    36,   127,   147,   410,    -1,   649,   541,
     147,   410,    -1,   649,   541,    36,   127,   147,   410,    -1,
     649,   425,   147,   410,    -1,   649,    36,   127,   425,   147,
     410,    -1,   649,   541,   425,   147,   410,    -1,   649,   541,
      36,   127,   425,   147,   410,    -1,   649,   426,   147,   410,
      -1,   649,   541,   426,   147,   410,    -1,   649,   425,   426,
     147,   410,    -1,   649,   541,   425,   426,   147,   410,    -1,
      96,   118,   649,    -1,   272,   118,   649,    -1,    51,   428,
      -1,   429,    -1,   428,   107,   429,    -1,   118,   649,   142,
     410,    -1,   118,   649,   541,   142,   410,    -1,   426,   142,
     410,    -1,   118,   649,   541,   426,   142,   410,    -1,   118,
     649,   147,   410,    -1,   118,   649,   541,   147,   410,    -1,
     432,    -1,   118,   649,    -1,   118,   649,   432,    -1,   425,
      -1,   425,   433,    -1,   433,    -1,    58,   118,   649,    53,
     118,   649,    -1,    53,   118,   649,    -1,    58,   118,   649,
      -1,   211,   410,    -1,   171,   170,   436,    -1,   437,    -1,
     436,   107,   437,    -1,   118,   649,    -1,   118,   649,   438,
      -1,   106,   647,    -1,   168,   170,   440,    -1,    69,   168,
     170,   440,    -1,   441,    -1,   440,   107,   441,    -1,   410,
      -1,   410,   442,    -1,   443,    -1,   444,    -1,   445,    -1,
     443,   444,    -1,   443,   445,    -1,   444,   445,    -1,   443,
     444,   445,    -1,    95,    -1,   116,    -1,   127,   128,    -1,
     127,   129,    -1,   106,   647,    -1,    67,   118,   447,   188,
     410,    -1,   135,   118,   447,   188,   410,    -1,   448,    -1,
     447,   107,   118,   448,    -1,   649,   147,   410,    -1,   649,
     541,   147,   410,    -1,    72,   156,   409,   187,   450,   113,
     186,   410,    -1,   451,    -1,   450,   451,    -1,   452,   186,
     410,    -1,   100,   410,    -1,   452,   100,   410,    -1,    72,
     156,   409,   187,   454,   113,   186,   391,    -1,   455,    -1,
     454,   455,    -1,   452,   186,   391,    -1,    73,   156,   409,
     187,   458,   113,   186,   410,    -1,    73,   156,   409,   187,
     458,   113,   118,   649,   186,   410,    -1,    73,   156,   409,
     187,   460,   113,   186,   391,    -1,    73,   156,   409,   187,
     458,   113,   118,   649,   186,   391,    -1,   459,    -1,   458,
     459,    -1,   100,   542,   186,   410,    -1,   100,   118,   649,
      94,   542,   186,   410,    -1,   461,    -1,   460,   461,    -1,
     100,   542,   186,   391,    -1,   100,   118,   649,    94,   542,
     186,   391,    -1,    48,   156,   409,   187,   197,   410,   126,
     410,    -1,   464,    -1,   463,   167,   464,    -1,   465,    -1,
     464,    92,   465,    -1,   467,    -1,   467,   482,   467,    -1,
     467,   483,   467,    -1,   467,   132,   467,    -1,   467,   162,
     467,    -1,    -1,   467,   157,   466,   467,    -1,   467,   155,
     467,    -1,   467,   143,   467,    -1,   467,   141,   467,    -1,
     468,    -1,   468,   248,    70,   580,   469,    -1,   470,    -1,
     470,    99,   468,    -1,    -1,   632,    -1,   471,    -1,   471,
     198,   471,    -1,   472,    -1,   471,   176,   472,    -1,   471,
     158,   472,    -1,   473,    -1,   472,   193,   473,    -1,   472,
     117,   473,    -1,   472,   146,   473,    -1,   472,   159,   473,
      -1,   474,    -1,   473,   200,   474,    -1,   473,   209,   474,
      -1,   475,    -1,   474,   150,   475,    -1,   474,   136,   475,
      -1,   476,    -1,   476,    50,   230,   542,    -1,   477,    -1,
     477,   199,    94,   542,    -1,   478,    -1,   478,   101,    94,
     540,    -1,   479,    -1,   479,   102,    94,   540,    -1,   481,
      -1,   480,   481,    -1,   176,    -1,   158,    -1,   480,   176,
      -1,   480,   158,    -1,   484,    -1,   488,    -1,   485,    -1,
     202,    -1,   207,    -1,   206,    -1,   205,    -1,   204,    -1,
     203,    -1,   151,    -1,   179,    -1,   140,    -1,    75,   153,
     389,   184,    -1,    75,   221,   153,   389,   184,    -1,    75,
     220,   153,   389,   184,    -1,    75,    76,   557,   153,   389,
     184,    -1,   486,   153,   184,    -1,   486,   153,   409,   184,
      -1,   487,    -1,   486,   487,    -1,   177,   649,    17,    -1,
     177,    18,    -1,   177,    19,    -1,   489,    -1,   489,   490,
      -1,   192,   490,    -1,   490,    -1,   191,    -1,   491,    -1,
     491,   191,   490,    -1,   491,   192,   490,    -1,   492,    -1,
     501,    -1,   493,    -1,   493,   502,    -1,   496,    -1,   496,
     502,    -1,   494,   498,    -1,   495,    -1,   105,   122,    -1,
     114,   122,    -1,    97,   122,    -1,   189,   122,    -1,   115,
     122,    -1,   139,   122,    -1,   138,   122,    -1,   498,    -1,
      98,   498,    -1,   497,   498,    -1,   120,    -1,   172,   122,
      -1,    90,   122,    -1,   181,   122,    -1,   180,   122,    -1,
      91,   122,    -1,   547,    -1,   499,    -1,   649,    -1,   500,
      -1,   193,    -1,    11,    -1,    12,    -1,    20,    -1,   504,
      -1,   501,   502,    -1,   501,   156,   187,    -1,   501,   156,
     513,   187,    -1,   503,    -1,   502,   503,    -1,   154,   409,
     185,    -1,   505,    -1,   507,    -1,   508,    -1,   509,    -1,
     512,    -1,   514,    -1,   510,    -1,   511,    -1,   560,    -1,
     393,    -1,   633,    -1,   635,    -1,   636,    -1,   637,    -1,
     506,    -1,   559,    -1,   110,    -1,   149,    -1,   124,    -1,
     118,   649,    -1,   156,   187,    -1,   156,   409,   187,    -1,
     119,    -1,   169,   153,   409,   184,    -1,   201,   153,   409,
     184,    -1,   650,   156,   187,    -1,   650,   156,   513,   187,
      -1,   410,    -1,   513,   107,   410,    -1,   515,    -1,   533,
      -1,   516,    -1,   530,    -1,   531,    -1,   157,   649,   520,
     130,    -1,   157,   649,   518,   520,   130,    -1,   157,   649,
     520,   196,   194,   649,   520,   196,    -1,   157,   649,   520,
     196,   517,   194,   649,   520,   196,    -1,   157,   649,   518,
     520,   196,   194,   649,   520,   196,    -1,   157,   649,   518,
     520,   196,   517,   194,   649,   520,   196,    -1,   528,    -1,
     517,   528,    -1,   519,    -1,   518,   519,    -1,    35,   649,
     520,   132,   520,   521,    -1,    -1,    35,    -1,   183,   522,
     183,    -1,    93,   524,    93,    -1,    -1,   523,    -1,   134,
      -1,   526,    -1,   523,   134,    -1,   523,   526,    -1,    -1,
     525,    -1,   133,    -1,   527,    -1,   525,   133,    -1,   525,
     527,    -1,    28,    -1,   529,    -1,     5,    -1,   529,    -1,
     515,    -1,    10,    -1,   532,    -1,   529,    -1,     9,    -1,
     123,    -1,   125,    -1,   153,   389,   184,    -1,   212,    30,
     213,    -1,   212,   213,    -1,   174,   648,   175,    -1,   174,
     648,     8,    -1,   103,     7,    -1,   534,    -1,   535,    -1,
     536,    -1,   537,    -1,   538,    -1,   539,    -1,    43,   153,
     389,   184,    -1,    21,   388,   184,    -1,    45,   153,   409,
     184,   153,   388,   184,    -1,    22,   388,   184,    -1,    97,
     153,   409,   184,   153,   388,   184,    -1,    70,   153,   389,
     184,    -1,    39,   153,   389,   184,    -1,    23,   388,   184,
      -1,    59,   153,   409,   184,   153,   388,   184,    -1,   546,
      -1,   546,   144,    -1,    94,   542,    -1,   544,    -1,   544,
     543,    -1,   210,   156,   187,    -1,   144,    -1,   193,    -1,
     176,    -1,   546,    -1,   547,    -1,   152,   156,   187,    -1,
     319,   156,   187,    -1,   563,    -1,   566,    -1,   643,    -1,
     542,    -1,   545,   107,   542,    -1,   649,    -1,   549,    -1,
     555,    -1,   553,    -1,   556,    -1,   554,    -1,   552,    -1,
     551,    -1,   550,    -1,   548,    -1,   224,   156,   187,    -1,
      44,   156,   187,    -1,    44,   156,   555,   187,    -1,    44,
     156,   556,   187,    -1,    70,   156,   187,    -1,    39,   156,
     187,    -1,    59,   156,   187,    -1,    59,   156,   648,   187,
      -1,    59,   156,    29,   187,    -1,    97,   156,   187,    -1,
      97,   156,   649,   187,    -1,    97,   156,   649,   107,   557,
     187,    -1,    97,   156,   193,   187,    -1,    97,   156,   193,
     107,   557,   187,    -1,    61,   156,   649,   187,    -1,    45,
     156,   187,    -1,    45,   156,   649,   187,    -1,    45,   156,
     649,   107,   557,   187,    -1,    45,   156,   649,   107,   558,
     187,    -1,    45,   156,   193,   187,    -1,    45,   156,   193,
     107,   557,   187,    -1,    45,   156,   193,   107,   558,   187,
      -1,    62,   156,   649,   187,    -1,   649,    -1,   649,   144,
      -1,    29,    -1,   561,    -1,   562,    -1,   649,   145,   149,
      -1,    47,   377,   394,    -1,   564,    -1,   565,    -1,    47,
     156,   193,   187,    -1,    47,   156,   187,    94,   542,    -1,
      47,   156,   545,   187,    94,   542,    -1,   156,   544,   187,
      -1,    33,   219,   220,    -1,    33,   219,   221,    -1,    33,
     219,   222,    -1,   225,   224,   410,   232,   410,    -1,   225,
     224,   410,    94,   231,   232,   410,    -1,   225,   224,   410,
      94,   233,   232,   410,    -1,   225,   224,   410,   217,   410,
      -1,   225,   224,   410,   218,   410,    -1,   225,   226,   410,
     232,   410,    -1,   225,   226,   410,    94,   231,   232,   410,
      -1,   225,   226,   410,    94,   233,   232,   410,    -1,   225,
     226,   410,   217,   410,    -1,   225,   226,   410,   218,   410,
      -1,   223,   224,   410,    -1,   223,   226,   410,    -1,   228,
     224,   410,   236,   410,    -1,   228,   229,   230,   224,   410,
     236,   410,    -1,   227,   224,   410,    94,   410,    -1,   235,
     118,   573,   234,   410,   186,   410,    -1,   574,    -1,   573,
     107,   118,   574,    -1,   649,   142,   410,    -1,   243,   153,
     409,   184,   576,    -1,   577,    -1,   576,   577,    -1,   244,
     579,   578,    -1,   153,   409,   184,    -1,   499,    -1,   579,
     209,   499,    -1,   583,   581,    -1,    -1,   582,    -1,   601,
      -1,   582,   601,    -1,   584,    -1,   583,   261,   584,    -1,
     585,    -1,   584,   257,   585,    -1,   586,    -1,   585,   259,
     147,   586,    -1,   587,    -1,   258,   587,    -1,   591,   588,
     589,    -1,    -1,   606,    -1,    -1,   590,    -1,   281,   153,
     409,   184,    -1,   595,   592,    -1,   156,   580,   187,    -1,
     593,    -1,    -1,   628,    -1,   486,   153,   594,   184,    -1,
      -1,   580,    -1,   596,   597,    -1,   505,    -1,   153,   409,
     184,    -1,    -1,   598,    -1,   247,   599,    -1,   246,   600,
      -1,   269,    -1,    -1,    78,    -1,    -1,   285,    -1,   602,
      -1,   603,    -1,   604,    -1,   630,    -1,   627,    -1,   169,
      -1,   283,   471,   605,    -1,   252,   629,   605,    -1,   285,
      -1,   275,    -1,   268,    -1,   245,   607,    -1,   606,   245,
     607,    -1,   608,    -1,   609,    -1,   610,    -1,   625,    -1,
     611,    -1,   619,    -1,   612,    -1,   626,    -1,   100,   273,
      -1,   100,   262,    -1,   265,    -1,   280,    -1,   250,   273,
      -1,   250,   262,    -1,    56,   649,    29,    -1,   276,    -1,
      54,   276,    -1,   278,   613,    -1,   278,   156,   613,   614,
     187,    -1,    54,   278,    -1,   616,    -1,   113,    -1,    -1,
     107,   615,    -1,   616,    -1,   615,   107,   616,    -1,    96,
      29,   617,   618,    -1,    -1,   270,    29,    -1,    -1,   629,
     264,    -1,   277,   285,   620,   622,    -1,   277,   285,   113,
     622,    -1,    54,   277,   285,    -1,    96,    29,    -1,   156,
     621,   187,    -1,    29,    -1,   621,   107,    29,    -1,    -1,
     623,    -1,   624,    -1,   623,   624,    -1,   200,   620,    -1,
     136,   620,    -1,   263,    29,    -1,   282,    -1,    54,   282,
      -1,    96,   216,    -1,    96,   253,    -1,   254,   249,    -1,
     266,   629,   279,    -1,   255,   471,    -1,    96,   129,   471,
      -1,    96,    52,   471,    -1,   256,   471,   198,   471,    -1,
     271,   631,    -1,   251,   631,    -1,   274,    -1,   267,    -1,
     284,   249,   473,    -1,   153,   634,   184,    -1,   410,   121,
     410,    -1,   634,   107,   410,   121,   410,    -1,   154,   185,
      -1,   154,   409,   185,    -1,   309,   310,    -1,   309,   409,
     310,    -1,   311,   312,    -1,   311,   409,   312,    -1,   225,
     313,   410,   232,   410,    -1,   225,   313,   410,   232,   410,
      96,   315,   410,    -1,   223,   313,   504,   156,   410,   187,
      -1,   227,   313,   504,   156,   410,   187,    94,   410,    -1,
     228,   313,   229,   230,   504,   156,   410,   187,   236,   410,
      -1,   314,   313,   410,   198,   410,    -1,   644,    -1,   645,
      -1,   646,    -1,   318,   156,   187,    -1,   316,   156,   187,
      -1,   317,   156,   187,    -1,    29,    -1,    16,    -1,   649,
      -1,   650,    -1,    97,    -1,    39,    -1,    44,    -1,    45,
      -1,   152,    -1,    48,    -1,   224,    -1,    59,    -1,    61,
      -1,    62,    -1,    70,    -1,    73,    -1,    72,    -1,   210,
      -1,   242,    -1,   651,    -1,    24,    -1,   214,    -1,   127,
      -1,    38,    -1,   260,    -1,    37,    -1,   221,    -1,   220,
      -1,   146,    -1,    43,    -1,   258,    -1,   259,    -1,   273,
      -1,   262,    -1,   250,    -1,   284,    -1,   276,    -1,   278,
      -1,   277,    -1,   282,    -1,   254,    -1,   249,    -1,    78,
      -1,   216,    -1,   253,    -1,    52,    -1,   222,    -1,   235,
      -1,   301,    -1,   229,    -1,   202,    -1,   207,    -1,   206,
      -1,   205,    -1,   204,    -1,   203,    -1,    96,    -1,   111,
      -1,   112,    -1,   186,    -1,    46,    -1,    36,    -1,    66,
      -1,    71,    -1,    58,    -1,    53,    -1,    55,    -1,    77,
      -1,    42,    -1,   147,    -1,    51,    -1,   211,    -1,   170,
      -1,   171,    -1,   168,    -1,    69,    -1,    95,    -1,   116,
      -1,   128,    -1,   129,    -1,   106,    -1,    67,    -1,   135,
      -1,   188,    -1,   100,    -1,    94,    -1,   197,    -1,   126,
      -1,   167,    -1,    92,    -1,    50,    -1,   230,    -1,   101,
      -1,   198,    -1,   117,    -1,   159,    -1,   200,    -1,   150,
      -1,   136,    -1,    75,    -1,    76,    -1,   102,    -1,   199,
      -1,   151,    -1,   182,    -1,   195,    -1,   160,    -1,   137,
      -1,   131,    -1,   166,    -1,   148,    -1,   165,    -1,    33,
      -1,    40,    -1,    57,    -1,   113,    -1,    41,    -1,    56,
      -1,   215,    -1,    49,    -1,    60,    -1,    34,    -1,    47,
      -1,   272,    -1,   248,    -1,   281,    -1,   283,    -1,   252,
      -1,   266,    -1,   279,    -1,   271,    -1,   251,    -1,   265,
      -1,   280,    -1,   270,    -1,   264,    -1,   263,    -1,   247,
      -1,   246,    -1,   255,    -1,   256,    -1,   285,    -1,   275,
      -1,   274,    -1,   269,    -1,   267,    -1,   268,    -1,   228,
      -1,   234,    -1,   231,    -1,   225,    -1,   218,    -1,   217,
      -1,   219,    -1,   236,    -1,   226,    -1,   227,    -1,   233,
      -1,   223,    -1,   232,    -1,    65,    -1,    63,    -1,    74,
      -1,   169,    -1,   201,    -1,   241,    -1,   239,    -1,   240,
      -1,   237,    -1,   238,    -1,   243,    -1,   244,    -1,   245,
      -1,    64,    -1,   294,    -1,   292,    -1,   293,    -1,   298,
      -1,   299,    -1,   300,    -1,   295,    -1,   296,    -1,   297,
      -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,
      -1,    89,    -1,   286,    -1,   287,    -1,   288,    -1,   289,
      -1,   290,    -1,   291,    -1,   302,    -1,   303,    -1,   304,
      -1,   305,    -1,   306,    -1,   307,    -1,   308,    -1,    90,
      -1,   105,    -1,   114,    -1,   172,    -1,   180,    -1,   189,
      -1,   138,    -1,    91,    -1,   115,    -1,   139,    -1,   181,
      -1,   313,    -1,   314,    -1,   315,    -1,   318,    -1,   317,
      -1,   319,    -1,    25,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    11,    13,    16,    18,    21,
      26,    33,    37,    41,    47,    49,    53,    57,    63,    69,
      71,    75,    79,    85,    92,    94,    98,   102,   104,   106,
     108,   110,   112,   114,   116,   118,   120,   122,   124,   126,
     128,   132,   136,   141,   145,   149,   153,   157,   161,   167,
     173,   179,   185,   191,   197,   199,   201,   205,   209,   214,
     220,   227,   229,   233,   237,   241,   245,   252,   258,   267,
     273,   279,   285,   287,   291,   295,   297,   299,   301,   303,
     305,   307,   309,   311,   316,   321,   323,   326,   330,   332,
     334,   336,   338,   340,   342,   344,   346,   348,   350,   355,
     359,   364,   368,   370,   372,   374,   377,   380,   385,   389,
     395,   399,   404,   409,   415,   417,   420,   422,   427,   429,
     434,   436,   440,   443,   447,   449,   451,   456,   461,   467,
     473,   476,   480,   485,   491,   493,   497,   500,   504,   508,
     514,   519,   526,   528,   531,   540,   550,   552,   556,   558,
     561,   564,   568,   580,   595,   609,   632,   634,   636,   638,
     639,   641,   643,   644,   646,   649,   651,   654,   656,   658,
     660,   662,   664,   666,   668,   670,   672,   674,   676,   678,
     682,   685,   689,   693,   696,   700,   703,   707,   710,   714,
     719,   725,   731,   734,   739,   745,   749,   753,   756,   759,
     768,   772,   774,   777,   781,   783,   787,   789,   791,   793,
     795,   797,   799,   801,   803,   805,   807,   809,   811,   813,
     815,   817,   819,   821,   823,   826,   829,   832,   835,   837,
     839,   842,   847,   851,   857,   862,   866,   868,   870,   872,
     874,   876,   878,   880,   882,   884,   887,   891,   893,   898,
     902,   908,   913,   920,   925,   932,   938,   946,   951,   957,
     963,   970,   974,   978,   981,   983,   987,   992,   998,  1002,
    1009,  1014,  1020,  1022,  1025,  1029,  1031,  1034,  1036,  1043,
    1047,  1051,  1054,  1058,  1060,  1064,  1067,  1071,  1074,  1078,
    1083,  1085,  1089,  1091,  1094,  1096,  1098,  1100,  1103,  1106,
    1109,  1113,  1115,  1117,  1120,  1123,  1126,  1132,  1138,  1140,
    1145,  1149,  1154,  1163,  1165,  1168,  1172,  1175,  1179,  1188,
    1190,  1193,  1197,  1206,  1217,  1226,  1237,  1239,  1242,  1247,
    1255,  1257,  1260,  1265,  1273,  1282,  1284,  1288,  1290,  1294,
    1296,  1300,  1304,  1308,  1312,  1313,  1318,  1322,  1326,  1330,
    1332,  1338,  1340,  1344,  1345,  1347,  1349,  1353,  1355,  1359,
    1363,  1365,  1369,  1373,  1377,  1381,  1383,  1387,  1391,  1393,
    1397,  1401,  1403,  1408,  1410,  1415,  1417,  1422,  1424,  1429,
    1431,  1434,  1436,  1438,  1441,  1444,  1446,  1448,  1450,  1452,
    1454,  1456,  1458,  1460,  1462,  1464,  1466,  1468,  1473,  1479,
    1485,  1492,  1496,  1501,  1503,  1506,  1510,  1513,  1516,  1518,
    1521,  1524,  1526,  1528,  1530,  1534,  1538,  1540,  1542,  1544,
    1547,  1549,  1552,  1555,  1557,  1560,  1563,  1566,  1569,  1572,
    1575,  1578,  1580,  1583,  1586,  1588,  1591,  1594,  1597,  1600,
    1603,  1605,  1607,  1609,  1611,  1613,  1615,  1617,  1619,  1621,
    1624,  1628,  1633,  1635,  1638,  1642,  1644,  1646,  1648,  1650,
    1652,  1654,  1656,  1658,  1660,  1662,  1664,  1666,  1668,  1670,
    1672,  1674,  1676,  1678,  1680,  1683,  1686,  1690,  1692,  1697,
    1702,  1706,  1711,  1713,  1717,  1719,  1721,  1723,  1725,  1727,
    1732,  1738,  1747,  1757,  1767,  1778,  1780,  1783,  1785,  1788,
    1795,  1796,  1798,  1802,  1806,  1807,  1809,  1811,  1813,  1816,
    1819,  1820,  1822,  1824,  1826,  1829,  1832,  1834,  1836,  1838,
    1840,  1842,  1844,  1846,  1848,  1850,  1852,  1854,  1858,  1862,
    1865,  1869,  1873,  1876,  1878,  1880,  1882,  1884,  1886,  1888,
    1893,  1897,  1905,  1909,  1917,  1922,  1927,  1931,  1939,  1941,
    1944,  1947,  1949,  1952,  1956,  1958,  1960,  1962,  1964,  1966,
    1970,  1974,  1976,  1978,  1980,  1982,  1986,  1988,  1990,  1992,
    1994,  1996,  1998,  2000,  2002,  2004,  2006,  2010,  2014,  2019,
    2024,  2028,  2032,  2036,  2041,  2046,  2050,  2055,  2062,  2067,
    2074,  2079,  2083,  2088,  2095,  2102,  2107,  2114,  2121,  2126,
    2128,  2131,  2133,  2135,  2137,  2141,  2145,  2147,  2149,  2154,
    2160,  2167,  2171,  2175,  2179,  2183,  2189,  2197,  2205,  2211,
    2217,  2223,  2231,  2239,  2245,  2251,  2255,  2259,  2265,  2273,
    2279,  2287,  2289,  2294,  2298,  2304,  2306,  2309,  2313,  2317,
    2319,  2323,  2326,  2327,  2329,  2331,  2334,  2336,  2340,  2342,
    2346,  2348,  2353,  2355,  2358,  2362,  2363,  2365,  2366,  2368,
    2373,  2376,  2380,  2382,  2383,  2385,  2390,  2391,  2393,  2396,
    2398,  2402,  2403,  2405,  2408,  2411,  2413,  2414,  2416,  2417,
    2419,  2421,  2423,  2425,  2427,  2429,  2431,  2435,  2439,  2441,
    2443,  2445,  2448,  2452,  2454,  2456,  2458,  2460,  2462,  2464,
    2466,  2468,  2471,  2474,  2476,  2478,  2481,  2484,  2488,  2490,
    2493,  2496,  2502,  2505,  2507,  2509,  2510,  2513,  2515,  2519,
    2524,  2525,  2528,  2529,  2532,  2537,  2542,  2546,  2549,  2553,
    2555,  2559,  2560,  2562,  2564,  2567,  2570,  2573,  2576,  2578,
    2581,  2584,  2587,  2590,  2594,  2597,  2601,  2605,  2610,  2613,
    2616,  2618,  2620,  2624,  2628,  2632,  2638,  2641,  2645,  2648,
    2652,  2655,  2659,  2665,  2674,  2681,  2690,  2701,  2707,  2709,
    2711,  2713,  2717,  2721,  2725,  2727,  2729,  2731,  2733,  2735,
    2737,  2739,  2741,  2743,  2745,  2747,  2749,  2751,  2753,  2755,
    2757,  2759,  2761,  2763,  2765,  2767,  2769,  2771,  2773,  2775,
    2777,  2779,  2781,  2783,  2785,  2787,  2789,  2791,  2793,  2795,
    2797,  2799,  2801,  2803,  2805,  2807,  2809,  2811,  2813,  2815,
    2817,  2819,  2821,  2823,  2825,  2827,  2829,  2831,  2833,  2835,
    2837,  2839,  2841,  2843,  2845,  2847,  2849,  2851,  2853,  2855,
    2857,  2859,  2861,  2863,  2865,  2867,  2869,  2871,  2873,  2875,
    2877,  2879,  2881,  2883,  2885,  2887,  2889,  2891,  2893,  2895,
    2897,  2899,  2901,  2903,  2905,  2907,  2909,  2911,  2913,  2915,
    2917,  2919,  2921,  2923,  2925,  2927,  2929,  2931,  2933,  2935,
    2937,  2939,  2941,  2943,  2945,  2947,  2949,  2951,  2953,  2955,
    2957,  2959,  2961,  2963,  2965,  2967,  2969,  2971,  2973,  2975,
    2977,  2979,  2981,  2983,  2985,  2987,  2989,  2991,  2993,  2995,
    2997,  2999,  3001,  3003,  3005,  3007,  3009,  3011,  3013,  3015,
    3017,  3019,  3021,  3023,  3025,  3027,  3029,  3031,  3033,  3035,
    3037,  3039,  3041,  3043,  3045,  3047,  3049,  3051,  3053,  3055,
    3057,  3059,  3061,  3063,  3065,  3067,  3069,  3071,  3073,  3075,
    3077,  3079,  3081,  3083,  3085,  3087,  3089,  3091,  3093,  3095,
    3097,  3099,  3101,  3103,  3105,  3107,  3109,  3111,  3113,  3115,
    3117,  3119,  3121,  3123,  3125,  3127,  3129,  3131,  3133,  3135,
    3137,  3139,  3141,  3143,  3145,  3147,  3149,  3151,  3153,  3155,
    3157,  3159,  3161,  3163,  3165,  3167,  3169,  3171,  3173
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1034,  1034,  1035,  1044,  1053,  1059,  1067,  1073,  1084,
    1089,  1097,  1104,  1111,  1120,  1127,  1135,  1143,  1151,  1162,
    1167,  1174,  1181,  1193,  1203,  1210,  1217,  1229,  1230,  1231,
    1232,  1233,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1247,
    1252,  1257,  1265,  1273,  1281,  1286,  1294,  1299,  1307,  1312,
    1320,  1327,  1334,  1341,  1351,  1353,  1356,  1366,  1371,  1379,
    1387,  1398,  1405,  1416,  1421,  1429,  1436,  1443,  1452,  1465,
    1473,  1480,  1490,  1497,  1504,  1515,  1516,  1517,  1518,  1519,
    1520,  1521,  1522,  1527,  1533,  1542,  1549,  1559,  1569,  1570,
    1571,  1572,  1573,  1574,  1575,  1576,  1577,  1578,  1583,  1591,
    1599,  1607,  1614,  1622,  1629,  1634,  1642,  1650,  1665,  1680,
    1698,  1703,  1711,  1719,  1730,  1735,  1744,  1749,  1756,  1761,
    1771,  1776,  1785,  1791,  1804,  1809,  1817,  1828,  1843,  1855,
    1870,  1875,  1880,  1885,  1893,  1900,  1911,  1916,  1926,  1933,
    1940,  1947,  1957,  1961,  1971,  1979,  1990,  1996,  2005,  2010,
    2017,  2024,  2035,  2045,  2055,  2065,  2083,  2103,  2107,  2112,
    2119,  2123,  2128,  2135,  2140,  2152,  2159,  2171,  2172,  2173,
    2174,  2175,  2176,  2177,  2179,  2180,  2181,  2182,  2183,  2188,
    2193,  2201,  2218,  2226,  2234,  2241,  2248,  2258,  2270,  2283,
    2295,  2311,  2319,  2327,  2335,  2350,  2355,  2363,  2377,  2394,
    2419,  2427,  2434,  2445,  2455,  2460,  2475,  2476,  2477,  2478,
    2479,  2480,  2485,  2486,  2489,  2490,  2491,  2492,  2493,  2496,
    2497,  2498,  2499,  2500,  2505,  2519,  2527,  2532,  2540,  2545,
    2550,  2558,  2567,  2579,  2589,  2602,  2610,  2611,  2612,  2617,
    2618,  2619,  2620,  2621,  2626,  2633,  2643,  2651,  2658,  2668,
    2678,  2688,  2698,  2708,  2718,  2728,  2738,  2749,  2758,  2768,
    2778,  2794,  2803,  2812,  2820,  2826,  2838,  2846,  2856,  2864,
    2876,  2882,  2893,  2895,  2899,  2907,  2911,  2916,  2920,  2924,
    2928,  2938,  2946,  2953,  2959,  2970,  2974,  2983,  2991,  2997,
    3007,  3013,  3023,  3027,  3037,  3043,  3049,  3055,  3064,  3073,
    3082,  3095,  3099,  3107,  3113,  3123,  3131,  3140,  3153,  3160,
    3172,  3176,  3188,  3195,  3201,  3210,  3217,  3223,  3234,  3241,
    3247,  3256,  3265,  3272,  3283,  3290,  3302,  3308,  3320,  3326,
    3337,  3343,  3354,  3360,  3371,  3380,  3384,  3393,  3397,  3405,
    3409,  3419,  3426,  3435,  3445,  3444,  3458,  3467,  3476,  3489,
    3493,  3505,  3509,  3517,  3520,  3527,  3531,  3540,  3544,  3548,
    3556,  3560,  3566,  3572,  3578,  3588,  3592,  3596,  3604,  3608,
    3614,  3624,  3628,  3638,  3642,  3652,  3656,  3666,  3670,  3680,
    3684,  3692,  3696,  3700,  3704,  3714,  3718,  3722,  3730,  3734,
    3738,  3742,  3746,  3750,  3758,  3762,  3766,  3774,  3778,  3782,
    3786,  3797,  3803,  3813,  3819,  3829,  3833,  3837,  3875,  3879,
    3889,  3899,  3912,  3921,  3931,  3935,  3944,  3948,  3957,  3963,
    3971,  3977,  3989,  3995,  4005,  4009,  4013,  4017,  4021,  4027,
    4033,  4041,  4045,  4053,  4057,  4068,  4072,  4076,  4082,  4086,
    4100,  4104,  4112,  4116,  4126,  4130,  4134,  4138,  4147,  4151,
    4155,  4159,  4167,  4173,  4183,  4191,  4195,  4199,  4203,  4207,
    4211,  4215,  4219,  4223,  4227,  4232,  4236,  4240,  4244,  4252,
    4256,  4264,  4271,  4278,  4289,  4297,  4301,  4309,  4317,  4325,
    4379,  4383,  4396,  4402,  4412,  4416,  4424,  4428,  4432,  4440,
    4450,  4460,  4470,  4480,  4490,  4505,  4511,  4522,  4528,  4539,
    4550,  4552,  4556,  4561,  4571,  4574,  4581,  4587,  4593,  4601,
    4614,  4617,  4624,  4630,  4636,  4643,  4654,  4658,  4668,  4672,
    4682,  4686,  4690,  4695,  4704,  4710,  4716,  4722,  4730,  4735,
    4743,  4748,  4756,  4764,  4769,  4774,  4779,  4784,  4789,  4798,
    4806,  4810,  4827,  4831,  4839,  4847,  4855,  4859,  4867,  4873,
    4883,  4891,  4895,  4899,  4934,  4940,  4946,  4956,  4960,  4964,
    4968,  4972,  4976,  4980,  4987,  4993,  5003,  5011,  5015,  5019,
    5023,  5027,  5031,  5035,  5039,  5043,  5051,  5059,  5063,  5067,
    5077,  5085,  5093,  5097,  5101,  5109,  5113,  5119,  5125,  5129,
    5139,  5147,  5151,  5157,  5166,  5175,  5181,  5187,  5197,  5214,
    5221,  5236,  5272,  5276,  5284,  5292,  5304,  5308,  5316,  5324,
    5328,  5339,  5356,  5362,  5368,  5378,  5382,  5388,  5394,  5398,
    5404,  5408,  5414,  5420,  5427,  5437,  5442,  5450,  5456,  5466,
    5488,  5497,  5503,  5516,  5530,  5537,  5543,  5553,  5562,  5570,
    5576,  5594,  5602,  5606,  5613,  5618,  5626,  5630,  5637,  5641,
    5648,  5652,  5659,  5663,  5672,  5685,  5688,  5696,  5699,  5707,
    5715,  5723,  5727,  5735,  5738,  5746,  5758,  5761,  5769,  5781,
    5787,  5797,  5800,  5808,  5812,  5816,  5824,  5827,  5835,  5838,
    5846,  5850,  5854,  5858,  5862,  5870,  5878,  5890,  5902,  5906,
    5910,  5918,  5924,  5934,  5938,  5942,  5946,  5950,  5954,  5958,
    5962,  5970,  5974,  5978,  5982,  5990,  5996,  6006,  6016,  6020,
    6028,  6038,  6049,  6056,  6060,  6068,  6071,  6078,  6083,  6092,
    6102,  6105,  6112,  6116,  6124,  6133,  6140,  6150,  6154,  6161,
    6167,  6177,  6180,  6187,  6192,  6204,  6212,  6224,  6232,  6236,
    6244,  6248,  6252,  6260,  6268,  6272,  6276,  6280,  6288,  6296,
    6308,  6312,  6320,  6334,  6341,  6345,  6358,  6362,  6369,  6374,
    6382,  6387,  6395,  6399,  6406,  6413,  6420,  6427,  6434,  6438,
    6442,  6449,  6456,  6463,  6475,  6479,  6480,  6493,  6494,  6495,
    6496,  6497,  6498,  6499,  6500,  6501,  6502,  6503,  6504,  6505,
    6506,  6507,  6508,  6512,  6513,  6514,  6515,  6516,  6517,  6518,
    6519,  6520,  6521,  6522,  6523,  6524,  6525,  6526,  6527,  6528,
    6529,  6530,  6531,  6532,  6533,  6534,  6535,  6536,  6537,  6538,
    6539,  6540,  6541,  6542,  6543,  6544,  6545,  6546,  6547,  6548,
    6549,  6550,  6551,  6552,  6553,  6554,  6555,  6556,  6557,  6558,
    6559,  6560,  6561,  6562,  6563,  6564,  6565,  6566,  6567,  6568,
    6569,  6570,  6571,  6572,  6573,  6574,  6575,  6576,  6577,  6578,
    6579,  6580,  6581,  6582,  6583,  6584,  6585,  6586,  6587,  6588,
    6589,  6590,  6591,  6592,  6593,  6594,  6595,  6596,  6597,  6598,
    6599,  6600,  6601,  6602,  6603,  6604,  6605,  6606,  6607,  6608,
    6609,  6610,  6611,  6612,  6613,  6614,  6615,  6616,  6617,  6618,
    6619,  6620,  6621,  6622,  6623,  6624,  6625,  6626,  6627,  6628,
    6629,  6630,  6631,  6632,  6633,  6634,  6635,  6636,  6637,  6638,
    6639,  6640,  6641,  6642,  6643,  6644,  6645,  6646,  6647,  6648,
    6649,  6650,  6651,  6652,  6653,  6654,  6655,  6656,  6657,  6658,
    6659,  6660,  6661,  6662,  6663,  6664,  6665,  6666,  6667,  6668,
    6669,  6670,  6671,  6672,  6673,  6674,  6675,  6676,  6677,  6678,
    6679,  6680,  6681,  6682,  6683,  6684,  6685,  6686,  6687,  6688,
    6689,  6690,  6691,  6692,  6693,  6694,  6695,  6696,  6697,  6698,
    6699,  6700,  6701,  6702,  6703,  6704,  6705,  6706,  6707,  6708,
    6709,  6710,  6711,  6712,  6713,  6714,  6715,  6716,  6721
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
     325,   326,   327,   328,   329,   330
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 15047;
  const int xquery_parser::yynnts_ = 321;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 601;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 331;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 585;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 16876 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6725 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"


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
    // remove the double quoting "''" from every token description
    string message = msg;
    int pos;
    while ((pos = message.find("\"'")) != -1 || (pos = message.find("'\"")) != -1)
      message.replace(pos, 2, "\"");
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), err::XPST0003, message));
  }
}

} // namespace zorba

