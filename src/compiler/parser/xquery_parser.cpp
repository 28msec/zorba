
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
#line 895 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 1001 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"

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
        case 109: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 285 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 123: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 294 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 148: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 303 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 919 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 528 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 919 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 537 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 919 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 919 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "JSONPairConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 919 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "JSONConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2697 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2706 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2715 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2724 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
#line 2809 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1019 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1028 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1037 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1043 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1051 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1057 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1068 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1073 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1081 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1088 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1095 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1104 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1111 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1119 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1127 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1135 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1146 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1151 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1158 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1165 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1177 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1187 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1194 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1201 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1236 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1241 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1249 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1257 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1265 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1270 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1278 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1283 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1291 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1296 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1304 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1311 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1318 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1325 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1340 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1350 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1355 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1363 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1371 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1382 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1389 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1400 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1405 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1413 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1420 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1427 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1436 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1449 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1457 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1464 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1474 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1481 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1488 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1511 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1517 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1526 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1533 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1543 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1552 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1553 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1554 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1555 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1556 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1557 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1558 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1559 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1560 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1561 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1567 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1575 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1583 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1591 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1598 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1606 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1613 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1618 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1626 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1634 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1649 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1664 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1682 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1687 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1695 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1703 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1714 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1719 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1728 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1733 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1740 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1745 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1755 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1760 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1769 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1775 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1788 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1793 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1801 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1812 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1827 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1839 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1854 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1859 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1864 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1869 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1877 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1884 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1895 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1900 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1924 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1931 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1941 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1945 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1955 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1963 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1974 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1980 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1989 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1994 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 2001 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 2008 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 2020 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2030 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2040 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2051 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2067 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2087 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2092 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2096 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2104 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2109 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2113 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2121 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2126 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2138 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2145 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2174 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2179 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2187 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2204 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2212 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2220 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2227 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2234 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2244 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2256 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2269 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2281 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2297 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 2305 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 2313 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2321 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2336 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2341 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2349 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2363 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2380 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2405 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2413 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2420 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2431 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2441 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2446 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 219:

/* Line 678 of lalr1.cc  */
#line 2484 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 220:

/* Line 678 of lalr1.cc  */
#line 2498 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2506 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2511 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2519 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2524 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2529 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2537 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2546 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2558 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 229:

/* Line 678 of lalr1.cc  */
#line 2568 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2581 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2605 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2612 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2622 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2630 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2637 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2647 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 245:

/* Line 678 of lalr1.cc  */
#line 2657 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 246:

/* Line 678 of lalr1.cc  */
#line 2667 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 247:

/* Line 678 of lalr1.cc  */
#line 2677 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 248:

/* Line 678 of lalr1.cc  */
#line 2687 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 249:

/* Line 678 of lalr1.cc  */
#line 2697 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 250:

/* Line 678 of lalr1.cc  */
#line 2707 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 251:

/* Line 678 of lalr1.cc  */
#line 2717 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 252:

/* Line 678 of lalr1.cc  */
#line 2728 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2737 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 254:

/* Line 678 of lalr1.cc  */
#line 2747 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 255:

/* Line 678 of lalr1.cc  */
#line 2757 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 256:

/* Line 678 of lalr1.cc  */
#line 2773 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2782 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2791 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2799 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2805 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2817 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2825 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2835 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2843 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2855 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2861 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2874 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2878 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2886 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2890 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2899 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2903 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2925 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2932 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2938 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2949 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2953 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2962 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2970 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2976 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2986 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2992 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 3002 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 3006 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 3016 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 3022 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 3028 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 3034 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3043 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3052 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3061 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3074 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3078 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3086 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3092 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3102 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3110 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3119 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3132 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3139 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3151 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3155 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3167 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3174 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3180 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3189 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3196 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3202 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3213 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3220 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3226 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3235 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3244 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3251 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3262 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3269 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3281 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3287 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3299 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3305 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3316 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3322 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3333 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3339 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3350 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3359 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3363 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3372 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3376 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3384 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3388 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 336:

/* Line 678 of lalr1.cc  */
#line 3398 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3405 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3414 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3423 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3428 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3437 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3446 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3455 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3468 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3472 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3484 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3488 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3497 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3501 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RangeExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3510 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3515 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new JSON_PairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3524 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3528 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3532 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3541 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3545 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3551 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3557 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3563 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3574 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3578 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3582 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3590 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3594 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3600 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3610 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3614 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3624 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3628 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3638 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3642 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3652 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3656 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3666 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3670 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3678 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3682 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3686 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3690 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3700 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3704 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3708 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3716 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3720 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3724 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3728 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3732 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3736 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3744 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3748 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3752 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3760 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3764 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3768 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3772 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3783 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3789 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3799 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3805 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3815 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3819 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3823 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3861 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3865 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3875 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3885 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3898 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3907 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      AxisStep* as = dynamic_cast<AxisStep*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (as ?
            new RelativePathExpr(LOC((yyloc)),
                                 ParseConstants::st_slash,
                                 new ContextItemExpr( LOC((yyloc)), true ), (yysemantic_stack_[(1) - (1)].expr))
            :
            (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3921 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3930 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3934 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3943 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3949 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3957 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3963 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3975 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3981 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3991 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3995 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3999 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 4003 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 4007 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 4013 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 4019 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 4027 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4031 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4039 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4043 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4054 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4058 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4062 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4068 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4072 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4086 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4090 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4098 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4102 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4112 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4116 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4120 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4124 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4133 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4137 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4141 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4145 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4153 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4159 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4169 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4177 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4181 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4185 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4189 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4193 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4197 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4201 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4205 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4209 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4219 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4223 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4231 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4235 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4243 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4250 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4257 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4268 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4276 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4280 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4288 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4296 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4304 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4358 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4362 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4375 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4381 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4391 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4395 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4403 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4407 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4411 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4419 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 482:

/* Line 678 of lalr1.cc  */
#line 4429 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 483:

/* Line 678 of lalr1.cc  */
#line 4439 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 484:

/* Line 678 of lalr1.cc  */
#line 4449 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 485:

/* Line 678 of lalr1.cc  */
#line 4459 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 486:

/* Line 678 of lalr1.cc  */
#line 4469 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 487:

/* Line 678 of lalr1.cc  */
#line 4484 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4490 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4501 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4507 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4518 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4535 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4540 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4549 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4553 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4560 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4566 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4572 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4580 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4592 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4596 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4603 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4609 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4615 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4622 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4633 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4637 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4647 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4651 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4661 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4665 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4669 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4674 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4683 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4689 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4695 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4701 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4709 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4714 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4722 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4727 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4735 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4743 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4748 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4753 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4758 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4763 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4768 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4777 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4785 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4789 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4806 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4810 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4818 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4826 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4834 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4838 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4846 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4852 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4862 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4870 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4874 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4878 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4913 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4919 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4925 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4935 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4939 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4943 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4947 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4951 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4955 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4962 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4968 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4978 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4986 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4990 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4994 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4998 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5002 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5006 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5010 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5014 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5018 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5026 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5034 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5038 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5042 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5052 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5060 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5068 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5072 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5076 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5084 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5088 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5094 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5100 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5104 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5114 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5122 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5126 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5132 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5141 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5150 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5156 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5162 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5172 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5189 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5196 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5211 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5247 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5251 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5259 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5267 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5279 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5283 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5291 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5299 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5303 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5314 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5331 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5337 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5343 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5353 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5357 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5363 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5369 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5373 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5379 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5383 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5389 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5395 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5402 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5412 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5417 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5425 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5431 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5441 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5463 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5472 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5478 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5491 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5505 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5512 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5518 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5537 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5545 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5551 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5569 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5577 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5581 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5588 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5593 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5601 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5605 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5612 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5616 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5623 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5627 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5634 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5638 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5647 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5659 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5663 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5670 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5674 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5682 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5690 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5698 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5702 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5709 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5713 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5721 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5732 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5736 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5744 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5756 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5762 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5771 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5775 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5783 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5787 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5791 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5798 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5802 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5809 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5813 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5821 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5825 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5829 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5833 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5837 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5845 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5853 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5865 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5877 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5881 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5885 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5893 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5899 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5909 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5913 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5921 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5925 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5929 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5933 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5937 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5945 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5949 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5953 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5957 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5965 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5971 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5981 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5991 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5995 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 6003 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 702:

/* Line 678 of lalr1.cc  */
#line 6013 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 703:

/* Line 678 of lalr1.cc  */
#line 6024 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 6031 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 6035 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 6042 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6046 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6053 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6058 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6067 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6076 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6080 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6087 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6091 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6099 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6108 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6115 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6125 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6129 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6136 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6142 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6151 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6155 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6162 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6167 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6179 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6187 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6199 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6207 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6211 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6219 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6223 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6227 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6235 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6243 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6247 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6251 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6255 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6263 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6271 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6283 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6287 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6295 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6305 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6310 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6340 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new JSON_ArrayConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6349 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new JSON_ObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6357 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6362 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6371 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6386 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6395 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
    }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6403 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
    }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6411 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
    }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6419 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonPair);
    }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6438 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 762:

/* Line 678 of lalr1.cc  */
#line 6451 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6452 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6453 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6454 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6455 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6456 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6457 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6458 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6459 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6460 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6461 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6462 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6463 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6464 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6465 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6470 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6471 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6472 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6473 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6474 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6475 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6476 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6477 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6478 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6479 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6480 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6481 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6482 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6483 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6484 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6485 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6486 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6487 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6488 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6489 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6490 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6491 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6492 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6493 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6494 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6495 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6496 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6497 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6498 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6499 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6500 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6501 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6502 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6503 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6504 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6505 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6506 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6507 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6508 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6509 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6510 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6511 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6512 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6513 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6514 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6515 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6516 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6517 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6518 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6519 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6520 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6521 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6522 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6523 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6524 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6525 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6526 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6527 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6528 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6529 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6530 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6531 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6532 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6533 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6534 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6535 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6536 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6537 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6538 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6539 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6540 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6541 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6542 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6543 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6544 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6545 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6546 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6547 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6548 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6549 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6550 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6551 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6552 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6553 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6554 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6555 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6556 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6557 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6558 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6559 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6560 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6561 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6562 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6563 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6564 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6565 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6566 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6567 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6568 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6569 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6570 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6571 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6572 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6573 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6574 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6575 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6576 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6577 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6578 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6579 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6580 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6581 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6582 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6583 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6584 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6585 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6586 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6587 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6588 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6589 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6590 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6591 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6592 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6593 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6594 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6595 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6596 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6597 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6598 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6599 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6600 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6601 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6602 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6603 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6604 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6605 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6606 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6607 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6608 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6609 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6610 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6611 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6612 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6613 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6614 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6615 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6616 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6617 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6618 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6619 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6620 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6621 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6622 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6623 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6624 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6625 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6626 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6627 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6628 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6629 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6630 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6631 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6632 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6633 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6634 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6635 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6636 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6637 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6638 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6639 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6640 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6641 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6642 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6643 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6644 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6645 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6646 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6647 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6648 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6649 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6650 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6651 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6652 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6653 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6654 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 963:

/* Line 678 of lalr1.cc  */
#line 6655 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 964:

/* Line 678 of lalr1.cc  */
#line 6656 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 965:

/* Line 678 of lalr1.cc  */
#line 6657 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 966:

/* Line 678 of lalr1.cc  */
#line 6658 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 967:

/* Line 678 of lalr1.cc  */
#line 6659 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 968:

/* Line 678 of lalr1.cc  */
#line 6660 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 969:

/* Line 678 of lalr1.cc  */
#line 6661 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 970:

/* Line 678 of lalr1.cc  */
#line 6662 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 971:

/* Line 678 of lalr1.cc  */
#line 6663 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 972:

/* Line 678 of lalr1.cc  */
#line 6664 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 973:

/* Line 678 of lalr1.cc  */
#line 6665 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 974:

/* Line 678 of lalr1.cc  */
#line 6666 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 975:

/* Line 678 of lalr1.cc  */
#line 6667 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 976:

/* Line 678 of lalr1.cc  */
#line 6668 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 977:

/* Line 678 of lalr1.cc  */
#line 6669 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 978:

/* Line 678 of lalr1.cc  */
#line 6670 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pair"))); }
    break;

  case 979:

/* Line 678 of lalr1.cc  */
#line 6671 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 980:

