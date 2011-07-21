
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
#line 71 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"


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
#line 79 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 860 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 960 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 109 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"

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
#line 178 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
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
        case 108: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 858 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 285 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 122: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 857 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 294 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 147: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 856 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 303 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 528 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 537 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
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
#line 124 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2773 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"

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
#line 978 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 987 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 996 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1002 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1010 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1016 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1027 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1032 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1040 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1047 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1054 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1063 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1070 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1078 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1086 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1094 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1105 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1110 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1117 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1124 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1136 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1146 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1153 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1160 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 1195 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1200 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1208 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1216 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1224 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1229 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1237 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1242 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1250 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1255 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1263 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1270 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1277 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1284 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1299 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1309 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1314 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1322 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1330 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1341 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1348 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1359 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1364 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1372 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1379 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1386 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1395 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 1408 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1416 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1423 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1433 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1440 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1447 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1470 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1476 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1485 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1492 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1502 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1511 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1512 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1513 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1514 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1515 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1516 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1517 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1518 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1519 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1520 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1526 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1534 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1542 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1550 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1557 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1565 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1572 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1577 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1585 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1593 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 1608 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 1623 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 1641 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1646 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1654 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1662 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1673 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1678 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1687 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1692 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1699 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1704 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1714 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1719 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1728 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1734 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1747 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1752 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1760 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 1771 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 1786 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 1798 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 1813 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1818 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1823 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1828 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1836 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1843 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1854 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1859 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1869 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1876 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1883 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1890 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1900 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1904 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1914 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 1922 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 1933 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1939 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1948 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1953 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1960 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1967 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1979 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 1989 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 1999 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2010 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2026 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2046 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2051 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2055 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2063 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2068 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2072 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2080 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2085 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2097 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2104 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2133 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2138 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2146 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2163 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2171 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2179 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2186 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2193 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2200 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2207 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)));
      vdecl->add((yysemantic_stack_[(4) - (4)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 2217 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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

  case 190:

/* Line 678 of lalr1.cc  */
#line 2229 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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

  case 191:

/* Line 678 of lalr1.cc  */
#line 2242 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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

  case 192:

/* Line 678 of lalr1.cc  */
#line 2254 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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

  case 193:

/* Line 678 of lalr1.cc  */
#line 2270 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2278 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 2286 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2294 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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

  case 197:

/* Line 678 of lalr1.cc  */
#line 2309 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2314 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2322 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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

  case 200:

/* Line 678 of lalr1.cc  */
#line 2336 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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

  case 201:

/* Line 678 of lalr1.cc  */
#line 2353 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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

  case 202:

/* Line 678 of lalr1.cc  */
#line 2378 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2386 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2393 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2404 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2410 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2416 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)),
                          *(yysemantic_stack_[(10) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(10) - (5)].expr)),
                          static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                          NULL,
                          (yysemantic_stack_[(10) - (10)].expr));
       delete (yysemantic_stack_[(10) - (2)].name_test_list);
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2427 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(13) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(13) - (5)].expr)),
                          static_cast<QName*>((yysemantic_stack_[(13) - (8)].expr)),
                          static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                          (yysemantic_stack_[(13) - (13)].expr));
       delete (yysemantic_stack_[(13) - (2)].name_test_list);
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2442 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2447 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2485 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2499 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2507 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2512 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2520 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2525 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2530 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2538 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2547 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2559 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2569 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2582 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2606 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2613 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2623 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2631 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2638 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2648 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2658 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2668 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2678 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2688 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2698 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2708 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2718 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2729 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2738 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2748 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2758 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2774 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2783 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2792 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2800 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2806 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2818 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2826 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2836 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2844 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 2856 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2862 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2875 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2879 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2887 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2891 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2900 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2904 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2908 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2918 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2926 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2933 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2939 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2950 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2954 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2963 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2971 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2977 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2987 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2993 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 3003 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3007 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3017 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3023 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3029 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3035 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 3044 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 3053 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 3062 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 3075 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3079 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3087 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3093 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3103 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3111 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 3120 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 3133 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3140 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3152 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3156 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3168 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3175 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3181 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3190 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3197 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3203 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3214 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3221 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3227 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3236 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3245 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3252 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 3263 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3270 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 3282 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3288 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3300 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3306 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3317 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3323 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3334 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3340 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3351 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3360 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3364 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3373 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3377 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3385 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3389 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 3399 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3406 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 3415 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 3424 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3429 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 3438 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 3447 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 3456 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 3469 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3473 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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
#line 3485 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3489 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3496 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3500 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3509 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3513 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3517 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3526 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3530 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3536 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3542 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3548 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3559 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3563 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3567 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3575 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3579 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3585 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3595 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3599 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3609 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3613 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3623 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3627 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3637 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3641 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3651 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3655 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3663 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3667 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3671 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3675 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3685 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3689 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3693 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3701 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3705 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3709 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3713 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3717 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3721 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3729 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3733 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3737 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3745 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3749 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3753 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3757 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3768 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3774 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3784 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3790 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3800 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3804 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3808 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3846 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3850 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3860 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3870 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3883 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3892 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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

  case 412:

/* Line 678 of lalr1.cc  */
#line 3902 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3906 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3915 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3919 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3928 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3934 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3942 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3948 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3960 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3966 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3976 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3980 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3984 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3988 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3992 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3998 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4004 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4012 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4016 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4024 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4028 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4039 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4043 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4047 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4053 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4057 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4071 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4075 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4083 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4087 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4097 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4101 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4105 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4109 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4118 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4122 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4126 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4130 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4138 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4144 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4154 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4162 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4166 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4170 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4174 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4178 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4182 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4186 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4190 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4194 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4204 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4212 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4216 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4224 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4231 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4238 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4249 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4257 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4261 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4269 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4277 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4285 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4339 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4343 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4356 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4362 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4372 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4376 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4384 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4388 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4392 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4400 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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

  case 484:

/* Line 678 of lalr1.cc  */
#line 4410 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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

  case 485:

/* Line 678 of lalr1.cc  */
#line 4420 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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

  case 486:

/* Line 678 of lalr1.cc  */
#line 4430 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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

  case 487:

/* Line 678 of lalr1.cc  */
#line 4440 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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

  case 488:

/* Line 678 of lalr1.cc  */
#line 4450 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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

  case 489:

/* Line 678 of lalr1.cc  */
#line 4465 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4471 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4482 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4488 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4499 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4516 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4521 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4530 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4534 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4541 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4547 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4553 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4561 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4573 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4577 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4584 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4590 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4596 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4603 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4614 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4618 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4628 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4632 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4642 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4646 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4650 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4655 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4664 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4670 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4676 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4682 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4690 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4695 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4703 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4708 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4716 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4724 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4729 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4734 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4739 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4744 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4749 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4758 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4766 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4770 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4787 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4791 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4799 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4807 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4815 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4819 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4827 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4833 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4843 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4851 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4855 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4859 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4894 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4900 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4906 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4916 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4920 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4924 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4928 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4932 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4939 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4945 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4955 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4963 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4967 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4971 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4975 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4979 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4983 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 4987 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 4991 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 4995 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5003 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5011 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5015 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5019 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5029 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5037 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5045 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5049 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5053 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5061 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5065 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5071 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5077 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5081 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5091 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5099 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5103 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5109 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5118 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5127 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5133 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5139 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5149 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5166 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5173 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5188 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5224 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5228 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5236 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5244 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5256 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5260 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5268 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5276 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5280 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5291 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5308 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5314 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5320 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5330 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5334 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5340 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5346 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5350 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5356 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5360 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5366 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5372 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5379 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5389 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5394 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5402 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5408 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5418 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5440 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5449 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5455 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5468 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5482 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5489 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5495 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5505 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5510 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5515 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)),
                          *(yysemantic_stack_[(10) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(10) - (5)].expr)),
                          static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                          NULL,
                          (yysemantic_stack_[(10) - (10)].expr));
       delete (yysemantic_stack_[(10) - (2)].name_test_list);
    }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5525 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(13) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(13) - (5)].expr)),
                          static_cast<QName*>((yysemantic_stack_[(13) - (8)].expr)),
                          static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                          (yysemantic_stack_[(13) - (13)].expr));
       delete (yysemantic_stack_[(13) - (2)].name_test_list);
    }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5539 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5547 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5553 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5571 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5579 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5583 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5590 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5595 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5603 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5607 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5614 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5618 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5625 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5629 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5636 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5640 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5649 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5661 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5665 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5672 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5676 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5684 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5692 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5700 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5704 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5711 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5715 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5723 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5734 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5738 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5746 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5758 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5764 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5773 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5777 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5785 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5789 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5793 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5800 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5804 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5811 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5815 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5823 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5827 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5831 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5835 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5839 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5847 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5855 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5867 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5879 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5883 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5887 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5895 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5901 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5911 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5915 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5919 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5923 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5927 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5931 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5935 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5939 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5947 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5951 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5955 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5959 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5967 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5973 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5983 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5993 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5997 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 6005 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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

  case 706:

/* Line 678 of lalr1.cc  */
#line 6015 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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

  case 707:

/* Line 678 of lalr1.cc  */
#line 6026 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6033 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6037 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6044 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6048 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6055 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6060 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6069 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6078 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6082 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6089 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6093 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6101 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6110 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6117 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6127 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6131 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6138 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6144 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6153 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6157 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6164 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6169 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6181 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6189 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6201 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6209 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6213 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6221 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6225 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6229 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6237 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6245 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6249 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6253 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6257 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6265 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6273 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6285 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6289 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6297 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6315 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
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

  case 752:

/* Line 678 of lalr1.cc  */
#line 6328 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6329 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6330 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6331 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6332 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6333 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6334 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6335 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6336 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6337 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6338 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6339 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6340 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6341 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6342 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6347 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6348 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6349 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6350 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6351 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6352 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6353 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6354 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6355 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6356 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6357 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6358 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6359 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6360 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6361 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6362 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6363 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6364 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6365 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6366 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6367 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6368 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6369 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6370 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6371 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6372 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6373 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6374 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6375 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6377 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6378 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6379 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6380 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6382 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6383 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6384 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6385 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6386 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6387 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6388 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6389 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6390 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6391 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6392 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6393 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6394 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6395 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6396 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6397 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6398 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6399 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6400 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6401 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6402 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6403 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6404 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6405 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6406 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6407 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6408 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6409 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6410 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6411 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6412 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6413 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6414 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6415 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6416 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6417 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6418 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6419 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6420 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6421 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6422 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6423 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6424 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6425 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6426 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6427 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6428 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6429 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6430 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6431 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6432 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6433 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6434 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6435 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6436 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6437 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6438 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6439 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6440 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6441 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6442 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6443 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6444 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6445 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6446 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6447 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6448 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6449 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6450 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6451 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6452 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6453 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6454 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6455 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6456 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6457 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6458 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6459 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6460 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6461 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6462 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6463 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6464 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6465 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6466 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6467 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6468 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6469 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6470 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6471 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6472 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6473 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6474 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6475 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6476 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6477 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6478 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6479 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6480 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6481 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6482 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6483 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6484 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6485 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6486 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6487 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6488 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6489 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6490 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6491 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6492 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("local"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6493 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6494 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6495 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6496 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6497 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6498 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6499 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6500 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6501 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6502 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6503 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6504 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6505 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6506 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6507 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6508 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6509 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6510 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6511 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6512 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6513 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6514 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6515 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6516 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6517 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6518 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6519 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6520 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6521 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6522 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6523 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6524 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6525 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6526 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6527 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6528 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6529 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6530 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6531 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6532 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6533 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6534 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6535 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6536 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6537 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6538 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6539 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6540 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6541 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 963:

/* Line 678 of lalr1.cc  */
#line 6542 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 964:

/* Line 678 of lalr1.cc  */
#line 6543 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 965:

/* Line 678 of lalr1.cc  */
#line 6544 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 966:

/* Line 678 of lalr1.cc  */
#line 6550 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    {
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true);
        }
    break;

  case 967:

/* Line 678 of lalr1.cc  */
#line 6556 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 11614 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1365;
  const short int
  xquery_parser::yypact_[] =
  {
      3113, -1365, -1365, -1365,  4599,  4599,  4599, -1365, -1365,   164,
     230,    57,   126,   236, -1365, -1365, -1365,   621, -1365, -1365,
   -1365,    21,   269,   772,   685,   294,   321,   752, -1365,    -3,
   -1365, -1365, -1365, -1365, -1365, -1365,   779, -1365,   325,   403,
   -1365, -1365, -1365, -1365,   335, -1365,   780, -1365,   441,   488,
   -1365,    97, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365,   295,   367, -1365, -1365, -1365,
   -1365,   738,  9054, -1365, -1365, -1365,   559, -1365, -1365, -1365,
     586, -1365,   632,   672, -1365, -1365, 12781, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365,   694, -1365, -1365,   761,   791,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365,  3411,  6381, 12781,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365,   665, -1365, -1365,
     795,  9935, -1365, 10225,   824,   864, -1365, -1365, -1365,   868,
   -1365,  8757, -1365, -1365, -1365, -1365, -1365, -1365,   742, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365,    56,   727, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365,   645,   837,   719,
   -1365,   775,   573, -1365, -1365, -1365, -1365, -1365, -1365,   882,
   -1365,   107,   760,   763,   764, -1365, -1365,   849,   855, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365,  4896,  1005, -1365,  5193, -1365, -1365,   471,    76,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365,    81, -1365, -1365, -1365, -1365, -1365,
   -1365,   180, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
    4599, -1365, -1365, -1365, -1365,   187, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365,   903, -1365,   823, -1365, -1365, -1365,
     296, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,   847,
     923, -1365,   745,   769,   682,   554,   445,   537, -1365,   967,
     821,   920,   921,  7569, -1365, -1365, -1365,     9, -1365, -1365,
    8757, -1365,   773, -1365,   871,  9054, -1365,   871,  9054, -1365,
   -1365, -1365,   820, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365,   901,   881,   873, -1365, -1365,
   -1365, -1365, -1365,   844, -1365,  4599,   846,   848,   290,   290,
    1000,   165,   616,   423, 13065, 12781,   -25,   985, 12781,   884,
     919,   360,  9935,   750,   792, 12781, 12781,   736,   702,    40,
   -1365, -1365, -1365,  9935,  4599,   857,  4599,    96,  7866, 10793,
     757,   758, 12781,   927,    29,   893,  7866,  1044,    72,   190,
   12781,   930,   910,   946, -1365,  7866,  9643, 12781, 12781, 12781,
    4599,   867,  7866,  7866, 12781,  4599,   902,   907, -1365, -1365,
   -1365,  7866, 11077, -1365,   900, -1365,   905, -1365, -1365, -1365,
   -1365,   911, -1365,   912, -1365, -1365, -1365, -1365, -1365,   913,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, 12781, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365,   924, 12781, -1365, -1365, -1365,   886,  3708,   915,   916,
     917, 12781,  4599, -1365,   922,   229, -1365,   491,  1037,  7866,
   -1365, -1365,    83, -1365, -1365, -1365,  1057, -1365, -1365, -1365,
   -1365,  7866,   865, -1365,  1046,  7866,  7866,   894,  7866,  7866,
    7866,  7866,   852, 12781,   586,   333,   889,   890,  7866,  7866,
    3411,   838, -1365, -1365, -1365, -1365,   126,   752,    87,    91,
    1079,  5490,  5490,  5787,  5787,   586, -1365, -1365,   903,   586,
   -1365,  7866, -1365,   968,   685,    -3,   925,   918,   926,  4599,
    7866, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,  8163,
    8163,  8163, -1365,  8163,  8163, -1365,  8163, -1365,  8163, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365,  8163,  8163,  1015,  8163,
    8163,  8163,  8163,  8163,  8163,  8163,  8163,  8163,  8163,  8163,
     859,   996,   997,   999, -1365, -1365, -1365,  6678, -1365, -1365,
    8757,  8757,  7866,   871, -1365, -1365,   871, -1365,  6975,   871,
    9935,   948,  7272, -1365, -1365, -1365, -1365,   231, -1365,   261,
   -1365, -1365, -1365, -1365, -1365,   988,   991,   294,  1068, -1365,
   -1365, 13065,   872,    53, 12781,   941,   942,   872,  1000,   976,
     972, -1365, -1365, -1365,   418,   860,  1010,   808, 12781,   966,
    7866,   992, 12781, 12781, -1365,   977,   928,  4599, -1365,   929,
     905,   403, -1365,   932,   933,   227, -1365,   262,   292, -1365,
   -1365,  1004, -1365,    35, 12781,    26, 12781,  1020,   297, -1365,
    4599, -1365,   299, -1365,  9935,  1019,  1070,  9935,  1000,  1024,
     626, 12781,  7866,    -3,   331,   935, -1365,   936,   937,   938,
       6, -1365,    58,   943, -1365,   305,   336,   973, -1365,   944,
    4599,  4599,   391, -1365,   340,   349,   643,  7866,    74, -1365,
   -1365,  7866,  7866,  7866, -1365,  7866, -1365,  7866, 12781,  1037,
   -1365,   183,   438, -1365, -1365, -1365,   463, -1365,    36, -1365,
   -1365, -1365,   134,   141,  1034,   895,   906,    -7, -1365,   990,
   -1365,   586, -1365, -1365,   945,   356,  4005,   499,  9351,   838,
   -1365,   471,   684,  1098,  1098, -1365, -1365,   101, -1365, -1365,
     119, -1365,    38, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   12781,   964,  7866,  1018, -1365, -1365, -1365,   923, -1365, -1365,
   -1365, -1365, -1365,  8163, -1365, -1365, -1365,    47,   554,   554,
      12,   445,   445,   445,   445,   537,   537, -1365, -1365, 12213,
   12213, 12781, 12781, -1365,   510, -1365, -1365,    22, -1365, -1365,
   -1365,   361, -1365, -1365, -1365,   373,   290, -1365, -1365,   206,
     339,   553, -1365,   294, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365,   872, -1365,  1006, 12497,   995,  7866,
   -1365, -1365, -1365,  1045,  1000,  1000,   872, -1365,   850,  1000,
     690, 12781,   379,   598,  1110, -1365, -1365,   856,    43, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
     418,   329,   940,   565,  7866, -1365, 12781,  1048,   845,  1000,
   -1365, -1365, -1365, -1365,   993, 12781, -1365, 12781, -1365,  1027,
    1022, 12213,  1029,  7866,    11,  1008,    14,   308,   897, -1365,
   -1365,   655,    26,  1045, 12213,  1035,  1061,   974,   962,  1036,
    1000,  1001,  1039,  1072,  1000,  7866,   -43, -1365, -1365, -1365,
    1021, -1365, -1365, -1365, -1365,  1054,  7866,  7866,  1026, -1365,
    1075,  1076,  4599, -1365,   994,   998,  1028, 12781, -1365, 12781,
   -1365,  7866,  1038,   987,  7866,   386,   392,   412,  1142, -1365,
     199, -1365,   408, -1365, -1365,  1152, -1365,   283,  7866,  7866,
    7866,   744,  7866,  7866,  7866,  7866,  7866,  7866,  1066,  7866,
    7866, -1365, -1365,  6084,  1030,  1032,  1033,  1040,   823,   711,
     947, -1365,   507, -1365,   120,   172,    38,  5787,  5787,  5787,
    1111, -1365,  7866,   814,  1083, -1365, 12781,  1087, -1365, -1365,
    7866,    47,   447,    10, -1365,   914,   570,   939,   949, -1365,
   -1365,   792, -1365,   934,   604,  1047,  1049, 12497,  1051, -1365,
     536, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
    1052, -1365, -1365, -1365,  7866, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365,   638, -1365,  1173,   762, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365,   952, -1365, -1365,
    1177, -1365, -1365, -1365, -1365, -1365,   575,  1179, -1365,   692,
   -1365, -1365, -1365,   900,   269,   911,   325,   912,   913,   837,
   -1365,   536,  8460,   931,   908, -1365,  1045,   329,   986,  1023,
    4599,  1041,  1053,  1071,  1055,  1056, 12781,   285, -1365, 12781,
   -1365,  7866,  1073,  7866,  1092,  7866,    32,  1074,  7866,  1077,
   -1365,  1104,  1105,  7866, 12781,   861,  1148, -1365, -1365, -1365,
   -1365, -1365, -1365, 12213, -1365,  4599,  1000,  1120, -1365, -1365,
   -1365,  1000,  1120, -1365,  7866,  1091,  4599, 12781, -1365, -1365,
    7866,  7866,   623, -1365,    24,   737, -1365, 11361,   743, -1365,
     765, -1365,  1050, -1365, -1365,  4599,  1058,  1059, -1365,  7866,
   -1365, -1365,  1042,  1075,  1141, -1365,  1115, -1365,   619, -1365,
   -1365,  1243, -1365, -1365,  4599, 12781, -1365,   681, -1365, -1365,
   -1365,  1063,  1025,  1031, -1365, -1365, -1365,  1043,  1060, -1365,
   -1365, -1365, -1365, -1365,  1062, 12781,  1069, -1365, -1365,  7866,
    7866,  7866,  4302,  6084,  9351,   947, -1365,  1138,  9351, -1365,
    1098,   388, -1365, -1365, -1365,  1083, -1365,  1000, -1365,   854,
   -1365,    66,  1154, -1365,  7866,  1155,  1018,   514,  1080, -1365,
      47,  1012, -1365, -1365,   267, -1365,   147,   -11,  1016,    47,
     147,  8163, -1365,    44, -1365, -1365, -1365, -1365, -1365, -1365,
      47,  1121,   989,   860,   -11, -1365, -1365,   984,  1195, -1365,
   -1365, -1365, 10509,  1089,  1090,  1094, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,  1247,    -2,
    1248,    -2,  1013,  1176, -1365,  1116, 12781,  1064, -1365, -1365,
    8460, -1365,  1101, -1365, -1365, -1365, -1365, -1365, -1365,  7866,
    1140, -1365, -1365,  7866, -1365,   311, -1365,  7866,  1143,  7866,
   -1365,  7866, 12781, 12781, -1365,   732, -1365,  7866, -1365,  1162,
    1163,  1194,  1000,  1120, -1365,  7866,  1109, -1365, -1365, -1365,
    1108, -1365,    37,  7866,  4599,  1114,    39, -1365, 12781,  1117,
   11645,    15, -1365, 11929,  1118, -1365, -1365,  1112, -1365, -1365,
   -1365,  7866,   776,  1142, 12781,   696, -1365,  1113,  1142, 12781,
   -1365, -1365,  7866,  7866,  7866,  7866,  7866, -1365,  7866,   442,
     451,   459,   574, -1365, 12781, -1365, -1365, -1365, -1365,  1154,
   -1365, -1365, -1365,  1000, -1365, -1365, -1365, -1365, -1365,  1123,
    8163, -1365, -1365, -1365, -1365, -1365,   260,  8163,  8163,   541,
   -1365,   939, -1365,    77, -1365,   949,    47,  1158, -1365, -1365,
    1065, -1365, -1365, -1365, -1365,  1200,  1125, -1365,   461, -1365,
   -1365, -1365, -1365,    48,    48, -1365,    -2, -1365, -1365,   469,
   -1365,  1270,   -11,  1208,  1126,  8460,   -33,  1067,  1144, -1365,
   -1365,  7866, -1365,  7866,  1161, -1365,  7866, -1365, -1365, -1365,
    1260, -1365, -1365,  6084,  7866,  1000, -1365, -1365, -1365,  7866,
    7866, -1365, -1365, -1365,  6084,  6084,  1221,  4599, 12781,  1132,
   12781,  7866, 12781,  1133,  6084, -1365,    55,    34,  1142, 12781,
   -1365,  1124,  1142, -1365, -1365, -1365, -1365, -1365, -1365,  1127,
    1075,  1076,  7866,  1204, -1365,   481, -1365, -1365, -1365,   445,
    8163,  8163,    12,   683, -1365, -1365, -1365, -1365, -1365, -1365,
    7866, -1365, 12213, -1365, 12213,  1230, -1365, -1365, -1365,  1296,
   -1365, -1365, -1365,  1081,  1222, -1365, -1365,  1223, -1365,   797,
   12781,  1210,  1107, 12781,  8460, -1365, -1365,  7866, -1365,  1214,
   -1365, -1365,  1120, -1365, -1365, 12213, -1365, -1365,  1238,  7866,
    1149, -1365,  1241,  6084, -1365, 12781,    95,   502, -1365,  1153,
    1142, -1365,  1156,  6084,   798,   521, 12781,  1220,  1040,    12,
      12,  8163,   534, -1365, -1365, 12213, -1365, -1365,  1208,  8460,
   -1365,  1154,  1078, 12781,  1226,  1129,  1223, -1365, 12781,  1164,
   12213,  4599, 12213,  1165, -1365, -1365,  1245,   387, -1365, -1365,
   -1365, -1365,  1172,   603, -1365, -1365, -1365,  1167, -1365,  1239,
   -1365,   516, 12781, -1365,    12, -1365, -1365, -1365, -1365, -1365,
    7866,  1082, 12781,  1240, -1365,  4599,  1174, -1365, -1365,  1175,
    7866, -1365, -1365, -1365, -1365, -1365, -1365, -1365, 12781,  1246,
    1212,   527, -1365,  1085,  1084, 12781, -1365, -1365,  7866,  6084,
    1180, 12781, -1365,  1249,  1040,  1086,  7866,  1088,  6084,   533,
   12781, -1365,  8460, -1365,  8460,  1250,  1212,  1182, -1365,  1178,
   12781, -1365,  1040,  1093,  1183, -1365, 12781,  1212,  1147, -1365,
    1254, 12781,  1095,  8460, -1365
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       159,   443,   444,   445,   162,   162,   162,   768,   967,   116,
     118,   593,   859,   868,   809,   773,   771,   753,   860,   863,
     816,   777,   754,   755,   808,   869,   757,   866,   838,   818,
     793,   813,   814,   864,   861,   812,   759,   867,   760,   761,
     908,   921,   907,   810,   829,   823,   762,   811,   764,   763,
     909,   847,   815,   790,   931,   932,   933,   934,   935,   936,
     937,   938,   939,   940,   941,   955,   962,   837,   833,   824,
     804,   752,     0,   832,   840,   848,   956,   828,   465,   805,
     806,   862,   957,   963,   825,   842,     0,   471,   432,   467,
     835,   770,   826,   827,   855,   830,   846,   854,   961,   964,
     776,   817,   857,   466,   845,   850,   756,     0,     0,     0,
     380,   843,   853,   858,   856,   836,   822,   910,   820,   821,
     958,     0,   379,     0,   959,   965,   851,   807,   831,   960,
     410,     0,   442,   852,   834,   841,   849,   844,   911,   798,
     803,   802,   801,   800,   799,   765,   819,     0,   769,   865,
     791,   899,   898,   900,   775,   774,   794,   905,   758,   897,
     902,   903,   894,   797,   839,   896,   906,   904,   895,   795,
     901,   913,   916,   917,   914,   915,   912,   766,   918,   919,
     920,   885,   884,   871,   789,   782,   878,   874,   792,   788,
     886,   887,   778,   779,   772,   781,   883,   882,   879,   875,
     892,   893,   891,   881,   877,   870,   780,   890,   889,   784,
     786,   785,   876,   880,   872,   787,   873,   783,   888,   942,
     943,   944,   945,   946,   947,   923,   924,   922,   928,   929,
     930,   925,   926,   927,   796,   948,   949,   950,   951,   952,
     953,   954,   159,     0,     2,   159,     5,     7,    19,     0,
      24,    27,    32,    33,    34,    35,    36,    37,    38,    28,
      54,    55,    29,    30,     0,    72,    75,    76,    31,    77,
      78,     0,   114,    79,    80,    81,    82,    14,   156,   157,
     158,   165,   167,   462,   168,     0,   169,   170,   171,   172,
     173,   174,   175,   178,   163,   209,   216,   211,   238,   244,
       0,   236,   237,   218,   212,   177,   213,   176,   214,   217,
     335,   337,   339,   349,   353,   355,   358,   363,   366,   369,
     371,   373,   375,     0,   377,   383,   385,     0,   401,   384,
     406,   409,   411,   414,   416,     0,   421,   418,     0,   429,
     439,   441,   415,   446,   453,   463,   454,   455,   456,   459,
     460,   457,   458,   478,   480,   481,   482,   479,   527,   528,
     529,   530,   531,   532,   438,   567,   559,   566,   565,   564,
     561,   563,   560,   562,   464,   461,   594,   595,    39,   219,
     220,   222,   221,   223,   215,     0,   440,   751,   767,   859,
     868,   866,   769,     0,   160,   161,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,   124,   125,     0,     0,     0,   162,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   263,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   434,   437,
     424,     0,     0,   748,   753,   777,   755,   808,   869,   757,
     818,   759,   829,   762,   764,   763,   847,   955,   962,   752,
     956,   806,   957,   963,   830,   961,   964,   910,   958,   959,
     965,   960,   911,   905,   897,   903,   894,   795,   913,   916,
     917,   914,   766,   918,   430,   440,   751,   422,     0,   185,
     423,   426,   753,   754,   755,   759,   760,   761,   762,   752,
     758,   468,     0,   428,   427,   180,     0,     0,   757,   764,
     763,     0,   162,   469,   918,     0,   216,     0,   494,     0,
     433,   749,     0,   750,   404,   405,     0,   436,   435,   425,
     408,     0,     0,   523,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     1,     6,     8,     0,     0,     0,     0,
       0,   159,   159,   159,   159,     0,   115,   166,   164,     0,
     183,     0,   194,     0,     0,     0,     0,     0,     0,     0,
       0,   199,   224,   243,   239,   245,   240,   242,   241,     0,
       0,     0,   394,     0,     0,   392,     0,   344,     0,   393,
     386,   391,   390,   389,   388,   387,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   382,   381,   378,     0,   402,   407,
       0,     0,     0,   417,   450,   420,   419,   431,     0,   447,
       0,     0,     0,   534,   536,   540,   593,     0,   120,     0,
      43,    40,    41,    44,    45,     0,     0,     0,     0,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   604,   605,   606,     0,    99,   138,     0,     0,   108,
       0,     0,     0,     0,   123,     0,     0,     0,   573,     0,
       0,     0,   569,     0,     0,     0,   583,     0,     0,   226,
     227,   246,   247,     0,     0,     0,     0,   130,     0,   134,
     162,   597,     0,    56,     0,    65,     0,     0,     0,    57,
       0,     0,     0,     0,     0,   748,   574,     0,     0,     0,
       0,   308,     0,     0,   572,     0,     0,     0,   591,     0,
       0,     0,     0,   577,     0,     0,   189,     0,     0,   181,
     179,     0,     0,     0,   468,     0,   470,     0,   495,   494,
     491,     0,     0,   525,   524,   403,     0,   522,     0,   617,
     618,   568,     0,     0,     0,     0,     0,     0,   623,     0,
     186,     0,   197,   198,     0,     0,     0,     0,     0,   202,
     203,    20,     0,    21,     0,     4,    25,     0,    11,    26,
       0,    15,   859,    73,    12,    74,    16,   187,   184,   210,
       0,     0,     0,     0,   200,   225,   281,   336,   338,   342,
     348,   347,   346,     0,   343,   340,   341,     0,   357,   356,
     354,   360,   361,   362,   359,   364,   365,   368,   367,     0,
       0,     0,     0,   399,     0,   412,   413,     0,   451,   448,
     476,     0,   966,   596,   474,     0,     0,   117,   119,     0,
       0,     0,    98,     0,    88,    90,    91,    92,    93,    95,
      96,    97,    89,    94,    84,    85,     0,     0,   104,     0,
     100,   102,   103,   110,     0,     0,    83,    42,     0,     0,
       0,     0,     0,     0,     0,   698,   703,     0,     0,   699,
     733,   686,   688,   689,   690,   692,   694,   693,   691,   695,
       0,     0,     0,     0,     0,   107,     0,   140,     0,     0,
     539,   533,   570,   571,     0,     0,   587,     0,   584,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   228,
     229,     0,   234,   136,     0,     0,   131,     0,     0,     0,
       0,     0,     0,    58,     0,     0,     0,   262,   268,   265,
       0,   576,   575,   582,   590,     0,     0,     0,     0,   538,
       0,     0,     0,   395,     0,     0,     0,     0,   580,     0,
     578,     0,   190,     0,     0,     0,     0,     0,   494,   492,
       0,   483,     0,   472,   473,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   195,     0,   757,   764,   763,   918,     0,     0,
       0,   634,     0,   204,     0,     0,     0,   159,   159,   159,
       0,   235,     0,   292,   288,   290,     0,   282,   283,   345,
       0,     0,     0,     0,   664,   351,   637,   641,   643,   645,
     647,   650,   657,   658,   666,   869,   756,     0,   765,   370,
     545,   551,   552,   554,   598,   599,   555,   558,   372,   374,
     542,   376,   400,   452,     0,   449,   475,   121,    52,    53,
      50,    51,   127,   126,     0,    86,     0,     0,   105,   106,
     111,    70,    71,    48,    49,    69,   704,     0,   707,   734,
       0,   697,   696,   701,   700,   732,     0,     0,   709,     0,
     705,   708,   687,     0,     0,     0,     0,     0,     0,     0,
     139,   142,     0,     0,     0,   109,   112,     0,     0,     0,
     162,     0,     0,   591,     0,     0,     0,     0,   544,     0,
     249,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     230,     0,     0,     0,     0,   275,     0,   272,   277,   233,
     137,   132,   135,     0,   182,     0,     0,    67,    61,    64,
      63,     0,    59,   266,     0,     0,   162,     0,   306,   310,
       0,     0,     0,   313,     0,     0,   319,     0,     0,   326,
       0,   330,     0,   397,   396,   162,     0,     0,   191,     0,
     193,   307,     0,     0,     0,   495,     0,   484,     0,   518,
     515,     0,   519,   520,     0,     0,   514,     0,   489,   517,
     516,     0,     0,     0,   610,   611,   607,     0,     0,   615,
     616,   612,   621,   619,     0,     0,     0,   625,   196,     0,
       0,     0,     0,     0,     0,   626,   627,     0,     0,   205,
      22,     0,    13,    17,    18,   289,   301,     0,   302,     0,
     293,   294,   295,   296,     0,   285,     0,     0,     0,   648,
     661,     0,   350,   352,     0,   680,     0,     0,     0,     0,
       0,     0,   636,   638,   639,   675,   676,   677,   679,   678,
       0,     0,   652,   651,     0,   655,   659,   673,   671,   670,
     663,   667,     0,     0,     0,     0,   548,   550,   549,   546,
     543,   477,   129,   128,    87,   101,   721,   702,     0,   726,
       0,   726,   715,   710,   143,     0,     0,     0,   113,   141,
       0,    23,     0,   588,   589,   592,   585,   586,   248,     0,
       0,   261,   253,     0,   257,     0,   251,     0,     0,     0,
     270,     0,     0,     0,   232,   273,   276,     0,   133,     0,
       0,    66,     0,    60,   267,     0,     0,   309,   311,   316,
       0,   314,     0,     0,     0,     0,     0,   320,     0,     0,
       0,     0,   327,     0,     0,   331,   398,     0,   581,   579,
     192,     0,     0,   494,     0,     0,   526,     0,   494,     0,
     490,    10,     0,     0,     0,     0,     0,   624,     0,     0,
       0,     0,     0,   628,     0,   635,   305,   303,   304,   297,
     298,   299,   291,     0,   286,   284,   665,   656,   662,     0,
       0,   735,   736,   746,   745,   744,     0,     0,     0,     0,
     737,   642,   743,     0,   640,   644,     0,     0,   649,   653,
       0,   674,   669,   672,   668,     0,     0,   556,     0,   553,
     603,   547,   722,     0,     0,   720,   727,   728,   724,     0,
     719,     0,   717,     0,     0,     0,     0,     0,     0,   535,
     250,     0,   259,     0,     0,   255,     0,   258,   271,   279,
     280,   274,   231,     0,     0,     0,    62,   269,   541,     0,
       0,   317,   321,   315,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   537,     0,     0,   494,     0,
     521,     0,   494,   608,   609,   613,   614,   620,   622,     0,
       0,     0,     0,     0,   629,     0,   300,   287,   660,   747,
       0,     0,   739,     0,   685,   684,   683,   682,   681,   646,
       0,   738,     0,   600,     0,     0,   731,   730,   729,     0,
     723,   716,   714,     0,   711,   712,   706,   144,   146,   148,
       0,     0,     0,     0,     0,   254,   252,     0,   260,     0,
     201,   334,    68,   312,   318,     0,   332,   328,     0,     0,
       0,   322,     0,     0,   324,     0,   504,   498,   493,     0,
     494,   485,     0,     0,     0,     0,     0,     0,     0,   741,
     740,     0,     0,   601,   557,     0,   725,   718,     0,     0,
     150,   149,     0,     0,     0,     0,   145,   256,     0,     0,
       0,     0,     0,     0,   512,   506,     0,   505,   507,   513,
     510,   500,     0,   499,   501,   511,   487,     0,   486,     0,
     633,     0,     0,   206,   742,   654,   602,   713,   147,   151,
       0,     0,     0,     0,   278,     0,     0,   325,   323,     0,
       0,   497,   508,   509,   496,   502,   503,   488,     0,     0,
       0,     0,   152,     0,     0,     0,   333,   329,     0,     0,
       0,     0,   630,     0,     0,     0,     0,     0,     0,     0,
       0,   207,     0,   154,     0,     0,     0,     0,   153,     0,
       0,   631,     0,     0,     0,   208,     0,     0,     0,   632,
       0,     0,     0,     0,   155
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1365, -1365,  -215,  1130, -1365,  1134,  1135, -1365,  1145,  -512,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
    -930, -1365, -1365, -1365, -1365,  -200,  -548, -1365,   695,  -719,
   -1365, -1365, -1365, -1365, -1365,   264,   479, -1365, -1365,    -9,
    -224,  1002, -1365,   969, -1365, -1365,  -597, -1365,   421, -1365,
     242, -1365,  -211,  -248, -1365,  -525, -1365,    13,    33,    18,
    -278,  -177, -1365,  -806, -1365, -1365,  -496, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365,   588,   -99,  1415,
       0, -1365, -1365, -1365, -1365,   433, -1365, -1365,  -290, -1365,
       8, -1365, -1365,   240,  -697,  -663, -1365, -1365,   660, -1365,
   -1365,    30,   234, -1365, -1365, -1365,   118, -1365, -1365,   354,
     127, -1365, -1365,   129, -1219, -1365,   891,   215, -1365, -1365,
     213,  -974, -1365, -1365,   211, -1365, -1365, -1179, -1157, -1365,
     207, -1365, -1365,   809,   810, -1365,  -508, -1365, -1365,  -624,
     353,  -604,   350,   351, -1365, -1365, -1365, -1365, -1365,  1096,
   -1365, -1365, -1365, -1365,  -804,  -316, -1087, -1365,   -89, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365,   -18,  -775, -1365, -1365,
     587,   257, -1365,  -378, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365,   759, -1365,  -966, -1365,   194, -1365,   646,  -754, -1365,
   -1365, -1365, -1365, -1365,  -239,  -231, -1163,  -858, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,   566,  -725,
    -828,   286,  -801, -1365,   132,  -807, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365,  1003,  1007,  -258,   482,   326, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365,   178, -1365, -1365,   170,  -882,   173,  -988, -1365,
   -1365, -1365,   139,   131,   -27,   380, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,   140,
   -1365, -1365, -1365,   -19,   374,   517, -1365, -1365, -1365, -1365,
   -1365,   317, -1365, -1365, -1364, -1365, -1365, -1365,  -488, -1365,
     108, -1365,   -38, -1365, -1365, -1365, -1365, -1215, -1365,   150,
   -1365,  -360,  -351,   892,   201, -1365
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   243,   814,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
    1187,   738,   261,   262,   263,   264,   265,   266,   894,   895,
     896,   267,   268,   269,   900,   901,   902,   270,   418,   271,
     272,   667,   273,   420,   421,   422,   435,   728,   729,   274,
    1140,   275,  1587,  1588,   276,   277,   278,   526,   279,   280,
     281,   282,   283,   731,   284,   285,   509,   286,   287,   288,
     289,   290,   291,   601,   292,   293,   809,   810,   294,   295,
     536,   297,   602,   433,   961,   962,   298,   603,   299,   605,
     537,   301,   721,   722,  1175,   442,   302,   443,   444,   725,
    1176,  1177,  1178,   606,   607,  1057,  1058,  1444,   608,  1054,
    1055,  1280,  1281,  1282,  1283,   303,   750,   751,   304,  1202,
    1203,  1392,   305,  1205,  1206,   306,   307,  1208,  1209,  1210,
    1211,   308,   309,   310,   311,   843,   312,  1292,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     626,   627,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     653,   654,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   871,   352,   353,   354,  1237,   779,   780,   781,  1618,
    1662,  1663,  1656,  1657,  1664,  1658,  1238,  1239,   355,   356,
    1240,   357,   358,   359,   360,   361,   362,   363,  1089,   956,
    1079,  1329,  1080,  1478,  1081,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   757,  1152,   374,   375,   376,
     377,  1083,  1084,  1085,  1086,   378,   379,   380,   381,   382,
     383,   797,   798,   384,  1265,  1266,  1554,  1042,  1065,  1302,
    1303,  1066,  1067,  1068,  1069,  1070,  1312,  1468,  1469,  1071,
    1315,  1072,  1449,  1073,  1074,  1320,  1321,  1474,  1472,  1304,
    1305,  1306,  1307,  1567,   695,   921,   922,   923,   924,   925,
     926,  1130,  1494,  1584,  1131,  1492,  1582,   927,  1341,  1489,
    1485,  1486,  1487,   928,   929,  1308,  1316,  1459,  1309,  1455,
    1293,   385,   542,   386,   387,   388
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -749;
  const short int
  xquery_parser::yytable_[] =
  {
       296,   571,   587,   419,   296,   296,   296,   850,   300,   535,
     604,   648,   300,   300,   300,   976,  1204,   393,   396,   397,
     668,   668,   395,   395,   395,  1010,   954,   988,   851,   852,
     853,   854,  1088,  1041,   582,   823,   825,   394,   394,   394,
     670,  1002,   550,  1063,  1192,  1412,  1236,   586,   579,   584,
    1164,  1402,  1082,  1082,   504,  1345,   818,   821,   824,   826,
     955,   690,  1440,  1441,     9,    10,     9,    10,   800,   816,
     819,   950,   705,  1288,  1420,  1103,   666,   580,   735,   739,
     881,   958,   580,  1590,  1456,   404,   552,   404,   580,   827,
    1082,   783,   580,   828,   405,   747,  1107,  1194,  1028,  1470,
    1654,   463,   580,   839,  1229,   840,   841,   296,   842,   952,
     844,   985,   407,   440,   407,   300,   408,   587,   845,   846,
     580,   580,  1393,  1158,  1141,   527,  1616,   591,   951,  1585,
     952,  1530,  1483,     9,    10,  1393,  1181,  1393,  1127,  1294,
     394,   710,   679,  1338,  1082,   726,   897,   409,   410,  1050,
     701,   951,     9,    10,  1128,    78,  1161,  1082,   711,  1165,
     647,  1290,   565,   400,   401,  1015,   402,   403,   629,    89,
    1277,  1615,   426,   404,   680,  1105,  -748,  1367,  1110,   985,
     953,   588,   405,   406,   123,   123,   630,  1105,   898,  1591,
     454,  1279,   986,   899,   103,   586,  1484,  1129,  1060,  1531,
     407,  1061,  1340,   987,   408,  1093,     9,    10,  1394,   400,
     401,  1295,   402,   403,   727,  1617,  1232,   564,  1233,   463,
    1556,  1520,   123,  1525,  1016,  1029,  1655,  1017,   441,   406,
     734,  1396,  1169,   629,  1021,   409,   410,   411,  1180,  1531,
     959,   649,   296,  1457,  1458,   296,  1234,   604,   455,   587,
     300,   630,  1420,   300,  1226,  1402,   784,  1063,  1063,  1166,
    1004,  1383,  1236,  1498,   581,   823,   825,   553,   441,   583,
    1082,  1236,  1592,   506,  1677,   811,  1324,  1583,   960,   813,
     296,   712,   441,  1271,   412,   441,  1104,   506,   300,  1047,
     585,  1162,   589,  1167,  1296,  1297,   588,  1298,  1333,   816,
     819,   736,  1448,   441,  1062,  1031,   441,  1049,  1270,   872,
     506,  1011,  1560,  1195,  1300,   456,   457,   655,   398,   666,
     657,   834,   506,   415,   506,   702,  1301,  1227,   907,   715,
     412,   416,   591,   703,   591,  1059,   876,   732,   593,   417,
    1141,   586,   594,   413,  1564,   671,   744,   595,   737,  1018,
    1019,  1565,  1098,   755,   756,  1378,  1022,  1023,   672,     9,
      10,  1566,   762,   812,  1020,   596,   876,   945,  1133,  1099,
    1640,  1024,  1624,  1134,   710,   590,  1082,  1012,   973,  1399,
     952,   817,   820,   969,   399,   414,   972,  1561,  1135,   413,
    1136,   711,  1654,  1228,   423,   296,  1229,   947,    78,  1137,
    1082,   951,   965,   300,   591,   685,   952,   686,  1589,   944,
     591,   415,    89,  1453,   776,   458,   877,  1229,  1230,   416,
    1454,  1348,  1679,   427,   296,  1138,   296,   417,   588,   587,
    1359,   414,   300,   685,   300,   686,   591,   103,   687,   709,
     782,   591,   707,   801,   395,   997,   878,   946,   434,  1236,
     296,   449,   786,  1168,   999,   296,  1503,   706,   300,   394,
    1360,   591,   597,   300,   688,   598,  1094,  1402,   707,  1064,
     805,   807,   910,   707,   911,   436,   666,   948,  1094,   447,
     599,  1451,   966,   753,   968,  1100,  1063,   459,   759,  1041,
     990,   591,   688,  1435,  1477,  1063,   591,   591,  1097,   823,
     825,   823,  1101,  1368,   576,   600,  1063,  1589,  1232,  1231,
    1233,  1229,  1242,   980,  1243,  1082,   912,   591,  1692,  1452,
     577,   991,  1272,  1273,  1274,   998,   689,   296,   587,  1232,
    1660,  1233,   296,   593,  1000,   300,   506,   594,  1234,   506,
     300,  1033,   595,   591,  1111,  1112,  1095,   591,   864,  1115,
     395,  1139,  1589,   867,   689,    78,   591,   448,  1096,  1234,
     596,   865,   866,   109,   591,   394,  1574,   419,   591,    89,
     296,  1222,  1529,   996,  1579,  1533,  1396,  1223,   300,  1149,
     121,   296,   296,   296,   296,  1602,  1627,   675,   806,   300,
     300,   300,   300,  1082,   103,   452,  1082,  1224,  1060,   296,
    1235,  1061,  1048,   676,   591,   677,   506,   300,   588,   506,
    1188,  1044,  1229,   506,  1188,   591,   506,   506,   147,   591,
    1013,  1699,   123,  1232,   506,  1233,   591,  1549,  1229,  1230,
     506,  1660,  1713,   506,  1661,  1728,  1550,  1729,  1725,   591,
    1121,   506,   453,   636,  1551,  1014,  1575,   506,   506,   506,
     506,  1122,   637,  1234,  1580,   506,  1744,   597,  1262,  1537,
     598,  1267,  1063,   506,  1541,  1294,  1628,   913,  1504,   632,
    1338,   638,  1005,  1006,  1007,   777,   807,  1463,  1326,   507,
     914,  1040,   915,  1064,  1064,   639,  1339,  1151,  1102,  1154,
    1229,  1230,  1092,   916,   917,   918,  1446,   919,   633,   920,
     600,  1700,   508,  1670,   730,  1229,  1230,   296,  1171,   506,
    1327,   634,  1714,  1172,  1268,   300,  1675,  1045,  1726,   951,
    1231,  1201,   823,   506,  1232,  1552,  1233,  1328,  1553,  1340,
     296,  1173,   506,   577,  1390,  1695,   951,  1295,   300,  1216,
    1232,  1217,  1233,   967,  1633,   635,  1634,   648,   395,   604,
     952,   430,   510,   593,  1234,  1258,   431,   594,  1659,  1665,
     296,   296,   595,   394,   506,  1082,   975,  1082,   300,   300,
    1234,  1174,   424,  1332,   109,   425,   437,  1649,   707,   707,
     596,  1268,  1231,  1001,  1619,  1171,   438,  1127,  1622,   730,
    1172,   121,   511,   994,   995,   561,   673,  1231,  1082,  1659,
     562,   432,  1232,  1128,  1233,  1665,  1038,  1676,  1564,   674,
     522,  1414,   439,   419,  1039,  1565,   539,  1232,  1712,  1233,
    1296,  1297,  1686,  1298,  1689,  1566,  1381,   952,  1082,   147,
    1299,  1188,  1234,  1562,  1563,  1201,   109,   699,   629,   629,
    1300,  1400,   700,  1082,  1731,  1082,  1559,  1234,  1395,  1317,
    1318,   109,  1301,   121,  1401,  1739,   630,   630,   460,  1123,
     571,   506,  1143,  1403,  1641,  1269,  1667,   555,   121,   556,
    1124,  1144,  1319,  1419,  1400,   611,  1404,   597,   631,  1631,
     598,   523,   883,   612,   613,   506,   614,  1536,  1539,   461,
     951,   147,   462,   551,   615,  1263,  1400,   898,   616,   506,
     617,  1277,   899,   506,   506,   618,   147,  1379,  1276,  1669,
     868,   524,  1064,   868,  1171,   540,   868,  1436,  1277,  1172,
     600,  1064,   619,   428,   656,   506,   429,   506,  1278,   659,
     445,   450,  1064,   446,   451,   506,  1629,  1630,   506,  1279,
     554,   558,   506,   559,   547,   620,   621,   622,   623,   624,
     625,   884,   885,   886,   887,   888,   889,   890,   891,   892,
     893,  1287,   650,   651,   505,  1116,  1117,  1118,   691,   692,
     693,  1119,   652,  1247,   658,  1248,  1113,  1114,   521,   506,
    1437,  1438,   848,   849,   548,   834,   855,   856,   549,   857,
     858,   557,   296,  1090,  1090,  1576,  1577,   560,   563,   566,
     300,   538,   567,   569,   568,   573,   570,  1674,   591,   506,
     707,   592,   609,   543,   610,   546,   628,   640,   641,   642,
     660,   643,  1516,   652,   661,  1212,   663,   662,   664,   463,
     665,   506,   681,  1038,   683,   684,   694,   419,   698,   719,
     720,  1039,   708,   724,   730,   733,   741,   296,   296,   296,
     742,   743,   754,   760,   425,   300,   300,   300,   761,   429,
     506,   506,   506,   506,   767,   446,   451,   462,   769,   771,
     772,   773,   778,   775,   785,   788,   787,   802,   803,   791,
     796,   808,   815,  1557,   830,   847,   832,   859,  1064,   860,
     861,   831,   862,   879,   833,   873,   880,   882,   506,   904,
     905,   908,   909,   931,   930,   932,   934,   939,   936,   949,
     940,   941,   506,   964,   970,   971,  1522,   942,   943,   974,
     981,   982,   983,   984,   992,   989,   993,  1025,  1027,  1026,
    1030,  1046,  1052,  1032,  1056,   899,  1106,   506,   951,  1125,
    1126,  1147,  1148,  1156,  1150,  1159,   506,  1157,   506,  1170,
     296,   726,   506,  1163,  1183,  1188,  1184,  1185,   300,  1189,
    1429,  1430,  1431,  1352,  1142,   506,  1186,  1191,   395,  1190,
    1197,  1200,  1196,  1201,  1207,  1220,  1213,  1225,  1219,  1215,
    1214,  1241,  1255,   394,  1259,   296,  1260,  1261,  1284,   687,
    1264,  1262,  1286,   300,  1330,  1310,   296,  1291,   506,  1314,
     506,  1322,   666,  1323,   300,  1325,  1337,  1311,  1342,  1386,
    1350,  1351,  1347,  1355,   395,   296,  1346,  1365,  1363,  1369,
    1372,  1373,  1371,   300,  1377,  1382,  1353,   505,  1407,   394,
     505,  1385,  1406,   395,   296,  1600,  1336,  1411,  1354,  1400,
    1356,  1357,   300,  1408,  1409,  1413,  1604,  1522,   394,  1606,
    1416,  1421,   707,  1428,  1434,  1422,  1614,   506,  1277,  1443,
    1450,  1423,  1038,  1038,  1460,  1447,  1466,  1417,  1471,  1467,
    1039,  1039,  1473,  1424,  1479,  1480,  1482,  1488,   506,  1481,
     806,  1493,  1491,  1499,  1495,  1501,  1513,  1514,  1506,  1515,
    1425,  1518,  1519,  1572,  1535,  1540,  1426,   678,  1524,  1581,
     682,  1527,  1534,  1127,   543,  1558,  1597,   696,   697,  1570,
    1573,  1586,  1594,  1599,  1605,   543,  1609,  1613,  1621,  1497,
    1626,   718,  1623,  1635,   723,  1636,  1643,  1638,  1639,  1644,
    1648,  1650,   740,  1651,  1652,  1606,  1672,  1691,   543,   748,
     749,   752,  1682,  1571,  1637,  1379,   758,  1666,  1685,  1690,
    1668,  1683,  1593,  1694,   765,  1698,  1705,   506,  1708,  1709,
     506,  1697,  1711,  1552,  1718,  1720,  1730,  1732,  1737,  1740,
    1741,  1335,   572,  1687,  1733,   506,  1715,  1108,  1736,   574,
     575,  1680,   906,  1646,   506,  1703,  1182,  1716,   704,  1349,
    1722,  1678,  1724,   578,   296,  1179,  1358,  1043,   506,  1743,
     766,   669,   300,   979,  1445,  1511,  1275,  1706,   506,  1376,
    1439,  1442,  1387,   768,   752,  1391,  1397,  1405,   837,   646,
     838,   875,  1415,   774,  1696,  1009,  1693,  1344,  1091,  1155,
     713,  1706,  1334,  1427,   714,  1433,   506,  1432,  1461,  1569,
    1687,  1465,  1289,  1464,  1568,  1313,  1343,  1132,  1578,  1490,
    1462,  1673,     0,  1625,     0,   799,   506,     0,     0,     0,
       0,     0,     0,     0,     0,   506,     0,     0,     0,   506,
       0,  1632,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1038,     0,     0,     0,     0,     0,     0,
       0,  1039,     0,   506,  1038,  1038,     0,   296,     0,     0,
       0,     0,  1039,  1039,  1038,   300,     0,  1721,     0,     0,
       0,     0,  1039,     0,     0,     0,     0,   506,     0,     0,
       0,     0,   543,     0,     0,  1735,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   506,   506,     0,   903,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     933,     0,     0,     0,   937,   938,     0,     0,     0,   506,
       0,   506,     0,     0,   506,     0,     0,     0,     0,     0,
       0,     0,     0,  1038,     0,   506,   957,     0,   963,     0,
     506,  1039,     0,  1038,     0,     0,   543,     0,     0,   543,
       0,  1039,     0,   977,     0,   506,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   296,     0,     0,     0,     0,     0,     0,     0,   300,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1008,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   296,     0,     0,     0,     0,
       0,     0,     0,   300,     0,     0,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,     0,     0,     0,  1038,
       0,     0,     0,     0,     0,     0,     0,  1039,  1038,     0,
       0,     0,  1051,     0,     0,     0,  1039,     0,     0,   506,
       0,   506,     0,   506,     0,     0,     0,     0,     0,     0,
     506,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1087,  1087,  1087,  1087,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   506,     0,   506,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1087,
       0,   506,     0,     0,   506,     0,     0,     0,     0,     0,
       0,     0,     0,  1120,     0,     0,   506,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   506,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   506,  1146,     0,
       0,     0,     0,     0,     0,     0,   506,  1153,     0,  1153,
       0,     0,     0,  1087,   506,     0,     0,     0,     0,   506,
       0,   506,     0,   506,     0,     0,  1087,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   506,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   506,     0,     0,     0,     0,     0,   758,
       0,   758,     0,     0,     0,     0,     0,     0,     0,   506,
       0,     0,     0,     0,     0,     0,   506,     0,     0,     0,
       0,     0,   506,     0,     0,     0,     0,     0,     0,     0,
       0,   506,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   506,     0,     0,     0,     0,     0,   506,     0,     0,
       0,     0,   506,     0,     0,     0,     0,     0,  1285,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1087,
     789,   790,     0,   792,   793,   794,   795,     0,     0,     0,
       0,     0,     0,   804,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   829,     0,     0,     0,
       0,     0,     0,     0,   835,   836,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   723,     0,
       0,  1361,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1375,     0,     0,     0,
       0,     0,     0,   870,     0,  1087,     0,   870,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   752,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1087,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   935,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1418,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   799,     0,     0,
       0,     0,     0,     0,     0,     0,   505,   978,     0,     0,
     505,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1003,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   835,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1087,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1496,     0,
       0,     0,     0,     0,     0,     0,     0,  1053,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1509,  1510,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1526,     0,  1087,     0,     0,  1087,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1538,     0,     0,     0,
       0,  1542,     0,     0,  1109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1555,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1160,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1198,  1199,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1218,     0,     0,  1221,
    1608,     0,  1610,     0,  1612,     0,     0,     0,     0,     0,
       0,  1620,     0,  1244,  1245,  1246,     0,  1249,  1250,  1251,
    1252,  1253,  1254,     0,  1256,  1257,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1087,     0,  1087,  1053,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1642,     0,     0,  1645,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1087,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1653,     0,  1331,
       0,     0,     0,     0,     0,     0,     0,     0,  1671,     0,
       0,     0,     0,     0,     0,     0,     0,  1087,     0,     0,
       0,     0,     0,     0,     0,  1681,     0,     0,     0,     0,
    1684,     0,  1087,     0,  1087,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1701,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1704,     0,  1362,     0,  1364,     0,
    1366,     0,     0,  1370,     0,     0,     0,     0,  1374,     0,
    1710,     0,     0,     0,     0,     0,     0,  1717,     0,     0,
    1380,     0,     0,  1719,     0,     0,     0,     0,     0,  1384,
       0,     0,  1727,     0,     0,  1388,  1389,     0,     0,     0,
       0,     0,  1734,     0,     0,     0,     0,     0,  1738,     0,
       0,     0,     0,  1742,  1410,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1053,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1500,     0,     0,     0,  1502,     0,
       0,     0,  1505,     0,  1507,     0,  1508,     0,     0,     0,
       0,     0,  1512,     0,     0,     0,     0,     0,     0,     0,
    1517,     0,     0,     0,     0,     0,     0,     0,  1521,  1523,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1380,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1543,  1544,  1545,
    1546,  1547,     0,  1548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1595,     0,  1596,     0,
       0,  1598,     0,     0,     0,     0,     0,     0,     0,  1601,
       0,     0,     0,     0,  1603,  1523,     0,     0,     0,     0,
       0,     0,  1607,     0,     0,     0,  1611,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1647,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1607,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1688,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1702,     0,     0,     0,     0,
    1707,     0,     0,     0,     0,  1688,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1707,     1,     2,     0,     0,     0,     0,
       0,  1723,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,     0,     0,     0,    12,    13,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    76,    77,     0,     0,
       0,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,    89,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,   107,     0,     0,   108,   109,   110,
     111,   112,     0,     0,     0,     0,   113,   114,   115,   116,
     117,   118,   119,   120,     0,   121,     0,   122,   123,     0,
       0,   124,   125,   126,     0,     0,     0,   127,     0,   128,
     129,     0,   130,   131,   132,     0,   133,     0,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,     0,
       0,   145,   146,   147,     0,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,     0,     0,     0,   389,   390,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     391,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,    76,    77,     0,     0,     0,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,    89,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,     0,     0,   108,   109,   110,   111,   112,
       0,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     119,   120,     0,   121,     0,   122,   123,     0,     0,   124,
     125,   126,     0,   525,     0,   127,     0,   128,   129,     0,
     130,   131,   132,     0,   133,     0,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,     0,     0,   145,
     146,   147,     0,   392,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   389,   390,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   391,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,    76,    77,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     0,
      89,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,    95,    96,    97,    98,    99,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,   106,   107,
       0,     0,   108,   109,   110,   111,   112,     0,     0,     0,
       0,   113,   114,   115,   116,   117,   118,   119,   120,     0,
     121,     0,   122,   123,     0,     0,   124,   125,   126,     0,
     770,     0,   127,     0,   128,   129,     0,   130,   131,   132,
       0,   133,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,     0,     0,   145,   146,   147,     0,
     392,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,     0,    11,     0,     0,     0,   389,   390,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,  1034,   391,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,  1035,  1036,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    76,    77,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,   107,     0,     0,   108,
     109,   110,   111,   112,     0,     0,     0,     0,   113,   114,
     115,   116,   117,   118,   119,   120,     0,   121,     0,   122,
     123,     0,     0,   124,   125,   126,     0,   770,     0,   127,
       0,   128,   129,     0,   130,   131,   132,     0,   133,     0,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,     0,     0,   145,   146,   147,     0,   392,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,  1037,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   389,   390,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    1034,   391,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,  1035,  1036,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,    76,    77,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,    89,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,    95,    96,    97,    98,    99,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,   106,   107,     0,     0,   108,   109,   110,   111,
     112,     0,     0,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,     0,   121,     0,   122,   123,     0,     0,
     124,   125,   126,     0,   525,     0,   127,     0,   128,   129,
       0,   130,   131,   132,     0,   133,     0,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,     0,     0,
     145,   146,   147,     0,   392,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,  1037,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,   389,   390,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   391,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,    76,    77,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,    89,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     107,     0,     0,   108,   109,   110,   111,   112,     0,     0,
       0,     0,   113,   114,   115,   116,   117,   118,   119,   120,
       0,   121,     0,   122,   123,     0,     0,   124,   125,   126,
       0,     0,     0,   127,     0,   128,   129,     0,   130,   131,
     132,     0,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,     0,     0,   145,   146,   147,
       0,   392,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,    12,
      13,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,    76,
      77,     0,     0,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     0,     0,     0,    89,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,    95,
      96,    97,    98,    99,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   106,   107,     0,     0,
     108,   109,   110,   111,   112,     0,     0,     0,     0,   113,
     114,   115,   116,   117,   118,   119,   120,     0,   121,     0,
     122,   123,     0,     0,   124,   125,   126,     0,     0,     0,
     127,     0,   128,   129,     0,   130,   131,   132,     0,   133,
       0,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,     0,     0,   145,   146,   147,     0,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,     0,     0,     0,    12,    13,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    76,    77,     0,     0,
       0,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,    89,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,   107,     0,     0,   108,   109,   110,
     111,   112,     0,     0,     0,     0,   113,   114,   115,   116,
     117,   118,   119,   120,     0,   121,     0,   122,   123,     0,
       0,   124,   125,   126,     0,     0,     0,   127,     0,   128,
     129,     0,   130,   131,   132,     0,   133,     0,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,     0,
       0,   145,   146,   147,     0,   392,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,    12,   390,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,    76,    77,     0,     0,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,     0,    89,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,    95,    96,    97,    98,    99,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   107,     0,     0,   108,   109,   110,   111,   112,     0,
       0,     0,     0,   113,   114,   115,   116,   117,   118,   119,
     120,     0,   121,     0,   122,   123,     0,     0,   124,   125,
     126,     0,     0,     0,   127,     0,   128,   129,     0,   130,
     131,   132,     0,   133,     0,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,     0,     0,   145,   146,
     147,     0,   392,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,     0,     0,     0,
     822,   390,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   391,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,   107,     0,
       0,   108,   109,   110,   111,   112,     0,     0,     0,     0,
     113,   114,   115,   116,   117,   118,   119,   120,     0,   121,
       0,   122,   123,     0,     0,   124,   125,   126,     0,     0,
       0,   127,     0,   128,   129,     0,   130,   131,   132,     0,
     133,     0,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,     0,     0,   145,   146,   147,     0,   392,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   389,   390,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,  1034,   391,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,  1035,  1036,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,    76,    77,     0,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,    89,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,    95,    96,    97,
      98,    99,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,   106,   107,     0,     0,   108,   109,
     110,   111,   112,     0,     0,     0,     0,   113,   114,   115,
     116,   117,   118,   119,   120,     0,   121,     0,   122,   123,
       0,     0,   124,   125,   126,     0,     0,     0,   127,     0,
     128,   129,     0,   130,   131,   132,     0,   133,     0,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
       0,     0,   145,   146,   147,     0,   392,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,  1037,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   389,   390,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   528,
     391,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,   529,   530,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,    76,    77,     0,     0,     0,    78,
      79,   481,    81,    82,    83,    84,    85,   531,    87,    88,
       0,     0,     0,    89,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   532,     0,     0,   108,   109,   110,   111,   112,
       0,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     119,   120,     0,   121,     0,   122,   123,     0,     0,   124,
     125,   126,     0,     0,     0,   127,   533,   128,   129,     0,
     130,   131,   132,     0,   133,     0,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,     0,     0,   145,
     146,   147,     0,   392,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   498,   499,   500,   501,
     175,   176,   502,   534,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   389,   390,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   528,   391,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     529,   530,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,    76,    77,     0,     0,     0,    78,    79,   481,    81,
      82,    83,    84,    85,   531,    87,    88,     0,     0,     0,
      89,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,    95,    96,    97,    98,    99,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,   106,   532,
       0,     0,   108,   109,   110,   111,   112,     0,     0,     0,
       0,   113,   114,   115,   116,   117,   118,   119,   120,     0,
     121,     0,   122,   123,     0,     0,   124,   125,   126,     0,
     863,     0,   127,     0,   128,   129,     0,   130,   131,   132,
       0,   133,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,     0,     0,   145,   146,   147,     0,
     392,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   498,   499,   500,   501,   175,   176,   502,
     534,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   389,   390,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   528,   391,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,   529,   530,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    76,    77,
       0,     0,     0,    78,    79,   481,    81,    82,    83,    84,
      85,   531,    87,    88,     0,     0,     0,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,   532,     0,     0,   108,
     109,   110,   111,   112,     0,     0,     0,     0,   113,   114,
     115,   116,   117,   118,   119,   120,     0,   121,     0,   122,
     123,     0,     0,   124,   125,   126,     0,     0,     0,   127,
     869,   128,   129,     0,   130,   131,   132,     0,   133,     0,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,     0,     0,   145,   146,   147,     0,   392,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     498,   499,   500,   501,   175,   176,   502,   534,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   389,   390,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     528,   391,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   529,   530,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,    76,    77,     0,     0,     0,
      78,    79,   481,    81,    82,    83,    84,    85,   531,    87,
      88,     0,     0,     0,    89,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,    95,    96,    97,    98,    99,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,   106,   532,     0,     0,   108,   109,   110,   111,
     112,     0,     0,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,     0,   121,     0,   122,   123,     0,     0,
     124,   125,   126,     0,     0,     0,   127,   874,   128,   129,
       0,   130,   131,   132,     0,   133,     0,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,     0,     0,
     145,   146,   147,     0,   392,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   498,   499,   500,
     501,   175,   176,   502,   534,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   389,   390,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   467,    25,   469,   391,    28,
     470,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,   472,     0,    45,    46,
      47,   474,   475,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,    76,    77,     0,     0,     0,    78,    79,   481,
      81,    82,    83,    84,    85,   531,    87,    88,     0,     0,
       0,    89,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,   484,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     532,     0,     0,   108,   109,   644,   111,   112,     0,     0,
       0,     0,   113,   114,   115,   116,   117,   118,   119,   120,
       0,   121,     0,   645,   123,     0,     0,   124,   125,   126,
       0,     0,     0,   127,     0,   128,   129,     0,   130,   131,
     132,     0,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,     0,     0,   145,   146,   147,
       0,   392,   149,   150,   151,   152,   153,   154,   155,   156,
     493,   158,   494,   160,   495,   496,   163,   164,   165,   166,
     167,   168,   497,   170,   498,   499,   500,   501,   175,   176,
     502,   503,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   389,
     390,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   528,   391,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,   529,   530,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,    76,
      77,     0,     0,     0,    78,    79,   481,    81,    82,    83,
      84,    85,   531,    87,    88,     0,     0,     0,    89,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,    95,
      96,    97,    98,    99,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   106,   532,     0,     0,
     108,   109,   110,   111,   112,     0,     0,     0,     0,   113,
     114,   115,   116,   117,   118,   119,   120,     0,   121,     0,
     122,   123,     0,     0,   124,   125,   126,     0,     0,     0,
     127,     0,   128,   129,     0,   130,   131,   132,     0,   133,
       0,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,     0,     0,   145,   146,   147,     0,   392,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   498,   499,   500,   501,   175,   176,   502,   534,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   389,   390,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   467,
      25,   469,   391,    28,   470,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
     472,     0,    45,    46,    47,   474,   475,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    76,    77,     0,     0,
       0,    78,    79,   481,    81,    82,    83,    84,    85,   531,
      87,    88,     0,     0,     0,    89,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,   484,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,   532,     0,     0,   108,   109,   110,
     111,   112,     0,     0,     0,     0,   113,   114,   115,   116,
     117,   118,   119,   120,     0,   121,     0,   122,   123,     0,
       0,   124,   125,   126,     0,     0,     0,   127,     0,   128,
     129,     0,   130,   131,   132,     0,   133,     0,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,     0,
       0,   145,   146,   147,     0,   392,   149,   150,   151,   152,
     153,   154,   155,   156,   493,   158,   494,   160,   495,   496,
     163,   164,   165,   166,   167,   168,   497,   170,   498,   499,
     500,   501,   175,   176,   502,   503,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   389,   390,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   467,    25,   469,   391,
      28,   470,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   472,     0,    45,
      46,    47,   474,   475,    50,   476,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,    76,    77,     0,     0,     0,    78,    79,
     481,    81,    82,    83,    84,    85,   531,    87,    88,     0,
       0,     0,    89,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,   484,    96,    97,    98,    99,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   532,     0,     0,   108,   109,     0,   111,   112,     0,
       0,     0,     0,   113,   114,   115,   116,   117,   118,   119,
     120,     0,   121,     0,     0,     0,     0,     0,   124,   125,
     126,     0,     0,     0,   127,     0,   128,   129,     0,   130,
     131,   132,     0,   133,     0,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,     0,     0,   145,   146,
     147,     0,   392,   149,   150,   151,   152,   153,   154,   155,
     156,   493,   158,   494,   160,   495,   496,   163,   164,   165,
     166,   167,   168,   497,   170,   498,   499,   500,   501,   175,
     176,   502,   503,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     389,   390,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   467,    25,   469,   391,    28,   470,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   472,     0,    45,    46,    47,   474,
     475,    50,   476,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,   481,    81,    82,
      83,    84,    85,   531,    87,    88,     0,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
     484,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,   532,     0,
       0,   108,   109,     0,   111,   112,     0,     0,     0,     0,
     113,   114,   115,   116,   117,   118,   119,   120,     0,   121,
       0,     0,     0,     0,     0,   124,   125,   126,     0,     0,
       0,   127,     0,   128,   129,     0,     0,     0,   132,     0,
     133,     0,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,     0,     0,   145,   146,   147,     0,   392,
     149,   150,   151,   152,   153,   154,   155,   156,   493,   158,
     494,   160,   495,   496,   163,   164,   165,   166,   167,   168,
     497,   170,   498,   499,   500,   501,   175,   176,   502,   503,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     0,     0,     0,     7,     8,
       0,     0,     0,   463,     0,     0,     0,   389,   390,     0,
      14,    15,    16,   464,    18,    19,    20,   465,    22,   466,
     467,   468,   469,   391,    28,   470,    30,    31,     0,    32,
      33,    34,    35,   471,    37,    38,    39,    40,    41,    42,
      43,   472,     0,    45,   473,    47,   474,   475,    50,   476,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   477,   478,    67,     0,    68,    69,    70,
     479,     0,    73,    74,    75,     0,     0,   480,    77,     0,
       0,     0,     0,    79,   481,    81,   482,   483,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,   484,    96,    97,
     485,   486,     0,     0,     0,     0,     0,     0,   100,   101,
     102,     0,   104,   105,   106,     0,     0,     0,     0,     0,
       0,   111,   112,     0,     0,     0,     0,   113,   114,   115,
     116,   487,   118,   119,   488,     0,     0,     0,     0,     0,
       0,     0,   489,   490,   126,     0,     0,     0,   127,     0,
     128,   491,     0,     0,     0,   132,     0,   133,     0,   134,
     135,   136,   137,   492,   139,   140,   141,   142,   143,   144,
       0,     0,   145,   146,     0,     0,   392,   149,   150,   151,
     152,   153,   154,   155,   156,   493,   158,   494,   160,   495,
     496,   163,   164,   165,   166,   167,   168,   497,   170,   498,
     499,   500,   501,   175,   176,   502,   503,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     0,     0,     7,     8,     0,     0,     0,
     463,     0,     0,     0,   389,   390,     0,    14,    15,    16,
     512,    18,    19,    20,   465,   513,   514,   467,   468,   469,
     391,    28,   470,    30,    31,     0,    32,    33,    34,    35,
     515,    37,   516,   517,    40,    41,    42,    43,   472,     0,
      45,   518,    47,   474,   475,    50,   476,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
     477,   478,    67,     0,    68,    69,    70,   519,     0,    73,
      74,    75,     0,     0,   480,    77,     0,     0,     0,     0,
      79,   481,    81,   482,   483,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,   484,    96,    97,   485,   486,     0,
       0,     0,     0,     0,     0,   100,   101,   102,     0,   104,
     105,   106,     0,     0,     0,     0,     0,     0,   111,   112,
       0,     0,     0,     0,   113,   114,   115,   116,   487,   118,
     119,   488,     0,     0,     0,     0,     0,     0,     0,   489,
     490,   126,     0,     0,     0,   127,     0,   128,   491,     0,
       0,     0,   132,     0,   133,     0,   134,   135,   136,   137,
     492,   139,   140,   141,   142,   143,   144,     0,     0,   145,
     146,     0,     0,   392,   149,   150,   151,   152,   153,   154,
     155,   156,   493,   520,   494,   160,   495,   496,   163,   164,
     165,   166,   167,   168,   497,   170,   498,   499,   500,   501,
     175,   176,   502,   503,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   541,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,   745,     0,     0,     0,   389,   390,     0,    14,
      15,    16,   512,    18,    19,    20,   465,   513,   514,   467,
     468,   469,   391,    28,   470,    30,    31,     0,    32,    33,
      34,    35,   515,    37,   516,   517,    40,    41,    42,    43,
     472,     0,    45,   518,    47,   474,   475,    50,   476,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   477,   478,    67,     0,    68,    69,    70,   519,
       0,    73,    74,    75,     0,     0,   480,    77,     0,     0,
       0,     0,    79,   481,    81,   482,   483,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,   484,    96,    97,   485,
     486,     0,     0,     0,     0,     0,     0,   100,   101,   102,
       0,   104,   105,   106,     0,     0,     0,     0,     0,     0,
     111,   112,     0,     0,     0,     0,   113,   114,   115,   116,
     487,   118,   119,   488,     0,     0,     0,     0,     0,     0,
       0,   489,   490,   126,     0,     0,     0,   127,   746,   128,
     491,     0,     0,     0,     0,     0,   133,     0,   134,   135,
     136,   137,   492,   139,   140,   141,   142,   143,   144,     0,
       0,   145,   146,     0,     0,   392,   149,   150,   151,   152,
     153,   154,   155,   156,   493,   520,   494,   160,   495,   496,
     163,   164,   165,   166,   167,   168,   497,   170,   498,   499,
     500,   501,   175,   176,   502,   503,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   541,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,   463,     0,     0,     0,   389,   390,
       0,    14,    15,    16,   512,    18,    19,    20,   465,   513,
     514,   467,   468,   469,   391,    28,   470,    30,    31,     0,
      32,    33,    34,    35,   515,    37,   516,   517,    40,    41,
      42,    43,   472,     0,    45,   518,    47,   474,   475,    50,
     476,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   477,   478,    67,     0,    68,    69,
      70,   519,     0,    73,    74,    75,     0,     0,   480,    77,
       0,     0,     0,     0,    79,   481,    81,   482,   483,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,   484,    96,
      97,   485,   486,     0,     0,     0,     0,     0,     0,   100,
     101,   102,     0,   104,   105,   106,     0,     0,     0,     0,
       0,     0,   111,   112,     0,     0,     0,     0,   113,   114,
     115,   116,   487,   118,   119,   488,     0,     0,     0,     0,
       0,     0,     0,   489,   490,   126,     0,     0,     0,   127,
       0,   128,   491,     0,     0,     0,     0,     0,   133,     0,
     134,   135,   136,   137,   492,   139,   140,   141,   142,   143,
     144,     0,     0,   145,   146,     0,     0,   392,   149,   150,
     151,   152,   153,   154,   155,   156,   493,   520,   494,   160,
     495,   496,   163,   164,   165,   166,   167,   168,   497,   170,
     498,   499,   500,   501,   175,   176,   502,   503,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   544,   545,     0,     0,     0,     0,     7,
       8,     0,     0,     0,   463,     0,     0,     0,   389,   390,
       0,    14,    15,    16,   512,    18,    19,    20,   465,   513,
     514,   467,   468,   469,   391,    28,   470,    30,    31,     0,
      32,    33,    34,    35,   515,    37,   516,   517,    40,    41,
      42,    43,   472,     0,    45,   518,    47,   474,   475,    50,
     476,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   477,   478,    67,     0,    68,    69,
      70,   519,     0,    73,    74,    75,     0,     0,   480,    77,
       0,     0,     0,     0,    79,   481,    81,   482,   483,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,   484,    96,
      97,   485,   486,     0,     0,     0,     0,     0,     0,   100,
     101,   102,     0,   104,   105,   106,     0,     0,     0,     0,
       0,     0,   111,   112,     0,     0,     0,     0,   113,   114,
     115,   116,   487,   118,   119,   488,     0,     0,     0,     0,
       0,     0,     0,   489,   490,   126,     0,     0,     0,   127,
       0,   128,   491,     0,     0,     0,     0,     0,   133,     0,
     134,   135,   136,   137,   492,   139,   140,   141,   142,   143,
     144,     0,     0,   145,   146,     0,     0,   392,   149,   150,
     151,   152,   153,   154,   155,   156,   493,   520,   494,   160,
     495,   496,   163,   164,   165,   166,   167,   168,   497,   170,
     498,   499,   500,   501,   175,   176,   502,   503,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     7,     8,     0,     0,     0,   463,     0,
       0,     0,   389,   390,     0,    14,    15,    16,   464,    18,
      19,    20,   465,    22,   466,   467,  1075,   469,   391,    28,
     470,    30,    31,     0,    32,    33,    34,    35,   471,    37,
      38,    39,    40,    41,    42,    43,   472,     0,    45,   473,
      47,   474,   475,    50,   476,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   477,   478,
      67,     0,    68,    69,    70,   479,     0,    73,    74,    75,
       0,     0,   480,    77,     0,     0,     0,     0,    79,   481,
      81,   482,   483,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,   484,    96,    97,   485,   486,     0,     0,     0,
       0,     0,     0,   100,   101,   102,     0,   104,   105,  1076,
       0,     0,     0,  1077,     0,     0,   111,   112,     0,     0,
       0,     0,   113,   114,   115,   116,   487,   118,   119,   488,
       0,     0,     0,     0,     0,     0,     0,   489,   490,   126,
       0,     0,     0,   127,  1475,   128,   491,     0,     0,     0,
    1476,     0,   133,     0,   134,   135,   136,   137,   492,   139,
     140,   141,   142,   143,   144,     0,     0,  1078,   146,     0,
       0,   392,   149,   150,   151,   152,   153,   154,   155,   156,
     493,   158,   494,   160,   495,   496,   163,   164,   165,   166,
     167,   168,   497,   170,   498,   499,   500,   501,   175,   176,
     502,   503,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     7,     8,     0,
       0,     0,   463,     0,     0,     0,   389,   390,     0,    14,
      15,    16,   512,    18,    19,    20,   465,   513,   514,   467,
     468,   469,   391,    28,   470,    30,    31,     0,    32,    33,
      34,    35,   515,    37,   516,   517,    40,    41,    42,    43,
     472,     0,    45,   518,    47,   474,   475,    50,   476,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   477,   478,    67,     0,    68,    69,    70,   519,
       0,    73,    74,    75,     0,     0,   480,    77,     0,     0,
       0,     0,    79,   481,    81,   482,   483,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,   484,    96,    97,   485,
     486,     0,     0,     0,     0,     0,     0,   100,   101,   102,
       0,   104,   105,   106,     0,     0,     0,     0,     0,     0,
     111,   112,     0,     0,     0,     0,   113,   114,   115,   116,
     487,   118,   119,   488,     0,     0,     0,     0,     0,     0,
       0,   489,   490,   126,     0,     0,     0,   127,   716,   128,
     491,     0,     0,     0,   717,     0,   133,     0,   134,   135,
     136,   137,   492,   139,   140,   141,   142,   143,   144,     0,
       0,   145,   146,     0,     0,   392,   149,   150,   151,   152,
     153,   154,   155,   156,   493,   520,   494,   160,   495,   496,
     163,   164,   165,   166,   167,   168,   497,   170,   498,   499,
     500,   501,   175,   176,   502,   503,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     7,     8,     0,     0,     0,   463,     0,     0,     0,
     389,   390,     0,    14,    15,    16,   512,    18,    19,    20,
     465,   513,   514,   467,   468,   469,   391,    28,   470,    30,
      31,     0,    32,    33,    34,    35,   515,    37,   516,   517,
      40,    41,    42,    43,   472,     0,    45,   518,    47,   474,
     475,    50,   476,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   477,   478,    67,     0,
      68,    69,    70,   519,     0,    73,    74,    75,     0,     0,
     480,    77,     0,     0,     0,     0,    79,   481,    81,   482,
     483,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
     484,    96,    97,   485,   486,     0,     0,     0,     0,     0,
       0,   100,   101,   102,     0,   104,   105,   106,     0,     0,
       0,     0,     0,     0,   111,   112,     0,     0,     0,     0,
     113,   114,   115,   116,   487,   118,   119,   488,     0,     0,
       0,     0,     0,     0,     0,   489,   490,   126,     0,     0,
       0,   127,   763,   128,   491,     0,     0,     0,   764,     0,
     133,     0,   134,   135,   136,   137,   492,   139,   140,   141,
     142,   143,   144,     0,     0,   145,   146,     0,     0,   392,
     149,   150,   151,   152,   153,   154,   155,   156,   493,   520,
     494,   160,   495,   496,   163,   164,   165,   166,   167,   168,
     497,   170,   498,   499,   500,   501,   175,   176,   502,   503,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     7,     8,     0,     0,     0,
     463,     0,     0,     0,   389,   390,     0,    14,    15,    16,
     464,    18,    19,    20,   465,    22,   466,   467,  1075,   469,
     391,    28,   470,    30,    31,     0,    32,    33,    34,    35,
     471,    37,    38,    39,    40,    41,    42,    43,   472,     0,
      45,   473,    47,   474,   475,    50,   476,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
     477,   478,    67,     0,    68,    69,    70,   479,     0,    73,
      74,    75,     0,     0,   480,    77,     0,     0,     0,     0,
      79,   481,    81,   482,   483,    84,    85,  1398,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,   484,    96,    97,   485,   486,     0,
       0,     0,     0,     0,     0,   100,   101,   102,     0,   104,
     105,  1076,     0,     0,     0,  1077,     0,     0,   111,   112,
       0,     0,     0,     0,   113,   114,   115,   116,   487,   118,
     119,   488,     0,     0,     0,     0,     0,     0,     0,   489,
     490,   126,     0,     0,     0,   127,     0,   128,   491,     0,
       0,     0,     0,     0,   133,     0,   134,   135,   136,   137,
     492,   139,   140,   141,   142,   143,   144,     0,     0,  1078,
     146,     0,     0,   392,   149,   150,   151,   152,   153,   154,
     155,   156,   493,   158,   494,   160,   495,   496,   163,   164,
     165,   166,   167,   168,   497,   170,   498,   499,   500,   501,
     175,   176,   502,   503,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     7,
       8,     0,     0,     0,   463,     0,     0,     0,   389,   390,
       0,    14,    15,    16,   464,    18,    19,    20,   465,    22,
     466,   467,  1075,   469,   391,    28,   470,    30,    31,     0,
      32,    33,    34,    35,   471,    37,    38,    39,    40,    41,
      42,    43,   472,     0,    45,   473,    47,   474,   475,    50,
     476,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   477,   478,    67,     0,    68,    69,
      70,   479,     0,    73,    74,    75,     0,     0,   480,    77,
       0,     0,     0,     0,    79,   481,    81,   482,   483,    84,
      85,  1528,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,   484,    96,
      97,   485,   486,     0,     0,     0,     0,     0,     0,   100,
     101,   102,     0,   104,   105,  1076,     0,     0,     0,  1077,
       0,     0,   111,   112,     0,     0,     0,     0,   113,   114,
     115,   116,   487,   118,   119,   488,     0,     0,     0,     0,
       0,     0,     0,   489,   490,   126,     0,     0,     0,   127,
       0,   128,   491,     0,     0,     0,     0,     0,   133,     0,
     134,   135,   136,   137,   492,   139,   140,   141,   142,   143,
     144,     0,     0,  1078,   146,     0,     0,   392,   149,   150,
     151,   152,   153,   154,   155,   156,   493,   158,   494,   160,
     495,   496,   163,   164,   165,   166,   167,   168,   497,   170,
     498,   499,   500,   501,   175,   176,   502,   503,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     7,     8,     0,     0,     0,   463,     0,
       0,     0,   389,   390,     0,    14,    15,    16,   464,    18,
      19,    20,   465,    22,   466,   467,  1075,   469,   391,    28,
     470,    30,    31,     0,    32,    33,    34,    35,   471,    37,
      38,    39,    40,    41,    42,    43,   472,     0,    45,   473,
      47,   474,   475,    50,   476,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   477,   478,
      67,     0,    68,    69,    70,   479,     0,    73,    74,    75,
       0,     0,   480,    77,     0,     0,     0,     0,    79,   481,
      81,   482,   483,    84,    85,  1532,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,   484,    96,    97,   485,   486,     0,     0,     0,
       0,     0,     0,   100,   101,   102,     0,   104,   105,  1076,
       0,     0,     0,  1077,     0,     0,   111,   112,     0,     0,
       0,     0,   113,   114,   115,   116,   487,   118,   119,   488,
       0,     0,     0,     0,     0,     0,     0,   489,   490,   126,
       0,     0,     0,   127,     0,   128,   491,     0,     0,     0,
       0,     0,   133,     0,   134,   135,   136,   137,   492,   139,
     140,   141,   142,   143,   144,     0,     0,  1078,   146,     0,
       0,   392,   149,   150,   151,   152,   153,   154,   155,   156,
     493,   158,   494,   160,   495,   496,   163,   164,   165,   166,
     167,   168,   497,   170,   498,   499,   500,   501,   175,   176,
     502,   503,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     7,     8,     0,
       0,     0,   463,     0,     0,     0,   389,   390,     0,    14,
      15,    16,   464,    18,    19,    20,   465,    22,   466,   467,
    1075,   469,   391,    28,   470,    30,    31,     0,    32,    33,
      34,    35,   471,    37,    38,    39,    40,    41,    42,    43,
     472,     0,    45,   473,    47,   474,   475,    50,   476,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   477,   478,    67,     0,    68,    69,    70,   479,
       0,    73,    74,    75,     0,     0,   480,    77,     0,     0,
       0,     0,    79,   481,    81,   482,   483,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,   484,    96,    97,   485,
     486,     0,     0,     0,     0,     0,     0,   100,   101,   102,
       0,   104,   105,  1076,     0,     0,     0,  1077,     0,     0,
     111,   112,     0,     0,     0,     0,   113,   114,   115,   116,
     487,   118,   119,   488,     0,     0,     0,     0,     0,     0,
       0,   489,   490,   126,     0,     0,     0,   127,     0,   128,
     491,     0,     0,     0,     0,     0,   133,     0,   134,   135,
     136,   137,   492,   139,   140,   141,   142,   143,   144,     0,
       0,  1078,   146,     0,     0,   392,   149,   150,   151,   152,
     153,   154,   155,   156,   493,   158,   494,   160,   495,   496,
     163,   164,   165,   166,   167,   168,   497,   170,   498,   499,
     500,   501,   175,   176,   502,   503,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     7,     8,     0,     0,     0,   463,     0,     0,     0,
     389,   390,     0,    14,    15,    16,   464,    18,    19,    20,
     465,    22,   466,   467,  1075,   469,   391,    28,   470,    30,
      31,     0,    32,    33,    34,    35,   471,    37,    38,    39,
      40,    41,    42,    43,   472,     0,    45,   473,    47,   474,
     475,    50,   476,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   477,   478,    67,     0,
      68,    69,    70,   479,     0,    73,    74,    75,     0,     0,
     480,    77,     0,     0,     0,     0,    79,   481,    81,   482,
     483,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
     484,    96,    97,   485,   486,     0,     0,     0,     0,     0,
       0,   100,   101,   102,     0,   104,   105,  1076,     0,     0,
       0,  1077,     0,     0,   111,   112,     0,     0,     0,     0,
     113,   114,   115,   116,   487,   118,   119,   488,     0,     0,
       0,     0,     0,     0,     0,   489,   490,   126,     0,     0,
       0,   127,     0,   128,   491,     0,     0,     0,     0,     0,
     133,     0,   134,   135,   136,   137,   492,   139,   140,   141,
     142,   143,   144,     0,     0,   145,   146,     0,     0,   392,
     149,   150,   151,   152,   153,   154,   155,   156,   493,   158,
     494,   160,   495,   496,   163,   164,   165,   166,   167,   168,
     497,   170,   498,   499,   500,   501,   175,   176,   502,   503,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     7,     8,     0,     0,     0,
     463,     0,     0,     0,   389,   390,     0,    14,    15,    16,
     512,    18,    19,    20,   465,   513,   514,   467,   468,   469,
     391,    28,   470,    30,    31,     0,    32,    33,    34,    35,
     515,    37,   516,   517,    40,    41,    42,    43,   472,     0,
      45,   518,    47,   474,   475,    50,   476,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
     477,   478,    67,     0,    68,    69,    70,   519,     0,    73,
      74,    75,     0,     0,   480,    77,     0,     0,     0,     0,
      79,   481,    81,   482,   483,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,   484,    96,    97,   485,   486,     0,
       0,     0,     0,     0,     0,   100,   101,   102,     0,   104,
     105,   106,     0,     0,     0,     0,     0,     0,   111,   112,
       0,     0,     0,     0,   113,   114,   115,   116,   487,   118,
     119,   488,     0,     0,     0,     0,     0,     0,     0,   489,
     490,   126,     0,     0,     0,   127,     0,   128,   491,     0,
       0,     0,     0,     0,   133,     0,   134,   135,   136,   137,
     492,   139,   140,   141,   142,   143,   144,     0,     0,   145,
     146,     0,     0,   392,   149,   150,   151,   152,   153,   154,
     155,   156,   493,   520,   494,   160,   495,   496,   163,   164,
     165,   166,   167,   168,   497,   170,   498,   499,   500,   501,
     175,   176,   502,   503,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     7,
       8,     0,     0,     0,   463,     0,     0,     0,   389,   390,
       0,    14,    15,    16,     0,    18,    19,    20,   465,     0,
       0,   467,   468,     0,   391,    28,   470,    30,    31,     0,
      32,    33,    34,    35,     0,    37,     0,     0,    40,    41,
      42,    43,   472,     0,    45,     0,    47,     0,     0,    50,
     476,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   477,   478,    67,     0,    68,    69,
      70,     0,     0,    73,    74,    75,     0,     0,   480,    77,
       0,     0,     0,     0,    79,   481,    81,   482,   483,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,   484,    96,
      97,   485,   486,     0,     0,     0,     0,     0,     0,   100,
     101,   102,     0,   104,   105,     0,     0,     0,     0,     0,
       0,     0,   111,   112,     0,     0,     0,     0,   113,   114,
     115,   116,   487,   118,   119,   488,     0,     0,     0,     0,
       0,     0,     0,   489,   490,   126,     0,     0,     0,   127,
       0,   128,   491,     0,     0,     0,     0,     0,   133,     0,
     134,   135,   136,   137,   492,   139,   140,   141,   142,   143,
     144,     0,     0,     0,   146,     0,     0,   392,   149,   150,
     151,   152,   153,   154,   155,   156,   493,     0,   494,   160,
     495,   496,   163,   164,   165,   166,   167,   168,   497,   170,
     498,   499,   500,   501,   175,   176,     0,   503,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   178,   280,    12,     4,     5,     6,   631,     0,   108,
     300,   327,     4,     5,     6,   740,   990,     4,     5,     6,
     398,   399,     4,     5,     6,   779,   723,   752,   632,   633,
     634,   635,   860,   808,   249,   583,   584,     4,     5,     6,
     400,   766,   131,   847,   974,  1224,  1012,   271,   248,   264,
      36,  1208,   859,   860,    72,  1142,   581,   582,   583,   584,
     723,   412,  1281,  1282,    26,    27,    26,    27,   564,   581,
     582,    36,   423,  1061,  1237,   881,    29,     1,   438,   439,
     677,    55,     1,   116,    95,    47,    30,    47,     1,   585,
     897,     8,     1,   589,    56,   446,   897,   140,   105,  1314,
       5,    29,     1,   611,     9,   613,   614,   107,   616,    95,
     618,   105,    74,   116,    74,   107,    78,   395,   626,   627,
       1,     1,    98,   951,   931,   107,    92,   105,    93,  1493,
      95,   116,   134,    26,    27,    98,   964,    98,    95,    95,
     107,    45,   167,    95,   951,   116,    93,   109,   110,   111,
     110,    93,    26,    27,   111,   108,   145,   964,    62,   145,
     151,   151,   171,    37,    38,   129,    40,    41,   156,   122,
     104,   116,   151,    47,   199,   894,   119,   145,   903,   105,
     145,   280,    56,    57,   175,   175,   174,   906,   135,   222,
      93,   125,   186,   140,   147,   419,   198,   154,   151,   184,
      74,   154,   154,   145,    78,   183,    26,    27,   184,    37,
      38,   167,    40,    41,   185,   181,   121,   110,   123,    29,
    1439,   184,   175,   184,   188,   232,   131,    93,   271,    57,
     158,  1205,   957,   156,    93,   109,   110,   111,   963,   184,
     214,   330,   242,   254,   255,   245,   151,   537,   151,   527,
     242,   174,  1415,   245,  1008,  1412,   173,  1061,  1062,   956,
     186,  1191,  1228,  1350,   188,   813,   814,   211,   271,   188,
    1077,  1237,   305,    72,  1638,   188,  1077,  1492,   252,   188,
     280,   185,   271,   111,   158,   271,   883,    86,   280,   188,
     110,   954,   105,   956,   250,   251,   395,   253,  1104,   811,
     812,   111,  1290,   271,   257,   801,   271,   188,   188,   660,
     109,   128,    52,   976,   270,   218,   219,   335,   154,    29,
     338,   599,   121,   285,   123,   285,   282,   128,   688,   428,
     158,   293,   105,   293,   105,   843,   105,   436,    42,   301,
    1147,   565,    46,   217,   267,   180,   445,    51,   158,   215,
     216,   274,   146,   452,   453,  1183,   215,   216,   193,    26,
      27,   284,   461,   578,   230,    69,   105,   105,    39,   163,
    1589,   230,  1551,    44,    45,   188,  1183,   194,   738,  1207,
      95,   581,   582,   734,   154,   259,   737,   127,    59,   217,
      61,    62,     5,   194,   158,   395,     9,   105,   108,    70,
    1207,    93,   105,   395,   105,    45,    95,    47,  1495,   182,
     105,   285,   122,   266,   185,   120,   185,     9,    10,   293,
     273,  1146,  1641,   154,   424,    96,   426,   301,   527,   707,
     145,   259,   424,    45,   426,    47,   105,   147,    78,   426,
     539,   105,   424,   110,   426,   105,   185,   185,   154,  1415,
     450,   116,   551,   145,   105,   455,   145,   424,   450,   426,
    1157,   105,   166,   455,   104,   169,   105,  1624,   450,   847,
     569,   570,    54,   455,    56,   154,    29,   185,   105,   154,
     184,   214,   185,   450,   185,   146,  1290,   120,   455,  1264,
     185,   105,   104,  1268,  1322,  1299,   105,   105,   876,  1047,
    1048,  1049,   163,  1166,    33,   209,  1310,  1594,   121,   101,
     123,     9,   229,   182,   231,  1322,    98,   105,   131,   252,
      49,   185,  1047,  1048,  1049,   185,   166,   527,   806,   121,
      28,   123,   532,    42,   185,   527,   335,    46,   151,   338,
     532,   185,    51,   105,   904,   905,   185,   105,   647,   909,
     532,   222,  1639,   652,   166,   108,   105,   154,   185,   151,
      69,   650,   651,   155,   105,   532,   105,   576,   105,   122,
     570,   185,  1400,   182,   105,  1403,  1550,   185,   570,   939,
     172,   581,   582,   583,   584,  1515,   105,   164,   570,   581,
     582,   583,   584,  1400,   147,   154,  1403,   185,   151,   599,
     192,   154,   817,   180,   105,   404,   405,   599,   707,   408,
     970,   811,     9,   412,   974,   105,   415,   416,   210,   105,
     182,   105,   175,   121,   423,   123,   105,   185,     9,    10,
     429,    28,   105,   432,   132,  1722,   185,  1724,   105,   105,
     261,   440,   154,   198,   185,   182,   185,   446,   447,   448,
     449,   272,   207,   151,   185,   454,  1743,   166,   151,  1413,
     169,   154,  1466,   462,  1418,    95,   185,   249,  1365,   115,
      95,   134,   771,   772,   773,   184,   775,  1301,   142,   120,
     262,   182,   264,  1061,  1062,   148,   111,   945,   135,   947,
       9,    10,   182,   275,   276,   277,   182,   279,   144,   281,
     209,   185,   116,   182,   151,     9,    10,   707,    53,   508,
     174,   157,   185,    58,   207,   707,   182,    33,   185,    93,
     101,    98,  1270,   522,   121,   151,   123,   191,   154,   154,
     730,    76,   531,    49,   111,   132,    93,   167,   730,   997,
     121,   999,   123,   730,  1572,   191,  1574,  1063,   730,  1039,
      95,    66,   120,    42,   151,  1033,    71,    46,  1616,  1617,
     760,   761,    51,   730,   563,  1572,   140,  1574,   760,   761,
     151,   116,   151,   135,   155,   154,    24,  1605,   760,   761,
      69,   207,   101,   140,  1538,    53,    34,    95,  1542,   151,
      58,   172,   120,   760,   761,   222,   180,   101,  1605,  1657,
     227,   116,   121,   111,   123,  1663,   806,  1635,   267,   193,
     116,   192,    60,   822,   806,   274,   151,   121,  1700,   123,
     250,   251,  1650,   253,  1652,   284,  1186,    95,  1635,   210,
     260,  1191,   151,  1457,  1458,    98,   155,   135,   156,   156,
     270,    98,   140,  1650,  1726,  1652,  1450,   151,   111,   245,
     246,   155,   282,   172,   111,  1737,   174,   174,   120,   261,
    1037,   660,   297,    98,  1589,  1042,  1620,   222,   172,   224,
     272,   306,   268,   192,    98,   130,   111,   166,   196,   196,
     169,   120,   681,   138,   139,   684,   141,   111,   192,   151,
      93,   210,   154,   151,   149,   184,    98,   135,   153,   698,
     155,   104,   140,   702,   703,   160,   210,  1185,    94,   111,
     653,   120,  1290,   656,    53,   120,   659,  1277,   104,    58,
     209,  1299,   177,   151,   337,   724,   154,   726,   114,   342,
     151,   151,  1310,   154,   154,   734,  1560,  1561,   737,   125,
     213,   222,   741,   224,   120,   200,   201,   202,   203,   204,
     205,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,  1060,   189,   190,    72,   275,   276,   277,   218,   219,
     220,   281,   152,   229,   154,   231,   126,   127,    86,   778,
     126,   127,   629,   630,   120,  1263,   636,   637,   120,   638,
     639,   154,   992,   861,   862,  1483,  1484,   222,   116,   239,
     992,   109,   239,   154,   240,     0,   151,  1631,   105,   808,
     992,   188,   165,   121,    91,   123,   247,    50,   197,    99,
     119,   100,  1382,   152,   143,   992,   182,   154,   182,    29,
     182,   830,    47,  1033,   150,   116,   244,  1046,   302,   282,
     282,  1033,   185,   116,   151,     1,   116,  1047,  1048,  1049,
     140,   105,   185,   151,   154,  1047,  1048,  1049,   151,   154,
     859,   860,   861,   862,   140,   154,   154,   154,   182,   154,
     154,   154,    35,   151,    17,    29,   211,   188,   188,   185,
     228,   243,     3,  1443,   116,    70,   168,   228,  1466,    93,
      93,   166,    93,   105,   168,   147,   105,    29,   897,   158,
     158,   125,   130,    93,   244,   297,   140,   130,   116,   105,
     182,   182,   911,    93,    95,    45,  1394,   185,   185,    95,
     185,   185,   185,   185,   151,   182,   182,    93,   222,   234,
     140,    33,   168,   188,   116,   140,   130,   936,    93,    29,
     284,    93,   297,   116,   151,   116,   945,   125,   947,   252,
    1150,   116,   951,   145,    93,  1515,   182,   195,  1150,   158,
    1259,  1260,  1261,  1150,   224,   964,   130,    95,  1150,   130,
     116,   145,   151,    98,    98,   188,   182,    35,   140,   151,
     182,    29,   116,  1150,   154,  1185,   154,   154,   105,    78,
     243,   151,   105,  1185,   142,   256,  1196,   283,   997,   265,
     999,   154,    29,   154,  1196,   154,    29,   258,    29,  1196,
     224,   188,   304,   142,  1196,  1215,   285,   125,   145,   145,
     116,   116,   145,  1215,    76,   105,   185,   335,  1215,  1196,
     338,   140,   182,  1215,  1234,  1513,   284,   195,   185,    98,
     185,   185,  1234,   185,   185,   130,  1524,  1525,  1215,  1527,
       7,   188,  1234,   184,   116,   230,  1534,  1056,   104,   104,
     248,   230,  1262,  1263,   248,   185,   145,  1234,   284,   280,
    1262,  1263,    77,   230,   185,   185,    29,    29,  1077,   185,
    1262,   105,   269,   182,   168,   145,   124,   124,   145,    95,
     230,   182,   184,    93,   182,   182,   234,   405,   184,    29,
     408,   184,   184,    95,   412,   182,   145,   415,   416,   151,
     185,   185,   168,    53,    93,   423,   184,   184,   194,   255,
     116,   429,   195,    93,   432,    29,   116,   105,   105,   222,
     116,    93,   440,   184,    93,  1613,   116,    92,   446,   447,
     448,   449,   116,   278,   263,  1623,   454,   194,   184,   184,
     194,   222,   285,   181,   462,   116,   116,  1156,   184,   184,
    1159,   194,   116,   151,   184,   116,   116,   185,   185,   222,
     116,  1107,   242,  1651,   196,  1174,   291,   898,   285,   245,
     245,   303,   687,  1594,  1183,   303,   965,   303,   419,  1147,
     304,  1639,   304,   248,  1394,   962,  1156,   809,  1197,   304,
     508,   399,  1394,   743,  1286,  1375,  1052,  1685,  1207,  1175,
    1281,  1284,  1197,   522,   522,  1202,  1205,  1210,   609,   323,
     610,   662,  1228,   531,  1663,   779,  1657,  1141,   862,   947,
     427,  1709,  1106,  1255,   427,  1265,  1235,  1264,  1299,  1466,
    1718,  1310,  1062,  1303,  1463,  1071,  1129,   930,  1486,  1341,
    1300,  1628,    -1,  1552,    -1,   563,  1255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1264,    -1,    -1,    -1,  1268,
      -1,  1570,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1513,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1513,    -1,  1322,  1524,  1525,    -1,  1527,    -1,    -1,
      -1,    -1,  1524,  1525,  1534,  1527,    -1,  1714,    -1,    -1,
      -1,    -1,  1534,    -1,    -1,    -1,    -1,  1346,    -1,    -1,
      -1,    -1,   660,    -1,    -1,  1732,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1372,  1373,    -1,   684,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     698,    -1,    -1,    -1,   702,   703,    -1,    -1,    -1,  1398,
      -1,  1400,    -1,    -1,  1403,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1613,    -1,  1414,   724,    -1,   726,    -1,
    1419,  1613,    -1,  1623,    -1,    -1,   734,    -1,    -1,   737,
      -1,  1623,    -1,   741,    -1,  1434,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1651,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1651,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     778,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1685,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1685,    -1,    -1,    -1,    -1,    -1,    -1,
     808,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1709,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1709,  1718,    -1,
      -1,    -1,   830,    -1,    -1,    -1,  1718,    -1,    -1,  1528,
      -1,  1530,    -1,  1532,    -1,    -1,    -1,    -1,    -1,    -1,
    1539,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   859,   860,   861,   862,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1572,    -1,  1574,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   897,
      -1,  1590,    -1,    -1,  1593,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   911,    -1,    -1,  1605,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1615,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1626,   936,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1635,   945,    -1,   947,
      -1,    -1,    -1,   951,  1643,    -1,    -1,    -1,    -1,  1648,
      -1,  1650,    -1,  1652,    -1,    -1,   964,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1672,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1682,    -1,    -1,    -1,    -1,    -1,   997,
      -1,   999,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1698,
      -1,    -1,    -1,    -1,    -1,    -1,  1705,    -1,    -1,    -1,
      -1,    -1,  1711,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1720,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1730,    -1,    -1,    -1,    -1,    -1,  1736,    -1,    -1,
      -1,    -1,  1741,    -1,    -1,    -1,    -1,    -1,  1056,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1077,
     555,   556,    -1,   558,   559,   560,   561,    -1,    -1,    -1,
      -1,    -1,    -1,   568,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   591,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   599,   600,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1156,    -1,
      -1,  1159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1174,    -1,    -1,    -1,
      -1,    -1,    -1,   658,    -1,  1183,    -1,   662,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1197,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1207,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   700,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1235,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1255,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1264,   742,    -1,    -1,
    1268,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   767,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   777,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1322,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1346,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   832,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1372,  1373,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1398,    -1,  1400,    -1,    -1,  1403,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1414,    -1,    -1,    -1,
      -1,  1419,    -1,    -1,   899,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1434,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   934,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   953,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     975,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   986,   987,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1001,    -1,    -1,  1004,
    1528,    -1,  1530,    -1,  1532,    -1,    -1,    -1,    -1,    -1,
      -1,  1539,    -1,  1018,  1019,  1020,    -1,  1022,  1023,  1024,
    1025,  1026,  1027,    -1,  1029,  1030,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1572,    -1,  1574,  1052,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1590,    -1,    -1,  1593,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1605,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1615,    -1,  1094,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1626,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1635,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1643,    -1,    -1,    -1,    -1,
    1648,    -1,  1650,    -1,  1652,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1672,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1682,    -1,  1161,    -1,  1163,    -1,
    1165,    -1,    -1,  1168,    -1,    -1,    -1,    -1,  1173,    -1,
    1698,    -1,    -1,    -1,    -1,    -1,    -1,  1705,    -1,    -1,
    1185,    -1,    -1,  1711,    -1,    -1,    -1,    -1,    -1,  1194,
      -1,    -1,  1720,    -1,    -1,  1200,  1201,    -1,    -1,    -1,
      -1,    -1,  1730,    -1,    -1,    -1,    -1,    -1,  1736,    -1,
      -1,    -1,    -1,  1741,  1219,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1284,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1359,    -1,    -1,    -1,  1363,    -1,
      -1,    -1,  1367,    -1,  1369,    -1,  1371,    -1,    -1,    -1,
      -1,    -1,  1377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1385,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1393,  1394,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1411,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1422,  1423,  1424,
    1425,  1426,    -1,  1428,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1501,    -1,  1503,    -1,
      -1,  1506,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1514,
      -1,    -1,    -1,    -1,  1519,  1520,    -1,    -1,    -1,    -1,
      -1,    -1,  1527,    -1,    -1,    -1,  1531,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1597,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1609,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1651,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1680,    -1,    -1,    -1,    -1,
    1685,    -1,    -1,    -1,    -1,  1690,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1708,    11,    12,    -1,    -1,    -1,    -1,
      -1,  1716,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,   122,    -1,   124,   125,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,   154,   155,   156,
     157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,   172,    -1,   174,   175,    -1,
      -1,   178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,
     187,    -1,   189,   190,   191,    -1,   193,    -1,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,   208,   209,   210,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      -1,    -1,    -1,   122,    -1,   124,   125,   126,   127,    -1,
     129,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,   172,    -1,   174,   175,    -1,    -1,   178,
     179,   180,    -1,   182,    -1,   184,    -1,   186,   187,    -1,
     189,   190,   191,    -1,   193,    -1,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,   208,
     209,   210,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
      -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
     122,    -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,    -1,
     172,    -1,   174,   175,    -1,    -1,   178,   179,   180,    -1,
     182,    -1,   184,    -1,   186,   187,    -1,   189,   190,   191,
      -1,   193,    -1,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,   208,   209,   210,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,    -1,    -1,   122,    -1,   124,
     125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,   154,
     155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,    -1,   174,
     175,    -1,    -1,   178,   179,   180,    -1,   182,    -1,   184,
      -1,   186,   187,    -1,   189,   190,   191,    -1,   193,    -1,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,   208,   209,   210,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,   122,    -1,   124,   125,   126,   127,
      -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,   172,    -1,   174,   175,    -1,    -1,
     178,   179,   180,    -1,   182,    -1,   184,    -1,   186,   187,
      -1,   189,   190,   191,    -1,   193,    -1,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
     208,   209,   210,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
      -1,   122,    -1,   124,   125,   126,   127,    -1,   129,    -1,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,   154,   155,   156,   157,   158,    -1,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
      -1,   172,    -1,   174,   175,    -1,    -1,   178,   179,   180,
      -1,    -1,    -1,   184,    -1,   186,   187,    -1,   189,   190,
     191,    -1,   193,    -1,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,   208,   209,   210,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,   103,
     104,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,   122,    -1,
     124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,    -1,   172,    -1,
     174,   175,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,
     184,    -1,   186,   187,    -1,   189,   190,   191,    -1,   193,
      -1,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    -1,    -1,   208,   209,   210,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,   122,    -1,   124,   125,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,   154,   155,   156,
     157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,   172,    -1,   174,   175,    -1,
      -1,   178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,
     187,    -1,   189,   190,   191,    -1,   193,    -1,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,   208,   209,   210,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,   122,    -1,   124,   125,   126,   127,    -1,   129,
      -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,   172,    -1,   174,   175,    -1,    -1,   178,   179,
     180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,   189,
     190,   191,    -1,   193,    -1,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,   208,   209,
     210,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,   122,
      -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,   154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,   172,
      -1,   174,   175,    -1,    -1,   178,   179,   180,    -1,    -1,
      -1,   184,    -1,   186,   187,    -1,   189,   190,   191,    -1,
     193,    -1,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,   208,   209,   210,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,    -1,   103,   104,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,   122,    -1,   124,   125,
     126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,    -1,   172,    -1,   174,   175,
      -1,    -1,   178,   179,   180,    -1,    -1,    -1,   184,    -1,
     186,   187,    -1,   189,   190,   191,    -1,   193,    -1,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,   208,   209,   210,    -1,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      -1,    -1,    -1,   122,    -1,   124,   125,   126,   127,    -1,
     129,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,   172,    -1,   174,   175,    -1,    -1,   178,
     179,   180,    -1,    -1,    -1,   184,   185,   186,   187,    -1,
     189,   190,   191,    -1,   193,    -1,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,   208,
     209,   210,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
      -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
     122,    -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,    -1,
     172,    -1,   174,   175,    -1,    -1,   178,   179,   180,    -1,
     182,    -1,   184,    -1,   186,   187,    -1,   189,   190,   191,
      -1,   193,    -1,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,   208,   209,   210,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,    -1,    -1,   122,    -1,   124,
     125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,   154,
     155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,    -1,   174,
     175,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,   184,
     185,   186,   187,    -1,   189,   190,   191,    -1,   193,    -1,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,   208,   209,   210,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,   122,    -1,   124,   125,   126,   127,
      -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,   172,    -1,   174,   175,    -1,    -1,
     178,   179,   180,    -1,    -1,    -1,   184,   185,   186,   187,
      -1,   189,   190,   191,    -1,   193,    -1,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
     208,   209,   210,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
      -1,   122,    -1,   124,   125,   126,   127,    -1,   129,    -1,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,   154,   155,   156,   157,   158,    -1,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
      -1,   172,    -1,   174,   175,    -1,    -1,   178,   179,   180,
      -1,    -1,    -1,   184,    -1,   186,   187,    -1,   189,   190,
     191,    -1,   193,    -1,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,   208,   209,   210,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,   103,
     104,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,   122,    -1,
     124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,    -1,   172,    -1,
     174,   175,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,
     184,    -1,   186,   187,    -1,   189,   190,   191,    -1,   193,
      -1,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    -1,    -1,   208,   209,   210,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,   122,    -1,   124,   125,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,   154,   155,   156,
     157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,   172,    -1,   174,   175,    -1,
      -1,   178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,
     187,    -1,   189,   190,   191,    -1,   193,    -1,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,   208,   209,   210,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,   122,    -1,   124,   125,   126,   127,    -1,   129,
      -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,   154,   155,    -1,   157,   158,    -1,
      -1,    -1,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,   172,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,   189,
     190,   191,    -1,   193,    -1,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,   208,   209,
     210,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,   122,
      -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,   154,   155,    -1,   157,   158,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,   172,
      -1,    -1,    -1,    -1,    -1,   178,   179,   180,    -1,    -1,
      -1,   184,    -1,   186,   187,    -1,    -1,    -1,   191,    -1,
     193,    -1,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,   208,   209,   210,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      96,    -1,    98,    99,   100,    -1,    -1,   103,   104,    -1,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,
     126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,    -1,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   178,   179,   180,    -1,    -1,    -1,   184,    -1,
     186,   187,    -1,    -1,    -1,   191,    -1,   193,    -1,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,   208,   209,    -1,    -1,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    95,    96,    -1,    98,
      99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,
     129,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,   148,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,
      -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,
     179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,
      -1,    -1,   191,    -1,   193,    -1,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,   208,
     209,    -1,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    96,
      -1,    98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
      -1,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   178,   179,   180,    -1,    -1,    -1,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,   208,   209,    -1,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    -1,    98,    99,   100,    -1,    -1,   103,   104,
      -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,    -1,   148,   149,   150,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   158,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,   184,
      -1,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,   208,   209,    -1,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    18,    19,    -1,    -1,    -1,    -1,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    -1,    98,    99,   100,    -1,    -1,   103,   104,
      -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,    -1,   148,   149,   150,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   158,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,   184,
      -1,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,   208,   209,    -1,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    95,    96,    -1,    98,    99,   100,
      -1,    -1,   103,   104,    -1,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,    -1,   129,    -1,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,    -1,   148,   149,   150,
      -1,    -1,    -1,   154,    -1,    -1,   157,   158,    -1,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,
      -1,    -1,    -1,   184,   185,   186,   187,    -1,    -1,    -1,
     191,    -1,   193,    -1,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,   208,   209,    -1,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    96,
      -1,    98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
      -1,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   178,   179,   180,    -1,    -1,    -1,   184,   185,   186,
     187,    -1,    -1,    -1,   191,    -1,   193,    -1,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,   208,   209,    -1,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    95,    96,    -1,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,    -1,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   158,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   178,   179,   180,    -1,    -1,
      -1,   184,   185,   186,   187,    -1,    -1,    -1,   191,    -1,
     193,    -1,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,   208,   209,    -1,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    95,    96,    -1,    98,
      99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,
     129,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,   148,
     149,   150,    -1,    -1,    -1,   154,    -1,    -1,   157,   158,
      -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,
     179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,   208,
     209,    -1,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    -1,    98,    99,   100,    -1,    -1,   103,   104,
      -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,    -1,   148,   149,   150,    -1,    -1,    -1,   154,
      -1,    -1,   157,   158,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,   184,
      -1,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,   208,   209,    -1,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    95,    96,    -1,    98,    99,   100,
      -1,    -1,   103,   104,    -1,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,    -1,   129,    -1,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,    -1,   148,   149,   150,
      -1,    -1,    -1,   154,    -1,    -1,   157,   158,    -1,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,
      -1,    -1,    -1,   184,    -1,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,   208,   209,    -1,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    96,
      -1,    98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
      -1,   148,   149,   150,    -1,    -1,    -1,   154,    -1,    -1,
     157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,   208,   209,    -1,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    95,    96,    -1,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,    -1,   148,   149,   150,    -1,    -1,
      -1,   154,    -1,    -1,   157,   158,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   178,   179,   180,    -1,    -1,
      -1,   184,    -1,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,   208,   209,    -1,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    95,    96,    -1,    98,
      99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,
     129,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,   148,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,
      -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,
     179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,   208,
     209,    -1,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    -1,    40,    41,    42,    43,    -1,
      -1,    46,    47,    -1,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    -1,    60,    -1,    -1,    63,    64,
      65,    66,    67,    -1,    69,    -1,    71,    -1,    -1,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    -1,    -1,    98,    99,   100,    -1,    -1,   103,   104,
      -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,    -1,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   158,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,   184,
      -1,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,   209,    -1,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,    -1,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
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
      84,    85,    86,    87,    88,    89,    90,    91,    93,    94,
      95,    96,    97,    98,    99,   100,   103,   104,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   122,
     124,   125,   126,   127,   129,   133,   134,   135,   136,   137,
     144,   145,   146,   147,   148,   149,   150,   151,   154,   155,
     156,   157,   158,   163,   164,   165,   166,   167,   168,   169,
     170,   172,   174,   175,   178,   179,   180,   184,   186,   187,
     189,   190,   191,   193,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   208,   209,   210,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   257,   258,   259,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   323,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   344,   345,   346,   347,   348,   349,   353,   354,   355,
     359,   361,   362,   364,   371,   373,   376,   377,   378,   380,
     381,   382,   383,   384,   386,   387,   389,   390,   391,   392,
     393,   394,   396,   397,   400,   401,   402,   403,   408,   410,
     412,   413,   418,   437,   440,   444,   447,   448,   453,   454,
     455,   456,   458,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   504,   505,   506,   520,   521,   523,   524,   525,
     526,   527,   528,   529,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   549,   550,   551,   552,   557,   558,
     559,   560,   561,   562,   565,   623,   625,   626,   627,    33,
      34,    49,   212,   379,   380,   381,   379,   379,   154,   154,
      37,    38,    40,    41,    47,    56,    57,    74,    78,   109,
     110,   111,   158,   217,   259,   285,   293,   301,   360,   361,
     365,   366,   367,   158,   151,   154,   151,   154,   151,   154,
      66,    71,   116,   405,   154,   368,   154,    24,    34,    60,
     116,   271,   417,   419,   420,   151,   154,   154,   154,   116,
     151,   154,   154,   154,    93,   151,   218,   219,   120,   120,
     120,   151,   154,    29,    39,    43,    45,    46,    47,    48,
      51,    59,    67,    70,    72,    73,    75,    89,    90,    96,
     103,   110,   112,   113,   133,   136,   137,   167,   170,   178,
     179,   187,   199,   221,   223,   225,   226,   233,   235,   236,
     237,   238,   241,   242,   488,   625,   626,   120,   116,   388,
     120,   120,    39,    44,    45,    59,    61,    62,    70,    96,
     222,   625,   116,   120,   120,   182,   379,   381,    48,    72,
      73,   116,   151,   185,   242,   400,   402,   412,   625,   151,
     120,    16,   624,   625,    18,    19,   625,   120,   120,   120,
     480,   151,    30,   211,   213,   222,   224,   154,   222,   224,
     222,   222,   227,   116,   110,   361,   239,   239,   240,   154,
     151,   383,   325,     0,   327,   328,    33,    49,   330,   347,
       1,   188,   324,   188,   324,   110,   362,   382,   400,   105,
     188,   105,   188,    42,    46,    51,    69,   166,   169,   184,
     209,   395,   404,   409,   410,   411,   425,   426,   430,   165,
      91,   130,   138,   139,   141,   149,   153,   155,   160,   177,
     200,   201,   202,   203,   204,   205,   472,   473,   247,   156,
     174,   196,   115,   144,   157,   191,   198,   207,   134,   148,
      50,   197,    99,   100,   156,   174,   471,   151,   477,   480,
     189,   190,   152,   492,   493,   488,   492,   488,   154,   492,
     119,   143,   154,   182,   182,   182,    29,   363,   495,   363,
     623,   180,   193,   180,   193,   164,   180,   626,   625,   167,
     199,    47,   625,   150,   116,    45,    47,    78,   104,   166,
     624,   218,   219,   220,   244,   596,   625,   625,   302,   135,
     140,   110,   285,   293,   365,   624,   380,   381,   185,   379,
      45,    62,   185,   545,   546,   400,   185,   191,   625,   282,
     282,   414,   415,   625,   116,   421,   116,   185,   369,   370,
     151,   385,   400,     1,   158,   623,   111,   158,   343,   623,
     625,   116,   140,   105,   400,    29,   185,   624,   625,   625,
     438,   439,   625,   380,   185,   400,   400,   547,   625,   380,
     151,   151,   400,   185,   191,   625,   625,   140,   438,   182,
     182,   154,   154,   154,   625,   151,   185,   184,    35,   508,
     509,   510,   400,     8,   173,    17,   400,   211,    29,   401,
     401,   185,   401,   401,   401,   401,   228,   563,   564,   625,
     388,   110,   188,   188,   401,   400,   381,   400,   243,   398,
     399,   188,   324,   188,   324,     3,   331,   347,   377,   331,
     347,   377,    33,   348,   377,   348,   377,   388,   388,   401,
     116,   166,   168,   168,   382,   401,   401,   455,   456,   458,
     458,   458,   458,   457,   458,   458,   458,    70,   462,   462,
     461,   463,   463,   463,   463,   464,   464,   465,   465,   228,
      93,    93,    93,   182,   400,   480,   480,   400,   493,   185,
     401,   503,   624,   147,   185,   503,   105,   185,   185,   105,
     105,   368,    29,   626,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,   350,   351,   352,    93,   135,   140,
     356,   357,   358,   625,   158,   158,   350,   623,   125,   130,
      54,    56,    98,   249,   262,   264,   275,   276,   277,   279,
     281,   597,   598,   599,   600,   601,   602,   609,   615,   616,
     244,    93,   297,   625,   140,   401,   116,   625,   625,   130,
     182,   182,   185,   185,   182,   105,   185,   105,   185,   105,
      36,    93,    95,   145,   416,   417,   531,   625,    55,   214,
     252,   406,   407,   625,    93,   105,   185,   379,   185,   624,
      95,    45,   624,   623,    95,   140,   531,   625,   401,   420,
     182,   185,   185,   185,   185,   105,   186,   145,   531,   182,
     185,   185,   151,   182,   380,   380,   182,   105,   185,   105,
     185,   140,   531,   401,   186,   400,   400,   400,   625,   509,
     510,   128,   194,   182,   182,   129,   188,    93,   215,   216,
     230,    93,   215,   216,   230,    93,   234,   222,   105,   232,
     140,   388,   188,   185,    48,    72,    73,   242,   402,   412,
     182,   489,   569,   399,   347,    33,    33,   188,   324,   188,
     111,   625,   168,   401,   431,   432,   116,   427,   428,   458,
     151,   154,   257,   476,   495,   570,   573,   574,   575,   576,
     577,   581,   583,   585,   586,    47,   150,   154,   208,   532,
     534,   536,   537,   553,   554,   555,   556,   625,   532,   530,
     536,   530,   182,   183,   105,   185,   185,   495,   146,   163,
     146,   163,   135,   385,   368,   351,   130,   534,   358,   401,
     531,   623,   623,   126,   127,   623,   275,   276,   277,   281,
     625,   261,   272,   261,   272,    29,   284,    95,   111,   154,
     603,   606,   597,    39,    44,    59,    61,    70,    96,   222,
     372,   537,   224,   297,   306,   401,   625,    93,   297,   623,
     151,   547,   548,   625,   547,   548,   116,   125,   532,   116,
     401,   145,   417,   145,    36,   145,   416,   417,   145,   531,
     252,    53,    58,    76,   116,   416,   422,   423,   424,   407,
     531,   532,   370,    93,   182,   195,   130,   342,   623,   158,
     130,    95,   342,   401,   140,   417,   151,   116,   401,   401,
     145,    98,   441,   442,   443,   445,   446,    98,   449,   450,
     451,   452,   380,   182,   182,   151,   547,   547,   401,   140,
     188,   401,   185,   185,   185,    35,   510,   128,   194,     9,
      10,   101,   121,   123,   151,   192,   505,   507,   518,   519,
     522,    29,   229,   231,   401,   401,   401,   229,   231,   401,
     401,   401,   401,   401,   401,   116,   401,   401,   382,   154,
     154,   154,   151,   184,   243,   566,   567,   154,   207,   383,
     188,   111,   377,   377,   377,   431,    94,   104,   114,   125,
     433,   434,   435,   436,   105,   625,   105,   400,   570,   577,
     151,   283,   459,   622,    95,   167,   250,   251,   253,   260,
     270,   282,   571,   572,   591,   592,   593,   594,   617,   620,
     256,   258,   578,   596,   265,   582,   618,   245,   246,   268,
     587,   588,   154,   154,   534,   154,   142,   174,   191,   533,
     142,   401,   135,   385,   549,   357,   284,    29,    95,   111,
     154,   610,    29,   603,   533,   478,   285,   304,   531,   372,
     224,   188,   379,   185,   185,   142,   185,   185,   415,   145,
     416,   625,   401,   145,   401,   125,   401,   145,   417,   145,
     401,   145,   116,   116,   401,   625,   424,    76,   532,   382,
     401,   623,   105,   342,   401,   140,   379,   439,   401,   401,
     111,   442,   443,    98,   184,   111,   443,   446,   116,   532,
      98,   111,   450,    98,   111,   452,   182,   379,   185,   185,
     401,   195,   449,   130,   192,   507,     7,   380,   625,   192,
     518,   188,   230,   230,   230,   230,   234,   564,   184,   400,
     400,   400,   569,   567,   116,   489,   623,   126,   127,   435,
     436,   436,   432,   104,   429,   428,   182,   185,   570,   584,
     248,   214,   252,   266,   273,   621,    95,   254,   255,   619,
     248,   574,   621,   461,   591,   575,   145,   280,   579,   580,
     619,   284,   590,    77,   589,   185,   191,   532,   535,   185,
     185,   185,    29,   134,   198,   612,   613,   614,    29,   611,
     612,   269,   607,   105,   604,   168,   625,   255,   478,   182,
     401,   145,   401,   145,   416,   401,   145,   401,   401,   625,
     625,   423,   401,   124,   124,    95,   623,   401,   182,   184,
     184,   401,   382,   401,   184,   184,   625,   184,   116,   532,
     116,   184,   116,   532,   184,   182,   111,   510,   625,   192,
     182,   510,   625,   401,   401,   401,   401,   401,   401,   185,
     185,   185,   151,   154,   568,   625,   436,   623,   182,   463,
      52,   127,   461,   461,   267,   274,   284,   595,   595,   576,
     151,   278,    93,   185,   105,   185,   610,   610,   614,   105,
     185,    29,   608,   619,   605,   606,   185,   374,   375,   478,
     116,   222,   305,   285,   168,   401,   401,   145,   401,    53,
     382,   401,   342,   401,   382,    93,   382,   401,   625,   184,
     625,   401,   625,   184,   382,   116,    92,   181,   511,   510,
     625,   194,   510,   195,   449,   400,   116,   105,   185,   461,
     461,   196,   400,   532,   532,    93,    29,   263,   105,   105,
     436,   531,   625,   116,   222,   625,   374,   401,   116,   532,
      93,   184,    93,   625,     5,   131,   514,   515,   517,   519,
      28,   132,   512,   513,   516,   519,   194,   510,   194,   111,
     182,   625,   116,   383,   461,   182,   532,   606,   375,   436,
     303,   625,   116,   222,   625,   184,   532,   382,   401,   532,
     184,    92,   131,   517,   181,   132,   516,   194,   116,   105,
     185,   625,   401,   303,   625,   116,   382,   401,   184,   184,
     625,   116,   568,   105,   185,   291,   303,   625,   184,   625,
     116,   383,   304,   401,   304,   105,   185,   625,   478,   478,
     116,   568,   185,   196,   625,   383,   285,   185,   625,   568,
     222,   116,   625,   304,   478
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
     575,   576
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   322,   323,   323,   324,   325,   325,   325,   325,   326,
     326,   327,   327,   327,   327,   327,   327,   327,   327,   328,
     328,   328,   328,   329,   330,   330,   330,   331,   331,   331,
     331,   331,   332,   332,   332,   332,   332,   332,   332,   332,
     333,   333,   334,   335,   336,   336,   337,   337,   338,   338,
     339,   339,   339,   339,   340,   340,   340,   341,   341,   341,
     341,   342,   342,   343,   343,   344,   344,   344,   344,   345,
     346,   346,   347,   347,   347,   348,   348,   348,   348,   348,
     348,   348,   348,   349,   349,   350,   350,   351,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   353,   354,
     355,   356,   356,   357,   357,   357,   358,   359,   359,   359,
     360,   360,   360,   360,   361,   361,   362,   362,   362,   362,
     363,   363,   364,   364,   365,   365,   366,   366,   367,   367,
     368,   368,   368,   368,   369,   369,   370,   370,   371,   371,
     371,   371,   372,   372,   373,   373,   374,   374,   375,   375,
     375,   375,   376,   376,   376,   376,   377,   378,   378,   378,
     379,   379,   379,   380,   380,   381,   381,   382,   382,   382,
     382,   382,   382,   382,   382,   382,   382,   382,   382,   383,
     383,   384,   385,   386,   387,   387,   387,   387,   387,   388,
     388,   388,   388,   389,   390,   391,   392,   393,   393,   394,
     395,   396,   397,   398,   398,   399,   399,   399,   399,   400,
     400,   401,   401,   401,   401,   401,   401,   402,   402,   402,
     402,   402,   402,   402,   403,   404,   405,   405,   406,   406,
     406,   407,   407,   408,   408,   409,   410,   410,   410,   411,
     411,   411,   411,   411,   412,   412,   413,   414,   414,   415,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   416,   417,   418,   419,   419,   420,   420,   420,   420,
     421,   421,   422,   422,   422,   423,   423,   423,   424,   424,
     424,   425,   426,   427,   427,   428,   428,   429,   430,   430,
     431,   431,   432,   432,   433,   433,   433,   433,   433,   433,
     433,   434,   434,   435,   435,   436,   437,   437,   438,   438,
     439,   439,   440,   441,   441,   442,   443,   443,   444,   445,
     445,   446,   447,   447,   448,   448,   449,   449,   450,   450,
     451,   451,   452,   452,   453,   454,   454,   455,   455,   456,
     456,   456,   456,   456,   457,   456,   456,   456,   456,   458,
     458,   459,   459,   460,   460,   461,   461,   461,   462,   462,
     462,   462,   462,   463,   463,   463,   464,   464,   464,   465,
     465,   466,   466,   467,   467,   468,   468,   469,   469,   470,
     470,   470,   470,   471,   471,   471,   472,   472,   472,   472,
     472,   472,   473,   473,   473,   474,   474,   474,   474,   475,
     475,   476,   476,   477,   477,   477,   478,   478,   478,   478,
     479,   480,   480,   480,   481,   481,   482,   482,   482,   482,
     483,   483,   484,   484,   484,   484,   484,   484,   484,   485,
     485,   486,   486,   487,   487,   487,   487,   487,   488,   488,
     489,   489,   490,   490,   490,   490,   491,   491,   491,   491,
     492,   492,   493,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   495,   495,   496,   496,   496,   497,   498,
     498,   499,   500,   501,   502,   502,   503,   503,   504,   504,
     505,   505,   505,   506,   506,   506,   506,   506,   506,   507,
     507,   508,   508,   509,   510,   510,   511,   511,   512,   512,
     513,   513,   513,   513,   514,   514,   515,   515,   515,   515,
     516,   516,   517,   517,   518,   518,   518,   518,   519,   519,
     519,   519,   520,   520,   521,   521,   522,   523,   523,   523,
     523,   523,   523,   524,   525,   525,   526,   526,   527,   528,
     529,   529,   530,   530,   531,   532,   532,   532,   533,   533,
     533,   534,   534,   534,   534,   534,   535,   535,   536,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   538,   539,
     539,   539,   540,   541,   542,   542,   542,   543,   543,   543,
     543,   543,   544,   545,   545,   545,   545,   545,   545,   545,
     546,   547,   548,   549,   550,   550,   551,   552,   553,   553,
     554,   555,   555,   556,   557,   557,   557,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   559,   559,   560,
     560,   561,   562,   563,   563,   564,   565,   566,   566,   567,
     567,   567,   567,   568,   569,   569,   570,   571,   571,   572,
     572,   573,   573,   574,   574,   575,   575,   576,   576,   577,
     578,   578,   579,   579,   580,   581,   581,   581,   582,   582,
     583,   584,   584,   585,   586,   586,   587,   587,   588,   588,
     588,   589,   589,   590,   590,   591,   591,   591,   591,   591,
     592,   593,   594,   595,   595,   595,   596,   596,   597,   597,
     597,   597,   597,   597,   597,   597,   598,   598,   598,   598,
     599,   599,   600,   601,   601,   602,   602,   602,   603,   603,
     604,   604,   605,   605,   606,   607,   607,   608,   608,   609,
     609,   609,   610,   610,   611,   611,   612,   612,   613,   613,
     614,   614,   615,   616,   616,   617,   617,   617,   618,   619,
     619,   619,   619,   620,   620,   621,   621,   622,   623,   624,
     624,   625,   625,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   627,   627
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
       2,     3,     3,     2,     3,     2,     3,     3,     4,     2,
       3,     4,     5,     5,     2,     4,     5,     3,     3,     2,
       2,     8,     3,     1,     2,     3,     7,    10,    13,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
       5,     0,     1,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       4,     1,     4,     1,     4,     1,     4,     1,     2,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     5,     5,     6,     3,
       4,     1,     2,     3,     2,     2,     1,     2,     2,     1,
       1,     1,     3,     3,     1,     1,     1,     2,     1,     2,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     1,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     4,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     1,     4,     4,     3,     4,     1,     3,     1,     1,
       1,     1,     1,     4,     5,     8,     9,     9,    10,     1,
       2,     1,     2,     6,     0,     1,     3,     3,     0,     1,
       1,     1,     2,     2,     0,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     2,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     4,     3,     7,     3,     7,     4,     4,
       3,     7,     1,     2,     2,     1,     2,     3,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       4,     4,     3,     3,     3,     4,     4,     3,     4,     6,
       4,     6,     4,     3,     4,     6,     6,     4,     6,     6,
       4,     1,     2,     1,     1,     1,     3,     3,     1,     1,
       4,     5,     6,     3,     3,     3,     3,     5,     7,     7,
       5,     5,     5,     7,     7,     5,     5,     3,     3,     5,
       7,     5,     7,     1,     4,     3,     5,     1,     2,     3,
       7,    10,    13,     3,     1,     3,     2,     0,     1,     1,
       2,     1,     3,     1,     3,     1,     4,     1,     2,     3,
       0,     1,     0,     1,     4,     2,     3,     1,     0,     1,
       4,     0,     1,     2,     1,     3,     0,     1,     2,     2,
       1,     0,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       2,     2,     3,     1,     2,     2,     5,     2,     1,     1,
       0,     2,     1,     3,     4,     0,     2,     0,     2,     4,
       4,     3,     2,     3,     1,     3,     0,     1,     1,     2,
       2,     2,     2,     1,     2,     2,     2,     2,     3,     2,
       3,     3,     4,     2,     2,     1,     1,     3,     1,     1,
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
       1,     1,     1,     1,     1,     1,     3,     1
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
  "\"'updating'\"", "\"'validate'\"", "\"'when'\"", "\"'word'\"",
  "\"'decimal-format'\"", "\"'decimal-separator'\"",
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
  "\"'copy'\"", "\"'with'\"", "\"'local'\"", "\"'break'\"",
  "\"'continue'\"", "\"'exit'\"", "\"'loop'\"", "\"'returning'\"",
  "\"'while'\"", "\"'try'\"", "\"'catch'\"", "\"'using'\"", "\"'all'\"",
  "\"'any'\"", "\"'contains'\"", "\"'content'\"", "\"'diacritics'\"",
  "\"'different'\"", "\"'distance'\"", "\"'end'\"", "\"'entire'\"",
  "\"'exactly'\"", "\"'from'\"", "\"'ftand'\"", "\"'ftnot'\"", "\"'not'\"",
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
  "\"'keys'\"", "\"'BOM_UTF8'\"", "RANGE_REDUCE", "ADDITIVE_REDUCE",
  "MULTIPLICATIVE_REDUCE", "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE",
  "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR", "UNARY_PREC",
  "SEQUENCE_TYPE_REDUCE", "OCCURS_STAR", "OCCURS_PLUS", "OCCURS_HOOK",
  "STEP_REDUCE", "$accept", "Module", "ERROR", "ModuleWithoutBOM",
  "VersionDecl", "MainModule", "LibraryModule", "ModuleDecl",
  "SIND_DeclList", "SIND_Decl", "Setter", "BoundarySpaceDecl",
  "DefaultCollationDecl", "BaseURIDecl", "ConstructionDecl",
  "OrderingModeDecl", "EmptyOrderDecl", "CopyNamespacesDecl", "Import",
  "SchemaImport", "URILiteralList", "SchemaPrefix", "ModuleImport",
  "NamespaceDecl", "DefaultNamespaceDecl", "VFO_DeclList", "VFO_Decl",
  "DecimalFormatDecl", "DecimalFormatParamList", "DecimalFormatParam",
  "DecimalFormatParamName", "OptionDecl", "FTOptionDecl", "CtxItemDecl",
  "CtxItemDecl2", "CtxItemDecl3", "CtxItemDecl4", "VarDecl",
  "VarNameAndType", "AnnotationList", "Annotation",
  "AnnotationLiteralList", "FunctionDecl", "FunctionDecl2",
  "FunctionDeclSimple", "FunctionDeclUpdating", "FunctionSig", "ParamList",
  "Param", "CollectionDecl", "CollectionTypeDecl", "IndexDecl",
  "IndexKeyList", "IndexKeySpec", "IntegrityConstraintDecl", "QueryBody",
  "StatementsAndOptionalExprTop", "StatementsAndOptionalExpr",
  "StatementsAndExpr", "Statements", "Statement", "BlockStatement",
  "BlockExpr", "EnclosedStatementsAndOptionalExpr", "VarDeclStatement",
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
  "opt_FTIgnoreOption", "RangeExpr", "AdditiveExpr", "MultiplicativeExpr",
  "UnionExpr", "IntersectExceptExpr", "InstanceofExpr", "TreatExpr",
  "CastableExpr", "CastExpr", "UnaryExpr", "SignList", "ValueExpr",
  "ValueComp", "NodeComp", "ValidateExpr", "ExtensionExpr", "Pragma_list",
  "Pragma", "PathExpr", "LeadingSlash", "RelativePathExpr", "StepExpr",
  "AxisStep", "ForwardStep", "ForwardAxis", "AbbrevForwardStep",
  "ReverseStep", "ReverseAxis", "NodeTest", "NameTest", "Wildcard",
  "FilterExpr", "PredicateList", "Predicate", "PrimaryExpr", "Literal",
  "NumericLiteral", "VarRef", "ParenthesizedExpr", "ContextItemExpr",
  "OrderedExpr", "UnorderedExpr", "FunctionCall", "ArgList", "Constructor",
  "DirectConstructor", "DirElemConstructor", "DirElemContentList",
  "DirAttributeList", "DirAttr", "OptionalBlank", "DirAttributeValue",
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
  "FTIgnoreOption", "URI_LITERAL", "NCNAME", "QNAME", "FUNCTION_NAME",
  "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       323,     0,    -1,   325,    -1,   308,   325,    -1,     1,     3,
      -1,   327,    -1,   326,   327,    -1,   328,    -1,   326,   328,
      -1,   212,   213,    29,   188,    -1,   212,   213,    29,   129,
      29,   188,    -1,   330,   188,   377,    -1,   347,   188,   377,
      -1,   330,   188,   347,   188,   377,    -1,   377,    -1,   330,
     324,   377,    -1,   347,   324,   377,    -1,   330,   188,   347,
     324,   377,    -1,   330,   324,   347,   188,   377,    -1,   329,
      -1,   329,   330,   188,    -1,   329,   347,   188,    -1,   329,
     330,   188,   347,   188,    -1,    34,   158,   624,   130,   623,
     188,    -1,   331,    -1,   330,   188,   331,    -1,   330,   324,
     331,    -1,   332,    -1,   340,    -1,   345,    -1,   346,    -1,
     354,    -1,   333,    -1,   334,    -1,   335,    -1,   336,    -1,
     337,    -1,   338,    -1,   339,    -1,   557,    -1,    33,    38,
     180,    -1,    33,    38,   193,    -1,    33,   111,   104,   623,
      -1,    33,    37,   623,    -1,    33,    40,   180,    -1,    33,
      40,   193,    -1,    33,    57,   167,    -1,    33,    57,   199,
      -1,    33,   111,   166,   125,   126,    -1,    33,   111,   166,
     125,   127,    -1,    33,    41,   180,   105,   146,    -1,    33,
      41,   180,   105,   163,    -1,    33,    41,   164,   105,   146,
      -1,    33,    41,   164,   105,   163,    -1,   341,    -1,   344,
      -1,    49,    24,     1,    -1,    49,    60,   623,    -1,    49,
      60,   343,   623,    -1,    49,    60,   623,    95,   342,    -1,
      49,    60,   343,   623,    95,   342,    -1,   623,    -1,   342,
     105,   623,    -1,   158,   624,   130,    -1,   111,    45,   158,
      -1,    49,    34,   623,    -1,    49,    34,   158,   624,   130,
     623,    -1,    49,    34,   623,    95,   342,    -1,    49,    34,
     158,   624,   130,   623,    95,   342,    -1,    33,   158,   624,
     130,   623,    -1,    33,   111,    45,   158,   623,    -1,    33,
     111,    47,   158,   623,    -1,   348,    -1,   347,   188,   348,
      -1,   347,   324,   348,    -1,   349,    -1,   353,    -1,   355,
      -1,   359,    -1,   364,    -1,   371,    -1,   373,    -1,   376,
      -1,    33,   111,    78,   350,    -1,    33,    78,   625,   350,
      -1,   351,    -1,   350,   351,    -1,   352,   130,   549,    -1,
      79,    -1,    87,    -1,    80,    -1,    81,    -1,    82,    -1,
      83,    -1,    88,    -1,    84,    -1,    85,    -1,    86,    -1,
      33,    56,   625,    29,    -1,    33,   259,   596,    -1,    33,
     109,   150,   356,    -1,    93,   534,   357,    -1,   357,    -1,
     358,    -1,   135,    -1,   135,   358,    -1,   140,   401,    -1,
      33,   360,   140,   401,    -1,    33,   360,   135,    -1,    33,
     360,   135,   140,   401,    -1,   110,   116,   625,    -1,   110,
     116,   625,   531,    -1,   361,   110,   116,   625,    -1,   361,
     110,   116,   625,   531,    -1,   362,    -1,   361,   362,    -1,
      26,    -1,    26,   154,   363,   185,    -1,    27,    -1,    27,
     154,   363,   185,    -1,   495,    -1,   363,   105,   495,    -1,
      33,   365,    -1,    33,   361,   365,    -1,   366,    -1,   367,
      -1,    47,   626,   368,   385,    -1,    47,   626,   368,   135,
      -1,    74,    47,   626,   368,   385,    -1,    74,    47,   626,
     368,   135,    -1,   154,   185,    -1,   154,   369,   185,    -1,
     154,   185,    93,   532,    -1,   154,   369,   185,    93,   532,
      -1,   370,    -1,   369,   105,   370,    -1,   116,   625,    -1,
     116,   625,   531,    -1,    33,   285,   625,    -1,    33,   285,
     625,    93,   372,    -1,    33,   361,   285,   625,    -1,    33,
     361,   285,   625,    93,   372,    -1,   537,    -1,   537,   533,
      -1,    33,   293,   625,   297,   224,   478,   168,   374,    -1,
      33,   361,   293,   625,   297,   224,   478,   168,   374,    -1,
     375,    -1,   374,   105,   375,    -1,   478,    -1,   478,   531,
      -1,   478,   436,    -1,   478,   531,   436,    -1,    33,   301,
     302,   625,   297,   285,   625,   116,   625,   303,   401,    -1,
      33,   301,   302,   625,   297,   285,   625,   222,   116,   625,
     303,   291,   304,   478,    -1,    33,   301,   302,   625,   297,
     285,   625,   305,   222,   116,   625,   303,   401,    -1,    33,
     301,   302,   625,   306,   304,   255,   285,   625,   222,   116,
     625,   304,   478,   196,   285,   625,   222,   116,   625,   304,
     478,    -1,   378,    -1,   380,    -1,   381,    -1,    -1,   380,
      -1,   381,    -1,    -1,   400,    -1,   381,   400,    -1,   382,
      -1,   381,   382,    -1,   383,    -1,   386,    -1,   389,    -1,
     390,    -1,   391,    -1,   392,    -1,   393,    -1,   394,    -1,
     396,    -1,   448,    -1,   444,    -1,   397,    -1,   151,   381,
     182,    -1,   151,   182,    -1,   151,   379,   182,    -1,   151,
     379,   182,    -1,   387,   188,    -1,   387,   105,   388,    -1,
     110,   388,    -1,   235,   110,   388,    -1,   361,   110,   388,
      -1,   235,   361,   110,   388,    -1,   116,   625,    -1,   116,
     625,   531,    -1,   116,   625,   140,   401,    -1,   116,   625,
     531,   140,   401,    -1,   116,   625,   140,   401,   188,    -1,
     402,   188,    -1,   238,   240,   401,   188,    -1,   241,   154,
     400,   185,   382,    -1,   236,   239,   188,    -1,   237,   239,
     188,    -1,   412,   395,    -1,   184,   382,    -1,    48,   154,
     400,   185,   195,   382,   124,   382,    -1,   242,   383,   398,
      -1,   399,    -1,   398,   399,    -1,   243,   569,   383,    -1,
     243,   569,   154,   116,   625,   185,   383,    -1,   243,   569,
     154,   116,   625,   105,   116,   625,   185,   383,    -1,   243,
     569,   154,   116,   625,   105,   116,   625,   105,   116,   625,
     185,   383,    -1,   401,    -1,   400,   105,   401,    -1,   403,
      -1,   440,    -1,   447,    -1,   453,    -1,   565,    -1,   402,
      -1,   454,    -1,   437,    -1,   558,    -1,   559,    -1,   561,
      -1,   560,    -1,   562,    -1,   412,   404,    -1,   184,   401,
      -1,    66,   282,    -1,    71,   282,    -1,   214,    -1,   252,
      -1,    55,   252,    -1,   406,   422,    76,   401,    -1,   406,
      76,   401,    -1,    46,   405,   421,   407,   407,    -1,    46,
     405,   421,   407,    -1,    42,   116,   625,    -1,   413,    -1,
     418,    -1,   408,    -1,   410,    -1,   425,    -1,   430,    -1,
     426,    -1,   409,    -1,   410,    -1,   412,   411,    -1,    46,
     116,   414,    -1,   415,    -1,   414,   105,   116,   415,    -1,
     625,   145,   401,    -1,   625,    36,   125,   145,   401,    -1,
     625,   531,   145,   401,    -1,   625,   531,    36,   125,   145,
     401,    -1,   625,   416,   145,   401,    -1,   625,    36,   125,
     416,   145,   401,    -1,   625,   531,   416,   145,   401,    -1,
     625,   531,    36,   125,   416,   145,   401,    -1,   625,   417,
     145,   401,    -1,   625,   531,   417,   145,   401,    -1,   625,
     416,   417,   145,   401,    -1,   625,   531,   416,   417,   145,
     401,    -1,    95,   116,   625,    -1,   271,   116,   625,    -1,
      51,   419,    -1,   420,    -1,   419,   105,   420,    -1,   116,
     625,   140,   401,    -1,   116,   625,   531,   140,   401,    -1,
     417,   140,   401,    -1,   116,   625,   531,   417,   140,   401,
      -1,   116,   625,   145,   401,    -1,   116,   625,   531,   145,
     401,    -1,   423,    -1,   116,   625,    -1,   116,   625,   423,
      -1,   416,    -1,   416,   424,    -1,   424,    -1,    58,   116,
     625,    53,   116,   625,    -1,    53,   116,   625,    -1,    58,
     116,   625,    -1,   209,   401,    -1,   169,   168,   427,    -1,
     428,    -1,   427,   105,   428,    -1,   116,   625,    -1,   116,
     625,   429,    -1,   104,   623,    -1,   166,   168,   431,    -1,
      69,   166,   168,   431,    -1,   432,    -1,   431,   105,   432,
      -1,   401,    -1,   401,   433,    -1,   434,    -1,   435,    -1,
     436,    -1,   434,   435,    -1,   434,   436,    -1,   435,   436,
      -1,   434,   435,   436,    -1,    94,    -1,   114,    -1,   125,
     126,    -1,   125,   127,    -1,   104,   623,    -1,    67,   116,
     438,   186,   401,    -1,   133,   116,   438,   186,   401,    -1,
     439,    -1,   438,   105,   116,   439,    -1,   625,   145,   401,
      -1,   625,   531,   145,   401,    -1,    72,   154,   400,   185,
     441,   111,   184,   401,    -1,   442,    -1,   441,   442,    -1,
     443,   184,   401,    -1,    98,   401,    -1,   443,    98,   401,
      -1,    72,   154,   400,   185,   445,   111,   184,   382,    -1,
     446,    -1,   445,   446,    -1,   443,   184,   382,    -1,    73,
     154,   400,   185,   449,   111,   184,   401,    -1,    73,   154,
     400,   185,   449,   111,   116,   625,   184,   401,    -1,    73,
     154,   400,   185,   451,   111,   184,   382,    -1,    73,   154,
     400,   185,   449,   111,   116,   625,   184,   382,    -1,   450,
      -1,   449,   450,    -1,    98,   532,   184,   401,    -1,    98,
     116,   625,    93,   532,   184,   401,    -1,   452,    -1,   451,
     452,    -1,    98,   532,   184,   382,    -1,    98,   116,   625,
      93,   532,   184,   382,    -1,    48,   154,   400,   185,   195,
     401,   124,   401,    -1,   455,    -1,   454,   165,   455,    -1,
     456,    -1,   455,    91,   456,    -1,   458,    -1,   458,   472,
     458,    -1,   458,   473,   458,    -1,   458,   130,   458,    -1,
     458,   160,   458,    -1,    -1,   458,   155,   457,   458,    -1,
     458,   153,   458,    -1,   458,   141,   458,    -1,   458,   139,
     458,    -1,   460,    -1,   460,   247,    70,   570,   459,    -1,
      -1,   622,    -1,   461,    -1,   461,   196,   461,    -1,   462,
      -1,   461,   174,   462,    -1,   461,   156,   462,    -1,   463,
      -1,   462,   191,   463,    -1,   462,   115,   463,    -1,   462,
     144,   463,    -1,   462,   157,   463,    -1,   464,    -1,   463,
     198,   464,    -1,   463,   207,   464,    -1,   465,    -1,   464,
     148,   465,    -1,   464,   134,   465,    -1,   466,    -1,   466,
      50,   228,   532,    -1,   467,    -1,   467,   197,    93,   532,
      -1,   468,    -1,   468,    99,    93,   530,    -1,   469,    -1,
     469,   100,    93,   530,    -1,   471,    -1,   470,   471,    -1,
     174,    -1,   156,    -1,   470,   174,    -1,   470,   156,    -1,
     474,    -1,   478,    -1,   475,    -1,   200,    -1,   205,    -1,
     204,    -1,   203,    -1,   202,    -1,   201,    -1,   149,    -1,
     177,    -1,   138,    -1,    75,   151,   380,   182,    -1,    75,
     219,   151,   380,   182,    -1,    75,   218,   151,   380,   182,
      -1,    75,    93,   547,   151,   380,   182,    -1,   476,   151,
     182,    -1,   476,   151,   400,   182,    -1,   477,    -1,   476,
     477,    -1,   175,   625,    17,    -1,   175,    18,    -1,   175,
      19,    -1,   479,    -1,   479,   480,    -1,   190,   480,    -1,
     480,    -1,   189,    -1,   481,    -1,   481,   189,   480,    -1,
     481,   190,   480,    -1,   482,    -1,   491,    -1,   483,    -1,
     483,   492,    -1,   486,    -1,   486,   492,    -1,   484,   488,
      -1,   485,    -1,   103,   120,    -1,   112,   120,    -1,    96,
     120,    -1,   187,   120,    -1,   113,   120,    -1,   137,   120,
      -1,   136,   120,    -1,   488,    -1,    97,   488,    -1,   487,
     488,    -1,   118,    -1,   170,   120,    -1,    89,   120,    -1,
     179,   120,    -1,   178,   120,    -1,    90,   120,    -1,   537,
      -1,   489,    -1,   625,    -1,   490,    -1,   191,    -1,    11,
      -1,    12,    -1,    20,    -1,   494,    -1,   491,   492,    -1,
     491,   154,   185,    -1,   491,   154,   503,   185,    -1,   493,
      -1,   492,   493,    -1,   152,   400,   183,    -1,   495,    -1,
     497,    -1,   498,    -1,   499,    -1,   502,    -1,   504,    -1,
     500,    -1,   501,    -1,   550,    -1,   384,    -1,   496,    -1,
     549,    -1,   108,    -1,   147,    -1,   122,    -1,   116,   625,
      -1,   154,   185,    -1,   154,   400,   185,    -1,   117,    -1,
     167,   151,   400,   182,    -1,   199,   151,   400,   182,    -1,
     626,   154,   185,    -1,   626,   154,   503,   185,    -1,   401,
      -1,   503,   105,   401,    -1,   505,    -1,   523,    -1,   506,
      -1,   520,    -1,   521,    -1,   155,   625,   510,   128,    -1,
     155,   625,   508,   510,   128,    -1,   155,   625,   510,   194,
     192,   625,   510,   194,    -1,   155,   625,   510,   194,   507,
     192,   625,   510,   194,    -1,   155,   625,   508,   510,   194,
     192,   625,   510,   194,    -1,   155,   625,   508,   510,   194,
     507,   192,   625,   510,   194,    -1,   518,    -1,   507,   518,
      -1,   509,    -1,   508,   509,    -1,    35,   625,   510,   130,
     510,   511,    -1,    -1,    35,    -1,   181,   512,   181,    -1,
      92,   514,    92,    -1,    -1,   513,    -1,   132,    -1,   516,
      -1,   513,   132,    -1,   513,   516,    -1,    -1,   515,    -1,
     131,    -1,   517,    -1,   515,   131,    -1,   515,   517,    -1,
      28,    -1,   519,    -1,     5,    -1,   519,    -1,   505,    -1,
      10,    -1,   522,    -1,   519,    -1,     9,    -1,   121,    -1,
     123,    -1,   151,   380,   182,    -1,   210,    30,   211,    -1,
     210,   211,    -1,   172,   624,   173,    -1,   172,   624,     8,
      -1,   101,     7,    -1,   524,    -1,   525,    -1,   526,    -1,
     527,    -1,   528,    -1,   529,    -1,    43,   151,   379,   182,
      -1,    21,   379,   182,    -1,    45,   151,   400,   182,   151,
     379,   182,    -1,    22,   379,   182,    -1,    96,   151,   400,
     182,   151,   379,   182,    -1,    70,   151,   380,   182,    -1,
      39,   151,   380,   182,    -1,    23,   379,   182,    -1,    59,
     151,   400,   182,   151,   379,   182,    -1,   536,    -1,   536,
     142,    -1,    93,   532,    -1,   534,    -1,   534,   533,    -1,
     208,   154,   185,    -1,   142,    -1,   191,    -1,   174,    -1,
     536,    -1,   537,    -1,   150,   154,   185,    -1,   553,    -1,
     556,    -1,   532,    -1,   535,   105,   532,    -1,   625,    -1,
     539,    -1,   545,    -1,   543,    -1,   546,    -1,   544,    -1,
     542,    -1,   541,    -1,   540,    -1,   538,    -1,   222,   154,
     185,    -1,    44,   154,   185,    -1,    44,   154,   545,   185,
      -1,    44,   154,   546,   185,    -1,    70,   154,   185,    -1,
      39,   154,   185,    -1,    59,   154,   185,    -1,    59,   154,
     624,   185,    -1,    59,   154,    29,   185,    -1,    96,   154,
     185,    -1,    96,   154,   625,   185,    -1,    96,   154,   625,
     105,   547,   185,    -1,    96,   154,   191,   185,    -1,    96,
     154,   191,   105,   547,   185,    -1,    61,   154,   625,   185,
      -1,    45,   154,   185,    -1,    45,   154,   625,   185,    -1,
      45,   154,   625,   105,   547,   185,    -1,    45,   154,   625,
     105,   548,   185,    -1,    45,   154,   191,   185,    -1,    45,
     154,   191,   105,   547,   185,    -1,    45,   154,   191,   105,
     548,   185,    -1,    62,   154,   625,   185,    -1,   625,    -1,
     625,   142,    -1,    29,    -1,   551,    -1,   552,    -1,   625,
     143,   147,    -1,    47,   368,   385,    -1,   554,    -1,   555,
      -1,    47,   154,   191,   185,    -1,    47,   154,   185,    93,
     532,    -1,    47,   154,   535,   185,    93,   532,    -1,   154,
     534,   185,    -1,    33,   217,   218,    -1,    33,   217,   219,
      -1,    33,   217,   220,    -1,   223,   222,   401,   230,   401,
      -1,   223,   222,   401,    93,   229,   230,   401,    -1,   223,
     222,   401,    93,   231,   230,   401,    -1,   223,   222,   401,
     215,   401,    -1,   223,   222,   401,   216,   401,    -1,   223,
     224,   401,   230,   401,    -1,   223,   224,   401,    93,   229,
     230,   401,    -1,   223,   224,   401,    93,   231,   230,   401,
      -1,   223,   224,   401,   215,   401,    -1,   223,   224,   401,
     216,   401,    -1,   221,   222,   401,    -1,   221,   224,   401,
      -1,   226,   222,   401,   234,   401,    -1,   226,   227,   228,
     222,   401,   234,   401,    -1,   225,   222,   401,    93,   401,
      -1,   233,   116,   563,   232,   401,   184,   401,    -1,   564,
      -1,   563,   105,   116,   564,    -1,   625,   140,   401,    -1,
     242,   151,   400,   182,   566,    -1,   567,    -1,   566,   567,
      -1,   243,   569,   568,    -1,   243,   569,   154,   116,   625,
     185,   568,    -1,   243,   569,   154,   116,   625,   105,   116,
     625,   185,   568,    -1,   243,   569,   154,   116,   625,   105,
     116,   625,   105,   116,   625,   185,   568,    -1,   151,   400,
     182,    -1,   489,    -1,   569,   207,   489,    -1,   573,   571,
      -1,    -1,   572,    -1,   591,    -1,   572,   591,    -1,   574,
      -1,   573,   260,   574,    -1,   575,    -1,   574,   256,   575,
      -1,   576,    -1,   575,   258,   145,   576,    -1,   577,    -1,
     257,   577,    -1,   581,   578,   579,    -1,    -1,   596,    -1,
      -1,   580,    -1,   280,   151,   400,   182,    -1,   585,   582,
      -1,   154,   570,   185,    -1,   583,    -1,    -1,   618,    -1,
     476,   151,   584,   182,    -1,    -1,   570,    -1,   586,   587,
      -1,   495,    -1,   151,   400,   182,    -1,    -1,   588,    -1,
     246,   589,    -1,   245,   590,    -1,   268,    -1,    -1,    77,
      -1,    -1,   284,    -1,   592,    -1,   593,    -1,   594,    -1,
     620,    -1,   617,    -1,   167,    -1,   282,   461,   595,    -1,
     251,   619,   595,    -1,   284,    -1,   274,    -1,   267,    -1,
     244,   597,    -1,   596,   244,   597,    -1,   598,    -1,   599,
      -1,   600,    -1,   615,    -1,   601,    -1,   609,    -1,   602,
      -1,   616,    -1,    98,   272,    -1,    98,   261,    -1,   264,
      -1,   279,    -1,   249,   272,    -1,   249,   261,    -1,    56,
     625,    29,    -1,   275,    -1,    54,   275,    -1,   277,   603,
      -1,   277,   154,   603,   604,   185,    -1,    54,   277,    -1,
     606,    -1,   111,    -1,    -1,   105,   605,    -1,   606,    -1,
     605,   105,   606,    -1,    95,    29,   607,   608,    -1,    -1,
     269,    29,    -1,    -1,   619,   263,    -1,   276,   284,   610,
     612,    -1,   276,   284,   111,   612,    -1,    54,   276,   284,
      -1,    95,    29,    -1,   154,   611,   185,    -1,    29,    -1,
     611,   105,    29,    -1,    -1,   613,    -1,   614,    -1,   613,
     614,    -1,   198,   610,    -1,   134,   610,    -1,   262,    29,
      -1,   281,    -1,    54,   281,    -1,    95,   214,    -1,    95,
     252,    -1,   253,   248,    -1,   265,   619,   278,    -1,   254,
     461,    -1,    95,   127,   461,    -1,    95,    52,   461,    -1,
     255,   461,   196,   461,    -1,   270,   621,    -1,   250,   621,
      -1,   273,    -1,   266,    -1,   283,   248,   463,    -1,    29,
      -1,    16,    -1,   625,    -1,   626,    -1,    96,    -1,    39,
      -1,    44,    -1,    45,    -1,   150,    -1,    48,    -1,   222,
      -1,    59,    -1,    61,    -1,    62,    -1,    70,    -1,    73,
      -1,    72,    -1,   208,    -1,   241,    -1,   627,    -1,    24,
      -1,   212,    -1,   125,    -1,    38,    -1,   259,    -1,    37,
      -1,   219,    -1,   218,    -1,   144,    -1,    43,    -1,   257,
      -1,   258,    -1,   272,    -1,   261,    -1,   249,    -1,   283,
      -1,   275,    -1,   277,    -1,   276,    -1,   281,    -1,   253,
      -1,   248,    -1,    77,    -1,   214,    -1,   252,    -1,    52,
      -1,   220,    -1,   233,    -1,   300,    -1,   227,    -1,   200,
      -1,   205,    -1,   204,    -1,   203,    -1,   202,    -1,   201,
      -1,    95,    -1,   109,    -1,   110,    -1,   184,    -1,    46,
      -1,    36,    -1,    66,    -1,    71,    -1,    58,    -1,    53,
      -1,    55,    -1,    76,    -1,    42,    -1,   145,    -1,    51,
      -1,   209,    -1,   168,    -1,   169,    -1,   166,    -1,    69,
      -1,    94,    -1,   114,    -1,   126,    -1,   127,    -1,   104,
      -1,    67,    -1,   133,    -1,   186,    -1,    98,    -1,    93,
      -1,   195,    -1,   124,    -1,   165,    -1,    91,    -1,    50,
      -1,   228,    -1,    99,    -1,   196,    -1,   115,    -1,   157,
      -1,   198,    -1,   148,    -1,   134,    -1,    75,    -1,   100,
      -1,   197,    -1,   149,    -1,   180,    -1,   193,    -1,   158,
      -1,   135,    -1,   129,    -1,   164,    -1,   146,    -1,   163,
      -1,    33,    -1,    40,    -1,    57,    -1,   111,    -1,    41,
      -1,    56,    -1,   213,    -1,    49,    -1,    60,    -1,    34,
      -1,    47,    -1,   271,    -1,   247,    -1,   280,    -1,   282,
      -1,   251,    -1,   265,    -1,   278,    -1,   270,    -1,   250,
      -1,   264,    -1,   279,    -1,   269,    -1,   263,    -1,   262,
      -1,   246,    -1,   245,    -1,   254,    -1,   255,    -1,   284,
      -1,   274,    -1,   273,    -1,   268,    -1,   266,    -1,   267,
      -1,   226,    -1,   232,    -1,   229,    -1,   223,    -1,   216,
      -1,   215,    -1,   217,    -1,   234,    -1,   224,    -1,   225,
      -1,   231,    -1,   221,    -1,   230,    -1,    65,    -1,    63,
      -1,    74,    -1,   167,    -1,   199,    -1,   240,    -1,   235,
      -1,   238,    -1,   239,    -1,   236,    -1,   237,    -1,   242,
      -1,   243,    -1,   244,    -1,    64,    -1,   293,    -1,   291,
      -1,   292,    -1,   297,    -1,   298,    -1,   299,    -1,   294,
      -1,   295,    -1,   296,    -1,    78,    -1,    79,    -1,    80,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,
      -1,    86,    -1,    87,    -1,    88,    -1,   285,    -1,   286,
      -1,   287,    -1,   288,    -1,   289,    -1,   290,    -1,   301,
      -1,   302,    -1,   303,    -1,   304,    -1,   305,    -1,   306,
      -1,   307,    -1,    89,    -1,   103,    -1,   112,    -1,   170,
      -1,   178,    -1,   187,    -1,   136,    -1,    90,    -1,   113,
      -1,   137,    -1,   179,    -1,   623,   119,   624,    -1,    25,
      -1
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
     682,   685,   689,   693,   696,   700,   703,   707,   711,   716,
     719,   723,   728,   734,   740,   743,   748,   754,   758,   762,
     765,   768,   777,   781,   783,   786,   790,   798,   809,   823,
     825,   829,   831,   833,   835,   837,   839,   841,   843,   845,
     847,   849,   851,   853,   855,   858,   861,   864,   867,   869,
     871,   874,   879,   883,   889,   894,   898,   900,   902,   904,
     906,   908,   910,   912,   914,   916,   919,   923,   925,   930,
     934,   940,   945,   952,   957,   964,   970,   978,   983,   989,
     995,  1002,  1006,  1010,  1013,  1015,  1019,  1024,  1030,  1034,
    1041,  1046,  1052,  1054,  1057,  1061,  1063,  1066,  1068,  1075,
    1079,  1083,  1086,  1090,  1092,  1096,  1099,  1103,  1106,  1110,
    1115,  1117,  1121,  1123,  1126,  1128,  1130,  1132,  1135,  1138,
    1141,  1145,  1147,  1149,  1152,  1155,  1158,  1164,  1170,  1172,
    1177,  1181,  1186,  1195,  1197,  1200,  1204,  1207,  1211,  1220,
    1222,  1225,  1229,  1238,  1249,  1258,  1269,  1271,  1274,  1279,
    1287,  1289,  1292,  1297,  1305,  1314,  1316,  1320,  1322,  1326,
    1328,  1332,  1336,  1340,  1344,  1345,  1350,  1354,  1358,  1362,
    1364,  1370,  1371,  1373,  1375,  1379,  1381,  1385,  1389,  1391,
    1395,  1399,  1403,  1407,  1409,  1413,  1417,  1419,  1423,  1427,
    1429,  1434,  1436,  1441,  1443,  1448,  1450,  1455,  1457,  1460,
    1462,  1464,  1467,  1470,  1472,  1474,  1476,  1478,  1480,  1482,
    1484,  1486,  1488,  1490,  1492,  1494,  1499,  1505,  1511,  1518,
    1522,  1527,  1529,  1532,  1536,  1539,  1542,  1544,  1547,  1550,
    1552,  1554,  1556,  1560,  1564,  1566,  1568,  1570,  1573,  1575,
    1578,  1581,  1583,  1586,  1589,  1592,  1595,  1598,  1601,  1604,
    1606,  1609,  1612,  1614,  1617,  1620,  1623,  1626,  1629,  1631,
    1633,  1635,  1637,  1639,  1641,  1643,  1645,  1647,  1650,  1654,
    1659,  1661,  1664,  1668,  1670,  1672,  1674,  1676,  1678,  1680,
    1682,  1684,  1686,  1688,  1690,  1692,  1694,  1696,  1698,  1701,
    1704,  1708,  1710,  1715,  1720,  1724,  1729,  1731,  1735,  1737,
    1739,  1741,  1743,  1745,  1750,  1756,  1765,  1775,  1785,  1796,
    1798,  1801,  1803,  1806,  1813,  1814,  1816,  1820,  1824,  1825,
    1827,  1829,  1831,  1834,  1837,  1838,  1840,  1842,  1844,  1847,
    1850,  1852,  1854,  1856,  1858,  1860,  1862,  1864,  1866,  1868,
    1870,  1872,  1876,  1880,  1883,  1887,  1891,  1894,  1896,  1898,
    1900,  1902,  1904,  1906,  1911,  1915,  1923,  1927,  1935,  1940,
    1945,  1949,  1957,  1959,  1962,  1965,  1967,  1970,  1974,  1976,
    1978,  1980,  1982,  1984,  1988,  1990,  1992,  1994,  1998,  2000,
    2002,  2004,  2006,  2008,  2010,  2012,  2014,  2016,  2018,  2022,
    2026,  2031,  2036,  2040,  2044,  2048,  2053,  2058,  2062,  2067,
    2074,  2079,  2086,  2091,  2095,  2100,  2107,  2114,  2119,  2126,
    2133,  2138,  2140,  2143,  2145,  2147,  2149,  2153,  2157,  2159,
    2161,  2166,  2172,  2179,  2183,  2187,  2191,  2195,  2201,  2209,
    2217,  2223,  2229,  2235,  2243,  2251,  2257,  2263,  2267,  2271,
    2277,  2285,  2291,  2299,  2301,  2306,  2310,  2316,  2318,  2321,
    2325,  2333,  2344,  2358,  2362,  2364,  2368,  2371,  2372,  2374,
    2376,  2379,  2381,  2385,  2387,  2391,  2393,  2398,  2400,  2403,
    2407,  2408,  2410,  2411,  2413,  2418,  2421,  2425,  2427,  2428,
    2430,  2435,  2436,  2438,  2441,  2443,  2447,  2448,  2450,  2453,
    2456,  2458,  2459,  2461,  2462,  2464,  2466,  2468,  2470,  2472,
    2474,  2476,  2480,  2484,  2486,  2488,  2490,  2493,  2497,  2499,
    2501,  2503,  2505,  2507,  2509,  2511,  2513,  2516,  2519,  2521,
    2523,  2526,  2529,  2533,  2535,  2538,  2541,  2547,  2550,  2552,
    2554,  2555,  2558,  2560,  2564,  2569,  2570,  2573,  2574,  2577,
    2582,  2587,  2591,  2594,  2598,  2600,  2604,  2605,  2607,  2609,
    2612,  2615,  2618,  2621,  2623,  2626,  2629,  2632,  2635,  2639,
    2642,  2646,  2650,  2655,  2658,  2661,  2663,  2665,  2669,  2671,
    2673,  2675,  2677,  2679,  2681,  2683,  2685,  2687,  2689,  2691,
    2693,  2695,  2697,  2699,  2701,  2703,  2705,  2707,  2709,  2711,
    2713,  2715,  2717,  2719,  2721,  2723,  2725,  2727,  2729,  2731,
    2733,  2735,  2737,  2739,  2741,  2743,  2745,  2747,  2749,  2751,
    2753,  2755,  2757,  2759,  2761,  2763,  2765,  2767,  2769,  2771,
    2773,  2775,  2777,  2779,  2781,  2783,  2785,  2787,  2789,  2791,
    2793,  2795,  2797,  2799,  2801,  2803,  2805,  2807,  2809,  2811,
    2813,  2815,  2817,  2819,  2821,  2823,  2825,  2827,  2829,  2831,
    2833,  2835,  2837,  2839,  2841,  2843,  2845,  2847,  2849,  2851,
    2853,  2855,  2857,  2859,  2861,  2863,  2865,  2867,  2869,  2871,
    2873,  2875,  2877,  2879,  2881,  2883,  2885,  2887,  2889,  2891,
    2893,  2895,  2897,  2899,  2901,  2903,  2905,  2907,  2909,  2911,
    2913,  2915,  2917,  2919,  2921,  2923,  2925,  2927,  2929,  2931,
    2933,  2935,  2937,  2939,  2941,  2943,  2945,  2947,  2949,  2951,
    2953,  2955,  2957,  2959,  2961,  2963,  2965,  2967,  2969,  2971,
    2973,  2975,  2977,  2979,  2981,  2983,  2985,  2987,  2989,  2991,
    2993,  2995,  2997,  2999,  3001,  3003,  3005,  3007,  3009,  3011,
    3013,  3015,  3017,  3019,  3021,  3023,  3025,  3027,  3029,  3031,
    3033,  3035,  3037,  3039,  3041,  3043,  3045,  3047,  3049,  3051,
    3053,  3055,  3057,  3059,  3061,  3063,  3065,  3067,  3069,  3071,
    3073,  3075,  3077,  3079,  3081,  3083,  3085,  3087,  3089,  3091,
    3093,  3095,  3097,  3099,  3101,  3103,  3105,  3109
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   976,   976,   977,   986,   995,  1001,  1009,  1015,  1026,
    1031,  1039,  1046,  1053,  1062,  1069,  1077,  1085,  1093,  1104,
    1109,  1116,  1123,  1135,  1145,  1152,  1159,  1171,  1172,  1173,
    1174,  1175,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1189,
    1194,  1199,  1207,  1215,  1223,  1228,  1236,  1241,  1249,  1254,
    1262,  1269,  1276,  1283,  1293,  1295,  1298,  1308,  1313,  1321,
    1329,  1340,  1347,  1358,  1363,  1371,  1378,  1385,  1394,  1407,
    1415,  1422,  1432,  1439,  1446,  1457,  1458,  1459,  1460,  1461,
    1462,  1463,  1464,  1469,  1475,  1484,  1491,  1501,  1511,  1512,
    1513,  1514,  1515,  1516,  1517,  1518,  1519,  1520,  1525,  1533,
    1541,  1549,  1556,  1564,  1571,  1576,  1584,  1592,  1607,  1622,
    1640,  1645,  1653,  1661,  1672,  1677,  1686,  1691,  1698,  1703,
    1713,  1718,  1727,  1733,  1746,  1751,  1759,  1770,  1785,  1797,
    1812,  1817,  1822,  1827,  1835,  1842,  1853,  1858,  1868,  1875,
    1882,  1889,  1899,  1903,  1913,  1921,  1932,  1938,  1947,  1952,
    1959,  1966,  1977,  1987,  1997,  2007,  2025,  2045,  2050,  2055,
    2062,  2067,  2072,  2079,  2084,  2096,  2103,  2115,  2116,  2117,
    2118,  2119,  2120,  2121,  2123,  2124,  2125,  2126,  2127,  2132,
    2137,  2145,  2162,  2170,  2178,  2185,  2192,  2199,  2206,  2216,
    2228,  2241,  2253,  2269,  2277,  2285,  2293,  2308,  2313,  2321,
    2335,  2352,  2377,  2385,  2392,  2403,  2409,  2415,  2426,  2441,
    2446,  2461,  2462,  2463,  2464,  2465,  2466,  2471,  2472,  2475,
    2476,  2477,  2478,  2479,  2484,  2498,  2506,  2511,  2519,  2524,
    2529,  2537,  2546,  2558,  2568,  2581,  2589,  2590,  2591,  2596,
    2597,  2598,  2599,  2600,  2605,  2612,  2622,  2630,  2637,  2647,
    2657,  2667,  2677,  2687,  2697,  2707,  2717,  2728,  2737,  2747,
    2757,  2773,  2782,  2791,  2799,  2805,  2817,  2825,  2835,  2843,
    2855,  2861,  2872,  2874,  2878,  2886,  2890,  2895,  2899,  2903,
    2907,  2917,  2925,  2932,  2938,  2949,  2953,  2962,  2970,  2976,
    2986,  2992,  3002,  3006,  3016,  3022,  3028,  3034,  3043,  3052,
    3061,  3074,  3078,  3086,  3092,  3102,  3110,  3119,  3132,  3139,
    3151,  3155,  3167,  3174,  3180,  3189,  3196,  3202,  3213,  3220,
    3226,  3235,  3244,  3251,  3262,  3269,  3281,  3287,  3299,  3305,
    3316,  3322,  3333,  3339,  3350,  3359,  3363,  3372,  3376,  3384,
    3388,  3398,  3405,  3414,  3424,  3423,  3437,  3446,  3455,  3468,
    3472,  3485,  3488,  3495,  3499,  3508,  3512,  3516,  3525,  3529,
    3535,  3541,  3547,  3558,  3562,  3566,  3574,  3578,  3584,  3594,
    3598,  3608,  3612,  3622,  3626,  3636,  3640,  3650,  3654,  3662,
    3666,  3670,  3674,  3684,  3688,  3692,  3700,  3704,  3708,  3712,
    3716,  3720,  3728,  3732,  3736,  3744,  3748,  3752,  3756,  3767,
    3773,  3783,  3789,  3799,  3803,  3807,  3845,  3849,  3859,  3869,
    3882,  3891,  3901,  3905,  3914,  3918,  3927,  3933,  3941,  3947,
    3959,  3965,  3975,  3979,  3983,  3987,  3991,  3997,  4003,  4011,
    4015,  4023,  4027,  4038,  4042,  4046,  4052,  4056,  4070,  4074,
    4082,  4086,  4096,  4100,  4104,  4108,  4117,  4121,  4125,  4129,
    4137,  4143,  4153,  4161,  4165,  4169,  4173,  4177,  4181,  4185,
    4189,  4193,  4203,  4211,  4215,  4223,  4230,  4237,  4248,  4256,
    4260,  4268,  4276,  4284,  4338,  4342,  4355,  4361,  4371,  4375,
    4383,  4387,  4391,  4399,  4409,  4419,  4429,  4439,  4449,  4464,
    4470,  4481,  4487,  4498,  4509,  4511,  4515,  4520,  4530,  4533,
    4540,  4546,  4552,  4560,  4573,  4576,  4583,  4589,  4595,  4602,
    4613,  4617,  4627,  4631,  4641,  4645,  4649,  4654,  4663,  4669,
    4675,  4681,  4689,  4694,  4702,  4707,  4715,  4723,  4728,  4733,
    4738,  4743,  4748,  4757,  4765,  4769,  4786,  4790,  4798,  4806,
    4814,  4818,  4826,  4832,  4842,  4850,  4854,  4858,  4893,  4899,
    4905,  4915,  4919,  4923,  4927,  4931,  4938,  4944,  4954,  4962,
    4966,  4970,  4974,  4978,  4982,  4986,  4990,  4994,  5002,  5010,
    5014,  5018,  5028,  5036,  5044,  5048,  5052,  5060,  5064,  5070,
    5076,  5080,  5090,  5098,  5102,  5108,  5117,  5126,  5132,  5138,
    5148,  5165,  5172,  5187,  5223,  5227,  5235,  5243,  5255,  5259,
    5267,  5275,  5279,  5290,  5307,  5313,  5319,  5329,  5333,  5339,
    5345,  5349,  5355,  5359,  5365,  5371,  5378,  5388,  5393,  5401,
    5407,  5417,  5439,  5448,  5454,  5467,  5481,  5488,  5494,  5504,
    5509,  5514,  5524,  5538,  5546,  5552,  5570,  5579,  5582,  5589,
    5594,  5602,  5606,  5613,  5617,  5624,  5628,  5635,  5639,  5648,
    5661,  5664,  5672,  5675,  5683,  5691,  5699,  5703,  5711,  5714,
    5722,  5734,  5737,  5745,  5757,  5763,  5773,  5776,  5784,  5788,
    5792,  5800,  5803,  5811,  5814,  5822,  5826,  5830,  5834,  5838,
    5846,  5854,  5866,  5878,  5882,  5886,  5894,  5900,  5910,  5914,
    5918,  5922,  5926,  5930,  5934,  5938,  5946,  5950,  5954,  5958,
    5966,  5972,  5982,  5992,  5996,  6004,  6014,  6025,  6032,  6036,
    6044,  6047,  6054,  6059,  6068,  6078,  6081,  6089,  6092,  6100,
    6109,  6116,  6126,  6130,  6137,  6143,  6153,  6156,  6163,  6168,
    6180,  6188,  6200,  6208,  6212,  6220,  6224,  6228,  6236,  6244,
    6248,  6252,  6256,  6264,  6272,  6284,  6288,  6296,  6309,  6313,
    6314,  6327,  6328,  6329,  6330,  6331,  6332,  6333,  6334,  6335,
    6336,  6337,  6338,  6339,  6340,  6341,  6342,  6346,  6347,  6348,
    6349,  6350,  6351,  6352,  6353,  6354,  6355,  6356,  6357,  6358,
    6359,  6360,  6361,  6362,  6363,  6364,  6365,  6366,  6367,  6368,
    6369,  6370,  6371,  6372,  6373,  6374,  6375,  6376,  6377,  6378,
    6379,  6380,  6381,  6382,  6383,  6384,  6385,  6386,  6387,  6388,
    6389,  6390,  6391,  6392,  6393,  6394,  6395,  6396,  6397,  6398,
    6399,  6400,  6401,  6402,  6403,  6404,  6405,  6406,  6407,  6408,
    6409,  6410,  6411,  6412,  6413,  6414,  6415,  6416,  6417,  6418,
    6419,  6420,  6421,  6422,  6423,  6424,  6425,  6426,  6427,  6428,
    6429,  6430,  6431,  6432,  6433,  6434,  6435,  6436,  6437,  6438,
    6439,  6440,  6441,  6442,  6443,  6444,  6445,  6446,  6447,  6448,
    6449,  6450,  6451,  6452,  6453,  6454,  6455,  6456,  6457,  6458,
    6459,  6460,  6461,  6462,  6463,  6464,  6465,  6466,  6467,  6468,
    6469,  6470,  6471,  6472,  6473,  6474,  6475,  6476,  6477,  6478,
    6479,  6480,  6481,  6482,  6483,  6484,  6485,  6486,  6487,  6488,
    6489,  6490,  6491,  6492,  6493,  6494,  6495,  6496,  6497,  6498,
    6499,  6500,  6501,  6502,  6503,  6504,  6505,  6506,  6507,  6508,
    6509,  6510,  6511,  6512,  6513,  6514,  6515,  6516,  6517,  6518,
    6519,  6520,  6521,  6522,  6523,  6524,  6525,  6526,  6527,  6528,
    6529,  6530,  6531,  6532,  6533,  6534,  6535,  6536,  6537,  6538,
    6539,  6540,  6541,  6542,  6543,  6544,  6549,  6556
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
     315,   316,   317,   318,   319,   320,   321
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 13372;
  const int xquery_parser::yynnts_ = 306;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 573;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 322;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 576;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 16197 "/home/mbrantner/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6560 "/home/mbrantner/zorba/trunk/core/src/compiler/parser/xquery_parser.y"


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