/* Line 678 of lalr1.cc  */
#line 6676 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 11726 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1425;
  const short int
  xquery_parser::yypact_[] =
  {
      2951, -1425, -1425, -1425,  4457,  4457,  4457, -1425, -1425,    64,
     192, -1425,    49,   250, -1425, -1425, -1425,   640, -1425, -1425,
   -1425,   333,   422,   709,   643,   428,   479,   698, -1425,    -3,
   -1425, -1425, -1425, -1425, -1425, -1425,   740, -1425,   485,   494,
   -1425, -1425, -1425, -1425,    71, -1425,   749, -1425,   570,   580,
   -1425,   150, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425,   400,   578, -1425, -1425,
   -1425, -1425,   587,  8972, -1425, -1425, -1425,   681, -1425, -1425,
   -1425,   540, -1425,   707,   723, -1425, -1425, 12751, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425,   762, -1425, -1425,   765,
     782, -1425, -1425, -1425, -1425, -1425, -1425, -1425,  3253,  7467,
    6263, 12751, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   600,
   -1425, -1425,   785,  9865, -1425, 10159,   802,   807, -1425, -1425,
   -1425,   822, -1425,  8671, -1425, -1425, -1425, -1425, -1425, -1425,
     792, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,    77,
     -44, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   671,
     790,   691, -1425,   724,    94, -1425, -1425, -1425, -1425, -1425,
   -1425,   831, -1425,   710,   711,   725, -1425, -1425,   796,   814,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425,  4758,   967, -1425,
    5059, -1425, -1425,   596,    76, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,    81,
   -1425, -1425, -1425, -1425, -1425, -1425,   112, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425,  4457, -1425, -1425, -1425, -1425,
      51, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   862,
   -1425,   786, -1425, -1425, -1425,   385, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425,   810,   885, -1425,   768,   732,   781,
     456,   490,   269,   298, -1425,   931,   784,   883,   884,  7768,
   -1425, -1425, -1425,    15, -1425, -1425,  8671, -1425,   426, -1425,
     834,  8972, -1425,   834,  8972, -1425, -1425, -1425,   531, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425,   840,   833, -1425, -1425, -1425, -1425,
   -1425,   806, -1425,  4457,   808,   809,   593,   593,   961,   362,
     457,   493, 13039, 12751,    -4,   946, 12751,   843,   878,   274,
    9865,   692,   752, 12751, 12751,   695,   716,    47, -1425, -1425,
   -1425,  9865,  4457,   812,  4457,   127,  7467, 10735,   717,   719,
   12751,   887,    18,   850,  7467,  1004,   142,    89, 12751,   889,
     866,   903, -1425,  7467,  9569, 12751, 12751, 12751,  4457,   824,
    7467,  7467, 12751,  4457,   860,   861, -1425, -1425, -1425,  7467,
   11023,   859, -1425,   867, -1425, -1425, -1425, -1425,   868, -1425,
     869, -1425, -1425, -1425, -1425, -1425,   871, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, 12751, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425,   880, 12751, -1425,
   -1425, -1425,   832,  3554,   862,   844,   873,   875,   876, 12751,
    4457,   877,   862, -1425,   581,   848, -1425,    50,   998,  7467,
   -1425, -1425,    58, -1425, -1425, -1425,  1017, -1425, -1425, -1425,
   -1425,  7467,   823, -1425,  1007,  7467,  7467,   851,  7467,  7467,
    7467,  7467,   813, 12751,   849,   854,  7467,  7467,  3253,   804,
   -1425, -1425, -1425, -1425,    49,   698,    83,    87,  1036,  5360,
    5360,  5661,  5661,   540, -1425, -1425,   862,   540, -1425,  7467,
   -1425,   928,   643,    -3,   879,   881,   882,  4457,  7467, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425,  8069,  8069,  8069,
   -1425,  8069,  8069, -1425,  8069, -1425,  8069, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425,  8069,  8069,   979,  8069,  8069,  8069,
    8069,  8069,  8069,  8069,  8069,  8069,  8069,  8069,  8069,   828,
     958,   964,   965, -1425, -1425, -1425,  6564, -1425, -1425,  8671,
    8671,  7467,   834, -1425, -1425,   834, -1425,  6865,   834,   912,
    7166, -1425, -1425, -1425,   235, -1425,   238, -1425, -1425, -1425,
   -1425, -1425, -1425,   955,   959,   428,  1037, -1425, -1425, 13039,
     874,   583, 12751,   909,   910,   874,   961,   944,   941, -1425,
   -1425, -1425,   129,   829,   980,   779, 12751,   936,  7467,   963,
   12751, 12751, -1425,   947,   898,  4457, -1425,   899,   867,   494,
   -1425,   897,   900,    44, -1425,   239,   262, -1425, -1425,   978,
   -1425,    36, 12751,    30, 12751,   991,   275, -1425,  4457, -1425,
     279, -1425,  9865,   992,  1042,  9865,   961,   994,    54, 12751,
    7467,    -3,    46,   905, -1425,   907,   908,   911,    57, -1425,
      53,   913, -1425,   292,   301,   943, -1425,   915,  4457,  4457,
     197, -1425,   308,   317,   401,  7467,   128, -1425, -1425, -1425,
    7467,  7467,  7467, -1425,  7467,  7467, -1425, -1425, 12751,   998,
   -1425,    12,   289, -1425, -1425, -1425,   375, -1425,   195, -1425,
   -1425, -1425,   121,   170,  1005,   865,   886,    13, -1425,   969,
   -1425, -1425,   916,   338,  3855,   376,  9273,   804, -1425,   596,
     680,  1069,  1069, -1425, -1425,    98, -1425, -1425,   102, -1425,
      66, -1425, -1425, -1425, -1425, -1425, -1425, -1425, 12751,   935,
    7467,   989, -1425, -1425, -1425,   885, -1425, -1425, -1425, -1425,
   -1425,  8069, -1425, -1425, -1425,    42, -1425,   359,   490,   490,
     269,   269,   269,   269,   298,   298, -1425, -1425, 12175, 12175,
   12751, 12751, -1425,   399, -1425, -1425,    69, -1425, -1425, -1425,
     339, -1425, -1425,   346,   593, -1425, -1425,   199,   337,   626,
   -1425,   428, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425,   874, -1425,   977, 12463,   970,  7467, -1425, -1425,
   -1425,  1018,   961,   961,   874, -1425,   799,   961,   594, 12751,
     539,   566,  1085, -1425, -1425,   835,   543, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   129,   608,
     890,  -113,  7467, -1425, 12751,  1022,   821,   961, -1425, -1425,
   -1425, -1425,   971, 12751, -1425, 12751, -1425,  1000,   995, 12175,
    1009,  7467,   -34,   976,    33,   366,   872, -1425, -1425,   584,
      30,  1018, 12175,  1011,  1035,   948,   934,  1001,   961,   974,
    1003,  1039,   961,  7467,    40, -1425, -1425, -1425,   984, -1425,
   -1425, -1425, -1425,  1021,  7467,  7467,   993, -1425,  1041,  1043,
    4457, -1425,   960,   962,   996, 12751, -1425, 12751, -1425,  7467,
    1006,   952,  7467,   349,   350,   363,  1109, -1425,    17, -1425,
     519, -1425, -1425,  1117, -1425,   685,  7467,  7467,  7467,   689,
    7467,  7467,  7467,  7467,  7467,  7467,  1032,  7467,  7467, -1425,
    5962,   997,   999,  1008,  1010,   786,   614,   914, -1425,     2,
   -1425,   108,   176,    66,  5661,  5661,  5661,  1071, -1425,  7467,
     750,  1045, -1425, 12751,  1050, -1425, -1425,  7467,    42,   267,
      16, -1425,   888,    73,   902,   901, -1425, -1425,   752, -1425,
     895,   558,  1012,  1013, 12463,  1014,  1015,  1020,  1023,  1024,
   -1425,   536, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425,  1029, -1425, -1425, -1425,
    7467, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
     631, -1425,  1132,   727, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425,   892, -1425, -1425,  1135, -1425, -1425, -1425,
   -1425, -1425,   595,  1136, -1425,   693, -1425, -1425, -1425,   859,
     422,   868,   485,   869,   871,   790, -1425,   536,  8370,   896,
     891, -1425,  1018,   608,   957,  1016,  4457,   987,  1027,  1040,
    1028,  1030, 12751,   266, -1425, 12751, -1425,  7467,  1034,  7467,
    1058,  7467,   -15,  1046,  7467,  1047, -1425,  1068,  1070,  7467,
   12751,   820,  1119, -1425, -1425, -1425, -1425, -1425, -1425, 12175,
   -1425,  4457,   961,  1080, -1425, -1425, -1425,   961,  1080, -1425,
    7467,  1053,  4457, 12751, -1425, -1425,  7467,  7467,   628, -1425,
      35,   635, -1425, 11311,   676, -1425,   708, -1425,  1019, -1425,
   -1425,  4457,  1031,  1033, -1425,  7467, -1425, -1425,  1025,  1041,
    1098, -1425,  1067, -1425,   544, -1425, -1425,  1192, -1425, -1425,
    4457, 12751, -1425,   663, -1425, -1425, -1425,  1026,   972,   973,
   -1425, -1425, -1425,   975,  1038, -1425, -1425, -1425, -1425, -1425,
     983, 12751,  1044, -1425, -1425,  7467,  7467,  7467,  4156,  5962,
    9273,   914, -1425,  9273, -1425,  1069,   313, -1425, -1425, -1425,
    1045, -1425,   961, -1425,   803, -1425,    48,  1095, -1425,  7467,
    1103,   989,   461,  1048, -1425,    42,   982, -1425, -1425,   -49,
   -1425,   460,    29,   985,    42,   460,  8069, -1425,   146, -1425,
   -1425, -1425, -1425, -1425, -1425,    42,  1064,   942,   829,    29,
   -1425, -1425,   940,  1147, -1425, -1425, -1425, 10447,  1049,  1052,
    1054,  1055,  1057,  1059,  1060, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425,  1197,     7,  1198,
       7,   986,  1122, -1425,  1075, 12751,   981, -1425, -1425,  8370,
   -1425,  1065, -1425, -1425, -1425, -1425, -1425, -1425,  7467,  1101,
   -1425, -1425,  7467, -1425,   321, -1425,  7467,  1105,  7467, -1425,
    7467, 12751, 12751, -1425,   678, -1425,  7467, -1425,  1124,  1127,
    1158,   961,  1080, -1425,  7467,  1074, -1425, -1425, -1425,  1076,
   -1425,    37,  7467,  4457,  1077,    45, -1425, 12751,  1078, 11599,
     145, -1425, 11887,  1079, -1425, -1425,  1082, -1425, -1425, -1425,
    7467,   730,  1109, 12751,   694, -1425,  1083,  1109, 12751, -1425,
   -1425,  7467,  7467,  7467,  7467,  7467, -1425,  7467,   380,   387,
     394,     3, -1425, -1425, -1425, -1425, -1425,  1095, -1425, -1425,
   -1425,   961, -1425, -1425, -1425, -1425, -1425,  1084,  8069, -1425,
   -1425, -1425, -1425, -1425,   302,  8069,  8069,   487, -1425,   902,
   -1425,   263, -1425,   901,    42,  1108, -1425, -1425,   990, -1425,
   -1425, -1425, -1425,  1180,  1090, -1425,   438, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425,   353,   353, -1425,     7, -1425,
   -1425,   439, -1425,  1248,    29,  1185,  1096,  8370,   -36,  1051,
    1114, -1425, -1425,  7467, -1425,  7467,  1138, -1425,  7467, -1425,
   -1425, -1425,  1232, -1425, -1425,  5962,  7467,   961, -1425, -1425,
   -1425,  7467,  7467, -1425, -1425, -1425,  5962,  5962,  1194,  4457,
   12751,  1104, 12751,  7467, 12751,  1107,  5962, -1425,   244,    27,
    1109, 12751, -1425,  1099,  1109, -1425, -1425, -1425, -1425, -1425,
   -1425,  1094,  1041,  1043,  7467, -1425, -1425, -1425, -1425,   269,
    8069,  8069,   359,     5, -1425, -1425, -1425, -1425, -1425, -1425,
    7467, -1425, 12175, -1425, 12175,  1199, -1425, -1425, -1425,  1266,
   -1425, -1425, -1425,  1061,  1190, -1425, -1425,  1191, -1425,   755,
   12751,  1181,  1081, 12751,  8370, -1425, -1425,  7467, -1425,  1182,
   -1425, -1425,  1080, -1425, -1425, 12175, -1425, -1425,  1206,  7467,
    1116, -1425,  1208,  5962, -1425, 12751,   621,   196, -1425,  1110,
    1109, -1425,  1111,  5962,   731,   502,   359,   359,  8069,   506,
   -1425, -1425, 12175, -1425, -1425,  1185,  8370, -1425,  1095,  1056,
   12751,  1186,  1086,  1191, -1425, 12751,  1123, 12175,  4457, 12175,
    1125, -1425, -1425,  1214,   701, -1425, -1425, -1425, -1425,  1129,
     374, -1425, -1425, -1425,  1118, -1425,  1195, -1425,   359, -1425,
   -1425, -1425, -1425, -1425,  7467,  1062, 12751,  1200, -1425,  4457,
    1130, -1425, -1425,  1131,  7467, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, 12751, -1425,  1063,  1066, 12751, -1425, -1425,  7467,
    5962,  1133,  1072,  7467,  1073,  5962,  8370, -1425,  8370, -1425,
    1128,  1087, 12751,  1091,  1204, 12751,  1089,  8370, -1425
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       159,   440,   441,   442,   162,   162,   162,   778,   980,   116,
     118,   592,   870,   879,   819,   783,   781,   763,   871,   874,
     826,   787,   764,   765,   818,   880,   767,   877,   848,   828,
     803,   823,   824,   875,   872,   822,   769,   878,   770,   771,
     919,   931,   918,   820,   839,   833,   772,   821,   774,   773,
     920,   857,   858,   825,   800,   941,   942,   943,   944,   945,
     946,   947,   948,   949,   950,   951,   965,   972,   847,   843,
     834,   814,   762,     0,   842,   850,   859,   966,   838,   463,
     815,   816,   873,   967,   973,   835,   852,     0,   469,   429,
     465,   845,   780,   836,   837,   866,   840,   856,   865,   971,
     974,   786,   827,   868,   464,   855,   861,   766,     0,   748,
       0,     0,   377,   853,   864,   869,   867,   846,   832,   921,
     830,   831,   968,     0,   376,     0,   969,   975,   862,   817,
     841,   970,   407,     0,   439,   863,   844,   851,   860,   854,
     922,   808,   813,   812,   811,   810,   809,   775,   829,     0,
     779,   876,   801,   910,   909,   911,   785,   784,   804,   916,
     768,   908,   913,   914,   905,   807,   849,   907,   917,   915,
     906,   805,   912,   926,   927,   924,   925,   923,   776,   928,
     929,   930,   896,   895,   882,   799,   792,   889,   885,   802,
     798,   897,   898,   788,   789,   782,   791,   894,   893,   890,
     886,   903,   904,   902,   892,   888,   881,   790,   901,   900,
     794,   796,   795,   887,   891,   883,   797,   884,   793,   899,
     952,   953,   954,   955,   956,   957,   933,   934,   932,   938,
     939,   940,   935,   936,   937,   806,   958,   959,   960,   961,
     962,   963,   964,   977,   979,   976,   978,   159,     0,     2,
     159,     5,     7,    19,     0,    24,    27,    32,    33,    34,
      35,    36,    37,    38,    28,    54,    55,    29,    30,     0,
      72,    75,    76,    31,    77,    78,     0,   114,    79,    80,
      81,    82,    14,   156,   157,   158,   165,   167,   459,   168,
       0,   169,   170,   171,   172,   173,   174,   175,   178,   163,
     204,   211,   206,   233,   239,     0,   231,   232,   213,   207,
     177,   208,   176,   209,   212,   330,   332,   334,   344,   348,
     350,   352,   355,   360,   363,   366,   368,   370,   372,     0,
     374,   380,   382,     0,   398,   381,   403,   406,   408,   411,
     413,     0,   418,   415,     0,   426,   436,   438,   412,   443,
     450,   461,   451,   452,   453,   456,   457,   454,   455,   476,
     478,   479,   480,   477,   525,   526,   527,   528,   529,   530,
     435,   566,   558,   565,   564,   563,   560,   562,   559,   561,
     462,   458,   593,   594,    39,   214,   215,   217,   216,   218,
     210,   460,   744,   745,   437,   761,   777,   870,   879,   877,
     779,     0,   160,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,   124,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   258,   259,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   431,   434,   421,     0,
       0,   763,   787,   765,   818,   880,   767,   828,   769,   839,
     772,   774,   773,   857,   965,   972,   762,   966,   816,   967,
     973,   840,   971,   974,   921,   968,   969,   975,   970,   922,
     916,   908,   914,   905,   805,   926,   927,   924,   776,   928,
     427,   437,   761,   419,     0,   185,   420,   423,   763,   764,
     765,   769,   770,   771,   772,   762,   768,   466,     0,   425,
     424,   180,     0,     0,   163,     0,   767,   774,   773,     0,
     162,   928,   749,   211,     0,     0,   467,     0,   492,     0,
     430,   759,     0,   760,   401,   402,     0,   433,   432,   422,
     405,     0,     0,   521,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     1,     6,     8,     0,     0,     0,     0,     0,   159,
     159,   159,   159,     0,   115,   166,   164,     0,   183,     0,
     192,     0,     0,     0,     0,     0,     0,     0,     0,   197,
     219,   238,   234,   240,   235,   237,   236,     0,     0,     0,
     391,     0,     0,   389,     0,   339,     0,   390,   383,   388,
     387,   386,   385,   384,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   379,   378,   375,     0,   399,   404,     0,
       0,     0,   414,   447,   417,   416,   428,     0,   444,     0,
       0,   532,   534,   538,     0,   120,     0,   758,    43,    40,
      41,    44,    45,     0,     0,     0,     0,    46,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   603,
     604,   605,     0,    99,   138,     0,     0,   108,     0,     0,
       0,     0,   123,     0,     0,     0,   572,     0,     0,     0,
     568,     0,     0,     0,   582,     0,     0,   221,   222,   241,
     242,     0,     0,     0,     0,   130,     0,   134,   162,   596,
       0,    56,     0,    65,     0,     0,     0,    57,     0,     0,
       0,     0,     0,     0,   573,     0,     0,     0,     0,   303,
       0,     0,   571,     0,     0,     0,   590,     0,     0,     0,
       0,   576,     0,     0,   187,     0,     0,   181,   179,   747,
       0,     0,     0,   466,     0,     0,   746,   468,   493,   492,
     489,     0,     0,   523,   522,   400,     0,   520,     0,   616,
     617,   567,     0,     0,     0,     0,     0,     0,   622,     0,
     195,   196,     0,     0,     0,     0,     0,   200,   201,    20,
       0,    21,     0,     4,    25,     0,    11,    26,     0,    15,
     870,    73,    12,    74,    16,   186,   184,   205,     0,     0,
       0,     0,   198,   220,   276,   331,   333,   337,   343,   342,
     341,     0,   338,   335,   336,     0,   349,   351,   354,   353,
     357,   358,   359,   356,   361,   362,   365,   364,     0,     0,
       0,     0,   396,     0,   409,   410,     0,   448,   445,   474,
       0,   595,   472,     0,     0,   117,   119,     0,     0,     0,
      98,     0,    88,    90,    91,    92,    93,    95,    96,    97,
      89,    94,    84,    85,     0,     0,   104,     0,   100,   102,
     103,   110,     0,     0,    83,    42,     0,     0,     0,     0,
       0,     0,     0,   694,   699,     0,     0,   695,   729,   682,
     684,   685,   686,   688,   690,   689,   687,   691,     0,     0,
       0,     0,     0,   107,     0,   140,     0,     0,   537,   531,
     569,   570,     0,     0,   586,     0,   583,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   223,   224,     0,
     229,   136,     0,     0,   131,     0,     0,     0,     0,     0,
       0,    58,     0,     0,     0,   257,   263,   260,     0,   575,
     574,   581,   589,     0,     0,     0,     0,   536,     0,     0,
       0,   392,     0,     0,     0,     0,   579,     0,   577,     0,
     188,     0,     0,     0,     0,     0,   492,   490,     0,   481,
       0,   470,   471,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   193,
       0,   767,   774,   773,   928,     0,     0,     0,   630,     0,
     202,     0,     0,     0,   159,   159,   159,     0,   230,     0,
     287,   283,   285,     0,   277,   278,   340,     0,     0,     0,
       0,   660,   346,   633,   637,   639,   641,   643,   646,   653,
     654,   662,   880,   766,     0,   775,   977,   979,   976,   978,
     367,   543,   549,   550,   552,   597,   598,   553,   554,   750,
     751,   752,   753,   557,   369,   371,   540,   373,   397,   449,
       0,   446,   473,   121,    52,    53,    50,    51,   127,   126,
       0,    86,     0,     0,   105,   106,   111,    70,    71,    48,
      49,    69,   700,     0,   703,   730,     0,   693,   692,   697,
     696,   728,     0,     0,   705,     0,   701,   704,   683,     0,
       0,     0,     0,     0,     0,     0,   139,   142,     0,     0,
       0,   109,   112,     0,     0,     0,   162,     0,     0,   590,
       0,     0,     0,     0,   542,     0,   244,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   225,     0,     0,     0,
       0,   270,     0,   267,   272,   228,   137,   132,   135,     0,
     182,     0,     0,    67,    61,    64,    63,     0,    59,   261,
       0,     0,   162,     0,   301,   305,     0,     0,     0,   308,
       0,     0,   314,     0,     0,   321,     0,   325,     0,   394,
     393,   162,     0,     0,   189,     0,   191,   302,     0,     0,
       0,   493,     0,   482,     0,   516,   513,     0,   517,   518,
       0,     0,   512,     0,   487,   515,   514,     0,     0,     0,
     609,   610,   606,     0,     0,   614,   615,   611,   620,   618,
       0,     0,     0,   624,   194,     0,     0,     0,     0,     0,
       0,   625,   626,     0,   203,    22,     0,    13,    17,    18,
     284,   296,     0,   297,     0,   288,   289,   290,   291,     0,
     280,     0,     0,     0,   644,   657,     0,   345,   347,     0,
     676,     0,     0,     0,     0,     0,     0,   632,   634,   635,
     671,   672,   673,   675,   674,     0,     0,   648,   647,     0,
     651,   655,   669,   667,   666,   659,   663,     0,     0,     0,
       0,     0,     0,     0,     0,   546,   548,   547,   544,   541,
     475,   129,   128,    87,   101,   717,   698,     0,   722,     0,
     722,   711,   706,   143,     0,     0,     0,   113,   141,     0,
      23,     0,   587,   588,   591,   584,   585,   243,     0,     0,
     256,   248,     0,   252,     0,   246,     0,     0,     0,   265,
       0,     0,     0,   227,   268,   271,     0,   133,     0,     0,
      66,     0,    60,   262,     0,     0,   304,   306,   311,     0,
     309,     0,     0,     0,     0,     0,   315,     0,     0,     0,
       0,   322,     0,     0,   326,   395,     0,   580,   578,   190,
       0,     0,   492,     0,     0,   524,     0,   492,     0,   488,
      10,     0,     0,     0,     0,     0,   623,     0,     0,     0,
       0,     0,   627,   631,   300,   298,   299,   292,   293,   294,
     286,     0,   281,   279,   661,   652,   658,     0,     0,   731,
     732,   742,   741,   740,     0,     0,     0,     0,   733,   638,
     739,     0,   636,   640,     0,     0,   645,   649,     0,   670,
     665,   668,   664,     0,     0,   555,     0,   551,   602,   545,
     756,   754,   755,   757,   718,     0,     0,   716,   723,   724,
     720,     0,   715,     0,   713,     0,     0,     0,     0,     0,
       0,   533,   245,     0,   254,     0,     0,   250,     0,   253,
     266,   274,   275,   269,   226,     0,     0,     0,    62,   264,
     539,     0,     0,   312,   316,   310,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   535,     0,     0,
     492,     0,   519,     0,   492,   607,   608,   612,   613,   619,
     621,     0,     0,     0,     0,   628,   295,   282,   656,   743,
       0,     0,   735,     0,   681,   680,   679,   678,   677,   642,
       0,   734,     0,   599,     0,     0,   727,   726,   725,     0,
     719,   712,   710,     0,   707,   708,   702,   144,   146,   148,
       0,     0,     0,     0,     0,   249,   247,     0,   255,     0,
     199,   329,    68,   307,   313,     0,   327,   323,     0,     0,
       0,   317,     0,     0,   319,     0,   502,   496,   491,     0,
     492,   483,     0,     0,     0,     0,   737,   736,     0,     0,
     600,   556,     0,   721,   714,     0,     0,   150,   149,     0,
       0,     0,     0,   145,   251,     0,     0,     0,     0,     0,
       0,   510,   504,     0,   503,   505,   511,   508,   498,     0,
     497,   499,   509,   485,     0,   484,     0,   629,   738,   650,
     601,   709,   147,   151,     0,     0,     0,     0,   273,     0,
       0,   320,   318,     0,     0,   495,   506,   507,   494,   500,
     501,   486,     0,   152,     0,     0,     0,   328,   324,     0,
       0,     0,     0,     0,     0,     0,     0,   154,     0,   153,
       0,     0,     0,     0,     0,     0,     0,     0,   155
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1425, -1425,  -211,  1088, -1425,  1092,  1100, -1425,  1102,  -510,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
    -944, -1425, -1425, -1425, -1425,  -218,  -541, -1425,   627,  -101,
   -1425, -1425, -1425, -1425, -1425,   203,   421, -1425, -1425,    -9,
    -133,   921, -1425,   904, -1425, -1425,  -625, -1425,   356, -1425,
     167, -1425,  -282,  -323, -1425,  -537, -1425,    11,    25,    41,
    -276,  -172, -1425,  -841, -1425, -1425,   -47, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425,   517,   -87,  1260,
       0, -1425, -1425, -1425, -1425,   367, -1425, -1425,  -266, -1425,
       8, -1425, -1425,   168,  -703,  -672, -1425, -1425,   588, -1425,
   -1425,   -53,   153, -1425, -1425, -1425,    52, -1425, -1425,   286,
      59, -1425, -1425,    55, -1232, -1425,   836,   135, -1425, -1425,
     131,  -978, -1425, -1425,   139, -1425, -1425, -1208, -1180, -1425,
     126, -1425, -1425,   739,   744, -1425,  -524, -1425, -1425,   726,
    -628,   293,  -617,   294,   287, -1425, -1425, -1425, -1425, -1425,
    1106, -1425, -1425, -1425, -1425,  -794,  -314, -1117, -1425,   -97,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425,    -5,  -774, -1425,
   -1425,   541,   223, -1425,  -405, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425,   696, -1425,  -958, -1425,   124, -1425,   585,  -778,
   -1425, -1425, -1425, -1425, -1425,  -310,  -301, -1136,  -839, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   504,
    -711,  -786,   221,  -779, -1425,    67,  -835, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425,   945,   949,  -235,   424,   259, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425,   111, -1425, -1425,   104, -1425,   103, -1028,
   -1425, -1425, -1425,    72,    62,   -96,   320, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
      78, -1425, -1425, -1425,   -91,   316,   453, -1425, -1425, -1425,
   -1425, -1425,   252, -1425, -1425, -1424, -1425, -1425, -1425,  -564,
   -1425,    38, -1425,  -108, -1425, -1425, -1425, -1425, -1214, -1425,
      80, -1425, -1425, -1425, -1425,  1292, -1425, -1425, -1425, -1425,
   -1425,  -390,  -353,  1002,   148, -1425
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   248,   822,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
    1203,   746,   266,   267,   268,   269,   270,   271,   902,   903,
     904,   272,   273,   274,   908,   909,   910,   275,   426,   276,
     277,   674,   278,   428,   429,   430,   443,   736,   737,   279,
    1156,   280,  1607,  1608,   281,   282,   283,   532,   284,   285,
     286,   287,   288,   739,   289,   290,   515,   291,   292,   293,
     294,   295,   296,   609,   297,   298,   817,   818,   299,   300,
     543,   302,   610,   441,   969,   970,   303,   611,   304,   613,
     544,   306,   729,   730,  1191,   450,   307,   451,   452,   733,
    1192,  1193,  1194,   614,   615,  1064,  1065,  1462,   616,  1061,
    1062,  1295,  1296,  1297,  1298,   308,   758,   759,   309,  1218,
    1219,  1411,   310,  1221,  1222,   311,   312,  1224,  1225,  1226,
    1227,   313,   314,   315,   316,   851,   317,  1307,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   634,   635,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   662,   663,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   880,   358,   359,   360,  1253,   789,   790,   791,
    1638,  1679,  1680,  1673,  1674,  1681,  1675,  1254,  1255,   361,
     362,  1256,   363,   364,   365,   366,   367,   368,   369,  1105,
     964,  1090,  1348,  1091,  1496,  1092,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   765,  1168,   380,   381,
     382,   383,  1094,  1095,  1096,  1097,   384,   385,   386,   387,
     388,   389,   807,   808,   390,  1281,  1282,  1575,  1049,  1072,
    1317,  1318,  1073,  1074,  1075,  1076,  1077,  1327,  1486,  1487,
    1078,  1330,  1079,  1467,  1080,  1081,  1335,  1336,  1492,  1490,
    1319,  1320,  1321,  1322,  1587,   703,   929,   930,   931,   932,
     933,   934,  1146,  1516,  1604,  1147,  1514,  1602,   935,  1360,
    1511,  1507,  1508,  1509,   936,   937,  1323,  1331,  1477,  1324,
    1473,  1308,   391,   392,   393,   535,  1098,  1099,  1100,  1101,
    1102,  1204,   552,   394,   395,   396
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       301,   675,   675,   427,   301,   301,   301,   579,   305,   595,
     857,  1018,   305,   305,   305,   401,   404,   405,   678,   657,
    1220,   534,   542,   547,   860,   861,   862,   863,   962,   402,
     402,   402,  1431,  1093,  1093,   587,   560,   984,  1208,   612,
    1303,  1364,  1048,   590,  1421,   403,   403,   403,  1119,   996,
     831,   833,   826,   829,   832,   834,   743,   747,   592,   963,
     889,  1070,  1252,  1010,  1458,  1459,   793,   698,   510,  1180,
    1093,    11,   958,     9,    10,     9,    10,   588,   713,   824,
     827,  1610,   588,  1104,   588,   966,   408,   409,   588,   410,
     411,  1605,     9,    10,   412,   847,   412,   848,   849,   588,
     850,   755,   852,   588,  1157,   413,   414,   562,   301,   588,
     853,   854,  1177,   412,   448,  1488,   305,  1439,   677,  1036,
    1636,   415,   413,   415,  1093,  1474,  1123,   595,   416,   960,
     959,  1386,   960,   402,  1412,   734,  1412,  1093,     9,    10,
     415,  1019,  1505,   594,  1412,   416,  1243,   959,   959,   533,
     599,    79,   599,  1292,  1278,  1574,   599,   597,   709,   417,
     418,   419,   639,   993,   687,    90,  1469,   656,  1305,  1309,
     564,   677,   718,  1174,  1294,   599,   417,   418,  1057,  1181,
     640,  1210,   961,   918,  1159,   919,  1197,  1611,   457,   719,
     104,   125,   125,  1160,  1067,   983,   688,  1068,   596,   995,
    1126,   744,  1648,  1470,   735,  1245,  1506,  1020,   420,  1637,
    1283,  1283,  1244,   408,   409,  1025,   410,   411,   125,   406,
    1413,   512,  1542,   593,  1677,  1576,   462,   952,   920,   988,
    1547,  1691,   794,   414,   993,   512,   787,   449,  1242,   658,
     598,  1310,  1309,  1415,   994,   967,  1037,   301,   745,  1093,
     301,  1421,  1520,  1109,  1185,   305,   449,   595,   305,   512,
    1196,  1182,  1552,  1402,  1029,   589,  1120,   421,   449,  1612,
     591,   512,   819,   512,  1070,  1070,   821,  1466,   612,  1352,
     831,   833,   968,  1475,  1476,   301,  1252,  1054,  1286,   563,
    1178,  1056,  1183,   305,   594,  1252,    11,  1285,  1439,  1069,
    1603,   742,   463,   599,   449,  1339,   915,   449,   422,   824,
     827,   449,  1211,   720,  1310,  1012,   596,   571,  1248,   693,
    1249,   694,   572,  1311,  1312,  1023,  1313,  1066,  1157,  1678,
    1553,   842,   710,  1314,   423,   420,   664,  1026,  1027,   666,
     711,   884,   424,  1315,   884,   953,  1114,   407,  1250,   723,
     425,   423,  1028,   695,  1580,  1316,   981,   740,   693,   424,
     694,  1635,   960,  1115,  1093,  1644,   752,   425,   955,   464,
     465,   825,   828,   763,   764,   820,    79,  1657,   921,   696,
    1004,   973,   770,  1245,  1024,   599,  1030,  1031,  1093,   977,
      90,   922,   980,   923,   421,   599,  1311,  1312,   599,  1313,
    1609,  1032,  1677,   301,   924,   925,   926,   599,   927,   431,
     928,   305,  1378,  1397,  1005,   104,  1315,   960,   696,  1067,
     639,   885,  1068,  1007,   886,   954,  1693,   601,  1316,  1553,
    1581,   602,   301,   647,   301,   422,   603,  1418,   640,   595,
     305,   697,   305,   125,   599,  1110,   596,   648,   956,  1357,
    1071,  1367,  1110,   534,   604,   599,   599,   714,   301,   717,
     959,   974,   792,   301,  1421,   976,   305,  1525,   645,   599,
    1379,   305,  1021,   715,   796,   715,  1252,   646,   998,  1113,
     697,   599,   599,   761,  1116,   434,   599,   999,   767,   512,
     813,   815,   512,   599,  1006,   959,  1248,  1609,  1249,   715,
     599,  1117,  1093,  1008,   715,   599,  1048,  1709,  1359,  1453,
    1387,  1070,  1184,   831,   833,   831,   639,  1287,  1288,  1289,
    1070,   466,  1127,  1128,  1040,  1111,  1250,  1131,  1245,  1246,
    1584,  1070,  1112,   301,   640,  1238,  1239,  1585,   595,  1609,
     301,   305,  1009,   679,  1594,  1599,   835,  1586,   305,  1240,
     836,  1495,   605,  1245,  1246,   606,   680,  1165,  1022,  1047,
     685,   512,   874,   875,   512,   402,  1571,   599,   512,   873,
     607,   512,   512,  1572,   876,   427,   638,   435,   301,   512,
    1573,   403,  1108,   442,  1093,   512,   305,  1093,   512,   301,
     301,   301,   301,  1622,  1415,   608,   512,   305,   305,   305,
     305,  1051,   512,   512,   512,   512,   641,   301,   599,  1729,
     512,  1730,   599,   639,  1055,   305,   659,   660,   512,   814,
    1738,  1247,    11,   601,  1595,  1600,  1671,   602,   596,   584,
    1245,   640,   603,  1551,   444,   642,  1555,  1187,   681,  1143,
     455,  1248,  1188,  1249,  1464,   585,  1247,  1149,   643,   456,
     604,   682,  1150,   718,  1559,  1144,   601,   514,   683,  1563,
     602,  1189,   512,  1071,  1071,   603,  1248,  1151,  1249,  1152,
     719,  1250,  1245,  1246,   684,   111,   512,   905,  1153,  1345,
     960,  1526,   644,   604,   661,  1687,   667,   512,  1481,  1689,
    1070,  1357,   123,  1013,  1014,  1015,  1250,   815,  1145,   467,
     111,  1190,    79,  1245,  1246,  1154,  1671,  1358,   468,   438,
    1245,  1346,  1251,  1052,   439,   301,    90,   123,  1167,   906,
    1170,   512,   445,   305,   907,   460,  1471,  1217,  1347,   585,
     149,  1187,   446,  1472,  1217,   461,  1188,  1433,   301,   469,
    1409,   104,   470,  1248,   831,  1249,   305,  1414,   605,   975,
    1359,   606,   549,  1672,  1584,   149,   657,  1093,   447,  1093,
     440,  1585,  1118,   402,  1274,  1247,   785,  1351,   301,   301,
    1232,  1586,  1233,  1250,   960,  1419,   305,   305,   738,   403,
     612,   605,  1639,   738,   606,  1248,  1642,  1249,  1420,  1143,
    1093,   608,   432,  1002,  1003,   433,  1247,  1676,  1682,  1279,
    1137,  1121,   513,  1332,  1333,  1144,  1650,  1422,  1651,   715,
     715,  1138,  1400,  1121,  1045,  1250,  1248,  1093,  1249,   111,
    1423,   427,  1046,  1248,   608,  1249,  1334,  1139,   516,  1419,
    1419,  1155,  1093,  1706,  1093,  1676,   123,   891,  1140,  1666,
     512,  1682,  1558,  1686,   517,  1291,  1250,  1582,  1583,   959,
     111,  1579,   707,  1250,   512,  1292,  1438,   708,   512,   512,
    1292,   436,  1684,   906,   437,  1293,  1690,   123,   907,  1132,
    1133,  1134,   579,  1187,   149,  1135,  1294,  1284,  1188,   528,
     512,  1700,   512,  1703,   665,   877,   529,  1561,   877,   668,
     512,   877,   453,   512,   565,   454,   566,   512,  1658,   619,
    1071,   458,  1454,   530,   459,   149,   550,   620,   621,  1071,
     622,   699,   700,   701,   568,  1258,   569,  1259,   623,  1263,
    1071,  1264,   624,   557,   625,  1398,  1129,  1130,   558,   626,
    1455,  1456,   858,   859,   866,   867,   512,  1106,  1106,   864,
     865,  1596,  1597,   559,   561,   567,   627,   570,   573,   574,
     575,   577,  1646,  1647,   892,   893,   894,   895,   896,   897,
     898,   899,   900,   901,   512,   576,   578,   581,   599,   628,
     629,   630,   631,   632,   633,   600,   617,   618,   637,   636,
    1302,   649,   650,   651,   669,   652,   512,   661,   670,   671,
     677,   672,   673,   689,   691,   692,   702,   706,   716,   727,
     301,   728,   738,   842,   732,   741,   749,   750,   305,   751,
     762,  1538,   768,   769,   433,   777,   512,   512,   512,   512,
    1688,   775,   437,   454,   459,  1228,   470,   779,   780,   784,
     781,   782,   786,   788,   795,   797,   798,   801,   810,   823,
    1045,   715,   806,   811,   427,   838,   839,   816,  1046,   855,
     840,   841,   869,   512,   301,   301,   301,   868,   870,   871,
     881,   887,   305,   305,   305,   888,   890,   512,   912,   913,
     916,  1577,   917,   938,   939,   511,   940,   942,   947,  1071,
     944,   948,   949,   950,   957,   972,   951,   979,   978,   527,
     982,   989,   512,   990,   991,  1000,   997,   992,  1001,  1033,
    1034,   512,  1053,   512,  1059,  1039,  1063,   512,  1122,  1035,
    1038,   907,   959,   548,  1141,  1158,  1163,  1172,  1164,  1142,
     512,  1173,  1179,  1166,  1186,   553,  1175,   556,   734,  1199,
    1201,  1200,  1202,  1205,  1206,  1207,  1212,  1544,  1213,  1216,
    1217,  1236,  1223,  1229,  1241,  1230,  1257,  1235,  1231,  1271,
     695,  1299,  1275,   512,  1276,   512,  1301,  1280,  1325,  1326,
    1329,    11,  1278,  1277,  1356,  1361,   301,  1337,  1338,  1340,
    1341,  1306,  1349,  1372,   305,  1342,  1355,  1371,  1343,  1344,
    1382,  1365,  1369,  1374,  1384,  1391,  1401,  1392,  1448,  1449,
    1450,   402,  1388,  1390,  1404,  1366,  1396,  1419,  1432,  1435,
    1292,   301,  1425,  1441,  1442,  1370,  1443,   403,  1461,   305,
    1484,   512,   301,  1373,  1375,  1440,  1376,  1427,  1445,  1428,
     305,  1430,  1485,  1405,  1489,  1491,  1504,  1510,  1515,  1447,
    1468,   301,   512,  1478,  1465,  1497,  1519,   402,  1498,   305,
    1499,  1500,  1426,  1501,  1517,  1502,  1503,  1523,  1521,  1535,
     301,  1528,  1536,   403,  1537,  1513,   402,  1540,   305,  1620,
    1590,  1541,  1546,  1549,  1556,  1557,  1562,  1578,  1591,  1444,
    1624,  1544,   403,  1626,  1592,  1436,  1593,  1601,  1045,  1045,
    1634,  1143,  1606,  1614,  1617,  1619,  1046,  1046,  1625,  1629,
    1643,   715,  1633,  1652,  1641,  1653,  1655,  1656,  1660,  1665,
    1667,  1668,  1669,  1696,  1661,  1683,  1685,  1705,  1699,  1697,
    1704,  1708,  1712,  1711,  1734,  1719,  1720,  1716,  1725,   814,
     512,  1735,   914,   512,  1654,  1731,  1354,  1124,   676,  1198,
    1368,   712,  1663,  1692,  1050,   580,  1613,  1195,   512,   987,
    1377,  1533,   582,   511,  1395,  1290,   511,   512,  1406,  1410,
     583,  1457,  1424,  1463,  1722,   586,   845,  1626,  1460,  1694,
    1416,   512,   846,   856,   776,  1714,   883,  1398,  1434,  1723,
    1710,   512,  1732,  1707,  1017,  1107,  1726,  1728,  1363,  1171,
     721,  1353,  1446,  1451,   722,  1452,  1479,  1483,  1589,  1304,
    1588,  1148,  1701,  1737,  1328,  1480,  1482,  1362,  1512,   512,
    1598,   545,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   301,     0,   686,     0,     0,   690,   512,
       0,   305,   553,  1717,     0,   704,   705,     0,   512,     0,
       0,   512,     0,   553,     0,   655,     0,     0,     0,   726,
       0,     0,   731,     0,  1717,     0,     0,     0,     0,  1701,
     748,     0,     0,     0,     0,     0,   553,   756,   757,   760,
       0,     0,     0,     0,   766,     0,     0,     0,     0,     0,
       0,     0,   773,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   512,     0,  1645,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1649,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   512,     0,     0,   774,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     760,     0,     0,     0,     0,  1045,     0,     0,     0,   512,
     512,   783,     0,  1046,     0,     0,  1045,  1045,     0,   301,
       0,     0,     0,     0,  1046,  1046,  1045,   305,     0,     0,
       0,     0,     0,     0,  1046,   512,     0,   512,     0,     0,
     512,     0,     0,     0,     0,   809,     0,     0,     0,     0,
       0,   512,     0,     0,     0,     0,   512,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1045,     0,     0,     0,     0,     0,     0,
       0,  1046,     0,  1045,     0,     0,     0,     0,     0,     0,
       0,  1046,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   301,     0,
       0,     0,     0,     0,     0,     0,   305,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   911,     0,     0,     0,   512,   301,
     512,     0,   512,     0,     0,     0,     0,   305,   941,   512,
       0,     0,   945,   946,     0,     0,     0,     0,     0,     0,
    1045,     0,     0,     0,     0,  1045,     0,     0,  1046,     0,
       0,     0,     0,  1046,   965,     0,   971,     0,     0,     0,
     512,     0,   512,     0,   553,     0,     0,   553,     0,     0,
       0,   985,     0,     0,     0,     0,     0,     0,   512,     0,
       0,   512,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   512,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   512,     0,     0,     0,     0,     0,     0,
    1016,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     512,     0,     0,     0,     0,     0,     0,     0,   512,     0,
       0,     0,     0,   512,     0,   512,     0,   512,   511,     0,
       0,     0,     0,     0,     0,   799,   800,     0,   802,   803,
     804,   805,     0,     0,     0,     0,   812,     0,     0,     0,
    1058,     0,     0,     0,   512,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   837,
     512,     0,     0,     0,   512,     0,     0,   843,   844,     0,
    1103,  1103,  1103,  1103,     0,     0,     0,     0,     0,     0,
     512,     0,     0,   512,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1136,     0,     0,     0,     0,     0,   879,     0,     0,
     879,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1162,     0,     0,     0,
       0,     0,     0,     0,     0,  1169,     0,  1169,     0,     0,
       0,  1103,     0,     0,     0,     0,     0,     0,   943,     0,
       0,     0,     0,     0,  1103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   766,     0,   766,
     986,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1011,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   843,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1300,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1060,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1125,     0,     0,
       0,     0,     0,     0,   731,     0,     0,  1380,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1394,     0,     0,     0,     0,     0,     0,     0,
       0,  1103,  1161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   760,     0,     0,     0,     0,
       0,  1176,     0,     0,     0,  1103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1209,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1437,  1214,  1215,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1234,
       0,     0,  1237,   809,     0,     0,     0,     0,     0,     0,
       0,     0,   511,     0,     0,   511,  1260,  1261,  1262,     0,
    1265,  1266,  1267,  1268,  1269,  1270,     0,  1272,  1273,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1060,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1518,     0,     0,
    1350,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1531,  1532,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1548,
       0,  1103,     0,     0,  1103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1560,     0,  1381,     0,  1383,
    1564,  1385,     0,     0,  1389,     0,     0,     0,     0,  1393,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1399,     0,     0,     0,     0,     0,     0,     0,     0,
    1403,     0,     0,     0,     0,     0,  1407,  1408,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1429,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1628,     0,  1630,     0,  1632,     0,     0,  1060,
       0,     0,     0,  1640,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1103,     0,  1103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1659,     0,     0,  1662,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1670,  1522,     0,
       0,     0,  1524,     0,     0,     0,  1527,     0,  1529,     0,
    1530,     0,     0,     0,  1103,     0,  1534,     0,     0,     0,
       0,     0,  1695,     0,  1539,     0,     0,  1698,     0,  1103,
       0,  1103,  1543,  1545,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1399,     0,     0,     0,     0,     0,     0,     0,  1715,     0,
       0,  1565,  1566,  1567,  1568,  1569,     0,  1570,     0,     0,
       0,     0,     0,     0,  1721,     0,     0,     0,  1724,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1733,     0,     0,  1736,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1615,     0,  1616,     0,     0,  1618,     0,
       0,     0,     0,     0,     0,     0,  1621,     0,     0,     0,
       0,  1623,  1545,     0,     0,     0,     0,     0,     0,  1627,
       0,     0,     0,  1631,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1664,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1627,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1702,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1713,     0,     0,     0,     0,  1718,
       0,     0,     1,     2,  1702,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,  1718,
      11,     0,     0,  1727,    12,    13,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
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
     147,   148,   149,     0,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,     0,     0,     0,   397,   398,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   399,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,   531,     0,   129,     0,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   400,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   397,   398,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   399,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     0,   110,
     111,   112,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,   124,
     125,     0,     0,   126,   127,   128,     0,   778,     0,   129,
       0,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   400,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,     0,    11,     0,     0,     0,   397,   398,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,  1041,   399,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,  1042,  1043,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,   778,     0,
     129,     0,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   400,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,  1044,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,   397,
     398,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,  1041,   399,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,  1042,  1043,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   124,   125,     0,     0,   126,   127,   128,     0,   531,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   400,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,  1044,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,     0,     0,     0,
     397,   398,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   399,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,   124,   125,     0,     0,   126,   127,   128,     0,
       0,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     400,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,    12,    13,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108,   109,     0,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   124,   125,     0,     0,   126,   127,   128,
       0,     0,     0,   129,     0,   130,   131,     0,   132,   133,
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
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,    12,    13,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   400,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,    12,   398,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,    74,
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
     148,   149,     0,   400,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,     0,     0,     0,   830,   398,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     399,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
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
     147,   148,   149,     0,   400,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   397,   398,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    1041,   399,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,  1042,  1043,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    78,     0,     0,
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
       0,   147,   148,   149,     0,   400,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,  1044,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   397,   398,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   536,   399,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,   537,   538,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   488,    82,    83,    84,    85,    86,
     539,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   540,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,   546,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   400,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   505,
     506,   507,   176,   177,   508,   541,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   397,   398,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   536,   399,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   537,   538,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   488,    82,    83,    84,    85,
      86,   539,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   540,   109,     0,   110,
     111,   112,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,   124,
     125,     0,     0,   126,   127,   128,     0,   872,     0,   129,
       0,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   400,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     505,   506,   507,   176,   177,   508,   541,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   397,   398,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   536,   399,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,   537,   538,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   488,    82,    83,    84,
      85,    86,   539,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   540,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,   878,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   400,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   505,   506,   507,   176,   177,   508,   541,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   397,
     398,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   536,   399,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,   537,   538,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   488,    82,    83,
      84,    85,    86,   539,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   540,   109,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   124,   125,     0,     0,   126,   127,   128,     0,     0,
       0,   129,   882,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   400,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   505,   506,   507,   176,   177,   508,   541,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     397,   398,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   536,   399,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,   537,
     538,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   488,    82,
      83,    84,    85,    86,   539,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   540,
     109,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,   124,   125,     0,     0,   126,   127,   128,     0,
       0,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     400,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   505,   506,   507,   176,   177,   508,   541,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   397,   398,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   474,    25,   476,   399,    28,   477,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   479,     0,    45,    46,    47,
     481,   482,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   488,
      82,    83,    84,    85,    86,   539,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   491,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     540,   109,     0,   110,   111,   653,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   654,   125,     0,     0,   126,   127,   128,
       0,     0,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   400,   151,   152,   153,   154,   155,   156,   157,   158,
     500,   160,   501,   162,   502,   503,   165,   166,   167,   168,
     169,   170,   504,   172,   505,   506,   507,   176,   177,   508,
     509,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   397,   398,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   474,    25,   476,   399,    28,
     477,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,   479,     0,    45,    46,
      47,   481,   482,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     488,    82,    83,    84,    85,    86,   539,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   491,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   540,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   400,   151,   152,   153,   154,   155,   156,   157,
     158,   500,   160,   501,   162,   502,   503,   165,   166,   167,
     168,   169,   170,   504,   172,   505,   506,   507,   176,   177,
     508,   509,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   397,   398,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   474,    25,   476,   399,
      28,   477,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   479,     0,    45,
      46,    47,   481,   482,    50,   483,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   488,    82,    83,    84,    85,    86,   539,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   491,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   540,   109,     0,   110,   111,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,     0,     0,     0,     0,   126,
     127,   128,     0,     0,     0,   129,     0,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   400,   151,   152,   153,   154,   155,   156,
     157,   158,   500,   160,   501,   162,   502,   503,   165,   166,
     167,   168,   169,   170,   504,   172,   505,   506,   507,   176,
     177,   508,   509,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   397,   398,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   474,    25,   476,
     399,    28,   477,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,   479,     0,
      45,    46,    47,   481,   482,    50,   483,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   488,    82,    83,    84,    85,    86,   539,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   491,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   540,   109,     0,   110,   111,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,     0,     0,     0,     0,
     126,   127,   128,     0,     0,     0,   129,     0,   130,   131,
       0,     0,     0,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   400,   151,   152,   153,   154,   155,
     156,   157,   158,   500,   160,   501,   162,   502,   503,   165,
     166,   167,   168,   169,   170,   504,   172,   505,   506,   507,
     176,   177,   508,   509,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,   397,   398,     0,    14,    15,
      16,   471,    18,    19,    20,   472,    22,   473,   474,   475,
     476,   399,    28,   477,    30,    31,     0,    32,    33,    34,
      35,   478,    37,    38,    39,    40,    41,    42,    43,   479,
       0,    45,   480,    47,   481,   482,    50,   483,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   484,   485,    68,     0,    69,    70,    71,   486,
       0,    74,    75,    76,     0,     0,   487,    78,     0,     0,
       0,     0,    80,   488,    82,   489,   490,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   491,    97,    98,   492,
     493,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     494,   120,   121,   495,     0,     0,     0,     0,     0,     0,
       0,   496,   497,   128,     0,     0,     0,   129,     0,   130,
     498,     0,     0,     0,   134,     0,   135,     0,   136,   137,
     138,   139,   499,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   400,   151,   152,   153,   154,
     155,   156,   157,   158,   500,   160,   501,   162,   502,   503,
     165,   166,   167,   168,   169,   170,   504,   172,   505,   506,
     507,   176,   177,   508,   509,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,   397,   398,     0,    14,
      15,    16,   518,    18,    19,    20,   472,   519,   520,   474,
     475,   476,   399,    28,   477,    30,    31,     0,    32,    33,
      34,    35,   521,    37,   522,   523,    40,    41,    42,    43,
     479,     0,    45,   524,    47,   481,   482,    50,   483,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   484,   485,    68,     0,    69,    70,    71,
     525,     0,    74,    75,    76,     0,     0,   487,    78,     0,
       0,     0,     0,    80,   488,    82,   489,   490,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   491,    97,    98,
     492,   493,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   494,   120,   121,   495,     0,     0,     0,     0,     0,
       0,     0,   496,   497,   128,     0,     0,     0,   129,     0,
     130,   498,     0,     0,     0,   134,     0,   135,     0,   136,
     137,   138,   139,   499,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,     0,     0,   400,   151,   152,   153,
     154,   155,   156,   157,   158,   500,   526,   501,   162,   502,
     503,   165,   166,   167,   168,   169,   170,   504,   172,   505,
     506,   507,   176,   177,   508,   509,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   551,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,   753,     0,
       0,     0,   397,   398,     0,    14,    15,    16,   518,    18,
      19,    20,   472,   519,   520,   474,   475,   476,   399,    28,
     477,    30,    31,     0,    32,    33,    34,    35,   521,    37,
     522,   523,    40,    41,    42,    43,   479,     0,    45,   524,
      47,   481,   482,    50,   483,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   484,
     485,    68,     0,    69,    70,    71,   525,     0,    74,    75,
      76,     0,     0,   487,    78,     0,     0,     0,     0,    80,
     488,    82,   489,   490,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   491,    97,    98,   492,   493,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   494,   120,   121,
     495,     0,     0,     0,     0,     0,     0,     0,   496,   497,
     128,     0,     0,     0,   129,   754,   130,   498,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   499,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
       0,     0,   400,   151,   152,   153,   154,   155,   156,   157,
     158,   500,   526,   501,   162,   502,   503,   165,   166,   167,
     168,   169,   170,   504,   172,   505,   506,   507,   176,   177,
     508,   509,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   551,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,   397,   398,
       0,    14,    15,    16,   518,    18,    19,    20,   472,   519,
     520,   474,   475,   476,   399,    28,   477,    30,    31,     0,
      32,    33,    34,    35,   521,    37,   522,   523,    40,    41,
      42,    43,   479,     0,    45,   524,    47,   481,   482,    50,
     483,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   484,   485,    68,     0,    69,
      70,    71,   525,     0,    74,    75,    76,     0,     0,   487,
      78,     0,     0,     0,     0,    80,   488,    82,   489,   490,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   491,
      97,    98,   492,   493,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,   107,     0,     0,     0,
       0,     0,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   494,   120,   121,   495,     0,     0,     0,
       0,     0,     0,     0,   496,   497,   128,     0,     0,     0,
     129,     0,   130,   498,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   499,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,     0,     0,   400,   151,
     152,   153,   154,   155,   156,   157,   158,   500,   526,   501,
     162,   502,   503,   165,   166,   167,   168,   169,   170,   504,
     172,   505,   506,   507,   176,   177,   508,   509,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   554,   555,     0,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,   397,   398,     0,    14,    15,    16,   518,    18,
      19,    20,   472,   519,   520,   474,   475,   476,   399,    28,
     477,    30,    31,     0,    32,    33,    34,    35,   521,    37,
     522,   523,    40,    41,    42,    43,   479,     0,    45,   524,
      47,   481,   482,    50,   483,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   484,
     485,    68,     0,    69,    70,    71,   525,     0,    74,    75,
      76,     0,     0,   487,    78,     0,     0,     0,     0,    80,
     488,    82,   489,   490,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   491,    97,    98,   492,   493,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   494,   120,   121,
     495,     0,     0,     0,     0,     0,     0,     0,   496,   497,
     128,     0,     0,     0,   129,     0,   130,   498,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   499,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
       0,     0,   400,   151,   152,   153,   154,   155,   156,   157,
     158,   500,   526,   501,   162,   502,   503,   165,   166,   167,
     168,   169,   170,   504,   172,   505,   506,   507,   176,   177,
     508,   509,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,     7,     8,     0,     0,     0,     0,     0,     0,     0,
     397,   398,     0,    14,    15,    16,   471,    18,    19,    20,
     472,    22,   473,   474,  1082,   476,   399,    28,   477,    30,
      31,     0,    32,    33,    34,    35,   478,    37,    38,    39,
      40,    41,    42,    43,   479,     0,    45,   480,    47,   481,
     482,    50,   483,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   484,   485,    68,
       0,    69,    70,    71,   486,     0,    74,    75,    76,     0,
       0,   487,    78,     0,     0,     0,     0,    80,   488,    82,
     489,   490,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   491,    97,    98,   492,   493,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,  1083,     0,
       0,     0,  1084,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   494,   120,   121,   495,     0,
       0,     0,     0,     0,     0,     0,   496,   497,   128,     0,
       0,     0,   129,  1493,   130,   498,     0,     0,     0,  1494,
       0,   135,     0,   136,   137,   138,   139,   499,   141,   142,
     143,   144,   145,   146,     0,     0,  1085,   148,     0,     0,
     400,   151,   152,   153,   154,   155,   156,   157,   158,   500,
     160,   501,   162,   502,   503,   165,   166,   167,   168,   169,
     170,   504,   172,   505,   506,   507,   176,   177,   508,   509,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,  1086,  1087,  1088,  1089,     7,
       8,     0,     0,     0,     0,     0,     0,     0,   397,   398,
       0,    14,    15,    16,   518,    18,    19,    20,   472,   519,
     520,   474,   475,   476,   399,    28,   477,    30,    31,     0,
      32,    33,    34,    35,   521,    37,   522,   523,    40,    41,
      42,    43,   479,     0,    45,   524,    47,   481,   482,    50,
     483,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   484,   485,    68,     0,    69,
      70,    71,   525,     0,    74,    75,    76,     0,     0,   487,
      78,     0,     0,     0,     0,    80,   488,    82,   489,   490,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   491,
      97,    98,   492,   493,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,   107,     0,     0,     0,
       0,     0,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   494,   120,   121,   495,     0,     0,     0,
       0,     0,     0,     0,   496,   497,   128,     0,     0,     0,
     129,   724,   130,   498,     0,     0,     0,   725,     0,   135,
       0,   136,   137,   138,   139,   499,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,     0,     0,   400,   151,
     152,   153,   154,   155,   156,   157,   158,   500,   526,   501,
     162,   502,   503,   165,   166,   167,   168,   169,   170,   504,
     172,   505,   506,   507,   176,   177,   508,   509,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     7,     8,     0,
       0,     0,     0,     0,     0,     0,   397,   398,     0,    14,
      15,    16,   518,    18,    19,    20,   472,   519,   520,   474,
     475,   476,   399,    28,   477,    30,    31,     0,    32,    33,
      34,    35,   521,    37,   522,   523,    40,    41,    42,    43,
     479,     0,    45,   524,    47,   481,   482,    50,   483,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   484,   485,    68,     0,    69,    70,    71,
     525,     0,    74,    75,    76,     0,     0,   487,    78,     0,
       0,     0,     0,    80,   488,    82,   489,   490,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   491,    97,    98,
     492,   493,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   494,   120,   121,   495,     0,     0,     0,     0,     0,
       0,     0,   496,   497,   128,     0,     0,     0,   129,   771,
     130,   498,     0,     0,     0,   772,     0,   135,     0,   136,
     137,   138,   139,   499,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,     0,     0,   400,   151,   152,   153,
     154,   155,   156,   157,   158,   500,   526,   501,   162,   502,
     503,   165,   166,   167,   168,   169,   170,   504,   172,   505,
     506,   507,   176,   177,   508,   509,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,     7,     8,     0,     0,     0,
       0,     0,     0,     0,   397,   398,     0,    14,    15,    16,
     471,    18,    19,    20,   472,    22,   473,   474,  1082,   476,
     399,    28,   477,    30,    31,     0,    32,    33,    34,    35,
     478,    37,    38,    39,    40,    41,    42,    43,   479,     0,
      45,   480,    47,   481,   482,    50,   483,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   484,   485,    68,     0,    69,    70,    71,   486,     0,
      74,    75,    76,     0,     0,   487,    78,     0,     0,     0,
       0,    80,   488,    82,   489,   490,    85,    86,  1417,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   491,    97,    98,   492,   493,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,  1083,     0,     0,     0,  1084,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   494,
     120,   121,   495,     0,     0,     0,     0,     0,     0,     0,
     496,   497,   128,     0,     0,     0,   129,     0,   130,   498,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   499,   141,   142,   143,   144,   145,   146,     0,     0,
    1085,   148,     0,     0,   400,   151,   152,   153,   154,   155,
     156,   157,   158,   500,   160,   501,   162,   502,   503,   165,
     166,   167,   168,   169,   170,   504,   172,   505,   506,   507,
     176,   177,   508,   509,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,  1086,
    1087,  1088,  1089,     7,     8,     0,     0,     0,     0,     0,
       0,     0,   397,   398,     0,    14,    15,    16,   471,    18,
      19,    20,   472,    22,   473,   474,  1082,   476,   399,    28,
     477,    30,    31,     0,    32,    33,    34,    35,   478,    37,
      38,    39,    40,    41,    42,    43,   479,     0,    45,   480,
      47,   481,   482,    50,   483,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   484,
     485,    68,     0,    69,    70,    71,   486,     0,    74,    75,
      76,     0,     0,   487,    78,     0,     0,     0,     0,    80,
     488,    82,   489,   490,    85,    86,  1550,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   491,    97,    98,   492,   493,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
    1083,     0,     0,     0,  1084,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   494,   120,   121,
     495,     0,     0,     0,     0,     0,     0,     0,   496,   497,
     128,     0,     0,     0,   129,     0,   130,   498,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   499,
     141,   142,   143,   144,   145,   146,     0,     0,  1085,   148,
       0,     0,   400,   151,   152,   153,   154,   155,   156,   157,
     158,   500,   160,   501,   162,   502,   503,   165,   166,   167,
     168,   169,   170,   504,   172,   505,   506,   507,   176,   177,
     508,   509,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,  1086,  1087,  1088,
    1089,     7,     8,     0,     0,     0,     0,     0,     0,     0,
     397,   398,     0,    14,    15,    16,   471,    18,    19,    20,
     472,    22,   473,   474,  1082,   476,   399,    28,   477,    30,
      31,     0,    32,    33,    34,    35,   478,    37,    38,    39,
      40,    41,    42,    43,   479,     0,    45,   480,    47,   481,
     482,    50,   483,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   484,   485,    68,
       0,    69,    70,    71,   486,     0,    74,    75,    76,     0,
       0,   487,    78,     0,     0,     0,     0,    80,   488,    82,
     489,   490,    85,    86,  1554,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   491,    97,    98,   492,   493,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,  1083,     0,
       0,     0,  1084,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   494,   120,   121,   495,     0,
       0,     0,     0,     0,     0,     0,   496,   497,   128,     0,
       0,     0,   129,     0,   130,   498,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   499,   141,   142,
     143,   144,   145,   146,     0,     0,  1085,   148,     0,     0,
     400,   151,   152,   153,   154,   155,   156,   157,   158,   500,
     160,   501,   162,   502,   503,   165,   166,   167,   168,   169,
     170,   504,   172,   505,   506,   507,   176,   177,   508,   509,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,  1086,  1087,  1088,  1089,     7,
       8,     0,     0,     0,     0,     0,     0,     0,   397,   398,
       0,    14,    15,    16,   471,    18,    19,    20,   472,    22,
     473,   474,  1082,   476,   399,    28,   477,    30,    31,     0,
      32,    33,    34,    35,   478,    37,    38,    39,    40,    41,
      42,    43,   479,     0,    45,   480,    47,   481,   482,    50,
     483,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   484,   485,    68,     0,    69,
      70,    71,   486,     0,    74,    75,    76,     0,     0,   487,
      78,     0,     0,     0,     0,    80,   488,    82,   489,   490,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   491,
      97,    98,   492,   493,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,  1083,     0,     0,     0,
    1084,     0,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   494,   120,   121,   495,     0,     0,     0,
       0,     0,     0,     0,   496,   497,   128,     0,     0,     0,
     129,     0,   130,   498,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   499,   141,   142,   143,   144,
     145,   146,     0,     0,  1085,   148,     0,     0,   400,   151,
     152,   153,   154,   155,   156,   157,   158,   500,   160,   501,
     162,   502,   503,   165,   166,   167,   168,   169,   170,   504,
     172,   505,   506,   507,   176,   177,   508,   509,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,  1086,  1087,  1088,  1089,     7,     8,     0,
       0,     0,     0,     0,     0,     0,   397,   398,     0,    14,
      15,    16,   471,    18,    19,    20,   472,    22,   473,   474,
    1082,   476,   399,    28,   477,    30,    31,     0,    32,    33,
      34,    35,   478,    37,    38,    39,    40,    41,    42,    43,
     479,     0,    45,   480,    47,   481,   482,    50,   483,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   484,   485,    68,     0,    69,    70,    71,
     486,     0,    74,    75,    76,     0,     0,   487,    78,     0,
       0,     0,     0,    80,   488,    82,   489,   490,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   491,    97,    98,
     492,   493,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,  1083,     0,     0,     0,  1084,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   494,   120,   121,   495,     0,     0,     0,     0,     0,
       0,     0,   496,   497,   128,     0,     0,     0,   129,     0,
     130,   498,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   499,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,     0,     0,   400,   151,   152,   153,
     154,   155,   156,   157,   158,   500,   160,   501,   162,   502,
     503,   165,   166,   167,   168,   169,   170,   504,   172,   505,
     506,   507,   176,   177,   508,   509,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,  1086,  1087,  1088,  1089,     7,     8,     0,     0,     0,
       0,     0,     0,     0,   397,   398,     0,    14,    15,    16,
     518,    18,    19,    20,   472,   519,   520,   474,   475,   476,
     399,    28,   477,    30,    31,     0,    32,    33,    34,    35,
     521,    37,   522,   523,    40,    41,    42,    43,   479,     0,
      45,   524,    47,   481,   482,    50,   483,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   484,   485,    68,     0,    69,    70,    71,   525,     0,
      74,    75,    76,     0,     0,   487,    78,     0,     0,     0,
       0,    80,   488,    82,   489,   490,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   491,    97,    98,   492,   493,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   494,
     120,   121,   495,     0,     0,     0,     0,     0,     0,     0,
     496,   497,   128,     0,     0,     0,   129,     0,   130,   498,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   499,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   400,   151,   152,   153,   154,   155,
     156,   157,   158,   500,   526,   501,   162,   502,   503,   165,
     166,   167,   168,   169,   170,   504,   172,   505,   506,   507,
     176,   177,   508,   509,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,     7,     8,     0,     0,     0,     0,     0,
       0,     0,   397,   398,     0,    14,    15,    16,     0,    18,
      19,    20,   472,     0,     0,   474,   475,     0,   399,    28,
     477,    30,    31,     0,    32,    33,    34,    35,     0,    37,
       0,     0,    40,    41,    42,    43,   479,     0,    45,     0,
      47,     0,     0,    50,   483,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   484,
     485,    68,     0,    69,    70,    71,     0,     0,    74,    75,
      76,     0,     0,   487,    78,     0,     0,     0,     0,    80,
     488,    82,   489,   490,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   491,    97,    98,   492,   493,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
       0,     0,     0,     0,     0,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   494,   120,   121,
     495,     0,     0,     0,     0,     0,     0,     0,   496,   497,
     128,     0,     0,     0,   129,     0,   130,   498,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   499,
     141,   142,   143,   144,   145,   146,     0,     0,     0,   148,
       0,     0,   400,   151,   152,   153,   154,   155,   156,   157,
     158,   500,     0,   501,   162,   502,   503,   165,   166,   167,
     168,   169,   170,   504,   172,   505,   506,   507,   176,   177,
       0,   509,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   406,   407,    12,     4,     5,     6,   179,     0,   285,
     638,   789,     4,     5,     6,     4,     5,     6,   408,   333,
     998,   108,   109,   110,   641,   642,   643,   644,   731,     4,
       5,     6,  1240,   868,   869,   253,   133,   748,   982,   305,
    1068,  1158,   816,   254,  1224,     4,     5,     6,   889,   760,
     591,   592,   589,   590,   591,   592,   446,   447,   269,   731,
     685,   855,  1020,   774,  1296,  1297,     8,   420,    73,    36,
     905,    29,    36,    26,    27,    26,    27,     1,   431,   589,
     590,   117,     1,   869,     1,    55,    37,    38,     1,    40,
      41,  1515,    26,    27,    47,   619,    47,   621,   622,     1,
     624,   454,   626,     1,   939,    56,    57,    30,   108,     1,
     634,   635,   146,    47,   117,  1329,   108,  1253,    29,   106,
      93,    74,    56,    74,   959,    96,   905,   403,    79,    96,
      94,   146,    96,   108,    99,   117,    99,   972,    26,    27,
      74,   129,   135,   276,    99,    79,   129,    94,    94,   108,
     106,   109,   106,   105,   152,   152,   106,   106,   111,   110,
     111,   112,   157,   106,   168,   123,   215,   152,   152,    96,
     214,    29,    45,   959,   126,   106,   110,   111,   112,   146,
     175,   141,   146,    54,   297,    56,   972,   223,   117,    62,
     148,   176,   176,   306,   152,   141,   200,   155,   285,   146,
     911,   112,   197,   252,   186,     9,   199,   195,   159,   182,
     208,   208,   195,    37,    38,    94,    40,    41,   176,   155,
     185,    73,   185,   111,    28,  1457,    76,   183,    99,   183,
     185,  1655,   174,    57,   106,    87,   186,   271,  1016,   336,
     189,   168,    96,  1221,   187,   215,   233,   247,   159,  1084,
     250,  1431,  1369,   184,   965,   247,   271,   533,   250,   111,
     971,   964,   117,  1207,    94,   189,   891,   218,   271,   305,
     189,   123,   189,   125,  1068,  1069,   189,  1305,   544,  1120,
     821,   822,   252,   254,   255,   285,  1244,   189,   112,   212,
     962,   189,   964,   285,   427,  1253,    29,   189,  1434,   257,
    1514,   159,   152,   106,   271,  1084,   696,   271,   259,   819,
     820,   271,   984,   186,   168,   187,   403,   223,   122,    45,
     124,    47,   228,   250,   251,   130,   253,   851,  1163,   133,
     185,   607,   285,   260,   285,   159,   341,   216,   217,   344,
     293,   106,   293,   270,   106,   106,   147,   155,   152,   436,
     301,   285,   231,    79,    52,   282,   746,   444,    45,   293,
      47,   117,    96,   164,  1199,  1573,   453,   301,   106,   219,
     220,   589,   590,   460,   461,   586,   109,  1609,   249,   105,
     183,   106,   469,     9,   189,   106,   216,   217,  1223,   742,
     123,   262,   745,   264,   218,   106,   250,   251,   106,   253,
    1517,   231,    28,   403,   275,   276,   277,   106,   279,   159,
     281,   403,   146,  1199,   106,   148,   270,    96,   105,   152,
     157,   186,   155,   106,   186,   186,  1658,    42,   282,   185,
     128,    46,   432,   135,   434,   259,    51,  1223,   175,   715,
     432,   167,   434,   176,   106,   106,   533,   149,   186,    96,
     855,  1162,   106,   540,    69,   106,   106,   432,   458,   434,
      94,   186,   549,   463,  1644,   186,   458,   146,   199,   106,
    1173,   463,   183,   432,   561,   434,  1434,   208,   186,   884,
     167,   106,   106,   458,   147,   152,   106,   186,   463,   341,
     577,   578,   344,   106,   186,    94,   122,  1614,   124,   458,
     106,   164,  1337,   186,   463,   106,  1280,   133,   155,  1283,
    1182,  1305,   146,  1054,  1055,  1056,   157,  1054,  1055,  1056,
    1314,   121,   912,   913,   186,   186,   152,   917,     9,    10,
     267,  1325,   186,   533,   175,   186,   186,   274,   814,  1656,
     540,   533,   141,   181,   106,   106,   593,   284,   540,   186,
     597,  1337,   167,     9,    10,   170,   194,   947,   183,   183,
     412,   413,   659,   660,   416,   540,   186,   106,   420,   656,
     185,   423,   424,   186,   661,   584,   120,   155,   578,   431,
     186,   540,   183,   155,  1419,   437,   578,  1422,   440,   589,
     590,   591,   592,  1537,  1572,   210,   448,   589,   590,   591,
     592,   819,   454,   455,   456,   457,   116,   607,   106,  1726,
     462,  1728,   106,   157,   825,   607,   190,   191,   470,   578,
    1737,   102,    29,    42,   186,   186,     5,    46,   715,    33,
       9,   175,    51,  1419,   155,   145,  1422,    53,   181,    96,
     155,   122,    58,   124,   183,    49,   102,    39,   158,   155,
      69,   194,    44,    45,  1432,   112,    42,   117,   165,  1437,
      46,    77,   514,  1068,  1069,    51,   122,    59,   124,    61,
      62,   152,     9,    10,   181,   156,   528,    94,    70,   143,
      96,  1384,   192,    69,   153,   183,   155,   539,  1316,   183,
    1484,    96,   173,   780,   781,   782,   152,   784,   155,   121,
     156,   117,   109,     9,    10,    97,     5,   112,   121,    66,
       9,   175,   193,    33,    71,   715,   123,   173,   953,   136,
     955,   573,    24,   715,   141,   155,   266,    99,   192,    49,
     211,    53,    34,   273,    99,   155,    58,   193,   738,   152,
     112,   148,   155,   122,  1285,   124,   738,   112,   167,   738,
     155,   170,   152,   132,   267,   211,  1070,  1592,    60,  1594,
     117,   274,   136,   738,  1040,   102,   185,   136,   768,   769,
    1005,   284,  1007,   152,    96,    99,   768,   769,   152,   738,
    1046,   167,  1560,   152,   170,   122,  1564,   124,   112,    96,
    1625,   210,   152,   768,   769,   155,   102,  1636,  1637,   185,
     261,   902,   121,   245,   246,   112,  1592,    99,  1594,   768,
     769,   272,  1202,   914,   814,   152,   122,  1652,   124,   156,
     112,   830,   814,   122,   210,   124,   268,   261,   121,    99,
      99,   223,  1667,   132,  1669,  1674,   173,   689,   272,  1625,
     692,  1680,   112,   112,   121,    95,   152,  1475,  1476,    94,
     156,  1468,   136,   152,   706,   105,   193,   141,   710,   711,
     105,   152,  1640,   136,   155,   115,  1652,   173,   141,   275,
     276,   277,  1044,    53,   211,   281,   126,  1049,    58,   117,
     732,  1667,   734,  1669,   343,   662,   121,   193,   665,   348,
     742,   668,   152,   745,   223,   155,   225,   749,  1609,   131,
    1305,   152,  1292,   121,   155,   211,   121,   139,   140,  1314,
     142,   219,   220,   221,   223,   230,   225,   232,   150,   230,
    1325,   232,   154,   121,   156,  1201,   127,   128,   121,   161,
     127,   128,   639,   640,   647,   648,   788,   870,   871,   645,
     646,  1505,  1506,   121,   152,   155,   178,   223,   117,   239,
     239,   155,  1580,  1581,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,   816,   240,   152,     0,   106,   201,
     202,   203,   204,   205,   206,   189,   166,    92,   197,   247,
    1067,    50,   198,   100,   144,   101,   838,   153,   155,   183,
      29,   183,   183,    47,   151,   117,   244,   302,   186,   282,
    1000,   282,   152,  1279,   117,     1,   117,   141,  1000,   106,
     186,  1401,   152,   152,   155,   183,   868,   869,   870,   871,
    1648,   141,   155,   155,   155,  1000,   155,   183,   155,   152,
     155,   155,   184,    35,    17,   212,    29,   186,   189,     3,
    1040,  1000,   229,   189,  1053,   117,   167,   243,  1040,    70,
     169,   169,    94,   905,  1054,  1055,  1056,   229,    94,    94,
     148,   106,  1054,  1055,  1056,   106,    29,   919,   159,   159,
     126,  1461,   131,   244,    94,    73,   297,   141,   131,  1484,
     117,   183,   183,   186,   106,    94,   186,    45,    96,    87,
      96,   186,   944,   186,   186,   152,   183,   186,   183,    94,
     235,   953,    33,   955,   169,   189,   117,   959,   131,   223,
     141,   141,    94,   111,    29,   225,    94,   117,   297,   284,
     972,   126,   146,   152,   252,   123,   117,   125,   117,    94,
     196,   183,   131,   159,   131,    96,   152,  1413,   117,   146,
      99,   189,    99,   183,    35,   183,    29,   141,   152,   117,
      79,   106,   155,  1005,   155,  1007,   106,   243,   256,   258,
     265,    29,   152,   155,    29,    29,  1166,   155,   155,   155,
     155,   283,   143,   186,  1166,   155,   284,  1166,   155,   155,
     146,   285,   225,   143,   126,   117,   106,   117,  1275,  1276,
    1277,  1166,   146,   146,   141,   304,    77,    99,   131,     7,
     105,  1201,   183,   231,   231,   189,   231,  1166,   105,  1201,
     146,  1063,  1212,   186,   186,   189,   186,   186,   235,   186,
    1212,   196,   280,  1212,   284,    78,    29,    29,   106,   185,
     248,  1231,  1084,   248,   186,   186,   255,  1212,   186,  1231,
     186,   186,  1231,   186,   169,   186,   186,   146,   183,   125,
    1250,   146,   125,  1212,    96,   269,  1231,   183,  1250,  1535,
     152,   185,   185,   185,   185,   183,   183,   183,   278,   231,
    1546,  1547,  1231,  1549,    94,  1250,   186,    29,  1278,  1279,
    1556,    96,   186,   169,   146,    53,  1278,  1279,    94,   185,
     196,  1250,   185,    94,   195,    29,   106,   106,   117,   117,
      94,   185,    94,   117,   223,   195,   195,    93,   185,   223,
     185,   182,   117,   195,   223,   185,   185,   117,   185,  1278,
    1172,   117,   695,  1175,   263,   197,  1123,   906,   407,   973,
    1163,   427,  1614,  1656,   817,   247,   285,   970,  1190,   751,
    1172,  1394,   250,   341,  1191,  1059,   344,  1199,  1213,  1218,
     250,  1296,  1226,  1301,   291,   253,   617,  1633,  1299,   303,
    1221,  1213,   618,   637,   528,   303,   670,  1643,  1244,   303,
    1680,  1223,   285,  1674,   789,   871,   304,   304,  1157,   955,
     435,  1122,  1271,  1280,   435,  1281,  1314,  1325,  1484,  1069,
    1481,   938,  1668,   304,  1078,  1315,  1318,  1145,  1360,  1251,
    1508,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1413,    -1,   413,    -1,    -1,   416,  1271,
      -1,  1413,   420,  1699,    -1,   423,   424,    -1,  1280,    -1,
      -1,  1283,    -1,   431,    -1,   329,    -1,    -1,    -1,   437,
      -1,    -1,   440,    -1,  1720,    -1,    -1,    -1,    -1,  1725,
     448,    -1,    -1,    -1,    -1,    -1,   454,   455,   456,   457,
      -1,    -1,    -1,    -1,   462,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1337,    -1,  1574,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1590,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1365,    -1,    -1,   514,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     528,    -1,    -1,    -1,    -1,  1535,    -1,    -1,    -1,  1391,
    1392,   539,    -1,  1535,    -1,    -1,  1546,  1547,    -1,  1549,
      -1,    -1,    -1,    -1,  1546,  1547,  1556,  1549,    -1,    -1,
      -1,    -1,    -1,    -1,  1556,  1417,    -1,  1419,    -1,    -1,
    1422,    -1,    -1,    -1,    -1,   573,    -1,    -1,    -1,    -1,
      -1,  1433,    -1,    -1,    -1,    -1,  1438,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1633,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1633,    -1,  1643,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1643,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1668,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1668,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   692,    -1,    -1,    -1,  1550,  1699,
    1552,    -1,  1554,    -1,    -1,    -1,    -1,  1699,   706,  1561,
      -1,    -1,   710,   711,    -1,    -1,    -1,    -1,    -1,    -1,
    1720,    -1,    -1,    -1,    -1,  1725,    -1,    -1,  1720,    -1,
      -1,    -1,    -1,  1725,   732,    -1,   734,    -1,    -1,    -1,
    1592,    -1,  1594,    -1,   742,    -1,    -1,   745,    -1,    -1,
      -1,   749,    -1,    -1,    -1,    -1,    -1,    -1,  1610,    -1,
      -1,  1613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1625,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1635,    -1,    -1,    -1,    -1,    -1,    -1,
     788,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1652,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1660,    -1,
      -1,    -1,    -1,  1665,    -1,  1667,    -1,  1669,   816,    -1,
      -1,    -1,    -1,    -1,    -1,   565,   566,    -1,   568,   569,
     570,   571,    -1,    -1,    -1,    -1,   576,    -1,    -1,    -1,
     838,    -1,    -1,    -1,  1696,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   599,
    1712,    -1,    -1,    -1,  1716,    -1,    -1,   607,   608,    -1,
     868,   869,   870,   871,    -1,    -1,    -1,    -1,    -1,    -1,
    1732,    -1,    -1,  1735,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   905,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   919,    -1,    -1,    -1,    -1,    -1,   667,    -1,    -1,
     670,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   944,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   953,    -1,   955,    -1,    -1,
      -1,   959,    -1,    -1,    -1,    -1,    -1,    -1,   708,    -1,
      -1,    -1,    -1,    -1,   972,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1005,    -1,  1007,
     750,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   775,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   785,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1063,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1084,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     840,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   907,    -1,    -1,
      -1,    -1,    -1,    -1,  1172,    -1,    -1,  1175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1199,   942,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1213,    -1,    -1,    -1,    -1,
      -1,   961,    -1,    -1,    -1,  1223,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   983,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1251,   994,   995,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1009,
      -1,    -1,  1012,  1271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1280,    -1,    -1,  1283,  1026,  1027,  1028,    -1,
    1030,  1031,  1032,  1033,  1034,  1035,    -1,  1037,  1038,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1059,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1337,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1365,    -1,    -1,
    1110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1391,  1392,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1417,
      -1,  1419,    -1,    -1,  1422,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1433,    -1,  1177,    -1,  1179,
    1438,  1181,    -1,    -1,  1184,    -1,    -1,    -1,    -1,  1189,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1210,    -1,    -1,    -1,    -1,    -1,  1216,  1217,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1550,    -1,  1552,    -1,  1554,    -1,    -1,  1299,
      -1,    -1,    -1,  1561,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1592,    -1,  1594,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1610,    -1,    -1,  1613,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1625,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1635,  1378,    -1,
      -1,    -1,  1382,    -1,    -1,    -1,  1386,    -1,  1388,    -1,
    1390,    -1,    -1,    -1,  1652,    -1,  1396,    -1,    -1,    -1,
      -1,    -1,  1660,    -1,  1404,    -1,    -1,  1665,    -1,  1667,
      -1,  1669,  1412,  1413,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1696,    -1,
      -1,  1441,  1442,  1443,  1444,  1445,    -1,  1447,    -1,    -1,
      -1,    -1,    -1,    -1,  1712,    -1,    -1,    -1,  1716,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1732,    -1,    -1,  1735,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1523,    -1,  1525,    -1,    -1,  1528,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1536,    -1,    -1,    -1,
      -1,  1541,  1542,    -1,    -1,    -1,    -1,    -1,    -1,  1549,
      -1,    -1,    -1,  1553,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1617,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1629,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1668,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1694,    -1,    -1,    -1,    -1,  1699,
      -1,    -1,    11,    12,  1704,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,  1719,
      29,    -1,    -1,  1723,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,
      -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,   155,   156,   157,   158,
     159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,
     179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,
      -1,   190,   191,   192,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,    -1,
     209,   210,   211,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,    -1,   104,   105,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,
     127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,
     137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,   155,   156,
     157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,    -1,   173,    -1,   175,   176,
      -1,    -1,   179,   180,   181,    -1,   183,    -1,   185,    -1,
     187,   188,    -1,   190,   191,   192,    -1,   194,    -1,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
      -1,    -1,   209,   210,   211,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,   175,
     176,    -1,    -1,   179,   180,   181,    -1,   183,    -1,   185,
      -1,   187,   188,    -1,   190,   191,   192,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,   211,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,
     125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
     155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,    -1,   173,    -1,
     175,   176,    -1,    -1,   179,   180,   181,    -1,   183,    -1,
     185,    -1,   187,   188,    -1,   190,   191,   192,    -1,   194,
      -1,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,    -1,   209,   210,   211,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,   155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
      -1,   175,   176,    -1,    -1,   179,   180,   181,    -1,   183,
      -1,   185,    -1,   187,   188,    -1,   190,   191,   192,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,   209,   210,   211,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
     123,    -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,
      -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,   155,   156,   157,   158,   159,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,    -1,
     173,    -1,   175,   176,    -1,    -1,   179,   180,   181,    -1,
      -1,    -1,   185,    -1,   187,   188,    -1,   190,   191,   192,
      -1,   194,    -1,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,   209,   210,   211,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,   190,   191,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,   130,
      -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,   155,   156,   157,   158,   159,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,
     181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,   190,
     191,   192,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,   209,   210,
     211,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,   157,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,
     190,   191,   192,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,
      -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,   155,   156,   157,   158,
     159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,
     179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,
      -1,   190,   191,   192,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,    -1,
     209,   210,   211,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,   157,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,   175,   176,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,
     188,    -1,   190,   191,   192,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,   211,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,    -1,   104,   105,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,
     127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,
     137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,   155,   156,
     157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,    -1,   173,    -1,   175,   176,
      -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,   186,
     187,   188,    -1,   190,   191,   192,    -1,   194,    -1,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
      -1,    -1,   209,   210,   211,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,   175,
     176,    -1,    -1,   179,   180,   181,    -1,   183,    -1,   185,
      -1,   187,   188,    -1,   190,   191,   192,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,   211,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,
     125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
     155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,    -1,   173,    -1,
     175,   176,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,
     185,   186,   187,   188,    -1,   190,   191,   192,    -1,   194,
      -1,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,    -1,   209,   210,   211,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,   155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
      -1,   175,   176,    -1,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,   186,   187,   188,    -1,   190,   191,   192,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,   209,   210,   211,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
     123,    -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,
      -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    -1,   155,   156,   157,   158,   159,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,    -1,
     173,    -1,   175,   176,    -1,    -1,   179,   180,   181,    -1,
      -1,    -1,   185,    -1,   187,   188,    -1,   190,   191,   192,
      -1,   194,    -1,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,   209,   210,   211,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,   190,   191,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,   130,
      -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,   155,   156,   157,   158,   159,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,
     181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,   190,
     191,   192,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,   209,   210,
     211,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,    -1,    -1,    -1,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,
     190,   191,   192,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,
      -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,   155,   156,    -1,   158,
     159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,    -1,   173,    -1,    -1,    -1,    -1,    -1,
     179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,
      -1,    -1,    -1,   192,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,    -1,
     209,   210,   211,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      -1,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
      -1,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,    -1,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    -1,    99,   100,   101,    -1,    -1,   104,   105,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,
     137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,
     187,   188,    -1,    -1,    -1,   192,    -1,   194,    -1,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
      -1,    -1,   209,   210,    -1,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    -1,    99,   100,
     101,    -1,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,   130,
      -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,    -1,   149,   150,
     151,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,
     181,    -1,    -1,    -1,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,   209,   210,
      -1,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    -1,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   147,    -1,   149,   150,   151,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,
     185,    -1,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,    -1,   209,   210,    -1,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    18,    19,    -1,
      -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    -1,    99,   100,
     101,    -1,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,   130,
      -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,    -1,   149,   150,
     151,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,
     181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,   209,   210,
      -1,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    -1,    99,   100,   101,    -1,
      -1,   104,   105,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,
      -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   147,    -1,   149,   150,   151,    -1,
      -1,    -1,   155,    -1,    -1,   158,   159,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,
      -1,    -1,   185,   186,   187,   188,    -1,    -1,    -1,   192,
      -1,   194,    -1,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,   209,   210,    -1,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    -1,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   147,    -1,   149,   150,   151,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,
     185,   186,   187,   188,    -1,    -1,    -1,   192,    -1,   194,
      -1,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,    -1,   209,   210,    -1,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    -1,    99,   100,   101,    -1,    -1,   104,   105,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,
     137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,   186,
     187,   188,    -1,    -1,    -1,   192,    -1,   194,    -1,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
      -1,    -1,   209,   210,    -1,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    -1,
      99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,
      -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,
     149,   150,   151,    -1,    -1,    -1,   155,    -1,    -1,   158,
     159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,    -1,
     209,   210,    -1,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    -1,    99,   100,
     101,    -1,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,   130,
      -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,    -1,   149,   150,
     151,    -1,    -1,    -1,   155,    -1,    -1,   158,   159,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,
     181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,   209,   210,
      -1,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    -1,    99,   100,   101,    -1,
      -1,   104,   105,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,
      -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   147,    -1,   149,   150,   151,    -1,
      -1,    -1,   155,    -1,    -1,   158,   159,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,
      -1,    -1,   185,    -1,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,   209,   210,    -1,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    -1,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   147,    -1,   149,   150,   151,    -1,    -1,    -1,
     155,    -1,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,
     185,    -1,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,    -1,   209,   210,    -1,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    -1,    99,   100,   101,    -1,    -1,   104,   105,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,
     137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,   149,   150,   151,    -1,    -1,    -1,   155,    -1,
      -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
      -1,    -1,   209,   210,    -1,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    -1,
      99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,
      -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,
     149,   150,   151,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,    -1,
     209,   210,    -1,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    -1,    40,
      41,    42,    43,    -1,    -1,    46,    47,    -1,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    -1,    60,
      -1,    -1,    63,    64,    65,    66,    67,    -1,    69,    -1,
      71,    -1,    -1,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    -1,    -1,    99,   100,
     101,    -1,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,   130,
      -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,    -1,   149,   150,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,
     181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,    -1,   210,
      -1,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
      -1,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311
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
      95,    96,    97,    98,    99,   100,   101,   104,   105,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     123,   125,   126,   127,   128,   130,   134,   135,   136,   137,
     138,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     155,   156,   157,   158,   159,   164,   165,   166,   167,   168,
     169,   170,   171,   173,   175,   176,   179,   180,   181,   185,
     187,   188,   190,   191,   192,   194,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   209,   210,   211,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   257,   258,   259,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   328,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   349,   350,   351,   352,
     353,   354,   358,   359,   360,   364,   366,   367,   369,   376,
     378,   381,   382,   383,   385,   386,   387,   388,   389,   391,
     392,   394,   395,   396,   397,   398,   399,   401,   402,   405,
     406,   407,   408,   413,   415,   417,   418,   423,   442,   445,
     449,   452,   453,   458,   459,   460,   461,   463,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   510,   511,
     512,   526,   527,   529,   530,   531,   532,   533,   534,   535,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     555,   556,   557,   558,   563,   564,   565,   566,   567,   568,
     571,   629,   630,   631,   640,   641,   642,    33,    34,    49,
     213,   384,   385,   386,   384,   384,   155,   155,    37,    38,
      40,    41,    47,    56,    57,    74,    79,   110,   111,   112,
     159,   218,   259,   285,   293,   301,   365,   366,   370,   371,
     372,   159,   152,   155,   152,   155,   152,   155,    66,    71,
     117,   410,   155,   373,   155,    24,    34,    60,   117,   271,
     422,   424,   425,   152,   155,   155,   155,   117,   152,   155,
     155,   155,    76,   152,   219,   220,   121,   121,   121,   152,
     155,    39,    43,    45,    46,    47,    48,    51,    59,    67,
      70,    72,    73,    75,    90,    91,    97,   104,   111,   113,
     114,   134,   137,   138,   168,   171,   179,   180,   188,   200,
     222,   224,   226,   227,   234,   236,   237,   238,   241,   242,
     494,   640,   641,   121,   117,   393,   121,   121,    39,    44,
      45,    59,    61,    62,    70,    97,   223,   640,   117,   121,
     121,   183,   384,   386,   405,   632,    48,    72,    73,   117,
     152,   242,   405,   407,   417,   632,   186,   405,   640,   152,
     121,    16,   639,   640,    18,    19,   640,   121,   121,   121,
     486,   152,    30,   212,   214,   223,   225,   155,   223,   225,
     223,   223,   228,   117,   239,   239,   240,   155,   152,   388,
     330,     0,   332,   333,    33,    49,   335,   352,     1,   189,
     329,   189,   329,   111,   367,   387,   405,   106,   189,   106,
     189,    42,    46,    51,    69,   167,   170,   185,   210,   400,
     409,   414,   415,   416,   430,   431,   435,   166,    92,   131,
     139,   140,   142,   150,   154,   156,   161,   178,   201,   202,
     203,   204,   205,   206,   478,   479,   247,   197,   120,   157,
     175,   116,   145,   158,   192,   199,   208,   135,   149,    50,
     198,   100,   101,   157,   175,   477,   152,   483,   486,   190,
     191,   153,   498,   499,   494,   498,   494,   155,   498,   144,
     155,   183,   183,   183,   368,   501,   368,    29,   638,   181,
     194,   181,   194,   165,   181,   641,   640,   168,   200,    47,
     640,   151,   117,    45,    47,    79,   105,   167,   639,   219,
     220,   221,   244,   602,   640,   640,   302,   136,   141,   111,
     285,   293,   370,   639,   385,   386,   186,   385,    45,    62,
     186,   551,   552,   405,   186,   192,   640,   282,   282,   419,
     420,   640,   117,   426,   117,   186,   374,   375,   152,   390,
     405,     1,   159,   638,   112,   159,   348,   638,   640,   117,
     141,   106,   405,    29,   186,   639,   640,   640,   443,   444,
     640,   385,   186,   405,   405,   553,   640,   385,   152,   152,
     405,   186,   192,   640,   640,   141,   443,   183,   183,   183,
     155,   155,   155,   640,   152,   185,   184,   186,    35,   514,
     515,   516,   405,     8,   174,    17,   405,   212,    29,   406,
     406,   186,   406,   406,   406,   406,   229,   569,   570,   640,
     189,   189,   406,   405,   386,   405,   243,   403,   404,   189,
     329,   189,   329,     3,   336,   352,   382,   336,   352,   382,
      33,   353,   382,   353,   382,   393,   393,   406,   117,   167,
     169,   169,   387,   406,   406,   460,   461,   463,   463,   463,
     463,   462,   463,   463,   463,    70,   466,   467,   468,   468,
     469,   469,   469,   469,   470,   470,   471,   471,   229,    94,
      94,    94,   183,   405,   486,   486,   405,   499,   186,   406,
     509,   148,   186,   509,   106,   186,   186,   106,   106,   373,
      29,   641,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,   355,   356,   357,    94,   136,   141,   361,   362,
     363,   640,   159,   159,   355,   638,   126,   131,    54,    56,
      99,   249,   262,   264,   275,   276,   277,   279,   281,   603,
     604,   605,   606,   607,   608,   615,   621,   622,   244,    94,
     297,   640,   141,   406,   117,   640,   640,   131,   183,   183,
     186,   186,   183,   106,   186,   106,   186,   106,    36,    94,
      96,   146,   421,   422,   537,   640,    55,   215,   252,   411,
     412,   640,    94,   106,   186,   384,   186,   639,    96,    45,
     639,   638,    96,   141,   537,   640,   406,   425,   183,   186,
     186,   186,   186,   106,   187,   146,   537,   183,   186,   186,
     152,   183,   385,   385,   183,   106,   186,   106,   186,   141,
     537,   406,   187,   405,   405,   405,   640,   515,   516,   129,
     195,   183,   183,   130,   189,    94,   216,   217,   231,    94,
     216,   217,   231,    94,   235,   223,   106,   233,   141,   189,
     186,    48,    72,    73,   242,   407,   417,   183,   495,   575,
     404,   352,    33,    33,   189,   329,   189,   112,   640,   169,
     406,   436,   437,   117,   432,   433,   463,   152,   155,   257,
     482,   501,   576,   579,   580,   581,   582,   583,   587,   589,
     591,   592,    47,   151,   155,   209,   308,   309,   310,   311,
     538,   540,   542,   543,   559,   560,   561,   562,   633,   634,
     635,   636,   637,   640,   538,   536,   542,   536,   183,   184,
     106,   186,   186,   501,   147,   164,   147,   164,   136,   390,
     373,   356,   131,   540,   363,   406,   537,   638,   638,   127,
     128,   638,   275,   276,   277,   281,   640,   261,   272,   261,
     272,    29,   284,    96,   112,   155,   609,   612,   603,    39,
      44,    59,    61,    70,    97,   223,   377,   543,   225,   297,
     306,   406,   640,    94,   297,   638,   152,   553,   554,   640,
     553,   554,   117,   126,   538,   117,   406,   146,   422,   146,
      36,   146,   421,   422,   146,   537,   252,    53,    58,    77,
     117,   421,   427,   428,   429,   412,   537,   538,   375,    94,
     183,   196,   131,   347,   638,   159,   131,    96,   347,   406,
     141,   422,   152,   117,   406,   406,   146,    99,   446,   447,
     448,   450,   451,    99,   454,   455,   456,   457,   385,   183,
     183,   152,   553,   553,   406,   141,   189,   406,   186,   186,
     186,    35,   516,   129,   195,     9,    10,   102,   122,   124,
     152,   193,   511,   513,   524,   525,   528,    29,   230,   232,
     406,   406,   406,   230,   232,   406,   406,   406,   406,   406,
     406,   117,   406,   406,   387,   155,   155,   155,   152,   185,
     243,   572,   573,   208,   388,   189,   112,   382,   382,   382,
     436,    95,   105,   115,   126,   438,   439,   440,   441,   106,
     640,   106,   405,   576,   583,   152,   283,   464,   628,    96,
     168,   250,   251,   253,   260,   270,   282,   577,   578,   597,
     598,   599,   600,   623,   626,   256,   258,   584,   602,   265,
     588,   624,   245,   246,   268,   593,   594,   155,   155,   540,
     155,   155,   155,   155,   155,   143,   175,   192,   539,   143,
     406,   136,   390,   555,   362,   284,    29,    96,   112,   155,
     616,    29,   609,   539,   484,   285,   304,   537,   377,   225,
     189,   384,   186,   186,   143,   186,   186,   420,   146,   421,
     640,   406,   146,   406,   126,   406,   146,   422,   146,   406,
     146,   117,   117,   406,   640,   429,    77,   538,   387,   406,
     638,   106,   347,   406,   141,   384,   444,   406,   406,   112,
     447,   448,    99,   185,   112,   448,   451,   117,   538,    99,
     112,   455,    99,   112,   457,   183,   384,   186,   186,   406,
     196,   454,   131,   193,   513,     7,   385,   640,   193,   524,
     189,   231,   231,   231,   231,   235,   570,   185,   405,   405,
     405,   575,   573,   495,   638,   127,   128,   440,   441,   441,
     437,   105,   434,   433,   183,   186,   576,   590,   248,   215,
     252,   266,   273,   627,    96,   254,   255,   625,   248,   580,
     627,   467,   597,   581,   146,   280,   585,   586,   625,   284,
     596,    78,   595,   186,   192,   538,   541,   186,   186,   186,
     186,   186,   186,   186,    29,   135,   199,   618,   619,   620,
      29,   617,   618,   269,   613,   106,   610,   169,   640,   255,
     484,   183,   406,   146,   406,   146,   421,   406,   146,   406,
     406,   640,   640,   428,   406,   125,   125,    96,   638,   406,
     183,   185,   185,   406,   387,   406,   185,   185,   640,   185,
     117,   538,   117,   185,   117,   538,   185,   183,   112,   516,
     640,   193,   183,   516,   640,   406,   406,   406,   406,   406,
     406,   186,   186,   186,   152,   574,   441,   638,   183,   469,
      52,   128,   467,   467,   267,   274,   284,   601,   601,   582,
     152,   278,    94,   186,   106,   186,   616,   616,   620,   106,
     186,    29,   614,   625,   611,   612,   186,   379,   380,   484,
     117,   223,   305,   285,   169,   406,   406,   146,   406,    53,
     387,   406,   347,   406,   387,    94,   387,   406,   640,   185,
     640,   406,   640,   185,   387,   117,    93,   182,   517,   516,
     640,   195,   516,   196,   454,   405,   467,   467,   197,   405,
     538,   538,    94,    29,   263,   106,   106,   441,   537,   640,
     117,   223,   640,   379,   406,   117,   538,    94,   185,    94,
     640,     5,   132,   520,   521,   523,   525,    28,   133,   518,
     519,   522,   525,   195,   516,   195,   112,   183,   467,   183,
     538,   612,   380,   441,   303,   640,   117,   223,   640,   185,
     538,   387,   406,   538,   185,    93,   132,   523,   182,   133,
     522,   195,   117,   406,   303,   640,   117,   387,   406,   185,
     185,   640,   291,   303,   640,   185,   304,   406,   304,   484,
     484,   197,   285,   640,   223,   117,   640,   304,   484
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
     575,   576,   577,   578,   579,   580,   581
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   327,   328,   328,   329,   330,   330,   330,   330,   331,
     331,   332,   332,   332,   332,   332,   332,   332,   332,   333,
     333,   333,   333,   334,   335,   335,   335,   336,   336,   336,
     336,   336,   337,   337,   337,   337,   337,   337,   337,   337,
     338,   338,   339,   340,   341,   341,   342,   342,   343,   343,
     344,   344,   344,   344,   345,   345,   345,   346,   346,   346,
     346,   347,   347,   348,   348,   349,   349,   349,   349,   350,
     351,   351,   352,   352,   352,   353,   353,   353,   353,   353,
     353,   353,   353,   354,   354,   355,   355,   356,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   358,   359,
     360,   361,   361,   362,   362,   362,   363,   364,   364,   364,
     365,   365,   365,   365,   366,   366,   367,   367,   367,   367,
     368,   368,   369,   369,   370,   370,   371,   371,   372,   372,
     373,   373,   373,   373,   374,   374,   375,   375,   376,   376,
     376,   376,   377,   377,   378,   378,   379,   379,   380,   380,
     380,   380,   381,   381,   381,   381,   382,   383,   383,   383,
     384,   384,   384,   385,   385,   386,   386,   387,   387,   387,
     387,   387,   387,   387,   387,   387,   387,   387,   387,   388,
     388,   389,   390,   391,   392,   392,   392,   393,   393,   393,
     393,   394,   395,   396,   397,   398,   398,   399,   400,   401,
     402,   403,   403,   404,   405,   405,   406,   406,   406,   406,
     406,   406,   407,   407,   407,   407,   407,   407,   407,   408,
     409,   410,   410,   411,   411,   411,   412,   412,   413,   413,
     414,   415,   415,   415,   416,   416,   416,   416,   416,   417,
     417,   418,   419,   419,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   421,   422,   423,   424,
     424,   425,   425,   425,   425,   426,   426,   427,   427,   427,
     428,   428,   428,   429,   429,   429,   430,   431,   432,   432,
     433,   433,   434,   435,   435,   436,   436,   437,   437,   438,
     438,   438,   438,   438,   438,   438,   439,   439,   440,   440,
     441,   442,   442,   443,   443,   444,   444,   445,   446,   446,
     447,   448,   448,   449,   450,   450,   451,   452,   452,   453,
     453,   454,   454,   455,   455,   456,   456,   457,   457,   458,
     459,   459,   460,   460,   461,   461,   461,   461,   461,   462,
     461,   461,   461,   461,   463,   463,   464,   464,   465,   465,
     466,   466,   467,   467,   467,   468,   468,   468,   468,   468,
     469,   469,   469,   470,   470,   470,   471,   471,   472,   472,
     473,   473,   474,   474,   475,   475,   476,   476,   476,   476,
     477,   477,   477,   478,   478,   478,   478,   478,   478,   479,
     479,   479,   480,   480,   480,   480,   481,   481,   482,   482,
     483,   483,   483,   484,   484,   484,   484,   485,   486,   486,
     486,   487,   487,   488,   488,   488,   488,   489,   489,   490,
     490,   490,   490,   490,   490,   490,   491,   491,   492,   492,
     493,   493,   493,   493,   493,   494,   494,   495,   495,   496,
     496,   496,   496,   497,   497,   497,   497,   498,   498,   499,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   501,   501,   502,   502,   502,   503,   504,   504,   505,
     506,   507,   508,   508,   509,   509,   510,   510,   511,   511,
     511,   512,   512,   512,   512,   512,   512,   513,   513,   514,
     514,   515,   516,   516,   517,   517,   518,   518,   519,   519,
     519,   519,   520,   520,   521,   521,   521,   521,   522,   522,
     523,   523,   524,   524,   524,   524,   525,   525,   525,   525,
     526,   526,   527,   527,   528,   529,   529,   529,   529,   529,
     529,   530,   531,   531,   532,   532,   533,   534,   535,   535,
     536,   536,   537,   538,   538,   538,   539,   539,   539,   540,
     540,   540,   540,   540,   540,   541,   541,   542,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   544,   545,   545,
     545,   546,   547,   548,   548,   548,   549,   549,   549,   549,
     549,   550,   551,   551,   551,   551,   551,   551,   551,   552,
     553,   554,   555,   556,   556,   557,   558,   559,   559,   560,
     561,   561,   562,   563,   563,   563,   564,   564,   564,   564,
     564,   564,   564,   564,   564,   564,   565,   565,   566,   566,
     567,   568,   569,   569,   570,   571,   572,   572,   573,   574,
     575,   575,   576,   577,   577,   578,   578,   579,   579,   580,
     580,   581,   581,   582,   582,   583,   584,   584,   585,   585,
     586,   587,   587,   587,   588,   588,   589,   590,   590,   591,
     592,   592,   593,   593,   594,   594,   594,   595,   595,   596,
     596,   597,   597,   597,   597,   597,   598,   599,   600,   601,
     601,   601,   602,   602,   603,   603,   603,   603,   603,   603,
     603,   603,   604,   604,   604,   604,   605,   605,   606,   607,
     607,   608,   608,   608,   609,   609,   610,   610,   611,   611,
     612,   613,   613,   614,   614,   615,   615,   615,   616,   616,
     617,   617,   618,   618,   619,   619,   620,   620,   621,   622,
     622,   623,   623,   623,   624,   625,   625,   625,   625,   626,
     626,   627,   627,   628,   629,   629,   630,   631,   632,   632,
     633,   633,   633,   633,   634,   635,   636,   637,   638,   639,
     639,   640,   640,   640,   640,   640,   640,   640,   640,   640,
     640,   640,   640,   640,   640,   640,   640,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     642
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     2,     4,     3,     5,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     4,     3,     5,     4,     6,     4,     6,
       5,     7,     4,     5,     5,     6,     3,     3,     2,     1,
       3,     4,     5,     3,     6,     4,     5,     1,     2,     3,
       1,     2,     1,     6,     3,     3,     2,     3,     1,     3,
       2,     3,     2,     3,     4,     1,     3,     1,     2,     1,
       1,     1,     2,     2,     2,     3,     1,     1,     2,     2,
       2,     5,     5,     1,     4,     3,     4,     8,     1,     2,
       3,     2,     3,     8,     1,     2,     3,     8,    10,     8,
      10,     1,     2,     4,     7,     1,     2,     4,     7,     8,
       1,     3,     1,     3,     1,     3,     3,     3,     3,     0,
       4,     3,     3,     3,     1,     5,     0,     1,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     4,     1,     4,
       1,     4,     1,     4,     1,     2,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     5,     6,     3,     4,     1,     2,
       3,     2,     2,     1,     2,     2,     1,     1,     1,     3,
       3,     1,     1,     1,     2,     1,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     1,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     4,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     1,
       4,     4,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     4,     5,     8,     9,     9,    10,     1,     2,     1,
       2,     6,     0,     1,     3,     3,     0,     1,     1,     1,
       2,     2,     0,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     2,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     4,     3,     7,     3,     7,     4,     4,     3,     7,
       1,     2,     2,     1,     2,     3,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     4,
       4,     3,     3,     3,     4,     4,     3,     4,     6,     4,
       6,     4,     3,     4,     6,     6,     4,     6,     6,     4,
       1,     2,     1,     1,     1,     3,     3,     1,     1,     4,
       5,     6,     3,     3,     3,     3,     5,     7,     7,     5,
       5,     5,     7,     7,     5,     5,     3,     3,     5,     7,
       5,     7,     1,     4,     3,     5,     1,     2,     3,     3,
       1,     3,     2,     0,     1,     1,     2,     1,     3,     1,
       3,     1,     4,     1,     2,     3,     0,     1,     0,     1,
       4,     2,     3,     1,     0,     1,     4,     0,     1,     2,
       1,     3,     0,     1,     2,     2,     1,     0,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     2,     2,     3,     1,
       2,     2,     5,     2,     1,     1,     0,     2,     1,     3,
       4,     0,     2,     0,     2,     4,     4,     3,     2,     3,
       1,     3,     0,     1,     1,     2,     2,     2,     2,     1,
       2,     2,     2,     2,     3,     2,     3,     3,     4,     2,
       2,     1,     1,     3,     1,     1,     3,     3,     0,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     1,     1,
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
  "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'@'\"",
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
  "\"'keys'\"", "\"'array'\"", "\"'json-item'\"", "\"'object'\"",
  "\"'pair'\"", "\"'BOM_UTF8'\"", "RANGE_REDUCE", "JSON_REDUCE",
  "ADDITIVE_REDUCE", "MULTIPLICATIVE_REDUCE", "UNION_REDUCE",
  "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR",
  "UNARY_PREC", "SEQUENCE_TYPE_REDUCE", "OCCURS_STAR", "OCCURS_PLUS",
  "OCCURS_HOOK", "STEP_REDUCE", "$accept", "Module", "ERROR",
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
  "opt_FTIgnoreOption", "RangeExpr", "JSONPairConstructor", "AdditiveExpr",
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
  "FTIgnoreOption", "JSONConstructor", "JSONArrayConstructor",
  "JSONObjectConstructor", "opt_Expr", "JSONTest", "JSONItemTest",
  "JSONObjectTest", "JSONArrayTest", "JSONPairTest", "URI_LITERAL",
  "NCNAME", "QNAME", "FUNCTION_NAME", "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       328,     0,    -1,   330,    -1,   312,   330,    -1,     1,     3,
      -1,   332,    -1,   331,   332,    -1,   333,    -1,   331,   333,
      -1,   213,   214,    29,   189,    -1,   213,   214,    29,   130,
      29,   189,    -1,   335,   189,   382,    -1,   352,   189,   382,
      -1,   335,   189,   352,   189,   382,    -1,   382,    -1,   335,
     329,   382,    -1,   352,   329,   382,    -1,   335,   189,   352,
     329,   382,    -1,   335,   329,   352,   189,   382,    -1,   334,
      -1,   334,   335,   189,    -1,   334,   352,   189,    -1,   334,
     335,   189,   352,   189,    -1,    34,   159,   639,   131,   638,
     189,    -1,   336,    -1,   335,   189,   336,    -1,   335,   329,
     336,    -1,   337,    -1,   345,    -1,   350,    -1,   351,    -1,
     359,    -1,   338,    -1,   339,    -1,   340,    -1,   341,    -1,
     342,    -1,   343,    -1,   344,    -1,   563,    -1,    33,    38,
     181,    -1,    33,    38,   194,    -1,    33,   112,   105,   638,
      -1,    33,    37,   638,    -1,    33,    40,   181,    -1,    33,
      40,   194,    -1,    33,    57,   168,    -1,    33,    57,   200,
      -1,    33,   112,   167,   126,   127,    -1,    33,   112,   167,
     126,   128,    -1,    33,    41,   181,   106,   147,    -1,    33,
      41,   181,   106,   164,    -1,    33,    41,   165,   106,   147,
      -1,    33,    41,   165,   106,   164,    -1,   346,    -1,   349,
      -1,    49,    24,     1,    -1,    49,    60,   638,    -1,    49,
      60,   348,   638,    -1,    49,    60,   638,    96,   347,    -1,
      49,    60,   348,   638,    96,   347,    -1,   638,    -1,   347,
     106,   638,    -1,   159,   639,   131,    -1,   112,    45,   159,
      -1,    49,    34,   638,    -1,    49,    34,   159,   639,   131,
     638,    -1,    49,    34,   638,    96,   347,    -1,    49,    34,
     159,   639,   131,   638,    96,   347,    -1,    33,   159,   639,
     131,   638,    -1,    33,   112,    45,   159,   638,    -1,    33,
     112,    47,   159,   638,    -1,   353,    -1,   352,   189,   353,
      -1,   352,   329,   353,    -1,   354,    -1,   358,    -1,   360,
      -1,   364,    -1,   369,    -1,   376,    -1,   378,    -1,   381,
      -1,    33,   112,    79,   355,    -1,    33,    79,   640,   355,
      -1,   356,    -1,   355,   356,    -1,   357,   131,   555,    -1,
      80,    -1,    88,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    89,    -1,    85,    -1,    86,    -1,    87,    -1,
      33,    56,   640,    29,    -1,    33,   259,   602,    -1,    33,
     110,   151,   361,    -1,    94,   540,   362,    -1,   362,    -1,
     363,    -1,   136,    -1,   136,   363,    -1,   141,   406,    -1,
      33,   365,   141,   406,    -1,    33,   365,   136,    -1,    33,
     365,   136,   141,   406,    -1,   111,   117,   640,    -1,   111,
     117,   640,   537,    -1,   366,   111,   117,   640,    -1,   366,
     111,   117,   640,   537,    -1,   367,    -1,   366,   367,    -1,
      26,    -1,    26,   155,   368,   186,    -1,    27,    -1,    27,
     155,   368,   186,    -1,   501,    -1,   368,   106,   501,    -1,
      33,   370,    -1,    33,   366,   370,    -1,   371,    -1,   372,
      -1,    47,   641,   373,   390,    -1,    47,   641,   373,   136,
      -1,    74,    47,   641,   373,   390,    -1,    74,    47,   641,
     373,   136,    -1,   155,   186,    -1,   155,   374,   186,    -1,
     155,   186,    94,   538,    -1,   155,   374,   186,    94,   538,
      -1,   375,    -1,   374,   106,   375,    -1,   117,   640,    -1,
     117,   640,   537,    -1,    33,   285,   640,    -1,    33,   285,
     640,    94,   377,    -1,    33,   366,   285,   640,    -1,    33,
     366,   285,   640,    94,   377,    -1,   543,    -1,   543,   539,
      -1,    33,   293,   640,   297,   225,   484,   169,   379,    -1,
      33,   366,   293,   640,   297,   225,   484,   169,   379,    -1,
     380,    -1,   379,   106,   380,    -1,   484,    -1,   484,   537,
      -1,   484,   441,    -1,   484,   537,   441,    -1,    33,   301,
     302,   640,   297,   285,   640,   117,   640,   303,   406,    -1,
      33,   301,   302,   640,   297,   285,   640,   223,   117,   640,
     303,   291,   304,   484,    -1,    33,   301,   302,   640,   297,
     285,   640,   305,   223,   117,   640,   303,   406,    -1,    33,
     301,   302,   640,   306,   304,   255,   285,   640,   223,   117,
     640,   304,   484,   197,   285,   640,   223,   117,   640,   304,
     484,    -1,   383,    -1,   385,    -1,   386,    -1,    -1,   385,
      -1,   386,    -1,    -1,   405,    -1,   386,   405,    -1,   387,
      -1,   386,   387,    -1,   388,    -1,   391,    -1,   394,    -1,
     395,    -1,   396,    -1,   397,    -1,   398,    -1,   399,    -1,
     401,    -1,   453,    -1,   449,    -1,   402,    -1,   152,   386,
     183,    -1,   152,   183,    -1,   152,   384,   183,    -1,   152,
     384,   183,    -1,   392,   189,    -1,   392,   106,   393,    -1,
     111,   393,    -1,   366,   111,   393,    -1,   117,   640,    -1,
     117,   640,   537,    -1,   117,   640,   141,   406,    -1,   117,
     640,   537,   141,   406,    -1,   117,   640,   141,   406,   189,
      -1,   407,   189,    -1,   238,   240,   406,   189,    -1,   241,
     155,   405,   186,   387,    -1,   236,   239,   189,    -1,   237,
     239,   189,    -1,   417,   400,    -1,   185,   387,    -1,    48,
     155,   405,   186,   196,   387,   125,   387,    -1,   242,   388,
     403,    -1,   404,    -1,   403,   404,    -1,   243,   575,   388,
      -1,   406,    -1,   405,   106,   406,    -1,   408,    -1,   445,
      -1,   452,    -1,   458,    -1,   571,    -1,   407,    -1,   459,
      -1,   442,    -1,   564,    -1,   565,    -1,   567,    -1,   566,
      -1,   568,    -1,   417,   409,    -1,   185,   406,    -1,    66,
     282,    -1,    71,   282,    -1,   215,    -1,   252,    -1,    55,
     252,    -1,   411,   427,    77,   406,    -1,   411,    77,   406,
      -1,    46,   410,   426,   412,   412,    -1,    46,   410,   426,
     412,    -1,    42,   117,   640,    -1,   418,    -1,   423,    -1,
     413,    -1,   415,    -1,   430,    -1,   435,    -1,   431,    -1,
     414,    -1,   415,    -1,   417,   416,    -1,    46,   117,   419,
      -1,   420,    -1,   419,   106,   117,   420,    -1,   640,   146,
     406,    -1,   640,    36,   126,   146,   406,    -1,   640,   537,
     146,   406,    -1,   640,   537,    36,   126,   146,   406,    -1,
     640,   421,   146,   406,    -1,   640,    36,   126,   421,   146,
     406,    -1,   640,   537,   421,   146,   406,    -1,   640,   537,
      36,   126,   421,   146,   406,    -1,   640,   422,   146,   406,
      -1,   640,   537,   422,   146,   406,    -1,   640,   421,   422,
     146,   406,    -1,   640,   537,   421,   422,   146,   406,    -1,
      96,   117,   640,    -1,   271,   117,   640,    -1,    51,   424,
      -1,   425,    -1,   424,   106,   425,    -1,   117,   640,   141,
     406,    -1,   117,   640,   537,   141,   406,    -1,   422,   141,
     406,    -1,   117,   640,   537,   422,   141,   406,    -1,   117,
     640,   146,   406,    -1,   117,   640,   537,   146,   406,    -1,
     428,    -1,   117,   640,    -1,   117,   640,   428,    -1,   421,
      -1,   421,   429,    -1,   429,    -1,    58,   117,   640,    53,
     117,   640,    -1,    53,   117,   640,    -1,    58,   117,   640,
      -1,   210,   406,    -1,   170,   169,   432,    -1,   433,    -1,
     432,   106,   433,    -1,   117,   640,    -1,   117,   640,   434,
      -1,   105,   638,    -1,   167,   169,   436,    -1,    69,   167,
     169,   436,    -1,   437,    -1,   436,   106,   437,    -1,   406,
      -1,   406,   438,    -1,   439,    -1,   440,    -1,   441,    -1,
     439,   440,    -1,   439,   441,    -1,   440,   441,    -1,   439,
     440,   441,    -1,    95,    -1,   115,    -1,   126,   127,    -1,
     126,   128,    -1,   105,   638,    -1,    67,   117,   443,   187,
     406,    -1,   134,   117,   443,   187,   406,    -1,   444,    -1,
     443,   106,   117,   444,    -1,   640,   146,   406,    -1,   640,
     537,   146,   406,    -1,    72,   155,   405,   186,   446,   112,
     185,   406,    -1,   447,    -1,   446,   447,    -1,   448,   185,
     406,    -1,    99,   406,    -1,   448,    99,   406,    -1,    72,
     155,   405,   186,   450,   112,   185,   387,    -1,   451,    -1,
     450,   451,    -1,   448,   185,   387,    -1,    73,   155,   405,
     186,   454,   112,   185,   406,    -1,    73,   155,   405,   186,
     454,   112,   117,   640,   185,   406,    -1,    73,   155,   405,
     186,   456,   112,   185,   387,    -1,    73,   155,   405,   186,
     454,   112,   117,   640,   185,   387,    -1,   455,    -1,   454,
     455,    -1,    99,   538,   185,   406,    -1,    99,   117,   640,
      94,   538,   185,   406,    -1,   457,    -1,   456,   457,    -1,
      99,   538,   185,   387,    -1,    99,   117,   640,    94,   538,
     185,   387,    -1,    48,   155,   405,   186,   196,   406,   125,
     406,    -1,   460,    -1,   459,   166,   460,    -1,   461,    -1,
     460,    92,   461,    -1,   463,    -1,   463,   478,   463,    -1,
     463,   479,   463,    -1,   463,   131,   463,    -1,   463,   161,
     463,    -1,    -1,   463,   156,   462,   463,    -1,   463,   154,
     463,    -1,   463,   142,   463,    -1,   463,   140,   463,    -1,
     465,    -1,   465,   247,    70,   576,   464,    -1,    -1,   628,
      -1,   466,    -1,   466,   197,   466,    -1,   467,    -1,   467,
     120,   467,    -1,   468,    -1,   467,   175,   468,    -1,   467,
     157,   468,    -1,   469,    -1,   468,   192,   469,    -1,   468,
     116,   469,    -1,   468,   145,   469,    -1,   468,   158,   469,
      -1,   470,    -1,   469,   199,   470,    -1,   469,   208,   470,
      -1,   471,    -1,   470,   149,   471,    -1,   470,   135,   471,
      -1,   472,    -1,   472,    50,   229,   538,    -1,   473,    -1,
     473,   198,    94,   538,    -1,   474,    -1,   474,   100,    94,
     536,    -1,   475,    -1,   475,   101,    94,   536,    -1,   477,
      -1,   476,   477,    -1,   175,    -1,   157,    -1,   476,   175,
      -1,   476,   157,    -1,   480,    -1,   484,    -1,   481,    -1,
     201,    -1,   206,    -1,   205,    -1,   204,    -1,   203,    -1,
     202,    -1,   150,    -1,   178,    -1,   139,    -1,    75,   152,
     385,   183,    -1,    75,   220,   152,   385,   183,    -1,    75,
     219,   152,   385,   183,    -1,    75,    76,   553,   152,   385,
     183,    -1,   482,   152,   183,    -1,   482,   152,   405,   183,
      -1,   483,    -1,   482,   483,    -1,   176,   640,    17,    -1,
     176,    18,    -1,   176,    19,    -1,   485,    -1,   485,   486,
      -1,   191,   486,    -1,   486,    -1,   190,    -1,   487,    -1,
     487,   190,   486,    -1,   487,   191,   486,    -1,   488,    -1,
     497,    -1,   489,    -1,   489,   498,    -1,   492,    -1,   492,
     498,    -1,   490,   494,    -1,   491,    -1,   104,   121,    -1,
     113,   121,    -1,    97,   121,    -1,   188,   121,    -1,   114,
     121,    -1,   138,   121,    -1,   137,   121,    -1,   494,    -1,
      98,   494,    -1,   493,   494,    -1,   119,    -1,   171,   121,
      -1,    90,   121,    -1,   180,   121,    -1,   179,   121,    -1,
      91,   121,    -1,   543,    -1,   495,    -1,   640,    -1,   496,
      -1,   192,    -1,    11,    -1,    12,    -1,    20,    -1,   500,
      -1,   497,   498,    -1,   497,   155,   186,    -1,   497,   155,
     509,   186,    -1,   499,    -1,   498,   499,    -1,   153,   405,
     184,    -1,   501,    -1,   503,    -1,   504,    -1,   505,    -1,
     508,    -1,   510,    -1,   506,    -1,   507,    -1,   556,    -1,
     389,    -1,   629,    -1,   502,    -1,   555,    -1,   109,    -1,
     148,    -1,   123,    -1,   117,   640,    -1,   155,   186,    -1,
     155,   405,   186,    -1,   118,    -1,   168,   152,   405,   183,
      -1,   200,   152,   405,   183,    -1,   641,   155,   186,    -1,
     641,   155,   509,   186,    -1,   406,    -1,   509,   106,   406,
      -1,   511,    -1,   529,    -1,   512,    -1,   526,    -1,   527,
      -1,   156,   640,   516,   129,    -1,   156,   640,   514,   516,
     129,    -1,   156,   640,   516,   195,   193,   640,   516,   195,
      -1,   156,   640,   516,   195,   513,   193,   640,   516,   195,
      -1,   156,   640,   514,   516,   195,   193,   640,   516,   195,
      -1,   156,   640,   514,   516,   195,   513,   193,   640,   516,
     195,    -1,   524,    -1,   513,   524,    -1,   515,    -1,   514,
     515,    -1,    35,   640,   516,   131,   516,   517,    -1,    -1,
      35,    -1,   182,   518,   182,    -1,    93,   520,    93,    -1,
      -1,   519,    -1,   133,    -1,   522,    -1,   519,   133,    -1,
     519,   522,    -1,    -1,   521,    -1,   132,    -1,   523,    -1,
     521,   132,    -1,   521,   523,    -1,    28,    -1,   525,    -1,
       5,    -1,   525,    -1,   511,    -1,    10,    -1,   528,    -1,
     525,    -1,     9,    -1,   122,    -1,   124,    -1,   152,   385,
     183,    -1,   211,    30,   212,    -1,   211,   212,    -1,   173,
     639,   174,    -1,   173,   639,     8,    -1,   102,     7,    -1,
     530,    -1,   531,    -1,   532,    -1,   533,    -1,   534,    -1,
     535,    -1,    43,   152,   385,   183,    -1,    21,   384,   183,
      -1,    45,   152,   405,   183,   152,   384,   183,    -1,    22,
     384,   183,    -1,    97,   152,   405,   183,   152,   384,   183,
      -1,    70,   152,   385,   183,    -1,    39,   152,   385,   183,
      -1,    23,   384,   183,    -1,    59,   152,   405,   183,   152,
     384,   183,    -1,   542,    -1,   542,   143,    -1,    94,   538,
      -1,   540,    -1,   540,   539,    -1,   209,   155,   186,    -1,
     143,    -1,   192,    -1,   175,    -1,   542,    -1,   543,    -1,
     151,   155,   186,    -1,   559,    -1,   562,    -1,   633,    -1,
     538,    -1,   541,   106,   538,    -1,   640,    -1,   545,    -1,
     551,    -1,   549,    -1,   552,    -1,   550,    -1,   548,    -1,
     547,    -1,   546,    -1,   544,    -1,   223,   155,   186,    -1,
      44,   155,   186,    -1,    44,   155,   551,   186,    -1,    44,
     155,   552,   186,    -1,    70,   155,   186,    -1,    39,   155,
     186,    -1,    59,   155,   186,    -1,    59,   155,   639,   186,
      -1,    59,   155,    29,   186,    -1,    97,   155,   186,    -1,
      97,   155,   640,   186,    -1,    97,   155,   640,   106,   553,
     186,    -1,    97,   155,   192,   186,    -1,    97,   155,   192,
     106,   553,   186,    -1,    61,   155,   640,   186,    -1,    45,
     155,   186,    -1,    45,   155,   640,   186,    -1,    45,   155,
     640,   106,   553,   186,    -1,    45,   155,   640,   106,   554,
     186,    -1,    45,   155,   192,   186,    -1,    45,   155,   192,
     106,   553,   186,    -1,    45,   155,   192,   106,   554,   186,
      -1,    62,   155,   640,   186,    -1,   640,    -1,   640,   143,
      -1,    29,    -1,   557,    -1,   558,    -1,   640,   144,   148,
      -1,    47,   373,   390,    -1,   560,    -1,   561,    -1,    47,
     155,   192,   186,    -1,    47,   155,   186,    94,   538,    -1,
      47,   155,   541,   186,    94,   538,    -1,   155,   540,   186,
      -1,    33,   218,   219,    -1,    33,   218,   220,    -1,    33,
     218,   221,    -1,   224,   223,   406,   231,   406,    -1,   224,
     223,   406,    94,   230,   231,   406,    -1,   224,   223,   406,
      94,   232,   231,   406,    -1,   224,   223,   406,   216,   406,
      -1,   224,   223,   406,   217,   406,    -1,   224,   225,   406,
     231,   406,    -1,   224,   225,   406,    94,   230,   231,   406,
      -1,   224,   225,   406,    94,   232,   231,   406,    -1,   224,
     225,   406,   216,   406,    -1,   224,   225,   406,   217,   406,
      -1,   222,   223,   406,    -1,   222,   225,   406,    -1,   227,
     223,   406,   235,   406,    -1,   227,   228,   229,   223,   406,
     235,   406,    -1,   226,   223,   406,    94,   406,    -1,   234,
     117,   569,   233,   406,   185,   406,    -1,   570,    -1,   569,
     106,   117,   570,    -1,   640,   141,   406,    -1,   242,   152,
     405,   183,   572,    -1,   573,    -1,   572,   573,    -1,   243,
     575,   574,    -1,   152,   405,   183,    -1,   495,    -1,   575,
     208,   495,    -1,   579,   577,    -1,    -1,   578,    -1,   597,
      -1,   578,   597,    -1,   580,    -1,   579,   260,   580,    -1,
     581,    -1,   580,   256,   581,    -1,   582,    -1,   581,   258,
     146,   582,    -1,   583,    -1,   257,   583,    -1,   587,   584,
     585,    -1,    -1,   602,    -1,    -1,   586,    -1,   280,   152,
     405,   183,    -1,   591,   588,    -1,   155,   576,   186,    -1,
     589,    -1,    -1,   624,    -1,   482,   152,   590,   183,    -1,
      -1,   576,    -1,   592,   593,    -1,   501,    -1,   152,   405,
     183,    -1,    -1,   594,    -1,   246,   595,    -1,   245,   596,
      -1,   268,    -1,    -1,    78,    -1,    -1,   284,    -1,   598,
      -1,   599,    -1,   600,    -1,   626,    -1,   623,    -1,   168,
      -1,   282,   467,   601,    -1,   251,   625,   601,    -1,   284,
      -1,   274,    -1,   267,    -1,   244,   603,    -1,   602,   244,
     603,    -1,   604,    -1,   605,    -1,   606,    -1,   621,    -1,
     607,    -1,   615,    -1,   608,    -1,   622,    -1,    99,   272,
      -1,    99,   261,    -1,   264,    -1,   279,    -1,   249,   272,
      -1,   249,   261,    -1,    56,   640,    29,    -1,   275,    -1,
      54,   275,    -1,   277,   609,    -1,   277,   155,   609,   610,
     186,    -1,    54,   277,    -1,   612,    -1,   112,    -1,    -1,
     106,   611,    -1,   612,    -1,   611,   106,   612,    -1,    96,
      29,   613,   614,    -1,    -1,   269,    29,    -1,    -1,   625,
     263,    -1,   276,   284,   616,   618,    -1,   276,   284,   112,
     618,    -1,    54,   276,   284,    -1,    96,    29,    -1,   155,
     617,   186,    -1,    29,    -1,   617,   106,    29,    -1,    -1,
     619,    -1,   620,    -1,   619,   620,    -1,   199,   616,    -1,
     135,   616,    -1,   262,    29,    -1,   281,    -1,    54,   281,
      -1,    96,   215,    -1,    96,   252,    -1,   253,   248,    -1,
     265,   625,   278,    -1,   254,   467,    -1,    96,   128,   467,
      -1,    96,    52,   467,    -1,   255,   467,   197,   467,    -1,
     270,   627,    -1,   250,   627,    -1,   273,    -1,   266,    -1,
     283,   248,   469,    -1,   630,    -1,   631,    -1,   153,   632,
     184,    -1,   152,   632,   183,    -1,    -1,   405,    -1,   634,
      -1,   635,    -1,   636,    -1,   637,    -1,   309,   155,   186,
      -1,   310,   155,   186,    -1,   308,   155,   186,    -1,   311,
     155,   186,    -1,    29,    -1,    16,    -1,   640,    -1,   641,
      -1,    97,    -1,    39,    -1,    44,    -1,    45,    -1,   151,
      -1,    48,    -1,   223,    -1,    59,    -1,    61,    -1,    62,
      -1,    70,    -1,    73,    -1,    72,    -1,   209,    -1,   241,
      -1,   642,    -1,    24,    -1,   213,    -1,   126,    -1,    38,
      -1,   259,    -1,    37,    -1,   220,    -1,   219,    -1,   145,
      -1,    43,    -1,   257,    -1,   258,    -1,   272,    -1,   261,
      -1,   249,    -1,   283,    -1,   275,    -1,   277,    -1,   276,
      -1,   281,    -1,   253,    -1,   248,    -1,    78,    -1,   215,
      -1,   252,    -1,    52,    -1,   221,    -1,   234,    -1,   300,
      -1,   228,    -1,   201,    -1,   206,    -1,   205,    -1,   204,
      -1,   203,    -1,   202,    -1,    96,    -1,   110,    -1,   111,
      -1,   185,    -1,    46,    -1,    36,    -1,    66,    -1,    71,
      -1,    58,    -1,    53,    -1,    55,    -1,    77,    -1,    42,
      -1,   146,    -1,    51,    -1,   210,    -1,   169,    -1,   170,
      -1,   167,    -1,    69,    -1,    95,    -1,   115,    -1,   127,
      -1,   128,    -1,   105,    -1,    67,    -1,   134,    -1,   187,
      -1,    99,    -1,    94,    -1,   196,    -1,   125,    -1,   166,
      -1,    92,    -1,    50,    -1,   229,    -1,   100,    -1,   197,
      -1,   116,    -1,   158,    -1,   199,    -1,   149,    -1,   135,
      -1,    75,    -1,    76,    -1,   101,    -1,   198,    -1,   150,
      -1,   181,    -1,   194,    -1,   159,    -1,   136,    -1,   130,
      -1,   165,    -1,   147,    -1,   164,    -1,    33,    -1,    40,
      -1,    57,    -1,   112,    -1,    41,    -1,    56,    -1,   214,
      -1,    49,    -1,    60,    -1,    34,    -1,    47,    -1,   271,
      -1,   247,    -1,   280,    -1,   282,    -1,   251,    -1,   265,
      -1,   278,    -1,   270,    -1,   250,    -1,   264,    -1,   279,
      -1,   269,    -1,   263,    -1,   262,    -1,   246,    -1,   245,
      -1,   254,    -1,   255,    -1,   284,    -1,   274,    -1,   273,
      -1,   268,    -1,   266,    -1,   267,    -1,   227,    -1,   233,
      -1,   230,    -1,   224,    -1,   217,    -1,   216,    -1,   218,
      -1,   235,    -1,   225,    -1,   226,    -1,   232,    -1,   222,
      -1,   231,    -1,    65,    -1,    63,    -1,    74,    -1,   168,
      -1,   200,    -1,   240,    -1,   238,    -1,   239,    -1,   236,
      -1,   237,    -1,   242,    -1,   243,    -1,   244,    -1,    64,
      -1,   293,    -1,   291,    -1,   292,    -1,   297,    -1,   298,
      -1,   299,    -1,   294,    -1,   295,    -1,   296,    -1,    79,
      -1,    80,    -1,    81,    -1,    82,    -1,    83,    -1,    84,
      -1,    85,    -1,    86,    -1,    87,    -1,    88,    -1,    89,
      -1,   285,    -1,   286,    -1,   287,    -1,   288,    -1,   289,
      -1,   290,    -1,   301,    -1,   302,    -1,   303,    -1,   304,
      -1,   305,    -1,   306,    -1,   307,    -1,    90,    -1,   104,
      -1,   113,    -1,   171,    -1,   179,    -1,   188,    -1,   137,
      -1,    91,    -1,   114,    -1,   138,    -1,   180,    -1,   310,
      -1,   308,    -1,   311,    -1,   309,    -1,    25,    -1
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
     816,   819,   822,   825,   827,   829,   832,   837,   841,   847,
     852,   856,   858,   860,   862,   864,   866,   868,   870,   872,
     874,   877,   881,   883,   888,   892,   898,   903,   910,   915,
     922,   928,   936,   941,   947,   953,   960,   964,   968,   971,
     973,   977,   982,   988,   992,   999,  1004,  1010,  1012,  1015,
    1019,  1021,  1024,  1026,  1033,  1037,  1041,  1044,  1048,  1050,
    1054,  1057,  1061,  1064,  1068,  1073,  1075,  1079,  1081,  1084,
    1086,  1088,  1090,  1093,  1096,  1099,  1103,  1105,  1107,  1110,
    1113,  1116,  1122,  1128,  1130,  1135,  1139,  1144,  1153,  1155,
    1158,  1162,  1165,  1169,  1178,  1180,  1183,  1187,  1196,  1207,
    1216,  1227,  1229,  1232,  1237,  1245,  1247,  1250,  1255,  1263,
    1272,  1274,  1278,  1280,  1284,  1286,  1290,  1294,  1298,  1302,
    1303,  1308,  1312,  1316,  1320,  1322,  1328,  1329,  1331,  1333,
    1337,  1339,  1343,  1345,  1349,  1353,  1355,  1359,  1363,  1367,
    1371,  1373,  1377,  1381,  1383,  1387,  1391,  1393,  1398,  1400,
    1405,  1407,  1412,  1414,  1419,  1421,  1424,  1426,  1428,  1431,
    1434,  1436,  1438,  1440,  1442,  1444,  1446,  1448,  1450,  1452,
    1454,  1456,  1458,  1463,  1469,  1475,  1482,  1486,  1491,  1493,
    1496,  1500,  1503,  1506,  1508,  1511,  1514,  1516,  1518,  1520,
    1524,  1528,  1530,  1532,  1534,  1537,  1539,  1542,  1545,  1547,
    1550,  1553,  1556,  1559,  1562,  1565,  1568,  1570,  1573,  1576,
    1578,  1581,  1584,  1587,  1590,  1593,  1595,  1597,  1599,  1601,
    1603,  1605,  1607,  1609,  1611,  1614,  1618,  1623,  1625,  1628,
    1632,  1634,  1636,  1638,  1640,  1642,  1644,  1646,  1648,  1650,
    1652,  1654,  1656,  1658,  1660,  1662,  1664,  1667,  1670,  1674,
    1676,  1681,  1686,  1690,  1695,  1697,  1701,  1703,  1705,  1707,
    1709,  1711,  1716,  1722,  1731,  1741,  1751,  1762,  1764,  1767,
    1769,  1772,  1779,  1780,  1782,  1786,  1790,  1791,  1793,  1795,
    1797,  1800,  1803,  1804,  1806,  1808,  1810,  1813,  1816,  1818,
    1820,  1822,  1824,  1826,  1828,  1830,  1832,  1834,  1836,  1838,
    1842,  1846,  1849,  1853,  1857,  1860,  1862,  1864,  1866,  1868,
    1870,  1872,  1877,  1881,  1889,  1893,  1901,  1906,  1911,  1915,
    1923,  1925,  1928,  1931,  1933,  1936,  1940,  1942,  1944,  1946,
    1948,  1950,  1954,  1956,  1958,  1960,  1962,  1966,  1968,  1970,
    1972,  1974,  1976,  1978,  1980,  1982,  1984,  1986,  1990,  1994,
    1999,  2004,  2008,  2012,  2016,  2021,  2026,  2030,  2035,  2042,
    2047,  2054,  2059,  2063,  2068,  2075,  2082,  2087,  2094,  2101,
    2106,  2108,  2111,  2113,  2115,  2117,  2121,  2125,  2127,  2129,
    2134,  2140,  2147,  2151,  2155,  2159,  2163,  2169,  2177,  2185,
    2191,  2197,  2203,  2211,  2219,  2225,  2231,  2235,  2239,  2245,
    2253,  2259,  2267,  2269,  2274,  2278,  2284,  2286,  2289,  2293,
    2297,  2299,  2303,  2306,  2307,  2309,  2311,  2314,  2316,  2320,
    2322,  2326,  2328,  2333,  2335,  2338,  2342,  2343,  2345,  2346,
    2348,  2353,  2356,  2360,  2362,  2363,  2365,  2370,  2371,  2373,
    2376,  2378,  2382,  2383,  2385,  2388,  2391,  2393,  2394,  2396,
    2397,  2399,  2401,  2403,  2405,  2407,  2409,  2411,  2415,  2419,
    2421,  2423,  2425,  2428,  2432,  2434,  2436,  2438,  2440,  2442,
    2444,  2446,  2448,  2451,  2454,  2456,  2458,  2461,  2464,  2468,
    2470,  2473,  2476,  2482,  2485,  2487,  2489,  2490,  2493,  2495,
    2499,  2504,  2505,  2508,  2509,  2512,  2517,  2522,  2526,  2529,
    2533,  2535,  2539,  2540,  2542,  2544,  2547,  2550,  2553,  2556,
    2558,  2561,  2564,  2567,  2570,  2574,  2577,  2581,  2585,  2590,
    2593,  2596,  2598,  2600,  2604,  2606,  2608,  2612,  2616,  2617,
    2619,  2621,  2623,  2625,  2627,  2631,  2635,  2639,  2643,  2645,
    2647,  2649,  2651,  2653,  2655,  2657,  2659,  2661,  2663,  2665,
    2667,  2669,  2671,  2673,  2675,  2677,  2679,  2681,  2683,  2685,
    2687,  2689,  2691,  2693,  2695,  2697,  2699,  2701,  2703,  2705,
    2707,  2709,  2711,  2713,  2715,  2717,  2719,  2721,  2723,  2725,
    2727,  2729,  2731,  2733,  2735,  2737,  2739,  2741,  2743,  2745,
    2747,  2749,  2751,  2753,  2755,  2757,  2759,  2761,  2763,  2765,
    2767,  2769,  2771,  2773,  2775,  2777,  2779,  2781,  2783,  2785,
    2787,  2789,  2791,  2793,  2795,  2797,  2799,  2801,  2803,  2805,
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
    3087
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1017,  1017,  1018,  1027,  1036,  1042,  1050,  1056,  1067,
    1072,  1080,  1087,  1094,  1103,  1110,  1118,  1126,  1134,  1145,
    1150,  1157,  1164,  1176,  1186,  1193,  1200,  1212,  1213,  1214,
    1215,  1216,  1221,  1222,  1223,  1224,  1225,  1226,  1227,  1230,
    1235,  1240,  1248,  1256,  1264,  1269,  1277,  1282,  1290,  1295,
    1303,  1310,  1317,  1324,  1334,  1336,  1339,  1349,  1354,  1362,
    1370,  1381,  1388,  1399,  1404,  1412,  1419,  1426,  1435,  1448,
    1456,  1463,  1473,  1480,  1487,  1498,  1499,  1500,  1501,  1502,
    1503,  1504,  1505,  1510,  1516,  1525,  1532,  1542,  1552,  1553,
    1554,  1555,  1556,  1557,  1558,  1559,  1560,  1561,  1566,  1574,
    1582,  1590,  1597,  1605,  1612,  1617,  1625,  1633,  1648,  1663,
    1681,  1686,  1694,  1702,  1713,  1718,  1727,  1732,  1739,  1744,
    1754,  1759,  1768,  1774,  1787,  1792,  1800,  1811,  1826,  1838,
    1853,  1858,  1863,  1868,  1876,  1883,  1894,  1899,  1909,  1916,
    1923,  1930,  1940,  1944,  1954,  1962,  1973,  1979,  1988,  1993,
    2000,  2007,  2018,  2028,  2038,  2048,  2066,  2086,  2091,  2096,
    2103,  2108,  2113,  2120,  2125,  2137,  2144,  2156,  2157,  2158,
    2159,  2160,  2161,  2162,  2164,  2165,  2166,  2167,  2168,  2173,
    2178,  2186,  2203,  2211,  2219,  2226,  2233,  2243,  2255,  2268,
    2280,  2296,  2304,  2312,  2320,  2335,  2340,  2348,  2362,  2379,
    2404,  2412,  2419,  2430,  2440,  2445,  2460,  2461,  2462,  2463,
    2464,  2465,  2470,  2471,  2474,  2475,  2476,  2477,  2478,  2483,
    2497,  2505,  2510,  2518,  2523,  2528,  2536,  2545,  2557,  2567,
    2580,  2588,  2589,  2590,  2595,  2596,  2597,  2598,  2599,  2604,
    2611,  2621,  2629,  2636,  2646,  2656,  2666,  2676,  2686,  2696,
    2706,  2716,  2727,  2736,  2746,  2756,  2772,  2781,  2790,  2798,
    2804,  2816,  2824,  2834,  2842,  2854,  2860,  2871,  2873,  2877,
    2885,  2889,  2894,  2898,  2902,  2906,  2916,  2924,  2931,  2937,
    2948,  2952,  2961,  2969,  2975,  2985,  2991,  3001,  3005,  3015,
    3021,  3027,  3033,  3042,  3051,  3060,  3073,  3077,  3085,  3091,
    3101,  3109,  3118,  3131,  3138,  3150,  3154,  3166,  3173,  3179,
    3188,  3195,  3201,  3212,  3219,  3225,  3234,  3243,  3250,  3261,
    3268,  3280,  3286,  3298,  3304,  3315,  3321,  3332,  3338,  3349,
    3358,  3362,  3371,  3375,  3383,  3387,  3397,  3404,  3413,  3423,
    3422,  3436,  3445,  3454,  3467,  3471,  3484,  3487,  3496,  3500,
    3509,  3514,  3523,  3527,  3531,  3540,  3544,  3550,  3556,  3562,
    3573,  3577,  3581,  3589,  3593,  3599,  3609,  3613,  3623,  3627,
    3637,  3641,  3651,  3655,  3665,  3669,  3677,  3681,  3685,  3689,
    3699,  3703,  3707,  3715,  3719,  3723,  3727,  3731,  3735,  3743,
    3747,  3751,  3759,  3763,  3767,  3771,  3782,  3788,  3798,  3804,
    3814,  3818,  3822,  3860,  3864,  3874,  3884,  3897,  3906,  3916,
    3920,  3929,  3933,  3942,  3948,  3956,  3962,  3974,  3980,  3990,
    3994,  3998,  4002,  4006,  4012,  4018,  4026,  4030,  4038,  4042,
    4053,  4057,  4061,  4067,  4071,  4085,  4089,  4097,  4101,  4111,
    4115,  4119,  4123,  4132,  4136,  4140,  4144,  4152,  4158,  4168,
    4176,  4180,  4184,  4188,  4192,  4196,  4200,  4204,  4208,  4218,
    4222,  4230,  4234,  4242,  4249,  4256,  4267,  4275,  4279,  4287,
    4295,  4303,  4357,  4361,  4374,  4380,  4390,  4394,  4402,  4406,
    4410,  4418,  4428,  4438,  4448,  4458,  4468,  4483,  4489,  4500,
    4506,  4517,  4528,  4530,  4534,  4539,  4549,  4552,  4559,  4565,
    4571,  4579,  4592,  4595,  4602,  4608,  4614,  4621,  4632,  4636,
    4646,  4650,  4660,  4664,  4668,  4673,  4682,  4688,  4694,  4700,
    4708,  4713,  4721,  4726,  4734,  4742,  4747,  4752,  4757,  4762,
    4767,  4776,  4784,  4788,  4805,  4809,  4817,  4825,  4833,  4837,
    4845,  4851,  4861,  4869,  4873,  4877,  4912,  4918,  4924,  4934,
    4938,  4942,  4946,  4950,  4954,  4961,  4967,  4977,  4985,  4989,
    4993,  4997,  5001,  5005,  5009,  5013,  5017,  5025,  5033,  5037,
    5041,  5051,  5059,  5067,  5071,  5075,  5083,  5087,  5093,  5099,
    5103,  5113,  5121,  5125,  5131,  5140,  5149,  5155,  5161,  5171,
    5188,  5195,  5210,  5246,  5250,  5258,  5266,  5278,  5282,  5290,
    5298,  5302,  5313,  5330,  5336,  5342,  5352,  5356,  5362,  5368,
    5372,  5378,  5382,  5388,  5394,  5401,  5411,  5416,  5424,  5430,
    5440,  5462,  5471,  5477,  5490,  5504,  5511,  5517,  5527,  5536,
    5544,  5550,  5568,  5577,  5580,  5587,  5592,  5600,  5604,  5611,
    5615,  5622,  5626,  5633,  5637,  5646,  5659,  5662,  5670,  5673,
    5681,  5689,  5697,  5701,  5709,  5712,  5720,  5732,  5735,  5743,
    5755,  5761,  5771,  5774,  5782,  5786,  5790,  5798,  5801,  5809,
    5812,  5820,  5824,  5828,  5832,  5836,  5844,  5852,  5864,  5876,
    5880,  5884,  5892,  5898,  5908,  5912,  5916,  5920,  5924,  5928,
    5932,  5936,  5944,  5948,  5952,  5956,  5964,  5970,  5980,  5990,
    5994,  6002,  6012,  6023,  6030,  6034,  6042,  6045,  6052,  6057,
    6066,  6076,  6079,  6087,  6090,  6098,  6107,  6114,  6124,  6128,
    6135,  6141,  6151,  6154,  6161,  6166,  6178,  6186,  6198,  6206,
    6210,  6218,  6222,  6226,  6234,  6242,  6246,  6250,  6254,  6262,
    6270,  6282,  6286,  6294,  6304,  6309,  6339,  6348,  6357,  6361,
    6370,  6375,  6380,  6385,  6394,  6402,  6410,  6418,  6432,  6436,
    6437,  6450,  6451,  6452,  6453,  6454,  6455,  6456,  6457,  6458,
    6459,  6460,  6461,  6462,  6463,  6464,  6465,  6469,  6470,  6471,
    6472,  6473,  6474,  6475,  6476,  6477,  6478,  6479,  6480,  6481,
    6482,  6483,  6484,  6485,  6486,  6487,  6488,  6489,  6490,  6491,
    6492,  6493,  6494,  6495,  6496,  6497,  6498,  6499,  6500,  6501,
    6502,  6503,  6504,  6505,  6506,  6507,  6508,  6509,  6510,  6511,
    6512,  6513,  6514,  6515,  6516,  6517,  6518,  6519,  6520,  6521,
    6522,  6523,  6524,  6525,  6526,  6527,  6528,  6529,  6530,  6531,
    6532,  6533,  6534,  6535,  6536,  6537,  6538,  6539,  6540,  6541,
    6542,  6543,  6544,  6545,  6546,  6547,  6548,  6549,  6550,  6551,
    6552,  6553,  6554,  6555,  6556,  6557,  6558,  6559,  6560,  6561,
    6562,  6563,  6564,  6565,  6566,  6567,  6568,  6569,  6570,  6571,
    6572,  6573,  6574,  6575,  6576,  6577,  6578,  6579,  6580,  6581,
    6582,  6583,  6584,  6585,  6586,  6587,  6588,  6589,  6590,  6591,
    6592,  6593,  6594,  6595,  6596,  6597,  6598,  6599,  6600,  6601,
    6602,  6603,  6604,  6605,  6606,  6607,  6608,  6609,  6610,  6611,
    6612,  6613,  6614,  6615,  6616,  6617,  6618,  6619,  6620,  6621,
    6622,  6623,  6624,  6625,  6626,  6627,  6628,  6629,  6630,  6631,
    6632,  6633,  6634,  6635,  6636,  6637,  6638,  6639,  6640,  6641,
    6642,  6643,  6644,  6645,  6646,  6647,  6648,  6649,  6650,  6651,
    6652,  6653,  6654,  6655,  6656,  6657,  6658,  6659,  6660,  6661,
    6662,  6663,  6664,  6665,  6666,  6667,  6668,  6669,  6670,  6671,
    6676
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
     325,   326
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 13350;
  const int xquery_parser::yynnts_ = 316;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 581;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 327;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 581;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 16315 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6680 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"


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

